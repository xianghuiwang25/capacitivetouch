/***********************************************************************************************************************
 * DISCLAIMER
 * This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products. No
 * other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
 * applicable laws, including copyright laws.
 * THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
 * THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED. TO THE MAXIMUM
 * EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES
 * SHALL BE LIABLE FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS
 * SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
 * Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability of
 * this software. By using this software, you agree to the additional terms and conditions found by accessing the
 * following link:
 * http://www.renesas.com/disclaimer
 *
 * Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 * File Name : r_ctsu_rx.c
 * Version : 1.00: [2016-06-13] Released as Version 1.00.
 *            1.10: [TBD]
 * Description : This module provides the interface to the R_CTSU peripheral.
 ***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @file
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 Includes
 ***********************************************************************************************************************/

#include <string.h>
#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

#include "r_ctsu.h"
#include "r_ctsu_private.h"

/***********************************************************************************************************************
 Macro definitions
 ***********************************************************************************************************************/
/** API revision number (major) */
#define CTSU_VERSION_MAJOR        (1)
/** API revision number (minor) */
#define CTSU_VERSION_MINOR        (10)

/**
 * Unique number to identify if handle is open.
 */
#define OPEN    (0x4F50454e)

#define CTSUERRS_ENABLE_CALIBRATION_MODE    (0x0082)

#define TUNING_UPPER_LIMIT    (350)
#define TUNING_LOWER_LIMIT    (300)
#define OFFSET_UPPER_LIMIT    (200)
#define OFFSET_LOWER_LIMIT    (150)

#define CTSU_CORRECTION_SCAN_COUNT  (32)

#if defined(BSP_MCU_GROUP_S124)
#define LAST_TS  (36)
#elif defined(BSP_MCU_GROUP_S3A7)
#define LAST_TS  (36)
#elif defined(BSP_MCU_GROUP_S5D9)
#error Unsupported MCU
#elif defined(BSP_MCU_GROUP_S7G2)
#define LAST_TS  (36)
#else
#define LAST_TS  (36)
#endif

#define ASSERT(test)    if(false==(test)) {return CTSU_ERR_INVALID_PARAM;}

#define CTSU_CFG_CTSU_CORRECTION_READINGS     (5)

/***********************************************************************************************************************
 Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 Private variables
 ***********************************************************************************************************************/
static bsp_lock_t BSP_HW_LOCK_CTSU;                     ///< Lock which prevents starting a scan if a scan is already in progress.
static ctsu_instance_ctrl_t * p_scan_ctrl = NULL;       ///< Identifies which handle in the array last used for scanning with the CTSU.
static uint32_t open_instances = 0;
static uint32_t sensor_wr_irq_itr = 0;        ///< CTSU Write Interrupt iterator
static uint32_t sensor_rd_irq_itr = 0;        ///< CTSU Read Interrupt iterator

#if (CTSU_CFG_ENABLE_CORRECTION > 0) && defined(UNITY_TESTING)
static uint16_t linear_interpolation_table[61];
static uint16_t linear_interpolation_coeff[61];
#endif


static uint16_t calculate_sensor_count (ctsu_mode_t mode, ctsu_const_sfrs_t * p_ctsu_settings);
static void ctsu_read_output(ctsu_mode_t mode, uint16_t num_sensors, uint16_t const * const offsets,void* p_dest, void* p_src);
static void ctsu_read_counter(ctsu_mode_t mode, uint16_t num_sensors, uint16_t const * const offsets,void* p_dest, void* p_src);
static void ctsu_handle_register_value_get(ctsu_instance_ctrl_t* p_ctrl_blk, ctsu_cmd_t cmd, void* p_dest);
static void ctsu_handle_register_value_set(ctsu_instance_ctrl_t* p_ctrl_blk, ctsu_cmd_t cmd, void* value);
static void ctsu_handle_register_16bit_get(ctsu_instance_ctrl_t* p_ctrl_blk, ctsu_cmd_t cmd, uint16_t offset, void* value);
static void ctsu_handle_register_16bit_set(ctsu_instance_ctrl_t* p_ctrl_blk, ctsu_cmd_t cmd, uint16_t offset, uint16_t value);
#if (CTSU_CFG_CALIBRATION_ENABLE > 0)
static ctsu_err_t ctsu_correction_factor(ctsu_instance_ctrl_t * const p_ctsu_ctrl);
#endif /* (CTSU_CFG_CALIBRATION_ENABLE > 0) */


/***********************************************************************************************************************
 Global Variables
 **********************************************************************************************************************/
uint32_t ctsu_write_isr(void);
uint32_t ctsu_read_isr(void);
uint32_t ctsu_end_isr(void);

/***********************************************************************************************************************
 Private function prototypes
 ***********************************************************************************************************************/
extern uint32_t hw_ctsu_poweron (void);
extern uint32_t hw_ctsu_poweroff (void);
extern bool lock(void * const p);
extern void unlock(void * const p);

/** Version data structure used by error logger macro. */
static const ssp_version_t g_ctsu_version =
{
    .api_version_major  = CTSU_API_VERSION_MAJOR,
    .api_version_minor  = CTSU_API_VERSION_MINOR,
    .code_version_major = CTSU_CODE_VERSION_MAJOR,
    .code_version_minor = CTSU_CODE_VERSION_MINOR,
};

const ctsu_api_t g_ctsu_on_ctsu =
{
    .open       = R_CTSU_Open,
    .close      = R_CTSU_Close,
    .scan       = R_CTSU_Scan,
    .read       = R_CTSU_Read,
    .calibrate  = R_CTSU_Calibrate,
    .control    = R_CTSU_Control,
    .versionGet = R_CTSU_VersionGet,
};

