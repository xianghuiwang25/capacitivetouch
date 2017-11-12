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
* File Name    : r_touch.h
* Version      : 1.00
* Device(s)    : R5F5113xAxFP,R5F5231xAxFP,R5F51305AxFN
* Description  : This file includes the Capacitive Touch parameter.
***********************************************************************************************************************/

/***********************************************************************************************************************
* History      : DD.MM.YYYY Version    Description
*              : xx.xx.2015   1.00     First Release
***********************************************************************************************************************/
#ifndef __R_TOUCH_H__    //[
#define __R_TOUCH_H__

/***********************************************************************************************************************
* Includes
***********************************************************************************************************************/
#include <stdint.h>
#include "r_ctsu.h"

/***********************************************************************************************************************
* Macro definitions
***********************************************************************************************************************/
#ifdef __R_TOUCH_C__
    #define TOUCH_EXTERN
#else
    #define TOUCH_EXTERN    extern
#endif

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

/* Maximum number of enable sensor number definition */
#define SELFCAP_SENSOR_MAX  (36)        /* Maximum number of enable sensor number + 1 */

/* Chip ID */
#define DF_CHIP_ID    ((DF_CCMD_VER << 8) | SELFCAP_SENSOR_MAX)

/* Date of source file creation */
#define CREATE_SOURCE_DATE0	(0x1608)    /* YYMM */
#define CREATE_SOURCE_DATE1	(0x0315)	/* DDHH */
#define CREATE_SOURCE_DATE2	(0x1528)    /* MMSS */
#define CREATE_SOURCE_DATE3	(0x0000)    /* 0000 */

#define KEY_USE
#define SLIDER_USE
#define WHEEL_USE

#if !defined(KEY_USE) && !defined(SLIDER_USE) && !defined(WHEEL_USE)
    #error "Exactly one of USE-options (KEY_USE/SLIDER_USE/WHEEL_USE) must be specified "
#endif

/* Main loop cycle */
#define TOUCH_MAIN_CYCLE_US     20000

/* Standard measurement time in case of Self-capacitance */
#define	SELF_MEASURE_TIME_US    700

/* Standard measurement time in case of Mutual-capacitance */
#define	MUTUAL_MEASURE_TIME_US  1400

/***********************************************************************************************************************
******************************                                                            ******************************
******************************                  Self parameter definition                 ******************************
******************************                                                            ******************************
***********************************************************************************************************************/
#define SELF_KEY_USE_00            (0)
#define SELF_KEY_USE_01            (0)
#define SELF_KEY_USE_02            (0)
#define SELF_KEY_USE_03            (0)
#define SELF_KEY_USE_04            (0)
#define SELF_KEY_USE_05            (0)
#define SELF_KEY_USE_06            (0)
#define SELF_KEY_USE_07            (0)
#define SELF_KEY_USE_08            (0)
#define SELF_KEY_USE_09            (0)
#define SELF_KEY_USE_10            (0)
#define SELF_KEY_USE_11            (1)
#define SELF_KEY_USE_12            (0)
#define SELF_KEY_USE_13            (0)
#define SELF_KEY_USE_14            (0)
#define SELF_KEY_USE_15            (0)
#define SELF_KEY_USE_16            (0)
#define SELF_KEY_USE_17            (0)
#define SELF_KEY_USE_18            (0)
#define SELF_KEY_USE_19            (0)
#define SELF_KEY_USE_20            (0)
#define SELF_KEY_USE_21            (0)
#define SELF_KEY_USE_22            (0)
#define SELF_KEY_USE_23            (0)
#define SELF_KEY_USE_24            (0)
#define SELF_KEY_USE_25            (0)
#define SELF_KEY_USE_26            (0)
#define SELF_KEY_USE_27            (0)
#define SELF_KEY_USE_28            (0)
#define SELF_KEY_USE_29            (0)
#define SELF_KEY_USE_30            (1)
#define SELF_KEY_USE_31            (1)
#define SELF_KEY_USE_32            (0)
#define SELF_KEY_USE_33            (0)
#define SELF_KEY_USE_34            (0)
#define SELF_KEY_USE_35            (0)

#define SELF_KEY_USE_GROUP0    ((SELF_KEY_USE_00      ) + (SELF_KEY_USE_01 <<  1) + (SELF_KEY_USE_02 <<  2) + \
                                (SELF_KEY_USE_03 <<  3) + (SELF_KEY_USE_04 <<  4) + (SELF_KEY_USE_05 <<  5) + \
                                (SELF_KEY_USE_06 <<  6) + (SELF_KEY_USE_07 <<  7) + (SELF_KEY_USE_08 <<  8) + \
                                (SELF_KEY_USE_09 <<  9) + (SELF_KEY_USE_10 << 10) + (SELF_KEY_USE_11 << 11) + \
                                (SELF_KEY_USE_12 << 12) + (SELF_KEY_USE_13 << 13) + (SELF_KEY_USE_14 << 14) + \
                                (SELF_KEY_USE_15 << 15))

#define SELF_KEY_USE_GROUP1    ((SELF_KEY_USE_16      ) + (SELF_KEY_USE_17 <<  1) + (SELF_KEY_USE_18 <<  2) + \
                                (SELF_KEY_USE_19 <<  3) + (SELF_KEY_USE_20 <<  4) + (SELF_KEY_USE_21 <<  5) + \
                                (SELF_KEY_USE_22 <<  6) + (SELF_KEY_USE_23 <<  7) + (SELF_KEY_USE_24 <<  8) + \
                                (SELF_KEY_USE_25 <<  9) + (SELF_KEY_USE_26 << 10) + (SELF_KEY_USE_27 << 11) + \
                                (SELF_KEY_USE_28 << 12) + (SELF_KEY_USE_29 << 13) + (SELF_KEY_USE_30 << 14) + \
                                (SELF_KEY_USE_31 << 15))

#define SELF_KEY_USE_GROUP2   ((SELF_KEY_USE_32      ) + (SELF_KEY_USE_33 <<  1) + (SELF_KEY_USE_34 <<  2) + \
                               (SELF_KEY_USE_35 << 3))

#if( SELF_KEY_USE_GROUP2 > 0 )
    #define SELF_MAX_GROUP        (3)
#elif( SELF_KEY_USE_GROUP1 > 0 )
    #define SELF_MAX_GROUP        (2)
#else
    #define SELF_MAX_GROUP        (1)
#endif

#define SELF_KEY_NUM           (SELF_KEY_USE_00 + SELF_KEY_USE_01 + SELF_KEY_USE_02 + SELF_KEY_USE_03 + \
                                SELF_KEY_USE_04 + SELF_KEY_USE_05 + SELF_KEY_USE_06 + SELF_KEY_USE_07 + \
                                SELF_KEY_USE_08 + SELF_KEY_USE_09 + SELF_KEY_USE_10 + SELF_KEY_USE_11 + \
                                SELF_KEY_USE_12 + SELF_KEY_USE_13 + SELF_KEY_USE_14 + SELF_KEY_USE_15 + \
                                SELF_KEY_USE_16 + SELF_KEY_USE_17 + SELF_KEY_USE_18 + SELF_KEY_USE_19 + \
                                SELF_KEY_USE_20 + SELF_KEY_USE_21 + SELF_KEY_USE_22 + SELF_KEY_USE_23 + \
                                SELF_KEY_USE_24 + SELF_KEY_USE_25 + SELF_KEY_USE_26 + SELF_KEY_USE_27 + \
                                SELF_KEY_USE_28 + SELF_KEY_USE_29 + SELF_KEY_USE_30 + SELF_KEY_USE_31 + \
                                SELF_KEY_USE_32 + SELF_KEY_USE_33 + SELF_KEY_USE_34 + SELF_KEY_USE_35)

/* ON/OFF threshold set up data */
#define SELF_TS00_THR            (1000)
#define SELF_TS01_THR            (1001)
#define SELF_TS02_THR            (1002)
#define SELF_TS03_THR            (1003)
#define SELF_TS04_THR            (1004)
#define SELF_TS05_THR            (1005)
#define SELF_TS06_THR            (1006)
#define SELF_TS07_THR            (1007)
#define SELF_TS08_THR            (1008)
#define SELF_TS09_THR            (1009)
#define SELF_TS10_THR            (1010)
#define SELF_TS11_THR            (1726)
#define SELF_TS12_THR            (1012)
#define SELF_TS13_THR            (1013)
#define SELF_TS14_THR            (1014)
#define SELF_TS15_THR            (1015)
#define SELF_TS16_THR            (1016)
#define SELF_TS17_THR            (1017)
#define SELF_TS18_THR            (1018)
#define SELF_TS19_THR            (1019)
#define SELF_TS20_THR            (1020)
#define SELF_TS21_THR            (1021)
#define SELF_TS22_THR            (1022)
#define SELF_TS23_THR            (1023)
#define SELF_TS24_THR            (1024)
#define SELF_TS25_THR            (1025)
#define SELF_TS26_THR            (1026)
#define SELF_TS27_THR            (1027)
#define SELF_TS28_THR            (1028)
#define SELF_TS29_THR            (1029)
#define SELF_TS30_THR            (2308)
#define SELF_TS31_THR            (1994)
#define SELF_TS32_THR            (1032)
#define SELF_TS33_THR            (1033)
#define SELF_TS34_THR            (1034)
#define SELF_TS35_THR            (1035)

/* Hysteresis set up data */
#define SELF_TS00_HYS            (50)
#define SELF_TS01_HYS            (51)
#define SELF_TS02_HYS            (52)
#define SELF_TS03_HYS            (53)
#define SELF_TS04_HYS            (54)
#define SELF_TS05_HYS            (55)
#define SELF_TS06_HYS            (56)
#define SELF_TS07_HYS            (57)
#define SELF_TS08_HYS            (58)
#define SELF_TS09_HYS            (59)
#define SELF_TS10_HYS            (60)
#define SELF_TS11_HYS            (86)
#define SELF_TS12_HYS            (62)
#define SELF_TS13_HYS            (63)
#define SELF_TS14_HYS            (64)
#define SELF_TS15_HYS            (65)
#define SELF_TS16_HYS            (66)
#define SELF_TS17_HYS            (67)
#define SELF_TS18_HYS            (68)
#define SELF_TS19_HYS            (69)
#define SELF_TS20_HYS            (70)
#define SELF_TS21_HYS            (71)
#define SELF_TS22_HYS            (72)
#define SELF_TS23_HYS            (73)
#define SELF_TS24_HYS            (74)
#define SELF_TS25_HYS            (75)
#define SELF_TS26_HYS            (76)
#define SELF_TS27_HYS            (77)
#define SELF_TS28_HYS            (78)
#define SELF_TS29_HYS            (79)
#define SELF_TS30_HYS            (115)
#define SELF_TS31_HYS            (99)
#define SELF_TS32_HYS            (82)
#define SELF_TS33_HYS            (83)
#define SELF_TS34_HYS            (84)
#define SELF_TS35_HYS            (85)

/*====================================================================================================================*/
/*=====    Mutual 0 touch parameter definition    ====================================================================*/
/*====================================================================================================================*/
#define MUTUAL0_KEY00_USE        (1)
#define MUTUAL0_KEY01_USE        (1)
#define MUTUAL0_KEY02_USE        (1)
#define MUTUAL0_KEY03_USE        (1)
#define MUTUAL0_KEY04_USE        (1)
#define MUTUAL0_KEY05_USE        (1)
#define MUTUAL0_KEY06_USE        (1)
#define MUTUAL0_KEY07_USE        (1)
#define MUTUAL0_KEY08_USE        (1)
#define MUTUAL0_KEY09_USE        (1)
#define MUTUAL0_KEY10_USE        (1)
#define MUTUAL0_KEY11_USE        (1)
#define MUTUAL0_KEY12_USE        (1)
#define MUTUAL0_KEY13_USE        (1)
#define MUTUAL0_KEY14_USE        (1)
#define MUTUAL0_KEY15_USE        (1)
#define MUTUAL0_KEY16_USE        (1)
#define MUTUAL0_KEY17_USE        (1)
#define MUTUAL0_KEY18_USE        (1)
#define MUTUAL0_KEY19_USE        (1)
#define MUTUAL0_KEY20_USE        (0)
#define MUTUAL0_KEY21_USE        (0)
#define MUTUAL0_KEY22_USE        (0)
#define MUTUAL0_KEY23_USE        (0)
#define MUTUAL0_KEY24_USE        (0)
#define MUTUAL0_KEY25_USE        (0)
#define MUTUAL0_KEY26_USE        (0)
#define MUTUAL0_KEY27_USE        (0)
#define MUTUAL0_KEY28_USE        (0)
#define MUTUAL0_KEY29_USE        (0)
#define MUTUAL0_KEY30_USE        (0)
#define MUTUAL0_KEY31_USE        (0)
#define MUTUAL0_KEY32_USE        (0)
#define MUTUAL0_KEY33_USE        (0)
#define MUTUAL0_KEY34_USE        (0)
#define MUTUAL0_KEY35_USE        (0)
#define MUTUAL0_KEY36_USE        (0)
#define MUTUAL0_KEY37_USE        (0)
#define MUTUAL0_KEY38_USE        (0)
#define MUTUAL0_KEY39_USE        (0)
#define MUTUAL0_KEY40_USE        (0)
#define MUTUAL0_KEY41_USE        (0)
#define MUTUAL0_KEY42_USE        (0)
#define MUTUAL0_KEY43_USE        (0)
#define MUTUAL0_KEY44_USE        (0)
#define MUTUAL0_KEY45_USE        (0)
#define MUTUAL0_KEY46_USE        (0)
#define MUTUAL0_KEY47_USE        (0)
#define MUTUAL0_KEY48_USE        (0)
#define MUTUAL0_KEY49_USE        (0)
#define MUTUAL0_KEY50_USE        (0)
#define MUTUAL0_KEY51_USE        (0)
#define MUTUAL0_KEY52_USE        (0)
#define MUTUAL0_KEY53_USE        (0)
#define MUTUAL0_KEY54_USE        (0)
#define MUTUAL0_KEY55_USE        (0)
#define MUTUAL0_KEY56_USE        (0)
#define MUTUAL0_KEY57_USE        (0)
#define MUTUAL0_KEY58_USE        (0)
#define MUTUAL0_KEY59_USE        (0)
#define MUTUAL0_KEY60_USE        (0)
#define MUTUAL0_KEY61_USE        (0)
#define MUTUAL0_KEY62_USE        (0)
#define MUTUAL0_KEY63_USE        (0)

#define MUTUAL0_KEY_USE_GROUP0   ((MUTUAL0_KEY00_USE      ) + (MUTUAL0_KEY01_USE <<  1) + (MUTUAL0_KEY02_USE <<  2) + \
                                  (MUTUAL0_KEY03_USE <<  3) + (MUTUAL0_KEY04_USE <<  4) + (MUTUAL0_KEY05_USE <<  5) + \
                                  (MUTUAL0_KEY06_USE <<  6) + (MUTUAL0_KEY07_USE <<  7) + (MUTUAL0_KEY08_USE <<  8) + \
                                  (MUTUAL0_KEY09_USE <<  9) + (MUTUAL0_KEY10_USE << 10) + (MUTUAL0_KEY11_USE << 11) + \
                                  (MUTUAL0_KEY12_USE << 12) + (MUTUAL0_KEY13_USE << 13) + (MUTUAL0_KEY14_USE << 14) + \
                                  (MUTUAL0_KEY15_USE << 15))

#define MUTUAL0_KEY_USE_GROUP1   ((MUTUAL0_KEY16_USE      ) + (MUTUAL0_KEY17_USE <<  1) + (MUTUAL0_KEY18_USE <<  2) + \
                                  (MUTUAL0_KEY19_USE <<  3) + (MUTUAL0_KEY20_USE <<  4) + (MUTUAL0_KEY21_USE <<  5) + \
                                  (MUTUAL0_KEY22_USE <<  6) + (MUTUAL0_KEY23_USE <<  7) + (MUTUAL0_KEY24_USE <<  8) + \
                                  (MUTUAL0_KEY25_USE <<  9) + (MUTUAL0_KEY26_USE << 10) + (MUTUAL0_KEY27_USE << 11) + \
                                  (MUTUAL0_KEY28_USE << 12) + (MUTUAL0_KEY29_USE << 13) + (MUTUAL0_KEY30_USE << 14) + \
                                  (MUTUAL0_KEY31_USE << 15))

#define MUTUAL0_KEY_USE_GROUP2   ((MUTUAL0_KEY32_USE      ) + (MUTUAL0_KEY33_USE <<  1) + (MUTUAL0_KEY34_USE <<  2) + \
                                  (MUTUAL0_KEY35_USE <<  3) + (MUTUAL0_KEY36_USE <<  4) + (MUTUAL0_KEY37_USE <<  5) + \
                                  (MUTUAL0_KEY36_USE <<  6) + (MUTUAL0_KEY39_USE <<  7) + (MUTUAL0_KEY40_USE <<  8) + \
                                  (MUTUAL0_KEY41_USE <<  9) + (MUTUAL0_KEY42_USE << 10) + (MUTUAL0_KEY43_USE << 11) + \
                                  (MUTUAL0_KEY44_USE << 12) + (MUTUAL0_KEY45_USE << 13) + (MUTUAL0_KEY46_USE << 14) + \
                                  (MUTUAL0_KEY47_USE << 15))

#define MUTUAL0_KEY_USE_GROUP3   ((MUTUAL0_KEY48_USE      ) + (MUTUAL0_KEY49_USE <<  1) + (MUTUAL0_KEY50_USE <<  2) + \
                                  (MUTUAL0_KEY51_USE <<  3) + (MUTUAL0_KEY52_USE <<  4) + (MUTUAL0_KEY53_USE <<  5) + \
                                  (MUTUAL0_KEY54_USE <<  6) + (MUTUAL0_KEY55_USE <<  7) + (MUTUAL0_KEY56_USE <<  8) + \
                                  (MUTUAL0_KEY57_USE <<  9) + (MUTUAL0_KEY58_USE << 10) + (MUTUAL0_KEY59_USE << 11) + \
                                  (MUTUAL0_KEY60_USE << 12) + (MUTUAL0_KEY61_USE << 13) + (MUTUAL0_KEY62_USE << 14) + \
                                  (MUTUAL0_KEY63_USE << 15))

#if (MUTUAL0_KEY_USE_GROUP3 > 0)
    #define MUTUAL0_MAX_GROUP        (4)
#elif (MUTUAL0_KEY_USE_GROUP2 > 0)
    #define MUTUAL0_MAX_GROUP        (3)
#elif (MUTUAL0_KEY_USE_GROUP1 > 0)
    #define MUTUAL0_MAX_GROUP        (2)
#else
    #define MUTUAL0_MAX_GROUP        (1)
#endif

#define MUTUAL0_KEY_NUM           (MUTUAL0_KEY00_USE + MUTUAL0_KEY01_USE + MUTUAL0_KEY02_USE + MUTUAL0_KEY03_USE + \
                                   MUTUAL0_KEY04_USE + MUTUAL0_KEY05_USE + MUTUAL0_KEY06_USE + MUTUAL0_KEY07_USE + \
                                   MUTUAL0_KEY08_USE + MUTUAL0_KEY09_USE + MUTUAL0_KEY10_USE + MUTUAL0_KEY11_USE + \
                                   MUTUAL0_KEY12_USE + MUTUAL0_KEY13_USE + MUTUAL0_KEY14_USE + MUTUAL0_KEY15_USE + \
                                   MUTUAL0_KEY16_USE + MUTUAL0_KEY17_USE + MUTUAL0_KEY18_USE + MUTUAL0_KEY19_USE + \
                                   MUTUAL0_KEY20_USE + MUTUAL0_KEY21_USE + MUTUAL0_KEY22_USE + MUTUAL0_KEY23_USE + \
                                   MUTUAL0_KEY24_USE + MUTUAL0_KEY25_USE + MUTUAL0_KEY26_USE + MUTUAL0_KEY27_USE + \
                                   MUTUAL0_KEY28_USE + MUTUAL0_KEY29_USE + MUTUAL0_KEY30_USE + MUTUAL0_KEY31_USE + \
                                   MUTUAL0_KEY32_USE + MUTUAL0_KEY33_USE + MUTUAL0_KEY34_USE + MUTUAL0_KEY35_USE + \
                                   MUTUAL0_KEY36_USE + MUTUAL0_KEY37_USE + MUTUAL0_KEY38_USE + MUTUAL0_KEY39_USE + \
                                   MUTUAL0_KEY40_USE + MUTUAL0_KEY41_USE + MUTUAL0_KEY42_USE + MUTUAL0_KEY43_USE + \
                                   MUTUAL0_KEY44_USE + MUTUAL0_KEY45_USE + MUTUAL0_KEY46_USE + MUTUAL0_KEY47_USE + \
                                   MUTUAL0_KEY48_USE + MUTUAL0_KEY49_USE + MUTUAL0_KEY50_USE + MUTUAL0_KEY51_USE + \
                                   MUTUAL0_KEY52_USE + MUTUAL0_KEY53_USE + MUTUAL0_KEY54_USE + MUTUAL0_KEY55_USE + \
                                   MUTUAL0_KEY56_USE + MUTUAL0_KEY57_USE + MUTUAL0_KEY58_USE + MUTUAL0_KEY59_USE + \
                                   MUTUAL0_KEY60_USE + MUTUAL0_KEY61_USE + MUTUAL0_KEY62_USE + MUTUAL0_KEY63_USE)

/* ON/OFF threshold set up data */
#define MUTUAL0_KEY00_THR          (1787)
#define MUTUAL0_KEY01_THR          (1429)
#define MUTUAL0_KEY02_THR          (1615)
#define MUTUAL0_KEY03_THR          (1150)
#define MUTUAL0_KEY04_THR          (1673)
#define MUTUAL0_KEY05_THR          (1380)
#define MUTUAL0_KEY06_THR          (1412)
#define MUTUAL0_KEY07_THR          (1512)
#define MUTUAL0_KEY08_THR          (1252)
#define MUTUAL0_KEY09_THR          (1330)
#define MUTUAL0_KEY10_THR          (1666)
#define MUTUAL0_KEY11_THR          (1673)
#define MUTUAL0_KEY12_THR          (1662)
#define MUTUAL0_KEY13_THR          (1617)
#define MUTUAL0_KEY14_THR          (1353)
#define MUTUAL0_KEY15_THR          (1601)
#define MUTUAL0_KEY16_THR          (1519)
#define MUTUAL0_KEY17_THR          (1819)
#define MUTUAL0_KEY18_THR          (1666)
#define MUTUAL0_KEY19_THR          (1579)
#define MUTUAL0_KEY20_THR          (1020)
#define MUTUAL0_KEY21_THR          (1021)
#define MUTUAL0_KEY22_THR          (1022)
#define MUTUAL0_KEY23_THR          (1023)
#define MUTUAL0_KEY24_THR          (1024)
#define MUTUAL0_KEY25_THR          (1025)
#define MUTUAL0_KEY26_THR          (1026)
#define MUTUAL0_KEY27_THR          (1027)
#define MUTUAL0_KEY28_THR          (1028)
#define MUTUAL0_KEY29_THR          (1029)
#define MUTUAL0_KEY30_THR          (1030)
#define MUTUAL0_KEY31_THR          (1031)
#define MUTUAL0_KEY32_THR          (1032)
#define MUTUAL0_KEY33_THR          (1033)
#define MUTUAL0_KEY34_THR          (1034)
#define MUTUAL0_KEY35_THR          (1035)
#define MUTUAL0_KEY36_THR          (1036)
#define MUTUAL0_KEY37_THR          (1037)
#define MUTUAL0_KEY38_THR          (1038)
#define MUTUAL0_KEY39_THR          (1039)
#define MUTUAL0_KEY40_THR          (1040)
#define MUTUAL0_KEY41_THR          (1041)
#define MUTUAL0_KEY42_THR          (1042)
#define MUTUAL0_KEY43_THR          (1043)
#define MUTUAL0_KEY44_THR          (1044)
#define MUTUAL0_KEY45_THR          (1045)
#define MUTUAL0_KEY46_THR          (1046)
#define MUTUAL0_KEY47_THR          (1047)
#define MUTUAL0_KEY48_THR          (1048)
#define MUTUAL0_KEY49_THR          (1049)
#define MUTUAL0_KEY50_THR          (1050)
#define MUTUAL0_KEY51_THR          (1051)
#define MUTUAL0_KEY52_THR          (1052)
#define MUTUAL0_KEY53_THR          (1053)
#define MUTUAL0_KEY54_THR          (1054)
#define MUTUAL0_KEY55_THR          (1055)
#define MUTUAL0_KEY56_THR          (1056)
#define MUTUAL0_KEY57_THR          (1057)
#define MUTUAL0_KEY58_THR          (1058)
#define MUTUAL0_KEY59_THR          (1059)
#define MUTUAL0_KEY60_THR          (1060)
#define MUTUAL0_KEY61_THR          (1061)
#define MUTUAL0_KEY62_THR          (1062)
#define MUTUAL0_KEY63_THR          (1063)

