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
 * Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
 ***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @file
 ***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @addtogroup Touch_Button
 * @brief Driver for operating TS Pins as buttons. Provides the ability to generate events per button.
 *
 * It implements the following interface:
 *  - @ref Touch_Button interface defined in r_touch_button_if.h
 * @{
 ***********************************************************************************************************************/
/***********************************************************************************************************************
 Includes
 ***********************************************************************************************************************/

#include <string.h>
#include "bsp_api.h"
#include "sf_touch_button.h"
#include "sf_touch_button_private.h"

/***********************************************************************************************************************
 Macro definitions
 ***********************************************************************************************************************/
#if (BSP_CFG_ASSERT==2)
#define ASSERT(test)    assert(test)
#else
#define ASSERT(test)    if((test)==false){return TOUCH_BUTTON_ERR_INVALID_PARAM;}
#endif

#define OPEN            (0x4F50454e)

#define TOUCH_BUTTON_CODE_VERSION_MAJOR (2)
#define TOUCH_BUTTON_CODE_VERSION_MINOR (00)

#ifndef LAST_TS
#if (BSP_MCU_RX113==1)
#define LAST_TS     (11)
#elif (BSP_MCU_RX130==1)
#define LAST_TS     (35)
#elif (BSP_MCU_RX230==1)
#define LAST_TS     (35)
#elif (BSP_MCU_RX231==1)
#define LAST_TS     (35)
#endif
#endif  /* LAST_TS */

#define NUM_CTRL_BLOCKS (sizeof(pvt_button_ctrl_blk)/sizeof(pvt_button_ctrl_blk[0]))

/***********************************************************************************************************************
 Typedef definitions
 ***********************************************************************************************************************/


static touch_button_instance_ctrl_t * pvt_button_ctrl_blk[BUTTON_CFG_MAX_CONTROL_BLOCK_COUNT];

/***********************************************************************************************************************
 Private function prototypes
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 Private global variables
 ***********************************************************************************************************************/
#if (MULTI_TOUCH_BUTTON_WAIT_FOR_RELEASE > 0)
uint16_t num_buttons_active = 0;
#endif

/***********************************************************************************************************************
 Global Variables
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 Functions
 ***********************************************************************************************************************/
static void touch_button_callback(touch_callback_arg_t const * const p_arg);
static uint8_t already_open(touch_button_instance_ctrl_t const*const p_ctrl_1, touch_button_instance_ctrl_t const*const p_ctrl_2);
static bool debounce(uint16_t * p_current, uint16_t const threshold);
static touch_button_err_t get_control_block_parameter(touch_button_instance_ctrl_t * p_ctrl, touch_button_control_arg_t * const p_arg);
static touch_button_err_t set_control_block_parameter(touch_button_instance_ctrl_t * p_ctrl, touch_button_control_arg_t * const p_arg);
static void touch_button_update(touch_button_instance_ctrl_t * const p_ctrl, touch_button_callback_arg_t * const p_arg);


static const ssp_version_t touch_button_version =
{
    .api_version_major  = TOUCH_BUTTON_API_VERSION_MAJOR,
    .api_version_minor  = TOUCH_BUTTON_API_VERSION_MINOR,
    .code_version_major = TOUCH_BUTTON_CODE_VERSION_MAJOR,
    .code_version_minor = TOUCH_BUTTON_CODE_VERSION_MINOR,
};

touch_button_api_t const g_touch_button_on_touch_button =
{
  .open  = R_TOUCH_ButtonOpen,
  .close = R_TOUCH_ButtonClose,
  .control = R_TOUCH_ButtonControl,
  .versionGet = R_TOUCH_ButtonGetVersion,
};

/***********************************************************************************************************************
* Function Name: R_TOUCH_ButtonGetVersion
* Description  : Get the version number for the driver.
* Arguments    : None
* Return Value : Version number of driver in 32-bits.
***********************************************************************************************************************/
ssp_err_t R_TOUCH_ButtonGetVersion(ssp_version_t * const p_version)
{
#if (BUTTON_CFG_PARAM_CHECKING_ENABLE == true)
    SSP_ASSERT(NULL != p_version);
#endif
    p_version->version_id =  touch_button_version.version_id;
    return SSP_SUCCESS;
}
/***********************************************************************************************************************
End of function R_TOUCH_ButtonGetVersion
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: R_TOUCH_ButtonOpen
* Description  : Open a TOUCH Sensor Button with the configuration provided.
* Arguments    : handle -
*                    Pointer to location where user wants the index of the Button Control block to be returned.
*                p_cfg -
*                    Pointer to button configuration information.
* Return Value : TOUCH_BUTTON_SUCCESS, TOUCH_BUTTON_ERR_INVALID_PARAM, TOUCH_BUTTON_ERR_INSUFFICIENT_MEMORY
***********************************************************************************************************************/
touch_button_err_t R_TOUCH_ButtonOpen(touch_button_ctrl_t * const handle, touch_button_cfg_t const * const p_cfg)
{
    touch_err_t touch_err;
#if (BUTTON_CFG_PARAM_CHECKING_ENABLE == true)
    ASSERT(NULL != handle);
    ASSERT(NULL != p_cfg);
    ASSERT(NULL != p_cfg->p_touch);
#endif

    touch_cfg_t touch_cfg =
    {
        /* Initializing constants to get rid of warnings */
        .p_ctsu = p_cfg->p_touch->p_cfg->p_ctsu,
        .p_common = p_cfg->p_touch->p_cfg->p_common,
        .p_sensor = p_cfg->p_touch->p_cfg->p_sensor,
        .p_ignored = p_cfg->p_touch->p_cfg->p_ignored,
    };

    touch_button_instance_ctrl_t * pctrl = handle;

    touch_button_instance_ctrl_t ctrl =
    {
        .open = OPEN,
        .lock = { .lock = false},
        .button =
        {
            .rx = p_cfg->button.rx,
            .tx = p_cfg->button.tx,
        },
        .enable.byte = p_cfg->enable.byte,
        .state = TOUCH_BUTTON_EVENT_RELEASED,
        .debounce = p_cfg->debounce,
        .hold_max = p_cfg->hold_max,
        .p_callback = p_cfg->p_callback,

        .ptouch = p_cfg->p_touch,
        .debounce_counter = 0,
        .hold_counter = 0,
    };

    touch_instance_t * p_hdl = (touch_instance_t *)ctrl.ptouch;

    memcpy(&touch_cfg, p_cfg->p_touch->p_cfg, sizeof(touch_cfg));

    /* Change the callback function to use the button update callback */
    touch_cfg.p_callback = touch_button_callback;

    /* CCheck if control block was already opened. */
    if(true ==  already_open(&ctrl, handle))
    {
        /* Nothing to do if block is already in use */
        return TOUCH_BUTTON_SUCCESS;
    }

    /* Open lower layers */
    touch_err = TOUCH_SUCCESS;
    touch_err |= p_hdl->p_api->open(p_hdl->p_ctrl, &touch_cfg);

#if (BUTTON_CFG_PARAM_CHECKING_ENABLE == true)
    /* Ensure lower layers opened successfully */
    ASSERT(TOUCH_SUCCESS==touch_err);
#endif

    if(TOUCH_SUCCESS==touch_err)
    {
        /* Lower layers opened successfully. Copy the control block */
        memcpy(pctrl, &ctrl, sizeof(touch_button_instance_ctrl_t));
    }


    for(uint32_t itr = 0; itr < NUM_CTRL_BLOCKS; itr++)
    {
        if (NULL == pvt_button_ctrl_blk[itr])
        {
            pvt_button_ctrl_blk[itr] = pctrl;
            return TOUCH_BUTTON_SUCCESS;
        }
    }

    return TOUCH_BUTTON_ERR_INSUFFICIENT_MEMORY;
}
/***********************************************************************************************************************
End of function R_TOUCH_ButtonOpen
***********************************************************************************************************************/



/***********************************************************************************************************************
* Function Name: R_TOUCH_ButtonClose
* Description  : Close a Touch Button Control block.
* Arguments    : hdl - Control block identifier for the button. (Returned by successful call to R_TOUCH_ButtonOpen)
* Return Value : TOUCH_BUTTON_SUCCESS, TOUCH_BUTTON_ERR_INVALID_PARAM, or TOUCH_BUTTON_ERR_LOCKED
***********************************************************************************************************************/
touch_button_err_t R_TOUCH_ButtonClose(touch_button_ctrl_t * p_ctrl)
{
    touch_button_err_t err;
#if (BUTTON_CFG_PARAM_CHECKING_ENABLE == true)
    ASSERT(NULL != p_ctrl);
#endif
    touch_button_instance_ctrl_t * pctrl = p_ctrl;
#if (BUTTON_CFG_PARAM_CHECKING_ENABLE == true)
    ASSERT(OPEN==pctrl->open);
#endif

    if (R_BSP_SoftwareLock (&pctrl->lock) == SSP_SUCCESS)
    {
        /* Not being used at the moment */
        touch_err_t touch_err = pctrl->ptouch->p_api->close(pctrl->ptouch->p_ctrl);

        SSP_ASSERT(TOUCH_SUCCESS == touch_err);

        memset(pctrl, 0, sizeof(touch_button_instance_ctrl_t));
        for(uint32_t itr = 0; itr < NUM_CTRL_BLOCKS; itr++)
        {
            if (pvt_button_ctrl_blk[itr] == pctrl)
            {
                pvt_button_ctrl_blk[itr] = NULL;
                return TOUCH_BUTTON_SUCCESS;
            }
        }

        err = TOUCH_BUTTON_ERR_INVALID_PARAM;
    }
    else
    {
        err = TOUCH_BUTTON_ERR_LOCKED;
    }
    return err;
}
/***********************************************************************************************************************
End of function R_TOUCH_ButtonClose
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: R_TOUCH_ButtonControl
* Description  : Control parameters associated with the operation of a button.
* Arguments    : hdl - Button Control Block Identifier (returned by a successfull call to R_Touch_Button_Open)
*                p_arg - Control arguments defining which parameter to get/set.
* Return Value : TOUCH_BUTTON_SUCCESS, TOUCH_BUTTON_ERR_INVALID_PARAM
***********************************************************************************************************************/
touch_button_err_t R_TOUCH_ButtonControl(touch_button_ctrl_t * p_ctrl, touch_button_control_arg_t * const p_arg)
{
    touch_button_err_t button_err;
#if (BUTTON_CFG_PARAM_CHECKING_ENABLE == true)
    ASSERT(NULL != p_ctrl);
    ASSERT(TOUCH_BUTTON_CMD_LAST > p_arg->cmd);
    ASSERT(NULL != p_arg->p_dest);
    ASSERT(0 < p_arg->size)
#endif
    touch_button_instance_ctrl_t * pctrl = p_ctrl;
#if (BUTTON_CFG_PARAM_CHECKING_ENABLE == true)
    ASSERT(OPEN==pctrl->open);
#endif

    if(TOUCH_BUTTON_GET_LAST > p_arg->cmd)
    {
        button_err = get_control_block_parameter(pctrl, p_arg);
    }
    else
    {
        button_err = set_control_block_parameter(pctrl, p_arg);
    }

#if (BUTTON_CFG_PARAM_CHECKING_ENABLE == true)
    ASSERT(button_err == TOUCH_BUTTON_SUCCESS);
#endif

    return button_err;
}
/***********************************************************************************************************************
End of function R_TOUCH_ButtonControl
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: touch_button_update
* Description  : Update parameters controlling the state of the button.
* Arguments    : p_ctrl - Pointer to button control block
*                p_output -
*                    Pointer of where to put the output data
* Return Value : Button callback arguments identifying the state of the button.
***********************************************************************************************************************/
static void touch_button_update(touch_button_instance_ctrl_t * const p_ctrl, touch_button_callback_arg_t * const p_arg)
{
    uint8_t binary;
    touch_err_t touch_err;
    touch_button_callback_arg_t button_arg;
    touch_read_t read_arg = {
        .read_cmd = TOUCH_DATA_BINARY,
        .sensor = &p_ctrl->button,
        .sensor_count = 1,
        .p_dest = &binary,
        .size = sizeof(binary),
    };
    binary = 0;
    button_arg.event = 0;
    button_arg.p_context = NULL;
    touch_err = p_ctrl->ptouch->p_api->read(p_ctrl->ptouch->p_ctrl, &read_arg);

    if (TOUCH_SUCCESS == touch_err)
    {
        if((binary & 0x01)==1)
        {
            /* Binary says 'touched' */
            if(TOUCH_BUTTON_EVENT_RELEASED==p_ctrl->state)
            {
                /* Current State := released */
                if(true==debounce(&p_ctrl->debounce_counter, p_ctrl->debounce))
                {
                    /* Button has been debounced */
                    p_ctrl->state = TOUCH_BUTTON_EVENT_PRESSED;
                    button_arg.event = (true == p_ctrl->enable.bit.press) ? TOUCH_BUTTON_EVENT_PRESSED : button_arg.event;
                }
            }
            else if (TOUCH_BUTTON_EVENT_PRESSED == p_ctrl->state)
            {
                debounce (&p_ctrl->hold_counter, p_ctrl->hold_max);
            }
            else
            {
                ; /* GSCE CODAN Error Elimination */
            }
        }
        else
        {   /* Binary says 'not touched' */
            if(TOUCH_BUTTON_EVENT_PRESSED==p_ctrl->state)
            {
                /* Button was touched; release it! */
                p_ctrl->state = TOUCH_BUTTON_EVENT_RELEASED;
                button_arg.event = (true == p_ctrl->enable.bit.release) ? TOUCH_BUTTON_EVENT_RELEASED : button_arg.event ;
                if(p_ctrl->hold_counter < p_ctrl->hold_max)
                {
                    /* Release within defined hold timing */
                    button_arg.event = (true == p_ctrl->enable.bit.hold) ? TOUCH_BUTTON_EVENT_HOLD : button_arg.event;
                }
                p_ctrl->debounce_counter = 0;
                p_ctrl->hold_counter = 0;
            }
        }
    }

    memcpy(p_arg, & button_arg, sizeof(touch_button_callback_arg_t));

    return;
}
/***********************************************************************************************************************
End of function touch_button_update
***********************************************************************************************************************/

/**
 *
 *  p_current Pointer to current value of the debounce.
 * @param threshold Pointer to the maximum value beyond which button is considered to be debounced.
 * @return true - Button is debounced;  false - Button is not debounced.
 */
/***********************************************************************************************************************
* Function Name: debounce
* Description  : Verify if button has been debounced.
* Arguments    : @param p_current - Pointer to current value of the debounce.
*                @param threshold - Pointer to the maximum value beyond which button is considered to be debounced.
* Return Value : @return true - Button is debounced;  false - Button is not debounced.
***********************************************************************************************************************/
static bool debounce(uint16_t * p_current, uint16_t const threshold)
{
    uint16_t current = *p_current;

    if(current >= threshold)
    {
        return true;
    }
    else
    {
        current++;
        *p_current = current;
        return false;
    }
    return false;
}
/***********************************************************************************************************************
End of function debounce
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: already_open
* Description  : Verify if a matching control block is found.
* Arguments    : @param ctrl - Pointer to control block to be used for comparison.
* Return Value : @return Index of a matching control block (if any).
***********************************************************************************************************************/
static uint8_t already_open(touch_button_instance_ctrl_t const*const p_ctrl_1, touch_button_instance_ctrl_t const*const p_ctrl_2)
{
    /* Run through all the open control blocks to check for a match */
    if(0==memcmp(p_ctrl_1, p_ctrl_2, offsetof(touch_button_instance_ctrl_t, lock)))
    {
        /* Matches a previously opened button! */
        return true;
    }
    return false;
}
/***********************************************************************************************************************
End of function already_open
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: get_control_block_parameter
* Description  : Get value of button control parameter from the control block.
* Arguments    : @param p_ctrl - Control block from which parameter must be extracted.
*                @param p_arg - Control arguments passed by the application.
* Return Value : @return TOUCH_BUTTON_SUCCESS, TOUCH_BUTTON_ERR_INVALID_PARAM
***********************************************************************************************************************/
static touch_button_err_t get_control_block_parameter(touch_button_instance_ctrl_t * p_ctrl, touch_button_control_arg_t * const p_arg)
{
    touch_button_cmd_t cmd = p_arg->cmd;
    size_t offset = 0;
    size_t size = 0;
    uint8_t * base_addr = (uint8_t *)p_ctrl;

    switch(cmd)
    {
        case TOUCH_BUTTON_GET_CHANNELS:
            offset = offsetof(touch_button_instance_ctrl_t, button);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->button);
            break;

        case TOUCH_BUTTON_GET_ENABLE_MASK:
            offset = offsetof(touch_button_instance_ctrl_t, enable);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->enable);
            break;

        case TOUCH_BUTTON_GET_CALLBACK:
            offset = offsetof(touch_button_instance_ctrl_t, p_callback);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->p_callback);
            break;

        case TOUCH_BUTTON_GET_TOUCH_HANDLE:
            offset = offsetof(touch_button_instance_ctrl_t, ptouch);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->ptouch);
            break;


        case TOUCH_BUTTON_GET_STATE:
            offset = offsetof(touch_button_instance_ctrl_t, state);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->state);
            break;

        case TOUCH_BUTTON_GET_DEBOUNCE_COUNTER:
            offset = offsetof(touch_button_instance_ctrl_t, debounce_counter);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->debounce_counter);
            break;

        case TOUCH_BUTTON_GET_HOLD_COUNTER:
            offset = offsetof(touch_button_instance_ctrl_t, hold_counter);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->hold_counter);
            break;
        default:
            return TOUCH_BUTTON_ERR_INVALID_PARAM;
            break;
    };

