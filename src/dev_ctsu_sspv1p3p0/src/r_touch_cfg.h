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
 * Copyright (C) 2015 Renesas Electronics Corporation. All rights reserved.
 ***********************************************************************************************************************/
/**********************************************************************************************************************
 * File Name    : r_touch_rx_config.h
 * Description  : This file contains global options used to configure the R_Touch API
 ***********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *           03.19.2015 1.00    Initial Release.
 ***********************************************************************************************************************/

/*******************************************************************************************************************//**
 * @file
 ***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @ingroup HAL_Library
 * @defgroup R_Touch R_Touch
 * @brief This file contains global options used to configure the R_Touch API.
 * @{
 ***********************************************************************************************************************/
#ifndef R_TOUCH_RX_CONFIG_REF_H_
#define R_TOUCH_RX_CONFIG_REF_H_

/**
 * Specify whether to include code for API parameter checking.
 *    - 1 : Enabled	(Assertion messages routed to Renesas Virtual Console if BSP_CFG_IO_LIB_ENABLE==1)
 *    - 0 : No parameter checking (No assertions)
 */
#define TOUCH_CFG_PARAM_CHECKING_ENABLE			(1)

/**
 * Perform drift compensation and sensitivity optimization for non-touched sensors while a sensor is touched.
 */
#define TOUCH_CFG_COMPENSATE_WHILE_TOUCHED		(0)

/**
 * Define the depth of the Single-Input-Single-Output averaging filter.
 */
#define TOUCH_CFG_FILTER_DEPTH					(1)

/**
 * Define if interval for drift compensation should be variable.
 */
#define TOUCH_CFG_VARIABLE_DRIFT_RATES				(0)

/**
 * Define the type of multi-touch rejection algorithm.
 * 0 := No Multi-Touch Rejection. (Value in max_touched_sensors is ignored)
 * 1 := Multi-Touch rejection will release all touched sensors, if non-debounced touch count is > max_touched_sensors.
 * 2 := Multi-Touch rejection will release all touched sensors, if debounced touch count is > max_touched_sensors.
 * 3 := Multi-Touch rejection will release all touched sensors, if (current debounced sensors - previously debounced sensors) > max_touched_sensors
 */
#define TOUCH_CFG_MULTITOUCH_REJECTION_TYPE					(0)

/**
 * Maximum open touch configurations used.
 */
#define TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS            (5)

/**
 * Upper limit used while calibrating sensors.
 */
#define TOUCH_CFG_TUNING_UPPER_DRIFT_LIMIT    (150)

/**
 * Lower limit used when calibrating sensors.
 */
#define TOUCH_CFG_TUNING_LOWER_DRIFT_LIMIT    (100)

/**
 * Maximum errors allowed before reporting to the upper layer.
 */
#define TOUCH_CFG_MAX_ERROR_COUNT             (1)

#endif /* R_TOUCH_RX_CONFIG_REF_H_ */