/* Hysteresis set up data */
#define MUTUAL0_KEY00_HYS          (89)
#define MUTUAL0_KEY01_HYS          (71)
#define MUTUAL0_KEY02_HYS          (80)
#define MUTUAL0_KEY03_HYS          (57)
#define MUTUAL0_KEY04_HYS          (83)
#define MUTUAL0_KEY05_HYS          (69)
#define MUTUAL0_KEY06_HYS          (70)
#define MUTUAL0_KEY07_HYS          (75)
#define MUTUAL0_KEY08_HYS          (62)
#define MUTUAL0_KEY09_HYS          (66)
#define MUTUAL0_KEY10_HYS          (83)
#define MUTUAL0_KEY11_HYS          (83)
#define MUTUAL0_KEY12_HYS          (83)
#define MUTUAL0_KEY13_HYS          (80)
#define MUTUAL0_KEY14_HYS          (67)
#define MUTUAL0_KEY15_HYS          (80)
#define MUTUAL0_KEY16_HYS          (75)
#define MUTUAL0_KEY17_HYS          (90)
#define MUTUAL0_KEY18_HYS          (83)
#define MUTUAL0_KEY19_HYS          (78)
#define MUTUAL0_KEY20_HYS          (40)
#define MUTUAL0_KEY21_HYS          (41)
#define MUTUAL0_KEY22_HYS          (42)
#define MUTUAL0_KEY23_HYS          (43)
#define MUTUAL0_KEY24_HYS          (44)
#define MUTUAL0_KEY25_HYS          (45)
#define MUTUAL0_KEY26_HYS          (46)
#define MUTUAL0_KEY27_HYS          (47)
#define MUTUAL0_KEY28_HYS          (48)
#define MUTUAL0_KEY29_HYS          (49)
#define MUTUAL0_KEY30_HYS          (50)
#define MUTUAL0_KEY31_HYS          (51)
#define MUTUAL0_KEY32_HYS          (52)
#define MUTUAL0_KEY33_HYS          (53)
#define MUTUAL0_KEY34_HYS          (54)
#define MUTUAL0_KEY35_HYS          (55)
#define MUTUAL0_KEY36_HYS          (56)
#define MUTUAL0_KEY37_HYS          (57)
#define MUTUAL0_KEY38_HYS          (58)
#define MUTUAL0_KEY39_HYS          (59)
#define MUTUAL0_KEY40_HYS          (60)
#define MUTUAL0_KEY41_HYS          (61)
#define MUTUAL0_KEY42_HYS          (62)
#define MUTUAL0_KEY43_HYS          (63)
#define MUTUAL0_KEY44_HYS          (64)
#define MUTUAL0_KEY45_HYS          (65)
#define MUTUAL0_KEY46_HYS          (66)
#define MUTUAL0_KEY47_HYS          (67)
#define MUTUAL0_KEY48_HYS          (68)
#define MUTUAL0_KEY49_HYS          (69)
#define MUTUAL0_KEY50_HYS          (70)
#define MUTUAL0_KEY51_HYS          (71)
#define MUTUAL0_KEY52_HYS          (72)
#define MUTUAL0_KEY53_HYS          (73)
#define MUTUAL0_KEY54_HYS          (74)
#define MUTUAL0_KEY55_HYS          (75)
#define MUTUAL0_KEY56_HYS          (76)
#define MUTUAL0_KEY57_HYS          (77)
#define MUTUAL0_KEY58_HYS          (78)
#define MUTUAL0_KEY59_HYS          (79)
#define MUTUAL0_KEY60_HYS          (80)
#define MUTUAL0_KEY61_HYS          (81)
#define MUTUAL0_KEY62_HYS          (82)
#define MUTUAL0_KEY63_HYS          (83)

/*====================================================================================================================*/
/*=====    Mutual 1 touch parameter definition    ====================================================================*/
/*====================================================================================================================*/
#define MUTUAL1_KEY00_USE        (0)
#define MUTUAL1_KEY01_USE        (0)
#define MUTUAL1_KEY02_USE        (0)
#define MUTUAL1_KEY03_USE        (0)
#define MUTUAL1_KEY04_USE        (0)
#define MUTUAL1_KEY05_USE        (0)
#define MUTUAL1_KEY06_USE        (0)
#define MUTUAL1_KEY07_USE        (0)
#define MUTUAL1_KEY08_USE        (0)
#define MUTUAL1_KEY09_USE        (0)
#define MUTUAL1_KEY10_USE        (0)
#define MUTUAL1_KEY11_USE        (0)
#define MUTUAL1_KEY12_USE        (0)
#define MUTUAL1_KEY13_USE        (0)
#define MUTUAL1_KEY14_USE        (0)
#define MUTUAL1_KEY15_USE        (0)
#define MUTUAL1_KEY16_USE        (0)
#define MUTUAL1_KEY17_USE        (0)
#define MUTUAL1_KEY18_USE        (0)
#define MUTUAL1_KEY19_USE        (0)
#define MUTUAL1_KEY20_USE        (0)
#define MUTUAL1_KEY21_USE        (0)
#define MUTUAL1_KEY22_USE        (0)
#define MUTUAL1_KEY23_USE        (0)
#define MUTUAL1_KEY24_USE        (0)
#define MUTUAL1_KEY25_USE        (0)
#define MUTUAL1_KEY26_USE        (0)
#define MUTUAL1_KEY27_USE        (0)
#define MUTUAL1_KEY28_USE        (0)
#define MUTUAL1_KEY29_USE        (0)
#define MUTUAL1_KEY30_USE        (0)
#define MUTUAL1_KEY31_USE        (0)
#define MUTUAL1_KEY32_USE        (0)
#define MUTUAL1_KEY33_USE        (0)
#define MUTUAL1_KEY34_USE        (0)
#define MUTUAL1_KEY35_USE        (0)
#define MUTUAL1_KEY36_USE        (0)
#define MUTUAL1_KEY37_USE        (0)
#define MUTUAL1_KEY38_USE        (0)
#define MUTUAL1_KEY39_USE        (0)
#define MUTUAL1_KEY40_USE        (0)
#define MUTUAL1_KEY41_USE        (0)
#define MUTUAL1_KEY42_USE        (0)
#define MUTUAL1_KEY43_USE        (0)
#define MUTUAL1_KEY44_USE        (0)
#define MUTUAL1_KEY45_USE        (0)
#define MUTUAL1_KEY46_USE        (0)
#define MUTUAL1_KEY47_USE        (0)
#define MUTUAL1_KEY48_USE        (0)
#define MUTUAL1_KEY49_USE        (0)
#define MUTUAL1_KEY50_USE        (0)
#define MUTUAL1_KEY51_USE        (0)
#define MUTUAL1_KEY52_USE        (0)
#define MUTUAL1_KEY53_USE        (0)
#define MUTUAL1_KEY54_USE        (0)
#define MUTUAL1_KEY55_USE        (0)
#define MUTUAL1_KEY56_USE        (0)
#define MUTUAL1_KEY57_USE        (0)
#define MUTUAL1_KEY58_USE        (0)
#define MUTUAL1_KEY59_USE        (0)
#define MUTUAL1_KEY60_USE        (0)
#define MUTUAL1_KEY61_USE        (0)
#define MUTUAL1_KEY62_USE        (0)
#define MUTUAL1_KEY63_USE        (0)

#define MUTUAL1_KEY_USE_GROUP0   ((MUTUAL1_KEY00_USE      ) + (MUTUAL1_KEY01_USE <<  1) + (MUTUAL1_KEY02_USE <<  2) + \
                                  (MUTUAL1_KEY03_USE <<  3) + (MUTUAL1_KEY04_USE <<  4) + (MUTUAL1_KEY05_USE <<  5) + \
                                  (MUTUAL1_KEY06_USE <<  6) + (MUTUAL1_KEY07_USE <<  7) + (MUTUAL1_KEY08_USE <<  8) + \
                                  (MUTUAL1_KEY09_USE <<  9) + (MUTUAL1_KEY10_USE << 10) + (MUTUAL1_KEY11_USE << 11) + \
                                  (MUTUAL1_KEY12_USE << 12) + (MUTUAL1_KEY13_USE << 13) + (MUTUAL1_KEY14_USE << 14) + \
                                  (MUTUAL1_KEY15_USE << 15))

#define MUTUAL1_KEY_USE_GROUP1   ((MUTUAL1_KEY16_USE      ) + (MUTUAL1_KEY17_USE <<  1) + (MUTUAL1_KEY18_USE <<  2) + \
                                  (MUTUAL1_KEY19_USE <<  3) + (MUTUAL1_KEY20_USE <<  4) + (MUTUAL1_KEY21_USE <<  5) + \
                                  (MUTUAL1_KEY22_USE <<  6) + (MUTUAL1_KEY23_USE <<  7) + (MUTUAL1_KEY24_USE <<  8) + \
                                  (MUTUAL1_KEY25_USE <<  9) + (MUTUAL1_KEY26_USE << 10) + (MUTUAL1_KEY27_USE << 11) + \
                                  (MUTUAL1_KEY28_USE << 12) + (MUTUAL1_KEY29_USE << 13) + (MUTUAL1_KEY30_USE << 14) + \
                                  (MUTUAL1_KEY31_USE << 15))

#define MUTUAL1_KEY_USE_GROUP2   ((MUTUAL1_KEY32_USE      ) + (MUTUAL1_KEY33_USE <<  1) + (MUTUAL1_KEY34_USE <<  2) + \
                                  (MUTUAL1_KEY35_USE <<  3) + (MUTUAL1_KEY36_USE <<  4) + (MUTUAL1_KEY37_USE <<  5) + \
                                  (MUTUAL1_KEY36_USE <<  6) + (MUTUAL1_KEY39_USE <<  7) + (MUTUAL1_KEY40_USE <<  8) + \
                                  (MUTUAL1_KEY41_USE <<  9) + (MUTUAL1_KEY42_USE << 10) + (MUTUAL1_KEY43_USE << 11) + \
                                  (MUTUAL1_KEY44_USE << 12) + (MUTUAL1_KEY45_USE << 13) + (MUTUAL1_KEY46_USE << 14) + \
                                  (MUTUAL1_KEY47_USE << 15))

#define MUTUAL1_KEY_USE_GROUP3   ((MUTUAL1_KEY48_USE      ) + (MUTUAL1_KEY49_USE <<  1) + (MUTUAL1_KEY50_USE <<  2) + \
                                  (MUTUAL1_KEY51_USE <<  3) + (MUTUAL1_KEY52_USE <<  4) + (MUTUAL1_KEY53_USE <<  5) + \
                                  (MUTUAL1_KEY54_USE <<  6) + (MUTUAL1_KEY55_USE <<  7) + (MUTUAL1_KEY56_USE <<  8) + \
                                  (MUTUAL1_KEY57_USE <<  9) + (MUTUAL1_KEY58_USE << 10) + (MUTUAL1_KEY59_USE << 11) + \
                                  (MUTUAL1_KEY60_USE << 12) + (MUTUAL1_KEY61_USE << 13) + (MUTUAL1_KEY62_USE << 14) + \
                                  (MUTUAL1_KEY63_USE << 15))

#if (MUTUAL1_KEY_USE_GROUP3 > 0)
    #define MUTUAL1_MAX_GROUP        (4)
#elif (MUTUAL1_KEY_USE_GROUP2 > 0)
    #define MUTUAL1_MAX_GROUP        (3)
#elif (MUTUAL1_KEY_USE_GROUP1 > 0)
    #define MUTUAL1_MAX_GROUP        (2)
#else
    #define MUTUAL1_MAX_GROUP        (1)
#endif

#define MUTUAL1_KEY_NUM           (MUTUAL1_KEY00_USE + MUTUAL1_KEY01_USE + MUTUAL1_KEY02_USE + MUTUAL1_KEY03_USE + \
                                   MUTUAL1_KEY04_USE + MUTUAL1_KEY05_USE + MUTUAL1_KEY06_USE + MUTUAL1_KEY07_USE + \
                                   MUTUAL1_KEY08_USE + MUTUAL1_KEY09_USE + MUTUAL1_KEY10_USE + MUTUAL1_KEY11_USE + \
                                   MUTUAL1_KEY12_USE + MUTUAL1_KEY13_USE + MUTUAL1_KEY14_USE + MUTUAL1_KEY15_USE + \
                                   MUTUAL1_KEY16_USE + MUTUAL1_KEY17_USE + MUTUAL1_KEY18_USE + MUTUAL1_KEY19_USE + \
                                   MUTUAL1_KEY20_USE + MUTUAL1_KEY21_USE + MUTUAL1_KEY22_USE + MUTUAL1_KEY23_USE + \
                                   MUTUAL1_KEY24_USE + MUTUAL1_KEY25_USE + MUTUAL1_KEY26_USE + MUTUAL1_KEY27_USE + \
                                   MUTUAL1_KEY28_USE + MUTUAL1_KEY29_USE + MUTUAL1_KEY30_USE + MUTUAL1_KEY31_USE + \
                                   MUTUAL1_KEY32_USE + MUTUAL1_KEY33_USE + MUTUAL1_KEY34_USE + MUTUAL1_KEY35_USE + \
                                   MUTUAL1_KEY36_USE + MUTUAL1_KEY37_USE + MUTUAL1_KEY38_USE + MUTUAL1_KEY39_USE + \
                                   MUTUAL1_KEY40_USE + MUTUAL1_KEY41_USE + MUTUAL1_KEY42_USE + MUTUAL1_KEY43_USE + \
                                   MUTUAL1_KEY44_USE + MUTUAL1_KEY45_USE + MUTUAL1_KEY46_USE + MUTUAL1_KEY47_USE + \
                                   MUTUAL1_KEY48_USE + MUTUAL1_KEY49_USE + MUTUAL1_KEY50_USE + MUTUAL1_KEY51_USE + \
                                   MUTUAL1_KEY52_USE + MUTUAL1_KEY53_USE + MUTUAL1_KEY54_USE + MUTUAL1_KEY55_USE + \
                                   MUTUAL1_KEY56_USE + MUTUAL1_KEY57_USE + MUTUAL1_KEY58_USE + MUTUAL1_KEY59_USE + \
                                   MUTUAL1_KEY60_USE + MUTUAL1_KEY61_USE + MUTUAL1_KEY62_USE + MUTUAL1_KEY63_USE)

/* ON/OFF threshold set up data */
#define MUTUAL1_KEY00_THR          (1000)
#define MUTUAL1_KEY01_THR          (1001)
#define MUTUAL1_KEY02_THR          (1002)
#define MUTUAL1_KEY03_THR          (1003)
#define MUTUAL1_KEY04_THR          (1004)
#define MUTUAL1_KEY05_THR          (1005)
#define MUTUAL1_KEY06_THR          (1006)
#define MUTUAL1_KEY07_THR          (1007)
#define MUTUAL1_KEY08_THR          (1008)
#define MUTUAL1_KEY09_THR          (1009)
#define MUTUAL1_KEY10_THR          (1010)
#define MUTUAL1_KEY11_THR          (1011)
#define MUTUAL1_KEY12_THR          (1012)
#define MUTUAL1_KEY13_THR          (1013)
#define MUTUAL1_KEY14_THR          (1014)
#define MUTUAL1_KEY15_THR          (1015)
#define MUTUAL1_KEY16_THR          (1016)
#define MUTUAL1_KEY17_THR          (1017)
#define MUTUAL1_KEY18_THR          (1018)
#define MUTUAL1_KEY19_THR          (1019)
#define MUTUAL1_KEY20_THR          (1020)
#define MUTUAL1_KEY21_THR          (1021)
#define MUTUAL1_KEY22_THR          (1022)
#define MUTUAL1_KEY23_THR          (1023)
#define MUTUAL1_KEY24_THR          (1024)
#define MUTUAL1_KEY25_THR          (1025)
#define MUTUAL1_KEY26_THR          (1026)
#define MUTUAL1_KEY27_THR          (1027)
#define MUTUAL1_KEY28_THR          (1028)
#define MUTUAL1_KEY29_THR          (1029)
#define MUTUAL1_KEY30_THR          (1030)
#define MUTUAL1_KEY31_THR          (1031)
#define MUTUAL1_KEY32_THR          (1032)
#define MUTUAL1_KEY33_THR          (1033)
#define MUTUAL1_KEY34_THR          (1034)
#define MUTUAL1_KEY35_THR          (1035)
#define MUTUAL1_KEY36_THR          (1036)
#define MUTUAL1_KEY37_THR          (1037)
#define MUTUAL1_KEY38_THR          (1038)
#define MUTUAL1_KEY39_THR          (1039)
#define MUTUAL1_KEY40_THR          (1040)
#define MUTUAL1_KEY41_THR          (1041)
#define MUTUAL1_KEY42_THR          (1042)
#define MUTUAL1_KEY43_THR          (1043)
#define MUTUAL1_KEY44_THR          (1044)
#define MUTUAL1_KEY45_THR          (1045)
#define MUTUAL1_KEY46_THR          (1046)
#define MUTUAL1_KEY47_THR          (1047)
#define MUTUAL1_KEY48_THR          (1048)
#define MUTUAL1_KEY49_THR          (1049)
#define MUTUAL1_KEY50_THR          (1050)
#define MUTUAL1_KEY51_THR          (1051)
#define MUTUAL1_KEY52_THR          (1052)
#define MUTUAL1_KEY53_THR          (1053)
#define MUTUAL1_KEY54_THR          (1054)
#define MUTUAL1_KEY55_THR          (1055)
#define MUTUAL1_KEY56_THR          (1056)
#define MUTUAL1_KEY57_THR          (1057)
#define MUTUAL1_KEY58_THR          (1058)
#define MUTUAL1_KEY59_THR          (1059)
#define MUTUAL1_KEY60_THR          (1060)
#define MUTUAL1_KEY61_THR          (1061)
#define MUTUAL1_KEY62_THR          (1062)
#define MUTUAL1_KEY63_THR          (1063)

/* Hysteresis set up data */
#define MUTUAL1_KEY00_HYS          (20)
#define MUTUAL1_KEY01_HYS          (21)
#define MUTUAL1_KEY02_HYS          (22)
#define MUTUAL1_KEY03_HYS          (23)
#define MUTUAL1_KEY04_HYS          (24)
#define MUTUAL1_KEY05_HYS          (25)
#define MUTUAL1_KEY06_HYS          (26)
#define MUTUAL1_KEY07_HYS          (27)
#define MUTUAL1_KEY08_HYS          (28)
#define MUTUAL1_KEY09_HYS          (29)
#define MUTUAL1_KEY10_HYS          (30)
#define MUTUAL1_KEY11_HYS          (31)
#define MUTUAL1_KEY12_HYS          (32)
#define MUTUAL1_KEY13_HYS          (33)
#define MUTUAL1_KEY14_HYS          (34)
#define MUTUAL1_KEY15_HYS          (35)
#define MUTUAL1_KEY16_HYS          (36)
#define MUTUAL1_KEY17_HYS          (37)
#define MUTUAL1_KEY18_HYS          (38)
#define MUTUAL1_KEY19_HYS          (39)
#define MUTUAL1_KEY20_HYS          (40)
#define MUTUAL1_KEY21_HYS          (41)
#define MUTUAL1_KEY22_HYS          (42)
#define MUTUAL1_KEY23_HYS          (43)
#define MUTUAL1_KEY24_HYS          (44)
#define MUTUAL1_KEY25_HYS          (45)
#define MUTUAL1_KEY26_HYS          (46)
#define MUTUAL1_KEY27_HYS          (47)
#define MUTUAL1_KEY28_HYS          (48)
#define MUTUAL1_KEY29_HYS          (49)
#define MUTUAL1_KEY30_HYS          (50)
#define MUTUAL1_KEY31_HYS          (51)
#define MUTUAL1_KEY32_HYS          (52)
#define MUTUAL1_KEY33_HYS          (53)
#define MUTUAL1_KEY34_HYS          (54)
#define MUTUAL1_KEY35_HYS          (55)
#define MUTUAL1_KEY36_HYS          (56)
#define MUTUAL1_KEY37_HYS          (57)
#define MUTUAL1_KEY38_HYS          (58)
#define MUTUAL1_KEY39_HYS          (59)
#define MUTUAL1_KEY40_HYS          (60)
#define MUTUAL1_KEY41_HYS          (61)
#define MUTUAL1_KEY42_HYS          (62)
#define MUTUAL1_KEY43_HYS          (63)
#define MUTUAL1_KEY44_HYS          (64)
#define MUTUAL1_KEY45_HYS          (65)
#define MUTUAL1_KEY46_HYS          (66)
#define MUTUAL1_KEY47_HYS          (67)
#define MUTUAL1_KEY48_HYS          (68)
#define MUTUAL1_KEY49_HYS          (69)
#define MUTUAL1_KEY50_HYS          (70)
#define MUTUAL1_KEY51_HYS          (71)
#define MUTUAL1_KEY52_HYS          (72)
#define MUTUAL1_KEY53_HYS          (73)
#define MUTUAL1_KEY54_HYS          (74)
#define MUTUAL1_KEY55_HYS          (75)
#define MUTUAL1_KEY56_HYS          (76)
#define MUTUAL1_KEY57_HYS          (77)
#define MUTUAL1_KEY58_HYS          (78)
#define MUTUAL1_KEY59_HYS          (79)
#define MUTUAL1_KEY60_HYS          (80)
#define MUTUAL1_KEY61_HYS          (81)
#define MUTUAL1_KEY62_HYS          (82)
#define MUTUAL1_KEY63_HYS          (83)

/*====================================================================================================================*/
/*=====    Mutual 2 touch parameter definition    ====================================================================*/
/*====================================================================================================================*/
#define MUTUAL2_KEY00_USE        (0)
#define MUTUAL2_KEY01_USE        (0)
#define MUTUAL2_KEY02_USE        (0)
#define MUTUAL2_KEY03_USE        (0)
#define MUTUAL2_KEY04_USE        (0)
#define MUTUAL2_KEY05_USE        (0)
#define MUTUAL2_KEY06_USE        (0)
#define MUTUAL2_KEY07_USE        (0)
#define MUTUAL2_KEY08_USE        (0)
#define MUTUAL2_KEY09_USE        (0)
#define MUTUAL2_KEY10_USE        (0)
#define MUTUAL2_KEY11_USE        (0)
#define MUTUAL2_KEY12_USE        (0)
#define MUTUAL2_KEY13_USE        (0)
#define MUTUAL2_KEY14_USE        (0)
#define MUTUAL2_KEY15_USE        (0)
#define MUTUAL2_KEY16_USE        (0)
#define MUTUAL2_KEY17_USE        (0)
#define MUTUAL2_KEY18_USE        (0)
#define MUTUAL2_KEY19_USE        (0)
#define MUTUAL2_KEY20_USE        (0)
#define MUTUAL2_KEY21_USE        (0)
#define MUTUAL2_KEY22_USE        (0)
#define MUTUAL2_KEY23_USE        (0)
#define MUTUAL2_KEY24_USE        (0)
#define MUTUAL2_KEY25_USE        (0)
#define MUTUAL2_KEY26_USE        (0)
#define MUTUAL2_KEY27_USE        (0)
#define MUTUAL2_KEY28_USE        (0)
#define MUTUAL2_KEY29_USE        (0)
#define MUTUAL2_KEY30_USE        (0)
#define MUTUAL2_KEY31_USE        (0)
#define MUTUAL2_KEY32_USE        (0)
#define MUTUAL2_KEY33_USE        (0)
#define MUTUAL2_KEY34_USE        (0)
#define MUTUAL2_KEY35_USE        (0)
#define MUTUAL2_KEY36_USE        (0)
#define MUTUAL2_KEY37_USE        (0)
#define MUTUAL2_KEY38_USE        (0)
#define MUTUAL2_KEY39_USE        (0)
#define MUTUAL2_KEY40_USE        (0)
#define MUTUAL2_KEY41_USE        (0)
#define MUTUAL2_KEY42_USE        (0)
#define MUTUAL2_KEY43_USE        (0)
#define MUTUAL2_KEY44_USE        (0)
#define MUTUAL2_KEY45_USE        (0)
#define MUTUAL2_KEY46_USE        (0)
#define MUTUAL2_KEY47_USE        (0)
#define MUTUAL2_KEY48_USE        (0)
#define MUTUAL2_KEY49_USE        (0)
#define MUTUAL2_KEY50_USE        (0)
#define MUTUAL2_KEY51_USE        (0)
#define MUTUAL2_KEY52_USE        (0)
#define MUTUAL2_KEY53_USE        (0)
#define MUTUAL2_KEY54_USE        (0)
#define MUTUAL2_KEY55_USE        (0)
#define MUTUAL2_KEY56_USE        (0)
#define MUTUAL2_KEY57_USE        (0)
#define MUTUAL2_KEY58_USE        (0)
#define MUTUAL2_KEY59_USE        (0)
#define MUTUAL2_KEY60_USE        (0)
#define MUTUAL2_KEY61_USE        (0)
#define MUTUAL2_KEY62_USE        (0)
#define MUTUAL2_KEY63_USE        (0)

#define MUTUAL2_KEY_USE_GROUP0   ((MUTUAL2_KEY00_USE      ) + (MUTUAL2_KEY01_USE <<  1) + (MUTUAL2_KEY02_USE <<  2) + \
                                  (MUTUAL2_KEY03_USE <<  3) + (MUTUAL2_KEY04_USE <<  4) + (MUTUAL2_KEY05_USE <<  5) + \
                                  (MUTUAL2_KEY06_USE <<  6) + (MUTUAL2_KEY07_USE <<  7) + (MUTUAL2_KEY08_USE <<  8) + \
                                  (MUTUAL2_KEY09_USE <<  9) + (MUTUAL2_KEY10_USE << 10) + (MUTUAL2_KEY11_USE << 11) + \
                                  (MUTUAL2_KEY12_USE << 12) + (MUTUAL2_KEY13_USE << 13) + (MUTUAL2_KEY14_USE << 14) + \
                                  (MUTUAL2_KEY15_USE << 15))

#define MUTUAL2_KEY_USE_GROUP1   ((MUTUAL2_KEY16_USE      ) + (MUTUAL2_KEY17_USE <<  1) + (MUTUAL2_KEY18_USE <<  2) + \
                                  (MUTUAL2_KEY19_USE <<  3) + (MUTUAL2_KEY20_USE <<  4) + (MUTUAL2_KEY21_USE <<  5) + \
                                  (MUTUAL2_KEY22_USE <<  6) + (MUTUAL2_KEY23_USE <<  7) + (MUTUAL2_KEY24_USE <<  8) + \
                                  (MUTUAL2_KEY25_USE <<  9) + (MUTUAL2_KEY26_USE << 10) + (MUTUAL2_KEY27_USE << 11) + \
                                  (MUTUAL2_KEY28_USE << 12) + (MUTUAL2_KEY29_USE << 13) + (MUTUAL2_KEY30_USE << 14) + \
                                  (MUTUAL2_KEY31_USE << 15))

#define MUTUAL2_KEY_USE_GROUP2   ((MUTUAL2_KEY32_USE      ) + (MUTUAL2_KEY33_USE <<  1) + (MUTUAL2_KEY34_USE <<  2) + \
                                  (MUTUAL2_KEY35_USE <<  3) + (MUTUAL2_KEY36_USE <<  4) + (MUTUAL2_KEY37_USE <<  5) + \
                                  (MUTUAL2_KEY36_USE <<  6) + (MUTUAL2_KEY39_USE <<  7) + (MUTUAL2_KEY40_USE <<  8) + \
                                  (MUTUAL2_KEY41_USE <<  9) + (MUTUAL2_KEY42_USE << 10) + (MUTUAL2_KEY43_USE << 11) + \
                                  (MUTUAL2_KEY44_USE << 12) + (MUTUAL2_KEY45_USE << 13) + (MUTUAL2_KEY46_USE << 14) + \
                                  (MUTUAL2_KEY47_USE << 15))