/***********************************************************************************************************************
 Functions
 **********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_CTSU_VersionGet
* Description  : Returns the current version of this module. The version number is encoded where the top 2 bytes are the
*                major version number and the bottom 2 bytes are the minor version number. For example, Version 4.25
*                would be returned as 0x00040019.
* Arguments    : none
* Return Value : Version of this module.
***********************************************************************************************************************/
ssp_err_t R_CTSU_VersionGet(ssp_version_t * const p_version)
{
#if CTSU_CFG_PARAM_CHECKING_ENABLE
    SSP_ASSERT(NULL != p_version);
#endif
    p_version->version_id =  g_ctsu_version.version_id;
    return SSP_SUCCESS;
}
/***********************************************************************************************************************
End of function R_CTSU_GetVersion
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: R_CTSU_Open
* Description  : Check parameters being used, Power up CTSU, and initialize an unused CTSU operation handle.
* Arguments    :
* @param p_usr_hdl    Location where the handle number is returned.
* @param p_ctsu_cfg Parameters that should be used for this handle.
* Return Value :
* @return @ref CTSU_SUCCESS, @ref CTSU_ERR_INVALID_PARAM, @ref CTSU_ERR_INSUFFICIENT_MEMORY, @ref CTSU_ERR_LOCKED
***********************************************************************************************************************/
ctsu_err_t R_CTSU_Open(ctsu_ctrl_t * const p_ctrl, ctsu_cfg_t const * const p_ctsu_cfg)
{
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    /** a. (Optional) Perform error checking. */
    ASSERT(p_ctrl != NULL);
    ASSERT(p_ctsu_cfg != NULL);
    ASSERT(p_ctsu_cfg->pclkb_hz >= 4000000);
    ASSERT(p_ctsu_cfg->p_ctsu_settings != NULL);
    ASSERT(p_ctsu_cfg->p_sensor_data != NULL);
    ASSERT(p_ctsu_cfg->p_sensor_settings != NULL);
    ASSERT(p_ctsu_cfg->p_ctsu_settings->ctsucr1.byte != 0);
#if (CTSU_CFG_ENABLE_MEASUREMENT_CORRECTION > 0)
    ASSERT(p_ctsu_cfg->p_correction_ideal_sensor_ico > 0);
    ASSERT(p_ctsu_cfg->correction_ctsuso_delta != 0);
#endif
#endif /*(CTSU_CFG_PARAM_CHECKING_ENABLE > 0) */

    ctsu_instance_ctrl_t ctrl_blk =
    {
            .p_ctsu_settings    = p_ctsu_cfg->p_ctsu_settings,
            .p_sensor_settings  = p_ctsu_cfg->p_sensor_settings,
            .p_sensor_data      = p_ctsu_cfg->p_sensor_data,
            .pclkb_hz           = p_ctsu_cfg->pclkb_hz,
            .p_callback         = p_ctsu_cfg->p_callback,
            .mode               = (ctsu_mode_t)(p_ctsu_cfg->p_ctsu_settings->ctsucr1.byte >> 6),
            .num_sensors        = calculate_sensor_count(ctrl_blk.mode, p_ctsu_cfg->p_ctsu_settings),
            .num_wr_irq_requests = ctrl_blk.num_sensors,
            .num_rd_irq_requests = (ctrl_blk.num_sensors * ((CTSU_MODE_MUTUAL_CAPACITANCE == ctrl_blk.mode) ? 2U : 1U)) & UINT16_MAX,
            .open = OPEN,
            .upper_level_count = 0,
            .p_correction_ideal_sensor_ico = p_ctsu_cfg->p_correction_ideal_sensor_ico,
            .p_linear_interpolation_table = &p_ctsu_cfg->p_correction_buffer[0],
            .p_linear_interpolation_coeff = &p_ctsu_cfg->p_correction_buffer[61],
            .p_magnification_sensor = (int8_t* )(&p_ctsu_cfg->p_correction_buffer[61+61]),
            .tscal_pin = p_ctsu_cfg->tscal_pin,
    };

    unlock(&ctrl_blk.lock);
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    /** d. Check if mode and number of sensors are valid. */
    ASSERT((ctrl_blk.num_sensors > 0) && (ctrl_blk.num_sensors <= 64));
#endif

    ctsu_instance_ctrl_t * p_ctsu_ctrl = p_ctrl;

    if (OPEN == p_ctsu_ctrl->open)
    {
        /* Was previously opened do a compare */
        if(0==memcmp(&ctrl_blk, p_ctsu_ctrl, offsetof(ctsu_instance_ctrl_t, open)))
        {
            /* Matching control block */
            lock(&p_ctsu_ctrl->lock);
            p_ctsu_ctrl->upper_level_count++;
            unlock(&p_ctsu_ctrl->lock);
            return CTSU_SUCCESS;
        }
        else
        {
            /* Provided a block that was previously opened with different CTSU settings. */
            return CTSU_ERR_INVALID_PARAM;
        }
    }
    else
    {
        memcpy(p_ctsu_ctrl, &ctrl_blk, sizeof(ctrl_blk));
        lock(&p_ctsu_ctrl->lock);
        p_ctsu_ctrl->upper_level_count = 1;
        unlock(&p_ctsu_ctrl->lock);
    }

    hw_ctsu_poweron();
    open_instances += 1;
    return CTSU_SUCCESS;
}
/***********************************************************************************************************************
End of function R_CTSU_Open
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_CTSU_Close
* Description  : Close a previously successfully opened handle.
* Arguments    : p_ctrl -
*                   Handle identifier provided to user by the @ref R_CTSU_Open function.
* Return Value :
*                CTSU_SUCCESS - Operation Succeeded.
*                CTSU_ERR_LOCKED - Failed as handle is being used.
***********************************************************************************************************************/
ctsu_err_t R_CTSU_Close(ctsu_ctrl_t * const p_ctrl)
{
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    ASSERT( NULL != p_ctrl);
#endif

    ctsu_instance_ctrl_t * const p_ctsu_ctrl = p_ctrl;
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    ASSERT(p_ctsu_ctrl->open == OPEN);
#endif

    if((lock (&p_ctsu_ctrl->lock) == false) && (p_scan_ctrl == p_ctrl))
    {
        /* Hardware is busy scanning with this handle.
         Cannot modify at this time. */
        return CTSU_ERR_LOCKED;
    }

    if (0 == (--p_ctsu_ctrl->upper_level_count))
    {
        /* No more upper levels are using this control block */
        memset(p_ctsu_ctrl, 0, sizeof(ctsu_instance_ctrl_t));
    }
    else
    {
        /* There are more upper layers using this handle. Release lock recently acquired and return. */
        unlock (&p_ctsu_ctrl->lock);
        return CTSU_SUCCESS;
    }

    if(p_scan_ctrl == p_ctrl)
    {
        p_scan_ctrl = NULL;
    }

    /* ********************** */
    /** Power OFF the CTSU */
    /* ********************** */
    if (0 == (--open_instances))
    {
        /* ********************************************** */
        /* Turn-off CTSU if all handles have been closed. */
        /* ********************************************** */
        /* Stop all conversions */
        HW_CTSU_CTSUCR0SetBitCTSUSTRT(0);

        /** 1. Re-initialize CTSU SFRs*/
        HW_CTSU_CTSUCR0SetBitCTSUINIT(1);

        /* Reset the SFRs to un-used state */
        HW_CTSU_CTSUCR0Set(0);
        HW_CTSU_CTSUCR1Set(0);
        HW_CTSU_CTSUSDPRSSet(0);
        HW_CTSU_CTSUDCLKCSet(0);
        HW_CTSU_CTSUSSTSet(0);
        HW_CTSU_CTSUCHAC0Set(0);
        HW_CTSU_CTSUCHAC1Set(0);
        HW_CTSU_CTSUCHAC2Set(0);
        HW_CTSU_CTSUCHAC3Set(0);
        HW_CTSU_CTSUCHAC4Set(0);
        HW_CTSU_CTSUCHTRC0Set(0);
        HW_CTSU_CTSUCHTRC1Set(0);
        HW_CTSU_CTSUCHTRC2Set(0);
        HW_CTSU_CTSUCHTRC3Set(0);
        HW_CTSU_CTSUCHTRC4Set(0);

        hw_ctsu_poweroff();
    }

    return CTSU_SUCCESS;
}
/***********************************************************************************************************************
End of function R_CTSU_Close
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_CTSU_Scan
* Description  : Enable scanning of a successfully opened handle.
* Arguments    : p_ctrl -
*                   Handle identifier provided to user by the @ref R_CTSU_Open function.
* Return Value :
* @return @ref CTSU_SUCCESS, @ref CTSU_ERR_CTSU_OPERATIONAL, @ref CTSU_ERR_LOCKED.
***********************************************************************************************************************/
ctsu_err_t R_CTSU_Scan(ctsu_ctrl_t * const p_ctrl)
{
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    ASSERT( NULL != p_ctrl);
#endif
    /** Get the handle */
    ctsu_instance_ctrl_t * const p_ctsu_ctrl = p_ctrl;

#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    /** (Optional) Perform error checking. */
    ASSERT( OPEN == p_ctsu_ctrl->open);
    ASSERT( HW_CTSU_PCLKB_Frequency() == p_ctsu_ctrl->pclkb_hz );
#endif

    ctsu_callback_arg_t args;
    args.handle_num = p_ctrl;
    args.info = 0;
    args.event_mask = 0;

    /** Lock the hardware. */
    if (lock (&BSP_HW_LOCK_CTSU) == false)
    {
        /* Hardware is busy scanning */
        return CTSU_ERR_CTSU_OPERATIONAL;
    }

    /** Lock the handle as the @ref st_ctsu_ctrl_blk::p_sensor_data buffer is about to be updated. */
    if (false == lock(&p_ctsu_ctrl->lock))
    {
        return CTSU_ERR_LOCKED;
    }

    if (((ctsu_instance_ctrl_t*)p_scan_ctrl != p_ctsu_ctrl) || (true == p_ctsu_ctrl->reload))
    {
        /** e. If handle is different from previous */
        /** 1. Load new CTSU SFR settings. */
        if(HW_CTSU_CTSUCR1GetBitCTSUMD() != p_ctsu_ctrl->mode)
        {
            /* Mode will be changed. Notify the user */
            args.event_mask |= CTSU_EVENT_SFRS_CHANGED;
        }
        HW_CTSU_CTSUCR1Set(p_ctsu_ctrl->p_ctsu_settings->ctsucr1.byte);
        HW_CTSU_CTSUSDPRSSet(p_ctsu_ctrl->p_ctsu_settings->ctsusdprs.byte);
        HW_CTSU_CTSUDCLKCSet(p_ctsu_ctrl->p_ctsu_settings->ctsudclkc.byte);
        HW_CTSU_CTSUSSTSet(p_ctsu_ctrl->p_ctsu_settings->ctsusst.byte);
        HW_CTSU_CTSUCHAC0Set(p_ctsu_ctrl->p_ctsu_settings->ctsuchac0.byte);
        HW_CTSU_CTSUCHAC1Set(p_ctsu_ctrl->p_ctsu_settings->ctsuchac1.byte);
        HW_CTSU_CTSUCHAC2Set(p_ctsu_ctrl->p_ctsu_settings->ctsuchac2.byte);
        HW_CTSU_CTSUCHAC3Set(p_ctsu_ctrl->p_ctsu_settings->ctsuchac3.byte);
        HW_CTSU_CTSUCHAC4Set(p_ctsu_ctrl->p_ctsu_settings->ctsuchac4.byte);
        HW_CTSU_CTSUCHTRC0Set(p_ctsu_ctrl->p_ctsu_settings->ctsuchtrc0.byte);
        HW_CTSU_CTSUCHTRC1Set(p_ctsu_ctrl->p_ctsu_settings->ctsuchtrc1.byte);
        HW_CTSU_CTSUCHTRC2Set(p_ctsu_ctrl->p_ctsu_settings->ctsuchtrc2.byte);
        HW_CTSU_CTSUCHTRC3Set(p_ctsu_ctrl->p_ctsu_settings->ctsuchtrc3.byte);
        HW_CTSU_CTSUCHTRC4Set(p_ctsu_ctrl->p_ctsu_settings->ctsuchtrc4.byte);
        HW_CTSU_CTSUCR0Set((p_ctsu_ctrl->p_ctsu_settings->ctsucr0.byte & (uint8_t)0xFE));

        /** 3. Set the scan handle index (which is used in the ISRs) */
        p_scan_ctrl = p_ctrl;
        if (true == p_ctsu_ctrl->reload)
        {
            p_ctsu_ctrl->reload = false;
        }
    }

    if(1 == HW_CTSU_CTSUCR0GetBitCTSUSNZ())
    {
        /* Refer note on CTSUSNZ Bit (CTSU Wait State Power-Saving Enable) about 16uS delay */
        HW_CTSU_CTSUCR0SetBitCTSUSNZ(0);
        args.event_mask |= CTSU_EVENT_SFRS_CHANGED;
    }

    args.info = p_ctsu_ctrl->num_sensors;
    args.event_mask |= CTSU_EVENT_STARTING_SCAN;
    if (NULL != p_ctsu_ctrl->p_callback)
    {
        /** f. If User has provided a callback, Notify User. */
        p_ctsu_ctrl->p_callback(&args);
    }

    /** g. Start CTSU scan operation. */
    HW_CTSU_CTSUCR0SetBitCTSUINIT(1);
    HW_CTSU_CTSUCR0SetBitCTSUSTRT(1);

    return CTSU_SUCCESS;
}
/***********************************************************************************************************************
End of function R_CTSU_Scan
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_CTSU_Read
* Description  : Read the results generated by a CTSU scan operation.
* Arguments    :
* @param usr_hdl Handle number provided to user by the @ref R_CTSU_Open function.
* @param p_arg Argument providing information about information to be read from latest scan.
* Return Value :
* @return @ref CTSU_SUCCESS, @ref CTSU_ERR_INVALID_CMD, @ref CTSU_ERR_INVALID_PARAM, @ref CTSU_ERR_LOCKED.
***********************************************************************************************************************/
ctsu_err_t R_CTSU_Read(ctsu_ctrl_t * p_ctrl, ctsu_read_t * p_arg)
{
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    ASSERT( NULL != p_ctrl);
#endif
    uint16_t* p_src;
    ctsu_err_t ctsu_err = CTSU_SUCCESS;
    ctsu_read_cmd_t cmd = p_arg->ctsu_result;
    size_t required_size = 0;

    /** a. Get the handle */
    ctsu_instance_ctrl_t * const p_ctsu_ctrl = p_ctrl;

#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    ASSERT(OPEN == p_ctsu_ctrl->open);
    ASSERT(NULL != p_arg->p_dest);
    ASSERT(0 < p_arg->size);
    ASSERT(CTSU_READ_LAST > p_arg->ctsu_result);
    ASSERT((NULL != p_arg->sensor_offset));
    ASSERT(0 < p_arg->count);
#endif
    uint16_t count = p_arg->count;
    uint16_t* p_dest = p_arg->p_dest;
    uint16_t const * const p_offsets = p_arg->sensor_offset;


    if (CTSU_MODE_SELF_CAPACITANCE == p_ctsu_ctrl->mode)
    {
        if ((CTSU_READ_SENSOR_COUNT_SECONDARY == cmd) || (CTSU_READ_REFERENCE_COUNT_SECONDARY == cmd))
        {
            return CTSU_ERR_INVALID_CMD;
        }
    }

    /** b. Calculate memory required to copy */
    if (CTSU_READ_BUFFER_ALL == cmd)
    {
        required_size = ((p_ctsu_ctrl->num_sensors * ((CTSU_MODE_MUTUAL_CAPACITANCE == p_ctsu_ctrl->mode) ? (4U) : (2U)))
                * sizeof(uint16_t));
    }
    else if (cmd < CTSU_READ_LAST)
    {
        required_size = (count * sizeof(uint16_t));
    }
    else
    {
        return CTSU_ERR_INVALID_CMD;
    }
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    ASSERT(required_size <= p_arg->size);
#endif
    if (required_size > p_arg->size)
    {
        /** Insufficient memory */
        return CTSU_ERR_INVALID_PARAM;
    }

    /** c. Check if the handle is in use*/
    if ((lock(&p_ctsu_ctrl->lock) == false) && ((ctsu_instance_ctrl_t*)p_scan_ctrl == p_ctsu_ctrl))
    {
        /* Hardware is busy scanning with this handle.
         Buffer should not be read at this time. */
        return CTSU_ERR_LOCKED;
    }

    /** d. Store the results into the user provided buffer location. */
    if (CTSU_READ_BUFFER_ALL == cmd)
    {
        /* Requesting everything (As is). */
        memcpy(p_arg->p_dest, p_ctsu_ctrl->p_sensor_data, required_size);
    }
    else if (CTSU_READ_SENSOR_OUTPUT == cmd)
    {
        p_src = (uint16_t*) p_ctsu_ctrl->p_sensor_data;
        ctsu_read_output(p_ctsu_ctrl->mode, count, p_offsets, p_dest, p_src);
    }
    else
    {
        switch (cmd)
        {
            case CTSU_READ_SENSOR_COUNT_PRIMARY :
                p_src = ((uint16_t*) p_ctsu_ctrl->p_sensor_data + OFFSET_PRIMARY_SENSOR_COUNT);
            break;
            case CTSU_READ_REFERENCE_COUNT_PRIMARY :
                p_src = (uint16_t*) p_ctsu_ctrl->p_sensor_data + OFFSET_PRIMARY_REFERENCE_COUNT;
            break;
            case CTSU_READ_SENSOR_COUNT_SECONDARY :
                p_src = (uint16_t*) p_ctsu_ctrl->p_sensor_data + OFFSET_SECONDARY_SENSOR_COUNT;
            break;
            case CTSU_READ_REFERENCE_COUNT_SECONDARY :
                p_src = (uint16_t*) p_ctsu_ctrl->p_sensor_data + OFFSET_SECONDARY_REFERENCE_COUNT;
            break;
            default :
                p_src = NULL;
            break;
        }
        ctsu_read_counter(p_ctsu_ctrl->mode, count, p_offsets, p_dest, p_src);
    }

    /** e. Unlock the handle so it can be used by other CTSU functions.*/
    unlock(&p_ctsu_ctrl->lock);
    return ctsu_err;
}
/***********************************************************************************************************************
End of function R_CTSU_Read
***********************************************************************************************************************/

