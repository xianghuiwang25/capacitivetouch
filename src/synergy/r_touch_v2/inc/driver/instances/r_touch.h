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
* File Name    : r_touch.h
* Version      : 1.0
* Description  : TOUCH Middleware Descriptions
***********************************************************************************************************************/
/***********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 15.10.2017 1.00     First Release
***********************************************************************************************************************/

#ifndef R_TOUCH_H_
#define R_TOUCH_H_

#include "bsp_api.h"
#include "stdlib.h"

#include "r_touch_cfg.h"
#include "r_touch_api.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define TOUCH_CODE_VERSION_MAJOR (2)
#define TOUCH_CODE_VERSION_MINOR (0)

#ifndef LAST_TS
#if defined(BSP_MCU_GROUP_S124)
#define LAST_TS  (36)
#elif defined(BSP_MCU_GROUP_S3A7)
#define LAST_TS  (36)
#elif defined(BSP_MCU_GROUP_S5D9)
#error Unsupported MCU
#elif defined(BSP_MCU_GROUP_S7G2)
#define LAST_TS  (36)
#else
#define LAST_TS  (36)
#endif
#endif  //LAST_TS

#if !defined(TOUCH_CFG_MAX_UPPER_LAYER_CALLBACKS)
/**
 * Define maximum number of upper layer callbacks (Default = 1)
 */
#define TOUCH_CFG_MAX_UPPER_LAYER_CALLBACKS         (3)
#endif

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/**
 * Different phases of operation for each sensor.
 */
typedef union st_touch_operation
{
    struct st_action{
        uint8_t filter:1;               ///< Enable filter for raw-data (1 := Enabled)
        uint8_t detection:1;            ///< Enable touch detection (1 := Enabled)
        uint8_t drift_comp:1;           ///< Enable drift compensation (1 := Enabled)
        uint8_t sensor_optimize:1;      ///< Enable sensitivity optimization (1 := Enabled)
        uint8_t dummy:3;                //!< dummy
    }bit;
    uint8_t byte;                       ///< Byte representation for fast access
}touch_operation_t;                     ///< Refer @ref st_touch_operation


/**
 * Parameters associated with the state of each sensor.
 */
typedef struct st_sensor_info
{
    /* Public: User provided data */
    touch_sensor_parameter_t * p_touch_sensor;

    /* Private: 26 bytes of volatile data handled by this driver */
    void * p_filter_state;      ///< Filter instance location
    touch_operation_t operation;///< Phase enable/disable bits
    uint16_t input;             ///< Input value (from filter)
    uint16_t baseline;          ///< Current baseline of sensor
    uint16_t delta;             ///< Difference between baseline and input.
    uint8_t dt_count;           ///< Delay to touch counter
    uint8_t dr_count;           ///< Delay to release counter
#if (TOUCH_CFG_VARIABLE_DRIFT_RATES==1)
    uint16_t drift_interval;    ///< Number of iterations to adjust baseline.
#endif
    uint16_t drift_counter;     ///< Counter value counting up to drift_interval
    uint16_t avg_input;         ///< Average value of input value for drift_interval samples
    uint16_t min_input;         ///< Minimum value of input value for drift_interval samples
    uint16_t max_input;         ///< Maximum value of input value for drift_interval samples
    uint16_t recalib_counter;   ///< Counter value counting up to recalib_threshold
    uint16_t avg_sen_cnt_pri;   ///< Average(sensor ICO value)
    uint16_t avg_ref_cnt_sec;   ///< Average(reference ICO value)
}sensor_info_t;                 ///< Refer @ref st_sensor_info

/**
 * Parameters controlling operation of a group of sensors,
 */
