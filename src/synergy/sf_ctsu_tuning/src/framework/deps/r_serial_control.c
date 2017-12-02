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
* Copyright (C) 2015 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/

/***********************************************************************************************************************
* File Name    : r_serial_control.c
* Version      : 1.00
* Device(s)    : R5F5113xAxFP,R5F5231xAxFP,R5F51305AxFN
* Description  : This file is the serial command.
***********************************************************************************************************************/

/***********************************************************************************************************************
* History      : DD.MM.YYYY Version    Description
*              : xx.xx.2015   1.00     First Release
***********************************************************************************************************************/

/***********************************************************************************************************************
* Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include <string.h>
#include "bsp_api.h"
/* Start user code for include. Do not edit comment generated here */
#include "r_ctsu_cfg.h"
#include "r_ctsu_api.h"
#include "sf_ctsu_tuning_cfg.h"
#include "sf_ctsu_tuning.h"

#include "../../../../r_ctsu_v2/src/driver/r_ctsu/r_ctsu_private.h"
#include "../../../../r_touch_v2/src/driver/r_touch/r_touch_private.h"

#if (2 == BSP_CFG_ASSERT)
/** @note Use assertion on the Renesas Virtual Console.
 * Instructions: (Alt+Shift+Q, C) >
 *      (Button)Display Selected Console >
 *          Renesas Virtual Console >
 *              (Button) Pin Console.
 */
#include <assert.h>
#endif

#if defined(KEY_USE)

#endif
#if defined(SLIDER_USE) || defined(WHEEL_USE)

#endif
#include "common_data.h"
#include "r_serial_control.h"

#define __R_SERIAL_COMMAND_C__

/* S/W driver version information(Year/Month) */
#define DF_VERSIONu (0x1603)
/*                     ||++--------------- set Month (BCD) */
/*                     ++----------------- set Year  (BCD / 2015 -> 15) */

/* S/W driver version information(Day/Sub) */
#define DF_VERSIONd (0x110a)
/*                     ||++--------------- set Sub Number (0, a -> f) */
/*                     ++----------------- set Day   (BCD) */

/* Communication command version */
#define DF_CCMD_VER    (1)

/* Chip ID */
#define DF_CHIP_ID    ((DF_CCMD_VER << 8) | SELFCAP_SENSOR_MAX)

/* Date of source file creation */
#define CREATE_SOURCE_DATE0 (0x1608)    /* YYMM */
#define CREATE_SOURCE_DATE1 (0x0315)    /* DDHH */
#define CREATE_SOURCE_DATE2 (0x1528)    /* MMSS */
#define CREATE_SOURCE_DATE3 (0x0000)    /* 0000 */

/* Profile information */
#define DF_PROFILE    (0x1234)

/* End user code. Do not edit comment generated here */

/***********************************************************************************************************************
* Macro definitions
***********************************************************************************************************************/
#define TRUE                (1u)
#define FALSE               (0u)

#define SLIDER_NUMBER       (0)
#define WHEEL_NUMBER        (0)

#if (2 == BSP_CFG_ASSERT)
#define ASSERT(test)    assert(test)
#else
#define ASSERT(test)
#endif

#if !defined(MCU_MODEL)
#define MCU_MODEL   (MCU_MODEL_R5F5xxxxxxxx)
#endif

/* Main loop cycle */
#define TOUCH_MAIN_CYCLE_US     20000

/* Standard measurement time in case of Self-capacitance */
#define SELF_MEASURE_TIME_US    700

/* Standard measurement time in case of Mutual-capacitance */
#define MUTUAL_MEASURE_TIME_US  1400

#if !defined(MAX_TS)
#define MAX_TS      (36)
#endif
/* The number of enable matrix key */
#define MAX_USR_MATRIX_KEY  (MUTUAL0_KEY_NUM + MUTUAL1_KEY_NUM + MUTUAL2_KEY_NUM + MUTUAL3_KEY_NUM + \
                             MUTUAL4_KEY_NUM + MUTUAL5_KEY_NUM + MUTUAL6_KEY_NUM + MUTUAL7_KEY_NUM)
#if !defined(SELF_ENABLE_NUM)
#define SELF_METHOD_NUM     (0)
#define SELFCAP_SENSOR_MAX  (0)
#define SELF_ENABLE_NUM     (0)
#else
#define SELF_METHOD_NUM     (1)

#if (SELF_TS0==TS_MODE_RECEIVE)
#define SELFCAP_SENSOR_MAX     (1)
#endif

#if (SELF_TS1==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (2)
#endif

#if (SELF_TS2==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (3)
#endif

#if (SELF_TS3==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (4)
#endif

#if (SELF_TS4==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (5)
#endif

#if (SELF_TS5==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (6)
#endif

#if (SELF_TS6==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (7)
#endif

#if (SELF_TS7==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (8)
#endif

#if (SELF_TS8==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (9)
#endif

#if (SELF_TS9==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (10)
#endif

#if (SELF_TS10==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (11)
#endif

#if (SELF_TS11==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (12)
#endif

#if (SELF_TS12==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (13)
#endif

#if (SELF_TS13==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (14)
#endif

#if (SELF_TS14==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (15)
#endif

#if (SELF_TS15==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (16)
#endif

#if (SELF_TS16==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (17)
#endif

#if (SELF_TS17==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (18)
#endif

#if (SELF_TS18==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (19)
#endif

#if (SELF_TS19==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (20)
#endif

#if (SELF_TS20==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (21)
#endif

#if (SELF_TS21==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (22)
#endif

#if (SELF_TS22==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (23)
#endif

#if (SELF_TS23==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (24)
#endif

#if (SELF_TS24==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (25)
#endif

#if (SELF_TS25==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (26)
#endif

#if (SELF_TS26==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (27)
#endif

#if (SELF_TS27==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (28)
#endif

#if (SELF_TS28==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (29)
#endif

#if (SELF_TS29==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (30)
#endif

#if (SELF_TS30==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (31)
#endif

#if (SELF_TS31==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (32)
#endif

#if (SELF_TS32==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (33)
#endif

#if (SELF_TS33==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (34)
#endif

#if (SELF_TS34==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (35)
#endif

#if (SELF_TS35==TS_MODE_RECEIVE)
#undef SELFCAP_SENSOR_MAX
#define SELFCAP_SENSOR_MAX     (36)
#endif

#endif

#if (SELF_METHOD_NUM > 0)
#define MAX_SELF_SENSOR_ID   SELFCAP_SENSOR_MAX
#else   // (SELF_METHOD_NUM == 1)
#define MAX_SELF_SENSOR_ID   (0)
#endif  // (SELF_METHOD_NUM == 1)

#if defined(MUTUAL7_ENABLE_NUM)
#define MUTUAL_METHOD_NUM   (8)
#elif defined(MUTUAL6_ENABLE_NUM)
#define MUTUAL_METHOD_NUM   (7)
#elif defined(MUTUAL5_ENABLE_NUM)
#define MUTUAL_METHOD_NUM   (6)
#elif defined(MUTUAL4_ENABLE_NUM)
#define MUTUAL_METHOD_NUM   (5)
#elif defined(MUTUAL3_ENABLE_NUM)
#define MUTUAL_METHOD_NUM   (4)
#elif defined(MUTUAL2_ENABLE_NUM)
#define MUTUAL_METHOD_NUM   (3)
#elif defined(MUTUAL1_ENABLE_NUM)
#define MUTUAL_METHOD_NUM   (2)
#elif defined(MUTUAL0_ENABLE_NUM)
#define MUTUAL_METHOD_NUM   (1)
#else
#define MUTUAL_METHOD_NUM   (0)
#endif

#define METHOD_NUM      (SELF_METHOD_NUM + MUTUAL_METHOD_NUM)

#if (MUTUAL_METHOD_NUM > 7)
#define MAX_MUTUAL_SENSOR_ID   (MUTUAL0_NUM + MUTUAL1_NUM + MUTUAL2_NUM + MUTUAL3_NUM + \
                         MUTUAL4_NUM + MUTUAL5_NUM + MUTUAL6_NUM + MUTUAL7_NUM)
#elif (MUTUAL_METHOD_NUM > 6)
#define MAX_MUTUAL_SENSOR_ID   (MUTUAL0_NUM + MUTUAL1_NUM + MUTUAL2_NUM + MUTUAL3_NUM + \
                         MUTUAL4_NUM + MUTUAL5_NUM + MUTUAL6_NUM)
#elif (MUTUAL_METHOD_NUM > 5)
#define MAX_MUTUAL_SENSOR_ID   (MUTUAL0_NUM + MUTUAL1_NUM + MUTUAL2_NUM + MUTUAL3_NUM + MUTUAL4_NUM + MUTUAL5_NUM)
#elif (MUTUAL_METHOD_NUM > 4)
#define MAX_MUTUAL_SENSOR_ID   (MUTUAL0_NUM + MUTUAL1_NUM + MUTUAL2_NUM + MUTUAL3_NUM + MUTUAL4_NUM)
#elif (MUTUAL_METHOD_NUM > 3)
#define MAX_MUTUAL_SENSOR_ID   (MUTUAL0_NUM + MUTUAL1_NUM + MUTUAL2_NUM + MUTUAL3_NUM)
#elif (MUTUAL_METHOD_NUM > 2)
#define MAX_MUTUAL_SENSOR_ID   (MUTUAL0_NUM + MUTUAL1_NUM + MUTUAL2_NUM)
#elif (MUTUAL_METHOD_NUM > 1)
#define MAX_MUTUAL_SENSOR_ID   (MUTUAL0_NUM + MUTUAL1_NUM)
#elif (MUTUAL_METHOD_NUM > 0)
#define MAX_MUTUAL_SENSOR_ID   (MUTUAL0_NUM)
#else
#define MAX_MUTUAL_SENSOR_ID   (0)
#endif

#define MAX_SENSOR_ID   (MAX_SELF_SENSOR_ID + MAX_MUTUAL_SENSOR_ID)

#define BUF_SIZE_SND_TMP    (4/* HEADER */ +                                                        \
                             4/* BDATA */ * sizeof(uint16_t)/* WORD */ * METHOD_NUM +               \
                             2/* CV + RV */ * sizeof(uint16_t)/* WORD */ * MAX_SENSOR_ID +      \
                             1/* SLIDER POSITION */ * sizeof(uint16_t)/* WORD */ * SLIDER_NUMBER +  \
                             1/* WHEEL POSITION */ * sizeof(uint16_t)/* WORD */ * WHEEL_NUMBER +    \
                             2/* RETURN VALUE */)

#define HEAD_SIZE           (4)
#define BUF_SIZE_RCV        (HEAD_SIZE + 32)
#define MONITOR_CMD_SIZE    (24)

#define BUF_SIZE_SND        (BUF_SIZE_SND_TMP + BUF_SIZE_SND_TMP % 4)

// command definition
#define CMD_PROFILE    (0x00u)
#define CMD_MEASURE    (0x01u)
#define CMD_PARAMETER  (0x02)
#define CMD_REGISTER   (0x03)
#define CMD_UTILITY    (0x04)
#define CMD_RESERVED   (0x05)

// Workbench ---> Touch sensor
#define CMD_RQ    (0x00u)
#define CMD_READ  (0x00)
#define CMD_WRITE (0x40)

#define CMD_RQ_PROFILE_READ     (CMD_RQ | CMD_READ  | CMD_PROFILE)      // sensor data read request
#define CMD_RQ_PROFILE_WRITE    (CMD_RQ | CMD_WRITE | CMD_PROFILE)      // sensor data read request
#define CMD_RQ_MEASURE_READ     (CMD_RQ | CMD_READ  | CMD_MEASURE)      // sensor data write request
#define CMD_RQ_MEASURE_WRITE    (CMD_RQ | CMD_WRITE | CMD_MEASURE)      // sensor data write request
#define CMD_RQ_PARAMETER_READ   (CMD_RQ | CMD_READ  | CMD_PARAMETER)    // usb i/f board status getting request
#define CMD_RQ_PARAMETER_WRITE  (CMD_RQ | CMD_WRITE | CMD_PARAMETER)    // usb i/f board status getting request
#define CMD_RQ_REGISTER_READ    (CMD_RQ | CMD_READ  | CMD_REGISTER)     // usb i/f board status control request
#define CMD_RQ_REGISTER_WRITE   (CMD_RQ | CMD_WRITE | CMD_REGISTER)     // usb i/f board status control request
#define CMD_RQ_UTILITY_READ     (CMD_RQ | CMD_READ  | CMD_UTILITY)      // usb i/f board read request
#define CMD_RQ_UTILITY_WRITE    (CMD_RQ | CMD_WRITE | CMD_UTILITY)      // usb i/f board read request

// Workbench <=== Touch sensor 
#define CMD_RE    (0x80u)

#define CMD_RESULT_SUCCESS    (0x00)
#define CMD_RESULT_FAILURE    (0xff)

#define CMD_UTILITY_PARAM_UPDATE    (1)
#define CMD_UTILITY_PARAM_RESET     (2)

#define CMD_UTILITY_UPDATE_FINISH   (0)
#define CMD_UTILITY_UPDATE_RUNNING  (1)

#define CMD_UTILITY_RESET_FINISH    (0)
#define CMD_UTILITY_RESET_RUNNING   (1)

#define COMMAND_MODE_SERIAL (0)    // Serial port communication
#define COMMAND_MODE_IDE    (1)    // Cube suite+/e2studio communication

/* Define the number of matrix key in Matrix0 when Matrix0 is disabled.  */
#if !defined(MUTUAL0_KEY_NUM)
#define MUTUAL0_KEY_NUM  0
#endif

/* Define the number of matrix key in Matrix1 when Matrix1 is disabled.  */
#if !defined(MUTUAL1_KEY_NUM)
#define MUTUAL1_KEY_NUM  0
#endif

/* Define the number of matrix key in Matrix2 when Matrix2 is disabled.  */
#if !defined(MUTUAL2_KEY_NUM)
#define MUTUAL2_KEY_NUM  0
#endif

/* Define the number of matrix key in Matrix3 when Matrix3 is disabled.  */
#if !defined(MUTUAL3_KEY_NUM)
#define MUTUAL3_KEY_NUM  0
#endif

/* Define the number of matrix key in Matrix4 when Matrix4 is disabled.  */
#if !defined(MUTUAL4_KEY_NUM)
#define MUTUAL4_KEY_NUM  0
#endif

/* Define the number of matrix key in Matrix5 when Matrix5 is disabled.  */
#if !defined(MUTUAL5_KEY_NUM)
#define MUTUAL5_KEY_NUM  0
#endif

/* Define the number of matrix key in Matrix6 when Matrix6 is disabled.  */
#if !defined(MUTUAL6_KEY_NUM)
#define MUTUAL6_KEY_NUM  0
#endif

/* Define the number of matrix key in Matrix7 when Matrix7 is disabled.  */
#if !defined(MUTUAL7_KEY_NUM)
#define MUTUAL7_KEY_NUM  0
#endif

/* Decide the number of maxumum matrix keys in all matrix */
#if (MUTUAL0_KEY_NUM >= MUTUAL1_KEY_NUM)
    #define MUTUAL01_MAX MUTUAL0_KEY_NUM
#else
    #define MUTUAL01_MAX MUTUAL1_KEY_NUM
#endif

#if (MUTUAL01_MAX >= MUTUAL2_KEY_NUM)
    #define MUTUAL02_MAX MUTUAL01_MAX
#else
    #define MUTUAL02_MAX MUTUAL2_KEY_NUM
#endif

#if (MUTUAL02_MAX >= MUTUAL3_KEY_NUM)
    #define MUTUAL03_MAX MUTUAL02_MAX
#else
    #define MUTUAL03_MAX MUTUAL3_KEY_NUM
#endif

#if (MUTUAL03_MAX >= MUTUAL4_KEY_NUM)
    #define MUTUAL04_MAX MUTUAL03_MAX
#else
    #define MUTUAL04_MAX MUTUAL4_KEY_NUM
#endif

#if (MUTUAL04_MAX >= MUTUAL5_KEY_NUM)
    #define MUTUAL05_MAX MUTUAL04_MAX
#else
    #define MUTUAL05_MAX MUTUAL5_KEY_NUM
#endif

#if (MUTUAL05_MAX >= MUTUAL6_KEY_NUM)
    #define MUTUAL06_MAX MUTUAL05_MAX
#else
    #define MUTUAL06_MAX MUTUAL6_KEY_NUM
#endif

#if (MUTUAL06_MAX >= MUTUAL7_KEY_NUM)
    #define MUTUAL07_MAX MUTUAL06_MAX
#else
    #define MUTUAL07_MAX MUTUAL7_KEY_NUM
#endif

/* Maximum measurement time in case of the Self-capacitance */
#define SELF_METHOD_MAX_US  (SELF_ENABLE_NUM * SELF_MEASURE_TIME_US)

/* Maximum measurement time in case of the Mutual-capacitance */
#define MUTUAL_METHOD_MAX_US (MUTUAL07_MAX * MUTUAL_MEASURE_TIME_US)