/**
 *

 */
/***********************************************************************************************************************
* Function Name: R_CTSU_Control
* Description  : Change operating parameters of the specified handle.
* Arguments    :
* @param usr_hdl Handle number provided to user by the @ref R_CTSU_Open function.
* @param p_arg Arguments specifying details of things to change.
* Return Value : @return @ref CTSU_SUCCESS, @ref CTSU_ERR_INVALID_PARAM, @ref CTSU_ERR_INVALID_CMD.
***********************************************************************************************************************/
ctsu_err_t R_CTSU_Control(ctsu_ctrl_t *const p_ctrl, ctsu_control_arg_t* p_arg)
{
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    ASSERT( NULL != p_ctrl);
#endif
    /** a. Get the handle */
    ctsu_instance_ctrl_t* p_ctrl_blk = p_ctrl;

#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    /** (Optional) Perform error checking. */
    ASSERT( OPEN == p_ctrl_blk->open );
    ASSERT( p_arg != NULL);
    ASSERT( p_arg->p_context != NULL);
#endif
    ctsu_cmd_t cmd = p_arg->cmd;
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    ASSERT(CTSU_CMD_LAST > cmd);
#endif

    /** b. Read or write value depending upon GET/SET command respectively. */
    /* ************** */
    /* Write commands */
    /* ************** */
    if(CTSU_CMD_GET_ONE_ARG_LAST > cmd)
    {
        ctsu_handle_register_value_get(p_ctrl_blk, cmd, p_arg->p_context);
    }
    else if(CTSU_CMD_GET_TWO_ARG_LAST > cmd)
    {
        ctsu_control_arg_ext_t* p_context = (ctsu_control_arg_ext_t*)p_arg->p_context;
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
        ASSERT(p_ctrl_blk->num_sensors > p_context->offset);
#endif
        ctsu_handle_register_16bit_get(p_ctrl_blk, cmd, p_context->offset, &p_context->value);
    }
    else if(CTSU_CMD_SET_ONE_ARG_LAST > cmd)
    {
        ctsu_handle_register_value_set(p_ctrl_blk, cmd, p_arg->p_context);
        p_ctrl_blk->reload = true;
    }
    else
    {
        /* (CTSU_CMD_SET_TWO_ARG_LAST > cmd)*/
        ctsu_control_arg_ext_t* p_context = (ctsu_control_arg_ext_t*)p_arg->p_context;
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
        ASSERT(p_ctrl_blk->num_sensors > p_context->offset);
#endif
        ctsu_handle_register_16bit_set(p_ctrl_blk, cmd, p_context->offset, p_context->value);
        p_ctrl_blk->reload = true;
    }

    return CTSU_SUCCESS;
}
/***********************************************************************************************************************
End of function R_CTSU_Control
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: R_CTSU_Calibrate
* Description  : Calibrate the CTSU handle. I.e. Bring sensor count ~~ reference counts.
* Arguments    :
* @param usr_hdl Handle number provided to user by the @ref R_CTSU_Open function.
* Return Value :
* @return CTSU error status.
***********************************************************************************************************************/
ctsu_err_t R_CTSU_Calibrate(ctsu_ctrl_t * const p_ctrl)
{
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    ASSERT( NULL != p_ctrl);
#endif
    /* Get the handle */
    ctsu_instance_ctrl_t *const p_ctsu_ctrl = p_ctrl;

    ctsu_err_t ctsu_err = CTSU_SUCCESS;
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    ASSERT( OPEN == p_ctsu_ctrl->open);
    ASSERT( 64 >= p_ctsu_ctrl->num_sensors);
#endif

#if (CTSU_CFG_CALIBRATION_ENABLE > 0)
    uint16_t ctsuso;
    uint32_t sensor_itr;
    uint16_t sensor_count = 0;
    uint16_t reference_count = 0;
    uint16_t num_sensors;
    uint16_t num_sensors_tuned = 0;
    uint64_t tuned_sensor_mask = 0;

    ctsu_err = ctsu_correction_factor(p_ctsu_ctrl);

    num_sensors = p_ctsu_ctrl->num_sensors;

    while(num_sensors_tuned < num_sensors)
    {
        ctsu_err = R_CTSU_Scan(p_ctsu_ctrl);

        if (CTSU_SUCCESS != ctsu_err)
        {
            /* Scan unable to start. */
            return ctsu_err;
        }

        /* Wait until scan is complete. Grab lock for manipulating buffers. */
        while (lock(&p_ctsu_ctrl->lock) == false)
        {
            ;
        }

        if(p_ctsu_ctrl->scan_errors & CTSU_ERR_CTSU_ICOMP)
        {
            /* Problem with TSCAP voltage. */
            ctsu_err = CTSU_ERR_CTSU_ICOMP;
        }

        num_sensors_tuned = 0;

        for(sensor_itr = 0; (sensor_itr < num_sensors) ; sensor_itr++)
        {
            if((((uint64_t)1<<sensor_itr) & tuned_sensor_mask) == ((uint64_t)1<<sensor_itr))
            {
                /* Sensor is already tuned */
                num_sensors_tuned++;
                continue;
            }

            if (CTSU_MODE_SELF_CAPACITANCE == p_ctsu_ctrl->mode)
            {
                sensor_count = ((uint16_t*)(p_ctsu_ctrl->p_sensor_data))[(2*sensor_itr) + 0];
                reference_count = ((uint16_t*)(p_ctsu_ctrl->p_sensor_data))[(2*sensor_itr) + 1];
            }
            else if (CTSU_MODE_MUTUAL_CAPACITANCE == p_ctsu_ctrl->mode)
            {
                sensor_count = ((uint16_t*) (p_ctsu_ctrl->p_sensor_data))[(4 * sensor_itr) + 0];
                reference_count = ((uint16_t*) (p_ctsu_ctrl->p_sensor_data))[(4 * sensor_itr) + 1];
            }
            else
            {
                ;
            }

            ctsuso = p_ctsu_ctrl->p_sensor_settings[sensor_itr].ctsuso0 & 0x3FF;

            if((0x3FF <= ctsuso) || (ctsuso <= 0))
            {
                /* Offset limit reached. Can't make any changes. */
                num_sensors_tuned ++;
                tuned_sensor_mask |= ((uint64_t)1U << sensor_itr);
                continue;
            }

            if(reference_count < (sensor_count - TUNING_UPPER_LIMIT) )
            {
                /* Need to increase sensor offset current amount to bring sensor within range of operation. */
                ctsuso ++;
            }
            else if( reference_count > (sensor_count + TUNING_LOWER_LIMIT) )
            {
                /* Need to reduce sensor offset current amount to bring sensor within range of operation. */
                ctsuso--;
            }
            else
            {
                /* Sensor is within range of operation. */
                num_sensors_tuned++;
                tuned_sensor_mask |= ((uint64_t)1U << sensor_itr);
                continue;
            }

            p_ctsu_ctrl->p_sensor_settings[sensor_itr].ctsuso0 =
                    (uint16_t)(p_ctsu_ctrl->p_sensor_settings[sensor_itr].ctsuso0 & (~0x3FFU));
            p_ctsu_ctrl->p_sensor_settings[sensor_itr].ctsuso0 |= ctsuso;

        }
        unlock(&p_ctsu_ctrl->lock);
    }
#endif    /*(CTSU_CFG_CALIBRATION_ENABLE > 0) */

    return ctsu_err;
}
/***********************************************************************************************************************
End of function R_CTSU_Calibrate
***********************************************************************************************************************/

