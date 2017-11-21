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
* File Name    : sf_touch_button_private.h
* Version      : 1.0
* Description  : XXX What does this module do?
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 15.01.2007 1.00     First Release
***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @file
 ***********************************************************************************************************************/
/*******************************************************************************************************************//**
* @defgroup SF_BUTTON_V2_SRC_DRIVER_SF_BUTTON_SF_TOUCH_BUTTON_PRIVATE_H_ Module in sf_touch_button_private.h
* @brief XXX Brief description
* @{
***********************************************************************************************************************/
#ifndef SF_TOUCH_BUTTON_PRIVATE_H_
#define SF_TOUCH_BUTTON_PRIVATE_H_

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global functions (to be accessed by other files)
***********************************************************************************************************************/
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
#endif /* SF_TOUCH_BUTTON_PRIVATE_H_ */
/*******************************************************************************************************************//**
* @}
***********************************************************************************************************************/