/* Re-define the measurement time with minimum value when the measurement time is less than minimum value  */
#if (SELF_METHOD_MAX_US < TOUCH_MAIN_CYCLE_US)
    #undef  SELF_METHOD_MAX_US
    #define SELF_METHOD_MAX_US  TOUCH_MAIN_CYCLE_US
#endif

#if (MUTUAL_METHOD_MAX_US < TOUCH_MAIN_CYCLE_US)
    #undef  MUTUAL_METHOD_MAX_US
    #define MUTUAL_METHOD_MAX_US  TOUCH_MAIN_CYCLE_US
#endif

/* Convert unit of the maximum measurement time to mill-second */
#if (MUTUAL_METHOD_MAX_US >= SELF_METHOD_MAX_US)
    #define TOUCH_METHOD_MAX_MS ((MUTUAL_METHOD_MAX_US / 1000) + 1)
#else
    #define TOUCH_METHOD_MAX_MS ((SELF_METHOD_MAX_US / 1000) + 1)
#endif

/* Define all measurement time of all method */
#define TOUCH_METHOD_CYCLE_MS ((SELF_METHOD_NUM + MUTUAL_METHOD_NUM) * TOUCH_METHOD_MAX_MS)

#if (ADD_TIME == 4)
#define WAIT_TIME    ADD4_WAIT_FREQUENCY * TOUCH_METHOD_CYCLE_MS   /* Wait-frequency:42 */
#elif ( ADD_TIME == 5 )
#define WAIT_TIME    ADD5_WAIT_FREQUENCY * TOUCH_METHOD_CYCLE_MS   /* Wait-frequency:56 */
#elif ( ADD_TIME == 6 )
#define WAIT_TIME    ADD6_WAIT_FREQUENCY * TOUCH_METHOD_CYCLE_MS   /* Wait-frequency:67 */
#elif ( ADD_TIME == 7 )
#define WAIT_TIME    ADD7_WAIT_FREQUENCY * TOUCH_METHOD_CYCLE_MS   /* Wait-frequency:78 */
#elif ( ADD_TIME == 8 )
#define WAIT_TIME    ADD8_WAIT_FREQUENCY * TOUCH_METHOD_CYCLE_MS   /* Wait-frequency:90 */
#else
#define WAIT_TIME   TOUCH_METHOD_CYCLE_MS
#endif

/***********************************************************************************************************************
* Typedef definitions
***********************************************************************************************************************/
typedef    unsigned char    BOOL;

typedef union type_com_data_rd
{
    struct
    {
        uint8_t main;
        uint8_t sub;
        uint8_t size;
        uint8_t sum;
        uint8_t data[BUF_SIZE_RCV - HEAD_SIZE];
    } fmt;
    uint8_t byte_acs[BUF_SIZE_RCV];
} com_data_rd_t;

typedef union type_com_data_tx
{
    uint32_t dw_acs[BUF_SIZE_SND / 4];
    struct
    {
        uint8_t main;
        uint8_t sub;
        uint8_t size;
        uint8_t sum;
        uint8_t data[BUF_SIZE_SND - HEAD_SIZE];
    } fmt;
    uint8_t byte_acs[BUF_SIZE_SND];
}com_data_tx_t;

typedef struct type_monitor_command
{
    uint8_t command[MONITOR_CMD_SIZE];
    uint8_t size;
} monitor_command_t;

#if (SELFCAP_SENSOR_MAX > MUTUAL07_MAX)
    #define MAX_KEY_NUM SELFCAP_SENSOR_MAX
#else
    #define MAX_KEY_NUM MUTUAL07_MAX
#endif

typedef struct
{
    uint8_t index[MAX_KEY_NUM];
}    touch_key_index_table_t;

#define METHOD_TYPE_SLFCP   (0)
#define METHOD_TYPE_MTLCP   (1)
typedef struct
{
    uint8_t type;   /* Method type (METHOD_TYPE_SLFCP, METHOD_TYPE_MTLCP ) */
    uint8_t enable; /* Number of enabled touch sensor */
}   method_info_t;

/** Immediate raw data readings from the CTSU registers CTSUSC(sensor count) and CTSURC(Reference count) in self-capacitance mode. */
typedef struct st_ctsu_channel_measurement_self
{
    uint16_t    sen_cnt;        ///< Sensor ICO count
    uint16_t    ref_cnt;        ///< Reference ICO count
} ctsu_channel_data_self_t;

/** Immediate raw data readings from the CTSU registers CTSUSC(sensor count) and CTSURC(Reference count) in mutual-capacitance mode. */
typedef struct st_ctsu_channel_measurement_mutual
{
    uint16_t sen_cnt_1;         ///< Sensor ICO count (primary measurement)
    uint16_t ref_cnt_1;         ///< Reference ICO count (primary measurement)
    uint16_t sen_cnt_2;         ///< Sensor ICO count (secondary measurement)
    uint16_t ref_cnt_2;         ///< Reference ICO count (secondary measurement)
} ctsu_channel_data_mutual_t;

/* Flag define */
typedef union
{
    uint8_t        byte;    /* flag data       */
    struct
    {
        uint8_t    sens_over       : 1;        /* 0 sensor counter overflow flag              */
        uint8_t    ref_over        : 1;        /* 1 reference counter overflow flag           */
        uint8_t    icomp_error     : 1;        /* 2 TSCAP voltage error                       */
        uint8_t    ctsu_measure    : 1;        /* 3 CTSU measurement on flag                  */
        uint8_t    data_update     : 1;        /* 5 measurement data updata flug              */
        uint8_t    dummy           : 3;        /* 7-6 dummy                                   */
    } flag;
} ctsu_status_t;

/*=====    Touch system control flag    ==============================================================================*/
typedef union
{
    struct
    {
        volatile uint8_t    initial       :1;        /* Calibration completion flag                                   */
        volatile uint8_t    timing        :1;        /* timing flag                                                   */
        volatile uint8_t    reserved      :6;        /* reserved                                                      */
    } flag;
    uint8_t    value;
} touch_system_t;

/*=====    Touch function control flag    ============================================================================*/
typedef union
{
    struct
    {
        volatile uint8_t    tuning        :1;        /* Initial tuning completion flag                                */
        volatile uint8_t    average       :1;        /* Moving average flag                                           */
        volatile uint8_t    calib         :1;        /* Calibration completion flag                                   */
        volatile uint8_t    drift         :1;        /* Drift correction                                              */
        volatile uint8_t    msa           :1;        /* Maximum successive on counter                                 */
        volatile uint8_t    acd0          :1;        /* Accumulated counter                                           */
        volatile uint8_t    acd1          :1;        /* Accumulated coutner                                           */
        volatile uint8_t    mtc           :1;        /* Multi touch canceller                                         */
    } flag;
    uint8_t    value;
} touch_func_flag_t;

/*=====    Touch function parameter    ===============================================================================*/
typedef struct
{
    uint8_t     calib_key_num;                       /*  */
    uint8_t     calib_freq;                          /* Calibration frequency                                         */
    uint8_t     touch_freq;                          /* Continuous agreement touch comparison frequency               */
    uint8_t     not_touch_freq;                      /* Continuous agreement non-touch comparison frequency           */
    uint16_t    drift_freq;                          /* Drift correction frequency                                    */
    uint16_t    msa_freq;                            /* Compulsion touch cancellation frequency                       */
} touch_func_param_t;

/*=====    Touch key parameter information    ========================================================================*/
typedef struct
{
             uint8_t     mode;                       /* Measurement mode flag    0 = Self, 1 = Mutual                 */
             uint8_t     key_num;                    /* Key funtion number                                            */
             uint8_t     ena_num;                    /* Touch sensor number                                           */
             uint8_t     key_max_group;              /* Key group max number                                          */
             uint16_t    *ref;                       /* Reference value                                               */
             uint16_t    *thr;                       /* Threshold value                                               */
             uint16_t    *user_thr;                  /* User setting touch threshold value                            */
             uint16_t    *hys;                       /* User setting hysteresis value                                 */
             uint16_t    *delta;                     /* Touch judgment delta  value                                   */
             uint16_t    *touch_cnt;                 /* Continuous agreement touch counter                            */
             uint16_t    *non_touch_cnt;             /* Continuous agreement non-touch counter                        */
             uint16_t    *in_touch;                  /* Inside touch flag                                             */
             uint16_t    *out_touch;                 /* Outside touch flag                                            */
             uint16_t    *touch_result;              /* Touch result flag                                             */
             uint16_t    *drift_permission;          /* Drift permission flag                                         */
             uint32_t    *drift_add_ref;             /* Drift reference value                                         */
             uint16_t    *drift_cnt;                 /* Drift correction counter                                      */
             uint16_t    *key_used_info;             /* Keu function used flag                                        */
             uint8_t     *sensor_index;              /* Touch sensor index                                            */
} key_info_t;
/*=====    Offset tuning information    ==============================================================================*/
typedef struct
{
             uint16_t    *ctsuso;                    /* Tuning ctsuso value                                           */
    volatile uint8_t     *result;                    /* Tuning completion flag                                        */
} touch_tuning_t;

/*=====    Calibration information    ================================================================================*/
typedef struct
{
             uint8_t     calib_key;                  /* Calibration key number                                        */
             uint8_t     calib_cnt;                  /* Calibration counter                                           */
             uint16_t    *calib_data;                /* Calibration value                                             */
} calib_info_t;

typedef struct
{
    const    uint16_t    *user_thr;                  /* User setting touch threshold  value                           */
    const    uint16_t     *user_hys;                  /* Hysteresis value                                              */
} key_user_param_t;

typedef struct
{
    const    uint16_t    *group;                     /*                         */
} touch_group_param_t;

/*=====    Slider information    =====================================================================================*/
typedef struct
{
    uint8_t     ts[10];                              /* Touch sensor number                                           */
    uint8_t     num;                                 /* Electrodes number                                             */
    uint16_t    threshold;                           /* Position calculation startthreshold value                     */
    uint16_t    resolution;                          /* Position resolution                                           */
    uint16_t    value;                               /*                                                               */
} slider_info_t;

/*=====    Wheel information    ======================================================================================*/
typedef struct
{
    uint8_t     ts[8];                               /* Touch sensor number                                           */
    uint8_t     num;                                 /* Electrodes number                                             */
    uint16_t    threshold;                           /* Position calculation startthreshold value                     */
    uint16_t    resolution;                          /* Position resolution                                           */
    uint16_t    value;                               /*                                                               */
} wheel_info_t;

/*=====    Button(Key), Slider, Wheel result information    ==========================================================*/


typedef struct
{
    uint8_t     data_num[10];                        /* Touch sensor number                                           */
} index_info_t;

/*=====    CTSU measure mode    ======================================================================================*/
typedef enum
{
    CTSU_STOP_MODE        = 0,
    CTSU_READY_MODE       = 1,
    CTSU_RUN_MODE         = 2,
    CTSU_FINISH_MODE      = 3
} ctsu_measure_mode;

/***********************************************************************************************************************
* Exported global variables (to be accessed by other files);
***********************************************************************************************************************/
#if defined(KEY_USE) && defined(USING_CAPTOUCH_BUTTONS) && (USING_CAPTOUCH_BUTTONS > 0)
extern touch_button_t* touch_buttons[];
extern const size_t num_touch_buttons;
#endif

#if defined(SLIDER_USE) || defined(WHEEL_USE)

#endif

#ifdef SLIDER_USE
slider_info_t    g_sliderInfo[SLIDER_NUMBER];
#endif

#ifdef WHEEL_USE
wheel_info_t     g_wheelInfo[WHEEL_NUMBER];
#endif

/***********************************************************************************************************************
* Private global variables and functions
***********************************************************************************************************************/
#ifdef WORKBENCH_COMMAND_USE
com_data_rd_t com_data =    /* Received data buffer */
{
    .byte_acs = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF},
};
com_data_tx_t rsp_cmd;    /* Transmit data buffer */
monitor_command_t monitor_command;    /* Monitor commands buffer */
BOOL        serial_transmit_ready;
uint8_t     command_mode;

/* MCU model name */
static const uint8_t *g_mcu_model_name;

const uint8_t g_matrix_index[] = {
    0,   1,  2,  3,  4,  5,  6,  7,  8,  9, 10, 11, 12, 13, 14, 15,
    16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31,
    32, 33, 34, 35, 36, 37, 38, 39, 40, 41, 42, 43, 44, 45, 46, 47,
    48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63,
};

//touch_system_t          g_touch_system;
touch_func_flag_t       g_touch_function[METHOD_NUM];
touch_func_param_t      g_touch_paramter[METHOD_NUM];
key_info_t              g_key_info[METHOD_NUM];
//touch_tuning_t          g_touch_tuning_info[METHOD_NUM];
//calib_info_t            g_calib_info[METHOD_NUM];
//key_user_param_t        g_key_user_parameter[METHOD_NUM];
touch_group_param_t     g_touch_key_group[METHOD_NUM];
//touch_result_t          g_touch_all_result[METHOD_NUM];
volatile uint8_t       g_ctsu_soft_mode;                                        /* CTSU operating mode flag                  */
volatile ctsu_status_t           g_ctsu_status[METHOD_NUM];                     /* CTSU measurement status flag */
uint8_t comm_command = 0;

ctsu_ctrl_t* ctsu_handle_id[METHOD_NUM];
touch_ctrl_t* touch_handle_id[METHOD_NUM];

ctsu_cfg_t * all_ctsu_configs[METHOD_NUM];
touch_cfg_t* all_touch_configs[METHOD_NUM];

static uint8_t g_burst_mode = 0;

uint8_t g_access_method  = 0;

static method_info_t g_method_info[] = {
/* --[Self capacitance]----------------- */
#if ( SELF_METHOD_NUM > 0 )
    { METHOD_TYPE_SLFCP,    SELFCAP_SENSOR_MAX },
#endif  // ( SELF_METHOD_NUM > 0 )
/* --[Mutual capacitance 0]------------- */
#if ( MUTUAL_METHOD_NUM > 0 )
    { METHOD_TYPE_MTLCP,    MUTUAL0_NUM },
#endif  // ( MUTUAL_METHOD_NUM > 0 )
/* --[Mutual capacitance 1]------------- */
#if ( MUTUAL_METHOD_NUM > 1 )
    { METHOD_TYPE_MTLCP,   MUTUAL1_NUM },
#endif  // ( MUTUAL_METHOD_NUM > 1 )
/* --[Mutual capacitance 2]------------- */
#if ( MUTUAL_METHOD_NUM > 2 )
    { METHOD_TYPE_MTLCP,   MUTUAL2_NUM },
#endif  // ( MUTUAL_METHOD_NUM > 2 )
/* --[Mutual capacitance 3]------------- */
#if ( MUTUAL_METHOD_NUM > 3 )
    { METHOD_TYPE_MTLCP,   MUTUAL3_NUM },
#endif  // ( MUTUAL_METHOD_NUM > 3 )
/* --[Mutual capacitance 4]------------- */
#if ( MUTUAL_METHOD_NUM > 4 )
    { METHOD_TYPE_MTLCP,   MUTUAL4_NUM },
#endif  // ( MUTUAL_METHOD_NUM > 4 )
/* --[Mutual capacitance 5]------------- */
#if ( MUTUAL_METHOD_NUM > 5 )
    { METHOD_TYPE_MTLCP,   MUTUAL5_NUM },
#endif  // ( MUTUAL_METHOD_NUM > 5 )
/* --[Mutual capacitance 6]------------- */
#if ( MUTUAL_METHOD_NUM > 6 )
    { METHOD_TYPE_MTLCP,   MUTUAL6_NUM },
#endif  // ( MUTUAL_METHOD_NUM > 6 )
/* --[Mutual capacitance 7]------------- */
#if ( MUTUAL_METHOD_NUM > 7 )
    { METHOD_TYPE_MTLCP,   MUTUAL7_NUM },
#endif  // ( MUTUAL_METHOD_NUM > 7 )
};


static void CreateResponceCommand(com_data_tx_t * pcmd);
static uint8_t SetChecksum(uint8_t main, uint8_t sub, uint8_t size, uint8_t * pdata);
static BOOL IsRightChecksum(com_data_rd_t * pcmd);
static uint8_t GetSensorValue(uint8_t code, uint16_t channel, uint16_t * pval);
static void SensorProfileReadResponse(com_data_tx_t * pcmd, uint16_t channel);
static void SensorMeasureReadResponse(com_data_tx_t * pcmd, uint16_t channel);
static void SensorParameterReadResponse(com_data_tx_t * pcmd, uint16_t channel);
static void SensorParameterWriteResponse(com_data_tx_t * pcmd, uint16_t channel);
static void SensorRegisterReadResponse(com_data_tx_t * pcmd, uint16_t channel);
static void SensorRegisterWriteResponse(com_data_tx_t * pcmd, uint16_t channel);
static void SensorUtilityReadResponse(com_data_tx_t * pcmd, uint16_t channel);
static void SensorUtilityWriteResponse(com_data_tx_t * pcmd, uint16_t channel);
void serial_control_callback(ctsu_callback_arg_t const * const p_arg);

#if 0
static void InitKeyIndexTable(void);
#endif
#endif // WORKBENCH_COMMAND_USE

