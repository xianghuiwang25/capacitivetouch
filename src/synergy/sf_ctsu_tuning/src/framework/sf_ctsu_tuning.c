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
* Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.    
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : sf_ctsu_tuning.c
* Version      : 1.0
* Description  : This module allows communication with Workbench6
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 15.01.2007 1.00     First Release
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "bsp_api.h"
#include "sf_ctsu_tuning_cfg.h"

#define COMM_FRAMEWORK_CONDITION ((BSP_CFG_RTOS==true) && (SF_CTSU_TUNING_CFG_CONNECTION==1))
#if (COMM_FRAMEWORK_CONDITION==true)
#include "sf_comms_api.h"
#else
#include "r_uart_api.h"
#endif
#include "sf_ctsu_tuning.h"
#include "sf_ctsu_tuning_private.h"

#include "deps/r_serial_control.h"

#define MAX_CTSU_CFG_COUNT  (8)
#define MAX_TOUCH_CFG_COUNT (8)

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#if !defined(SF_CTSU_TUNING_CFG_SCI_SIZE_CHECK_COUNT)
#define SF_CTSU_TUNING_CFG_SCI_SIZE_CHECK_COUNT            (2)
#endif

#if !defined(SF_CTSU_TUNING_CFG_SCI_BASE_DATA_SIZE)
#define SF_CTSU_TUNING_CFG_SCI_BASE_DATA_SIZE              (3)
#endif

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/
static uint8_t receive_data[36] = {0xFF, 0xFF, 0xFF, 0xFF};
static uint8_t transmit_data[270 + SF_CTSU_TUNING_CFG_SCI_BASE_DATA_SIZE];

#if (COMM_FRAMEWORK_CONDITION==true)
static uint8_t host_comm_thread_stack[SF_CTSU_TUNING_CFG_THREAD_STACK_SIZE];
static TX_THREAD host_comm_thread;
static void host_communication_thread(ULONG input);
#else
static uint8_t receive_flag;
static volatile uint8_t receive_count;
static uint16_t receive_data_size;

static uint8_t send_flag;
static uint16_t send_count;

void wkbh_send_command(uart_instance_t const * const p_uart, uint8_t * const p_src, uint16_t count);
void wkbh_uart_callback(uart_callback_args_t * arg);
#endif


sf_ctsu_tuning_api_t const g_ctsu_tuning_api =
{
 .open = SF_CTSU_TuneOpen,
 .run = SF_CTSU_TuneRun,
};

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/
static ctsu_ctrl_t * ctsu_ctrls[MAX_CTSU_CFG_COUNT];

#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
static touch_ctrl_t * touch_ctrls[MAX_TOUCH_CFG_COUNT];
#endif


ssp_err_t SF_CTSU_TuneOpen(sf_ctsu_tuning_ctrl_t * const p_vctrl, sf_ctsu_tuning_cfg_t const * const p_cfg)
{
#if (SF_CTSU_TUNING_CFG_PARAM_CHECK==1)
    SSP_ASSERT(p_vctrl != NULL);
    SSP_ASSERT(p_cfg->p_comms != NULL);
    SSP_ASSERT(p_cfg->p_ctsu != NULL);
#endif
    ssp_err_t err = SSP_SUCCESS;

    sf_ctsu_tuning_instance_ctrl_t * p_ctrl = p_vctrl;

    /** Initialize Serial Communication Structures */
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)

    if(!SerialCommandInitialTouch((touch_instance_t *)p_cfg->p_touch, (uint8_t)p_cfg->index))
    {
        err = SSP_ERR_INVALID_ARGUMENT;
    }

#elif (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_TUNING)
    if(!SerialCommandInitial((ctsu_instance_t *)p_cfg->p_ctsu, (uint8_t)p_cfg->index))
    {
        err = SSP_ERR_INVALID_ARGUMENT;
    }
