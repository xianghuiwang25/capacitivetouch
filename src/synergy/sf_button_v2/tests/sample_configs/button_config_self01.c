
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
#include "bsp_api.h"
#include "../../../../r_touch_v2/tests/sample_configs/r_touch.h"
#include "sf_touch_button.h"

#if defined(BSP_MCU_GROUP_S3A7) && (SELF_METHOD_NUM > 0)

extern touch_instance_t const g_touch_on_g_ctsu_self_buttons;

static void g_touch_cfg_on_g_ctsu_cfg_self_button_callback(touch_button_callback_arg_t * const p_arg)
{
    SSP_PARAMETER_NOT_USED(p_arg);
}

touch_button_cfg_t Button_RX00_on_g_touch_cfg_on_g_ctsu_cfg_self = {
     .button.tx = 255,
     .button.rx = 11,
     .p_touch = &g_touch_on_g_ctsu_self_buttons,
     .enable.bit.reserved = 0,
     .enable.bit.hold = false,
     .enable.bit.press = true,
     .enable.bit.release = true,
     .debounce = 20,
	 .hold_max = 1000,
     .p_callback = g_touch_cfg_on_g_ctsu_cfg_self_button_callback,
};

touch_button_cfg_t Button_RX01_on_g_touch_cfg_on_g_ctsu_cfg_self = {
     .button.tx = 255,
     .button.rx = 30,
     .p_touch = &g_touch_on_g_ctsu_self_buttons,
     .enable.bit.reserved = 0,
     .enable.bit.hold = false,
     .enable.bit.press = true,
     .enable.bit.release = true,
     .debounce = 20,
	 .hold_max = 1000,
     .p_callback = g_touch_cfg_on_g_ctsu_cfg_self_button_callback,
};

touch_button_cfg_t Button_RX21_on_g_touch_cfg_on_g_ctsu_cfg_self = {
     .button.tx = 255,
     .button.rx = 31,
     .p_touch = &g_touch_on_g_ctsu_self_buttons,
     .enable.bit.reserved = 0,
     .enable.bit.hold = false,
     .enable.bit.press = true,
     .enable.bit.release = true,
     .debounce = 20,
     .hold_max = 1000,
     .p_callback = g_touch_cfg_on_g_ctsu_cfg_self_button_callback,
};
#endif