#if (BUTTON_CFG_PARAM_CHECKING_ENABLE == true)
    ASSERT(size <= p_arg->size);
#endif
    memcpy(p_arg->p_dest, (base_addr + offset), size);

    return TOUCH_BUTTON_SUCCESS;
}
/***********************************************************************************************************************
End of function get_control_block_parameter
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: set_control_block_parameter
* Description  : Set value of a button control parameter in the control block.
* Arguments    : @param p_ctrl Control block for which parameter must be changed.
*                @param p_arg Control arguments passed by the application.
* Return Value : @return TOUCH_BUTTON_SUCCESS, TOUCH_BUTTON_ERR_INVALID_PARAM
***********************************************************************************************************************/
static touch_button_err_t set_control_block_parameter(touch_button_instance_ctrl_t * p_ctrl, touch_button_control_arg_t * const p_arg)
{
    touch_button_cmd_t cmd = p_arg->cmd;
    size_t offset = 0;
    size_t size = 0;
    uint8_t * base_addr = (uint8_t *)p_ctrl;

    switch(cmd)
    {
        case TOUCH_BUTTON_SET_CHANNELS:
            offset = offsetof(touch_button_instance_ctrl_t, button);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->button);
            break;

        case TOUCH_BUTTON_SET_ENABLE_MASK:
            offset = offsetof(touch_button_instance_ctrl_t, enable);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->enable);
            break;
        case TOUCH_BUTTON_SET_CALLBACK:
            offset = offsetof(touch_button_instance_ctrl_t, p_callback);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->p_callback);
            break;
        case TOUCH_BUTTON_SET_TOUCH_HANDLE:
            offset = offsetof(touch_button_instance_ctrl_t, ptouch);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->ptouch);
            break;
        case TOUCH_BUTTON_SET_STATE:
            offset = offsetof(touch_button_instance_ctrl_t, state);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->state);
            break;
        case TOUCH_BUTTON_SET_DEBOUNCE_COUNTER:
            offset = offsetof(touch_button_instance_ctrl_t, debounce_counter);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->debounce_counter);
            break;
        case TOUCH_BUTTON_SET_HOLD_COUNTER:
            offset = offsetof(touch_button_instance_ctrl_t, hold_counter);
            size = sizeof(((touch_button_instance_ctrl_t *)0)->hold_counter);
            break;

        default:
            return TOUCH_BUTTON_ERR_INVALID_PARAM;
            break;
    }