/**********************************************************************************************************************/
/*                                      Local function definitions                                                    */
/**********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: ctsu_read_output
* Description  : Read the counter value representing capacitance indexed by sensor offsets.
* Arguments    :
* @param mode - CTSU mode of operation. Refer @ref ctsu_mode_t.
* @param num_sensors - Number of sensors provided by argument offsets.
* @param offsets - Array of sensor offsets to read.
* @param p_dest - Location where copy of results should be made.
* @param p_src - Location where results are output by the CTSU.
* Return Value : None
***********************************************************************************************************************/
static void ctsu_read_output(ctsu_mode_t mode, uint16_t num_sensors, uint16_t const * const offsets,void* p_dest, void* p_src)
{
    uint32_t itr;
    uint16_t* p_result_dest = p_dest;
    uint16_t* p_result_src  = p_src;
    uint16_t sen_cnt_2 = 0;
    uint16_t sen_cnt_1 = 0;
    uint16_t offset = 0;

    for(itr = 0; itr < num_sensors; itr++)
    {
        offset = ((offsets[itr] * ((CTSU_MODE_MUTUAL_CAPACITANCE == mode) ? 4U : 2U)) & UINT16_MAX);
        sen_cnt_1 = p_result_src[offset+OFFSET_PRIMARY_SENSOR_COUNT];
        sen_cnt_2 = p_result_src[offset+OFFSET_SECONDARY_SENSOR_COUNT];

        p_result_dest[itr] =
                ((CTSU_MODE_MUTUAL_CAPACITANCE == mode) ?
                (uint16_t)(sen_cnt_2 - sen_cnt_1):(sen_cnt_1));
    }
}
/***********************************************************************************************************************
End of function ctsu_read_output
***********************************************************************************************************************/

/**
 * Read Counter values at for sensor.
 * @param mode CTSU mode of operation.
 * @param num_sensors Number of sensors provided by argument offsets.
 * @param offsets Array of sensor offsets to read.
 * @param p_dest Location where copy of results should be made.
 * @param p_src    Location where results are output by the CTSU.
 */
/***********************************************************************************************************************
* Function Name: ctsu_read_counter
* Description  : Counter values at for sensor.
* Arguments    :
* @param mode - CTSU mode of operation.
* @param num_sensors - Number of sensors provided by argument offsets.
* @param offsets - Array of sensor offsets to read.
* @param p_dest - Location where copy of results should be made.
* @param p_src - Location where results are output by the CTSU.
* Return Value : None
***********************************************************************************************************************/
static void ctsu_read_counter(ctsu_mode_t mode, uint16_t num_sensors, uint16_t const * const offsets,void* p_dest, void* p_src)
{
    uint16_t* p_result_dest = p_dest;
    uint16_t* p_result_src  = p_src;
    uint16_t offset = 0;
    uint32_t itr;
    for(itr = 0; itr < num_sensors; itr++)
    {
        offset = ((offsets[itr] * ((CTSU_MODE_MUTUAL_CAPACITANCE == mode) ? 4U : 2U)) & UINT16_MAX);
        p_result_dest[itr] = p_result_src[offset];
    }
}
/***********************************************************************************************************************
End of function ctsu_read_counter
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: ctsu_handle_register_value_get
* Description  : Get value stored for parameter in control block.
* Arguments    :
* @param p_ctrl_blk - Control block index to read
* @param cmd Control - command issued
* @param p_dest - Location where result must be copied
* Return Value : None
***********************************************************************************************************************/
static void ctsu_handle_register_value_get(ctsu_instance_ctrl_t* p_ctrl_blk, ctsu_cmd_t cmd, void* p_dest)
{
    uint64_t chac_mask;
    uint64_t chtrc_mask;
    switch (cmd)
    {
        case CTSU_CMD_GET_CTSUCR0 :
            *(uint8_t*) p_dest = p_ctrl_blk->p_ctsu_settings->ctsucr0.byte;
            break;
        case CTSU_CMD_GET_CTSUCR1 :
            *(uint8_t*) p_dest = p_ctrl_blk->p_ctsu_settings->ctsucr1.byte;
            break;
        case CTSU_CMD_GET_CTSUSDPRS :
            *(uint8_t*) p_dest = p_ctrl_blk->p_ctsu_settings->ctsusdprs.byte;
            break;
        case CTSU_CMD_GET_CTSUSST :
            *(uint8_t*) p_dest = p_ctrl_blk->p_ctsu_settings->ctsusst.byte;
            break;
        case CTSU_CMD_GET_CTSUCHAC :
            chac_mask = 0;
            chac_mask |= p_ctrl_blk->p_ctsu_settings->ctsuchac4.byte;
            chac_mask <<= 8;
            chac_mask |= p_ctrl_blk->p_ctsu_settings->ctsuchac3.byte;
            chac_mask <<= 8;
            chac_mask |= p_ctrl_blk->p_ctsu_settings->ctsuchac2.byte;
            chac_mask <<= 8;
            chac_mask |= p_ctrl_blk->p_ctsu_settings->ctsuchac1.byte;
            chac_mask <<= 8;
            chac_mask |= p_ctrl_blk->p_ctsu_settings->ctsuchac0.byte;

            *(uint64_t*) p_dest = chac_mask;
            break;
        case CTSU_CMD_GET_CTSUCHTRC :
            chtrc_mask = 0;
            chtrc_mask |= p_ctrl_blk->p_ctsu_settings->ctsuchtrc4.byte;
            chtrc_mask <<= 8;
            chtrc_mask |= p_ctrl_blk->p_ctsu_settings->ctsuchtrc3.byte;
            chtrc_mask <<= 8;
            chtrc_mask |= p_ctrl_blk->p_ctsu_settings->ctsuchtrc2.byte;
            chtrc_mask <<= 8;
            chtrc_mask |= p_ctrl_blk->p_ctsu_settings->ctsuchtrc1.byte;
            chtrc_mask <<= 8;
            chtrc_mask |= p_ctrl_blk->p_ctsu_settings->ctsuchtrc0.byte;

            *(uint64_t*) p_dest = chtrc_mask;
            break;

        case CTSU_CMD_GET_CTSUDCLKC :
            *(uint8_t*) p_dest = p_ctrl_blk->p_ctsu_settings->ctsudclkc.byte;
            break;

        case CTSU_CMD_GET_RESULT_OUTPUT_BUFFER :
            *(void**) p_dest = p_ctrl_blk->p_sensor_data;
            break;

        case CTSU_CMD_GET_MODE :
            *(ctsu_mode_t*) p_dest = p_ctrl_blk->mode;
            break;

        case CTSU_CMD_GET_PCLK :
            *(uint32_t*) p_dest = p_ctrl_blk->pclkb_hz;
            break;

        case CTSU_CMD_GET_SENSOR_COUNT :
            *(uint16_t*) p_dest = p_ctrl_blk->num_sensors;
            break;

        case CTSU_CMD_GET_ERROR_INFORMATION :
            *(uint32_t*) p_dest = p_ctrl_blk->scan_errors;
            break;

        case CTSU_CMD_GET_CALLBACK :
            *(ctsu_callback_t*) p_dest = p_ctrl_blk->p_callback;
            break;

        default :

            break;
    }
}
/***********************************************************************************************************************
End of function ctsu_handle_register_value_get
***********************************************************************************************************************/

/**
 * Set value for parameter in control block.

 */