#define MUTUAL2_KEY_USE_GROUP3   ((MUTUAL2_KEY48_USE      ) + (MUTUAL2_KEY49_USE <<  1) + (MUTUAL2_KEY50_USE <<  2) + \
                                  (MUTUAL2_KEY51_USE <<  3) + (MUTUAL2_KEY52_USE <<  4) + (MUTUAL2_KEY53_USE <<  5) + \
                                  (MUTUAL2_KEY54_USE <<  6) + (MUTUAL2_KEY55_USE <<  7) + (MUTUAL2_KEY56_USE <<  8) + \
                                  (MUTUAL2_KEY57_USE <<  9) + (MUTUAL2_KEY58_USE << 10) + (MUTUAL2_KEY59_USE << 11) + \
                                  (MUTUAL2_KEY60_USE << 12) + (MUTUAL2_KEY61_USE << 13) + (MUTUAL2_KEY62_USE << 14) + \
                                  (MUTUAL2_KEY63_USE << 15))

#if (MUTUAL2_KEY_USE_GROUP3 > 0)
    #define MUTUAL2_MAX_GROUP        (4)
#elif (MUTUAL2_KEY_USE_GROUP2 > 0)
    #define MUTUAL2_MAX_GROUP        (3)
#elif (MUTUAL2_KEY_USE_GROUP1 > 0)
    #define MUTUAL2_MAX_GROUP        (2)
#else
    #define MUTUAL2_MAX_GROUP        (1)
#endif

#define MUTUAL2_KEY_NUM           (MUTUAL2_KEY00_USE + MUTUAL2_KEY01_USE + MUTUAL2_KEY02_USE + MUTUAL2_KEY03_USE + \
                                   MUTUAL2_KEY04_USE + MUTUAL2_KEY05_USE + MUTUAL2_KEY06_USE + MUTUAL2_KEY07_USE + \
                                   MUTUAL2_KEY08_USE + MUTUAL2_KEY09_USE + MUTUAL2_KEY10_USE + MUTUAL2_KEY11_USE + \
                                   MUTUAL2_KEY12_USE + MUTUAL2_KEY13_USE + MUTUAL2_KEY14_USE + MUTUAL2_KEY15_USE + \
                                   MUTUAL2_KEY16_USE + MUTUAL2_KEY17_USE + MUTUAL2_KEY18_USE + MUTUAL2_KEY19_USE + \
                                   MUTUAL2_KEY20_USE + MUTUAL2_KEY21_USE + MUTUAL2_KEY22_USE + MUTUAL2_KEY23_USE + \
                                   MUTUAL2_KEY24_USE + MUTUAL2_KEY25_USE + MUTUAL2_KEY26_USE + MUTUAL2_KEY27_USE + \
                                   MUTUAL2_KEY28_USE + MUTUAL2_KEY29_USE + MUTUAL2_KEY30_USE + MUTUAL2_KEY31_USE + \
                                   MUTUAL2_KEY32_USE + MUTUAL2_KEY33_USE + MUTUAL2_KEY34_USE + MUTUAL2_KEY35_USE + \
                                   MUTUAL2_KEY36_USE + MUTUAL2_KEY37_USE + MUTUAL2_KEY38_USE + MUTUAL2_KEY39_USE + \
                                   MUTUAL2_KEY40_USE + MUTUAL2_KEY41_USE + MUTUAL2_KEY42_USE + MUTUAL2_KEY43_USE + \
                                   MUTUAL2_KEY44_USE + MUTUAL2_KEY45_USE + MUTUAL2_KEY46_USE + MUTUAL2_KEY47_USE + \
                                   MUTUAL2_KEY48_USE + MUTUAL2_KEY49_USE + MUTUAL2_KEY50_USE + MUTUAL2_KEY51_USE + \
                                   MUTUAL2_KEY52_USE + MUTUAL2_KEY53_USE + MUTUAL2_KEY54_USE + MUTUAL2_KEY55_USE + \
                                   MUTUAL2_KEY56_USE + MUTUAL2_KEY57_USE + MUTUAL2_KEY58_USE + MUTUAL2_KEY59_USE + \
                                   MUTUAL2_KEY60_USE + MUTUAL2_KEY61_USE + MUTUAL2_KEY62_USE + MUTUAL2_KEY63_USE)

/* ON/OFF threshold set up data */
#define MUTUAL2_KEY00_THR          (1000)
#define MUTUAL2_KEY01_THR          (1001)
#define MUTUAL2_KEY02_THR          (1002)
#define MUTUAL2_KEY03_THR          (1003)
#define MUTUAL2_KEY04_THR          (1004)
#define MUTUAL2_KEY05_THR          (1005)
#define MUTUAL2_KEY06_THR          (1006)
#define MUTUAL2_KEY07_THR          (1007)
#define MUTUAL2_KEY08_THR          (1008)
#define MUTUAL2_KEY09_THR          (1009)
#define MUTUAL2_KEY10_THR          (1010)
#define MUTUAL2_KEY11_THR          (1011)
#define MUTUAL2_KEY12_THR          (1012)
#define MUTUAL2_KEY13_THR          (1013)
#define MUTUAL2_KEY14_THR          (1014)
#define MUTUAL2_KEY15_THR          (1015)
#define MUTUAL2_KEY16_THR          (1016)
#define MUTUAL2_KEY17_THR          (1017)
#define MUTUAL2_KEY18_THR          (1018)
#define MUTUAL2_KEY19_THR          (1019)
#define MUTUAL2_KEY20_THR          (1020)
#define MUTUAL2_KEY21_THR          (1021)
#define MUTUAL2_KEY22_THR          (1022)
#define MUTUAL2_KEY23_THR          (1023)
#define MUTUAL2_KEY24_THR          (1024)
#define MUTUAL2_KEY25_THR          (1025)
#define MUTUAL2_KEY26_THR          (1026)
#define MUTUAL2_KEY27_THR          (1027)
#define MUTUAL2_KEY28_THR          (1028)
#define MUTUAL2_KEY29_THR          (1029)
#define MUTUAL2_KEY30_THR          (1030)
#define MUTUAL2_KEY31_THR          (1031)
#define MUTUAL2_KEY32_THR          (1032)
#define MUTUAL2_KEY33_THR          (1033)
#define MUTUAL2_KEY34_THR          (1034)
#define MUTUAL2_KEY35_THR          (1035)
#define MUTUAL2_KEY36_THR          (1036)
#define MUTUAL2_KEY37_THR          (1037)
#define MUTUAL2_KEY38_THR          (1038)
#define MUTUAL2_KEY39_THR          (1039)
#define MUTUAL2_KEY40_THR          (1040)
#define MUTUAL2_KEY41_THR          (1041)
#define MUTUAL2_KEY42_THR          (1042)
#define MUTUAL2_KEY43_THR          (1043)
#define MUTUAL2_KEY44_THR          (1044)
#define MUTUAL2_KEY45_THR          (1045)
#define MUTUAL2_KEY46_THR          (1046)
#define MUTUAL2_KEY47_THR          (1047)
#define MUTUAL2_KEY48_THR          (1048)
#define MUTUAL2_KEY49_THR          (1049)
#define MUTUAL2_KEY50_THR          (1050)
#define MUTUAL2_KEY51_THR          (1051)
#define MUTUAL2_KEY52_THR          (1052)
#define MUTUAL2_KEY53_THR          (1053)
#define MUTUAL2_KEY54_THR          (1054)
#define MUTUAL2_KEY55_THR          (1055)
#define MUTUAL2_KEY56_THR          (1056)
#define MUTUAL2_KEY57_THR          (1057)
#define MUTUAL2_KEY58_THR          (1058)
#define MUTUAL2_KEY59_THR          (1059)
#define MUTUAL2_KEY60_THR          (1060)
#define MUTUAL2_KEY61_THR          (1061)
#define MUTUAL2_KEY62_THR          (1062)
#define MUTUAL2_KEY63_THR          (1063)

/* Hysteresis set up data */
#define MUTUAL2_KEY00_HYS          (20)
#define MUTUAL2_KEY01_HYS          (21)
#define MUTUAL2_KEY02_HYS          (22)
#define MUTUAL2_KEY03_HYS          (23)
#define MUTUAL2_KEY04_HYS          (24)
#define MUTUAL2_KEY05_HYS          (25)
#define MUTUAL2_KEY06_HYS          (26)
#define MUTUAL2_KEY07_HYS          (27)
#define MUTUAL2_KEY08_HYS          (28)
#define MUTUAL2_KEY09_HYS          (29)
#define MUTUAL2_KEY10_HYS          (30)
#define MUTUAL2_KEY11_HYS          (31)
#define MUTUAL2_KEY12_HYS          (32)
#define MUTUAL2_KEY13_HYS          (33)
#define MUTUAL2_KEY14_HYS          (34)
#define MUTUAL2_KEY15_HYS          (35)
#define MUTUAL2_KEY16_HYS          (36)
#define MUTUAL2_KEY17_HYS          (37)
#define MUTUAL2_KEY18_HYS          (38)
#define MUTUAL2_KEY19_HYS          (39)
#define MUTUAL2_KEY20_HYS          (40)
#define MUTUAL2_KEY21_HYS          (41)
#define MUTUAL2_KEY22_HYS          (42)
#define MUTUAL2_KEY23_HYS          (43)
#define MUTUAL2_KEY24_HYS          (44)
#define MUTUAL2_KEY25_HYS          (45)
#define MUTUAL2_KEY26_HYS          (46)
#define MUTUAL2_KEY27_HYS          (47)
#define MUTUAL2_KEY28_HYS          (48)
#define MUTUAL2_KEY29_HYS          (49)
#define MUTUAL2_KEY30_HYS          (50)
#define MUTUAL2_KEY31_HYS          (51)
#define MUTUAL2_KEY32_HYS          (52)
#define MUTUAL2_KEY33_HYS          (53)
#define MUTUAL2_KEY34_HYS          (54)
#define MUTUAL2_KEY35_HYS          (55)
#define MUTUAL2_KEY36_HYS          (56)
#define MUTUAL2_KEY37_HYS          (57)
#define MUTUAL2_KEY38_HYS          (58)
#define MUTUAL2_KEY39_HYS          (59)
#define MUTUAL2_KEY40_HYS          (60)
#define MUTUAL2_KEY41_HYS          (61)
#define MUTUAL2_KEY42_HYS          (62)
#define MUTUAL2_KEY43_HYS          (63)
#define MUTUAL2_KEY44_HYS          (64)
#define MUTUAL2_KEY45_HYS          (65)
#define MUTUAL2_KEY46_HYS          (66)
#define MUTUAL2_KEY47_HYS          (67)
#define MUTUAL2_KEY48_HYS          (68)
#define MUTUAL2_KEY49_HYS          (69)
#define MUTUAL2_KEY50_HYS          (70)
#define MUTUAL2_KEY51_HYS          (71)
#define MUTUAL2_KEY52_HYS          (72)
#define MUTUAL2_KEY53_HYS          (73)
#define MUTUAL2_KEY54_HYS          (74)
#define MUTUAL2_KEY55_HYS          (75)
#define MUTUAL2_KEY56_HYS          (76)
#define MUTUAL2_KEY57_HYS          (77)
#define MUTUAL2_KEY58_HYS          (78)
#define MUTUAL2_KEY59_HYS          (79)
#define MUTUAL2_KEY60_HYS          (80)
#define MUTUAL2_KEY61_HYS          (81)
#define MUTUAL2_KEY62_HYS          (82)
#define MUTUAL2_KEY63_HYS          (83)

/*====================================================================================================================*/
/*=====    Mutual 3 touch parameter definition    ====================================================================*/
/*====================================================================================================================*/
#define MUTUAL3_KEY00_USE        (0)
#define MUTUAL3_KEY01_USE        (0)
#define MUTUAL3_KEY02_USE        (0)
#define MUTUAL3_KEY03_USE        (0)
#define MUTUAL3_KEY04_USE        (0)
#define MUTUAL3_KEY05_USE        (0)
#define MUTUAL3_KEY06_USE        (0)
#define MUTUAL3_KEY07_USE        (0)
#define MUTUAL3_KEY08_USE        (0)
#define MUTUAL3_KEY09_USE        (0)
#define MUTUAL3_KEY10_USE        (0)
#define MUTUAL3_KEY11_USE        (0)
#define MUTUAL3_KEY12_USE        (0)
#define MUTUAL3_KEY13_USE        (0)
#define MUTUAL3_KEY14_USE        (0)
#define MUTUAL3_KEY15_USE        (0)
#define MUTUAL3_KEY16_USE        (0)
#define MUTUAL3_KEY17_USE        (0)
#define MUTUAL3_KEY18_USE        (0)
#define MUTUAL3_KEY19_USE        (0)
#define MUTUAL3_KEY20_USE        (0)
#define MUTUAL3_KEY21_USE        (0)
#define MUTUAL3_KEY22_USE        (0)
#define MUTUAL3_KEY23_USE        (0)
#define MUTUAL3_KEY24_USE        (0)
#define MUTUAL3_KEY25_USE        (0)
#define MUTUAL3_KEY26_USE        (0)
#define MUTUAL3_KEY27_USE        (0)
#define MUTUAL3_KEY28_USE        (0)
#define MUTUAL3_KEY29_USE        (0)
#define MUTUAL3_KEY30_USE        (0)
#define MUTUAL3_KEY31_USE        (0)
#define MUTUAL3_KEY32_USE        (0)
#define MUTUAL3_KEY33_USE        (0)
#define MUTUAL3_KEY34_USE        (0)
#define MUTUAL3_KEY35_USE        (0)
#define MUTUAL3_KEY36_USE        (0)
#define MUTUAL3_KEY37_USE        (0)
#define MUTUAL3_KEY38_USE        (0)
#define MUTUAL3_KEY39_USE        (0)
#define MUTUAL3_KEY40_USE        (0)
#define MUTUAL3_KEY41_USE        (0)
#define MUTUAL3_KEY42_USE        (0)
#define MUTUAL3_KEY43_USE        (0)
#define MUTUAL3_KEY44_USE        (0)
#define MUTUAL3_KEY45_USE        (0)
#define MUTUAL3_KEY46_USE        (0)
#define MUTUAL3_KEY47_USE        (0)
#define MUTUAL3_KEY48_USE        (0)
#define MUTUAL3_KEY49_USE        (0)
#define MUTUAL3_KEY50_USE        (0)
#define MUTUAL3_KEY51_USE        (0)
#define MUTUAL3_KEY52_USE        (0)
#define MUTUAL3_KEY53_USE        (0)
#define MUTUAL3_KEY54_USE        (0)
#define MUTUAL3_KEY55_USE        (0)
#define MUTUAL3_KEY56_USE        (0)
#define MUTUAL3_KEY57_USE        (0)
#define MUTUAL3_KEY58_USE        (0)
#define MUTUAL3_KEY59_USE        (0)
#define MUTUAL3_KEY60_USE        (0)
#define MUTUAL3_KEY61_USE        (0)
#define MUTUAL3_KEY62_USE        (0)
#define MUTUAL3_KEY63_USE        (0)

#define MUTUAL3_KEY_USE_GROUP0   ((MUTUAL3_KEY00_USE      ) + (MUTUAL3_KEY01_USE <<  1) + (MUTUAL3_KEY02_USE <<  2) + \
                                  (MUTUAL3_KEY03_USE <<  3) + (MUTUAL3_KEY04_USE <<  4) + (MUTUAL3_KEY05_USE <<  5) + \
                                  (MUTUAL3_KEY06_USE <<  6) + (MUTUAL3_KEY07_USE <<  7) + (MUTUAL3_KEY08_USE <<  8) + \
                                  (MUTUAL3_KEY09_USE <<  9) + (MUTUAL3_KEY10_USE << 10) + (MUTUAL3_KEY11_USE << 11) + \
                                  (MUTUAL3_KEY12_USE << 12) + (MUTUAL3_KEY13_USE << 13) + (MUTUAL3_KEY14_USE << 14) + \
                                  (MUTUAL3_KEY15_USE << 15))

#define MUTUAL3_KEY_USE_GROUP1   ((MUTUAL3_KEY16_USE      ) + (MUTUAL3_KEY17_USE <<  1) + (MUTUAL3_KEY18_USE <<  2) + \
                                  (MUTUAL3_KEY19_USE <<  3) + (MUTUAL3_KEY20_USE <<  4) + (MUTUAL3_KEY21_USE <<  5) + \
                                  (MUTUAL3_KEY22_USE <<  6) + (MUTUAL3_KEY23_USE <<  7) + (MUTUAL3_KEY24_USE <<  8) + \
                                  (MUTUAL3_KEY25_USE <<  9) + (MUTUAL3_KEY26_USE << 10) + (MUTUAL3_KEY27_USE << 11) + \
                                  (MUTUAL3_KEY28_USE << 12) + (MUTUAL3_KEY29_USE << 13) + (MUTUAL3_KEY30_USE << 14) + \
                                  (MUTUAL3_KEY31_USE << 15))

#define MUTUAL3_KEY_USE_GROUP2   ((MUTUAL3_KEY32_USE      ) + (MUTUAL3_KEY33_USE <<  1) + (MUTUAL3_KEY34_USE <<  2) + \
                                  (MUTUAL3_KEY35_USE <<  3) + (MUTUAL3_KEY36_USE <<  4) + (MUTUAL3_KEY37_USE <<  5) + \
                                  (MUTUAL3_KEY36_USE <<  6) + (MUTUAL3_KEY39_USE <<  7) + (MUTUAL3_KEY40_USE <<  8) + \
                                  (MUTUAL3_KEY41_USE <<  9) + (MUTUAL3_KEY42_USE << 10) + (MUTUAL3_KEY43_USE << 11) + \
                                  (MUTUAL3_KEY44_USE << 12) + (MUTUAL3_KEY45_USE << 13) + (MUTUAL3_KEY46_USE << 14) + \
                                  (MUTUAL3_KEY47_USE << 15))

#define MUTUAL3_KEY_USE_GROUP3   ((MUTUAL3_KEY48_USE      ) + (MUTUAL3_KEY49_USE <<  1) + (MUTUAL3_KEY50_USE <<  2) + \
                                  (MUTUAL3_KEY51_USE <<  3) + (MUTUAL3_KEY52_USE <<  4) + (MUTUAL3_KEY53_USE <<  5) + \
                                  (MUTUAL3_KEY54_USE <<  6) + (MUTUAL3_KEY55_USE <<  7) + (MUTUAL3_KEY56_USE <<  8) + \
                                  (MUTUAL3_KEY57_USE <<  9) + (MUTUAL3_KEY58_USE << 10) + (MUTUAL3_KEY59_USE << 11) + \
                                  (MUTUAL3_KEY60_USE << 12) + (MUTUAL3_KEY61_USE << 13) + (MUTUAL3_KEY62_USE << 14) + \
                                  (MUTUAL3_KEY63_USE << 15))

#if (MUTUAL3_KEY_USE_GROUP3 > 0)
    #define MUTUAL3_MAX_GROUP        (4)
#elif (MUTUAL3_KEY_USE_GROUP2 > 0)
    #define MUTUAL3_MAX_GROUP        (3)
#elif (MUTUAL3_KEY_USE_GROUP1 > 0)
    #define MUTUAL3_MAX_GROUP        (2)
#else
    #define MUTUAL3_MAX_GROUP        (1)
#endif

#define MUTUAL3_KEY_NUM           (MUTUAL3_KEY00_USE + MUTUAL3_KEY01_USE + MUTUAL3_KEY02_USE + MUTUAL3_KEY03_USE + \
                                   MUTUAL3_KEY04_USE + MUTUAL3_KEY05_USE + MUTUAL3_KEY06_USE + MUTUAL3_KEY07_USE + \
                                   MUTUAL3_KEY08_USE + MUTUAL3_KEY09_USE + MUTUAL3_KEY10_USE + MUTUAL3_KEY11_USE + \
                                   MUTUAL3_KEY12_USE + MUTUAL3_KEY13_USE + MUTUAL3_KEY14_USE + MUTUAL3_KEY15_USE + \
                                   MUTUAL3_KEY16_USE + MUTUAL3_KEY17_USE + MUTUAL3_KEY18_USE + MUTUAL3_KEY19_USE + \
                                   MUTUAL3_KEY20_USE + MUTUAL3_KEY21_USE + MUTUAL3_KEY22_USE + MUTUAL3_KEY23_USE + \
                                   MUTUAL3_KEY24_USE + MUTUAL3_KEY25_USE + MUTUAL3_KEY26_USE + MUTUAL3_KEY27_USE + \
                                   MUTUAL3_KEY28_USE + MUTUAL3_KEY29_USE + MUTUAL3_KEY30_USE + MUTUAL3_KEY31_USE + \
                                   MUTUAL3_KEY32_USE + MUTUAL3_KEY33_USE + MUTUAL3_KEY34_USE + MUTUAL3_KEY35_USE + \
                                   MUTUAL3_KEY36_USE + MUTUAL3_KEY37_USE + MUTUAL3_KEY38_USE + MUTUAL3_KEY39_USE + \
                                   MUTUAL3_KEY40_USE + MUTUAL3_KEY41_USE + MUTUAL3_KEY42_USE + MUTUAL3_KEY43_USE + \
                                   MUTUAL3_KEY44_USE + MUTUAL3_KEY45_USE + MUTUAL3_KEY46_USE + MUTUAL3_KEY47_USE + \
                                   MUTUAL3_KEY48_USE + MUTUAL3_KEY49_USE + MUTUAL3_KEY50_USE + MUTUAL3_KEY51_USE + \
                                   MUTUAL3_KEY52_USE + MUTUAL3_KEY53_USE + MUTUAL3_KEY54_USE + MUTUAL3_KEY55_USE + \
                                   MUTUAL3_KEY56_USE + MUTUAL3_KEY57_USE + MUTUAL3_KEY58_USE + MUTUAL3_KEY59_USE + \
                                   MUTUAL3_KEY60_USE + MUTUAL3_KEY61_USE + MUTUAL3_KEY62_USE + MUTUAL3_KEY63_USE)

/* ON/OFF threshold set up data */
#define MUTUAL3_KEY00_THR          (1000)
#define MUTUAL3_KEY01_THR          (1001)
#define MUTUAL3_KEY02_THR          (1002)
#define MUTUAL3_KEY03_THR          (1003)
#define MUTUAL3_KEY04_THR          (1004)
#define MUTUAL3_KEY05_THR          (1005)
#define MUTUAL3_KEY06_THR          (1006)
#define MUTUAL3_KEY07_THR          (1007)
#define MUTUAL3_KEY08_THR          (1008)
#define MUTUAL3_KEY09_THR          (1009)
#define MUTUAL3_KEY10_THR          (1010)
#define MUTUAL3_KEY11_THR          (1011)
#define MUTUAL3_KEY12_THR          (1012)
#define MUTUAL3_KEY13_THR          (1013)
#define MUTUAL3_KEY14_THR          (1014)
#define MUTUAL3_KEY15_THR          (1015)
#define MUTUAL3_KEY16_THR          (1016)
#define MUTUAL3_KEY17_THR          (1017)
#define MUTUAL3_KEY18_THR          (1018)
#define MUTUAL3_KEY19_THR          (1019)
#define MUTUAL3_KEY20_THR          (1020)
#define MUTUAL3_KEY21_THR          (1021)
#define MUTUAL3_KEY22_THR          (1022)
#define MUTUAL3_KEY23_THR          (1023)
#define MUTUAL3_KEY24_THR          (1024)
#define MUTUAL3_KEY25_THR          (1025)
#define MUTUAL3_KEY26_THR          (1026)
#define MUTUAL3_KEY27_THR          (1027)
#define MUTUAL3_KEY28_THR          (1028)
#define MUTUAL3_KEY29_THR          (1029)
#define MUTUAL3_KEY30_THR          (1030)
#define MUTUAL3_KEY31_THR          (1031)
#define MUTUAL3_KEY32_THR          (1032)
#define MUTUAL3_KEY33_THR          (1033)
#define MUTUAL3_KEY34_THR          (1034)
#define MUTUAL3_KEY35_THR          (1035)
#define MUTUAL3_KEY36_THR          (1036)
#define MUTUAL3_KEY37_THR          (1037)
#define MUTUAL3_KEY38_THR          (1038)
#define MUTUAL3_KEY39_THR          (1039)
#define MUTUAL3_KEY40_THR          (1040)
#define MUTUAL3_KEY41_THR          (1041)
#define MUTUAL3_KEY42_THR          (1042)
#define MUTUAL3_KEY43_THR          (1043)
#define MUTUAL3_KEY44_THR          (1044)
#define MUTUAL3_KEY45_THR          (1045)
#define MUTUAL3_KEY46_THR          (1046)
#define MUTUAL3_KEY47_THR          (1047)
#define MUTUAL3_KEY48_THR          (1048)
#define MUTUAL3_KEY49_THR          (1049)
#define MUTUAL3_KEY50_THR          (1050)
#define MUTUAL3_KEY51_THR          (1051)
#define MUTUAL3_KEY52_THR          (1052)
#define MUTUAL3_KEY53_THR          (1053)
#define MUTUAL3_KEY54_THR          (1054)
#define MUTUAL3_KEY55_THR          (1055)
#define MUTUAL3_KEY56_THR          (1056)
#define MUTUAL3_KEY57_THR          (1057)
#define MUTUAL3_KEY58_THR          (1058)
#define MUTUAL3_KEY59_THR          (1059)
#define MUTUAL3_KEY60_THR          (1060)
#define MUTUAL3_KEY61_THR          (1061)
#define MUTUAL3_KEY62_THR          (1062)
#define MUTUAL3_KEY63_THR          (1063)

