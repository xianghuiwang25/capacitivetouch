
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
* File Name    : touch_config.c
* Version      : 2.0
* Description  : This file contains TOUCH middleware configuration settings.
***********************************************************************************************************************/
#include "r_touch_synergy_if.h"
#include "r_touch.h"

static touch_common_parameter_t g_touch_cfg_on_g_ctsu_cfg_mutual0_common_parameter_all =
{
    .drift_hold_limit = 50,
    .on_limit = (MUTUAL0_MSA == 0) ? (2000):(MUTUAL0_MSA),
#if defined(SLIDER_USE) || defined(WHEEL_USE)
    .max_touched_sensors = 2,
#else
    .max_touched_sensors = 1,
#endif
};

static touch_sensor_parameter_t g_touch_cfg_on_g_ctsu_cfg_mutual0_sensor_parameter_all[] =
{

    [0] = {.threshold = MUTUAL0_KEY00_THR, .hysteresis = MUTUAL0_KEY00_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [1] = {.threshold = MUTUAL0_KEY01_THR, .hysteresis = MUTUAL0_KEY01_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [2] = {.threshold = MUTUAL0_KEY02_THR, .hysteresis = MUTUAL0_KEY02_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [3] = {.threshold = MUTUAL0_KEY03_THR, .hysteresis = MUTUAL0_KEY03_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [4] = {.threshold = MUTUAL0_KEY04_THR, .hysteresis = MUTUAL0_KEY04_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [5] = {.threshold = MUTUAL0_KEY05_THR, .hysteresis = MUTUAL0_KEY05_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [6] = {.threshold = MUTUAL0_KEY06_THR, .hysteresis = MUTUAL0_KEY06_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [7] = {.threshold = MUTUAL0_KEY07_THR, .hysteresis = MUTUAL0_KEY07_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [8] = {.threshold = MUTUAL0_KEY08_THR, .hysteresis = MUTUAL0_KEY08_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [9] = {.threshold = MUTUAL0_KEY09_THR, .hysteresis = MUTUAL0_KEY09_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [10] = {.threshold = MUTUAL0_KEY10_THR, .hysteresis = MUTUAL0_KEY10_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [11] = {.threshold = MUTUAL0_KEY11_THR, .hysteresis = MUTUAL0_KEY11_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [12] = {.threshold = MUTUAL0_KEY12_THR, .hysteresis = MUTUAL0_KEY12_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [13] = {.threshold = MUTUAL0_KEY13_THR, .hysteresis = MUTUAL0_KEY13_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [14] = {.threshold = MUTUAL0_KEY14_THR, .hysteresis = MUTUAL0_KEY14_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [15] = {.threshold = MUTUAL0_KEY15_THR, .hysteresis = MUTUAL0_KEY15_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [16] = {.threshold = MUTUAL0_KEY16_THR, .hysteresis = MUTUAL0_KEY16_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [17] = {.threshold = MUTUAL0_KEY17_THR, .hysteresis = MUTUAL0_KEY17_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [18] = {.threshold = MUTUAL0_KEY18_THR, .hysteresis = MUTUAL0_KEY18_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [19] = {.threshold = MUTUAL0_KEY19_THR, .hysteresis = MUTUAL0_KEY19_HYS, .dt_limit = MUTUAL0_TOUCH_ON, .dr_limit = MUTUAL0_TOUCH_OFF, .drift_rate = MUTUAL0_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
};

uint8_t g_touch_cfg_on_g_ctsu_cfg_mutual0_binary_all[(20/8) + 1];

static uint8_t g_touch_cfg_on_g_ctsu_cfg_mutual0_buffer_all[640];

extern ctsu_cfg_t g_ctsu_cfg_mutual_all_sensors;

touch_cfg_t g_touch_cfg_on_g_ctsu_cfg_mutual0 =
{
    .p_ctsu_cfg = &g_ctsu_cfg_mutual_all_sensors,
    .p_common = &g_touch_cfg_on_g_ctsu_cfg_mutual0_common_parameter_all,
    .p_sensor = (touch_sensor_parameter_t*)&g_touch_cfg_on_g_ctsu_cfg_mutual0_sensor_parameter_all,
    .p_binary_result = g_touch_cfg_on_g_ctsu_cfg_mutual0_binary_all,
    .p_callback = NULL,
    .num_ignored = 0,
    .p_ignored = NULL,
    .buffer = {
        .p_start = g_touch_cfg_on_g_ctsu_cfg_mutual0_buffer_all,
        .size = sizeof(g_touch_cfg_on_g_ctsu_cfg_mutual0_buffer_all),
    },
    .custom =
    {
        .p_filter = NULL,
        .p_touch_detect = NULL,
        .p_filter_instance = NULL,
        .num_filter_instances = 0,
    },
};
    