/***********************************************************************************************************************
* Function Name: ctsu_handle_register_value_set
* Description  : Does an example task. Making this longer just to see how it wraps. Making this long just to see how it
*                wraps.
* Arguments    :
* @param p_ctrl_blk - Control block index to read.
* @param cmd Control - command issued.
* @param value - Location where result must be copied.
* Return Value : count -
*                    How many entries were found
***********************************************************************************************************************/
static void ctsu_handle_register_value_set(ctsu_instance_ctrl_t* p_ctrl_blk, ctsu_cmd_t cmd, void* value)
{
    uint64_t chac;
    uint64_t chtrc;

    switch(cmd)
    {
        case CTSU_CMD_SET_CTSUCR0:
            p_ctrl_blk->p_ctsu_settings->ctsucr0.byte = *(uint8_t*)value;
            break;

        case CTSU_CMD_SET_CTSUCR1:
            p_ctrl_blk->p_ctsu_settings->ctsucr1.byte = *(uint8_t*)value;
            break;

        case CTSU_CMD_SET_CTSUSDPRS:
            p_ctrl_blk->p_ctsu_settings->ctsusdprs.byte = *(uint8_t*)value;
            break;

        case CTSU_CMD_SET_CTSUSST:
        p_ctrl_blk->p_ctsu_settings->ctsusst.byte = *(uint8_t*)value;
            break;

        case CTSU_CMD_SET_CTSUCHAC:
            chac = *(uint64_t*)value;
            p_ctrl_blk->p_ctsu_settings->ctsuchac0.byte = chac & 0xFF;
            chac >>= 8;
            p_ctrl_blk->p_ctsu_settings->ctsuchac1.byte = chac & 0xFF;
            chac >>= 8;
            p_ctrl_blk->p_ctsu_settings->ctsuchac2.byte = chac & 0xFF;
            chac >>= 8;
            p_ctrl_blk->p_ctsu_settings->ctsuchac3.byte = chac & 0xFF;
            chac >>= 8;
            p_ctrl_blk->p_ctsu_settings->ctsuchac4.byte = chac & 0xFF;
            break;

        case CTSU_CMD_SET_CTSUCHTRC:
            chtrc = *(uint64_t*)value;
            p_ctrl_blk->p_ctsu_settings->ctsuchtrc0.byte = chtrc & 0xFF;
            chtrc >>= 8;
            p_ctrl_blk->p_ctsu_settings->ctsuchtrc1.byte = chtrc & 0xFF;
            chtrc >>= 8;
            p_ctrl_blk->p_ctsu_settings->ctsuchtrc2.byte = chtrc & 0xFF;
            chtrc >>= 8;
            p_ctrl_blk->p_ctsu_settings->ctsuchtrc3.byte = chtrc & 0xFF;
            chtrc >>= 8;
            p_ctrl_blk->p_ctsu_settings->ctsuchtrc4.byte = chtrc & 0xFF;
            break;

        case CTSU_CMD_SET_CTSUDCLKC:
            p_ctrl_blk->p_ctsu_settings->ctsudclkc.byte = *(uint8_t*)value;
            break;

        case CTSU_CMD_SET_RESULT_OUTPUT_BUFFER:
            p_ctrl_blk->p_sensor_data = value;
            break;

        case CTSU_CMD_SET_CALLBACK:
            p_ctrl_blk->p_callback = (void(*)(ctsu_callback_arg_t const * const p_arg))value;
            break;

        default:
            break;
    }
}
/***********************************************************************************************************************
End of function ctsu_handle_register_value_set
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: ctsu_handle_register_16bit_get
* Description  : Get 16-bit value stored for parameter in control block at given offset.
* Arguments    :
* @param p_ctrl_blk - Control block index to read.
* @param cmd - Control command issued.
* @param offset - Offset of sensor.
* @param value - Pointer to location where value must be stored.
* Return Value : None
***********************************************************************************************************************/
static void ctsu_handle_register_16bit_get(ctsu_instance_ctrl_t* p_ctrl_blk, ctsu_cmd_t cmd, uint16_t offset, void* value)
{
    if(CTSU_CMD_GET_CTSUSSC == cmd)
    {
        *(uint16_t*) value = p_ctrl_blk->p_sensor_settings[offset].ctsussc;
    }
    else if(CTSU_CMD_GET_CTSUSO0 == cmd)
    {
        *(uint16_t*) value = p_ctrl_blk->p_sensor_settings[offset].ctsuso0;
    }
    else if(CTSU_CMD_GET_CTSUSO1 == cmd)
    {
        *(uint16_t*) value =p_ctrl_blk->p_sensor_settings[offset].ctsuso1;
    }
    else
    {
        ;
    }
}
/***********************************************************************************************************************
End of function ctsu_handle_register_16bit_get
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: ctsu_handle_register_16bit_set
* Description  : Set 16-bit parameter value in control block.
* Arguments    :
* @param p_ctrl_blk - Control block index to read.
* @param cmd - Control command issued.
* @param offset - Offset of sensor.
* @param value - Location where result must be copied.
* Return Value : None
***********************************************************************************************************************/
static void ctsu_handle_register_16bit_set(ctsu_instance_ctrl_t* p_ctrl_blk, ctsu_cmd_t cmd, uint16_t offset, uint16_t value)
{
    if(CTSU_CMD_SET_CTSUSSC == cmd)
    {
        p_ctrl_blk->p_sensor_settings[offset].ctsussc = value;
    }
    else if(CTSU_CMD_SET_CTSUSO0 == cmd)
    {
        p_ctrl_blk->p_sensor_settings[offset].ctsuso0 = value;
    }
    else if(CTSU_CMD_SET_CTSUSO1 == cmd)
    {
        p_ctrl_blk->p_sensor_settings[offset].ctsuso1 = value;
    }
    else
    {
        ;
    }
}
/***********************************************************************************************************************
End of function ctsu_handle_register_16bit_set
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: calculate_sensor_count
* Description  : Calculate the sensor count for CTSU setting
* Arguments    :
* @param mode - Mode of CTSU operation
* @param p_ctsu_settings - Pointer to CTSU settings
* Return Value :
* @return Sensor count
***********************************************************************************************************************/
static uint16_t calculate_sensor_count (ctsu_mode_t mode, ctsu_const_sfrs_t * p_ctsu_settings)
{
    uint8_t sensor_itr;
    uint8_t num_tx = 0;
    uint8_t num_rx = 0;
    uint64_t ch_en_mask = 0;
    uint64_t ch_tx_mask = 0;

    ch_en_mask = p_ctsu_settings->ctsuchac4.byte;
    ch_en_mask <<= 8;
    ch_en_mask |= p_ctsu_settings->ctsuchac3.byte;
    ch_en_mask <<= 8;
    ch_en_mask |= p_ctsu_settings->ctsuchac2.byte;
    ch_en_mask <<= 8;
    ch_en_mask |= p_ctsu_settings->ctsuchac1.byte;
    ch_en_mask <<= 8;
    ch_en_mask |= p_ctsu_settings->ctsuchac0.byte;

    ch_tx_mask = p_ctsu_settings->ctsuchtrc4.byte;
    ch_tx_mask <<= 8;
    ch_tx_mask |= p_ctsu_settings->ctsuchtrc3.byte;
    ch_tx_mask <<= 8;
    ch_tx_mask |= p_ctsu_settings->ctsuchtrc2.byte;
    ch_tx_mask <<= 8;
    ch_tx_mask |= p_ctsu_settings->ctsuchtrc1.byte;
    ch_tx_mask <<= 8;
    ch_tx_mask |= p_ctsu_settings->ctsuchtrc0.byte;

    for(sensor_itr = 0; sensor_itr < LAST_TS; sensor_itr++)
    {
        /* Iterate through to the last sensor */
        if((ch_en_mask & ((uint64_t)1<<sensor_itr)) && (ch_tx_mask & ((uint64_t)1<<sensor_itr)))
        {
            /* CTSU will be operated in mutual mode. */
            num_tx++;
        }
        else if(ch_en_mask & ((uint64_t)1<<sensor_itr))
        {
            /* CTSU will be operated in self mode. */
            num_rx++;
        }
        else
        {
            /* Nothing to do */
            ;
        }
    }

    return (uint16_t)((CTSU_MODE_MUTUAL_CAPACITANCE == mode) ? (num_rx * num_tx) : num_rx);
}
/***********************************************************************************************************************
End of function calculate_sensor_count
***********************************************************************************************************************/
#if (CTSU_CFG_ENABLE_CORRECTION > 0)
/***********************************************************************************************************************
* Function Name: ctsu_get_sdpa_setting
* Description  : Get the SDPA setting for achieving specified target frequency.
* Arguments    :   @param target_freq - Target Drive Frequency
*                  @param pclkb - PCLKB Frequency from CGC
*                  @param ctsuclk - CTSU divisor value in CTSU SFRs.
*                  @return
* Return Value : CTSUSDPA SFR value.
***********************************************************************************************************************/
static uint8_t ctsu_get_sdpa_setting(uint32_t target_freq, uint32_t pclkb, uint8_t ctsuclk)
{
    uint32_t pclkb_actual = pclkb/(1U<<ctsuclk);
    uint8_t sdpa_setting = (uint8_t)(((pclkb_actual / target_freq)>>1U) - 1U);

    return sdpa_setting;
}
/***********************************************************************************************************************
End of function ctsu_get_sdpa_setting
***********************************************************************************************************************/