/* Hysteresis set up data */
#define MUTUAL3_KEY00_HYS          (20)
#define MUTUAL3_KEY01_HYS          (21)
#define MUTUAL3_KEY02_HYS          (22)
#define MUTUAL3_KEY03_HYS          (23)
#define MUTUAL3_KEY04_HYS          (24)
#define MUTUAL3_KEY05_HYS          (25)
#define MUTUAL3_KEY06_HYS          (26)
#define MUTUAL3_KEY07_HYS          (27)
#define MUTUAL3_KEY08_HYS          (28)
#define MUTUAL3_KEY09_HYS          (29)
#define MUTUAL3_KEY10_HYS          (30)
#define MUTUAL3_KEY11_HYS          (31)
#define MUTUAL3_KEY12_HYS          (32)
#define MUTUAL3_KEY13_HYS          (33)
#define MUTUAL3_KEY14_HYS          (34)
#define MUTUAL3_KEY15_HYS          (35)
#define MUTUAL3_KEY16_HYS          (36)
#define MUTUAL3_KEY17_HYS          (37)
#define MUTUAL3_KEY18_HYS          (38)
#define MUTUAL3_KEY19_HYS          (39)
#define MUTUAL3_KEY20_HYS          (40)
#define MUTUAL3_KEY21_HYS          (41)
#define MUTUAL3_KEY22_HYS          (42)
#define MUTUAL3_KEY23_HYS          (43)
#define MUTUAL3_KEY24_HYS          (44)
#define MUTUAL3_KEY25_HYS          (45)
#define MUTUAL3_KEY26_HYS          (46)
#define MUTUAL3_KEY27_HYS          (47)
#define MUTUAL3_KEY28_HYS          (48)
#define MUTUAL3_KEY29_HYS          (49)
#define MUTUAL3_KEY30_HYS          (50)
#define MUTUAL3_KEY31_HYS          (51)
#define MUTUAL3_KEY32_HYS          (52)
#define MUTUAL3_KEY33_HYS          (53)
#define MUTUAL3_KEY34_HYS          (54)
#define MUTUAL3_KEY35_HYS          (55)
#define MUTUAL3_KEY36_HYS          (56)
#define MUTUAL3_KEY37_HYS          (57)
#define MUTUAL3_KEY38_HYS          (58)
#define MUTUAL3_KEY39_HYS          (59)
#define MUTUAL3_KEY40_HYS          (60)
#define MUTUAL3_KEY41_HYS          (61)
#define MUTUAL3_KEY42_HYS          (62)
#define MUTUAL3_KEY43_HYS          (63)
#define MUTUAL3_KEY44_HYS          (64)
#define MUTUAL3_KEY45_HYS          (65)
#define MUTUAL3_KEY46_HYS          (66)
#define MUTUAL3_KEY47_HYS          (67)
#define MUTUAL3_KEY48_HYS          (68)
#define MUTUAL3_KEY49_HYS          (69)
#define MUTUAL3_KEY50_HYS          (70)
#define MUTUAL3_KEY51_HYS          (71)
#define MUTUAL3_KEY52_HYS          (72)
#define MUTUAL3_KEY53_HYS          (73)
#define MUTUAL3_KEY54_HYS          (74)
#define MUTUAL3_KEY55_HYS          (75)
#define MUTUAL3_KEY56_HYS          (76)
#define MUTUAL3_KEY57_HYS          (77)
#define MUTUAL3_KEY58_HYS          (78)
#define MUTUAL3_KEY59_HYS          (79)
#define MUTUAL3_KEY60_HYS          (80)
#define MUTUAL3_KEY61_HYS          (81)
#define MUTUAL3_KEY62_HYS          (82)
#define MUTUAL3_KEY63_HYS          (83)

/*====================================================================================================================*/
/*=====    Mutual 4 touch parameter definition    ====================================================================*/
/*====================================================================================================================*/
#define MUTUAL4_KEY00_USE        (0)
#define MUTUAL4_KEY01_USE        (0)
#define MUTUAL4_KEY02_USE        (0)
#define MUTUAL4_KEY03_USE        (0)
#define MUTUAL4_KEY04_USE        (0)
#define MUTUAL4_KEY05_USE        (0)
#define MUTUAL4_KEY06_USE        (0)
#define MUTUAL4_KEY07_USE        (0)
#define MUTUAL4_KEY08_USE        (0)
#define MUTUAL4_KEY09_USE        (0)
#define MUTUAL4_KEY10_USE        (0)
#define MUTUAL4_KEY11_USE        (0)
#define MUTUAL4_KEY12_USE        (0)
#define MUTUAL4_KEY13_USE        (0)
#define MUTUAL4_KEY14_USE        (0)
#define MUTUAL4_KEY15_USE        (0)
#define MUTUAL4_KEY16_USE        (0)
#define MUTUAL4_KEY17_USE        (0)
#define MUTUAL4_KEY18_USE        (0)
#define MUTUAL4_KEY19_USE        (0)
#define MUTUAL4_KEY20_USE        (0)
#define MUTUAL4_KEY21_USE        (0)
#define MUTUAL4_KEY22_USE        (0)
#define MUTUAL4_KEY23_USE        (0)
#define MUTUAL4_KEY24_USE        (0)
#define MUTUAL4_KEY25_USE        (0)
#define MUTUAL4_KEY26_USE        (0)
#define MUTUAL4_KEY27_USE        (0)
#define MUTUAL4_KEY28_USE        (0)
#define MUTUAL4_KEY29_USE        (0)
#define MUTUAL4_KEY30_USE        (0)
#define MUTUAL4_KEY31_USE        (0)
#define MUTUAL4_KEY32_USE        (0)
#define MUTUAL4_KEY33_USE        (0)
#define MUTUAL4_KEY34_USE        (0)
#define MUTUAL4_KEY35_USE        (0)
#define MUTUAL4_KEY36_USE        (0)
#define MUTUAL4_KEY37_USE        (0)
#define MUTUAL4_KEY38_USE        (0)
#define MUTUAL4_KEY39_USE        (0)
#define MUTUAL4_KEY40_USE        (0)
#define MUTUAL4_KEY41_USE        (0)
#define MUTUAL4_KEY42_USE        (0)
#define MUTUAL4_KEY43_USE        (0)
#define MUTUAL4_KEY44_USE        (0)
#define MUTUAL4_KEY45_USE        (0)
#define MUTUAL4_KEY46_USE        (0)
#define MUTUAL4_KEY47_USE        (0)
#define MUTUAL4_KEY48_USE        (0)
#define MUTUAL4_KEY49_USE        (0)
#define MUTUAL4_KEY50_USE        (0)
#define MUTUAL4_KEY51_USE        (0)
#define MUTUAL4_KEY52_USE        (0)
#define MUTUAL4_KEY53_USE        (0)
#define MUTUAL4_KEY54_USE        (0)
#define MUTUAL4_KEY55_USE        (0)
#define MUTUAL4_KEY56_USE        (0)
#define MUTUAL4_KEY57_USE        (0)
#define MUTUAL4_KEY58_USE        (0)
#define MUTUAL4_KEY59_USE        (0)
#define MUTUAL4_KEY60_USE        (0)
#define MUTUAL4_KEY61_USE        (0)
#define MUTUAL4_KEY62_USE        (0)
#define MUTUAL4_KEY63_USE        (0)

#define MUTUAL4_KEY_USE_GROUP0   ((MUTUAL4_KEY00_USE      ) + (MUTUAL4_KEY01_USE <<  1) + (MUTUAL4_KEY02_USE <<  2) + \
                                  (MUTUAL4_KEY03_USE <<  3) + (MUTUAL4_KEY04_USE <<  4) + (MUTUAL4_KEY05_USE <<  5) + \
                                  (MUTUAL4_KEY06_USE <<  6) + (MUTUAL4_KEY07_USE <<  7) + (MUTUAL4_KEY08_USE <<  8) + \
                                  (MUTUAL4_KEY09_USE <<  9) + (MUTUAL4_KEY10_USE << 10) + (MUTUAL4_KEY11_USE << 11) + \
                                  (MUTUAL4_KEY12_USE << 12) + (MUTUAL4_KEY13_USE << 13) + (MUTUAL4_KEY14_USE << 14) + \
                                  (MUTUAL4_KEY15_USE << 15))

#define MUTUAL4_KEY_USE_GROUP1   ((MUTUAL4_KEY16_USE      ) + (MUTUAL4_KEY17_USE <<  1) + (MUTUAL4_KEY18_USE <<  2) + \
                                  (MUTUAL4_KEY19_USE <<  3) + (MUTUAL4_KEY20_USE <<  4) + (MUTUAL4_KEY21_USE <<  5) + \
                                  (MUTUAL4_KEY22_USE <<  6) + (MUTUAL4_KEY23_USE <<  7) + (MUTUAL4_KEY24_USE <<  8) + \
                                  (MUTUAL4_KEY25_USE <<  9) + (MUTUAL4_KEY26_USE << 10) + (MUTUAL4_KEY27_USE << 11) + \
                                  (MUTUAL4_KEY28_USE << 12) + (MUTUAL4_KEY29_USE << 13) + (MUTUAL4_KEY30_USE << 14) + \
                                  (MUTUAL4_KEY31_USE << 15))

#define MUTUAL4_KEY_USE_GROUP2   ((MUTUAL4_KEY32_USE      ) + (MUTUAL4_KEY33_USE <<  1) + (MUTUAL4_KEY34_USE <<  2) + \
                                  (MUTUAL4_KEY35_USE <<  3) + (MUTUAL4_KEY36_USE <<  4) + (MUTUAL4_KEY37_USE <<  5) + \
                                  (MUTUAL4_KEY36_USE <<  6) + (MUTUAL4_KEY39_USE <<  7) + (MUTUAL4_KEY40_USE <<  8) + \
                                  (MUTUAL4_KEY41_USE <<  9) + (MUTUAL4_KEY42_USE << 10) + (MUTUAL4_KEY43_USE << 11) + \
                                  (MUTUAL4_KEY44_USE << 12) + (MUTUAL4_KEY45_USE << 13) + (MUTUAL4_KEY46_USE << 14) + \
                                  (MUTUAL4_KEY47_USE << 15))

#define MUTUAL4_KEY_USE_GROUP3   ((MUTUAL4_KEY48_USE      ) + (MUTUAL4_KEY49_USE <<  1) + (MUTUAL4_KEY50_USE <<  2) + \
                                  (MUTUAL4_KEY51_USE <<  3) + (MUTUAL4_KEY52_USE <<  4) + (MUTUAL4_KEY53_USE <<  5) + \
                                  (MUTUAL4_KEY54_USE <<  6) + (MUTUAL4_KEY55_USE <<  7) + (MUTUAL4_KEY56_USE <<  8) + \
                                  (MUTUAL4_KEY57_USE <<  9) + (MUTUAL4_KEY58_USE << 10) + (MUTUAL4_KEY59_USE << 11) + \
                                  (MUTUAL4_KEY60_USE << 12) + (MUTUAL4_KEY61_USE << 13) + (MUTUAL4_KEY62_USE << 14) + \
                                  (MUTUAL4_KEY63_USE << 15))

#if (MUTUAL4_KEY_USE_GROUP3 > 0)
    #define MUTUAL4_MAX_GROUP        (4)
#elif (MUTUAL4_KEY_USE_GROUP2 > 0)
    #define MUTUAL4_MAX_GROUP        (3)
#elif (MUTUAL4_KEY_USE_GROUP1 > 0)
    #define MUTUAL4_MAX_GROUP        (2)
#else
    #define MUTUAL4_MAX_GROUP        (1)
#endif

#define MUTUAL4_KEY_NUM           (MUTUAL4_KEY00_USE + MUTUAL4_KEY01_USE + MUTUAL4_KEY02_USE + MUTUAL4_KEY03_USE + \
                                   MUTUAL4_KEY04_USE + MUTUAL4_KEY05_USE + MUTUAL4_KEY06_USE + MUTUAL4_KEY07_USE + \
                                   MUTUAL4_KEY08_USE + MUTUAL4_KEY09_USE + MUTUAL4_KEY10_USE + MUTUAL4_KEY11_USE + \
                                   MUTUAL4_KEY12_USE + MUTUAL4_KEY13_USE + MUTUAL4_KEY14_USE + MUTUAL4_KEY15_USE + \
                                   MUTUAL4_KEY16_USE + MUTUAL4_KEY17_USE + MUTUAL4_KEY18_USE + MUTUAL4_KEY19_USE + \
                                   MUTUAL4_KEY20_USE + MUTUAL4_KEY21_USE + MUTUAL4_KEY22_USE + MUTUAL4_KEY23_USE + \
                                   MUTUAL4_KEY24_USE + MUTUAL4_KEY25_USE + MUTUAL4_KEY26_USE + MUTUAL4_KEY27_USE + \
                                   MUTUAL4_KEY28_USE + MUTUAL4_KEY29_USE + MUTUAL4_KEY30_USE + MUTUAL4_KEY31_USE + \
                                   MUTUAL4_KEY32_USE + MUTUAL4_KEY33_USE + MUTUAL4_KEY34_USE + MUTUAL4_KEY35_USE + \
                                   MUTUAL4_KEY36_USE + MUTUAL4_KEY37_USE + MUTUAL4_KEY38_USE + MUTUAL4_KEY39_USE + \
                                   MUTUAL4_KEY40_USE + MUTUAL4_KEY41_USE + MUTUAL4_KEY42_USE + MUTUAL4_KEY43_USE + \
                                   MUTUAL4_KEY44_USE + MUTUAL4_KEY45_USE + MUTUAL4_KEY46_USE + MUTUAL4_KEY47_USE + \
                                   MUTUAL4_KEY48_USE + MUTUAL4_KEY49_USE + MUTUAL4_KEY50_USE + MUTUAL4_KEY51_USE + \
                                   MUTUAL4_KEY52_USE + MUTUAL4_KEY53_USE + MUTUAL4_KEY54_USE + MUTUAL4_KEY55_USE + \
                                   MUTUAL4_KEY56_USE + MUTUAL4_KEY57_USE + MUTUAL4_KEY58_USE + MUTUAL4_KEY59_USE + \
                                   MUTUAL4_KEY60_USE + MUTUAL4_KEY61_USE + MUTUAL4_KEY62_USE + MUTUAL4_KEY63_USE)

/* ON/OFF threshold set up data */
#define MUTUAL4_KEY00_THR          (1000)
#define MUTUAL4_KEY01_THR          (1001)
#define MUTUAL4_KEY02_THR          (1002)
#define MUTUAL4_KEY03_THR          (1003)
#define MUTUAL4_KEY04_THR          (1004)
#define MUTUAL4_KEY05_THR          (1005)
#define MUTUAL4_KEY06_THR          (1006)
#define MUTUAL4_KEY07_THR          (1007)
#define MUTUAL4_KEY08_THR          (1008)
#define MUTUAL4_KEY09_THR          (1009)
#define MUTUAL4_KEY10_THR          (1010)
#define MUTUAL4_KEY11_THR          (1011)
#define MUTUAL4_KEY12_THR          (1012)
#define MUTUAL4_KEY13_THR          (1013)
#define MUTUAL4_KEY14_THR          (1014)
#define MUTUAL4_KEY15_THR          (1015)
#define MUTUAL4_KEY16_THR          (1016)
#define MUTUAL4_KEY17_THR          (1017)
#define MUTUAL4_KEY18_THR          (1018)
#define MUTUAL4_KEY19_THR          (1019)
#define MUTUAL4_KEY20_THR          (1020)
#define MUTUAL4_KEY21_THR          (1021)
#define MUTUAL4_KEY22_THR          (1022)
#define MUTUAL4_KEY23_THR          (1023)
#define MUTUAL4_KEY24_THR          (1024)
#define MUTUAL4_KEY25_THR          (1025)
#define MUTUAL4_KEY26_THR          (1026)
#define MUTUAL4_KEY27_THR          (1027)
#define MUTUAL4_KEY28_THR          (1028)
#define MUTUAL4_KEY29_THR          (1029)
#define MUTUAL4_KEY30_THR          (1030)
#define MUTUAL4_KEY31_THR          (1031)
#define MUTUAL4_KEY32_THR          (1032)
#define MUTUAL4_KEY33_THR          (1033)
#define MUTUAL4_KEY34_THR          (1034)
#define MUTUAL4_KEY35_THR          (1035)
#define MUTUAL4_KEY36_THR          (1036)
#define MUTUAL4_KEY37_THR          (1037)
#define MUTUAL4_KEY38_THR          (1038)
#define MUTUAL4_KEY39_THR          (1039)
#define MUTUAL4_KEY40_THR          (1040)
#define MUTUAL4_KEY41_THR          (1041)
#define MUTUAL4_KEY42_THR          (1042)
#define MUTUAL4_KEY43_THR          (1043)
#define MUTUAL4_KEY44_THR          (1044)
#define MUTUAL4_KEY45_THR          (1045)
#define MUTUAL4_KEY46_THR          (1046)
#define MUTUAL4_KEY47_THR          (1047)
#define MUTUAL4_KEY48_THR          (1048)
#define MUTUAL4_KEY49_THR          (1049)
#define MUTUAL4_KEY50_THR          (1050)
#define MUTUAL4_KEY51_THR          (1051)
#define MUTUAL4_KEY52_THR          (1052)
#define MUTUAL4_KEY53_THR          (1053)
#define MUTUAL4_KEY54_THR          (1054)
#define MUTUAL4_KEY55_THR          (1055)
#define MUTUAL4_KEY56_THR          (1056)
#define MUTUAL4_KEY57_THR          (1057)
#define MUTUAL4_KEY58_THR          (1058)
#define MUTUAL4_KEY59_THR          (1059)
#define MUTUAL4_KEY60_THR          (1060)
#define MUTUAL4_KEY61_THR          (1061)
#define MUTUAL4_KEY62_THR          (1062)
#define MUTUAL4_KEY63_THR          (1063)

/* Hysteresis set up data */
#define MUTUAL4_KEY00_HYS          (20)
#define MUTUAL4_KEY01_HYS          (21)
#define MUTUAL4_KEY02_HYS          (22)
#define MUTUAL4_KEY03_HYS          (23)
#define MUTUAL4_KEY04_HYS          (24)
#define MUTUAL4_KEY05_HYS          (25)
#define MUTUAL4_KEY06_HYS          (26)
#define MUTUAL4_KEY07_HYS          (27)
#define MUTUAL4_KEY08_HYS          (28)
#define MUTUAL4_KEY09_HYS          (29)
#define MUTUAL4_KEY10_HYS          (30)
#define MUTUAL4_KEY11_HYS          (31)
#define MUTUAL4_KEY12_HYS          (32)
#define MUTUAL4_KEY13_HYS          (33)
#define MUTUAL4_KEY14_HYS          (34)
#define MUTUAL4_KEY15_HYS          (35)
#define MUTUAL4_KEY16_HYS          (36)
#define MUTUAL4_KEY17_HYS          (37)
#define MUTUAL4_KEY18_HYS          (38)
#define MUTUAL4_KEY19_HYS          (39)
#define MUTUAL4_KEY20_HYS          (40)
#define MUTUAL4_KEY21_HYS          (41)
#define MUTUAL4_KEY22_HYS          (42)
#define MUTUAL4_KEY23_HYS          (43)
#define MUTUAL4_KEY24_HYS          (44)
#define MUTUAL4_KEY25_HYS          (45)
#define MUTUAL4_KEY26_HYS          (46)
#define MUTUAL4_KEY27_HYS          (47)
#define MUTUAL4_KEY28_HYS          (48)
#define MUTUAL4_KEY29_HYS          (49)
#define MUTUAL4_KEY30_HYS          (50)
#define MUTUAL4_KEY31_HYS          (51)
#define MUTUAL4_KEY32_HYS          (52)
#define MUTUAL4_KEY33_HYS          (53)
#define MUTUAL4_KEY34_HYS          (54)
#define MUTUAL4_KEY35_HYS          (55)
#define MUTUAL4_KEY36_HYS          (56)
#define MUTUAL4_KEY37_HYS          (57)
#define MUTUAL4_KEY38_HYS          (58)
#define MUTUAL4_KEY39_HYS          (59)
#define MUTUAL4_KEY40_HYS          (60)
#define MUTUAL4_KEY41_HYS          (61)
#define MUTUAL4_KEY42_HYS          (62)
#define MUTUAL4_KEY43_HYS          (63)
#define MUTUAL4_KEY44_HYS          (64)
#define MUTUAL4_KEY45_HYS          (65)
#define MUTUAL4_KEY46_HYS          (66)
#define MUTUAL4_KEY47_HYS          (67)
#define MUTUAL4_KEY48_HYS          (68)
#define MUTUAL4_KEY49_HYS          (69)
#define MUTUAL4_KEY50_HYS          (70)
#define MUTUAL4_KEY51_HYS          (71)
#define MUTUAL4_KEY52_HYS          (72)
#define MUTUAL4_KEY53_HYS          (73)
#define MUTUAL4_KEY54_HYS          (74)
#define MUTUAL4_KEY55_HYS          (75)
#define MUTUAL4_KEY56_HYS          (76)
#define MUTUAL4_KEY57_HYS          (77)
#define MUTUAL4_KEY58_HYS          (78)
#define MUTUAL4_KEY59_HYS          (79)
#define MUTUAL4_KEY60_HYS          (80)
#define MUTUAL4_KEY61_HYS          (81)
#define MUTUAL4_KEY62_HYS          (82)
#define MUTUAL4_KEY63_HYS          (83)

/*====================================================================================================================*/
/*=====    Mutual 5 touch parameter definition    ====================================================================*/
/*====================================================================================================================*/
#define MUTUAL5_KEY00_USE        (0)
#define MUTUAL5_KEY01_USE        (0)
#define MUTUAL5_KEY02_USE        (0)
#define MUTUAL5_KEY03_USE        (0)
#define MUTUAL5_KEY04_USE        (0)
#define MUTUAL5_KEY05_USE        (0)
#define MUTUAL5_KEY06_USE        (0)
#define MUTUAL5_KEY07_USE        (0)
#define MUTUAL5_KEY08_USE        (0)
#define MUTUAL5_KEY09_USE        (0)
#define MUTUAL5_KEY10_USE        (0)
#define MUTUAL5_KEY11_USE        (0)
#define MUTUAL5_KEY12_USE        (0)
#define MUTUAL5_KEY13_USE        (0)
#define MUTUAL5_KEY14_USE        (0)
#define MUTUAL5_KEY15_USE        (0)
#define MUTUAL5_KEY16_USE        (0)
#define MUTUAL5_KEY17_USE        (0)
#define MUTUAL5_KEY18_USE        (0)
#define MUTUAL5_KEY19_USE        (0)
#define MUTUAL5_KEY20_USE        (0)
#define MUTUAL5_KEY21_USE        (0)
#define MUTUAL5_KEY22_USE        (0)
#define MUTUAL5_KEY23_USE        (0)
#define MUTUAL5_KEY24_USE        (0)
#define MUTUAL5_KEY25_USE        (0)
#define MUTUAL5_KEY26_USE        (0)
#define MUTUAL5_KEY27_USE        (0)
#define MUTUAL5_KEY28_USE        (0)
#define MUTUAL5_KEY29_USE        (0)
#define MUTUAL5_KEY30_USE        (0)
#define MUTUAL5_KEY31_USE        (0)
#define MUTUAL5_KEY32_USE        (0)
#define MUTUAL5_KEY33_USE        (0)
#define MUTUAL5_KEY34_USE        (0)
#define MUTUAL5_KEY35_USE        (0)
#define MUTUAL5_KEY36_USE        (0)
#define MUTUAL5_KEY37_USE        (0)
#define MUTUAL5_KEY38_USE        (0)
#define MUTUAL5_KEY39_USE        (0)
#define MUTUAL5_KEY40_USE        (0)
#define MUTUAL5_KEY41_USE        (0)
#define MUTUAL5_KEY42_USE        (0)
#define MUTUAL5_KEY43_USE        (0)
#define MUTUAL5_KEY44_USE        (0)
#define MUTUAL5_KEY45_USE        (0)
#define MUTUAL5_KEY46_USE        (0)
#define MUTUAL5_KEY47_USE        (0)
#define MUTUAL5_KEY48_USE        (0)
#define MUTUAL5_KEY49_USE        (0)
#define MUTUAL5_KEY50_USE        (0)
#define MUTUAL5_KEY51_USE        (0)
#define MUTUAL5_KEY52_USE        (0)
#define MUTUAL5_KEY53_USE        (0)
#define MUTUAL5_KEY54_USE        (0)
#define MUTUAL5_KEY55_USE        (0)
#define MUTUAL5_KEY56_USE        (0)
#define MUTUAL5_KEY57_USE        (0)
#define MUTUAL5_KEY58_USE        (0)
#define MUTUAL5_KEY59_USE        (0)
#define MUTUAL5_KEY60_USE        (0)
#define MUTUAL5_KEY61_USE        (0)
#define MUTUAL5_KEY62_USE        (0)
#define MUTUAL5_KEY63_USE        (0)

#define MUTUAL5_KEY_USE_GROUP0   ((MUTUAL5_KEY00_USE      ) + (MUTUAL5_KEY01_USE <<  1) + (MUTUAL5_KEY02_USE <<  2) + \
                                  (MUTUAL5_KEY03_USE <<  3) + (MUTUAL5_KEY04_USE <<  4) + (MUTUAL5_KEY05_USE <<  5) + \
                                  (MUTUAL5_KEY06_USE <<  6) + (MUTUAL5_KEY07_USE <<  7) + (MUTUAL5_KEY08_USE <<  8) + \
                                  (MUTUAL5_KEY09_USE <<  9) + (MUTUAL5_KEY10_USE << 10) + (MUTUAL5_KEY11_USE << 11) + \
                                  (MUTUAL5_KEY12_USE << 12) + (MUTUAL5_KEY13_USE << 13) + (MUTUAL5_KEY14_USE << 14) + \
                                  (MUTUAL5_KEY15_USE << 15))

#define MUTUAL5_KEY_USE_GROUP1   ((MUTUAL5_KEY16_USE      ) + (MUTUAL5_KEY17_USE <<  1) + (MUTUAL5_KEY18_USE <<  2) + \
                                  (MUTUAL5_KEY19_USE <<  3) + (MUTUAL5_KEY20_USE <<  4) + (MUTUAL5_KEY21_USE <<  5) + \
                                  (MUTUAL5_KEY22_USE <<  6) + (MUTUAL5_KEY23_USE <<  7) + (MUTUAL5_KEY24_USE <<  8) + \
                                  (MUTUAL5_KEY25_USE <<  9) + (MUTUAL5_KEY26_USE << 10) + (MUTUAL5_KEY27_USE << 11) + \
                                  (MUTUAL5_KEY28_USE << 12) + (MUTUAL5_KEY29_USE << 13) + (MUTUAL5_KEY30_USE << 14) + \
                                  (MUTUAL5_KEY31_USE << 15))

#define MUTUAL5_KEY_USE_GROUP2   ((MUTUAL5_KEY32_USE      ) + (MUTUAL5_KEY33_USE <<  1) + (MUTUAL5_KEY34_USE <<  2) + \
                                  (MUTUAL5_KEY35_USE <<  3) + (MUTUAL5_KEY36_USE <<  4) + (MUTUAL5_KEY37_USE <<  5) + \
                                  (MUTUAL5_KEY36_USE <<  6) + (MUTUAL5_KEY39_USE <<  7) + (MUTUAL5_KEY40_USE <<  8) + \
                                  (MUTUAL5_KEY41_USE <<  9) + (MUTUAL5_KEY42_USE << 10) + (MUTUAL5_KEY43_USE << 11) + \
                                  (MUTUAL5_KEY44_USE << 12) + (MUTUAL5_KEY45_USE << 13) + (MUTUAL5_KEY46_USE << 14) + \
                                  (MUTUAL5_KEY47_USE << 15))

