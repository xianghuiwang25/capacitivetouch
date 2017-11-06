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
* File Name : r_ctsu_synergy_private.h
* Version : 1.00: [2016-07-29] Released as Version 1.00.
*			1.10: [TBD]
* Description : This module provides the interface to the R_CTSU peripheral.
***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @file
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 Includes
 ***********************************************************************************************************************/
#ifndef SRC_R_CTSU_RX_PRIVATE_HEADER
#define SRC_R_CTSU_RX_PRIVATE_HEADER

/***********************************************************************************************************************
 Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
 Typedef definitions
 ***********************************************************************************************************************/

/**
 * ******************************************************************************************
 * Check parameters being used, Power up CTSU, and initialize an unused CTSU operation handle.
 * @param p_usr_hdl    Location where the handle number is returned.
 * @param p_ctsu_cfg Parameters that should be used for this handle.
 * @return @ref CTSU_SUCCESS, @ref CTSU_ERR_INVALID_PARAM, @ref CTSU_ERR_INSUFFICIENT_MEMORY, @ref CTSU_ERR_LOCKED
 * ******************************************************************************************
 */
ctsu_err_t R_CTSU_Open(ctsu_ctrl_t * const p_ctrl, ctsu_cfg_t const * const p_ctsu_cfg);

/**
 * ******************************************************************************************
 * Close a previously successfully opened handle.
 * @param usr_hdl Handle identifier provided to user by the @ref R_CTSU_Open function.
 * @return @ref CTSU_SUCCESS, @ref CTSU_ERR_LOCKED.
 * ******************************************************************************************
 */
ctsu_err_t R_CTSU_Close(ctsu_ctrl_t * const p_ctrl);

/**
 * ******************************************************************************************
 * Enable scanning of a successfully opened handle
 * @param usr_hdl Handle number provided to user by the @ref R_CTSU_Open function.
 * @return @ref CTSU_SUCCESS, @ref CTSU_ERR_CTSU_OPERATIONAL, @ref CTSU_ERR_LOCKED.
 * ******************************************************************************************
 */
ctsu_err_t R_CTSU_Scan(ctsu_ctrl_t * const p_ctrl);

/**
 * Calibrate the CTSU handle. I.e. Bring sensor count ~~ reference counts.
 * @param usr_hdl Handle number provided to user by the @ref R_CTSU_Open function.
 * @return CTSU error status.
 */
ctsu_err_t R_CTSU_Calibrate(ctsu_ctrl_t * const p_ctrl);

/**
 * ******************************************************************************************
 * Read the results generated by a CTSU scan operation.
 * @param usr_hdl Handle number provided to user by the @ref R_CTSU_Open function.
 * @param p_arg Argument providing information about information to be read from latest scan.
 * @return @ref CTSU_SUCCESS, @ref CTSU_ERR_INVALID_CMD, @ref CTSU_ERR_INVALID_PARAM, @ref CTSU_ERR_LOCKED.
 * ******************************************************************************************
 */
ctsu_err_t R_CTSU_Read(ctsu_ctrl_t * const p_ctrl, ctsu_read_t * p_arg);

/**
 * Change operating parameters of the specified handle.
 * @param usr_hdl Handle number provided to user by the @ref R_CTSU_Open function.
 * @param p_arg Arguments specifying details of things to change.
 * @return @ref CTSU_SUCCESS, @ref CTSU_ERR_INVALID_PARAM, @ref CTSU_ERR_INVALID_CMD.
 */
ctsu_err_t R_CTSU_Control(ctsu_ctrl_t * const p_ctrl, ctsu_control_arg_t* p_arg);

ssp_err_t R_CTSU_VersionGet(ssp_version_t * const p_version);
#endif /* SRC_R_CTSU_RX_PRIVATE_HEADER */