/***********************************************************************************************************************
* Function Name: SerialCommandInitial
* Description  : Serial command initialization
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
uint8_t g_key_sensor_index[METHOD_NUM][(MAX_MUTUAL_SENSOR_ID > SELFCAP_SENSOR_MAX) ? MAX_MUTUAL_SENSOR_ID : SELFCAP_SENSOR_MAX];
uint16_t g_touch_key_group_group[METHOD_NUM][(MAX_MUTUAL_SENSOR_ID > SELFCAP_SENSOR_MAX) ? ((MAX_MUTUAL_SENSOR_ID >> 4) + 1) : ((SELFCAP_SENSOR_MAX >> 4) + 1)];
touch_sensor_t g_sensors[METHOD_NUM][(MAX_MUTUAL_SENSOR_ID > SELFCAP_SENSOR_MAX) ? MAX_MUTUAL_SENSOR_ID : SELFCAP_SENSOR_MAX];

int SerialCommandInitialTouch(touch_instance_t * p_touch, const uint8_t itr)
{
#if (SF_CTSU_TUNING_CFG_PARAM_CHECK==true)
    ASSERT(itr < METHOD_NUM);
    ASSERT(p_touch != NULL);
    ASSERT(p_touch->p_cfg != NULL);
#endif
    int err = SerialCommandInitial((ctsu_instance_t *)p_touch->p_cfg->p_ctsu, itr);

    if(!err)
    {
        return err;
    }

    g_key_info[itr].touch_result = (uint16_t*)all_touch_configs[itr]->p_binary_result;
    all_touch_configs[itr] = (touch_ctrl_t*)p_touch->p_cfg;
    touch_handle_id[itr]   = p_touch->p_ctrl;

    /* Global information */
    g_touch_paramter[itr].drift_freq = all_touch_configs[itr]->p_sensor[0].drift_rate;
    g_touch_paramter[itr].msa_freq = all_touch_configs[itr]->p_common->on_limit;
    g_touch_paramter[itr].touch_freq = all_touch_configs[itr]->p_sensor[0].dt_limit;
    g_touch_paramter[itr].not_touch_freq = all_touch_configs[itr]->p_sensor[0].dr_limit;

    g_touch_function[itr].flag.drift = (g_touch_paramter[itr].drift_freq < UINT16_MAX) ? (true):(false);
    g_touch_function[itr].flag.msa = (g_touch_paramter[itr].msa_freq < UINT16_MAX) ? (true):(false);
    g_touch_function[itr].flag.acd0 = (g_touch_paramter[itr].touch_freq < UINT8_MAX) ? (true):(false);
    g_touch_function[itr].flag.acd1 = (g_touch_paramter[itr].not_touch_freq < UINT8_MAX) ? (true):(false);

    return 1;
}

int SerialCommandInitial(ctsu_instance_t * p_ctsu, const uint8_t itr)
{
#if (SF_CTSU_TUNING_CFG_PARAM_CHECK==true)
    ASSERT(itr < METHOD_NUM);
    ASSERT(p_ctsu!=NULL);
    ASSERT(p_ctsu->p_cfg != NULL);
#endif
    ctsu_cfg_t const * const p_cfg = p_ctsu->p_cfg;
#ifdef WORKBENCH_COMMAND_USE
    serial_transmit_ready = FALSE;
#if (USING_USB_COMM > 0)
    command_mode          = COMMAND_MODE_SERIAL;
#endif

    uint8_t ch_num;
    uint16_t index;
    uint8_t arr_rx[MAX_TS];
    uint8_t arr_tx[MAX_TS];
    extern const fmi_instance_t g_fmi;
    (void)index;

    fmi_product_info_t * p_product_info;
    g_fmi.p_api->productInfoGet(&p_product_info);
    g_mcu_model_name = p_product_info->product_name;


    ctsu_mode_t mode = ((p_cfg->p_ctsu_settings->ctsucr1.byte & 0xC0) >> 6);

    if(mode==CTSU_MODE_SELF_CAPACITANCE)
    {
        g_method_info[itr].type=METHOD_TYPE_SLFCP;
    }
    else if(mode==CTSU_MODE_MUTUAL_CAPACITANCE)
    {
        g_method_info[itr].type=METHOD_TYPE_MTLCP;
    }
    else
    {
        return 0;
    }


    uint8_t tx_count = 0;
    uint8_t rx_count = 0;
    uint16_t index_rx;
    uint16_t index_tx;

    uint64_t ch_en = 0;
    uint64_t ch_tx = 0;
#if !defined(BSP_MCU_RX113)
    ch_en = p_cfg->p_ctsu_settings->ctsuchac4.byte;
    ch_tx = p_cfg->p_ctsu_settings->ctsuchtrc4.byte;
    ch_en <<= 8;
    ch_tx <<= 8;
    ch_en |= p_cfg->p_ctsu_settings->ctsuchac3.byte;
    ch_tx |= p_cfg->p_ctsu_settings->ctsuchtrc3.byte;
    ch_en <<= 8;
    ch_tx <<= 8;
    ch_en |= p_cfg->p_ctsu_settings->ctsuchac2.byte;
    ch_tx |= p_cfg->p_ctsu_settings->ctsuchtrc2.byte;
    ch_en <<= 8;
    ch_tx <<= 8;
#endif
    ch_en |= p_cfg->p_ctsu_settings->ctsuchac1.byte;
    ch_tx |= p_cfg->p_ctsu_settings->ctsuchtrc1.byte;
    ch_en <<= 8;
    ch_tx <<= 8;
    ch_en |= p_cfg->p_ctsu_settings->ctsuchac0.byte;
    ch_tx |= p_cfg->p_ctsu_settings->ctsuchtrc0.byte;

    /* Global information */
    g_touch_paramter[g_access_method].drift_freq = 0xffff;
    g_touch_paramter[g_access_method].msa_freq = 0xffff;
    g_touch_paramter[g_access_method].touch_freq = 0xff;
    g_touch_paramter[g_access_method].not_touch_freq = 0xff;

    /* Assign the sensor index number array. */
    g_key_info[itr].sensor_index = g_key_sensor_index[itr];

    if (0 == ch_en)
    {
        return 0;
    }

    if(g_method_info[itr].type==METHOD_TYPE_SLFCP)
    {
        for( ch_num = 0; ch_num < SELFCAP_SENSOR_MAX; ch_num++)
        {
            g_key_info[itr].sensor_index[ch_num] = 0x0;
            g_sensors[itr][ch_num].rx = 0xff;
            g_sensors[itr][ch_num].tx = 0xff;
            if((ch_en & ((uint64_t)1<<ch_num))==((uint64_t)1<<ch_num))
            {
                g_key_info[itr].ena_num++;
                g_key_info[itr].sensor_index[ch_num] = rx_count;
                g_sensors[itr][ch_num].rx = ch_num;
                g_sensors[itr][ch_num].tx = 0xFF;
                rx_count++;
            }
        }
        g_touch_key_group[itr].group = g_touch_key_group_group[itr];
        g_key_info[itr].touch_result = (uint16_t*)all_touch_configs[itr]->p_binary_result;
        g_key_info[itr].key_max_group = (SELFCAP_SENSOR_MAX >> 4) + 1;
    }
    else if(g_method_info[itr].type==METHOD_TYPE_MTLCP)
    {
        for( ch_num = 0, rx_count = 0; ch_num < MAX_TS; ch_num++)
        {
            arr_rx[rx_count] = 0xFF;
            if(((ch_en & ((uint64_t)1<<ch_num))==((uint64_t)1<<ch_num)) && ((ch_tx & ((uint64_t)1<<ch_num))==0))
            {
                arr_rx[rx_count] = ch_num;
                rx_count++;
            }
        }
        for( ch_num = 0, tx_count = 0; ch_num < MAX_TS; ch_num++)
        {
            arr_tx[tx_count] = 0xFF;
            if((ch_tx & ((uint64_t)1<<ch_num))==((uint64_t)1<<ch_num))
            {
                arr_tx[tx_count] = ch_num;
                tx_count++;
            }
        }
        ASSERT(((rx_count*tx_count) <= 64)&&((rx_count*tx_count) > 0));
        g_touch_key_group[itr].group = g_touch_key_group_group[itr];
        g_key_info[itr].sensor_index = g_key_sensor_index[itr];
        g_key_info[itr].ena_num = (uint8_t)(rx_count*tx_count);
        g_key_info[itr].key_num = 0;

        if(g_key_info[itr].ena_num > 0)
        {
            /* Save the number of channels enabled. */
            g_key_info[itr].touch_result = (uint16_t*)all_touch_configs[itr]->p_binary_result;
        g_key_info[itr].key_max_group = (uint8_t)((g_key_info[itr].ena_num >> 4) + 1);
        }

        for(index_rx = 0; index_rx < rx_count; index_rx++)
        {
            for(index_tx = 0; index_tx < tx_count; index_tx++)
            {
                g_key_info[itr].sensor_index[(index_rx*tx_count)+index_tx] = (uint8_t)((index_rx*tx_count)+index_tx);
                g_key_info[itr].key_num++;
                g_touch_key_group_group[itr][((index_rx*tx_count)+index_tx) >> 4] = (uint8_t)(g_touch_key_group_group[itr][((index_rx*tx_count)+index_tx) >> 4] |(1<<(((index_rx*tx_count)+index_tx)%16)));        //Right shift by 4 because group is a uint16_t.
                g_sensors[itr][(index_rx*tx_count)+index_tx].rx = arr_rx[index_rx];
                g_sensors[itr][(index_rx*tx_count)+index_tx].tx = arr_tx[index_tx];
            }
        }
    }

    if(0==g_key_info[itr].key_num)
    {
        g_key_info[itr].key_num = g_key_info[itr].ena_num;
    }

    all_ctsu_configs[itr] = (ctsu_cfg_t *)p_cfg;
    ctsu_handle_id[itr] = p_ctsu->p_ctrl;

#endif //WORKBENCH_COMMAND_USE

    return 1;
}

/***********************************************************************************************************************
* Function Name: PrepareReplayMessage
* Description  :
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void PrepareReplayMessage(void)
{
#ifdef WORKBENCH_COMMAND_USE
    if (serial_transmit_ready)
    {
        if (COMMAND_MODE_IDE == command_mode)
        {
            /* preparing transmittion buffer */
            CreateResponceCommand(&rsp_cmd);
        }
        serial_transmit_ready    = FALSE;
    }
#endif // WORKBENCH_COMMAND_USE
}

/***********************************************************************************************************************
* Function Name: Serial command receive
* Description  : SerialCommandReceive
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
uint8_t    SerialCommandReceive(uint8_t * value, uint16_t length)
{
    uint8_t result = FALSE;

#ifdef WORKBENCH_COMMAND_USE
    uint8_t i;

    for (i = 0; i < length; i++)
    {
        com_data.byte_acs[i]    = value[i];
    }
    if (FALSE != IsRightChecksum(&com_data))
    {
        serial_transmit_ready    = TRUE;

        result    = TRUE;
    }
#endif // WORKBENCH_COMMAND_USE
    return result;
}

/***********************************************************************************************************************
* Function Name: GetReplayMessage
* Description  : Replay the serial command from USB port.
* Arguments    : 
* Return Value : TRUE: success, FALSE: failure
***********************************************************************************************************************/
uint8_t    GetReplayMessage(uint8_t * value, uint16_t * length)
{
    BOOL    result = FALSE;

#ifdef WORKBENCH_COMMAND_USE
    uint16_t i;
    uint16_t size;

    if (serial_transmit_ready)
    {
        /* preparing transmittion buffer */
        CreateResponceCommand(&rsp_cmd);

        /* UARTi transmission data is set */
        *length    =
        size    = (uint8_t)(rsp_cmd.fmt.size + HEAD_SIZE);
        if (rsp_cmd.fmt.main & 0x20)
        {
            size = (uint16_t)(size + 256);
            *length = size;
        }
        for (i = 0; i < size; i++)
        {
            value[i]    = rsp_cmd.byte_acs[i];
        }
        serial_transmit_ready    = FALSE;
        result                   = TRUE;
    }
#endif // WORKBENCH_COMMAND_USE
    return result;
}

#ifdef WORKBENCH_COMMAND_USE // [
/***********************************************************************************************************************
* Function Name: GetMeasureSensorCounter
* Description  : Getting the value of Sensor counter value (Count value)
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetMeasureSensorCounter(uint16_t channel, uint16_t * value)
{
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_TUNING)
    uint8_t result;
    uint8_t index;

    *value = 0xffff;
    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type == 0)
        {
            index = g_key_info[g_access_method].sensor_index[channel];
            if ( index != 0xff)
            {
                ctsu_channel_data_self_t* result = (ctsu_channel_data_self_t*)all_ctsu_configs[g_access_method]->p_sensor_data;
                *value = result[index].sen_cnt;
            }
        }
        else
        {
            index = g_key_info[g_access_method].sensor_index[channel];
            if (g_key_info[g_access_method].sensor_index[channel] != 0xff)
            {
                ctsu_channel_data_mutual_t* result = (ctsu_channel_data_mutual_t*)all_ctsu_configs[g_access_method]->p_sensor_data;
                *value = (result[index].sen_cnt_2 - result[index].sen_cnt_1);
            }
        }
        result = CMD_RESULT_SUCCESS;
    }
#endif

#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    uint8_t result;

    touch_err_t touch_err;
    touch_read_t read_arg =
    {
        .read_cmd = TOUCH_DATA_FILTERED_COUNT,
        .sensor = &g_sensors[g_access_method][channel],
        .sensor_count = 1,
        .p_dest = value,
        .size = sizeof(uint16_t),
    };

    *value = 0xffff;
    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (0xff != g_key_info[g_access_method].sensor_index[channel])
        {
            touch_err = R_TOUCH_Read(touch_handle_id[g_access_method], &read_arg);
            if (TOUCH_SUCCESS == touch_err)
            {
                result = CMD_RESULT_SUCCESS;
            }
        }
        result = CMD_RESULT_SUCCESS;
    }
#endif
    return result;
}

/***********************************************************************************************************************
* Function Name: GetMeasureReferenceValue
* Description  : Getting the value of Reference value
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Reference value
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetMeasureReferenceValue(uint16_t channel, uint16_t * value)
{
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_TUNING)
    uint8_t result;
    uint8_t index;
    (void)index;
    *value = 0xffff;
    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type == 0)
        {
            index = g_key_info[g_access_method].sensor_index[channel];
            if ( index != 0xff)
            {
                ctsu_channel_data_self_t* filtered_values = (ctsu_channel_data_self_t*)all_ctsu_configs[g_access_method]->p_sensor_data;
                if(filtered_values!=NULL)
                {
                    *value = filtered_values[index].ref_cnt;
                    result = CMD_RESULT_SUCCESS;
                }
            }
        }
        else
        {
            index = g_key_info[g_access_method].sensor_index[channel];
            if ( index != 0xff)
            {
                ctsu_channel_data_mutual_t* filtered_values = (ctsu_channel_data_mutual_t*)all_ctsu_configs[g_access_method]->p_sensor_data;
                if(filtered_values!=NULL)
                {
                    *value = filtered_values[index].ref_cnt_2 - filtered_values[index].ref_cnt_1;
                    result = CMD_RESULT_SUCCESS;
                }

                result = CMD_RESULT_SUCCESS;
            }
        }
    }
    result = CMD_RESULT_SUCCESS;
    ASSERT(result!=CMD_RESULT_FAILURE);
#endif

#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    uint8_t result;
    touch_err_t touch_err;
    touch_read_t read_arg =
    {
            .read_cmd = TOUCH_DATA_BASELINE_COUNT,
            .sensor = &g_sensors[g_access_method][channel],
            .sensor_count = 1,
            .p_dest = value,
            .size = sizeof(uint16_t),
    };

    *value = 0xffff;
    result = CMD_RESULT_FAILURE;

    if (channel < g_method_info[g_access_method].enable)
    {
        if (0xff != g_key_info[g_access_method].sensor_index[channel])
        {
            touch_err = R_TOUCH_Read(touch_handle_id[g_access_method], &read_arg);
            if (TOUCH_SUCCESS == touch_err)
            {
                result = CMD_RESULT_SUCCESS;
            }
        }
        result = CMD_RESULT_SUCCESS;
    }
    ASSERT(result!=CMD_RESULT_FAILURE);
#endif

    return result;
}

/***********************************************************************************************************************
* Function Name: GetMeasureReferenceCounter
* Description  : Getting the value of Reference counter
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Reference value
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetMeasureReferenceCounter(uint16_t channel, uint16_t * value)
{
    uint8_t result;
    uint8_t index;

    *value = 0xffff;
    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type == 0)
        {
            index = g_key_info[g_access_method].sensor_index[channel];
            if ( index != 0xff)
            {
                ctsu_channel_data_self_t* filtered_values = (ctsu_channel_data_self_t*)all_ctsu_configs[g_access_method]->p_sensor_data;
                if(filtered_values!=NULL)
                {
                    *value = filtered_values[index].ref_cnt;
                    result = CMD_RESULT_SUCCESS;
                }
            }
        }
        else
        {
            index = g_key_info[g_access_method].sensor_index[channel];
            if ( index != 0xff)
            {
                ctsu_channel_data_mutual_t* filtered_values = (ctsu_channel_data_mutual_t*)all_ctsu_configs[g_access_method]->p_sensor_data;
                if (NULL != filtered_values)
                {
                    *value = (uint16_t)( filtered_values[index].ref_cnt_2 - filtered_values[index].ref_cnt_1 );
                    result = CMD_RESULT_SUCCESS;
                }

                result = CMD_RESULT_SUCCESS;
            }
        }
        result = CMD_RESULT_SUCCESS;
    }

    return result;
}

/***********************************************************************************************************************
* Function Name: GetMeasureSliderPosition
* Description  : Getting the value of Slider position
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Slider position
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetMeasureSliderPosition(uint16_t channel, uint16_t * value)
{
    uint8_t result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    result = CMD_RESULT_FAILURE;
#ifdef  SLIDER_USE
    if (SLIDER_NUMBER > channel)
    {

    }
#endif  // SLIDER_USE
    /* XXX Slider position not provided by this layer */
    result = CMD_RESULT_SUCCESS;
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetMeasureWheelPosition
* Description  : Getting the value of Wheel position
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Wheel position
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetMeasureWheelPosition(uint16_t channel, uint16_t * value)
{
    uint8_t result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    result = CMD_RESULT_FAILURE;
#ifdef  WHEEL_USE
    if (WHEEL_NUMBER > channel)
    {

    }
#endif  // WHEEL_USE
    /* XXX Wheel position not provided by this layer. */
    result = CMD_RESULT_SUCCESS;
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetMeasureTouchResult
* Description  : Getting the value of result of touch judgement
* Arguments    : uint16_t channel   : Touch result ID
*              : uint16_t * value   : Value of result of touch judgement
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetMeasureTouchResult(uint16_t channel, uint16_t * value)
{
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_TUNING)
    uint8_t result;
    uint8_t ch_num, index;
    (void) index;           //Compiler warning disable
    (void) ch_num;          //Compiler warning disable
    *value = 0;
    result = CMD_RESULT_SUCCESS;
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
#endif

#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    uint8_t result;
    uint8_t index;
    uint32_t itr = 0;
    uint32_t sensor_count = 0;

    uint64_t binary_read = 0;
    typedef union {
        struct
        {
            uint8_t uint8[sizeof(uint64_t)];
        };
        struct
        {
            uint16_t uint16[sizeof(uint64_t)/sizeof(uint16_t)];
        };
        uint64_t uint64;
    }result_t ;
    result_t binary_out;
    result_t binary_result;
    binary_out.uint64 = 0;
    binary_result.uint64 = 0;

    ctsu_control_arg_t ctsu_ctrl_arg;
    ctsu_ctrl_arg.cmd = CTSU_CMD_GET_SENSOR_COUNT;
    ctsu_ctrl_arg.p_context = &sensor_count;

    R_CTSU_Control( ctsu_handle_id[g_access_method], &ctsu_ctrl_arg);

    for(itr = 0; itr < (sensor_count + (sensor_count & 0x7)); itr+=8)
    {
        binary_read = all_touch_configs[g_access_method]->p_binary_result[itr >> 3];
        binary_result.uint64 |= (binary_read << itr);
    }
    if(g_method_info[g_access_method].type==METHOD_TYPE_SLFCP)
    {
        for(itr = 0; (itr < SELFCAP_SENSOR_MAX); itr++)
        {
            index = g_key_info[g_access_method].sensor_index[itr];
            if( ((uint64_t)1U<<index) == (((uint64_t)1U<<index) & binary_result.uint64)  )
            {   /* */
                binary_out.uint64 |= ((uint64_t)1U << itr);
            }
        }

        binary_result.uint64 = binary_out.uint64;
    }

    *value = 0;
    if (g_key_info[g_access_method].key_num > 0)
    {
        if (g_key_info[g_access_method].key_max_group > channel)
        {
            *value = binary_result.uint16[channel];
        }
    }
    result = CMD_RESULT_SUCCESS;
    return result;
#endif
}

