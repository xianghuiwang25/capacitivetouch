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
 * @{
 * @brief Interface file defining the r_touch_button layer.
 ***********************************************************************************************************************/

#ifndef SF_TOUCH_BUTTON_API_H_
#define SF_TOUCH_BUTTON_API_H_

#include "r_touch_api.h"

/** Major Revision number of the driver */
#define TOUCH_BUTTON_API_VERSION_MAJOR  (2)

/** Minor Revision number of the driver */
#define TOUCH_BUTTON_API_VERSION_MINOR  (00)

#if !defined(TOUCH_API_VERSION_MAJOR)||!defined (TOUCH_API_VERSION_MINOR)
#error "TOUCH Middle-ware version not defined."
#endif

#if (TOUCH_API_VERSION_MAJOR < 2)
#error "TOUCH Middle-ware must be greater than v2.0"
#endif

/**
 * Forward declared TOUCH Button Control block
 */
typedef void touch_button_ctrl_t;

/** Different error status returned by the API. */
typedef enum e_touch_button_err
{
    TOUCH_BUTTON_SUCCESS = TOUCH_SUCCESS,   ///< Operation Successful
    TOUCH_BUTTON_ERR_INVALID_PARAM,         ///< Invalid Parameter Found in arguments.
    TOUCH_BUTTON_ERR_INSUFFICIENT_MEMORY,   ///< Insufficient memory (consider increasing MAX_CONTROL_BLOCK_COUNT)
    TOUCH_BUTTON_ERR_LOCKED,                ///< Button Control block is currently in use.
}touch_button_err_t;                        ///< Refer @ref e_touch_button_err

/**
 * Different states/events for a button.
 */
typedef enum e_touch_button_event
{
    TOUCH_BUTTON_EVENT_RELEASED = 1,        ///< Button is in the released state
    TOUCH_BUTTON_EVENT_PRESSED = 2,         ///< Button is in the pressed state
    TOUCH_BUTTON_EVENT_HOLD = 4,            ///< Button released within valid timing
    TOUCH_BUTTON_EVENT_MULTI_TOUCH = 8,     ///< More than one touch sensor is being touched
    TOUCH_BUTTON_EVENT_REQUEST_DELAY = 0x10,///< Lower level asking for a delay
} touch_button_event_t;                     ///< Refer @ref e_touch_button_event

/**
 * Types of Control Commands
 */
typedef enum e_touch_button_cmd
{
    TOUCH_BUTTON_GET_CHANNELS,                    ///< Get TS pins (touch_sensor_t) used by button
    TOUCH_BUTTON_GET_ENABLE_MASK,                 ///< Get enabled events mask
    TOUCH_BUTTON_GET_CALLBACK,                    ///< Get the callback function for the button
    TOUCH_BUTTON_GET_TOUCH_HANDLE,                ///< Get the identifier of lower TOUCH layer.
    TOUCH_BUTTON_GET_STATE,                       ///< Get the state of the button
    TOUCH_BUTTON_GET_DEBOUNCE_COUNTER,            ///< Get the value of the debounce counter
    TOUCH_BUTTON_GET_HOLD_COUNTER,                ///< Get the value of the hold counter for the button.

    TOUCH_BUTTON_GET_LAST,                        ///< Do not use

    TOUCH_BUTTON_SET_CHANNELS,                    ///< Set TS pins (touch_sensor_t) used by button
    TOUCH_BUTTON_SET_ENABLE_MASK,                 ///< Set enabled events mask
    TOUCH_BUTTON_SET_CALLBACK,                    ///< Set the callback function for the button
    TOUCH_BUTTON_SET_TOUCH_HANDLE,                ///< Set the identifier of lower TOUCH layer.
    TOUCH_BUTTON_SET_STATE,                       ///< Set the state of the button
    TOUCH_BUTTON_SET_DEBOUNCE_COUNTER,            ///< Set the value of the debounce counter
    TOUCH_BUTTON_SET_HOLD_COUNTER,                ///< Set the value of the hold counter for the button.

    TOUCH_BUTTON_SET_LAST,                        ///< Do not use
    TOUCH_BUTTON_CMD_LAST = TOUCH_BUTTON_SET_LAST,///< Do not use
}touch_button_cmd_t;                   ///< Refer @ref e_touch_button_cmd

/**
 * Argument structure passed to callback function defined by the user.
 */
typedef struct st_touch_button_callback_arg
{
    touch_ctrl_t * id;                  ///< Button Identifier (matches identifier returned by successful call to R_Touch_Button_Open)
    uint32_t event;                     ///< Type of event occurred
    void const * p_context;             ///< Placeholder for user data (Future use)
}touch_button_callback_arg_t;           ///< Refer @ref st_touch_button_callback_arg

/** Definition of a Touch Button Callback function */
typedef void (* touch_button_callback_t)(touch_button_callback_arg_t * const p_arg);

/** Definition of a button and it's behavior in software provided by the Application. */
typedef struct st_touch_button
{
    touch_sensor_t button;              ///< Define the channel pairs which make up a button.
    touch_instance_t const * const p_touch;    ///< Pointer to lower level Touch configuration with which this button operates.
    union
    {
        struct{
            uint8_t  release : 1;       ///< enable release events
            uint8_t  press   : 1;       ///< enable press events
            uint8_t  hold    : 1;       ///< enable hold events
            uint8_t  reserved: 5;       ///< unused bits
        }bit;
        uint8_t byte;                   ///< Byte representation of events enabled.
    } enable;
    uint16_t    debounce;               ///< Debounce threshold for the sensor
    uint16_t hold_max;                  ///< Maximum duration of a valid touch (for reporting a HOLD event)
    touch_button_callback_t p_callback;          ///< Function invoked when an button event occurs
} touch_button_cfg_t;                   ///< Refer @ref st_touch_button

/**
 * Argument structure passed to the R_Touch_Button_Control function.
 */
typedef struct st_touch_button_control_arg
{
    touch_button_cmd_t cmd;            ///< Control Command type
    void * p_dest;                      ///< Pointer to location where data is stored
    size_t size;                        ///< Amount of memory available at the location pointed by @ref st_touch_button_control_arg::p_dest.
}touch_button_control_arg_t;            ///< Refer @ref st_touch_button_control_arg

/**********************************************************************************************************************/
/*                          Exported global functions (to be accessed by other files)                                 */
/**********************************************************************************************************************/
/**
 * Open a TOUCH Sensor Button with the configuration provided.
 * @param handle Pointer to location where user wants the control block identifier to be stored.
 * @param p_cfg Configuration parameters for button operation.
 * @return TOUCH_BUTTON_SUCCESS, TOUCH_BUTTON_ERR_INVALID_PARAM, TOUCH_BUTTON_ERR_INSUFFICIENT_MEMORY
 */
touch_button_err_t R_TOUCH_ButtonOpen(touch_button_ctrl_t * const p_ctrl, touch_button_cfg_t const * const btn);

/**
 * Close a Touch Button Control block.
 * @param hdl Control block identifier for the button.
 * @return TOUCH_BUTTON_SUCCESS, TOUCH_BUTTON_ERR_INVALID_PARAM, TOUCH_BUTTON_ERR_LOCKED
 */
touch_button_err_t R_TOUCH_ButtonClose(touch_button_ctrl_t * const p_ctrl);

/**
 *
 * @param hdl Button Control Block Identifier (returned by a successfull call to R_Touch_Button_Open)
 * @param p_arg Control arguments defining which parameter to get/set.
 * @return TOUCH_BUTTON_SUCCESS, TOUCH_BUTTON_ERR_INVALID_PARAM
 */
touch_button_err_t R_TOUCH_ButtonControl(touch_button_ctrl_t * const p_ctrl, touch_button_control_arg_t* p_arg);

/**
 * Get the version number for the driver.
 * @return Version number of driver in 32-bits.
 */
ssp_err_t R_TOUCH_ButtonGetVersion(ssp_version_t * const p_version);
#endif /* SF_TOUCH_BUTTON_API_H_ */
/*******************************************************************************************************************//**
 * @} (end Touch_Button)
 ***********************************************************************************************************************/