#define MUTUAL5_KEY_USE_GROUP3   ((MUTUAL5_KEY48_USE      ) + (MUTUAL5_KEY49_USE <<  1) + (MUTUAL5_KEY50_USE <<  2) + \
                                  (MUTUAL5_KEY51_USE <<  3) + (MUTUAL5_KEY52_USE <<  4) + (MUTUAL5_KEY53_USE <<  5) + \
                                  (MUTUAL5_KEY54_USE <<  6) + (MUTUAL5_KEY55_USE <<  7) + (MUTUAL5_KEY56_USE <<  8) + \
                                  (MUTUAL5_KEY57_USE <<  9) + (MUTUAL5_KEY58_USE << 10) + (MUTUAL5_KEY59_USE << 11) + \
                                  (MUTUAL5_KEY60_USE << 12) + (MUTUAL5_KEY61_USE << 13) + (MUTUAL5_KEY62_USE << 14) + \
                                  (MUTUAL5_KEY63_USE << 15))

#if (MUTUAL5_KEY_USE_GROUP3 > 0)
    #define MUTUAL5_MAX_GROUP        (4)
#elif (MUTUAL5_KEY_USE_GROUP2 > 0)
    #define MUTUAL5_MAX_GROUP        (3)
#elif (MUTUAL5_KEY_USE_GROUP1 > 0)
    #define MUTUAL5_MAX_GROUP        (2)
#else
    #define MUTUAL5_MAX_GROUP        (1)
#endif

#define MUTUAL5_KEY_NUM           (MUTUAL5_KEY00_USE + MUTUAL5_KEY01_USE + MUTUAL5_KEY02_USE + MUTUAL5_KEY03_USE + \
                                   MUTUAL5_KEY04_USE + MUTUAL5_KEY05_USE + MUTUAL5_KEY06_USE + MUTUAL5_KEY07_USE + \
                                   MUTUAL5_KEY08_USE + MUTUAL5_KEY09_USE + MUTUAL5_KEY10_USE + MUTUAL5_KEY11_USE + \
                                   MUTUAL5_KEY12_USE + MUTUAL5_KEY13_USE + MUTUAL5_KEY14_USE + MUTUAL5_KEY15_USE + \
                                   MUTUAL5_KEY16_USE + MUTUAL5_KEY17_USE + MUTUAL5_KEY18_USE + MUTUAL5_KEY19_USE + \
                                   MUTUAL5_KEY20_USE + MUTUAL5_KEY21_USE + MUTUAL5_KEY22_USE + MUTUAL5_KEY23_USE + \
                                   MUTUAL5_KEY24_USE + MUTUAL5_KEY25_USE + MUTUAL5_KEY26_USE + MUTUAL5_KEY27_USE + \
                                   MUTUAL5_KEY28_USE + MUTUAL5_KEY29_USE + MUTUAL5_KEY30_USE + MUTUAL5_KEY31_USE + \
                                   MUTUAL5_KEY32_USE + MUTUAL5_KEY33_USE + MUTUAL5_KEY34_USE + MUTUAL5_KEY35_USE + \
                                   MUTUAL5_KEY36_USE + MUTUAL5_KEY37_USE + MUTUAL5_KEY38_USE + MUTUAL5_KEY39_USE + \
                                   MUTUAL5_KEY40_USE + MUTUAL5_KEY41_USE + MUTUAL5_KEY42_USE + MUTUAL5_KEY43_USE + \
                                   MUTUAL5_KEY44_USE + MUTUAL5_KEY45_USE + MUTUAL5_KEY46_USE + MUTUAL5_KEY47_USE + \
                                   MUTUAL5_KEY48_USE + MUTUAL5_KEY49_USE + MUTUAL5_KEY50_USE + MUTUAL5_KEY51_USE + \
                                   MUTUAL5_KEY52_USE + MUTUAL5_KEY53_USE + MUTUAL5_KEY54_USE + MUTUAL5_KEY55_USE + \
                                   MUTUAL5_KEY56_USE + MUTUAL5_KEY57_USE + MUTUAL5_KEY58_USE + MUTUAL5_KEY59_USE + \
                                   MUTUAL5_KEY60_USE + MUTUAL5_KEY61_USE + MUTUAL5_KEY62_USE + MUTUAL5_KEY63_USE)

/* ON/OFF threshold set up data */
#define MUTUAL5_KEY00_THR          (1000)
#define MUTUAL5_KEY01_THR          (1001)
#define MUTUAL5_KEY02_THR          (1002)
#define MUTUAL5_KEY03_THR          (1003)
#define MUTUAL5_KEY04_THR          (1004)
#define MUTUAL5_KEY05_THR          (1005)
#define MUTUAL5_KEY06_THR          (1006)
#define MUTUAL5_KEY07_THR          (1007)
#define MUTUAL5_KEY08_THR          (1008)
#define MUTUAL5_KEY09_THR          (1009)
#define MUTUAL5_KEY10_THR          (1010)
#define MUTUAL5_KEY11_THR          (1011)
#define MUTUAL5_KEY12_THR          (1012)
#define MUTUAL5_KEY13_THR          (1013)
#define MUTUAL5_KEY14_THR          (1014)
#define MUTUAL5_KEY15_THR          (1015)
#define MUTUAL5_KEY16_THR          (1016)
#define MUTUAL5_KEY17_THR          (1017)
#define MUTUAL5_KEY18_THR          (1018)
#define MUTUAL5_KEY19_THR          (1019)
#define MUTUAL5_KEY20_THR          (1020)
#define MUTUAL5_KEY21_THR          (1021)
#define MUTUAL5_KEY22_THR          (1022)
#define MUTUAL5_KEY23_THR          (1023)
#define MUTUAL5_KEY24_THR          (1024)
#define MUTUAL5_KEY25_THR          (1025)
#define MUTUAL5_KEY26_THR          (1026)
#define MUTUAL5_KEY27_THR          (1027)
#define MUTUAL5_KEY28_THR          (1028)
#define MUTUAL5_KEY29_THR          (1029)
#define MUTUAL5_KEY30_THR          (1030)
#define MUTUAL5_KEY31_THR          (1031)
#define MUTUAL5_KEY32_THR          (1032)
#define MUTUAL5_KEY33_THR          (1033)
#define MUTUAL5_KEY34_THR          (1034)
#define MUTUAL5_KEY35_THR          (1035)
#define MUTUAL5_KEY36_THR          (1036)
#define MUTUAL5_KEY37_THR          (1037)
#define MUTUAL5_KEY38_THR          (1038)
#define MUTUAL5_KEY39_THR          (1039)
#define MUTUAL5_KEY40_THR          (1040)
#define MUTUAL5_KEY41_THR          (1041)
#define MUTUAL5_KEY42_THR          (1042)
#define MUTUAL5_KEY43_THR          (1043)
#define MUTUAL5_KEY44_THR          (1044)
#define MUTUAL5_KEY45_THR          (1045)
#define MUTUAL5_KEY46_THR          (1046)
#define MUTUAL5_KEY47_THR          (1047)
#define MUTUAL5_KEY48_THR          (1048)
#define MUTUAL5_KEY49_THR          (1049)
#define MUTUAL5_KEY50_THR          (1050)
#define MUTUAL5_KEY51_THR          (1051)
#define MUTUAL5_KEY52_THR          (1052)
#define MUTUAL5_KEY53_THR          (1053)
#define MUTUAL5_KEY54_THR          (1054)
#define MUTUAL5_KEY55_THR          (1055)
#define MUTUAL5_KEY56_THR          (1056)
#define MUTUAL5_KEY57_THR          (1057)
#define MUTUAL5_KEY58_THR          (1058)
#define MUTUAL5_KEY59_THR          (1059)
#define MUTUAL5_KEY60_THR          (1060)
#define MUTUAL5_KEY61_THR          (1061)
#define MUTUAL5_KEY62_THR          (1062)
#define MUTUAL5_KEY63_THR          (1063)

/* Hysteresis set up data */
#define MUTUAL5_KEY00_HYS          (20)
#define MUTUAL5_KEY01_HYS          (21)
#define MUTUAL5_KEY02_HYS          (22)
#define MUTUAL5_KEY03_HYS          (23)
#define MUTUAL5_KEY04_HYS          (24)
#define MUTUAL5_KEY05_HYS          (25)
#define MUTUAL5_KEY06_HYS          (26)
#define MUTUAL5_KEY07_HYS          (27)
#define MUTUAL5_KEY08_HYS          (28)
#define MUTUAL5_KEY09_HYS          (29)
#define MUTUAL5_KEY10_HYS          (30)
#define MUTUAL5_KEY11_HYS          (31)
#define MUTUAL5_KEY12_HYS          (32)
#define MUTUAL5_KEY13_HYS          (33)
#define MUTUAL5_KEY14_HYS          (34)
#define MUTUAL5_KEY15_HYS          (35)
#define MUTUAL5_KEY16_HYS          (36)
#define MUTUAL5_KEY17_HYS          (37)
#define MUTUAL5_KEY18_HYS          (38)
#define MUTUAL5_KEY19_HYS          (39)
#define MUTUAL5_KEY20_HYS          (40)
#define MUTUAL5_KEY21_HYS          (41)
#define MUTUAL5_KEY22_HYS          (42)
#define MUTUAL5_KEY23_HYS          (43)
#define MUTUAL5_KEY24_HYS          (44)
#define MUTUAL5_KEY25_HYS          (45)
#define MUTUAL5_KEY26_HYS          (46)
#define MUTUAL5_KEY27_HYS          (47)
#define MUTUAL5_KEY28_HYS          (48)
#define MUTUAL5_KEY29_HYS          (49)
#define MUTUAL5_KEY30_HYS          (50)
#define MUTUAL5_KEY31_HYS          (51)
#define MUTUAL5_KEY32_HYS          (52)
#define MUTUAL5_KEY33_HYS          (53)
#define MUTUAL5_KEY34_HYS          (54)
#define MUTUAL5_KEY35_HYS          (55)
#define MUTUAL5_KEY36_HYS          (56)
#define MUTUAL5_KEY37_HYS          (57)
#define MUTUAL5_KEY38_HYS          (58)
#define MUTUAL5_KEY39_HYS          (59)
#define MUTUAL5_KEY40_HYS          (60)
#define MUTUAL5_KEY41_HYS          (61)
#define MUTUAL5_KEY42_HYS          (62)
#define MUTUAL5_KEY43_HYS          (63)
#define MUTUAL5_KEY44_HYS          (64)
#define MUTUAL5_KEY45_HYS          (65)
#define MUTUAL5_KEY46_HYS          (66)
#define MUTUAL5_KEY47_HYS          (67)
#define MUTUAL5_KEY48_HYS          (68)
#define MUTUAL5_KEY49_HYS          (69)
#define MUTUAL5_KEY50_HYS          (70)
#define MUTUAL5_KEY51_HYS          (71)
#define MUTUAL5_KEY52_HYS          (72)
#define MUTUAL5_KEY53_HYS          (73)
#define MUTUAL5_KEY54_HYS          (74)
#define MUTUAL5_KEY55_HYS          (75)
#define MUTUAL5_KEY56_HYS          (76)
#define MUTUAL5_KEY57_HYS          (77)
#define MUTUAL5_KEY58_HYS          (78)
#define MUTUAL5_KEY59_HYS          (79)
#define MUTUAL5_KEY60_HYS          (80)
#define MUTUAL5_KEY61_HYS          (81)
#define MUTUAL5_KEY62_HYS          (82)
#define MUTUAL5_KEY63_HYS          (83)

/*====================================================================================================================*/
/*=====    Mutual 6 touch parameter definition    ====================================================================*/
/*====================================================================================================================*/
#define MUTUAL6_KEY00_USE        (0)
#define MUTUAL6_KEY01_USE        (0)
#define MUTUAL6_KEY02_USE        (0)
#define MUTUAL6_KEY03_USE        (0)
#define MUTUAL6_KEY04_USE        (0)
#define MUTUAL6_KEY05_USE        (0)
#define MUTUAL6_KEY06_USE        (0)
#define MUTUAL6_KEY07_USE        (0)
#define MUTUAL6_KEY08_USE        (0)
#define MUTUAL6_KEY09_USE        (0)
#define MUTUAL6_KEY10_USE        (0)
#define MUTUAL6_KEY11_USE        (0)
#define MUTUAL6_KEY12_USE        (0)
#define MUTUAL6_KEY13_USE        (0)
#define MUTUAL6_KEY14_USE        (0)
#define MUTUAL6_KEY15_USE        (0)
#define MUTUAL6_KEY16_USE        (0)
#define MUTUAL6_KEY17_USE        (0)
#define MUTUAL6_KEY18_USE        (0)
#define MUTUAL6_KEY19_USE        (0)
#define MUTUAL6_KEY20_USE        (0)
#define MUTUAL6_KEY21_USE        (0)
#define MUTUAL6_KEY22_USE        (0)
#define MUTUAL6_KEY23_USE        (0)
#define MUTUAL6_KEY24_USE        (0)
#define MUTUAL6_KEY25_USE        (0)
#define MUTUAL6_KEY26_USE        (0)
#define MUTUAL6_KEY27_USE        (0)
#define MUTUAL6_KEY28_USE        (0)
#define MUTUAL6_KEY29_USE        (0)
#define MUTUAL6_KEY30_USE        (0)
#define MUTUAL6_KEY31_USE        (0)
#define MUTUAL6_KEY32_USE        (0)
#define MUTUAL6_KEY33_USE        (0)
#define MUTUAL6_KEY34_USE        (0)
#define MUTUAL6_KEY35_USE        (0)
#define MUTUAL6_KEY36_USE        (0)
#define MUTUAL6_KEY37_USE        (0)
#define MUTUAL6_KEY38_USE        (0)
#define MUTUAL6_KEY39_USE        (0)
#define MUTUAL6_KEY40_USE        (0)
#define MUTUAL6_KEY41_USE        (0)
#define MUTUAL6_KEY42_USE        (0)
#define MUTUAL6_KEY43_USE        (0)
#define MUTUAL6_KEY44_USE        (0)
#define MUTUAL6_KEY45_USE        (0)
#define MUTUAL6_KEY46_USE        (0)
#define MUTUAL6_KEY47_USE        (0)
#define MUTUAL6_KEY48_USE        (0)
#define MUTUAL6_KEY49_USE        (0)
#define MUTUAL6_KEY50_USE        (0)
#define MUTUAL6_KEY51_USE        (0)
#define MUTUAL6_KEY52_USE        (0)
#define MUTUAL6_KEY53_USE        (0)
#define MUTUAL6_KEY54_USE        (0)
#define MUTUAL6_KEY55_USE        (0)
#define MUTUAL6_KEY56_USE        (0)
#define MUTUAL6_KEY57_USE        (0)
#define MUTUAL6_KEY58_USE        (0)
#define MUTUAL6_KEY59_USE        (0)
#define MUTUAL6_KEY60_USE        (0)
#define MUTUAL6_KEY61_USE        (0)
#define MUTUAL6_KEY62_USE        (0)
#define MUTUAL6_KEY63_USE        (0)

#define MUTUAL6_KEY_USE_GROUP0   ((MUTUAL6_KEY00_USE      ) + (MUTUAL6_KEY01_USE <<  1) + (MUTUAL6_KEY02_USE <<  2) + \
                                  (MUTUAL6_KEY03_USE <<  3) + (MUTUAL6_KEY04_USE <<  4) + (MUTUAL6_KEY05_USE <<  5) + \
                                  (MUTUAL6_KEY06_USE <<  6) + (MUTUAL6_KEY07_USE <<  7) + (MUTUAL6_KEY08_USE <<  8) + \
                                  (MUTUAL6_KEY09_USE <<  9) + (MUTUAL6_KEY10_USE << 10) + (MUTUAL6_KEY11_USE << 11) + \
                                  (MUTUAL6_KEY12_USE << 12) + (MUTUAL6_KEY13_USE << 13) + (MUTUAL6_KEY14_USE << 14) + \
                                  (MUTUAL6_KEY15_USE << 15))

#define MUTUAL6_KEY_USE_GROUP1   ((MUTUAL6_KEY16_USE      ) + (MUTUAL6_KEY17_USE <<  1) + (MUTUAL6_KEY18_USE <<  2) + \
                                  (MUTUAL6_KEY19_USE <<  3) + (MUTUAL6_KEY20_USE <<  4) + (MUTUAL6_KEY21_USE <<  5) + \
                                  (MUTUAL6_KEY22_USE <<  6) + (MUTUAL6_KEY23_USE <<  7) + (MUTUAL6_KEY24_USE <<  8) + \
                                  (MUTUAL6_KEY25_USE <<  9) + (MUTUAL6_KEY26_USE << 10) + (MUTUAL6_KEY27_USE << 11) + \
                                  (MUTUAL6_KEY28_USE << 12) + (MUTUAL6_KEY29_USE << 13) + (MUTUAL6_KEY30_USE << 14) + \
                                  (MUTUAL6_KEY31_USE << 15))

#define MUTUAL6_KEY_USE_GROUP2   ((MUTUAL6_KEY32_USE      ) + (MUTUAL6_KEY33_USE <<  1) + (MUTUAL6_KEY34_USE <<  2) + \
                                  (MUTUAL6_KEY35_USE <<  3) + (MUTUAL6_KEY36_USE <<  4) + (MUTUAL6_KEY37_USE <<  5) + \
                                  (MUTUAL6_KEY36_USE <<  6) + (MUTUAL6_KEY39_USE <<  7) + (MUTUAL6_KEY40_USE <<  8) + \
                                  (MUTUAL6_KEY41_USE <<  9) + (MUTUAL6_KEY42_USE << 10) + (MUTUAL6_KEY43_USE << 11) + \
                                  (MUTUAL6_KEY44_USE << 12) + (MUTUAL6_KEY45_USE << 13) + (MUTUAL6_KEY46_USE << 14) + \
                                  (MUTUAL6_KEY47_USE << 15))

#define MUTUAL6_KEY_USE_GROUP3   ((MUTUAL6_KEY48_USE      ) + (MUTUAL6_KEY49_USE <<  1) + (MUTUAL6_KEY50_USE <<  2) + \
                                  (MUTUAL6_KEY51_USE <<  3) + (MUTUAL6_KEY52_USE <<  4) + (MUTUAL6_KEY53_USE <<  5) + \
                                  (MUTUAL6_KEY54_USE <<  6) + (MUTUAL6_KEY55_USE <<  7) + (MUTUAL6_KEY56_USE <<  8) + \
                                  (MUTUAL6_KEY57_USE <<  9) + (MUTUAL6_KEY58_USE << 10) + (MUTUAL6_KEY59_USE << 11) + \
                                  (MUTUAL6_KEY60_USE << 12) + (MUTUAL6_KEY61_USE << 13) + (MUTUAL6_KEY62_USE << 14) + \
                                  (MUTUAL6_KEY63_USE << 15))

#if (MUTUAL6_KEY_USE_GROUP3 > 0)
    #define MUTUAL6_MAX_GROUP        (4)
#elif (MUTUAL6_KEY_USE_GROUP2 > 0)
    #define MUTUAL6_MAX_GROUP        (3)
#elif (MUTUAL6_KEY_USE_GROUP1 > 0)
    #define MUTUAL6_MAX_GROUP        (2)
#else
    #define MUTUAL6_MAX_GROUP        (1)
#endif

#define MUTUAL6_KEY_NUM           (MUTUAL6_KEY00_USE + MUTUAL6_KEY01_USE + MUTUAL6_KEY02_USE + MUTUAL6_KEY03_USE + \
                                   MUTUAL6_KEY04_USE + MUTUAL6_KEY05_USE + MUTUAL6_KEY06_USE + MUTUAL6_KEY07_USE + \
                                   MUTUAL6_KEY08_USE + MUTUAL6_KEY09_USE + MUTUAL6_KEY10_USE + MUTUAL6_KEY11_USE + \
                                   MUTUAL6_KEY12_USE + MUTUAL6_KEY13_USE + MUTUAL6_KEY14_USE + MUTUAL6_KEY15_USE + \
                                   MUTUAL6_KEY16_USE + MUTUAL6_KEY17_USE + MUTUAL6_KEY18_USE + MUTUAL6_KEY19_USE + \
                                   MUTUAL6_KEY20_USE + MUTUAL6_KEY21_USE + MUTUAL6_KEY22_USE + MUTUAL6_KEY23_USE + \
                                   MUTUAL6_KEY24_USE + MUTUAL6_KEY25_USE + MUTUAL6_KEY26_USE + MUTUAL6_KEY27_USE + \
                                   MUTUAL6_KEY28_USE + MUTUAL6_KEY29_USE + MUTUAL6_KEY30_USE + MUTUAL6_KEY31_USE + \
                                   MUTUAL6_KEY32_USE + MUTUAL6_KEY33_USE + MUTUAL6_KEY34_USE + MUTUAL6_KEY35_USE + \
                                   MUTUAL6_KEY36_USE + MUTUAL6_KEY37_USE + MUTUAL6_KEY38_USE + MUTUAL6_KEY39_USE + \
                                   MUTUAL6_KEY40_USE + MUTUAL6_KEY41_USE + MUTUAL6_KEY42_USE + MUTUAL6_KEY43_USE + \
                                   MUTUAL6_KEY44_USE + MUTUAL6_KEY45_USE + MUTUAL6_KEY46_USE + MUTUAL6_KEY47_USE + \
                                   MUTUAL6_KEY48_USE + MUTUAL6_KEY49_USE + MUTUAL6_KEY50_USE + MUTUAL6_KEY51_USE + \
                                   MUTUAL6_KEY52_USE + MUTUAL6_KEY53_USE + MUTUAL6_KEY54_USE + MUTUAL6_KEY55_USE + \
                                   MUTUAL6_KEY56_USE + MUTUAL6_KEY57_USE + MUTUAL6_KEY58_USE + MUTUAL6_KEY59_USE + \
                                   MUTUAL6_KEY60_USE + MUTUAL6_KEY61_USE + MUTUAL6_KEY62_USE + MUTUAL6_KEY63_USE)

/* ON/OFF threshold set up data */
#define MUTUAL6_KEY00_THR          (1000)
#define MUTUAL6_KEY01_THR          (1001)
#define MUTUAL6_KEY02_THR          (1002)
#define MUTUAL6_KEY03_THR          (1003)
#define MUTUAL6_KEY04_THR          (1004)
#define MUTUAL6_KEY05_THR          (1005)
#define MUTUAL6_KEY06_THR          (1006)
#define MUTUAL6_KEY07_THR          (1007)
#define MUTUAL6_KEY08_THR          (1008)
#define MUTUAL6_KEY09_THR          (1009)
#define MUTUAL6_KEY10_THR          (1010)
#define MUTUAL6_KEY11_THR          (1011)
#define MUTUAL6_KEY12_THR          (1012)
#define MUTUAL6_KEY13_THR          (1013)
#define MUTUAL6_KEY14_THR          (1014)
#define MUTUAL6_KEY15_THR          (1015)
#define MUTUAL6_KEY16_THR          (1016)
#define MUTUAL6_KEY17_THR          (1017)
#define MUTUAL6_KEY18_THR          (1018)
#define MUTUAL6_KEY19_THR          (1019)
#define MUTUAL6_KEY20_THR          (1020)
#define MUTUAL6_KEY21_THR          (1021)
#define MUTUAL6_KEY22_THR          (1022)
#define MUTUAL6_KEY23_THR          (1023)
#define MUTUAL6_KEY24_THR          (1024)
#define MUTUAL6_KEY25_THR          (1025)
#define MUTUAL6_KEY26_THR          (1026)
#define MUTUAL6_KEY27_THR          (1027)
#define MUTUAL6_KEY28_THR          (1028)
#define MUTUAL6_KEY29_THR          (1029)
#define MUTUAL6_KEY30_THR          (1030)
#define MUTUAL6_KEY31_THR          (1031)
#define MUTUAL6_KEY32_THR          (1032)
#define MUTUAL6_KEY33_THR          (1033)
#define MUTUAL6_KEY34_THR          (1034)
#define MUTUAL6_KEY35_THR          (1035)
#define MUTUAL6_KEY36_THR          (1036)
#define MUTUAL6_KEY37_THR          (1037)
#define MUTUAL6_KEY38_THR          (1038)
#define MUTUAL6_KEY39_THR          (1039)
#define MUTUAL6_KEY40_THR          (1040)
#define MUTUAL6_KEY41_THR          (1041)
#define MUTUAL6_KEY42_THR          (1042)
#define MUTUAL6_KEY43_THR          (1043)
#define MUTUAL6_KEY44_THR          (1044)
#define MUTUAL6_KEY45_THR          (1045)
#define MUTUAL6_KEY46_THR          (1046)
#define MUTUAL6_KEY47_THR          (1047)
#define MUTUAL6_KEY48_THR          (1048)
#define MUTUAL6_KEY49_THR          (1049)
#define MUTUAL6_KEY50_THR          (1050)
#define MUTUAL6_KEY51_THR          (1051)
#define MUTUAL6_KEY52_THR          (1052)
#define MUTUAL6_KEY53_THR          (1053)
#define MUTUAL6_KEY54_THR          (1054)
#define MUTUAL6_KEY55_THR          (1055)
#define MUTUAL6_KEY56_THR          (1056)
#define MUTUAL6_KEY57_THR          (1057)
#define MUTUAL6_KEY58_THR          (1058)
#define MUTUAL6_KEY59_THR          (1059)
#define MUTUAL6_KEY60_THR          (1060)
#define MUTUAL6_KEY61_THR          (1061)
#define MUTUAL6_KEY62_THR          (1062)
#define MUTUAL6_KEY63_THR          (1063)