#if (BUTTON_CFG_PARAM_CHECKING_ENABLE == true)
    ASSERT(size <= p_arg->size);
#endif

    ssp_err_t err = R_BSP_SoftwareLock (&p_ctrl->lock);

    if(SSP_SUCCESS == err)
    {
        memcpy((base_addr + offset), p_arg->p_dest, size);
    }
    else
    {
        return TOUCH_BUTTON_ERR_LOCKED;
    }

    R_BSP_SoftwareUnlock(&p_ctrl->lock);

    return TOUCH_BUTTON_SUCCESS;
}
/***********************************************************************************************************************
End of function set_control_block_parameter
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: touch_button_callback
* Description  : Common callback for all buttons invoked by the lower layers.
* Arguments    : @param arg - Argument passed by the lower layer (of type touch_callback_arg_t)
* Return Value : None
***********************************************************************************************************************/
static void touch_button_callback(touch_callback_arg_t const * const p_arg)
{
    touch_button_callback_arg_t button_arg;
    touch_event_t event = (touch_event_t)(p_arg->event);

    memset(&button_arg, 0, sizeof(button_arg));

    if (TOUCH_EVENT_REQUEST_DELAY == event)
    {
        /* Lower layer requesting a delay */
        button_arg.event = TOUCH_BUTTON_EVENT_REQUEST_DELAY;
        button_arg.id = NULL;
        button_arg.p_context = NULL;
        for(uint32_t itr = 0; itr < NUM_CTRL_BLOCKS; itr++)
        {
            touch_button_instance_ctrl_t * pctrl = pvt_button_ctrl_blk[itr];
            if (NULL != pctrl->p_callback)
            {
                /* Found a valid callback to use */
                pctrl->p_callback(&button_arg);
                return;
            }
        }
    }
    else if ((event & TOUCH_EVENT_PARAMETERS_UPDATED) == TOUCH_EVENT_PARAMETERS_UPDATED)
    {
        for (uint32_t itr = 0; itr < NUM_CTRL_BLOCKS; itr++)
        {
            touch_button_instance_ctrl_t * pctrl = pvt_button_ctrl_blk[itr];
            if (OPEN == pctrl->open)
            {
                if (pctrl->ptouch->p_ctrl == p_arg->handle_num)
                {
                    touch_button_update (pctrl, &button_arg);
                    button_arg.id = pctrl;
                }
                if ((p_arg->info > 1) && (TOUCH_BUTTON_EVENT_PRESSED == button_arg.event))
                {
                    button_arg.event |= TOUCH_BUTTON_EVENT_MULTI_TOUCH;
                }
                if ((button_arg.event > 0) && (NULL != pctrl->p_callback))
                {
                        pctrl->p_callback (&button_arg);
                }
            }
        }
    }
    else
    {
        ; /* GSCE CODAN Error Elimination */
    }
}
/***********************************************************************************************************************
End of function touch_button_callback
***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @} (end defgroup R_Touch)
 ***********************************************************************************************************************/
