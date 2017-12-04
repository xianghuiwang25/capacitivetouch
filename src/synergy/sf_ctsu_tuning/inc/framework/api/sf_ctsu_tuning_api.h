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
* File Name    : sf_ctsu_tuning.h
* Version      : 1.0 <- Optional as long as history is shown below
* Description  : This module solves all the world's problems
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 15.01.2007 1.00     First Release
***********************************************************************************************************************/

#ifndef SF_CTSU_TUNING_API_H_
#define SF_CTSU_TUNING_API_H_

#include "r_ctsu_api.h"
/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
typedef void sf_ctsu_tuning_ctrl_t;

typedef struct st_sf_ctsu_tuning_cfg
{
    uint32_t index;
    void const * const p_comms;
    ctsu_instance_t const * const p_ctsu;
    touch_instance_t const * const p_touch;
}sf_ctsu_tuning_cfg_t;

/** Framework communications API structure.  Implementations will use the following API. */
typedef struct st_sf_ctsu_tuning_api
{
    /** Initialize communications driver.
     * @param[in,out] p_ctrl   Pointer to a control structure allocated by user. The control structure is
     *                         initialized in this function.
     * @param[in]     p_cfg    Pointer to configuration structure. All elements of the structure must be set by user.
     */
    ssp_err_t (* open)(sf_ctsu_tuning_ctrl_t       * const p_ctrl,
            sf_ctsu_tuning_cfg_t  const * const p_cfg);

    /** Clean up Tuning driver.
     * @param[in]   p_ctrl      Pointer to device control block initialized in Open call for Tuning driver.
     */
    ssp_err_t (* close)(sf_ctsu_tuning_ctrl_t * const p_ctrl);

    /**
     * Run the Tuning driver
     * @param[in] p_ctrl      Pointer to device control block initialized in Open call for Tuning driver.
     */
    ssp_err_t (* run)(sf_ctsu_tuning_ctrl_t * const p_ctrl);

}sf_ctsu_tuning_api_t;

typedef struct st_sf_ctsu_tuning_instance
{
    sf_ctsu_tuning_ctrl_t       * p_ctrl;
    sf_ctsu_tuning_api_t  const * p_api;
    sf_ctsu_tuning_cfg_t  const * p_cfg;
}sf_ctsu_tuning_instance_t;

/***********************************************************************************************************************
Exported global variables
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global functions (to be accessed by other files)
***********************************************************************************************************************/

#endif /* SF_CTSU_TUNING_API_H_ */