#if (CTSU_CFG_ENABLE_CORRECTION==1)
/***********************************************************************************************************************
* Function Name: ctsu_correction_factor_first_coefficient
* Description  : Calculate first coefficient for the correction factor.
* Arguments    : sensor_ico_avg - Sensor ICO average value.
* Return Value : first coefficient calculated as:
*                                             (sensor_ico_avg * 1024)       sensor_ico_avg +20
*       correction_1st_coefficient  =  -------------------------------  =  --------------------------
*                                                        40960                            40
***********************************************************************************************************************/
static uint16_t ctsu_correction_factor_first_coefficient(uint16_t sensor_ico_avg)
{
    uint16_t correction_1st_coefficient = (uint16_t)((sensor_ico_avg + 20 ) / 40);
    return correction_1st_coefficient;
}
/***********************************************************************************************************************
End of function ctsu_correction_factor_first_coefficient
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: ctsu_correction_factor_second_std_value
* Description  : Calculate Standard deviation value
* Arguments    : ctsutrmr - Register value from CTSU Trimming register (set by factory).
* Return Value : Standard deviation value calculated as:
*                                  ctsutrmr + 273                             (ctsutrmr + 273) * 2560 *128
* g_correction_2nd_std_val  =  ----------------------- * 40960 *128  =  -------------------------------------
*                                        528                                               33
***********************************************************************************************************************/
static uint16_t ctsu_correction_factor_second_std_value(uint16_t ctsutrmr)
{
    uint32_t temp = (uint32_t)((ctsutrmr + 273) * 9930) + 64;
    return (uint16_t)(temp >> 7);
}
/***********************************************************************************************************************
End of function ctsu_correction_factor_second_std_value
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: ctsu_correction_factor_second_coefficient
* Description  : Calculates second coefficient for CTSU correction factor based on standard deviation value, and
*                   second sensor ico average reading.
* Arguments    : sensor_ico_avg - second sensor ico average reading
*                second_std_val - Standard deviation value
* Return Value : second coefficient calculated as:
*                                      g_correction_2nd_val
*  g_correction_2nd_coefficient  =  -------------------------- * 1024
*                                    g_correction_2nd_std_val
***********************************************************************************************************************/
static uint16_t ctsu_correction_factor_second_coefficient(uint16_t sensor_ico_avg, uint16_t second_std_val)
{
    uint16_t retval = (uint16_t)(((sensor_ico_avg << 10) + (second_std_val/2)) / second_std_val);
    return retval;
}
/***********************************************************************************************************************
End of function ctsu_correction_factor_second_coefficient
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: ctsu_correction_16pt_table_create
* Description  : Creates an interpolated 16-point table of sensor ICO values and coefficients.
* Arguments    : ideal_sensor_ico_values_16pt - ideal sensor ICO curve
*                coeff_1 - 1st correction coefficient
*                coeff_2 - 2nd correction coefficient
*                std_2 - Standard deviation value
*                table16pt - Sensor ICO values expected.
*                coeff16pt - Correction coefficients to be applied.
* Return Value : None, (Return from argument := table16pt and coeff16pt)
***********************************************************************************************************************/
static void ctsu_correction_16pt_table_create(uint16_t const * const ideal_sensor_ico_values_16pt,
                                        uint16_t coeff_1,
                                        uint16_t coeff_2,
                                        uint16_t std_2,
                                        uint16_t * const table16pt,
                                        uint16_t * const coeff16pt)
{
    uint16_t flag;
    uint32_t diff;
    uint16_t correction_pt[16];

    if(coeff_2 > coeff_1)
    {
        flag = 0;
        diff = (uint32_t)(coeff_2 - coeff_1);
    }
    else
    {
        flag = 1;
        diff = (uint32_t)(coeff_1 - coeff_2);
    }

    /*         diff_coefficient * 40960                                                                               */
    /*     ----------------------------------                                                                         */
    /*      40960 - g_correction_2nd_std_val                                                                          */

    diff = diff * 40960;
    diff = (uint32_t)(diff/(uint32_t)(40960 - std_2));

    /*                                                                 fill_diff * N                                  */
    /*     g_correction_16point  =  g_correction_1st_coefficient +(-) ---------------                                 */
    /*                                                                      16                                        */

    for(uint8_t itr = 1; itr < 16; itr++)
    {
        correction_pt[itr] = (0 == flag) ?
                                (uint16_t)(coeff_1 + ((diff * itr) >> 4))
                              : (uint16_t)(coeff_1 - ((diff * itr) >> 4));
    }

    correction_pt[0] = coeff_1;

    for(uint8_t itr = 0; itr < 16; itr++)
    {
        uint32_t temp = (uint32_t)(correction_pt[itr] * ideal_sensor_ico_values_16pt[itr]);
        table16pt[itr] = (uint16_t)((temp + 512) >> 10);
        coeff16pt[itr] = (uint16_t)(1000000/correction_pt[15-itr]);
    }

}


/***********************************************************************************************************************
* Function Name: ctsu_corrected_value
* Description  : Returns the corrected value for the provided CTSU measurement.
* Arguments    : input - Input value to the algorithm
*                magnification - Magnification factor calculated for the sensor
*                table61pt - Table of Sensor ICO values
*                coeff61pt - Table of correction coefficients
* Return Value : Corrected Sensor ICO value.
***********************************************************************************************************************/
static uint16_t ctsu_corrected_value(uint16_t input,
                                int8_t magnification,
                                uint16_t const * const table61pt,
                                uint16_t const * const coeff61pt)
{
    uint8_t loop;
    uint8_t loop_coef;
    uint32_t cmp_val = 0;
    uint32_t correct_box;
    uint32_t correct_box2;
    uint16_t correction_sensor_cnt;

    if(0 > magnification)
    {
        cmp_val = (uint32_t)(((-1)* magnification) * input) ;
        cmp_val /= 10;
    }
    else
    {
        cmp_val = (uint32_t)((input * 10) / magnification);
    }
    correct_box = input;

    if(table61pt[60]>= cmp_val)
    {
        correct_box2 = correct_box*coeff61pt[0];
        correction_sensor_cnt = (uint16_t)(correct_box2>>10);
    }
    else
    {
        if (table61pt[29] <= cmp_val)
        {
            if (table61pt[14] <= cmp_val)
            {
                for (loop = 0, loop_coef = 60; loop < 15; loop++)
                {
                    if (table61pt[loop] <= cmp_val)
                    {
                        correct_box2          = correct_box * coeff61pt[loop_coef];
                        correction_sensor_cnt = (uint16_t)(correct_box2 >> 10);
                        break;
                    }
                    loop_coef--;
                }
            }
            else
            {
                for (loop = 15, loop_coef = 45; loop < 30; loop++)
                {
                    if (table61pt[loop] <= cmp_val)
                    {
                        correct_box2          = correct_box * coeff61pt[loop_coef];
                        correction_sensor_cnt = (uint16_t)(correct_box2 >> 10);
                        break;
                    }
                    loop_coef--;
                }
            }
        }
        else
        {
            if (table61pt[44] <= cmp_val)
            {
                for (loop = 30, loop_coef = 30; loop < 45; loop++)
                {
                    if (table61pt[loop] <= cmp_val)
                    {
                        correct_box2          = correct_box * coeff61pt[loop_coef];
                        correction_sensor_cnt = (uint16_t)(correct_box2 >> 10);
                        break;
                    }
                    loop_coef--;
                }
            }
            else
            {
                for (loop = 45, loop_coef = 15; loop < 60; loop++)
                {
                    if (table61pt[loop] <= cmp_val)
                    {
                        correct_box2          = correct_box * coeff61pt[loop_coef];
                        correction_sensor_cnt = (uint16_t)(correct_box2 >> 10);
                        break;
                    }
                    loop_coef--;
                }
            }
        }
    }

    return correction_sensor_cnt;
}
/***********************************************************************************************************************
End of function ctsu_corrected_value
***********************************************************************************************************************/
#endif

/***********************************************************************************************************************
* Function Name: ctsu_correction_get_avg_sensor_ico_value
* Description  : Does an example task. Making this longer just to see how it wraps. Making this long just to see how it
*                wraps.
* Arguments    : tune_hdl - CTSU Control Block to be used for Scanning.
*                p_result - Location where the result must be output.
* Return Value : See R_CTSU_Scan error return values.
***********************************************************************************************************************/
static ctsu_err_t ctsu_correction_get_avg_sensor_ico_value(ctsu_instance_ctrl_t *const p_ctsu_ctrl, uint16_t * const p_result)
{
    uint16_t scan_count = 0;
    uint32_t sensor_ico = 0;

    ctsu_err_t ctsu_err = CTSU_SUCCESS;

    uint16_t const * const ctsu_result = p_ctsu_ctrl->p_sensor_data;

    while(scan_count < CTSU_CORRECTION_SCAN_COUNT)
    {
        ctsu_err = R_CTSU_Scan(p_ctsu_ctrl);

        if (CTSU_SUCCESS != ctsu_err)
        {
            return ctsu_err;
        }

        /* Wait until scan is complete. Grab lock for manipulating buffers. */
        while (lock(&p_ctsu_ctrl->lock) == false)
        {
            /* GSCE CODAN Error Elimination: Do Nothing. */;
        }

        sensor_ico += ctsu_result[0];
        scan_count++;

        unlock(&p_ctsu_ctrl->lock);
    }

    sensor_ico /= scan_count;

    p_result[0] = (uint16_t)(sensor_ico & UINT16_MAX);

    return CTSU_SUCCESS;
}
/***********************************************************************************************************************
End of function ctsu_correction_get_avg_sensor_ico_value
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: ctsu_correction_create_bins
* Description  : Create interpolated data over 61 points.
* Arguments    : table16pt - Table of 16 sensor ICO values
*                coeff16pt - Table of 16 correction coefficients
*                table61pt - Table of 61 sensor ICO values
*                coeff61pt - Table of 61 correction coefficients
* Return Value : table61pt, and coeff61pt.
***********************************************************************************************************************/
static void ctsu_correction_create_bins(uint16_t const * const table16pt,
                                        uint16_t const * const coeff16pt,
                                        uint16_t * const table61pt,
                                        uint16_t * const coeff61pt)
{
    for (uint16_t itr = 0; itr < 15; itr++)
    {
        uint16_t delta;
        delta = (uint16_t)(((table16pt[itr] - table16pt[itr+1]) + 2) / 4);

        uint16_t offset = (uint16_t)(itr*4);
        table61pt[offset + 0] = table16pt[itr];
        table61pt[offset + 1] = (uint16_t)(table16pt[itr] - delta);
        table61pt[offset + 2] = (uint16_t)(table16pt[itr] - (delta*2));
        table61pt[offset + 3] = (uint16_t)(table16pt[itr] - (delta*3));

        if(coeff16pt[1] > coeff16pt[0])
        {
            delta = (uint16_t)(((coeff16pt[itr+1] - coeff16pt[itr]) +2) / 4);
            coeff61pt[offset + 0] = coeff16pt[itr];
            coeff61pt[offset + 1] = (uint16_t)(coeff16pt[itr] + delta);
            coeff61pt[offset + 2] = (uint16_t)(coeff16pt[itr] + (delta * 2));
            coeff61pt[offset + 3] = (uint16_t)(coeff16pt[itr] + (delta * 3));
        }
        else
        {
            delta = (uint16_t)(((coeff16pt[itr] - coeff16pt[itr+1]) +2) / 4);
            coeff61pt[offset + 0] = coeff16pt[itr];
            coeff61pt[offset + 1] = (uint16_t)(coeff16pt[itr] - delta);
            coeff61pt[offset + 2] = (uint16_t)(coeff16pt[itr] - (delta * 2));
            coeff61pt[offset + 3] = (uint16_t)(coeff16pt[itr] - (delta * 3));
        }
    }

    table61pt[60] = table16pt[15];
    coeff61pt[60] = coeff16pt[15];
}
/***********************************************************************************************************************
End of function ctsu_correction_create_bins
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: ctsu_correction_set_magnification
* Description  : Calculate a correction magnification factor
* Arguments    : buffer -  array of int8_t holding magnification factors. (return value)
*                p_setting - waveform drive settings for the touch sensor.
*                sensor count - number of touch sensors
*                pclkb_hz - PCLKB Frequency
* Return Value : None
***********************************************************************************************************************/
static void ctsu_correction_set_magnification(int8_t * const p_buffer,
                                                ctsu_sensor_setting_t const * const p_setting,
                                                uint16_t const sensor_count,
                                                uint32_t const pclkb_hz)
{
    for(uint16_t itr = 0; itr < sensor_count; itr++)
    {
        uint16_t   measurement_period;
        int8_t snum = (int8_t)((p_setting[itr].ctsuso0 & 0xFC00)>>10);
        int8_t sdpa = (int8_t)((p_setting[itr].ctsuso1 & 0x1F00)>>8);
        uint8_t mea_freq = (uint8_t)(((pclkb_hz/1000000U) * 10U) /(uint32_t)(2*(sdpa+1)));

        switch (mea_freq)
        {
            case 40:                                                   /* 4.0MHz    32MHz / 8     24MHz / 6  */
                measurement_period =  (uint16_t)(625 * (snum + 1));
                break;
            case 33:                                                   /* 3.3MHz    27MHz / 8  */
                measurement_period =  (uint16_t)(750 * (snum + 1));
                break;
            case 20:                                                   /* 2.0MHz    32MHz / 16    24MHz / 12  */
                measurement_period = (uint16_t)(1250 * (snum + 1));
                break;
            case 16:                                                   /* 1.6MHz    27MHz / 16 */
                measurement_period = (uint16_t)(1500 * (snum + 1));
                break;
            case 10:                                                   /* 1.0MHz    32MHz / 32    24MHz / 24  */
                measurement_period = (uint16_t)(2500 * (snum + 1));
                break;
            case 8:                                                    /* 0.8MHz    27MHz / 32 */
                measurement_period = (uint16_t)(3000 * (snum + 1));
                break;
            case 5:                                                    /* 0.5MHz    32MHz / 64    24MHz / 48  */
                measurement_period = (uint16_t)(5000 * (snum + 1));
                break;
            case 4:                                                    /* 0.4MHz    27MHz / 64 */
                measurement_period = (uint16_t)(6000 * (snum + 1));
                break;
            default:
                break;
        }

        p_buffer[itr] = (5000 <= measurement_period) ? (int8_t)(measurement_period/500):
                                                        (int8_t)((-1)*(int8_t)(50000 / measurement_period));
    }
}
/***********************************************************************************************************************
End of function ctsu_correction_set_magnification
***********************************************************************************************************************/
#endif  /* (CTSU_CFG_ENABLE_CORRECTION > 0) */