/* Hysteresis set up data */
#define MUTUAL6_KEY00_HYS          (20)
#define MUTUAL6_KEY01_HYS          (21)
#define MUTUAL6_KEY02_HYS          (22)
#define MUTUAL6_KEY03_HYS          (23)
#define MUTUAL6_KEY04_HYS          (24)
#define MUTUAL6_KEY05_HYS          (25)
#define MUTUAL6_KEY06_HYS          (26)
#define MUTUAL6_KEY07_HYS          (27)
#define MUTUAL6_KEY08_HYS          (28)
#define MUTUAL6_KEY09_HYS          (29)
#define MUTUAL6_KEY10_HYS          (30)
#define MUTUAL6_KEY11_HYS          (31)
#define MUTUAL6_KEY12_HYS          (32)
#define MUTUAL6_KEY13_HYS          (33)
#define MUTUAL6_KEY14_HYS          (34)
#define MUTUAL6_KEY15_HYS          (35)
#define MUTUAL6_KEY16_HYS          (36)
#define MUTUAL6_KEY17_HYS          (37)
#define MUTUAL6_KEY18_HYS          (38)
#define MUTUAL6_KEY19_HYS          (39)
#define MUTUAL6_KEY20_HYS          (40)
#define MUTUAL6_KEY21_HYS          (41)
#define MUTUAL6_KEY22_HYS          (42)
#define MUTUAL6_KEY23_HYS          (43)
#define MUTUAL6_KEY24_HYS          (44)
#define MUTUAL6_KEY25_HYS          (45)
#define MUTUAL6_KEY26_HYS          (46)
#define MUTUAL6_KEY27_HYS          (47)
#define MUTUAL6_KEY28_HYS          (48)
#define MUTUAL6_KEY29_HYS          (49)
#define MUTUAL6_KEY30_HYS          (50)
#define MUTUAL6_KEY31_HYS          (51)
#define MUTUAL6_KEY32_HYS          (52)
#define MUTUAL6_KEY33_HYS          (53)
#define MUTUAL6_KEY34_HYS          (54)
#define MUTUAL6_KEY35_HYS          (55)
#define MUTUAL6_KEY36_HYS          (56)
#define MUTUAL6_KEY37_HYS          (57)
#define MUTUAL6_KEY38_HYS          (58)
#define MUTUAL6_KEY39_HYS          (59)
#define MUTUAL6_KEY40_HYS          (60)
#define MUTUAL6_KEY41_HYS          (61)
#define MUTUAL6_KEY42_HYS          (62)
#define MUTUAL6_KEY43_HYS          (63)
#define MUTUAL6_KEY44_HYS          (64)
#define MUTUAL6_KEY45_HYS          (65)
#define MUTUAL6_KEY46_HYS          (66)
#define MUTUAL6_KEY47_HYS          (67)
#define MUTUAL6_KEY48_HYS          (68)
#define MUTUAL6_KEY49_HYS          (69)
#define MUTUAL6_KEY50_HYS          (70)
#define MUTUAL6_KEY51_HYS          (71)
#define MUTUAL6_KEY52_HYS          (72)
#define MUTUAL6_KEY53_HYS          (73)
#define MUTUAL6_KEY54_HYS          (74)
#define MUTUAL6_KEY55_HYS          (75)
#define MUTUAL6_KEY56_HYS          (76)
#define MUTUAL6_KEY57_HYS          (77)
#define MUTUAL6_KEY58_HYS          (78)
#define MUTUAL6_KEY59_HYS          (79)
#define MUTUAL6_KEY60_HYS          (80)
#define MUTUAL6_KEY61_HYS          (81)
#define MUTUAL6_KEY62_HYS          (82)
#define MUTUAL6_KEY63_HYS          (83)

/*====================================================================================================================*/
/*=====    Mutual 7 touch parameter definition    ====================================================================*/
/*====================================================================================================================*/
#define MUTUAL7_KEY00_USE        (0)
#define MUTUAL7_KEY01_USE        (0)
#define MUTUAL7_KEY02_USE        (0)
#define MUTUAL7_KEY03_USE        (0)
#define MUTUAL7_KEY04_USE        (0)
#define MUTUAL7_KEY05_USE        (0)
#define MUTUAL7_KEY06_USE        (0)
#define MUTUAL7_KEY07_USE        (0)
#define MUTUAL7_KEY08_USE        (0)
#define MUTUAL7_KEY09_USE        (0)
#define MUTUAL7_KEY10_USE        (0)
#define MUTUAL7_KEY11_USE        (0)
#define MUTUAL7_KEY12_USE        (0)
#define MUTUAL7_KEY13_USE        (0)
#define MUTUAL7_KEY14_USE        (0)
#define MUTUAL7_KEY15_USE        (0)
#define MUTUAL7_KEY16_USE        (0)
#define MUTUAL7_KEY17_USE        (0)
#define MUTUAL7_KEY18_USE        (0)
#define MUTUAL7_KEY19_USE        (0)
#define MUTUAL7_KEY20_USE        (0)
#define MUTUAL7_KEY21_USE        (0)
#define MUTUAL7_KEY22_USE        (0)
#define MUTUAL7_KEY23_USE        (0)
#define MUTUAL7_KEY24_USE        (0)
#define MUTUAL7_KEY25_USE        (0)
#define MUTUAL7_KEY26_USE        (0)
#define MUTUAL7_KEY27_USE        (0)
#define MUTUAL7_KEY28_USE        (0)
#define MUTUAL7_KEY29_USE        (0)
#define MUTUAL7_KEY30_USE        (0)
#define MUTUAL7_KEY31_USE        (0)
#define MUTUAL7_KEY32_USE        (0)
#define MUTUAL7_KEY33_USE        (0)
#define MUTUAL7_KEY34_USE        (0)
#define MUTUAL7_KEY35_USE        (0)
#define MUTUAL7_KEY36_USE        (0)
#define MUTUAL7_KEY37_USE        (0)
#define MUTUAL7_KEY38_USE        (0)
#define MUTUAL7_KEY39_USE        (0)
#define MUTUAL7_KEY40_USE        (0)
#define MUTUAL7_KEY41_USE        (0)
#define MUTUAL7_KEY42_USE        (0)
#define MUTUAL7_KEY43_USE        (0)
#define MUTUAL7_KEY44_USE        (0)
#define MUTUAL7_KEY45_USE        (0)
#define MUTUAL7_KEY46_USE        (0)
#define MUTUAL7_KEY47_USE        (0)
#define MUTUAL7_KEY48_USE        (0)
#define MUTUAL7_KEY49_USE        (0)
#define MUTUAL7_KEY50_USE        (0)
#define MUTUAL7_KEY51_USE        (0)
#define MUTUAL7_KEY52_USE        (0)
#define MUTUAL7_KEY53_USE        (0)
#define MUTUAL7_KEY54_USE        (0)
#define MUTUAL7_KEY55_USE        (0)
#define MUTUAL7_KEY56_USE        (0)
#define MUTUAL7_KEY57_USE        (0)
#define MUTUAL7_KEY58_USE        (0)
#define MUTUAL7_KEY59_USE        (0)
#define MUTUAL7_KEY60_USE        (0)
#define MUTUAL7_KEY61_USE        (0)
#define MUTUAL7_KEY62_USE        (0)
#define MUTUAL7_KEY63_USE        (0)

#define MUTUAL7_KEY_USE_GROUP0   ((MUTUAL7_KEY00_USE      ) + (MUTUAL7_KEY01_USE <<  1) + (MUTUAL7_KEY02_USE <<  2) + \
                                  (MUTUAL7_KEY03_USE <<  3) + (MUTUAL7_KEY04_USE <<  4) + (MUTUAL7_KEY05_USE <<  5) + \
                                  (MUTUAL7_KEY06_USE <<  6) + (MUTUAL7_KEY07_USE <<  7) + (MUTUAL7_KEY08_USE <<  8) + \
                                  (MUTUAL7_KEY09_USE <<  9) + (MUTUAL7_KEY10_USE << 10) + (MUTUAL7_KEY11_USE << 11) + \
                                  (MUTUAL7_KEY12_USE << 12) + (MUTUAL7_KEY13_USE << 13) + (MUTUAL7_KEY14_USE << 14) + \
                                  (MUTUAL7_KEY15_USE << 15))

#define MUTUAL7_KEY_USE_GROUP1   ((MUTUAL7_KEY16_USE      ) + (MUTUAL7_KEY17_USE <<  1) + (MUTUAL7_KEY18_USE <<  2) + \
                                  (MUTUAL7_KEY19_USE <<  3) + (MUTUAL7_KEY20_USE <<  4) + (MUTUAL7_KEY21_USE <<  5) + \
                                  (MUTUAL7_KEY22_USE <<  6) + (MUTUAL7_KEY23_USE <<  7) + (MUTUAL7_KEY24_USE <<  8) + \
                                  (MUTUAL7_KEY25_USE <<  9) + (MUTUAL7_KEY26_USE << 10) + (MUTUAL7_KEY27_USE << 11) + \
                                  (MUTUAL7_KEY28_USE << 12) + (MUTUAL7_KEY29_USE << 13) + (MUTUAL7_KEY30_USE << 14) + \
                                  (MUTUAL7_KEY31_USE << 15))

#define MUTUAL7_KEY_USE_GROUP2   ((MUTUAL7_KEY32_USE      ) + (MUTUAL7_KEY33_USE <<  1) + (MUTUAL7_KEY34_USE <<  2) + \
                                  (MUTUAL7_KEY35_USE <<  3) + (MUTUAL7_KEY36_USE <<  4) + (MUTUAL7_KEY37_USE <<  5) + \
                                  (MUTUAL7_KEY36_USE <<  6) + (MUTUAL7_KEY39_USE <<  7) + (MUTUAL7_KEY40_USE <<  8) + \
                                  (MUTUAL7_KEY41_USE <<  9) + (MUTUAL7_KEY42_USE << 10) + (MUTUAL7_KEY43_USE << 11) + \
                                  (MUTUAL7_KEY44_USE << 12) + (MUTUAL7_KEY45_USE << 13) + (MUTUAL7_KEY46_USE << 14) + \
                                  (MUTUAL7_KEY47_USE << 15))

#define MUTUAL7_KEY_USE_GROUP3   ((MUTUAL7_KEY48_USE      ) + (MUTUAL7_KEY49_USE <<  1) + (MUTUAL7_KEY50_USE <<  2) + \
                                  (MUTUAL7_KEY51_USE <<  3) + (MUTUAL7_KEY52_USE <<  4) + (MUTUAL7_KEY53_USE <<  5) + \
                                  (MUTUAL7_KEY54_USE <<  6) + (MUTUAL7_KEY55_USE <<  7) + (MUTUAL7_KEY56_USE <<  8) + \
                                  (MUTUAL7_KEY57_USE <<  9) + (MUTUAL7_KEY58_USE << 10) + (MUTUAL7_KEY59_USE << 11) + \
                                  (MUTUAL7_KEY60_USE << 12) + (MUTUAL7_KEY61_USE << 13) + (MUTUAL7_KEY62_USE << 14) + \
                                  (MUTUAL7_KEY63_USE << 15))

#if (MUTUAL7_KEY_USE_GROUP3 > 0)
    #define MUTUAL7_MAX_GROUP        (4)
#elif (MUTUAL7_KEY_USE_GROUP2 > 0)
    #define MUTUAL7_MAX_GROUP        (3)
#elif (MUTUAL7_KEY_USE_GROUP1 > 0)
    #define MUTUAL7_MAX_GROUP        (2)
#else
    #define MUTUAL7_MAX_GROUP        (1)
#endif

#define MUTUAL7_KEY_NUM           (MUTUAL7_KEY00_USE + MUTUAL7_KEY01_USE + MUTUAL7_KEY02_USE + MUTUAL7_KEY03_USE + \
                                   MUTUAL7_KEY04_USE + MUTUAL7_KEY05_USE + MUTUAL7_KEY06_USE + MUTUAL7_KEY07_USE + \
                                   MUTUAL7_KEY08_USE + MUTUAL7_KEY09_USE + MUTUAL7_KEY10_USE + MUTUAL7_KEY11_USE + \
                                   MUTUAL7_KEY12_USE + MUTUAL7_KEY13_USE + MUTUAL7_KEY14_USE + MUTUAL7_KEY15_USE + \
                                   MUTUAL7_KEY16_USE + MUTUAL7_KEY17_USE + MUTUAL7_KEY18_USE + MUTUAL7_KEY19_USE + \
                                   MUTUAL7_KEY20_USE + MUTUAL7_KEY21_USE + MUTUAL7_KEY22_USE + MUTUAL7_KEY23_USE + \
                                   MUTUAL7_KEY24_USE + MUTUAL7_KEY25_USE + MUTUAL7_KEY26_USE + MUTUAL7_KEY27_USE + \
                                   MUTUAL7_KEY28_USE + MUTUAL7_KEY29_USE + MUTUAL7_KEY30_USE + MUTUAL7_KEY31_USE + \
                                   MUTUAL7_KEY32_USE + MUTUAL7_KEY33_USE + MUTUAL7_KEY34_USE + MUTUAL7_KEY35_USE + \
                                   MUTUAL7_KEY36_USE + MUTUAL7_KEY37_USE + MUTUAL7_KEY38_USE + MUTUAL7_KEY39_USE + \
                                   MUTUAL7_KEY40_USE + MUTUAL7_KEY41_USE + MUTUAL7_KEY42_USE + MUTUAL7_KEY43_USE + \
                                   MUTUAL7_KEY44_USE + MUTUAL7_KEY45_USE + MUTUAL7_KEY46_USE + MUTUAL7_KEY47_USE + \
                                   MUTUAL7_KEY48_USE + MUTUAL7_KEY49_USE + MUTUAL7_KEY50_USE + MUTUAL7_KEY51_USE + \
                                   MUTUAL7_KEY52_USE + MUTUAL7_KEY53_USE + MUTUAL7_KEY54_USE + MUTUAL7_KEY55_USE + \
                                   MUTUAL7_KEY56_USE + MUTUAL7_KEY57_USE + MUTUAL7_KEY58_USE + MUTUAL7_KEY59_USE + \
                                   MUTUAL7_KEY60_USE + MUTUAL7_KEY61_USE + MUTUAL7_KEY62_USE + MUTUAL7_KEY63_USE)

/* ON/OFF threshold set up data */
#define MUTUAL7_KEY00_THR          (1000)
#define MUTUAL7_KEY01_THR          (1001)
#define MUTUAL7_KEY02_THR          (1002)
#define MUTUAL7_KEY03_THR          (1003)
#define MUTUAL7_KEY04_THR          (1004)
#define MUTUAL7_KEY05_THR          (1005)
#define MUTUAL7_KEY06_THR          (1006)
#define MUTUAL7_KEY07_THR          (1007)
#define MUTUAL7_KEY08_THR          (1008)
#define MUTUAL7_KEY09_THR          (1009)
#define MUTUAL7_KEY10_THR          (1010)
#define MUTUAL7_KEY11_THR          (1011)
#define MUTUAL7_KEY12_THR          (1012)
#define MUTUAL7_KEY13_THR          (1013)
#define MUTUAL7_KEY14_THR          (1014)
#define MUTUAL7_KEY15_THR          (1015)
#define MUTUAL7_KEY16_THR          (1016)
#define MUTUAL7_KEY17_THR          (1017)
#define MUTUAL7_KEY18_THR          (1018)
#define MUTUAL7_KEY19_THR          (1019)
#define MUTUAL7_KEY20_THR          (1020)
#define MUTUAL7_KEY21_THR          (1021)
#define MUTUAL7_KEY22_THR          (1022)
#define MUTUAL7_KEY23_THR          (1023)
#define MUTUAL7_KEY24_THR          (1024)
#define MUTUAL7_KEY25_THR          (1025)
#define MUTUAL7_KEY26_THR          (1026)
#define MUTUAL7_KEY27_THR          (1027)
#define MUTUAL7_KEY28_THR          (1028)
#define MUTUAL7_KEY29_THR          (1029)
#define MUTUAL7_KEY30_THR          (1030)
#define MUTUAL7_KEY31_THR          (1031)
#define MUTUAL7_KEY32_THR          (1032)
#define MUTUAL7_KEY33_THR          (1033)
#define MUTUAL7_KEY34_THR          (1034)
#define MUTUAL7_KEY35_THR          (1035)
#define MUTUAL7_KEY36_THR          (1036)
#define MUTUAL7_KEY37_THR          (1037)
#define MUTUAL7_KEY38_THR          (1038)
#define MUTUAL7_KEY39_THR          (1039)
#define MUTUAL7_KEY40_THR          (1040)
#define MUTUAL7_KEY41_THR          (1041)
#define MUTUAL7_KEY42_THR          (1042)
#define MUTUAL7_KEY43_THR          (1043)
#define MUTUAL7_KEY44_THR          (1044)
#define MUTUAL7_KEY45_THR          (1045)
#define MUTUAL7_KEY46_THR          (1046)
#define MUTUAL7_KEY47_THR          (1047)
#define MUTUAL7_KEY48_THR          (1048)
#define MUTUAL7_KEY49_THR          (1049)
#define MUTUAL7_KEY50_THR          (1050)
#define MUTUAL7_KEY51_THR          (1051)
#define MUTUAL7_KEY52_THR          (1052)
#define MUTUAL7_KEY53_THR          (1053)
#define MUTUAL7_KEY54_THR          (1054)
#define MUTUAL7_KEY55_THR          (1055)
#define MUTUAL7_KEY56_THR          (1056)
#define MUTUAL7_KEY57_THR          (1057)
#define MUTUAL7_KEY58_THR          (1058)
#define MUTUAL7_KEY59_THR          (1059)
#define MUTUAL7_KEY60_THR          (1060)
#define MUTUAL7_KEY61_THR          (1061)
#define MUTUAL7_KEY62_THR          (1062)
#define MUTUAL7_KEY63_THR          (1063)

/* Hysteresis set up data */
#define MUTUAL7_KEY00_HYS          (20)
#define MUTUAL7_KEY01_HYS          (21)
#define MUTUAL7_KEY02_HYS          (22)
#define MUTUAL7_KEY03_HYS          (23)
#define MUTUAL7_KEY04_HYS          (24)
#define MUTUAL7_KEY05_HYS          (25)
#define MUTUAL7_KEY06_HYS          (26)
#define MUTUAL7_KEY07_HYS          (27)
#define MUTUAL7_KEY08_HYS          (28)
#define MUTUAL7_KEY09_HYS          (29)
#define MUTUAL7_KEY10_HYS          (30)
#define MUTUAL7_KEY11_HYS          (31)
#define MUTUAL7_KEY12_HYS          (32)
#define MUTUAL7_KEY13_HYS          (33)
#define MUTUAL7_KEY14_HYS          (34)
#define MUTUAL7_KEY15_HYS          (35)
#define MUTUAL7_KEY16_HYS          (36)
#define MUTUAL7_KEY17_HYS          (37)
#define MUTUAL7_KEY18_HYS          (38)
#define MUTUAL7_KEY19_HYS          (39)
#define MUTUAL7_KEY20_HYS          (40)
#define MUTUAL7_KEY21_HYS          (41)
#define MUTUAL7_KEY22_HYS          (42)
#define MUTUAL7_KEY23_HYS          (43)
#define MUTUAL7_KEY24_HYS          (44)
#define MUTUAL7_KEY25_HYS          (45)
#define MUTUAL7_KEY26_HYS          (46)
#define MUTUAL7_KEY27_HYS          (47)
#define MUTUAL7_KEY28_HYS          (48)
#define MUTUAL7_KEY29_HYS          (49)
#define MUTUAL7_KEY30_HYS          (50)
#define MUTUAL7_KEY31_HYS          (51)
#define MUTUAL7_KEY32_HYS          (52)
#define MUTUAL7_KEY33_HYS          (53)
#define MUTUAL7_KEY34_HYS          (54)
#define MUTUAL7_KEY35_HYS          (55)
#define MUTUAL7_KEY36_HYS          (56)
#define MUTUAL7_KEY37_HYS          (57)
#define MUTUAL7_KEY38_HYS          (58)
#define MUTUAL7_KEY39_HYS          (59)
#define MUTUAL7_KEY40_HYS          (60)
#define MUTUAL7_KEY41_HYS          (61)
#define MUTUAL7_KEY42_HYS          (62)
#define MUTUAL7_KEY43_HYS          (63)
#define MUTUAL7_KEY44_HYS          (64)
#define MUTUAL7_KEY45_HYS          (65)
#define MUTUAL7_KEY46_HYS          (66)
#define MUTUAL7_KEY47_HYS          (67)
#define MUTUAL7_KEY48_HYS          (68)
#define MUTUAL7_KEY49_HYS          (69)
#define MUTUAL7_KEY50_HYS          (70)
#define MUTUAL7_KEY51_HYS          (71)
#define MUTUAL7_KEY52_HYS          (72)
#define MUTUAL7_KEY53_HYS          (73)
#define MUTUAL7_KEY54_HYS          (74)
#define MUTUAL7_KEY55_HYS          (75)
#define MUTUAL7_KEY56_HYS          (76)
#define MUTUAL7_KEY57_HYS          (77)
#define MUTUAL7_KEY58_HYS          (78)
#define MUTUAL7_KEY59_HYS          (79)
#define MUTUAL7_KEY60_HYS          (80)
#define MUTUAL7_KEY61_HYS          (81)
#define MUTUAL7_KEY62_HYS          (82)
#define MUTUAL7_KEY63_HYS          (83)

#define NO_SENSOR                        (255)              /* Not used sensor                                       */
#define DUMMY_ID                         (1)                /* Case SLIDER_NUMBER or WHEEL_NUMBER = 0                */
/**********************************************************************************************************************
*****    Slider common values    **************************************************************************************
**********************************************************************************************************************/
#define SLIDER_NUMBER                    (1)                /* Nummber of slider                                     */
#define SLIDER_SENSOR_MAX                (10)               /* Number of slider composition maximum TS               */

/* Slider0 Configuration */
#define SLIDER0_00                       (27)                /* Slider ID 0 sensor number 00                          */
#define SLIDER0_00_NORM                  (5510)             /* Slider ID 0 sensor number 00 normalization value      */
#define SLIDER0_00_NOISE                 (2918)              /* Slider ID 0 sensor number 00 noise value              */
#define SLIDER0_01                       (29)                /* Slider ID 0 sensor number 01                          */
#define SLIDER0_01_NORM                  (6101)             /* Slider ID 0 sensor number 01 normalization value      */
#define SLIDER0_01_NOISE                 (3367)              /* Slider ID 0 sensor number 01 noise value              */
#define SLIDER0_02                       (22)                /* Slider ID 0 sensor number 02                          */
#define SLIDER0_02_NORM                  (5032)             /* Slider ID 0 sensor number 02 normalization value      */
#define SLIDER0_02_NOISE                 (3436)              /* Slider ID 0 sensor number 02 noise value              */
#define SLIDER0_03                       (26)                /* Slider ID 0 sensor number 03                          */
#define SLIDER0_03_NORM                  (6380)             /* Slider ID 0 sensor number 03 normalization value      */
#define SLIDER0_03_NOISE                 (3119)              /* Slider ID 0 sensor number 03 noise value              */
#define SLIDER0_04                       (20)                /* Slider ID 0 sensor number 04                          */
#define SLIDER0_04_NORM                  (6919)             /* Slider ID 0 sensor number 04 normalization value      */
#define SLIDER0_04_NOISE                 (2725)              /* Slider ID 0 sensor number 04 noise value              */
#define SLIDER0_05                       NO_SENSOR          /* Slider ID 0 sensor number 05                          */
#define SLIDER0_05_NORM                  (1000)             /* Slider ID 0 sensor number 05 normalization value      */
#define SLIDER0_05_NOISE                 (100)              /* Slider ID 0 sensor number 05 noise value              */
#define SLIDER0_06                       NO_SENSOR          /* Slider ID 0 sensor number 06                          */
#define SLIDER0_06_NORM                  (1000)             /* Slider ID 0 sensor number 06 normalization value      */
#define SLIDER0_06_NOISE                 (100)              /* Slider ID 0 sensor number 06 noise value              */
#define SLIDER0_07                       NO_SENSOR          /* Slider ID 0 sensor number 07                          */
#define SLIDER0_07_NORM                  (1000)             /* Slider ID 0 sensor number 07 normalization value      */
#define SLIDER0_07_NOISE                 (100)              /* Slider ID 0 sensor number 07 noise value              */
#define SLIDER0_08                       NO_SENSOR          /* Slider ID 0 sensor number 08                          */
#define SLIDER0_08_NORM                  (1000)             /* Slider ID 0 sensor number 08 normalization value      */
#define SLIDER0_08_NOISE                 (100)              /* Slider ID 0 sensor number 08 noise value              */
#define SLIDER0_09                       NO_SENSOR          /* Slider ID 0 sensor number 09                          */
#define SLIDER0_09_NORM                  (1000)             /* Slider ID 0 sensor number 09 normalization value      */
#define SLIDER0_09_NOISE                 (100)              /* Slider ID 0 sensor number 09 noise value              */

#define SLIDER0_SENSOR_NUMBER            (5)                /* Slider ID 0                                           */
#define SLIDER0_THRESHOLD                (5428)              /* Slider ID 0 position calculation threshold            */
#define SLIDER0_RESOLUTION               (1)                /* Slider ID 0 resolution (1=100,2=50,4=25,5=20,10=10)   */

/* Slider1 Configuration */
#define SLIDER1_00                       NO_SENSOR          /* Slider ID 1 sensor number 00                          */
#define SLIDER1_00_NORM                  (1000)             /* Slider ID 1 sensor number 00 normalization value      */
#define SLIDER1_00_NOISE                 (100)              /* Slider ID 1 sensor number 00 noise value              */
#define SLIDER1_01                       NO_SENSOR          /* Slider ID 1 sensor number 01                          */
#define SLIDER1_01_NORM                  (1000)             /* Slider ID 1 sensor number 01 normalization value      */
#define SLIDER1_01_NOISE                 (100)              /* Slider ID 1 sensor number 01 noise value              */
#define SLIDER1_02                       NO_SENSOR          /* Slider ID 1 sensor number 02                         */
#define SLIDER1_02_NORM                  (1000)             /* Slider ID 1 sensor number 02 normalization value      */
#define SLIDER1_02_NOISE                 (100)              /* Slider ID 1 sensor number 02 noise value              */
#define SLIDER1_03                       NO_SENSOR          /* Slider ID 1 sensor number 03                          */
#define SLIDER1_03_NORM                  (1000)             /* Slider ID 1 sensor number 03 normalization value      */
#define SLIDER1_03_NOISE                 (100)              /* Slider ID 1 sensor number 03 noise value              */
#define SLIDER1_04                       NO_SENSOR          /* Slider ID 1 sensor number 04                          */
#define SLIDER1_04_NORM                  (1000)             /* Slider ID 1 sensor number 04 normalization value      */
#define SLIDER1_04_NOISE                 (100)              /* Slider ID 1 sensor number 04 noise value              */
#define SLIDER1_05                       NO_SENSOR          /* Slider ID 1 sensor number 05                          */
#define SLIDER1_05_NORM                  (1000)             /* Slider ID 1 sensor number 05 normalization value      */
#define SLIDER1_05_NOISE                 (100)              /* Slider ID 1 sensor number 05 noise value              */
#define SLIDER1_06                       NO_SENSOR          /* Slider ID 1 sensor number 06                          */
#define SLIDER1_06_NORM                  (1000)             /* Slider ID 1 sensor number 06 normalization value      */
#define SLIDER1_06_NOISE                 (100)              /* Slider ID 1 sensor number 06 noise value              */
#define SLIDER1_07                       NO_SENSOR          /* Slider ID 1 sensor number 07                          */
#define SLIDER1_07_NORM                  (1000)             /* Slider ID 1 sensor number 07 normalization value      */
#define SLIDER1_07_NOISE                 (100)              /* Slider ID 1 sensor number 07 noise value              */
#define SLIDER1_08                       NO_SENSOR          /* Slider ID 1 sensor number 08                          */
#define SLIDER1_08_NORM                  (1000)             /* Slider ID 1 sensor number 08 normalization value      */
#define SLIDER1_08_NOISE                 (100)              /* Slider ID 1 sensor number 08 noise value              */
#define SLIDER1_09                       NO_SENSOR          /* Slider ID 1 sensor number 09                          */
#define SLIDER1_09_NORM                  (1000)             /* Slider ID 1 sensor number 09 normalization value      */
#define SLIDER1_09_NOISE                 (100)              /* Slider ID 1 sensor number 09 noise value              */

