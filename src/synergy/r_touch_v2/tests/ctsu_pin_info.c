/*
 * ctsu_pin_info.c
 *
 *  Created on: Jan 12, 2017
 *      Author: Onkar.Raut
 */

#include "bsp_api.h"

/**
 * Specify the TS Pins available with the MCU Group.
 */
ioport_port_pin_t const g_ctsu_tspin_info[] =
{
#if defined(BSP_MCU_GROUP_S124)

#elif defined(BSP_MCU_GROUP_S3A7)
 [0] =  IOPORT_PORT_02_PIN_04, /* TS00 */
 [1] =  IOPORT_PORT_02_PIN_06, /* TS01 */
#if (SSP_VERSION_MAJOR >= 1) && (SSP_VERSION_MINOR >= 2)
 [2] =  0xFFFF,            /* TS02 Not available */
#else
 [2] =  IOPORT_PIN_END,
#endif
 [3] =  IOPORT_PORT_04_PIN_07, /* TS03 */
 [4] =  IOPORT_PORT_04_PIN_08, /* TS04 */
 [5] =  IOPORT_PORT_04_PIN_09, /* TS05 */
 [6] =  IOPORT_PORT_04_PIN_10, /* TS06 */
 [7] =  IOPORT_PORT_04_PIN_11, /* TS07 */
 [8] =  IOPORT_PORT_04_PIN_12, /* TS08 */
 [9] =  IOPORT_PORT_04_PIN_13, /* TS09 */
 [10] = IOPORT_PORT_04_PIN_14, /* TS10 */
 [11] = IOPORT_PORT_04_PIN_15, /* TS11 */
 [12] = IOPORT_PORT_07_PIN_08, /* TS12 */
 [13] = IOPORT_PORT_07_PIN_09, /* TS13 */
 [14] = IOPORT_PORT_04_PIN_06, /* TS14 */
 [15] = IOPORT_PORT_04_PIN_05, /* TS15 */
 [16] = IOPORT_PORT_04_PIN_04, /* TS16 */
 [17] = IOPORT_PORT_04_PIN_03, /* TS17 */
 [18] = IOPORT_PORT_04_PIN_02, /* TS18 */
 [19] = IOPORT_PORT_04_PIN_01, /* TS19 */
 [20] = IOPORT_PORT_04_PIN_00, /* TS20 */
 [21] = IOPORT_PORT_00_PIN_00, /* TS21 */
 [22] = IOPORT_PORT_00_PIN_01, /* TS22 */
#if (SSP_VERSION_MAJOR >= 1) && (SSP_VERSION_MINOR >= 2)
 [23] = 0xFFFF, /* TS23 Not available */
 [24] = 0xFFFF, /* TS24 Not available */
 [25] = 0xFFFF, /* TS25 Not available */
#else
 [23] = IOPORT_PIN_END, /* TS23 Not available */
 [24] = IOPORT_PIN_END, /* TS24 Not available */
 [25] = IOPORT_PIN_END, /* TS25 Not available */
#endif
 [26] = IOPORT_PORT_00_PIN_05, /* TS26 */
 [27] = IOPORT_PORT_00_PIN_06, /* TS27 */
#if (SSP_VERSION_MAJOR >= 1) && (SSP_VERSION_MINOR >= 2)
 [28] = 0xFFFF, /* TS28 */
#else
 [28] = IOPORT_PIN_END, /* TS28 */
#endif
 [29] = IOPORT_PORT_00_PIN_08, /* TS29 */
 [30] = IOPORT_PORT_00_PIN_10, /* TS30 */
 [31] = IOPORT_PORT_00_PIN_11, /* TS31 */
 [32] = IOPORT_PORT_07_PIN_00, /* TS32 */
 [33] = IOPORT_PORT_07_PIN_01, /* TS33 */
 [34] = IOPORT_PORT_07_PIN_02, /* TS34 */
 [35] = IOPORT_PORT_07_PIN_10, /* TS35 */
#elif defined(BSP_MCU_GROUP_S5D9)
 [0] =  IOPORT_PORT_02_PIN_04, /* TS00 */
 [1] =  IOPORT_PORT_02_PIN_06, /* TS01 */
 [2] =  IOPORT_PORT_02_PIN_07, /* TS02 */
 [3] =  IOPORT_PORT_04_PIN_07, /* TS03 */
 [4] =  IOPORT_PORT_04_PIN_08, /* TS04 */
 [5] =  IOPORT_PORT_04_PIN_09, /* TS05 */
 [6] =  IOPORT_PORT_04_PIN_10, /* TS06 */
 [7] =  IOPORT_PORT_04_PIN_11, /* TS07 */
 [8] =  IOPORT_PORT_04_PIN_12, /* TS08 */
 [9] =  IOPORT_PORT_04_PIN_13, /* TS09 */
 [10] = IOPORT_PORT_04_PIN_14, /* TS10 */
 [11] = IOPORT_PORT_04_PIN_15, /* TS11 */
 [12] = IOPORT_PORT_07_PIN_08, /* TS12 */
 [13] = IOPORT_PORT_07_PIN_09, /* TS13 */
 [14] = IOPORT_PORT_07_PIN_10, /* TS14 */
 [15] = IOPORT_PORT_07_PIN_11, /* TS15 */
 [16] = IOPORT_PORT_07_PIN_12, /* TS16 */
 [17] = IOPORT_PORT_07_PIN_13, /* TS17 */
#elif defined(BSP_MCU_GROUP_S7G2)

#else

#endif
};

const size_t g_tspin_count = (sizeof(g_ctsu_tspin_info))/(sizeof(g_ctsu_tspin_info[0]));

/**
 * Specify the Port Pin used for TSCAP.
 */
ioport_port_pin_t g_ctsu_tscap_info[1] =
{
#if defined(BSP_MCU_GROUP_S124)

#elif defined(BSP_MCU_GROUP_S3A7)
#if 0
 [0] =  IOPORT_PORT_02_PIN_03, /* TS00 */
#else
 [0] =  IOPORT_PORT_02_PIN_05, /* TS01 */
#endif
#elif defined(BSP_MCU_GROUP_S5D9)


#elif defined(BSP_MCU_GROUP_S7G2)

#else

#endif
};

