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
/***********************************************************************************************************************
* File Name    : r_ctsu_synergy_common_test
* Description  : Common framework to begin migrating test code to...
************************************************************************************************************************
* History : DD.MM.YYYY Version Description
*           06.15.2016 1.00    Initial Release
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include <stdio.h>
#include "bsp_api.h"
#include "r_touch_config.h"
#include "r_touch_synergy_if.h"
/* Include the private header for retrieving the max count of control blocks.*/
#include "src/r_touch_synergy_private.h"

#ifndef TEST_R_CTSU_RX_COMMON_TEST_H_
#define TEST_R_CTSU_RX_COMMON_TEST_H_

#if defined(BSP_MCU_GROUP_S3A7)
#define CAPTOUCH_SENSOR_COUNT   (20)
#define SW3     (IOPORT_PORT_05_PIN_05)
#define SW_ACTIVE (IOPORT_LEVEL_LOW)
#elif defined(BSP_MCU_RX113)
#define CAPTOUCH_SENSOR_COUNT   (12)
#endif

/**
 * Initialize CTSU TSCAP and TS pins.
 * @param pin_mask Bit field which describes pins being used as TS pins.
 */
void ctsu_pin_init(uint64_t pin_mask);
uint64_t ctsu_get_tspin_mask(ctsu_cfg_t const*const p_cfg);
uint64_t ctsu_get_rxpin_mask(ctsu_cfg_t const*const p_cfg);
uint64_t ctsu_get_txpin_mask(ctsu_cfg_t const*const p_cfg);
uint32_t ctsu_get_pin_count(uint64_t tspin_mask);
ioport_level_t get_pin_level(ioport_port_pin_t pin);
#endif /* TEST_R_CTSU_RX_COMMON_TEST_H_ */