#if (CTSU_CFG_CALIBRATION_ENABLE > 0)
/***********************************************************************************************************************
* Function Name: ctsu_correction_factor
* Description  : Calculate Correction Factor for Control Block.
* Arguments    :
* @param usr_hdl Index to Control Block in array.
*
* Return Value :
* @return @ref CTSU_SUCCESS, CTSU_ERR_CORRECTION_FACTOR
* @note When CTSU_CFG_CALIBRATION_ENABLE is set to 1, algorithm specified in R01AN3610EJ0100 is implemented.
***********************************************************************************************************************/
static ctsu_err_t ctsu_correction_factor(ctsu_instance_ctrl_t * const p_ctsu_ctrl)
{
    ctsu_err_t ctsu_err = CTSU_SUCCESS;
#if (CTSU_CFG_PARAM_CHECKING_ENABLE > 0)
    ASSERT( OPEN == p_ctsu_ctrl->open);
    ASSERT( 64 >= p_ctsu_ctrl->num_sensors);
#endif

#if (CTSU_CFG_ENABLE_CORRECTION > 0)
    /**
     * CTSU Sensor ICO Correction using CTSUTRMR register.
     * Refer: R01AN3610EJ0100
     */


    /* Set the magnification factor */
    ctsu_correction_set_magnification(p_ctsu_ctrl->p_magnification_sensor,
            p_ctsu_ctrl->p_sensor_settings,
            p_ctsu_ctrl->num_sensors,
            p_ctsu_ctrl->pclkb_hz);

    uint8_t ctsutrmr = HW_CTSU_CTSUTRMRGet();

    typedef union
    {
       uint8_t byte[5];
       uint64_t dlong;
    }ctsu_chxx_t;

    ctsu_chxx_t chac;
    chac.dlong = 0;

    if (CTSU_MODE_SELF_CAPACITANCE == p_ctsu_ctrl->mode)
    {
        chac.byte[0] = p_ctsu_ctrl->p_ctsu_settings->ctsuchac0.byte;
        chac.byte[1] = p_ctsu_ctrl->p_ctsu_settings->ctsuchac1.byte;
        chac.byte[2] = p_ctsu_ctrl->p_ctsu_settings->ctsuchac2.byte;
        chac.byte[3] = p_ctsu_ctrl->p_ctsu_settings->ctsuchac3.byte;
        chac.byte[4] = p_ctsu_ctrl->p_ctsu_settings->ctsuchac4.byte;
    }
    else if(CTSU_MODE_MUTUAL_CAPACITANCE == p_ctsu_ctrl->mode)
    {
        chac.byte[0] = p_ctsu_ctrl->p_ctsu_settings->ctsuchtrc0.byte;
        chac.byte[1] = p_ctsu_ctrl->p_ctsu_settings->ctsuchtrc1.byte;
        chac.byte[2] = p_ctsu_ctrl->p_ctsu_settings->ctsuchtrc2.byte;
        chac.byte[3] = p_ctsu_ctrl->p_ctsu_settings->ctsuchtrc3.byte;
        chac.byte[4] = p_ctsu_ctrl->p_ctsu_settings->ctsuchtrc4.byte;
    }
    else
    {
        ;
    }

    /* Enable only one sensor */
    for(uint64_t itr = 1; itr > 0 ;itr <<= 1)
    {
        if((chac.dlong & itr) > 0)
        {
            chac.dlong &= itr;
            break;
        }
    }

    ASSERT(chac.dlong > 0);

    const uint8_t ctsuclk = (p_ctsu_ctrl->p_ctsu_settings->ctsucr1.byte & 0x30);

    ctsu_const_sfrs_t ctsu_const_sfrs_correction =
    {
        .ctsucr0.byte   = 0,
        .ctsucr1.byte   = (0x43) | ctsuclk,
        .ctsusdprs.byte = 0x63,
        .ctsusst.byte   = 0x10,
        .ctsuchac0.byte = chac.byte[0],
        .ctsuchac1.byte = chac.byte[1],
        .ctsuchac2.byte = chac.byte[2],
        .ctsuchac3.byte = chac.byte[3],
        .ctsuchac4.byte = chac.byte[4],
        .ctsuchtrc0.byte = 0,
        .ctsuchtrc1.byte = 0,
        .ctsuchtrc2.byte = 0,
        .ctsuchtrc3.byte = 0,
        .ctsuchtrc4.byte = 0,
        .ctsudclkc.byte = 0x30,
    };

    uint16_t ctsu_result[4];

    ctsu_sensor_setting_t sensor_drive_setting_correction[1] =
    {
        [0] = {.ctsussc = 0x0700, .ctsuso0 = 0x0000, .ctsuso1 = 0x200F},
    };

    const uint16_t ctsusdpa = ctsu_get_sdpa_setting(500000, p_ctsu_ctrl->pclkb_hz, ctsuclk);

    sensor_drive_setting_correction[0].ctsuso1 =
            (uint16_t)(sensor_drive_setting_correction[0].ctsuso1 | (ctsusdpa << 8));

    memset(ctsu_result, 0, sizeof(ctsu_result));

    const ctsu_cfg_t ctsu_correction_cfg =
    {
         .p_ctsu_settings = &ctsu_const_sfrs_correction,
         .p_sensor_settings = &sensor_drive_setting_correction[0],
         .p_sensor_data = &ctsu_result[0],
         .pclkb_hz = p_ctsu_ctrl->pclkb_hz,
         .p_callback = NULL,
    };

    ctsu_instance_ctrl_t ctsu_ctrl;
    memset(&ctsu_ctrl, 0, sizeof(ctsu_ctrl));

    ctsu_err = R_CTSU_Open(&ctsu_ctrl, &ctsu_correction_cfg);

    /* Following code enables CTSUERRS.CTSUSPMD=2, CTSUTSOC=1*/
    {
        uint16_t ctsuerrs = HW_CTSU_CTSUERRSGet();
        const uint16_t mask = CTSUERRS_ENABLE_CALIBRATION_MODE;
        ctsuerrs |= mask;
        HW_CTSU_CTSUERRSSet(ctsuerrs);
    }

    uint16_t avg_sensor_ico[2] = {0,0};

    /* Get average Primary CTSUSC value */
    ctsu_err = ctsu_correction_get_avg_sensor_ico_value(&ctsu_ctrl, &avg_sensor_ico[0]);

    /* Change CTSUTRMR Value to 0xFF*/
    HW_CTSU_CTSUTRMRSet(0xFF);

    /* Get average Primary CTSUSC value */
    ctsu_err = ctsu_correction_get_avg_sensor_ico_value(&ctsu_ctrl, &avg_sensor_ico[1]);

    /* Restore CTSUTRMR Value */
    HW_CTSU_CTSUTRMRSet(ctsutrmr);

    /* Following code sets CTSUERRS.CTSUSPMD=0, CTSUTSOC=0*/
    {
        uint16_t ctsuerrs = HW_CTSU_CTSUERRSGet();
        const uint16_t mask = (uint16_t)(~CTSUERRS_ENABLE_CALIBRATION_MODE);
        ctsuerrs &= mask;
        HW_CTSU_CTSUERRSSet(ctsuerrs);
    }

    /* Create 1st Coefficient */
    uint16_t correction_coefficient[2];
    correction_coefficient[0] = ctsu_correction_factor_first_coefficient(avg_sensor_ico[0]);

    /* Create 2nd standard value */
    uint16_t correction_std_val_2nd = ctsu_correction_factor_second_std_value(ctsutrmr);

    /* Create 2nd Coefficient value */
    correction_coefficient[1] = ctsu_correction_factor_second_coefficient(avg_sensor_ico[1], correction_std_val_2nd);

    uint16_t table16pt[16];
    uint16_t coeff16pt[16];

    memset(&table16pt, 0, sizeof(table16pt));
    memset(&coeff16pt, 0, sizeof(coeff16pt));

    /* Create 16 point table */
    ctsu_correction_16pt_table_create(p_ctsu_ctrl->p_correction_ideal_sensor_ico,
                                        correction_coefficient[0],
                                        correction_coefficient[1],
                                        correction_std_val_2nd,
                                        &table16pt[0],
                                        &coeff16pt[0]);

    /* Create Interpolated table and coefficients */
    ctsu_correction_create_bins(&table16pt[0],
                                &coeff16pt[0],
                                p_ctsu_ctrl->p_linear_interpolation_table,
                                p_ctsu_ctrl->p_linear_interpolation_coeff);

#if defined(UNITY_TESTING)
    memcpy(&linear_interpolation_table[0],
            p_ctsu_ctrl->p_linear_interpolation_table,
            sizeof(linear_interpolation_table));
    memcpy(&linear_interpolation_coeff[0],
            p_ctsu_ctrl->p_linear_interpolation_coeff,
            sizeof(linear_interpolation_coeff));
#endif

    /* Close the configuration */
    ctsu_err = R_CTSU_Close(&ctsu_ctrl);
#endif /* (CTSU_CFG_ENABLE_MEASUREMENT_CORRECTION > 0) */

    return ctsu_err;
}
/***********************************************************************************************************************
End of function ctsu_correction_factor
***********************************************************************************************************************/
#endif /* (CTSU_CFG_CALIBRATION_ENABLE > 0) */


