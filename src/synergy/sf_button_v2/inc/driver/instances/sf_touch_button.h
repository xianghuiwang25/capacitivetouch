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
* File Name    : sf_touch_button.h
* Version      : 1.0 <- Optional as long as history is shown below
* Description  : This module solves all the world's problems
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 15.01.2007 1.00     First Release
***********************************************************************************************************************/
#ifndef SF_TOUCH_BUTTON_H
#define SF_TOUCH_BUTTON_H
/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "sf_touch_button_cfg.h"
#include "sf_touch_button_api.h"
/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

typedef struct st_touch_button_instance_ctrl_t
{
    uint32_t open;

    /** Define the channel pairs which make up a button. */
    touch_sensor_t button;
    union
    {
        struct{
            /** enable release events */
            uint8_t  release    : 1; ///< Enable release events.
            uint8_t  press      : 1; ///< Enable press events.
            uint8_t  hold       : 1; ///< Enable hold events.
        }bit;
        uint8_t byte; ///< Byte representation of events enabled.
    } enable;
    uint16_t const debounce;    ///< Number of consecutive times a button is determined as touched before state changes from touched to not touched.
    uint16_t const hold_max;    ///< Maximum duration of a valid touch.
    touch_button_callback_t p_callback;  ///< Function to call when an event occurs.

    /***************************************************************************/
    /* Private values. Configured and manipulated by R_Touch_Button code only. */
    /***************************************************************************/
    bsp_lock_t lock;
    touch_instance_t const * const ptouch;       ///< Represents the identifier of the lower level.
    touch_button_event_t  state;    ///< Represents the current state of the button.
    uint16_t debounce_counter;      ///< Variable value for debouncing purposes.
    uint16_t hold_counter;          ///< Variable value for noting the amount of time for which button is spending between press and release.
} touch_button_instance_ctrl_t;
#endif /* SF_TOUCH_BUTTON_H */