/***********************************************************************************************************************
* Function Name: GetMeasurePrimarySensorCounter
* Description  : Getting the value of Primary sensor counter
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Primary sensor counter
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetMeasurePrimarySensorCounter(uint16_t channel, uint16_t * value)
{
    uint8_t result;

    *value = 0xffff;
    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type != 0)
        {
            ctsu_channel_data_mutual_t* filtered_values = (ctsu_channel_data_mutual_t*)all_ctsu_configs[g_access_method]->p_sensor_data;
            *value = filtered_values[channel].sen_cnt_1;
        }
        else
        {
            ctsu_channel_data_self_t* filtered_values = (ctsu_channel_data_self_t*)all_ctsu_configs[g_access_method]->p_sensor_data;
            *value = filtered_values[channel].sen_cnt;
        }
        result = CMD_RESULT_SUCCESS;
    }
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}


/***********************************************************************************************************************
* Function Name: GetMeasureSecondarySensorCounter
* Description  : Getting the value of Primary sensor counter
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Primary sensor counter
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetMeasureSecondarySensorCounter(uint16_t channel, uint16_t * value)
{
    uint8_t result;

    *value = 0xffff;
    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type != 0)
        {
            ctsu_channel_data_mutual_t* filtered_values = (ctsu_channel_data_mutual_t*)all_ctsu_configs[g_access_method]->p_sensor_data;
            *value = filtered_values[channel].sen_cnt_2;
        }
        result = CMD_RESULT_SUCCESS;
    }
    return result;
}


/***********************************************************************************************************************
* Function Name: GetMeasurePrimaryReferenceCounter
* Description  : Getting the value of Primary reference counter
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Primary reference counter
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetMeasurePrimaryReferenceCounter(uint16_t channel, uint16_t * value)
{
    uint8_t result;

    *value = 0xffff;
    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type != 0)
        {
            ctsu_channel_data_mutual_t* filtered_values = (ctsu_channel_data_mutual_t*)all_ctsu_configs[g_access_method]->p_sensor_data;
            *value = filtered_values[channel].ref_cnt_1;
        }
        else
        {
            ctsu_channel_data_self_t* filtered_values = (ctsu_channel_data_self_t*)all_ctsu_configs[g_access_method]->p_sensor_data;
            *value = filtered_values[channel].ref_cnt;
        }
        result = CMD_RESULT_SUCCESS;
    }
    return result;
}

/***********************************************************************************************************************
* Function Name: GetMeasureSecondaryReferenceCounter
* Description  : Getting the value of Secondary reference counter
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Primary reference counter
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetMeasureSecondaryReferenceCounter(uint16_t channel, uint16_t * value)
{
    uint8_t result;

    *value = 0xffff;
    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type != 0)
        {
            ctsu_channel_data_mutual_t* filtered_values = (ctsu_channel_data_mutual_t*)all_ctsu_configs[g_access_method]->p_sensor_data;
            *value = filtered_values[channel].ref_cnt_2;
        }
        result = CMD_RESULT_SUCCESS;
    }
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterTouchFuncMode
* Description  : Getting the value of Touch sensor function mode flags
* Arguments    : uint16_t * value    : Value of Touch function mode flags
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterTouchFuncMode(uint16_t * value)
{
    uint8_t result = CMD_RESULT_FAILURE;
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    *value = (uint16_t)(((g_touch_function[g_access_method].flag.drift & 0x01) << 0) +
                        ((g_touch_function[g_access_method].flag.msa   & 0x01) << 1) +
                        ((g_touch_function[g_access_method].flag.acd0  & 0x01) << 2) +
                        ((g_touch_function[g_access_method].flag.acd1  & 0x01) << 3) +
                        ((g_touch_function[g_access_method].flag.mtc & 0x01) << 4));
    result = CMD_RESULT_SUCCESS;
    ASSERT(result!=CMD_RESULT_FAILURE);
#endif

    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: SetParameterTouchFuncMode
* Description  : Set the value to Touch sensor function mode flags
* Arguments    : uint16_t value      : Value to set Touch sensor function mode flags
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetParameterTouchFuncMode(uint16_t value)
{
    /* Drift correction      */
    uint8_t result = CMD_RESULT_FAILURE;
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    g_touch_function[g_access_method].flag.drift = (uint8_t)((value >> 0) & 0x01); /* Drift correction      */
    g_touch_function[g_access_method].flag.msa   = (uint8_t)((value >> 1) & 0x01); /* - */
    g_touch_function[g_access_method].flag.acd0  = (uint8_t)((value >> 2) & 0x01); /* - */
    g_touch_function[g_access_method].flag.acd1  = (uint8_t)((value >> 3) & 0x01); /* - */
    g_touch_function[g_access_method].flag.mtc = (uint8_t)((value >> 4) & 0x01); /* - */
    result = CMD_RESULT_SUCCESS;