#endif

    if (SSP_SUCCESS == err)
    {
        /** Initialize control handle */
        p_ctrl->index   = p_cfg->index;
        p_ctrl->p_comms = p_cfg->p_comms;
        p_ctrl->p_ctsu  = p_cfg->p_ctsu;
        p_ctrl->p_touch = p_cfg->p_touch;

        uint32_t itr = 0;
        for(itr = 0; itr < ((sizeof(ctsu_ctrls))/(sizeof(ctsu_ctrls[0]))); itr++)
        {
            if (NULL == ctsu_ctrls[itr])
            {
                break;
            }
        }

        if(itr >= ((sizeof(ctsu_ctrls))/(sizeof(ctsu_ctrls[0]))) )
        {
            return SSP_ERR_INSUFFICIENT_SPACE;
        }

        ctsu_ctrls[itr] = p_cfg->p_ctsu->p_ctrl;
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
        touch_ctrls[itr] = p_cfg->p_touch->p_ctrl;
#endif

#if (SF_CTSU_TUNING_CFG_CONNECTION==2)
        uart_instance_t const * const p_uart = p_cfg->p_comms;
        if(p_uart->p_cfg->p_callback != wkbh_uart_callback)
        {
            err = SSP_ERR_INVALID_ARGUMENT;
        }
        err = p_uart->p_api->open(p_uart->p_ctrl, p_uart->p_cfg);
#endif

    }
#if (COMM_FRAMEWORK_CONDITION == true)
    if (0 == host_comm_thread.tx_thread_name)
    {
        /** Kick off Communication thread to be able to get data from Host */
        tx_thread_create (&host_comm_thread,
                          (CHAR *) "Host Communication",
                          host_communication_thread,
                          (ULONG) p_ctrl,
                          &host_comm_thread_stack[0],
                          sizeof(host_comm_thread_stack),
                          SF_CTSU_TUNING_CFG_THREAD_PRIORITY,
                          1,
                          1,
                          TX_AUTO_START);
    }
#endif
    return err;
}

ssp_err_t SF_CTSU_TuneRun(sf_ctsu_tuning_ctrl_t * const p_vctrl)
{
    sf_ctsu_tuning_instance_ctrl_t * const p_ctrl = p_vctrl;
    ssp_err_t err = SSP_SUCCESS;

#if (SF_CTSU_TUNING_CFG_CONNECTION==0)
    PrepareReplayMessage();
#endif

    if (NULL != p_ctrl->p_comms)
    {
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_TUNING)
        extern uint8_t g_access_method;
        extern volatile uint8_t       g_ctsu_soft_mode;
        if (0 != g_ctsu_soft_mode)
        {
            const uint32_t sensor_count = 0;
            ctsu_control_arg_t arg =
            {
             .cmd = CTSU_CMD_GET_SENSOR_COUNT,
             .p_context = (void * )&sensor_count,
            };

            ctsu_err_t ctsu_err = p_ctrl->p_ctsu->p_api->control(ctsu_ctrls[g_access_method], &arg);

            if (CTSU_SUCCESS == ctsu_err)
            {
                /** Start a scan */
                ctsu_err = p_ctrl->p_ctsu->p_api->scan(ctsu_ctrls[g_access_method]);
            }

            if (CTSU_SUCCESS == ctsu_err)
            {
#if (BSP_CFG_RTOS==true)
                /** Sleep till scan completes while */
                tx_thread_sleep (sensor_count);
#endif
            }

        }
#endif

#if (SF_CTSU_TUNING_CFG_CONNECTION==2)
        if (1 == receive_flag)
        {
            if (0 == send_flag)
            {
                if (SerialCommandReceive(receive_data, receive_data_size))
                {
                    if (GetReplayMessage(transmit_data, (uint16_t *)&send_count))
                    {
                        uart_instance_t const * const p_uart = p_ctrl->p_comms;
                        wkbh_send_command(p_uart, transmit_data, send_count);
                    }
                }
            }
        }
#endif
    }

    return err;
}


