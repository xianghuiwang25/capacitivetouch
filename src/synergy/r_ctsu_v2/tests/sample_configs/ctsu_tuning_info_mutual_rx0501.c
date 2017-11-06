
/***********************************************************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only intended for use with Renesas products.
* No other uses are authorized. This software is owned by Renesas Electronics Corporation and is protected under all
* applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIESREGARDING THIS SOFTWARE, WHETHER EXPRESS, IMPLIED
* OR STATUTORY, INCLUDING BUT NOT LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
* NON-INFRINGEMENT.  ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY
* LAW, NEITHER RENESAS ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE FOR ANY DIRECT,
* INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR
* ITS AFFILIATES HAVE BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software and to discontinue the availability
* of this software. By using this software, you agree to the additional terms and conditions found by accessing the
* following link:
* http://www.renesas.com/disclaimer
*
* Copyright (C) 2016 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : ctsu_config.c
* Version      : 2.0
* Description  : This file contains CTSU SFR settings.
***********************************************************************************************************************/
#include "bsp_api.h"
#include "r_ctsu_api.h"
#include "r_ctsu.h"


static ctsu_sensor_setting_t sensor_setting_g_ctsu_cfg_mutual_rx_05_01[] =
{
	{ .ctsussc = CTSUSSC_MUTUAL0_KEY05,  .ctsuso0 = CTSUSO0_MUTUAL0_KEY05,  .ctsuso1 = CTSUSO1_MUTUAL0_KEY05, },
	{ .ctsussc = CTSUSSC_MUTUAL0_KEY06,  .ctsuso0 = CTSUSO0_MUTUAL0_KEY06,  .ctsuso1 = CTSUSO1_MUTUAL0_KEY06, },
	{ .ctsussc = CTSUSSC_MUTUAL0_KEY07,  .ctsuso0 = CTSUSO0_MUTUAL0_KEY07,  .ctsuso1 = CTSUSO1_MUTUAL0_KEY07, },
	{ .ctsussc = CTSUSSC_MUTUAL0_KEY08,  .ctsuso0 = CTSUSO0_MUTUAL0_KEY08,  .ctsuso1 = CTSUSO1_MUTUAL0_KEY08, },
	{ .ctsussc = CTSUSSC_MUTUAL0_KEY09,  .ctsuso0 = CTSUSO0_MUTUAL0_KEY09,  .ctsuso1 = CTSUSO1_MUTUAL0_KEY09, },
    { .ctsussc = CTSUSSC_MUTUAL0_KEY15,  .ctsuso0 = CTSUSO0_MUTUAL0_KEY15,  .ctsuso1 = CTSUSO1_MUTUAL0_KEY15, },
    { .ctsussc = CTSUSSC_MUTUAL0_KEY16,  .ctsuso0 = CTSUSO0_MUTUAL0_KEY16,  .ctsuso1 = CTSUSO1_MUTUAL0_KEY16, },
    { .ctsussc = CTSUSSC_MUTUAL0_KEY17,  .ctsuso0 = CTSUSO0_MUTUAL0_KEY17,  .ctsuso1 = CTSUSO1_MUTUAL0_KEY17, },
    { .ctsussc = CTSUSSC_MUTUAL0_KEY18,  .ctsuso0 = CTSUSO0_MUTUAL0_KEY18,  .ctsuso1 = CTSUSO1_MUTUAL0_KEY18, },
    { .ctsussc = CTSUSSC_MUTUAL0_KEY19,  .ctsuso0 = CTSUSO0_MUTUAL0_KEY19,  .ctsuso1 = CTSUSO1_MUTUAL0_KEY19, },
};

static uint16_t ctsu_sensor_data_g_ctsu_cfg_mutual_rx_05_01[40];
	
static ctsu_const_sfrs_t ctsu_const_sfrs_g_ctsu_cfg_mutual_rx_05_01 = {
	.ctsucr0.byte     = (MUTUAL0_CTSUTXVSEL<<7),
	.ctsucr1.byte     = ((_11_CTSUMD_MUTUAL<<6)|(_00_CTSUCLK_PCLK<<4)|(MUTUAL0_CTSUATUNE1<<3)|(_0_CTSUATUNE0_NORMAL<<2)|(_1_CTSUCSW_ON<<1)|(_1_CTSUPON_HW_POWER_ON<<0)),
	.ctsusdprs.byte   = ((MUTUAL0_CTSUSOFF<<6)|(MUTUAL0_CTSUPRMODE<<4)|(MUTUAL0_CTSUPRRATIO<<0)),
	.ctsusst.byte     = (_00010000_CTSUSST_RECOMMEND),
	.ctsuchac0.byte   = 0|(MUTUAL0_ENABLE_TS01<<1)|(MUTUAL0_ENABLE_TS05<<5),
	.ctsuchac1.byte   = 0,
#if !defined(BSP_MCU_RX113)
	.ctsuchac2.byte   = 0|(MUTUAL0_ENABLE_TS18<<2)|(MUTUAL0_ENABLE_TS19<<3)|(MUTUAL0_ENABLE_TS20<<4)|(MUTUAL0_ENABLE_TS21<<5),
	.ctsuchac3.byte   = 0|(MUTUAL0_ENABLE_TS26<<2),
	.ctsuchac4.byte   = 0,
#endif

	.ctsuchtrc0.byte  = 0,
	.ctsuchtrc1.byte  = 0,
#if !defined(BSP_MCU_RX113)
	.ctsuchtrc2.byte  = 0|(MUTUAL0_ENABLE_TS18<<2)|(MUTUAL0_ENABLE_TS19<<3)|(MUTUAL0_ENABLE_TS20<<4)|(MUTUAL0_ENABLE_TS21<<5),
	.ctsuchtrc3.byte  = 0|(MUTUAL0_ENABLE_TS26<<2),
	.ctsuchtrc4.byte  = 0,
#endif
	.ctsudclkc.byte   = ((_11_CTSUSSCNT<<4)|(_00_CTSUSSMOD<<0)),
};

ctsu_cfg_t g_ctsu_cfg_mutual_rcv_05_01 = {
    /* One Time Settings */
    .p_ctsu_settings = &ctsu_const_sfrs_g_ctsu_cfg_mutual_rx_05_01,
    /* Per channel settings */
    .p_sensor_settings = (ctsu_sensor_setting_t*)sensor_setting_g_ctsu_cfg_mutual_rx_05_01,
    .p_sensor_data = ctsu_sensor_data_g_ctsu_cfg_mutual_rx_05_01,
	.pclkb_hz = 24000000,
	.p_callback = NULL,
#if (CTSU_CFG_ENABLE_MEASUREMENT_CORRECTION > 0)
	.correction_factor_pri_cal = 0,
	.correction_factor_sec_cal = 0,
	.correction_ctsuso_delta = 0,
#endif
};
	