/**********************************************************************************************************************/
/*                                                 Interrupt service routines                                               */
/**********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: ctsu_write_isr
* Description  : Interrupt service routine definition for the CTSUWR interrupt.
* Arguments    : None
* Return Value : Control block identifier which supposedly initiated the scan.
***********************************************************************************************************************/
uint32_t ctsu_write_isr(void)
{
    /** a. Grab the a handle being used by the CTSU. */
    ctsu_instance_ctrl_t * const p_ctsu_ctrl = p_scan_ctrl;

    /** b. Write CTSU settings from RAM to SFR */
    if(sensor_wr_irq_itr < p_ctsu_ctrl->num_wr_irq_requests)
    {
        /* Write iterator is valid. */
        HW_CTSU_CTSUSSCSet(p_ctsu_ctrl->p_sensor_settings[sensor_wr_irq_itr].ctsussc);
        HW_CTSU_CTSUSO0Set(p_ctsu_ctrl->p_sensor_settings[sensor_wr_irq_itr].ctsuso0);
        HW_CTSU_CTSUSO1Set(p_ctsu_ctrl->p_sensor_settings[sensor_wr_irq_itr].ctsuso1);
    }
    else
    {
        /* Write iterator is invalid. Fill SFRs with values so that CTSU can go into error condition. */
        HW_CTSU_CTSUSSCSet(0);
        HW_CTSU_CTSUSO0Set(0);
        HW_CTSU_CTSUSO1Set(0);
    }

    /** c. Increment write IRQ iterator */
    sensor_wr_irq_itr++;

    return (uint32_t)p_scan_ctrl;
}
/***********************************************************************************************************************
End of function ctsu_write_isr
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: ctsu_read_isr
* Description  : Interrupt service routine definition for CTSURD interrupt.
* Arguments    : None
* Return Value : Control block identifier which supposedly initiated the scan.
***********************************************************************************************************************/
uint32_t ctsu_read_isr(void)
{
    /** a. Grab the a handle being used by the CTSU. */
    ctsu_instance_ctrl_t * const p_ctsu_ctrl = p_scan_ctrl;

    /** b. Get location in RAM where results should be stored*/
    uint16_t* p_result = (uint16_t*)p_ctsu_ctrl->p_sensor_data;

    const uint16_t max_rd_itr = (uint16_t)(p_ctsu_ctrl->num_rd_irq_requests<<1U);

    /** c. Copy CTSU scan results from SFR to RAM */
    if((uint16_t)(sensor_rd_irq_itr + 1U) < max_rd_itr)
    {
        /* Read iterator is valid */
        p_result[sensor_rd_irq_itr + 0] = HW_CTSU_CTSUSCGet();
        p_result[sensor_rd_irq_itr + 1] = HW_CTSU_CTSURCGet();
    }
    else
    {
        /* Read iterator is invalid. Read out the CTSU information so state machine can proceed. */
        HW_CTSU_CTSUSCGet();
        HW_CTSU_CTSURCGet();
    }

    /** d. Increment read IRQ iterator */
    sensor_rd_irq_itr+=2;

    return (uint32_t)p_scan_ctrl;
}
/***********************************************************************************************************************
End of function ctsu_read_isr
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: ctsu_end_isr
* Description  : Interrupt service routine definition for CTSUFN interrupt.
* Arguments    : None.
* Return Value : Control block identifier which supposedly initiated the scan.
***********************************************************************************************************************/
uint32_t ctsu_end_isr(void)
{
    ctsu_callback_arg_t args;
    args.event_mask = CTSU_EVENT_SCAN_COMPLETED;
    args.info = 0;

    /** Read the CTSU SFRs which indicate errors encountered from the latest scan.
     * Record and Clear if any errors occurred during scan. */
    if(HW_CTSU_CTSUSTGetBitCTSUROVF() == 1)
    {
        args.info |= CTSU_ERR_CTSU_RC_OVF;
        HW_CTSU_CTSUCR0SetBitCTSUINIT(1);
    }

    if(HW_CTSU_CTSUSTGetBitCTSUSOVF() == 1)
    {
        args.info |= CTSU_ERR_CTSU_SC_OVF;
        HW_CTSU_CTSUCR0SetBitCTSUINIT(1);
    }

    if(HW_CTSU_CTSUERRSGetBitCTSUICOMP() == 1)
    {
        args.info |= CTSU_ERR_CTSU_ICOMP;
        uint8_t ctsucr1 = HW_CTSU_CTSUCR1Get();

        /* Hardware note on CTSU LPF Capacitance Charging Control/TSCAP Voltage Error Monitor */
        HW_CTSU_CTSUCR1Set(ctsucr1 & (uint8_t)(~0x03U));
        HW_CTSU_CTSUCR1Set(ctsucr1);
    }

#if (CTSU_CFG_WAIT_STATE_POWER_SAVING_ENABLE==true)
    /* Refer CTSUSNZ Bit (CTSU Wait State Power-Saving Enable) */
    HW_CTSU_CTSUCR0SetBitCTSUSNZ(1);
#endif

    /** Grab the a handle being used by the CTSU. */
    ctsu_instance_ctrl_t * const p_ctsu_ctrl = p_scan_ctrl;
    args.handle_num = p_ctsu_ctrl;
#if (CTSU_CFG_ENABLE_CORRECTION > 0)
    if ((NULL != p_ctsu_ctrl->p_correction_ideal_sensor_ico)
            && (p_ctsu_ctrl->p_linear_interpolation_table[61] > 0))
    {
        /* Ready to perform corrections */
        uint16_t multiplier = (CTSU_MODE_SELF_CAPACITANCE == p_ctsu_ctrl->mode) ? 2U : 4U;
        uint16_t * const input = p_ctsu_ctrl->p_sensor_data;
        for(uint16_t itr = 0; itr < p_ctsu_ctrl->num_sensors; itr++)
        {
            /* Primary Sensor Counter */
            int8_t magnifier = p_ctsu_ctrl->p_magnification_sensor[itr];
            input[(itr*multiplier) + 0] = ctsu_corrected_value(input[(itr*multiplier) + 0],
                                                               magnifier,
                                                               p_ctsu_ctrl->p_linear_interpolation_table,
                                                               p_ctsu_ctrl->p_linear_interpolation_coeff);
            input[(itr*multiplier) + 1] = (CTSU_MODE_SELF_CAPACITANCE == p_ctsu_ctrl->mode) ?
                    (p_ctsu_ctrl->p_correction_ideal_sensor_ico[_07_2UA]):
                    (p_ctsu_ctrl->p_correction_ideal_sensor_ico[_04_8UA]);

            if (CTSU_MODE_MUTUAL_CAPACITANCE == p_ctsu_ctrl->mode)
            {
                /* Secondary Sensor Counter */
                input[(itr*multiplier) + 2] = ctsu_corrected_value(input[(itr*multiplier) + 2],
                                                                   magnifier,
                                                                   p_ctsu_ctrl->p_linear_interpolation_table,
                                                                   p_ctsu_ctrl->p_linear_interpolation_coeff);
                input[(itr*multiplier) + 3] = p_ctsu_ctrl->p_correction_ideal_sensor_ico[_04_8UA];
            }
        }

    }
#endif

    p_ctsu_ctrl->scan_errors = args.info;

    /** Unlock the handle so it can be used by other CTSU functions.*/
    unlock(&p_ctsu_ctrl->lock);

    if (NULL != p_ctsu_ctrl->p_callback)
    {
        /** Perform callback to the upper layer. */
        args.handle_num = p_scan_ctrl;
        p_ctsu_ctrl->p_callback(&args);
    }


    /** Unlock the hardware locked by a call to @ref R_CTSU_Scan */
    unlock (&BSP_HW_LOCK_CTSU);

    /** f. Reset the ISR iterators */
    sensor_wr_irq_itr = 0;
    sensor_rd_irq_itr = 0;

    return (uint32_t)p_scan_ctrl;
}
/***********************************************************************************************************************
End of function ctsu_end_isr
***********************************************************************************************************************/
