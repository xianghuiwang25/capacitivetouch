/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* <b href="http://www.renesas.com/disclaimer">http://www.renesas.com/disclaimer.</b>
* http://www.renesas.com/disclaimer
* © 2012-2016 Renesas Electronics Corporation All rights reserved.
*******************************************************************************/

/***********************************************************************************************************************
* File Name : r_touch_rx_common_test.h
* Version : XXX: [Aug 11, 2016:Onkar.Raut:4:44:14 PM] TODO: Insert Release Note.
* Description : Short Description.
***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @file
 ***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @ingroup XXX
 * @defgroup XXX
 * @brief This is a brief description 
 * @{
 * Sample Usage:
 *
 ***********************************************************************************************************************/

#ifndef TEST_R_TOUCH_RX_COMMON_TEST_H_
#define TEST_R_TOUCH_RX_COMMON_TEST_H_

#include <stdio.h>
#include "bsp_api.h"
#include "sf_touch_button.h"
/* Include the private header for retrieving the max count of control blocks.*/
#include "../../../src/driver/sf_button/sf_touch_button_private.h"

#if defined(BSP_MCU_GROUP_S3A7)
#define CAPTOUCH_SENSOR_COUNT   (20)
#define SW3     (IOPORT_PORT_05_PIN_05)
#define SW_ACTIVE (IOPORT_LEVEL_LOW)
#elif defined(BSP_MCU_RX113)
#define CAPTOUCH_SENSOR_COUNT   (12)
#endif

extern void ctsu_pin_init(uint64_t pin_mask);
extern uint64_t ctsu_get_tspin_mask(ctsu_cfg_t const*const p_cfg);
extern uint64_t ctsu_get_rxpin_mask(ctsu_cfg_t const*const p_cfg);
extern uint64_t ctsu_get_txpin_mask(ctsu_cfg_t const*const p_cfg);
extern uint32_t ctsu_get_pin_count(uint64_t tspin_mask);
extern ioport_level_t get_pin_level(ioport_port_pin_t pin);

#endif /* TEST_R_TOUCH_RX_COMMON_TEST_H_ */