typedef struct st_touch_ctrl_blk
{
    /* Lower level information */
    ctsu_instance_t const * const p_ctsu;              ///< Lower level CTSU H/W handle identifier.
    ctsu_mode_t mode;                       ///< CTSU mode of operation.
    const uint8_t num_rx;                   ///< Count of sensors configured as receive electrodes.
    const uint8_t num_tx;                   ///< Count of sensors configured as transmit electrodes.
    const uint8_t offset_en[LAST_TS+1];     ///< Offset of each sensor in receive electrode list (0xff := Unused).
    const uint16_t num_sensors;             ///< Total count of sensors being scanned by CTSU.

    /* Touch related common parameters */
    uint16_t const drift_hold_limit;        ///< Number indicating amount of time drift compensation must be held.
    uint16_t const on_limit;                ///< Number indicating amount of time a sensor can remain touched.
    uint8_t const max_touched_sensors;      ///< Maximum number of touched sensors allowed.

    /* Touch related information (per sensor) */
    sensor_info_t * p_sensor;               ///< Pointer to touch related parameters for each sensor(@ref st_touch_ctrl_blk::num_sensors).

    /* Channel ignoring */
    const uint8_t num_ignored;              ///< Number of touch sensor pin combinations to skip.
    touch_sensor_t const * const p_ignored; ///< Array containing touch sensor pin combinations to skip.

    /* Filter information */
    void (*p_filter)(void*);                ///< Pointer to function used to filter CTSU data.

    /* Touch Detection */
    bool (*p_touch_detect)(void*);          ///< Pointer to function to use for Touch Detection.
    uint8_t * const p_binary_result;        ///< Pointer into user space where binary is stored.

    /* Variables that change over time (not used to determine if block is unique) */
    /* Block management */
    uint32_t open;                          ///< Identifies if a block is in un-used.
    uint16_t upper_level_count;
    uint32_t num_touched;                   ///< Integer identifying number of sensors currently detected as Touched.
    bool multi_touch;
    touch_callback_t p_callback[TOUCH_CFG_MAX_UPPER_LAYER_CALLBACKS]; ///< Callback function to use for upper level notification.
    uint32_t callback_count;
    uint16_t drift_hold_count;              ///< Counts down from drift_hold_limit to 0
    uint16_t on_count;                      ///< Counts up from 0 to st_touch_ctrl_blk::on_limit

    /** Members below this line are not included in the checksum */
    bsp_lock_t lock;                        ///< Identifies if block is being accessed by API.
    uint32_t scan_errors;                   ///< Scan errors returned by lower level.
    uint32_t safety;                        ///< Flag which (set to 0x53414645) identifies that this control block is subject to diagnostic and integrity checking.
    uint32_t checksum;                      ///< Variable holding the checksum.
}touch_instance_ctrl_t;                          ///< Refer @ref st_touch_ctrl_blk

/**
 * Structure passed to the function filtering CTSU generated data.
 */
typedef struct st_filter_args
{
    const uint16_t itr;             ///< Current iteration number (sensor offset)
    const uint16_t input;           ///< Input value returned by the CTSU
    uint16_t output;                ///< Output value (to be provided by the filter)
    void * p_instance;              ///< Instance of the filter control block (passed during Open).
}filter_args_t;                     ///< Refer @ref st_filter_args

/**
 * Structure passed to the function performing Touch detection.
 */
typedef struct st_touch_detect_parameters
{
    uint16_t const input;       ///< Input value (from filter output)
    uint16_t const baseline;    ///< Current baseline of sensor
    uint16_t const threshold;   ///< Threshold count of sensor
    uint16_t const hysteresis;  ///< Hysteresis count of sensor
    uint8_t  const dt_limit;    ///< Delay to touch limit (Immediate = 0)
    uint8_t  const dr_limit;    ///< Delay to release limit (Immediate = 0)

    uint16_t dt_count;          ///< Delay to touch counter
    uint16_t dr_count;          ///< Delay to release counter
    uint16_t delta;             ///< Difference between baseline and input
}touch_detect_t;                ///< Refer @ref st_touch_detect_parameters

/**
 * Structure passed to the function Performing drift compensation.
 */
typedef struct st_drift_parameters
{
    uint16_t const input;   ///< Latest sensor input value
#if (TOUCH_CFG_VARIABLE_DRIFT_RATES==1)
    uint8_t const add_int;  ///< Counts to add to current drift interval
    uint8_t const sub_int;  ///< Counts to subtract from current drift interval
    ctsu_mode_t const mode; ///< Mode of CTSU operation
#endif
    uint16_t interval;      ///< Drift interval

    uint16_t count;         ///< Drift iteration counter
    uint16_t avg_input;     ///< Average sensor input value for current interval
    uint16_t baseline;      ///< Current reference value of sensor input
    uint16_t max_input;     ///< Maximum input value observed over drift interval
    uint16_t min_input;     ///< Minumum input value observed over drift interval
}drift_adjust_t;            ///< Refer @ref st_drift_parameters

/**
 * Structure passed to the function optimizing CTSU sensitivity.
 */
typedef struct st_sensor_optimize
{
    ctsu_instance_t const * const p_ctsu;    ///< CTSU Hardware Identifier to use.
    uint16_t const sensor_offset;            ///< Offset of the sensor in the CTSU configuration
    uint16_t const input;                    ///< Input value of sensor
    uint16_t const baseline;                 ///< Baseline value of sensor
    uint16_t const interval;                 ///< Delay to perform tuning of un-touched sensor (Disabled = 65535)
    uint16_t const threshold;                ///< Expressed as a percentage of the detection threshold setting.
    uint16_t const sen_cnt_pri;              ///< Current sensor ICO value (primary measurement)
    uint16_t const ref_cnt_pri;              ///< Current reference ICO value (primary measurement)
    uint16_t count;                          ///< Re-calibration counter
    uint16_t avg_sen_cnt_pri;                ///< Average(sensor ICO value) over itr_limit
    uint16_t avg_ref_cnt_pri;                ///< Average(reference ICO value) over itr_limit
}sensor_optimize_t;                          ///< Refer @ref st_sensor_optimize

/***********************************************************************************************************************
Exported global variables
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global functions (to be accessed by other files)
***********************************************************************************************************************/
extern touch_api_t const g_touch_on_touch;
#endif /* R_TOUCH_H_ */
