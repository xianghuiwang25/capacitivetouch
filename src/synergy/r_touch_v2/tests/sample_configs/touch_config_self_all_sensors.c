
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
#include "../../../synergy/r_touch_v2/inc/driver/instances/r_touch.h"
#include "./r_touch.h"

static touch_common_parameter_t g_touch_cfg_on_g_ctsu_cfg_self_common_parameter_all_sensors =
{
    .drift_hold_limit = 50,
    .on_limit = (SELF_MSA == 0) ? (2000):(SELF_MSA),
#if defined(SLIDER_USE) || defined(WHEEL_USE)
    .max_touched_sensors = 2,
#else
    .max_touched_sensors = 1,
#endif
};

static touch_sensor_parameter_t g_touch_cfg_on_g_ctsu_cfg_self_sensor_parameter_all_sensors[] =
{

    [0] = {.threshold = WHEEL1_05_NORM/4, .hysteresis = WHEEL1_05_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [1] = {.threshold = WHEEL1_06_NORM/4, .hysteresis = WHEEL1_06_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [2] = {.threshold = WHEEL1_07_NORM/4, .hysteresis = WHEEL1_07_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [3] = {.threshold = WHEEL0_03_NORM/4, .hysteresis = WHEEL0_03_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [4] = {.threshold = WHEEL1_00_NORM/4, .hysteresis = WHEEL1_00_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [5] = {.threshold = WHEEL0_00_NORM/4, .hysteresis = WHEEL0_00_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [6] = {.threshold = SELF_TS11_THR, .hysteresis = SELF_TS11_HYS, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [7] = {.threshold = WHEEL0_01_NORM/4, .hysteresis = WHEEL0_01_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [8] = {.threshold = WHEEL1_01_NORM/4, .hysteresis = WHEEL1_01_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [9] = {.threshold = SLIDER0_04_NORM/4, .hysteresis = SLIDER0_04_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [10] = {.threshold = WHEEL1_04_NORM/4, .hysteresis = WHEEL1_04_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [11] = {.threshold = SLIDER0_02_NORM/4, .hysteresis = SLIDER0_02_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [12] = {.threshold = SLIDER0_03_NORM/4, .hysteresis = SLIDER0_03_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [13] = {.threshold = SLIDER0_00_NORM/4, .hysteresis = SLIDER0_00_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [14] = {.threshold = SLIDER0_01_NORM/4, .hysteresis = SLIDER0_01_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [15] = {.threshold = SELF_TS30_THR, .hysteresis = SELF_TS30_HYS, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [16] = {.threshold = SELF_TS31_THR, .hysteresis = SELF_TS31_HYS, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [17] = {.threshold = WHEEL0_02_NORM/4, .hysteresis = WHEEL0_02_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [18] = {.threshold = WHEEL1_02_NORM/4, .hysteresis = WHEEL1_02_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
    [19] = {.threshold = WHEEL1_03_NORM/4, .hysteresis = WHEEL1_03_NOISE, .dt_limit = SELF_TOUCH_ON, .dr_limit = SELF_TOUCH_OFF, .drift_rate = SELF_DRIFT_FREQUENCY, .drift_rate_plus = 0, .drift_rate_minus = 0, .recalib_delay = 50, .recalib_threshold = 10},
};

uint8_t g_touch_cfg_on_g_ctsu_cfg_self_binary_all_sensors[(20/8) + 1];

static uint8_t g_touch_cfg_on_g_ctsu_cfg_self_buffer_all_sensors[640];

extern ctsu_instance_t const g_ctsu_self_all;

touch_cfg_t g_touch_cfg_on_g_ctsu_cfg_self_all_sensors =
{
    .p_ctsu = &g_ctsu_self_all,
    .p_common = &g_touch_cfg_on_g_ctsu_cfg_self_common_parameter_all_sensors,
    .p_sensor = (touch_sensor_parameter_t*)&g_touch_cfg_on_g_ctsu_cfg_self_sensor_parameter_all_sensors,
    .p_binary_result = g_touch_cfg_on_g_ctsu_cfg_self_binary_all_sensors,
    .p_callback = NULL,
    .num_ignored = 0,
    .p_ignored = NULL,
    .buffer = {
        .p_start = g_touch_cfg_on_g_ctsu_cfg_self_buffer_all_sensors,
        .size = sizeof(g_touch_cfg_on_g_ctsu_cfg_self_buffer_all_sensors),
    },
    .custom =
    {
        .p_filter = NULL,
        .p_touch_detect = NULL,
        .p_filter_instance = NULL,
        .num_filter_instances = 0,
    },
};
    
