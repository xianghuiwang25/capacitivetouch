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
* File Name    : r_touch_private.h
* Version      : 1.0
* Description  : This module Contains Function Declarations for the Touch Middleware
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 15.10.2017 1.00     First Release
***********************************************************************************************************************/

#ifndef R_TOUCH_PRIVATE_H_
#define R_TOUCH_PRIVATE_H_

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
 * Description: Saves the configuration information into an empty control block.
 * Enables lower level CTSU hardware module.
 * Initializes necessary data in the handles.
 * @param p_id Pointer to a user specified location where the control block
 *      index will be stored. The user should use this control block number to
 *      perform all future associated actions.
 * @param p_cfg
 *      (created by Workbench6).
 * @return @ref TOUCH_SUCCESS, @ref TOUCH_ERR_INSUFFICIENT_MEMORY,
 *          @ref TOUCH_ERR_INVALID_PARAM
 */
touch_err_t R_TOUCH_Open(touch_ctrl_t * const p_id, touch_cfg_t const * const p_cfg);

/**
 * Close the user specified control block.
 * @param id Control Block Identifier returned by a successful call to
 *      @ref R_TOUCH_Open
 * @return  @ref TOUCH_SUCCESS @ref TOUCH_ERR_LOCKED
 */
touch_err_t R_TOUCH_Close(touch_ctrl_t * const id);

/**
 * Perform a scan with the provided control block.
 * @param id Control Block Identifier returned by a successful call to
 *      @ref R_TOUCH_Open
 * @return @ref TOUCH_SUCCESS @ref TOUCH_ERR_LOCKED, @ref TOUCH_ERR_CTSU_LOCKED
 */
touch_err_t R_TOUCH_StartScan(touch_ctrl_t * const id);

/**
 * Update Touch Sensing information after a control block has been
 * successfully scanned.
 * @param id Control Block Identifier returned by a successful call to
 *      @ref R_TOUCH_Open
 * @return @ref TOUCH_SUCCESS, @ref TOUCH_ERR_LOCKED,
 */
touch_err_t R_TOUCH_Update(touch_ctrl_t * const id);

/**
 * Calibrate the specified control block.
 * @param id Identifier returned by a successful call to R_TOUCH_Open
 * @return @ref TOUCH_SUCCESS, @ref TOUCH_ERR_AUTO_TUNE_FAILED,
 *      @ref TOUCH_ERR_INVALID_PARAM
 */
touch_err_t R_TOUCH_Calibrate(touch_ctrl_t * const id);

/**
 * Read results updated with R_TOUCH_Update. This function will create copy of
 * data into application space.
 * @param id Identifier returned by a successful call to R_TOUCH_Open
 * @param p_arg Structure specifying information about what user wants to read.
 * @return @ref TOUCH_SUCCESS, @ref TOUCH_ERR_INVALID_CMD,
 *      @ref TOUCH_ERR_INSUFFICIENT_MEMORY, @ref TOUCH_ERR_LOCKED,
 *      @ref TOUCH_ERR_INVALID_PARAM
 */
touch_err_t R_TOUCH_Read(touch_ctrl_t * const id, touch_read_t const * const p_arg);

/**
 * Change parameters of associated with a control block and related sensors
 * @param id Identifier returned by a successful call to R_TOUCH_Open
 * @param p_arg Structure identifying which parameter to change and the value to
 *      change to. If parameter is a sensor setting, the tx and rx electrode
 *      information for the sensor must be provided.
 * @return @ref TOUCH_SUCCESS, @ref TOUCH_ERR_LOCKED, @ref TOUCH_ERR_INVALID_CMD,
 *      @ref TOUCH_ERR_INVALID_PARAM.
 */
touch_err_t R_TOUCH_Control(touch_ctrl_t * const id, touch_control_arg_t const * const p_arg);

/**
 * Get the version number for the driver.
 * @return Version number of driver in 32-bits.
 */
ssp_err_t R_TOUCH_GetVersion(ssp_version_t * const p_version);
#endif /* R_TOUCH_V2_SRC_DRIVER_R_TOUCH_R_TOUCH_PRIVATE_H_ */