#endif
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterDriftInterval
* Description  : Getting the value of Drift correction interval
* Arguments    : uint16_t * value   : Value of Drift correction interval
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterDriftInterval(uint16_t * value)
{
    uint8_t result = CMD_RESULT_FAILURE;
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    *value = g_touch_paramter[g_access_method].drift_freq = all_touch_configs[g_access_method]->p_sensor[0].drift_rate;
    result = CMD_RESULT_SUCCESS;
#endif
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: SetParameterDriftInterval
* Description  : Set the value to Drift correction interval
* Arguments    : uint16_t value      : Value to set Drift correction interval
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetParameterDriftInterval(uint16_t value)
{
    uint8_t result = CMD_RESULT_FAILURE;
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    uint16_t sensor_count = 0;
    ctsu_err_t ctsu_err;
    SSP_PARAMETER_NOT_USED(ctsu_err);
    uint16_t itr = 0;

    g_touch_paramter[g_access_method].drift_freq = value;

    ctsu_control_arg_t control_args =
    {
            .cmd = CTSU_CMD_GET_SENSOR_COUNT,
            .p_context = &sensor_count,
    };

    ctsu_err = R_CTSU_Control(ctsu_handle_id[g_access_method], &control_args);
    ASSERT(CTSU_SUCCESS==ctsu_err);
    for(itr = 0; itr < sensor_count; itr++)
    {
        memcpy((void*)&all_touch_configs[g_access_method]->p_sensor[itr].drift_rate, &value, sizeof(uint16_t));
    }

    result = CMD_RESULT_SUCCESS;
#endif
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterMsa
* Description  : Getting the value of MSA
* Arguments    : uint16_t * value   : Value of MSA
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterMsa(uint16_t * value)
{
    uint8_t result = CMD_RESULT_FAILURE;
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    *value = g_touch_paramter[g_access_method].msa_freq = all_touch_configs[g_access_method]->p_common->on_limit;
    result = CMD_RESULT_SUCCESS;
#endif
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: SetParameterMsa
* Description  : Set the value to MSA
* Arguments    : uint16_t value      : Value to set MSA
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetParameterMsa(uint16_t value)
{
    uint8_t result = CMD_RESULT_FAILURE;
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    memcpy((void*)&all_touch_configs[g_access_method]->p_common->on_limit, &value, sizeof(uint16_t));
    g_touch_paramter[g_access_method].msa_freq = value;
    result = CMD_RESULT_SUCCESS;
#endif
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParaAcdToTouch
* Description  : Getting the value of ACD to touch
* Arguments    : uint16_t * value    : Value of ACD to touch
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterAcdToTouch(uint16_t * value)
{
    uint8_t result = CMD_RESULT_FAILURE;
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    *value = g_touch_paramter[g_access_method].touch_freq = all_touch_configs[g_access_method]->p_sensor[0].dt_limit;
    result = CMD_RESULT_SUCCESS;
#endif
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: SetParaAcdToTouch
* Description  : Set the value to ACD to Touch
* Arguments    : uint16_t value      : Value to set ACD to Touch
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetParameterAcdToTouch(uint16_t value)
{
    uint8_t result = CMD_RESULT_FAILURE;
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    uint16_t sensor_count = 0;
    ctsu_err_t ctsu_err;
    SSP_PARAMETER_NOT_USED(ctsu_err);
    uint16_t itr = 0;

    g_touch_paramter[g_access_method].touch_freq = (uint8_t)value;

    ctsu_control_arg_t control_args =
    {
            .cmd = CTSU_CMD_GET_SENSOR_COUNT,
            .p_context = &sensor_count,
    };

    ctsu_err = R_CTSU_Control(ctsu_handle_id[g_access_method], &control_args);
    ASSERT(CTSU_SUCCESS==ctsu_err);
    for(itr = 0; itr < sensor_count; itr++)
    {
        memcpy((void*)&all_touch_configs[g_access_method]->p_sensor[itr].dt_limit, &value, sizeof(uint16_t));
    }

    result = CMD_RESULT_SUCCESS;
#endif
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterAcdToNoTouch
* Description  : Getting the value of ACD to No touch
* Arguments    : uint16_t * value    : Value of ACD to No touch
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterAcdToNoTouch(uint16_t * value)
{
    uint8_t result = CMD_RESULT_FAILURE;
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    *value = g_touch_paramter[g_access_method].not_touch_freq = all_touch_configs[g_access_method]->p_sensor[0].dr_limit;
    result = CMD_RESULT_SUCCESS;
#endif
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: SetParameterAcdToNoTouch
* Description  : Set the value to ACD to No touch
* Arguments    : uint16_t value    : Value to set ACD to No touch
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetParameterAcdToNoTouch(uint16_t value)
{
    uint8_t result = CMD_RESULT_FAILURE;
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
    uint16_t sensor_count = 0;
    ctsu_err_t ctsu_err;
    SSP_PARAMETER_NOT_USED(ctsu_err);
    uint16_t itr = 0;

    g_touch_paramter[g_access_method].not_touch_freq = (uint8_t)value;

    ctsu_control_arg_t control_args =
    {
            .cmd = CTSU_CMD_GET_SENSOR_COUNT,
            .p_context = &sensor_count,
    };

    ctsu_err = R_CTSU_Control(ctsu_handle_id[g_access_method], &control_args);
    ASSERT(CTSU_SUCCESS==ctsu_err);
    for(itr = 0; itr < sensor_count; itr++)
    {
        memcpy((void*)&all_touch_configs[g_access_method]->p_sensor[itr].dr_limit, &value, sizeof(uint16_t));
    }

    result = CMD_RESULT_SUCCESS;
#endif
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterThreshold
* Description  : Getting the value of threshold
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterThreshold(uint16_t channel, uint16_t * value)
{
    uint8_t result;
    uint8_t index;
    (void) index;           //Compiler warning disable
    *value = 0xffff;
    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
        index = g_key_info[g_access_method].sensor_index[channel];
        if (0xff != index)
        {
            *value = all_touch_configs[g_access_method]->p_sensor[index].threshold;
        }
        result = CMD_RESULT_SUCCESS;
#endif
    }
    result = CMD_RESULT_SUCCESS;
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: SetParameterThreshold
* Description  : Set the value to threshold
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetParameterThreshold(uint16_t channel, uint16_t value)
{
    uint8_t result;
    uint8_t index;
    (void) index;           //Compiler warning disable
    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
        index = g_key_info[g_access_method].sensor_index[channel];
        if (0xff != index)
        {
            memcpy((void*)&all_touch_configs[g_access_method]->p_sensor[index].threshold, &value, sizeof(uint16_t));
        }
        result = CMD_RESULT_SUCCESS;
#endif
    }
    result = CMD_RESULT_SUCCESS;
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterHysteresis
* Description  : Getting the value of hysteresis
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterHysteresis(uint16_t channel, uint16_t * value)
{
    uint8_t result;
    *value = 0;
    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
        uint8_t index = g_key_info[g_access_method].sensor_index[channel];
        if (0xff != index)
        {
            *value = all_touch_configs[g_access_method]->p_sensor[index].hysteresis;
        }
        result = CMD_RESULT_SUCCESS;
#endif
    }
    result = CMD_RESULT_SUCCESS;
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: SetParameterHysteresis
* Description  : Set the value to hysteresis
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetParameterHysteresis(uint16_t channel, uint16_t value)
{
    uint8_t result;
    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_MONITOR)
        uint8_t index = g_key_info[g_access_method].sensor_index[channel];
        if (0xff != index)
        {
            memcpy((void*)&all_touch_configs[g_access_method]->p_sensor[index].hysteresis, &value, sizeof(uint16_t));
        }
        result = CMD_RESULT_SUCCESS;
#endif
    }
    result = CMD_RESULT_SUCCESS;
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterSliderNumber
* Description  : Getting the value of number of slider
* Arguments    : uint16_t * value    : Value of number of slider
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterSliderNumber(uint16_t * value)
{
    *value = 0;
    if (g_method_info[g_access_method].type == 0)
    {
        *value = SLIDER_NUMBER;
    }
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: GetParameterSliderSensor
* Description  : Gets the touch sensor channel number of the specified slider
* Arguments    : uint16_t channel   : Slider ID
*              : uint16_t * no      : Slider sensor number
*              : uint16_t * value   : Value of Slider sensor numebr
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t    GetParameterSliderSensor(uint8_t channel, uint8_t no, uint16_t * value)
{
    uint8_t    result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    SSP_PARAMETER_NOT_USED(no);
    result    = CMD_RESULT_FAILURE;
#ifdef    SLIDER_USE
    if (SLIDER_NUMBER > channel)
    {
        result = CMD_RESULT_SUCCESS;
        *value = g_sliderInfo[channel].ts[no];
    }
#endif  // SLIDER_USE
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterSliderSensorNumber
* Description  : Getting the value of number of slider touch sensor
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterSliderSensorNumber(uint16_t channel, uint16_t * value)
{
    uint8_t result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    result = CMD_RESULT_FAILURE;
#ifdef SLIDER_USE
    if (SLIDER_NUMBER > channel)
    {
        *value  = g_sliderInfo[channel].num;
        result  = CMD_RESULT_SUCCESS;
    }
#endif  // SLIDER_USE
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterSliderResolution
* Description  : Getting the value of slider resolution
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterSliderResolution(uint16_t channel, uint16_t * value)
{
    uint8_t result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    result = CMD_RESULT_FAILURE;
#ifdef  SLIDER_USE
    if (SLIDER_NUMBER > channel)
    {
        *value  = g_sliderInfo[channel].resolution;
        result  = CMD_RESULT_SUCCESS;
    }
#endif  // SLIDER_USE
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: SetParameterSliderResolution
* Description  : Set the value to slider resolution
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetParameterSliderResolution(uint16_t channel, uint16_t value)
{
    uint8_t result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    result = CMD_RESULT_FAILURE;
#ifdef  SLIDER_USE
    if (SLIDER_NUMBER > channel)
    {
        g_sliderInfo[channel].resolution = value;
        result = CMD_RESULT_SUCCESS;
    }
#endif  // SLIDER_USE
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterSliderThreshold
* Description  : Getting the value of slider threshold
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterSliderThreshold(uint16_t channel, uint16_t * value)
{
    uint8_t result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    result = CMD_RESULT_FAILURE;
#ifdef  SLIDER_USE
    if (SLIDER_NUMBER > channel)
    {
        *value  = g_sliderInfo[channel].threshold;
        result  = CMD_RESULT_SUCCESS;
    }
#endif  // SLIDER_USE
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: SetParameterSliderThreshold
* Description  : Set the value to slider threshold
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetParameterSliderThreshold(uint16_t channel, uint16_t value)
{
    uint8_t result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    result = CMD_RESULT_FAILURE;
#ifdef  SLIDER_USE
    if (SLIDER_NUMBER > channel)
    {
        g_sliderInfo[channel].threshold = value;
        result = CMD_RESULT_SUCCESS;
    }
#endif  // SLIDER_USE
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterWheelNumber
* Description  : Getting the value of number of wheel
* Arguments    : uint16_t * value    : Value of number of wheel
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterWheelNumber(uint16_t * value)
{
    *value = 0;
    if (g_method_info[g_access_method].type == 0)
    {
        *value = WHEEL_NUMBER;
    }
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: GetParameterWheelSensor
* Description  : Gets the touch sensor channel number of the specified wheel
* Arguments    : uint16_t channel   : Wheel ID
*              : uint16_t * no      : Wheel sensor number
*              : uint16_t * value   : Value of Wheel sensor numebr
* Return Value : Touch sensor number
***********************************************************************************************************************/
static uint8_t    GetParameterWheelSensor(uint8_t channel, uint8_t no, uint16_t * value)
{
    uint8_t    result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    SSP_PARAMETER_NOT_USED(no);
    result    = CMD_RESULT_FAILURE;
#ifdef    WHEEL_USE
    if (WHEEL_NUMBER > channel)
    {
        result = CMD_RESULT_SUCCESS;
        *value = g_wheelInfo[channel].ts[no];
    }
#endif    // WHEEL_USE
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterWheelSensorNumber
* Description  : Getting the value of number of wheel touch sensor
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterWheelSensorNumber(uint16_t channel, uint16_t * value)
{
    uint8_t result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    result = CMD_RESULT_FAILURE;
#ifdef  WHEEL_USE
    if (WHEEL_NUMBER > channel)
    {
        *value  = g_wheelInfo[channel].num;
        result  = CMD_RESULT_SUCCESS;
    }
#endif  // WHEEL_USE
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterWheelResolution
* Description  : Getting the value of wheel resolution
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterWheelResolution(uint16_t channel, uint16_t * value)
{
    uint8_t result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    result = CMD_RESULT_FAILURE;
#ifdef  WHEEL_USE
    if (WHEEL_NUMBER > channel)
    {
        *value = g_wheelInfo[channel].resolution;
        result  = CMD_RESULT_SUCCESS;
    }
#endif  // WHEEL_USE
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: SetParameterWheelResolution
* Description  : Set the value to wheel resolution
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetParameterWheelResolution(uint16_t channel, uint16_t value)
{
    uint8_t result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    result = CMD_RESULT_FAILURE;
#ifdef  WHEEL_USE
    if (WHEEL_NUMBER > channel)
    {
        g_wheelInfo[channel].resolution = value;
        result = CMD_RESULT_SUCCESS;
    }
#endif  // WHEEL_USE
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterWheelThreshold
* Description  : Getting the value of wheel threshold
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterWheelThreshold(uint16_t channel, uint16_t * value)
{
    uint8_t result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    result = CMD_RESULT_FAILURE;
#ifdef  WHEEL_USE
    if (WHEEL_NUMBER > channel)
    {
        *value  = g_wheelInfo[channel].threshold;
        result  = CMD_RESULT_SUCCESS;
    }
#endif  // WHEEL_USE
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: SetParameterWheelThreshold
* Description  : Set the value to wheel threshold
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetParameterWheelThreshold(uint16_t channel, uint16_t value)
{
    uint8_t result;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(channel);
    result = CMD_RESULT_FAILURE;
#ifdef  WHEEL_USE
    if (WHEEL_NUMBER > channel)
    {
        g_wheelInfo[channel].threshold = value;
        result = CMD_RESULT_SUCCESS;
    }
#endif  // WHEEL_USE
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterKeyEnableControl
* Description  : Getting the value of setting of enable of touch key
* Arguments    : uint16_t channel   : Touch sensor channel number
*              : uint16_t * value   : Value of Sensor counter value (Count value)
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterKeyEnableControl(uint16_t channel, uint16_t * value)
{
    uint8_t result;

    result = CMD_RESULT_FAILURE;
    if (g_key_info[g_access_method].key_max_group > channel)
    {
        *value = g_touch_key_group[g_access_method].group[channel];
        result = CMD_RESULT_SUCCESS;
    }
    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: GetParameterTouchKeyNumber
* Description  : Getting the value of number of touch keys (Touch button, Matrix button)
* Arguments    : uint16_t * value    : Value of number of touch keys
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetParameterTouchKeyNumber(uint16_t * value)
{
    *value = g_key_info[g_access_method].ena_num;
    return CMD_RESULT_SUCCESS;
}


/***********************************************************************************************************************
* Function Name: GetRegisterCTSUCR0
* Description  : Getting the value of CTSUCR0
* Arguments    : uint16_t * value      : Value to set CTSUCR0
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUCR0(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUCR0;
    control_arg.p_context = value;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUCR0
* Description  : Set the value to CTSUCR0
* Arguments    : uint16_t value      : Value to set CTSUCR0
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUCR0(uint16_t value)
{
    ctsu_control_arg_t control_arg;
    all_ctsu_configs[g_access_method]->p_ctsu_settings->ctsucr0.byte = (uint8_t)value;
    control_arg.cmd = CTSU_CMD_SET_CTSUCR0;
    control_arg.p_context = &all_ctsu_configs[g_access_method]->p_ctsu_settings->ctsucr0.byte;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUCR1
* Description  : Getting the value of CTSUCR1
* Arguments    : uint16_t * value    : Value of CTSUCR1
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUCR1(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUCR1;
    control_arg.p_context = value;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUCR1
* Description  : Set the value to CTSUCR1
* Arguments    : uint16_t value      : Value to set CTSUCR1
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUCR1(uint16_t value)
{
    ctsu_control_arg_t control_arg;
    all_ctsu_configs[g_access_method]->p_ctsu_settings->ctsucr1.byte  = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUCR1;
    control_arg.p_context = &all_ctsu_configs[g_access_method]->p_ctsu_settings->ctsucr1.byte;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUSDPRS
* Description  : Getting the value of CTSUSDPRS
* Arguments    : uint16_t * value    : Value of CTSUSDPRS
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUSDPRS(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUSDPRS;
    control_arg.p_context = value;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUSDPRS
* Description  : Set the value to CTSUSDPRS
* Arguments    : uint16_t value      : Value to set CTSUSDPRS
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUSDPRS(uint16_t value)
{
    ctsu_control_arg_t control_arg;
    all_ctsu_configs[g_access_method]->p_ctsu_settings->ctsusdprs.byte  = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUSDPRS;
    control_arg.p_context = &all_ctsu_configs[g_access_method]->p_ctsu_settings->ctsusdprs.byte;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUSST
* Description  : Getting the value of CTSUSST
* Arguments    : uint16_t * value    : Value of CTSUSST
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUSST(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUSST;
    control_arg.p_context = value;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUSST
* Description  : Set the value to CTSUSST
* Arguments    : uint16_t value      : Value to set CTSUSST
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUSST(uint16_t value)
{
    ctsu_control_arg_t control_arg;
    all_ctsu_configs[g_access_method]->p_ctsu_settings->ctsusst.byte = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUSST;
    control_arg.p_context = &all_ctsu_configs[g_access_method]->p_ctsu_settings->ctsusst.byte;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUMCH0
* Description  : Getting the value of CTSUMCH0
* Arguments    : uint16_t * value    : Value of CTSUMCH0
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUMCH0(uint16_t * value)
{
    uint8_t result = CMD_RESULT_FAILURE;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    ASSERT(result!=CMD_RESULT_FAILURE);
    return CMD_RESULT_FAILURE;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUMCH0
* Description  : Set the value to CTSUMCH0
* Arguments    : uint16_t value    : Value to set CTSUMCH0
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUMCH0(uint16_t value)
{
    uint8_t result = CMD_RESULT_FAILURE;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    ASSERT(result!=CMD_RESULT_FAILURE);
    return CMD_RESULT_FAILURE;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUMCH1
* Description  : Getting the value of CTSUMCH1
* Arguments    : uint16_t * value    : Value of CTSUMCH1
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUMCH1(uint16_t * value)
{
    uint8_t result = CMD_RESULT_FAILURE;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    ASSERT(result!=CMD_RESULT_FAILURE);
    return CMD_RESULT_FAILURE;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUMCH1
* Description  : Set the value to CTSUMCH1
* Arguments    : uint16_t value    : Value to set CTSUMCH1
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUMCH1(uint16_t value)
{
    uint8_t result = CMD_RESULT_FAILURE;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    ASSERT(result!=CMD_RESULT_FAILURE);
    return CMD_RESULT_FAILURE;
}
typedef union ctsuchx_access{
    uint64_t bit_64;
    uint8_t bit_8[5];
}ctsuchx_t;
/***********************************************************************************************************************
* Function Name: GetRegisterCTSUCHAC0
* Description  : Getting the value of CTSUCHAC0
* Arguments    : uint16_t * value    : Value of CTSUAC0
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUCHAC0(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUCHAC;
    ctsuchx_t cmd_ret_val;
    cmd_ret_val.bit_64 = 0;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    *value = (uint16_t)(cmd_ret_val.bit_8[0]);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUCHAC0
* Description  : Set the value to CTSUCHAC0
* Arguments    : uint16_t value      : Value to set CTSUCHAC0
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUCHAC0(uint16_t value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUCHAC;
    ctsuchx_t cmd_ret_val;
    cmd_ret_val.bit_64 = 0;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    cmd_ret_val.bit_8[0] = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUCHAC;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUCHAC1
* Description  : Getting the value of CTSUCHAC1
* Arguments    : uint16_t * value    : Value of CTSUCHAC1
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUCHAC1(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUCHAC;
    ctsuchx_t cmd_ret_val;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    *value = (uint16_t)(cmd_ret_val.bit_8[1]);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUCHAC1
* Description  : Set the value to CTSUCHAC1
* Arguments    : uint16_t value      : Value to set CTSUCHAC1
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUCHAC1(uint16_t value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUCHAC;
    ctsuchx_t cmd_ret_val;
    cmd_ret_val.bit_64 = 0;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    cmd_ret_val.bit_8[1] = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUCHAC;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUCHAC2
* Description  : Getting the value of CTSUCHAC2
* Arguments    : uint16_t * value    : Value of CTSUSSC
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUCHAC2(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
#if !defined(BSP_MCU_RX113)
    control_arg.cmd = CTSU_CMD_GET_CTSUCHAC;
    ctsuchx_t cmd_ret_val;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    *value = (uint16_t)(cmd_ret_val.bit_8[2]);
#else
    *value = 0;
#endif
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUCHAC2
* Description  : Set the value to CTSUCHAC2
* Arguments    : uint16_t value      : Value to set CTSUCHAC2
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUCHAC2(uint16_t value)
{
    ctsu_control_arg_t control_arg;
#if !defined(BSP_MCU_RX113)
    control_arg.cmd = CTSU_CMD_GET_CTSUCHAC;
    ctsuchx_t cmd_ret_val;
    cmd_ret_val.bit_64 = 0;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    cmd_ret_val.bit_8[2] = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUCHAC;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
#else
    return CMD_RESULT_SUCCESS;
#endif
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUCHAC3
* Description  : Getting the value of CTSUCHAC3
* Arguments    : uint16_t * value    : Value of CTSUCHAC3
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUCHAC3(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
#if !defined(BSP_MCU_RX113)
    control_arg.cmd = CTSU_CMD_GET_CTSUCHAC;
    ctsuchx_t cmd_ret_val;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    *value = (uint16_t)(cmd_ret_val.bit_8[3]);
#else
    *value = 0;
#endif
    return CMD_RESULT_SUCCESS;;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUCHAC3
* Description  : Set the value to CTSUCHAC3
* Arguments    : uint16_t value      : Value to set CTSUCHAC3
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUCHAC3(uint16_t value)
{
    ctsu_control_arg_t control_arg;
#if !defined(BSP_MCU_RX113)
    control_arg.cmd = CTSU_CMD_GET_CTSUCHAC;
    ctsuchx_t cmd_ret_val;
    cmd_ret_val.bit_64 = 0;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    cmd_ret_val.bit_8[3] = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUCHAC;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
#else
    return CMD_RESULT_SUCCESS;;
#endif
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUCHAC4
* Description  : Getting the value of CTSUCHAC4
* Arguments    : uint16_t * value    : Value of CTSUCHAC4
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUCHAC4(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
#if !defined(BSP_MCU_RX113)
    control_arg.cmd = CTSU_CMD_GET_CTSUCHAC;
    ctsuchx_t cmd_ret_val;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    *value = (uint16_t)(cmd_ret_val.bit_8[4]);
#else
    *value = 0;
#endif
    return CMD_RESULT_SUCCESS;;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUCHAC4
* Description  : Set the value to CTSUCHAC4
* Arguments    : uint16_t value    : Value to set CTSUCHAC4
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUCHAC4(uint16_t value)
{
    ctsu_control_arg_t control_arg;
#if !defined(BSP_MCU_RX113)
    control_arg.cmd = CTSU_CMD_GET_CTSUCHAC;
    ctsuchx_t cmd_ret_val;
    cmd_ret_val.bit_64 = 0;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    cmd_ret_val.bit_8[4] = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUCHAC;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
#else
#endif
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUCHTRC0
* Description  : Getting the value of CTSUCHTRC0
* Arguments    : uint16_t * value    : Value of CTSUCHTRC0
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUCHTRC0(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUCHTRC;
    ctsuchx_t cmd_ret_val;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    *value = (uint16_t)(cmd_ret_val.bit_8[0]);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUCHTRC0
* Description  : Set the value to CTSUCHTRC0
* Arguments    : uint16_t value      : Value to set CTSUCHTRC0
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUCHTRC0(uint16_t value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUCHTRC;
    ctsuchx_t cmd_ret_val;
    cmd_ret_val.bit_64 = 0;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    cmd_ret_val.bit_8[0] = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUCHTRC;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUCHTRC1
* Description  : Getting the value of CTSUCHTRC1
* Arguments    : uint16_t * value    : Value of CTSUCHTRC1
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUCHTRC1(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUCHTRC;
    ctsuchx_t cmd_ret_val;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    *value = (uint16_t)(cmd_ret_val.bit_8[1]);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUCHTRC1
* Description  : Set the value to CTSUCHTRC1
* Arguments    : uint16_t value      : Value to set CTSUCHTRC1
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUCHTRC1(uint16_t value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUCHTRC;
    ctsuchx_t cmd_ret_val;
    cmd_ret_val.bit_64 = 0;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    cmd_ret_val.bit_8[1] = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUCHTRC;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUCHTRC2
* Description  : Getting the value of CTSUCHTRC2
* Arguments    : uint16_t * value    : Value of CTSUCHTRC2
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUCHTRC2(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
#if !defined(BSP_MCU_RX113)
    control_arg.cmd = CTSU_CMD_GET_CTSUCHTRC;
    ctsuchx_t cmd_ret_val;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    *value = (uint16_t)(cmd_ret_val.bit_8[2]);
#else
    *value = 0;
#endif
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUCHTRC2
* Description  : Set the value to CTSUCHTRC2
* Arguments    : uint16_t value      : Value to set CTSUCHTRC2
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUCHTRC2(uint16_t value)
{
    ctsu_control_arg_t control_arg;
#if !defined(BSP_MCU_RX113)
    control_arg.cmd = CTSU_CMD_GET_CTSUCHTRC;
    ctsuchx_t cmd_ret_val;
    cmd_ret_val.bit_64 = 0;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    cmd_ret_val.bit_8[2] = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUCHTRC;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
#else
#endif
    return CMD_RESULT_SUCCESS;;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUCHTRC3
* Description  : Getting the value of CTSUCHTRC3
* Arguments    : uint16_t * value    : Value of CTSUCHTRC3
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUCHTRC3(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
#if !defined(BSP_MCU_RX113)
    control_arg.cmd = CTSU_CMD_GET_CTSUCHTRC;
    ctsuchx_t cmd_ret_val;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    *value = (uint16_t)(cmd_ret_val.bit_8[3]);
#else
    *value = 0;
#endif
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUCHTRC3
* Description  : Set the value to CTSUCHTRC3
* Arguments    : uint16_t value      : Value to set CTSUCHTRC3
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUCHTRC3(uint16_t value)
{
    ctsu_control_arg_t control_arg;
#if !defined(BSP_MCU_RX113)
    control_arg.cmd = CTSU_CMD_GET_CTSUCHTRC;
    ctsuchx_t cmd_ret_val;
    cmd_ret_val.bit_64 = 0;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    cmd_ret_val.bit_8[3] = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUCHTRC;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
#else
#endif
    return CMD_RESULT_SUCCESS;;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUCHTRC4
* Description  : Getting the value of CTSUCHTRC4
* Arguments    : uint16_t * value    : Value of CTSUCHTRC4
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUCHTRC4(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
#if !defined(BSP_MCU_RX113)
    control_arg.cmd = CTSU_CMD_GET_CTSUCHTRC;
    ctsuchx_t cmd_ret_val;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    *value = (uint16_t)(cmd_ret_val.bit_8[4]);
#else
    *value = 0;
#endif
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUCHTRC4
* Description  : Set the value to CTSUCHTRC4
* Arguments    : uint16_t value      : Value to set CTSUCHTRC4
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUCHTRC4(uint16_t value)
{
    ctsu_control_arg_t control_arg;
#if !defined(BSP_MCU_RX113)
    control_arg.cmd = CTSU_CMD_GET_CTSUCHTRC;
    ctsuchx_t cmd_ret_val;
    cmd_ret_val.bit_64 = 0;
    control_arg.p_context = &cmd_ret_val;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    cmd_ret_val.bit_8[4] = (uint8_t)(value & 0xFF);
    control_arg.cmd = CTSU_CMD_SET_CTSUCHTRC;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
#else
    return CMD_RESULT_SUCCESS;;
#endif
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUDCLKC
* Description  : Getting the value of CTSUDCLKC
* Arguments    : uint16_t * value    : Value of CTSUDCLKC
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUDCLKC(uint16_t * value)
{
    ctsu_control_arg_t control_arg;
    control_arg.cmd = CTSU_CMD_GET_CTSUDCLKC;
    control_arg.p_context = value;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUDCLKC
* Description  : Set the value to CTSUDCLKC
* Arguments    : uint16_t value    : Value to set CTSUDCLKC
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUDCLKC(uint16_t value)
{
    ctsu_control_arg_t control_arg;
    all_ctsu_configs[g_access_method]->p_ctsu_settings->ctsudclkc.byte = (uint8_t)(value & 0xff);
    control_arg.cmd = CTSU_CMD_SET_CTSUDCLKC;
    control_arg.p_context = &all_ctsu_configs[g_access_method]->p_ctsu_settings->ctsudclkc.byte;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUST
* Description  : Getting the value of CTSUST
* Arguments    : uint16_t * value    : Value of CTSUSSC
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUST(uint16_t * value)
{
#if 0
    *value = (uint16_t)((g_ctsu_status[g_access_method].flag.sens_over << 5) +
                        (g_ctsu_status[g_access_method].flag.ref_over  << 6));
#else
    ctsu_control_arg_t control_info;
    uint32_t scan_errors;
    control_info.cmd = CTSU_CMD_GET_ERROR_INFORMATION;
    control_info.p_context = &scan_errors;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_info);
    scan_errors &= (CTSU_ERR_CTSU_SC_OVF|CTSU_ERR_CTSU_RC_OVF);
    *value = (uint16_t)(scan_errors<<1);
#endif
    return CMD_RESULT_SUCCESS;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUST
* Description  : Set the value to CTSUST
* Arguments    : uint16_t value    : Value to set CTSUST
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUST(uint16_t value)
{
    uint8_t result = CMD_RESULT_FAILURE;
    SSP_PARAMETER_NOT_USED(result);
    SSP_PARAMETER_NOT_USED(value);
    ASSERT(result!=CMD_RESULT_FAILURE);
    return CMD_RESULT_FAILURE;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUSSC
* Description  : Getting the value of CTSUSSC
* Arguments    : uint16_t channel    : Touch sensor channel number
*              : uint16_t * value     : Value of CTSUSSC
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUSSC(uint16_t channel, uint16_t * value)
{
    uint8_t result;

    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type == 0)
        {   /* Touch sensor measurement method : Self capacitance */
            uint8_t index = g_key_info[g_access_method].sensor_index[channel];
            if (index != 0xff)
            {
                ctsu_sensor_setting_t* ch_setting = all_ctsu_configs[g_access_method]->p_sensor_settings;
                *value = ch_setting[index].ctsussc;
                result = CMD_RESULT_SUCCESS;
            }
        }
        else
        {   /* Touch sensor measurement method : Mutual capacitance */
            uint8_t index = g_key_info[g_access_method].sensor_index[channel];
            if (index != 0xff)
            {
                ctsu_sensor_setting_t* ch_setting = all_ctsu_configs[g_access_method]->p_sensor_settings;
                *value = ch_setting[index].ctsussc;
                result = CMD_RESULT_SUCCESS;
            }
        }
    }
    return result;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUSSC
* Description  : Set the value to CTSUSSC
* Arguments    : uint16_t channel  : Touch sensor channel number
*              : uint16_t value    : Value to set CTSUSSC
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUSSC(uint16_t channel, uint16_t value)
{
    uint8_t result;

    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type == 0)
        {   /* Touch sensor measurement method : Self capacitance */
            uint8_t index = g_key_info[g_access_method].sensor_index[channel];
            if (index != 0xff)
            {
                ctsu_sensor_setting_t* ch_setting = all_ctsu_configs[g_access_method]->p_sensor_settings;
                ch_setting[index].ctsussc = value;
                result = CMD_RESULT_SUCCESS;
            }
        }
        else
        {   /* Touch sensor measurement method : Mutual capacitance */
            uint8_t index = g_key_info[g_access_method].sensor_index[channel];
            if (index != 0xff)
            {
                ctsu_sensor_setting_t* ch_setting = all_ctsu_configs[g_access_method]->p_sensor_settings;
                ch_setting[index].ctsussc = value;
                result = CMD_RESULT_SUCCESS;
            }
        }
    }
    return result;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUSO0
* Description  : Getting the value of CTSUSO0
* Arguments    : uint16_t channel    : Touch sensor channel number
*              : uint16_t value      : Value of CTSUSO0
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUSO0(uint16_t channel, uint16_t * value)
{
    uint8_t result;

    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type == 0)
        {   /* Touch sensor measurement method : Self capacitance */
            uint8_t index = g_key_info[g_access_method].sensor_index[channel];
            if (index != 0xff)
            {
                ctsu_sensor_setting_t* ch_setting = all_ctsu_configs[g_access_method]->p_sensor_settings;
                *value = ch_setting[index].ctsuso0;
                result = CMD_RESULT_SUCCESS;
            }
        }
        else
        {   /* Touch sensor measurement method : Mutual capacitance */
            uint8_t index = g_key_info[g_access_method].sensor_index[channel];
            if (index != 0xff)
            {
                ctsu_sensor_setting_t* ch_setting = all_ctsu_configs[g_access_method]->p_sensor_settings;
                *value = ch_setting[index].ctsuso0;
                result = CMD_RESULT_SUCCESS;
            }
        }
    }
    return result;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUSO0
* Description  : Set the value to CTSUSO0
* Arguments    : uint16_t channel    : Touch sensor channel number
*              : uint16_t value      : Value to set CTSUSO0
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUSO0(uint16_t channel, uint16_t value)
{
    uint8_t result;

    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type == 0)
        {   /* Touch sensor measurement method : Self capacitance */
            uint8_t index = g_key_info[g_access_method].sensor_index[channel];
            if (index != 0xff)
            {
                ctsu_sensor_setting_t* ch_setting = all_ctsu_configs[g_access_method]->p_sensor_settings;
                ch_setting[index].ctsuso0 = value;
                result = CMD_RESULT_SUCCESS;
            }
        }
        else
        {   /* Touch sensor measurement method : Mutual capacitance */
            uint8_t index = g_key_info[g_access_method].sensor_index[channel];
            if (index != 0xff)
            {
                ctsu_sensor_setting_t* ch_setting = all_ctsu_configs[g_access_method]->p_sensor_settings;
                ch_setting[index].ctsuso0 = value;
                result = CMD_RESULT_SUCCESS;
            }
        }
    }
    return result;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUSO1
* Description  : Getting the value of CTSUSO1
* Arguments    : uint16_t channel    : Touch sensor channel number
*              : uint16_t value      : Value to set CTSUERRS
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUSO1(uint16_t channel, uint16_t * value)
{
    uint8_t result;

    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type == 0)
        {   /* Touch sensor measurement method : Self capacitance */
            uint8_t index = g_key_info[g_access_method].sensor_index[channel];
            if (index != 0xff)
            {
                ctsu_sensor_setting_t* ch_setting = all_ctsu_configs[g_access_method]->p_sensor_settings;
                *value = ch_setting[index].ctsuso1;
                result = CMD_RESULT_SUCCESS;
            }
        }
        else
        {   /* Touch sensor measurement method : Mutual capacitance */
            uint8_t index = g_key_info[g_access_method].sensor_index[channel];
            if (index != 0xff)
            {
                ctsu_sensor_setting_t* ch_setting = all_ctsu_configs[g_access_method]->p_sensor_settings;
                *value = ch_setting[index].ctsuso1;
                result = CMD_RESULT_SUCCESS;
            }
        }
    }
    return result;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUSO1
* Description  : Set the value to CTSUSO1
* Arguments    : uint16_t channel  : Touch sensor channel number
*              : uint16_t value    : Value to set CTSUSO1
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUSO1(uint16_t channel, uint16_t value)
{
    uint8_t result;

    result = CMD_RESULT_FAILURE;
    if (channel < g_method_info[g_access_method].enable)
    {
        if (g_method_info[g_access_method].type == 0)
        {   /* Touch sensor measurement method : Self capacitance */
            uint8_t index = g_key_info[g_access_method].sensor_index[channel];
            if (index != 0xff)
            {
                ctsu_sensor_setting_t* ch_setting = all_ctsu_configs[g_access_method]->p_sensor_settings;
                ch_setting[index].ctsuso1 = value;
                result = CMD_RESULT_SUCCESS;
            }
        }
        else
        {   /* Touch sensor measurement method : Mutual capacitance */
            uint8_t index = g_key_info[g_access_method].sensor_index[channel];
            if (index != 0xff)
            {
                ctsu_sensor_setting_t* ch_setting = all_ctsu_configs[g_access_method]->p_sensor_settings;
                ch_setting[index].ctsuso1 = value;
                result = CMD_RESULT_SUCCESS;
            }
        }
    }
    return result;
}

/***********************************************************************************************************************
* Function Name: GetRegisterCTSUERRS
* Description  : Getting the value of CTSUERRS
* Arguments    : uint16_t * value    : Value to set CTSUERRS
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetRegisterCTSUERRS(uint16_t * value)
{
    uint8_t result = CMD_RESULT_FAILURE;

    ctsu_control_arg_t control_info;
    uint32_t scan_errors;
    control_info.cmd = CTSU_CMD_GET_ERROR_INFORMATION;
    control_info.p_context = &scan_errors;
    R_CTSU_Control(ctsu_handle_id[g_access_method], &control_info);
    scan_errors &= (CTSU_ERR_CTSU_ICOMP);
    *value = (uint16_t)(scan_errors<<9);
    result = CMD_RESULT_SUCCESS;

    ASSERT(result!=CMD_RESULT_FAILURE);
    return result;
}

/***********************************************************************************************************************
* Function Name: SetRegisterCTSUERRS
* Description  : Set the value to CTSUERRS
* Arguments    : uint16_t value    : Value to set CTSUERRS
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t SetRegisterCTSUERRS(uint16_t value)
{
    uint8_t result = CMD_RESULT_FAILURE;
    SSP_PARAMETER_NOT_USED(value);
    SSP_PARAMETER_NOT_USED(result);
    ASSERT(result!=CMD_RESULT_FAILURE);
    return CMD_RESULT_FAILURE;
}

/***********************************************************************************************************************
* Function Name: GetUtilityExecuteBatch
* Description  : Get the value of batch command execution
* Arguments    : uint16_t * value    : Value to set the value of the
* Return Value : CMD_RESULT_SUCCESS : success
*              : CMD_RESULT_FAILURE : failure
***********************************************************************************************************************/
static uint8_t GetUtilityExecuteBatch(uint8_t * pvalue, uint16_t * length)
{
    uint8_t     i;
    uint16_t    index;
    uint8_t     startMethod;
    uint8_t     stopMethod;
    uint8_t     sensor;
    uint8_t     endSensor;
    uint8_t     cmd;
    uint8_t     method;
    uint16_t    value;
    uint8_t     status;

    index = 0;
    status    = CMD_RESULT_SUCCESS;
    for (i = 0; (i < monitor_command.size) && (status != CMD_RESULT_FAILURE); )
    {
        cmd         = monitor_command.command[i++];
        startMethod = monitor_command.command[i++];
        stopMethod  = monitor_command.command[i++];

        for (method = startMethod; (method < stopMethod) && (status != CMD_RESULT_FAILURE); method++) {
            if (cmd == 0x06/* RSLT0 */        ||
                cmd == 0x07/* RSLT1 */        ||
                cmd == 0x08/* RSLT2 */        ||
                cmd == 0x09/* RSLT3 */)
            {
                endSensor = 1;
            }
            else
            {
                endSensor     = g_method_info[method].enable;
            }
            g_access_method = method;
            if (cmd != 0x04/* SLDPOS */ && cmd != 0x05/* WHLPOS */)
            {           
                for (sensor = 0; (sensor < endSensor) && (status != CMD_RESULT_FAILURE); sensor++)
                {
                    if (GetSensorValue(cmd, sensor, &value) != CMD_RESULT_FAILURE)
                    {
                        pvalue[index++] = (uint8_t)(value & 0xff);
                        pvalue[index++] = (uint8_t)(value >> 8);
                    }
                    else
                    {
                        status    = CMD_RESULT_FAILURE;
                    }
                }
            }
            else
            {
                if (GetSensorValue(cmd, method, &value) != CMD_RESULT_FAILURE)
                {
                    pvalue[index++] = (uint8_t)(value & 0xff);
                    pvalue[index++] = (uint8_t)(value >> 8);
                }
            }
        }
    }
    // Set buffer size to output parameter
    *length = index;
    return status;
}

/***********************************************************************************************************************
* Function Name: CreateResponceCommand
* Description  : Create responce command
* Arguments    : pcmd -
*                    Pointer of command
* Return Value : none
***********************************************************************************************************************/
static void CreateResponceCommand(com_data_tx_t *pcmd)
{
    pcmd->fmt.main = (uint8_t)(com_data.fmt.main | CMD_RE);
    pcmd->fmt.sub  = com_data.fmt.sub;

    switch (com_data.fmt.main)
    {
        case CMD_RQ_PROFILE_READ:
            SensorProfileReadResponse(pcmd, com_data.fmt.data[0]);
            break;
        case CMD_RQ_PROFILE_WRITE:
            break;
        case CMD_RQ_MEASURE_READ:
            SensorMeasureReadResponse(pcmd, com_data.fmt.data[0]);
            break;
/*      case CMD_RQ_MEASURE_WRITE:
            break;                 */
        case CMD_RQ_PARAMETER_READ:
            SensorParameterReadResponse(pcmd, com_data.fmt.data[0]);
            break;
        case CMD_RQ_PARAMETER_WRITE:
            SensorParameterWriteResponse(pcmd, com_data.fmt.data[2]);
            break;
        case CMD_RQ_REGISTER_READ:
            SensorRegisterReadResponse(pcmd, com_data.fmt.data[0]);
            break;
        case CMD_RQ_REGISTER_WRITE:
            SensorRegisterWriteResponse(pcmd, com_data.fmt.data[2]);
            break;
        case CMD_RQ_UTILITY_READ:
            SensorUtilityReadResponse(pcmd, com_data.fmt.data[0]);
            break;
        case CMD_RQ_UTILITY_WRITE:
            SensorUtilityWriteResponse(pcmd, com_data.fmt.data[2]);
            break;
        default:
            pcmd->fmt.size = 1;
            pcmd->fmt.data[0] = CMD_RESULT_FAILURE;
            break;
    }

    pcmd->fmt.sum = SetChecksum(pcmd->fmt.main, pcmd->fmt.sub, pcmd->fmt.size, pcmd->fmt.data);
}

/***********************************************************************************************************************
* Function Name: SetChecksum
* Description  : Set checksum
* Arguments    : main -
*                    main command id
*                sub -
*                    sub command id
*                size -
*                    size of data
*                pdata -
*                    Pointer of data buffer
* Return Value : sum -
*                    checksum
***********************************************************************************************************************/
static uint8_t SetChecksum(uint8_t main, uint8_t sub, uint8_t size, uint8_t *pdata)
{
    uint8_t sum;
    uint8_t i;

    sum = (uint8_t)(main + sub + size);
    for (i = 0; i < size; i++)
    {
        sum = (uint8_t)(sum + pdata[i]);
    }

    return sum;
}

/***********************************************************************************************************************
* Function Name: IsRightChecksum
* Description  : Right checksum
* Arguments    : pcmd -
*                    Pointer of received data
* Return Value : result -
*                    TRUE , FALSE
***********************************************************************************************************************/
static BOOL IsRightChecksum(com_data_rd_t *pcmd)
{
    BOOL result;
    uint8_t sum;

    sum = SetChecksum(pcmd->fmt.main, pcmd->fmt.sub, pcmd->fmt.size, pcmd->fmt.data);
    result = FALSE;
    if (pcmd->fmt.sum == sum)
    {
        result = TRUE;
    }
    return result;
}


/***********************************************************************************************************************
* Function Name: GetSensorValue
* Description  : Get sensor value
* Arguments    : code - 
*                    Where to start looking
*                channel - 
*                    channel data
*                pval - 
*                    Pointer of serial output data
* Return Value : result - 
*                    TRUE , FALSE
***********************************************************************************************************************/
static uint8_t GetSensorValue(uint8_t code, uint16_t channel, uint16_t *pval)
{
    uint8_t result;

    switch (code)
    {
        case 0x00:    // SC
            result = GetMeasureSensorCounter(channel, pval);
            break;
        case 0x01:    // RV
            result = GetMeasureReferenceValue(channel, pval);
            break;
        case 0x02:    // RC
            result = GetMeasureReferenceCounter(channel, pval);
            break;
//        case 0x03:    // RC
//            break;
        case 0x04:    // SDLPOS
            result = GetMeasureSliderPosition(channel, pval);
            break;
        case 0x05:
            result = GetMeasureWheelPosition(channel, pval);
            break;
        case 0x06: // Touch sensor On/Off judgement 1 (RSLT0)
            result = GetMeasureTouchResult(0, pval);
            break;
        case 0x07: // Touch sensor On/Off judgement 2 (RSLT1)
            result = GetMeasureTouchResult(1, pval);
            break;
        case 0x08: // Touch sensor On/Off judgement 3 (RSLT2)
            result = GetMeasureTouchResult(2, pval);
            break;
        case 0x09: // Touch sensor On/Off judgement 4 (RSLT3)
            result = GetMeasureTouchResult(3, pval);
            break;
        case 0x0a:    // SCFRST (Sensor counter at 1st measurement)
            result = GetMeasurePrimarySensorCounter(channel, pval);
            break;
        case 0x0b:    // SCSCND (Sensor counte at 2nd measurement)
            result = GetMeasureSecondarySensorCounter(channel, pval);
            break;
        case 0x0c:    // RCFRST (Sensor counter at 1st measurement)
            result = GetMeasurePrimaryReferenceCounter(channel, pval);
            break;
        case 0x0d:    // RCSCND (Sensor counte at 2nd measurement)
            result = GetMeasureSecondaryReferenceCounter(channel, pval);
            break;            
        default:
            result = CMD_RESULT_FAILURE;
            break;
    }
    return result;
}

/***********************************************************************************************************************
* Function Name: SensorProfileReadResponse
* Description  : Sensor read response
* Arguments    : pcmd - 
*                    Pointer of transfer data
*                channel - 
*                    channel data
* Return Value : none
***********************************************************************************************************************/
static void SensorProfileReadResponse(com_data_tx_t *pcmd, uint16_t channel)
{
    uint16_t value;
    uint8_t status;

    SSP_PARAMETER_NOT_USED(channel);

    pcmd->fmt.size    = 3;
    pcmd->fmt.data[0] = CMD_RESULT_FAILURE;    /* Error status */
    pcmd->fmt.data[1] = 0;
    pcmd->fmt.data[2] = 0;

    status = CMD_RESULT_SUCCESS;
    value  = 0;
    switch (pcmd->fmt.sub)
    {
        case 0x00:
            /* ID */
            value = DF_CHIP_ID;
            break;
        case 0x01:
            /* VER1(Version Lower) */
            value = DF_VERSIONu;
            break;
        case 0x02:
            /* VER2(Version Upper) */
            value = DF_VERSIONd;
            break;
        case 0x03:
            /* PROFILE */
            value = DF_PROFILE;
            break;
        case 0x04:
            /* MCU model name 0 */
            value =  (uint16_t)(g_mcu_model_name[0] + ((uint16_t)g_mcu_model_name[1] << 8));
            break;
        case 0x05:
            /* MCU model name 1 */
            value =  (uint16_t)(g_mcu_model_name[2] + ((uint16_t)g_mcu_model_name[3] << 8));
            break;
        case 0x06:
            /* MCU model name 2 */
            value =  (uint16_t)(g_mcu_model_name[4] + ((uint16_t)g_mcu_model_name[5] << 8));
            break;
        case 0x07:
            /* MCU model name 3 */
            value =  (uint16_t)(g_mcu_model_name[6] + ((uint16_t)g_mcu_model_name[7] << 8));
            break;
        case 0x08:
            /* MCU model name 4 */
            value =  (uint16_t)(g_mcu_model_name[8] + ((uint16_t)g_mcu_model_name[9] << 8));
            break;
        case 0x09:
            /* MCU model name 5 */
            value =  (uint16_t)(g_mcu_model_name[10] + ((uint16_t)g_mcu_model_name[11] << 8));
            break;
        case 0x0a:
            /* MCU model name 6 */
            value = (uint16_t)(g_mcu_model_name[12] + ((uint16_t)g_mcu_model_name[13] << 8));
            break;
        case 0x0b:
            /* MCU model name 7 */
            value =  (uint16_t)(g_mcu_model_name[14] + ((uint16_t)g_mcu_model_name[15] << 8));
            break;
        case 0x0c:
            /* Date information 0 */
            value =  (uint16_t)CREATE_SOURCE_DATE0;
            break;
        case 0x0d:
            /* Date information 1 */
            value =  (uint16_t)CREATE_SOURCE_DATE1;
            break;
        case 0x0e:
            /* Date information 2 */
            value =  (uint16_t)CREATE_SOURCE_DATE2;
            break;
        case 0x0f:
            /* Date information 3 */
            value =  (uint16_t)CREATE_SOURCE_DATE3;
            break;
        default:
            status = CMD_RESULT_FAILURE;
            break;
    }
    pcmd->fmt.data[0] = status;
    if (CMD_RESULT_FAILURE != status)
    {
        /* Normal status */
        pcmd->fmt.data[1] = (uint8_t)(value & 0xff);
        pcmd->fmt.data[2] = (uint8_t)(value >> 8);
    }
}

/***********************************************************************************************************************
* Function Name: SensorMeasureReadResponse
* Description  : Sensor write response
* Arguments    : pcmd - 
*                    Pointer of transfer data
*                channel - 
*                    channel data
* Return Value : none
***********************************************************************************************************************/
static void SensorMeasureReadResponse(com_data_tx_t *pcmd, uint16_t channel)
{
    uint16_t value;

    pcmd->fmt.size    = 1;
    pcmd->fmt.data[0] = CMD_RESULT_FAILURE;    /* Error status */

    if (GetSensorValue(pcmd->fmt.sub, channel, &value) != CMD_RESULT_FAILURE)
    {
        pcmd->fmt.size = 3;
        pcmd->fmt.data[0] = CMD_RESULT_SUCCESS;
        pcmd->fmt.data[1] = (uint8_t)(value & 0xff);
        pcmd->fmt.data[2] = (uint8_t)(value >> 8);
    }
}

/***********************************************************************************************************************
* Function Name: SensorParameterReadResponse
* Description  : State response
* Arguments    : pcmd - 
*                    Pointer of transfer data
* Return Value : none
***********************************************************************************************************************/
static void SensorParameterReadResponse(com_data_tx_t * pcmd, uint16_t channel)
{
    uint16_t value;
    uint8_t  status;

    pcmd->fmt.size    = 1;
    pcmd->fmt.data[0] = CMD_RESULT_FAILURE;    /* Error status */
    value             = 0;
    status            = CMD_RESULT_SUCCESS;

    switch (pcmd->fmt.sub)
    {
        case 0x00:
            status = GetParameterTouchFuncMode(&value);
            break;
        case 0x01:
            status = GetParameterDriftInterval(&value);
            break;
        case 0x02:
            status = GetParameterMsa(&value);
            break;
        case 0x03:
            status = GetParameterAcdToTouch(&value);
            break;
        case 0x04:
            status = GetParameterAcdToNoTouch(&value);
            break;
        case 0x05:
        case 0x06:
        case 0x07:
            status = CMD_RESULT_SUCCESS;
            break;
        case 0x08:
            status = GetParameterThreshold(channel, &value);
            break;
        case 0x09:
            status = GetParameterHysteresis(channel, &value);
            break;
        case 0x0a:
            status = GetParameterSliderNumber(&value);
            break;
        case 0x0b:
            status = GetParameterSliderSensorNumber(channel, &value);
            break;
        case 0x0c:
            status  = GetParameterSliderSensor((uint8_t)channel, 0, &value);
            break;
        case 0x0d:
            status  = GetParameterSliderSensor((uint8_t)channel, 1, &value);
            break;
        case 0x0e:
            status  = GetParameterSliderSensor((uint8_t)channel, 2, &value);
            break;
        case 0x0f:
            status  = GetParameterSliderSensor((uint8_t)channel, 3, &value);
            break;
        case 0x10:
            status  = GetParameterSliderSensor((uint8_t)channel, 4, &value);
            break;
        case 0x11:
            status  = GetParameterSliderSensor((uint8_t)channel, 5, &value);
            break;
        case 0x12:
            status  = GetParameterSliderSensor((uint8_t)channel, 6, &value);
            break;
        case 0x13:
            status  = GetParameterSliderSensor((uint8_t)channel, 7, &value);
            break;
        case 0x14:
            status  = GetParameterSliderSensor((uint8_t)channel, 8, &value);
            break;
        case 0x15:
            status  = GetParameterSliderSensor((uint8_t)channel, 9, &value);
            break;
        case 0x16:
            status = GetParameterSliderResolution(channel, &value);
            break;
        case 0x17:
            status = GetParameterSliderThreshold(channel, &value);
            break;
        case 0x18:
            status = GetParameterWheelNumber(&value);
            break;
        case 0x19:
            status = GetParameterWheelSensorNumber(channel, &value);
            break;
        case 0x1a:
            status = GetParameterWheelSensor((uint8_t)channel, 0, &value);
            break;
        case 0x1b:
            status = GetParameterWheelSensor((uint8_t)channel, 1, &value);
            break;
        case 0x1c:
            status = GetParameterWheelSensor((uint8_t)channel, 2, &value);
            break;
        case 0x1d:
            status = GetParameterWheelSensor((uint8_t)channel, 3, &value);
            break;
        case 0x1e:
            status = GetParameterWheelSensor((uint8_t)channel, 4, &value);
            break;
        case 0x1f:
            status = GetParameterWheelSensor((uint8_t)channel, 5, &value);
            break;
        case 0x20:
            status = GetParameterWheelSensor((uint8_t)channel, 6, &value);
            break;
        case 0x21:
            status = GetParameterWheelSensor((uint8_t)channel, 7, &value);
            break;
        case 0x22:
            status = GetParameterWheelSensor((uint8_t)channel, 8, &value);
            break;
        case 0x23:
            status = GetParameterWheelSensor((uint8_t)channel, 9, &value);
            break;
        case 0x24:
            status = GetParameterWheelResolution(channel, &value);
            break;
        case 0x25:
            status = GetParameterWheelThreshold(channel, &value);
            break;
        case 0x28:
            status = GetParameterKeyEnableControl(0, &value);
            break;
        case 0x29:
            status = GetParameterKeyEnableControl(1, &value);
            break;
        case 0x2a:
            status = GetParameterKeyEnableControl(2, &value);
            break;
        case 0x2b:
            status = GetParameterKeyEnableControl(3, &value);
            break;
        case 0x2c:
            status = GetParameterTouchKeyNumber(&value);
            break;
        default:
            status  = CMD_RESULT_FAILURE;
            break;
    }

    if (status == CMD_RESULT_SUCCESS)
    {
        pcmd->fmt.size        = 3;
        pcmd->fmt.data[0]    = status;
        pcmd->fmt.data[1]    = (uint8_t)(value & 0xff);
        pcmd->fmt.data[2]    = (uint8_t)(value >> 8);
    }
}

/***********************************************************************************************************************
* Function Name: SensorParameterWriteResponse
* Description  : Process for the write command of Parameter 
* Arguments    : pcmd - Pointer of transfer data
*                channel - touch sensor number
* Return Value : none
***********************************************************************************************************************/
static void SensorParameterWriteResponse(com_data_tx_t * pcmd, uint16_t channel)
{
    uint16_t value;
    uint8_t  status;

    pcmd->fmt.size = 1;
    status  = CMD_RESULT_FAILURE;

    value = (uint16_t)(((uint16_t)com_data.fmt.data[1] << 8) + com_data.fmt.data[0]);

    switch (pcmd->fmt.sub)
    {
        case 0x00:
            status = SetParameterTouchFuncMode(value);
            break;
        case 0x01:
            status = SetParameterDriftInterval(value);
            break;
        case 0x02:
            status = SetParameterMsa(value);
            break;
        case 0x03:
            status = SetParameterAcdToTouch(value);
            break;
        case 0x04:
            status = SetParameterAcdToNoTouch(value);
            break;
        case 0x05:
        case 0x06:
        case 0x07:
            status = CMD_RESULT_SUCCESS;
            break;
        case 0x08:
            status = SetParameterThreshold(channel, value);
            break;
        case 0x09:
            status = SetParameterHysteresis(channel, value);
            break;
        case 0x16:
            status = SetParameterSliderResolution(channel, value);
            break;
        case 0x17:
            status = SetParameterSliderThreshold(channel, value);
            break;
        case 0x24:
            status = SetParameterWheelResolution(channel, value);
            break;
        case 0x25:
            status = SetParameterWheelThreshold(channel, value);
            break;
        default:
            status = CMD_RESULT_FAILURE;
            break;
    }
    pcmd->fmt.data[0] = status;
}

/***********************************************************************************************************************
* Function Name: SensorRegisterReadResponse
* Description  : Control response
* Arguments    : pcmd - 
*                    Pointer of transfer data
* Return Value : none
***********************************************************************************************************************/
static void SensorRegisterReadResponse(com_data_tx_t * pcmd, uint16_t channel)
{
    uint16_t value;
    uint8_t  status;

    value = 0;

    switch (pcmd->fmt.sub)
    {
        case 0x00:    // CR0
            status = GetRegisterCTSUCR0(&value);
            break;
        case 0x01:    // CR1
            status = GetRegisterCTSUCR1(&value);
            break;
        case 0x02:    // SDPRS
            status = GetRegisterCTSUSDPRS(&value);
            break;
        case 0x03:    // SST
            status = GetRegisterCTSUSST(&value);
            break;
        case 0x04:    // MCH0
            status = GetRegisterCTSUMCH0(&value);
            break;
        case 0x05:    // MCH1
            status = GetRegisterCTSUMCH1(&value);
            break;
        case 0x06:    // CHAC0
            status = GetRegisterCTSUCHAC0(&value);
            break;
        case 0x07:    // CHAC1
            status = GetRegisterCTSUCHAC1(&value);
            break;
        case 0x08:    // CHAC2
            status = GetRegisterCTSUCHAC2(&value);
            break;
        case 0x09:    // CHAC3
            status = GetRegisterCTSUCHAC3(&value);
            break;
        case 0x0a:    // CHAC4
            status = GetRegisterCTSUCHAC4(&value);
            break;
        case 0x0b:    // CHTRC0
            status = GetRegisterCTSUCHTRC0(&value);
            break;
        case 0x0c:    // CHTRC1
            status = GetRegisterCTSUCHTRC1(&value);
            break;
        case 0x0d:    // CHTRC2
            status = GetRegisterCTSUCHTRC2(&value);
            break;
        case 0x0e:    // CHTRC3
            status = GetRegisterCTSUCHTRC3(&value);
            break;
        case 0x0f:    // CHTRC4
            status = GetRegisterCTSUCHTRC4(&value);
            break;
        case 0x10:    // DCLKC
            status = GetRegisterCTSUDCLKC(&value);
            break;
        case 0x11:    // ST
            status = GetRegisterCTSUST(&value);
            break;
        case 0x12:    // SSC
            status = GetRegisterCTSUSSC(channel, &value);
            break;
        case 0x13:    // SO0
            status = GetRegisterCTSUSO0(channel, &value);
            break;
        case 0x14:    // SO1
            status = GetRegisterCTSUSO1(channel, &value);
            break;
        case 0x15: // CTSUSC - No support command
        case 0x16: // CTSURC - No support command
            status = CMD_RESULT_FAILURE;
            break;
        case 0x17:    // ERRS
            status = GetRegisterCTSUERRS(&value);
            break;
        default:
            status = CMD_RESULT_FAILURE;
            break;
    }

    pcmd->fmt.data[0] = status; /* Set command status */
    pcmd->fmt.size    = 1;      /* Set size of data buffer */
    if (status != CMD_RESULT_FAILURE)
    {
        pcmd->fmt.size    = 3;  /* Set size of data buffer */
        pcmd->fmt.data[1] = (uint8_t)(value & 0xff);
        pcmd->fmt.data[2] = (uint8_t)(value >> 8);
    }
}

/***********************************************************************************************************************
* Function Name: SensorRegisterWriteResponse
* Description  : Process for the write command of Register
* Arguments    : pcmd - Pointer of transfer data
*                channel - touch sensor number
* Return Value : none
***********************************************************************************************************************/
static void SensorRegisterWriteResponse(com_data_tx_t * pcmd, uint16_t channel)
{
    uint16_t value;
    uint8_t  status;
    uint8_t  i;
    uint8_t  num;

    SSP_PARAMETER_NOT_USED(i);
    SSP_PARAMETER_NOT_USED(num);

    /* Set the value to write CTSU register */
    value = (uint16_t)(((uint16_t)com_data.fmt.data[1] << 8) + com_data.fmt.data[0]);

    switch (pcmd->fmt.sub)
    {
        case 0x00:    // CR0
            status = SetRegisterCTSUCR0(value);
            break;
        case 0x01:    // CR1
            status = SetRegisterCTSUCR1(value);

            /* Set flags for the touch measurement */
//            for (i = 0; i < METHOD_NUM; i++) {
//                g_touch_function[i].flag.tuning  = 0;
//                g_touch_function[i].flag.calib   = 1;
//                g_touch_function[i].flag.average = 0;
//                for (num = 0; num < g_key_info[i].ena_num; num++)
//                {
//                    *(g_touch_tuning_info[i].result + num) = 0;
//                }
//            }
//            g_touch_system.flag.initial = 0;
            break;
        case 0x02:    // SDPRS
            status = SetRegisterCTSUSDPRS(value);
            break;
        case 0x03:    // SST
            status = SetRegisterCTSUSST(value);
            break;
        case 0x04:    // MCH0
            status = SetRegisterCTSUMCH0(value);
            break;
        case 0x05:    // MCH1
            status = SetRegisterCTSUMCH1(value);
            break;
        case 0x06:    // CHAC0
            status = SetRegisterCTSUCHAC0(value);
            break;
        case 0x07:    // CHAC1
            status = SetRegisterCTSUCHAC1(value);
            break;
        case 0x08:    // CHAC2
            status = SetRegisterCTSUCHAC2(value);
            break;
        case 0x09:    // CHAC3
            status = SetRegisterCTSUCHAC3(value);
            break;
        case 0x0a:    // CHAC4
            status = SetRegisterCTSUCHAC4(value);
            break;
        case 0x0b:    // CHTRC0
            status = SetRegisterCTSUCHTRC0(value);
            break;
        case 0x0c:    // CHTRC1
            status = SetRegisterCTSUCHTRC1(value);
            break;
        case 0x0d:    // CHTRC2
            status = SetRegisterCTSUCHTRC2(value);
            break;
        case 0x0e:    // CHTRC3
            status = SetRegisterCTSUCHTRC3(value);
            break;
        case 0x0f:    // CHTRC4
            status = SetRegisterCTSUCHTRC4(value);
            break;
        case 0x10:    // DCLKC
            status = SetRegisterCTSUDCLKC(value);
            break;
        case 0x11:    // ST
            status = SetRegisterCTSUST(value);
            break;
        case 0x12:    // SSC
            status = SetRegisterCTSUSSC(channel, value);
            break;
        case 0x13:    // SO0
            status = SetRegisterCTSUSO0(channel, value);
            break;
        case 0x14:    // SO1
            status = SetRegisterCTSUSO1(channel, value);
            break;
        case 0x15: // CTSUSC - No support command
        case 0x16: // CTSURC - No support command
            status = CMD_RESULT_FAILURE;
            break;
        case 0x17:
            status = SetRegisterCTSUERRS(value);
            break;
        default:
            status = CMD_RESULT_FAILURE;
            break;
    }
    pcmd->fmt.size = 1;
    pcmd->fmt.data[0] = status;
}

/***********************************************************************************************************************
* Function Name: SensorUtilityReadResponse
* Description  : Process for the read command of Utlility
* Arguments    : pcmd - Pointer of transfer data
*                channel - touch sensor number
* Return Value : none
***********************************************************************************************************************/
static void SensorUtilityReadResponse(com_data_tx_t *pcmd, uint16_t channel)
{
    uint16_t value;
    uint16_t tmpval;
    uint8_t  status;
    uint8_t  size;
    uint16_t monitorSize;

    /* Set default value */
    size  = 1;
    value = 0;

    switch (pcmd->fmt.sub)
    {
        case 0x00:    // UPDATE
            break;
        case 0x01:    // RESET
            break;
        case 0x02:    // SET_BATCH
            break;
        case 0x03:    // EXEC_BATCH
            status = CMD_RESULT_FAILURE;
            if (GetUtilityExecuteBatch(&pcmd->fmt.data[1], &monitorSize) != CMD_RESULT_FAILURE)
            {
                monitorSize++;
                status = CMD_RESULT_SUCCESS;
            }
            if (CMD_RESULT_FAILURE != status)
            {
                size = (uint8_t)monitorSize;
                if  (monitorSize > 255)
                {
                    pcmd->fmt.main |= 0x20;
                }
            }
            break;
        case 0x04:    // MEASURE
            size  = 2;
            value = 1;
            if (CTSU_STOP_MODE == g_ctsu_soft_mode)
            {
                value = 0;
            }
            status = CMD_RESULT_SUCCESS;
            break;
        case 0x05:    // FLAGS
            size  = 3;
            value = g_ctsu_status[g_access_method].byte;
            status = CMD_RESULT_SUCCESS;
            break;
        case 0x06:    // WAIT
            size   = 3;
            value  = WAIT_TIME;
            status = CMD_RESULT_SUCCESS;
            break;
        case 0x07:  // Burst mode
            size   = 3;
            value  = g_burst_mode;
#if !defined(USB_SERIAL_USE)
            status = CMD_RESULT_FAILURE;
#else
            status = CMD_RESULT_SUCCESS;
#endif
            break;
        case 0x08:    // METHOD
            size   = 3;
            value  = METHOD_NUM;
            if (MUTUAL_METHOD_NUM > 7)
            {
                value |= (uint8_t)(0x10);
            }
            for (int i = 0; i < MUTUAL_METHOD_NUM; i++) {
                tmpval = (uint16_t)(tmpval |(1 << (+ i)));
            }
            if (0 != SELF_METHOD_NUM )
            {
                tmpval = (uint16_t)(tmpval << 1);
            }
            value = (uint16_t)(value | (tmpval << 8));
            status = CMD_RESULT_SUCCESS;
            break;
        case 0x09:    // METHOD_INFO
            size   = 3;
            value  = g_method_info[channel].enable;
            status = CMD_RESULT_SUCCESS;
            break;
        case 0x0a:    // ACCESS_METHOD
            size   = 3;
            value  = g_access_method;
            status = CMD_RESULT_SUCCESS;
            break;
        default:
            break;
    }
    pcmd->fmt.size    = 1;
    pcmd->fmt.data[0] = status;
    if (CMD_RESULT_FAILURE != status)
    {
        pcmd->fmt.size    = size;
        pcmd->fmt.data[0] = status;
        if (pcmd->fmt.sub != 0x03/* EXEC_BATCH */)
        {
            pcmd->fmt.data[1] = (uint8_t)(value & 0xff);
            pcmd->fmt.data[2] = (uint8_t)(value >> 8);
        }
    }
}

/***********************************************************************************************************************
* Function Name: SensorUtilityWriteResponse
* Description  : Process for the write command of Utlility 
* Arguments    : pcmd - Pointer of transfer data
*                channel - touch sensor number
* Return Value : none
***********************************************************************************************************************/
static void SensorUtilityWriteResponse(com_data_tx_t *pcmd, uint16_t channel)
{
    uint8_t i;
    uint8_t status;
    ctsu_err_t err;
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_TUNING)
    ctsu_control_arg_t control_arg;
#endif
    status = CMD_RESULT_FAILURE;

    SSP_PARAMETER_NOT_USED(channel);

    switch (pcmd->fmt.sub)
    {
        case 0x00:    // UPDATE
            /* Nothing to do. */
            status = CMD_RESULT_SUCCESS;
            break;
        case 0x01:    // RESET (Initialize from parameter interface )
            g_ctsu_soft_mode = CTSU_STOP_MODE;
            /* Reset parameters from ROM */
            for(uint32_t itr = 0; itr < METHOD_NUM; itr++)
            {
                do
                {
                    err = R_CTSU_Close(ctsu_handle_id[g_access_method]);
                }
                while(CTSU_ERR_LOCKED==err);
            }
            g_ctsu_soft_mode = CTSU_READY_MODE;
            status = CMD_RESULT_SUCCESS;
            break;
        case 0x02:    // SET_BATCH
            for (i = 0; i < com_data.fmt.size; i++)
            {
                monitor_command.command[i] = com_data.fmt.data[i];
            }
            monitor_command.size = com_data.fmt.size;
            status = CMD_RESULT_SUCCESS;
            break;
//        case 0x03:    // EXEC_BATCH (Read only)
//            break;
        case 0x04:    // MEASURE
#if (SF_CTSU_TUNING_CFG_MODE==SF_CTSU_TUNING_CFG_MODE_TUNING)
            if (0 != com_data.fmt.data[0])
            {
                /* Measurement Re-start */
                R_CTSU_Close(ctsu_handle_id[g_access_method]);
                ctsu_cfg_t temp_cfg;

                memcpy(&temp_cfg, all_ctsu_configs[g_access_method], sizeof(ctsu_cfg_t));

                memcpy(&temp_cfg.p_callback, serial_control_callback, sizeof(ctsu_callback_t));

                err = R_CTSU_Open(ctsu_handle_id[g_access_method], &temp_cfg);
                ASSERT(err==CTSU_SUCCESS);
                control_arg.cmd = CTSU_CMD_SET_CALLBACK;
                control_arg.p_context = serial_control_callback;
                err = R_CTSU_Control(ctsu_handle_id[g_access_method], &control_arg);
                ASSERT(err==CTSU_SUCCESS);
                g_ctsu_soft_mode = CTSU_READY_MODE;
            }
            else
            {   /* Close the handle */
                R_CTSU_Close(ctsu_handle_id[g_access_method]);
                g_ctsu_soft_mode = CTSU_STOP_MODE;
                memset((void*)&g_ctsu_status[g_access_method], 0, sizeof(ctsu_status_t));
            }
            status = CMD_RESULT_SUCCESS;
#endif
            break;
//        case 0x05:    // FLAGS (Read only)
//            break;
//        case 0x06:    // WAIT (Read only)
//            break;
        case 0x07:  // Burst mode
            g_burst_mode    = com_data.fmt.data[0];
            status = CMD_RESULT_SUCCESS;
            break;
//        case 0x08:  // METHOD (Read ony)
//            break;
//        case 0x09:  // METHOD_INFO (Read only)
//            break;
        case 0x0a:  // ACCESS_METHOD
            if (com_data.fmt.data[0] < METHOD_NUM)
            {
                g_access_method = com_data.fmt.data[0];
                status = CMD_RESULT_SUCCESS;
            }
            break;
        default:     /* Non-support commands */
            status    = CMD_RESULT_FAILURE;
            break;
    }
    pcmd->fmt.size    = 1;
    pcmd->fmt.data[0] = status;
}

/***********************************************************************************************************************
* Function Name: CTSUGetReferenceCounter
* Description  : This API gets data of Reference counter.
* Arguments    : None
* Return Value : counter
***********************************************************************************************************************/
void BurstMonitorSendSensorValue(void)
{
#ifdef  USB_SERIAL_USE
    uint16_t    loop;
    uint16_t    length;

    // Check the Burst monitor mode flag
    if (1 == g_burst_mode)
    {
        length = 0; // Initialize send value size

        if (g_method_info[0].type == METHOD_TYPE_MTLCP)
        {
            for (loop = 0; loop < METHOD_NUM; loop++)
            {
                for (uint16_t keynum = 0; keynum < g_key_info[loop].ena_num; keynum++)
                {
                    // Primary sensor counter
                    rsp_cmd.fmt.data[length++] = (uint8_t)(*(g_mutual_ico_pri_sensor_pt[loop] + (keynum * 4)) &  0xff);
                    rsp_cmd.fmt.data[length++] = (uint8_t)(*(g_mutual_ico_pri_sensor_pt[loop] + (keynum * 4)) >> 8);

                    // Secondary sensor counter
                    rsp_cmd.fmt.data[length++] = (uint8_t)(*(g_mutual_ico_snd_sensor_pt[loop] + (keynum * 4)) & 0xff);
                    rsp_cmd.fmt.data[length++] = (uint8_t)(*(g_mutual_ico_snd_sensor_pt[loop] + (keynum * 4)) >> 8);
                }
            }
        }
        else
        {
            uint16_t    value0;
            uint16_t    value1;

            for (loop = 0; loop < SELFCAP_SENSOR_MAX; loop++)
            {
                value0  = 0;
                value1  = 0;
                if (g_key_info[0].sensor_index[loop] != 0xff)
                {
                    // Sensor counter
                    value0  = g_self_ico_data_pt[0][g_key_info[0].sensor_index[loop]].sen;

                    // Reference counter
                    value1  = g_self_ico_data_pt[0][g_key_info[0].sensor_index[loop]].ref;
                }

                // Sensor counter
                rsp_cmd.fmt.data[length++] = (uint8_t)(value0 &  0xff);
                rsp_cmd.fmt.data[length++] = (uint8_t)(value0 >> 8);

                // Reference counter
                rsp_cmd.fmt.data[length++] = (uint8_t)(value1 & 0xff);
                rsp_cmd.fmt.data[length++] = (uint8_t)(value1 >> 8);
            }
        }

        rsp_cmd.fmt.main = 0x00;
        rsp_cmd.fmt.sub  = 'B';
        rsp_cmd.fmt.sum  = 'M';
        rsp_cmd.fmt.size = length;
        if (length > 255) {
            // Enable the Carry flag
            rsp_cmd.fmt.main |= 0x20;
        }

        // Send sensor values to USB-Serial port
        R_usb_pcdc_SendData( &rsp_cmd.byte_acs[0], length + HEAD_SIZE, (usb_cbinfo_t)&usb_psmpl_TxCB );
    }
#endif  // USB_SERIAL_USE
}


uint32_t scan_count = 0;

void serial_control_callback(ctsu_callback_arg_t const * const p_arg)
{

    if(p_arg->event_mask == CTSU_EVENT_SCAN_COMPLETED)
    {
        scan_count++;
        if(p_arg->info == 0)
        {
            g_ctsu_status[g_access_method].flag.data_update = 1;
            g_ctsu_status[g_access_method].flag.sens_over = 0;
            g_ctsu_status[g_access_method].flag.ref_over = 0;
            g_ctsu_status[g_access_method].flag.icomp_error = 0;
        }
        else
        {
            if(p_arg->info & CTSU_ERR_CTSU_SC_OVF)
            {
                g_ctsu_status[g_access_method].flag.sens_over = 1;
            }
            if(p_arg->info & CTSU_ERR_CTSU_RC_OVF)
            {
                g_ctsu_status[g_access_method].flag.ref_over = 1;
            }
            else if(p_arg->info & CTSU_ERR_CTSU_ICOMP)
            {
                g_ctsu_status[g_access_method].flag.icomp_error = 1;
            }
        }
    }
    else if ((p_arg->event_mask & CTSU_EVENT_STARTING_SCAN) == CTSU_EVENT_STARTING_SCAN)
    {
        g_ctsu_status[g_access_method].flag.ctsu_measure = 1;
    }
}
#endif    //] WORKBENCH_COMMAND_USE
/******************************************************************************
* END OF TEXT
******************************************************************************/