#define SLIDER1_SENSOR_NUMBER            (0)                /* Slider ID 1                                           */
#define SLIDER1_THRESHOLD                (1000)             /* Slider ID 1 position calculation threshold            */
#define SLIDER1_RESOLUTION               (1)                /* Slider ID 1 resolution (1=100,2=50,4=25,5=20,10=10)   */

/* Slider2 Configuration */
#define SLIDER2_00                       NO_SENSOR          /* Slider ID 2 sensor number 00                          */
#define SLIDER2_00_NORM                  (1000)             /* Slider ID 2 sensor number 00 normalization value      */
#define SLIDER2_00_NOISE                 (100)              /* Slider ID 2 sensor number 00 noise value              */
#define SLIDER2_01                       NO_SENSOR          /* Slider ID 2 sensor number 01                          */
#define SLIDER2_01_NORM                  (1000)             /* Slider ID 2 sensor number 01 normalization value      */
#define SLIDER2_01_NOISE                 (100)              /* Slider ID 2 sensor number 01 noise value              */
#define SLIDER2_02                       NO_SENSOR          /* Slider ID 2 sensor number 02                          */
#define SLIDER2_02_NORM                  (1000)             /* Slider ID 2 sensor number 02 normalization value      */
#define SLIDER2_02_NOISE                 (100)              /* Slider ID 2 sensor number 02 noise value              */
#define SLIDER2_03                       NO_SENSOR          /* Slider ID 2 sensor number 03                          */
#define SLIDER2_03_NORM                  (1000)             /* Slider ID 2 sensor number 03 normalization value      */
#define SLIDER2_03_NOISE                 (100)              /* Slider ID 2 sensor number 03 noise value              */
#define SLIDER2_04                       NO_SENSOR          /* Slider ID 2 sensor number 04                          */
#define SLIDER2_04_NORM                  (1000)             /* Slider ID 2 sensor number 04 normalization value      */
#define SLIDER2_04_NOISE                 (100)              /* Slider ID 2 sensor number 04 noise value              */
#define SLIDER2_05                       NO_SENSOR          /* Slider ID 2 sensor number 05                          */
#define SLIDER2_05_NORM                  (1000)             /* Slider ID 2 sensor number 05 normalization value      */
#define SLIDER2_05_NOISE                 (100)              /* Slider ID 2 sensor number 05 noise value              */
#define SLIDER2_06                       NO_SENSOR          /* Slider ID 2 sensor number 06                          */
#define SLIDER2_06_NORM                  (1000)             /* Slider ID 2 sensor number 06 normalization value      */
#define SLIDER2_06_NOISE                 (100)              /* Slider ID 2 sensor number 06 noise value              */
#define SLIDER2_07                       NO_SENSOR          /* Slider ID 2 sensor number 07                          */
#define SLIDER2_07_NORM                  (1000)             /* Slider ID 2 sensor number 07 normalization value      */
#define SLIDER2_07_NOISE                 (100)              /* Slider ID 2 sensor number 07 noise value              */
#define SLIDER2_08                       NO_SENSOR          /* Slider ID 2 sensor number 08                          */
#define SLIDER2_08_NORM                  (1000)             /* Slider ID 2 sensor number 08 normalization value      */
#define SLIDER2_08_NOISE                 (100)              /* Slider ID 2 sensor number 08 noise value              */
#define SLIDER2_09                       NO_SENSOR          /* Slider ID 2 sensor number 09                          */
#define SLIDER2_09_NORM                  (1000)             /* Slider ID 2 sensor number 09 normalization value      */
#define SLIDER2_09_NOISE                 (100)              /* Slider ID 2 sensor number 09 noise value              */

#define SLIDER2_SENSOR_NUMBER            (0)                /* Slider ID 2                                           */
#define SLIDER2_THRESHOLD                (1000)             /* Slider ID 2 position calculation threshold            */
#define SLIDER2_RESOLUTION               (1)                /* Slider ID 2 resolution (1=100,2=50,4=25,5=20,10=10)   */

/* Slider3 Configuration */
#define SLIDER3_00                       NO_SENSOR          /* Slider ID 3 sensor number 00                          */
#define SLIDER3_00_NORM                  (1000)             /* Slider ID 3 sensor number 00 normalization value      */
#define SLIDER3_00_NOISE                 (100)              /* Slider ID 3 sensor number 00 noise value              */
#define SLIDER3_01                       NO_SENSOR          /* Slider ID 3 sensor number 01                          */
#define SLIDER3_01_NORM                  (1000)             /* Slider ID 3 sensor number 01 normalization value      */
#define SLIDER3_01_NOISE                 (100)              /* Slider ID 3 sensor number 01 noise value              */
#define SLIDER3_02                       NO_SENSOR          /* Slider ID 3 sensor number 02                          */
#define SLIDER3_02_NORM                  (1000)             /* Slider ID 3 sensor number 02 normalization value      */
#define SLIDER3_02_NOISE                 (100)              /* Slider ID 3 sensor number 02 noise value              */
#define SLIDER3_03                       NO_SENSOR          /* Slider ID 3 sensor number 03                          */
#define SLIDER3_03_NORM                  (1000)             /* Slider ID 3 sensor number 03 normalization value      */
#define SLIDER3_03_NOISE                 (100)              /* Slider ID 3 sensor number 03 noise value              */
#define SLIDER3_04                       NO_SENSOR          /* Slider ID 3 sensor number 04                          */
#define SLIDER3_04_NORM                  (1000)             /* Slider ID 3 sensor number 04 normalization value      */
#define SLIDER3_04_NOISE                 (100)              /* Slider ID 3 sensor number 04 noise value              */
#define SLIDER3_05                       NO_SENSOR          /* Slider ID 3 sensor number 05                          */
#define SLIDER3_05_NORM                  (1000)             /* Slider ID 3 sensor number 05 normalization value      */
#define SLIDER3_05_NOISE                 (100)              /* Slider ID 3 sensor number 05 noise value              */
#define SLIDER3_06                       NO_SENSOR          /* Slider ID 3 sensor number 06                          */
#define SLIDER3_06_NORM                  (1000)             /* Slider ID 3 sensor number 06 normalization value      */
#define SLIDER3_06_NOISE                 (100)              /* Slider ID 3 sensor number 06 noise value              */
#define SLIDER3_07                       NO_SENSOR          /* Slider ID 3 sensor number 07                          */
#define SLIDER3_07_NORM                  (1000)             /* Slider ID 3 sensor number 07 normalization value      */
#define SLIDER3_07_NOISE                 (100)              /* Slider ID 3 sensor number 07 noise value              */
#define SLIDER3_08                       NO_SENSOR          /* Slider ID 3 sensor number 08                          */
#define SLIDER3_08_NORM                  (1000)             /* Slider ID 3 sensor number 08 normalization value      */
#define SLIDER3_08_NOISE                 (100)              /* Slider ID 3 sensor number 08 noise value              */
#define SLIDER3_09                       NO_SENSOR          /* Slider ID 3 sensor number 09                          */
#define SLIDER3_09_NORM                  (1000)             /* Slider ID 3 sensor number 09 normalization value      */
#define SLIDER3_09_NOISE                 (100)              /* Slider ID 3 sensor number 09 noise value              */

#define SLIDER3_SENSOR_NUMBER            (0)                /* Slider ID 3                                           */
#define SLIDER3_THRESHOLD                (1000)             /* Slider ID 3 position calculation threshold            */
#define SLIDER3_RESOLUTION               (1)                /* Slider ID 3 resolution (1=100,2=50,4=25,5=20,10=10)   */

/* Slider4 Configuration */
#define SLIDER4_00                       NO_SENSOR          /* Slider ID 4 sensor number 00                          */
#define SLIDER4_00_NORM                  (1000)             /* Slider ID 4 sensor number 00 normalization value      */
#define SLIDER4_00_NOISE                 (100)              /* Slider ID 4 sensor number 00 noise value              */
#define SLIDER4_01                       NO_SENSOR          /* Slider ID 4 sensor number 01                          */
#define SLIDER4_01_NORM                  (1000)             /* Slider ID 4 sensor number 01 normalization value      */
#define SLIDER4_01_NOISE                 (100)              /* Slider ID 4 sensor number 01 noise value              */
#define SLIDER4_02                       NO_SENSOR          /* Slider ID 4 sensor number 02                          */
#define SLIDER4_02_NORM                  (1000)             /* Slider ID 4 sensor number 02 normalization value      */
#define SLIDER4_02_NOISE                 (100)              /* Slider ID 4 sensor number 02 noise value              */
#define SLIDER4_03                       NO_SENSOR          /* Slider ID 4 sensor number 03                          */
#define SLIDER4_03_NORM                  (1000)             /* Slider ID 4 sensor number 03 normalization value      */
#define SLIDER4_03_NOISE                 (100)              /* Slider ID 4 sensor number 03 noise value              */
#define SLIDER4_04                       NO_SENSOR          /* Slider ID 4 sensor number 04                          */
#define SLIDER4_04_NORM                  (1000)             /* Slider ID 4 sensor number 04 normalization value      */
#define SLIDER4_04_NOISE                 (100)              /* Slider ID 4 sensor number 04 noise value              */
#define SLIDER4_05                       NO_SENSOR          /* Slider ID 4 sensor number 05                          */
#define SLIDER4_05_NORM                  (1000)             /* Slider ID 4 sensor number 05 normalization value      */
#define SLIDER4_05_NOISE                 (100)              /* Slider ID 4 sensor number 05 noise value              */
#define SLIDER4_06                       NO_SENSOR          /* Slider ID 4 sensor number 06                          */
#define SLIDER4_06_NORM                  (1000)             /* Slider ID 4 sensor number 06 normalization value      */
#define SLIDER4_06_NOISE                 (100)              /* Slider ID 4 sensor number 06 noise value              */
#define SLIDER4_07                       NO_SENSOR          /* Slider ID 4 sensor number 07                          */
#define SLIDER4_07_NORM                  (1000)             /* Slider ID 4 sensor number 07 normalization value      */
#define SLIDER4_07_NOISE                 (100)              /* Slider ID 4 sensor number 07 noise value              */
#define SLIDER4_08                       NO_SENSOR          /* Slider ID 4 sensor number 08                          */
#define SLIDER4_08_NORM                  (1000)             /* Slider ID 4 sensor number 08 normalization value      */
#define SLIDER4_08_NOISE                 (100)              /* Slider ID 4 sensor number 08 noise value              */
#define SLIDER4_09                       NO_SENSOR          /* Slider ID 4 sensor number 09                          */
#define SLIDER4_09_NORM                  (1000)             /* Slider ID 4 sensor number 09 normalization value      */
#define SLIDER4_09_NOISE                 (100)              /* Slider ID 4 sensor number 09 noise value              */

#define SLIDER4_SENSOR_NUMBER            (0)                /* Slider ID 4                                           */
#define SLIDER4_THRESHOLD                (1000)             /* Slider ID 4 position calculation threshold            */
#define SLIDER4_RESOLUTION               (1)                /* Slider ID 4 resolution (1=100,2=50,4=25,5=20,10=10)   */

/* Slider5 Configuration */
#define SLIDER5_00                       NO_SENSOR          /* Slider ID 5 sensor number 00                          */
#define SLIDER5_00_NORM                  (1000)             /* Slider ID 5 sensor number 00 normalization value      */
#define SLIDER5_00_NOISE                 (100)              /* Slider ID 5 sensor number 00 noise value              */
#define SLIDER5_01                       NO_SENSOR          /* Slider ID 5 sensor number 01                          */
#define SLIDER5_01_NORM                  (1000)             /* Slider ID 5 sensor number 01 normalization value      */
#define SLIDER5_01_NOISE                 (100)              /* Slider ID 5 sensor number 01 noise value              */
#define SLIDER5_02                       NO_SENSOR          /* Slider ID 5 sensor number 02                          */
#define SLIDER5_02_NORM                  (1000)             /* Slider ID 5 sensor number 02 normalization value      */
#define SLIDER5_02_NOISE                 (100)              /* Slider ID 5 sensor number 02 noise value              */
#define SLIDER5_03                       NO_SENSOR          /* Slider ID 5 sensor number 03                          */
#define SLIDER5_03_NORM                  (1000)             /* Slider ID 5 sensor number 03 normalization value      */
#define SLIDER5_03_NOISE                 (100)              /* Slider ID 5 sensor number 03 noise value              */
#define SLIDER5_04                       NO_SENSOR          /* Slider ID 5 sensor number 04                          */
#define SLIDER5_04_NORM                  (1000)             /* Slider ID 5 sensor number 04 normalization value      */
#define SLIDER5_04_NOISE                 (100)              /* Slider ID 5 sensor number 04 noise value              */
#define SLIDER5_05                       NO_SENSOR          /* Slider ID 5 sensor number 05                          */
#define SLIDER5_05_NORM                  (1000)             /* Slider ID 5 sensor number 05 normalization value      */
#define SLIDER5_05_NOISE                 (100)              /* Slider ID 5 sensor number 05 noise value              */
#define SLIDER5_06                       NO_SENSOR          /* Slider ID 5 sensor number 06                          */
#define SLIDER5_06_NORM                  (1000)             /* Slider ID 5 sensor number 06 normalization value      */
#define SLIDER5_06_NOISE                 (100)              /* Slider ID 5 sensor number 06 noise value              */
#define SLIDER5_07                       NO_SENSOR          /* Slider ID 5 sensor number 07                          */
#define SLIDER5_07_NORM                  (1000)             /* Slider ID 5 sensor number 07 normalization value      */
#define SLIDER5_07_NOISE                 (100)              /* Slider ID 5 sensor number 07 noise value              */
#define SLIDER5_08                       NO_SENSOR          /* Slider ID 5 sensor number 08                          */
#define SLIDER5_08_NORM                  (1000)             /* Slider ID 5 sensor number 08 normalization value      */
#define SLIDER5_08_NOISE                 (100)              /* Slider ID 5 sensor number 08 noise value              */
#define SLIDER5_09                       NO_SENSOR          /* Slider ID 5 sensor number 09                          */
#define SLIDER5_09_NORM                  (1000)             /* Slider ID 5 sensor number 09 normalization value      */
#define SLIDER5_09_NOISE                 (100)              /* Slider ID 5 sensor number 09 noise value              */

#define SLIDER5_SENSOR_NUMBER            (0)                /* Slider ID 5                                           */
#define SLIDER5_THRESHOLD                (1000)             /* Slider ID 5 position calculation threshold            */
#define SLIDER5_RESOLUTION               (1)                /* Slider ID 5 resolution (1=100,2=50,4=25,5=20,10=10)   */

/* Slider6 Configuration */
#define SLIDER6_00                       NO_SENSOR          /* Slider ID 6 sensor number 00                          */
#define SLIDER6_00_NORM                  (1000)             /* Slider ID 6 sensor number 00 normalization value      */
#define SLIDER6_00_NOISE                 (100)              /* Slider ID 6 sensor number 00 noise value              */
#define SLIDER6_01                       NO_SENSOR          /* Slider ID 6 sensor number 01                          */
#define SLIDER6_01_NORM                  (1000)             /* Slider ID 6 sensor number 01 normalization value      */
#define SLIDER6_01_NOISE                 (100)              /* Slider ID 6 sensor number 01 noise value              */
#define SLIDER6_02                       NO_SENSOR          /* Slider ID 6 sensor number 02                          */
#define SLIDER6_02_NORM                  (1000)             /* Slider ID 6 sensor number 02 normalization value      */
#define SLIDER6_02_NOISE                 (100)              /* Slider ID 6 sensor number 02 noise value              */
#define SLIDER6_03                       NO_SENSOR          /* Slider ID 6 sensor number 03                          */
#define SLIDER6_03_NORM                  (1000)             /* Slider ID 6 sensor number 03 normalization value      */
#define SLIDER6_03_NOISE                 (100)              /* Slider ID 6 sensor number 03 noise value              */
#define SLIDER6_04                       NO_SENSOR          /* Slider ID 6 sensor number 04                          */
#define SLIDER6_04_NORM                  (1000)             /* Slider ID 6 sensor number 04 normalization value      */
#define SLIDER6_04_NOISE                 (100)              /* Slider ID 6 sensor number 04 noise value              */
#define SLIDER6_05                       NO_SENSOR          /* Slider ID 6 sensor number 05                          */
#define SLIDER6_05_NORM                  (1000)             /* Slider ID 6 sensor number 05 normalization value      */
#define SLIDER6_05_NOISE                 (100)              /* Slider ID 6 sensor number 05 noise value              */
#define SLIDER6_06                       NO_SENSOR          /* Slider ID 6 sensor number 06                          */
#define SLIDER6_06_NORM                  (1000)             /* Slider ID 6 sensor number 06 normalization value      */
#define SLIDER6_06_NOISE                 (100)              /* Slider ID 6 sensor number 06 noise value              */
#define SLIDER6_07                       NO_SENSOR          /* Slider ID 6 sensor number 07                          */
#define SLIDER6_07_NORM                  (1000)             /* Slider ID 6 sensor number 07 normalization value      */
#define SLIDER6_07_NOISE                 (100)              /* Slider ID 6 sensor number 07 noise value              */
#define SLIDER6_08                       NO_SENSOR          /* Slider ID 6 sensor number 08                          */
#define SLIDER6_08_NORM                  (1000)             /* Slider ID 6 sensor number 08 normalization value      */
#define SLIDER6_08_NOISE                 (100)              /* Slider ID 6 sensor number 08 noise value              */
#define SLIDER6_09                       NO_SENSOR          /* Slider ID 6 sensor number 09                          */
#define SLIDER6_09_NORM                  (1000)             /* Slider ID 6 sensor number 09 normalization value      */
#define SLIDER6_09_NOISE                 (100)              /* Slider ID 6 sensor number 09 noise value              */

#define SLIDER6_SENSOR_NUMBER            (0)                /* Slider ID 6                                           */
#define SLIDER6_THRESHOLD                (1000)             /* Slider ID 6 position calculation threshold            */
#define SLIDER6_RESOLUTION               (1)                /* Slider ID 6 resolution (1=100,2=50,4=25,5=20,10=10)   */

/* Slider7 Configuration */
#define SLIDER7_00                       NO_SENSOR          /* Slider ID 7 sensor number 00                          */
#define SLIDER7_00_NORM                  (1000)             /* Slider ID 7 sensor number 00 normalization value      */
#define SLIDER7_00_NOISE                 (100)              /* Slider ID 7 sensor number 00 noise value              */
#define SLIDER7_01                       NO_SENSOR          /* Slider ID 7 sensor number 01                          */
#define SLIDER7_01_NORM                  (1000)             /* Slider ID 7 sensor number 01 normalization value      */
#define SLIDER7_01_NOISE                 (100)              /* Slider ID 7 sensor number 01 noise value              */
#define SLIDER7_02                       NO_SENSOR          /* Slider ID 7 sensor number 02                          */
#define SLIDER7_02_NORM                  (1000)             /* Slider ID 7 sensor number 02 normalization value      */
#define SLIDER7_02_NOISE                 (100)              /* Slider ID 7 sensor number 02 noise value              */
#define SLIDER7_03                       NO_SENSOR          /* Slider ID 7 sensor number 03                          */
#define SLIDER7_03_NORM                  (1000)             /* Slider ID 7 sensor number 03 normalization value      */
#define SLIDER7_03_NOISE                 (100)              /* Slider ID 7 sensor number 03 noise value              */
#define SLIDER7_04                       NO_SENSOR          /* Slider ID 7 sensor number 04                          */
#define SLIDER7_04_NORM                  (1000)             /* Slider ID 7 sensor number 04 normalization value      */
#define SLIDER7_04_NOISE                 (100)              /* Slider ID 7 sensor number 04 noise value              */
#define SLIDER7_05                       NO_SENSOR          /* Slider ID 7 sensor number 05                          */
#define SLIDER7_05_NORM                  (1000)             /* Slider ID 7 sensor number 05 normalization value      */
#define SLIDER7_05_NOISE                 (100)              /* Slider ID 7 sensor number 05 noise value              */
#define SLIDER7_06                       NO_SENSOR          /* Slider ID 7 sensor number 06                          */
#define SLIDER7_06_NORM                  (1000)             /* Slider ID 7 sensor number 06 normalization value      */
#define SLIDER7_06_NOISE                 (100)              /* Slider ID 7 sensor number 06 noise value              */
#define SLIDER7_07                       NO_SENSOR          /* Slider ID 7 sensor number 07                          */
#define SLIDER7_07_NORM                  (1000)             /* Slider ID 7 sensor number 07 normalization value      */
#define SLIDER7_07_NOISE                 (100)              /* Slider ID 7 sensor number 07 noise value              */
#define SLIDER7_08                       NO_SENSOR          /* Slider ID 7 sensor number 08                          */
#define SLIDER7_08_NORM                  (1000)             /* Slider ID 7 sensor number 08 normalization value      */
#define SLIDER7_08_NOISE                 (100)              /* Slider ID 7 sensor number 08 noise value              */
#define SLIDER7_09                       NO_SENSOR          /* Slider ID 7 sensor number 09                          */
#define SLIDER7_09_NORM                  (1000)             /* Slider ID 7 sensor number 09 normalization value      */
#define SLIDER7_09_NOISE                 (100)              /* Slider ID 7 sensor number 09 noise value              */

#define SLIDER7_SENSOR_NUMBER            (0)                /* Slider ID 7                                           */
#define SLIDER7_THRESHOLD                (1000)             /* Slider ID 7 position calculation threshold            */
#define SLIDER7_RESOLUTION               (1)                /* Slider ID 7 resolution (1=100,2=50,4=25,5=20,10=10)   */

/**********************************************************************************************************************
*****    Wheel common values    ***************************************************************************************
**********************************************************************************************************************/
#define WHEEL_NUMBER                     (2)                /* Nummber of wheel                                      */
#define WHEEL_SENSOR_MAX                 (8)                /* Number of wheel composition maximum TS                */

/* Wheel0 Configuration */
#define WHEEL0_00                        (10)                /* Wheel ID 0 sensor number 00                           */
#define WHEEL0_00_NORM                   (6873)             /* Wheel ID 0 sensor number 00 normalization values      */
#define WHEEL0_00_NOISE                  (3181)              /* Wheel ID 0 sensor number 00 noise value               */
#define WHEEL0_01                        (12)                /* Wheel ID 0 sensor number 01                           */
#define WHEEL0_01_NORM                   (5709)             /* Wheel ID 0 sensor number 01 normalization values      */
#define WHEEL0_01_NOISE                  (2963)              /* Wheel ID 0 sensor number 01 noise value               */
#define WHEEL0_02                        (32)                /* Wheel ID 0 sensor number 02                           */
#define WHEEL0_02_NORM                   (6785)             /* Wheel ID 0 sensor number 02 normalization values      */
#define WHEEL0_02_NOISE                  (2588)              /* Wheel ID 0 sensor number 02 noise value               */
#define WHEEL0_03                        (5)                /* Wheel ID 0 sensor number 03                           */
#define WHEEL0_03_NORM                   (5702)             /* Wheel ID 0 sensor number 03 normalization values      */
#define WHEEL0_03_NOISE                  (2695)              /* Wheel ID 0 sensor number 03 noise value               */
#define WHEEL0_04                        NO_SENSOR          /* Wheel ID 0 sensor number 04                           */
#define WHEEL0_04_NORM                   (1000)             /* Wheel ID 0 sensor number 04 normalization values      */
#define WHEEL0_04_NOISE                  (100)              /* Wheel ID 0 sensor number 04 noise value               */
#define WHEEL0_05                        NO_SENSOR          /* Wheel ID 0 sensor number 05                           */
#define WHEEL0_05_NORM                   (1000)             /* Wheel ID 0 sensor number 05 normalization values      */
#define WHEEL0_05_NOISE                  (100)              /* Wheel ID 0 sensor number 05 noise value               */
#define WHEEL0_06                        NO_SENSOR          /* Wheel ID 0 sensor number 06                           */
#define WHEEL0_06_NORM                   (1000)             /* Wheel ID 0 sensor number 06 normalization values      */
#define WHEEL0_06_NOISE                  (100)              /* Wheel ID 0 sensor number 06 noise value               */
#define WHEEL0_07                        NO_SENSOR          /* Wheel ID 0 sensor number 07                           */
#define WHEEL0_07_NORM                   (1000)             /* Wheel ID 0 sensor number 07 normalization values      */
#define WHEEL0_07_NOISE                  (100)              /* Wheel ID 0 sensor number 07 noise value               */

#define WHEEL0_SENSOR_NUMBER             (4)                /* Wheel ID 0                                            */
#define WHEEL0_THRESHOLD                 (5100)              /* Wheel ID 0 position calculation threshold             */
#define WHEEL0_RESOLUTION                (1)                /* Wheel ID 0 resolution (1=90,2=45,3=30,5=18,9=10)      */