#if (COMM_FRAMEWORK_CONDITION==true)
static void host_communication_thread(ULONG p_arg)
{
    ssp_err_t err = 0;
    uint16_t send_count;
    sf_ctsu_tuning_instance_ctrl_t const * const p_ctrl = (sf_ctsu_tuning_instance_ctrl_t const * const )p_arg;

    sf_comms_instance_t const * const p_comms = p_ctrl->p_comms;

    memset(receive_data, 0xFF, sizeof(receive_data));


    while(1)
    {
        /** Grab data from the Communication Interface (Main + Sub + Size + Checksum) */
        err = p_comms->p_api->read(p_comms->p_ctrl,
                                           &receive_data[0],
                                           4,
                                           TX_WAIT_FOREVER);

        if (SSP_SUCCESS != err)
        {
            while ((SSP_ERR_NOT_OPEN == err) || (SSP_ERR_TIMEOUT == err))
            {
                /** Initialize the Communication Interface */
                err = p_comms->p_api->open(p_comms->p_ctrl, p_comms->p_cfg);
            }
            /** Retry reception (Main + Sub + Size + Checksum) */
            err = p_comms->p_api->read(p_comms->p_ctrl,
                                               &receive_data[0],
                                               4,
                                               TX_WAIT_FOREVER);
        }

        uint32_t data_count = receive_data[2];
        if(data_count > 0)
        {
            err = p_comms->p_api->read(p_comms->p_ctrl,
                                               &receive_data[4],
                                               data_count,
                                               data_count * TX_TIMER_TICKS_PER_SECOND);
        }

#if (SF_CTSU_TUNING_CFG_CONNECTION == 1)
        if(SerialCommandReceive(&receive_data[0], (uint16_t)(UINT16_C(4) + data_count)))
        {
            if (GetReplayMessage(&transmit_data[0],&send_count))
            {
                err = p_comms->p_api->write(p_comms->p_ctrl, &transmit_data[0], send_count, TX_WAIT_FOREVER);
            }
        }
#endif
    }
}
#else

void wkbh_send_command(uart_instance_t const * const p_uart, uint8_t * const p_src, uint16_t count)
{
    ssp_err_t err = p_uart->p_api->write(p_uart->p_ctrl, p_src, count);
    if(SSP_SUCCESS==err)
    {
        send_flag = 1;
        receive_flag  = 0;
        receive_count = 0;
    }
}

/***********************************************************************************************************************
* Function Name: wkbh_uart_callback
* Description  : Handles incoming bytes over the UART
* Arguments    : p_arg -
*                    Pointer of where event details are available.
* Return Value : None
***********************************************************************************************************************/
void wkbh_uart_callback(uart_callback_args_t * p_arg)
{
    uart_event_t  event = p_arg->event;

    if(UART_EVENT_ERR_FRAMING == event)
    {
        receive_flag  = 0;
        receive_count = 0;
    }
    else if (UART_EVENT_RX_CHAR == event)
    {
        receive_data[receive_count] = (uint8_t)(p_arg->data & 0xFF);

        if (SF_CTSU_TUNING_CFG_SCI_SIZE_CHECK_COUNT == receive_count)                    /* SCI6 Receive data size check              */
        {
            if (0x00 == receive_data[receive_count])           /* Receive data = 0 check                    */
            {
                /* Data size = 3 setting (main command + sub command + size + check sum) */
                receive_data_size = SF_CTSU_TUNING_CFG_SCI_BASE_DATA_SIZE;
            }
            else
            {
                /* Data size = (3 + data size) setting (main command + sub command + size + check sum + data size) */
                receive_data_size = (uint16_t)(SF_CTSU_TUNING_CFG_SCI_BASE_DATA_SIZE + receive_data[SF_CTSU_TUNING_CFG_SCI_SIZE_CHECK_COUNT]);
            }
        }

        if (SF_CTSU_TUNING_CFG_SCI_SIZE_CHECK_COUNT < receive_count)
        {
            if (receive_data_size == receive_count)
            {
                receive_flag  = 1;
                receive_count = 0;
                receive_data_size = (uint16_t)(receive_data_size + UINT16_C(1));
            }
            else
            {
                receive_count = (uint8_t)(receive_count + UINT16_C(1));
            }
        }
        else
        {
            receive_count = (uint8_t)(receive_count + UINT16_C(1));
        }
    }
    else if(UART_EVENT_TX_COMPLETE==event)
    {
        send_flag = 0;
    }
    else
    {
        ;
    }

}
/***********************************************************************************************************************
End of function wkbh_uart_callback
***********************************************************************************************************************/
#endif