/* Wheel1 Configuration */
#define WHEEL1_00                        (8)          /* Wheel ID 1 sensor number 00                           */
#define WHEEL1_00_NORM                   (6107)             /* Wheel ID 1 sensor number 00 normalization values      */
#define WHEEL1_00_NOISE                  (2775)              /* Wheel ID 1 sensor number 00 noise value               */
#define WHEEL1_01                        (13)          /* Wheel ID 1 sensor number 01                           */
#define WHEEL1_01_NORM                   (8054)             /* Wheel ID 1 sensor number 01 normalization values      */
#define WHEEL1_01_NOISE                  (2726)              /* Wheel ID 1 sensor number 01 noise value               */
#define WHEEL1_02                        (34)          /* Wheel ID 1 sensor number 02                           */
#define WHEEL1_02_NORM                   (5370)             /* Wheel ID 1 sensor number 02 normalization values      */
#define WHEEL1_02_NOISE                  (2649)              /* Wheel ID 1 sensor number 02 noise value               */
#define WHEEL1_03                        (35)          /* Wheel ID 1 sensor number 03                           */
#define WHEEL1_03_NORM                   (6921)             /* Wheel ID 1 sensor number 03 normalization values      */
#define WHEEL1_03_NOISE                  (2339)              /* Wheel ID 1 sensor number 03 noise value               */
#define WHEEL1_04                        (21)          /* Wheel ID 1 sensor number 04                           */
#define WHEEL1_04_NORM                   (6639)             /* Wheel ID 1 sensor number 04 normalization values      */
#define WHEEL1_04_NOISE                  (2574)              /* Wheel ID 1 sensor number 04 noise value               */
#define WHEEL1_05                        (0)          /* Wheel ID 1 sensor number 05                           */
#define WHEEL1_05_NORM                   (7348)             /* Wheel ID 1 sensor number 05 normalization values      */
#define WHEEL1_05_NOISE                  (3027)              /* Wheel ID 1 sensor number 05 noise value               */
#define WHEEL1_06                        (1)          /* Wheel ID 1 sensor number 06                           */
#define WHEEL1_06_NORM                   (5554)             /* Wheel ID 1 sensor number 06 normalization values      */
#define WHEEL1_06_NOISE                  (3526)              /* Wheel ID 1 sensor number 06 noise value               */
#define WHEEL1_07                        (4)          /* Wheel ID 1 sensor number 07                           */
#define WHEEL1_07_NORM                   (5639)             /* Wheel ID 1 sensor number 07 normalization values      */
#define WHEEL1_07_NOISE                  (3047)              /* Wheel ID 1 sensor number 07 noise value               */

#define WHEEL1_SENSOR_NUMBER             (8)                /* Wheel ID 1                                            */
#define WHEEL1_THRESHOLD                 (5985)              /* Wheel ID 1 position calculation threshold             */
#define WHEEL1_RESOLUTION                (1)                /* Wheel ID 1 resolution (1=90,2=45,3=30,5=18,9=10)      */

/* Wheel2 Configuration */
#define WHEEL2_00                        NO_SENSOR          /* Wheel ID 2 sensor number 00                           */
#define WHEEL2_00_NORM                   (1000)             /* Wheel ID 2 sensor number 00 normalization values      */
#define WHEEL2_00_NOISE                  (100)              /* Wheel ID 2 sensor number 00 noise value               */
#define WHEEL2_01                        NO_SENSOR          /* Wheel ID 2 sensor number 01                           */
#define WHEEL2_01_NORM                   (1000)             /* Wheel ID 2 sensor number 01 normalization values      */
#define WHEEL2_01_NOISE                  (100)              /* Wheel ID 2 sensor number 01 noise value               */
#define WHEEL2_02                        NO_SENSOR          /* Wheel ID 2 sensor number 02                           */
#define WHEEL2_02_NORM                   (1000)             /* Wheel ID 2 sensor number 02 normalization values      */
#define WHEEL2_02_NOISE                  (100)              /* Wheel ID 2 sensor number 02 noise value               */
#define WHEEL2_03                        NO_SENSOR          /* Wheel ID 2 sensor number 03                           */
#define WHEEL2_03_NORM                   (1000)             /* Wheel ID 2 sensor number 03 normalization values      */
#define WHEEL2_03_NOISE                  (100)              /* Wheel ID 2 sensor number 03 noise value               */
#define WHEEL2_04                        NO_SENSOR          /* Wheel ID 2 sensor number 04                           */
#define WHEEL2_04_NORM                   (1000)             /* Wheel ID 2 sensor number 04 normalization values      */
#define WHEEL2_04_NOISE                  (100)              /* Wheel ID 2 sensor number 04 noise value               */
#define WHEEL2_05                        NO_SENSOR          /* Wheel ID 2 sensor number 05                           */
#define WHEEL2_05_NORM                   (1000)             /* Wheel ID 2 sensor number 05 normalization values      */
#define WHEEL2_05_NOISE                  (100)              /* Wheel ID 2 sensor number 05 noise value               */
#define WHEEL2_06                        NO_SENSOR          /* Wheel ID 2 sensor number 06                           */
#define WHEEL2_06_NORM                   (1000)             /* Wheel ID 2 sensor number 06 normalization values      */
#define WHEEL2_06_NOISE                  (100)              /* Wheel ID 2 sensor number 06 noise value               */
#define WHEEL2_07                        NO_SENSOR          /* Wheel ID 2 sensor number 07                           */
#define WHEEL2_07_NORM                   (1000)             /* Wheel ID 2 sensor number 07 normalization values      */
#define WHEEL2_07_NOISE                  (100)              /* Wheel ID 2 sensor number 07 noise value               */

#define WHEEL2_SENSOR_NUMBER             (0)                /* Wheel ID 2                                            */
#define WHEEL2_THRESHOLD                 (800)              /* Wheel ID 2 position calculation threshold             */
#define WHEEL2_RESOLUTION                (1)                /* Wheel ID 2 resolution (1=90,2=45,3=30,5=18,9=10)      */

/* Wheel3 Configuration */
#define WHEEL3_00                        NO_SENSOR          /* Wheel ID 3 sensor number 00                           */
#define WHEEL3_00_NORM                   (1000)             /* Wheel ID 3 sensor number 00 normalization values      */
#define WHEEL3_00_NOISE                  (100)              /* Wheel ID 3 sensor number 00 noise value               */
#define WHEEL3_01                        NO_SENSOR          /* Wheel ID 3 sensor number 01                           */
#define WHEEL3_01_NORM                   (1000)             /* Wheel ID 3 sensor number 01 normalization values      */
#define WHEEL3_01_NOISE                  (100)              /* Wheel ID 3 sensor number 01 noise value               */
#define WHEEL3_02                        NO_SENSOR          /* Wheel ID 3 sensor number 02                           */
#define WHEEL3_02_NORM                   (1000)             /* Wheel ID 3 sensor number 02 normalization values      */
#define WHEEL3_02_NOISE                  (100)              /* Wheel ID 3 sensor number 02 noise value               */
#define WHEEL3_03                        NO_SENSOR          /* Wheel ID 3 sensor number 03                           */
#define WHEEL3_03_NORM                   (1000)             /* Wheel ID 3 sensor number 03 normalization values      */
#define WHEEL3_03_NOISE                  (100)              /* Wheel ID 3 sensor number 03 noise value               */
#define WHEEL3_04                        NO_SENSOR          /* Wheel ID 3 sensor number 04                           */
#define WHEEL3_04_NORM                   (1000)             /* Wheel ID 3 sensor number 04 normalization values      */
#define WHEEL3_04_NOISE                  (100)              /* Wheel ID 3 sensor number 04 noise value               */
#define WHEEL3_05                        NO_SENSOR          /* Wheel ID 3 sensor number 05                           */
#define WHEEL3_05_NORM                   (1000)             /* Wheel ID 3 sensor number 05 normalization values      */
#define WHEEL3_05_NOISE                  (100)              /* Wheel ID 3 sensor number 05 noise value               */
#define WHEEL3_06                        NO_SENSOR          /* Wheel ID 3 sensor number 06                           */
#define WHEEL3_06_NORM                   (1000)             /* Wheel ID 3 sensor number 06 normalization values      */
#define WHEEL3_06_NOISE                  (100)              /* Wheel ID 3 sensor number 06 noise value               */
#define WHEEL3_07                        NO_SENSOR          /* Wheel ID 3 sensor number 07                           */
#define WHEEL3_07_NORM                   (1000)             /* Wheel ID 3 sensor number 07 normalization values      */
#define WHEEL3_07_NOISE                  (100)              /* Wheel ID 3 sensor number 07 noise value               */

#define WHEEL3_SENSOR_NUMBER             (0)                /* Wheel ID 3                                            */
#define WHEEL3_THRESHOLD                 (800)              /* Wheel ID 3 position calculation threshold             */
#define WHEEL3_RESOLUTION                (1)                /* Wheel ID 3 resolution (1=90,2=45,3=30,5=18,9=10)      */

/* Wheel4 Configuration */
#define WHEEL4_00                        NO_SENSOR          /* Wheel ID 4 sensor number 00                           */
#define WHEEL4_00_NORM                   (1000)             /* Wheel ID 4 sensor number 00 normalization values      */
#define WHEEL4_00_NOISE                  (100)              /* Wheel ID 4 sensor number 00 noise value               */
#define WHEEL4_01                        NO_SENSOR          /* Wheel ID 4 sensor number 01                           */
#define WHEEL4_01_NORM                   (1000)             /* Wheel ID 4 sensor number 01 normalization values      */
#define WHEEL4_01_NOISE                  (100)              /* Wheel ID 4 sensor number 01 noise value               */
#define WHEEL4_02                        NO_SENSOR          /* Wheel ID 4 sensor number 02                           */
#define WHEEL4_02_NORM                   (1000)             /* Wheel ID 4 sensor number 02 normalization values      */
#define WHEEL4_02_NOISE                  (100)              /* Wheel ID 4 sensor number 02 noise value               */
#define WHEEL4_03                        NO_SENSOR          /* Wheel ID 4 sensor number 03                           */
#define WHEEL4_03_NORM                   (1000)             /* Wheel ID 4 sensor number 03 normalization values      */
#define WHEEL4_03_NOISE                  (100)              /* Wheel ID 4 sensor number 03 noise value               */
#define WHEEL4_04                        NO_SENSOR          /* Wheel ID 4 sensor number 04                           */
#define WHEEL4_04_NORM                   (1000)             /* Wheel ID 4 sensor number 04 normalization values      */
#define WHEEL4_04_NOISE                  (100)              /* Wheel ID 4 sensor number 04 noise value               */
#define WHEEL4_05                        NO_SENSOR          /* Wheel ID 4 sensor number 05                           */
#define WHEEL4_05_NORM                   (1000)             /* Wheel ID 4 sensor number 05 normalization values      */
#define WHEEL4_05_NOISE                  (100)              /* Wheel ID 4 sensor number 05 noise value               */
#define WHEEL4_06                        NO_SENSOR          /* Wheel ID 4 sensor number 06                           */
#define WHEEL4_06_NORM                   (1000)             /* Wheel ID 4 sensor number 06 normalization values      */
#define WHEEL4_06_NOISE                  (100)              /* Wheel ID 4 sensor number 06 noise value               */
#define WHEEL4_07                        NO_SENSOR          /* Wheel ID 4 sensor number 07                           */
#define WHEEL4_07_NORM                   (1000)             /* Wheel ID 4 sensor number 07 normalization values      */
#define WHEEL4_07_NOISE                  (100)              /* Wheel ID 4 sensor number 07 noise value               */

#define WHEEL4_SENSOR_NUMBER             (0)                /* Wheel ID 4                                            */
#define WHEEL4_THRESHOLD                 (800)              /* Wheel ID 4 position calculation threshold             */
#define WHEEL4_RESOLUTION                (1)                /* Wheel ID 4 resolution (1=90,2=45,3=30,5=18,9=10)      */

/* Wheel5 Configuration */
#define WHEEL5_00                        NO_SENSOR          /* Wheel ID 5 sensor number 00                           */
#define WHEEL5_00_NORM                   (1000)             /* Wheel ID 5 sensor number 00 normalization values      */
#define WHEEL5_00_NOISE                  (100)              /* Wheel ID 5 sensor number 00 noise value               */
#define WHEEL5_01                        NO_SENSOR          /* Wheel ID 5 sensor number 01                           */
#define WHEEL5_01_NORM                   (1000)             /* Wheel ID 5 sensor number 01 normalization values      */
#define WHEEL5_01_NOISE                  (100)              /* Wheel ID 5 sensor number 01 noise value               */
#define WHEEL5_02                        NO_SENSOR          /* Wheel ID 5 sensor number 02                           */
#define WHEEL5_02_NORM                   (1000)             /* Wheel ID 5 sensor number 02 normalization values      */
#define WHEEL5_02_NOISE                  (100)              /* Wheel ID 5 sensor number 02 noise value               */
#define WHEEL5_03                        NO_SENSOR          /* Wheel ID 5 sensor number 03                           */
#define WHEEL5_03_NORM                   (1000)             /* Wheel ID 5 sensor number 03 normalization values      */
#define WHEEL5_03_NOISE                  (100)              /* Wheel ID 5 sensor number 03 noise value               */
#define WHEEL5_04                        NO_SENSOR          /* Wheel ID 5 sensor number 04                           */
#define WHEEL5_04_NORM                   (1000)             /* Wheel ID 5 sensor number 04 normalization values      */
#define WHEEL5_04_NOISE                  (100)              /* Wheel ID 5 sensor number 04 noise value               */
#define WHEEL5_05                        NO_SENSOR          /* Wheel ID 5 sensor number 05                           */
#define WHEEL5_05_NORM                   (1000)             /* Wheel ID 5 sensor number 05 normalization values      */
#define WHEEL5_05_NOISE                  (100)              /* Wheel ID 5 sensor number 05 noise value               */
#define WHEEL5_06                        NO_SENSOR          /* Wheel ID 5 sensor number 06                           */
#define WHEEL5_06_NORM                   (1000)             /* Wheel ID 5 sensor number 06 normalization values      */
#define WHEEL5_06_NOISE                  (100)              /* Wheel ID 5 sensor number 06 noise value               */
#define WHEEL5_07                        NO_SENSOR          /* Wheel ID 5 sensor number 07                           */
#define WHEEL5_07_NORM                   (1000)             /* Wheel ID 5 sensor number 07 normalization values      */
#define WHEEL5_07_NOISE                  (100)              /* Wheel ID 5 sensor number 07 noise value               */

#define WHEEL5_SENSOR_NUMBER             (0)                /* Wheel ID 5                                            */
#define WHEEL5_THRESHOLD                 (800)              /* Wheel ID 5 position calculation threshold             */
#define WHEEL5_RESOLUTION                (1)                /* Wheel ID 5 resolution (1=90,2=45,3=30,5=18,9=10)      */

/* Wheel6 Configuration */
#define WHEEL6_00                        NO_SENSOR          /* Wheel ID 6 sensor number 00                           */
#define WHEEL6_00_NORM                   (1000)             /* Wheel ID 6 sensor number 00 normalization values      */
#define WHEEL6_00_NOISE                  (100)              /* Wheel ID 6 sensor number 00 noise value               */
#define WHEEL6_01                        NO_SENSOR          /* Wheel ID 6 sensor number 01                           */
#define WHEEL6_01_NORM                   (1000)             /* Wheel ID 6 sensor number 01 normalization values      */
#define WHEEL6_01_NOISE                  (100)              /* Wheel ID 6 sensor number 01 noise value               */
#define WHEEL6_02                        NO_SENSOR          /* Wheel ID 6 sensor number 02                           */
#define WHEEL6_02_NORM                   (1000)             /* Wheel ID 6 sensor number 02 normalization values      */
#define WHEEL6_02_NOISE                  (100)              /* Wheel ID 6 sensor number 02 noise value               */
#define WHEEL6_03                        NO_SENSOR          /* Wheel ID 6 sensor number 03                           */
#define WHEEL6_03_NORM                   (1000)             /* Wheel ID 6 sensor number 03 normalization values      */
#define WHEEL6_03_NOISE                  (100)              /* Wheel ID 6 sensor number 03 noise value               */
#define WHEEL6_04                        NO_SENSOR          /* Wheel ID 6 sensor number 04                           */
#define WHEEL6_04_NORM                   (1000)             /* Wheel ID 6 sensor number 04 normalization values      */
#define WHEEL6_04_NOISE                  (100)              /* Wheel ID 6 sensor number 04 noise value               */
#define WHEEL6_05                        NO_SENSOR          /* Wheel ID 6 sensor number 05                           */
#define WHEEL6_05_NORM                   (1000)             /* Wheel ID 6 sensor number 05 normalization values      */
#define WHEEL6_05_NOISE                  (100)              /* Wheel ID 6 sensor number 05 noise value               */
#define WHEEL6_06                        NO_SENSOR          /* Wheel ID 6 sensor number 06                           */
#define WHEEL6_06_NORM                   (1000)             /* Wheel ID 6 sensor number 06 normalization values      */
#define WHEEL6_06_NOISE                  (100)              /* Wheel ID 6 sensor number 06 noise value               */
#define WHEEL6_07                        NO_SENSOR          /* Wheel ID 6 sensor number 07                           */
#define WHEEL6_07_NORM                   (1000)             /* Wheel ID 6 sensor number 07 normalization values      */
#define WHEEL6_07_NOISE                  (100)              /* Wheel ID 6 sensor number 07 noise value               */

#define WHEEL6_SENSOR_NUMBER             (0)                /* Wheel ID 6                                            */
#define WHEEL6_THRESHOLD                 (800)              /* Wheel ID 6 position calculation threshold             */
#define WHEEL6_RESOLUTION                (1)                /* Wheel ID 6 resolution (1=90,2=45,3=30,5=18,9=10)      */

/* Wheel7 Configuration */
#define WHEEL7_00                        NO_SENSOR          /* Wheel ID 7 sensor number 00                           */
#define WHEEL7_00_NORM                   (1000)             /* Wheel ID 7 sensor number 00 normalization values      */
#define WHEEL7_00_NOISE                  (100)              /* Wheel ID 7 sensor number 00 noise value               */
#define WHEEL7_01                        NO_SENSOR          /* Wheel ID 7 sensor number 01                           */
#define WHEEL7_01_NORM                   (1000)             /* Wheel ID 7 sensor number 01 normalization values      */
#define WHEEL7_01_NOISE                  (100)              /* Wheel ID 7 sensor number 01 noise value               */
#define WHEEL7_02                        NO_SENSOR          /* Wheel ID 7 sensor number 02                           */
#define WHEEL7_02_NORM                   (1000)             /* Wheel ID 7 sensor number 02 normalization values      */
#define WHEEL7_02_NOISE                  (100)              /* Wheel ID 7 sensor number 02 noise value               */
#define WHEEL7_03                        NO_SENSOR          /* Wheel ID 7 sensor number 03                           */
#define WHEEL7_03_NORM                   (1000)             /* Wheel ID 7 sensor number 03 normalization values      */
#define WHEEL7_03_NOISE                  (100)              /* Wheel ID 7 sensor number 03 noise value               */
#define WHEEL7_04                        NO_SENSOR          /* Wheel ID 7 sensor number 04                           */
#define WHEEL7_04_NORM                   (1000)             /* Wheel ID 7 sensor number 04 normalization values      */
#define WHEEL7_04_NOISE                  (100)              /* Wheel ID 7 sensor number 04 noise value               */
#define WHEEL7_05                        NO_SENSOR          /* Wheel ID 7 sensor number 05                           */
#define WHEEL7_05_NORM                   (1000)             /* Wheel ID 7 sensor number 05 normalization values      */
#define WHEEL7_05_NOISE                  (100)              /* Wheel ID 7 sensor number 05 noise value               */
#define WHEEL7_06                        NO_SENSOR          /* Wheel ID 7 sensor number 06                           */
#define WHEEL7_06_NORM                   (1000)             /* Wheel ID 7 sensor number 06 normalization values      */
#define WHEEL7_06_NOISE                  (100)              /* Wheel ID 7 sensor number 06 noise value               */
#define WHEEL7_07                        NO_SENSOR          /* Wheel ID 7 sensor number 07                           */
#define WHEEL7_07_NORM                   (1000)             /* Wheel ID 7 sensor number 07 normalization values      */
#define WHEEL7_07_NOISE                  (100)              /* Wheel ID 7 sensor number 07 noise value               */

#define WHEEL7_SENSOR_NUMBER             (0)                /* Wheel ID 7                                            */
#define WHEEL7_THRESHOLD                 (800)              /* Wheel ID 7 position calculation threshold             */
#define WHEEL7_RESOLUTION                (1)                /* Wheel ID 7 resolution (1=90,2=45,3=30,5=18,9=10)      */

/***********************************************************************************************************************
******************************                                                            ******************************
******************************                Common parameter definition                 ******************************
******************************                                                            ******************************
***********************************************************************************************************************/
#define CALIB_TIME        (4)

#define DRIFT_OK          (0)
#define DRIFT_ERROR       (1)
#define DRIFT_OFF         (2)

#define KEY_DISENABLE     (0)
#define KEY_ENABLE        (1)

#define KEY_GROUP0        (16)
#define KEY_GROUP1        (32)
#define KEY_GROUP2        (48)
#define KEY_GROUP3        (64)

/* Profile information */
#define DF_PROFILE    (0x1234)
#define WORKBENCH_COMMAND_USE
#define TS_NON    (0xff)

/* Multi Touch Cancel */
#define DF_MTC_ONOFF       (OFF)      /* ON/OFF */
#define DF_MTC_START_TS    (0)
#define DF_MTC_END_TS      (11)

/* Touch ON/OFF judgment */
#define SELF_TOUCH_ON                    (3)             /* 0-255 The cumulative number of determinations of [ON]     */
#define SELF_TOUCH_OFF                   (3)             /* 0-255 The cumulative number of determinations of [OFF]    */
#define SELF_MSA                         (0)             /* 0-65535 Maximum continuous [ON], 0:no use                 */
#define SELF_DRIFT_ENABLE                (1)             /* Drift function enable                                     */
#define SELF_DRIFT_FREQUENCY             (255)           /* 0-65535                                                   */

#define MUTUAL0_TOUCH_ON                 (3)             /* 0-255 The cumulative number of determinations of [ON]     */
#define MUTUAL0_TOUCH_OFF                (3)             /* 0-255 The cumulative number of determinations of [OFF]    */
#define MUTUAL0_MSA                      (0)             /* 0-65535 Maximum continuous [ON], 0:no use                 */
#define MUTUAL0_DRIFT_ENABLE             (1)             /* Drift function enable                                     */
#define MUTUAL0_DRIFT_FREQUENCY          (255)           /* 0-65535                                                   */

#define MUTUAL1_TOUCH_ON                 (3)             /* 0-255 The cumulative number of determinations of [ON]     */
#define MUTUAL1_TOUCH_OFF                (3)             /* 0-255 The cumulative number of determinations of [OFF]    */
#define MUTUAL1_MSA                      (0)             /* 0-65535 Maximum continuous [ON], 0:no use                 */
#define MUTUAL1_DRIFT_ENABLE             (1)             /* Drift function enable                                     */
#define MUTUAL1_DRIFT_FREQUENCY          (255)           /* 0-65535                                                   */

#define MUTUAL2_TOUCH_ON                 (3)             /* 0-255 The cumulative number of determinations of [ON]     */
#define MUTUAL2_TOUCH_OFF                (3)             /* 0-255 The cumulative number of determinations of [OFF]    */
#define MUTUAL2_MSA                      (0)             /* 0-65535 Maximum continuous [ON], 0:no use                 */
#define MUTUAL2_DRIFT_ENABLE             (1)             /* Drift function enable                                     */
#define MUTUAL2_DRIFT_FREQUENCY          (255)           /* 0-65535                                                   */

#define MUTUAL3_TOUCH_ON                 (3)             /* 0-255 The cumulative number of determinations of [ON]     */
#define MUTUAL3_TOUCH_OFF                (3)             /* 0-255 The cumulative number of determinations of [OFF]    */
#define MUTUAL3_MSA                      (0)             /* 0-65535 Maximum continuous [ON], 0:no use                 */
#define MUTUAL3_DRIFT_ENABLE             (1)             /* Drift function enable                                     */
#define MUTUAL3_DRIFT_FREQUENCY          (255)           /* 0-65535                                                   */

#define MUTUAL4_TOUCH_ON                 (3)             /* 0-255 The cumulative number of determinations of [ON]     */
#define MUTUAL4_TOUCH_OFF                (3)             /* 0-255 The cumulative number of determinations of [OFF]    */
#define MUTUAL4_MSA                      (0)             /* 0-65535 Maximum continuous [ON], 0:no use                 */
#define MUTUAL4_DRIFT_ENABLE             (1)             /* Drift function enable                                     */
#define MUTUAL4_DRIFT_FREQUENCY          (255)           /* 0-65535                                                   */

#define MUTUAL5_TOUCH_ON                 (3)             /* 0-255 The cumulative number of determinations of [ON]     */
#define MUTUAL5_TOUCH_OFF                (3)             /* 0-255 The cumulative number of determinations of [OFF]    */
#define MUTUAL5_MSA                      (0)             /* 0-65535 Maximum continuous [ON], 0:no use                 */
#define MUTUAL5_DRIFT_ENABLE             (1)             /* Drift function enable                                     */
#define MUTUAL5_DRIFT_FREQUENCY          (255)           /* 0-65535                                                   */

#define MUTUAL6_TOUCH_ON                 (3)             /* 0-255 The cumulative number of determinations of [ON]     */
#define MUTUAL6_TOUCH_OFF                (3)             /* 0-255 The cumulative number of determinations of [OFF]    */
#define MUTUAL6_MSA                      (0)             /* 0-65535 Maximum continuous [ON], 0:no use                 */
#define MUTUAL6_DRIFT_ENABLE             (1)             /* Drift function enable                                     */
#define MUTUAL6_DRIFT_FREQUENCY          (255)           /* 0-65535                                                   */

#define MUTUAL7_TOUCH_ON                 (3)             /* 0-255 The cumulative number of determinations of [ON]     */
#define MUTUAL7_TOUCH_OFF                (3)             /* 0-255 The cumulative number of determinations of [OFF]    */
#define MUTUAL7_MSA                      (0)             /* 0-65535 Maximum continuous [ON], 0:no use                 */
#define MUTUAL7_DRIFT_ENABLE             (1)             /* Drift function enable                                     */
#define MUTUAL7_DRIFT_FREQUENCY          (255)           /* 0-65535                                                   */

#define ZERO_ENA                         (0)
#define ZERO_DIS                         (1)

/***********************************************************************************************************************
* Typedef definitions
***********************************************************************************************************************/

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
* Global variables
***********************************************************************************************************************/

#endif //] __R_TOUCH_H__

/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
