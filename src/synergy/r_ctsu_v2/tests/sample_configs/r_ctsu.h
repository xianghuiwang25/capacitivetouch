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
* File Name    : r_ctsu.h
* Version      : 1.00
* Device(s)    : R5F5113xAxFP,R5F5231xAxFP,R5F51305AxFN
* Description  : This file includes the Capacitive Touch Sensing Unit.
***********************************************************************************************************************/

/***********************************************************************************************************************
* History      : DD.MM.YYYY Version    Description
*              : xx.xx.2015   1.00     First Release
***********************************************************************************************************************/
#ifndef __R_CTSU_H__    //[
#define __R_CTSU_H__

/***********************************************************************************************************************
* Includes
***********************************************************************************************************************/
#include <stdint.h>

#define MCU_MODEL	(MCU_MODEL_R5F51305AxFN)
/***********************************************************************************************************************
 Macro definitions
***********************************************************************************************************************/
#ifdef __R_CTSU_C__
    #define CTSU_EXTERN
#else
    #define CTSU_EXTERN    extern
#endif

/***********************************************************************************************************************
* Macro definitions
***********************************************************************************************************************/
#define R5F5113                          (1)         /* Definition for RX113 compiling options                        */
#define R5F5231                          (2)         /* Definition for RX231 compiling options                        */
#define R5F5230                          (3)         /* Definition for RX230 compiling options                        */
#define R5F5130                          (4)         /* Definition for RX130 compiling options                        */

/*****    1 channel mesurement time 0.5ms table    ********************************************************************/
#define _19_2UA                          (40960)
#define _18_0UA                          (38400)
#define _16_8UA                          (35840)
#define _15_6UA                          (33280)
#define _14_4UA                          (30720)
#define _13_2UA                          (28160)
#define _12_0UA                          (25600)
#define _10_8UA                          (23040)
#define _09_6UA                          (20480)
#define _08_4UA                          (17920)
#define _07_2UA                          (15360)
#define _06_0UA                          (12800)
#define _04_8UA                          (10240)
#define _03_6UA                          (7680)
#define _02_4UA                          (5120)
#define _01_2UA                          (2560)

/**********************************************************************************************************************/
/*****    Measurement method composition definition    ****************************************************************/
/**********************************************************************************************************************/
#define SELF_METHOD_NUM                  (1)         /* 0 or 1                                                        */
#define MUTUAL_METHOD_NUM                (1)         /* Minimum = 1, Maximum = 8, Range = 1-8                         */
#define METHOD_NUM                       (SELF_METHOD_NUM + MUTUAL_METHOD_NUM)

/**********************************************************************************************************************/
/*****    Mutual-touch sensor function definition    ******************************************************************/
/**********************************************************************************************************************/
#define RECEPTION_FUNCITON               (0)         /* Reception function TS                                         */
#define TRANSMISSION_FUNCITON            (1)         /* Transmission function TS                                      */

/*****    Address 0008 001Ch Module Stop Control Register D    ********************************************************/
#define _0_MSTPD10_CTSU_ENABLE           (0)        /* CTSU module clock is enabled                                   */
#define _1_MSTPD10_CTSU_DISABLE          (1)        /* CTSU module clock is disabled                                  */

/*****    Address 000A 0900h CTSU control register 0    ***************************************************************/
#define _0_CTSUCAP_0_SOFT_TRIGGER        (0)        /* Software trigger                                               */
#define _1_CTSUCAP_1_EXTERNAL_TRIGGER    (1)        /* External trigger                                               */

#define _0_CTSUSNZ_LOW_POWER_DISABLE     (0)        /* Low power function disable                                     */
#define _1_CTSUSNZ_LOW_POWER_ENABLE      (1)        /* Low power function enable                                      */

#define _0_CTSUTXVSEL_VCC                (0)        /* Vcc select                                                     */
#define _1_CTSUTXVSEL_INTERNAL_POWER     (1)        /* Interal logic power supply                                     */

#define MUTUAL0_CTSUTXVSEL               (_0_CTSUTXVSEL_VCC)
#define MUTUAL1_CTSUTXVSEL               (_0_CTSUTXVSEL_VCC)
#define MUTUAL2_CTSUTXVSEL               (_0_CTSUTXVSEL_VCC)
#define MUTUAL3_CTSUTXVSEL               (_0_CTSUTXVSEL_VCC)
#define MUTUAL4_CTSUTXVSEL               (_0_CTSUTXVSEL_VCC)
#define MUTUAL5_CTSUTXVSEL               (_0_CTSUTXVSEL_VCC)
#define MUTUAL6_CTSUTXVSEL               (_0_CTSUTXVSEL_VCC)
#define MUTUAL7_CTSUTXVSEL               (_0_CTSUTXVSEL_VCC)

/*****    Address 000A 0901h CTSU channel register 1    ***************************************************************/
#define _0_CTSUPON_HW_POWER_OFF          (0)        /* CTSU hardware macro power off                                  */
#define _1_CTSUPON_HW_POWER_ON           (1)        /* CTSU hardware macro power on                                   */

#define _0_CTSUCSW_OFF                   (0)        /* Capacitance switch turned off                                  */
#define _1_CTSUCSW_ON                    (1)        /* Capacitance switch turned on                                   */

#define _0_CTSUATUNE0_NORMAL             (0)        /* Normal operating mode                                          */
#define _1_CTSUATUNE0_LOW                (1)        /* Low-voltage operating mode                                     */

#define SELF_CTSUATUNE0                  (_0_CTSUATUNE0_NORMAL)
#define MUTUAL0_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#define MUTUAL1_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#define MUTUAL2_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#define MUTUAL3_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#define MUTUAL4_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#define MUTUAL5_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#define MUTUAL6_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)
#define MUTUAL7_CTSUATUNE0               (_0_CTSUATUNE0_NORMAL)

#define _0_CTSUATUNE1_NORMAL             (0)        /* Normal output                                                  */
#define _1_CTSUATUNE1_HIGH               (1)        /* High-current output                                            */

#define SELF_CTSUATUNE1                  (_0_CTSUATUNE1_NORMAL)
#define MUTUAL0_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#define MUTUAL1_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#define MUTUAL2_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#define MUTUAL3_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#define MUTUAL4_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#define MUTUAL5_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#define MUTUAL6_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)
#define MUTUAL7_CTSUATUNE1               (_1_CTSUATUNE1_HIGH)

#define _00_CTSUCLK_PCLK                 (0)        /* PCLK                                                           */
#define _01_CTSUCLK_PCLK_DIV2            (1)        /* PCLK/2(PCLK divided by 2)                                      */
#define _10_CTSUCLK_PCLK_DIV4            (2)        /* PCLK/4(PCLK divided by 4)                                      */
#define _11_CTSUCLK_PROHIBITION          (3)        /* Setting prohibited                                             */

#define _00_CTSUMD_SELF_SINGLE           (0)        /* Self-capacitance single scan mode                              */
#define _01_CTSUMD_SELF_MULTI            (1)        /* Self-capacitance multi-scan mode                               */
#define _10_CTSUMD_PROHIBITION           (2)        /* Setting prohibited                                             */
#define _11_CTSUMD_MUTUAL                (3)        /* Mutual-capacitance scan mode                                   */

/*****    Address 000A 0902h CTSU Sensor drive pulse spectrum diffusion set register    *******************************/
#define _0011_CTSUPRRATIO_RECOMMEND      (3)        /* Recommended setting value                                      */

#define SELF_CTSUPRRATIO                 (3)
#define MUTUAL0_CTSUPRRATIO              (3)
#define MUTUAL1_CTSUPRRATIO              (3)
#define MUTUAL2_CTSUPRRATIO              (3)
#define MUTUAL3_CTSUPRRATIO              (3)
#define MUTUAL4_CTSUPRRATIO              (3)
#define MUTUAL5_CTSUPRRATIO              (3)
#define MUTUAL6_CTSUPRRATIO              (3)
#define MUTUAL7_CTSUPRRATIO              (3)

#define _00_CTSUPRMODE_510_PULSES        (0)        /* 510 pulses                                                     */
#define _01_CTSUPRMODE_126_PULSES        (1)        /* 126 pulses                                                     */
#define _10_CTSUPRMODE_62_PULSES         (2)        /* 62 pulses (recommended setting value)                          */
#define _11_CTSUPRMODE_3_PULSES          (3)        /* Setting prohibited                                             */

#define SELF_CTSUPRMODE                  (_10_CTSUPRMODE_62_PULSES)
#define MUTUAL0_CTSUPRMODE               (_10_CTSUPRMODE_62_PULSES)
#define MUTUAL1_CTSUPRMODE               (_10_CTSUPRMODE_62_PULSES)
#define MUTUAL2_CTSUPRMODE               (_10_CTSUPRMODE_62_PULSES)
#define MUTUAL3_CTSUPRMODE               (_10_CTSUPRMODE_62_PULSES)
#define MUTUAL4_CTSUPRMODE               (_10_CTSUPRMODE_62_PULSES)
#define MUTUAL5_CTSUPRMODE               (_10_CTSUPRMODE_62_PULSES)
#define MUTUAL6_CTSUPRMODE               (_10_CTSUPRMODE_62_PULSES)
#define MUTUAL7_CTSUPRMODE               (_10_CTSUPRMODE_62_PULSES)

#define _0_CTSUSOFF_ON                   (0)        /* High-pass noise reduction function turned on                   */
#define _1_CTSUSOFF_OFF                  (1)        /* High-pass noise reduction function turned off                  */

#define SELF_CTSUSOFF                    (_0_CTSUSOFF_ON)
#define MUTUAL0_CTSUSOFF                 (_0_CTSUSOFF_ON)
#define MUTUAL1_CTSUSOFF                 (_0_CTSUSOFF_ON)
#define MUTUAL2_CTSUSOFF                 (_0_CTSUSOFF_ON)
#define MUTUAL3_CTSUSOFF                 (_0_CTSUSOFF_ON)
#define MUTUAL4_CTSUSOFF                 (_0_CTSUSOFF_ON)
#define MUTUAL5_CTSUSOFF                 (_0_CTSUSOFF_ON)
#define MUTUAL6_CTSUSOFF                 (_0_CTSUSOFF_ON)
#define MUTUAL7_CTSUSOFF                 (_0_CTSUSOFF_ON)

/*****    Address 000A 0903h CTSU Sensor wait time register    ********************************************************/
#define _00010000_CTSUSST_RECOMMEND      (16)       /* The value of these bits should be fixed to 00010000b           */

/*****    Address 000A 0904h CTSU Measurement channel register0    ****************************************************/
/***** Self-capacitance single scan mode only *************************************************************************/
                                                    /*       100pin         80pin  64pin         48pin                */
#define _000000_CTSUMCH0_TS00            (0)        /* TS00 ( RX113, RX231, RX130,        RX130,              )       */
#define _000001_CTSUMCH0_TS01            (1)        /* TS01 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define _000010_CTSUMCH0_TS02            (2)        /* TS02 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define _000011_CTSUMCH0_TS03            (3)        /* TS03 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define _000100_CTSUMCH0_TS04            (4)        /* TS04 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define _000101_CTSUMCH0_TS05            (5)        /* TS05 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define _000110_CTSUMCH0_TS06            (6)        /* TS06 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define _000111_CTSUMCH0_TS07            (7)        /* TS07 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define _001000_CTSUMCH0_TS08            (8)        /* TS08 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define _001001_CTSUMCH0_TS09            (9)        /* TS09 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define _001010_CTSUMCH0_TS10            (10)       /* TS10 ( RX113,        RX130,        RX130,        RX130 )       */
#define _001011_CTSUMCH0_TS11            (11)       /* TS11 ( RX113,        RX130,        RX130               )       */
#define _001100_CTSUMCH0_TS12            (12)       /* TS12 (        RX231, RX130, RX231, RX130, RX231        )       */
#define _001101_CTSUMCH0_TS13            (13)       /* TS13 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define _001110_CTSUMCH0_TS14            (14)       /* TS14 (               RX130,        RX130,        RX130 )       */
#define _001111_CTSUMCH0_TS15            (15)       /* TS15 (        RX231, RX130, RX231, RX130,        RX130 )       */
#define _010000_CTSUMCH0_TS16            (16)       /* TS16 (        RX231, RX130, RX231, RX130               )       */
#define _010001_CTSUMCH0_TS17            (17)       /* TS17 (        RX231, RX130,        RX130               )       */
#define _010010_CTSUMCH0_TS18            (18)       /* TS18 (        RX231, RX130,        RX130,              )       */
#define _010011_CTSUMCH0_TS19            (19)       /* TS19 (        RX231, RX130,        RX130,              )       */
#define _010100_CTSUMCH0_TS20            (20)       /* TS20 (        RX231, RX130,        RX130,        RX130 )       */
#define _010101_CTSUMCH0_TS21            (21)       /* TS21 (               RX130                             )       */
#define _010110_CTSUMCH0_TS22            (22)       /* TS22 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define _010111_CTSUMCH0_TS23            (23)       /* TS23 (        RX231, RX130, RX231,        RX231        )       */
#define _011000_CTSUMCH0_TS24            (24)       /* TS24 (               RX130,        RX130,        RX130 )       */
#define _011001_CTSUMCH0_TS25            (25)       /* TS25 (               RX130,        RX130,        RX130 )       */
#define _011010_CTSUMCH0_TS26            (26)       /* TS26 (               RX130,        RX130,        RX130 )       */
#define _011011_CTSUMCH0_TS27            (27)       /* TS27 (        RX231, RX130, RX231                      )       */
#define _011100_CTSUMCH0_TS28            (28)       /* TS28 (               RX130,        RX130,        RX130 )       */
#define _011101_CTSUMCH0_TS29            (29)       /* TS29 (               RX130,        RX130,        RX130 )       */
#define _011110_CTSUMCH0_TS30            (30)       /* TS30 (        RX231, RX130, RX231                      )       */
#define _011111_CTSUMCH0_TS31            (31)       /* TS31 (               RX130,        RX130,        RX130 )       */
#define _100000_CTSUMCH0_TS32            (32)       /* TS32 (        RX231, RX130,        RX130               )       */
#define _100001_CTSUMCH0_TS33            (33)       /* TS33 (               RX130,        RX130,        RX130 )       */
#define _100010_CTSUMCH0_TS34            (34)       /* TS34 (               RX130,        RX130,        RX130 )       */
#define _100011_CTSUMCH0_TS35            (35)       /* TS35 (        RX231, RX130,        RX130,        RX130 )       */
                                                    /* Total    12     24     36     10     32      6     24          */

/*****    Address 000A 0910h CTSU Channel send and receive control register 0 *****************************************/
#define _00_CTSUSSMOD                    (0)        /* These bits should be set to 00b.                               */
#define _11_CTSUSSCNT                    (3)        /* These bits should be set to 11b.                               */

#if ( SELF_METHOD_NUM == 1 )

/*====================================================================================================================*/
/*=====     Self-measurement TS enable definition     ================================================================*/
/*=====     0:disable 1:enable                        ================================================================*/
/*====================================================================================================================*/
                                                    /*       100pin         80pin  64pin         48pin                */
#define SELF_ENABLE_TS00                 (1)        /* TS00 ( RX113, RX231, RX130,        RX130,              )       */
#define SELF_ENABLE_TS01                 (1)        /* TS01 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS02                 (0)        /* TS02 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define SELF_ENABLE_TS03                 (0)        /* TS03 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define SELF_ENABLE_TS04                 (1)        /* TS04 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS05                 (1)        /* TS05 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS06                 (0)        /* TS06 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS07                 (0)        /* TS07 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS08                 (1)        /* TS08 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS09                 (0)        /* TS09 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS10                 (1)        /* TS10 ( RX113,        RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS11                 (1)        /* TS11 ( RX113,        RX130,        RX130               )       */
#define SELF_ENABLE_TS12                 (1)        /* TS12 (        RX231, RX130, RX231, RX130, RX231        )       */
#define SELF_ENABLE_TS13                 (1)        /* TS13 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define SELF_ENABLE_TS14                 (0)        /* TS14 (               RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS15                 (0)        /* TS15 (        RX231, RX130, RX231, RX130,        RX130 )       */
#define SELF_ENABLE_TS16                 (0)        /* TS16 (        RX231, RX130, RX231, RX130               )       */
#define SELF_ENABLE_TS17                 (0)        /* TS17 (        RX231, RX130,        RX130               )       */
#define SELF_ENABLE_TS18                 (0)        /* TS18 (        RX231, RX130,        RX130,              )       */
#define SELF_ENABLE_TS19                 (0)        /* TS19 (        RX231, RX130,        RX130,              )       */
#define SELF_ENABLE_TS20                 (1)        /* TS20 (        RX231, RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS21                 (1)        /* TS21 (               RX130                             )       */
#define SELF_ENABLE_TS22                 (1)        /* TS22 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define SELF_ENABLE_TS23                 (0)        /* TS23 (        RX231, RX130, RX231,        RX231        )       */
#define SELF_ENABLE_TS24                 (0)        /* TS24 (               RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS25                 (0)        /* TS25 (               RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS26                 (1)        /* TS26 (               RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS27                 (1)        /* TS27 (        RX231, RX130, RX231                      )       */
#define SELF_ENABLE_TS28                 (0)        /* TS28 (               RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS29                 (1)        /* TS29 (               RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS30                 (1)        /* TS30 (        RX231, RX130, RX231                      )       */
#define SELF_ENABLE_TS31                 (1)        /* TS31 (               RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS32                 (1)        /* TS32 (        RX231, RX130,        RX130               )       */
#define SELF_ENABLE_TS33                 (0)        /* TS33 (               RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS34                 (1)        /* TS34 (               RX130,        RX130,        RX130 )       */
#define SELF_ENABLE_TS35                 (1)        /* TS35 (        RX231, RX130,        RX130,        RX130 )       */
                                                    /* Total    12     24     36     10     32      6     24          */

/*****    Address 000A 0906h CTSU Channel enable control register 0    ************************************************/
#define CTSUCHAC0_SELF_ENABLE_TS       ((SELF_ENABLE_TS00 << 0) | (SELF_ENABLE_TS01 << 1) | (SELF_ENABLE_TS02 << 2) | \
                                        (SELF_ENABLE_TS03 << 3) | (SELF_ENABLE_TS04 << 4) | (SELF_ENABLE_TS05 << 5) | \
                                        (SELF_ENABLE_TS06 << 6) | (SELF_ENABLE_TS07 << 7))

/*****    Address 000A 0907h CTSU Channel enable control register 1    ************************************************/
#define CTSUCHAC1_SELF_ENABLE_TS       ((SELF_ENABLE_TS08 << 0) | (SELF_ENABLE_TS09 << 1) | (SELF_ENABLE_TS10 << 2) | \
                                        (SELF_ENABLE_TS11 << 3) | (SELF_ENABLE_TS12 << 4) | (SELF_ENABLE_TS13 << 5) | \
                                        (SELF_ENABLE_TS14 << 6) | (SELF_ENABLE_TS15 << 7))

/*****    Address 000A 0908h CTSU Channel enable control register 2    ************************************************/
#define CTSUCHAC2_SELF_ENABLE_TS       ((SELF_ENABLE_TS16 << 0) | (SELF_ENABLE_TS17 << 1) | (SELF_ENABLE_TS18 << 2) | \
                                        (SELF_ENABLE_TS19 << 3) | (SELF_ENABLE_TS20 << 4) | (SELF_ENABLE_TS21 << 5) | \
                                        (SELF_ENABLE_TS22 << 6) | (SELF_ENABLE_TS23 << 7))

/*****    Address 000A 0909h CTSU Channel enable control register 3    ************************************************/
#define CTSUCHAC3_SELF_ENABLE_TS       ((SELF_ENABLE_TS24 << 0) | (SELF_ENABLE_TS25 << 1) | (SELF_ENABLE_TS26 << 2) | \
                                        (SELF_ENABLE_TS27 << 3) | (SELF_ENABLE_TS28 << 4) | (SELF_ENABLE_TS29 << 5) | \
                                        (SELF_ENABLE_TS30 << 6) | (SELF_ENABLE_TS31 << 7))

/*****    Address 000A 090ah CTSU Channel enable control register 4    ************************************************/
#define CTSUCHAC4_SELF_ENABLE_TS       ((SELF_ENABLE_TS32 << 0) | (SELF_ENABLE_TS33 << 1) | (SELF_ENABLE_TS34 << 2) | \
                                        (SELF_ENABLE_TS35 << 3))

/* SUM of Channels */ /* Do not edit this macro definition */
#define SELF_ENABLE_NUM                 (SELF_ENABLE_TS00 + SELF_ENABLE_TS01 + SELF_ENABLE_TS02 + SELF_ENABLE_TS03 + \
                                         SELF_ENABLE_TS04 + SELF_ENABLE_TS05 + SELF_ENABLE_TS06 + SELF_ENABLE_TS07 + \
                                         SELF_ENABLE_TS08 + SELF_ENABLE_TS09 + SELF_ENABLE_TS10 + SELF_ENABLE_TS11 + \
                                         SELF_ENABLE_TS12 + SELF_ENABLE_TS13 + SELF_ENABLE_TS14 + SELF_ENABLE_TS15 + \
                                         SELF_ENABLE_TS16 + SELF_ENABLE_TS17 + SELF_ENABLE_TS18 + SELF_ENABLE_TS19 + \
                                         SELF_ENABLE_TS20 + SELF_ENABLE_TS21 + SELF_ENABLE_TS22 + SELF_ENABLE_TS23 + \
                                         SELF_ENABLE_TS24 + SELF_ENABLE_TS25 + SELF_ENABLE_TS26 + SELF_ENABLE_TS27 + \
                                         SELF_ENABLE_TS28 + SELF_ENABLE_TS29 + SELF_ENABLE_TS30 + SELF_ENABLE_TS31 + \
                                         SELF_ENABLE_TS32 + SELF_ENABLE_TS33 + SELF_ENABLE_TS34 + SELF_ENABLE_TS35)

/*****    Address 000A 0912h CTSU High-Pass Noise Reduction Spectrum Diffusion Control Register    ********************/
/**********************************************************************************************************************/
/*    CTSU Spectrum Diffusion Frequency Division Setting                                                              */
/*    Base Clock Frequency fb (MHz)   CTSUSSDIV[3:0] Bit Setting                                                      */
/*          4.00 =< fb                           0x00                                                                 */
/*          2.00 =< fb  < 4.00                   0x01                                                                 */
/*          1.33 =< fb  < 2.00                   0x02                                                                 */
/*          1.00 =< fb  < 1.33                   0x03                                                                 */
/*          0.80 =< fb  < 1.00                   0x04                                                                 */
/*          0.67 =< fb  < 0.80                   0x05                                                                 */
/*          0.57 =< fb  < 0.67                   0x06                                                                 */
/*          0.50 =< fb  < 0.57                   0x07                                                                 */
/*          0.44 =< fb  < 0.50                   0x08                                                                 */
/*          0.40 =< fb  < 0.44                   0x09                                                                 */
/*          0.36 =< fb  < 0.40                   0x0A                                                                 */
/*          0.33 =< fb  < 0.36                   0x0B                                                                 */
/*          0.31 =< fb  < 0.33                   0x0C                                                                 */
/*          0.29 =< fb  < 0.31                   0x0D                                                                 */
/*          0.27 =< fb  < 0.29                   0x0E                                                                 */
/*                  fb =< 0.25                   0x0F                                                                 */
/**********************************************************************************************************************/
                                                    /*       100pin         80pin  64pin         48pin                */
#define CTSUSSDIV_TS00                (0x00)        /* TS00 ( RX113, RX231, RX130,        RX130,              )       */
#define CTSUSSDIV_TS01                (0x00)        /* TS01 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS02                (0x07)        /* TS02 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSSDIV_TS03                (0x07)        /* TS03 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSSDIV_TS04                (0x00)        /* TS04 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS05                (0x00)        /* TS05 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS06                (0x07)        /* TS06 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS07                (0x07)        /* TS07 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS08                (0x00)        /* TS08 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS09                (0x07)        /* TS09 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS10                (0x00)        /* TS10 ( RX113,        RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS11                (0x00)        /* TS11 ( RX113,        RX130,        RX130               )       */
#define CTSUSSDIV_TS12                (0x00)        /* TS12 (        RX231, RX130, RX231, RX130, RX231        )       */
#define CTSUSSDIV_TS13                (0x00)        /* TS13 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSSDIV_TS14                (0x07)        /* TS14 (               RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS15                (0x07)        /* TS15 (        RX231, RX130, RX231, RX130,        RX130 )       */
#define CTSUSSDIV_TS16                (0x07)        /* TS16 (        RX231, RX130, RX231, RX130               )       */
#define CTSUSSDIV_TS17                (0x07)        /* TS17 (        RX231, RX130,        RX130               )       */
#define CTSUSSDIV_TS18                (0x07)        /* TS18 (        RX231, RX130,        RX130,              )       */
#define CTSUSSDIV_TS19                (0x07)        /* TS19 (        RX231, RX130,        RX130,              )       */
#define CTSUSSDIV_TS20                (0x00)        /* TS20 (        RX231, RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS21                (0x00)        /* TS21 (               RX130                             )       */
#define CTSUSSDIV_TS22                (0x00)        /* TS22 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSSDIV_TS23                (0x07)        /* TS23 (        RX231, RX130, RX231,        RX231        )       */
#define CTSUSSDIV_TS24                (0x07)        /* TS24 (               RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS25                (0x07)        /* TS25 (               RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS26                (0x00)        /* TS26 (               RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS27                (0x00)        /* TS27 (        RX231, RX130, RX231                      )       */
#define CTSUSSDIV_TS28                (0x07)        /* TS28 (               RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS29                (0x00)        /* TS29 (               RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS30                (0x00)        /* TS30 (        RX231, RX130, RX231                      )       */
#define CTSUSSDIV_TS31                (0x00)        /* TS31 (               RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS32                (0x00)        /* TS32 (        RX231, RX130,        RX130               )       */
#define CTSUSSDIV_TS33                (0x07)        /* TS33 (               RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS34                (0x00)        /* TS34 (               RX130,        RX130,        RX130 )       */
#define CTSUSSDIV_TS35                (0x00)        /* TS35 (        RX231, RX130,        RX130,        RX130 )       */
                                                    /* Total    12     24     36     10     32      6     24          */

#define CTSUSSC_TS00                  (CTSUSSDIV_TS00 << 8)
#define CTSUSSC_TS01                  (CTSUSSDIV_TS01 << 8)
#define CTSUSSC_TS02                  (CTSUSSDIV_TS02 << 8)
#define CTSUSSC_TS03                  (CTSUSSDIV_TS03 << 8)
#define CTSUSSC_TS04                  (CTSUSSDIV_TS04 << 8)
#define CTSUSSC_TS05                  (CTSUSSDIV_TS05 << 8)
#define CTSUSSC_TS06                  (CTSUSSDIV_TS06 << 8)
#define CTSUSSC_TS07                  (CTSUSSDIV_TS07 << 8)
#define CTSUSSC_TS08                  (CTSUSSDIV_TS08 << 8)
#define CTSUSSC_TS09                  (CTSUSSDIV_TS09 << 8)
#define CTSUSSC_TS10                  (CTSUSSDIV_TS10 << 8)
#define CTSUSSC_TS11                  (CTSUSSDIV_TS11 << 8)
#define CTSUSSC_TS12                  (CTSUSSDIV_TS12 << 8)
#define CTSUSSC_TS13                  (CTSUSSDIV_TS13 << 8)
#define CTSUSSC_TS14                  (CTSUSSDIV_TS14 << 8)
#define CTSUSSC_TS15                  (CTSUSSDIV_TS15 << 8)
#define CTSUSSC_TS16                  (CTSUSSDIV_TS16 << 8)
#define CTSUSSC_TS17                  (CTSUSSDIV_TS17 << 8)
#define CTSUSSC_TS18                  (CTSUSSDIV_TS18 << 8)
#define CTSUSSC_TS19                  (CTSUSSDIV_TS19 << 8)
#define CTSUSSC_TS20                  (CTSUSSDIV_TS20 << 8)
#define CTSUSSC_TS21                  (CTSUSSDIV_TS21 << 8)
#define CTSUSSC_TS22                  (CTSUSSDIV_TS22 << 8)
#define CTSUSSC_TS23                  (CTSUSSDIV_TS23 << 8)
#define CTSUSSC_TS24                  (CTSUSSDIV_TS24 << 8)
#define CTSUSSC_TS25                  (CTSUSSDIV_TS25 << 8)
#define CTSUSSC_TS26                  (CTSUSSDIV_TS26 << 8)
#define CTSUSSC_TS27                  (CTSUSSDIV_TS27 << 8)
#define CTSUSSC_TS28                  (CTSUSSDIV_TS28 << 8)
#define CTSUSSC_TS29                  (CTSUSSDIV_TS29 << 8)
#define CTSUSSC_TS30                  (CTSUSSDIV_TS30 << 8)
#define CTSUSSC_TS31                  (CTSUSSDIV_TS31 << 8)
#define CTSUSSC_TS32                  (CTSUSSDIV_TS32 << 8)
#define CTSUSSC_TS33                  (CTSUSSDIV_TS33 << 8)
#define CTSUSSC_TS34                  (CTSUSSDIV_TS34 << 8)
#define CTSUSSC_TS35                  (CTSUSSDIV_TS35 << 8)

/*****    Address 0000A 0914h CTSU Sensor offset register0     ********************************************************/
/**********************************************************************************************************************/
/*    CTSU Sensor Offset Adjustment Setting                                                                           */
/*      Current offset amount is 0       0x000                                                                        */
/*      Current offset amount is 1       0x001                                                                        */
/*      Current offset amount is 2       0x002                                                                        */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*      Current offset amount is 1023    0x3FF                                                                        */
/**********************************************************************************************************************/
                                                    /*       100pin         80pin  64pin         48pin                */
#define CTSUSO_TS00                   (0x2BC)       /* TS00 ( RX113, RX231, RX130,        RX130,              )       */
#define CTSUSO_TS01                   (0x29A)       /* TS01 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSO_TS02                   (0x000)       /* TS02 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSO_TS03                   (0x000)       /* TS03 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSO_TS04                   (0x24B)       /* TS04 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSO_TS05                   (0x291)       /* TS05 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSO_TS06                   (0x000)       /* TS06 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSO_TS07                   (0x000)       /* TS07 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSO_TS08                   (0x24F)       /* TS08 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSO_TS09                   (0x000)       /* TS09 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSO_TS10                   (0x264)       /* TS10 ( RX113,        RX130,        RX130,        RX130 )       */
#define CTSUSO_TS11                   (0x202)       /* TS11 ( RX113,        RX130,        RX130               )       */
#define CTSUSO_TS12                   (0x26D)       /* TS12 (        RX231, RX130, RX231, RX130, RX231        )       */
#define CTSUSO_TS13                   (0x25D)       /* TS13 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSO_TS14                   (0x000)       /* TS14 (               RX130,        RX130,        RX130 )       */
#define CTSUSO_TS15                   (0x000)       /* TS15 (        RX231, RX130, RX231, RX130,        RX130 )       */
#define CTSUSO_TS16                   (0x000)       /* TS16 (        RX231, RX130, RX231, RX130               )       */
#define CTSUSO_TS17                   (0x000)       /* TS17 (        RX231, RX130,        RX130               )       */
#define CTSUSO_TS18                   (0x000)       /* TS18 (        RX231, RX130,        RX130,              )       */
#define CTSUSO_TS19                   (0x000)       /* TS19 (        RX231, RX130,        RX130,              )       */
#define CTSUSO_TS20                   (0x22E)       /* TS20 (        RX231, RX130,        RX130,        RX130 )       */
#define CTSUSO_TS21                   (0x32B)       /* TS21 (               RX130                             )       */
#define CTSUSO_TS22                   (0x233)       /* TS22 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSO_TS23                   (0x000)       /* TS23 (        RX231, RX130, RX231,        RX231        )       */
#define CTSUSO_TS24                   (0x000)       /* TS24 (               RX130,        RX130,        RX130 )       */
#define CTSUSO_TS25                   (0x000)       /* TS25 (               RX130,        RX130,        RX130 )       */
#define CTSUSO_TS26                   (0x24A)       /* TS26 (               RX130,        RX130,        RX130 )       */
#define CTSUSO_TS27                   (0x1D5)       /* TS27 (        RX231, RX130, RX231                      )       */
#define CTSUSO_TS28                   (0x000)       /* TS28 (               RX130,        RX130,        RX130 )       */
#define CTSUSO_TS29                   (0x209)       /* TS29 (               RX130,        RX130,        RX130 )       */
#define CTSUSO_TS30                   (0x28C)       /* TS30 (        RX231, RX130, RX231                      )       */
#define CTSUSO_TS31                   (0x295)       /* TS31 (               RX130,        RX130,        RX130 )       */
#define CTSUSO_TS32                   (0x2F1)       /* TS32 (        RX231, RX130,        RX130               )       */
#define CTSUSO_TS33                   (0x000)       /* TS33 (               RX130,        RX130,        RX130 )       */
#define CTSUSO_TS34                   (0x277)       /* TS34 (               RX130,        RX130,        RX130 )       */
#define CTSUSO_TS35                   (0x2B9)       /* TS35 (        RX231, RX130,        RX130,        RX130 )       */
                                                    /* Total    12     24     36     10     32      6     24          */
/**********************************************************************************************************************/
/*    CTSU Measurement Count Setting                                                                                  */
/*      4.0MHz    7                                                                                                   */
/*      2.0MHz    3                                                                                                   */
/*      1.0MHz    1                                                                                                   */
/*      0.5MHz    0                                                                                                   */
/**********************************************************************************************************************/
                                                    /*       100pin         80pin  64pin         48pin                */
#define CTSUSNUM_TS00                 (7)           /* TS00 ( RX113, RX231, RX130,        RX130,              )       */
#define CTSUSNUM_TS01                 (7)           /* TS01 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS02                 (0)           /* TS02 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSNUM_TS03                 (0)           /* TS03 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSNUM_TS04                 (7)           /* TS04 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS05                 (7)           /* TS05 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS06                 (0)           /* TS06 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS07                 (0)           /* TS07 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS08                 (7)           /* TS08 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS09                 (0)           /* TS09 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS10                 (7)           /* TS10 ( RX113,        RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS11                 (7)           /* TS11 ( RX113,        RX130,        RX130               )       */
#define CTSUSNUM_TS12                 (7)           /* TS12 (        RX231, RX130, RX231, RX130, RX231        )       */
#define CTSUSNUM_TS13                 (7)           /* TS13 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSNUM_TS14                 (0)           /* TS14 (               RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS15                 (0)           /* TS15 (        RX231, RX130, RX231, RX130,        RX130 )       */
#define CTSUSNUM_TS16                 (0)           /* TS16 (        RX231, RX130, RX231, RX130               )       */
#define CTSUSNUM_TS17                 (0)           /* TS17 (        RX231, RX130,        RX130               )       */
#define CTSUSNUM_TS18                 (0)           /* TS18 (        RX231, RX130,        RX130,              )       */
#define CTSUSNUM_TS19                 (0)           /* TS19 (        RX231, RX130,        RX130,              )       */
#define CTSUSNUM_TS20                 (7)           /* TS20 (        RX231, RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS21                 (7)           /* TS21 (               RX130                             )       */
#define CTSUSNUM_TS22                 (7)           /* TS22 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSNUM_TS23                 (0)           /* TS23 (        RX231, RX130, RX231,        RX231        )       */
#define CTSUSNUM_TS24                 (0)           /* TS24 (               RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS25                 (0)           /* TS25 (               RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS26                 (7)           /* TS26 (               RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS27                 (7)           /* TS27 (        RX231, RX130, RX231                      )       */
#define CTSUSNUM_TS28                 (0)           /* TS28 (               RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS29                 (7)           /* TS29 (               RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS30                 (7)           /* TS30 (        RX231, RX130, RX231                      )       */
#define CTSUSNUM_TS31                 (7)           /* TS31 (               RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS32                 (7)           /* TS32 (        RX231, RX130,        RX130               )       */
#define CTSUSNUM_TS33                 (0)           /* TS33 (               RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS34                 (7)           /* TS34 (               RX130,        RX130,        RX130 )       */
#define CTSUSNUM_TS35                 (7)           /* TS35 (        RX231, RX130,        RX130,        RX130 )       */
                                                    /* Total    12     24     36     10     32      6     24          */

/* CTSU Sensor Offset Register 0 initial value  */
#define CTSUSO0_TS00                  ((CTSUSNUM_TS00 << 10) | CTSUSO_TS00)
#define CTSUSO0_TS01                  ((CTSUSNUM_TS01 << 10) | CTSUSO_TS01)
#define CTSUSO0_TS02                  ((CTSUSNUM_TS02 << 10) | CTSUSO_TS02)
#define CTSUSO0_TS03                  ((CTSUSNUM_TS03 << 10) | CTSUSO_TS03)
#define CTSUSO0_TS04                  ((CTSUSNUM_TS04 << 10) | CTSUSO_TS04)
#define CTSUSO0_TS05                  ((CTSUSNUM_TS05 << 10) | CTSUSO_TS05)
#define CTSUSO0_TS06                  ((CTSUSNUM_TS06 << 10) | CTSUSO_TS06)
#define CTSUSO0_TS07                  ((CTSUSNUM_TS07 << 10) | CTSUSO_TS07)
#define CTSUSO0_TS08                  ((CTSUSNUM_TS08 << 10) | CTSUSO_TS08)
#define CTSUSO0_TS09                  ((CTSUSNUM_TS09 << 10) | CTSUSO_TS09)
#define CTSUSO0_TS10                  ((CTSUSNUM_TS10 << 10) | CTSUSO_TS10)
#define CTSUSO0_TS11                  ((CTSUSNUM_TS11 << 10) | CTSUSO_TS11)
#define CTSUSO0_TS12                  ((CTSUSNUM_TS12 << 10) | CTSUSO_TS12)
#define CTSUSO0_TS13                  ((CTSUSNUM_TS13 << 10) | CTSUSO_TS13)
#define CTSUSO0_TS14                  ((CTSUSNUM_TS14 << 10) | CTSUSO_TS14)
#define CTSUSO0_TS15                  ((CTSUSNUM_TS15 << 10) | CTSUSO_TS15)
#define CTSUSO0_TS16                  ((CTSUSNUM_TS16 << 10) | CTSUSO_TS16)
#define CTSUSO0_TS17                  ((CTSUSNUM_TS17 << 10) | CTSUSO_TS17)
#define CTSUSO0_TS18                  ((CTSUSNUM_TS18 << 10) | CTSUSO_TS18)
#define CTSUSO0_TS19                  ((CTSUSNUM_TS19 << 10) | CTSUSO_TS19)
#define CTSUSO0_TS20                  ((CTSUSNUM_TS20 << 10) | CTSUSO_TS20)
#define CTSUSO0_TS21                  ((CTSUSNUM_TS21 << 10) | CTSUSO_TS21)
#define CTSUSO0_TS22                  ((CTSUSNUM_TS22 << 10) | CTSUSO_TS22)
#define CTSUSO0_TS23                  ((CTSUSNUM_TS23 << 10) | CTSUSO_TS23)
#define CTSUSO0_TS24                  ((CTSUSNUM_TS24 << 10) | CTSUSO_TS24)
#define CTSUSO0_TS25                  ((CTSUSNUM_TS25 << 10) | CTSUSO_TS25)
#define CTSUSO0_TS26                  ((CTSUSNUM_TS26 << 10) | CTSUSO_TS26)
#define CTSUSO0_TS27                  ((CTSUSNUM_TS27 << 10) | CTSUSO_TS27)
#define CTSUSO0_TS28                  ((CTSUSNUM_TS28 << 10) | CTSUSO_TS28)
#define CTSUSO0_TS29                  ((CTSUSNUM_TS29 << 10) | CTSUSO_TS29)
#define CTSUSO0_TS30                  ((CTSUSNUM_TS30 << 10) | CTSUSO_TS30)
#define CTSUSO0_TS31                  ((CTSUSNUM_TS31 << 10) | CTSUSO_TS31)
#define CTSUSO0_TS32                  ((CTSUSNUM_TS32 << 10) | CTSUSO_TS32)
#define CTSUSO0_TS33                  ((CTSUSNUM_TS33 << 10) | CTSUSO_TS33)
#define CTSUSO0_TS34                  ((CTSUSNUM_TS34 << 10) | CTSUSO_TS34)
#define CTSUSO0_TS35                  ((CTSUSNUM_TS35 << 10) | CTSUSO_TS35)

/*****    Address 000A 0914h CTSU Sensor Offset Register 1    *********************************************************/
/**********************************************************************************************************************/
/*    CTSU Reference ICO Current Adjustment                                                                           */
/*        Input current amount 0      0x00                                                                            */
/*        Input current amount 1      0x01                                                                            */
/*        Input current amount 2      0x02                                                                            */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*        Input current amount 254    0xFF                                                                            */
/**********************************************************************************************************************/
                                                    /*       100pin         80pin  64pin         48pin                */
#define CTSURICOA_TS00                (0x5F)        /* TS00 ( RX113, RX231, RX130,        RX130,              )       */
#define CTSURICOA_TS01                (0x5F)        /* TS01 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS02                (0x5F)        /* TS02 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSURICOA_TS03                (0x5F)        /* TS03 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSURICOA_TS04                (0x5F)        /* TS04 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS05                (0x5F)        /* TS05 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS06                (0x5F)        /* TS06 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS07                (0x5F)        /* TS07 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS08                (0x5F)        /* TS08 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS09                (0x5F)        /* TS09 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS10                (0x5F)        /* TS10 ( RX113,        RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS11                (0x5F)        /* TS11 ( RX113,        RX130,        RX130               )       */
#define CTSURICOA_TS12                (0x5F)        /* TS12 (        RX231, RX130, RX231, RX130, RX231        )       */
#define CTSURICOA_TS13                (0x5F)        /* TS13 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSURICOA_TS14                (0x5F)        /* TS14 (               RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS15                (0x5F)        /* TS15 (        RX231, RX130, RX231, RX130,        RX130 )       */
#define CTSURICOA_TS16                (0x5F)        /* TS16 (        RX231, RX130, RX231, RX130               )       */
#define CTSURICOA_TS17                (0x5F)        /* TS17 (        RX231, RX130,        RX130               )       */
#define CTSURICOA_TS18                (0x5F)        /* TS18 (        RX231, RX130,        RX130,              )       */
#define CTSURICOA_TS19                (0x5F)        /* TS19 (        RX231, RX130,        RX130,              )       */
#define CTSURICOA_TS20                (0x5F)        /* TS20 (        RX231, RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS21                (0x5F)        /* TS21 (               RX130                             )       */
#define CTSURICOA_TS22                (0x5F)        /* TS22 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSURICOA_TS23                (0x5F)        /* TS23 (        RX231, RX130, RX231,        RX231        )       */
#define CTSURICOA_TS24                (0x5F)        /* TS24 (               RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS25                (0x5F)        /* TS25 (               RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS26                (0x5F)        /* TS26 (               RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS27                (0x5F)        /* TS27 (        RX231, RX130, RX231                      )       */
#define CTSURICOA_TS28                (0x5F)        /* TS28 (               RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS29                (0x5F)        /* TS29 (               RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS30                (0x5F)        /* TS30 (        RX231, RX130, RX231                      )       */
#define CTSURICOA_TS31                (0x5F)        /* TS31 (               RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS32                (0x5F)        /* TS32 (        RX231, RX130,        RX130               )       */
#define CTSURICOA_TS33                (0x5F)        /* TS33 (               RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS34                (0x5F)        /* TS34 (               RX130,        RX130,        RX130 )       */
#define CTSURICOA_TS35                (0x5F)        /* TS35 (        RX231, RX130,        RX130,        RX130 )       */
                                                    /* Total    12     24     36     10     32      6     24          */
/**********************************************************************************************************************/
/*    CTSU Base Clock Setting                                                                                         */
/*        Operating clock divided by 2     0x00                                                                       */
/*        Operating clock divided by 4     0x01                                                                       */
/*        Operating clock divided by 6     0x02                                                                       */
/*                       :                                                                                            */
/*                       :                                                                                            */
/*        Operating clock divided by 64    0x1F                                                                       */
/*                                                                                                                    */
/*    Case : CTSU Operating Clock 32MHz      Case : CTSU Operating Clock 24MHz      Case : CTSU Operating Clock 16MHz */
/*           4.0MHz <--- 0x03                       4.0MHz <--- 0x02                       4.0MHz <--- 0x01           */
/*           2.0MHz <--- 0x07                       2.0MHz <--- 0x05                       2.0MHz <--- 0x03           */
/*           1.0MHz <--- 0x0F                       1.0MHz <--- 0x0B                       1.0MHz <--- 0x07           */
/*           0.5MHz <--- 0x1F                       0.5MHz <--- 0x17                       0.5MHz <--- 0x0F           */
/**********************************************************************************************************************/
                                                    /*       100pin         80pin  64pin         48pin                */
#define CTSUSDPA_TS00                 (0x02)        /* TS00 ( RX113, RX231, RX130,        RX130,              )       */
#define CTSUSDPA_TS01                 (0x02)        /* TS01 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS02                 (0x1F)        /* TS02 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSDPA_TS03                 (0x1F)        /* TS03 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSDPA_TS04                 (0x02)        /* TS04 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS05                 (0x02)        /* TS05 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS06                 (0x1F)        /* TS06 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS07                 (0x1F)        /* TS07 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS08                 (0x02)        /* TS08 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS09                 (0x1F)        /* TS09 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS10                 (0x02)        /* TS10 ( RX113,        RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS11                 (0x02)        /* TS11 ( RX113,        RX130,        RX130               )       */
#define CTSUSDPA_TS12                 (0x02)        /* TS12 (        RX231, RX130, RX231, RX130, RX231        )       */
#define CTSUSDPA_TS13                 (0x02)        /* TS13 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSDPA_TS14                 (0x1F)        /* TS14 (               RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS15                 (0x1F)        /* TS15 (        RX231, RX130, RX231, RX130,        RX130 )       */
#define CTSUSDPA_TS16                 (0x1F)        /* TS16 (        RX231, RX130, RX231, RX130               )       */
#define CTSUSDPA_TS17                 (0x1F)        /* TS17 (        RX231, RX130,        RX130               )       */
#define CTSUSDPA_TS18                 (0x1F)        /* TS18 (        RX231, RX130,        RX130,              )       */
#define CTSUSDPA_TS19                 (0x1F)        /* TS19 (        RX231, RX130,        RX130,              )       */
#define CTSUSDPA_TS20                 (0x02)        /* TS20 (        RX231, RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS21                 (0x02)        /* TS21 (               RX130                             )       */
#define CTSUSDPA_TS22                 (0x02)        /* TS22 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUSDPA_TS23                 (0x1F)        /* TS23 (        RX231, RX130, RX231,        RX231        )       */
#define CTSUSDPA_TS24                 (0x1F)        /* TS24 (               RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS25                 (0x1F)        /* TS25 (               RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS26                 (0x02)        /* TS26 (               RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS27                 (0x02)        /* TS27 (        RX231, RX130, RX231                      )       */
#define CTSUSDPA_TS28                 (0x1F)        /* TS28 (               RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS29                 (0x02)        /* TS29 (               RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS30                 (0x02)        /* TS30 (        RX231, RX130, RX231                      )       */
#define CTSUSDPA_TS31                 (0x02)        /* TS31 (               RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS32                 (0x02)        /* TS32 (        RX231, RX130,        RX130               )       */
#define CTSUSDPA_TS33                 (0x1F)        /* TS33 (               RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS34                 (0x02)        /* TS34 (               RX130,        RX130,        RX130 )       */
#define CTSUSDPA_TS35                 (0x02)        /* TS35 (        RX231, RX130,        RX130,        RX130 )       */
                                                    /* Total    12     24     36     10     32      6     24          */
/**********************************************************************************************************************/
/*    CTSU ICO Gain Adjustment                                                                                        */
/*        0 : 100% gain                                                                                               */
/*        1 :  66% gain                                                                                               */
/*        2 :  50% gain                                                                                               */
/*        3 :  40% gain                                                                                               */
/**********************************************************************************************************************/
                                                    /*       100pin         80pin  64pin         48pin                */
#define CTSUICOG_TS00                 (1)           /* TS00 ( RX113, RX231, RX130,        RX130,              )       */
#define CTSUICOG_TS01                 (1)           /* TS01 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS02                 (1)           /* TS02 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUICOG_TS03                 (1)           /* TS03 ( RX113, RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUICOG_TS04                 (1)           /* TS04 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS05                 (1)           /* TS05 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS06                 (1)           /* TS06 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS07                 (1)           /* TS07 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS08                 (1)           /* TS08 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS09                 (1)           /* TS09 ( RX113, RX231, RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS10                 (1)           /* TS10 ( RX113,        RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS11                 (1)           /* TS11 ( RX113,        RX130,        RX130               )       */
#define CTSUICOG_TS12                 (1)           /* TS12 (        RX231, RX130, RX231, RX130, RX231        )       */
#define CTSUICOG_TS13                 (1)           /* TS13 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUICOG_TS14                 (1)           /* TS14 (               RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS15                 (1)           /* TS15 (        RX231, RX130, RX231, RX130,        RX130 )       */
#define CTSUICOG_TS16                 (1)           /* TS16 (        RX231, RX130, RX231, RX130               )       */
#define CTSUICOG_TS17                 (1)           /* TS17 (        RX231, RX130,        RX130               )       */
#define CTSUICOG_TS18                 (1)           /* TS18 (        RX231, RX130,        RX130,              )       */
#define CTSUICOG_TS19                 (1)           /* TS19 (        RX231, RX130,        RX130,              )       */
#define CTSUICOG_TS20                 (1)           /* TS20 (        RX231, RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS21                 (1)           /* TS21 (               RX130                             )       */
#define CTSUICOG_TS22                 (1)           /* TS22 (        RX231, RX130, RX231, RX130, RX231, RX130 )       */
#define CTSUICOG_TS23                 (1)           /* TS23 (        RX231, RX130, RX231,        RX231        )       */
#define CTSUICOG_TS24                 (1)           /* TS24 (               RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS25                 (1)           /* TS25 (               RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS26                 (1)           /* TS26 (               RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS27                 (1)           /* TS27 (        RX231, RX130, RX231                      )       */
#define CTSUICOG_TS28                 (1)           /* TS28 (               RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS29                 (1)           /* TS29 (               RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS30                 (1)           /* TS30 (        RX231, RX130, RX231                      )       */
#define CTSUICOG_TS31                 (1)           /* TS31 (               RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS32                 (1)           /* TS32 (        RX231, RX130,        RX130               )       */
#define CTSUICOG_TS33                 (1)           /* TS33 (               RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS34                 (1)           /* TS34 (               RX130,        RX130,        RX130 )       */
#define CTSUICOG_TS35                 (1)           /* TS35 (        RX231, RX130,        RX130,        RX130 )       */
                                                    /* Total    12     24     36     10     32      6     24          */

/* CTSU Sensor Offset Register 1 initial value Do not change */
#define CTSUSO1_TS00                  (CTSUICOG_TS00 << 13) | (CTSUSDPA_TS00 << 8) | CTSURICOA_TS00
#define CTSUSO1_TS01                  (CTSUICOG_TS01 << 13) | (CTSUSDPA_TS01 << 8) | CTSURICOA_TS01
#define CTSUSO1_TS02                  (CTSUICOG_TS02 << 13) | (CTSUSDPA_TS02 << 8) | CTSURICOA_TS02
#define CTSUSO1_TS03                  (CTSUICOG_TS03 << 13) | (CTSUSDPA_TS03 << 8) | CTSURICOA_TS03
#define CTSUSO1_TS04                  (CTSUICOG_TS04 << 13) | (CTSUSDPA_TS04 << 8) | CTSURICOA_TS04
#define CTSUSO1_TS05                  (CTSUICOG_TS05 << 13) | (CTSUSDPA_TS05 << 8) | CTSURICOA_TS05
#define CTSUSO1_TS06                  (CTSUICOG_TS06 << 13) | (CTSUSDPA_TS06 << 8) | CTSURICOA_TS06
#define CTSUSO1_TS07                  (CTSUICOG_TS07 << 13) | (CTSUSDPA_TS07 << 8) | CTSURICOA_TS07
#define CTSUSO1_TS08                  (CTSUICOG_TS08 << 13) | (CTSUSDPA_TS08 << 8) | CTSURICOA_TS08
#define CTSUSO1_TS09                  (CTSUICOG_TS09 << 13) | (CTSUSDPA_TS09 << 8) | CTSURICOA_TS09
#define CTSUSO1_TS10                  (CTSUICOG_TS10 << 13) | (CTSUSDPA_TS10 << 8) | CTSURICOA_TS10
#define CTSUSO1_TS11                  (CTSUICOG_TS11 << 13) | (CTSUSDPA_TS11 << 8) | CTSURICOA_TS11
#define CTSUSO1_TS12                  (CTSUICOG_TS12 << 13) | (CTSUSDPA_TS12 << 8) | CTSURICOA_TS12
#define CTSUSO1_TS13                  (CTSUICOG_TS13 << 13) | (CTSUSDPA_TS13 << 8) | CTSURICOA_TS13
#define CTSUSO1_TS14                  (CTSUICOG_TS14 << 13) | (CTSUSDPA_TS14 << 8) | CTSURICOA_TS14
#define CTSUSO1_TS15                  (CTSUICOG_TS15 << 13) | (CTSUSDPA_TS15 << 8) | CTSURICOA_TS15
#define CTSUSO1_TS16                  (CTSUICOG_TS16 << 13) | (CTSUSDPA_TS16 << 8) | CTSURICOA_TS16
#define CTSUSO1_TS17                  (CTSUICOG_TS17 << 13) | (CTSUSDPA_TS17 << 8) | CTSURICOA_TS17
#define CTSUSO1_TS18                  (CTSUICOG_TS18 << 13) | (CTSUSDPA_TS18 << 8) | CTSURICOA_TS18
#define CTSUSO1_TS19                  (CTSUICOG_TS19 << 13) | (CTSUSDPA_TS19 << 8) | CTSURICOA_TS19
#define CTSUSO1_TS20                  (CTSUICOG_TS20 << 13) | (CTSUSDPA_TS20 << 8) | CTSURICOA_TS20
#define CTSUSO1_TS21                  (CTSUICOG_TS21 << 13) | (CTSUSDPA_TS21 << 8) | CTSURICOA_TS21
#define CTSUSO1_TS22                  (CTSUICOG_TS22 << 13) | (CTSUSDPA_TS22 << 8) | CTSURICOA_TS22
#define CTSUSO1_TS23                  (CTSUICOG_TS23 << 13) | (CTSUSDPA_TS23 << 8) | CTSURICOA_TS23
#define CTSUSO1_TS24                  (CTSUICOG_TS24 << 13) | (CTSUSDPA_TS24 << 8) | CTSURICOA_TS24
#define CTSUSO1_TS25                  (CTSUICOG_TS25 << 13) | (CTSUSDPA_TS25 << 8) | CTSURICOA_TS25
#define CTSUSO1_TS26                  (CTSUICOG_TS26 << 13) | (CTSUSDPA_TS26 << 8) | CTSURICOA_TS26
#define CTSUSO1_TS27                  (CTSUICOG_TS27 << 13) | (CTSUSDPA_TS27 << 8) | CTSURICOA_TS27
#define CTSUSO1_TS28                  (CTSUICOG_TS28 << 13) | (CTSUSDPA_TS28 << 8) | CTSURICOA_TS28
#define CTSUSO1_TS29                  (CTSUICOG_TS29 << 13) | (CTSUSDPA_TS29 << 8) | CTSURICOA_TS29
#define CTSUSO1_TS30                  (CTSUICOG_TS30 << 13) | (CTSUSDPA_TS30 << 8) | CTSURICOA_TS30
#define CTSUSO1_TS31                  (CTSUICOG_TS31 << 13) | (CTSUSDPA_TS31 << 8) | CTSURICOA_TS31
#define CTSUSO1_TS32                  (CTSUICOG_TS32 << 13) | (CTSUSDPA_TS32 << 8) | CTSURICOA_TS32
#define CTSUSO1_TS33                  (CTSUICOG_TS33 << 13) | (CTSUSDPA_TS33 << 8) | CTSURICOA_TS33
#define CTSUSO1_TS34                  (CTSUICOG_TS34 << 13) | (CTSUSDPA_TS34 << 8) | CTSURICOA_TS34
#define CTSUSO1_TS35                  (CTSUICOG_TS35 << 13) | (CTSUSDPA_TS35 << 8) | CTSURICOA_TS35
#endif    // ( SELF_METHOD_NUM == 1 )

#if ( MUTUAL_METHOD_NUM >= 1 )
/*====================================================================================================================*/
/*=====     Mutual-measurement 0 TS enable definition    =============================================================*/
/*====================================================================================================================*/
#define MUTUAL0_ENABLE_TS00              (1)        /* Mutual 0 TS00 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS01              (1)        /* Mutual 0 TS01 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS02              (0)        /* Mutual 0 TS02 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS03              (0)        /* Mutual 0 TS03 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS04              (1)        /* Mutual 0 TS04 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS05              (1)        /* Mutual 0 TS05 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS06              (0)        /* Mutual 0 TS06 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS07              (0)        /* Mutual 0 TS07 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS08              (0)        /* Mutual 0 TS08 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS09              (0)        /* Mutual 0 TS09 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS10              (0)        /* Mutual 0 TS10 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS11              (0)        /* Mutual 0 TS11 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS12              (0)        /* Mutual 0 TS12 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS13              (0)        /* Mutual 0 TS13 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS14              (0)        /* Mutual 0 TS14 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS15              (0)        /* Mutual 0 TS15 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS16              (0)        /* Mutual 0 TS16 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS17              (0)        /* Mutual 0 TS17 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS18              (1)        /* Mutual 0 TS18 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS19              (1)        /* Mutual 0 TS19 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS20              (1)        /* Mutual 0 TS20 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS21              (1)        /* Mutual 0 TS21 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS22              (0)        /* Mutual 0 TS22 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS23              (0)        /* Mutual 0 TS23 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS24              (0)        /* Mutual 0 TS24 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS25              (0)        /* Mutual 0 TS25 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS26              (1)        /* Mutual 0 TS26 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS27              (0)        /* Mutual 0 TS27 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS28              (0)        /* Mutual 0 TS28 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS29              (0)        /* Mutual 0 TS29 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS30              (0)        /* Mutual 0 TS30 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS31              (0)        /* Mutual 0 TS31 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS32              (0)        /* Mutual 0 TS32 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS33              (0)        /* Mutual 0 TS33 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS34              (0)        /* Mutual 0 TS34 0:disable 1:enable                               */
#define MUTUAL0_ENABLE_TS35              (0)        /* Mutual 0 TS35 0:disable 1:enable                               */

/*****    Address 000A 0906h CTSU Channel enable control register 0    ************************************************/
#define CTSUCHAC0_MUTUAL0_ENABLE_TS       ((MUTUAL0_ENABLE_TS00 << 0) | (MUTUAL0_ENABLE_TS01 << 1) | \
                                           (MUTUAL0_ENABLE_TS02 << 2) | (MUTUAL0_ENABLE_TS03 << 3) | \
                                           (MUTUAL0_ENABLE_TS04 << 4) | (MUTUAL0_ENABLE_TS05 << 5) | \
                                           (MUTUAL0_ENABLE_TS06 << 6) | (MUTUAL0_ENABLE_TS07 << 7))

/*****    Address 000A 0907h CTSU Channel enable control register 1    ************************************************/
#define CTSUCHAC1_MUTUAL0_ENABLE_TS       ((MUTUAL0_ENABLE_TS08 << 0) | (MUTUAL0_ENABLE_TS09 << 1) | \
                                           (MUTUAL0_ENABLE_TS10 << 2) | (MUTUAL0_ENABLE_TS11 << 3) | \
                                           (MUTUAL0_ENABLE_TS12 << 4) | (MUTUAL0_ENABLE_TS13 << 5) | \
                                           (MUTUAL0_ENABLE_TS14 << 6) | (MUTUAL0_ENABLE_TS15 << 7))

/*****    Address 000A 0908h CTSU Channel enable control register 2    ************************************************/
#define CTSUCHAC2_MUTUAL0_ENABLE_TS       ((MUTUAL0_ENABLE_TS16 << 0) | (MUTUAL0_ENABLE_TS17 << 1) | \
                                           (MUTUAL0_ENABLE_TS18 << 2) | (MUTUAL0_ENABLE_TS19 << 3) | \
                                           (MUTUAL0_ENABLE_TS20 << 4) | (MUTUAL0_ENABLE_TS21 << 5) | \
                                           (MUTUAL0_ENABLE_TS22 << 6) | (MUTUAL0_ENABLE_TS23 << 7))

/*****    Address 000A 0909h CTSU Channel enable control register 3    ************************************************/
#define CTSUCHAC3_MUTUAL0_ENABLE_TS       ((MUTUAL0_ENABLE_TS24 << 0) | (MUTUAL0_ENABLE_TS25 << 1) | \
                                           (MUTUAL0_ENABLE_TS26 << 2) | (MUTUAL0_ENABLE_TS27 << 3) | \
                                           (MUTUAL0_ENABLE_TS28 << 4) | (MUTUAL0_ENABLE_TS29 << 5) | \
                                           (MUTUAL0_ENABLE_TS30 << 6) | (MUTUAL0_ENABLE_TS31 << 7))

/*****    Address 000A 090ah CTSU Channel enable control register 4    ************************************************/
#define CTSUCHAC4_MUTUAL0_ENABLE_TS       ((MUTUAL0_ENABLE_TS32 << 0) | (MUTUAL0_ENABLE_TS33 << 1) | \
                                           (MUTUAL0_ENABLE_TS34 << 2) | (MUTUAL0_ENABLE_TS35 << 3))

/* SUM of Channels */ /* Do not edit this macro definition */
#define MUTUAL0_ENABLE_NUM               (MUTUAL0_ENABLE_TS00 + MUTUAL0_ENABLE_TS01 + MUTUAL0_ENABLE_TS02 + \
                                          MUTUAL0_ENABLE_TS03 + MUTUAL0_ENABLE_TS04 + MUTUAL0_ENABLE_TS05 + \
                                          MUTUAL0_ENABLE_TS06 + MUTUAL0_ENABLE_TS07 + MUTUAL0_ENABLE_TS08 + \
                                          MUTUAL0_ENABLE_TS09 + MUTUAL0_ENABLE_TS10 + MUTUAL0_ENABLE_TS11 + \
                                          MUTUAL0_ENABLE_TS12 + MUTUAL0_ENABLE_TS13 + MUTUAL0_ENABLE_TS14 + \
                                          MUTUAL0_ENABLE_TS15 + MUTUAL0_ENABLE_TS16 + MUTUAL0_ENABLE_TS17 + \
                                          MUTUAL0_ENABLE_TS18 + MUTUAL0_ENABLE_TS19 + MUTUAL0_ENABLE_TS20 + \
                                          MUTUAL0_ENABLE_TS21 + MUTUAL0_ENABLE_TS22 + MUTUAL0_ENABLE_TS23 + \
                                          MUTUAL0_ENABLE_TS24 + MUTUAL0_ENABLE_TS25 + MUTUAL0_ENABLE_TS26 + \
                                          MUTUAL0_ENABLE_TS27 + MUTUAL0_ENABLE_TS28 + MUTUAL0_ENABLE_TS29 + \
                                          MUTUAL0_ENABLE_TS30 + MUTUAL0_ENABLE_TS31 + MUTUAL0_ENABLE_TS32 + \
                                          MUTUAL0_ENABLE_TS33 + MUTUAL0_ENABLE_TS34 + MUTUAL0_ENABLE_TS35)

/*====================================================================================================================*/
/*=====     Mutual-measurement 0 function definition     =============================================================*/
/*====================================================================================================================*/
#define MUTUAL0_FUNCTION_TS00            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS01            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS02            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS03            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS04            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS05            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS06            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS07            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS08            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS09            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS10            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS11            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS12            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS13            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS14            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS15            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS16            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS17            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS18            (TRANSMISSION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS19            (TRANSMISSION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS20            (TRANSMISSION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS21            (TRANSMISSION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS22            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS23            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS24            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS25            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS26            (TRANSMISSION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS27            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS28            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS29            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS30            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS31            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS32            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS33            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS34            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL0_FUNCTION_TS35            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */

/*****    Address 000A 090Bh CTSU Channel send and receive control register 0 *****************************************/
#define CTSUCHTRC0_MUTUAL0_TRANSMIT_TS   ((MUTUAL0_FUNCTION_TS00 << 0) | (MUTUAL0_FUNCTION_TS01 << 1) | \
                                          (MUTUAL0_FUNCTION_TS02 << 2) | (MUTUAL0_FUNCTION_TS03 << 3) | \
                                          (MUTUAL0_FUNCTION_TS04 << 4) | (MUTUAL0_FUNCTION_TS05 << 5) | \
                                          (MUTUAL0_FUNCTION_TS06 << 6) | (MUTUAL0_FUNCTION_TS07 << 7))

/*****    Address 000A 090Ch CTSU Channel send and receive control register 1 *****************************************/
#define CTSUCHTRC1_MUTUAL0_TRANSMIT_TS   ((MUTUAL0_FUNCTION_TS08 << 0) | (MUTUAL0_FUNCTION_TS09 << 1) | \
                                          (MUTUAL0_FUNCTION_TS10 << 2) | (MUTUAL0_FUNCTION_TS11 << 3) | \
                                          (MUTUAL0_FUNCTION_TS12 << 4) | (MUTUAL0_FUNCTION_TS13 << 5) | \
                                          (MUTUAL0_FUNCTION_TS14 << 6) | (MUTUAL0_FUNCTION_TS15 << 7))

/*****    Address 000A 090Dh CTSU Channel send and receive control register 2 *****************************************/
#define CTSUCHTRC2_MUTUAL0_TRANSMIT_TS   ((MUTUAL0_FUNCTION_TS16 << 0) | (MUTUAL0_FUNCTION_TS17 << 1) | \
                                          (MUTUAL0_FUNCTION_TS18 << 2) | (MUTUAL0_FUNCTION_TS19 << 3) | \
                                          (MUTUAL0_FUNCTION_TS20 << 4) | (MUTUAL0_FUNCTION_TS21 << 5) | \
                                          (MUTUAL0_FUNCTION_TS22 << 6) | (MUTUAL0_FUNCTION_TS23 << 7))

/*****    Address 000A 090Eh CTSU Channel send and receive control register 3 *****************************************/
#define CTSUCHTRC3_MUTUAL0_TRANSMIT_TS   ((MUTUAL0_FUNCTION_TS24 << 0) | (MUTUAL0_FUNCTION_TS25 << 1) | \
                                          (MUTUAL0_FUNCTION_TS26 << 2) | (MUTUAL0_FUNCTION_TS27 << 3) | \
                                          (MUTUAL0_FUNCTION_TS28 << 4) | (MUTUAL0_FUNCTION_TS29 << 5) | \
                                          (MUTUAL0_FUNCTION_TS30 << 6) | (MUTUAL0_FUNCTION_TS31 << 7))

/*****    Address 000A 090Fh CTSU Channel send and receive control register 4 *****************************************/
#define CTSUCHTRC4_MUTUAL0_TRANSMIT_TS   ((MUTUAL0_FUNCTION_TS32 << 0) | (MUTUAL0_FUNCTION_TS33 << 1) | \
                                          (MUTUAL0_FUNCTION_TS34 << 2) | (MUTUAL0_FUNCTION_TS35 << 3))

#define TRANSMISSION0_NUM                  (MUTUAL0_FUNCTION_TS00 + MUTUAL0_FUNCTION_TS01 + MUTUAL0_FUNCTION_TS02 + \
                                            MUTUAL0_FUNCTION_TS03 + MUTUAL0_FUNCTION_TS04 + MUTUAL0_FUNCTION_TS05 + \
                                            MUTUAL0_FUNCTION_TS06 + MUTUAL0_FUNCTION_TS07 + MUTUAL0_FUNCTION_TS08 + \
                                            MUTUAL0_FUNCTION_TS09 + MUTUAL0_FUNCTION_TS10 + MUTUAL0_FUNCTION_TS11 + \
                                            MUTUAL0_FUNCTION_TS12 + MUTUAL0_FUNCTION_TS13 + MUTUAL0_FUNCTION_TS14 + \
                                            MUTUAL0_FUNCTION_TS15 + MUTUAL0_FUNCTION_TS16 + MUTUAL0_FUNCTION_TS17 + \
                                            MUTUAL0_FUNCTION_TS18 + MUTUAL0_FUNCTION_TS19 + MUTUAL0_FUNCTION_TS20 + \
                                            MUTUAL0_FUNCTION_TS21 + MUTUAL0_FUNCTION_TS22 + MUTUAL0_FUNCTION_TS23 + \
                                            MUTUAL0_FUNCTION_TS24 + MUTUAL0_FUNCTION_TS25 + MUTUAL0_FUNCTION_TS26 + \
                                            MUTUAL0_FUNCTION_TS27 + MUTUAL0_FUNCTION_TS28 + MUTUAL0_FUNCTION_TS29 + \
                                            MUTUAL0_FUNCTION_TS30 + MUTUAL0_FUNCTION_TS31 + MUTUAL0_FUNCTION_TS32 + \
                                            MUTUAL0_FUNCTION_TS33 + MUTUAL0_FUNCTION_TS34 + MUTUAL0_FUNCTION_TS35)

#define RECEPTION0_NUM                     (MUTUAL0_ENABLE_NUM - TRANSMISSION0_NUM)
#define MUTUAL0_NUM                        (TRANSMISSION0_NUM * RECEPTION0_NUM)

#if TRANSMISSION0_NUM == 0
    #error "Send TS Setting error ( TRANSMISSION0_NUM = 0 )"
#endif
#if RECEPTION0_NUM == 0
    #error "Receive TS Setting error ( RECEPTION_NUM0 = 0 )"
#endif

/*****    Address 000A 0912h CTSU High-Pass Noise Reduction Spectrum Diffusion Control Register    ********************/
/**********************************************************************************************************************/
/*    CTSU Spectrum Diffusion Frequency Division Setting                                                              */
/*    Base Clock Frequency fb (MHz)   CTSUSSDIV[3:0] Bit Setting                                                      */
/*          4.00 =< fb                           0x00                                                                 */
/*          2.00 =< fb  < 4.00                   0x01                                                                 */
/*          1.33 =< fb  < 2.00                   0x02                                                                 */
/*          1.00 =< fb  < 1.33                   0x03                                                                 */
/*          0.80 =< fb  < 1.00                   0x04                                                                 */
/*          0.67 =< fb  < 0.80                   0x05                                                                 */
/*          0.57 =< fb  < 0.67                   0x06                                                                 */
/*          0.50 =< fb  < 0.57                   0x07                                                                 */
/*          0.44 =< fb  < 0.50                   0x08                                                                 */
/*          0.40 =< fb  < 0.44                   0x09                                                                 */
/*          0.36 =< fb  < 0.40                   0x0A                                                                 */
/*          0.33 =< fb  < 0.36                   0x0B                                                                 */
/*          0.31 =< fb  < 0.33                   0x0C                                                                 */
/*          0.29 =< fb  < 0.31                   0x0D                                                                 */
/*          0.27 =< fb  < 0.29                   0x0E                                                                 */
/*                  fb =< 0.25                   0x0F                                                                 */
/**********************************************************************************************************************/
#define CTSUSSDIV_MUTUAL0_KEY00         (0x00)                 /* Mutual 0 Key00 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY01         (0x00)                 /* Mutual 0 Key01 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY02         (0x00)                 /* Mutual 0 Key02 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY03         (0x00)                 /* Mutual 0 Key03 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY04         (0x00)                 /* Mutual 0 Key04 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY05         (0x00)                 /* Mutual 0 Key05 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY06         (0x00)                 /* Mutual 0 Key06 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY07         (0x00)                 /* Mutual 0 Key07 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY08         (0x00)                 /* Mutual 0 Key08 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY09         (0x00)                 /* Mutual 0 Key09 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY10         (0x00)                 /* Mutual 0 Key10 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY11         (0x00)                 /* Mutual 0 Key11 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY12         (0x00)                 /* Mutual 0 Key12 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY13         (0x00)                 /* Mutual 0 Key13 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY14         (0x00)                 /* Mutual 0 Key14 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY15         (0x00)                 /* Mutual 0 Key15 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY16         (0x00)                 /* Mutual 0 Key16 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY17         (0x00)                 /* Mutual 0 Key17 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY18         (0x00)                 /* Mutual 0 Key18 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY19         (0x00)                 /* Mutual 0 Key19 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY20         (0x01)                 /* Mutual 0 Key20 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY21         (0x01)                 /* Mutual 0 Key21 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY22         (0x01)                 /* Mutual 0 Key22 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY23         (0x01)                 /* Mutual 0 Key23 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY24         (0x01)                 /* Mutual 0 Key24 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY25         (0x01)                 /* Mutual 0 Key25 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY26         (0x01)                 /* Mutual 0 Key26 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY27         (0x01)                 /* Mutual 0 Key27 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY28         (0x01)                 /* Mutual 0 Key28 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY29         (0x01)                 /* Mutual 0 Key29 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY30         (0x01)                 /* Mutual 0 Key30 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY31         (0x01)                 /* Mutual 0 Key31 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY32         (0x01)                 /* Mutual 0 Key32 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY33         (0x01)                 /* Mutual 0 Key33 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY34         (0x01)                 /* Mutual 0 Key34 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY35         (0x01)                 /* Mutual 0 Key35 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY36         (0x01)                 /* Mutual 0 Key36 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY37         (0x01)                 /* Mutual 0 Key37 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY38         (0x01)                 /* Mutual 0 Key38 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY39         (0x01)                 /* Mutual 0 Key39 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY40         (0x01)                 /* Mutual 0 Key40 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY41         (0x01)                 /* Mutual 0 Key41 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY42         (0x01)                 /* Mutual 0 Key42 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY43         (0x01)                 /* Mutual 0 Key43 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY44         (0x01)                 /* Mutual 0 Key44 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY45         (0x01)                 /* Mutual 0 Key45 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY46         (0x01)                 /* Mutual 0 Key46 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY47         (0x01)                 /* Mutual 0 Key47 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY48         (0x01)                 /* Mutual 0 Key48 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY49         (0x01)                 /* Mutual 0 Key49 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY50         (0x01)                 /* Mutual 0 Key50 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY51         (0x01)                 /* Mutual 0 Key51 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY52         (0x01)                 /* Mutual 0 Key52 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY53         (0x01)                 /* Mutual 0 Key53 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY54         (0x01)                 /* Mutual 0 Key54 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY55         (0x01)                 /* Mutual 0 Key55 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY56         (0x01)                 /* Mutual 0 Key56 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY57         (0x01)                 /* Mutual 0 Key57 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY58         (0x01)                 /* Mutual 0 Key58 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY59         (0x01)                 /* Mutual 0 Key59 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY60         (0x01)                 /* Mutual 0 Key60 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY61         (0x01)                 /* Mutual 0 Key61 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY62         (0x01)                 /* Mutual 0 Key62 CTSUSSDIV                            */
#define CTSUSSDIV_MUTUAL0_KEY63         (0x01)                 /* Mutual 0 Key63 CTSUSSDIV                            */

#define CTSUSSC_MUTUAL0_KEY00           (CTSUSSDIV_MUTUAL0_KEY00 << 8)
#define CTSUSSC_MUTUAL0_KEY01           (CTSUSSDIV_MUTUAL0_KEY01 << 8)
#define CTSUSSC_MUTUAL0_KEY02           (CTSUSSDIV_MUTUAL0_KEY02 << 8)
#define CTSUSSC_MUTUAL0_KEY03           (CTSUSSDIV_MUTUAL0_KEY03 << 8)
#define CTSUSSC_MUTUAL0_KEY04           (CTSUSSDIV_MUTUAL0_KEY04 << 8)
#define CTSUSSC_MUTUAL0_KEY05           (CTSUSSDIV_MUTUAL0_KEY05 << 8)
#define CTSUSSC_MUTUAL0_KEY06           (CTSUSSDIV_MUTUAL0_KEY06 << 8)
#define CTSUSSC_MUTUAL0_KEY07           (CTSUSSDIV_MUTUAL0_KEY07 << 8)
#define CTSUSSC_MUTUAL0_KEY08           (CTSUSSDIV_MUTUAL0_KEY08 << 8)
#define CTSUSSC_MUTUAL0_KEY09           (CTSUSSDIV_MUTUAL0_KEY09 << 8)
#define CTSUSSC_MUTUAL0_KEY10           (CTSUSSDIV_MUTUAL0_KEY10 << 8)
#define CTSUSSC_MUTUAL0_KEY11           (CTSUSSDIV_MUTUAL0_KEY11 << 8)
#define CTSUSSC_MUTUAL0_KEY12           (CTSUSSDIV_MUTUAL0_KEY12 << 8)
#define CTSUSSC_MUTUAL0_KEY13           (CTSUSSDIV_MUTUAL0_KEY13 << 8)
#define CTSUSSC_MUTUAL0_KEY14           (CTSUSSDIV_MUTUAL0_KEY14 << 8)
#define CTSUSSC_MUTUAL0_KEY15           (CTSUSSDIV_MUTUAL0_KEY15 << 8)
#define CTSUSSC_MUTUAL0_KEY16           (CTSUSSDIV_MUTUAL0_KEY16 << 8)
#define CTSUSSC_MUTUAL0_KEY17           (CTSUSSDIV_MUTUAL0_KEY17 << 8)
#define CTSUSSC_MUTUAL0_KEY18           (CTSUSSDIV_MUTUAL0_KEY18 << 8)
#define CTSUSSC_MUTUAL0_KEY19           (CTSUSSDIV_MUTUAL0_KEY19 << 8)
#define CTSUSSC_MUTUAL0_KEY20           (CTSUSSDIV_MUTUAL0_KEY20 << 8)
#define CTSUSSC_MUTUAL0_KEY21           (CTSUSSDIV_MUTUAL0_KEY21 << 8)
#define CTSUSSC_MUTUAL0_KEY22           (CTSUSSDIV_MUTUAL0_KEY22 << 8)
#define CTSUSSC_MUTUAL0_KEY23           (CTSUSSDIV_MUTUAL0_KEY23 << 8)
#define CTSUSSC_MUTUAL0_KEY24           (CTSUSSDIV_MUTUAL0_KEY24 << 8)
#define CTSUSSC_MUTUAL0_KEY25           (CTSUSSDIV_MUTUAL0_KEY25 << 8)
#define CTSUSSC_MUTUAL0_KEY26           (CTSUSSDIV_MUTUAL0_KEY26 << 8)
#define CTSUSSC_MUTUAL0_KEY27           (CTSUSSDIV_MUTUAL0_KEY27 << 8)
#define CTSUSSC_MUTUAL0_KEY28           (CTSUSSDIV_MUTUAL0_KEY28 << 8)
#define CTSUSSC_MUTUAL0_KEY29           (CTSUSSDIV_MUTUAL0_KEY29 << 8)
#define CTSUSSC_MUTUAL0_KEY30           (CTSUSSDIV_MUTUAL0_KEY30 << 8)
#define CTSUSSC_MUTUAL0_KEY31           (CTSUSSDIV_MUTUAL0_KEY31 << 8)
#define CTSUSSC_MUTUAL0_KEY32           (CTSUSSDIV_MUTUAL0_KEY32 << 8)
#define CTSUSSC_MUTUAL0_KEY33           (CTSUSSDIV_MUTUAL0_KEY33 << 8)
#define CTSUSSC_MUTUAL0_KEY34           (CTSUSSDIV_MUTUAL0_KEY34 << 8)
#define CTSUSSC_MUTUAL0_KEY35           (CTSUSSDIV_MUTUAL0_KEY35 << 8)
#define CTSUSSC_MUTUAL0_KEY36           (CTSUSSDIV_MUTUAL0_KEY36 << 8)
#define CTSUSSC_MUTUAL0_KEY37           (CTSUSSDIV_MUTUAL0_KEY37 << 8)
#define CTSUSSC_MUTUAL0_KEY38           (CTSUSSDIV_MUTUAL0_KEY38 << 8)
#define CTSUSSC_MUTUAL0_KEY39           (CTSUSSDIV_MUTUAL0_KEY39 << 8)
#define CTSUSSC_MUTUAL0_KEY40           (CTSUSSDIV_MUTUAL0_KEY40 << 8)
#define CTSUSSC_MUTUAL0_KEY41           (CTSUSSDIV_MUTUAL0_KEY41 << 8)
#define CTSUSSC_MUTUAL0_KEY42           (CTSUSSDIV_MUTUAL0_KEY42 << 8)
#define CTSUSSC_MUTUAL0_KEY43           (CTSUSSDIV_MUTUAL0_KEY43 << 8)
#define CTSUSSC_MUTUAL0_KEY44           (CTSUSSDIV_MUTUAL0_KEY44 << 8)
#define CTSUSSC_MUTUAL0_KEY45           (CTSUSSDIV_MUTUAL0_KEY45 << 8)
#define CTSUSSC_MUTUAL0_KEY46           (CTSUSSDIV_MUTUAL0_KEY46 << 8)
#define CTSUSSC_MUTUAL0_KEY47           (CTSUSSDIV_MUTUAL0_KEY47 << 8)
#define CTSUSSC_MUTUAL0_KEY48           (CTSUSSDIV_MUTUAL0_KEY48 << 8)
#define CTSUSSC_MUTUAL0_KEY49           (CTSUSSDIV_MUTUAL0_KEY49 << 8)
#define CTSUSSC_MUTUAL0_KEY50           (CTSUSSDIV_MUTUAL0_KEY50 << 8)
#define CTSUSSC_MUTUAL0_KEY51           (CTSUSSDIV_MUTUAL0_KEY51 << 8)
#define CTSUSSC_MUTUAL0_KEY52           (CTSUSSDIV_MUTUAL0_KEY52 << 8)
#define CTSUSSC_MUTUAL0_KEY53           (CTSUSSDIV_MUTUAL0_KEY53 << 8)
#define CTSUSSC_MUTUAL0_KEY54           (CTSUSSDIV_MUTUAL0_KEY54 << 8)
#define CTSUSSC_MUTUAL0_KEY55           (CTSUSSDIV_MUTUAL0_KEY55 << 8)
#define CTSUSSC_MUTUAL0_KEY56           (CTSUSSDIV_MUTUAL0_KEY56 << 8)
#define CTSUSSC_MUTUAL0_KEY57           (CTSUSSDIV_MUTUAL0_KEY57 << 8)
#define CTSUSSC_MUTUAL0_KEY58           (CTSUSSDIV_MUTUAL0_KEY58 << 8)
#define CTSUSSC_MUTUAL0_KEY59           (CTSUSSDIV_MUTUAL0_KEY59 << 8)
#define CTSUSSC_MUTUAL0_KEY60           (CTSUSSDIV_MUTUAL0_KEY60 << 8)
#define CTSUSSC_MUTUAL0_KEY61           (CTSUSSDIV_MUTUAL0_KEY61 << 8)
#define CTSUSSC_MUTUAL0_KEY62           (CTSUSSDIV_MUTUAL0_KEY62 << 8)
#define CTSUSSC_MUTUAL0_KEY63           (CTSUSSDIV_MUTUAL0_KEY63 << 8)

/*****    Address 000A 0914h CTSU Sensor Offset Register 0     ********************************************************/
/**********************************************************************************************************************/
/*    CTSU Sensor Offset Adjustment                                                                                   */
/*      Current offset amount is 0       0x000                                                                        */
/*      Current offset amount is 1       0x001                                                                        */
/*      Current offset amount is 2       0x002                                                                        */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*      Current offset amount is 1023    0x3FF                                                                        */
/**********************************************************************************************************************/
#define CTSUSO_MUTUAL0_KEY00            (0x260)                 /* Mutual 0 Key00 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY01            (0x271)                 /* Mutual 0 Key01 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY02            (0x25C)                 /* Mutual 0 Key02 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY03            (0x25E)                 /* Mutual 0 Key03 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY04            (0x254)                 /* Mutual 0 Key04 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY05            (0x27F)                 /* Mutual 0 Key05 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY06            (0x28D)                 /* Mutual 0 Key06 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY07            (0x27D)                 /* Mutual 0 Key07 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY08            (0x27E)                 /* Mutual 0 Key08 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY09            (0x273)                 /* Mutual 0 Key09 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY10            (0x239)                 /* Mutual 0 Key10 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY11            (0x243)                 /* Mutual 0 Key11 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY12            (0x236)                 /* Mutual 0 Key12 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY13            (0x235)                 /* Mutual 0 Key13 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY14            (0x230)                 /* Mutual 0 Key14 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY15            (0x1D6)                 /* Mutual 0 Key15 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY16            (0x1D6)                 /* Mutual 0 Key16 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY17            (0x1D3)                 /* Mutual 0 Key17 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY18            (0x1D7)                 /* Mutual 0 Key18 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY19            (0x1D6)                 /* Mutual 0 Key19 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY20            (0x000)                 /* Mutual 0 Key20 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY21            (0x000)                 /* Mutual 0 Key21 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY22            (0x000)                 /* Mutual 0 Key22 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY23            (0x000)                 /* Mutual 0 Key23 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY24            (0x000)                 /* Mutual 0 Key24 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY25            (0x000)                 /* Mutual 0 Key25 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY26            (0x000)                 /* Mutual 0 Key26 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY27            (0x000)                 /* Mutual 0 Key27 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY28            (0x000)                 /* Mutual 0 Key28 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY29            (0x000)                 /* Mutual 0 Key29 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY30            (0x000)                 /* Mutual 0 Key30 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY31            (0x000)                 /* Mutual 0 Key31 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY32            (0x000)                 /* Mutual 0 Key32 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY33            (0x000)                 /* Mutual 0 Key33 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY34            (0x000)                 /* Mutual 0 Key34 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY35            (0x000)                 /* Mutual 0 Key35 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY36            (0x000)                 /* Mutual 0 Key36 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY37            (0x000)                 /* Mutual 0 Key37 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY38            (0x000)                 /* Mutual 0 Key38 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY39            (0x000)                 /* Mutual 0 Key39 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY40            (0x000)                 /* Mutual 0 Key40 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY41            (0x000)                 /* Mutual 0 Key41 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY42            (0x000)                 /* Mutual 0 Key42 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY43            (0x000)                 /* Mutual 0 Key43 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY44            (0x000)                 /* Mutual 0 Key44 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY45            (0x000)                 /* Mutual 0 Key45 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY46            (0x000)                 /* Mutual 0 Key46 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY47            (0x000)                 /* Mutual 0 Key47 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY48            (0x000)                 /* Mutual 0 Key48 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY49            (0x000)                 /* Mutual 0 Key49 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY50            (0x000)                 /* Mutual 0 Key50 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY51            (0x000)                 /* Mutual 0 Key51 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY52            (0x000)                 /* Mutual 0 Key52 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY53            (0x000)                 /* Mutual 0 Key53 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY54            (0x000)                 /* Mutual 0 Key54 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY55            (0x000)                 /* Mutual 0 Key55 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY56            (0x000)                 /* Mutual 0 Key56 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY57            (0x000)                 /* Mutual 0 Key57 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY58            (0x000)                 /* Mutual 0 Key58 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY59            (0x000)                 /* Mutual 0 Key59 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY60            (0x000)                 /* Mutual 0 Key60 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY61            (0x000)                 /* Mutual 0 Key61 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY62            (0x000)                 /* Mutual 0 Key62 CTSUSO                              */
#define CTSUSO_MUTUAL0_KEY63            (0x000)                 /* Mutual 0 Key63 CTSUSO                              */

/**********************************************************************************************************************/
/*    CTSU Measurement Count Setting                                                                                  */
/*      4.0MHz    7                                                                                                   */
/*      2.0MHz    3                                                                                                   */
/*      1.0MHz    1                                                                                                   */
/*      0.5MHz    0                                                                                                   */
/**********************************************************************************************************************/
#define CTSUSNUM_MUTUAL0_KEY00          (7)                     /* Mutual 0 Key00 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY01          (7)                     /* Mutual 0 Key01 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY02          (7)                     /* Mutual 0 Key02 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY03          (7)                     /* Mutual 0 Key03 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY04          (7)                     /* Mutual 0 Key04 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY05          (7)                     /* Mutual 0 Key05 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY06          (7)                     /* Mutual 0 Key06 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY07          (7)                     /* Mutual 0 Key07 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY08          (7)                     /* Mutual 0 Key08 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY09          (7)                     /* Mutual 0 Key09 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY10          (7)                     /* Mutual 0 Key10 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY11          (7)                     /* Mutual 0 Key11 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY12          (7)                     /* Mutual 0 Key12 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY13          (7)                     /* Mutual 0 Key13 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY14          (7)                     /* Mutual 0 Key14 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY15          (7)                     /* Mutual 0 Key15 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY16          (7)                     /* Mutual 0 Key16 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY17          (7)                     /* Mutual 0 Key17 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY18          (7)                     /* Mutual 0 Key18 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY19          (7)                     /* Mutual 0 Key19 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY20          (3)                     /* Mutual 0 Key20 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY21          (3)                     /* Mutual 0 Key21 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY22          (3)                     /* Mutual 0 Key22 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY23          (3)                     /* Mutual 0 Key23 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY24          (3)                     /* Mutual 0 Key24 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY25          (3)                     /* Mutual 0 Key25 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY26          (3)                     /* Mutual 0 Key26 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY27          (3)                     /* Mutual 0 Key27 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY28          (3)                     /* Mutual 0 Key28 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY29          (3)                     /* Mutual 0 Key29 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY30          (3)                     /* Mutual 0 Key30 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY31          (3)                     /* Mutual 0 Key31 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY32          (3)                     /* Mutual 0 Key32 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY33          (3)                     /* Mutual 0 Key33 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY34          (3)                     /* Mutual 0 Key34 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY35          (3)                     /* Mutual 0 Key35 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY36          (3)                     /* Mutual 0 Key36 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY37          (3)                     /* Mutual 0 Key37 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY38          (3)                     /* Mutual 0 Key38 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY39          (3)                     /* Mutual 0 Key39 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY40          (3)                     /* Mutual 0 Key40 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY41          (3)                     /* Mutual 0 Key41 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY42          (3)                     /* Mutual 0 Key42 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY43          (3)                     /* Mutual 0 Key43 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY44          (3)                     /* Mutual 0 Key44 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY45          (3)                     /* Mutual 0 Key45 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY46          (3)                     /* Mutual 0 Key46 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY47          (3)                     /* Mutual 0 Key47 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY48          (3)                     /* Mutual 0 Key48 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY49          (3)                     /* Mutual 0 Key49 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY50          (3)                     /* Mutual 0 Key50 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY51          (3)                     /* Mutual 0 Key51 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY52          (3)                     /* Mutual 0 Key52 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY53          (3)                     /* Mutual 0 Key53 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY54          (3)                     /* Mutual 0 Key54 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY55          (3)                     /* Mutual 0 Key55 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY56          (3)                     /* Mutual 0 Key56 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY57          (3)                     /* Mutual 0 Key57 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY58          (3)                     /* Mutual 0 Key58 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY59          (3)                     /* Mutual 0 Key59 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY60          (3)                     /* Mutual 0 Key60 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY61          (3)                     /* Mutual 0 Key61 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY62          (3)                     /* Mutual 0 Key62 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL0_KEY63          (3)                     /* Mutual 0 Key63 CTSUSNUM                            */

#define CTSUSO0_MUTUAL0_KEY00           ((CTSUSNUM_MUTUAL0_KEY00 << 10) | CTSUSO_MUTUAL0_KEY00)
#define CTSUSO0_MUTUAL0_KEY01           ((CTSUSNUM_MUTUAL0_KEY01 << 10) | CTSUSO_MUTUAL0_KEY01)
#define CTSUSO0_MUTUAL0_KEY02           ((CTSUSNUM_MUTUAL0_KEY02 << 10) | CTSUSO_MUTUAL0_KEY02)
#define CTSUSO0_MUTUAL0_KEY03           ((CTSUSNUM_MUTUAL0_KEY03 << 10) | CTSUSO_MUTUAL0_KEY03)
#define CTSUSO0_MUTUAL0_KEY04           ((CTSUSNUM_MUTUAL0_KEY04 << 10) | CTSUSO_MUTUAL0_KEY04)
#define CTSUSO0_MUTUAL0_KEY05           ((CTSUSNUM_MUTUAL0_KEY05 << 10) | CTSUSO_MUTUAL0_KEY05)
#define CTSUSO0_MUTUAL0_KEY06           ((CTSUSNUM_MUTUAL0_KEY06 << 10) | CTSUSO_MUTUAL0_KEY06)
#define CTSUSO0_MUTUAL0_KEY07           ((CTSUSNUM_MUTUAL0_KEY07 << 10) | CTSUSO_MUTUAL0_KEY07)
#define CTSUSO0_MUTUAL0_KEY08           ((CTSUSNUM_MUTUAL0_KEY08 << 10) | CTSUSO_MUTUAL0_KEY08)
#define CTSUSO0_MUTUAL0_KEY09           ((CTSUSNUM_MUTUAL0_KEY09 << 10) | CTSUSO_MUTUAL0_KEY09)
#define CTSUSO0_MUTUAL0_KEY10           ((CTSUSNUM_MUTUAL0_KEY10 << 10) | CTSUSO_MUTUAL0_KEY10)
#define CTSUSO0_MUTUAL0_KEY11           ((CTSUSNUM_MUTUAL0_KEY11 << 10) | CTSUSO_MUTUAL0_KEY11)
#define CTSUSO0_MUTUAL0_KEY12           ((CTSUSNUM_MUTUAL0_KEY12 << 10) | CTSUSO_MUTUAL0_KEY12)
#define CTSUSO0_MUTUAL0_KEY13           ((CTSUSNUM_MUTUAL0_KEY13 << 10) | CTSUSO_MUTUAL0_KEY13)
#define CTSUSO0_MUTUAL0_KEY14           ((CTSUSNUM_MUTUAL0_KEY14 << 10) | CTSUSO_MUTUAL0_KEY14)
#define CTSUSO0_MUTUAL0_KEY15           ((CTSUSNUM_MUTUAL0_KEY15 << 10) | CTSUSO_MUTUAL0_KEY15)
#define CTSUSO0_MUTUAL0_KEY16           ((CTSUSNUM_MUTUAL0_KEY16 << 10) | CTSUSO_MUTUAL0_KEY16)
#define CTSUSO0_MUTUAL0_KEY17           ((CTSUSNUM_MUTUAL0_KEY17 << 10) | CTSUSO_MUTUAL0_KEY17)
#define CTSUSO0_MUTUAL0_KEY18           ((CTSUSNUM_MUTUAL0_KEY18 << 10) | CTSUSO_MUTUAL0_KEY18)
#define CTSUSO0_MUTUAL0_KEY19           ((CTSUSNUM_MUTUAL0_KEY19 << 10) | CTSUSO_MUTUAL0_KEY19)
#define CTSUSO0_MUTUAL0_KEY20           ((CTSUSNUM_MUTUAL0_KEY20 << 10) | CTSUSO_MUTUAL0_KEY20)
#define CTSUSO0_MUTUAL0_KEY21           ((CTSUSNUM_MUTUAL0_KEY21 << 10) | CTSUSO_MUTUAL0_KEY21)
#define CTSUSO0_MUTUAL0_KEY22           ((CTSUSNUM_MUTUAL0_KEY22 << 10) | CTSUSO_MUTUAL0_KEY22)
#define CTSUSO0_MUTUAL0_KEY23           ((CTSUSNUM_MUTUAL0_KEY23 << 10) | CTSUSO_MUTUAL0_KEY23)
#define CTSUSO0_MUTUAL0_KEY24           ((CTSUSNUM_MUTUAL0_KEY24 << 10) | CTSUSO_MUTUAL0_KEY24)
#define CTSUSO0_MUTUAL0_KEY25           ((CTSUSNUM_MUTUAL0_KEY25 << 10) | CTSUSO_MUTUAL0_KEY25)
#define CTSUSO0_MUTUAL0_KEY26           ((CTSUSNUM_MUTUAL0_KEY26 << 10) | CTSUSO_MUTUAL0_KEY26)
#define CTSUSO0_MUTUAL0_KEY27           ((CTSUSNUM_MUTUAL0_KEY27 << 10) | CTSUSO_MUTUAL0_KEY27)
#define CTSUSO0_MUTUAL0_KEY28           ((CTSUSNUM_MUTUAL0_KEY28 << 10) | CTSUSO_MUTUAL0_KEY28)
#define CTSUSO0_MUTUAL0_KEY29           ((CTSUSNUM_MUTUAL0_KEY29 << 10) | CTSUSO_MUTUAL0_KEY29)
#define CTSUSO0_MUTUAL0_KEY30           ((CTSUSNUM_MUTUAL0_KEY30 << 10) | CTSUSO_MUTUAL0_KEY30)
#define CTSUSO0_MUTUAL0_KEY31           ((CTSUSNUM_MUTUAL0_KEY31 << 10) | CTSUSO_MUTUAL0_KEY31)
#define CTSUSO0_MUTUAL0_KEY32           ((CTSUSNUM_MUTUAL0_KEY32 << 10) | CTSUSO_MUTUAL0_KEY32)
#define CTSUSO0_MUTUAL0_KEY33           ((CTSUSNUM_MUTUAL0_KEY33 << 10) | CTSUSO_MUTUAL0_KEY33)
#define CTSUSO0_MUTUAL0_KEY34           ((CTSUSNUM_MUTUAL0_KEY34 << 10) | CTSUSO_MUTUAL0_KEY34)
#define CTSUSO0_MUTUAL0_KEY35           ((CTSUSNUM_MUTUAL0_KEY35 << 10) | CTSUSO_MUTUAL0_KEY35)
#define CTSUSO0_MUTUAL0_KEY36           ((CTSUSNUM_MUTUAL0_KEY36 << 10) | CTSUSO_MUTUAL0_KEY36)
#define CTSUSO0_MUTUAL0_KEY37           ((CTSUSNUM_MUTUAL0_KEY37 << 10) | CTSUSO_MUTUAL0_KEY37)
#define CTSUSO0_MUTUAL0_KEY38           ((CTSUSNUM_MUTUAL0_KEY38 << 10) | CTSUSO_MUTUAL0_KEY38)
#define CTSUSO0_MUTUAL0_KEY39           ((CTSUSNUM_MUTUAL0_KEY39 << 10) | CTSUSO_MUTUAL0_KEY39)
#define CTSUSO0_MUTUAL0_KEY40           ((CTSUSNUM_MUTUAL0_KEY40 << 10) | CTSUSO_MUTUAL0_KEY40)
#define CTSUSO0_MUTUAL0_KEY41           ((CTSUSNUM_MUTUAL0_KEY41 << 10) | CTSUSO_MUTUAL0_KEY41)
#define CTSUSO0_MUTUAL0_KEY42           ((CTSUSNUM_MUTUAL0_KEY42 << 10) | CTSUSO_MUTUAL0_KEY42)
#define CTSUSO0_MUTUAL0_KEY43           ((CTSUSNUM_MUTUAL0_KEY43 << 10) | CTSUSO_MUTUAL0_KEY43)
#define CTSUSO0_MUTUAL0_KEY44           ((CTSUSNUM_MUTUAL0_KEY44 << 10) | CTSUSO_MUTUAL0_KEY44)
#define CTSUSO0_MUTUAL0_KEY45           ((CTSUSNUM_MUTUAL0_KEY45 << 10) | CTSUSO_MUTUAL0_KEY45)
#define CTSUSO0_MUTUAL0_KEY46           ((CTSUSNUM_MUTUAL0_KEY46 << 10) | CTSUSO_MUTUAL0_KEY46)
#define CTSUSO0_MUTUAL0_KEY47           ((CTSUSNUM_MUTUAL0_KEY47 << 10) | CTSUSO_MUTUAL0_KEY47)
#define CTSUSO0_MUTUAL0_KEY48           ((CTSUSNUM_MUTUAL0_KEY48 << 10) | CTSUSO_MUTUAL0_KEY48)
#define CTSUSO0_MUTUAL0_KEY49           ((CTSUSNUM_MUTUAL0_KEY49 << 10) | CTSUSO_MUTUAL0_KEY49)
#define CTSUSO0_MUTUAL0_KEY50           ((CTSUSNUM_MUTUAL0_KEY50 << 10) | CTSUSO_MUTUAL0_KEY50)
#define CTSUSO0_MUTUAL0_KEY51           ((CTSUSNUM_MUTUAL0_KEY51 << 10) | CTSUSO_MUTUAL0_KEY51)
#define CTSUSO0_MUTUAL0_KEY52           ((CTSUSNUM_MUTUAL0_KEY52 << 10) | CTSUSO_MUTUAL0_KEY52)
#define CTSUSO0_MUTUAL0_KEY53           ((CTSUSNUM_MUTUAL0_KEY53 << 10) | CTSUSO_MUTUAL0_KEY53)
#define CTSUSO0_MUTUAL0_KEY54           ((CTSUSNUM_MUTUAL0_KEY54 << 10) | CTSUSO_MUTUAL0_KEY54)
#define CTSUSO0_MUTUAL0_KEY55           ((CTSUSNUM_MUTUAL0_KEY55 << 10) | CTSUSO_MUTUAL0_KEY55)
#define CTSUSO0_MUTUAL0_KEY56           ((CTSUSNUM_MUTUAL0_KEY56 << 10) | CTSUSO_MUTUAL0_KEY56)
#define CTSUSO0_MUTUAL0_KEY57           ((CTSUSNUM_MUTUAL0_KEY57 << 10) | CTSUSO_MUTUAL0_KEY57)
#define CTSUSO0_MUTUAL0_KEY58           ((CTSUSNUM_MUTUAL0_KEY58 << 10) | CTSUSO_MUTUAL0_KEY58)
#define CTSUSO0_MUTUAL0_KEY59           ((CTSUSNUM_MUTUAL0_KEY59 << 10) | CTSUSO_MUTUAL0_KEY59)
#define CTSUSO0_MUTUAL0_KEY60           ((CTSUSNUM_MUTUAL0_KEY60 << 10) | CTSUSO_MUTUAL0_KEY60)
#define CTSUSO0_MUTUAL0_KEY61           ((CTSUSNUM_MUTUAL0_KEY61 << 10) | CTSUSO_MUTUAL0_KEY61)
#define CTSUSO0_MUTUAL0_KEY62           ((CTSUSNUM_MUTUAL0_KEY62 << 10) | CTSUSO_MUTUAL0_KEY62)
#define CTSUSO0_MUTUAL0_KEY63           ((CTSUSNUM_MUTUAL0_KEY63 << 10) | CTSUSO_MUTUAL0_KEY63)

/*****    Address 000A 0914h CTSU Sensor Offset Register 1    *********************************************************/
/**********************************************************************************************************************/
/*    CTSU Reference ICO Current Adjustment                                                                           */
/*        Input current amount 0      0x00                                                                            */
/*        Input current amount 1      0x01                                                                            */
/*        Input current amount 2      0x02                                                                            */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*        Input current amount 254    0xFF                                                                            */
/**********************************************************************************************************************/
#define CTSURICOA_MUTUAL0_KEY00         (0x3F)                  /* Mutual 0 Key00 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY01         (0x3F)                  /* Mutual 0 Key01 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY02         (0x3F)                  /* Mutual 0 Key02 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY03         (0x3F)                  /* Mutual 0 Key03 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY04         (0x3F)                  /* Mutual 0 Key04 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY05         (0x3F)                  /* Mutual 0 Key05 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY06         (0x3F)                  /* Mutual 0 Key06 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY07         (0x3F)                  /* Mutual 0 Key07 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY08         (0x3F)                  /* Mutual 0 Key08 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY09         (0x3F)                  /* Mutual 0 Key09 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY10         (0x3F)                  /* Mutual 0 Key10 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY11         (0x3F)                  /* Mutual 0 Key11 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY12         (0x3F)                  /* Mutual 0 Key12 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY13         (0x3F)                  /* Mutual 0 Key13 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY14         (0x3F)                  /* Mutual 0 Key14 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY15         (0x3F)                  /* Mutual 0 Key15 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY16         (0x3F)                  /* Mutual 0 Key16 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY17         (0x3F)                  /* Mutual 0 Key17 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY18         (0x3F)                  /* Mutual 0 Key18 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY19         (0x3F)                  /* Mutual 0 Key19 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY20         (0x3F)                  /* Mutual 0 Key20 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY21         (0x3F)                  /* Mutual 0 Key21 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY22         (0x3F)                  /* Mutual 0 Key22 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY23         (0x3F)                  /* Mutual 0 Key23 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY24         (0x3F)                  /* Mutual 0 Key24 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY25         (0x3F)                  /* Mutual 0 Key25 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY26         (0x3F)                  /* Mutual 0 Key26 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY27         (0x3F)                  /* Mutual 0 Key27 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY28         (0x3F)                  /* Mutual 0 Key28 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY29         (0x3F)                  /* Mutual 0 Key29 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY30         (0x3F)                  /* Mutual 0 Key30 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY31         (0x3F)                  /* Mutual 0 Key31 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY32         (0x3F)                  /* Mutual 0 Key32 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY33         (0x3F)                  /* Mutual 0 Key33 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY34         (0x3F)                  /* Mutual 0 Key34 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY35         (0x3F)                  /* Mutual 0 Key35 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY36         (0x3F)                  /* Mutual 0 Key36 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY37         (0x3F)                  /* Mutual 0 Key37 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY38         (0x3F)                  /* Mutual 0 Key38 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY39         (0x3F)                  /* Mutual 0 Key39 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY40         (0x3F)                  /* Mutual 0 Key40 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY41         (0x3F)                  /* Mutual 0 Key41 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY42         (0x3F)                  /* Mutual 0 Key42 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY43         (0x3F)                  /* Mutual 0 Key43 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY44         (0x3F)                  /* Mutual 0 Key44 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY45         (0x3F)                  /* Mutual 0 Key45 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY46         (0x3F)                  /* Mutual 0 Key46 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY47         (0x3F)                  /* Mutual 0 Key47 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY48         (0x3F)                  /* Mutual 0 Key48 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY49         (0x3F)                  /* Mutual 0 Key49 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY50         (0x3F)                  /* Mutual 0 Key50 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY51         (0x3F)                  /* Mutual 0 Key51 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY52         (0x3F)                  /* Mutual 0 Key52 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY53         (0x3F)                  /* Mutual 0 Key53 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY54         (0x3F)                  /* Mutual 0 Key54 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY55         (0x3F)                  /* Mutual 0 Key55 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY56         (0x3F)                  /* Mutual 0 Key56 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY57         (0x3F)                  /* Mutual 0 Key57 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY58         (0x3F)                  /* Mutual 0 Key58 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY59         (0x3F)                  /* Mutual 0 Key59 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY60         (0x3F)                  /* Mutual 0 Key60 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY61         (0x3F)                  /* Mutual 0 Key61 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY62         (0x3F)                  /* Mutual 0 Key62 CTSURICOA                           */
#define CTSURICOA_MUTUAL0_KEY63         (0x3F)                  /* Mutual 0 Key63 CTSURICOA                           */

/**********************************************************************************************************************/
/*    CTSU Base Clock Setting                                                                                         */
/*        Operating clock divided by 2     0x00                                                                       */
/*        Operating clock divided by 4     0x01                                                                       */
/*        Operating clock divided by 6     0x02                                                                       */
/*                       :                                                                                            */
/*                       :                                                                                            */
/*        Operating clock divided by 64    0x1F                                                                       */
/*                                                                                                                    */
/*    Case : CTSU Operating Clock 32MHz      Case : CTSU Operating Clock 24MHz      Case : CTSU Operating Clock 16MHz */
/*           4.0MHz <--- 0x03                       4.0MHz <--- 0x02                       4.0MHz <--- 0x01           */
/*           2.0MHz <--- 0x07                       2.0MHz <--- 0x05                       2.0MHz <--- 0x03           */
/*           1.0MHz <--- 0x0F                       1.0MHz <--- 0x0B                       1.0MHz <--- 0x07           */
/*           0.5MHz <--- 0x1F                       0.5MHz <--- 0x17                       0.5MHz <--- 0x0F           */
/**********************************************************************************************************************/
#define CTSUSDPA_MUTUAL0_KEY00          (2)                     /* Mutual 0 Key00 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY01          (2)                     /* Mutual 0 Key01 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY02          (2)                     /* Mutual 0 Key02 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY03          (2)                     /* Mutual 0 Key03 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY04          (2)                     /* Mutual 0 Key04 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY05          (2)                     /* Mutual 0 Key05 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY06          (2)                     /* Mutual 0 Key06 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY07          (2)                     /* Mutual 0 Key07 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY08          (2)                     /* Mutual 0 Key08 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY09          (2)                     /* Mutual 0 Key09 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY10          (2)                     /* Mutual 0 Key10 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY11          (2)                     /* Mutual 0 Key11 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY12          (2)                     /* Mutual 0 Key12 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY13          (2)                     /* Mutual 0 Key13 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY14          (2)                     /* Mutual 0 Key14 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY15          (2)                     /* Mutual 0 Key15 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY16          (2)                     /* Mutual 0 Key16 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY17          (2)                     /* Mutual 0 Key17 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY18          (2)                     /* Mutual 0 Key18 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY19          (2)                     /* Mutual 0 Key19 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY20          (7)                     /* Mutual 0 Key20 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY21          (7)                     /* Mutual 0 Key21 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY22          (7)                     /* Mutual 0 Key22 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY23          (7)                     /* Mutual 0 Key23 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY24          (7)                     /* Mutual 0 Key24 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY25          (7)                     /* Mutual 0 Key25 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY26          (7)                     /* Mutual 0 Key26 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY27          (7)                     /* Mutual 0 Key27 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY28          (7)                     /* Mutual 0 Key28 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY29          (7)                     /* Mutual 0 Key29 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY30          (7)                     /* Mutual 0 Key30 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY31          (7)                     /* Mutual 0 Key31 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY32          (7)                     /* Mutual 0 Key32 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY33          (7)                     /* Mutual 0 Key33 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY34          (7)                     /* Mutual 0 Key34 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY35          (7)                     /* Mutual 0 Key35 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY36          (7)                     /* Mutual 0 Key36 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY37          (7)                     /* Mutual 0 Key37 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY38          (7)                     /* Mutual 0 Key38 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY39          (7)                     /* Mutual 0 Key39 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY40          (7)                     /* Mutual 0 Key40 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY41          (7)                     /* Mutual 0 Key41 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY42          (7)                     /* Mutual 0 Key42 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY43          (7)                     /* Mutual 0 Key43 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY44          (7)                     /* Mutual 0 Key44 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY45          (7)                     /* Mutual 0 Key45 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY46          (7)                     /* Mutual 0 Key46 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY47          (7)                     /* Mutual 0 Key47 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY48          (7)                     /* Mutual 0 Key48 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY49          (7)                     /* Mutual 0 Key49 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY50          (7)                     /* Mutual 0 Key50 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY51          (7)                     /* Mutual 0 Key51 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY52          (7)                     /* Mutual 0 Key52 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY53          (7)                     /* Mutual 0 Key53 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY54          (7)                     /* Mutual 0 Key54 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY55          (7)                     /* Mutual 0 Key55 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY56          (7)                     /* Mutual 0 Key56 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY57          (7)                     /* Mutual 0 Key57 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY58          (7)                     /* Mutual 0 Key58 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY59          (7)                     /* Mutual 0 Key59 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY60          (7)                     /* Mutual 0 Key60 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY61          (7)                     /* Mutual 0 Key61 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY62          (7)                     /* Mutual 0 Key62 CTSUSDPA                            */
#define CTSUSDPA_MUTUAL0_KEY63          (7)                     /* Mutual 0 Key63 CTSUSDPA                            */

/**********************************************************************************************************************/
/*    CTSU ICO Gain Adjustment                                                                                        */
/*        0 : 100% gain                                                                                               */
/*        1 :  66% gain                                                                                               */
/*        2 :  50% gain                                                                                               */
/*        3 :  40% gain                                                                                               */
/**********************************************************************************************************************/
#define CTSUICOG_MUTUAL0_KEY00          (1)                     /* Mutual 0 Key00 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY01          (1)                     /* Mutual 0 Key01 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY02          (1)                     /* Mutual 0 Key02 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY03          (1)                     /* Mutual 0 Key03 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY04          (1)                     /* Mutual 0 Key04 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY05          (1)                     /* Mutual 0 Key05 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY06          (1)                     /* Mutual 0 Key06 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY07          (1)                     /* Mutual 0 Key07 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY08          (1)                     /* Mutual 0 Key08 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY09          (1)                     /* Mutual 0 Key09 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY10          (1)                     /* Mutual 0 Key10 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY11          (1)                     /* Mutual 0 Key11 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY12          (1)                     /* Mutual 0 Key12 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY13          (1)                     /* Mutual 0 Key13 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY14          (1)                     /* Mutual 0 Key14 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY15          (1)                     /* Mutual 0 Key15 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY16          (1)                     /* Mutual 0 Key16 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY17          (1)                     /* Mutual 0 Key17 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY18          (1)                     /* Mutual 0 Key18 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY19          (1)                     /* Mutual 0 Key19 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY20          (1)                     /* Mutual 0 Key20 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY21          (1)                     /* Mutual 0 Key21 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY22          (1)                     /* Mutual 0 Key22 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY23          (1)                     /* Mutual 0 Key23 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY24          (1)                     /* Mutual 0 Key24 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY25          (1)                     /* Mutual 0 Key25 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY26          (1)                     /* Mutual 0 Key26 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY27          (1)                     /* Mutual 0 Key27 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY28          (1)                     /* Mutual 0 Key28 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY29          (1)                     /* Mutual 0 Key29 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY30          (1)                     /* Mutual 0 Key30 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY31          (1)                     /* Mutual 0 Key31 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY32          (1)                     /* Mutual 0 Key32 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY33          (1)                     /* Mutual 0 Key33 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY34          (1)                     /* Mutual 0 Key34 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY35          (1)                     /* Mutual 0 Key35 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY36          (1)                     /* Mutual 0 Key36 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY37          (1)                     /* Mutual 0 Key37 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY38          (1)                     /* Mutual 0 Key38 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY39          (1)                     /* Mutual 0 Key39 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY40          (1)                     /* Mutual 0 Key40 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY41          (1)                     /* Mutual 0 Key41 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY42          (1)                     /* Mutual 0 Key42 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY43          (1)                     /* Mutual 0 Key43 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY44          (1)                     /* Mutual 0 Key44 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY45          (1)                     /* Mutual 0 Key45 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY46          (1)                     /* Mutual 0 Key46 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY47          (1)                     /* Mutual 0 Key47 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY48          (1)                     /* Mutual 0 Key48 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY49          (1)                     /* Mutual 0 Key49 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY50          (1)                     /* Mutual 0 Key50 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY51          (1)                     /* Mutual 0 Key51 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY52          (1)                     /* Mutual 0 Key52 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY53          (1)                     /* Mutual 0 Key53 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY54          (1)                     /* Mutual 0 Key54 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY55          (1)                     /* Mutual 0 Key55 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY56          (1)                     /* Mutual 0 Key56 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY57          (1)                     /* Mutual 0 Key57 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY58          (1)                     /* Mutual 0 Key58 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY59          (1)                     /* Mutual 0 Key59 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY60          (1)                     /* Mutual 0 Key60 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY61          (1)                     /* Mutual 0 Key61 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY62          (1)                     /* Mutual 0 Key62 CTSUICOG                            */
#define CTSUICOG_MUTUAL0_KEY63          (1)                     /* Mutual 0 Key63 CTSUICOG                            */

#define CTSUSO1_MUTUAL0_KEY00  ((CTSUICOG_MUTUAL0_KEY00 << 13) | (CTSUSDPA_MUTUAL0_KEY00 << 8) | CTSURICOA_MUTUAL0_KEY00)
#define CTSUSO1_MUTUAL0_KEY01  ((CTSUICOG_MUTUAL0_KEY01 << 13) | (CTSUSDPA_MUTUAL0_KEY01 << 8) | CTSURICOA_MUTUAL0_KEY01)
#define CTSUSO1_MUTUAL0_KEY02  ((CTSUICOG_MUTUAL0_KEY02 << 13) | (CTSUSDPA_MUTUAL0_KEY02 << 8) | CTSURICOA_MUTUAL0_KEY02)
#define CTSUSO1_MUTUAL0_KEY03  ((CTSUICOG_MUTUAL0_KEY03 << 13) | (CTSUSDPA_MUTUAL0_KEY03 << 8) | CTSURICOA_MUTUAL0_KEY03)
#define CTSUSO1_MUTUAL0_KEY04  ((CTSUICOG_MUTUAL0_KEY04 << 13) | (CTSUSDPA_MUTUAL0_KEY04 << 8) | CTSURICOA_MUTUAL0_KEY04)
#define CTSUSO1_MUTUAL0_KEY05  ((CTSUICOG_MUTUAL0_KEY05 << 13) | (CTSUSDPA_MUTUAL0_KEY05 << 8) | CTSURICOA_MUTUAL0_KEY05)
#define CTSUSO1_MUTUAL0_KEY06  ((CTSUICOG_MUTUAL0_KEY06 << 13) | (CTSUSDPA_MUTUAL0_KEY06 << 8) | CTSURICOA_MUTUAL0_KEY06)
#define CTSUSO1_MUTUAL0_KEY07  ((CTSUICOG_MUTUAL0_KEY07 << 13) | (CTSUSDPA_MUTUAL0_KEY07 << 8) | CTSURICOA_MUTUAL0_KEY07)
#define CTSUSO1_MUTUAL0_KEY08  ((CTSUICOG_MUTUAL0_KEY08 << 13) | (CTSUSDPA_MUTUAL0_KEY08 << 8) | CTSURICOA_MUTUAL0_KEY08)
#define CTSUSO1_MUTUAL0_KEY09  ((CTSUICOG_MUTUAL0_KEY09 << 13) | (CTSUSDPA_MUTUAL0_KEY09 << 8) | CTSURICOA_MUTUAL0_KEY09)
#define CTSUSO1_MUTUAL0_KEY10  ((CTSUICOG_MUTUAL0_KEY10 << 13) | (CTSUSDPA_MUTUAL0_KEY10 << 8) | CTSURICOA_MUTUAL0_KEY10)
#define CTSUSO1_MUTUAL0_KEY11  ((CTSUICOG_MUTUAL0_KEY11 << 13) | (CTSUSDPA_MUTUAL0_KEY11 << 8) | CTSURICOA_MUTUAL0_KEY11)
#define CTSUSO1_MUTUAL0_KEY12  ((CTSUICOG_MUTUAL0_KEY12 << 13) | (CTSUSDPA_MUTUAL0_KEY12 << 8) | CTSURICOA_MUTUAL0_KEY12)
#define CTSUSO1_MUTUAL0_KEY13  ((CTSUICOG_MUTUAL0_KEY13 << 13) | (CTSUSDPA_MUTUAL0_KEY13 << 8) | CTSURICOA_MUTUAL0_KEY13)
#define CTSUSO1_MUTUAL0_KEY14  ((CTSUICOG_MUTUAL0_KEY14 << 13) | (CTSUSDPA_MUTUAL0_KEY14 << 8) | CTSURICOA_MUTUAL0_KEY14)
#define CTSUSO1_MUTUAL0_KEY15  ((CTSUICOG_MUTUAL0_KEY15 << 13) | (CTSUSDPA_MUTUAL0_KEY15 << 8) | CTSURICOA_MUTUAL0_KEY15)
#define CTSUSO1_MUTUAL0_KEY16  ((CTSUICOG_MUTUAL0_KEY16 << 13) | (CTSUSDPA_MUTUAL0_KEY16 << 8) | CTSURICOA_MUTUAL0_KEY16)
#define CTSUSO1_MUTUAL0_KEY17  ((CTSUICOG_MUTUAL0_KEY17 << 13) | (CTSUSDPA_MUTUAL0_KEY17 << 8) | CTSURICOA_MUTUAL0_KEY17)
#define CTSUSO1_MUTUAL0_KEY18  ((CTSUICOG_MUTUAL0_KEY18 << 13) | (CTSUSDPA_MUTUAL0_KEY18 << 8) | CTSURICOA_MUTUAL0_KEY18)
#define CTSUSO1_MUTUAL0_KEY19  ((CTSUICOG_MUTUAL0_KEY19 << 13) | (CTSUSDPA_MUTUAL0_KEY19 << 8) | CTSURICOA_MUTUAL0_KEY19)
#define CTSUSO1_MUTUAL0_KEY20  ((CTSUICOG_MUTUAL0_KEY20 << 13) | (CTSUSDPA_MUTUAL0_KEY20 << 8) | CTSURICOA_MUTUAL0_KEY20)
#define CTSUSO1_MUTUAL0_KEY21  ((CTSUICOG_MUTUAL0_KEY21 << 13) | (CTSUSDPA_MUTUAL0_KEY21 << 8) | CTSURICOA_MUTUAL0_KEY21)
#define CTSUSO1_MUTUAL0_KEY22  ((CTSUICOG_MUTUAL0_KEY22 << 13) | (CTSUSDPA_MUTUAL0_KEY22 << 8) | CTSURICOA_MUTUAL0_KEY22)
#define CTSUSO1_MUTUAL0_KEY23  ((CTSUICOG_MUTUAL0_KEY23 << 13) | (CTSUSDPA_MUTUAL0_KEY23 << 8) | CTSURICOA_MUTUAL0_KEY23)
#define CTSUSO1_MUTUAL0_KEY24  ((CTSUICOG_MUTUAL0_KEY24 << 13) | (CTSUSDPA_MUTUAL0_KEY24 << 8) | CTSURICOA_MUTUAL0_KEY24)
#define CTSUSO1_MUTUAL0_KEY25  ((CTSUICOG_MUTUAL0_KEY25 << 13) | (CTSUSDPA_MUTUAL0_KEY25 << 8) | CTSURICOA_MUTUAL0_KEY25)
#define CTSUSO1_MUTUAL0_KEY26  ((CTSUICOG_MUTUAL0_KEY26 << 13) | (CTSUSDPA_MUTUAL0_KEY26 << 8) | CTSURICOA_MUTUAL0_KEY26)
#define CTSUSO1_MUTUAL0_KEY27  ((CTSUICOG_MUTUAL0_KEY27 << 13) | (CTSUSDPA_MUTUAL0_KEY27 << 8) | CTSURICOA_MUTUAL0_KEY27)
#define CTSUSO1_MUTUAL0_KEY28  ((CTSUICOG_MUTUAL0_KEY28 << 13) | (CTSUSDPA_MUTUAL0_KEY28 << 8) | CTSURICOA_MUTUAL0_KEY28)
#define CTSUSO1_MUTUAL0_KEY29  ((CTSUICOG_MUTUAL0_KEY29 << 13) | (CTSUSDPA_MUTUAL0_KEY29 << 8) | CTSURICOA_MUTUAL0_KEY29)
#define CTSUSO1_MUTUAL0_KEY30  ((CTSUICOG_MUTUAL0_KEY30 << 13) | (CTSUSDPA_MUTUAL0_KEY30 << 8) | CTSURICOA_MUTUAL0_KEY30)
#define CTSUSO1_MUTUAL0_KEY31  ((CTSUICOG_MUTUAL0_KEY31 << 13) | (CTSUSDPA_MUTUAL0_KEY31 << 8) | CTSURICOA_MUTUAL0_KEY31)
#define CTSUSO1_MUTUAL0_KEY32  ((CTSUICOG_MUTUAL0_KEY32 << 13) | (CTSUSDPA_MUTUAL0_KEY32 << 8) | CTSURICOA_MUTUAL0_KEY32)
#define CTSUSO1_MUTUAL0_KEY33  ((CTSUICOG_MUTUAL0_KEY33 << 13) | (CTSUSDPA_MUTUAL0_KEY33 << 8) | CTSURICOA_MUTUAL0_KEY33)
#define CTSUSO1_MUTUAL0_KEY34  ((CTSUICOG_MUTUAL0_KEY34 << 13) | (CTSUSDPA_MUTUAL0_KEY34 << 8) | CTSURICOA_MUTUAL0_KEY34)
#define CTSUSO1_MUTUAL0_KEY35  ((CTSUICOG_MUTUAL0_KEY35 << 13) | (CTSUSDPA_MUTUAL0_KEY35 << 8) | CTSURICOA_MUTUAL0_KEY35)
#define CTSUSO1_MUTUAL0_KEY36  ((CTSUICOG_MUTUAL0_KEY36 << 13) | (CTSUSDPA_MUTUAL0_KEY36 << 8) | CTSURICOA_MUTUAL0_KEY36)
#define CTSUSO1_MUTUAL0_KEY37  ((CTSUICOG_MUTUAL0_KEY37 << 13) | (CTSUSDPA_MUTUAL0_KEY37 << 8) | CTSURICOA_MUTUAL0_KEY37)
#define CTSUSO1_MUTUAL0_KEY38  ((CTSUICOG_MUTUAL0_KEY38 << 13) | (CTSUSDPA_MUTUAL0_KEY38 << 8) | CTSURICOA_MUTUAL0_KEY38)
#define CTSUSO1_MUTUAL0_KEY39  ((CTSUICOG_MUTUAL0_KEY39 << 13) | (CTSUSDPA_MUTUAL0_KEY39 << 8) | CTSURICOA_MUTUAL0_KEY39)
#define CTSUSO1_MUTUAL0_KEY40  ((CTSUICOG_MUTUAL0_KEY40 << 13) | (CTSUSDPA_MUTUAL0_KEY40 << 8) | CTSURICOA_MUTUAL0_KEY40)
#define CTSUSO1_MUTUAL0_KEY41  ((CTSUICOG_MUTUAL0_KEY41 << 13) | (CTSUSDPA_MUTUAL0_KEY41 << 8) | CTSURICOA_MUTUAL0_KEY41)
#define CTSUSO1_MUTUAL0_KEY42  ((CTSUICOG_MUTUAL0_KEY42 << 13) | (CTSUSDPA_MUTUAL0_KEY42 << 8) | CTSURICOA_MUTUAL0_KEY42)
#define CTSUSO1_MUTUAL0_KEY43  ((CTSUICOG_MUTUAL0_KEY43 << 13) | (CTSUSDPA_MUTUAL0_KEY43 << 8) | CTSURICOA_MUTUAL0_KEY43)
#define CTSUSO1_MUTUAL0_KEY44  ((CTSUICOG_MUTUAL0_KEY44 << 13) | (CTSUSDPA_MUTUAL0_KEY44 << 8) | CTSURICOA_MUTUAL0_KEY44)
#define CTSUSO1_MUTUAL0_KEY45  ((CTSUICOG_MUTUAL0_KEY45 << 13) | (CTSUSDPA_MUTUAL0_KEY45 << 8) | CTSURICOA_MUTUAL0_KEY45)
#define CTSUSO1_MUTUAL0_KEY46  ((CTSUICOG_MUTUAL0_KEY46 << 13) | (CTSUSDPA_MUTUAL0_KEY46 << 8) | CTSURICOA_MUTUAL0_KEY46)
#define CTSUSO1_MUTUAL0_KEY47  ((CTSUICOG_MUTUAL0_KEY47 << 13) | (CTSUSDPA_MUTUAL0_KEY47 << 8) | CTSURICOA_MUTUAL0_KEY47)
#define CTSUSO1_MUTUAL0_KEY48  ((CTSUICOG_MUTUAL0_KEY48 << 13) | (CTSUSDPA_MUTUAL0_KEY48 << 8) | CTSURICOA_MUTUAL0_KEY48)
#define CTSUSO1_MUTUAL0_KEY49  ((CTSUICOG_MUTUAL0_KEY49 << 13) | (CTSUSDPA_MUTUAL0_KEY49 << 8) | CTSURICOA_MUTUAL0_KEY49)
#define CTSUSO1_MUTUAL0_KEY50  ((CTSUICOG_MUTUAL0_KEY50 << 13) | (CTSUSDPA_MUTUAL0_KEY50 << 8) | CTSURICOA_MUTUAL0_KEY50)
#define CTSUSO1_MUTUAL0_KEY51  ((CTSUICOG_MUTUAL0_KEY51 << 13) | (CTSUSDPA_MUTUAL0_KEY51 << 8) | CTSURICOA_MUTUAL0_KEY51)
#define CTSUSO1_MUTUAL0_KEY52  ((CTSUICOG_MUTUAL0_KEY52 << 13) | (CTSUSDPA_MUTUAL0_KEY52 << 8) | CTSURICOA_MUTUAL0_KEY52)
#define CTSUSO1_MUTUAL0_KEY53  ((CTSUICOG_MUTUAL0_KEY53 << 13) | (CTSUSDPA_MUTUAL0_KEY53 << 8) | CTSURICOA_MUTUAL0_KEY53)
#define CTSUSO1_MUTUAL0_KEY54  ((CTSUICOG_MUTUAL0_KEY54 << 13) | (CTSUSDPA_MUTUAL0_KEY54 << 8) | CTSURICOA_MUTUAL0_KEY54)
#define CTSUSO1_MUTUAL0_KEY55  ((CTSUICOG_MUTUAL0_KEY55 << 13) | (CTSUSDPA_MUTUAL0_KEY55 << 8) | CTSURICOA_MUTUAL0_KEY55)
#define CTSUSO1_MUTUAL0_KEY56  ((CTSUICOG_MUTUAL0_KEY56 << 13) | (CTSUSDPA_MUTUAL0_KEY56 << 8) | CTSURICOA_MUTUAL0_KEY56)
#define CTSUSO1_MUTUAL0_KEY57  ((CTSUICOG_MUTUAL0_KEY57 << 13) | (CTSUSDPA_MUTUAL0_KEY57 << 8) | CTSURICOA_MUTUAL0_KEY57)
#define CTSUSO1_MUTUAL0_KEY58  ((CTSUICOG_MUTUAL0_KEY58 << 13) | (CTSUSDPA_MUTUAL0_KEY58 << 8) | CTSURICOA_MUTUAL0_KEY58)
#define CTSUSO1_MUTUAL0_KEY59  ((CTSUICOG_MUTUAL0_KEY59 << 13) | (CTSUSDPA_MUTUAL0_KEY59 << 8) | CTSURICOA_MUTUAL0_KEY59)
#define CTSUSO1_MUTUAL0_KEY60  ((CTSUICOG_MUTUAL0_KEY60 << 13) | (CTSUSDPA_MUTUAL0_KEY60 << 8) | CTSURICOA_MUTUAL0_KEY60)
#define CTSUSO1_MUTUAL0_KEY61  ((CTSUICOG_MUTUAL0_KEY61 << 13) | (CTSUSDPA_MUTUAL0_KEY61 << 8) | CTSURICOA_MUTUAL0_KEY61)
#define CTSUSO1_MUTUAL0_KEY62  ((CTSUICOG_MUTUAL0_KEY62 << 13) | (CTSUSDPA_MUTUAL0_KEY62 << 8) | CTSURICOA_MUTUAL0_KEY62)
#define CTSUSO1_MUTUAL0_KEY63  ((CTSUICOG_MUTUAL0_KEY63 << 13) | (CTSUSDPA_MUTUAL0_KEY63 << 8) | CTSURICOA_MUTUAL0_KEY63)
#endif    // ( MUTUAL_METHOD_NUM >= 1 )

#if ( MUTUAL_METHOD_NUM >= 2 )
/*====================================================================================================================*/
/*=====     Mutual-measurement 1 TS enable definition    =============================================================*/
/*====================================================================================================================*/
#define MUTUAL1_ENABLE_TS00              (0)        /* Mutual 1 TS00 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS01              (0)        /* Mutual 1 TS01 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS02              (0)        /* Mutual 1 TS02 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS03              (0)        /* Mutual 1 TS03 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS04              (0)        /* Mutual 1 TS04 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS05              (0)        /* Mutual 1 TS05 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS06              (0)        /* Mutual 1 TS06 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS07              (0)        /* Mutual 1 TS07 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS08              (0)        /* Mutual 1 TS08 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS09              (0)        /* Mutual 1 TS09 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS10              (0)        /* Mutual 1 TS10 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS11              (0)        /* Mutual 1 TS11 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS12              (0)        /* Mutual 1 TS12 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS13              (0)        /* Mutual 1 TS13 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS14              (0)        /* Mutual 1 TS14 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS15              (0)        /* Mutual 1 TS15 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS16              (0)        /* Mutual 1 TS16 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS17              (0)        /* Mutual 1 TS17 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS18              (0)        /* Mutual 1 TS18 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS19              (0)        /* Mutual 1 TS19 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS20              (0)        /* Mutual 1 TS20 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS21              (0)        /* Mutual 1 TS21 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS22              (0)        /* Mutual 1 TS22 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS23              (0)        /* Mutual 1 TS23 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS24              (0)        /* Mutual 1 TS24 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS25              (0)        /* Mutual 1 TS25 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS26              (0)        /* Mutual 1 TS26 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS27              (0)        /* Mutual 1 TS27 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS28              (0)        /* Mutual 1 TS28 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS29              (0)        /* Mutual 1 TS29 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS30              (0)        /* Mutual 1 TS30 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS31              (0)        /* Mutual 1 TS31 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS32              (0)        /* Mutual 1 TS32 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS33              (0)        /* Mutual 1 TS33 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS34              (0)        /* Mutual 1 TS34 0:disable 1:enable                               */
#define MUTUAL1_ENABLE_TS35              (0)        /* Mutual 1 TS35 0:disable 1:enable                               */

/*****    Address 000A 0906h CTSU Channel enable control register 0    ************************************************/
#define CTSUCHAC0_MUTUAL1_ENABLE_TS      ((MUTUAL1_ENABLE_TS00 << 0) | (MUTUAL1_ENABLE_TS01 << 1) | \
                                          (MUTUAL1_ENABLE_TS02 << 2) | (MUTUAL1_ENABLE_TS03 << 3) | \
                                          (MUTUAL1_ENABLE_TS04 << 4) | (MUTUAL1_ENABLE_TS05 << 5) | \
                                          (MUTUAL1_ENABLE_TS06 << 6) | (MUTUAL1_ENABLE_TS07 << 7))

/*****    Address 000A 0907h CTSU Channel enable control register 1    ************************************************/
#define CTSUCHAC1_MUTUAL1_ENABLE_TS      ((MUTUAL1_ENABLE_TS08 << 0) | (MUTUAL1_ENABLE_TS09 << 1) | \
                                          (MUTUAL1_ENABLE_TS10 << 2) | (MUTUAL1_ENABLE_TS11 << 3) | \
                                          (MUTUAL1_ENABLE_TS12 << 4) | (MUTUAL1_ENABLE_TS13 << 5) | \
                                          (MUTUAL1_ENABLE_TS14 << 6) | (MUTUAL1_ENABLE_TS15 << 7))

/*****    Address 000A 0908h CTSU Channel enable control register 2    ************************************************/
#define CTSUCHAC2_MUTUAL1_ENABLE_TS      ((MUTUAL1_ENABLE_TS16 << 0) | (MUTUAL1_ENABLE_TS17 << 1) | \
                                          (MUTUAL1_ENABLE_TS18 << 2) | (MUTUAL1_ENABLE_TS19 << 3) | \
                                          (MUTUAL1_ENABLE_TS20 << 4) | (MUTUAL1_ENABLE_TS21 << 5) | \
                                          (MUTUAL1_ENABLE_TS22 << 6) | (MUTUAL1_ENABLE_TS23 << 7))

/*****    Address 000A 0909h CTSU Channel enable control register 3    ************************************************/
#define CTSUCHAC3_MUTUAL1_ENABLE_TS      ((MUTUAL1_ENABLE_TS24 << 0) | (MUTUAL1_ENABLE_TS25 << 1) | \
                                          (MUTUAL1_ENABLE_TS26 << 2) | (MUTUAL1_ENABLE_TS27 << 3) | \
                                          (MUTUAL1_ENABLE_TS28 << 4) | (MUTUAL1_ENABLE_TS29 << 5) | \
                                          (MUTUAL1_ENABLE_TS30 << 6) | (MUTUAL1_ENABLE_TS31 << 7))

/*****    Address 000A 090ah CTSU Channel enable control register 4    ************************************************/
#define CTSUCHAC4_MUTUAL1_ENABLE_TS      ((MUTUAL1_ENABLE_TS32 << 0) | (MUTUAL1_ENABLE_TS33 << 1) | \
                                          (MUTUAL1_ENABLE_TS34 << 2) | (MUTUAL1_ENABLE_TS35 << 3))

/* SUM of Channels */ /* Do not edit this macro definition */
#define MUTUAL1_ENABLE_NUM               (MUTUAL1_ENABLE_TS00 + MUTUAL1_ENABLE_TS01 + MUTUAL1_ENABLE_TS02 + \
                                          MUTUAL1_ENABLE_TS03 + MUTUAL1_ENABLE_TS04 + MUTUAL1_ENABLE_TS05 + \
                                          MUTUAL1_ENABLE_TS06 + MUTUAL1_ENABLE_TS07 + MUTUAL1_ENABLE_TS08 + \
                                          MUTUAL1_ENABLE_TS09 + MUTUAL1_ENABLE_TS10 + MUTUAL1_ENABLE_TS11 + \
                                          MUTUAL1_ENABLE_TS12 + MUTUAL1_ENABLE_TS13 + MUTUAL1_ENABLE_TS14 + \
                                          MUTUAL1_ENABLE_TS15 + MUTUAL1_ENABLE_TS16 + MUTUAL1_ENABLE_TS17 + \
                                          MUTUAL1_ENABLE_TS18 + MUTUAL1_ENABLE_TS19 + MUTUAL1_ENABLE_TS20 + \
                                          MUTUAL1_ENABLE_TS21 + MUTUAL1_ENABLE_TS22 + MUTUAL1_ENABLE_TS23 + \
                                          MUTUAL1_ENABLE_TS24 + MUTUAL1_ENABLE_TS25 + MUTUAL1_ENABLE_TS26 + \
                                          MUTUAL1_ENABLE_TS27 + MUTUAL1_ENABLE_TS28 + MUTUAL1_ENABLE_TS29 + \
                                          MUTUAL1_ENABLE_TS30 + MUTUAL1_ENABLE_TS31 + MUTUAL1_ENABLE_TS32 + \
                                          MUTUAL1_ENABLE_TS33 + MUTUAL1_ENABLE_TS34 + MUTUAL1_ENABLE_TS35)

/*====================================================================================================================*/
/*=====     Mutual-measurement 1 function definition     =============================================================*/
/*====================================================================================================================*/
#define MUTUAL1_FUNCTION_TS00            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS01            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS02            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS03            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS04            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS05            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS06            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS07            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS08            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS09            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS10            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS11            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS12            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS13            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS14            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS15            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS16            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS17            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS18            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS19            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS20            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS21            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS22            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS23            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS24            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS25            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS26            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS27            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS28            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS29            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS30            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS31            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS32            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS33            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS34            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL1_FUNCTION_TS35            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */

/*****    Address 000A 090Bh CTSU Channel send and receive control register 0 *****************************************/
#define CTSUCHTRC0_MUTUAL1_TRANSMIT_TS   ((MUTUAL1_FUNCTION_TS00 << 0) | (MUTUAL1_FUNCTION_TS01 << 1) | \
                                          (MUTUAL1_FUNCTION_TS02 << 2) | (MUTUAL1_FUNCTION_TS03 << 3) | \
                                          (MUTUAL1_FUNCTION_TS04 << 4) | (MUTUAL1_FUNCTION_TS05 << 5) | \
                                          (MUTUAL1_FUNCTION_TS06 << 6) | (MUTUAL1_FUNCTION_TS07 << 7))

/*****    Address 000A 090Ch CTSU Channel send and receive control register 1 *****************************************/
#define CTSUCHTRC1_MUTUAL1_TRANSMIT_TS   ((MUTUAL1_FUNCTION_TS08 << 0) | (MUTUAL1_FUNCTION_TS09 << 1) | \
                                          (MUTUAL1_FUNCTION_TS10 << 2) | (MUTUAL1_FUNCTION_TS11 << 3) | \
                                          (MUTUAL1_FUNCTION_TS12 << 4) | (MUTUAL1_FUNCTION_TS13 << 5) | \
                                          (MUTUAL1_FUNCTION_TS14 << 6) | (MUTUAL1_FUNCTION_TS15 << 7))

/*****    Address 000A 090Dh CTSU Channel send and receive control register 2 *****************************************/
#define CTSUCHTRC2_MUTUAL1_TRANSMIT_TS   ((MUTUAL1_FUNCTION_TS16 << 0) | (MUTUAL1_FUNCTION_TS17 << 1) | \
                                          (MUTUAL1_FUNCTION_TS18 << 2) | (MUTUAL1_FUNCTION_TS19 << 3) | \
                                          (MUTUAL1_FUNCTION_TS20 << 4) | (MUTUAL1_FUNCTION_TS21 << 5) | \
                                          (MUTUAL1_FUNCTION_TS22 << 6) | (MUTUAL1_FUNCTION_TS23 << 7))

/*****    Address 000A 090Eh CTSU Channel send and receive control register 3 *****************************************/
#define CTSUCHTRC3_MUTUAL1_TRANSMIT_TS   ((MUTUAL1_FUNCTION_TS24 << 0) | (MUTUAL1_FUNCTION_TS25 << 1) | \
                                          (MUTUAL1_FUNCTION_TS26 << 2) | (MUTUAL1_FUNCTION_TS27 << 3) | \
                                          (MUTUAL1_FUNCTION_TS28 << 4) | (MUTUAL1_FUNCTION_TS29 << 5) | \
                                          (MUTUAL1_FUNCTION_TS30 << 6) | (MUTUAL1_FUNCTION_TS31 << 7))

/*****    Address 000A 090Fh CTSU Channel send and receive control register 4 *****************************************/
#define CTSUCHTRC4_MUTUAL1_TRANSMIT_TS   ((MUTUAL1_FUNCTION_TS32 << 0) | (MUTUAL1_FUNCTION_TS33 << 1) | \
                                          (MUTUAL1_FUNCTION_TS34 << 2) | (MUTUAL1_FUNCTION_TS35 << 3))

#define TRANSMISSION1_NUM                  (MUTUAL1_FUNCTION_TS00 + MUTUAL1_FUNCTION_TS01 + MUTUAL1_FUNCTION_TS02 + \
                                            MUTUAL1_FUNCTION_TS03 + MUTUAL1_FUNCTION_TS04 + MUTUAL1_FUNCTION_TS05 + \
                                            MUTUAL1_FUNCTION_TS06 + MUTUAL1_FUNCTION_TS07 + MUTUAL1_FUNCTION_TS08 + \
                                            MUTUAL1_FUNCTION_TS09 + MUTUAL1_FUNCTION_TS10 + MUTUAL1_FUNCTION_TS11 + \
                                            MUTUAL1_FUNCTION_TS12 + MUTUAL1_FUNCTION_TS13 + MUTUAL1_FUNCTION_TS14 + \
                                            MUTUAL1_FUNCTION_TS15 + MUTUAL1_FUNCTION_TS16 + MUTUAL1_FUNCTION_TS17 + \
                                            MUTUAL1_FUNCTION_TS18 + MUTUAL1_FUNCTION_TS19 + MUTUAL1_FUNCTION_TS20 + \
                                            MUTUAL1_FUNCTION_TS21 + MUTUAL1_FUNCTION_TS22 + MUTUAL1_FUNCTION_TS23 + \
                                            MUTUAL1_FUNCTION_TS24 + MUTUAL1_FUNCTION_TS25 + MUTUAL1_FUNCTION_TS26 + \
                                            MUTUAL1_FUNCTION_TS27 + MUTUAL1_FUNCTION_TS28 + MUTUAL1_FUNCTION_TS29 + \
                                            MUTUAL1_FUNCTION_TS30 + MUTUAL1_FUNCTION_TS31 + MUTUAL1_FUNCTION_TS32 + \
                                            MUTUAL1_FUNCTION_TS33 + MUTUAL1_FUNCTION_TS34 + MUTUAL1_FUNCTION_TS35)

#define RECEPTION1_NUM                     (MUTUAL1_ENABLE_NUM - TRANSMISSION1_NUM)
#define MUTUAL1_NUM                        (TRANSMISSION1_NUM * RECEPTION1_NUM)

#if TRANSMISSION1_NUM == 0
    #error "Send TS Setting error ( TRANSMISSION1_NUM = 0 )"
#endif
#if RECEPTION1_NUM == 0
    #error "Receive TS Setting error ( RECEPTION_NUM1 = 0 )"
#endif

/*****    Address 000A 0912h CTSU High-Pass Noise Reduction Spectrum Diffusion Control Register    ********************/
/**********************************************************************************************************************/
/*    CTSU Spectrum Diffusion Frequency Division Setting                                                              */
/*    Base Clock Frequency fb (MHz)   CTSUSSDIV[3:0] Bit Setting                                                      */
/*          4.00 =< fb                           0x00                                                                 */
/*          2.00 =< fb  < 4.00                   0x01                                                                 */
/*          1.33 =< fb  < 2.00                   0x02                                                                 */
/*          1.00 =< fb  < 1.33                   0x03                                                                 */
/*          0.80 =< fb  < 1.00                   0x04                                                                 */
/*          0.67 =< fb  < 0.80                   0x05                                                                 */
/*          0.57 =< fb  < 0.67                   0x06                                                                 */
/*          0.50 =< fb  < 0.57                   0x07                                                                 */
/*          0.44 =< fb  < 0.50                   0x08                                                                 */
/*          0.40 =< fb  < 0.44                   0x09                                                                 */
/*          0.36 =< fb  < 0.40                   0x0A                                                                 */
/*          0.33 =< fb  < 0.36                   0x0B                                                                 */
/*          0.31 =< fb  < 0.33                   0x0C                                                                 */
/*          0.29 =< fb  < 0.31                   0x0D                                                                 */
/*          0.27 =< fb  < 0.29                   0x0E                                                                 */
/*                  fb =< 0.25                   0x0F                                                                 */
/**********************************************************************************************************************/
#define CTSUSSDIV_MUTUAL1_KEY00         (0x01)                  /* Mutual 1 Key00 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY01         (0x01)                  /* Mutual 1 Key01 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY02         (0x01)                  /* Mutual 1 Key02 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY03         (0x01)                  /* Mutual 1 Key03 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY04         (0x01)                  /* Mutual 1 Key04 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY05         (0x01)                  /* Mutual 1 Key05 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY06         (0x01)                  /* Mutual 1 Key06 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY07         (0x01)                  /* Mutual 1 Key07 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY08         (0x01)                  /* Mutual 1 Key08 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY09         (0x01)                  /* Mutual 1 Key09 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY10         (0x01)                  /* Mutual 1 Key10 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY11         (0x01)                  /* Mutual 1 Key11 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY12         (0x01)                  /* Mutual 1 Key12 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY13         (0x01)                  /* Mutual 1 Key13 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY14         (0x01)                  /* Mutual 1 Key14 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY15         (0x01)                  /* Mutual 1 Key15 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY16         (0x01)                  /* Mutual 1 Key16 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY17         (0x01)                  /* Mutual 1 Key17 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY18         (0x01)                  /* Mutual 1 Key18 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY19         (0x01)                  /* Mutual 1 Key19 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY20         (0x01)                  /* Mutual 1 Key20 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY21         (0x01)                  /* Mutual 1 Key21 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY22         (0x01)                  /* Mutual 1 Key22 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY23         (0x01)                  /* Mutual 1 Key23 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY24         (0x01)                  /* Mutual 1 Key24 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY25         (0x01)                  /* Mutual 1 Key25 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY26         (0x01)                  /* Mutual 1 Key26 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY27         (0x01)                  /* Mutual 1 Key27 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY28         (0x01)                  /* Mutual 1 Key28 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY29         (0x01)                  /* Mutual 1 Key29 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY30         (0x01)                  /* Mutual 1 Key30 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY31         (0x01)                  /* Mutual 1 Key31 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY32         (0x01)                  /* Mutual 1 Key32 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY33         (0x01)                  /* Mutual 1 Key33 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY34         (0x01)                  /* Mutual 1 Key34 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY35         (0x01)                  /* Mutual 1 Key35 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY36         (0x01)                  /* Mutual 1 Key36 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY37         (0x01)                  /* Mutual 1 Key37 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY38         (0x01)                  /* Mutual 1 Key38 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY39         (0x01)                  /* Mutual 1 Key39 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY40         (0x01)                  /* Mutual 1 Key40 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY41         (0x01)                  /* Mutual 1 Key41 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY42         (0x01)                  /* Mutual 1 Key42 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY43         (0x01)                  /* Mutual 1 Key43 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY44         (0x01)                  /* Mutual 1 Key44 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY45         (0x01)                  /* Mutual 1 Key45 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY46         (0x01)                  /* Mutual 1 Key46 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY47         (0x01)                  /* Mutual 1 Key47 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY48         (0x01)                  /* Mutual 1 Key48 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY49         (0x01)                  /* Mutual 1 Key49 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY50         (0x01)                  /* Mutual 1 Key50 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY51         (0x01)                  /* Mutual 1 Key51 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY52         (0x01)                  /* Mutual 1 Key52 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY53         (0x01)                  /* Mutual 1 Key53 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY54         (0x01)                  /* Mutual 1 Key54 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY55         (0x01)                  /* Mutual 1 Key55 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY56         (0x01)                  /* Mutual 1 Key56 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY57         (0x01)                  /* Mutual 1 Key57 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY58         (0x01)                  /* Mutual 1 Key58 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY59         (0x01)                  /* Mutual 1 Key59 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY60         (0x01)                  /* Mutual 1 Key60 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY61         (0x01)                  /* Mutual 1 Key61 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY62         (0x01)                  /* Mutual 1 Key62 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL1_KEY63         (0x01)                  /* Mutual 1 Key63 CTSUSDIV                            */

#define CTSUSSC_MUTUAL1_KEY00           (CTSUSSDIV_MUTUAL1_KEY00 << 8)
#define CTSUSSC_MUTUAL1_KEY01           (CTSUSSDIV_MUTUAL1_KEY01 << 8)
#define CTSUSSC_MUTUAL1_KEY02           (CTSUSSDIV_MUTUAL1_KEY02 << 8)
#define CTSUSSC_MUTUAL1_KEY03           (CTSUSSDIV_MUTUAL1_KEY03 << 8)
#define CTSUSSC_MUTUAL1_KEY04           (CTSUSSDIV_MUTUAL1_KEY04 << 8)
#define CTSUSSC_MUTUAL1_KEY05           (CTSUSSDIV_MUTUAL1_KEY05 << 8)
#define CTSUSSC_MUTUAL1_KEY06           (CTSUSSDIV_MUTUAL1_KEY06 << 8)
#define CTSUSSC_MUTUAL1_KEY07           (CTSUSSDIV_MUTUAL1_KEY07 << 8)
#define CTSUSSC_MUTUAL1_KEY08           (CTSUSSDIV_MUTUAL1_KEY08 << 8)
#define CTSUSSC_MUTUAL1_KEY09           (CTSUSSDIV_MUTUAL1_KEY09 << 8)
#define CTSUSSC_MUTUAL1_KEY10           (CTSUSSDIV_MUTUAL1_KEY10 << 8)
#define CTSUSSC_MUTUAL1_KEY11           (CTSUSSDIV_MUTUAL1_KEY11 << 8)
#define CTSUSSC_MUTUAL1_KEY12           (CTSUSSDIV_MUTUAL1_KEY12 << 8)
#define CTSUSSC_MUTUAL1_KEY13           (CTSUSSDIV_MUTUAL1_KEY13 << 8)
#define CTSUSSC_MUTUAL1_KEY14           (CTSUSSDIV_MUTUAL1_KEY14 << 8)
#define CTSUSSC_MUTUAL1_KEY15           (CTSUSSDIV_MUTUAL1_KEY15 << 8)
#define CTSUSSC_MUTUAL1_KEY16           (CTSUSSDIV_MUTUAL1_KEY16 << 8)
#define CTSUSSC_MUTUAL1_KEY17           (CTSUSSDIV_MUTUAL1_KEY17 << 8)
#define CTSUSSC_MUTUAL1_KEY18           (CTSUSSDIV_MUTUAL1_KEY18 << 8)
#define CTSUSSC_MUTUAL1_KEY19           (CTSUSSDIV_MUTUAL1_KEY19 << 8)
#define CTSUSSC_MUTUAL1_KEY20           (CTSUSSDIV_MUTUAL1_KEY20 << 8)
#define CTSUSSC_MUTUAL1_KEY21           (CTSUSSDIV_MUTUAL1_KEY21 << 8)
#define CTSUSSC_MUTUAL1_KEY22           (CTSUSSDIV_MUTUAL1_KEY22 << 8)
#define CTSUSSC_MUTUAL1_KEY23           (CTSUSSDIV_MUTUAL1_KEY23 << 8)
#define CTSUSSC_MUTUAL1_KEY24           (CTSUSSDIV_MUTUAL1_KEY24 << 8)
#define CTSUSSC_MUTUAL1_KEY25           (CTSUSSDIV_MUTUAL1_KEY25 << 8)
#define CTSUSSC_MUTUAL1_KEY26           (CTSUSSDIV_MUTUAL1_KEY26 << 8)
#define CTSUSSC_MUTUAL1_KEY27           (CTSUSSDIV_MUTUAL1_KEY27 << 8)
#define CTSUSSC_MUTUAL1_KEY28           (CTSUSSDIV_MUTUAL1_KEY28 << 8)
#define CTSUSSC_MUTUAL1_KEY29           (CTSUSSDIV_MUTUAL1_KEY29 << 8)
#define CTSUSSC_MUTUAL1_KEY30           (CTSUSSDIV_MUTUAL1_KEY30 << 8)
#define CTSUSSC_MUTUAL1_KEY31           (CTSUSSDIV_MUTUAL1_KEY31 << 8)
#define CTSUSSC_MUTUAL1_KEY32           (CTSUSSDIV_MUTUAL1_KEY32 << 8)
#define CTSUSSC_MUTUAL1_KEY33           (CTSUSSDIV_MUTUAL1_KEY33 << 8)
#define CTSUSSC_MUTUAL1_KEY34           (CTSUSSDIV_MUTUAL1_KEY34 << 8)
#define CTSUSSC_MUTUAL1_KEY35           (CTSUSSDIV_MUTUAL1_KEY35 << 8)
#define CTSUSSC_MUTUAL1_KEY36           (CTSUSSDIV_MUTUAL1_KEY36 << 8)
#define CTSUSSC_MUTUAL1_KEY37           (CTSUSSDIV_MUTUAL1_KEY37 << 8)
#define CTSUSSC_MUTUAL1_KEY38           (CTSUSSDIV_MUTUAL1_KEY38 << 8)
#define CTSUSSC_MUTUAL1_KEY39           (CTSUSSDIV_MUTUAL1_KEY39 << 8)
#define CTSUSSC_MUTUAL1_KEY40           (CTSUSSDIV_MUTUAL1_KEY40 << 8)
#define CTSUSSC_MUTUAL1_KEY41           (CTSUSSDIV_MUTUAL1_KEY41 << 8)
#define CTSUSSC_MUTUAL1_KEY42           (CTSUSSDIV_MUTUAL1_KEY42 << 8)
#define CTSUSSC_MUTUAL1_KEY43           (CTSUSSDIV_MUTUAL1_KEY43 << 8)
#define CTSUSSC_MUTUAL1_KEY44           (CTSUSSDIV_MUTUAL1_KEY44 << 8)
#define CTSUSSC_MUTUAL1_KEY45           (CTSUSSDIV_MUTUAL1_KEY45 << 8)
#define CTSUSSC_MUTUAL1_KEY46           (CTSUSSDIV_MUTUAL1_KEY46 << 8)
#define CTSUSSC_MUTUAL1_KEY47           (CTSUSSDIV_MUTUAL1_KEY47 << 8)
#define CTSUSSC_MUTUAL1_KEY48           (CTSUSSDIV_MUTUAL1_KEY48 << 8)
#define CTSUSSC_MUTUAL1_KEY49           (CTSUSSDIV_MUTUAL1_KEY49 << 8)
#define CTSUSSC_MUTUAL1_KEY50           (CTSUSSDIV_MUTUAL1_KEY50 << 8)
#define CTSUSSC_MUTUAL1_KEY51           (CTSUSSDIV_MUTUAL1_KEY51 << 8)
#define CTSUSSC_MUTUAL1_KEY52           (CTSUSSDIV_MUTUAL1_KEY52 << 8)
#define CTSUSSC_MUTUAL1_KEY53           (CTSUSSDIV_MUTUAL1_KEY53 << 8)
#define CTSUSSC_MUTUAL1_KEY54           (CTSUSSDIV_MUTUAL1_KEY54 << 8)
#define CTSUSSC_MUTUAL1_KEY55           (CTSUSSDIV_MUTUAL1_KEY55 << 8)
#define CTSUSSC_MUTUAL1_KEY56           (CTSUSSDIV_MUTUAL1_KEY56 << 8)
#define CTSUSSC_MUTUAL1_KEY57           (CTSUSSDIV_MUTUAL1_KEY57 << 8)
#define CTSUSSC_MUTUAL1_KEY58           (CTSUSSDIV_MUTUAL1_KEY58 << 8)
#define CTSUSSC_MUTUAL1_KEY59           (CTSUSSDIV_MUTUAL1_KEY59 << 8)
#define CTSUSSC_MUTUAL1_KEY60           (CTSUSSDIV_MUTUAL1_KEY60 << 8)
#define CTSUSSC_MUTUAL1_KEY61           (CTSUSSDIV_MUTUAL1_KEY61 << 8)
#define CTSUSSC_MUTUAL1_KEY62           (CTSUSSDIV_MUTUAL1_KEY62 << 8)
#define CTSUSSC_MUTUAL1_KEY63           (CTSUSSDIV_MUTUAL1_KEY63 << 8)

/*****    Address 000A 0914h CTSU Sensor Offset Register 0     ********************************************************/
/**********************************************************************************************************************/
/*    CTSU Sensor Offset Adjustment                                                                                   */
/*      Current offset amount is 0       0x000                                                                        */
/*      Current offset amount is 1       0x001                                                                        */
/*      Current offset amount is 2       0x002                                                                        */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*      Current offset amount is 1023    0x3FF                                                                        */
/**********************************************************************************************************************/
#define CTSUSO_MUTUAL1_KEY00            (0x000)                 /* Mutual 1 Key00 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY01            (0x000)                 /* Mutual 1 Key01 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY02            (0x000)                 /* Mutual 1 Key02 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY03            (0x000)                 /* Mutual 1 Key03 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY04            (0x000)                 /* Mutual 1 Key04 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY05            (0x000)                 /* Mutual 1 Key05 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY06            (0x000)                 /* Mutual 1 Key06 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY07            (0x000)                 /* Mutual 1 Key07 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY08            (0x000)                 /* Mutual 1 Key08 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY09            (0x000)                 /* Mutual 1 Key09 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY10            (0x000)                 /* Mutual 1 Key10 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY11            (0x000)                 /* Mutual 1 Key11 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY12            (0x000)                 /* Mutual 1 Key12 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY13            (0x000)                 /* Mutual 1 Key13 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY14            (0x000)                 /* Mutual 1 Key14 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY15            (0x000)                 /* Mutual 1 Key15 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY16            (0x000)                 /* Mutual 1 Key16 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY17            (0x000)                 /* Mutual 1 Key17 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY18            (0x000)                 /* Mutual 1 Key18 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY19            (0x000)                 /* Mutual 1 Key19 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY20            (0x000)                 /* Mutual 1 Key20 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY21            (0x000)                 /* Mutual 1 Key21 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY22            (0x000)                 /* Mutual 1 Key22 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY23            (0x000)                 /* Mutual 1 Key23 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY24            (0x000)                 /* Mutual 1 Key24 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY25            (0x000)                 /* Mutual 1 Key25 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY26            (0x000)                 /* Mutual 1 Key26 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY27            (0x000)                 /* Mutual 1 Key27 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY28            (0x000)                 /* Mutual 1 Key28 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY29            (0x000)                 /* Mutual 1 Key29 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY30            (0x000)                 /* Mutual 1 Key30 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY31            (0x000)                 /* Mutual 1 Key31 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY32            (0x000)                 /* Mutual 1 Key32 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY33            (0x000)                 /* Mutual 1 Key33 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY34            (0x000)                 /* Mutual 1 Key34 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY35            (0x000)                 /* Mutual 1 Key35 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY36            (0x000)                 /* Mutual 1 Key36 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY37            (0x000)                 /* Mutual 1 Key37 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY38            (0x000)                 /* Mutual 1 Key38 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY39            (0x000)                 /* Mutual 1 Key39 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY40            (0x000)                 /* Mutual 1 Key40 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY41            (0x000)                 /* Mutual 1 Key41 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY42            (0x000)                 /* Mutual 1 Key42 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY43            (0x000)                 /* Mutual 1 Key43 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY44            (0x000)                 /* Mutual 1 Key44 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY45            (0x000)                 /* Mutual 1 Key45 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY46            (0x000)                 /* Mutual 1 Key46 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY47            (0x000)                 /* Mutual 1 Key47 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY48            (0x000)                 /* Mutual 1 Key48 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY49            (0x000)                 /* Mutual 1 Key49 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY50            (0x000)                 /* Mutual 1 Key50 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY51            (0x000)                 /* Mutual 1 Key51 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY52            (0x000)                 /* Mutual 1 Key52 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY53            (0x000)                 /* Mutual 1 Key53 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY54            (0x000)                 /* Mutual 1 Key54 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY55            (0x000)                 /* Mutual 1 Key55 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY56            (0x000)                 /* Mutual 1 Key56 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY57            (0x000)                 /* Mutual 1 Key57 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY58            (0x000)                 /* Mutual 1 Key58 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY59            (0x000)                 /* Mutual 1 Key59 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY60            (0x000)                 /* Mutual 1 Key60 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY61            (0x000)                 /* Mutual 1 Key61 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY62            (0x000)                 /* Mutual 1 Key62 CTSUSO                              */
#define CTSUSO_MUTUAL1_KEY63            (0x000)                 /* Mutual 1 Key63 CTSUSO                              */

/**********************************************************************************************************************/
/*    CTSU Measurement Count Setting                                                                                  */
/*      4.0MHz    7                                                                                                   */
/*      2.0MHz    3                                                                                                   */
/*      1.0MHz    1                                                                                                   */
/*      0.5MHz    0                                                                                                   */
/**********************************************************************************************************************/
#define CTSUSNUM_MUTUAL1_KEY00          (3)                     /* Mutual 1 Key00 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY01          (3)                     /* Mutual 1 Key01 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY02          (3)                     /* Mutual 1 Key02 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY03          (3)                     /* Mutual 1 Key03 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY04          (3)                     /* Mutual 1 Key04 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY05          (3)                     /* Mutual 1 Key05 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY06          (3)                     /* Mutual 1 Key06 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY07          (3)                     /* Mutual 1 Key07 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY08          (3)                     /* Mutual 1 Key08 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY09          (3)                     /* Mutual 1 Key09 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY10          (3)                     /* Mutual 1 Key10 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY11          (3)                     /* Mutual 1 Key11 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY12          (3)                     /* Mutual 1 Key12 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY13          (3)                     /* Mutual 1 Key13 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY14          (3)                     /* Mutual 1 Key14 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY15          (3)                     /* Mutual 1 Key15 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY16          (3)                     /* Mutual 1 Key16 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY17          (3)                     /* Mutual 1 Key17 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY18          (3)                     /* Mutual 1 Key18 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY19          (3)                     /* Mutual 1 Key19 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY20          (3)                     /* Mutual 1 Key20 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY21          (3)                     /* Mutual 1 Key21 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY22          (3)                     /* Mutual 1 Key22 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY23          (3)                     /* Mutual 1 Key23 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY24          (3)                     /* Mutual 1 Key24 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY25          (3)                     /* Mutual 1 Key25 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY26          (3)                     /* Mutual 1 Key26 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY27          (3)                     /* Mutual 1 Key27 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY28          (3)                     /* Mutual 1 Key28 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY29          (3)                     /* Mutual 1 Key29 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY30          (3)                     /* Mutual 1 Key30 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY31          (3)                     /* Mutual 1 Key31 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY32          (3)                     /* Mutual 1 Key32 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY33          (3)                     /* Mutual 1 Key33 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY34          (3)                     /* Mutual 1 Key34 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY35          (3)                     /* Mutual 1 Key35 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY36          (3)                     /* Mutual 1 Key36 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY37          (3)                     /* Mutual 1 Key37 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY38          (3)                     /* Mutual 1 Key38 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY39          (3)                     /* Mutual 1 Key39 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY40          (3)                     /* Mutual 1 Key40 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY41          (3)                     /* Mutual 1 Key41 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY42          (3)                     /* Mutual 1 Key42 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY43          (3)                     /* Mutual 1 Key43 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY44          (3)                     /* Mutual 1 Key44 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY45          (3)                     /* Mutual 1 Key45 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY46          (3)                     /* Mutual 1 Key46 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY47          (3)                     /* Mutual 1 Key47 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY48          (3)                     /* Mutual 1 Key48 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY49          (3)                     /* Mutual 1 Key49 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY50          (3)                     /* Mutual 1 Key50 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY51          (3)                     /* Mutual 1 Key51 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY52          (3)                     /* Mutual 1 Key52 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY53          (3)                     /* Mutual 1 Key53 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY54          (3)                     /* Mutual 1 Key54 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY55          (3)                     /* Mutual 1 Key55 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY56          (3)                     /* Mutual 1 Key56 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY57          (3)                     /* Mutual 1 Key57 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY58          (3)                     /* Mutual 1 Key58 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY59          (3)                     /* Mutual 1 Key59 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY60          (3)                     /* Mutual 1 Key60 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY61          (3)                     /* Mutual 1 Key61 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY62          (3)                     /* Mutual 1 Key62 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL1_KEY63          (3)                     /* Mutual 1 Key63 CTSUSNUM                            */

#define CTSUSO0_MUTUAL1_KEY00           ((CTSUSNUM_MUTUAL1_KEY00 << 10) | CTSUSO_MUTUAL1_KEY00)
#define CTSUSO0_MUTUAL1_KEY01           ((CTSUSNUM_MUTUAL1_KEY01 << 10) | CTSUSO_MUTUAL1_KEY01)
#define CTSUSO0_MUTUAL1_KEY02           ((CTSUSNUM_MUTUAL1_KEY02 << 10) | CTSUSO_MUTUAL1_KEY02)
#define CTSUSO0_MUTUAL1_KEY03           ((CTSUSNUM_MUTUAL1_KEY03 << 10) | CTSUSO_MUTUAL1_KEY03)
#define CTSUSO0_MUTUAL1_KEY04           ((CTSUSNUM_MUTUAL1_KEY04 << 10) | CTSUSO_MUTUAL1_KEY04)
#define CTSUSO0_MUTUAL1_KEY05           ((CTSUSNUM_MUTUAL1_KEY05 << 10) | CTSUSO_MUTUAL1_KEY05)
#define CTSUSO0_MUTUAL1_KEY06           ((CTSUSNUM_MUTUAL1_KEY06 << 10) | CTSUSO_MUTUAL1_KEY06)
#define CTSUSO0_MUTUAL1_KEY07           ((CTSUSNUM_MUTUAL1_KEY07 << 10) | CTSUSO_MUTUAL1_KEY07)
#define CTSUSO0_MUTUAL1_KEY08           ((CTSUSNUM_MUTUAL1_KEY08 << 10) | CTSUSO_MUTUAL1_KEY08)
#define CTSUSO0_MUTUAL1_KEY09           ((CTSUSNUM_MUTUAL1_KEY09 << 10) | CTSUSO_MUTUAL1_KEY09)
#define CTSUSO0_MUTUAL1_KEY10           ((CTSUSNUM_MUTUAL1_KEY10 << 10) | CTSUSO_MUTUAL1_KEY10)
#define CTSUSO0_MUTUAL1_KEY11           ((CTSUSNUM_MUTUAL1_KEY11 << 10) | CTSUSO_MUTUAL1_KEY11)
#define CTSUSO0_MUTUAL1_KEY12           ((CTSUSNUM_MUTUAL1_KEY12 << 10) | CTSUSO_MUTUAL1_KEY12)
#define CTSUSO0_MUTUAL1_KEY13           ((CTSUSNUM_MUTUAL1_KEY13 << 10) | CTSUSO_MUTUAL1_KEY13)
#define CTSUSO0_MUTUAL1_KEY14           ((CTSUSNUM_MUTUAL1_KEY14 << 10) | CTSUSO_MUTUAL1_KEY14)
#define CTSUSO0_MUTUAL1_KEY15           ((CTSUSNUM_MUTUAL1_KEY15 << 10) | CTSUSO_MUTUAL1_KEY15)
#define CTSUSO0_MUTUAL1_KEY16           ((CTSUSNUM_MUTUAL1_KEY16 << 10) | CTSUSO_MUTUAL1_KEY16)
#define CTSUSO0_MUTUAL1_KEY17           ((CTSUSNUM_MUTUAL1_KEY17 << 10) | CTSUSO_MUTUAL1_KEY17)
#define CTSUSO0_MUTUAL1_KEY18           ((CTSUSNUM_MUTUAL1_KEY18 << 10) | CTSUSO_MUTUAL1_KEY18)
#define CTSUSO0_MUTUAL1_KEY19           ((CTSUSNUM_MUTUAL1_KEY19 << 10) | CTSUSO_MUTUAL1_KEY19)
#define CTSUSO0_MUTUAL1_KEY20           ((CTSUSNUM_MUTUAL1_KEY20 << 10) | CTSUSO_MUTUAL1_KEY20)
#define CTSUSO0_MUTUAL1_KEY21           ((CTSUSNUM_MUTUAL1_KEY21 << 10) | CTSUSO_MUTUAL1_KEY21)
#define CTSUSO0_MUTUAL1_KEY22           ((CTSUSNUM_MUTUAL1_KEY22 << 10) | CTSUSO_MUTUAL1_KEY22)
#define CTSUSO0_MUTUAL1_KEY23           ((CTSUSNUM_MUTUAL1_KEY23 << 10) | CTSUSO_MUTUAL1_KEY23)
#define CTSUSO0_MUTUAL1_KEY24           ((CTSUSNUM_MUTUAL1_KEY24 << 10) | CTSUSO_MUTUAL1_KEY24)
#define CTSUSO0_MUTUAL1_KEY25           ((CTSUSNUM_MUTUAL1_KEY25 << 10) | CTSUSO_MUTUAL1_KEY25)
#define CTSUSO0_MUTUAL1_KEY26           ((CTSUSNUM_MUTUAL1_KEY26 << 10) | CTSUSO_MUTUAL1_KEY26)
#define CTSUSO0_MUTUAL1_KEY27           ((CTSUSNUM_MUTUAL1_KEY27 << 10) | CTSUSO_MUTUAL1_KEY27)
#define CTSUSO0_MUTUAL1_KEY28           ((CTSUSNUM_MUTUAL1_KEY28 << 10) | CTSUSO_MUTUAL1_KEY28)
#define CTSUSO0_MUTUAL1_KEY29           ((CTSUSNUM_MUTUAL1_KEY29 << 10) | CTSUSO_MUTUAL1_KEY29)
#define CTSUSO0_MUTUAL1_KEY30           ((CTSUSNUM_MUTUAL1_KEY30 << 10) | CTSUSO_MUTUAL1_KEY30)
#define CTSUSO0_MUTUAL1_KEY31           ((CTSUSNUM_MUTUAL1_KEY31 << 10) | CTSUSO_MUTUAL1_KEY31)
#define CTSUSO0_MUTUAL1_KEY32           ((CTSUSNUM_MUTUAL1_KEY32 << 10) | CTSUSO_MUTUAL1_KEY32)
#define CTSUSO0_MUTUAL1_KEY33           ((CTSUSNUM_MUTUAL1_KEY33 << 10) | CTSUSO_MUTUAL1_KEY33)
#define CTSUSO0_MUTUAL1_KEY34           ((CTSUSNUM_MUTUAL1_KEY34 << 10) | CTSUSO_MUTUAL1_KEY34)
#define CTSUSO0_MUTUAL1_KEY35           ((CTSUSNUM_MUTUAL1_KEY35 << 10) | CTSUSO_MUTUAL1_KEY35)
#define CTSUSO0_MUTUAL1_KEY36           ((CTSUSNUM_MUTUAL1_KEY36 << 10) | CTSUSO_MUTUAL1_KEY36)
#define CTSUSO0_MUTUAL1_KEY37           ((CTSUSNUM_MUTUAL1_KEY37 << 10) | CTSUSO_MUTUAL1_KEY37)
#define CTSUSO0_MUTUAL1_KEY38           ((CTSUSNUM_MUTUAL1_KEY38 << 10) | CTSUSO_MUTUAL1_KEY38)
#define CTSUSO0_MUTUAL1_KEY39           ((CTSUSNUM_MUTUAL1_KEY39 << 10) | CTSUSO_MUTUAL1_KEY39)
#define CTSUSO0_MUTUAL1_KEY40           ((CTSUSNUM_MUTUAL1_KEY40 << 10) | CTSUSO_MUTUAL1_KEY40)
#define CTSUSO0_MUTUAL1_KEY41           ((CTSUSNUM_MUTUAL1_KEY41 << 10) | CTSUSO_MUTUAL1_KEY41)
#define CTSUSO0_MUTUAL1_KEY42           ((CTSUSNUM_MUTUAL1_KEY42 << 10) | CTSUSO_MUTUAL1_KEY42)
#define CTSUSO0_MUTUAL1_KEY43           ((CTSUSNUM_MUTUAL1_KEY43 << 10) | CTSUSO_MUTUAL1_KEY43)
#define CTSUSO0_MUTUAL1_KEY44           ((CTSUSNUM_MUTUAL1_KEY44 << 10) | CTSUSO_MUTUAL1_KEY44)
#define CTSUSO0_MUTUAL1_KEY45           ((CTSUSNUM_MUTUAL1_KEY45 << 10) | CTSUSO_MUTUAL1_KEY45)
#define CTSUSO0_MUTUAL1_KEY46           ((CTSUSNUM_MUTUAL1_KEY46 << 10) | CTSUSO_MUTUAL1_KEY46)
#define CTSUSO0_MUTUAL1_KEY47           ((CTSUSNUM_MUTUAL1_KEY47 << 10) | CTSUSO_MUTUAL1_KEY47)
#define CTSUSO0_MUTUAL1_KEY48           ((CTSUSNUM_MUTUAL1_KEY48 << 10) | CTSUSO_MUTUAL1_KEY48)
#define CTSUSO0_MUTUAL1_KEY49           ((CTSUSNUM_MUTUAL1_KEY49 << 10) | CTSUSO_MUTUAL1_KEY49)
#define CTSUSO0_MUTUAL1_KEY50           ((CTSUSNUM_MUTUAL1_KEY50 << 10) | CTSUSO_MUTUAL1_KEY50)
#define CTSUSO0_MUTUAL1_KEY51           ((CTSUSNUM_MUTUAL1_KEY51 << 10) | CTSUSO_MUTUAL1_KEY51)
#define CTSUSO0_MUTUAL1_KEY52           ((CTSUSNUM_MUTUAL1_KEY52 << 10) | CTSUSO_MUTUAL1_KEY52)
#define CTSUSO0_MUTUAL1_KEY53           ((CTSUSNUM_MUTUAL1_KEY53 << 10) | CTSUSO_MUTUAL1_KEY53)
#define CTSUSO0_MUTUAL1_KEY54           ((CTSUSNUM_MUTUAL1_KEY54 << 10) | CTSUSO_MUTUAL1_KEY54)
#define CTSUSO0_MUTUAL1_KEY55           ((CTSUSNUM_MUTUAL1_KEY55 << 10) | CTSUSO_MUTUAL1_KEY55)
#define CTSUSO0_MUTUAL1_KEY56           ((CTSUSNUM_MUTUAL1_KEY56 << 10) | CTSUSO_MUTUAL1_KEY56)
#define CTSUSO0_MUTUAL1_KEY57           ((CTSUSNUM_MUTUAL1_KEY57 << 10) | CTSUSO_MUTUAL1_KEY57)
#define CTSUSO0_MUTUAL1_KEY58           ((CTSUSNUM_MUTUAL1_KEY58 << 10) | CTSUSO_MUTUAL1_KEY58)
#define CTSUSO0_MUTUAL1_KEY59           ((CTSUSNUM_MUTUAL1_KEY59 << 10) | CTSUSO_MUTUAL1_KEY59)
#define CTSUSO0_MUTUAL1_KEY60           ((CTSUSNUM_MUTUAL1_KEY60 << 10) | CTSUSO_MUTUAL1_KEY60)
#define CTSUSO0_MUTUAL1_KEY61           ((CTSUSNUM_MUTUAL1_KEY61 << 10) | CTSUSO_MUTUAL1_KEY61)
#define CTSUSO0_MUTUAL1_KEY62           ((CTSUSNUM_MUTUAL1_KEY62 << 10) | CTSUSO_MUTUAL1_KEY62)
#define CTSUSO0_MUTUAL1_KEY63           ((CTSUSNUM_MUTUAL1_KEY63 << 10) | CTSUSO_MUTUAL1_KEY63)

/*****    Address 000A 0914h CTSU Sensor Offset Register 1    *********************************************************/
/**********************************************************************************************************************/
/*    CTSU Reference ICO Current Adjustment                                                                           */
/*        Input current amount 0      0x00                                                                            */
/*        Input current amount 1      0x01                                                                            */
/*        Input current amount 2      0x02                                                                            */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*        Input current amount 254    0xFF                                                                            */
/**********************************************************************************************************************/
#define CTSURICOA_MUTUAL1_KEY00         (0x3F)                  /* Mutual 1 Key00 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY01         (0x3F)                  /* Mutual 1 Key01 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY02         (0x3F)                  /* Mutual 1 Key02 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY03         (0x3F)                  /* Mutual 1 Key03 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY04         (0x3F)                  /* Mutual 1 Key04 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY05         (0x3F)                  /* Mutual 1 Key05 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY06         (0x3F)                  /* Mutual 1 Key06 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY07         (0x3F)                  /* Mutual 1 Key07 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY08         (0x3F)                  /* Mutual 1 Key08 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY09         (0x3F)                  /* Mutual 1 Key09 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY10         (0x3F)                  /* Mutual 1 Key10 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY11         (0x3F)                  /* Mutual 1 Key11 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY12         (0x3F)                  /* Mutual 1 Key12 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY13         (0x3F)                  /* Mutual 1 Key13 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY14         (0x3F)                  /* Mutual 1 Key14 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY15         (0x3F)                  /* Mutual 1 Key15 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY16         (0x3F)                  /* Mutual 1 Key16 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY17         (0x3F)                  /* Mutual 1 Key17 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY18         (0x3F)                  /* Mutual 1 Key18 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY19         (0x3F)                  /* Mutual 1 Key19 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY20         (0x3F)                  /* Mutual 1 Key20 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY21         (0x3F)                  /* Mutual 1 Key21 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY22         (0x3F)                  /* Mutual 1 Key22 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY23         (0x3F)                  /* Mutual 1 Key23 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY24         (0x3F)                  /* Mutual 1 Key24 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY25         (0x3F)                  /* Mutual 1 Key25 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY26         (0x3F)                  /* Mutual 1 Key26 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY27         (0x3F)                  /* Mutual 1 Key27 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY28         (0x3F)                  /* Mutual 1 Key28 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY29         (0x3F)                  /* Mutual 1 Key29 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY30         (0x3F)                  /* Mutual 1 Key30 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY31         (0x3F)                  /* Mutual 1 Key31 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY32         (0x3F)                  /* Mutual 1 Key32 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY33         (0x3F)                  /* Mutual 1 Key33 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY34         (0x3F)                  /* Mutual 1 Key34 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY35         (0x3F)                  /* Mutual 1 Key35 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY36         (0x3F)                  /* Mutual 1 Key36 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY37         (0x3F)                  /* Mutual 1 Key37 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY38         (0x3F)                  /* Mutual 1 Key38 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY39         (0x3F)                  /* Mutual 1 Key39 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY40         (0x3F)                  /* Mutual 1 Key40 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY41         (0x3F)                  /* Mutual 1 Key41 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY42         (0x3F)                  /* Mutual 1 Key42 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY43         (0x3F)                  /* Mutual 1 Key43 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY44         (0x3F)                  /* Mutual 1 Key44 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY45         (0x3F)                  /* Mutual 1 Key45 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY46         (0x3F)                  /* Mutual 1 Key46 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY47         (0x3F)                  /* Mutual 1 Key47 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY48         (0x3F)                  /* Mutual 1 Key48 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY49         (0x3F)                  /* Mutual 1 Key49 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY50         (0x3F)                  /* Mutual 1 Key50 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY51         (0x3F)                  /* Mutual 1 Key51 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY52         (0x3F)                  /* Mutual 1 Key52 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY53         (0x3F)                  /* Mutual 1 Key53 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY54         (0x3F)                  /* Mutual 1 Key54 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY55         (0x3F)                  /* Mutual 1 Key55 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY56         (0x3F)                  /* Mutual 1 Key56 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY57         (0x3F)                  /* Mutual 1 Key57 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY58         (0x3F)                  /* Mutual 1 Key58 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY59         (0x3F)                  /* Mutual 1 Key59 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY60         (0x3F)                  /* Mutual 1 Key60 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY61         (0x3F)                  /* Mutual 1 Key61 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY62         (0x3F)                  /* Mutual 1 Key62 CTSUICOA                            */
#define CTSURICOA_MUTUAL1_KEY63         (0x3F)                  /* Mutual 1 Key63 CTSUICOA                            */

/**********************************************************************************************************************/
/*    CTSU Base Clock Setting                                                                                         */
/*        Operating clock divided by 2     0x00                                                                       */
/*        Operating clock divided by 4     0x01                                                                       */
/*        Operating clock divided by 6     0x02                                                                       */
/*                       :                                                                                            */
/*                       :                                                                                            */
/*        Operating clock divided by 64    0x1F                                                                       */
/*                                                                                                                    */
/*    Case : CTSU Operating Clock 32MHz      Case : CTSU Operating Clock 24MHz      Case : CTSU Operating Clock 16MHz */
/*           4.0MHz <--- 0x03                       4.0MHz <--- 0x02                       4.0MHz <--- 0x01           */
/*           2.0MHz <--- 0x07                       2.0MHz <--- 0x05                       2.0MHz <--- 0x03           */
/*           1.0MHz <--- 0x0F                       1.0MHz <--- 0x0B                       1.0MHz <--- 0x07           */
/*           0.5MHz <--- 0x1F                       0.5MHz <--- 0x17                       0.5MHz <--- 0x0F           */
/**********************************************************************************************************************/
#define CTSUSDPA_MUTUAL1_KEY00          (7)                     /* Mutual 1 Key00 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY01          (7)                     /* Mutual 1 Key01 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY02          (7)                     /* Mutual 1 Key02 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY03          (7)                     /* Mutual 1 Key03 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY04          (7)                     /* Mutual 1 Key04 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY05          (7)                     /* Mutual 1 Key05 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY06          (7)                     /* Mutual 1 Key06 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY07          (7)                     /* Mutual 1 Key07 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY08          (7)                     /* Mutual 1 Key08 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY09          (7)                     /* Mutual 1 Key09 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY10          (7)                     /* Mutual 1 Key10 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY11          (7)                     /* Mutual 1 Key11 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY12          (7)                     /* Mutual 1 Key12 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY13          (7)                     /* Mutual 1 Key13 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY14          (7)                     /* Mutual 1 Key14 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY15          (7)                     /* Mutual 1 Key15 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY16          (7)                     /* Mutual 1 Key16 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY17          (7)                     /* Mutual 1 Key17 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY18          (7)                     /* Mutual 1 Key18 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY19          (7)                     /* Mutual 1 Key19 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY20          (7)                     /* Mutual 1 Key20 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY21          (7)                     /* Mutual 1 Key21 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY22          (7)                     /* Mutual 1 Key22 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY23          (7)                     /* Mutual 1 Key23 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY24          (7)                     /* Mutual 1 Key24 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY25          (7)                     /* Mutual 1 Key25 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY26          (7)                     /* Mutual 1 Key26 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY27          (7)                     /* Mutual 1 Key27 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY28          (7)                     /* Mutual 1 Key28 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY29          (7)                     /* Mutual 1 Key29 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY30          (7)                     /* Mutual 1 Key30 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY31          (7)                     /* Mutual 1 Key31 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY32          (7)                     /* Mutual 1 Key32 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY33          (7)                     /* Mutual 1 Key33 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY34          (7)                     /* Mutual 1 Key34 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY35          (7)                     /* Mutual 1 Key35 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY36          (7)                     /* Mutual 1 Key36 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY37          (7)                     /* Mutual 1 Key37 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY38          (7)                     /* Mutual 1 Key38 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY39          (7)                     /* Mutual 1 Key39 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY40          (7)                     /* Mutual 1 Key40 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY41          (7)                     /* Mutual 1 Key41 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY42          (7)                     /* Mutual 1 Key42 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY43          (7)                     /* Mutual 1 Key43 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY44          (7)                     /* Mutual 1 Key44 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY45          (7)                     /* Mutual 1 Key45 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY46          (7)                     /* Mutual 1 Key46 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY47          (7)                     /* Mutual 1 Key47 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY48          (7)                     /* Mutual 1 Key48 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY49          (7)                     /* Mutual 1 Key49 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY50          (7)                     /* Mutual 1 Key50 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY51          (7)                     /* Mutual 1 Key51 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY52          (7)                     /* Mutual 1 Key52 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY53          (7)                     /* Mutual 1 Key53 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY54          (7)                     /* Mutual 1 Key54 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY55          (7)                     /* Mutual 1 Key55 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY56          (7)                     /* Mutual 1 Key56 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY57          (7)                     /* Mutual 1 Key57 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY58          (7)                     /* Mutual 1 Key58 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY59          (7)                     /* Mutual 1 Key59 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY60          (7)                     /* Mutual 1 Key60 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY61          (7)                     /* Mutual 1 Key61 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY62          (7)                     /* Mutual 1 Key62 CTSUDPA                             */
#define CTSUSDPA_MUTUAL1_KEY63          (7)                     /* Mutual 1 Key63 CTSUDPA                             */

/**********************************************************************************************************************/
/*    CTSU ICO Gain Adjustment                                                                                        */
/*        0 : 100% gain                                                                                               */
/*        1 :  66% gain                                                                                               */
/*        2 :  50% gain                                                                                               */
/*        3 :  40% gain                                                                                               */
/**********************************************************************************************************************/
#define CTSUICOG_MUTUAL1_KEY00          (1)                     /* Mutual 1 Key00 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY01          (1)                     /* Mutual 1 Key01 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY02          (1)                     /* Mutual 1 Key02 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY03          (1)                     /* Mutual 1 Key03 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY04          (1)                     /* Mutual 1 Key04 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY05          (1)                     /* Mutual 1 Key05 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY06          (1)                     /* Mutual 1 Key06 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY07          (1)                     /* Mutual 1 Key07 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY08          (1)                     /* Mutual 1 Key08 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY09          (1)                     /* Mutual 1 Key09 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY10          (1)                     /* Mutual 1 Key10 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY11          (1)                     /* Mutual 1 Key11 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY12          (1)                     /* Mutual 1 Key12 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY13          (1)                     /* Mutual 1 Key13 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY14          (1)                     /* Mutual 1 Key14 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY15          (1)                     /* Mutual 1 Key15 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY16          (1)                     /* Mutual 1 Key16 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY17          (1)                     /* Mutual 1 Key17 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY18          (1)                     /* Mutual 1 Key18 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY19          (1)                     /* Mutual 1 Key19 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY20          (1)                     /* Mutual 1 Key20 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY21          (1)                     /* Mutual 1 Key21 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY22          (1)                     /* Mutual 1 Key22 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY23          (1)                     /* Mutual 1 Key23 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY24          (1)                     /* Mutual 1 Key24 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY25          (1)                     /* Mutual 1 Key25 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY26          (1)                     /* Mutual 1 Key26 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY27          (1)                     /* Mutual 1 Key27 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY28          (1)                     /* Mutual 1 Key28 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY29          (1)                     /* Mutual 1 Key29 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY30          (1)                     /* Mutual 1 Key30 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY31          (1)                     /* Mutual 1 Key31 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY32          (1)                     /* Mutual 1 Key32 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY33          (1)                     /* Mutual 1 Key33 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY34          (1)                     /* Mutual 1 Key34 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY35          (1)                     /* Mutual 1 Key35 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY36          (1)                     /* Mutual 1 Key36 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY37          (1)                     /* Mutual 1 Key37 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY38          (1)                     /* Mutual 1 Key38 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY39          (1)                     /* Mutual 1 Key39 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY40          (1)                     /* Mutual 1 Key40 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY41          (1)                     /* Mutual 1 Key41 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY42          (1)                     /* Mutual 1 Key42 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY43          (1)                     /* Mutual 1 Key43 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY44          (1)                     /* Mutual 1 Key44 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY45          (1)                     /* Mutual 1 Key45 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY46          (1)                     /* Mutual 1 Key46 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY47          (1)                     /* Mutual 1 Key47 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY48          (1)                     /* Mutual 1 Key48 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY49          (1)                     /* Mutual 1 Key49 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY50          (1)                     /* Mutual 1 Key50 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY51          (1)                     /* Mutual 1 Key51 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY52          (1)                     /* Mutual 1 Key52 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY53          (1)                     /* Mutual 1 Key53 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY54          (1)                     /* Mutual 1 Key54 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY55          (1)                     /* Mutual 1 Key55 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY56          (1)                     /* Mutual 1 Key56 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY57          (1)                     /* Mutual 1 Key57 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY58          (1)                     /* Mutual 1 Key58 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY59          (1)                     /* Mutual 1 Key59 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY60          (1)                     /* Mutual 1 Key60 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY61          (1)                     /* Mutual 1 Key61 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY62          (1)                     /* Mutual 1 Key62 CTSICOG                             */
#define CTSUICOG_MUTUAL1_KEY63          (1)                     /* Mutual 1 Key63 CTSICOG                             */

#define CTSUSO1_MUTUAL1_KEY00  ((CTSUICOG_MUTUAL1_KEY00 << 13) | (CTSUSDPA_MUTUAL1_KEY00 << 8) | CTSURICOA_MUTUAL1_KEY00)
#define CTSUSO1_MUTUAL1_KEY01  ((CTSUICOG_MUTUAL1_KEY01 << 13) | (CTSUSDPA_MUTUAL1_KEY01 << 8) | CTSURICOA_MUTUAL1_KEY01)
#define CTSUSO1_MUTUAL1_KEY02  ((CTSUICOG_MUTUAL1_KEY02 << 13) | (CTSUSDPA_MUTUAL1_KEY02 << 8) | CTSURICOA_MUTUAL1_KEY02)
#define CTSUSO1_MUTUAL1_KEY03  ((CTSUICOG_MUTUAL1_KEY03 << 13) | (CTSUSDPA_MUTUAL1_KEY03 << 8) | CTSURICOA_MUTUAL1_KEY03)
#define CTSUSO1_MUTUAL1_KEY04  ((CTSUICOG_MUTUAL1_KEY04 << 13) | (CTSUSDPA_MUTUAL1_KEY04 << 8) | CTSURICOA_MUTUAL1_KEY04)
#define CTSUSO1_MUTUAL1_KEY05  ((CTSUICOG_MUTUAL1_KEY05 << 13) | (CTSUSDPA_MUTUAL1_KEY05 << 8) | CTSURICOA_MUTUAL1_KEY05)
#define CTSUSO1_MUTUAL1_KEY06  ((CTSUICOG_MUTUAL1_KEY06 << 13) | (CTSUSDPA_MUTUAL1_KEY06 << 8) | CTSURICOA_MUTUAL1_KEY06)
#define CTSUSO1_MUTUAL1_KEY07  ((CTSUICOG_MUTUAL1_KEY07 << 13) | (CTSUSDPA_MUTUAL1_KEY07 << 8) | CTSURICOA_MUTUAL1_KEY07)
#define CTSUSO1_MUTUAL1_KEY08  ((CTSUICOG_MUTUAL1_KEY08 << 13) | (CTSUSDPA_MUTUAL1_KEY08 << 8) | CTSURICOA_MUTUAL1_KEY08)
#define CTSUSO1_MUTUAL1_KEY09  ((CTSUICOG_MUTUAL1_KEY09 << 13) | (CTSUSDPA_MUTUAL1_KEY09 << 8) | CTSURICOA_MUTUAL1_KEY09)
#define CTSUSO1_MUTUAL1_KEY10  ((CTSUICOG_MUTUAL1_KEY10 << 13) | (CTSUSDPA_MUTUAL1_KEY10 << 8) | CTSURICOA_MUTUAL1_KEY10)
#define CTSUSO1_MUTUAL1_KEY11  ((CTSUICOG_MUTUAL1_KEY11 << 13) | (CTSUSDPA_MUTUAL1_KEY11 << 8) | CTSURICOA_MUTUAL1_KEY11)
#define CTSUSO1_MUTUAL1_KEY12  ((CTSUICOG_MUTUAL1_KEY12 << 13) | (CTSUSDPA_MUTUAL1_KEY12 << 8) | CTSURICOA_MUTUAL1_KEY12)
#define CTSUSO1_MUTUAL1_KEY13  ((CTSUICOG_MUTUAL1_KEY13 << 13) | (CTSUSDPA_MUTUAL1_KEY13 << 8) | CTSURICOA_MUTUAL1_KEY13)
#define CTSUSO1_MUTUAL1_KEY14  ((CTSUICOG_MUTUAL1_KEY14 << 13) | (CTSUSDPA_MUTUAL1_KEY14 << 8) | CTSURICOA_MUTUAL1_KEY14)
#define CTSUSO1_MUTUAL1_KEY15  ((CTSUICOG_MUTUAL1_KEY15 << 13) | (CTSUSDPA_MUTUAL1_KEY15 << 8) | CTSURICOA_MUTUAL1_KEY15)
#define CTSUSO1_MUTUAL1_KEY16  ((CTSUICOG_MUTUAL1_KEY16 << 13) | (CTSUSDPA_MUTUAL1_KEY16 << 8) | CTSURICOA_MUTUAL1_KEY16)
#define CTSUSO1_MUTUAL1_KEY17  ((CTSUICOG_MUTUAL1_KEY17 << 13) | (CTSUSDPA_MUTUAL1_KEY17 << 8) | CTSURICOA_MUTUAL1_KEY17)
#define CTSUSO1_MUTUAL1_KEY18  ((CTSUICOG_MUTUAL1_KEY18 << 13) | (CTSUSDPA_MUTUAL1_KEY18 << 8) | CTSURICOA_MUTUAL1_KEY18)
#define CTSUSO1_MUTUAL1_KEY19  ((CTSUICOG_MUTUAL1_KEY19 << 13) | (CTSUSDPA_MUTUAL1_KEY19 << 8) | CTSURICOA_MUTUAL1_KEY19)
#define CTSUSO1_MUTUAL1_KEY20  ((CTSUICOG_MUTUAL1_KEY20 << 13) | (CTSUSDPA_MUTUAL1_KEY20 << 8) | CTSURICOA_MUTUAL1_KEY20)
#define CTSUSO1_MUTUAL1_KEY21  ((CTSUICOG_MUTUAL1_KEY21 << 13) | (CTSUSDPA_MUTUAL1_KEY21 << 8) | CTSURICOA_MUTUAL1_KEY21)
#define CTSUSO1_MUTUAL1_KEY22  ((CTSUICOG_MUTUAL1_KEY22 << 13) | (CTSUSDPA_MUTUAL1_KEY22 << 8) | CTSURICOA_MUTUAL1_KEY22)
#define CTSUSO1_MUTUAL1_KEY23  ((CTSUICOG_MUTUAL1_KEY23 << 13) | (CTSUSDPA_MUTUAL1_KEY23 << 8) | CTSURICOA_MUTUAL1_KEY23)
#define CTSUSO1_MUTUAL1_KEY24  ((CTSUICOG_MUTUAL1_KEY24 << 13) | (CTSUSDPA_MUTUAL1_KEY24 << 8) | CTSURICOA_MUTUAL1_KEY24)
#define CTSUSO1_MUTUAL1_KEY25  ((CTSUICOG_MUTUAL1_KEY25 << 13) | (CTSUSDPA_MUTUAL1_KEY25 << 8) | CTSURICOA_MUTUAL1_KEY25)
#define CTSUSO1_MUTUAL1_KEY26  ((CTSUICOG_MUTUAL1_KEY26 << 13) | (CTSUSDPA_MUTUAL1_KEY26 << 8) | CTSURICOA_MUTUAL1_KEY26)
#define CTSUSO1_MUTUAL1_KEY27  ((CTSUICOG_MUTUAL1_KEY27 << 13) | (CTSUSDPA_MUTUAL1_KEY27 << 8) | CTSURICOA_MUTUAL1_KEY27)
#define CTSUSO1_MUTUAL1_KEY28  ((CTSUICOG_MUTUAL1_KEY28 << 13) | (CTSUSDPA_MUTUAL1_KEY28 << 8) | CTSURICOA_MUTUAL1_KEY28)
#define CTSUSO1_MUTUAL1_KEY29  ((CTSUICOG_MUTUAL1_KEY29 << 13) | (CTSUSDPA_MUTUAL1_KEY29 << 8) | CTSURICOA_MUTUAL1_KEY29)
#define CTSUSO1_MUTUAL1_KEY30  ((CTSUICOG_MUTUAL1_KEY30 << 13) | (CTSUSDPA_MUTUAL1_KEY30 << 8) | CTSURICOA_MUTUAL1_KEY30)
#define CTSUSO1_MUTUAL1_KEY31  ((CTSUICOG_MUTUAL1_KEY31 << 13) | (CTSUSDPA_MUTUAL1_KEY31 << 8) | CTSURICOA_MUTUAL1_KEY31)
#define CTSUSO1_MUTUAL1_KEY32  ((CTSUICOG_MUTUAL1_KEY32 << 13) | (CTSUSDPA_MUTUAL1_KEY32 << 8) | CTSURICOA_MUTUAL1_KEY32)
#define CTSUSO1_MUTUAL1_KEY33  ((CTSUICOG_MUTUAL1_KEY33 << 13) | (CTSUSDPA_MUTUAL1_KEY33 << 8) | CTSURICOA_MUTUAL1_KEY33)
#define CTSUSO1_MUTUAL1_KEY34  ((CTSUICOG_MUTUAL1_KEY34 << 13) | (CTSUSDPA_MUTUAL1_KEY34 << 8) | CTSURICOA_MUTUAL1_KEY34)
#define CTSUSO1_MUTUAL1_KEY35  ((CTSUICOG_MUTUAL1_KEY35 << 13) | (CTSUSDPA_MUTUAL1_KEY35 << 8) | CTSURICOA_MUTUAL1_KEY35)
#define CTSUSO1_MUTUAL1_KEY36  ((CTSUICOG_MUTUAL1_KEY36 << 13) | (CTSUSDPA_MUTUAL1_KEY36 << 8) | CTSURICOA_MUTUAL1_KEY36)
#define CTSUSO1_MUTUAL1_KEY37  ((CTSUICOG_MUTUAL1_KEY37 << 13) | (CTSUSDPA_MUTUAL1_KEY37 << 8) | CTSURICOA_MUTUAL1_KEY37)
#define CTSUSO1_MUTUAL1_KEY38  ((CTSUICOG_MUTUAL1_KEY38 << 13) | (CTSUSDPA_MUTUAL1_KEY38 << 8) | CTSURICOA_MUTUAL1_KEY38)
#define CTSUSO1_MUTUAL1_KEY39  ((CTSUICOG_MUTUAL1_KEY39 << 13) | (CTSUSDPA_MUTUAL1_KEY39 << 8) | CTSURICOA_MUTUAL1_KEY39)
#define CTSUSO1_MUTUAL1_KEY40  ((CTSUICOG_MUTUAL1_KEY40 << 13) | (CTSUSDPA_MUTUAL1_KEY40 << 8) | CTSURICOA_MUTUAL1_KEY40)
#define CTSUSO1_MUTUAL1_KEY41  ((CTSUICOG_MUTUAL1_KEY41 << 13) | (CTSUSDPA_MUTUAL1_KEY41 << 8) | CTSURICOA_MUTUAL1_KEY41)
#define CTSUSO1_MUTUAL1_KEY42  ((CTSUICOG_MUTUAL1_KEY42 << 13) | (CTSUSDPA_MUTUAL1_KEY42 << 8) | CTSURICOA_MUTUAL1_KEY42)
#define CTSUSO1_MUTUAL1_KEY43  ((CTSUICOG_MUTUAL1_KEY43 << 13) | (CTSUSDPA_MUTUAL1_KEY43 << 8) | CTSURICOA_MUTUAL1_KEY43)
#define CTSUSO1_MUTUAL1_KEY44  ((CTSUICOG_MUTUAL1_KEY44 << 13) | (CTSUSDPA_MUTUAL1_KEY44 << 8) | CTSURICOA_MUTUAL1_KEY44)
#define CTSUSO1_MUTUAL1_KEY45  ((CTSUICOG_MUTUAL1_KEY45 << 13) | (CTSUSDPA_MUTUAL1_KEY45 << 8) | CTSURICOA_MUTUAL1_KEY45)
#define CTSUSO1_MUTUAL1_KEY46  ((CTSUICOG_MUTUAL1_KEY46 << 13) | (CTSUSDPA_MUTUAL1_KEY46 << 8) | CTSURICOA_MUTUAL1_KEY46)
#define CTSUSO1_MUTUAL1_KEY47  ((CTSUICOG_MUTUAL1_KEY47 << 13) | (CTSUSDPA_MUTUAL1_KEY47 << 8) | CTSURICOA_MUTUAL1_KEY47)
#define CTSUSO1_MUTUAL1_KEY48  ((CTSUICOG_MUTUAL1_KEY48 << 13) | (CTSUSDPA_MUTUAL1_KEY48 << 8) | CTSURICOA_MUTUAL1_KEY48)
#define CTSUSO1_MUTUAL1_KEY49  ((CTSUICOG_MUTUAL1_KEY49 << 13) | (CTSUSDPA_MUTUAL1_KEY49 << 8) | CTSURICOA_MUTUAL1_KEY49)
#define CTSUSO1_MUTUAL1_KEY50  ((CTSUICOG_MUTUAL1_KEY50 << 13) | (CTSUSDPA_MUTUAL1_KEY50 << 8) | CTSURICOA_MUTUAL1_KEY50)
#define CTSUSO1_MUTUAL1_KEY51  ((CTSUICOG_MUTUAL1_KEY51 << 13) | (CTSUSDPA_MUTUAL1_KEY51 << 8) | CTSURICOA_MUTUAL1_KEY51)
#define CTSUSO1_MUTUAL1_KEY52  ((CTSUICOG_MUTUAL1_KEY52 << 13) | (CTSUSDPA_MUTUAL1_KEY52 << 8) | CTSURICOA_MUTUAL1_KEY52)
#define CTSUSO1_MUTUAL1_KEY53  ((CTSUICOG_MUTUAL1_KEY53 << 13) | (CTSUSDPA_MUTUAL1_KEY53 << 8) | CTSURICOA_MUTUAL1_KEY53)
#define CTSUSO1_MUTUAL1_KEY54  ((CTSUICOG_MUTUAL1_KEY54 << 13) | (CTSUSDPA_MUTUAL1_KEY54 << 8) | CTSURICOA_MUTUAL1_KEY54)
#define CTSUSO1_MUTUAL1_KEY55  ((CTSUICOG_MUTUAL1_KEY55 << 13) | (CTSUSDPA_MUTUAL1_KEY55 << 8) | CTSURICOA_MUTUAL1_KEY55)
#define CTSUSO1_MUTUAL1_KEY56  ((CTSUICOG_MUTUAL1_KEY56 << 13) | (CTSUSDPA_MUTUAL1_KEY56 << 8) | CTSURICOA_MUTUAL1_KEY56)
#define CTSUSO1_MUTUAL1_KEY57  ((CTSUICOG_MUTUAL1_KEY57 << 13) | (CTSUSDPA_MUTUAL1_KEY57 << 8) | CTSURICOA_MUTUAL1_KEY57)
#define CTSUSO1_MUTUAL1_KEY58  ((CTSUICOG_MUTUAL1_KEY58 << 13) | (CTSUSDPA_MUTUAL1_KEY58 << 8) | CTSURICOA_MUTUAL1_KEY58)
#define CTSUSO1_MUTUAL1_KEY59  ((CTSUICOG_MUTUAL1_KEY59 << 13) | (CTSUSDPA_MUTUAL1_KEY59 << 8) | CTSURICOA_MUTUAL1_KEY59)
#define CTSUSO1_MUTUAL1_KEY60  ((CTSUICOG_MUTUAL1_KEY60 << 13) | (CTSUSDPA_MUTUAL1_KEY60 << 8) | CTSURICOA_MUTUAL1_KEY60)
#define CTSUSO1_MUTUAL1_KEY61  ((CTSUICOG_MUTUAL1_KEY61 << 13) | (CTSUSDPA_MUTUAL1_KEY61 << 8) | CTSURICOA_MUTUAL1_KEY61)
#define CTSUSO1_MUTUAL1_KEY62  ((CTSUICOG_MUTUAL1_KEY62 << 13) | (CTSUSDPA_MUTUAL1_KEY62 << 8) | CTSURICOA_MUTUAL1_KEY62)
#define CTSUSO1_MUTUAL1_KEY63  ((CTSUICOG_MUTUAL1_KEY63 << 13) | (CTSUSDPA_MUTUAL1_KEY63 << 8) | CTSURICOA_MUTUAL1_KEY63)
#endif    // ( MUTUAL_METHOD_NUM >= 2 )

#if ( MUTUAL_METHOD_NUM >= 3 )
/*====================================================================================================================*/
/*=====     Mutual-measurement 2 TS enable definition    =============================================================*/
/*====================================================================================================================*/
#define MUTUAL2_ENABLE_TS00              (0)        /* Mutual 2 TS00 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS01              (0)        /* Mutual 2 TS01 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS02              (0)        /* Mutual 2 TS02 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS03              (0)        /* Mutual 2 TS03 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS04              (0)        /* Mutual 2 TS04 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS05              (0)        /* Mutual 2 TS05 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS06              (0)        /* Mutual 2 TS06 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS07              (0)        /* Mutual 2 TS07 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS08              (0)        /* Mutual 2 TS08 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS09              (0)        /* Mutual 2 TS09 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS10              (0)        /* Mutual 2 TS10 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS11              (0)        /* Mutual 2 TS11 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS12              (0)        /* Mutual 2 TS12 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS13              (0)        /* Mutual 2 TS13 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS14              (0)        /* Mutual 2 TS14 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS15              (0)        /* Mutual 2 TS15 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS16              (0)        /* Mutual 2 TS16 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS17              (0)        /* Mutual 2 TS17 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS18              (0)        /* Mutual 2 TS18 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS19              (0)        /* Mutual 2 TS19 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS20              (0)        /* Mutual 2 TS20 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS21              (0)        /* Mutual 2 TS21 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS22              (0)        /* Mutual 2 TS22 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS23              (0)        /* Mutual 2 TS23 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS24              (0)        /* Mutual 2 TS24 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS25              (0)        /* Mutual 2 TS25 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS26              (0)        /* Mutual 2 TS26 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS27              (0)        /* Mutual 2 TS27 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS28              (0)        /* Mutual 2 TS28 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS29              (0)        /* Mutual 2 TS29 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS30              (0)        /* Mutual 2 TS30 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS31              (0)        /* Mutual 2 TS31 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS32              (0)        /* Mutual 2 TS32 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS33              (0)        /* Mutual 2 TS33 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS34              (0)        /* Mutual 2 TS34 0:disable 1:enable                               */
#define MUTUAL2_ENABLE_TS35              (0)        /* Mutual 2 TS35 0:disable 1:enable                               */

/*****    Address 000A 0906h CTSU Channel enable control register 0    ************************************************/
#define CTSUCHAC0_MUTUAL2_ENABLE_TS      ((MUTUAL2_ENABLE_TS00 << 0) | (MUTUAL2_ENABLE_TS01 << 1) | \
                                          (MUTUAL2_ENABLE_TS02 << 2) | (MUTUAL2_ENABLE_TS03 << 3) | \
                                          (MUTUAL2_ENABLE_TS04 << 4) | (MUTUAL2_ENABLE_TS05 << 5) | \
                                          (MUTUAL2_ENABLE_TS06 << 6) | (MUTUAL2_ENABLE_TS07 << 7))

/*****    Address 000A 0907h CTSU Channel enable control register 1    ************************************************/
#define CTSUCHAC1_MUTUAL2_ENABLE_TS      ((MUTUAL2_ENABLE_TS08 << 0) | (MUTUAL2_ENABLE_TS09 << 1) | \
                                          (MUTUAL2_ENABLE_TS10 << 2) | (MUTUAL2_ENABLE_TS11 << 3) | \
                                          (MUTUAL2_ENABLE_TS12 << 4) | (MUTUAL2_ENABLE_TS13 << 5) | \
                                          (MUTUAL2_ENABLE_TS14 << 6) | (MUTUAL2_ENABLE_TS15 << 7))

/*****    Address 000A 0908h CTSU Channel enable control register 2    ************************************************/
#define CTSUCHAC2_MUTUAL2_ENABLE_TS      ((MUTUAL2_ENABLE_TS16 << 0) | (MUTUAL2_ENABLE_TS17 << 1) | \
                                          (MUTUAL2_ENABLE_TS18 << 2) | (MUTUAL2_ENABLE_TS19 << 3) | \
                                          (MUTUAL2_ENABLE_TS20 << 4) | (MUTUAL2_ENABLE_TS21 << 5) | \
                                          (MUTUAL2_ENABLE_TS22 << 6) | (MUTUAL2_ENABLE_TS23 << 7))

/*****    Address 000A 0909h CTSU Channel enable control register 3    ************************************************/
#define CTSUCHAC3_MUTUAL2_ENABLE_TS      ((MUTUAL2_ENABLE_TS24 << 0) | (MUTUAL2_ENABLE_TS25 << 1) | \
                                          (MUTUAL2_ENABLE_TS26 << 2) | (MUTUAL2_ENABLE_TS27 << 3) | \
                                          (MUTUAL2_ENABLE_TS28 << 4) | (MUTUAL2_ENABLE_TS29 << 5) | \
                                          (MUTUAL2_ENABLE_TS30 << 6) | (MUTUAL2_ENABLE_TS31 << 7))

/*****    Address 000A 090ah CTSU Channel enable control register 4    ************************************************/
#define CTSUCHAC4_MUTUAL2_ENABLE_TS      ((MUTUAL2_ENABLE_TS32 << 0) | (MUTUAL2_ENABLE_TS33 << 1) | \
                                          (MUTUAL2_ENABLE_TS34 << 2) | (MUTUAL2_ENABLE_TS35 << 3))

/* SUM of Channels */ /* Do not edit this macro definition */
#define MUTUAL2_ENABLE_NUM               (MUTUAL2_ENABLE_TS00 + MUTUAL2_ENABLE_TS01 + MUTUAL2_ENABLE_TS02 + \
                                          MUTUAL2_ENABLE_TS03 + MUTUAL2_ENABLE_TS04 + MUTUAL2_ENABLE_TS05 + \
                                          MUTUAL2_ENABLE_TS06 + MUTUAL2_ENABLE_TS07 + MUTUAL2_ENABLE_TS08 + \
                                          MUTUAL2_ENABLE_TS09 + MUTUAL2_ENABLE_TS10 + MUTUAL2_ENABLE_TS11 + \
                                          MUTUAL2_ENABLE_TS12 + MUTUAL2_ENABLE_TS13 + MUTUAL2_ENABLE_TS14 + \
                                          MUTUAL2_ENABLE_TS15 + MUTUAL2_ENABLE_TS16 + MUTUAL2_ENABLE_TS17 + \
                                          MUTUAL2_ENABLE_TS18 + MUTUAL2_ENABLE_TS19 + MUTUAL2_ENABLE_TS20 + \
                                          MUTUAL2_ENABLE_TS21 + MUTUAL2_ENABLE_TS22 + MUTUAL2_ENABLE_TS23 + \
                                          MUTUAL2_ENABLE_TS24 + MUTUAL2_ENABLE_TS25 + MUTUAL2_ENABLE_TS26 + \
                                          MUTUAL2_ENABLE_TS27 + MUTUAL2_ENABLE_TS28 + MUTUAL2_ENABLE_TS29 + \
                                          MUTUAL2_ENABLE_TS30 + MUTUAL2_ENABLE_TS31 + MUTUAL2_ENABLE_TS32 + \
                                          MUTUAL2_ENABLE_TS33 + MUTUAL2_ENABLE_TS34 + MUTUAL2_ENABLE_TS35)

/*====================================================================================================================*/
/*=====     Mutual-measurement 0 function definition     =============================================================*/
/*====================================================================================================================*/
#define MUTUAL2_FUNCTION_TS00            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS01            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS02            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS03            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS04            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS05            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS06            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS07            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS08            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS09            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS10            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS11            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS12            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS13            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS14            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS15            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS16            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS17            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS18            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS19            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS20            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS21            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS22            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS23            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS24            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS25            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS26            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS27            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS28            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS29            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS30            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS31            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS32            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS33            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS34            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL2_FUNCTION_TS35            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */

/*****    Address 000A 090Bh CTSU Channel send and receive control register 0 *****************************************/
#define CTSUCHTRC0_MUTUAL2_TRANSMIT_TS   ((MUTUAL2_FUNCTION_TS00 << 0) | (MUTUAL2_FUNCTION_TS01 << 1) | \
                                          (MUTUAL2_FUNCTION_TS02 << 2) | (MUTUAL2_FUNCTION_TS03 << 3) | \
                                          (MUTUAL2_FUNCTION_TS04 << 4) | (MUTUAL2_FUNCTION_TS05 << 5) | \
                                          (MUTUAL2_FUNCTION_TS06 << 6) | (MUTUAL2_FUNCTION_TS07 << 7))

/*****    Address 000A 090Ch CTSU Channel send and receive control register 1 *****************************************/
#define CTSUCHTRC1_MUTUAL2_TRANSMIT_TS   ((MUTUAL2_FUNCTION_TS08 << 0) | (MUTUAL2_FUNCTION_TS09 << 1) | \
                                          (MUTUAL2_FUNCTION_TS10 << 2) | (MUTUAL2_FUNCTION_TS11 << 3) | \
                                          (MUTUAL2_FUNCTION_TS12 << 4) | (MUTUAL2_FUNCTION_TS13 << 5) | \
                                          (MUTUAL2_FUNCTION_TS14 << 6) | (MUTUAL2_FUNCTION_TS15 << 7))

/*****    Address 000A 090Dh CTSU Channel send and receive control register 2 *****************************************/
#define CTSUCHTRC2_MUTUAL2_TRANSMIT_TS   ((MUTUAL2_FUNCTION_TS16 << 0) | (MUTUAL2_FUNCTION_TS17 << 1) | \
                                          (MUTUAL2_FUNCTION_TS18 << 2) | (MUTUAL2_FUNCTION_TS19 << 3) | \
                                          (MUTUAL2_FUNCTION_TS20 << 4) | (MUTUAL2_FUNCTION_TS21 << 5) | \
                                          (MUTUAL2_FUNCTION_TS22 << 6) | (MUTUAL2_FUNCTION_TS23 << 7))

/*****    Address 000A 090Eh CTSU Channel send and receive control register 3 *****************************************/
#define CTSUCHTRC3_MUTUAL2_TRANSMIT_TS   ((MUTUAL2_FUNCTION_TS24 << 0) | (MUTUAL2_FUNCTION_TS25 << 1) | \
                                          (MUTUAL2_FUNCTION_TS26 << 2) | (MUTUAL2_FUNCTION_TS27 << 3) | \
                                          (MUTUAL2_FUNCTION_TS28 << 4) | (MUTUAL2_FUNCTION_TS29 << 5) | \
                                          (MUTUAL2_FUNCTION_TS30 << 6) | (MUTUAL2_FUNCTION_TS31 << 7))

/*****    Address 000A 090Fh CTSU Channel send and receive control register 4 *****************************************/
#define CTSUCHTRC4_MUTUAL2_TRANSMIT_TS   ((MUTUAL2_FUNCTION_TS32 << 0) | (MUTUAL2_FUNCTION_TS33 << 1) | \
                                          (MUTUAL2_FUNCTION_TS34 << 2) | (MUTUAL2_FUNCTION_TS35 << 3))

#define TRANSMISSION2_NUM                  (MUTUAL2_FUNCTION_TS00 + MUTUAL2_FUNCTION_TS01 + MUTUAL2_FUNCTION_TS02 + \
                                            MUTUAL2_FUNCTION_TS03 + MUTUAL2_FUNCTION_TS04 + MUTUAL2_FUNCTION_TS05 + \
                                            MUTUAL2_FUNCTION_TS06 + MUTUAL2_FUNCTION_TS07 + MUTUAL2_FUNCTION_TS08 + \
                                            MUTUAL2_FUNCTION_TS09 + MUTUAL2_FUNCTION_TS10 + MUTUAL2_FUNCTION_TS11 + \
                                            MUTUAL2_FUNCTION_TS12 + MUTUAL2_FUNCTION_TS13 + MUTUAL2_FUNCTION_TS14 + \
                                            MUTUAL2_FUNCTION_TS15 + MUTUAL2_FUNCTION_TS16 + MUTUAL2_FUNCTION_TS17 + \
                                            MUTUAL2_FUNCTION_TS18 + MUTUAL2_FUNCTION_TS19 + MUTUAL2_FUNCTION_TS20 + \
                                            MUTUAL2_FUNCTION_TS21 + MUTUAL2_FUNCTION_TS22 + MUTUAL2_FUNCTION_TS23 + \
                                            MUTUAL2_FUNCTION_TS24 + MUTUAL2_FUNCTION_TS25 + MUTUAL2_FUNCTION_TS26 + \
                                            MUTUAL2_FUNCTION_TS27 + MUTUAL2_FUNCTION_TS28 + MUTUAL2_FUNCTION_TS29 + \
                                            MUTUAL2_FUNCTION_TS30 + MUTUAL2_FUNCTION_TS31 + MUTUAL2_FUNCTION_TS32 + \
                                            MUTUAL2_FUNCTION_TS33 + MUTUAL2_FUNCTION_TS34 + MUTUAL2_FUNCTION_TS35)

#define RECEPTION2_NUM                     (MUTUAL2_ENABLE_NUM - TRANSMISSION2_NUM)
#define MUTUAL2_NUM                        (TRANSMISSION2_NUM * RECEPTION2_NUM)

#if TRANSMISSION2_NUM == 0
    #error "Send TS Setting error ( TRANSMISSION2_NUM = 0 )"
#endif
#if RECEPTION2_NUM == 0
    #error "Receive TS Setting error ( RECEPTION_NUM2 = 0 )"
#endif

/*****    Address 000A 0912h CTSU High-Pass Noise Reduction Spectrum Diffusion Control Register    ********************/
/**********************************************************************************************************************/
/*    CTSU Spectrum Diffusion Frequency Division Setting                                                              */
/*    Base Clock Frequency fb (MHz)   CTSUSSDIV[3:0] Bit Setting                                                      */
/*          4.00 =< fb                           0x00                                                                 */
/*          2.00 =< fb  < 4.00                   0x01                                                                 */
/*          1.33 =< fb  < 2.00                   0x02                                                                 */
/*          1.00 =< fb  < 1.33                   0x03                                                                 */
/*          0.80 =< fb  < 1.00                   0x04                                                                 */
/*          0.67 =< fb  < 0.80                   0x05                                                                 */
/*          0.57 =< fb  < 0.67                   0x06                                                                 */
/*          0.50 =< fb  < 0.57                   0x07                                                                 */
/*          0.44 =< fb  < 0.50                   0x08                                                                 */
/*          0.40 =< fb  < 0.44                   0x09                                                                 */
/*          0.36 =< fb  < 0.40                   0x0A                                                                 */
/*          0.33 =< fb  < 0.36                   0x0B                                                                 */
/*          0.31 =< fb  < 0.33                   0x0C                                                                 */
/*          0.29 =< fb  < 0.31                   0x0D                                                                 */
/*          0.27 =< fb  < 0.29                   0x0E                                                                 */
/*                  fb =< 0.25                   0x0F                                                                 */
/**********************************************************************************************************************/
#define CTSUSSDIV_MUTUAL2_KEY00         (0x01)                  /* Mutual 2 Key00 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY01         (0x01)                  /* Mutual 2 Key01 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY02         (0x01)                  /* Mutual 2 Key02 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY03         (0x01)                  /* Mutual 2 Key03 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY04         (0x01)                  /* Mutual 2 Key04 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY05         (0x01)                  /* Mutual 2 Key05 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY06         (0x01)                  /* Mutual 2 Key06 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY07         (0x01)                  /* Mutual 2 Key07 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY08         (0x01)                  /* Mutual 2 Key08 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY09         (0x01)                  /* Mutual 2 Key09 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY10         (0x01)                  /* Mutual 2 Key10 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY11         (0x01)                  /* Mutual 2 Key11 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY12         (0x01)                  /* Mutual 2 Key12 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY13         (0x01)                  /* Mutual 2 Key13 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY14         (0x01)                  /* Mutual 2 Key14 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY15         (0x01)                  /* Mutual 2 Key15 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY16         (0x01)                  /* Mutual 2 Key16 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY17         (0x01)                  /* Mutual 2 Key17 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY18         (0x01)                  /* Mutual 2 Key18 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY19         (0x01)                  /* Mutual 2 Key19 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY20         (0x01)                  /* Mutual 2 Key20 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY21         (0x01)                  /* Mutual 2 Key21 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY22         (0x01)                  /* Mutual 2 Key22 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY23         (0x01)                  /* Mutual 2 Key23 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY24         (0x01)                  /* Mutual 2 Key24 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY25         (0x01)                  /* Mutual 2 Key25 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY26         (0x01)                  /* Mutual 2 Key26 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY27         (0x01)                  /* Mutual 2 Key27 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY28         (0x01)                  /* Mutual 2 Key28 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY29         (0x01)                  /* Mutual 2 Key29 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY30         (0x01)                  /* Mutual 2 Key30 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY31         (0x01)                  /* Mutual 2 Key31 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY32         (0x01)                  /* Mutual 2 Key32 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY33         (0x01)                  /* Mutual 2 Key33 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY34         (0x01)                  /* Mutual 2 Key34 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY35         (0x01)                  /* Mutual 2 Key35 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY36         (0x01)                  /* Mutual 2 Key36 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY37         (0x01)                  /* Mutual 2 Key37 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY38         (0x01)                  /* Mutual 2 Key38 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY39         (0x01)                  /* Mutual 2 Key39 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY40         (0x01)                  /* Mutual 2 Key40 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY41         (0x01)                  /* Mutual 2 Key41 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY42         (0x01)                  /* Mutual 2 Key42 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY43         (0x01)                  /* Mutual 2 Key43 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY44         (0x01)                  /* Mutual 2 Key44 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY45         (0x01)                  /* Mutual 2 Key45 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY46         (0x01)                  /* Mutual 2 Key46 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY47         (0x01)                  /* Mutual 2 Key47 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY48         (0x01)                  /* Mutual 2 Key48 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY49         (0x01)                  /* Mutual 2 Key49 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY50         (0x01)                  /* Mutual 2 Key50 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY51         (0x01)                  /* Mutual 2 Key51 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY52         (0x01)                  /* Mutual 2 Key52 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY53         (0x01)                  /* Mutual 2 Key53 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY54         (0x01)                  /* Mutual 2 Key54 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY55         (0x01)                  /* Mutual 2 Key55 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY56         (0x01)                  /* Mutual 2 Key56 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY57         (0x01)                  /* Mutual 2 Key57 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY58         (0x01)                  /* Mutual 2 Key58 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY59         (0x01)                  /* Mutual 2 Key59 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY60         (0x01)                  /* Mutual 2 Key60 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY61         (0x01)                  /* Mutual 2 Key61 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY62         (0x01)                  /* Mutual 2 Key62 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL2_KEY63         (0x01)                  /* Mutual 2 Key63 CTSUSDIV                            */

#define CTSUSSC_MUTUAL2_KEY00           (CTSUSSDIV_MUTUAL2_KEY00 << 8)
#define CTSUSSC_MUTUAL2_KEY01           (CTSUSSDIV_MUTUAL2_KEY01 << 8)
#define CTSUSSC_MUTUAL2_KEY02           (CTSUSSDIV_MUTUAL2_KEY02 << 8)
#define CTSUSSC_MUTUAL2_KEY03           (CTSUSSDIV_MUTUAL2_KEY03 << 8)
#define CTSUSSC_MUTUAL2_KEY04           (CTSUSSDIV_MUTUAL2_KEY04 << 8)
#define CTSUSSC_MUTUAL2_KEY05           (CTSUSSDIV_MUTUAL2_KEY05 << 8)
#define CTSUSSC_MUTUAL2_KEY06           (CTSUSSDIV_MUTUAL2_KEY06 << 8)
#define CTSUSSC_MUTUAL2_KEY07           (CTSUSSDIV_MUTUAL2_KEY07 << 8)
#define CTSUSSC_MUTUAL2_KEY08           (CTSUSSDIV_MUTUAL2_KEY08 << 8)
#define CTSUSSC_MUTUAL2_KEY09           (CTSUSSDIV_MUTUAL2_KEY09 << 8)
#define CTSUSSC_MUTUAL2_KEY10           (CTSUSSDIV_MUTUAL2_KEY10 << 8)
#define CTSUSSC_MUTUAL2_KEY11           (CTSUSSDIV_MUTUAL2_KEY11 << 8)
#define CTSUSSC_MUTUAL2_KEY12           (CTSUSSDIV_MUTUAL2_KEY12 << 8)
#define CTSUSSC_MUTUAL2_KEY13           (CTSUSSDIV_MUTUAL2_KEY13 << 8)
#define CTSUSSC_MUTUAL2_KEY14           (CTSUSSDIV_MUTUAL2_KEY14 << 8)
#define CTSUSSC_MUTUAL2_KEY15           (CTSUSSDIV_MUTUAL2_KEY15 << 8)
#define CTSUSSC_MUTUAL2_KEY16           (CTSUSSDIV_MUTUAL2_KEY16 << 8)
#define CTSUSSC_MUTUAL2_KEY17           (CTSUSSDIV_MUTUAL2_KEY17 << 8)
#define CTSUSSC_MUTUAL2_KEY18           (CTSUSSDIV_MUTUAL2_KEY18 << 8)
#define CTSUSSC_MUTUAL2_KEY19           (CTSUSSDIV_MUTUAL2_KEY19 << 8)
#define CTSUSSC_MUTUAL2_KEY20           (CTSUSSDIV_MUTUAL2_KEY20 << 8)
#define CTSUSSC_MUTUAL2_KEY21           (CTSUSSDIV_MUTUAL2_KEY21 << 8)
#define CTSUSSC_MUTUAL2_KEY22           (CTSUSSDIV_MUTUAL2_KEY22 << 8)
#define CTSUSSC_MUTUAL2_KEY23           (CTSUSSDIV_MUTUAL2_KEY23 << 8)
#define CTSUSSC_MUTUAL2_KEY24           (CTSUSSDIV_MUTUAL2_KEY24 << 8)
#define CTSUSSC_MUTUAL2_KEY25           (CTSUSSDIV_MUTUAL2_KEY25 << 8)
#define CTSUSSC_MUTUAL2_KEY26           (CTSUSSDIV_MUTUAL2_KEY26 << 8)
#define CTSUSSC_MUTUAL2_KEY27           (CTSUSSDIV_MUTUAL2_KEY27 << 8)
#define CTSUSSC_MUTUAL2_KEY28           (CTSUSSDIV_MUTUAL2_KEY28 << 8)
#define CTSUSSC_MUTUAL2_KEY29           (CTSUSSDIV_MUTUAL2_KEY29 << 8)
#define CTSUSSC_MUTUAL2_KEY30           (CTSUSSDIV_MUTUAL2_KEY30 << 8)
#define CTSUSSC_MUTUAL2_KEY31           (CTSUSSDIV_MUTUAL2_KEY31 << 8)
#define CTSUSSC_MUTUAL2_KEY32           (CTSUSSDIV_MUTUAL2_KEY32 << 8)
#define CTSUSSC_MUTUAL2_KEY33           (CTSUSSDIV_MUTUAL2_KEY33 << 8)
#define CTSUSSC_MUTUAL2_KEY34           (CTSUSSDIV_MUTUAL2_KEY34 << 8)
#define CTSUSSC_MUTUAL2_KEY35           (CTSUSSDIV_MUTUAL2_KEY35 << 8)
#define CTSUSSC_MUTUAL2_KEY36           (CTSUSSDIV_MUTUAL2_KEY36 << 8)
#define CTSUSSC_MUTUAL2_KEY37           (CTSUSSDIV_MUTUAL2_KEY37 << 8)
#define CTSUSSC_MUTUAL2_KEY38           (CTSUSSDIV_MUTUAL2_KEY38 << 8)
#define CTSUSSC_MUTUAL2_KEY39           (CTSUSSDIV_MUTUAL2_KEY39 << 8)
#define CTSUSSC_MUTUAL2_KEY40           (CTSUSSDIV_MUTUAL2_KEY40 << 8)
#define CTSUSSC_MUTUAL2_KEY41           (CTSUSSDIV_MUTUAL2_KEY41 << 8)
#define CTSUSSC_MUTUAL2_KEY42           (CTSUSSDIV_MUTUAL2_KEY42 << 8)
#define CTSUSSC_MUTUAL2_KEY43           (CTSUSSDIV_MUTUAL2_KEY43 << 8)
#define CTSUSSC_MUTUAL2_KEY44           (CTSUSSDIV_MUTUAL2_KEY44 << 8)
#define CTSUSSC_MUTUAL2_KEY45           (CTSUSSDIV_MUTUAL2_KEY45 << 8)
#define CTSUSSC_MUTUAL2_KEY46           (CTSUSSDIV_MUTUAL2_KEY46 << 8)
#define CTSUSSC_MUTUAL2_KEY47           (CTSUSSDIV_MUTUAL2_KEY47 << 8)
#define CTSUSSC_MUTUAL2_KEY48           (CTSUSSDIV_MUTUAL2_KEY48 << 8)
#define CTSUSSC_MUTUAL2_KEY49           (CTSUSSDIV_MUTUAL2_KEY49 << 8)
#define CTSUSSC_MUTUAL2_KEY50           (CTSUSSDIV_MUTUAL2_KEY50 << 8)
#define CTSUSSC_MUTUAL2_KEY51           (CTSUSSDIV_MUTUAL2_KEY51 << 8)
#define CTSUSSC_MUTUAL2_KEY52           (CTSUSSDIV_MUTUAL2_KEY52 << 8)
#define CTSUSSC_MUTUAL2_KEY53           (CTSUSSDIV_MUTUAL2_KEY53 << 8)
#define CTSUSSC_MUTUAL2_KEY54           (CTSUSSDIV_MUTUAL2_KEY54 << 8)
#define CTSUSSC_MUTUAL2_KEY55           (CTSUSSDIV_MUTUAL2_KEY55 << 8)
#define CTSUSSC_MUTUAL2_KEY56           (CTSUSSDIV_MUTUAL2_KEY56 << 8)
#define CTSUSSC_MUTUAL2_KEY57           (CTSUSSDIV_MUTUAL2_KEY57 << 8)
#define CTSUSSC_MUTUAL2_KEY58           (CTSUSSDIV_MUTUAL2_KEY58 << 8)
#define CTSUSSC_MUTUAL2_KEY59           (CTSUSSDIV_MUTUAL2_KEY59 << 8)
#define CTSUSSC_MUTUAL2_KEY60           (CTSUSSDIV_MUTUAL2_KEY60 << 8)
#define CTSUSSC_MUTUAL2_KEY61           (CTSUSSDIV_MUTUAL2_KEY61 << 8)
#define CTSUSSC_MUTUAL2_KEY62           (CTSUSSDIV_MUTUAL2_KEY62 << 8)
#define CTSUSSC_MUTUAL2_KEY63           (CTSUSSDIV_MUTUAL2_KEY63 << 8)

/*****    Address 000A 0914h CTSU Sensor Offset Register 0     ********************************************************/
/**********************************************************************************************************************/
/*    CTSU Sensor Offset Adjustment                                                                                   */
/*      Current offset amount is 0       0x000                                                                        */
/*      Current offset amount is 1       0x001                                                                        */
/*      Current offset amount is 2       0x002                                                                        */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*      Current offset amount is 1023    0x3FF                                                                        */
/**********************************************************************************************************************/
#define CTSUSO_MUTUAL2_KEY00            (0x000)                 /* Mutual 2 Key00 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY01            (0x000)                 /* Mutual 2 Key01 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY02            (0x000)                 /* Mutual 2 Key02 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY03            (0x000)                 /* Mutual 2 Key03 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY04            (0x000)                 /* Mutual 2 Key04 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY05            (0x000)                 /* Mutual 2 Key05 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY06            (0x000)                 /* Mutual 2 Key06 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY07            (0x000)                 /* Mutual 2 Key07 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY08            (0x000)                 /* Mutual 2 Key08 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY09            (0x000)                 /* Mutual 2 Key09 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY10            (0x000)                 /* Mutual 2 Key10 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY11            (0x000)                 /* Mutual 2 Key11 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY12            (0x000)                 /* Mutual 2 Key12 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY13            (0x000)                 /* Mutual 2 Key13 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY14            (0x000)                 /* Mutual 2 Key14 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY15            (0x000)                 /* Mutual 2 Key15 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY16            (0x000)                 /* Mutual 2 Key16 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY17            (0x000)                 /* Mutual 2 Key17 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY18            (0x000)                 /* Mutual 2 Key18 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY19            (0x000)                 /* Mutual 2 Key19 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY20            (0x000)                 /* Mutual 2 Key20 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY21            (0x000)                 /* Mutual 2 Key21 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY22            (0x000)                 /* Mutual 2 Key22 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY23            (0x000)                 /* Mutual 2 Key23 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY24            (0x000)                 /* Mutual 2 Key24 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY25            (0x000)                 /* Mutual 2 Key25 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY26            (0x000)                 /* Mutual 2 Key26 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY27            (0x000)                 /* Mutual 2 Key27 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY28            (0x000)                 /* Mutual 2 Key28 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY29            (0x000)                 /* Mutual 2 Key29 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY30            (0x000)                 /* Mutual 2 Key30 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY31            (0x000)                 /* Mutual 2 Key31 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY32            (0x000)                 /* Mutual 2 Key32 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY33            (0x000)                 /* Mutual 2 Key33 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY34            (0x000)                 /* Mutual 2 Key34 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY35            (0x000)                 /* Mutual 2 Key35 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY36            (0x000)                 /* Mutual 2 Key36 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY37            (0x000)                 /* Mutual 2 Key37 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY38            (0x000)                 /* Mutual 2 Key38 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY39            (0x000)                 /* Mutual 2 Key39 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY40            (0x000)                 /* Mutual 2 Key40 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY41            (0x000)                 /* Mutual 2 Key41 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY42            (0x000)                 /* Mutual 2 Key42 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY43            (0x000)                 /* Mutual 2 Key43 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY44            (0x000)                 /* Mutual 2 Key44 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY45            (0x000)                 /* Mutual 2 Key45 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY46            (0x000)                 /* Mutual 2 Key46 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY47            (0x000)                 /* Mutual 2 Key47 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY48            (0x000)                 /* Mutual 2 Key48 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY49            (0x000)                 /* Mutual 2 Key49 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY50            (0x000)                 /* Mutual 2 Key50 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY51            (0x000)                 /* Mutual 2 Key51 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY52            (0x000)                 /* Mutual 2 Key52 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY53            (0x000)                 /* Mutual 2 Key53 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY54            (0x000)                 /* Mutual 2 Key54 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY55            (0x000)                 /* Mutual 2 Key55 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY56            (0x000)                 /* Mutual 2 Key56 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY57            (0x000)                 /* Mutual 2 Key57 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY58            (0x000)                 /* Mutual 2 Key58 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY59            (0x000)                 /* Mutual 2 Key59 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY60            (0x000)                 /* Mutual 2 Key60 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY61            (0x000)                 /* Mutual 2 Key61 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY62            (0x000)                 /* Mutual 2 Key62 CTSUSO                              */
#define CTSUSO_MUTUAL2_KEY63            (0x000)                 /* Mutual 2 Key63 CTSUSO                              */

/**********************************************************************************************************************/
/*    CTSU Measurement Count Setting                                                                                  */
/*      4.0MHz    7                                                                                                   */
/*      2.0MHz    3                                                                                                   */
/*      1.0MHz    1                                                                                                   */
/*      0.5MHz    0                                                                                                   */
/**********************************************************************************************************************/
#define CTSUSNUM_MUTUAL2_KEY00          (3)                     /* Mutual 2 Key00 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY01          (3)                     /* Mutual 2 Key01 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY02          (3)                     /* Mutual 2 Key02 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY03          (3)                     /* Mutual 2 Key03 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY04          (3)                     /* Mutual 2 Key04 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY05          (3)                     /* Mutual 2 Key05 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY06          (3)                     /* Mutual 2 Key06 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY07          (3)                     /* Mutual 2 Key07 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY08          (3)                     /* Mutual 2 Key08 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY09          (3)                     /* Mutual 2 Key09 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY10          (3)                     /* Mutual 2 Key10 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY11          (3)                     /* Mutual 2 Key11 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY12          (3)                     /* Mutual 2 Key12 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY13          (3)                     /* Mutual 2 Key13 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY14          (3)                     /* Mutual 2 Key14 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY15          (3)                     /* Mutual 2 Key15 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY16          (3)                     /* Mutual 2 Key16 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY17          (3)                     /* Mutual 2 Key17 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY18          (3)                     /* Mutual 2 Key18 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY19          (3)                     /* Mutual 2 Key19 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY20          (3)                     /* Mutual 2 Key20 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY21          (3)                     /* Mutual 2 Key21 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY22          (3)                     /* Mutual 2 Key22 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY23          (3)                     /* Mutual 2 Key23 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY24          (3)                     /* Mutual 2 Key24 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY25          (3)                     /* Mutual 2 Key25 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY26          (3)                     /* Mutual 2 Key26 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY27          (3)                     /* Mutual 2 Key27 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY28          (3)                     /* Mutual 2 Key28 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY29          (3)                     /* Mutual 2 Key29 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY30          (3)                     /* Mutual 2 Key30 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY31          (3)                     /* Mutual 2 Key31 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY32          (3)                     /* Mutual 2 Key32 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY33          (3)                     /* Mutual 2 Key33 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY34          (3)                     /* Mutual 2 Key34 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY35          (3)                     /* Mutual 2 Key35 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY36          (3)                     /* Mutual 2 Key36 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY37          (3)                     /* Mutual 2 Key37 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY38          (3)                     /* Mutual 2 Key38 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY39          (3)                     /* Mutual 2 Key39 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY40          (3)                     /* Mutual 2 Key40 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY41          (3)                     /* Mutual 2 Key41 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY42          (3)                     /* Mutual 2 Key42 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY43          (3)                     /* Mutual 2 Key43 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY44          (3)                     /* Mutual 2 Key44 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY45          (3)                     /* Mutual 2 Key45 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY46          (3)                     /* Mutual 2 Key46 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY47          (3)                     /* Mutual 2 Key47 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY48          (3)                     /* Mutual 2 Key48 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY49          (3)                     /* Mutual 2 Key49 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY50          (3)                     /* Mutual 2 Key50 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY51          (3)                     /* Mutual 2 Key51 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY52          (3)                     /* Mutual 2 Key52 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY53          (3)                     /* Mutual 2 Key53 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY54          (3)                     /* Mutual 2 Key54 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY55          (3)                     /* Mutual 2 Key55 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY56          (3)                     /* Mutual 2 Key56 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY57          (3)                     /* Mutual 2 Key57 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY58          (3)                     /* Mutual 2 Key58 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY59          (3)                     /* Mutual 2 Key59 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY60          (3)                     /* Mutual 2 Key60 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY61          (3)                     /* Mutual 2 Key61 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY62          (3)                     /* Mutual 2 Key62 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL2_KEY63          (3)                     /* Mutual 2 Key63 CTSUSNUM                            */

#define CTSUSO0_MUTUAL2_KEY00           ((CTSUSNUM_MUTUAL2_KEY00 << 10) | CTSUSO_MUTUAL2_KEY00)
#define CTSUSO0_MUTUAL2_KEY01           ((CTSUSNUM_MUTUAL2_KEY01 << 10) | CTSUSO_MUTUAL2_KEY01)
#define CTSUSO0_MUTUAL2_KEY02           ((CTSUSNUM_MUTUAL2_KEY02 << 10) | CTSUSO_MUTUAL2_KEY02)
#define CTSUSO0_MUTUAL2_KEY03           ((CTSUSNUM_MUTUAL2_KEY03 << 10) | CTSUSO_MUTUAL2_KEY03)
#define CTSUSO0_MUTUAL2_KEY04           ((CTSUSNUM_MUTUAL2_KEY04 << 10) | CTSUSO_MUTUAL2_KEY04)
#define CTSUSO0_MUTUAL2_KEY05           ((CTSUSNUM_MUTUAL2_KEY05 << 10) | CTSUSO_MUTUAL2_KEY05)
#define CTSUSO0_MUTUAL2_KEY06           ((CTSUSNUM_MUTUAL2_KEY06 << 10) | CTSUSO_MUTUAL2_KEY06)
#define CTSUSO0_MUTUAL2_KEY07           ((CTSUSNUM_MUTUAL2_KEY07 << 10) | CTSUSO_MUTUAL2_KEY07)
#define CTSUSO0_MUTUAL2_KEY08           ((CTSUSNUM_MUTUAL2_KEY08 << 10) | CTSUSO_MUTUAL2_KEY08)
#define CTSUSO0_MUTUAL2_KEY09           ((CTSUSNUM_MUTUAL2_KEY09 << 10) | CTSUSO_MUTUAL2_KEY09)
#define CTSUSO0_MUTUAL2_KEY10           ((CTSUSNUM_MUTUAL2_KEY10 << 10) | CTSUSO_MUTUAL2_KEY10)
#define CTSUSO0_MUTUAL2_KEY11           ((CTSUSNUM_MUTUAL2_KEY11 << 10) | CTSUSO_MUTUAL2_KEY11)
#define CTSUSO0_MUTUAL2_KEY12           ((CTSUSNUM_MUTUAL2_KEY12 << 10) | CTSUSO_MUTUAL2_KEY12)
#define CTSUSO0_MUTUAL2_KEY13           ((CTSUSNUM_MUTUAL2_KEY13 << 10) | CTSUSO_MUTUAL2_KEY13)
#define CTSUSO0_MUTUAL2_KEY14           ((CTSUSNUM_MUTUAL2_KEY14 << 10) | CTSUSO_MUTUAL2_KEY14)
#define CTSUSO0_MUTUAL2_KEY15           ((CTSUSNUM_MUTUAL2_KEY15 << 10) | CTSUSO_MUTUAL2_KEY15)
#define CTSUSO0_MUTUAL2_KEY16           ((CTSUSNUM_MUTUAL2_KEY16 << 10) | CTSUSO_MUTUAL2_KEY16)
#define CTSUSO0_MUTUAL2_KEY17           ((CTSUSNUM_MUTUAL2_KEY17 << 10) | CTSUSO_MUTUAL2_KEY17)
#define CTSUSO0_MUTUAL2_KEY18           ((CTSUSNUM_MUTUAL2_KEY18 << 10) | CTSUSO_MUTUAL2_KEY18)
#define CTSUSO0_MUTUAL2_KEY19           ((CTSUSNUM_MUTUAL2_KEY19 << 10) | CTSUSO_MUTUAL2_KEY19)
#define CTSUSO0_MUTUAL2_KEY20           ((CTSUSNUM_MUTUAL2_KEY20 << 10) | CTSUSO_MUTUAL2_KEY20)
#define CTSUSO0_MUTUAL2_KEY21           ((CTSUSNUM_MUTUAL2_KEY21 << 10) | CTSUSO_MUTUAL2_KEY21)
#define CTSUSO0_MUTUAL2_KEY22           ((CTSUSNUM_MUTUAL2_KEY22 << 10) | CTSUSO_MUTUAL2_KEY22)
#define CTSUSO0_MUTUAL2_KEY23           ((CTSUSNUM_MUTUAL2_KEY23 << 10) | CTSUSO_MUTUAL2_KEY23)
#define CTSUSO0_MUTUAL2_KEY24           ((CTSUSNUM_MUTUAL2_KEY24 << 10) | CTSUSO_MUTUAL2_KEY24)
#define CTSUSO0_MUTUAL2_KEY25           ((CTSUSNUM_MUTUAL2_KEY25 << 10) | CTSUSO_MUTUAL2_KEY25)
#define CTSUSO0_MUTUAL2_KEY26           ((CTSUSNUM_MUTUAL2_KEY26 << 10) | CTSUSO_MUTUAL2_KEY26)
#define CTSUSO0_MUTUAL2_KEY27           ((CTSUSNUM_MUTUAL2_KEY27 << 10) | CTSUSO_MUTUAL2_KEY27)
#define CTSUSO0_MUTUAL2_KEY28           ((CTSUSNUM_MUTUAL2_KEY28 << 10) | CTSUSO_MUTUAL2_KEY28)
#define CTSUSO0_MUTUAL2_KEY29           ((CTSUSNUM_MUTUAL2_KEY29 << 10) | CTSUSO_MUTUAL2_KEY29)
#define CTSUSO0_MUTUAL2_KEY30           ((CTSUSNUM_MUTUAL2_KEY30 << 10) | CTSUSO_MUTUAL2_KEY30)
#define CTSUSO0_MUTUAL2_KEY31           ((CTSUSNUM_MUTUAL2_KEY31 << 10) | CTSUSO_MUTUAL2_KEY31)
#define CTSUSO0_MUTUAL2_KEY32           ((CTSUSNUM_MUTUAL2_KEY32 << 10) | CTSUSO_MUTUAL2_KEY32)
#define CTSUSO0_MUTUAL2_KEY33           ((CTSUSNUM_MUTUAL2_KEY33 << 10) | CTSUSO_MUTUAL2_KEY33)
#define CTSUSO0_MUTUAL2_KEY34           ((CTSUSNUM_MUTUAL2_KEY34 << 10) | CTSUSO_MUTUAL2_KEY34)
#define CTSUSO0_MUTUAL2_KEY35           ((CTSUSNUM_MUTUAL2_KEY35 << 10) | CTSUSO_MUTUAL2_KEY35)
#define CTSUSO0_MUTUAL2_KEY36           ((CTSUSNUM_MUTUAL2_KEY36 << 10) | CTSUSO_MUTUAL2_KEY36)
#define CTSUSO0_MUTUAL2_KEY37           ((CTSUSNUM_MUTUAL2_KEY37 << 10) | CTSUSO_MUTUAL2_KEY37)
#define CTSUSO0_MUTUAL2_KEY38           ((CTSUSNUM_MUTUAL2_KEY38 << 10) | CTSUSO_MUTUAL2_KEY38)
#define CTSUSO0_MUTUAL2_KEY39           ((CTSUSNUM_MUTUAL2_KEY39 << 10) | CTSUSO_MUTUAL2_KEY39)
#define CTSUSO0_MUTUAL2_KEY40           ((CTSUSNUM_MUTUAL2_KEY40 << 10) | CTSUSO_MUTUAL2_KEY40)
#define CTSUSO0_MUTUAL2_KEY41           ((CTSUSNUM_MUTUAL2_KEY41 << 10) | CTSUSO_MUTUAL2_KEY41)
#define CTSUSO0_MUTUAL2_KEY42           ((CTSUSNUM_MUTUAL2_KEY42 << 10) | CTSUSO_MUTUAL2_KEY42)
#define CTSUSO0_MUTUAL2_KEY43           ((CTSUSNUM_MUTUAL2_KEY43 << 10) | CTSUSO_MUTUAL2_KEY43)
#define CTSUSO0_MUTUAL2_KEY44           ((CTSUSNUM_MUTUAL2_KEY44 << 10) | CTSUSO_MUTUAL2_KEY44)
#define CTSUSO0_MUTUAL2_KEY45           ((CTSUSNUM_MUTUAL2_KEY45 << 10) | CTSUSO_MUTUAL2_KEY45)
#define CTSUSO0_MUTUAL2_KEY46           ((CTSUSNUM_MUTUAL2_KEY46 << 10) | CTSUSO_MUTUAL2_KEY46)
#define CTSUSO0_MUTUAL2_KEY47           ((CTSUSNUM_MUTUAL2_KEY47 << 10) | CTSUSO_MUTUAL2_KEY47)
#define CTSUSO0_MUTUAL2_KEY48           ((CTSUSNUM_MUTUAL2_KEY48 << 10) | CTSUSO_MUTUAL2_KEY48)
#define CTSUSO0_MUTUAL2_KEY49           ((CTSUSNUM_MUTUAL2_KEY49 << 10) | CTSUSO_MUTUAL2_KEY49)
#define CTSUSO0_MUTUAL2_KEY50           ((CTSUSNUM_MUTUAL2_KEY50 << 10) | CTSUSO_MUTUAL2_KEY50)
#define CTSUSO0_MUTUAL2_KEY51           ((CTSUSNUM_MUTUAL2_KEY51 << 10) | CTSUSO_MUTUAL2_KEY51)
#define CTSUSO0_MUTUAL2_KEY52           ((CTSUSNUM_MUTUAL2_KEY52 << 10) | CTSUSO_MUTUAL2_KEY52)
#define CTSUSO0_MUTUAL2_KEY53           ((CTSUSNUM_MUTUAL2_KEY53 << 10) | CTSUSO_MUTUAL2_KEY53)
#define CTSUSO0_MUTUAL2_KEY54           ((CTSUSNUM_MUTUAL2_KEY54 << 10) | CTSUSO_MUTUAL2_KEY54)
#define CTSUSO0_MUTUAL2_KEY55           ((CTSUSNUM_MUTUAL2_KEY55 << 10) | CTSUSO_MUTUAL2_KEY55)
#define CTSUSO0_MUTUAL2_KEY56           ((CTSUSNUM_MUTUAL2_KEY56 << 10) | CTSUSO_MUTUAL2_KEY56)
#define CTSUSO0_MUTUAL2_KEY57           ((CTSUSNUM_MUTUAL2_KEY57 << 10) | CTSUSO_MUTUAL2_KEY57)
#define CTSUSO0_MUTUAL2_KEY58           ((CTSUSNUM_MUTUAL2_KEY58 << 10) | CTSUSO_MUTUAL2_KEY58)
#define CTSUSO0_MUTUAL2_KEY59           ((CTSUSNUM_MUTUAL2_KEY59 << 10) | CTSUSO_MUTUAL2_KEY59)
#define CTSUSO0_MUTUAL2_KEY60           ((CTSUSNUM_MUTUAL2_KEY60 << 10) | CTSUSO_MUTUAL2_KEY60)
#define CTSUSO0_MUTUAL2_KEY61           ((CTSUSNUM_MUTUAL2_KEY61 << 10) | CTSUSO_MUTUAL2_KEY61)
#define CTSUSO0_MUTUAL2_KEY62           ((CTSUSNUM_MUTUAL2_KEY62 << 10) | CTSUSO_MUTUAL2_KEY62)
#define CTSUSO0_MUTUAL2_KEY63           ((CTSUSNUM_MUTUAL2_KEY63 << 10) | CTSUSO_MUTUAL2_KEY63)

/*****    Address 000A 0914h CTSU Sensor Offset Register 1    *********************************************************/
/**********************************************************************************************************************/
/*    CTSU Reference ICO Current Adjustment                                                                           */
/*        Input current amount 0      0x00                                                                            */
/*        Input current amount 1      0x01                                                                            */
/*        Input current amount 2      0x02                                                                            */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*        Input current amount 254    0xFF                                                                            */
/**********************************************************************************************************************/
#define CTSURICOA_MUTUAL2_KEY00         (0x3F)                  /* Mutual 2 Key00 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY01         (0x3F)                  /* Mutual 2 Key01 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY02         (0x3F)                  /* Mutual 2 Key02 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY03         (0x3F)                  /* Mutual 2 Key03 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY04         (0x3F)                  /* Mutual 2 Key04 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY05         (0x3F)                  /* Mutual 2 Key05 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY06         (0x3F)                  /* Mutual 2 Key06 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY07         (0x3F)                  /* Mutual 2 Key07 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY08         (0x3F)                  /* Mutual 2 Key08 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY09         (0x3F)                  /* Mutual 2 Key09 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY10         (0x3F)                  /* Mutual 2 Key10 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY11         (0x3F)                  /* Mutual 2 Key11 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY12         (0x3F)                  /* Mutual 2 Key12 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY13         (0x3F)                  /* Mutual 2 Key13 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY14         (0x3F)                  /* Mutual 2 Key14 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY15         (0x3F)                  /* Mutual 2 Key15 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY16         (0x3F)                  /* Mutual 2 Key16 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY17         (0x3F)                  /* Mutual 2 Key17 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY18         (0x3F)                  /* Mutual 2 Key18 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY19         (0x3F)                  /* Mutual 2 Key19 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY20         (0x3F)                  /* Mutual 2 Key20 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY21         (0x3F)                  /* Mutual 2 Key21 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY22         (0x3F)                  /* Mutual 2 Key22 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY23         (0x3F)                  /* Mutual 2 Key23 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY24         (0x3F)                  /* Mutual 2 Key24 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY25         (0x3F)                  /* Mutual 2 Key25 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY26         (0x3F)                  /* Mutual 2 Key26 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY27         (0x3F)                  /* Mutual 2 Key27 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY28         (0x3F)                  /* Mutual 2 Key28 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY29         (0x3F)                  /* Mutual 2 Key29 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY30         (0x3F)                  /* Mutual 2 Key30 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY31         (0x3F)                  /* Mutual 2 Key31 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY32         (0x3F)                  /* Mutual 2 Key32 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY33         (0x3F)                  /* Mutual 2 Key33 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY34         (0x3F)                  /* Mutual 2 Key34 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY35         (0x3F)                  /* Mutual 2 Key35 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY36         (0x3F)                  /* Mutual 2 Key36 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY37         (0x3F)                  /* Mutual 2 Key37 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY38         (0x3F)                  /* Mutual 2 Key38 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY39         (0x3F)                  /* Mutual 2 Key39 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY40         (0x3F)                  /* Mutual 2 Key40 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY41         (0x3F)                  /* Mutual 2 Key41 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY42         (0x3F)                  /* Mutual 2 Key42 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY43         (0x3F)                  /* Mutual 2 Key43 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY44         (0x3F)                  /* Mutual 2 Key44 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY45         (0x3F)                  /* Mutual 2 Key45 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY46         (0x3F)                  /* Mutual 2 Key46 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY47         (0x3F)                  /* Mutual 2 Key47 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY48         (0x3F)                  /* Mutual 2 Key48 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY49         (0x3F)                  /* Mutual 2 Key49 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY50         (0x3F)                  /* Mutual 2 Key50 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY51         (0x3F)                  /* Mutual 2 Key51 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY52         (0x3F)                  /* Mutual 2 Key52 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY53         (0x3F)                  /* Mutual 2 Key53 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY54         (0x3F)                  /* Mutual 2 Key54 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY55         (0x3F)                  /* Mutual 2 Key55 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY56         (0x3F)                  /* Mutual 2 Key56 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY57         (0x3F)                  /* Mutual 2 Key57 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY58         (0x3F)                  /* Mutual 2 Key58 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY59         (0x3F)                  /* Mutual 2 Key59 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY60         (0x3F)                  /* Mutual 2 Key60 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY61         (0x3F)                  /* Mutual 2 Key61 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY62         (0x3F)                  /* Mutual 2 Key62 CTSUICOA                            */
#define CTSURICOA_MUTUAL2_KEY63         (0x3F)                  /* Mutual 2 Key63 CTSUICOA                            */

/**********************************************************************************************************************/
/*    CTSU Base Clock Setting                                                                                         */
/*        Operating clock divided by 2     0x00                                                                       */
/*        Operating clock divided by 4     0x01                                                                       */
/*        Operating clock divided by 6     0x02                                                                       */
/*                       :                                                                                            */
/*                       :                                                                                            */
/*        Operating clock divided by 64    0x1F                                                                       */
/*                                                                                                                    */
/*    Case : CTSU Operating Clock 32MHz      Case : CTSU Operating Clock 24MHz      Case : CTSU Operating Clock 16MHz */
/*           4.0MHz <--- 0x03                       4.0MHz <--- 0x02                       4.0MHz <--- 0x01           */
/*           2.0MHz <--- 0x07                       2.0MHz <--- 0x05                       2.0MHz <--- 0x03           */
/*           1.0MHz <--- 0x0F                       1.0MHz <--- 0x0B                       1.0MHz <--- 0x07           */
/*           0.5MHz <--- 0x1F                       0.5MHz <--- 0x17                       0.5MHz <--- 0x0F           */
/**********************************************************************************************************************/
#define CTSUSDPA_MUTUAL2_KEY00          (7)                     /* Mutual 2 Key00 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY01          (7)                     /* Mutual 2 Key01 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY02          (7)                     /* Mutual 2 Key02 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY03          (7)                     /* Mutual 2 Key03 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY04          (7)                     /* Mutual 2 Key04 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY05          (7)                     /* Mutual 2 Key05 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY06          (7)                     /* Mutual 2 Key06 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY07          (7)                     /* Mutual 2 Key07 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY08          (7)                     /* Mutual 2 Key08 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY09          (7)                     /* Mutual 2 Key09 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY10          (7)                     /* Mutual 2 Key10 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY11          (7)                     /* Mutual 2 Key11 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY12          (7)                     /* Mutual 2 Key12 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY13          (7)                     /* Mutual 2 Key13 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY14          (7)                     /* Mutual 2 Key14 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY15          (7)                     /* Mutual 2 Key15 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY16          (7)                     /* Mutual 2 Key16 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY17          (7)                     /* Mutual 2 Key17 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY18          (7)                     /* Mutual 2 Key18 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY19          (7)                     /* Mutual 2 Key19 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY20          (7)                     /* Mutual 2 Key20 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY21          (7)                     /* Mutual 2 Key21 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY22          (7)                     /* Mutual 2 Key22 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY23          (7)                     /* Mutual 2 Key23 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY24          (7)                     /* Mutual 2 Key24 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY25          (7)                     /* Mutual 2 Key25 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY26          (7)                     /* Mutual 2 Key26 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY27          (7)                     /* Mutual 2 Key27 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY28          (7)                     /* Mutual 2 Key28 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY29          (7)                     /* Mutual 2 Key29 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY30          (7)                     /* Mutual 2 Key30 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY31          (7)                     /* Mutual 2 Key31 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY32          (7)                     /* Mutual 2 Key32 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY33          (7)                     /* Mutual 2 Key33 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY34          (7)                     /* Mutual 2 Key34 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY35          (7)                     /* Mutual 2 Key35 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY36          (7)                     /* Mutual 2 Key36 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY37          (7)                     /* Mutual 2 Key37 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY38          (7)                     /* Mutual 2 Key38 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY39          (7)                     /* Mutual 2 Key39 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY40          (7)                     /* Mutual 2 Key40 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY41          (7)                     /* Mutual 2 Key41 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY42          (7)                     /* Mutual 2 Key42 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY43          (7)                     /* Mutual 2 Key43 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY44          (7)                     /* Mutual 2 Key44 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY45          (7)                     /* Mutual 2 Key45 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY46          (7)                     /* Mutual 2 Key46 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY47          (7)                     /* Mutual 2 Key47 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY48          (7)                     /* Mutual 2 Key48 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY49          (7)                     /* Mutual 2 Key49 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY50          (7)                     /* Mutual 2 Key50 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY51          (7)                     /* Mutual 2 Key51 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY52          (7)                     /* Mutual 2 Key52 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY53          (7)                     /* Mutual 2 Key53 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY54          (7)                     /* Mutual 2 Key54 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY55          (7)                     /* Mutual 2 Key55 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY56          (7)                     /* Mutual 2 Key56 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY57          (7)                     /* Mutual 2 Key57 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY58          (7)                     /* Mutual 2 Key58 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY59          (7)                     /* Mutual 2 Key59 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY60          (7)                     /* Mutual 2 Key60 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY61          (7)                     /* Mutual 2 Key61 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY62          (7)                     /* Mutual 2 Key62 CTSUDPA                             */
#define CTSUSDPA_MUTUAL2_KEY63          (7)                     /* Mutual 2 Key63 CTSUDPA                             */

/**********************************************************************************************************************/
/*    CTSU ICO Gain Adjustment                                                                                        */
/*        0 : 100% gain                                                                                               */
/*        1 :  66% gain                                                                                               */
/*        2 :  50% gain                                                                                               */
/*        3 :  40% gain                                                                                               */
/**********************************************************************************************************************/
#define CTSUICOG_MUTUAL2_KEY00          (1)                     /* Mutual 2 Key00 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY01          (1)                     /* Mutual 2 Key01 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY02          (1)                     /* Mutual 2 Key02 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY03          (1)                     /* Mutual 2 Key03 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY04          (1)                     /* Mutual 2 Key04 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY05          (1)                     /* Mutual 2 Key05 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY06          (1)                     /* Mutual 2 Key06 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY07          (1)                     /* Mutual 2 Key07 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY08          (1)                     /* Mutual 2 Key08 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY09          (1)                     /* Mutual 2 Key09 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY10          (1)                     /* Mutual 2 Key10 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY11          (1)                     /* Mutual 2 Key11 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY12          (1)                     /* Mutual 2 Key12 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY13          (1)                     /* Mutual 2 Key13 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY14          (1)                     /* Mutual 2 Key14 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY15          (1)                     /* Mutual 2 Key15 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY16          (1)                     /* Mutual 2 Key16 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY17          (1)                     /* Mutual 2 Key17 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY18          (1)                     /* Mutual 2 Key18 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY19          (1)                     /* Mutual 2 Key19 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY20          (1)                     /* Mutual 2 Key20 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY21          (1)                     /* Mutual 2 Key21 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY22          (1)                     /* Mutual 2 Key22 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY23          (1)                     /* Mutual 2 Key23 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY24          (1)                     /* Mutual 2 Key24 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY25          (1)                     /* Mutual 2 Key25 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY26          (1)                     /* Mutual 2 Key26 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY27          (1)                     /* Mutual 2 Key27 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY28          (1)                     /* Mutual 2 Key28 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY29          (1)                     /* Mutual 2 Key29 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY30          (1)                     /* Mutual 2 Key30 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY31          (1)                     /* Mutual 2 Key31 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY32          (1)                     /* Mutual 2 Key32 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY33          (1)                     /* Mutual 2 Key33 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY34          (1)                     /* Mutual 2 Key34 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY35          (1)                     /* Mutual 2 Key35 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY36          (1)                     /* Mutual 2 Key36 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY37          (1)                     /* Mutual 2 Key37 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY38          (1)                     /* Mutual 2 Key38 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY39          (1)                     /* Mutual 2 Key39 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY40          (1)                     /* Mutual 2 Key40 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY41          (1)                     /* Mutual 2 Key41 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY42          (1)                     /* Mutual 2 Key42 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY43          (1)                     /* Mutual 2 Key43 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY44          (1)                     /* Mutual 2 Key44 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY45          (1)                     /* Mutual 2 Key45 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY46          (1)                     /* Mutual 2 Key46 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY47          (1)                     /* Mutual 2 Key47 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY48          (1)                     /* Mutual 2 Key48 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY49          (1)                     /* Mutual 2 Key49 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY50          (1)                     /* Mutual 2 Key50 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY51          (1)                     /* Mutual 2 Key51 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY52          (1)                     /* Mutual 2 Key52 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY53          (1)                     /* Mutual 2 Key53 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY54          (1)                     /* Mutual 2 Key54 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY55          (1)                     /* Mutual 2 Key55 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY56          (1)                     /* Mutual 2 Key56 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY57          (1)                     /* Mutual 2 Key57 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY58          (1)                     /* Mutual 2 Key58 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY59          (1)                     /* Mutual 2 Key59 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY60          (1)                     /* Mutual 2 Key60 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY61          (1)                     /* Mutual 2 Key61 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY62          (1)                     /* Mutual 2 Key62 CTSICOG                             */
#define CTSUICOG_MUTUAL2_KEY63          (1)                     /* Mutual 2 Key63 CTSICOG                             */

#define CTSUSO1_MUTUAL2_KEY00  ((CTSUICOG_MUTUAL2_KEY00 << 13) | (CTSUSDPA_MUTUAL2_KEY00 << 8) | CTSURICOA_MUTUAL2_KEY00)
#define CTSUSO1_MUTUAL2_KEY01  ((CTSUICOG_MUTUAL2_KEY01 << 13) | (CTSUSDPA_MUTUAL2_KEY01 << 8) | CTSURICOA_MUTUAL2_KEY01)
#define CTSUSO1_MUTUAL2_KEY02  ((CTSUICOG_MUTUAL2_KEY02 << 13) | (CTSUSDPA_MUTUAL2_KEY02 << 8) | CTSURICOA_MUTUAL2_KEY02)
#define CTSUSO1_MUTUAL2_KEY03  ((CTSUICOG_MUTUAL2_KEY03 << 13) | (CTSUSDPA_MUTUAL2_KEY03 << 8) | CTSURICOA_MUTUAL2_KEY03)
#define CTSUSO1_MUTUAL2_KEY04  ((CTSUICOG_MUTUAL2_KEY04 << 13) | (CTSUSDPA_MUTUAL2_KEY04 << 8) | CTSURICOA_MUTUAL2_KEY04)
#define CTSUSO1_MUTUAL2_KEY05  ((CTSUICOG_MUTUAL2_KEY05 << 13) | (CTSUSDPA_MUTUAL2_KEY05 << 8) | CTSURICOA_MUTUAL2_KEY05)
#define CTSUSO1_MUTUAL2_KEY06  ((CTSUICOG_MUTUAL2_KEY06 << 13) | (CTSUSDPA_MUTUAL2_KEY06 << 8) | CTSURICOA_MUTUAL2_KEY06)
#define CTSUSO1_MUTUAL2_KEY07  ((CTSUICOG_MUTUAL2_KEY07 << 13) | (CTSUSDPA_MUTUAL2_KEY07 << 8) | CTSURICOA_MUTUAL2_KEY07)
#define CTSUSO1_MUTUAL2_KEY08  ((CTSUICOG_MUTUAL2_KEY08 << 13) | (CTSUSDPA_MUTUAL2_KEY08 << 8) | CTSURICOA_MUTUAL2_KEY08)
#define CTSUSO1_MUTUAL2_KEY09  ((CTSUICOG_MUTUAL2_KEY09 << 13) | (CTSUSDPA_MUTUAL2_KEY09 << 8) | CTSURICOA_MUTUAL2_KEY09)
#define CTSUSO1_MUTUAL2_KEY10  ((CTSUICOG_MUTUAL2_KEY10 << 13) | (CTSUSDPA_MUTUAL2_KEY10 << 8) | CTSURICOA_MUTUAL2_KEY10)
#define CTSUSO1_MUTUAL2_KEY11  ((CTSUICOG_MUTUAL2_KEY11 << 13) | (CTSUSDPA_MUTUAL2_KEY11 << 8) | CTSURICOA_MUTUAL2_KEY11)
#define CTSUSO1_MUTUAL2_KEY12  ((CTSUICOG_MUTUAL2_KEY12 << 13) | (CTSUSDPA_MUTUAL2_KEY12 << 8) | CTSURICOA_MUTUAL2_KEY12)
#define CTSUSO1_MUTUAL2_KEY13  ((CTSUICOG_MUTUAL2_KEY13 << 13) | (CTSUSDPA_MUTUAL2_KEY13 << 8) | CTSURICOA_MUTUAL2_KEY13)
#define CTSUSO1_MUTUAL2_KEY14  ((CTSUICOG_MUTUAL2_KEY14 << 13) | (CTSUSDPA_MUTUAL2_KEY14 << 8) | CTSURICOA_MUTUAL2_KEY14)
#define CTSUSO1_MUTUAL2_KEY15  ((CTSUICOG_MUTUAL2_KEY15 << 13) | (CTSUSDPA_MUTUAL2_KEY15 << 8) | CTSURICOA_MUTUAL2_KEY15)
#define CTSUSO1_MUTUAL2_KEY16  ((CTSUICOG_MUTUAL2_KEY16 << 13) | (CTSUSDPA_MUTUAL2_KEY16 << 8) | CTSURICOA_MUTUAL2_KEY16)
#define CTSUSO1_MUTUAL2_KEY17  ((CTSUICOG_MUTUAL2_KEY17 << 13) | (CTSUSDPA_MUTUAL2_KEY17 << 8) | CTSURICOA_MUTUAL2_KEY17)
#define CTSUSO1_MUTUAL2_KEY18  ((CTSUICOG_MUTUAL2_KEY18 << 13) | (CTSUSDPA_MUTUAL2_KEY18 << 8) | CTSURICOA_MUTUAL2_KEY18)
#define CTSUSO1_MUTUAL2_KEY19  ((CTSUICOG_MUTUAL2_KEY19 << 13) | (CTSUSDPA_MUTUAL2_KEY19 << 8) | CTSURICOA_MUTUAL2_KEY19)
#define CTSUSO1_MUTUAL2_KEY20  ((CTSUICOG_MUTUAL2_KEY20 << 13) | (CTSUSDPA_MUTUAL2_KEY20 << 8) | CTSURICOA_MUTUAL2_KEY20)
#define CTSUSO1_MUTUAL2_KEY21  ((CTSUICOG_MUTUAL2_KEY21 << 13) | (CTSUSDPA_MUTUAL2_KEY21 << 8) | CTSURICOA_MUTUAL2_KEY21)
#define CTSUSO1_MUTUAL2_KEY22  ((CTSUICOG_MUTUAL2_KEY22 << 13) | (CTSUSDPA_MUTUAL2_KEY22 << 8) | CTSURICOA_MUTUAL2_KEY22)
#define CTSUSO1_MUTUAL2_KEY23  ((CTSUICOG_MUTUAL2_KEY23 << 13) | (CTSUSDPA_MUTUAL2_KEY23 << 8) | CTSURICOA_MUTUAL2_KEY23)
#define CTSUSO1_MUTUAL2_KEY24  ((CTSUICOG_MUTUAL2_KEY24 << 13) | (CTSUSDPA_MUTUAL2_KEY24 << 8) | CTSURICOA_MUTUAL2_KEY24)
#define CTSUSO1_MUTUAL2_KEY25  ((CTSUICOG_MUTUAL2_KEY25 << 13) | (CTSUSDPA_MUTUAL2_KEY25 << 8) | CTSURICOA_MUTUAL2_KEY25)
#define CTSUSO1_MUTUAL2_KEY26  ((CTSUICOG_MUTUAL2_KEY26 << 13) | (CTSUSDPA_MUTUAL2_KEY26 << 8) | CTSURICOA_MUTUAL2_KEY26)
#define CTSUSO1_MUTUAL2_KEY27  ((CTSUICOG_MUTUAL2_KEY27 << 13) | (CTSUSDPA_MUTUAL2_KEY27 << 8) | CTSURICOA_MUTUAL2_KEY27)
#define CTSUSO1_MUTUAL2_KEY28  ((CTSUICOG_MUTUAL2_KEY28 << 13) | (CTSUSDPA_MUTUAL2_KEY28 << 8) | CTSURICOA_MUTUAL2_KEY28)
#define CTSUSO1_MUTUAL2_KEY29  ((CTSUICOG_MUTUAL2_KEY29 << 13) | (CTSUSDPA_MUTUAL2_KEY29 << 8) | CTSURICOA_MUTUAL2_KEY29)
#define CTSUSO1_MUTUAL2_KEY30  ((CTSUICOG_MUTUAL2_KEY30 << 13) | (CTSUSDPA_MUTUAL2_KEY30 << 8) | CTSURICOA_MUTUAL2_KEY30)
#define CTSUSO1_MUTUAL2_KEY31  ((CTSUICOG_MUTUAL2_KEY31 << 13) | (CTSUSDPA_MUTUAL2_KEY31 << 8) | CTSURICOA_MUTUAL2_KEY31)
#define CTSUSO1_MUTUAL2_KEY32  ((CTSUICOG_MUTUAL2_KEY32 << 13) | (CTSUSDPA_MUTUAL2_KEY32 << 8) | CTSURICOA_MUTUAL2_KEY32)
#define CTSUSO1_MUTUAL2_KEY33  ((CTSUICOG_MUTUAL2_KEY33 << 13) | (CTSUSDPA_MUTUAL2_KEY33 << 8) | CTSURICOA_MUTUAL2_KEY33)
#define CTSUSO1_MUTUAL2_KEY34  ((CTSUICOG_MUTUAL2_KEY34 << 13) | (CTSUSDPA_MUTUAL2_KEY34 << 8) | CTSURICOA_MUTUAL2_KEY34)
#define CTSUSO1_MUTUAL2_KEY35  ((CTSUICOG_MUTUAL2_KEY35 << 13) | (CTSUSDPA_MUTUAL2_KEY35 << 8) | CTSURICOA_MUTUAL2_KEY35)
#define CTSUSO1_MUTUAL2_KEY36  ((CTSUICOG_MUTUAL2_KEY36 << 13) | (CTSUSDPA_MUTUAL2_KEY36 << 8) | CTSURICOA_MUTUAL2_KEY36)
#define CTSUSO1_MUTUAL2_KEY37  ((CTSUICOG_MUTUAL2_KEY37 << 13) | (CTSUSDPA_MUTUAL2_KEY37 << 8) | CTSURICOA_MUTUAL2_KEY37)
#define CTSUSO1_MUTUAL2_KEY38  ((CTSUICOG_MUTUAL2_KEY38 << 13) | (CTSUSDPA_MUTUAL2_KEY38 << 8) | CTSURICOA_MUTUAL2_KEY38)
#define CTSUSO1_MUTUAL2_KEY39  ((CTSUICOG_MUTUAL2_KEY39 << 13) | (CTSUSDPA_MUTUAL2_KEY39 << 8) | CTSURICOA_MUTUAL2_KEY39)
#define CTSUSO1_MUTUAL2_KEY40  ((CTSUICOG_MUTUAL2_KEY40 << 13) | (CTSUSDPA_MUTUAL2_KEY40 << 8) | CTSURICOA_MUTUAL2_KEY40)
#define CTSUSO1_MUTUAL2_KEY41  ((CTSUICOG_MUTUAL2_KEY41 << 13) | (CTSUSDPA_MUTUAL2_KEY41 << 8) | CTSURICOA_MUTUAL2_KEY41)
#define CTSUSO1_MUTUAL2_KEY42  ((CTSUICOG_MUTUAL2_KEY42 << 13) | (CTSUSDPA_MUTUAL2_KEY42 << 8) | CTSURICOA_MUTUAL2_KEY42)
#define CTSUSO1_MUTUAL2_KEY43  ((CTSUICOG_MUTUAL2_KEY43 << 13) | (CTSUSDPA_MUTUAL2_KEY43 << 8) | CTSURICOA_MUTUAL2_KEY43)
#define CTSUSO1_MUTUAL2_KEY44  ((CTSUICOG_MUTUAL2_KEY44 << 13) | (CTSUSDPA_MUTUAL2_KEY44 << 8) | CTSURICOA_MUTUAL2_KEY44)
#define CTSUSO1_MUTUAL2_KEY45  ((CTSUICOG_MUTUAL2_KEY45 << 13) | (CTSUSDPA_MUTUAL2_KEY45 << 8) | CTSURICOA_MUTUAL2_KEY45)
#define CTSUSO1_MUTUAL2_KEY46  ((CTSUICOG_MUTUAL2_KEY46 << 13) | (CTSUSDPA_MUTUAL2_KEY46 << 8) | CTSURICOA_MUTUAL2_KEY46)
#define CTSUSO1_MUTUAL2_KEY47  ((CTSUICOG_MUTUAL2_KEY47 << 13) | (CTSUSDPA_MUTUAL2_KEY47 << 8) | CTSURICOA_MUTUAL2_KEY47)
#define CTSUSO1_MUTUAL2_KEY48  ((CTSUICOG_MUTUAL2_KEY48 << 13) | (CTSUSDPA_MUTUAL2_KEY48 << 8) | CTSURICOA_MUTUAL2_KEY48)
#define CTSUSO1_MUTUAL2_KEY49  ((CTSUICOG_MUTUAL2_KEY49 << 13) | (CTSUSDPA_MUTUAL2_KEY49 << 8) | CTSURICOA_MUTUAL2_KEY49)
#define CTSUSO1_MUTUAL2_KEY50  ((CTSUICOG_MUTUAL2_KEY50 << 13) | (CTSUSDPA_MUTUAL2_KEY50 << 8) | CTSURICOA_MUTUAL2_KEY50)
#define CTSUSO1_MUTUAL2_KEY51  ((CTSUICOG_MUTUAL2_KEY51 << 13) | (CTSUSDPA_MUTUAL2_KEY51 << 8) | CTSURICOA_MUTUAL2_KEY51)
#define CTSUSO1_MUTUAL2_KEY52  ((CTSUICOG_MUTUAL2_KEY52 << 13) | (CTSUSDPA_MUTUAL2_KEY52 << 8) | CTSURICOA_MUTUAL2_KEY52)
#define CTSUSO1_MUTUAL2_KEY53  ((CTSUICOG_MUTUAL2_KEY53 << 13) | (CTSUSDPA_MUTUAL2_KEY53 << 8) | CTSURICOA_MUTUAL2_KEY53)
#define CTSUSO1_MUTUAL2_KEY54  ((CTSUICOG_MUTUAL2_KEY54 << 13) | (CTSUSDPA_MUTUAL2_KEY54 << 8) | CTSURICOA_MUTUAL2_KEY54)
#define CTSUSO1_MUTUAL2_KEY55  ((CTSUICOG_MUTUAL2_KEY55 << 13) | (CTSUSDPA_MUTUAL2_KEY55 << 8) | CTSURICOA_MUTUAL2_KEY55)
#define CTSUSO1_MUTUAL2_KEY56  ((CTSUICOG_MUTUAL2_KEY56 << 13) | (CTSUSDPA_MUTUAL2_KEY56 << 8) | CTSURICOA_MUTUAL2_KEY56)
#define CTSUSO1_MUTUAL2_KEY57  ((CTSUICOG_MUTUAL2_KEY57 << 13) | (CTSUSDPA_MUTUAL2_KEY57 << 8) | CTSURICOA_MUTUAL2_KEY57)
#define CTSUSO1_MUTUAL2_KEY58  ((CTSUICOG_MUTUAL2_KEY58 << 13) | (CTSUSDPA_MUTUAL2_KEY58 << 8) | CTSURICOA_MUTUAL2_KEY58)
#define CTSUSO1_MUTUAL2_KEY59  ((CTSUICOG_MUTUAL2_KEY59 << 13) | (CTSUSDPA_MUTUAL2_KEY59 << 8) | CTSURICOA_MUTUAL2_KEY59)
#define CTSUSO1_MUTUAL2_KEY60  ((CTSUICOG_MUTUAL2_KEY60 << 13) | (CTSUSDPA_MUTUAL2_KEY60 << 8) | CTSURICOA_MUTUAL2_KEY60)
#define CTSUSO1_MUTUAL2_KEY61  ((CTSUICOG_MUTUAL2_KEY61 << 13) | (CTSUSDPA_MUTUAL2_KEY61 << 8) | CTSURICOA_MUTUAL2_KEY61)
#define CTSUSO1_MUTUAL2_KEY62  ((CTSUICOG_MUTUAL2_KEY62 << 13) | (CTSUSDPA_MUTUAL2_KEY62 << 8) | CTSURICOA_MUTUAL2_KEY62)
#define CTSUSO1_MUTUAL2_KEY63  ((CTSUICOG_MUTUAL2_KEY63 << 13) | (CTSUSDPA_MUTUAL2_KEY63 << 8) | CTSURICOA_MUTUAL2_KEY63)
#endif    // ( MUTUAL_METHOD_NUM >= 3 )

#if ( MUTUAL_METHOD_NUM >= 4 )
/*====================================================================================================================*/
/*=====     Mutual-measurement 3 TS enable definition    =============================================================*/
/*====================================================================================================================*/
#define MUTUAL3_ENABLE_TS00              (0)        /* Mutual 3 TS00 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS01              (0)        /* Mutual 3 TS01 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS02              (0)        /* Mutual 3 TS02 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS03              (0)        /* Mutual 3 TS03 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS04              (0)        /* Mutual 3 TS04 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS05              (0)        /* Mutual 3 TS05 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS06              (0)        /* Mutual 3 TS06 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS07              (0)        /* Mutual 3 TS07 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS08              (0)        /* Mutual 3 TS08 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS09              (0)        /* Mutual 3 TS09 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS10              (0)        /* Mutual 3 TS10 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS11              (0)        /* Mutual 3 TS11 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS12              (0)        /* Mutual 3 TS12 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS13              (0)        /* Mutual 3 TS13 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS14              (0)        /* Mutual 3 TS14 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS15              (0)        /* Mutual 3 TS15 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS16              (0)        /* Mutual 3 TS16 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS17              (0)        /* Mutual 3 TS17 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS18              (0)        /* Mutual 3 TS18 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS19              (0)        /* Mutual 3 TS19 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS20              (0)        /* Mutual 3 TS20 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS21              (0)        /* Mutual 3 TS21 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS22              (0)        /* Mutual 3 TS22 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS23              (0)        /* Mutual 3 TS23 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS24              (0)        /* Mutual 3 TS24 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS25              (0)        /* Mutual 3 TS25 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS26              (0)        /* Mutual 3 TS26 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS27              (0)        /* Mutual 3 TS27 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS28              (0)        /* Mutual 3 TS28 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS29              (0)        /* Mutual 3 TS29 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS30              (0)        /* Mutual 3 TS30 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS31              (0)        /* Mutual 3 TS31 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS32              (0)        /* Mutual 3 TS32 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS33              (0)        /* Mutual 3 TS33 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS34              (0)        /* Mutual 3 TS34 0:disable 1:enable                               */
#define MUTUAL3_ENABLE_TS35              (0)        /* Mutual 3 TS35 0:disable 1:enable                               */

/*****    Address 000A 0906h CTSU Channel enable control register 0    ************************************************/
#define CTSUCHAC0_MUTUAL3_ENABLE_TS      ((MUTUAL3_ENABLE_TS00 << 0) | (MUTUAL3_ENABLE_TS01 << 1) | \
                                          (MUTUAL3_ENABLE_TS02 << 2) | (MUTUAL3_ENABLE_TS03 << 3) | \
                                          (MUTUAL3_ENABLE_TS04 << 4) | (MUTUAL3_ENABLE_TS05 << 5) | \
                                          (MUTUAL3_ENABLE_TS06 << 6) | (MUTUAL3_ENABLE_TS07 << 7))

/*****    Address 000A 0907h CTSU Channel enable control register 1    ************************************************/
#define CTSUCHAC1_MUTUAL3_ENABLE_TS      ((MUTUAL3_ENABLE_TS08 << 0) | (MUTUAL3_ENABLE_TS09 << 1) | \
                                          (MUTUAL3_ENABLE_TS10 << 2) | (MUTUAL3_ENABLE_TS11 << 3) | \
                                          (MUTUAL3_ENABLE_TS12 << 4) | (MUTUAL3_ENABLE_TS13 << 5) | \
                                          (MUTUAL3_ENABLE_TS14 << 6) | (MUTUAL3_ENABLE_TS15 << 7))

/*****    Address 000A 0908h CTSU Channel enable control register 2    ************************************************/
#define CTSUCHAC2_MUTUAL3_ENABLE_TS      ((MUTUAL3_ENABLE_TS16 << 0) | (MUTUAL3_ENABLE_TS17 << 1) | \
                                          (MUTUAL3_ENABLE_TS18 << 2) | (MUTUAL3_ENABLE_TS19 << 3) | \
                                          (MUTUAL3_ENABLE_TS20 << 4) | (MUTUAL3_ENABLE_TS21 << 5) | \
                                          (MUTUAL3_ENABLE_TS22 << 6) | (MUTUAL3_ENABLE_TS23 << 7))

/*****    Address 000A 0909h CTSU Channel enable control register 3    ************************************************/
#define CTSUCHAC3_MUTUAL3_ENABLE_TS      ((MUTUAL3_ENABLE_TS24 << 0) | (MUTUAL3_ENABLE_TS25 << 1) | \
                                          (MUTUAL3_ENABLE_TS26 << 2) | (MUTUAL3_ENABLE_TS27 << 3) | \
                                          (MUTUAL3_ENABLE_TS28 << 4) | (MUTUAL3_ENABLE_TS29 << 5) | \
                                          (MUTUAL3_ENABLE_TS30 << 6) | (MUTUAL3_ENABLE_TS31 << 7))

/*****    Address 000A 090ah CTSU Channel enable control register 4    ************************************************/
#define CTSUCHAC4_MUTUAL3_ENABLE_TS      ((MUTUAL3_ENABLE_TS32 << 0) | (MUTUAL3_ENABLE_TS33 << 1) | \
                                          (MUTUAL3_ENABLE_TS34 << 2) | (MUTUAL3_ENABLE_TS35 << 3))

/* SUM of Channels */ /* Do not edit this macro definition */
#define MUTUAL3_ENABLE_NUM               (MUTUAL3_ENABLE_TS00 + MUTUAL3_ENABLE_TS01 + MUTUAL3_ENABLE_TS02 + \
                                          MUTUAL3_ENABLE_TS03 + MUTUAL3_ENABLE_TS04 + MUTUAL3_ENABLE_TS05 + \
                                          MUTUAL3_ENABLE_TS06 + MUTUAL3_ENABLE_TS07 + MUTUAL3_ENABLE_TS08 + \
                                          MUTUAL3_ENABLE_TS09 + MUTUAL3_ENABLE_TS10 + MUTUAL3_ENABLE_TS11 + \
                                          MUTUAL3_ENABLE_TS12 + MUTUAL3_ENABLE_TS13 + MUTUAL3_ENABLE_TS14 + \
                                          MUTUAL3_ENABLE_TS15 + MUTUAL3_ENABLE_TS16 + MUTUAL3_ENABLE_TS17 + \
                                          MUTUAL3_ENABLE_TS18 + MUTUAL3_ENABLE_TS19 + MUTUAL3_ENABLE_TS20 + \
                                          MUTUAL3_ENABLE_TS21 + MUTUAL3_ENABLE_TS22 + MUTUAL3_ENABLE_TS23 + \
                                          MUTUAL3_ENABLE_TS24 + MUTUAL3_ENABLE_TS25 + MUTUAL3_ENABLE_TS26 + \
                                          MUTUAL3_ENABLE_TS27 + MUTUAL3_ENABLE_TS28 + MUTUAL3_ENABLE_TS29 + \
                                          MUTUAL3_ENABLE_TS30 + MUTUAL3_ENABLE_TS31 + MUTUAL3_ENABLE_TS32 + \
                                          MUTUAL3_ENABLE_TS33 + MUTUAL3_ENABLE_TS34 + MUTUAL3_ENABLE_TS35)

/*====================================================================================================================*/
/*=====     Mutual-measurement 0 function definition     =============================================================*/
/*====================================================================================================================*/
#define MUTUAL3_FUNCTION_TS00            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS01            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS02            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS03            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS04            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS05            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS06            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS07            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS08            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS09            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS10            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS11            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS12            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS13            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS14            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS15            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS16            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS17            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS18            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS19            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS20            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS21            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS22            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS23            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS24            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS25            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS26            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS27            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS28            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS29            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS30            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS31            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS32            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS33            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS34            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL3_FUNCTION_TS35            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */

/*****    Address 000A 090Bh CTSU Channel send and receive control register 0 *****************************************/
#define CTSUCHTRC0_MUTUAL3_TRANSMIT_TS   ((MUTUAL3_FUNCTION_TS00 << 0) | (MUTUAL3_FUNCTION_TS01 << 1) | \
                                          (MUTUAL3_FUNCTION_TS02 << 2) | (MUTUAL3_FUNCTION_TS03 << 3) | \
                                          (MUTUAL3_FUNCTION_TS04 << 4) | (MUTUAL3_FUNCTION_TS05 << 5) | \
                                          (MUTUAL3_FUNCTION_TS06 << 6) | (MUTUAL3_FUNCTION_TS07 << 7))

/*****    Address 000A 090Ch CTSU Channel send and receive control register 1 *****************************************/
#define CTSUCHTRC1_MUTUAL3_TRANSMIT_TS   ((MUTUAL3_FUNCTION_TS08 << 0) | (MUTUAL3_FUNCTION_TS09 << 1) | \
                                          (MUTUAL3_FUNCTION_TS10 << 2) | (MUTUAL3_FUNCTION_TS11 << 3) | \
                                          (MUTUAL3_FUNCTION_TS12 << 4) | (MUTUAL3_FUNCTION_TS13 << 5) | \
                                          (MUTUAL3_FUNCTION_TS14 << 6) | (MUTUAL3_FUNCTION_TS15 << 7))

/*****    Address 000A 090Dh CTSU Channel send and receive control register 2 *****************************************/
#define CTSUCHTRC2_MUTUAL3_TRANSMIT_TS   ((MUTUAL3_FUNCTION_TS16 << 0) | (MUTUAL3_FUNCTION_TS17 << 1) | \
                                          (MUTUAL3_FUNCTION_TS18 << 2) | (MUTUAL3_FUNCTION_TS19 << 3) | \
                                          (MUTUAL3_FUNCTION_TS20 << 4) | (MUTUAL3_FUNCTION_TS21 << 5) | \
                                          (MUTUAL3_FUNCTION_TS22 << 6) | (MUTUAL3_FUNCTION_TS23 << 7))

/*****    Address 000A 090Eh CTSU Channel send and receive control register 3 *****************************************/
#define CTSUCHTRC3_MUTUAL3_TRANSMIT_TS   ((MUTUAL3_FUNCTION_TS24 << 0) | (MUTUAL3_FUNCTION_TS25 << 1) | \
                                          (MUTUAL3_FUNCTION_TS26 << 2) | (MUTUAL3_FUNCTION_TS27 << 3) | \
                                          (MUTUAL3_FUNCTION_TS28 << 4) | (MUTUAL3_FUNCTION_TS29 << 5) | \
                                          (MUTUAL3_FUNCTION_TS30 << 6) | (MUTUAL3_FUNCTION_TS31 << 7))

/*****    Address 000A 090Fh CTSU Channel send and receive control register 4 *****************************************/
#define CTSUCHTRC4_MUTUAL3_TRANSMIT_TS   ((MUTUAL3_FUNCTION_TS32 << 0) | (MUTUAL3_FUNCTION_TS33 << 1) | \
                                          (MUTUAL3_FUNCTION_TS34 << 2) | (MUTUAL3_FUNCTION_TS35 << 3))

#define TRANSMISSION3_NUM                  (MUTUAL3_FUNCTION_TS00 + MUTUAL3_FUNCTION_TS01 + MUTUAL3_FUNCTION_TS02 + \
                                            MUTUAL3_FUNCTION_TS03 + MUTUAL3_FUNCTION_TS04 + MUTUAL3_FUNCTION_TS05 + \
                                            MUTUAL3_FUNCTION_TS06 + MUTUAL3_FUNCTION_TS07 + MUTUAL3_FUNCTION_TS08 + \
                                            MUTUAL3_FUNCTION_TS09 + MUTUAL3_FUNCTION_TS10 + MUTUAL3_FUNCTION_TS11 + \
                                            MUTUAL3_FUNCTION_TS12 + MUTUAL3_FUNCTION_TS13 + MUTUAL3_FUNCTION_TS14 + \
                                            MUTUAL3_FUNCTION_TS15 + MUTUAL3_FUNCTION_TS16 + MUTUAL3_FUNCTION_TS17 + \
                                            MUTUAL3_FUNCTION_TS18 + MUTUAL3_FUNCTION_TS19 + MUTUAL3_FUNCTION_TS20 + \
                                            MUTUAL3_FUNCTION_TS21 + MUTUAL3_FUNCTION_TS22 + MUTUAL3_FUNCTION_TS23 + \
                                            MUTUAL3_FUNCTION_TS24 + MUTUAL3_FUNCTION_TS25 + MUTUAL3_FUNCTION_TS26 + \
                                            MUTUAL3_FUNCTION_TS27 + MUTUAL3_FUNCTION_TS28 + MUTUAL3_FUNCTION_TS29 + \
                                            MUTUAL3_FUNCTION_TS30 + MUTUAL3_FUNCTION_TS31 + MUTUAL3_FUNCTION_TS32 + \
                                            MUTUAL3_FUNCTION_TS33 + MUTUAL3_FUNCTION_TS34 + MUTUAL3_FUNCTION_TS35)

#define RECEPTION3_NUM                     (MUTUAL3_ENABLE_NUM - TRANSMISSION3_NUM)
#define MUTUAL3_NUM                        (TRANSMISSION3_NUM * RECEPTION3_NUM)

#if TRANSMISSION3_NUM == 0
    #error "Send TS Setting error ( TRANSMISSION3_NUM = 0 )"
#endif
#if RECEPTION3_NUM == 0
    #error "Receive TS Setting error ( RECEPTION_NUM3 = 0 )"
#endif

/*****    Address 000A 0912h CTSU High-Pass Noise Reduction Spectrum Diffusion Control Register    ********************/
/**********************************************************************************************************************/
/*    CTSU Spectrum Diffusion Frequency Division Setting                                                              */
/*    Base Clock Frequency fb (MHz)   CTSUSSDIV[3:0] Bit Setting                                                      */
/*          4.00 =< fb                           0x00                                                                 */
/*          2.00 =< fb  < 4.00                   0x01                                                                 */
/*          1.33 =< fb  < 2.00                   0x02                                                                 */
/*          1.00 =< fb  < 1.33                   0x03                                                                 */
/*          0.80 =< fb  < 1.00                   0x04                                                                 */
/*          0.67 =< fb  < 0.80                   0x05                                                                 */
/*          0.57 =< fb  < 0.67                   0x06                                                                 */
/*          0.50 =< fb  < 0.57                   0x07                                                                 */
/*          0.44 =< fb  < 0.50                   0x08                                                                 */
/*          0.40 =< fb  < 0.44                   0x09                                                                 */
/*          0.36 =< fb  < 0.40                   0x0A                                                                 */
/*          0.33 =< fb  < 0.36                   0x0B                                                                 */
/*          0.31 =< fb  < 0.33                   0x0C                                                                 */
/*          0.29 =< fb  < 0.31                   0x0D                                                                 */
/*          0.27 =< fb  < 0.29                   0x0E                                                                 */
/*                  fb =< 0.25                   0x0F                                                                 */
/**********************************************************************************************************************/
#define CTSUSSDIV_MUTUAL3_KEY00         (0x01)                  /* Mutual 3 Key00 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY01         (0x01)                  /* Mutual 3 Key01 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY02         (0x01)                  /* Mutual 3 Key02 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY03         (0x01)                  /* Mutual 3 Key03 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY04         (0x01)                  /* Mutual 3 Key04 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY05         (0x01)                  /* Mutual 3 Key05 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY06         (0x01)                  /* Mutual 3 Key06 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY07         (0x01)                  /* Mutual 3 Key07 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY08         (0x01)                  /* Mutual 3 Key08 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY09         (0x01)                  /* Mutual 3 Key09 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY10         (0x01)                  /* Mutual 3 Key10 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY11         (0x01)                  /* Mutual 3 Key11 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY12         (0x01)                  /* Mutual 3 Key12 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY13         (0x01)                  /* Mutual 3 Key13 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY14         (0x01)                  /* Mutual 3 Key14 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY15         (0x01)                  /* Mutual 3 Key15 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY16         (0x01)                  /* Mutual 3 Key16 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY17         (0x01)                  /* Mutual 3 Key17 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY18         (0x01)                  /* Mutual 3 Key18 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY19         (0x01)                  /* Mutual 3 Key19 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY20         (0x01)                  /* Mutual 3 Key20 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY21         (0x01)                  /* Mutual 3 Key21 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY22         (0x01)                  /* Mutual 3 Key22 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY23         (0x01)                  /* Mutual 3 Key23 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY24         (0x01)                  /* Mutual 3 Key24 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY25         (0x01)                  /* Mutual 3 Key25 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY26         (0x01)                  /* Mutual 3 Key26 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY27         (0x01)                  /* Mutual 3 Key27 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY28         (0x01)                  /* Mutual 3 Key28 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY29         (0x01)                  /* Mutual 3 Key29 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY30         (0x01)                  /* Mutual 3 Key30 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY31         (0x01)                  /* Mutual 3 Key31 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY32         (0x01)                  /* Mutual 3 Key32 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY33         (0x01)                  /* Mutual 3 Key33 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY34         (0x01)                  /* Mutual 3 Key34 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY35         (0x01)                  /* Mutual 3 Key35 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY36         (0x01)                  /* Mutual 3 Key36 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY37         (0x01)                  /* Mutual 3 Key37 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY38         (0x01)                  /* Mutual 3 Key38 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY39         (0x01)                  /* Mutual 3 Key39 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY40         (0x01)                  /* Mutual 3 Key40 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY41         (0x01)                  /* Mutual 3 Key41 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY42         (0x01)                  /* Mutual 3 Key42 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY43         (0x01)                  /* Mutual 3 Key43 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY44         (0x01)                  /* Mutual 3 Key44 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY45         (0x01)                  /* Mutual 3 Key45 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY46         (0x01)                  /* Mutual 3 Key46 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY47         (0x01)                  /* Mutual 3 Key47 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY48         (0x01)                  /* Mutual 3 Key48 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY49         (0x01)                  /* Mutual 3 Key49 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY50         (0x01)                  /* Mutual 3 Key50 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY51         (0x01)                  /* Mutual 3 Key51 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY52         (0x01)                  /* Mutual 3 Key52 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY53         (0x01)                  /* Mutual 3 Key53 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY54         (0x01)                  /* Mutual 3 Key54 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY55         (0x01)                  /* Mutual 3 Key55 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY56         (0x01)                  /* Mutual 3 Key56 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY57         (0x01)                  /* Mutual 3 Key57 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY58         (0x01)                  /* Mutual 3 Key58 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY59         (0x01)                  /* Mutual 3 Key59 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY60         (0x01)                  /* Mutual 3 Key60 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY61         (0x01)                  /* Mutual 3 Key61 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY62         (0x01)                  /* Mutual 3 Key62 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL3_KEY63         (0x01)                  /* Mutual 3 Key63 CTSUSDIV                            */

#define CTSUSSC_MUTUAL3_KEY00           (CTSUSSDIV_MUTUAL3_KEY00 << 8)
#define CTSUSSC_MUTUAL3_KEY01           (CTSUSSDIV_MUTUAL3_KEY01 << 8)
#define CTSUSSC_MUTUAL3_KEY02           (CTSUSSDIV_MUTUAL3_KEY02 << 8)
#define CTSUSSC_MUTUAL3_KEY03           (CTSUSSDIV_MUTUAL3_KEY03 << 8)
#define CTSUSSC_MUTUAL3_KEY04           (CTSUSSDIV_MUTUAL3_KEY04 << 8)
#define CTSUSSC_MUTUAL3_KEY05           (CTSUSSDIV_MUTUAL3_KEY05 << 8)
#define CTSUSSC_MUTUAL3_KEY06           (CTSUSSDIV_MUTUAL3_KEY06 << 8)
#define CTSUSSC_MUTUAL3_KEY07           (CTSUSSDIV_MUTUAL3_KEY07 << 8)
#define CTSUSSC_MUTUAL3_KEY08           (CTSUSSDIV_MUTUAL3_KEY08 << 8)
#define CTSUSSC_MUTUAL3_KEY09           (CTSUSSDIV_MUTUAL3_KEY09 << 8)
#define CTSUSSC_MUTUAL3_KEY10           (CTSUSSDIV_MUTUAL3_KEY10 << 8)
#define CTSUSSC_MUTUAL3_KEY11           (CTSUSSDIV_MUTUAL3_KEY11 << 8)
#define CTSUSSC_MUTUAL3_KEY12           (CTSUSSDIV_MUTUAL3_KEY12 << 8)
#define CTSUSSC_MUTUAL3_KEY13           (CTSUSSDIV_MUTUAL3_KEY13 << 8)
#define CTSUSSC_MUTUAL3_KEY14           (CTSUSSDIV_MUTUAL3_KEY14 << 8)
#define CTSUSSC_MUTUAL3_KEY15           (CTSUSSDIV_MUTUAL3_KEY15 << 8)
#define CTSUSSC_MUTUAL3_KEY16           (CTSUSSDIV_MUTUAL3_KEY16 << 8)
#define CTSUSSC_MUTUAL3_KEY17           (CTSUSSDIV_MUTUAL3_KEY17 << 8)
#define CTSUSSC_MUTUAL3_KEY18           (CTSUSSDIV_MUTUAL3_KEY18 << 8)
#define CTSUSSC_MUTUAL3_KEY19           (CTSUSSDIV_MUTUAL3_KEY19 << 8)
#define CTSUSSC_MUTUAL3_KEY20           (CTSUSSDIV_MUTUAL3_KEY20 << 8)
#define CTSUSSC_MUTUAL3_KEY21           (CTSUSSDIV_MUTUAL3_KEY21 << 8)
#define CTSUSSC_MUTUAL3_KEY22           (CTSUSSDIV_MUTUAL3_KEY22 << 8)
#define CTSUSSC_MUTUAL3_KEY23           (CTSUSSDIV_MUTUAL3_KEY23 << 8)
#define CTSUSSC_MUTUAL3_KEY24           (CTSUSSDIV_MUTUAL3_KEY24 << 8)
#define CTSUSSC_MUTUAL3_KEY25           (CTSUSSDIV_MUTUAL3_KEY25 << 8)
#define CTSUSSC_MUTUAL3_KEY26           (CTSUSSDIV_MUTUAL3_KEY26 << 8)
#define CTSUSSC_MUTUAL3_KEY27           (CTSUSSDIV_MUTUAL3_KEY27 << 8)
#define CTSUSSC_MUTUAL3_KEY28           (CTSUSSDIV_MUTUAL3_KEY28 << 8)
#define CTSUSSC_MUTUAL3_KEY29           (CTSUSSDIV_MUTUAL3_KEY29 << 8)
#define CTSUSSC_MUTUAL3_KEY30           (CTSUSSDIV_MUTUAL3_KEY30 << 8)
#define CTSUSSC_MUTUAL3_KEY31           (CTSUSSDIV_MUTUAL3_KEY31 << 8)
#define CTSUSSC_MUTUAL3_KEY32           (CTSUSSDIV_MUTUAL3_KEY32 << 8)
#define CTSUSSC_MUTUAL3_KEY33           (CTSUSSDIV_MUTUAL3_KEY33 << 8)
#define CTSUSSC_MUTUAL3_KEY34           (CTSUSSDIV_MUTUAL3_KEY34 << 8)
#define CTSUSSC_MUTUAL3_KEY35           (CTSUSSDIV_MUTUAL3_KEY35 << 8)
#define CTSUSSC_MUTUAL3_KEY36           (CTSUSSDIV_MUTUAL3_KEY36 << 8)
#define CTSUSSC_MUTUAL3_KEY37           (CTSUSSDIV_MUTUAL3_KEY37 << 8)
#define CTSUSSC_MUTUAL3_KEY38           (CTSUSSDIV_MUTUAL3_KEY38 << 8)
#define CTSUSSC_MUTUAL3_KEY39           (CTSUSSDIV_MUTUAL3_KEY39 << 8)
#define CTSUSSC_MUTUAL3_KEY40           (CTSUSSDIV_MUTUAL3_KEY40 << 8)
#define CTSUSSC_MUTUAL3_KEY41           (CTSUSSDIV_MUTUAL3_KEY41 << 8)
#define CTSUSSC_MUTUAL3_KEY42           (CTSUSSDIV_MUTUAL3_KEY42 << 8)
#define CTSUSSC_MUTUAL3_KEY43           (CTSUSSDIV_MUTUAL3_KEY43 << 8)
#define CTSUSSC_MUTUAL3_KEY44           (CTSUSSDIV_MUTUAL3_KEY44 << 8)
#define CTSUSSC_MUTUAL3_KEY45           (CTSUSSDIV_MUTUAL3_KEY45 << 8)
#define CTSUSSC_MUTUAL3_KEY46           (CTSUSSDIV_MUTUAL3_KEY46 << 8)
#define CTSUSSC_MUTUAL3_KEY47           (CTSUSSDIV_MUTUAL3_KEY47 << 8)
#define CTSUSSC_MUTUAL3_KEY48           (CTSUSSDIV_MUTUAL3_KEY48 << 8)
#define CTSUSSC_MUTUAL3_KEY49           (CTSUSSDIV_MUTUAL3_KEY49 << 8)
#define CTSUSSC_MUTUAL3_KEY50           (CTSUSSDIV_MUTUAL3_KEY50 << 8)
#define CTSUSSC_MUTUAL3_KEY51           (CTSUSSDIV_MUTUAL3_KEY51 << 8)
#define CTSUSSC_MUTUAL3_KEY52           (CTSUSSDIV_MUTUAL3_KEY52 << 8)
#define CTSUSSC_MUTUAL3_KEY53           (CTSUSSDIV_MUTUAL3_KEY53 << 8)
#define CTSUSSC_MUTUAL3_KEY54           (CTSUSSDIV_MUTUAL3_KEY54 << 8)
#define CTSUSSC_MUTUAL3_KEY55           (CTSUSSDIV_MUTUAL3_KEY55 << 8)
#define CTSUSSC_MUTUAL3_KEY56           (CTSUSSDIV_MUTUAL3_KEY56 << 8)
#define CTSUSSC_MUTUAL3_KEY57           (CTSUSSDIV_MUTUAL3_KEY57 << 8)
#define CTSUSSC_MUTUAL3_KEY58           (CTSUSSDIV_MUTUAL3_KEY58 << 8)
#define CTSUSSC_MUTUAL3_KEY59           (CTSUSSDIV_MUTUAL3_KEY59 << 8)
#define CTSUSSC_MUTUAL3_KEY60           (CTSUSSDIV_MUTUAL3_KEY60 << 8)
#define CTSUSSC_MUTUAL3_KEY61           (CTSUSSDIV_MUTUAL3_KEY61 << 8)
#define CTSUSSC_MUTUAL3_KEY62           (CTSUSSDIV_MUTUAL3_KEY62 << 8)
#define CTSUSSC_MUTUAL3_KEY63           (CTSUSSDIV_MUTUAL3_KEY63 << 8)

/*****    Address 000A 0914h CTSU Sensor Offset Register 0     ********************************************************/
/**********************************************************************************************************************/
/*    CTSU Sensor Offset Adjustment                                                                                   */
/*      Current offset amount is 0       0x000                                                                        */
/*      Current offset amount is 1       0x001                                                                        */
/*      Current offset amount is 2       0x002                                                                        */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*      Current offset amount is 1023    0x3FF                                                                        */
/**********************************************************************************************************************/
#define CTSUSO_MUTUAL3_KEY00            (0x000)                 /* Mutual 3 Key00 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY01            (0x000)                 /* Mutual 3 Key01 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY02            (0x000)                 /* Mutual 3 Key02 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY03            (0x000)                 /* Mutual 3 Key03 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY04            (0x000)                 /* Mutual 3 Key04 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY05            (0x000)                 /* Mutual 3 Key05 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY06            (0x000)                 /* Mutual 3 Key06 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY07            (0x000)                 /* Mutual 3 Key07 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY08            (0x000)                 /* Mutual 3 Key08 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY09            (0x000)                 /* Mutual 3 Key09 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY10            (0x000)                 /* Mutual 3 Key10 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY11            (0x000)                 /* Mutual 3 Key11 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY12            (0x000)                 /* Mutual 3 Key12 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY13            (0x000)                 /* Mutual 3 Key13 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY14            (0x000)                 /* Mutual 3 Key14 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY15            (0x000)                 /* Mutual 3 Key15 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY16            (0x000)                 /* Mutual 3 Key16 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY17            (0x000)                 /* Mutual 3 Key17 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY18            (0x000)                 /* Mutual 3 Key18 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY19            (0x000)                 /* Mutual 3 Key19 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY20            (0x000)                 /* Mutual 3 Key20 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY21            (0x000)                 /* Mutual 3 Key21 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY22            (0x000)                 /* Mutual 3 Key22 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY23            (0x000)                 /* Mutual 3 Key23 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY24            (0x000)                 /* Mutual 3 Key24 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY25            (0x000)                 /* Mutual 3 Key25 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY26            (0x000)                 /* Mutual 3 Key26 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY27            (0x000)                 /* Mutual 3 Key27 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY28            (0x000)                 /* Mutual 3 Key28 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY29            (0x000)                 /* Mutual 3 Key29 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY30            (0x000)                 /* Mutual 3 Key30 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY31            (0x000)                 /* Mutual 3 Key31 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY32            (0x000)                 /* Mutual 3 Key32 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY33            (0x000)                 /* Mutual 3 Key33 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY34            (0x000)                 /* Mutual 3 Key34 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY35            (0x000)                 /* Mutual 3 Key35 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY36            (0x000)                 /* Mutual 3 Key36 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY37            (0x000)                 /* Mutual 3 Key37 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY38            (0x000)                 /* Mutual 3 Key38 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY39            (0x000)                 /* Mutual 3 Key39 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY40            (0x000)                 /* Mutual 3 Key40 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY41            (0x000)                 /* Mutual 3 Key41 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY42            (0x000)                 /* Mutual 3 Key42 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY43            (0x000)                 /* Mutual 3 Key43 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY44            (0x000)                 /* Mutual 3 Key44 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY45            (0x000)                 /* Mutual 3 Key45 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY46            (0x000)                 /* Mutual 3 Key46 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY47            (0x000)                 /* Mutual 3 Key47 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY48            (0x000)                 /* Mutual 3 Key48 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY49            (0x000)                 /* Mutual 3 Key49 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY50            (0x000)                 /* Mutual 3 Key50 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY51            (0x000)                 /* Mutual 3 Key51 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY52            (0x000)                 /* Mutual 3 Key52 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY53            (0x000)                 /* Mutual 3 Key53 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY54            (0x000)                 /* Mutual 3 Key54 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY55            (0x000)                 /* Mutual 3 Key55 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY56            (0x000)                 /* Mutual 3 Key56 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY57            (0x000)                 /* Mutual 3 Key57 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY58            (0x000)                 /* Mutual 3 Key58 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY59            (0x000)                 /* Mutual 3 Key59 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY60            (0x000)                 /* Mutual 3 Key60 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY61            (0x000)                 /* Mutual 3 Key61 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY62            (0x000)                 /* Mutual 3 Key62 CTSUSO                              */
#define CTSUSO_MUTUAL3_KEY63            (0x000)                 /* Mutual 3 Key63 CTSUSO                              */

/**********************************************************************************************************************/
/*    CTSU Measurement Count Setting                                                                                  */
/*      4.0MHz    7                                                                                                   */
/*      2.0MHz    3                                                                                                   */
/*      1.0MHz    1                                                                                                   */
/*      0.5MHz    0                                                                                                   */
/**********************************************************************************************************************/
#define CTSUSNUM_MUTUAL3_KEY00          (3)                     /* Mutual 3 Key00 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY01          (3)                     /* Mutual 3 Key01 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY02          (3)                     /* Mutual 3 Key02 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY03          (3)                     /* Mutual 3 Key03 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY04          (3)                     /* Mutual 3 Key04 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY05          (3)                     /* Mutual 3 Key05 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY06          (3)                     /* Mutual 3 Key06 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY07          (3)                     /* Mutual 3 Key07 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY08          (3)                     /* Mutual 3 Key08 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY09          (3)                     /* Mutual 3 Key09 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY10          (3)                     /* Mutual 3 Key10 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY11          (3)                     /* Mutual 3 Key11 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY12          (3)                     /* Mutual 3 Key12 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY13          (3)                     /* Mutual 3 Key13 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY14          (3)                     /* Mutual 3 Key14 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY15          (3)                     /* Mutual 3 Key15 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY16          (3)                     /* Mutual 3 Key16 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY17          (3)                     /* Mutual 3 Key17 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY18          (3)                     /* Mutual 3 Key18 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY19          (3)                     /* Mutual 3 Key19 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY20          (3)                     /* Mutual 3 Key20 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY21          (3)                     /* Mutual 3 Key21 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY22          (3)                     /* Mutual 3 Key22 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY23          (3)                     /* Mutual 3 Key23 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY24          (3)                     /* Mutual 3 Key24 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY25          (3)                     /* Mutual 3 Key25 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY26          (3)                     /* Mutual 3 Key26 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY27          (3)                     /* Mutual 3 Key27 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY28          (3)                     /* Mutual 3 Key28 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY29          (3)                     /* Mutual 3 Key29 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY30          (3)                     /* Mutual 3 Key30 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY31          (3)                     /* Mutual 3 Key31 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY32          (3)                     /* Mutual 3 Key32 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY33          (3)                     /* Mutual 3 Key33 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY34          (3)                     /* Mutual 3 Key34 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY35          (3)                     /* Mutual 3 Key35 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY36          (3)                     /* Mutual 3 Key36 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY37          (3)                     /* Mutual 3 Key37 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY38          (3)                     /* Mutual 3 Key38 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY39          (3)                     /* Mutual 3 Key39 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY40          (3)                     /* Mutual 3 Key40 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY41          (3)                     /* Mutual 3 Key41 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY42          (3)                     /* Mutual 3 Key42 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY43          (3)                     /* Mutual 3 Key43 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY44          (3)                     /* Mutual 3 Key44 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY45          (3)                     /* Mutual 3 Key45 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY46          (3)                     /* Mutual 3 Key46 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY47          (3)                     /* Mutual 3 Key47 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY48          (3)                     /* Mutual 3 Key48 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY49          (3)                     /* Mutual 3 Key49 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY50          (3)                     /* Mutual 3 Key50 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY51          (3)                     /* Mutual 3 Key51 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY52          (3)                     /* Mutual 3 Key52 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY53          (3)                     /* Mutual 3 Key53 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY54          (3)                     /* Mutual 3 Key54 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY55          (3)                     /* Mutual 3 Key55 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY56          (3)                     /* Mutual 3 Key56 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY57          (3)                     /* Mutual 3 Key57 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY58          (3)                     /* Mutual 3 Key58 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY59          (3)                     /* Mutual 3 Key59 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY60          (3)                     /* Mutual 3 Key60 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY61          (3)                     /* Mutual 3 Key61 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY62          (3)                     /* Mutual 3 Key62 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL3_KEY63          (3)                     /* Mutual 3 Key63 CTSUSNUM                            */

#define CTSUSO0_MUTUAL3_KEY00           ((CTSUSNUM_MUTUAL3_KEY00 << 10) | CTSUSO_MUTUAL3_KEY00)
#define CTSUSO0_MUTUAL3_KEY01           ((CTSUSNUM_MUTUAL3_KEY01 << 10) | CTSUSO_MUTUAL3_KEY01)
#define CTSUSO0_MUTUAL3_KEY02           ((CTSUSNUM_MUTUAL3_KEY02 << 10) | CTSUSO_MUTUAL3_KEY02)
#define CTSUSO0_MUTUAL3_KEY03           ((CTSUSNUM_MUTUAL3_KEY03 << 10) | CTSUSO_MUTUAL3_KEY03)
#define CTSUSO0_MUTUAL3_KEY04           ((CTSUSNUM_MUTUAL3_KEY04 << 10) | CTSUSO_MUTUAL3_KEY04)
#define CTSUSO0_MUTUAL3_KEY05           ((CTSUSNUM_MUTUAL3_KEY05 << 10) | CTSUSO_MUTUAL3_KEY05)
#define CTSUSO0_MUTUAL3_KEY06           ((CTSUSNUM_MUTUAL3_KEY06 << 10) | CTSUSO_MUTUAL3_KEY06)
#define CTSUSO0_MUTUAL3_KEY07           ((CTSUSNUM_MUTUAL3_KEY07 << 10) | CTSUSO_MUTUAL3_KEY07)
#define CTSUSO0_MUTUAL3_KEY08           ((CTSUSNUM_MUTUAL3_KEY08 << 10) | CTSUSO_MUTUAL3_KEY08)
#define CTSUSO0_MUTUAL3_KEY09           ((CTSUSNUM_MUTUAL3_KEY09 << 10) | CTSUSO_MUTUAL3_KEY09)
#define CTSUSO0_MUTUAL3_KEY10           ((CTSUSNUM_MUTUAL3_KEY10 << 10) | CTSUSO_MUTUAL3_KEY10)
#define CTSUSO0_MUTUAL3_KEY11           ((CTSUSNUM_MUTUAL3_KEY11 << 10) | CTSUSO_MUTUAL3_KEY11)
#define CTSUSO0_MUTUAL3_KEY12           ((CTSUSNUM_MUTUAL3_KEY12 << 10) | CTSUSO_MUTUAL3_KEY12)
#define CTSUSO0_MUTUAL3_KEY13           ((CTSUSNUM_MUTUAL3_KEY13 << 10) | CTSUSO_MUTUAL3_KEY13)
#define CTSUSO0_MUTUAL3_KEY14           ((CTSUSNUM_MUTUAL3_KEY14 << 10) | CTSUSO_MUTUAL3_KEY14)
#define CTSUSO0_MUTUAL3_KEY15           ((CTSUSNUM_MUTUAL3_KEY15 << 10) | CTSUSO_MUTUAL3_KEY15)
#define CTSUSO0_MUTUAL3_KEY16           ((CTSUSNUM_MUTUAL3_KEY16 << 10) | CTSUSO_MUTUAL3_KEY16)
#define CTSUSO0_MUTUAL3_KEY17           ((CTSUSNUM_MUTUAL3_KEY17 << 10) | CTSUSO_MUTUAL3_KEY17)
#define CTSUSO0_MUTUAL3_KEY18           ((CTSUSNUM_MUTUAL3_KEY18 << 10) | CTSUSO_MUTUAL3_KEY18)
#define CTSUSO0_MUTUAL3_KEY19           ((CTSUSNUM_MUTUAL3_KEY19 << 10) | CTSUSO_MUTUAL3_KEY19)
#define CTSUSO0_MUTUAL3_KEY20           ((CTSUSNUM_MUTUAL3_KEY20 << 10) | CTSUSO_MUTUAL3_KEY20)
#define CTSUSO0_MUTUAL3_KEY21           ((CTSUSNUM_MUTUAL3_KEY21 << 10) | CTSUSO_MUTUAL3_KEY21)
#define CTSUSO0_MUTUAL3_KEY22           ((CTSUSNUM_MUTUAL3_KEY22 << 10) | CTSUSO_MUTUAL3_KEY22)
#define CTSUSO0_MUTUAL3_KEY23           ((CTSUSNUM_MUTUAL3_KEY23 << 10) | CTSUSO_MUTUAL3_KEY23)
#define CTSUSO0_MUTUAL3_KEY24           ((CTSUSNUM_MUTUAL3_KEY24 << 10) | CTSUSO_MUTUAL3_KEY24)
#define CTSUSO0_MUTUAL3_KEY25           ((CTSUSNUM_MUTUAL3_KEY25 << 10) | CTSUSO_MUTUAL3_KEY25)
#define CTSUSO0_MUTUAL3_KEY26           ((CTSUSNUM_MUTUAL3_KEY26 << 10) | CTSUSO_MUTUAL3_KEY26)
#define CTSUSO0_MUTUAL3_KEY27           ((CTSUSNUM_MUTUAL3_KEY27 << 10) | CTSUSO_MUTUAL3_KEY27)
#define CTSUSO0_MUTUAL3_KEY28           ((CTSUSNUM_MUTUAL3_KEY28 << 10) | CTSUSO_MUTUAL3_KEY28)
#define CTSUSO0_MUTUAL3_KEY29           ((CTSUSNUM_MUTUAL3_KEY29 << 10) | CTSUSO_MUTUAL3_KEY29)
#define CTSUSO0_MUTUAL3_KEY30           ((CTSUSNUM_MUTUAL3_KEY30 << 10) | CTSUSO_MUTUAL3_KEY30)
#define CTSUSO0_MUTUAL3_KEY31           ((CTSUSNUM_MUTUAL3_KEY31 << 10) | CTSUSO_MUTUAL3_KEY31)
#define CTSUSO0_MUTUAL3_KEY32           ((CTSUSNUM_MUTUAL3_KEY32 << 10) | CTSUSO_MUTUAL3_KEY32)
#define CTSUSO0_MUTUAL3_KEY33           ((CTSUSNUM_MUTUAL3_KEY33 << 10) | CTSUSO_MUTUAL3_KEY33)
#define CTSUSO0_MUTUAL3_KEY34           ((CTSUSNUM_MUTUAL3_KEY34 << 10) | CTSUSO_MUTUAL3_KEY34)
#define CTSUSO0_MUTUAL3_KEY35           ((CTSUSNUM_MUTUAL3_KEY35 << 10) | CTSUSO_MUTUAL3_KEY35)
#define CTSUSO0_MUTUAL3_KEY36           ((CTSUSNUM_MUTUAL3_KEY36 << 10) | CTSUSO_MUTUAL3_KEY36)
#define CTSUSO0_MUTUAL3_KEY37           ((CTSUSNUM_MUTUAL3_KEY37 << 10) | CTSUSO_MUTUAL3_KEY37)
#define CTSUSO0_MUTUAL3_KEY38           ((CTSUSNUM_MUTUAL3_KEY38 << 10) | CTSUSO_MUTUAL3_KEY38)
#define CTSUSO0_MUTUAL3_KEY39           ((CTSUSNUM_MUTUAL3_KEY39 << 10) | CTSUSO_MUTUAL3_KEY39)
#define CTSUSO0_MUTUAL3_KEY40           ((CTSUSNUM_MUTUAL3_KEY40 << 10) | CTSUSO_MUTUAL3_KEY40)
#define CTSUSO0_MUTUAL3_KEY41           ((CTSUSNUM_MUTUAL3_KEY41 << 10) | CTSUSO_MUTUAL3_KEY41)
#define CTSUSO0_MUTUAL3_KEY42           ((CTSUSNUM_MUTUAL3_KEY42 << 10) | CTSUSO_MUTUAL3_KEY42)
#define CTSUSO0_MUTUAL3_KEY43           ((CTSUSNUM_MUTUAL3_KEY43 << 10) | CTSUSO_MUTUAL3_KEY43)
#define CTSUSO0_MUTUAL3_KEY44           ((CTSUSNUM_MUTUAL3_KEY44 << 10) | CTSUSO_MUTUAL3_KEY44)
#define CTSUSO0_MUTUAL3_KEY45           ((CTSUSNUM_MUTUAL3_KEY45 << 10) | CTSUSO_MUTUAL3_KEY45)
#define CTSUSO0_MUTUAL3_KEY46           ((CTSUSNUM_MUTUAL3_KEY46 << 10) | CTSUSO_MUTUAL3_KEY46)
#define CTSUSO0_MUTUAL3_KEY47           ((CTSUSNUM_MUTUAL3_KEY47 << 10) | CTSUSO_MUTUAL3_KEY47)
#define CTSUSO0_MUTUAL3_KEY48           ((CTSUSNUM_MUTUAL3_KEY48 << 10) | CTSUSO_MUTUAL3_KEY48)
#define CTSUSO0_MUTUAL3_KEY49           ((CTSUSNUM_MUTUAL3_KEY49 << 10) | CTSUSO_MUTUAL3_KEY49)
#define CTSUSO0_MUTUAL3_KEY50           ((CTSUSNUM_MUTUAL3_KEY50 << 10) | CTSUSO_MUTUAL3_KEY50)
#define CTSUSO0_MUTUAL3_KEY51           ((CTSUSNUM_MUTUAL3_KEY51 << 10) | CTSUSO_MUTUAL3_KEY51)
#define CTSUSO0_MUTUAL3_KEY52           ((CTSUSNUM_MUTUAL3_KEY52 << 10) | CTSUSO_MUTUAL3_KEY52)
#define CTSUSO0_MUTUAL3_KEY53           ((CTSUSNUM_MUTUAL3_KEY53 << 10) | CTSUSO_MUTUAL3_KEY53)
#define CTSUSO0_MUTUAL3_KEY54           ((CTSUSNUM_MUTUAL3_KEY54 << 10) | CTSUSO_MUTUAL3_KEY54)
#define CTSUSO0_MUTUAL3_KEY55           ((CTSUSNUM_MUTUAL3_KEY55 << 10) | CTSUSO_MUTUAL3_KEY55)
#define CTSUSO0_MUTUAL3_KEY56           ((CTSUSNUM_MUTUAL3_KEY56 << 10) | CTSUSO_MUTUAL3_KEY56)
#define CTSUSO0_MUTUAL3_KEY57           ((CTSUSNUM_MUTUAL3_KEY57 << 10) | CTSUSO_MUTUAL3_KEY57)
#define CTSUSO0_MUTUAL3_KEY58           ((CTSUSNUM_MUTUAL3_KEY58 << 10) | CTSUSO_MUTUAL3_KEY58)
#define CTSUSO0_MUTUAL3_KEY59           ((CTSUSNUM_MUTUAL3_KEY59 << 10) | CTSUSO_MUTUAL3_KEY59)
#define CTSUSO0_MUTUAL3_KEY60           ((CTSUSNUM_MUTUAL3_KEY60 << 10) | CTSUSO_MUTUAL3_KEY60)
#define CTSUSO0_MUTUAL3_KEY61           ((CTSUSNUM_MUTUAL3_KEY61 << 10) | CTSUSO_MUTUAL3_KEY61)
#define CTSUSO0_MUTUAL3_KEY62           ((CTSUSNUM_MUTUAL3_KEY62 << 10) | CTSUSO_MUTUAL3_KEY62)
#define CTSUSO0_MUTUAL3_KEY63           ((CTSUSNUM_MUTUAL3_KEY63 << 10) | CTSUSO_MUTUAL3_KEY63)

/*****    Address 000A 0914h CTSU Sensor Offset Register 1    *********************************************************/
/**********************************************************************************************************************/
/*    CTSU Reference ICO Current Adjustment                                                                           */
/*        Input current amount 0      0x00                                                                            */
/*        Input current amount 1      0x01                                                                            */
/*        Input current amount 2      0x02                                                                            */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*        Input current amount 254    0xFF                                                                            */
/**********************************************************************************************************************/
#define CTSURICOA_MUTUAL3_KEY00         (0x3F)                  /* Mutual 3 Key00 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY01         (0x3F)                  /* Mutual 3 Key01 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY02         (0x3F)                  /* Mutual 3 Key02 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY03         (0x3F)                  /* Mutual 3 Key03 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY04         (0x3F)                  /* Mutual 3 Key04 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY05         (0x3F)                  /* Mutual 3 Key05 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY06         (0x3F)                  /* Mutual 3 Key06 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY07         (0x3F)                  /* Mutual 3 Key07 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY08         (0x3F)                  /* Mutual 3 Key08 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY09         (0x3F)                  /* Mutual 3 Key09 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY10         (0x3F)                  /* Mutual 3 Key10 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY11         (0x3F)                  /* Mutual 3 Key11 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY12         (0x3F)                  /* Mutual 3 Key12 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY13         (0x3F)                  /* Mutual 3 Key13 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY14         (0x3F)                  /* Mutual 3 Key14 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY15         (0x3F)                  /* Mutual 3 Key15 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY16         (0x3F)                  /* Mutual 3 Key16 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY17         (0x3F)                  /* Mutual 3 Key17 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY18         (0x3F)                  /* Mutual 3 Key18 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY19         (0x3F)                  /* Mutual 3 Key19 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY20         (0x3F)                  /* Mutual 3 Key20 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY21         (0x3F)                  /* Mutual 3 Key21 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY22         (0x3F)                  /* Mutual 3 Key22 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY23         (0x3F)                  /* Mutual 3 Key23 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY24         (0x3F)                  /* Mutual 3 Key24 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY25         (0x3F)                  /* Mutual 3 Key25 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY26         (0x3F)                  /* Mutual 3 Key26 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY27         (0x3F)                  /* Mutual 3 Key27 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY28         (0x3F)                  /* Mutual 3 Key28 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY29         (0x3F)                  /* Mutual 3 Key29 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY30         (0x3F)                  /* Mutual 3 Key30 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY31         (0x3F)                  /* Mutual 3 Key31 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY32         (0x3F)                  /* Mutual 3 Key32 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY33         (0x3F)                  /* Mutual 3 Key33 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY34         (0x3F)                  /* Mutual 3 Key34 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY35         (0x3F)                  /* Mutual 3 Key35 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY36         (0x3F)                  /* Mutual 3 Key36 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY37         (0x3F)                  /* Mutual 3 Key37 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY38         (0x3F)                  /* Mutual 3 Key38 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY39         (0x3F)                  /* Mutual 3 Key39 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY40         (0x3F)                  /* Mutual 3 Key40 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY41         (0x3F)                  /* Mutual 3 Key41 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY42         (0x3F)                  /* Mutual 3 Key42 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY43         (0x3F)                  /* Mutual 3 Key43 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY44         (0x3F)                  /* Mutual 3 Key44 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY45         (0x3F)                  /* Mutual 3 Key45 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY46         (0x3F)                  /* Mutual 3 Key46 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY47         (0x3F)                  /* Mutual 3 Key47 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY48         (0x3F)                  /* Mutual 3 Key48 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY49         (0x3F)                  /* Mutual 3 Key49 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY50         (0x3F)                  /* Mutual 3 Key50 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY51         (0x3F)                  /* Mutual 3 Key51 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY52         (0x3F)                  /* Mutual 3 Key52 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY53         (0x3F)                  /* Mutual 3 Key53 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY54         (0x3F)                  /* Mutual 3 Key54 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY55         (0x3F)                  /* Mutual 3 Key55 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY56         (0x3F)                  /* Mutual 3 Key56 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY57         (0x3F)                  /* Mutual 3 Key57 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY58         (0x3F)                  /* Mutual 3 Key58 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY59         (0x3F)                  /* Mutual 3 Key59 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY60         (0x3F)                  /* Mutual 3 Key60 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY61         (0x3F)                  /* Mutual 3 Key61 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY62         (0x3F)                  /* Mutual 3 Key62 CTSUICOA                            */
#define CTSURICOA_MUTUAL3_KEY63         (0x3F)                  /* Mutual 3 Key63 CTSUICOA                            */

/**********************************************************************************************************************/
/*    CTSU Base Clock Setting                                                                                         */
/*        Operating clock divided by 2     0x00                                                                       */
/*        Operating clock divided by 4     0x01                                                                       */
/*        Operating clock divided by 6     0x02                                                                       */
/*                       :                                                                                            */
/*                       :                                                                                            */
/*        Operating clock divided by 64    0x1F                                                                       */
/*                                                                                                                    */
/*    Case : CTSU Operating Clock 32MHz      Case : CTSU Operating Clock 24MHz      Case : CTSU Operating Clock 16MHz */
/*           4.0MHz <--- 0x03                       4.0MHz <--- 0x02                       4.0MHz <--- 0x01           */
/*           2.0MHz <--- 0x07                       2.0MHz <--- 0x05                       2.0MHz <--- 0x03           */
/*           1.0MHz <--- 0x0F                       1.0MHz <--- 0x0B                       1.0MHz <--- 0x07           */
/*           0.5MHz <--- 0x1F                       0.5MHz <--- 0x17                       0.5MHz <--- 0x0F           */
/**********************************************************************************************************************/
#define CTSUSDPA_MUTUAL3_KEY00          (7)                     /* Mutual 3 Key00 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY01          (7)                     /* Mutual 3 Key01 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY02          (7)                     /* Mutual 3 Key02 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY03          (7)                     /* Mutual 3 Key03 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY04          (7)                     /* Mutual 3 Key04 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY05          (7)                     /* Mutual 3 Key05 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY06          (7)                     /* Mutual 3 Key06 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY07          (7)                     /* Mutual 3 Key07 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY08          (7)                     /* Mutual 3 Key08 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY09          (7)                     /* Mutual 3 Key09 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY10          (7)                     /* Mutual 3 Key10 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY11          (7)                     /* Mutual 3 Key11 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY12          (7)                     /* Mutual 3 Key12 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY13          (7)                     /* Mutual 3 Key13 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY14          (7)                     /* Mutual 3 Key14 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY15          (7)                     /* Mutual 3 Key15 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY16          (7)                     /* Mutual 3 Key16 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY17          (7)                     /* Mutual 3 Key17 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY18          (7)                     /* Mutual 3 Key18 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY19          (7)                     /* Mutual 3 Key19 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY20          (7)                     /* Mutual 3 Key20 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY21          (7)                     /* Mutual 3 Key21 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY22          (7)                     /* Mutual 3 Key22 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY23          (7)                     /* Mutual 3 Key23 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY24          (7)                     /* Mutual 3 Key24 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY25          (7)                     /* Mutual 3 Key25 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY26          (7)                     /* Mutual 3 Key26 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY27          (7)                     /* Mutual 3 Key27 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY28          (7)                     /* Mutual 3 Key28 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY29          (7)                     /* Mutual 3 Key29 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY30          (7)                     /* Mutual 3 Key30 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY31          (7)                     /* Mutual 3 Key31 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY32          (7)                     /* Mutual 3 Key32 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY33          (7)                     /* Mutual 3 Key33 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY34          (7)                     /* Mutual 3 Key34 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY35          (7)                     /* Mutual 3 Key35 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY36          (7)                     /* Mutual 3 Key36 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY37          (7)                     /* Mutual 3 Key37 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY38          (7)                     /* Mutual 3 Key38 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY39          (7)                     /* Mutual 3 Key39 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY40          (7)                     /* Mutual 3 Key40 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY41          (7)                     /* Mutual 3 Key41 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY42          (7)                     /* Mutual 3 Key42 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY43          (7)                     /* Mutual 3 Key43 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY44          (7)                     /* Mutual 3 Key44 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY45          (7)                     /* Mutual 3 Key45 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY46          (7)                     /* Mutual 3 Key46 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY47          (7)                     /* Mutual 3 Key47 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY48          (7)                     /* Mutual 3 Key48 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY49          (7)                     /* Mutual 3 Key49 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY50          (7)                     /* Mutual 3 Key50 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY51          (7)                     /* Mutual 3 Key51 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY52          (7)                     /* Mutual 3 Key52 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY53          (7)                     /* Mutual 3 Key53 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY54          (7)                     /* Mutual 3 Key54 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY55          (7)                     /* Mutual 3 Key55 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY56          (7)                     /* Mutual 3 Key56 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY57          (7)                     /* Mutual 3 Key57 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY58          (7)                     /* Mutual 3 Key58 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY59          (7)                     /* Mutual 3 Key59 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY60          (7)                     /* Mutual 3 Key60 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY61          (7)                     /* Mutual 3 Key61 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY62          (7)                     /* Mutual 3 Key62 CTSUDPA                             */
#define CTSUSDPA_MUTUAL3_KEY63          (7)                     /* Mutual 3 Key63 CTSUDPA                             */

/**********************************************************************************************************************/
/*    CTSU ICO Gain Adjustment                                                                                        */
/*        0 : 100% gain                                                                                               */
/*        1 :  66% gain                                                                                               */
/*        2 :  50% gain                                                                                               */
/*        3 :  40% gain                                                                                               */
/**********************************************************************************************************************/
#define CTSUICOG_MUTUAL3_KEY00          (1)                     /* Mutual 3 Key00 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY01          (1)                     /* Mutual 3 Key01 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY02          (1)                     /* Mutual 3 Key02 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY03          (1)                     /* Mutual 3 Key03 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY04          (1)                     /* Mutual 3 Key04 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY05          (1)                     /* Mutual 3 Key05 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY06          (1)                     /* Mutual 3 Key06 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY07          (1)                     /* Mutual 3 Key07 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY08          (1)                     /* Mutual 3 Key08 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY09          (1)                     /* Mutual 3 Key09 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY10          (1)                     /* Mutual 3 Key10 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY11          (1)                     /* Mutual 3 Key11 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY12          (1)                     /* Mutual 3 Key12 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY13          (1)                     /* Mutual 3 Key13 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY14          (1)                     /* Mutual 3 Key14 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY15          (1)                     /* Mutual 3 Key15 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY16          (1)                     /* Mutual 3 Key16 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY17          (1)                     /* Mutual 3 Key17 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY18          (1)                     /* Mutual 3 Key18 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY19          (1)                     /* Mutual 3 Key19 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY20          (1)                     /* Mutual 3 Key20 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY21          (1)                     /* Mutual 3 Key21 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY22          (1)                     /* Mutual 3 Key22 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY23          (1)                     /* Mutual 3 Key23 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY24          (1)                     /* Mutual 3 Key24 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY25          (1)                     /* Mutual 3 Key25 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY26          (1)                     /* Mutual 3 Key26 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY27          (1)                     /* Mutual 3 Key27 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY28          (1)                     /* Mutual 3 Key28 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY29          (1)                     /* Mutual 3 Key29 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY30          (1)                     /* Mutual 3 Key30 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY31          (1)                     /* Mutual 3 Key31 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY32          (1)                     /* Mutual 3 Key32 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY33          (1)                     /* Mutual 3 Key33 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY34          (1)                     /* Mutual 3 Key34 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY35          (1)                     /* Mutual 3 Key35 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY36          (1)                     /* Mutual 3 Key36 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY37          (1)                     /* Mutual 3 Key37 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY38          (1)                     /* Mutual 3 Key38 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY39          (1)                     /* Mutual 3 Key39 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY40          (1)                     /* Mutual 3 Key40 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY41          (1)                     /* Mutual 3 Key41 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY42          (1)                     /* Mutual 3 Key42 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY43          (1)                     /* Mutual 3 Key43 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY44          (1)                     /* Mutual 3 Key44 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY45          (1)                     /* Mutual 3 Key45 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY46          (1)                     /* Mutual 3 Key46 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY47          (1)                     /* Mutual 3 Key47 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY48          (1)                     /* Mutual 3 Key48 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY49          (1)                     /* Mutual 3 Key49 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY50          (1)                     /* Mutual 3 Key50 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY51          (1)                     /* Mutual 3 Key51 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY52          (1)                     /* Mutual 3 Key52 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY53          (1)                     /* Mutual 3 Key53 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY54          (1)                     /* Mutual 3 Key54 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY55          (1)                     /* Mutual 3 Key55 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY56          (1)                     /* Mutual 3 Key56 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY57          (1)                     /* Mutual 3 Key57 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY58          (1)                     /* Mutual 3 Key58 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY59          (1)                     /* Mutual 3 Key59 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY60          (1)                     /* Mutual 3 Key60 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY61          (1)                     /* Mutual 3 Key61 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY62          (1)                     /* Mutual 3 Key62 CTSICOG                             */
#define CTSUICOG_MUTUAL3_KEY63          (1)                     /* Mutual 3 Key63 CTSICOG                             */

#define CTSUSO1_MUTUAL3_KEY00  ((CTSUICOG_MUTUAL3_KEY00 << 13) | (CTSUSDPA_MUTUAL3_KEY00 << 8) | CTSURICOA_MUTUAL3_KEY00)
#define CTSUSO1_MUTUAL3_KEY01  ((CTSUICOG_MUTUAL3_KEY01 << 13) | (CTSUSDPA_MUTUAL3_KEY01 << 8) | CTSURICOA_MUTUAL3_KEY01)
#define CTSUSO1_MUTUAL3_KEY02  ((CTSUICOG_MUTUAL3_KEY02 << 13) | (CTSUSDPA_MUTUAL3_KEY02 << 8) | CTSURICOA_MUTUAL3_KEY02)
#define CTSUSO1_MUTUAL3_KEY03  ((CTSUICOG_MUTUAL3_KEY03 << 13) | (CTSUSDPA_MUTUAL3_KEY03 << 8) | CTSURICOA_MUTUAL3_KEY03)
#define CTSUSO1_MUTUAL3_KEY04  ((CTSUICOG_MUTUAL3_KEY04 << 13) | (CTSUSDPA_MUTUAL3_KEY04 << 8) | CTSURICOA_MUTUAL3_KEY04)
#define CTSUSO1_MUTUAL3_KEY05  ((CTSUICOG_MUTUAL3_KEY05 << 13) | (CTSUSDPA_MUTUAL3_KEY05 << 8) | CTSURICOA_MUTUAL3_KEY05)
#define CTSUSO1_MUTUAL3_KEY06  ((CTSUICOG_MUTUAL3_KEY06 << 13) | (CTSUSDPA_MUTUAL3_KEY06 << 8) | CTSURICOA_MUTUAL3_KEY06)
#define CTSUSO1_MUTUAL3_KEY07  ((CTSUICOG_MUTUAL3_KEY07 << 13) | (CTSUSDPA_MUTUAL3_KEY07 << 8) | CTSURICOA_MUTUAL3_KEY07)
#define CTSUSO1_MUTUAL3_KEY08  ((CTSUICOG_MUTUAL3_KEY08 << 13) | (CTSUSDPA_MUTUAL3_KEY08 << 8) | CTSURICOA_MUTUAL3_KEY08)
#define CTSUSO1_MUTUAL3_KEY09  ((CTSUICOG_MUTUAL3_KEY09 << 13) | (CTSUSDPA_MUTUAL3_KEY09 << 8) | CTSURICOA_MUTUAL3_KEY09)
#define CTSUSO1_MUTUAL3_KEY10  ((CTSUICOG_MUTUAL3_KEY10 << 13) | (CTSUSDPA_MUTUAL3_KEY10 << 8) | CTSURICOA_MUTUAL3_KEY10)
#define CTSUSO1_MUTUAL3_KEY11  ((CTSUICOG_MUTUAL3_KEY11 << 13) | (CTSUSDPA_MUTUAL3_KEY11 << 8) | CTSURICOA_MUTUAL3_KEY11)
#define CTSUSO1_MUTUAL3_KEY12  ((CTSUICOG_MUTUAL3_KEY12 << 13) | (CTSUSDPA_MUTUAL3_KEY12 << 8) | CTSURICOA_MUTUAL3_KEY12)
#define CTSUSO1_MUTUAL3_KEY13  ((CTSUICOG_MUTUAL3_KEY13 << 13) | (CTSUSDPA_MUTUAL3_KEY13 << 8) | CTSURICOA_MUTUAL3_KEY13)
#define CTSUSO1_MUTUAL3_KEY14  ((CTSUICOG_MUTUAL3_KEY14 << 13) | (CTSUSDPA_MUTUAL3_KEY14 << 8) | CTSURICOA_MUTUAL3_KEY14)
#define CTSUSO1_MUTUAL3_KEY15  ((CTSUICOG_MUTUAL3_KEY15 << 13) | (CTSUSDPA_MUTUAL3_KEY15 << 8) | CTSURICOA_MUTUAL3_KEY15)
#define CTSUSO1_MUTUAL3_KEY16  ((CTSUICOG_MUTUAL3_KEY16 << 13) | (CTSUSDPA_MUTUAL3_KEY16 << 8) | CTSURICOA_MUTUAL3_KEY16)
#define CTSUSO1_MUTUAL3_KEY17  ((CTSUICOG_MUTUAL3_KEY17 << 13) | (CTSUSDPA_MUTUAL3_KEY17 << 8) | CTSURICOA_MUTUAL3_KEY17)
#define CTSUSO1_MUTUAL3_KEY18  ((CTSUICOG_MUTUAL3_KEY18 << 13) | (CTSUSDPA_MUTUAL3_KEY18 << 8) | CTSURICOA_MUTUAL3_KEY18)
#define CTSUSO1_MUTUAL3_KEY19  ((CTSUICOG_MUTUAL3_KEY19 << 13) | (CTSUSDPA_MUTUAL3_KEY19 << 8) | CTSURICOA_MUTUAL3_KEY19)
#define CTSUSO1_MUTUAL3_KEY20  ((CTSUICOG_MUTUAL3_KEY20 << 13) | (CTSUSDPA_MUTUAL3_KEY20 << 8) | CTSURICOA_MUTUAL3_KEY20)
#define CTSUSO1_MUTUAL3_KEY21  ((CTSUICOG_MUTUAL3_KEY21 << 13) | (CTSUSDPA_MUTUAL3_KEY21 << 8) | CTSURICOA_MUTUAL3_KEY21)
#define CTSUSO1_MUTUAL3_KEY22  ((CTSUICOG_MUTUAL3_KEY22 << 13) | (CTSUSDPA_MUTUAL3_KEY22 << 8) | CTSURICOA_MUTUAL3_KEY22)
#define CTSUSO1_MUTUAL3_KEY23  ((CTSUICOG_MUTUAL3_KEY23 << 13) | (CTSUSDPA_MUTUAL3_KEY23 << 8) | CTSURICOA_MUTUAL3_KEY23)
#define CTSUSO1_MUTUAL3_KEY24  ((CTSUICOG_MUTUAL3_KEY24 << 13) | (CTSUSDPA_MUTUAL3_KEY24 << 8) | CTSURICOA_MUTUAL3_KEY24)
#define CTSUSO1_MUTUAL3_KEY25  ((CTSUICOG_MUTUAL3_KEY25 << 13) | (CTSUSDPA_MUTUAL3_KEY25 << 8) | CTSURICOA_MUTUAL3_KEY25)
#define CTSUSO1_MUTUAL3_KEY26  ((CTSUICOG_MUTUAL3_KEY26 << 13) | (CTSUSDPA_MUTUAL3_KEY26 << 8) | CTSURICOA_MUTUAL3_KEY26)
#define CTSUSO1_MUTUAL3_KEY27  ((CTSUICOG_MUTUAL3_KEY27 << 13) | (CTSUSDPA_MUTUAL3_KEY27 << 8) | CTSURICOA_MUTUAL3_KEY27)
#define CTSUSO1_MUTUAL3_KEY28  ((CTSUICOG_MUTUAL3_KEY28 << 13) | (CTSUSDPA_MUTUAL3_KEY28 << 8) | CTSURICOA_MUTUAL3_KEY28)
#define CTSUSO1_MUTUAL3_KEY29  ((CTSUICOG_MUTUAL3_KEY29 << 13) | (CTSUSDPA_MUTUAL3_KEY29 << 8) | CTSURICOA_MUTUAL3_KEY29)
#define CTSUSO1_MUTUAL3_KEY30  ((CTSUICOG_MUTUAL3_KEY30 << 13) | (CTSUSDPA_MUTUAL3_KEY30 << 8) | CTSURICOA_MUTUAL3_KEY30)
#define CTSUSO1_MUTUAL3_KEY31  ((CTSUICOG_MUTUAL3_KEY31 << 13) | (CTSUSDPA_MUTUAL3_KEY31 << 8) | CTSURICOA_MUTUAL3_KEY31)
#define CTSUSO1_MUTUAL3_KEY32  ((CTSUICOG_MUTUAL3_KEY32 << 13) | (CTSUSDPA_MUTUAL3_KEY32 << 8) | CTSURICOA_MUTUAL3_KEY32)
#define CTSUSO1_MUTUAL3_KEY33  ((CTSUICOG_MUTUAL3_KEY33 << 13) | (CTSUSDPA_MUTUAL3_KEY33 << 8) | CTSURICOA_MUTUAL3_KEY33)
#define CTSUSO1_MUTUAL3_KEY34  ((CTSUICOG_MUTUAL3_KEY34 << 13) | (CTSUSDPA_MUTUAL3_KEY34 << 8) | CTSURICOA_MUTUAL3_KEY34)
#define CTSUSO1_MUTUAL3_KEY35  ((CTSUICOG_MUTUAL3_KEY35 << 13) | (CTSUSDPA_MUTUAL3_KEY35 << 8) | CTSURICOA_MUTUAL3_KEY35)
#define CTSUSO1_MUTUAL3_KEY36  ((CTSUICOG_MUTUAL3_KEY36 << 13) | (CTSUSDPA_MUTUAL3_KEY36 << 8) | CTSURICOA_MUTUAL3_KEY36)
#define CTSUSO1_MUTUAL3_KEY37  ((CTSUICOG_MUTUAL3_KEY37 << 13) | (CTSUSDPA_MUTUAL3_KEY37 << 8) | CTSURICOA_MUTUAL3_KEY37)
#define CTSUSO1_MUTUAL3_KEY38  ((CTSUICOG_MUTUAL3_KEY38 << 13) | (CTSUSDPA_MUTUAL3_KEY38 << 8) | CTSURICOA_MUTUAL3_KEY38)
#define CTSUSO1_MUTUAL3_KEY39  ((CTSUICOG_MUTUAL3_KEY39 << 13) | (CTSUSDPA_MUTUAL3_KEY39 << 8) | CTSURICOA_MUTUAL3_KEY39)
#define CTSUSO1_MUTUAL3_KEY40  ((CTSUICOG_MUTUAL3_KEY40 << 13) | (CTSUSDPA_MUTUAL3_KEY40 << 8) | CTSURICOA_MUTUAL3_KEY40)
#define CTSUSO1_MUTUAL3_KEY41  ((CTSUICOG_MUTUAL3_KEY41 << 13) | (CTSUSDPA_MUTUAL3_KEY41 << 8) | CTSURICOA_MUTUAL3_KEY41)
#define CTSUSO1_MUTUAL3_KEY42  ((CTSUICOG_MUTUAL3_KEY42 << 13) | (CTSUSDPA_MUTUAL3_KEY42 << 8) | CTSURICOA_MUTUAL3_KEY42)
#define CTSUSO1_MUTUAL3_KEY43  ((CTSUICOG_MUTUAL3_KEY43 << 13) | (CTSUSDPA_MUTUAL3_KEY43 << 8) | CTSURICOA_MUTUAL3_KEY43)
#define CTSUSO1_MUTUAL3_KEY44  ((CTSUICOG_MUTUAL3_KEY44 << 13) | (CTSUSDPA_MUTUAL3_KEY44 << 8) | CTSURICOA_MUTUAL3_KEY44)
#define CTSUSO1_MUTUAL3_KEY45  ((CTSUICOG_MUTUAL3_KEY45 << 13) | (CTSUSDPA_MUTUAL3_KEY45 << 8) | CTSURICOA_MUTUAL3_KEY45)
#define CTSUSO1_MUTUAL3_KEY46  ((CTSUICOG_MUTUAL3_KEY46 << 13) | (CTSUSDPA_MUTUAL3_KEY46 << 8) | CTSURICOA_MUTUAL3_KEY46)
#define CTSUSO1_MUTUAL3_KEY47  ((CTSUICOG_MUTUAL3_KEY47 << 13) | (CTSUSDPA_MUTUAL3_KEY47 << 8) | CTSURICOA_MUTUAL3_KEY47)
#define CTSUSO1_MUTUAL3_KEY48  ((CTSUICOG_MUTUAL3_KEY48 << 13) | (CTSUSDPA_MUTUAL3_KEY48 << 8) | CTSURICOA_MUTUAL3_KEY48)
#define CTSUSO1_MUTUAL3_KEY49  ((CTSUICOG_MUTUAL3_KEY49 << 13) | (CTSUSDPA_MUTUAL3_KEY49 << 8) | CTSURICOA_MUTUAL3_KEY49)
#define CTSUSO1_MUTUAL3_KEY50  ((CTSUICOG_MUTUAL3_KEY50 << 13) | (CTSUSDPA_MUTUAL3_KEY50 << 8) | CTSURICOA_MUTUAL3_KEY50)
#define CTSUSO1_MUTUAL3_KEY51  ((CTSUICOG_MUTUAL3_KEY51 << 13) | (CTSUSDPA_MUTUAL3_KEY51 << 8) | CTSURICOA_MUTUAL3_KEY51)
#define CTSUSO1_MUTUAL3_KEY52  ((CTSUICOG_MUTUAL3_KEY52 << 13) | (CTSUSDPA_MUTUAL3_KEY52 << 8) | CTSURICOA_MUTUAL3_KEY52)
#define CTSUSO1_MUTUAL3_KEY53  ((CTSUICOG_MUTUAL3_KEY53 << 13) | (CTSUSDPA_MUTUAL3_KEY53 << 8) | CTSURICOA_MUTUAL3_KEY53)
#define CTSUSO1_MUTUAL3_KEY54  ((CTSUICOG_MUTUAL3_KEY54 << 13) | (CTSUSDPA_MUTUAL3_KEY54 << 8) | CTSURICOA_MUTUAL3_KEY54)
#define CTSUSO1_MUTUAL3_KEY55  ((CTSUICOG_MUTUAL3_KEY55 << 13) | (CTSUSDPA_MUTUAL3_KEY55 << 8) | CTSURICOA_MUTUAL3_KEY55)
#define CTSUSO1_MUTUAL3_KEY56  ((CTSUICOG_MUTUAL3_KEY56 << 13) | (CTSUSDPA_MUTUAL3_KEY56 << 8) | CTSURICOA_MUTUAL3_KEY56)
#define CTSUSO1_MUTUAL3_KEY57  ((CTSUICOG_MUTUAL3_KEY57 << 13) | (CTSUSDPA_MUTUAL3_KEY57 << 8) | CTSURICOA_MUTUAL3_KEY57)
#define CTSUSO1_MUTUAL3_KEY58  ((CTSUICOG_MUTUAL3_KEY58 << 13) | (CTSUSDPA_MUTUAL3_KEY58 << 8) | CTSURICOA_MUTUAL3_KEY58)
#define CTSUSO1_MUTUAL3_KEY59  ((CTSUICOG_MUTUAL3_KEY59 << 13) | (CTSUSDPA_MUTUAL3_KEY59 << 8) | CTSURICOA_MUTUAL3_KEY59)
#define CTSUSO1_MUTUAL3_KEY60  ((CTSUICOG_MUTUAL3_KEY60 << 13) | (CTSUSDPA_MUTUAL3_KEY60 << 8) | CTSURICOA_MUTUAL3_KEY60)
#define CTSUSO1_MUTUAL3_KEY61  ((CTSUICOG_MUTUAL3_KEY61 << 13) | (CTSUSDPA_MUTUAL3_KEY61 << 8) | CTSURICOA_MUTUAL3_KEY61)
#define CTSUSO1_MUTUAL3_KEY62  ((CTSUICOG_MUTUAL3_KEY62 << 13) | (CTSUSDPA_MUTUAL3_KEY62 << 8) | CTSURICOA_MUTUAL3_KEY62)
#define CTSUSO1_MUTUAL3_KEY63  ((CTSUICOG_MUTUAL3_KEY63 << 13) | (CTSUSDPA_MUTUAL3_KEY63 << 8) | CTSURICOA_MUTUAL3_KEY63)
#endif    // ( MUTUAL_METHOD_NUM >= 4 )

#if ( MUTUAL_METHOD_NUM >= 5 )
/*====================================================================================================================*/
/*=====     Mutual-measurement 4 TS enable definition    =============================================================*/
/*====================================================================================================================*/
#define MUTUAL4_ENABLE_TS00              (0)        /* Mutual 4 TS00 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS01              (0)        /* Mutual 4 TS01 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS02              (0)        /* Mutual 4 TS02 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS03              (0)        /* Mutual 4 TS03 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS04              (0)        /* Mutual 4 TS04 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS05              (0)        /* Mutual 4 TS05 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS06              (0)        /* Mutual 4 TS06 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS07              (0)        /* Mutual 4 TS07 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS08              (0)        /* Mutual 4 TS08 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS09              (0)        /* Mutual 4 TS09 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS10              (0)        /* Mutual 4 TS10 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS11              (0)        /* Mutual 4 TS11 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS12              (0)        /* Mutual 4 TS12 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS13              (0)        /* Mutual 4 TS13 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS14              (0)        /* Mutual 4 TS14 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS15              (0)        /* Mutual 4 TS15 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS16              (0)        /* Mutual 4 TS16 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS17              (0)        /* Mutual 4 TS17 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS18              (0)        /* Mutual 4 TS18 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS19              (0)        /* Mutual 4 TS19 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS20              (0)        /* Mutual 4 TS20 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS21              (0)        /* Mutual 4 TS21 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS22              (0)        /* Mutual 4 TS22 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS23              (0)        /* Mutual 4 TS23 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS24              (0)        /* Mutual 4 TS24 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS25              (0)        /* Mutual 4 TS25 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS26              (0)        /* Mutual 4 TS26 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS27              (0)        /* Mutual 4 TS27 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS28              (0)        /* Mutual 4 TS28 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS29              (0)        /* Mutual 4 TS29 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS30              (0)        /* Mutual 4 TS30 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS31              (0)        /* Mutual 4 TS31 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS32              (0)        /* Mutual 4 TS32 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS33              (0)        /* Mutual 4 TS33 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS34              (0)        /* Mutual 4 TS34 0:disable 1:enable                               */
#define MUTUAL4_ENABLE_TS35              (0)        /* Mutual 4 TS35 0:disable 1:enable                               */

/*****    Address 000A 0906h CTSU Channel enable control register 0    ************************************************/
#define CTSUCHAC0_MUTUAL4_ENABLE_TS      ((MUTUAL4_ENABLE_TS00 << 0) | (MUTUAL4_ENABLE_TS01 << 1) | \
                                          (MUTUAL4_ENABLE_TS02 << 2) | (MUTUAL4_ENABLE_TS03 << 3) | \
                                          (MUTUAL4_ENABLE_TS04 << 4) | (MUTUAL4_ENABLE_TS05 << 5) | \
                                          (MUTUAL4_ENABLE_TS06 << 6) | (MUTUAL4_ENABLE_TS07 << 7))

/*****    Address 000A 0907h CTSU Channel enable control register 1    ************************************************/
#define CTSUCHAC1_MUTUAL4_ENABLE_TS      ((MUTUAL4_ENABLE_TS08 << 0) | (MUTUAL4_ENABLE_TS09 << 1) | \
                                          (MUTUAL4_ENABLE_TS10 << 2) | (MUTUAL4_ENABLE_TS11 << 3) | \
                                          (MUTUAL4_ENABLE_TS12 << 4) | (MUTUAL4_ENABLE_TS13 << 5) | \
                                          (MUTUAL4_ENABLE_TS14 << 6) | (MUTUAL4_ENABLE_TS15 << 7))

/*****    Address 000A 0908h CTSU Channel enable control register 2    ************************************************/
#define CTSUCHAC2_MUTUAL4_ENABLE_TS      ((MUTUAL4_ENABLE_TS16 << 0) | (MUTUAL4_ENABLE_TS17 << 1) | \
                                          (MUTUAL4_ENABLE_TS18 << 2) | (MUTUAL4_ENABLE_TS19 << 3) | \
                                          (MUTUAL4_ENABLE_TS20 << 4) | (MUTUAL4_ENABLE_TS21 << 5) | \
                                          (MUTUAL4_ENABLE_TS22 << 6) | (MUTUAL4_ENABLE_TS23 << 7))

/*****    Address 000A 0909h CTSU Channel enable control register 3    ************************************************/
#define CTSUCHAC3_MUTUAL4_ENABLE_TS      ((MUTUAL4_ENABLE_TS24 << 0) | (MUTUAL4_ENABLE_TS25 << 1) | \
                                          (MUTUAL4_ENABLE_TS26 << 2) | (MUTUAL4_ENABLE_TS27 << 3) | \
                                          (MUTUAL4_ENABLE_TS28 << 4) | (MUTUAL4_ENABLE_TS29 << 5) | \
                                          (MUTUAL4_ENABLE_TS30 << 6) | (MUTUAL4_ENABLE_TS31 << 7))

/*****    Address 000A 090ah CTSU Channel enable control register 4    ************************************************/
#define CTSUCHAC4_MUTUAL4_ENABLE_TS      ((MUTUAL4_ENABLE_TS32 << 0) | (MUTUAL4_ENABLE_TS33 << 1) | \
                                          (MUTUAL4_ENABLE_TS34 << 2) | (MUTUAL4_ENABLE_TS35 << 3))

/* SUM of Channels */ /* Do not edit this macro definition */
#define MUTUAL4_ENABLE_NUM               (MUTUAL4_ENABLE_TS00 + MUTUAL4_ENABLE_TS01 + MUTUAL4_ENABLE_TS02 + \
                                          MUTUAL4_ENABLE_TS03 + MUTUAL4_ENABLE_TS04 + MUTUAL4_ENABLE_TS05 + \
                                          MUTUAL4_ENABLE_TS06 + MUTUAL4_ENABLE_TS07 + MUTUAL4_ENABLE_TS08 + \
                                          MUTUAL4_ENABLE_TS09 + MUTUAL4_ENABLE_TS10 + MUTUAL4_ENABLE_TS11 + \
                                          MUTUAL4_ENABLE_TS12 + MUTUAL4_ENABLE_TS13 + MUTUAL4_ENABLE_TS14 + \
                                          MUTUAL4_ENABLE_TS15 + MUTUAL4_ENABLE_TS16 + MUTUAL4_ENABLE_TS17 + \
                                          MUTUAL4_ENABLE_TS18 + MUTUAL4_ENABLE_TS19 + MUTUAL4_ENABLE_TS20 + \
                                          MUTUAL4_ENABLE_TS21 + MUTUAL4_ENABLE_TS22 + MUTUAL4_ENABLE_TS23 + \
                                          MUTUAL4_ENABLE_TS24 + MUTUAL4_ENABLE_TS25 + MUTUAL4_ENABLE_TS26 + \
                                          MUTUAL4_ENABLE_TS27 + MUTUAL4_ENABLE_TS28 + MUTUAL4_ENABLE_TS29 + \
                                          MUTUAL4_ENABLE_TS30 + MUTUAL4_ENABLE_TS31 + MUTUAL4_ENABLE_TS32 + \
                                          MUTUAL4_ENABLE_TS33 + MUTUAL4_ENABLE_TS34 + MUTUAL4_ENABLE_TS35)

/*====================================================================================================================*/
/*=====     Mutual-measurement 0 function definition     =============================================================*/
/*====================================================================================================================*/
#define MUTUAL4_FUNCTION_TS00            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS01            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS02            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS03            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS04            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS05            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS06            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS07            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS08            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS09            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS10            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS11            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS12            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS13            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS14            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS15            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS16            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS17            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS18            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS19            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS20            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS21            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS22            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS23            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS24            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS25            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS26            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS27            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS28            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS29            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS30            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS31            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS32            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS33            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS34            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL4_FUNCTION_TS35            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */

/*****    Address 000A 090Bh CTSU Channel send and receive control register 0 *****************************************/
#define CTSUCHTRC0_MUTUAL4_TRANSMIT_TS   ((MUTUAL4_FUNCTION_TS00 << 0) | (MUTUAL4_FUNCTION_TS01 << 1) | \
                                          (MUTUAL4_FUNCTION_TS02 << 2) | (MUTUAL4_FUNCTION_TS03 << 3) | \
                                          (MUTUAL4_FUNCTION_TS04 << 4) | (MUTUAL4_FUNCTION_TS05 << 5) | \
                                          (MUTUAL4_FUNCTION_TS06 << 6) | (MUTUAL4_FUNCTION_TS07 << 7))

/*****    Address 000A 090Ch CTSU Channel send and receive control register 1 *****************************************/
#define CTSUCHTRC1_MUTUAL4_TRANSMIT_TS   ((MUTUAL4_FUNCTION_TS08 << 0) | (MUTUAL4_FUNCTION_TS09 << 1) | \
                                          (MUTUAL4_FUNCTION_TS10 << 2) | (MUTUAL4_FUNCTION_TS11 << 3) | \
                                          (MUTUAL4_FUNCTION_TS12 << 4) | (MUTUAL4_FUNCTION_TS13 << 5) | \
                                          (MUTUAL4_FUNCTION_TS14 << 6) | (MUTUAL4_FUNCTION_TS15 << 7))

/*****    Address 000A 090Dh CTSU Channel send and receive control register 2 *****************************************/
#define CTSUCHTRC2_MUTUAL4_TRANSMIT_TS   ((MUTUAL4_FUNCTION_TS16 << 0) | (MUTUAL4_FUNCTION_TS17 << 1) | \
                                          (MUTUAL4_FUNCTION_TS18 << 2) | (MUTUAL4_FUNCTION_TS19 << 3) | \
                                          (MUTUAL4_FUNCTION_TS20 << 4) | (MUTUAL4_FUNCTION_TS21 << 5) | \
                                          (MUTUAL4_FUNCTION_TS22 << 6) | (MUTUAL4_FUNCTION_TS23 << 7))

/*****    Address 000A 090Eh CTSU Channel send and receive control register 3 *****************************************/
#define CTSUCHTRC3_MUTUAL4_TRANSMIT_TS   ((MUTUAL4_FUNCTION_TS24 << 0) | (MUTUAL4_FUNCTION_TS25 << 1) | \
                                          (MUTUAL4_FUNCTION_TS26 << 2) | (MUTUAL4_FUNCTION_TS27 << 3) | \
                                          (MUTUAL4_FUNCTION_TS28 << 4) | (MUTUAL4_FUNCTION_TS29 << 5) | \
                                          (MUTUAL4_FUNCTION_TS30 << 6) | (MUTUAL4_FUNCTION_TS31 << 7))

/*****    Address 000A 090Fh CTSU Channel send and receive control register 4 *****************************************/
#define CTSUCHTRC4_MUTUAL4_TRANSMIT_TS   ((MUTUAL4_FUNCTION_TS32 << 0) | (MUTUAL4_FUNCTION_TS33 << 1) | \
                                          (MUTUAL4_FUNCTION_TS34 << 2) | (MUTUAL4_FUNCTION_TS35 << 3))

#define TRANSMISSION4_NUM                  (MUTUAL4_FUNCTION_TS00 + MUTUAL4_FUNCTION_TS01 + MUTUAL4_FUNCTION_TS02 + \
                                            MUTUAL4_FUNCTION_TS03 + MUTUAL4_FUNCTION_TS04 + MUTUAL4_FUNCTION_TS05 + \
                                            MUTUAL4_FUNCTION_TS06 + MUTUAL4_FUNCTION_TS07 + MUTUAL4_FUNCTION_TS08 + \
                                            MUTUAL4_FUNCTION_TS09 + MUTUAL4_FUNCTION_TS10 + MUTUAL4_FUNCTION_TS11 + \
                                            MUTUAL4_FUNCTION_TS12 + MUTUAL4_FUNCTION_TS13 + MUTUAL4_FUNCTION_TS14 + \
                                            MUTUAL4_FUNCTION_TS15 + MUTUAL4_FUNCTION_TS16 + MUTUAL4_FUNCTION_TS17 + \
                                            MUTUAL4_FUNCTION_TS18 + MUTUAL4_FUNCTION_TS19 + MUTUAL4_FUNCTION_TS20 + \
                                            MUTUAL4_FUNCTION_TS21 + MUTUAL4_FUNCTION_TS22 + MUTUAL4_FUNCTION_TS23 + \
                                            MUTUAL4_FUNCTION_TS24 + MUTUAL4_FUNCTION_TS25 + MUTUAL4_FUNCTION_TS26 + \
                                            MUTUAL4_FUNCTION_TS27 + MUTUAL4_FUNCTION_TS28 + MUTUAL4_FUNCTION_TS29 + \
                                            MUTUAL4_FUNCTION_TS30 + MUTUAL4_FUNCTION_TS31 + MUTUAL4_FUNCTION_TS32 + \
                                            MUTUAL4_FUNCTION_TS33 + MUTUAL4_FUNCTION_TS34 + MUTUAL4_FUNCTION_TS35)

#define RECEPTION4_NUM                     (MUTUAL4_ENABLE_NUM - TRANSMISSION4_NUM)
#define MUTUAL4_NUM                        (TRANSMISSION4_NUM * RECEPTION4_NUM)

#if TRANSMISSION4_NUM == 0
    #error "Send TS Setting error ( TRANSMISSION4_NUM = 0 )"
#endif
#if RECEPTION4_NUM == 0
    #error "Receive TS Setting error ( RECEPTION_NUM4 = 0 )"
#endif

/*****    Address 000A 0912h CTSU High-Pass Noise Reduction Spectrum Diffusion Control Register    ********************/
/**********************************************************************************************************************/
/*    CTSU Spectrum Diffusion Frequency Division Setting                                                              */
/*    Base Clock Frequency fb (MHz)   CTSUSSDIV[3:0] Bit Setting                                                      */
/*          4.00 =< fb                           0x00                                                                 */
/*          2.00 =< fb  < 4.00                   0x01                                                                 */
/*          1.33 =< fb  < 2.00                   0x02                                                                 */
/*          1.00 =< fb  < 1.33                   0x03                                                                 */
/*          0.80 =< fb  < 1.00                   0x04                                                                 */
/*          0.67 =< fb  < 0.80                   0x05                                                                 */
/*          0.57 =< fb  < 0.67                   0x06                                                                 */
/*          0.50 =< fb  < 0.57                   0x07                                                                 */
/*          0.44 =< fb  < 0.50                   0x08                                                                 */
/*          0.40 =< fb  < 0.44                   0x09                                                                 */
/*          0.36 =< fb  < 0.40                   0x0A                                                                 */
/*          0.33 =< fb  < 0.36                   0x0B                                                                 */
/*          0.31 =< fb  < 0.33                   0x0C                                                                 */
/*          0.29 =< fb  < 0.31                   0x0D                                                                 */
/*          0.27 =< fb  < 0.29                   0x0E                                                                 */
/*                  fb =< 0.25                   0x0F                                                                 */
/**********************************************************************************************************************/
#define CTSUSSDIV_MUTUAL4_KEY00         (0x01)                  /* Mutual 4 Key00 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY01         (0x01)                  /* Mutual 4 Key01 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY02         (0x01)                  /* Mutual 4 Key02 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY03         (0x01)                  /* Mutual 4 Key03 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY04         (0x01)                  /* Mutual 4 Key04 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY05         (0x01)                  /* Mutual 4 Key05 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY06         (0x01)                  /* Mutual 4 Key06 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY07         (0x01)                  /* Mutual 4 Key07 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY08         (0x01)                  /* Mutual 4 Key08 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY09         (0x01)                  /* Mutual 4 Key09 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY10         (0x01)                  /* Mutual 4 Key10 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY11         (0x01)                  /* Mutual 4 Key11 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY12         (0x01)                  /* Mutual 4 Key12 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY13         (0x01)                  /* Mutual 4 Key13 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY14         (0x01)                  /* Mutual 4 Key14 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY15         (0x01)                  /* Mutual 4 Key15 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY16         (0x01)                  /* Mutual 4 Key16 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY17         (0x01)                  /* Mutual 4 Key17 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY18         (0x01)                  /* Mutual 4 Key18 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY19         (0x01)                  /* Mutual 4 Key19 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY20         (0x01)                  /* Mutual 4 Key20 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY21         (0x01)                  /* Mutual 4 Key21 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY22         (0x01)                  /* Mutual 4 Key22 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY23         (0x01)                  /* Mutual 4 Key23 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY24         (0x01)                  /* Mutual 4 Key24 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY25         (0x01)                  /* Mutual 4 Key25 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY26         (0x01)                  /* Mutual 4 Key26 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY27         (0x01)                  /* Mutual 4 Key27 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY28         (0x01)                  /* Mutual 4 Key28 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY29         (0x01)                  /* Mutual 4 Key29 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY30         (0x01)                  /* Mutual 4 Key30 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY31         (0x01)                  /* Mutual 4 Key31 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY32         (0x01)                  /* Mutual 4 Key32 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY33         (0x01)                  /* Mutual 4 Key33 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY34         (0x01)                  /* Mutual 4 Key34 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY35         (0x01)                  /* Mutual 4 Key35 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY36         (0x01)                  /* Mutual 4 Key36 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY37         (0x01)                  /* Mutual 4 Key37 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY38         (0x01)                  /* Mutual 4 Key38 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY39         (0x01)                  /* Mutual 4 Key39 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY40         (0x01)                  /* Mutual 4 Key40 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY41         (0x01)                  /* Mutual 4 Key41 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY42         (0x01)                  /* Mutual 4 Key42 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY43         (0x01)                  /* Mutual 4 Key43 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY44         (0x01)                  /* Mutual 4 Key44 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY45         (0x01)                  /* Mutual 4 Key45 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY46         (0x01)                  /* Mutual 4 Key46 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY47         (0x01)                  /* Mutual 4 Key47 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY48         (0x01)                  /* Mutual 4 Key48 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY49         (0x01)                  /* Mutual 4 Key49 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY50         (0x01)                  /* Mutual 4 Key50 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY51         (0x01)                  /* Mutual 4 Key51 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY52         (0x01)                  /* Mutual 4 Key52 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY53         (0x01)                  /* Mutual 4 Key53 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY54         (0x01)                  /* Mutual 4 Key54 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY55         (0x01)                  /* Mutual 4 Key55 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY56         (0x01)                  /* Mutual 4 Key56 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY57         (0x01)                  /* Mutual 4 Key57 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY58         (0x01)                  /* Mutual 4 Key58 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY59         (0x01)                  /* Mutual 4 Key59 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY60         (0x01)                  /* Mutual 4 Key60 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY61         (0x01)                  /* Mutual 4 Key61 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY62         (0x01)                  /* Mutual 4 Key62 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL4_KEY63         (0x01)                  /* Mutual 4 Key63 CTSUSDIV                            */

#define CTSUSSC_MUTUAL4_KEY00           (CTSUSSDIV_MUTUAL4_KEY00 << 8)
#define CTSUSSC_MUTUAL4_KEY01           (CTSUSSDIV_MUTUAL4_KEY01 << 8)
#define CTSUSSC_MUTUAL4_KEY02           (CTSUSSDIV_MUTUAL4_KEY02 << 8)
#define CTSUSSC_MUTUAL4_KEY03           (CTSUSSDIV_MUTUAL4_KEY03 << 8)
#define CTSUSSC_MUTUAL4_KEY04           (CTSUSSDIV_MUTUAL4_KEY04 << 8)
#define CTSUSSC_MUTUAL4_KEY05           (CTSUSSDIV_MUTUAL4_KEY05 << 8)
#define CTSUSSC_MUTUAL4_KEY06           (CTSUSSDIV_MUTUAL4_KEY06 << 8)
#define CTSUSSC_MUTUAL4_KEY07           (CTSUSSDIV_MUTUAL4_KEY07 << 8)
#define CTSUSSC_MUTUAL4_KEY08           (CTSUSSDIV_MUTUAL4_KEY08 << 8)
#define CTSUSSC_MUTUAL4_KEY09           (CTSUSSDIV_MUTUAL4_KEY09 << 8)
#define CTSUSSC_MUTUAL4_KEY10           (CTSUSSDIV_MUTUAL4_KEY10 << 8)
#define CTSUSSC_MUTUAL4_KEY11           (CTSUSSDIV_MUTUAL4_KEY11 << 8)
#define CTSUSSC_MUTUAL4_KEY12           (CTSUSSDIV_MUTUAL4_KEY12 << 8)
#define CTSUSSC_MUTUAL4_KEY13           (CTSUSSDIV_MUTUAL4_KEY13 << 8)
#define CTSUSSC_MUTUAL4_KEY14           (CTSUSSDIV_MUTUAL4_KEY14 << 8)
#define CTSUSSC_MUTUAL4_KEY15           (CTSUSSDIV_MUTUAL4_KEY15 << 8)
#define CTSUSSC_MUTUAL4_KEY16           (CTSUSSDIV_MUTUAL4_KEY16 << 8)
#define CTSUSSC_MUTUAL4_KEY17           (CTSUSSDIV_MUTUAL4_KEY17 << 8)
#define CTSUSSC_MUTUAL4_KEY18           (CTSUSSDIV_MUTUAL4_KEY18 << 8)
#define CTSUSSC_MUTUAL4_KEY19           (CTSUSSDIV_MUTUAL4_KEY19 << 8)
#define CTSUSSC_MUTUAL4_KEY20           (CTSUSSDIV_MUTUAL4_KEY20 << 8)
#define CTSUSSC_MUTUAL4_KEY21           (CTSUSSDIV_MUTUAL4_KEY21 << 8)
#define CTSUSSC_MUTUAL4_KEY22           (CTSUSSDIV_MUTUAL4_KEY22 << 8)
#define CTSUSSC_MUTUAL4_KEY23           (CTSUSSDIV_MUTUAL4_KEY23 << 8)
#define CTSUSSC_MUTUAL4_KEY24           (CTSUSSDIV_MUTUAL4_KEY24 << 8)
#define CTSUSSC_MUTUAL4_KEY25           (CTSUSSDIV_MUTUAL4_KEY25 << 8)
#define CTSUSSC_MUTUAL4_KEY26           (CTSUSSDIV_MUTUAL4_KEY26 << 8)
#define CTSUSSC_MUTUAL4_KEY27           (CTSUSSDIV_MUTUAL4_KEY27 << 8)
#define CTSUSSC_MUTUAL4_KEY28           (CTSUSSDIV_MUTUAL4_KEY28 << 8)
#define CTSUSSC_MUTUAL4_KEY29           (CTSUSSDIV_MUTUAL4_KEY29 << 8)
#define CTSUSSC_MUTUAL4_KEY30           (CTSUSSDIV_MUTUAL4_KEY30 << 8)
#define CTSUSSC_MUTUAL4_KEY31           (CTSUSSDIV_MUTUAL4_KEY31 << 8)
#define CTSUSSC_MUTUAL4_KEY32           (CTSUSSDIV_MUTUAL4_KEY32 << 8)
#define CTSUSSC_MUTUAL4_KEY33           (CTSUSSDIV_MUTUAL4_KEY33 << 8)
#define CTSUSSC_MUTUAL4_KEY34           (CTSUSSDIV_MUTUAL4_KEY34 << 8)
#define CTSUSSC_MUTUAL4_KEY35           (CTSUSSDIV_MUTUAL4_KEY35 << 8)
#define CTSUSSC_MUTUAL4_KEY36           (CTSUSSDIV_MUTUAL4_KEY36 << 8)
#define CTSUSSC_MUTUAL4_KEY37           (CTSUSSDIV_MUTUAL4_KEY37 << 8)
#define CTSUSSC_MUTUAL4_KEY38           (CTSUSSDIV_MUTUAL4_KEY38 << 8)
#define CTSUSSC_MUTUAL4_KEY39           (CTSUSSDIV_MUTUAL4_KEY39 << 8)
#define CTSUSSC_MUTUAL4_KEY40           (CTSUSSDIV_MUTUAL4_KEY40 << 8)
#define CTSUSSC_MUTUAL4_KEY41           (CTSUSSDIV_MUTUAL4_KEY41 << 8)
#define CTSUSSC_MUTUAL4_KEY42           (CTSUSSDIV_MUTUAL4_KEY42 << 8)
#define CTSUSSC_MUTUAL4_KEY43           (CTSUSSDIV_MUTUAL4_KEY43 << 8)
#define CTSUSSC_MUTUAL4_KEY44           (CTSUSSDIV_MUTUAL4_KEY44 << 8)
#define CTSUSSC_MUTUAL4_KEY45           (CTSUSSDIV_MUTUAL4_KEY45 << 8)
#define CTSUSSC_MUTUAL4_KEY46           (CTSUSSDIV_MUTUAL4_KEY46 << 8)
#define CTSUSSC_MUTUAL4_KEY47           (CTSUSSDIV_MUTUAL4_KEY47 << 8)
#define CTSUSSC_MUTUAL4_KEY48           (CTSUSSDIV_MUTUAL4_KEY48 << 8)
#define CTSUSSC_MUTUAL4_KEY49           (CTSUSSDIV_MUTUAL4_KEY49 << 8)
#define CTSUSSC_MUTUAL4_KEY50           (CTSUSSDIV_MUTUAL4_KEY50 << 8)
#define CTSUSSC_MUTUAL4_KEY51           (CTSUSSDIV_MUTUAL4_KEY51 << 8)
#define CTSUSSC_MUTUAL4_KEY52           (CTSUSSDIV_MUTUAL4_KEY52 << 8)
#define CTSUSSC_MUTUAL4_KEY53           (CTSUSSDIV_MUTUAL4_KEY53 << 8)
#define CTSUSSC_MUTUAL4_KEY54           (CTSUSSDIV_MUTUAL4_KEY54 << 8)
#define CTSUSSC_MUTUAL4_KEY55           (CTSUSSDIV_MUTUAL4_KEY55 << 8)
#define CTSUSSC_MUTUAL4_KEY56           (CTSUSSDIV_MUTUAL4_KEY56 << 8)
#define CTSUSSC_MUTUAL4_KEY57           (CTSUSSDIV_MUTUAL4_KEY57 << 8)
#define CTSUSSC_MUTUAL4_KEY58           (CTSUSSDIV_MUTUAL4_KEY58 << 8)
#define CTSUSSC_MUTUAL4_KEY59           (CTSUSSDIV_MUTUAL4_KEY59 << 8)
#define CTSUSSC_MUTUAL4_KEY60           (CTSUSSDIV_MUTUAL4_KEY60 << 8)
#define CTSUSSC_MUTUAL4_KEY61           (CTSUSSDIV_MUTUAL4_KEY61 << 8)
#define CTSUSSC_MUTUAL4_KEY62           (CTSUSSDIV_MUTUAL4_KEY62 << 8)
#define CTSUSSC_MUTUAL4_KEY63           (CTSUSSDIV_MUTUAL4_KEY63 << 8)

/*****    Address 000A 0914h CTSU Sensor Offset Register 0     ********************************************************/
/**********************************************************************************************************************/
/*    CTSU Sensor Offset Adjustment                                                                                   */
/*      Current offset amount is 0       0x000                                                                        */
/*      Current offset amount is 1       0x001                                                                        */
/*      Current offset amount is 2       0x002                                                                        */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*      Current offset amount is 1023    0x3FF                                                                        */
/**********************************************************************************************************************/
#define CTSUSO_MUTUAL4_KEY00            (0x000)                 /* Mutual 4 Key00 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY01            (0x000)                 /* Mutual 4 Key01 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY02            (0x000)                 /* Mutual 4 Key02 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY03            (0x000)                 /* Mutual 4 Key03 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY04            (0x000)                 /* Mutual 4 Key04 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY05            (0x000)                 /* Mutual 4 Key05 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY06            (0x000)                 /* Mutual 4 Key06 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY07            (0x000)                 /* Mutual 4 Key07 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY08            (0x000)                 /* Mutual 4 Key08 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY09            (0x000)                 /* Mutual 4 Key09 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY10            (0x000)                 /* Mutual 4 Key10 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY11            (0x000)                 /* Mutual 4 Key11 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY12            (0x000)                 /* Mutual 4 Key12 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY13            (0x000)                 /* Mutual 4 Key13 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY14            (0x000)                 /* Mutual 4 Key14 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY15            (0x000)                 /* Mutual 4 Key15 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY16            (0x000)                 /* Mutual 4 Key16 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY17            (0x000)                 /* Mutual 4 Key17 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY18            (0x000)                 /* Mutual 4 Key18 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY19            (0x000)                 /* Mutual 4 Key19 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY20            (0x000)                 /* Mutual 4 Key20 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY21            (0x000)                 /* Mutual 4 Key21 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY22            (0x000)                 /* Mutual 4 Key22 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY23            (0x000)                 /* Mutual 4 Key23 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY24            (0x000)                 /* Mutual 4 Key24 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY25            (0x000)                 /* Mutual 4 Key25 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY26            (0x000)                 /* Mutual 4 Key26 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY27            (0x000)                 /* Mutual 4 Key27 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY28            (0x000)                 /* Mutual 4 Key28 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY29            (0x000)                 /* Mutual 4 Key29 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY30            (0x000)                 /* Mutual 4 Key30 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY31            (0x000)                 /* Mutual 4 Key31 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY32            (0x000)                 /* Mutual 4 Key32 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY33            (0x000)                 /* Mutual 4 Key33 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY34            (0x000)                 /* Mutual 4 Key34 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY35            (0x000)                 /* Mutual 4 Key35 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY36            (0x000)                 /* Mutual 4 Key36 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY37            (0x000)                 /* Mutual 4 Key37 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY38            (0x000)                 /* Mutual 4 Key38 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY39            (0x000)                 /* Mutual 4 Key39 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY40            (0x000)                 /* Mutual 4 Key40 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY41            (0x000)                 /* Mutual 4 Key41 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY42            (0x000)                 /* Mutual 4 Key42 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY43            (0x000)                 /* Mutual 4 Key43 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY44            (0x000)                 /* Mutual 4 Key44 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY45            (0x000)                 /* Mutual 4 Key45 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY46            (0x000)                 /* Mutual 4 Key46 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY47            (0x000)                 /* Mutual 4 Key47 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY48            (0x000)                 /* Mutual 4 Key48 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY49            (0x000)                 /* Mutual 4 Key49 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY50            (0x000)                 /* Mutual 4 Key50 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY51            (0x000)                 /* Mutual 4 Key51 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY52            (0x000)                 /* Mutual 4 Key52 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY53            (0x000)                 /* Mutual 4 Key53 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY54            (0x000)                 /* Mutual 4 Key54 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY55            (0x000)                 /* Mutual 4 Key55 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY56            (0x000)                 /* Mutual 4 Key56 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY57            (0x000)                 /* Mutual 4 Key57 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY58            (0x000)                 /* Mutual 4 Key58 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY59            (0x000)                 /* Mutual 4 Key59 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY60            (0x000)                 /* Mutual 4 Key60 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY61            (0x000)                 /* Mutual 4 Key61 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY62            (0x000)                 /* Mutual 4 Key62 CTSUSO                              */
#define CTSUSO_MUTUAL4_KEY63            (0x000)                 /* Mutual 4 Key63 CTSUSO                              */

/**********************************************************************************************************************/
/*    CTSU Measurement Count Setting                                                                                  */
/*      4.0MHz    7                                                                                                   */
/*      2.0MHz    3                                                                                                   */
/*      1.0MHz    1                                                                                                   */
/*      0.5MHz    0                                                                                                   */
/**********************************************************************************************************************/
#define CTSUSNUM_MUTUAL4_KEY00          (3)                     /* Mutual 4 Key00 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY01          (3)                     /* Mutual 4 Key01 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY02          (3)                     /* Mutual 4 Key02 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY03          (3)                     /* Mutual 4 Key03 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY04          (3)                     /* Mutual 4 Key04 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY05          (3)                     /* Mutual 4 Key05 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY06          (3)                     /* Mutual 4 Key06 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY07          (3)                     /* Mutual 4 Key07 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY08          (3)                     /* Mutual 4 Key08 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY09          (3)                     /* Mutual 4 Key09 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY10          (3)                     /* Mutual 4 Key10 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY11          (3)                     /* Mutual 4 Key11 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY12          (3)                     /* Mutual 4 Key12 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY13          (3)                     /* Mutual 4 Key13 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY14          (3)                     /* Mutual 4 Key14 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY15          (3)                     /* Mutual 4 Key15 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY16          (3)                     /* Mutual 4 Key16 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY17          (3)                     /* Mutual 4 Key17 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY18          (3)                     /* Mutual 4 Key18 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY19          (3)                     /* Mutual 4 Key19 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY20          (3)                     /* Mutual 4 Key20 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY21          (3)                     /* Mutual 4 Key21 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY22          (3)                     /* Mutual 4 Key22 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY23          (3)                     /* Mutual 4 Key23 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY24          (3)                     /* Mutual 4 Key24 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY25          (3)                     /* Mutual 4 Key25 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY26          (3)                     /* Mutual 4 Key26 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY27          (3)                     /* Mutual 4 Key27 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY28          (3)                     /* Mutual 4 Key28 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY29          (3)                     /* Mutual 4 Key29 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY30          (3)                     /* Mutual 4 Key30 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY31          (3)                     /* Mutual 4 Key31 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY32          (3)                     /* Mutual 4 Key32 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY33          (3)                     /* Mutual 4 Key33 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY34          (3)                     /* Mutual 4 Key34 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY35          (3)                     /* Mutual 4 Key35 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY36          (3)                     /* Mutual 4 Key36 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY37          (3)                     /* Mutual 4 Key37 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY38          (3)                     /* Mutual 4 Key38 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY39          (3)                     /* Mutual 4 Key39 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY40          (3)                     /* Mutual 4 Key40 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY41          (3)                     /* Mutual 4 Key41 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY42          (3)                     /* Mutual 4 Key42 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY43          (3)                     /* Mutual 4 Key43 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY44          (3)                     /* Mutual 4 Key44 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY45          (3)                     /* Mutual 4 Key45 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY46          (3)                     /* Mutual 4 Key46 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY47          (3)                     /* Mutual 4 Key47 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY48          (3)                     /* Mutual 4 Key48 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY49          (3)                     /* Mutual 4 Key49 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY50          (3)                     /* Mutual 4 Key50 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY51          (3)                     /* Mutual 4 Key51 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY52          (3)                     /* Mutual 4 Key52 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY53          (3)                     /* Mutual 4 Key53 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY54          (3)                     /* Mutual 4 Key54 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY55          (3)                     /* Mutual 4 Key55 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY56          (3)                     /* Mutual 4 Key56 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY57          (3)                     /* Mutual 4 Key57 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY58          (3)                     /* Mutual 4 Key58 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY59          (3)                     /* Mutual 4 Key59 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY60          (3)                     /* Mutual 4 Key60 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY61          (3)                     /* Mutual 4 Key61 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY62          (3)                     /* Mutual 4 Key62 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL4_KEY63          (3)                     /* Mutual 4 Key63 CTSUSNUM                            */

#define CTSUSO0_MUTUAL4_KEY00           ((CTSUSNUM_MUTUAL4_KEY00 << 10) | CTSUSO_MUTUAL4_KEY00)
#define CTSUSO0_MUTUAL4_KEY01           ((CTSUSNUM_MUTUAL4_KEY01 << 10) | CTSUSO_MUTUAL4_KEY01)
#define CTSUSO0_MUTUAL4_KEY02           ((CTSUSNUM_MUTUAL4_KEY02 << 10) | CTSUSO_MUTUAL4_KEY02)
#define CTSUSO0_MUTUAL4_KEY03           ((CTSUSNUM_MUTUAL4_KEY03 << 10) | CTSUSO_MUTUAL4_KEY03)
#define CTSUSO0_MUTUAL4_KEY04           ((CTSUSNUM_MUTUAL4_KEY04 << 10) | CTSUSO_MUTUAL4_KEY04)
#define CTSUSO0_MUTUAL4_KEY05           ((CTSUSNUM_MUTUAL4_KEY05 << 10) | CTSUSO_MUTUAL4_KEY05)
#define CTSUSO0_MUTUAL4_KEY06           ((CTSUSNUM_MUTUAL4_KEY06 << 10) | CTSUSO_MUTUAL4_KEY06)
#define CTSUSO0_MUTUAL4_KEY07           ((CTSUSNUM_MUTUAL4_KEY07 << 10) | CTSUSO_MUTUAL4_KEY07)
#define CTSUSO0_MUTUAL4_KEY08           ((CTSUSNUM_MUTUAL4_KEY08 << 10) | CTSUSO_MUTUAL4_KEY08)
#define CTSUSO0_MUTUAL4_KEY09           ((CTSUSNUM_MUTUAL4_KEY09 << 10) | CTSUSO_MUTUAL4_KEY09)
#define CTSUSO0_MUTUAL4_KEY10           ((CTSUSNUM_MUTUAL4_KEY10 << 10) | CTSUSO_MUTUAL4_KEY10)
#define CTSUSO0_MUTUAL4_KEY11           ((CTSUSNUM_MUTUAL4_KEY11 << 10) | CTSUSO_MUTUAL4_KEY11)
#define CTSUSO0_MUTUAL4_KEY12           ((CTSUSNUM_MUTUAL4_KEY12 << 10) | CTSUSO_MUTUAL4_KEY12)
#define CTSUSO0_MUTUAL4_KEY13           ((CTSUSNUM_MUTUAL4_KEY13 << 10) | CTSUSO_MUTUAL4_KEY13)
#define CTSUSO0_MUTUAL4_KEY14           ((CTSUSNUM_MUTUAL4_KEY14 << 10) | CTSUSO_MUTUAL4_KEY14)
#define CTSUSO0_MUTUAL4_KEY15           ((CTSUSNUM_MUTUAL4_KEY15 << 10) | CTSUSO_MUTUAL4_KEY15)
#define CTSUSO0_MUTUAL4_KEY16           ((CTSUSNUM_MUTUAL4_KEY16 << 10) | CTSUSO_MUTUAL4_KEY16)
#define CTSUSO0_MUTUAL4_KEY17           ((CTSUSNUM_MUTUAL4_KEY17 << 10) | CTSUSO_MUTUAL4_KEY17)
#define CTSUSO0_MUTUAL4_KEY18           ((CTSUSNUM_MUTUAL4_KEY18 << 10) | CTSUSO_MUTUAL4_KEY18)
#define CTSUSO0_MUTUAL4_KEY19           ((CTSUSNUM_MUTUAL4_KEY19 << 10) | CTSUSO_MUTUAL4_KEY19)
#define CTSUSO0_MUTUAL4_KEY20           ((CTSUSNUM_MUTUAL4_KEY20 << 10) | CTSUSO_MUTUAL4_KEY20)
#define CTSUSO0_MUTUAL4_KEY21           ((CTSUSNUM_MUTUAL4_KEY21 << 10) | CTSUSO_MUTUAL4_KEY21)
#define CTSUSO0_MUTUAL4_KEY22           ((CTSUSNUM_MUTUAL4_KEY22 << 10) | CTSUSO_MUTUAL4_KEY22)
#define CTSUSO0_MUTUAL4_KEY23           ((CTSUSNUM_MUTUAL4_KEY23 << 10) | CTSUSO_MUTUAL4_KEY23)
#define CTSUSO0_MUTUAL4_KEY24           ((CTSUSNUM_MUTUAL4_KEY24 << 10) | CTSUSO_MUTUAL4_KEY24)
#define CTSUSO0_MUTUAL4_KEY25           ((CTSUSNUM_MUTUAL4_KEY25 << 10) | CTSUSO_MUTUAL4_KEY25)
#define CTSUSO0_MUTUAL4_KEY26           ((CTSUSNUM_MUTUAL4_KEY26 << 10) | CTSUSO_MUTUAL4_KEY26)
#define CTSUSO0_MUTUAL4_KEY27           ((CTSUSNUM_MUTUAL4_KEY27 << 10) | CTSUSO_MUTUAL4_KEY27)
#define CTSUSO0_MUTUAL4_KEY28           ((CTSUSNUM_MUTUAL4_KEY28 << 10) | CTSUSO_MUTUAL4_KEY28)
#define CTSUSO0_MUTUAL4_KEY29           ((CTSUSNUM_MUTUAL4_KEY29 << 10) | CTSUSO_MUTUAL4_KEY29)
#define CTSUSO0_MUTUAL4_KEY30           ((CTSUSNUM_MUTUAL4_KEY30 << 10) | CTSUSO_MUTUAL4_KEY30)
#define CTSUSO0_MUTUAL4_KEY31           ((CTSUSNUM_MUTUAL4_KEY31 << 10) | CTSUSO_MUTUAL4_KEY31)
#define CTSUSO0_MUTUAL4_KEY32           ((CTSUSNUM_MUTUAL4_KEY32 << 10) | CTSUSO_MUTUAL4_KEY32)
#define CTSUSO0_MUTUAL4_KEY33           ((CTSUSNUM_MUTUAL4_KEY33 << 10) | CTSUSO_MUTUAL4_KEY33)
#define CTSUSO0_MUTUAL4_KEY34           ((CTSUSNUM_MUTUAL4_KEY34 << 10) | CTSUSO_MUTUAL4_KEY34)
#define CTSUSO0_MUTUAL4_KEY35           ((CTSUSNUM_MUTUAL4_KEY35 << 10) | CTSUSO_MUTUAL4_KEY35)
#define CTSUSO0_MUTUAL4_KEY36           ((CTSUSNUM_MUTUAL4_KEY36 << 10) | CTSUSO_MUTUAL4_KEY36)
#define CTSUSO0_MUTUAL4_KEY37           ((CTSUSNUM_MUTUAL4_KEY37 << 10) | CTSUSO_MUTUAL4_KEY37)
#define CTSUSO0_MUTUAL4_KEY38           ((CTSUSNUM_MUTUAL4_KEY38 << 10) | CTSUSO_MUTUAL4_KEY38)
#define CTSUSO0_MUTUAL4_KEY39           ((CTSUSNUM_MUTUAL4_KEY39 << 10) | CTSUSO_MUTUAL4_KEY39)
#define CTSUSO0_MUTUAL4_KEY40           ((CTSUSNUM_MUTUAL4_KEY40 << 10) | CTSUSO_MUTUAL4_KEY40)
#define CTSUSO0_MUTUAL4_KEY41           ((CTSUSNUM_MUTUAL4_KEY41 << 10) | CTSUSO_MUTUAL4_KEY41)
#define CTSUSO0_MUTUAL4_KEY42           ((CTSUSNUM_MUTUAL4_KEY42 << 10) | CTSUSO_MUTUAL4_KEY42)
#define CTSUSO0_MUTUAL4_KEY43           ((CTSUSNUM_MUTUAL4_KEY43 << 10) | CTSUSO_MUTUAL4_KEY43)
#define CTSUSO0_MUTUAL4_KEY44           ((CTSUSNUM_MUTUAL4_KEY44 << 10) | CTSUSO_MUTUAL4_KEY44)
#define CTSUSO0_MUTUAL4_KEY45           ((CTSUSNUM_MUTUAL4_KEY45 << 10) | CTSUSO_MUTUAL4_KEY45)
#define CTSUSO0_MUTUAL4_KEY46           ((CTSUSNUM_MUTUAL4_KEY46 << 10) | CTSUSO_MUTUAL4_KEY46)
#define CTSUSO0_MUTUAL4_KEY47           ((CTSUSNUM_MUTUAL4_KEY47 << 10) | CTSUSO_MUTUAL4_KEY47)
#define CTSUSO0_MUTUAL4_KEY48           ((CTSUSNUM_MUTUAL4_KEY48 << 10) | CTSUSO_MUTUAL4_KEY48)
#define CTSUSO0_MUTUAL4_KEY49           ((CTSUSNUM_MUTUAL4_KEY49 << 10) | CTSUSO_MUTUAL4_KEY49)
#define CTSUSO0_MUTUAL4_KEY50           ((CTSUSNUM_MUTUAL4_KEY50 << 10) | CTSUSO_MUTUAL4_KEY50)
#define CTSUSO0_MUTUAL4_KEY51           ((CTSUSNUM_MUTUAL4_KEY51 << 10) | CTSUSO_MUTUAL4_KEY51)
#define CTSUSO0_MUTUAL4_KEY52           ((CTSUSNUM_MUTUAL4_KEY52 << 10) | CTSUSO_MUTUAL4_KEY52)
#define CTSUSO0_MUTUAL4_KEY53           ((CTSUSNUM_MUTUAL4_KEY53 << 10) | CTSUSO_MUTUAL4_KEY53)
#define CTSUSO0_MUTUAL4_KEY54           ((CTSUSNUM_MUTUAL4_KEY54 << 10) | CTSUSO_MUTUAL4_KEY54)
#define CTSUSO0_MUTUAL4_KEY55           ((CTSUSNUM_MUTUAL4_KEY55 << 10) | CTSUSO_MUTUAL4_KEY55)
#define CTSUSO0_MUTUAL4_KEY56           ((CTSUSNUM_MUTUAL4_KEY56 << 10) | CTSUSO_MUTUAL4_KEY56)
#define CTSUSO0_MUTUAL4_KEY57           ((CTSUSNUM_MUTUAL4_KEY57 << 10) | CTSUSO_MUTUAL4_KEY57)
#define CTSUSO0_MUTUAL4_KEY58           ((CTSUSNUM_MUTUAL4_KEY58 << 10) | CTSUSO_MUTUAL4_KEY58)
#define CTSUSO0_MUTUAL4_KEY59           ((CTSUSNUM_MUTUAL4_KEY59 << 10) | CTSUSO_MUTUAL4_KEY59)
#define CTSUSO0_MUTUAL4_KEY60           ((CTSUSNUM_MUTUAL4_KEY60 << 10) | CTSUSO_MUTUAL4_KEY60)
#define CTSUSO0_MUTUAL4_KEY61           ((CTSUSNUM_MUTUAL4_KEY61 << 10) | CTSUSO_MUTUAL4_KEY61)
#define CTSUSO0_MUTUAL4_KEY62           ((CTSUSNUM_MUTUAL4_KEY62 << 10) | CTSUSO_MUTUAL4_KEY62)
#define CTSUSO0_MUTUAL4_KEY63           ((CTSUSNUM_MUTUAL4_KEY63 << 10) | CTSUSO_MUTUAL4_KEY63)

/*****    Address 000A 0914h CTSU Sensor Offset Register 1    *********************************************************/
/**********************************************************************************************************************/
/*    CTSU Reference ICO Current Adjustment                                                                           */
/*        Input current amount 0      0x00                                                                            */
/*        Input current amount 1      0x01                                                                            */
/*        Input current amount 2      0x02                                                                            */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*        Input current amount 254    0xFF                                                                            */
/**********************************************************************************************************************/
#define CTSURICOA_MUTUAL4_KEY00         (0x3F)                  /* Mutual 4 Key00 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY01         (0x3F)                  /* Mutual 4 Key01 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY02         (0x3F)                  /* Mutual 4 Key02 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY03         (0x3F)                  /* Mutual 4 Key03 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY04         (0x3F)                  /* Mutual 4 Key04 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY05         (0x3F)                  /* Mutual 4 Key05 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY06         (0x3F)                  /* Mutual 4 Key06 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY07         (0x3F)                  /* Mutual 4 Key07 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY08         (0x3F)                  /* Mutual 4 Key08 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY09         (0x3F)                  /* Mutual 4 Key09 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY10         (0x3F)                  /* Mutual 4 Key10 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY11         (0x3F)                  /* Mutual 4 Key11 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY12         (0x3F)                  /* Mutual 4 Key12 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY13         (0x3F)                  /* Mutual 4 Key13 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY14         (0x3F)                  /* Mutual 4 Key14 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY15         (0x3F)                  /* Mutual 4 Key15 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY16         (0x3F)                  /* Mutual 4 Key16 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY17         (0x3F)                  /* Mutual 4 Key17 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY18         (0x3F)                  /* Mutual 4 Key18 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY19         (0x3F)                  /* Mutual 4 Key19 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY20         (0x3F)                  /* Mutual 4 Key20 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY21         (0x3F)                  /* Mutual 4 Key21 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY22         (0x3F)                  /* Mutual 4 Key22 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY23         (0x3F)                  /* Mutual 4 Key23 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY24         (0x3F)                  /* Mutual 4 Key24 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY25         (0x3F)                  /* Mutual 4 Key25 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY26         (0x3F)                  /* Mutual 4 Key26 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY27         (0x3F)                  /* Mutual 4 Key27 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY28         (0x3F)                  /* Mutual 4 Key28 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY29         (0x3F)                  /* Mutual 4 Key29 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY30         (0x3F)                  /* Mutual 4 Key30 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY31         (0x3F)                  /* Mutual 4 Key31 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY32         (0x3F)                  /* Mutual 4 Key32 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY33         (0x3F)                  /* Mutual 4 Key33 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY34         (0x3F)                  /* Mutual 4 Key34 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY35         (0x3F)                  /* Mutual 4 Key35 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY36         (0x3F)                  /* Mutual 4 Key36 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY37         (0x3F)                  /* Mutual 4 Key37 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY38         (0x3F)                  /* Mutual 4 Key38 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY39         (0x3F)                  /* Mutual 4 Key39 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY40         (0x3F)                  /* Mutual 4 Key40 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY41         (0x3F)                  /* Mutual 4 Key41 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY42         (0x3F)                  /* Mutual 4 Key42 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY43         (0x3F)                  /* Mutual 4 Key43 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY44         (0x3F)                  /* Mutual 4 Key44 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY45         (0x3F)                  /* Mutual 4 Key45 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY46         (0x3F)                  /* Mutual 4 Key46 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY47         (0x3F)                  /* Mutual 4 Key47 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY48         (0x3F)                  /* Mutual 4 Key48 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY49         (0x3F)                  /* Mutual 4 Key49 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY50         (0x3F)                  /* Mutual 4 Key50 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY51         (0x3F)                  /* Mutual 4 Key51 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY52         (0x3F)                  /* Mutual 4 Key52 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY53         (0x3F)                  /* Mutual 4 Key53 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY54         (0x3F)                  /* Mutual 4 Key54 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY55         (0x3F)                  /* Mutual 4 Key55 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY56         (0x3F)                  /* Mutual 4 Key56 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY57         (0x3F)                  /* Mutual 4 Key57 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY58         (0x3F)                  /* Mutual 4 Key58 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY59         (0x3F)                  /* Mutual 4 Key59 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY60         (0x3F)                  /* Mutual 4 Key60 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY61         (0x3F)                  /* Mutual 4 Key61 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY62         (0x3F)                  /* Mutual 4 Key62 CTSUICOA                            */
#define CTSURICOA_MUTUAL4_KEY63         (0x3F)                  /* Mutual 4 Key63 CTSUICOA                            */

/**********************************************************************************************************************/
/*    CTSU Base Clock Setting                                                                                         */
/*        Operating clock divided by 2     0x00                                                                       */
/*        Operating clock divided by 4     0x01                                                                       */
/*        Operating clock divided by 6     0x02                                                                       */
/*                       :                                                                                            */
/*                       :                                                                                            */
/*        Operating clock divided by 64    0x1F                                                                       */
/*                                                                                                                    */
/*    Case : CTSU Operating Clock 32MHz      Case : CTSU Operating Clock 24MHz      Case : CTSU Operating Clock 16MHz */
/*           4.0MHz <--- 0x03                       4.0MHz <--- 0x02                       4.0MHz <--- 0x01           */
/*           2.0MHz <--- 0x07                       2.0MHz <--- 0x05                       2.0MHz <--- 0x03           */
/*           1.0MHz <--- 0x0F                       1.0MHz <--- 0x0B                       1.0MHz <--- 0x07           */
/*           0.5MHz <--- 0x1F                       0.5MHz <--- 0x17                       0.5MHz <--- 0x0F           */
/**********************************************************************************************************************/
#define CTSUSDPA_MUTUAL4_KEY00          (7)                     /* Mutual 4 Key00 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY01          (7)                     /* Mutual 4 Key01 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY02          (7)                     /* Mutual 4 Key02 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY03          (7)                     /* Mutual 4 Key03 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY04          (7)                     /* Mutual 4 Key04 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY05          (7)                     /* Mutual 4 Key05 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY06          (7)                     /* Mutual 4 Key06 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY07          (7)                     /* Mutual 4 Key07 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY08          (7)                     /* Mutual 4 Key08 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY09          (7)                     /* Mutual 4 Key09 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY10          (7)                     /* Mutual 4 Key10 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY11          (7)                     /* Mutual 4 Key11 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY12          (7)                     /* Mutual 4 Key12 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY13          (7)                     /* Mutual 4 Key13 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY14          (7)                     /* Mutual 4 Key14 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY15          (7)                     /* Mutual 4 Key15 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY16          (7)                     /* Mutual 4 Key16 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY17          (7)                     /* Mutual 4 Key17 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY18          (7)                     /* Mutual 4 Key18 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY19          (7)                     /* Mutual 4 Key19 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY20          (7)                     /* Mutual 4 Key20 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY21          (7)                     /* Mutual 4 Key21 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY22          (7)                     /* Mutual 4 Key22 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY23          (7)                     /* Mutual 4 Key23 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY24          (7)                     /* Mutual 4 Key24 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY25          (7)                     /* Mutual 4 Key25 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY26          (7)                     /* Mutual 4 Key26 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY27          (7)                     /* Mutual 4 Key27 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY28          (7)                     /* Mutual 4 Key28 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY29          (7)                     /* Mutual 4 Key29 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY30          (7)                     /* Mutual 4 Key30 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY31          (7)                     /* Mutual 4 Key31 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY32          (7)                     /* Mutual 4 Key32 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY33          (7)                     /* Mutual 4 Key33 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY34          (7)                     /* Mutual 4 Key34 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY35          (7)                     /* Mutual 4 Key35 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY36          (7)                     /* Mutual 4 Key36 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY37          (7)                     /* Mutual 4 Key37 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY38          (7)                     /* Mutual 4 Key38 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY39          (7)                     /* Mutual 4 Key39 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY40          (7)                     /* Mutual 4 Key40 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY41          (7)                     /* Mutual 4 Key41 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY42          (7)                     /* Mutual 4 Key42 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY43          (7)                     /* Mutual 4 Key43 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY44          (7)                     /* Mutual 4 Key44 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY45          (7)                     /* Mutual 4 Key45 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY46          (7)                     /* Mutual 4 Key46 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY47          (7)                     /* Mutual 4 Key47 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY48          (7)                     /* Mutual 4 Key48 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY49          (7)                     /* Mutual 4 Key49 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY50          (7)                     /* Mutual 4 Key50 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY51          (7)                     /* Mutual 4 Key51 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY52          (7)                     /* Mutual 4 Key52 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY53          (7)                     /* Mutual 4 Key53 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY54          (7)                     /* Mutual 4 Key54 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY55          (7)                     /* Mutual 4 Key55 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY56          (7)                     /* Mutual 4 Key56 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY57          (7)                     /* Mutual 4 Key57 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY58          (7)                     /* Mutual 4 Key58 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY59          (7)                     /* Mutual 4 Key59 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY60          (7)                     /* Mutual 4 Key60 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY61          (7)                     /* Mutual 4 Key61 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY62          (7)                     /* Mutual 4 Key62 CTSUDPA                             */
#define CTSUSDPA_MUTUAL4_KEY63          (7)                     /* Mutual 4 Key63 CTSUDPA                             */

/**********************************************************************************************************************/
/*    CTSU ICO Gain Adjustment                                                                                        */
/*        0 : 100% gain                                                                                               */
/*        1 :  66% gain                                                                                               */
/*        2 :  50% gain                                                                                               */
/*        3 :  40% gain                                                                                               */
/**********************************************************************************************************************/
#define CTSUICOG_MUTUAL4_KEY00          (1)                     /* Mutual 4 Key00 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY01          (1)                     /* Mutual 4 Key01 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY02          (1)                     /* Mutual 4 Key02 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY03          (1)                     /* Mutual 4 Key03 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY04          (1)                     /* Mutual 4 Key04 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY05          (1)                     /* Mutual 4 Key05 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY06          (1)                     /* Mutual 4 Key06 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY07          (1)                     /* Mutual 4 Key07 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY08          (1)                     /* Mutual 4 Key08 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY09          (1)                     /* Mutual 4 Key09 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY10          (1)                     /* Mutual 4 Key10 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY11          (1)                     /* Mutual 4 Key11 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY12          (1)                     /* Mutual 4 Key12 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY13          (1)                     /* Mutual 4 Key13 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY14          (1)                     /* Mutual 4 Key14 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY15          (1)                     /* Mutual 4 Key15 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY16          (1)                     /* Mutual 4 Key16 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY17          (1)                     /* Mutual 4 Key17 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY18          (1)                     /* Mutual 4 Key18 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY19          (1)                     /* Mutual 4 Key19 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY20          (1)                     /* Mutual 4 Key20 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY21          (1)                     /* Mutual 4 Key21 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY22          (1)                     /* Mutual 4 Key22 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY23          (1)                     /* Mutual 4 Key23 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY24          (1)                     /* Mutual 4 Key24 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY25          (1)                     /* Mutual 4 Key25 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY26          (1)                     /* Mutual 4 Key26 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY27          (1)                     /* Mutual 4 Key27 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY28          (1)                     /* Mutual 4 Key28 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY29          (1)                     /* Mutual 4 Key29 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY30          (1)                     /* Mutual 4 Key30 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY31          (1)                     /* Mutual 4 Key31 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY32          (1)                     /* Mutual 4 Key32 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY33          (1)                     /* Mutual 4 Key33 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY34          (1)                     /* Mutual 4 Key34 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY35          (1)                     /* Mutual 4 Key35 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY36          (1)                     /* Mutual 4 Key36 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY37          (1)                     /* Mutual 4 Key37 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY38          (1)                     /* Mutual 4 Key38 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY39          (1)                     /* Mutual 4 Key39 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY40          (1)                     /* Mutual 4 Key40 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY41          (1)                     /* Mutual 4 Key41 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY42          (1)                     /* Mutual 4 Key42 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY43          (1)                     /* Mutual 4 Key43 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY44          (1)                     /* Mutual 4 Key44 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY45          (1)                     /* Mutual 4 Key45 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY46          (1)                     /* Mutual 4 Key46 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY47          (1)                     /* Mutual 4 Key47 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY48          (1)                     /* Mutual 4 Key48 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY49          (1)                     /* Mutual 4 Key49 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY50          (1)                     /* Mutual 4 Key50 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY51          (1)                     /* Mutual 4 Key51 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY52          (1)                     /* Mutual 4 Key52 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY53          (1)                     /* Mutual 4 Key53 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY54          (1)                     /* Mutual 4 Key54 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY55          (1)                     /* Mutual 4 Key55 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY56          (1)                     /* Mutual 4 Key56 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY57          (1)                     /* Mutual 4 Key57 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY58          (1)                     /* Mutual 4 Key58 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY59          (1)                     /* Mutual 4 Key59 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY60          (1)                     /* Mutual 4 Key60 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY61          (1)                     /* Mutual 4 Key61 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY62          (1)                     /* Mutual 4 Key62 CTSICOG                             */
#define CTSUICOG_MUTUAL4_KEY63          (1)                     /* Mutual 4 Key63 CTSICOG                             */

#define CTSUSO1_MUTUAL4_KEY00  ((CTSUICOG_MUTUAL4_KEY00 << 13) | (CTSUSDPA_MUTUAL4_KEY00 << 8) | CTSURICOA_MUTUAL4_KEY00)
#define CTSUSO1_MUTUAL4_KEY01  ((CTSUICOG_MUTUAL4_KEY01 << 13) | (CTSUSDPA_MUTUAL4_KEY01 << 8) | CTSURICOA_MUTUAL4_KEY01)
#define CTSUSO1_MUTUAL4_KEY02  ((CTSUICOG_MUTUAL4_KEY02 << 13) | (CTSUSDPA_MUTUAL4_KEY02 << 8) | CTSURICOA_MUTUAL4_KEY02)
#define CTSUSO1_MUTUAL4_KEY03  ((CTSUICOG_MUTUAL4_KEY03 << 13) | (CTSUSDPA_MUTUAL4_KEY03 << 8) | CTSURICOA_MUTUAL4_KEY03)
#define CTSUSO1_MUTUAL4_KEY04  ((CTSUICOG_MUTUAL4_KEY04 << 13) | (CTSUSDPA_MUTUAL4_KEY04 << 8) | CTSURICOA_MUTUAL4_KEY04)
#define CTSUSO1_MUTUAL4_KEY05  ((CTSUICOG_MUTUAL4_KEY05 << 13) | (CTSUSDPA_MUTUAL4_KEY05 << 8) | CTSURICOA_MUTUAL4_KEY05)
#define CTSUSO1_MUTUAL4_KEY06  ((CTSUICOG_MUTUAL4_KEY06 << 13) | (CTSUSDPA_MUTUAL4_KEY06 << 8) | CTSURICOA_MUTUAL4_KEY06)
#define CTSUSO1_MUTUAL4_KEY07  ((CTSUICOG_MUTUAL4_KEY07 << 13) | (CTSUSDPA_MUTUAL4_KEY07 << 8) | CTSURICOA_MUTUAL4_KEY07)
#define CTSUSO1_MUTUAL4_KEY08  ((CTSUICOG_MUTUAL4_KEY08 << 13) | (CTSUSDPA_MUTUAL4_KEY08 << 8) | CTSURICOA_MUTUAL4_KEY08)
#define CTSUSO1_MUTUAL4_KEY09  ((CTSUICOG_MUTUAL4_KEY09 << 13) | (CTSUSDPA_MUTUAL4_KEY09 << 8) | CTSURICOA_MUTUAL4_KEY09)
#define CTSUSO1_MUTUAL4_KEY10  ((CTSUICOG_MUTUAL4_KEY10 << 13) | (CTSUSDPA_MUTUAL4_KEY10 << 8) | CTSURICOA_MUTUAL4_KEY10)
#define CTSUSO1_MUTUAL4_KEY11  ((CTSUICOG_MUTUAL4_KEY11 << 13) | (CTSUSDPA_MUTUAL4_KEY11 << 8) | CTSURICOA_MUTUAL4_KEY11)
#define CTSUSO1_MUTUAL4_KEY12  ((CTSUICOG_MUTUAL4_KEY12 << 13) | (CTSUSDPA_MUTUAL4_KEY12 << 8) | CTSURICOA_MUTUAL4_KEY12)
#define CTSUSO1_MUTUAL4_KEY13  ((CTSUICOG_MUTUAL4_KEY13 << 13) | (CTSUSDPA_MUTUAL4_KEY13 << 8) | CTSURICOA_MUTUAL4_KEY13)
#define CTSUSO1_MUTUAL4_KEY14  ((CTSUICOG_MUTUAL4_KEY14 << 13) | (CTSUSDPA_MUTUAL4_KEY14 << 8) | CTSURICOA_MUTUAL4_KEY14)
#define CTSUSO1_MUTUAL4_KEY15  ((CTSUICOG_MUTUAL4_KEY15 << 13) | (CTSUSDPA_MUTUAL4_KEY15 << 8) | CTSURICOA_MUTUAL4_KEY15)
#define CTSUSO1_MUTUAL4_KEY16  ((CTSUICOG_MUTUAL4_KEY16 << 13) | (CTSUSDPA_MUTUAL4_KEY16 << 8) | CTSURICOA_MUTUAL4_KEY16)
#define CTSUSO1_MUTUAL4_KEY17  ((CTSUICOG_MUTUAL4_KEY17 << 13) | (CTSUSDPA_MUTUAL4_KEY17 << 8) | CTSURICOA_MUTUAL4_KEY17)
#define CTSUSO1_MUTUAL4_KEY18  ((CTSUICOG_MUTUAL4_KEY18 << 13) | (CTSUSDPA_MUTUAL4_KEY18 << 8) | CTSURICOA_MUTUAL4_KEY18)
#define CTSUSO1_MUTUAL4_KEY19  ((CTSUICOG_MUTUAL4_KEY19 << 13) | (CTSUSDPA_MUTUAL4_KEY19 << 8) | CTSURICOA_MUTUAL4_KEY19)
#define CTSUSO1_MUTUAL4_KEY20  ((CTSUICOG_MUTUAL4_KEY20 << 13) | (CTSUSDPA_MUTUAL4_KEY20 << 8) | CTSURICOA_MUTUAL4_KEY20)
#define CTSUSO1_MUTUAL4_KEY21  ((CTSUICOG_MUTUAL4_KEY21 << 13) | (CTSUSDPA_MUTUAL4_KEY21 << 8) | CTSURICOA_MUTUAL4_KEY21)
#define CTSUSO1_MUTUAL4_KEY22  ((CTSUICOG_MUTUAL4_KEY22 << 13) | (CTSUSDPA_MUTUAL4_KEY22 << 8) | CTSURICOA_MUTUAL4_KEY22)
#define CTSUSO1_MUTUAL4_KEY23  ((CTSUICOG_MUTUAL4_KEY23 << 13) | (CTSUSDPA_MUTUAL4_KEY23 << 8) | CTSURICOA_MUTUAL4_KEY23)
#define CTSUSO1_MUTUAL4_KEY24  ((CTSUICOG_MUTUAL4_KEY24 << 13) | (CTSUSDPA_MUTUAL4_KEY24 << 8) | CTSURICOA_MUTUAL4_KEY24)
#define CTSUSO1_MUTUAL4_KEY25  ((CTSUICOG_MUTUAL4_KEY25 << 13) | (CTSUSDPA_MUTUAL4_KEY25 << 8) | CTSURICOA_MUTUAL4_KEY25)
#define CTSUSO1_MUTUAL4_KEY26  ((CTSUICOG_MUTUAL4_KEY26 << 13) | (CTSUSDPA_MUTUAL4_KEY26 << 8) | CTSURICOA_MUTUAL4_KEY26)
#define CTSUSO1_MUTUAL4_KEY27  ((CTSUICOG_MUTUAL4_KEY27 << 13) | (CTSUSDPA_MUTUAL4_KEY27 << 8) | CTSURICOA_MUTUAL4_KEY27)
#define CTSUSO1_MUTUAL4_KEY28  ((CTSUICOG_MUTUAL4_KEY28 << 13) | (CTSUSDPA_MUTUAL4_KEY28 << 8) | CTSURICOA_MUTUAL4_KEY28)
#define CTSUSO1_MUTUAL4_KEY29  ((CTSUICOG_MUTUAL4_KEY29 << 13) | (CTSUSDPA_MUTUAL4_KEY29 << 8) | CTSURICOA_MUTUAL4_KEY29)
#define CTSUSO1_MUTUAL4_KEY30  ((CTSUICOG_MUTUAL4_KEY30 << 13) | (CTSUSDPA_MUTUAL4_KEY30 << 8) | CTSURICOA_MUTUAL4_KEY30)
#define CTSUSO1_MUTUAL4_KEY31  ((CTSUICOG_MUTUAL4_KEY31 << 13) | (CTSUSDPA_MUTUAL4_KEY31 << 8) | CTSURICOA_MUTUAL4_KEY31)
#define CTSUSO1_MUTUAL4_KEY32  ((CTSUICOG_MUTUAL4_KEY32 << 13) | (CTSUSDPA_MUTUAL4_KEY32 << 8) | CTSURICOA_MUTUAL4_KEY32)
#define CTSUSO1_MUTUAL4_KEY33  ((CTSUICOG_MUTUAL4_KEY33 << 13) | (CTSUSDPA_MUTUAL4_KEY33 << 8) | CTSURICOA_MUTUAL4_KEY33)
#define CTSUSO1_MUTUAL4_KEY34  ((CTSUICOG_MUTUAL4_KEY34 << 13) | (CTSUSDPA_MUTUAL4_KEY34 << 8) | CTSURICOA_MUTUAL4_KEY34)
#define CTSUSO1_MUTUAL4_KEY35  ((CTSUICOG_MUTUAL4_KEY35 << 13) | (CTSUSDPA_MUTUAL4_KEY35 << 8) | CTSURICOA_MUTUAL4_KEY35)
#define CTSUSO1_MUTUAL4_KEY36  ((CTSUICOG_MUTUAL4_KEY36 << 13) | (CTSUSDPA_MUTUAL4_KEY36 << 8) | CTSURICOA_MUTUAL4_KEY36)
#define CTSUSO1_MUTUAL4_KEY37  ((CTSUICOG_MUTUAL4_KEY37 << 13) | (CTSUSDPA_MUTUAL4_KEY37 << 8) | CTSURICOA_MUTUAL4_KEY37)
#define CTSUSO1_MUTUAL4_KEY38  ((CTSUICOG_MUTUAL4_KEY38 << 13) | (CTSUSDPA_MUTUAL4_KEY38 << 8) | CTSURICOA_MUTUAL4_KEY38)
#define CTSUSO1_MUTUAL4_KEY39  ((CTSUICOG_MUTUAL4_KEY39 << 13) | (CTSUSDPA_MUTUAL4_KEY39 << 8) | CTSURICOA_MUTUAL4_KEY39)
#define CTSUSO1_MUTUAL4_KEY40  ((CTSUICOG_MUTUAL4_KEY40 << 13) | (CTSUSDPA_MUTUAL4_KEY40 << 8) | CTSURICOA_MUTUAL4_KEY40)
#define CTSUSO1_MUTUAL4_KEY41  ((CTSUICOG_MUTUAL4_KEY41 << 13) | (CTSUSDPA_MUTUAL4_KEY41 << 8) | CTSURICOA_MUTUAL4_KEY41)
#define CTSUSO1_MUTUAL4_KEY42  ((CTSUICOG_MUTUAL4_KEY42 << 13) | (CTSUSDPA_MUTUAL4_KEY42 << 8) | CTSURICOA_MUTUAL4_KEY42)
#define CTSUSO1_MUTUAL4_KEY43  ((CTSUICOG_MUTUAL4_KEY43 << 13) | (CTSUSDPA_MUTUAL4_KEY43 << 8) | CTSURICOA_MUTUAL4_KEY43)
#define CTSUSO1_MUTUAL4_KEY44  ((CTSUICOG_MUTUAL4_KEY44 << 13) | (CTSUSDPA_MUTUAL4_KEY44 << 8) | CTSURICOA_MUTUAL4_KEY44)
#define CTSUSO1_MUTUAL4_KEY45  ((CTSUICOG_MUTUAL4_KEY45 << 13) | (CTSUSDPA_MUTUAL4_KEY45 << 8) | CTSURICOA_MUTUAL4_KEY45)
#define CTSUSO1_MUTUAL4_KEY46  ((CTSUICOG_MUTUAL4_KEY46 << 13) | (CTSUSDPA_MUTUAL4_KEY46 << 8) | CTSURICOA_MUTUAL4_KEY46)
#define CTSUSO1_MUTUAL4_KEY47  ((CTSUICOG_MUTUAL4_KEY47 << 13) | (CTSUSDPA_MUTUAL4_KEY47 << 8) | CTSURICOA_MUTUAL4_KEY47)
#define CTSUSO1_MUTUAL4_KEY48  ((CTSUICOG_MUTUAL4_KEY48 << 13) | (CTSUSDPA_MUTUAL4_KEY48 << 8) | CTSURICOA_MUTUAL4_KEY48)
#define CTSUSO1_MUTUAL4_KEY49  ((CTSUICOG_MUTUAL4_KEY49 << 13) | (CTSUSDPA_MUTUAL4_KEY49 << 8) | CTSURICOA_MUTUAL4_KEY49)
#define CTSUSO1_MUTUAL4_KEY50  ((CTSUICOG_MUTUAL4_KEY50 << 13) | (CTSUSDPA_MUTUAL4_KEY50 << 8) | CTSURICOA_MUTUAL4_KEY50)
#define CTSUSO1_MUTUAL4_KEY51  ((CTSUICOG_MUTUAL4_KEY51 << 13) | (CTSUSDPA_MUTUAL4_KEY51 << 8) | CTSURICOA_MUTUAL4_KEY51)
#define CTSUSO1_MUTUAL4_KEY52  ((CTSUICOG_MUTUAL4_KEY52 << 13) | (CTSUSDPA_MUTUAL4_KEY52 << 8) | CTSURICOA_MUTUAL4_KEY52)
#define CTSUSO1_MUTUAL4_KEY53  ((CTSUICOG_MUTUAL4_KEY53 << 13) | (CTSUSDPA_MUTUAL4_KEY53 << 8) | CTSURICOA_MUTUAL4_KEY53)
#define CTSUSO1_MUTUAL4_KEY54  ((CTSUICOG_MUTUAL4_KEY54 << 13) | (CTSUSDPA_MUTUAL4_KEY54 << 8) | CTSURICOA_MUTUAL4_KEY54)
#define CTSUSO1_MUTUAL4_KEY55  ((CTSUICOG_MUTUAL4_KEY55 << 13) | (CTSUSDPA_MUTUAL4_KEY55 << 8) | CTSURICOA_MUTUAL4_KEY55)
#define CTSUSO1_MUTUAL4_KEY56  ((CTSUICOG_MUTUAL4_KEY56 << 13) | (CTSUSDPA_MUTUAL4_KEY56 << 8) | CTSURICOA_MUTUAL4_KEY56)
#define CTSUSO1_MUTUAL4_KEY57  ((CTSUICOG_MUTUAL4_KEY57 << 13) | (CTSUSDPA_MUTUAL4_KEY57 << 8) | CTSURICOA_MUTUAL4_KEY57)
#define CTSUSO1_MUTUAL4_KEY58  ((CTSUICOG_MUTUAL4_KEY58 << 13) | (CTSUSDPA_MUTUAL4_KEY58 << 8) | CTSURICOA_MUTUAL4_KEY58)
#define CTSUSO1_MUTUAL4_KEY59  ((CTSUICOG_MUTUAL4_KEY59 << 13) | (CTSUSDPA_MUTUAL4_KEY59 << 8) | CTSURICOA_MUTUAL4_KEY59)
#define CTSUSO1_MUTUAL4_KEY60  ((CTSUICOG_MUTUAL4_KEY60 << 13) | (CTSUSDPA_MUTUAL4_KEY60 << 8) | CTSURICOA_MUTUAL4_KEY60)
#define CTSUSO1_MUTUAL4_KEY61  ((CTSUICOG_MUTUAL4_KEY61 << 13) | (CTSUSDPA_MUTUAL4_KEY61 << 8) | CTSURICOA_MUTUAL4_KEY61)
#define CTSUSO1_MUTUAL4_KEY62  ((CTSUICOG_MUTUAL4_KEY62 << 13) | (CTSUSDPA_MUTUAL4_KEY62 << 8) | CTSURICOA_MUTUAL4_KEY62)
#define CTSUSO1_MUTUAL4_KEY63  ((CTSUICOG_MUTUAL4_KEY63 << 13) | (CTSUSDPA_MUTUAL4_KEY63 << 8) | CTSURICOA_MUTUAL4_KEY63)
#endif    // ( MUTUAL_METHOD_NUM >= 5 )

#if ( MUTUAL_METHOD_NUM >= 6 )
/*====================================================================================================================*/
/*=====     Mutual-measurement 5 TS enable definition    =============================================================*/
/*====================================================================================================================*/
#define MUTUAL5_ENABLE_TS00              (0)        /* Mutual 1 TS00 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS01              (0)        /* Mutual 1 TS01 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS02              (0)        /* Mutual 1 TS02 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS03              (0)        /* Mutual 1 TS03 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS04              (0)        /* Mutual 1 TS04 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS05              (0)        /* Mutual 1 TS05 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS06              (0)        /* Mutual 1 TS06 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS07              (0)        /* Mutual 1 TS07 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS08              (0)        /* Mutual 1 TS08 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS09              (0)        /* Mutual 1 TS09 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS10              (0)        /* Mutual 1 TS10 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS11              (0)        /* Mutual 1 TS11 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS12              (0)        /* Mutual 1 TS12 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS13              (0)        /* Mutual 1 TS13 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS14              (0)        /* Mutual 1 TS14 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS15              (0)        /* Mutual 1 TS15 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS16              (0)        /* Mutual 1 TS16 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS17              (0)        /* Mutual 1 TS17 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS18              (0)        /* Mutual 1 TS18 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS19              (0)        /* Mutual 1 TS19 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS20              (0)        /* Mutual 1 TS20 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS21              (0)        /* Mutual 1 TS21 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS22              (0)        /* Mutual 1 TS22 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS23              (0)        /* Mutual 1 TS23 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS24              (0)        /* Mutual 1 TS24 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS25              (0)        /* Mutual 1 TS25 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS26              (0)        /* Mutual 1 TS26 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS27              (0)        /* Mutual 1 TS27 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS28              (0)        /* Mutual 1 TS28 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS29              (0)        /* Mutual 1 TS29 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS30              (0)        /* Mutual 1 TS30 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS31              (0)        /* Mutual 1 TS31 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS32              (0)        /* Mutual 1 TS32 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS33              (0)        /* Mutual 1 TS33 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS34              (0)        /* Mutual 1 TS34 0:disable 1:enable                               */
#define MUTUAL5_ENABLE_TS35              (0)        /* Mutual 1 TS35 0:disable 1:enable                               */

/*****    Address 000A 0906h CTSU Channel enable control register 0    ************************************************/
#define CTSUCHAC0_MUTUAL5_ENABLE_TS      ((MUTUAL5_ENABLE_TS00 << 0) | (MUTUAL5_ENABLE_TS01 << 1) | \
                                          (MUTUAL5_ENABLE_TS02 << 2) | (MUTUAL5_ENABLE_TS03 << 3) | \
                                          (MUTUAL5_ENABLE_TS04 << 4) | (MUTUAL5_ENABLE_TS05 << 5) | \
                                          (MUTUAL5_ENABLE_TS06 << 6) | (MUTUAL5_ENABLE_TS07 << 7))

/*****    Address 000A 0907h CTSU Channel enable control register 1    ************************************************/
#define CTSUCHAC1_MUTUAL5_ENABLE_TS      ((MUTUAL5_ENABLE_TS08 << 0) | (MUTUAL5_ENABLE_TS09 << 1) | \
                                          (MUTUAL5_ENABLE_TS10 << 2) | (MUTUAL5_ENABLE_TS11 << 3) | \
                                          (MUTUAL5_ENABLE_TS12 << 4) | (MUTUAL5_ENABLE_TS13 << 5) | \
                                          (MUTUAL5_ENABLE_TS14 << 6) | (MUTUAL5_ENABLE_TS15 << 7))

/*****    Address 000A 0908h CTSU Channel enable control register 2    ************************************************/
#define CTSUCHAC2_MUTUAL5_ENABLE_TS      ((MUTUAL5_ENABLE_TS16 << 0) | (MUTUAL5_ENABLE_TS17 << 1) | \
                                          (MUTUAL5_ENABLE_TS18 << 2) | (MUTUAL5_ENABLE_TS19 << 3) | \
                                          (MUTUAL5_ENABLE_TS20 << 4) | (MUTUAL5_ENABLE_TS21 << 5) | \
                                          (MUTUAL5_ENABLE_TS22 << 6) | (MUTUAL5_ENABLE_TS23 << 7))

/*****    Address 000A 0909h CTSU Channel enable control register 3    ************************************************/
#define CTSUCHAC3_MUTUAL5_ENABLE_TS      ((MUTUAL5_ENABLE_TS24 << 0) | (MUTUAL5_ENABLE_TS25 << 1) | \
                                          (MUTUAL5_ENABLE_TS26 << 2) | (MUTUAL5_ENABLE_TS27 << 3) | \
                                          (MUTUAL5_ENABLE_TS28 << 4) | (MUTUAL5_ENABLE_TS29 << 5) | \
                                          (MUTUAL5_ENABLE_TS30 << 6) | (MUTUAL5_ENABLE_TS31 << 7))

/*****    Address 000A 090ah CTSU Channel enable control register 4    ************************************************/
#define CTSUCHAC4_MUTUAL5_ENABLE_TS      ((MUTUAL5_ENABLE_TS32 << 0) | (MUTUAL5_ENABLE_TS33 << 1) | \
                                          (MUTUAL5_ENABLE_TS34 << 2) | (MUTUAL5_ENABLE_TS35 << 3))

/* SUM of Channels */ /* Do not edit this macro definition */
#define MUTUAL5_ENABLE_NUM               (MUTUAL5_ENABLE_TS00 + MUTUAL5_ENABLE_TS01 + MUTUAL5_ENABLE_TS02 + \
                                          MUTUAL5_ENABLE_TS03 + MUTUAL5_ENABLE_TS04 + MUTUAL5_ENABLE_TS05 + \
                                          MUTUAL5_ENABLE_TS06 + MUTUAL5_ENABLE_TS07 + MUTUAL5_ENABLE_TS08 + \
                                          MUTUAL5_ENABLE_TS09 + MUTUAL5_ENABLE_TS10 + MUTUAL5_ENABLE_TS11 + \
                                          MUTUAL5_ENABLE_TS12 + MUTUAL5_ENABLE_TS13 + MUTUAL5_ENABLE_TS14 + \
                                          MUTUAL5_ENABLE_TS15 + MUTUAL5_ENABLE_TS16 + MUTUAL5_ENABLE_TS17 + \
                                          MUTUAL5_ENABLE_TS18 + MUTUAL5_ENABLE_TS19 + MUTUAL5_ENABLE_TS20 + \
                                          MUTUAL5_ENABLE_TS21 + MUTUAL5_ENABLE_TS22 + MUTUAL5_ENABLE_TS23 + \
                                          MUTUAL5_ENABLE_TS24 + MUTUAL5_ENABLE_TS25 + MUTUAL5_ENABLE_TS26 + \
                                          MUTUAL5_ENABLE_TS27 + MUTUAL5_ENABLE_TS28 + MUTUAL5_ENABLE_TS29 + \
                                          MUTUAL5_ENABLE_TS30 + MUTUAL5_ENABLE_TS31 + MUTUAL5_ENABLE_TS32 + \
                                          MUTUAL5_ENABLE_TS33 + MUTUAL5_ENABLE_TS34 + MUTUAL5_ENABLE_TS35)

/*====================================================================================================================*/
/*=====     Mutual-measurement 5 function definition     =============================================================*/
/*====================================================================================================================*/
#define MUTUAL5_FUNCTION_TS00            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS01            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS02            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS03            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS04            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS05            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS06            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS07            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS08            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS09            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS10            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS11            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS12            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS13            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS14            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS15            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS16            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS17            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS18            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS19            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS20            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS21            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS22            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS23            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS24            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS25            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS26            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS27            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS28            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS29            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS30            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS31            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS32            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS33            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS34            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL5_FUNCTION_TS35            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */

/*****    Address 000A 090Bh CTSU Channel send and receive control register 0 *****************************************/
#define CTSUCHTRC0_MUTUAL5_TRANSMIT_TS   ((MUTUAL5_FUNCTION_TS00 << 0) | (MUTUAL5_FUNCTION_TS01 << 1) | \
                                          (MUTUAL5_FUNCTION_TS02 << 2) | (MUTUAL5_FUNCTION_TS03 << 3) | \
                                          (MUTUAL5_FUNCTION_TS04 << 4) | (MUTUAL5_FUNCTION_TS05 << 5) | \
                                          (MUTUAL5_FUNCTION_TS06 << 6) | (MUTUAL5_FUNCTION_TS07 << 7))

/*****    Address 000A 090Ch CTSU Channel send and receive control register 1 *****************************************/
#define CTSUCHTRC1_MUTUAL5_TRANSMIT_TS   ((MUTUAL5_FUNCTION_TS08 << 0) | (MUTUAL5_FUNCTION_TS09 << 1) | \
                                          (MUTUAL5_FUNCTION_TS10 << 2) | (MUTUAL5_FUNCTION_TS11 << 3) | \
                                          (MUTUAL5_FUNCTION_TS12 << 4) | (MUTUAL5_FUNCTION_TS13 << 5) | \
                                          (MUTUAL5_FUNCTION_TS14 << 6) | (MUTUAL5_FUNCTION_TS15 << 7))

/*****    Address 000A 090Dh CTSU Channel send and receive control register 2 *****************************************/
#define CTSUCHTRC2_MUTUAL5_TRANSMIT_TS   ((MUTUAL5_FUNCTION_TS16 << 0) | (MUTUAL5_FUNCTION_TS17 << 1) | \
                                          (MUTUAL5_FUNCTION_TS18 << 2) | (MUTUAL5_FUNCTION_TS19 << 3) | \
                                          (MUTUAL5_FUNCTION_TS20 << 4) | (MUTUAL5_FUNCTION_TS21 << 5) | \
                                          (MUTUAL5_FUNCTION_TS22 << 6) | (MUTUAL5_FUNCTION_TS23 << 7))

/*****    Address 000A 090Eh CTSU Channel send and receive control register 3 *****************************************/
#define CTSUCHTRC3_MUTUAL5_TRANSMIT_TS   ((MUTUAL5_FUNCTION_TS24 << 0) | (MUTUAL5_FUNCTION_TS25 << 1) | \
                                          (MUTUAL5_FUNCTION_TS26 << 2) | (MUTUAL5_FUNCTION_TS27 << 3) | \
                                          (MUTUAL5_FUNCTION_TS28 << 4) | (MUTUAL5_FUNCTION_TS29 << 5) | \
                                          (MUTUAL5_FUNCTION_TS30 << 6) | (MUTUAL5_FUNCTION_TS31 << 7))

/*****    Address 000A 090Fh CTSU Channel send and receive control register 4 *****************************************/
#define CTSUCHTRC4_MUTUAL5_TRANSMIT_TS   ((MUTUAL5_FUNCTION_TS32 << 0) | (MUTUAL5_FUNCTION_TS33 << 1) | \
                                          (MUTUAL5_FUNCTION_TS34 << 2) | (MUTUAL5_FUNCTION_TS35 << 3))

#define TRANSMISSION5_NUM                  (MUTUAL5_FUNCTION_TS00 + MUTUAL5_FUNCTION_TS01 + MUTUAL5_FUNCTION_TS02 + \
                                            MUTUAL5_FUNCTION_TS03 + MUTUAL5_FUNCTION_TS04 + MUTUAL5_FUNCTION_TS05 + \
                                            MUTUAL5_FUNCTION_TS06 + MUTUAL5_FUNCTION_TS07 + MUTUAL5_FUNCTION_TS08 + \
                                            MUTUAL5_FUNCTION_TS09 + MUTUAL5_FUNCTION_TS10 + MUTUAL5_FUNCTION_TS11 + \
                                            MUTUAL5_FUNCTION_TS12 + MUTUAL5_FUNCTION_TS13 + MUTUAL5_FUNCTION_TS14 + \
                                            MUTUAL5_FUNCTION_TS15 + MUTUAL5_FUNCTION_TS16 + MUTUAL5_FUNCTION_TS17 + \
                                            MUTUAL5_FUNCTION_TS18 + MUTUAL5_FUNCTION_TS19 + MUTUAL5_FUNCTION_TS20 + \
                                            MUTUAL5_FUNCTION_TS21 + MUTUAL5_FUNCTION_TS22 + MUTUAL5_FUNCTION_TS23 + \
                                            MUTUAL5_FUNCTION_TS24 + MUTUAL5_FUNCTION_TS25 + MUTUAL5_FUNCTION_TS26 + \
                                            MUTUAL5_FUNCTION_TS27 + MUTUAL5_FUNCTION_TS28 + MUTUAL5_FUNCTION_TS29 + \
                                            MUTUAL5_FUNCTION_TS30 + MUTUAL5_FUNCTION_TS31 + MUTUAL5_FUNCTION_TS32 + \
                                            MUTUAL5_FUNCTION_TS33 + MUTUAL5_FUNCTION_TS34 + MUTUAL5_FUNCTION_TS35)

#define RECEPTION5_NUM                     (MUTUAL5_ENABLE_NUM - TRANSMISSION5_NUM)
#define MUTUAL5_NUM                        (TRANSMISSION5_NUM * RECEPTION5_NUM)

#if TRANSMISSION5_NUM == 0
    #error "Send TS Setting error ( TRANSMISSION5_NUM = 0 )"
#endif
#if RECEPTION5_NUM == 0
    #error "Receive TS Setting error ( RECEPTION_NUM5 = 0 )"
#endif

/*****    Address 000A 0912h CTSU High-Pass Noise Reduction Spectrum Diffusion Control Register    ********************/
/**********************************************************************************************************************/
/*    CTSU Spectrum Diffusion Frequency Division Setting                                                              */
/*    Base Clock Frequency fb (MHz)   CTSUSSDIV[3:0] Bit Setting                                                      */
/*          4.00 =< fb                           0x00                                                                 */
/*          2.00 =< fb  < 4.00                   0x01                                                                 */
/*          1.33 =< fb  < 2.00                   0x02                                                                 */
/*          1.00 =< fb  < 1.33                   0x03                                                                 */
/*          0.80 =< fb  < 1.00                   0x04                                                                 */
/*          0.67 =< fb  < 0.80                   0x05                                                                 */
/*          0.57 =< fb  < 0.67                   0x06                                                                 */
/*          0.50 =< fb  < 0.57                   0x07                                                                 */
/*          0.44 =< fb  < 0.50                   0x08                                                                 */
/*          0.40 =< fb  < 0.44                   0x09                                                                 */
/*          0.36 =< fb  < 0.40                   0x0A                                                                 */
/*          0.33 =< fb  < 0.36                   0x0B                                                                 */
/*          0.31 =< fb  < 0.33                   0x0C                                                                 */
/*          0.29 =< fb  < 0.31                   0x0D                                                                 */
/*          0.27 =< fb  < 0.29                   0x0E                                                                 */
/*                  fb =< 0.25                   0x0F                                                                 */
/**********************************************************************************************************************/
#define CTSUSSDIV_MUTUAL5_KEY00         (0x01)                  /* Mutual 1 Key00 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY01         (0x01)                  /* Mutual 1 Key01 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY02         (0x01)                  /* Mutual 1 Key02 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY03         (0x01)                  /* Mutual 1 Key03 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY04         (0x01)                  /* Mutual 1 Key04 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY05         (0x01)                  /* Mutual 1 Key05 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY06         (0x01)                  /* Mutual 1 Key06 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY07         (0x01)                  /* Mutual 1 Key07 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY08         (0x01)                  /* Mutual 1 Key08 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY09         (0x01)                  /* Mutual 1 Key09 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY10         (0x01)                  /* Mutual 1 Key10 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY11         (0x01)                  /* Mutual 1 Key11 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY12         (0x01)                  /* Mutual 1 Key12 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY13         (0x01)                  /* Mutual 1 Key13 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY14         (0x01)                  /* Mutual 1 Key14 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY15         (0x01)                  /* Mutual 1 Key15 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY16         (0x01)                  /* Mutual 1 Key16 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY17         (0x01)                  /* Mutual 1 Key17 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY18         (0x01)                  /* Mutual 1 Key18 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY19         (0x01)                  /* Mutual 1 Key19 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY20         (0x01)                  /* Mutual 1 Key20 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY21         (0x01)                  /* Mutual 1 Key21 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY22         (0x01)                  /* Mutual 1 Key22 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY23         (0x01)                  /* Mutual 1 Key23 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY24         (0x01)                  /* Mutual 1 Key24 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY25         (0x01)                  /* Mutual 1 Key25 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY26         (0x01)                  /* Mutual 1 Key26 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY27         (0x01)                  /* Mutual 1 Key27 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY28         (0x01)                  /* Mutual 1 Key28 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY29         (0x01)                  /* Mutual 1 Key29 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY30         (0x01)                  /* Mutual 1 Key30 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY31         (0x01)                  /* Mutual 1 Key31 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY32         (0x01)                  /* Mutual 1 Key32 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY33         (0x01)                  /* Mutual 1 Key33 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY34         (0x01)                  /* Mutual 1 Key34 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY35         (0x01)                  /* Mutual 1 Key35 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY36         (0x01)                  /* Mutual 1 Key36 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY37         (0x01)                  /* Mutual 1 Key37 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY38         (0x01)                  /* Mutual 1 Key38 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY39         (0x01)                  /* Mutual 1 Key39 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY40         (0x01)                  /* Mutual 1 Key40 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY41         (0x01)                  /* Mutual 1 Key41 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY42         (0x01)                  /* Mutual 1 Key42 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY43         (0x01)                  /* Mutual 1 Key43 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY44         (0x01)                  /* Mutual 1 Key44 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY45         (0x01)                  /* Mutual 1 Key45 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY46         (0x01)                  /* Mutual 1 Key46 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY47         (0x01)                  /* Mutual 1 Key47 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY48         (0x01)                  /* Mutual 1 Key48 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY49         (0x01)                  /* Mutual 1 Key49 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY50         (0x01)                  /* Mutual 1 Key50 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY51         (0x01)                  /* Mutual 1 Key51 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY52         (0x01)                  /* Mutual 1 Key52 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY53         (0x01)                  /* Mutual 1 Key53 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY54         (0x01)                  /* Mutual 1 Key54 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY55         (0x01)                  /* Mutual 1 Key55 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY56         (0x01)                  /* Mutual 1 Key56 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY57         (0x01)                  /* Mutual 1 Key57 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY58         (0x01)                  /* Mutual 1 Key58 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY59         (0x01)                  /* Mutual 1 Key59 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY60         (0x01)                  /* Mutual 1 Key60 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY61         (0x01)                  /* Mutual 1 Key61 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY62         (0x01)                  /* Mutual 1 Key62 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL5_KEY63         (0x01)                  /* Mutual 1 Key63 CTSUSDIV                            */

#define CTSUSSC_MUTUAL5_KEY00           (CTSUSSDIV_MUTUAL5_KEY00 << 8)
#define CTSUSSC_MUTUAL5_KEY01           (CTSUSSDIV_MUTUAL5_KEY01 << 8)
#define CTSUSSC_MUTUAL5_KEY02           (CTSUSSDIV_MUTUAL5_KEY02 << 8)
#define CTSUSSC_MUTUAL5_KEY03           (CTSUSSDIV_MUTUAL5_KEY03 << 8)
#define CTSUSSC_MUTUAL5_KEY04           (CTSUSSDIV_MUTUAL5_KEY04 << 8)
#define CTSUSSC_MUTUAL5_KEY05           (CTSUSSDIV_MUTUAL5_KEY05 << 8)
#define CTSUSSC_MUTUAL5_KEY06           (CTSUSSDIV_MUTUAL5_KEY06 << 8)
#define CTSUSSC_MUTUAL5_KEY07           (CTSUSSDIV_MUTUAL5_KEY07 << 8)
#define CTSUSSC_MUTUAL5_KEY08           (CTSUSSDIV_MUTUAL5_KEY08 << 8)
#define CTSUSSC_MUTUAL5_KEY09           (CTSUSSDIV_MUTUAL5_KEY09 << 8)
#define CTSUSSC_MUTUAL5_KEY10           (CTSUSSDIV_MUTUAL5_KEY10 << 8)
#define CTSUSSC_MUTUAL5_KEY11           (CTSUSSDIV_MUTUAL5_KEY11 << 8)
#define CTSUSSC_MUTUAL5_KEY12           (CTSUSSDIV_MUTUAL5_KEY12 << 8)
#define CTSUSSC_MUTUAL5_KEY13           (CTSUSSDIV_MUTUAL5_KEY13 << 8)
#define CTSUSSC_MUTUAL5_KEY14           (CTSUSSDIV_MUTUAL5_KEY14 << 8)
#define CTSUSSC_MUTUAL5_KEY15           (CTSUSSDIV_MUTUAL5_KEY15 << 8)
#define CTSUSSC_MUTUAL5_KEY16           (CTSUSSDIV_MUTUAL5_KEY16 << 8)
#define CTSUSSC_MUTUAL5_KEY17           (CTSUSSDIV_MUTUAL5_KEY17 << 8)
#define CTSUSSC_MUTUAL5_KEY18           (CTSUSSDIV_MUTUAL5_KEY18 << 8)
#define CTSUSSC_MUTUAL5_KEY19           (CTSUSSDIV_MUTUAL5_KEY19 << 8)
#define CTSUSSC_MUTUAL5_KEY20           (CTSUSSDIV_MUTUAL5_KEY20 << 8)
#define CTSUSSC_MUTUAL5_KEY21           (CTSUSSDIV_MUTUAL5_KEY21 << 8)
#define CTSUSSC_MUTUAL5_KEY22           (CTSUSSDIV_MUTUAL5_KEY22 << 8)
#define CTSUSSC_MUTUAL5_KEY23           (CTSUSSDIV_MUTUAL5_KEY23 << 8)
#define CTSUSSC_MUTUAL5_KEY24           (CTSUSSDIV_MUTUAL5_KEY24 << 8)
#define CTSUSSC_MUTUAL5_KEY25           (CTSUSSDIV_MUTUAL5_KEY25 << 8)
#define CTSUSSC_MUTUAL5_KEY26           (CTSUSSDIV_MUTUAL5_KEY26 << 8)
#define CTSUSSC_MUTUAL5_KEY27           (CTSUSSDIV_MUTUAL5_KEY27 << 8)
#define CTSUSSC_MUTUAL5_KEY28           (CTSUSSDIV_MUTUAL5_KEY28 << 8)
#define CTSUSSC_MUTUAL5_KEY29           (CTSUSSDIV_MUTUAL5_KEY29 << 8)
#define CTSUSSC_MUTUAL5_KEY30           (CTSUSSDIV_MUTUAL5_KEY30 << 8)
#define CTSUSSC_MUTUAL5_KEY31           (CTSUSSDIV_MUTUAL5_KEY31 << 8)
#define CTSUSSC_MUTUAL5_KEY32           (CTSUSSDIV_MUTUAL5_KEY32 << 8)
#define CTSUSSC_MUTUAL5_KEY33           (CTSUSSDIV_MUTUAL5_KEY33 << 8)
#define CTSUSSC_MUTUAL5_KEY34           (CTSUSSDIV_MUTUAL5_KEY34 << 8)
#define CTSUSSC_MUTUAL5_KEY35           (CTSUSSDIV_MUTUAL5_KEY35 << 8)
#define CTSUSSC_MUTUAL5_KEY36           (CTSUSSDIV_MUTUAL5_KEY36 << 8)
#define CTSUSSC_MUTUAL5_KEY37           (CTSUSSDIV_MUTUAL5_KEY37 << 8)
#define CTSUSSC_MUTUAL5_KEY38           (CTSUSSDIV_MUTUAL5_KEY38 << 8)
#define CTSUSSC_MUTUAL5_KEY39           (CTSUSSDIV_MUTUAL5_KEY39 << 8)
#define CTSUSSC_MUTUAL5_KEY40           (CTSUSSDIV_MUTUAL5_KEY40 << 8)
#define CTSUSSC_MUTUAL5_KEY41           (CTSUSSDIV_MUTUAL5_KEY41 << 8)
#define CTSUSSC_MUTUAL5_KEY42           (CTSUSSDIV_MUTUAL5_KEY42 << 8)
#define CTSUSSC_MUTUAL5_KEY43           (CTSUSSDIV_MUTUAL5_KEY43 << 8)
#define CTSUSSC_MUTUAL5_KEY44           (CTSUSSDIV_MUTUAL5_KEY44 << 8)
#define CTSUSSC_MUTUAL5_KEY45           (CTSUSSDIV_MUTUAL5_KEY45 << 8)
#define CTSUSSC_MUTUAL5_KEY46           (CTSUSSDIV_MUTUAL5_KEY46 << 8)
#define CTSUSSC_MUTUAL5_KEY47           (CTSUSSDIV_MUTUAL5_KEY47 << 8)
#define CTSUSSC_MUTUAL5_KEY48           (CTSUSSDIV_MUTUAL5_KEY48 << 8)
#define CTSUSSC_MUTUAL5_KEY49           (CTSUSSDIV_MUTUAL5_KEY49 << 8)
#define CTSUSSC_MUTUAL5_KEY50           (CTSUSSDIV_MUTUAL5_KEY50 << 8)
#define CTSUSSC_MUTUAL5_KEY51           (CTSUSSDIV_MUTUAL5_KEY51 << 8)
#define CTSUSSC_MUTUAL5_KEY52           (CTSUSSDIV_MUTUAL5_KEY52 << 8)
#define CTSUSSC_MUTUAL5_KEY53           (CTSUSSDIV_MUTUAL5_KEY53 << 8)
#define CTSUSSC_MUTUAL5_KEY54           (CTSUSSDIV_MUTUAL5_KEY54 << 8)
#define CTSUSSC_MUTUAL5_KEY55           (CTSUSSDIV_MUTUAL5_KEY55 << 8)
#define CTSUSSC_MUTUAL5_KEY56           (CTSUSSDIV_MUTUAL5_KEY56 << 8)
#define CTSUSSC_MUTUAL5_KEY57           (CTSUSSDIV_MUTUAL5_KEY57 << 8)
#define CTSUSSC_MUTUAL5_KEY58           (CTSUSSDIV_MUTUAL5_KEY58 << 8)
#define CTSUSSC_MUTUAL5_KEY59           (CTSUSSDIV_MUTUAL5_KEY59 << 8)
#define CTSUSSC_MUTUAL5_KEY60           (CTSUSSDIV_MUTUAL5_KEY60 << 8)
#define CTSUSSC_MUTUAL5_KEY61           (CTSUSSDIV_MUTUAL5_KEY61 << 8)
#define CTSUSSC_MUTUAL5_KEY62           (CTSUSSDIV_MUTUAL5_KEY62 << 8)
#define CTSUSSC_MUTUAL5_KEY63           (CTSUSSDIV_MUTUAL5_KEY63 << 8)

/*****    Address 000A 0914h CTSU Sensor Offset Register 0     ********************************************************/
/**********************************************************************************************************************/
/*    CTSU Sensor Offset Adjustment                                                                                   */
/*      Current offset amount is 0       0x000                                                                        */
/*      Current offset amount is 1       0x001                                                                        */
/*      Current offset amount is 2       0x002                                                                        */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*      Current offset amount is 1023    0x3FF                                                                        */
/**********************************************************************************************************************/
#define CTSUSO_MUTUAL5_KEY00            (0x000)                 /* Mutual 1 Key00 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY01            (0x000)                 /* Mutual 1 Key01 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY02            (0x000)                 /* Mutual 1 Key02 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY03            (0x000)                 /* Mutual 1 Key03 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY04            (0x000)                 /* Mutual 1 Key04 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY05            (0x000)                 /* Mutual 1 Key05 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY06            (0x000)                 /* Mutual 1 Key06 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY07            (0x000)                 /* Mutual 1 Key07 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY08            (0x000)                 /* Mutual 1 Key08 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY09            (0x000)                 /* Mutual 1 Key09 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY10            (0x000)                 /* Mutual 1 Key10 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY11            (0x000)                 /* Mutual 1 Key11 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY12            (0x000)                 /* Mutual 1 Key12 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY13            (0x000)                 /* Mutual 1 Key13 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY14            (0x000)                 /* Mutual 1 Key14 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY15            (0x000)                 /* Mutual 1 Key15 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY16            (0x000)                 /* Mutual 1 Key16 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY17            (0x000)                 /* Mutual 1 Key17 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY18            (0x000)                 /* Mutual 1 Key18 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY19            (0x000)                 /* Mutual 1 Key19 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY20            (0x000)                 /* Mutual 1 Key20 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY21            (0x000)                 /* Mutual 1 Key21 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY22            (0x000)                 /* Mutual 1 Key22 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY23            (0x000)                 /* Mutual 1 Key23 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY24            (0x000)                 /* Mutual 1 Key24 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY25            (0x000)                 /* Mutual 1 Key25 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY26            (0x000)                 /* Mutual 1 Key26 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY27            (0x000)                 /* Mutual 1 Key27 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY28            (0x000)                 /* Mutual 1 Key28 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY29            (0x000)                 /* Mutual 1 Key29 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY30            (0x000)                 /* Mutual 1 Key30 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY31            (0x000)                 /* Mutual 1 Key31 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY32            (0x000)                 /* Mutual 1 Key32 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY33            (0x000)                 /* Mutual 1 Key33 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY34            (0x000)                 /* Mutual 1 Key34 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY35            (0x000)                 /* Mutual 1 Key35 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY36            (0x000)                 /* Mutual 1 Key36 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY37            (0x000)                 /* Mutual 1 Key37 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY38            (0x000)                 /* Mutual 1 Key38 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY39            (0x000)                 /* Mutual 1 Key39 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY40            (0x000)                 /* Mutual 1 Key40 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY41            (0x000)                 /* Mutual 1 Key41 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY42            (0x000)                 /* Mutual 1 Key42 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY43            (0x000)                 /* Mutual 1 Key43 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY44            (0x000)                 /* Mutual 1 Key44 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY45            (0x000)                 /* Mutual 1 Key45 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY46            (0x000)                 /* Mutual 1 Key46 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY47            (0x000)                 /* Mutual 1 Key47 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY48            (0x000)                 /* Mutual 1 Key48 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY49            (0x000)                 /* Mutual 1 Key49 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY50            (0x000)                 /* Mutual 1 Key50 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY51            (0x000)                 /* Mutual 1 Key51 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY52            (0x000)                 /* Mutual 1 Key52 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY53            (0x000)                 /* Mutual 1 Key53 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY54            (0x000)                 /* Mutual 1 Key54 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY55            (0x000)                 /* Mutual 1 Key55 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY56            (0x000)                 /* Mutual 1 Key56 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY57            (0x000)                 /* Mutual 1 Key57 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY58            (0x000)                 /* Mutual 1 Key58 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY59            (0x000)                 /* Mutual 1 Key59 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY60            (0x000)                 /* Mutual 1 Key60 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY61            (0x000)                 /* Mutual 1 Key61 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY62            (0x000)                 /* Mutual 1 Key62 CTSUSO                              */
#define CTSUSO_MUTUAL5_KEY63            (0x000)                 /* Mutual 1 Key63 CTSUSO                              */

/**********************************************************************************************************************/
/*    CTSU Measurement Count Setting                                                                                  */
/*      4.0MHz    7                                                                                                   */
/*      2.0MHz    3                                                                                                   */
/*      1.0MHz    1                                                                                                   */
/*      0.5MHz    0                                                                                                   */
/**********************************************************************************************************************/
#define CTSUSNUM_MUTUAL5_KEY00          (3)                     /* Mutual 1 Key00 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY01          (3)                     /* Mutual 1 Key01 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY02          (3)                     /* Mutual 1 Key02 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY03          (3)                     /* Mutual 1 Key03 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY04          (3)                     /* Mutual 1 Key04 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY05          (3)                     /* Mutual 1 Key05 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY06          (3)                     /* Mutual 1 Key06 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY07          (3)                     /* Mutual 1 Key07 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY08          (3)                     /* Mutual 1 Key08 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY09          (3)                     /* Mutual 1 Key09 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY10          (3)                     /* Mutual 1 Key10 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY11          (3)                     /* Mutual 1 Key11 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY12          (3)                     /* Mutual 1 Key12 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY13          (3)                     /* Mutual 1 Key13 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY14          (3)                     /* Mutual 1 Key14 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY15          (3)                     /* Mutual 1 Key15 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY16          (3)                     /* Mutual 1 Key16 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY17          (3)                     /* Mutual 1 Key17 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY18          (3)                     /* Mutual 1 Key18 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY19          (3)                     /* Mutual 1 Key19 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY20          (3)                     /* Mutual 1 Key20 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY21          (3)                     /* Mutual 1 Key21 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY22          (3)                     /* Mutual 1 Key22 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY23          (3)                     /* Mutual 1 Key23 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY24          (3)                     /* Mutual 1 Key24 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY25          (3)                     /* Mutual 1 Key25 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY26          (3)                     /* Mutual 1 Key26 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY27          (3)                     /* Mutual 1 Key27 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY28          (3)                     /* Mutual 1 Key28 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY29          (3)                     /* Mutual 1 Key29 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY30          (3)                     /* Mutual 1 Key30 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY31          (3)                     /* Mutual 1 Key31 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY32          (3)                     /* Mutual 1 Key32 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY33          (3)                     /* Mutual 1 Key33 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY34          (3)                     /* Mutual 1 Key34 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY35          (3)                     /* Mutual 1 Key35 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY36          (3)                     /* Mutual 1 Key36 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY37          (3)                     /* Mutual 1 Key37 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY38          (3)                     /* Mutual 1 Key38 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY39          (3)                     /* Mutual 1 Key39 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY40          (3)                     /* Mutual 1 Key40 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY41          (3)                     /* Mutual 1 Key41 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY42          (3)                     /* Mutual 1 Key42 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY43          (3)                     /* Mutual 1 Key43 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY44          (3)                     /* Mutual 1 Key44 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY45          (3)                     /* Mutual 1 Key45 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY46          (3)                     /* Mutual 1 Key46 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY47          (3)                     /* Mutual 1 Key47 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY48          (3)                     /* Mutual 1 Key48 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY49          (3)                     /* Mutual 1 Key49 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY50          (3)                     /* Mutual 1 Key50 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY51          (3)                     /* Mutual 1 Key51 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY52          (3)                     /* Mutual 1 Key52 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY53          (3)                     /* Mutual 1 Key53 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY54          (3)                     /* Mutual 1 Key54 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY55          (3)                     /* Mutual 1 Key55 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY56          (3)                     /* Mutual 1 Key56 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY57          (3)                     /* Mutual 1 Key57 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY58          (3)                     /* Mutual 1 Key58 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY59          (3)                     /* Mutual 1 Key59 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY60          (3)                     /* Mutual 1 Key60 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY61          (3)                     /* Mutual 1 Key61 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY62          (3)                     /* Mutual 1 Key62 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL5_KEY63          (3)                     /* Mutual 1 Key63 CTSUSNUM                            */

#define CTSUSO0_MUTUAL5_KEY00           ((CTSUSNUM_MUTUAL5_KEY00 << 10) | CTSUSO_MUTUAL5_KEY00)
#define CTSUSO0_MUTUAL5_KEY01           ((CTSUSNUM_MUTUAL5_KEY01 << 10) | CTSUSO_MUTUAL5_KEY01)
#define CTSUSO0_MUTUAL5_KEY02           ((CTSUSNUM_MUTUAL5_KEY02 << 10) | CTSUSO_MUTUAL5_KEY02)
#define CTSUSO0_MUTUAL5_KEY03           ((CTSUSNUM_MUTUAL5_KEY03 << 10) | CTSUSO_MUTUAL5_KEY03)
#define CTSUSO0_MUTUAL5_KEY04           ((CTSUSNUM_MUTUAL5_KEY04 << 10) | CTSUSO_MUTUAL5_KEY04)
#define CTSUSO0_MUTUAL5_KEY05           ((CTSUSNUM_MUTUAL5_KEY05 << 10) | CTSUSO_MUTUAL5_KEY05)
#define CTSUSO0_MUTUAL5_KEY06           ((CTSUSNUM_MUTUAL5_KEY06 << 10) | CTSUSO_MUTUAL5_KEY06)
#define CTSUSO0_MUTUAL5_KEY07           ((CTSUSNUM_MUTUAL5_KEY07 << 10) | CTSUSO_MUTUAL5_KEY07)
#define CTSUSO0_MUTUAL5_KEY08           ((CTSUSNUM_MUTUAL5_KEY08 << 10) | CTSUSO_MUTUAL5_KEY08)
#define CTSUSO0_MUTUAL5_KEY09           ((CTSUSNUM_MUTUAL5_KEY09 << 10) | CTSUSO_MUTUAL5_KEY09)
#define CTSUSO0_MUTUAL5_KEY10           ((CTSUSNUM_MUTUAL5_KEY10 << 10) | CTSUSO_MUTUAL5_KEY10)
#define CTSUSO0_MUTUAL5_KEY11           ((CTSUSNUM_MUTUAL5_KEY11 << 10) | CTSUSO_MUTUAL5_KEY11)
#define CTSUSO0_MUTUAL5_KEY12           ((CTSUSNUM_MUTUAL5_KEY12 << 10) | CTSUSO_MUTUAL5_KEY12)
#define CTSUSO0_MUTUAL5_KEY13           ((CTSUSNUM_MUTUAL5_KEY13 << 10) | CTSUSO_MUTUAL5_KEY13)
#define CTSUSO0_MUTUAL5_KEY14           ((CTSUSNUM_MUTUAL5_KEY14 << 10) | CTSUSO_MUTUAL5_KEY14)
#define CTSUSO0_MUTUAL5_KEY15           ((CTSUSNUM_MUTUAL5_KEY15 << 10) | CTSUSO_MUTUAL5_KEY15)
#define CTSUSO0_MUTUAL5_KEY16           ((CTSUSNUM_MUTUAL5_KEY16 << 10) | CTSUSO_MUTUAL5_KEY16)
#define CTSUSO0_MUTUAL5_KEY17           ((CTSUSNUM_MUTUAL5_KEY17 << 10) | CTSUSO_MUTUAL5_KEY17)
#define CTSUSO0_MUTUAL5_KEY18           ((CTSUSNUM_MUTUAL5_KEY18 << 10) | CTSUSO_MUTUAL5_KEY18)
#define CTSUSO0_MUTUAL5_KEY19           ((CTSUSNUM_MUTUAL5_KEY19 << 10) | CTSUSO_MUTUAL5_KEY19)
#define CTSUSO0_MUTUAL5_KEY20           ((CTSUSNUM_MUTUAL5_KEY20 << 10) | CTSUSO_MUTUAL5_KEY20)
#define CTSUSO0_MUTUAL5_KEY21           ((CTSUSNUM_MUTUAL5_KEY21 << 10) | CTSUSO_MUTUAL5_KEY21)
#define CTSUSO0_MUTUAL5_KEY22           ((CTSUSNUM_MUTUAL5_KEY22 << 10) | CTSUSO_MUTUAL5_KEY22)
#define CTSUSO0_MUTUAL5_KEY23           ((CTSUSNUM_MUTUAL5_KEY23 << 10) | CTSUSO_MUTUAL5_KEY23)
#define CTSUSO0_MUTUAL5_KEY24           ((CTSUSNUM_MUTUAL5_KEY24 << 10) | CTSUSO_MUTUAL5_KEY24)
#define CTSUSO0_MUTUAL5_KEY25           ((CTSUSNUM_MUTUAL5_KEY25 << 10) | CTSUSO_MUTUAL5_KEY25)
#define CTSUSO0_MUTUAL5_KEY26           ((CTSUSNUM_MUTUAL5_KEY26 << 10) | CTSUSO_MUTUAL5_KEY26)
#define CTSUSO0_MUTUAL5_KEY27           ((CTSUSNUM_MUTUAL5_KEY27 << 10) | CTSUSO_MUTUAL5_KEY27)
#define CTSUSO0_MUTUAL5_KEY28           ((CTSUSNUM_MUTUAL5_KEY28 << 10) | CTSUSO_MUTUAL5_KEY28)
#define CTSUSO0_MUTUAL5_KEY29           ((CTSUSNUM_MUTUAL5_KEY29 << 10) | CTSUSO_MUTUAL5_KEY29)
#define CTSUSO0_MUTUAL5_KEY30           ((CTSUSNUM_MUTUAL5_KEY30 << 10) | CTSUSO_MUTUAL5_KEY30)
#define CTSUSO0_MUTUAL5_KEY31           ((CTSUSNUM_MUTUAL5_KEY31 << 10) | CTSUSO_MUTUAL5_KEY31)
#define CTSUSO0_MUTUAL5_KEY32           ((CTSUSNUM_MUTUAL5_KEY32 << 10) | CTSUSO_MUTUAL5_KEY32)
#define CTSUSO0_MUTUAL5_KEY33           ((CTSUSNUM_MUTUAL5_KEY33 << 10) | CTSUSO_MUTUAL5_KEY33)
#define CTSUSO0_MUTUAL5_KEY34           ((CTSUSNUM_MUTUAL5_KEY34 << 10) | CTSUSO_MUTUAL5_KEY34)
#define CTSUSO0_MUTUAL5_KEY35           ((CTSUSNUM_MUTUAL5_KEY35 << 10) | CTSUSO_MUTUAL5_KEY35)
#define CTSUSO0_MUTUAL5_KEY36           ((CTSUSNUM_MUTUAL5_KEY36 << 10) | CTSUSO_MUTUAL5_KEY36)
#define CTSUSO0_MUTUAL5_KEY37           ((CTSUSNUM_MUTUAL5_KEY37 << 10) | CTSUSO_MUTUAL5_KEY37)
#define CTSUSO0_MUTUAL5_KEY38           ((CTSUSNUM_MUTUAL5_KEY38 << 10) | CTSUSO_MUTUAL5_KEY38)
#define CTSUSO0_MUTUAL5_KEY39           ((CTSUSNUM_MUTUAL5_KEY39 << 10) | CTSUSO_MUTUAL5_KEY39)
#define CTSUSO0_MUTUAL5_KEY40           ((CTSUSNUM_MUTUAL5_KEY40 << 10) | CTSUSO_MUTUAL5_KEY40)
#define CTSUSO0_MUTUAL5_KEY41           ((CTSUSNUM_MUTUAL5_KEY41 << 10) | CTSUSO_MUTUAL5_KEY41)
#define CTSUSO0_MUTUAL5_KEY42           ((CTSUSNUM_MUTUAL5_KEY42 << 10) | CTSUSO_MUTUAL5_KEY42)
#define CTSUSO0_MUTUAL5_KEY43           ((CTSUSNUM_MUTUAL5_KEY43 << 10) | CTSUSO_MUTUAL5_KEY43)
#define CTSUSO0_MUTUAL5_KEY44           ((CTSUSNUM_MUTUAL5_KEY44 << 10) | CTSUSO_MUTUAL5_KEY44)
#define CTSUSO0_MUTUAL5_KEY45           ((CTSUSNUM_MUTUAL5_KEY45 << 10) | CTSUSO_MUTUAL5_KEY45)
#define CTSUSO0_MUTUAL5_KEY46           ((CTSUSNUM_MUTUAL5_KEY46 << 10) | CTSUSO_MUTUAL5_KEY46)
#define CTSUSO0_MUTUAL5_KEY47           ((CTSUSNUM_MUTUAL5_KEY47 << 10) | CTSUSO_MUTUAL5_KEY47)
#define CTSUSO0_MUTUAL5_KEY48           ((CTSUSNUM_MUTUAL5_KEY48 << 10) | CTSUSO_MUTUAL5_KEY48)
#define CTSUSO0_MUTUAL5_KEY49           ((CTSUSNUM_MUTUAL5_KEY49 << 10) | CTSUSO_MUTUAL5_KEY49)
#define CTSUSO0_MUTUAL5_KEY50           ((CTSUSNUM_MUTUAL5_KEY50 << 10) | CTSUSO_MUTUAL5_KEY50)
#define CTSUSO0_MUTUAL5_KEY51           ((CTSUSNUM_MUTUAL5_KEY51 << 10) | CTSUSO_MUTUAL5_KEY51)
#define CTSUSO0_MUTUAL5_KEY52           ((CTSUSNUM_MUTUAL5_KEY52 << 10) | CTSUSO_MUTUAL5_KEY52)
#define CTSUSO0_MUTUAL5_KEY53           ((CTSUSNUM_MUTUAL5_KEY53 << 10) | CTSUSO_MUTUAL5_KEY53)
#define CTSUSO0_MUTUAL5_KEY54           ((CTSUSNUM_MUTUAL5_KEY54 << 10) | CTSUSO_MUTUAL5_KEY54)
#define CTSUSO0_MUTUAL5_KEY55           ((CTSUSNUM_MUTUAL5_KEY55 << 10) | CTSUSO_MUTUAL5_KEY55)
#define CTSUSO0_MUTUAL5_KEY56           ((CTSUSNUM_MUTUAL5_KEY56 << 10) | CTSUSO_MUTUAL5_KEY56)
#define CTSUSO0_MUTUAL5_KEY57           ((CTSUSNUM_MUTUAL5_KEY57 << 10) | CTSUSO_MUTUAL5_KEY57)
#define CTSUSO0_MUTUAL5_KEY58           ((CTSUSNUM_MUTUAL5_KEY58 << 10) | CTSUSO_MUTUAL5_KEY58)
#define CTSUSO0_MUTUAL5_KEY59           ((CTSUSNUM_MUTUAL5_KEY59 << 10) | CTSUSO_MUTUAL5_KEY59)
#define CTSUSO0_MUTUAL5_KEY60           ((CTSUSNUM_MUTUAL5_KEY60 << 10) | CTSUSO_MUTUAL5_KEY60)
#define CTSUSO0_MUTUAL5_KEY61           ((CTSUSNUM_MUTUAL5_KEY61 << 10) | CTSUSO_MUTUAL5_KEY61)
#define CTSUSO0_MUTUAL5_KEY62           ((CTSUSNUM_MUTUAL5_KEY62 << 10) | CTSUSO_MUTUAL5_KEY62)
#define CTSUSO0_MUTUAL5_KEY63           ((CTSUSNUM_MUTUAL5_KEY63 << 10) | CTSUSO_MUTUAL5_KEY63)

/*****    Address 000A 0914h CTSU Sensor Offset Register 1    *********************************************************/
/**********************************************************************************************************************/
/*    CTSU Reference ICO Current Adjustment                                                                           */
/*        Input current amount 0      0x00                                                                            */
/*        Input current amount 1      0x01                                                                            */
/*        Input current amount 2      0x02                                                                            */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*        Input current amount 254    0xFF                                                                            */
/**********************************************************************************************************************/
#define CTSURICOA_MUTUAL5_KEY00         (0x3F)                  /* Mutual 1 Key00 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY01         (0x3F)                  /* Mutual 1 Key01 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY02         (0x3F)                  /* Mutual 1 Key02 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY03         (0x3F)                  /* Mutual 1 Key03 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY04         (0x3F)                  /* Mutual 1 Key04 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY05         (0x3F)                  /* Mutual 1 Key05 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY06         (0x3F)                  /* Mutual 1 Key06 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY07         (0x3F)                  /* Mutual 1 Key07 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY08         (0x3F)                  /* Mutual 1 Key08 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY09         (0x3F)                  /* Mutual 1 Key09 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY10         (0x3F)                  /* Mutual 1 Key10 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY11         (0x3F)                  /* Mutual 1 Key11 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY12         (0x3F)                  /* Mutual 1 Key12 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY13         (0x3F)                  /* Mutual 1 Key13 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY14         (0x3F)                  /* Mutual 1 Key14 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY15         (0x3F)                  /* Mutual 1 Key15 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY16         (0x3F)                  /* Mutual 1 Key16 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY17         (0x3F)                  /* Mutual 1 Key17 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY18         (0x3F)                  /* Mutual 1 Key18 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY19         (0x3F)                  /* Mutual 1 Key19 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY20         (0x3F)                  /* Mutual 1 Key20 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY21         (0x3F)                  /* Mutual 1 Key21 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY22         (0x3F)                  /* Mutual 1 Key22 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY23         (0x3F)                  /* Mutual 1 Key23 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY24         (0x3F)                  /* Mutual 1 Key24 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY25         (0x3F)                  /* Mutual 1 Key25 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY26         (0x3F)                  /* Mutual 1 Key26 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY27         (0x3F)                  /* Mutual 1 Key27 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY28         (0x3F)                  /* Mutual 1 Key28 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY29         (0x3F)                  /* Mutual 1 Key29 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY30         (0x3F)                  /* Mutual 1 Key30 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY31         (0x3F)                  /* Mutual 1 Key31 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY32         (0x3F)                  /* Mutual 1 Key32 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY33         (0x3F)                  /* Mutual 1 Key33 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY34         (0x3F)                  /* Mutual 1 Key34 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY35         (0x3F)                  /* Mutual 1 Key35 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY36         (0x3F)                  /* Mutual 1 Key36 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY37         (0x3F)                  /* Mutual 1 Key37 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY38         (0x3F)                  /* Mutual 1 Key38 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY39         (0x3F)                  /* Mutual 1 Key39 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY40         (0x3F)                  /* Mutual 1 Key40 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY41         (0x3F)                  /* Mutual 1 Key41 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY42         (0x3F)                  /* Mutual 1 Key42 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY43         (0x3F)                  /* Mutual 1 Key43 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY44         (0x3F)                  /* Mutual 1 Key44 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY45         (0x3F)                  /* Mutual 1 Key45 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY46         (0x3F)                  /* Mutual 1 Key46 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY47         (0x3F)                  /* Mutual 1 Key47 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY48         (0x3F)                  /* Mutual 1 Key48 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY49         (0x3F)                  /* Mutual 1 Key49 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY50         (0x3F)                  /* Mutual 1 Key50 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY51         (0x3F)                  /* Mutual 1 Key51 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY52         (0x3F)                  /* Mutual 1 Key52 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY53         (0x3F)                  /* Mutual 1 Key53 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY54         (0x3F)                  /* Mutual 1 Key54 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY55         (0x3F)                  /* Mutual 1 Key55 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY56         (0x3F)                  /* Mutual 1 Key56 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY57         (0x3F)                  /* Mutual 1 Key57 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY58         (0x3F)                  /* Mutual 1 Key58 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY59         (0x3F)                  /* Mutual 1 Key59 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY60         (0x3F)                  /* Mutual 1 Key60 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY61         (0x3F)                  /* Mutual 1 Key61 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY62         (0x3F)                  /* Mutual 1 Key62 CTSUICOA                            */
#define CTSURICOA_MUTUAL5_KEY63         (0x3F)                  /* Mutual 1 Key63 CTSUICOA                            */

/**********************************************************************************************************************/
/*    CTSU Base Clock Setting                                                                                         */
/*        Operating clock divided by 2     0x00                                                                       */
/*        Operating clock divided by 4     0x01                                                                       */
/*        Operating clock divided by 6     0x02                                                                       */
/*                       :                                                                                            */
/*                       :                                                                                            */
/*        Operating clock divided by 64    0x1F                                                                       */
/*                                                                                                                    */
/*    Case : CTSU Operating Clock 32MHz      Case : CTSU Operating Clock 24MHz      Case : CTSU Operating Clock 16MHz */
/*           4.0MHz <--- 0x03                       4.0MHz <--- 0x02                       4.0MHz <--- 0x01           */
/*           2.0MHz <--- 0x07                       2.0MHz <--- 0x05                       2.0MHz <--- 0x03           */
/*           1.0MHz <--- 0x0F                       1.0MHz <--- 0x0B                       1.0MHz <--- 0x07           */
/*           0.5MHz <--- 0x1F                       0.5MHz <--- 0x17                       0.5MHz <--- 0x0F           */
/**********************************************************************************************************************/
#define CTSUSDPA_MUTUAL5_KEY00          (7)                     /* Mutual 1 Key00 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY01          (7)                     /* Mutual 1 Key01 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY02          (7)                     /* Mutual 1 Key02 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY03          (7)                     /* Mutual 1 Key03 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY04          (7)                     /* Mutual 1 Key04 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY05          (7)                     /* Mutual 1 Key05 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY06          (7)                     /* Mutual 1 Key06 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY07          (7)                     /* Mutual 1 Key07 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY08          (7)                     /* Mutual 1 Key08 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY09          (7)                     /* Mutual 1 Key09 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY10          (7)                     /* Mutual 1 Key10 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY11          (7)                     /* Mutual 1 Key11 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY12          (7)                     /* Mutual 1 Key12 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY13          (7)                     /* Mutual 1 Key13 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY14          (7)                     /* Mutual 1 Key14 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY15          (7)                     /* Mutual 1 Key15 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY16          (7)                     /* Mutual 1 Key16 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY17          (7)                     /* Mutual 1 Key17 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY18          (7)                     /* Mutual 1 Key18 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY19          (7)                     /* Mutual 1 Key19 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY20          (7)                     /* Mutual 1 Key20 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY21          (7)                     /* Mutual 1 Key21 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY22          (7)                     /* Mutual 1 Key22 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY23          (7)                     /* Mutual 1 Key23 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY24          (7)                     /* Mutual 1 Key24 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY25          (7)                     /* Mutual 1 Key25 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY26          (7)                     /* Mutual 1 Key26 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY27          (7)                     /* Mutual 1 Key27 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY28          (7)                     /* Mutual 1 Key28 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY29          (7)                     /* Mutual 1 Key29 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY30          (7)                     /* Mutual 1 Key30 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY31          (7)                     /* Mutual 1 Key31 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY32          (7)                     /* Mutual 1 Key32 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY33          (7)                     /* Mutual 1 Key33 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY34          (7)                     /* Mutual 1 Key34 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY35          (7)                     /* Mutual 1 Key35 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY36          (7)                     /* Mutual 1 Key36 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY37          (7)                     /* Mutual 1 Key37 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY38          (7)                     /* Mutual 1 Key38 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY39          (7)                     /* Mutual 1 Key39 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY40          (7)                     /* Mutual 1 Key40 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY41          (7)                     /* Mutual 1 Key41 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY42          (7)                     /* Mutual 1 Key42 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY43          (7)                     /* Mutual 1 Key43 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY44          (7)                     /* Mutual 1 Key44 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY45          (7)                     /* Mutual 1 Key45 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY46          (7)                     /* Mutual 1 Key46 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY47          (7)                     /* Mutual 1 Key47 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY48          (7)                     /* Mutual 1 Key48 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY49          (7)                     /* Mutual 1 Key49 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY50          (7)                     /* Mutual 1 Key50 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY51          (7)                     /* Mutual 1 Key51 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY52          (7)                     /* Mutual 1 Key52 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY53          (7)                     /* Mutual 1 Key53 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY54          (7)                     /* Mutual 1 Key54 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY55          (7)                     /* Mutual 1 Key55 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY56          (7)                     /* Mutual 1 Key56 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY57          (7)                     /* Mutual 1 Key57 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY58          (7)                     /* Mutual 1 Key58 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY59          (7)                     /* Mutual 1 Key59 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY60          (7)                     /* Mutual 1 Key60 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY61          (7)                     /* Mutual 1 Key61 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY62          (7)                     /* Mutual 1 Key62 CTSUDPA                             */
#define CTSUSDPA_MUTUAL5_KEY63          (7)                     /* Mutual 1 Key63 CTSUDPA                             */

/**********************************************************************************************************************/
/*    CTSU ICO Gain Adjustment                                                                                        */
/*        0 : 100% gain                                                                                               */
/*        1 :  66% gain                                                                                               */
/*        2 :  50% gain                                                                                               */
/*        3 :  40% gain                                                                                               */
/**********************************************************************************************************************/
#define CTSUICOG_MUTUAL5_KEY00          (1)                     /* Mutual 1 Key00 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY01          (1)                     /* Mutual 1 Key01 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY02          (1)                     /* Mutual 1 Key02 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY03          (1)                     /* Mutual 1 Key03 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY04          (1)                     /* Mutual 1 Key04 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY05          (1)                     /* Mutual 1 Key05 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY06          (1)                     /* Mutual 1 Key06 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY07          (1)                     /* Mutual 1 Key07 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY08          (1)                     /* Mutual 1 Key08 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY09          (1)                     /* Mutual 1 Key09 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY10          (1)                     /* Mutual 1 Key10 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY11          (1)                     /* Mutual 1 Key11 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY12          (1)                     /* Mutual 1 Key12 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY13          (1)                     /* Mutual 1 Key13 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY14          (1)                     /* Mutual 1 Key14 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY15          (1)                     /* Mutual 1 Key15 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY16          (1)                     /* Mutual 1 Key16 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY17          (1)                     /* Mutual 1 Key17 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY18          (1)                     /* Mutual 1 Key18 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY19          (1)                     /* Mutual 1 Key19 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY20          (1)                     /* Mutual 1 Key20 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY21          (1)                     /* Mutual 1 Key21 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY22          (1)                     /* Mutual 1 Key22 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY23          (1)                     /* Mutual 1 Key23 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY24          (1)                     /* Mutual 1 Key24 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY25          (1)                     /* Mutual 1 Key25 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY26          (1)                     /* Mutual 1 Key26 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY27          (1)                     /* Mutual 1 Key27 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY28          (1)                     /* Mutual 1 Key28 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY29          (1)                     /* Mutual 1 Key29 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY30          (1)                     /* Mutual 1 Key30 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY31          (1)                     /* Mutual 1 Key31 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY32          (1)                     /* Mutual 1 Key32 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY33          (1)                     /* Mutual 1 Key33 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY34          (1)                     /* Mutual 1 Key34 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY35          (1)                     /* Mutual 1 Key35 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY36          (1)                     /* Mutual 1 Key36 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY37          (1)                     /* Mutual 1 Key37 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY38          (1)                     /* Mutual 1 Key38 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY39          (1)                     /* Mutual 1 Key39 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY40          (1)                     /* Mutual 1 Key40 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY41          (1)                     /* Mutual 1 Key41 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY42          (1)                     /* Mutual 1 Key42 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY43          (1)                     /* Mutual 1 Key43 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY44          (1)                     /* Mutual 1 Key44 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY45          (1)                     /* Mutual 1 Key45 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY46          (1)                     /* Mutual 1 Key46 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY47          (1)                     /* Mutual 1 Key47 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY48          (1)                     /* Mutual 1 Key48 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY49          (1)                     /* Mutual 1 Key49 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY50          (1)                     /* Mutual 1 Key50 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY51          (1)                     /* Mutual 1 Key51 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY52          (1)                     /* Mutual 1 Key52 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY53          (1)                     /* Mutual 1 Key53 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY54          (1)                     /* Mutual 1 Key54 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY55          (1)                     /* Mutual 1 Key55 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY56          (1)                     /* Mutual 1 Key56 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY57          (1)                     /* Mutual 1 Key57 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY58          (1)                     /* Mutual 1 Key58 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY59          (1)                     /* Mutual 1 Key59 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY60          (1)                     /* Mutual 1 Key60 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY61          (1)                     /* Mutual 1 Key61 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY62          (1)                     /* Mutual 1 Key62 CTSICOG                             */
#define CTSUICOG_MUTUAL5_KEY63          (1)                     /* Mutual 1 Key63 CTSICOG                             */

#define CTSUSO1_MUTUAL5_KEY00  ((CTSUICOG_MUTUAL5_KEY00 << 13) | (CTSUSDPA_MUTUAL5_KEY00 << 8) | CTSURICOA_MUTUAL5_KEY00)
#define CTSUSO1_MUTUAL5_KEY01  ((CTSUICOG_MUTUAL5_KEY01 << 13) | (CTSUSDPA_MUTUAL5_KEY01 << 8) | CTSURICOA_MUTUAL5_KEY01)
#define CTSUSO1_MUTUAL5_KEY02  ((CTSUICOG_MUTUAL5_KEY02 << 13) | (CTSUSDPA_MUTUAL5_KEY02 << 8) | CTSURICOA_MUTUAL5_KEY02)
#define CTSUSO1_MUTUAL5_KEY03  ((CTSUICOG_MUTUAL5_KEY03 << 13) | (CTSUSDPA_MUTUAL5_KEY03 << 8) | CTSURICOA_MUTUAL5_KEY03)
#define CTSUSO1_MUTUAL5_KEY04  ((CTSUICOG_MUTUAL5_KEY04 << 13) | (CTSUSDPA_MUTUAL5_KEY04 << 8) | CTSURICOA_MUTUAL5_KEY04)
#define CTSUSO1_MUTUAL5_KEY05  ((CTSUICOG_MUTUAL5_KEY05 << 13) | (CTSUSDPA_MUTUAL5_KEY05 << 8) | CTSURICOA_MUTUAL5_KEY05)
#define CTSUSO1_MUTUAL5_KEY06  ((CTSUICOG_MUTUAL5_KEY06 << 13) | (CTSUSDPA_MUTUAL5_KEY06 << 8) | CTSURICOA_MUTUAL5_KEY06)
#define CTSUSO1_MUTUAL5_KEY07  ((CTSUICOG_MUTUAL5_KEY07 << 13) | (CTSUSDPA_MUTUAL5_KEY07 << 8) | CTSURICOA_MUTUAL5_KEY07)
#define CTSUSO1_MUTUAL5_KEY08  ((CTSUICOG_MUTUAL5_KEY08 << 13) | (CTSUSDPA_MUTUAL5_KEY08 << 8) | CTSURICOA_MUTUAL5_KEY08)
#define CTSUSO1_MUTUAL5_KEY09  ((CTSUICOG_MUTUAL5_KEY09 << 13) | (CTSUSDPA_MUTUAL5_KEY09 << 8) | CTSURICOA_MUTUAL5_KEY09)
#define CTSUSO1_MUTUAL5_KEY10  ((CTSUICOG_MUTUAL5_KEY10 << 13) | (CTSUSDPA_MUTUAL5_KEY10 << 8) | CTSURICOA_MUTUAL5_KEY10)
#define CTSUSO1_MUTUAL5_KEY11  ((CTSUICOG_MUTUAL5_KEY11 << 13) | (CTSUSDPA_MUTUAL5_KEY11 << 8) | CTSURICOA_MUTUAL5_KEY11)
#define CTSUSO1_MUTUAL5_KEY12  ((CTSUICOG_MUTUAL5_KEY12 << 13) | (CTSUSDPA_MUTUAL5_KEY12 << 8) | CTSURICOA_MUTUAL5_KEY12)
#define CTSUSO1_MUTUAL5_KEY13  ((CTSUICOG_MUTUAL5_KEY13 << 13) | (CTSUSDPA_MUTUAL5_KEY13 << 8) | CTSURICOA_MUTUAL5_KEY13)
#define CTSUSO1_MUTUAL5_KEY14  ((CTSUICOG_MUTUAL5_KEY14 << 13) | (CTSUSDPA_MUTUAL5_KEY14 << 8) | CTSURICOA_MUTUAL5_KEY14)
#define CTSUSO1_MUTUAL5_KEY15  ((CTSUICOG_MUTUAL5_KEY15 << 13) | (CTSUSDPA_MUTUAL5_KEY15 << 8) | CTSURICOA_MUTUAL5_KEY15)
#define CTSUSO1_MUTUAL5_KEY16  ((CTSUICOG_MUTUAL5_KEY16 << 13) | (CTSUSDPA_MUTUAL5_KEY16 << 8) | CTSURICOA_MUTUAL5_KEY16)
#define CTSUSO1_MUTUAL5_KEY17  ((CTSUICOG_MUTUAL5_KEY17 << 13) | (CTSUSDPA_MUTUAL5_KEY17 << 8) | CTSURICOA_MUTUAL5_KEY17)
#define CTSUSO1_MUTUAL5_KEY18  ((CTSUICOG_MUTUAL5_KEY18 << 13) | (CTSUSDPA_MUTUAL5_KEY18 << 8) | CTSURICOA_MUTUAL5_KEY18)
#define CTSUSO1_MUTUAL5_KEY19  ((CTSUICOG_MUTUAL5_KEY19 << 13) | (CTSUSDPA_MUTUAL5_KEY19 << 8) | CTSURICOA_MUTUAL5_KEY19)
#define CTSUSO1_MUTUAL5_KEY20  ((CTSUICOG_MUTUAL5_KEY20 << 13) | (CTSUSDPA_MUTUAL5_KEY20 << 8) | CTSURICOA_MUTUAL5_KEY20)
#define CTSUSO1_MUTUAL5_KEY21  ((CTSUICOG_MUTUAL5_KEY21 << 13) | (CTSUSDPA_MUTUAL5_KEY21 << 8) | CTSURICOA_MUTUAL5_KEY21)
#define CTSUSO1_MUTUAL5_KEY22  ((CTSUICOG_MUTUAL5_KEY22 << 13) | (CTSUSDPA_MUTUAL5_KEY22 << 8) | CTSURICOA_MUTUAL5_KEY22)
#define CTSUSO1_MUTUAL5_KEY23  ((CTSUICOG_MUTUAL5_KEY23 << 13) | (CTSUSDPA_MUTUAL5_KEY23 << 8) | CTSURICOA_MUTUAL5_KEY23)
#define CTSUSO1_MUTUAL5_KEY24  ((CTSUICOG_MUTUAL5_KEY24 << 13) | (CTSUSDPA_MUTUAL5_KEY24 << 8) | CTSURICOA_MUTUAL5_KEY24)
#define CTSUSO1_MUTUAL5_KEY25  ((CTSUICOG_MUTUAL5_KEY25 << 13) | (CTSUSDPA_MUTUAL5_KEY25 << 8) | CTSURICOA_MUTUAL5_KEY25)
#define CTSUSO1_MUTUAL5_KEY26  ((CTSUICOG_MUTUAL5_KEY26 << 13) | (CTSUSDPA_MUTUAL5_KEY26 << 8) | CTSURICOA_MUTUAL5_KEY26)
#define CTSUSO1_MUTUAL5_KEY27  ((CTSUICOG_MUTUAL5_KEY27 << 13) | (CTSUSDPA_MUTUAL5_KEY27 << 8) | CTSURICOA_MUTUAL5_KEY27)
#define CTSUSO1_MUTUAL5_KEY28  ((CTSUICOG_MUTUAL5_KEY28 << 13) | (CTSUSDPA_MUTUAL5_KEY28 << 8) | CTSURICOA_MUTUAL5_KEY28)
#define CTSUSO1_MUTUAL5_KEY29  ((CTSUICOG_MUTUAL5_KEY29 << 13) | (CTSUSDPA_MUTUAL5_KEY29 << 8) | CTSURICOA_MUTUAL5_KEY29)
#define CTSUSO1_MUTUAL5_KEY30  ((CTSUICOG_MUTUAL5_KEY30 << 13) | (CTSUSDPA_MUTUAL5_KEY30 << 8) | CTSURICOA_MUTUAL5_KEY30)
#define CTSUSO1_MUTUAL5_KEY31  ((CTSUICOG_MUTUAL5_KEY31 << 13) | (CTSUSDPA_MUTUAL5_KEY31 << 8) | CTSURICOA_MUTUAL5_KEY31)
#define CTSUSO1_MUTUAL5_KEY32  ((CTSUICOG_MUTUAL5_KEY32 << 13) | (CTSUSDPA_MUTUAL5_KEY32 << 8) | CTSURICOA_MUTUAL5_KEY32)
#define CTSUSO1_MUTUAL5_KEY33  ((CTSUICOG_MUTUAL5_KEY33 << 13) | (CTSUSDPA_MUTUAL5_KEY33 << 8) | CTSURICOA_MUTUAL5_KEY33)
#define CTSUSO1_MUTUAL5_KEY34  ((CTSUICOG_MUTUAL5_KEY34 << 13) | (CTSUSDPA_MUTUAL5_KEY34 << 8) | CTSURICOA_MUTUAL5_KEY34)
#define CTSUSO1_MUTUAL5_KEY35  ((CTSUICOG_MUTUAL5_KEY35 << 13) | (CTSUSDPA_MUTUAL5_KEY35 << 8) | CTSURICOA_MUTUAL5_KEY35)
#define CTSUSO1_MUTUAL5_KEY36  ((CTSUICOG_MUTUAL5_KEY36 << 13) | (CTSUSDPA_MUTUAL5_KEY36 << 8) | CTSURICOA_MUTUAL5_KEY36)
#define CTSUSO1_MUTUAL5_KEY37  ((CTSUICOG_MUTUAL5_KEY37 << 13) | (CTSUSDPA_MUTUAL5_KEY37 << 8) | CTSURICOA_MUTUAL5_KEY37)
#define CTSUSO1_MUTUAL5_KEY38  ((CTSUICOG_MUTUAL5_KEY38 << 13) | (CTSUSDPA_MUTUAL5_KEY38 << 8) | CTSURICOA_MUTUAL5_KEY38)
#define CTSUSO1_MUTUAL5_KEY39  ((CTSUICOG_MUTUAL5_KEY39 << 13) | (CTSUSDPA_MUTUAL5_KEY39 << 8) | CTSURICOA_MUTUAL5_KEY39)
#define CTSUSO1_MUTUAL5_KEY40  ((CTSUICOG_MUTUAL5_KEY40 << 13) | (CTSUSDPA_MUTUAL5_KEY40 << 8) | CTSURICOA_MUTUAL5_KEY40)
#define CTSUSO1_MUTUAL5_KEY41  ((CTSUICOG_MUTUAL5_KEY41 << 13) | (CTSUSDPA_MUTUAL5_KEY41 << 8) | CTSURICOA_MUTUAL5_KEY41)
#define CTSUSO1_MUTUAL5_KEY42  ((CTSUICOG_MUTUAL5_KEY42 << 13) | (CTSUSDPA_MUTUAL5_KEY42 << 8) | CTSURICOA_MUTUAL5_KEY42)
#define CTSUSO1_MUTUAL5_KEY43  ((CTSUICOG_MUTUAL5_KEY43 << 13) | (CTSUSDPA_MUTUAL5_KEY43 << 8) | CTSURICOA_MUTUAL5_KEY43)
#define CTSUSO1_MUTUAL5_KEY44  ((CTSUICOG_MUTUAL5_KEY44 << 13) | (CTSUSDPA_MUTUAL5_KEY44 << 8) | CTSURICOA_MUTUAL5_KEY44)
#define CTSUSO1_MUTUAL5_KEY45  ((CTSUICOG_MUTUAL5_KEY45 << 13) | (CTSUSDPA_MUTUAL5_KEY45 << 8) | CTSURICOA_MUTUAL5_KEY45)
#define CTSUSO1_MUTUAL5_KEY46  ((CTSUICOG_MUTUAL5_KEY46 << 13) | (CTSUSDPA_MUTUAL5_KEY46 << 8) | CTSURICOA_MUTUAL5_KEY46)
#define CTSUSO1_MUTUAL5_KEY47  ((CTSUICOG_MUTUAL5_KEY47 << 13) | (CTSUSDPA_MUTUAL5_KEY47 << 8) | CTSURICOA_MUTUAL5_KEY47)
#define CTSUSO1_MUTUAL5_KEY48  ((CTSUICOG_MUTUAL5_KEY48 << 13) | (CTSUSDPA_MUTUAL5_KEY48 << 8) | CTSURICOA_MUTUAL5_KEY48)
#define CTSUSO1_MUTUAL5_KEY49  ((CTSUICOG_MUTUAL5_KEY49 << 13) | (CTSUSDPA_MUTUAL5_KEY49 << 8) | CTSURICOA_MUTUAL5_KEY49)
#define CTSUSO1_MUTUAL5_KEY50  ((CTSUICOG_MUTUAL5_KEY50 << 13) | (CTSUSDPA_MUTUAL5_KEY50 << 8) | CTSURICOA_MUTUAL5_KEY50)
#define CTSUSO1_MUTUAL5_KEY51  ((CTSUICOG_MUTUAL5_KEY51 << 13) | (CTSUSDPA_MUTUAL5_KEY51 << 8) | CTSURICOA_MUTUAL5_KEY51)
#define CTSUSO1_MUTUAL5_KEY52  ((CTSUICOG_MUTUAL5_KEY52 << 13) | (CTSUSDPA_MUTUAL5_KEY52 << 8) | CTSURICOA_MUTUAL5_KEY52)
#define CTSUSO1_MUTUAL5_KEY53  ((CTSUICOG_MUTUAL5_KEY53 << 13) | (CTSUSDPA_MUTUAL5_KEY53 << 8) | CTSURICOA_MUTUAL5_KEY53)
#define CTSUSO1_MUTUAL5_KEY54  ((CTSUICOG_MUTUAL5_KEY54 << 13) | (CTSUSDPA_MUTUAL5_KEY54 << 8) | CTSURICOA_MUTUAL5_KEY54)
#define CTSUSO1_MUTUAL5_KEY55  ((CTSUICOG_MUTUAL5_KEY55 << 13) | (CTSUSDPA_MUTUAL5_KEY55 << 8) | CTSURICOA_MUTUAL5_KEY55)
#define CTSUSO1_MUTUAL5_KEY56  ((CTSUICOG_MUTUAL5_KEY56 << 13) | (CTSUSDPA_MUTUAL5_KEY56 << 8) | CTSURICOA_MUTUAL5_KEY56)
#define CTSUSO1_MUTUAL5_KEY57  ((CTSUICOG_MUTUAL5_KEY57 << 13) | (CTSUSDPA_MUTUAL5_KEY57 << 8) | CTSURICOA_MUTUAL5_KEY57)
#define CTSUSO1_MUTUAL5_KEY58  ((CTSUICOG_MUTUAL5_KEY58 << 13) | (CTSUSDPA_MUTUAL5_KEY58 << 8) | CTSURICOA_MUTUAL5_KEY58)
#define CTSUSO1_MUTUAL5_KEY59  ((CTSUICOG_MUTUAL5_KEY59 << 13) | (CTSUSDPA_MUTUAL5_KEY59 << 8) | CTSURICOA_MUTUAL5_KEY59)
#define CTSUSO1_MUTUAL5_KEY60  ((CTSUICOG_MUTUAL5_KEY60 << 13) | (CTSUSDPA_MUTUAL5_KEY60 << 8) | CTSURICOA_MUTUAL5_KEY60)
#define CTSUSO1_MUTUAL5_KEY61  ((CTSUICOG_MUTUAL5_KEY61 << 13) | (CTSUSDPA_MUTUAL5_KEY61 << 8) | CTSURICOA_MUTUAL5_KEY61)
#define CTSUSO1_MUTUAL5_KEY62  ((CTSUICOG_MUTUAL5_KEY62 << 13) | (CTSUSDPA_MUTUAL5_KEY62 << 8) | CTSURICOA_MUTUAL5_KEY62)
#define CTSUSO1_MUTUAL5_KEY63  ((CTSUICOG_MUTUAL5_KEY63 << 13) | (CTSUSDPA_MUTUAL5_KEY63 << 8) | CTSURICOA_MUTUAL5_KEY63)
#endif    // ( MUTUAL_METHOD_NUM >= 6 )

#if ( MUTUAL_METHOD_NUM >= 7 )
/*====================================================================================================================*/
/*=====     Mutual-measurement 6 TS enable definition    =============================================================*/
/*====================================================================================================================*/
#define MUTUAL6_ENABLE_TS00              (0)        /* Mutual 1 TS00 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS01              (0)        /* Mutual 1 TS01 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS02              (0)        /* Mutual 1 TS02 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS03              (0)        /* Mutual 1 TS03 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS04              (0)        /* Mutual 1 TS04 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS05              (0)        /* Mutual 1 TS05 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS06              (0)        /* Mutual 1 TS06 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS07              (0)        /* Mutual 1 TS07 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS08              (0)        /* Mutual 1 TS08 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS09              (0)        /* Mutual 1 TS09 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS10              (0)        /* Mutual 1 TS10 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS11              (0)        /* Mutual 1 TS11 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS12              (0)        /* Mutual 1 TS12 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS13              (0)        /* Mutual 1 TS13 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS14              (0)        /* Mutual 1 TS14 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS15              (0)        /* Mutual 1 TS15 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS16              (0)        /* Mutual 1 TS16 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS17              (0)        /* Mutual 1 TS17 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS18              (0)        /* Mutual 1 TS18 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS19              (0)        /* Mutual 1 TS19 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS20              (0)        /* Mutual 1 TS20 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS21              (0)        /* Mutual 1 TS21 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS22              (0)        /* Mutual 1 TS22 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS23              (0)        /* Mutual 1 TS23 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS24              (0)        /* Mutual 1 TS24 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS25              (0)        /* Mutual 1 TS25 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS26              (0)        /* Mutual 1 TS26 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS27              (0)        /* Mutual 1 TS27 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS28              (0)        /* Mutual 1 TS28 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS29              (0)        /* Mutual 1 TS29 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS30              (0)        /* Mutual 1 TS30 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS31              (0)        /* Mutual 1 TS31 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS32              (0)        /* Mutual 1 TS32 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS33              (0)        /* Mutual 1 TS33 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS34              (0)        /* Mutual 1 TS34 0:disable 1:enable                               */
#define MUTUAL6_ENABLE_TS35              (0)        /* Mutual 1 TS35 0:disable 1:enable                               */

/*****    Address 000A 0906h CTSU Channel enable control register 0    ************************************************/
#define CTSUCHAC0_MUTUAL6_ENABLE_TS      ((MUTUAL6_ENABLE_TS00 << 0) | (MUTUAL6_ENABLE_TS01 << 1) | \
                                          (MUTUAL6_ENABLE_TS02 << 2) | (MUTUAL6_ENABLE_TS03 << 3) | \
                                          (MUTUAL6_ENABLE_TS04 << 4) | (MUTUAL6_ENABLE_TS05 << 5) | \
                                          (MUTUAL6_ENABLE_TS06 << 6) | (MUTUAL6_ENABLE_TS07 << 7))

/*****    Address 000A 0907h CTSU Channel enable control register 1    ************************************************/
#define CTSUCHAC1_MUTUAL6_ENABLE_TS      ((MUTUAL6_ENABLE_TS08 << 0) | (MUTUAL6_ENABLE_TS09 << 1) | \
                                          (MUTUAL6_ENABLE_TS10 << 2) | (MUTUAL6_ENABLE_TS11 << 3) | \
                                          (MUTUAL6_ENABLE_TS12 << 4) | (MUTUAL6_ENABLE_TS13 << 5) | \
                                          (MUTUAL6_ENABLE_TS14 << 6) | (MUTUAL6_ENABLE_TS15 << 7))

/*****    Address 000A 0908h CTSU Channel enable control register 2    ************************************************/
#define CTSUCHAC2_MUTUAL6_ENABLE_TS      ((MUTUAL6_ENABLE_TS16 << 0) | (MUTUAL6_ENABLE_TS17 << 1) | \
                                          (MUTUAL6_ENABLE_TS18 << 2) | (MUTUAL6_ENABLE_TS19 << 3) | \
                                          (MUTUAL6_ENABLE_TS20 << 4) | (MUTUAL6_ENABLE_TS21 << 5) | \
                                          (MUTUAL6_ENABLE_TS22 << 6) | (MUTUAL6_ENABLE_TS23 << 7))

/*****    Address 000A 0909h CTSU Channel enable control register 3    ************************************************/
#define CTSUCHAC3_MUTUAL6_ENABLE_TS      ((MUTUAL6_ENABLE_TS24 << 0) | (MUTUAL6_ENABLE_TS25 << 1) | \
                                          (MUTUAL6_ENABLE_TS26 << 2) | (MUTUAL6_ENABLE_TS27 << 3) | \
                                          (MUTUAL6_ENABLE_TS28 << 4) | (MUTUAL6_ENABLE_TS29 << 5) | \
                                          (MUTUAL6_ENABLE_TS30 << 6) | (MUTUAL6_ENABLE_TS31 << 7))

/*****    Address 000A 090ah CTSU Channel enable control register 4    ************************************************/
#define CTSUCHAC4_MUTUAL6_ENABLE_TS      ((MUTUAL6_ENABLE_TS32 << 0) | (MUTUAL6_ENABLE_TS33 << 1) | \
                                          (MUTUAL6_ENABLE_TS34 << 2) | (MUTUAL6_ENABLE_TS35 << 3))

/* SUM of Channels */ /* Do not edit this macro definition */
#define MUTUAL6_ENABLE_NUM               (MUTUAL6_ENABLE_TS00 + MUTUAL6_ENABLE_TS01 + MUTUAL6_ENABLE_TS02 + \
                                          MUTUAL6_ENABLE_TS03 + MUTUAL6_ENABLE_TS04 + MUTUAL6_ENABLE_TS05 + \
                                          MUTUAL6_ENABLE_TS06 + MUTUAL6_ENABLE_TS07 + MUTUAL6_ENABLE_TS08 + \
                                          MUTUAL6_ENABLE_TS09 + MUTUAL6_ENABLE_TS10 + MUTUAL6_ENABLE_TS11 + \
                                          MUTUAL6_ENABLE_TS12 + MUTUAL6_ENABLE_TS13 + MUTUAL6_ENABLE_TS14 + \
                                          MUTUAL6_ENABLE_TS15 + MUTUAL6_ENABLE_TS16 + MUTUAL6_ENABLE_TS17 + \
                                          MUTUAL6_ENABLE_TS18 + MUTUAL6_ENABLE_TS19 + MUTUAL6_ENABLE_TS20 + \
                                          MUTUAL6_ENABLE_TS21 + MUTUAL6_ENABLE_TS22 + MUTUAL6_ENABLE_TS23 + \
                                          MUTUAL6_ENABLE_TS24 + MUTUAL6_ENABLE_TS25 + MUTUAL6_ENABLE_TS26 + \
                                          MUTUAL6_ENABLE_TS27 + MUTUAL6_ENABLE_TS28 + MUTUAL6_ENABLE_TS29 + \
                                          MUTUAL6_ENABLE_TS30 + MUTUAL6_ENABLE_TS31 + MUTUAL6_ENABLE_TS32 + \
                                          MUTUAL6_ENABLE_TS33 + MUTUAL6_ENABLE_TS34 + MUTUAL6_ENABLE_TS35)

/*====================================================================================================================*/
/*=====     Mutual-measurement 6 function definition     =============================================================*/
/*====================================================================================================================*/
#define MUTUAL6_FUNCTION_TS00            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS01            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS02            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS03            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS04            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS05            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS06            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS07            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS08            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS09            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS10            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS11            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS12            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS13            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS14            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS15            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS16            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS17            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS18            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS19            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS20            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS21            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS22            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS23            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS24            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS25            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS26            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS27            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS28            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS29            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS30            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS31            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS32            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS33            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS34            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL6_FUNCTION_TS35            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */

/*****    Address 000A 090Bh CTSU Channel send and receive control register 0 *****************************************/
#define CTSUCHTRC0_MUTUAL6_TRANSMIT_TS   ((MUTUAL6_FUNCTION_TS00 << 0) | (MUTUAL6_FUNCTION_TS01 << 1) | \
                                          (MUTUAL6_FUNCTION_TS02 << 2) | (MUTUAL6_FUNCTION_TS03 << 3) | \
                                          (MUTUAL6_FUNCTION_TS04 << 4) | (MUTUAL6_FUNCTION_TS05 << 5) | \
                                          (MUTUAL6_FUNCTION_TS06 << 6) | (MUTUAL6_FUNCTION_TS07 << 7))

/*****    Address 000A 090Ch CTSU Channel send and receive control register 1 *****************************************/
#define CTSUCHTRC1_MUTUAL6_TRANSMIT_TS   ((MUTUAL6_FUNCTION_TS08 << 0) | (MUTUAL6_FUNCTION_TS09 << 1) | \
                                          (MUTUAL6_FUNCTION_TS10 << 2) | (MUTUAL6_FUNCTION_TS11 << 3) | \
                                          (MUTUAL6_FUNCTION_TS12 << 4) | (MUTUAL6_FUNCTION_TS13 << 5) | \
                                          (MUTUAL6_FUNCTION_TS14 << 6) | (MUTUAL6_FUNCTION_TS15 << 7))

/*****    Address 000A 090Dh CTSU Channel send and receive control register 2 *****************************************/
#define CTSUCHTRC2_MUTUAL6_TRANSMIT_TS   ((MUTUAL6_FUNCTION_TS16 << 0) | (MUTUAL6_FUNCTION_TS17 << 1) | \
                                          (MUTUAL6_FUNCTION_TS18 << 2) | (MUTUAL6_FUNCTION_TS19 << 3) | \
                                          (MUTUAL6_FUNCTION_TS20 << 4) | (MUTUAL6_FUNCTION_TS21 << 5) | \
                                          (MUTUAL6_FUNCTION_TS22 << 6) | (MUTUAL6_FUNCTION_TS23 << 7))

/*****    Address 000A 090Eh CTSU Channel send and receive control register 3 *****************************************/
#define CTSUCHTRC3_MUTUAL6_TRANSMIT_TS   ((MUTUAL6_FUNCTION_TS24 << 0) | (MUTUAL6_FUNCTION_TS25 << 1) | \
                                          (MUTUAL6_FUNCTION_TS26 << 2) | (MUTUAL6_FUNCTION_TS27 << 3) | \
                                          (MUTUAL6_FUNCTION_TS28 << 4) | (MUTUAL6_FUNCTION_TS29 << 5) | \
                                          (MUTUAL6_FUNCTION_TS30 << 6) | (MUTUAL6_FUNCTION_TS31 << 7))

/*****    Address 000A 090Fh CTSU Channel send and receive control register 4 *****************************************/
#define CTSUCHTRC4_MUTUAL6_TRANSMIT_TS   ((MUTUAL6_FUNCTION_TS32 << 0) | (MUTUAL6_FUNCTION_TS33 << 1) | \
                                          (MUTUAL6_FUNCTION_TS34 << 2) | (MUTUAL6_FUNCTION_TS35 << 3))

#define TRANSMISSION6_NUM                  (MUTUAL6_FUNCTION_TS00 + MUTUAL6_FUNCTION_TS01 + MUTUAL6_FUNCTION_TS02 + \
                                            MUTUAL6_FUNCTION_TS03 + MUTUAL6_FUNCTION_TS04 + MUTUAL6_FUNCTION_TS05 + \
                                            MUTUAL6_FUNCTION_TS06 + MUTUAL6_FUNCTION_TS07 + MUTUAL6_FUNCTION_TS08 + \
                                            MUTUAL6_FUNCTION_TS09 + MUTUAL6_FUNCTION_TS10 + MUTUAL6_FUNCTION_TS11 + \
                                            MUTUAL6_FUNCTION_TS12 + MUTUAL6_FUNCTION_TS13 + MUTUAL6_FUNCTION_TS14 + \
                                            MUTUAL6_FUNCTION_TS15 + MUTUAL6_FUNCTION_TS16 + MUTUAL6_FUNCTION_TS17 + \
                                            MUTUAL6_FUNCTION_TS18 + MUTUAL6_FUNCTION_TS19 + MUTUAL6_FUNCTION_TS20 + \
                                            MUTUAL6_FUNCTION_TS21 + MUTUAL6_FUNCTION_TS22 + MUTUAL6_FUNCTION_TS23 + \
                                            MUTUAL6_FUNCTION_TS24 + MUTUAL6_FUNCTION_TS25 + MUTUAL6_FUNCTION_TS26 + \
                                            MUTUAL6_FUNCTION_TS27 + MUTUAL6_FUNCTION_TS28 + MUTUAL6_FUNCTION_TS29 + \
                                            MUTUAL6_FUNCTION_TS30 + MUTUAL6_FUNCTION_TS31 + MUTUAL6_FUNCTION_TS32 + \
                                            MUTUAL6_FUNCTION_TS33 + MUTUAL6_FUNCTION_TS34 + MUTUAL6_FUNCTION_TS35)

#define RECEPTION6_NUM                     (MUTUAL6_ENABLE_NUM - TRANSMISSION6_NUM)
#define MUTUAL6_NUM                        (TRANSMISSION6_NUM * RECEPTION6_NUM)

#if TRANSMISSION6_NUM == 0
    #error "Send TS Setting error ( TRANSMISSION6_NUM = 0 )"
#endif
#if RECEPTION6_NUM == 0
    #error "Receive TS Setting error ( RECEPTION_NUM6 = 0 )"
#endif

/*****    Address 000A 0912h CTSU High-Pass Noise Reduction Spectrum Diffusion Control Register    ********************/
/**********************************************************************************************************************/
/*    CTSU Spectrum Diffusion Frequency Division Setting                                                              */
/*    Base Clock Frequency fb (MHz)   CTSUSSDIV[3:0] Bit Setting                                                      */
/*          4.00 =< fb                           0x00                                                                 */
/*          2.00 =< fb  < 4.00                   0x01                                                                 */
/*          1.33 =< fb  < 2.00                   0x02                                                                 */
/*          1.00 =< fb  < 1.33                   0x03                                                                 */
/*          0.80 =< fb  < 1.00                   0x04                                                                 */
/*          0.67 =< fb  < 0.80                   0x05                                                                 */
/*          0.57 =< fb  < 0.67                   0x06                                                                 */
/*          0.50 =< fb  < 0.57                   0x07                                                                 */
/*          0.44 =< fb  < 0.50                   0x08                                                                 */
/*          0.40 =< fb  < 0.44                   0x09                                                                 */
/*          0.36 =< fb  < 0.40                   0x0A                                                                 */
/*          0.33 =< fb  < 0.36                   0x0B                                                                 */
/*          0.31 =< fb  < 0.33                   0x0C                                                                 */
/*          0.29 =< fb  < 0.31                   0x0D                                                                 */
/*          0.27 =< fb  < 0.29                   0x0E                                                                 */
/*                  fb =< 0.25                   0x0F                                                                 */
/**********************************************************************************************************************/
#define CTSUSSDIV_MUTUAL6_KEY00         (0x01)                  /* Mutual 1 Key00 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY01         (0x01)                  /* Mutual 1 Key01 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY02         (0x01)                  /* Mutual 1 Key02 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY03         (0x01)                  /* Mutual 1 Key03 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY04         (0x01)                  /* Mutual 1 Key04 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY05         (0x01)                  /* Mutual 1 Key05 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY06         (0x01)                  /* Mutual 1 Key06 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY07         (0x01)                  /* Mutual 1 Key07 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY08         (0x01)                  /* Mutual 1 Key08 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY09         (0x01)                  /* Mutual 1 Key09 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY10         (0x01)                  /* Mutual 1 Key10 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY11         (0x01)                  /* Mutual 1 Key11 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY12         (0x01)                  /* Mutual 1 Key12 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY13         (0x01)                  /* Mutual 1 Key13 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY14         (0x01)                  /* Mutual 1 Key14 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY15         (0x01)                  /* Mutual 1 Key15 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY16         (0x01)                  /* Mutual 1 Key16 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY17         (0x01)                  /* Mutual 1 Key17 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY18         (0x01)                  /* Mutual 1 Key18 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY19         (0x01)                  /* Mutual 1 Key19 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY20         (0x01)                  /* Mutual 1 Key20 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY21         (0x01)                  /* Mutual 1 Key21 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY22         (0x01)                  /* Mutual 1 Key22 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY23         (0x01)                  /* Mutual 1 Key23 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY24         (0x01)                  /* Mutual 1 Key24 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY25         (0x01)                  /* Mutual 1 Key25 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY26         (0x01)                  /* Mutual 1 Key26 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY27         (0x01)                  /* Mutual 1 Key27 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY28         (0x01)                  /* Mutual 1 Key28 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY29         (0x01)                  /* Mutual 1 Key29 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY30         (0x01)                  /* Mutual 1 Key30 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY31         (0x01)                  /* Mutual 1 Key31 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY32         (0x01)                  /* Mutual 1 Key32 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY33         (0x01)                  /* Mutual 1 Key33 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY34         (0x01)                  /* Mutual 1 Key34 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY35         (0x01)                  /* Mutual 1 Key35 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY36         (0x01)                  /* Mutual 1 Key36 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY37         (0x01)                  /* Mutual 1 Key37 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY38         (0x01)                  /* Mutual 1 Key38 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY39         (0x01)                  /* Mutual 1 Key39 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY40         (0x01)                  /* Mutual 1 Key40 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY41         (0x01)                  /* Mutual 1 Key41 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY42         (0x01)                  /* Mutual 1 Key42 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY43         (0x01)                  /* Mutual 1 Key43 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY44         (0x01)                  /* Mutual 1 Key44 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY45         (0x01)                  /* Mutual 1 Key45 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY46         (0x01)                  /* Mutual 1 Key46 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY47         (0x01)                  /* Mutual 1 Key47 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY48         (0x01)                  /* Mutual 1 Key48 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY49         (0x01)                  /* Mutual 1 Key49 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY50         (0x01)                  /* Mutual 1 Key50 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY51         (0x01)                  /* Mutual 1 Key51 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY52         (0x01)                  /* Mutual 1 Key52 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY53         (0x01)                  /* Mutual 1 Key53 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY54         (0x01)                  /* Mutual 1 Key54 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY55         (0x01)                  /* Mutual 1 Key55 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY56         (0x01)                  /* Mutual 1 Key56 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY57         (0x01)                  /* Mutual 1 Key57 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY58         (0x01)                  /* Mutual 1 Key58 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY59         (0x01)                  /* Mutual 1 Key59 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY60         (0x01)                  /* Mutual 1 Key60 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY61         (0x01)                  /* Mutual 1 Key61 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY62         (0x01)                  /* Mutual 1 Key62 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL6_KEY63         (0x01)                  /* Mutual 1 Key63 CTSUSDIV                            */

#define CTSUSSC_MUTUAL6_KEY00           (CTSUSSDIV_MUTUAL6_KEY00 << 8)
#define CTSUSSC_MUTUAL6_KEY01           (CTSUSSDIV_MUTUAL6_KEY01 << 8)
#define CTSUSSC_MUTUAL6_KEY02           (CTSUSSDIV_MUTUAL6_KEY02 << 8)
#define CTSUSSC_MUTUAL6_KEY03           (CTSUSSDIV_MUTUAL6_KEY03 << 8)
#define CTSUSSC_MUTUAL6_KEY04           (CTSUSSDIV_MUTUAL6_KEY04 << 8)
#define CTSUSSC_MUTUAL6_KEY05           (CTSUSSDIV_MUTUAL6_KEY05 << 8)
#define CTSUSSC_MUTUAL6_KEY06           (CTSUSSDIV_MUTUAL6_KEY06 << 8)
#define CTSUSSC_MUTUAL6_KEY07           (CTSUSSDIV_MUTUAL6_KEY07 << 8)
#define CTSUSSC_MUTUAL6_KEY08           (CTSUSSDIV_MUTUAL6_KEY08 << 8)
#define CTSUSSC_MUTUAL6_KEY09           (CTSUSSDIV_MUTUAL6_KEY09 << 8)
#define CTSUSSC_MUTUAL6_KEY10           (CTSUSSDIV_MUTUAL6_KEY10 << 8)
#define CTSUSSC_MUTUAL6_KEY11           (CTSUSSDIV_MUTUAL6_KEY11 << 8)
#define CTSUSSC_MUTUAL6_KEY12           (CTSUSSDIV_MUTUAL6_KEY12 << 8)
#define CTSUSSC_MUTUAL6_KEY13           (CTSUSSDIV_MUTUAL6_KEY13 << 8)
#define CTSUSSC_MUTUAL6_KEY14           (CTSUSSDIV_MUTUAL6_KEY14 << 8)
#define CTSUSSC_MUTUAL6_KEY15           (CTSUSSDIV_MUTUAL6_KEY15 << 8)
#define CTSUSSC_MUTUAL6_KEY16           (CTSUSSDIV_MUTUAL6_KEY16 << 8)
#define CTSUSSC_MUTUAL6_KEY17           (CTSUSSDIV_MUTUAL6_KEY17 << 8)
#define CTSUSSC_MUTUAL6_KEY18           (CTSUSSDIV_MUTUAL6_KEY18 << 8)
#define CTSUSSC_MUTUAL6_KEY19           (CTSUSSDIV_MUTUAL6_KEY19 << 8)
#define CTSUSSC_MUTUAL6_KEY20           (CTSUSSDIV_MUTUAL6_KEY20 << 8)
#define CTSUSSC_MUTUAL6_KEY21           (CTSUSSDIV_MUTUAL6_KEY21 << 8)
#define CTSUSSC_MUTUAL6_KEY22           (CTSUSSDIV_MUTUAL6_KEY22 << 8)
#define CTSUSSC_MUTUAL6_KEY23           (CTSUSSDIV_MUTUAL6_KEY23 << 8)
#define CTSUSSC_MUTUAL6_KEY24           (CTSUSSDIV_MUTUAL6_KEY24 << 8)
#define CTSUSSC_MUTUAL6_KEY25           (CTSUSSDIV_MUTUAL6_KEY25 << 8)
#define CTSUSSC_MUTUAL6_KEY26           (CTSUSSDIV_MUTUAL6_KEY26 << 8)
#define CTSUSSC_MUTUAL6_KEY27           (CTSUSSDIV_MUTUAL6_KEY27 << 8)
#define CTSUSSC_MUTUAL6_KEY28           (CTSUSSDIV_MUTUAL6_KEY28 << 8)
#define CTSUSSC_MUTUAL6_KEY29           (CTSUSSDIV_MUTUAL6_KEY29 << 8)
#define CTSUSSC_MUTUAL6_KEY30           (CTSUSSDIV_MUTUAL6_KEY30 << 8)
#define CTSUSSC_MUTUAL6_KEY31           (CTSUSSDIV_MUTUAL6_KEY31 << 8)
#define CTSUSSC_MUTUAL6_KEY32           (CTSUSSDIV_MUTUAL6_KEY32 << 8)
#define CTSUSSC_MUTUAL6_KEY33           (CTSUSSDIV_MUTUAL6_KEY33 << 8)
#define CTSUSSC_MUTUAL6_KEY34           (CTSUSSDIV_MUTUAL6_KEY34 << 8)
#define CTSUSSC_MUTUAL6_KEY35           (CTSUSSDIV_MUTUAL6_KEY35 << 8)
#define CTSUSSC_MUTUAL6_KEY36           (CTSUSSDIV_MUTUAL6_KEY36 << 8)
#define CTSUSSC_MUTUAL6_KEY37           (CTSUSSDIV_MUTUAL6_KEY37 << 8)
#define CTSUSSC_MUTUAL6_KEY38           (CTSUSSDIV_MUTUAL6_KEY38 << 8)
#define CTSUSSC_MUTUAL6_KEY39           (CTSUSSDIV_MUTUAL6_KEY39 << 8)
#define CTSUSSC_MUTUAL6_KEY40           (CTSUSSDIV_MUTUAL6_KEY40 << 8)
#define CTSUSSC_MUTUAL6_KEY41           (CTSUSSDIV_MUTUAL6_KEY41 << 8)
#define CTSUSSC_MUTUAL6_KEY42           (CTSUSSDIV_MUTUAL6_KEY42 << 8)
#define CTSUSSC_MUTUAL6_KEY43           (CTSUSSDIV_MUTUAL6_KEY43 << 8)
#define CTSUSSC_MUTUAL6_KEY44           (CTSUSSDIV_MUTUAL6_KEY44 << 8)
#define CTSUSSC_MUTUAL6_KEY45           (CTSUSSDIV_MUTUAL6_KEY45 << 8)
#define CTSUSSC_MUTUAL6_KEY46           (CTSUSSDIV_MUTUAL6_KEY46 << 8)
#define CTSUSSC_MUTUAL6_KEY47           (CTSUSSDIV_MUTUAL6_KEY47 << 8)
#define CTSUSSC_MUTUAL6_KEY48           (CTSUSSDIV_MUTUAL6_KEY48 << 8)
#define CTSUSSC_MUTUAL6_KEY49           (CTSUSSDIV_MUTUAL6_KEY49 << 8)
#define CTSUSSC_MUTUAL6_KEY50           (CTSUSSDIV_MUTUAL6_KEY50 << 8)
#define CTSUSSC_MUTUAL6_KEY51           (CTSUSSDIV_MUTUAL6_KEY51 << 8)
#define CTSUSSC_MUTUAL6_KEY52           (CTSUSSDIV_MUTUAL6_KEY52 << 8)
#define CTSUSSC_MUTUAL6_KEY53           (CTSUSSDIV_MUTUAL6_KEY53 << 8)
#define CTSUSSC_MUTUAL6_KEY54           (CTSUSSDIV_MUTUAL6_KEY54 << 8)
#define CTSUSSC_MUTUAL6_KEY55           (CTSUSSDIV_MUTUAL6_KEY55 << 8)
#define CTSUSSC_MUTUAL6_KEY56           (CTSUSSDIV_MUTUAL6_KEY56 << 8)
#define CTSUSSC_MUTUAL6_KEY57           (CTSUSSDIV_MUTUAL6_KEY57 << 8)
#define CTSUSSC_MUTUAL6_KEY58           (CTSUSSDIV_MUTUAL6_KEY58 << 8)
#define CTSUSSC_MUTUAL6_KEY59           (CTSUSSDIV_MUTUAL6_KEY59 << 8)
#define CTSUSSC_MUTUAL6_KEY60           (CTSUSSDIV_MUTUAL6_KEY60 << 8)
#define CTSUSSC_MUTUAL6_KEY61           (CTSUSSDIV_MUTUAL6_KEY61 << 8)
#define CTSUSSC_MUTUAL6_KEY62           (CTSUSSDIV_MUTUAL6_KEY62 << 8)
#define CTSUSSC_MUTUAL6_KEY63           (CTSUSSDIV_MUTUAL6_KEY63 << 8)

/*****    Address 000A 0914h CTSU Sensor Offset Register 0     ********************************************************/
/**********************************************************************************************************************/
/*    CTSU Sensor Offset Adjustment                                                                                   */
/*      Current offset amount is 0       0x000                                                                        */
/*      Current offset amount is 1       0x001                                                                        */
/*      Current offset amount is 2       0x002                                                                        */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*      Current offset amount is 1023    0x3FF                                                                        */
/**********************************************************************************************************************/
#define CTSUSO_MUTUAL6_KEY00            (0x000)                 /* Mutual 1 Key00 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY01            (0x000)                 /* Mutual 1 Key01 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY02            (0x000)                 /* Mutual 1 Key02 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY03            (0x000)                 /* Mutual 1 Key03 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY04            (0x000)                 /* Mutual 1 Key04 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY05            (0x000)                 /* Mutual 1 Key05 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY06            (0x000)                 /* Mutual 1 Key06 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY07            (0x000)                 /* Mutual 1 Key07 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY08            (0x000)                 /* Mutual 1 Key08 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY09            (0x000)                 /* Mutual 1 Key09 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY10            (0x000)                 /* Mutual 1 Key10 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY11            (0x000)                 /* Mutual 1 Key11 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY12            (0x000)                 /* Mutual 1 Key12 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY13            (0x000)                 /* Mutual 1 Key13 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY14            (0x000)                 /* Mutual 1 Key14 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY15            (0x000)                 /* Mutual 1 Key15 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY16            (0x000)                 /* Mutual 1 Key16 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY17            (0x000)                 /* Mutual 1 Key17 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY18            (0x000)                 /* Mutual 1 Key18 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY19            (0x000)                 /* Mutual 1 Key19 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY20            (0x000)                 /* Mutual 1 Key20 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY21            (0x000)                 /* Mutual 1 Key21 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY22            (0x000)                 /* Mutual 1 Key22 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY23            (0x000)                 /* Mutual 1 Key23 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY24            (0x000)                 /* Mutual 1 Key24 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY25            (0x000)                 /* Mutual 1 Key25 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY26            (0x000)                 /* Mutual 1 Key26 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY27            (0x000)                 /* Mutual 1 Key27 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY28            (0x000)                 /* Mutual 1 Key28 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY29            (0x000)                 /* Mutual 1 Key29 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY30            (0x000)                 /* Mutual 1 Key30 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY31            (0x000)                 /* Mutual 1 Key31 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY32            (0x000)                 /* Mutual 1 Key32 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY33            (0x000)                 /* Mutual 1 Key33 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY34            (0x000)                 /* Mutual 1 Key34 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY35            (0x000)                 /* Mutual 1 Key35 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY36            (0x000)                 /* Mutual 1 Key36 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY37            (0x000)                 /* Mutual 1 Key37 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY38            (0x000)                 /* Mutual 1 Key38 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY39            (0x000)                 /* Mutual 1 Key39 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY40            (0x000)                 /* Mutual 1 Key40 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY41            (0x000)                 /* Mutual 1 Key41 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY42            (0x000)                 /* Mutual 1 Key42 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY43            (0x000)                 /* Mutual 1 Key43 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY44            (0x000)                 /* Mutual 1 Key44 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY45            (0x000)                 /* Mutual 1 Key45 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY46            (0x000)                 /* Mutual 1 Key46 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY47            (0x000)                 /* Mutual 1 Key47 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY48            (0x000)                 /* Mutual 1 Key48 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY49            (0x000)                 /* Mutual 1 Key49 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY50            (0x000)                 /* Mutual 1 Key50 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY51            (0x000)                 /* Mutual 1 Key51 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY52            (0x000)                 /* Mutual 1 Key52 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY53            (0x000)                 /* Mutual 1 Key53 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY54            (0x000)                 /* Mutual 1 Key54 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY55            (0x000)                 /* Mutual 1 Key55 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY56            (0x000)                 /* Mutual 1 Key56 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY57            (0x000)                 /* Mutual 1 Key57 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY58            (0x000)                 /* Mutual 1 Key58 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY59            (0x000)                 /* Mutual 1 Key59 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY60            (0x000)                 /* Mutual 1 Key60 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY61            (0x000)                 /* Mutual 1 Key61 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY62            (0x000)                 /* Mutual 1 Key62 CTSUSO                              */
#define CTSUSO_MUTUAL6_KEY63            (0x000)                 /* Mutual 1 Key63 CTSUSO                              */

/**********************************************************************************************************************/
/*    CTSU Measurement Count Setting                                                                                  */
/*      4.0MHz    7                                                                                                   */
/*      2.0MHz    3                                                                                                   */
/*      1.0MHz    1                                                                                                   */
/*      0.5MHz    0                                                                                                   */
/**********************************************************************************************************************/
#define CTSUSNUM_MUTUAL6_KEY00          (3)                     /* Mutual 1 Key00 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY01          (3)                     /* Mutual 1 Key01 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY02          (3)                     /* Mutual 1 Key02 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY03          (3)                     /* Mutual 1 Key03 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY04          (3)                     /* Mutual 1 Key04 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY05          (3)                     /* Mutual 1 Key05 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY06          (3)                     /* Mutual 1 Key06 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY07          (3)                     /* Mutual 1 Key07 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY08          (3)                     /* Mutual 1 Key08 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY09          (3)                     /* Mutual 1 Key09 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY10          (3)                     /* Mutual 1 Key10 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY11          (3)                     /* Mutual 1 Key11 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY12          (3)                     /* Mutual 1 Key12 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY13          (3)                     /* Mutual 1 Key13 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY14          (3)                     /* Mutual 1 Key14 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY15          (3)                     /* Mutual 1 Key15 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY16          (3)                     /* Mutual 1 Key16 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY17          (3)                     /* Mutual 1 Key17 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY18          (3)                     /* Mutual 1 Key18 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY19          (3)                     /* Mutual 1 Key19 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY20          (3)                     /* Mutual 1 Key20 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY21          (3)                     /* Mutual 1 Key21 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY22          (3)                     /* Mutual 1 Key22 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY23          (3)                     /* Mutual 1 Key23 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY24          (3)                     /* Mutual 1 Key24 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY25          (3)                     /* Mutual 1 Key25 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY26          (3)                     /* Mutual 1 Key26 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY27          (3)                     /* Mutual 1 Key27 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY28          (3)                     /* Mutual 1 Key28 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY29          (3)                     /* Mutual 1 Key29 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY30          (3)                     /* Mutual 1 Key30 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY31          (3)                     /* Mutual 1 Key31 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY32          (3)                     /* Mutual 1 Key32 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY33          (3)                     /* Mutual 1 Key33 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY34          (3)                     /* Mutual 1 Key34 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY35          (3)                     /* Mutual 1 Key35 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY36          (3)                     /* Mutual 1 Key36 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY37          (3)                     /* Mutual 1 Key37 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY38          (3)                     /* Mutual 1 Key38 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY39          (3)                     /* Mutual 1 Key39 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY40          (3)                     /* Mutual 1 Key40 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY41          (3)                     /* Mutual 1 Key41 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY42          (3)                     /* Mutual 1 Key42 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY43          (3)                     /* Mutual 1 Key43 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY44          (3)                     /* Mutual 1 Key44 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY45          (3)                     /* Mutual 1 Key45 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY46          (3)                     /* Mutual 1 Key46 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY47          (3)                     /* Mutual 1 Key47 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY48          (3)                     /* Mutual 1 Key48 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY49          (3)                     /* Mutual 1 Key49 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY50          (3)                     /* Mutual 1 Key50 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY51          (3)                     /* Mutual 1 Key51 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY52          (3)                     /* Mutual 1 Key52 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY53          (3)                     /* Mutual 1 Key53 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY54          (3)                     /* Mutual 1 Key54 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY55          (3)                     /* Mutual 1 Key55 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY56          (3)                     /* Mutual 1 Key56 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY57          (3)                     /* Mutual 1 Key57 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY58          (3)                     /* Mutual 1 Key58 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY59          (3)                     /* Mutual 1 Key59 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY60          (3)                     /* Mutual 1 Key60 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY61          (3)                     /* Mutual 1 Key61 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY62          (3)                     /* Mutual 1 Key62 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL6_KEY63          (3)                     /* Mutual 1 Key63 CTSUSNUM                            */

#define CTSUSO0_MUTUAL6_KEY00           ((CTSUSNUM_MUTUAL6_KEY00 << 10) | CTSUSO_MUTUAL6_KEY00)
#define CTSUSO0_MUTUAL6_KEY01           ((CTSUSNUM_MUTUAL6_KEY01 << 10) | CTSUSO_MUTUAL6_KEY01)
#define CTSUSO0_MUTUAL6_KEY02           ((CTSUSNUM_MUTUAL6_KEY02 << 10) | CTSUSO_MUTUAL6_KEY02)
#define CTSUSO0_MUTUAL6_KEY03           ((CTSUSNUM_MUTUAL6_KEY03 << 10) | CTSUSO_MUTUAL6_KEY03)
#define CTSUSO0_MUTUAL6_KEY04           ((CTSUSNUM_MUTUAL6_KEY04 << 10) | CTSUSO_MUTUAL6_KEY04)
#define CTSUSO0_MUTUAL6_KEY05           ((CTSUSNUM_MUTUAL6_KEY05 << 10) | CTSUSO_MUTUAL6_KEY05)
#define CTSUSO0_MUTUAL6_KEY06           ((CTSUSNUM_MUTUAL6_KEY06 << 10) | CTSUSO_MUTUAL6_KEY06)
#define CTSUSO0_MUTUAL6_KEY07           ((CTSUSNUM_MUTUAL6_KEY07 << 10) | CTSUSO_MUTUAL6_KEY07)
#define CTSUSO0_MUTUAL6_KEY08           ((CTSUSNUM_MUTUAL6_KEY08 << 10) | CTSUSO_MUTUAL6_KEY08)
#define CTSUSO0_MUTUAL6_KEY09           ((CTSUSNUM_MUTUAL6_KEY09 << 10) | CTSUSO_MUTUAL6_KEY09)
#define CTSUSO0_MUTUAL6_KEY10           ((CTSUSNUM_MUTUAL6_KEY10 << 10) | CTSUSO_MUTUAL6_KEY10)
#define CTSUSO0_MUTUAL6_KEY11           ((CTSUSNUM_MUTUAL6_KEY11 << 10) | CTSUSO_MUTUAL6_KEY11)
#define CTSUSO0_MUTUAL6_KEY12           ((CTSUSNUM_MUTUAL6_KEY12 << 10) | CTSUSO_MUTUAL6_KEY12)
#define CTSUSO0_MUTUAL6_KEY13           ((CTSUSNUM_MUTUAL6_KEY13 << 10) | CTSUSO_MUTUAL6_KEY13)
#define CTSUSO0_MUTUAL6_KEY14           ((CTSUSNUM_MUTUAL6_KEY14 << 10) | CTSUSO_MUTUAL6_KEY14)
#define CTSUSO0_MUTUAL6_KEY15           ((CTSUSNUM_MUTUAL6_KEY15 << 10) | CTSUSO_MUTUAL6_KEY15)
#define CTSUSO0_MUTUAL6_KEY16           ((CTSUSNUM_MUTUAL6_KEY16 << 10) | CTSUSO_MUTUAL6_KEY16)
#define CTSUSO0_MUTUAL6_KEY17           ((CTSUSNUM_MUTUAL6_KEY17 << 10) | CTSUSO_MUTUAL6_KEY17)
#define CTSUSO0_MUTUAL6_KEY18           ((CTSUSNUM_MUTUAL6_KEY18 << 10) | CTSUSO_MUTUAL6_KEY18)
#define CTSUSO0_MUTUAL6_KEY19           ((CTSUSNUM_MUTUAL6_KEY19 << 10) | CTSUSO_MUTUAL6_KEY19)
#define CTSUSO0_MUTUAL6_KEY20           ((CTSUSNUM_MUTUAL6_KEY20 << 10) | CTSUSO_MUTUAL6_KEY20)
#define CTSUSO0_MUTUAL6_KEY21           ((CTSUSNUM_MUTUAL6_KEY21 << 10) | CTSUSO_MUTUAL6_KEY21)
#define CTSUSO0_MUTUAL6_KEY22           ((CTSUSNUM_MUTUAL6_KEY22 << 10) | CTSUSO_MUTUAL6_KEY22)
#define CTSUSO0_MUTUAL6_KEY23           ((CTSUSNUM_MUTUAL6_KEY23 << 10) | CTSUSO_MUTUAL6_KEY23)
#define CTSUSO0_MUTUAL6_KEY24           ((CTSUSNUM_MUTUAL6_KEY24 << 10) | CTSUSO_MUTUAL6_KEY24)
#define CTSUSO0_MUTUAL6_KEY25           ((CTSUSNUM_MUTUAL6_KEY25 << 10) | CTSUSO_MUTUAL6_KEY25)
#define CTSUSO0_MUTUAL6_KEY26           ((CTSUSNUM_MUTUAL6_KEY26 << 10) | CTSUSO_MUTUAL6_KEY26)
#define CTSUSO0_MUTUAL6_KEY27           ((CTSUSNUM_MUTUAL6_KEY27 << 10) | CTSUSO_MUTUAL6_KEY27)
#define CTSUSO0_MUTUAL6_KEY28           ((CTSUSNUM_MUTUAL6_KEY28 << 10) | CTSUSO_MUTUAL6_KEY28)
#define CTSUSO0_MUTUAL6_KEY29           ((CTSUSNUM_MUTUAL6_KEY29 << 10) | CTSUSO_MUTUAL6_KEY29)
#define CTSUSO0_MUTUAL6_KEY30           ((CTSUSNUM_MUTUAL6_KEY30 << 10) | CTSUSO_MUTUAL6_KEY30)
#define CTSUSO0_MUTUAL6_KEY31           ((CTSUSNUM_MUTUAL6_KEY31 << 10) | CTSUSO_MUTUAL6_KEY31)
#define CTSUSO0_MUTUAL6_KEY32           ((CTSUSNUM_MUTUAL6_KEY32 << 10) | CTSUSO_MUTUAL6_KEY32)
#define CTSUSO0_MUTUAL6_KEY33           ((CTSUSNUM_MUTUAL6_KEY33 << 10) | CTSUSO_MUTUAL6_KEY33)
#define CTSUSO0_MUTUAL6_KEY34           ((CTSUSNUM_MUTUAL6_KEY34 << 10) | CTSUSO_MUTUAL6_KEY34)
#define CTSUSO0_MUTUAL6_KEY35           ((CTSUSNUM_MUTUAL6_KEY35 << 10) | CTSUSO_MUTUAL6_KEY35)
#define CTSUSO0_MUTUAL6_KEY36           ((CTSUSNUM_MUTUAL6_KEY36 << 10) | CTSUSO_MUTUAL6_KEY36)
#define CTSUSO0_MUTUAL6_KEY37           ((CTSUSNUM_MUTUAL6_KEY37 << 10) | CTSUSO_MUTUAL6_KEY37)
#define CTSUSO0_MUTUAL6_KEY38           ((CTSUSNUM_MUTUAL6_KEY38 << 10) | CTSUSO_MUTUAL6_KEY38)
#define CTSUSO0_MUTUAL6_KEY39           ((CTSUSNUM_MUTUAL6_KEY39 << 10) | CTSUSO_MUTUAL6_KEY39)
#define CTSUSO0_MUTUAL6_KEY40           ((CTSUSNUM_MUTUAL6_KEY40 << 10) | CTSUSO_MUTUAL6_KEY40)
#define CTSUSO0_MUTUAL6_KEY41           ((CTSUSNUM_MUTUAL6_KEY41 << 10) | CTSUSO_MUTUAL6_KEY41)
#define CTSUSO0_MUTUAL6_KEY42           ((CTSUSNUM_MUTUAL6_KEY42 << 10) | CTSUSO_MUTUAL6_KEY42)
#define CTSUSO0_MUTUAL6_KEY43           ((CTSUSNUM_MUTUAL6_KEY43 << 10) | CTSUSO_MUTUAL6_KEY43)
#define CTSUSO0_MUTUAL6_KEY44           ((CTSUSNUM_MUTUAL6_KEY44 << 10) | CTSUSO_MUTUAL6_KEY44)
#define CTSUSO0_MUTUAL6_KEY45           ((CTSUSNUM_MUTUAL6_KEY45 << 10) | CTSUSO_MUTUAL6_KEY45)
#define CTSUSO0_MUTUAL6_KEY46           ((CTSUSNUM_MUTUAL6_KEY46 << 10) | CTSUSO_MUTUAL6_KEY46)
#define CTSUSO0_MUTUAL6_KEY47           ((CTSUSNUM_MUTUAL6_KEY47 << 10) | CTSUSO_MUTUAL6_KEY47)
#define CTSUSO0_MUTUAL6_KEY48           ((CTSUSNUM_MUTUAL6_KEY48 << 10) | CTSUSO_MUTUAL6_KEY48)
#define CTSUSO0_MUTUAL6_KEY49           ((CTSUSNUM_MUTUAL6_KEY49 << 10) | CTSUSO_MUTUAL6_KEY49)
#define CTSUSO0_MUTUAL6_KEY50           ((CTSUSNUM_MUTUAL6_KEY50 << 10) | CTSUSO_MUTUAL6_KEY50)
#define CTSUSO0_MUTUAL6_KEY51           ((CTSUSNUM_MUTUAL6_KEY51 << 10) | CTSUSO_MUTUAL6_KEY51)
#define CTSUSO0_MUTUAL6_KEY52           ((CTSUSNUM_MUTUAL6_KEY52 << 10) | CTSUSO_MUTUAL6_KEY52)
#define CTSUSO0_MUTUAL6_KEY53           ((CTSUSNUM_MUTUAL6_KEY53 << 10) | CTSUSO_MUTUAL6_KEY53)
#define CTSUSO0_MUTUAL6_KEY54           ((CTSUSNUM_MUTUAL6_KEY54 << 10) | CTSUSO_MUTUAL6_KEY54)
#define CTSUSO0_MUTUAL6_KEY55           ((CTSUSNUM_MUTUAL6_KEY55 << 10) | CTSUSO_MUTUAL6_KEY55)
#define CTSUSO0_MUTUAL6_KEY56           ((CTSUSNUM_MUTUAL6_KEY56 << 10) | CTSUSO_MUTUAL6_KEY56)
#define CTSUSO0_MUTUAL6_KEY57           ((CTSUSNUM_MUTUAL6_KEY57 << 10) | CTSUSO_MUTUAL6_KEY57)
#define CTSUSO0_MUTUAL6_KEY58           ((CTSUSNUM_MUTUAL6_KEY58 << 10) | CTSUSO_MUTUAL6_KEY58)
#define CTSUSO0_MUTUAL6_KEY59           ((CTSUSNUM_MUTUAL6_KEY59 << 10) | CTSUSO_MUTUAL6_KEY59)
#define CTSUSO0_MUTUAL6_KEY60           ((CTSUSNUM_MUTUAL6_KEY60 << 10) | CTSUSO_MUTUAL6_KEY60)
#define CTSUSO0_MUTUAL6_KEY61           ((CTSUSNUM_MUTUAL6_KEY61 << 10) | CTSUSO_MUTUAL6_KEY61)
#define CTSUSO0_MUTUAL6_KEY62           ((CTSUSNUM_MUTUAL6_KEY62 << 10) | CTSUSO_MUTUAL6_KEY62)
#define CTSUSO0_MUTUAL6_KEY63           ((CTSUSNUM_MUTUAL6_KEY63 << 10) | CTSUSO_MUTUAL6_KEY63)

/*****    Address 000A 0914h CTSU Sensor Offset Register 1    *********************************************************/
/**********************************************************************************************************************/
/*    CTSU Reference ICO Current Adjustment                                                                           */
/*        Input current amount 0      0x00                                                                            */
/*        Input current amount 1      0x01                                                                            */
/*        Input current amount 2      0x02                                                                            */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*        Input current amount 254    0xFF                                                                            */
/**********************************************************************************************************************/
#define CTSURICOA_MUTUAL6_KEY00         (0x3F)                  /* Mutual 1 Key00 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY01         (0x3F)                  /* Mutual 1 Key01 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY02         (0x3F)                  /* Mutual 1 Key02 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY03         (0x3F)                  /* Mutual 1 Key03 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY04         (0x3F)                  /* Mutual 1 Key04 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY05         (0x3F)                  /* Mutual 1 Key05 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY06         (0x3F)                  /* Mutual 1 Key06 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY07         (0x3F)                  /* Mutual 1 Key07 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY08         (0x3F)                  /* Mutual 1 Key08 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY09         (0x3F)                  /* Mutual 1 Key09 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY10         (0x3F)                  /* Mutual 1 Key10 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY11         (0x3F)                  /* Mutual 1 Key11 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY12         (0x3F)                  /* Mutual 1 Key12 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY13         (0x3F)                  /* Mutual 1 Key13 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY14         (0x3F)                  /* Mutual 1 Key14 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY15         (0x3F)                  /* Mutual 1 Key15 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY16         (0x3F)                  /* Mutual 1 Key16 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY17         (0x3F)                  /* Mutual 1 Key17 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY18         (0x3F)                  /* Mutual 1 Key18 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY19         (0x3F)                  /* Mutual 1 Key19 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY20         (0x3F)                  /* Mutual 1 Key20 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY21         (0x3F)                  /* Mutual 1 Key21 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY22         (0x3F)                  /* Mutual 1 Key22 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY23         (0x3F)                  /* Mutual 1 Key23 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY24         (0x3F)                  /* Mutual 1 Key24 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY25         (0x3F)                  /* Mutual 1 Key25 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY26         (0x3F)                  /* Mutual 1 Key26 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY27         (0x3F)                  /* Mutual 1 Key27 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY28         (0x3F)                  /* Mutual 1 Key28 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY29         (0x3F)                  /* Mutual 1 Key29 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY30         (0x3F)                  /* Mutual 1 Key30 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY31         (0x3F)                  /* Mutual 1 Key31 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY32         (0x3F)                  /* Mutual 1 Key32 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY33         (0x3F)                  /* Mutual 1 Key33 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY34         (0x3F)                  /* Mutual 1 Key34 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY35         (0x3F)                  /* Mutual 1 Key35 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY36         (0x3F)                  /* Mutual 1 Key36 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY37         (0x3F)                  /* Mutual 1 Key37 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY38         (0x3F)                  /* Mutual 1 Key38 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY39         (0x3F)                  /* Mutual 1 Key39 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY40         (0x3F)                  /* Mutual 1 Key40 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY41         (0x3F)                  /* Mutual 1 Key41 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY42         (0x3F)                  /* Mutual 1 Key42 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY43         (0x3F)                  /* Mutual 1 Key43 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY44         (0x3F)                  /* Mutual 1 Key44 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY45         (0x3F)                  /* Mutual 1 Key45 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY46         (0x3F)                  /* Mutual 1 Key46 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY47         (0x3F)                  /* Mutual 1 Key47 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY48         (0x3F)                  /* Mutual 1 Key48 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY49         (0x3F)                  /* Mutual 1 Key49 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY50         (0x3F)                  /* Mutual 1 Key50 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY51         (0x3F)                  /* Mutual 1 Key51 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY52         (0x3F)                  /* Mutual 1 Key52 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY53         (0x3F)                  /* Mutual 1 Key53 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY54         (0x3F)                  /* Mutual 1 Key54 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY55         (0x3F)                  /* Mutual 1 Key55 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY56         (0x3F)                  /* Mutual 1 Key56 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY57         (0x3F)                  /* Mutual 1 Key57 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY58         (0x3F)                  /* Mutual 1 Key58 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY59         (0x3F)                  /* Mutual 1 Key59 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY60         (0x3F)                  /* Mutual 1 Key60 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY61         (0x3F)                  /* Mutual 1 Key61 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY62         (0x3F)                  /* Mutual 1 Key62 CTSUICOA                            */
#define CTSURICOA_MUTUAL6_KEY63         (0x3F)                  /* Mutual 1 Key63 CTSUICOA                            */

/**********************************************************************************************************************/
/*    CTSU Base Clock Setting                                                                                         */
/*        Operating clock divided by 2     0x00                                                                       */
/*        Operating clock divided by 4     0x01                                                                       */
/*        Operating clock divided by 6     0x02                                                                       */
/*                       :                                                                                            */
/*                       :                                                                                            */
/*        Operating clock divided by 64    0x1F                                                                       */
/*                                                                                                                    */
/*    Case : CTSU Operating Clock 32MHz      Case : CTSU Operating Clock 24MHz      Case : CTSU Operating Clock 16MHz */
/*           4.0MHz <--- 0x03                       4.0MHz <--- 0x02                       4.0MHz <--- 0x01           */
/*           2.0MHz <--- 0x07                       2.0MHz <--- 0x05                       2.0MHz <--- 0x03           */
/*           1.0MHz <--- 0x0F                       1.0MHz <--- 0x0B                       1.0MHz <--- 0x07           */
/*           0.5MHz <--- 0x1F                       0.5MHz <--- 0x17                       0.5MHz <--- 0x0F           */
/**********************************************************************************************************************/
#define CTSUSDPA_MUTUAL6_KEY00          (7)                     /* Mutual 1 Key00 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY01          (7)                     /* Mutual 1 Key01 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY02          (7)                     /* Mutual 1 Key02 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY03          (7)                     /* Mutual 1 Key03 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY04          (7)                     /* Mutual 1 Key04 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY05          (7)                     /* Mutual 1 Key05 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY06          (7)                     /* Mutual 1 Key06 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY07          (7)                     /* Mutual 1 Key07 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY08          (7)                     /* Mutual 1 Key08 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY09          (7)                     /* Mutual 1 Key09 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY10          (7)                     /* Mutual 1 Key10 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY11          (7)                     /* Mutual 1 Key11 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY12          (7)                     /* Mutual 1 Key12 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY13          (7)                     /* Mutual 1 Key13 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY14          (7)                     /* Mutual 1 Key14 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY15          (7)                     /* Mutual 1 Key15 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY16          (7)                     /* Mutual 1 Key16 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY17          (7)                     /* Mutual 1 Key17 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY18          (7)                     /* Mutual 1 Key18 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY19          (7)                     /* Mutual 1 Key19 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY20          (7)                     /* Mutual 1 Key20 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY21          (7)                     /* Mutual 1 Key21 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY22          (7)                     /* Mutual 1 Key22 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY23          (7)                     /* Mutual 1 Key23 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY24          (7)                     /* Mutual 1 Key24 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY25          (7)                     /* Mutual 1 Key25 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY26          (7)                     /* Mutual 1 Key26 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY27          (7)                     /* Mutual 1 Key27 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY28          (7)                     /* Mutual 1 Key28 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY29          (7)                     /* Mutual 1 Key29 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY30          (7)                     /* Mutual 1 Key30 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY31          (7)                     /* Mutual 1 Key31 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY32          (7)                     /* Mutual 1 Key32 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY33          (7)                     /* Mutual 1 Key33 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY34          (7)                     /* Mutual 1 Key34 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY35          (7)                     /* Mutual 1 Key35 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY36          (7)                     /* Mutual 1 Key36 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY37          (7)                     /* Mutual 1 Key37 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY38          (7)                     /* Mutual 1 Key38 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY39          (7)                     /* Mutual 1 Key39 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY40          (7)                     /* Mutual 1 Key40 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY41          (7)                     /* Mutual 1 Key41 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY42          (7)                     /* Mutual 1 Key42 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY43          (7)                     /* Mutual 1 Key43 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY44          (7)                     /* Mutual 1 Key44 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY45          (7)                     /* Mutual 1 Key45 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY46          (7)                     /* Mutual 1 Key46 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY47          (7)                     /* Mutual 1 Key47 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY48          (7)                     /* Mutual 1 Key48 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY49          (7)                     /* Mutual 1 Key49 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY50          (7)                     /* Mutual 1 Key50 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY51          (7)                     /* Mutual 1 Key51 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY52          (7)                     /* Mutual 1 Key52 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY53          (7)                     /* Mutual 1 Key53 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY54          (7)                     /* Mutual 1 Key54 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY55          (7)                     /* Mutual 1 Key55 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY56          (7)                     /* Mutual 1 Key56 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY57          (7)                     /* Mutual 1 Key57 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY58          (7)                     /* Mutual 1 Key58 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY59          (7)                     /* Mutual 1 Key59 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY60          (7)                     /* Mutual 1 Key60 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY61          (7)                     /* Mutual 1 Key61 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY62          (7)                     /* Mutual 1 Key62 CTSUDPA                             */
#define CTSUSDPA_MUTUAL6_KEY63          (7)                     /* Mutual 1 Key63 CTSUDPA                             */

/**********************************************************************************************************************/
/*    CTSU ICO Gain Adjustment                                                                                        */
/*        0 : 100% gain                                                                                               */
/*        1 :  66% gain                                                                                               */
/*        2 :  50% gain                                                                                               */
/*        3 :  40% gain                                                                                               */
/**********************************************************************************************************************/
#define CTSUICOG_MUTUAL6_KEY00          (1)                     /* Mutual 1 Key00 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY01          (1)                     /* Mutual 1 Key01 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY02          (1)                     /* Mutual 1 Key02 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY03          (1)                     /* Mutual 1 Key03 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY04          (1)                     /* Mutual 1 Key04 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY05          (1)                     /* Mutual 1 Key05 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY06          (1)                     /* Mutual 1 Key06 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY07          (1)                     /* Mutual 1 Key07 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY08          (1)                     /* Mutual 1 Key08 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY09          (1)                     /* Mutual 1 Key09 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY10          (1)                     /* Mutual 1 Key10 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY11          (1)                     /* Mutual 1 Key11 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY12          (1)                     /* Mutual 1 Key12 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY13          (1)                     /* Mutual 1 Key13 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY14          (1)                     /* Mutual 1 Key14 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY15          (1)                     /* Mutual 1 Key15 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY16          (1)                     /* Mutual 1 Key16 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY17          (1)                     /* Mutual 1 Key17 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY18          (1)                     /* Mutual 1 Key18 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY19          (1)                     /* Mutual 1 Key19 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY20          (1)                     /* Mutual 1 Key20 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY21          (1)                     /* Mutual 1 Key21 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY22          (1)                     /* Mutual 1 Key22 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY23          (1)                     /* Mutual 1 Key23 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY24          (1)                     /* Mutual 1 Key24 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY25          (1)                     /* Mutual 1 Key25 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY26          (1)                     /* Mutual 1 Key26 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY27          (1)                     /* Mutual 1 Key27 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY28          (1)                     /* Mutual 1 Key28 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY29          (1)                     /* Mutual 1 Key29 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY30          (1)                     /* Mutual 1 Key30 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY31          (1)                     /* Mutual 1 Key31 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY32          (1)                     /* Mutual 1 Key32 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY33          (1)                     /* Mutual 1 Key33 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY34          (1)                     /* Mutual 1 Key34 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY35          (1)                     /* Mutual 1 Key35 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY36          (1)                     /* Mutual 1 Key36 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY37          (1)                     /* Mutual 1 Key37 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY38          (1)                     /* Mutual 1 Key38 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY39          (1)                     /* Mutual 1 Key39 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY40          (1)                     /* Mutual 1 Key40 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY41          (1)                     /* Mutual 1 Key41 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY42          (1)                     /* Mutual 1 Key42 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY43          (1)                     /* Mutual 1 Key43 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY44          (1)                     /* Mutual 1 Key44 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY45          (1)                     /* Mutual 1 Key45 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY46          (1)                     /* Mutual 1 Key46 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY47          (1)                     /* Mutual 1 Key47 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY48          (1)                     /* Mutual 1 Key48 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY49          (1)                     /* Mutual 1 Key49 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY50          (1)                     /* Mutual 1 Key50 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY51          (1)                     /* Mutual 1 Key51 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY52          (1)                     /* Mutual 1 Key52 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY53          (1)                     /* Mutual 1 Key53 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY54          (1)                     /* Mutual 1 Key54 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY55          (1)                     /* Mutual 1 Key55 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY56          (1)                     /* Mutual 1 Key56 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY57          (1)                     /* Mutual 1 Key57 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY58          (1)                     /* Mutual 1 Key58 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY59          (1)                     /* Mutual 1 Key59 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY60          (1)                     /* Mutual 1 Key60 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY61          (1)                     /* Mutual 1 Key61 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY62          (1)                     /* Mutual 1 Key62 CTSICOG                             */
#define CTSUICOG_MUTUAL6_KEY63          (1)                     /* Mutual 1 Key63 CTSICOG                             */

#define CTSUSO1_MUTUAL6_KEY00  ((CTSUICOG_MUTUAL6_KEY00 << 13) | (CTSUSDPA_MUTUAL6_KEY00 << 8) | CTSURICOA_MUTUAL6_KEY00)
#define CTSUSO1_MUTUAL6_KEY01  ((CTSUICOG_MUTUAL6_KEY01 << 13) | (CTSUSDPA_MUTUAL6_KEY01 << 8) | CTSURICOA_MUTUAL6_KEY01)
#define CTSUSO1_MUTUAL6_KEY02  ((CTSUICOG_MUTUAL6_KEY02 << 13) | (CTSUSDPA_MUTUAL6_KEY02 << 8) | CTSURICOA_MUTUAL6_KEY02)
#define CTSUSO1_MUTUAL6_KEY03  ((CTSUICOG_MUTUAL6_KEY03 << 13) | (CTSUSDPA_MUTUAL6_KEY03 << 8) | CTSURICOA_MUTUAL6_KEY03)
#define CTSUSO1_MUTUAL6_KEY04  ((CTSUICOG_MUTUAL6_KEY04 << 13) | (CTSUSDPA_MUTUAL6_KEY04 << 8) | CTSURICOA_MUTUAL6_KEY04)
#define CTSUSO1_MUTUAL6_KEY05  ((CTSUICOG_MUTUAL6_KEY05 << 13) | (CTSUSDPA_MUTUAL6_KEY05 << 8) | CTSURICOA_MUTUAL6_KEY05)
#define CTSUSO1_MUTUAL6_KEY06  ((CTSUICOG_MUTUAL6_KEY06 << 13) | (CTSUSDPA_MUTUAL6_KEY06 << 8) | CTSURICOA_MUTUAL6_KEY06)
#define CTSUSO1_MUTUAL6_KEY07  ((CTSUICOG_MUTUAL6_KEY07 << 13) | (CTSUSDPA_MUTUAL6_KEY07 << 8) | CTSURICOA_MUTUAL6_KEY07)
#define CTSUSO1_MUTUAL6_KEY08  ((CTSUICOG_MUTUAL6_KEY08 << 13) | (CTSUSDPA_MUTUAL6_KEY08 << 8) | CTSURICOA_MUTUAL6_KEY08)
#define CTSUSO1_MUTUAL6_KEY09  ((CTSUICOG_MUTUAL6_KEY09 << 13) | (CTSUSDPA_MUTUAL6_KEY09 << 8) | CTSURICOA_MUTUAL6_KEY09)
#define CTSUSO1_MUTUAL6_KEY10  ((CTSUICOG_MUTUAL6_KEY10 << 13) | (CTSUSDPA_MUTUAL6_KEY10 << 8) | CTSURICOA_MUTUAL6_KEY10)
#define CTSUSO1_MUTUAL6_KEY11  ((CTSUICOG_MUTUAL6_KEY11 << 13) | (CTSUSDPA_MUTUAL6_KEY11 << 8) | CTSURICOA_MUTUAL6_KEY11)
#define CTSUSO1_MUTUAL6_KEY12  ((CTSUICOG_MUTUAL6_KEY12 << 13) | (CTSUSDPA_MUTUAL6_KEY12 << 8) | CTSURICOA_MUTUAL6_KEY12)
#define CTSUSO1_MUTUAL6_KEY13  ((CTSUICOG_MUTUAL6_KEY13 << 13) | (CTSUSDPA_MUTUAL6_KEY13 << 8) | CTSURICOA_MUTUAL6_KEY13)
#define CTSUSO1_MUTUAL6_KEY14  ((CTSUICOG_MUTUAL6_KEY14 << 13) | (CTSUSDPA_MUTUAL6_KEY14 << 8) | CTSURICOA_MUTUAL6_KEY14)
#define CTSUSO1_MUTUAL6_KEY15  ((CTSUICOG_MUTUAL6_KEY15 << 13) | (CTSUSDPA_MUTUAL6_KEY15 << 8) | CTSURICOA_MUTUAL6_KEY15)
#define CTSUSO1_MUTUAL6_KEY16  ((CTSUICOG_MUTUAL6_KEY16 << 13) | (CTSUSDPA_MUTUAL6_KEY16 << 8) | CTSURICOA_MUTUAL6_KEY16)
#define CTSUSO1_MUTUAL6_KEY17  ((CTSUICOG_MUTUAL6_KEY17 << 13) | (CTSUSDPA_MUTUAL6_KEY17 << 8) | CTSURICOA_MUTUAL6_KEY17)
#define CTSUSO1_MUTUAL6_KEY18  ((CTSUICOG_MUTUAL6_KEY18 << 13) | (CTSUSDPA_MUTUAL6_KEY18 << 8) | CTSURICOA_MUTUAL6_KEY18)
#define CTSUSO1_MUTUAL6_KEY19  ((CTSUICOG_MUTUAL6_KEY19 << 13) | (CTSUSDPA_MUTUAL6_KEY19 << 8) | CTSURICOA_MUTUAL6_KEY19)
#define CTSUSO1_MUTUAL6_KEY20  ((CTSUICOG_MUTUAL6_KEY20 << 13) | (CTSUSDPA_MUTUAL6_KEY20 << 8) | CTSURICOA_MUTUAL6_KEY20)
#define CTSUSO1_MUTUAL6_KEY21  ((CTSUICOG_MUTUAL6_KEY21 << 13) | (CTSUSDPA_MUTUAL6_KEY21 << 8) | CTSURICOA_MUTUAL6_KEY21)
#define CTSUSO1_MUTUAL6_KEY22  ((CTSUICOG_MUTUAL6_KEY22 << 13) | (CTSUSDPA_MUTUAL6_KEY22 << 8) | CTSURICOA_MUTUAL6_KEY22)
#define CTSUSO1_MUTUAL6_KEY23  ((CTSUICOG_MUTUAL6_KEY23 << 13) | (CTSUSDPA_MUTUAL6_KEY23 << 8) | CTSURICOA_MUTUAL6_KEY23)
#define CTSUSO1_MUTUAL6_KEY24  ((CTSUICOG_MUTUAL6_KEY24 << 13) | (CTSUSDPA_MUTUAL6_KEY24 << 8) | CTSURICOA_MUTUAL6_KEY24)
#define CTSUSO1_MUTUAL6_KEY25  ((CTSUICOG_MUTUAL6_KEY25 << 13) | (CTSUSDPA_MUTUAL6_KEY25 << 8) | CTSURICOA_MUTUAL6_KEY25)
#define CTSUSO1_MUTUAL6_KEY26  ((CTSUICOG_MUTUAL6_KEY26 << 13) | (CTSUSDPA_MUTUAL6_KEY26 << 8) | CTSURICOA_MUTUAL6_KEY26)
#define CTSUSO1_MUTUAL6_KEY27  ((CTSUICOG_MUTUAL6_KEY27 << 13) | (CTSUSDPA_MUTUAL6_KEY27 << 8) | CTSURICOA_MUTUAL6_KEY27)
#define CTSUSO1_MUTUAL6_KEY28  ((CTSUICOG_MUTUAL6_KEY28 << 13) | (CTSUSDPA_MUTUAL6_KEY28 << 8) | CTSURICOA_MUTUAL6_KEY28)
#define CTSUSO1_MUTUAL6_KEY29  ((CTSUICOG_MUTUAL6_KEY29 << 13) | (CTSUSDPA_MUTUAL6_KEY29 << 8) | CTSURICOA_MUTUAL6_KEY29)
#define CTSUSO1_MUTUAL6_KEY30  ((CTSUICOG_MUTUAL6_KEY30 << 13) | (CTSUSDPA_MUTUAL6_KEY30 << 8) | CTSURICOA_MUTUAL6_KEY30)
#define CTSUSO1_MUTUAL6_KEY31  ((CTSUICOG_MUTUAL6_KEY31 << 13) | (CTSUSDPA_MUTUAL6_KEY31 << 8) | CTSURICOA_MUTUAL6_KEY31)
#define CTSUSO1_MUTUAL6_KEY32  ((CTSUICOG_MUTUAL6_KEY32 << 13) | (CTSUSDPA_MUTUAL6_KEY32 << 8) | CTSURICOA_MUTUAL6_KEY32)
#define CTSUSO1_MUTUAL6_KEY33  ((CTSUICOG_MUTUAL6_KEY33 << 13) | (CTSUSDPA_MUTUAL6_KEY33 << 8) | CTSURICOA_MUTUAL6_KEY33)
#define CTSUSO1_MUTUAL6_KEY34  ((CTSUICOG_MUTUAL6_KEY34 << 13) | (CTSUSDPA_MUTUAL6_KEY34 << 8) | CTSURICOA_MUTUAL6_KEY34)
#define CTSUSO1_MUTUAL6_KEY35  ((CTSUICOG_MUTUAL6_KEY35 << 13) | (CTSUSDPA_MUTUAL6_KEY35 << 8) | CTSURICOA_MUTUAL6_KEY35)
#define CTSUSO1_MUTUAL6_KEY36  ((CTSUICOG_MUTUAL6_KEY36 << 13) | (CTSUSDPA_MUTUAL6_KEY36 << 8) | CTSURICOA_MUTUAL6_KEY36)
#define CTSUSO1_MUTUAL6_KEY37  ((CTSUICOG_MUTUAL6_KEY37 << 13) | (CTSUSDPA_MUTUAL6_KEY37 << 8) | CTSURICOA_MUTUAL6_KEY37)
#define CTSUSO1_MUTUAL6_KEY38  ((CTSUICOG_MUTUAL6_KEY38 << 13) | (CTSUSDPA_MUTUAL6_KEY38 << 8) | CTSURICOA_MUTUAL6_KEY38)
#define CTSUSO1_MUTUAL6_KEY39  ((CTSUICOG_MUTUAL6_KEY39 << 13) | (CTSUSDPA_MUTUAL6_KEY39 << 8) | CTSURICOA_MUTUAL6_KEY39)
#define CTSUSO1_MUTUAL6_KEY40  ((CTSUICOG_MUTUAL6_KEY40 << 13) | (CTSUSDPA_MUTUAL6_KEY40 << 8) | CTSURICOA_MUTUAL6_KEY40)
#define CTSUSO1_MUTUAL6_KEY41  ((CTSUICOG_MUTUAL6_KEY41 << 13) | (CTSUSDPA_MUTUAL6_KEY41 << 8) | CTSURICOA_MUTUAL6_KEY41)
#define CTSUSO1_MUTUAL6_KEY42  ((CTSUICOG_MUTUAL6_KEY42 << 13) | (CTSUSDPA_MUTUAL6_KEY42 << 8) | CTSURICOA_MUTUAL6_KEY42)
#define CTSUSO1_MUTUAL6_KEY43  ((CTSUICOG_MUTUAL6_KEY43 << 13) | (CTSUSDPA_MUTUAL6_KEY43 << 8) | CTSURICOA_MUTUAL6_KEY43)
#define CTSUSO1_MUTUAL6_KEY44  ((CTSUICOG_MUTUAL6_KEY44 << 13) | (CTSUSDPA_MUTUAL6_KEY44 << 8) | CTSURICOA_MUTUAL6_KEY44)
#define CTSUSO1_MUTUAL6_KEY45  ((CTSUICOG_MUTUAL6_KEY45 << 13) | (CTSUSDPA_MUTUAL6_KEY45 << 8) | CTSURICOA_MUTUAL6_KEY45)
#define CTSUSO1_MUTUAL6_KEY46  ((CTSUICOG_MUTUAL6_KEY46 << 13) | (CTSUSDPA_MUTUAL6_KEY46 << 8) | CTSURICOA_MUTUAL6_KEY46)
#define CTSUSO1_MUTUAL6_KEY47  ((CTSUICOG_MUTUAL6_KEY47 << 13) | (CTSUSDPA_MUTUAL6_KEY47 << 8) | CTSURICOA_MUTUAL6_KEY47)
#define CTSUSO1_MUTUAL6_KEY48  ((CTSUICOG_MUTUAL6_KEY48 << 13) | (CTSUSDPA_MUTUAL6_KEY48 << 8) | CTSURICOA_MUTUAL6_KEY48)
#define CTSUSO1_MUTUAL6_KEY49  ((CTSUICOG_MUTUAL6_KEY49 << 13) | (CTSUSDPA_MUTUAL6_KEY49 << 8) | CTSURICOA_MUTUAL6_KEY49)
#define CTSUSO1_MUTUAL6_KEY50  ((CTSUICOG_MUTUAL6_KEY50 << 13) | (CTSUSDPA_MUTUAL6_KEY50 << 8) | CTSURICOA_MUTUAL6_KEY50)
#define CTSUSO1_MUTUAL6_KEY51  ((CTSUICOG_MUTUAL6_KEY51 << 13) | (CTSUSDPA_MUTUAL6_KEY51 << 8) | CTSURICOA_MUTUAL6_KEY51)
#define CTSUSO1_MUTUAL6_KEY52  ((CTSUICOG_MUTUAL6_KEY52 << 13) | (CTSUSDPA_MUTUAL6_KEY52 << 8) | CTSURICOA_MUTUAL6_KEY52)
#define CTSUSO1_MUTUAL6_KEY53  ((CTSUICOG_MUTUAL6_KEY53 << 13) | (CTSUSDPA_MUTUAL6_KEY53 << 8) | CTSURICOA_MUTUAL6_KEY53)
#define CTSUSO1_MUTUAL6_KEY54  ((CTSUICOG_MUTUAL6_KEY54 << 13) | (CTSUSDPA_MUTUAL6_KEY54 << 8) | CTSURICOA_MUTUAL6_KEY54)
#define CTSUSO1_MUTUAL6_KEY55  ((CTSUICOG_MUTUAL6_KEY55 << 13) | (CTSUSDPA_MUTUAL6_KEY55 << 8) | CTSURICOA_MUTUAL6_KEY55)
#define CTSUSO1_MUTUAL6_KEY56  ((CTSUICOG_MUTUAL6_KEY56 << 13) | (CTSUSDPA_MUTUAL6_KEY56 << 8) | CTSURICOA_MUTUAL6_KEY56)
#define CTSUSO1_MUTUAL6_KEY57  ((CTSUICOG_MUTUAL6_KEY57 << 13) | (CTSUSDPA_MUTUAL6_KEY57 << 8) | CTSURICOA_MUTUAL6_KEY57)
#define CTSUSO1_MUTUAL6_KEY58  ((CTSUICOG_MUTUAL6_KEY58 << 13) | (CTSUSDPA_MUTUAL6_KEY58 << 8) | CTSURICOA_MUTUAL6_KEY58)
#define CTSUSO1_MUTUAL6_KEY59  ((CTSUICOG_MUTUAL6_KEY59 << 13) | (CTSUSDPA_MUTUAL6_KEY59 << 8) | CTSURICOA_MUTUAL6_KEY59)
#define CTSUSO1_MUTUAL6_KEY60  ((CTSUICOG_MUTUAL6_KEY60 << 13) | (CTSUSDPA_MUTUAL6_KEY60 << 8) | CTSURICOA_MUTUAL6_KEY60)
#define CTSUSO1_MUTUAL6_KEY61  ((CTSUICOG_MUTUAL6_KEY61 << 13) | (CTSUSDPA_MUTUAL6_KEY61 << 8) | CTSURICOA_MUTUAL6_KEY61)
#define CTSUSO1_MUTUAL6_KEY62  ((CTSUICOG_MUTUAL6_KEY62 << 13) | (CTSUSDPA_MUTUAL6_KEY62 << 8) | CTSURICOA_MUTUAL6_KEY62)
#define CTSUSO1_MUTUAL6_KEY63  ((CTSUICOG_MUTUAL6_KEY63 << 13) | (CTSUSDPA_MUTUAL6_KEY63 << 8) | CTSURICOA_MUTUAL6_KEY63)
#endif   // ( MUTUAL_METHOD_NUM >= 7 )

#if ( MUTUAL_METHOD_NUM >= 8 )
/*====================================================================================================================*/
/*=====     Mutual-measurement 7 TS enable definition    =============================================================*/
/*====================================================================================================================*/
#define MUTUAL7_ENABLE_TS00              (0)        /* Mutual 1 TS00 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS01              (0)        /* Mutual 1 TS01 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS02              (0)        /* Mutual 1 TS02 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS03              (0)        /* Mutual 1 TS03 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS04              (0)        /* Mutual 1 TS04 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS05              (0)        /* Mutual 1 TS05 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS06              (0)        /* Mutual 1 TS06 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS07              (0)        /* Mutual 1 TS07 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS08              (0)        /* Mutual 1 TS08 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS09              (0)        /* Mutual 1 TS09 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS10              (0)        /* Mutual 1 TS10 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS11              (0)        /* Mutual 1 TS11 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS12              (0)        /* Mutual 1 TS12 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS13              (0)        /* Mutual 1 TS13 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS14              (0)        /* Mutual 1 TS14 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS15              (0)        /* Mutual 1 TS15 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS16              (0)        /* Mutual 1 TS16 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS17              (0)        /* Mutual 1 TS17 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS18              (0)        /* Mutual 1 TS18 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS19              (0)        /* Mutual 1 TS19 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS20              (0)        /* Mutual 1 TS20 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS21              (0)        /* Mutual 1 TS21 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS22              (0)        /* Mutual 1 TS22 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS23              (0)        /* Mutual 1 TS23 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS24              (0)        /* Mutual 1 TS24 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS25              (0)        /* Mutual 1 TS25 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS26              (0)        /* Mutual 1 TS26 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS27              (0)        /* Mutual 1 TS27 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS28              (0)        /* Mutual 1 TS28 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS29              (0)        /* Mutual 1 TS29 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS30              (0)        /* Mutual 1 TS30 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS31              (0)        /* Mutual 1 TS31 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS32              (0)        /* Mutual 1 TS32 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS33              (0)        /* Mutual 1 TS33 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS34              (0)        /* Mutual 1 TS34 0:disable 1:enable                               */
#define MUTUAL7_ENABLE_TS35              (0)        /* Mutual 1 TS35 0:disable 1:enable                               */

/*****    Address 000A 0906h CTSU Channel enable control register 0    ************************************************/
#define CTSUCHAC0_MUTUAL7_ENABLE_TS      ((MUTUAL7_ENABLE_TS00 << 0) | (MUTUAL7_ENABLE_TS01 << 1) | \
                                          (MUTUAL7_ENABLE_TS02 << 2) | (MUTUAL7_ENABLE_TS03 << 3) | \
                                          (MUTUAL7_ENABLE_TS04 << 4) | (MUTUAL7_ENABLE_TS05 << 5) | \
                                          (MUTUAL7_ENABLE_TS06 << 6) | (MUTUAL7_ENABLE_TS07 << 7))

/*****    Address 000A 0907h CTSU Channel enable control register 1    ************************************************/
#define CTSUCHAC1_MUTUAL7_ENABLE_TS      ((MUTUAL7_ENABLE_TS08 << 0) | (MUTUAL7_ENABLE_TS09 << 1) | \
                                          (MUTUAL7_ENABLE_TS10 << 2) | (MUTUAL7_ENABLE_TS11 << 3) | \
                                          (MUTUAL7_ENABLE_TS12 << 4) | (MUTUAL7_ENABLE_TS13 << 5) | \
                                          (MUTUAL7_ENABLE_TS14 << 6) | (MUTUAL7_ENABLE_TS15 << 7))

/*****    Address 000A 0908h CTSU Channel enable control register 2    ************************************************/
#define CTSUCHAC2_MUTUAL7_ENABLE_TS      ((MUTUAL7_ENABLE_TS16 << 0) | (MUTUAL7_ENABLE_TS17 << 1) | \
                                          (MUTUAL7_ENABLE_TS18 << 2) | (MUTUAL7_ENABLE_TS19 << 3) | \
                                          (MUTUAL7_ENABLE_TS20 << 4) | (MUTUAL7_ENABLE_TS21 << 5) | \
                                          (MUTUAL7_ENABLE_TS22 << 6) | (MUTUAL7_ENABLE_TS23 << 7))

/*****    Address 000A 0909h CTSU Channel enable control register 3    ************************************************/
#define CTSUCHAC3_MUTUAL7_ENABLE_TS      ((MUTUAL7_ENABLE_TS24 << 0) | (MUTUAL7_ENABLE_TS25 << 1) | \
                                          (MUTUAL7_ENABLE_TS26 << 2) | (MUTUAL7_ENABLE_TS27 << 3) | \
                                          (MUTUAL7_ENABLE_TS28 << 4) | (MUTUAL7_ENABLE_TS29 << 5) | \
                                          (MUTUAL7_ENABLE_TS30 << 6) | (MUTUAL7_ENABLE_TS31 << 7))

/*****    Address 000A 090ah CTSU Channel enable control register 4    ************************************************/
#define CTSUCHAC4_MUTUAL7_ENABLE_TS      ((MUTUAL7_ENABLE_TS32 << 0) | (MUTUAL7_ENABLE_TS33 << 1) | \
                                          (MUTUAL7_ENABLE_TS34 << 2) | (MUTUAL7_ENABLE_TS35 << 3))

/* SUM of Channels */ /* Do not edit this macro definition */
#define MUTUAL7_ENABLE_NUM               (MUTUAL7_ENABLE_TS00 + MUTUAL7_ENABLE_TS01 + MUTUAL7_ENABLE_TS02 + \
                                          MUTUAL7_ENABLE_TS03 + MUTUAL7_ENABLE_TS04 + MUTUAL7_ENABLE_TS05 + \
                                          MUTUAL7_ENABLE_TS06 + MUTUAL7_ENABLE_TS07 + MUTUAL7_ENABLE_TS08 + \
                                          MUTUAL7_ENABLE_TS09 + MUTUAL7_ENABLE_TS10 + MUTUAL7_ENABLE_TS11 + \
                                          MUTUAL7_ENABLE_TS12 + MUTUAL7_ENABLE_TS13 + MUTUAL7_ENABLE_TS14 + \
                                          MUTUAL7_ENABLE_TS15 + MUTUAL7_ENABLE_TS16 + MUTUAL7_ENABLE_TS17 + \
                                          MUTUAL7_ENABLE_TS18 + MUTUAL7_ENABLE_TS19 + MUTUAL7_ENABLE_TS20 + \
                                          MUTUAL7_ENABLE_TS21 + MUTUAL7_ENABLE_TS22 + MUTUAL7_ENABLE_TS23 + \
                                          MUTUAL7_ENABLE_TS24 + MUTUAL7_ENABLE_TS25 + MUTUAL7_ENABLE_TS26 + \
                                          MUTUAL7_ENABLE_TS27 + MUTUAL7_ENABLE_TS28 + MUTUAL7_ENABLE_TS29 + \
                                          MUTUAL7_ENABLE_TS30 + MUTUAL7_ENABLE_TS31 + MUTUAL7_ENABLE_TS32 + \
                                          MUTUAL7_ENABLE_TS33 + MUTUAL7_ENABLE_TS34 + MUTUAL7_ENABLE_TS35)

/*====================================================================================================================*/
/*=====     Mutual-measurement 7 function definition     =============================================================*/
/*====================================================================================================================*/
#define MUTUAL7_FUNCTION_TS00            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS01            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS02            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS03            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS04            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS05            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS06            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS07            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS08            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS09            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS10            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS11            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS12            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS13            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS14            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS15            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS16            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS17            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS18            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS19            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS20            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS21            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS22            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS23            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS24            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS25            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS26            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS27            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS28            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS29            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS30            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS31            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS32            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS33            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS34            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */
#define MUTUAL7_FUNCTION_TS35            (RECEPTION_FUNCITON)       /* TRANSMISSION_FUNCITON or RECEPTION_FUNCITON    */

/*****    Address 000A 090Bh CTSU Channel send and receive control register 0 *****************************************/
#define CTSUCHTRC0_MUTUAL7_TRANSMIT_TS   ((MUTUAL7_FUNCTION_TS00 << 0) | (MUTUAL7_FUNCTION_TS01 << 1) | \
                                          (MUTUAL7_FUNCTION_TS02 << 2) | (MUTUAL7_FUNCTION_TS03 << 3) | \
                                          (MUTUAL7_FUNCTION_TS04 << 4) | (MUTUAL7_FUNCTION_TS05 << 5) | \
                                          (MUTUAL7_FUNCTION_TS06 << 6) | (MUTUAL7_FUNCTION_TS07 << 7))

/*****    Address 000A 090Ch CTSU Channel send and receive control register 1 *****************************************/
#define CTSUCHTRC1_MUTUAL7_TRANSMIT_TS   ((MUTUAL7_FUNCTION_TS08 << 0) | (MUTUAL7_FUNCTION_TS09 << 1) | \
                                          (MUTUAL7_FUNCTION_TS10 << 2) | (MUTUAL7_FUNCTION_TS11 << 3) | \
                                          (MUTUAL7_FUNCTION_TS12 << 4) | (MUTUAL7_FUNCTION_TS13 << 5) | \
                                          (MUTUAL7_FUNCTION_TS14 << 6) | (MUTUAL7_FUNCTION_TS15 << 7))

/*****    Address 000A 090Dh CTSU Channel send and receive control register 2 *****************************************/
#define CTSUCHTRC2_MUTUAL7_TRANSMIT_TS   ((MUTUAL7_FUNCTION_TS16 << 0) | (MUTUAL7_FUNCTION_TS17 << 1) | \
                                          (MUTUAL7_FUNCTION_TS18 << 2) | (MUTUAL7_FUNCTION_TS19 << 3) | \
                                          (MUTUAL7_FUNCTION_TS20 << 4) | (MUTUAL7_FUNCTION_TS21 << 5) | \
                                          (MUTUAL7_FUNCTION_TS22 << 6) | (MUTUAL7_FUNCTION_TS23 << 7))

/*****    Address 000A 090Eh CTSU Channel send and receive control register 3 *****************************************/
#define CTSUCHTRC3_MUTUAL7_TRANSMIT_TS   ((MUTUAL7_FUNCTION_TS24 << 0) | (MUTUAL7_FUNCTION_TS25 << 1) | \
                                          (MUTUAL7_FUNCTION_TS26 << 2) | (MUTUAL7_FUNCTION_TS27 << 3) | \
                                          (MUTUAL7_FUNCTION_TS28 << 4) | (MUTUAL7_FUNCTION_TS29 << 5) | \
                                          (MUTUAL7_FUNCTION_TS30 << 6) | (MUTUAL7_FUNCTION_TS31 << 7))

/*****    Address 000A 090Fh CTSU Channel send and receive control register 4 *****************************************/
#define CTSUCHTRC4_MUTUAL7_TRANSMIT_TS   ((MUTUAL7_FUNCTION_TS32 << 0) | (MUTUAL7_FUNCTION_TS33 << 1) | \
                                          (MUTUAL7_FUNCTION_TS34 << 2) | (MUTUAL7_FUNCTION_TS35 << 3))

#define TRANSMISSION7_NUM                  (MUTUAL7_FUNCTION_TS00 + MUTUAL7_FUNCTION_TS01 + MUTUAL7_FUNCTION_TS02 + \
                                            MUTUAL7_FUNCTION_TS03 + MUTUAL7_FUNCTION_TS04 + MUTUAL7_FUNCTION_TS05 + \
                                            MUTUAL7_FUNCTION_TS06 + MUTUAL7_FUNCTION_TS07 + MUTUAL7_FUNCTION_TS08 + \
                                            MUTUAL7_FUNCTION_TS09 + MUTUAL7_FUNCTION_TS10 + MUTUAL7_FUNCTION_TS11 + \
                                            MUTUAL7_FUNCTION_TS12 + MUTUAL7_FUNCTION_TS13 + MUTUAL7_FUNCTION_TS14 + \
                                            MUTUAL7_FUNCTION_TS15 + MUTUAL7_FUNCTION_TS16 + MUTUAL7_FUNCTION_TS17 + \
                                            MUTUAL7_FUNCTION_TS18 + MUTUAL7_FUNCTION_TS19 + MUTUAL7_FUNCTION_TS20 + \
                                            MUTUAL7_FUNCTION_TS21 + MUTUAL7_FUNCTION_TS22 + MUTUAL7_FUNCTION_TS23 + \
                                            MUTUAL7_FUNCTION_TS24 + MUTUAL7_FUNCTION_TS25 + MUTUAL7_FUNCTION_TS26 + \
                                            MUTUAL7_FUNCTION_TS27 + MUTUAL7_FUNCTION_TS28 + MUTUAL7_FUNCTION_TS29 + \
                                            MUTUAL7_FUNCTION_TS30 + MUTUAL7_FUNCTION_TS31 + MUTUAL7_FUNCTION_TS32 + \
                                            MUTUAL7_FUNCTION_TS33 + MUTUAL7_FUNCTION_TS34 + MUTUAL7_FUNCTION_TS35)

#define RECEPTION7_NUM                     (MUTUAL7_ENABLE_NUM - TRANSMISSION7_NUM)
#define MUTUAL7_NUM                        (TRANSMISSION7_NUM * RECEPTION7_NUM)

#if TRANSMISSION7_NUM == 0
    #error "Send TS Setting error ( TRANSMISSION7_NUM = 0 )"
#endif
#if RECEPTION7_NUM == 0
    #error "Receive TS Setting error ( RECEPTION_NUM7 = 0 )"
#endif

/*****    Address 000A 0912h CTSU High-Pass Noise Reduction Spectrum Diffusion Control Register    ********************/
/**********************************************************************************************************************/
/*    CTSU Spectrum Diffusion Frequency Division Setting                                                              */
/*    Base Clock Frequency fb (MHz)   CTSUSSDIV[3:0] Bit Setting                                                      */
/*          4.00 =< fb                           0x00                                                                 */
/*          2.00 =< fb  < 4.00                   0x01                                                                 */
/*          1.33 =< fb  < 2.00                   0x02                                                                 */
/*          1.00 =< fb  < 1.33                   0x03                                                                 */
/*          0.80 =< fb  < 1.00                   0x04                                                                 */
/*          0.67 =< fb  < 0.80                   0x05                                                                 */
/*          0.57 =< fb  < 0.67                   0x06                                                                 */
/*          0.50 =< fb  < 0.57                   0x07                                                                 */
/*          0.44 =< fb  < 0.50                   0x08                                                                 */
/*          0.40 =< fb  < 0.44                   0x09                                                                 */
/*          0.36 =< fb  < 0.40                   0x0A                                                                 */
/*          0.33 =< fb  < 0.36                   0x0B                                                                 */
/*          0.31 =< fb  < 0.33                   0x0C                                                                 */
/*          0.29 =< fb  < 0.31                   0x0D                                                                 */
/*          0.27 =< fb  < 0.29                   0x0E                                                                 */
/*                  fb =< 0.25                   0x0F                                                                 */
/**********************************************************************************************************************/
#define CTSUSSDIV_MUTUAL7_KEY00         (0x01)                  /* Mutual 1 Key00 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY01         (0x01)                  /* Mutual 1 Key01 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY02         (0x01)                  /* Mutual 1 Key02 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY03         (0x01)                  /* Mutual 1 Key03 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY04         (0x01)                  /* Mutual 1 Key04 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY05         (0x01)                  /* Mutual 1 Key05 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY06         (0x01)                  /* Mutual 1 Key06 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY07         (0x01)                  /* Mutual 1 Key07 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY08         (0x01)                  /* Mutual 1 Key08 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY09         (0x01)                  /* Mutual 1 Key09 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY10         (0x01)                  /* Mutual 1 Key10 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY11         (0x01)                  /* Mutual 1 Key11 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY12         (0x01)                  /* Mutual 1 Key12 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY13         (0x01)                  /* Mutual 1 Key13 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY14         (0x01)                  /* Mutual 1 Key14 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY15         (0x01)                  /* Mutual 1 Key15 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY16         (0x01)                  /* Mutual 1 Key16 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY17         (0x01)                  /* Mutual 1 Key17 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY18         (0x01)                  /* Mutual 1 Key18 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY19         (0x01)                  /* Mutual 1 Key19 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY20         (0x01)                  /* Mutual 1 Key20 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY21         (0x01)                  /* Mutual 1 Key21 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY22         (0x01)                  /* Mutual 1 Key22 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY23         (0x01)                  /* Mutual 1 Key23 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY24         (0x01)                  /* Mutual 1 Key24 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY25         (0x01)                  /* Mutual 1 Key25 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY26         (0x01)                  /* Mutual 1 Key26 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY27         (0x01)                  /* Mutual 1 Key27 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY28         (0x01)                  /* Mutual 1 Key28 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY29         (0x01)                  /* Mutual 1 Key29 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY30         (0x01)                  /* Mutual 1 Key30 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY31         (0x01)                  /* Mutual 1 Key31 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY32         (0x01)                  /* Mutual 1 Key32 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY33         (0x01)                  /* Mutual 1 Key33 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY34         (0x01)                  /* Mutual 1 Key34 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY35         (0x01)                  /* Mutual 1 Key35 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY36         (0x01)                  /* Mutual 1 Key36 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY37         (0x01)                  /* Mutual 1 Key37 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY38         (0x01)                  /* Mutual 1 Key38 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY39         (0x01)                  /* Mutual 1 Key39 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY40         (0x01)                  /* Mutual 1 Key40 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY41         (0x01)                  /* Mutual 1 Key41 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY42         (0x01)                  /* Mutual 1 Key42 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY43         (0x01)                  /* Mutual 1 Key43 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY44         (0x01)                  /* Mutual 1 Key44 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY45         (0x01)                  /* Mutual 1 Key45 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY46         (0x01)                  /* Mutual 1 Key46 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY47         (0x01)                  /* Mutual 1 Key47 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY48         (0x01)                  /* Mutual 1 Key48 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY49         (0x01)                  /* Mutual 1 Key49 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY50         (0x01)                  /* Mutual 1 Key50 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY51         (0x01)                  /* Mutual 1 Key51 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY52         (0x01)                  /* Mutual 1 Key52 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY53         (0x01)                  /* Mutual 1 Key53 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY54         (0x01)                  /* Mutual 1 Key54 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY55         (0x01)                  /* Mutual 1 Key55 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY56         (0x01)                  /* Mutual 1 Key56 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY57         (0x01)                  /* Mutual 1 Key57 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY58         (0x01)                  /* Mutual 1 Key58 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY59         (0x01)                  /* Mutual 1 Key59 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY60         (0x01)                  /* Mutual 1 Key60 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY61         (0x01)                  /* Mutual 1 Key61 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY62         (0x01)                  /* Mutual 1 Key62 CTSUSDIV                            */
#define CTSUSSDIV_MUTUAL7_KEY63         (0x01)                  /* Mutual 1 Key63 CTSUSDIV                            */

#define CTSUSSC_MUTUAL7_KEY00           (CTSUSSDIV_MUTUAL7_KEY00 << 8)
#define CTSUSSC_MUTUAL7_KEY01           (CTSUSSDIV_MUTUAL7_KEY01 << 8)
#define CTSUSSC_MUTUAL7_KEY02           (CTSUSSDIV_MUTUAL7_KEY02 << 8)
#define CTSUSSC_MUTUAL7_KEY03           (CTSUSSDIV_MUTUAL7_KEY03 << 8)
#define CTSUSSC_MUTUAL7_KEY04           (CTSUSSDIV_MUTUAL7_KEY04 << 8)
#define CTSUSSC_MUTUAL7_KEY05           (CTSUSSDIV_MUTUAL7_KEY05 << 8)
#define CTSUSSC_MUTUAL7_KEY06           (CTSUSSDIV_MUTUAL7_KEY06 << 8)
#define CTSUSSC_MUTUAL7_KEY07           (CTSUSSDIV_MUTUAL7_KEY07 << 8)
#define CTSUSSC_MUTUAL7_KEY08           (CTSUSSDIV_MUTUAL7_KEY08 << 8)
#define CTSUSSC_MUTUAL7_KEY09           (CTSUSSDIV_MUTUAL7_KEY09 << 8)
#define CTSUSSC_MUTUAL7_KEY10           (CTSUSSDIV_MUTUAL7_KEY10 << 8)
#define CTSUSSC_MUTUAL7_KEY11           (CTSUSSDIV_MUTUAL7_KEY11 << 8)
#define CTSUSSC_MUTUAL7_KEY12           (CTSUSSDIV_MUTUAL7_KEY12 << 8)
#define CTSUSSC_MUTUAL7_KEY13           (CTSUSSDIV_MUTUAL7_KEY13 << 8)
#define CTSUSSC_MUTUAL7_KEY14           (CTSUSSDIV_MUTUAL7_KEY14 << 8)
#define CTSUSSC_MUTUAL7_KEY15           (CTSUSSDIV_MUTUAL7_KEY15 << 8)
#define CTSUSSC_MUTUAL7_KEY16           (CTSUSSDIV_MUTUAL7_KEY16 << 8)
#define CTSUSSC_MUTUAL7_KEY17           (CTSUSSDIV_MUTUAL7_KEY17 << 8)
#define CTSUSSC_MUTUAL7_KEY18           (CTSUSSDIV_MUTUAL7_KEY18 << 8)
#define CTSUSSC_MUTUAL7_KEY19           (CTSUSSDIV_MUTUAL7_KEY19 << 8)
#define CTSUSSC_MUTUAL7_KEY20           (CTSUSSDIV_MUTUAL7_KEY20 << 8)
#define CTSUSSC_MUTUAL7_KEY21           (CTSUSSDIV_MUTUAL7_KEY21 << 8)
#define CTSUSSC_MUTUAL7_KEY22           (CTSUSSDIV_MUTUAL7_KEY22 << 8)
#define CTSUSSC_MUTUAL7_KEY23           (CTSUSSDIV_MUTUAL7_KEY23 << 8)
#define CTSUSSC_MUTUAL7_KEY24           (CTSUSSDIV_MUTUAL7_KEY24 << 8)
#define CTSUSSC_MUTUAL7_KEY25           (CTSUSSDIV_MUTUAL7_KEY25 << 8)
#define CTSUSSC_MUTUAL7_KEY26           (CTSUSSDIV_MUTUAL7_KEY26 << 8)
#define CTSUSSC_MUTUAL7_KEY27           (CTSUSSDIV_MUTUAL7_KEY27 << 8)
#define CTSUSSC_MUTUAL7_KEY28           (CTSUSSDIV_MUTUAL7_KEY28 << 8)
#define CTSUSSC_MUTUAL7_KEY29           (CTSUSSDIV_MUTUAL7_KEY29 << 8)
#define CTSUSSC_MUTUAL7_KEY30           (CTSUSSDIV_MUTUAL7_KEY30 << 8)
#define CTSUSSC_MUTUAL7_KEY31           (CTSUSSDIV_MUTUAL7_KEY31 << 8)
#define CTSUSSC_MUTUAL7_KEY32           (CTSUSSDIV_MUTUAL7_KEY32 << 8)
#define CTSUSSC_MUTUAL7_KEY33           (CTSUSSDIV_MUTUAL7_KEY33 << 8)
#define CTSUSSC_MUTUAL7_KEY34           (CTSUSSDIV_MUTUAL7_KEY34 << 8)
#define CTSUSSC_MUTUAL7_KEY35           (CTSUSSDIV_MUTUAL7_KEY35 << 8)
#define CTSUSSC_MUTUAL7_KEY36           (CTSUSSDIV_MUTUAL7_KEY36 << 8)
#define CTSUSSC_MUTUAL7_KEY37           (CTSUSSDIV_MUTUAL7_KEY37 << 8)
#define CTSUSSC_MUTUAL7_KEY38           (CTSUSSDIV_MUTUAL7_KEY38 << 8)
#define CTSUSSC_MUTUAL7_KEY39           (CTSUSSDIV_MUTUAL7_KEY39 << 8)
#define CTSUSSC_MUTUAL7_KEY40           (CTSUSSDIV_MUTUAL7_KEY40 << 8)
#define CTSUSSC_MUTUAL7_KEY41           (CTSUSSDIV_MUTUAL7_KEY41 << 8)
#define CTSUSSC_MUTUAL7_KEY42           (CTSUSSDIV_MUTUAL7_KEY42 << 8)
#define CTSUSSC_MUTUAL7_KEY43           (CTSUSSDIV_MUTUAL7_KEY43 << 8)
#define CTSUSSC_MUTUAL7_KEY44           (CTSUSSDIV_MUTUAL7_KEY44 << 8)
#define CTSUSSC_MUTUAL7_KEY45           (CTSUSSDIV_MUTUAL7_KEY45 << 8)
#define CTSUSSC_MUTUAL7_KEY46           (CTSUSSDIV_MUTUAL7_KEY46 << 8)
#define CTSUSSC_MUTUAL7_KEY47           (CTSUSSDIV_MUTUAL7_KEY47 << 8)
#define CTSUSSC_MUTUAL7_KEY48           (CTSUSSDIV_MUTUAL7_KEY48 << 8)
#define CTSUSSC_MUTUAL7_KEY49           (CTSUSSDIV_MUTUAL7_KEY49 << 8)
#define CTSUSSC_MUTUAL7_KEY50           (CTSUSSDIV_MUTUAL7_KEY50 << 8)
#define CTSUSSC_MUTUAL7_KEY51           (CTSUSSDIV_MUTUAL7_KEY51 << 8)
#define CTSUSSC_MUTUAL7_KEY52           (CTSUSSDIV_MUTUAL7_KEY52 << 8)
#define CTSUSSC_MUTUAL7_KEY53           (CTSUSSDIV_MUTUAL7_KEY53 << 8)
#define CTSUSSC_MUTUAL7_KEY54           (CTSUSSDIV_MUTUAL7_KEY54 << 8)
#define CTSUSSC_MUTUAL7_KEY55           (CTSUSSDIV_MUTUAL7_KEY55 << 8)
#define CTSUSSC_MUTUAL7_KEY56           (CTSUSSDIV_MUTUAL7_KEY56 << 8)
#define CTSUSSC_MUTUAL7_KEY57           (CTSUSSDIV_MUTUAL7_KEY57 << 8)
#define CTSUSSC_MUTUAL7_KEY58           (CTSUSSDIV_MUTUAL7_KEY58 << 8)
#define CTSUSSC_MUTUAL7_KEY59           (CTSUSSDIV_MUTUAL7_KEY59 << 8)
#define CTSUSSC_MUTUAL7_KEY60           (CTSUSSDIV_MUTUAL7_KEY60 << 8)
#define CTSUSSC_MUTUAL7_KEY61           (CTSUSSDIV_MUTUAL7_KEY61 << 8)
#define CTSUSSC_MUTUAL7_KEY62           (CTSUSSDIV_MUTUAL7_KEY62 << 8)
#define CTSUSSC_MUTUAL7_KEY63           (CTSUSSDIV_MUTUAL7_KEY63 << 8)

/*****    Address 000A 0914h CTSU Sensor Offset Register 0     ********************************************************/
/**********************************************************************************************************************/
/*    CTSU Sensor Offset Adjustment                                                                                   */
/*      Current offset amount is 0       0x000                                                                        */
/*      Current offset amount is 1       0x001                                                                        */
/*      Current offset amount is 2       0x002                                                                        */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*      Current offset amount is 1023    0x3FF                                                                        */
/**********************************************************************************************************************/
#define CTSUSO_MUTUAL7_KEY00            (0x000)                 /* Mutual 1 Key00 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY01            (0x000)                 /* Mutual 1 Key01 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY02            (0x000)                 /* Mutual 1 Key02 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY03            (0x000)                 /* Mutual 1 Key03 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY04            (0x000)                 /* Mutual 1 Key04 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY05            (0x000)                 /* Mutual 1 Key05 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY06            (0x000)                 /* Mutual 1 Key06 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY07            (0x000)                 /* Mutual 1 Key07 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY08            (0x000)                 /* Mutual 1 Key08 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY09            (0x000)                 /* Mutual 1 Key09 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY10            (0x000)                 /* Mutual 1 Key10 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY11            (0x000)                 /* Mutual 1 Key11 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY12            (0x000)                 /* Mutual 1 Key12 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY13            (0x000)                 /* Mutual 1 Key13 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY14            (0x000)                 /* Mutual 1 Key14 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY15            (0x000)                 /* Mutual 1 Key15 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY16            (0x000)                 /* Mutual 1 Key16 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY17            (0x000)                 /* Mutual 1 Key17 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY18            (0x000)                 /* Mutual 1 Key18 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY19            (0x000)                 /* Mutual 1 Key19 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY20            (0x000)                 /* Mutual 1 Key20 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY21            (0x000)                 /* Mutual 1 Key21 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY22            (0x000)                 /* Mutual 1 Key22 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY23            (0x000)                 /* Mutual 1 Key23 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY24            (0x000)                 /* Mutual 1 Key24 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY25            (0x000)                 /* Mutual 1 Key25 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY26            (0x000)                 /* Mutual 1 Key26 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY27            (0x000)                 /* Mutual 1 Key27 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY28            (0x000)                 /* Mutual 1 Key28 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY29            (0x000)                 /* Mutual 1 Key29 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY30            (0x000)                 /* Mutual 1 Key30 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY31            (0x000)                 /* Mutual 1 Key31 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY32            (0x000)                 /* Mutual 1 Key32 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY33            (0x000)                 /* Mutual 1 Key33 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY34            (0x000)                 /* Mutual 1 Key34 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY35            (0x000)                 /* Mutual 1 Key35 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY36            (0x000)                 /* Mutual 1 Key36 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY37            (0x000)                 /* Mutual 1 Key37 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY38            (0x000)                 /* Mutual 1 Key38 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY39            (0x000)                 /* Mutual 1 Key39 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY40            (0x000)                 /* Mutual 1 Key40 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY41            (0x000)                 /* Mutual 1 Key41 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY42            (0x000)                 /* Mutual 1 Key42 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY43            (0x000)                 /* Mutual 1 Key43 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY44            (0x000)                 /* Mutual 1 Key44 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY45            (0x000)                 /* Mutual 1 Key45 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY46            (0x000)                 /* Mutual 1 Key46 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY47            (0x000)                 /* Mutual 1 Key47 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY48            (0x000)                 /* Mutual 1 Key48 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY49            (0x000)                 /* Mutual 1 Key49 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY50            (0x000)                 /* Mutual 1 Key50 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY51            (0x000)                 /* Mutual 1 Key51 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY52            (0x000)                 /* Mutual 1 Key52 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY53            (0x000)                 /* Mutual 1 Key53 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY54            (0x000)                 /* Mutual 1 Key54 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY55            (0x000)                 /* Mutual 1 Key55 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY56            (0x000)                 /* Mutual 1 Key56 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY57            (0x000)                 /* Mutual 1 Key57 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY58            (0x000)                 /* Mutual 1 Key58 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY59            (0x000)                 /* Mutual 1 Key59 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY60            (0x000)                 /* Mutual 1 Key60 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY61            (0x000)                 /* Mutual 1 Key61 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY62            (0x000)                 /* Mutual 1 Key62 CTSUSO                              */
#define CTSUSO_MUTUAL7_KEY63            (0x000)                 /* Mutual 1 Key63 CTSUSO                              */

/**********************************************************************************************************************/
/*    CTSU Measurement Count Setting                                                                                  */
/*      4.0MHz    7                                                                                                   */
/*      2.0MHz    3                                                                                                   */
/*      1.0MHz    1                                                                                                   */
/*      0.5MHz    0                                                                                                   */
/**********************************************************************************************************************/
#define CTSUSNUM_MUTUAL7_KEY00          (3)                     /* Mutual 1 Key00 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY01          (3)                     /* Mutual 1 Key01 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY02          (3)                     /* Mutual 1 Key02 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY03          (3)                     /* Mutual 1 Key03 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY04          (3)                     /* Mutual 1 Key04 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY05          (3)                     /* Mutual 1 Key05 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY06          (3)                     /* Mutual 1 Key06 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY07          (3)                     /* Mutual 1 Key07 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY08          (3)                     /* Mutual 1 Key08 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY09          (3)                     /* Mutual 1 Key09 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY10          (3)                     /* Mutual 1 Key10 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY11          (3)                     /* Mutual 1 Key11 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY12          (3)                     /* Mutual 1 Key12 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY13          (3)                     /* Mutual 1 Key13 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY14          (3)                     /* Mutual 1 Key14 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY15          (3)                     /* Mutual 1 Key15 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY16          (3)                     /* Mutual 1 Key16 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY17          (3)                     /* Mutual 1 Key17 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY18          (3)                     /* Mutual 1 Key18 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY19          (3)                     /* Mutual 1 Key19 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY20          (3)                     /* Mutual 1 Key20 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY21          (3)                     /* Mutual 1 Key21 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY22          (3)                     /* Mutual 1 Key22 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY23          (3)                     /* Mutual 1 Key23 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY24          (3)                     /* Mutual 1 Key24 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY25          (3)                     /* Mutual 1 Key25 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY26          (3)                     /* Mutual 1 Key26 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY27          (3)                     /* Mutual 1 Key27 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY28          (3)                     /* Mutual 1 Key28 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY29          (3)                     /* Mutual 1 Key29 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY30          (3)                     /* Mutual 1 Key30 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY31          (3)                     /* Mutual 1 Key31 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY32          (3)                     /* Mutual 1 Key32 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY33          (3)                     /* Mutual 1 Key33 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY34          (3)                     /* Mutual 1 Key34 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY35          (3)                     /* Mutual 1 Key35 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY36          (3)                     /* Mutual 1 Key36 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY37          (3)                     /* Mutual 1 Key37 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY38          (3)                     /* Mutual 1 Key38 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY39          (3)                     /* Mutual 1 Key39 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY40          (3)                     /* Mutual 1 Key40 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY41          (3)                     /* Mutual 1 Key41 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY42          (3)                     /* Mutual 1 Key42 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY43          (3)                     /* Mutual 1 Key43 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY44          (3)                     /* Mutual 1 Key44 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY45          (3)                     /* Mutual 1 Key45 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY46          (3)                     /* Mutual 1 Key46 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY47          (3)                     /* Mutual 1 Key47 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY48          (3)                     /* Mutual 1 Key48 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY49          (3)                     /* Mutual 1 Key49 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY50          (3)                     /* Mutual 1 Key50 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY51          (3)                     /* Mutual 1 Key51 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY52          (3)                     /* Mutual 1 Key52 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY53          (3)                     /* Mutual 1 Key53 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY54          (3)                     /* Mutual 1 Key54 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY55          (3)                     /* Mutual 1 Key55 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY56          (3)                     /* Mutual 1 Key56 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY57          (3)                     /* Mutual 1 Key57 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY58          (3)                     /* Mutual 1 Key58 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY59          (3)                     /* Mutual 1 Key59 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY60          (3)                     /* Mutual 1 Key60 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY61          (3)                     /* Mutual 1 Key61 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY62          (3)                     /* Mutual 1 Key62 CTSUSNUM                            */
#define CTSUSNUM_MUTUAL7_KEY63          (3)                     /* Mutual 1 Key63 CTSUSNUM                            */

#define CTSUSO0_MUTUAL7_KEY00           ((CTSUSNUM_MUTUAL7_KEY00 << 10) | CTSUSO_MUTUAL7_KEY00)
#define CTSUSO0_MUTUAL7_KEY01           ((CTSUSNUM_MUTUAL7_KEY01 << 10) | CTSUSO_MUTUAL7_KEY01)
#define CTSUSO0_MUTUAL7_KEY02           ((CTSUSNUM_MUTUAL7_KEY02 << 10) | CTSUSO_MUTUAL7_KEY02)
#define CTSUSO0_MUTUAL7_KEY03           ((CTSUSNUM_MUTUAL7_KEY03 << 10) | CTSUSO_MUTUAL7_KEY03)
#define CTSUSO0_MUTUAL7_KEY04           ((CTSUSNUM_MUTUAL7_KEY04 << 10) | CTSUSO_MUTUAL7_KEY04)
#define CTSUSO0_MUTUAL7_KEY05           ((CTSUSNUM_MUTUAL7_KEY05 << 10) | CTSUSO_MUTUAL7_KEY05)
#define CTSUSO0_MUTUAL7_KEY06           ((CTSUSNUM_MUTUAL7_KEY06 << 10) | CTSUSO_MUTUAL7_KEY06)
#define CTSUSO0_MUTUAL7_KEY07           ((CTSUSNUM_MUTUAL7_KEY07 << 10) | CTSUSO_MUTUAL7_KEY07)
#define CTSUSO0_MUTUAL7_KEY08           ((CTSUSNUM_MUTUAL7_KEY08 << 10) | CTSUSO_MUTUAL7_KEY08)
#define CTSUSO0_MUTUAL7_KEY09           ((CTSUSNUM_MUTUAL7_KEY09 << 10) | CTSUSO_MUTUAL7_KEY09)
#define CTSUSO0_MUTUAL7_KEY10           ((CTSUSNUM_MUTUAL7_KEY10 << 10) | CTSUSO_MUTUAL7_KEY10)
#define CTSUSO0_MUTUAL7_KEY11           ((CTSUSNUM_MUTUAL7_KEY11 << 10) | CTSUSO_MUTUAL7_KEY11)
#define CTSUSO0_MUTUAL7_KEY12           ((CTSUSNUM_MUTUAL7_KEY12 << 10) | CTSUSO_MUTUAL7_KEY12)
#define CTSUSO0_MUTUAL7_KEY13           ((CTSUSNUM_MUTUAL7_KEY13 << 10) | CTSUSO_MUTUAL7_KEY13)
#define CTSUSO0_MUTUAL7_KEY14           ((CTSUSNUM_MUTUAL7_KEY14 << 10) | CTSUSO_MUTUAL7_KEY14)
#define CTSUSO0_MUTUAL7_KEY15           ((CTSUSNUM_MUTUAL7_KEY15 << 10) | CTSUSO_MUTUAL7_KEY15)
#define CTSUSO0_MUTUAL7_KEY16           ((CTSUSNUM_MUTUAL7_KEY16 << 10) | CTSUSO_MUTUAL7_KEY16)
#define CTSUSO0_MUTUAL7_KEY17           ((CTSUSNUM_MUTUAL7_KEY17 << 10) | CTSUSO_MUTUAL7_KEY17)
#define CTSUSO0_MUTUAL7_KEY18           ((CTSUSNUM_MUTUAL7_KEY18 << 10) | CTSUSO_MUTUAL7_KEY18)
#define CTSUSO0_MUTUAL7_KEY19           ((CTSUSNUM_MUTUAL7_KEY19 << 10) | CTSUSO_MUTUAL7_KEY19)
#define CTSUSO0_MUTUAL7_KEY20           ((CTSUSNUM_MUTUAL7_KEY20 << 10) | CTSUSO_MUTUAL7_KEY20)
#define CTSUSO0_MUTUAL7_KEY21           ((CTSUSNUM_MUTUAL7_KEY21 << 10) | CTSUSO_MUTUAL7_KEY21)
#define CTSUSO0_MUTUAL7_KEY22           ((CTSUSNUM_MUTUAL7_KEY22 << 10) | CTSUSO_MUTUAL7_KEY22)
#define CTSUSO0_MUTUAL7_KEY23           ((CTSUSNUM_MUTUAL7_KEY23 << 10) | CTSUSO_MUTUAL7_KEY23)
#define CTSUSO0_MUTUAL7_KEY24           ((CTSUSNUM_MUTUAL7_KEY24 << 10) | CTSUSO_MUTUAL7_KEY24)
#define CTSUSO0_MUTUAL7_KEY25           ((CTSUSNUM_MUTUAL7_KEY25 << 10) | CTSUSO_MUTUAL7_KEY25)
#define CTSUSO0_MUTUAL7_KEY26           ((CTSUSNUM_MUTUAL7_KEY26 << 10) | CTSUSO_MUTUAL7_KEY26)
#define CTSUSO0_MUTUAL7_KEY27           ((CTSUSNUM_MUTUAL7_KEY27 << 10) | CTSUSO_MUTUAL7_KEY27)
#define CTSUSO0_MUTUAL7_KEY28           ((CTSUSNUM_MUTUAL7_KEY28 << 10) | CTSUSO_MUTUAL7_KEY28)
#define CTSUSO0_MUTUAL7_KEY29           ((CTSUSNUM_MUTUAL7_KEY29 << 10) | CTSUSO_MUTUAL7_KEY29)
#define CTSUSO0_MUTUAL7_KEY30           ((CTSUSNUM_MUTUAL7_KEY30 << 10) | CTSUSO_MUTUAL7_KEY30)
#define CTSUSO0_MUTUAL7_KEY31           ((CTSUSNUM_MUTUAL7_KEY31 << 10) | CTSUSO_MUTUAL7_KEY31)
#define CTSUSO0_MUTUAL7_KEY32           ((CTSUSNUM_MUTUAL7_KEY32 << 10) | CTSUSO_MUTUAL7_KEY32)
#define CTSUSO0_MUTUAL7_KEY33           ((CTSUSNUM_MUTUAL7_KEY33 << 10) | CTSUSO_MUTUAL7_KEY33)
#define CTSUSO0_MUTUAL7_KEY34           ((CTSUSNUM_MUTUAL7_KEY34 << 10) | CTSUSO_MUTUAL7_KEY34)
#define CTSUSO0_MUTUAL7_KEY35           ((CTSUSNUM_MUTUAL7_KEY35 << 10) | CTSUSO_MUTUAL7_KEY35)
#define CTSUSO0_MUTUAL7_KEY36           ((CTSUSNUM_MUTUAL7_KEY36 << 10) | CTSUSO_MUTUAL7_KEY36)
#define CTSUSO0_MUTUAL7_KEY37           ((CTSUSNUM_MUTUAL7_KEY37 << 10) | CTSUSO_MUTUAL7_KEY37)
#define CTSUSO0_MUTUAL7_KEY38           ((CTSUSNUM_MUTUAL7_KEY38 << 10) | CTSUSO_MUTUAL7_KEY38)
#define CTSUSO0_MUTUAL7_KEY39           ((CTSUSNUM_MUTUAL7_KEY39 << 10) | CTSUSO_MUTUAL7_KEY39)
#define CTSUSO0_MUTUAL7_KEY40           ((CTSUSNUM_MUTUAL7_KEY40 << 10) | CTSUSO_MUTUAL7_KEY40)
#define CTSUSO0_MUTUAL7_KEY41           ((CTSUSNUM_MUTUAL7_KEY41 << 10) | CTSUSO_MUTUAL7_KEY41)
#define CTSUSO0_MUTUAL7_KEY42           ((CTSUSNUM_MUTUAL7_KEY42 << 10) | CTSUSO_MUTUAL7_KEY42)
#define CTSUSO0_MUTUAL7_KEY43           ((CTSUSNUM_MUTUAL7_KEY43 << 10) | CTSUSO_MUTUAL7_KEY43)
#define CTSUSO0_MUTUAL7_KEY44           ((CTSUSNUM_MUTUAL7_KEY44 << 10) | CTSUSO_MUTUAL7_KEY44)
#define CTSUSO0_MUTUAL7_KEY45           ((CTSUSNUM_MUTUAL7_KEY45 << 10) | CTSUSO_MUTUAL7_KEY45)
#define CTSUSO0_MUTUAL7_KEY46           ((CTSUSNUM_MUTUAL7_KEY46 << 10) | CTSUSO_MUTUAL7_KEY46)
#define CTSUSO0_MUTUAL7_KEY47           ((CTSUSNUM_MUTUAL7_KEY47 << 10) | CTSUSO_MUTUAL7_KEY47)
#define CTSUSO0_MUTUAL7_KEY48           ((CTSUSNUM_MUTUAL7_KEY48 << 10) | CTSUSO_MUTUAL7_KEY48)
#define CTSUSO0_MUTUAL7_KEY49           ((CTSUSNUM_MUTUAL7_KEY49 << 10) | CTSUSO_MUTUAL7_KEY49)
#define CTSUSO0_MUTUAL7_KEY50           ((CTSUSNUM_MUTUAL7_KEY50 << 10) | CTSUSO_MUTUAL7_KEY50)
#define CTSUSO0_MUTUAL7_KEY51           ((CTSUSNUM_MUTUAL7_KEY51 << 10) | CTSUSO_MUTUAL7_KEY51)
#define CTSUSO0_MUTUAL7_KEY52           ((CTSUSNUM_MUTUAL7_KEY52 << 10) | CTSUSO_MUTUAL7_KEY52)
#define CTSUSO0_MUTUAL7_KEY53           ((CTSUSNUM_MUTUAL7_KEY53 << 10) | CTSUSO_MUTUAL7_KEY53)
#define CTSUSO0_MUTUAL7_KEY54           ((CTSUSNUM_MUTUAL7_KEY54 << 10) | CTSUSO_MUTUAL7_KEY54)
#define CTSUSO0_MUTUAL7_KEY55           ((CTSUSNUM_MUTUAL7_KEY55 << 10) | CTSUSO_MUTUAL7_KEY55)
#define CTSUSO0_MUTUAL7_KEY56           ((CTSUSNUM_MUTUAL7_KEY56 << 10) | CTSUSO_MUTUAL7_KEY56)
#define CTSUSO0_MUTUAL7_KEY57           ((CTSUSNUM_MUTUAL7_KEY57 << 10) | CTSUSO_MUTUAL7_KEY57)
#define CTSUSO0_MUTUAL7_KEY58           ((CTSUSNUM_MUTUAL7_KEY58 << 10) | CTSUSO_MUTUAL7_KEY58)
#define CTSUSO0_MUTUAL7_KEY59           ((CTSUSNUM_MUTUAL7_KEY59 << 10) | CTSUSO_MUTUAL7_KEY59)
#define CTSUSO0_MUTUAL7_KEY60           ((CTSUSNUM_MUTUAL7_KEY60 << 10) | CTSUSO_MUTUAL7_KEY60)
#define CTSUSO0_MUTUAL7_KEY61           ((CTSUSNUM_MUTUAL7_KEY61 << 10) | CTSUSO_MUTUAL7_KEY61)
#define CTSUSO0_MUTUAL7_KEY62           ((CTSUSNUM_MUTUAL7_KEY62 << 10) | CTSUSO_MUTUAL7_KEY62)
#define CTSUSO0_MUTUAL7_KEY63           ((CTSUSNUM_MUTUAL7_KEY63 << 10) | CTSUSO_MUTUAL7_KEY63)

/*****    Address 000A 0914h CTSU Sensor Offset Register 1    *********************************************************/
/**********************************************************************************************************************/
/*    CTSU Reference ICO Current Adjustment                                                                           */
/*        Input current amount 0      0x00                                                                            */
/*        Input current amount 1      0x01                                                                            */
/*        Input current amount 2      0x02                                                                            */
/*                     :                                                                                              */
/*                     :                                                                                              */
/*        Input current amount 254    0xFF                                                                            */
/**********************************************************************************************************************/
#define CTSURICOA_MUTUAL7_KEY00         (0x3F)                  /* Mutual 1 Key00 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY01         (0x3F)                  /* Mutual 1 Key01 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY02         (0x3F)                  /* Mutual 1 Key02 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY03         (0x3F)                  /* Mutual 1 Key03 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY04         (0x3F)                  /* Mutual 1 Key04 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY05         (0x3F)                  /* Mutual 1 Key05 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY06         (0x3F)                  /* Mutual 1 Key06 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY07         (0x3F)                  /* Mutual 1 Key07 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY08         (0x3F)                  /* Mutual 1 Key08 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY09         (0x3F)                  /* Mutual 1 Key09 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY10         (0x3F)                  /* Mutual 1 Key10 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY11         (0x3F)                  /* Mutual 1 Key11 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY12         (0x3F)                  /* Mutual 1 Key12 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY13         (0x3F)                  /* Mutual 1 Key13 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY14         (0x3F)                  /* Mutual 1 Key14 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY15         (0x3F)                  /* Mutual 1 Key15 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY16         (0x3F)                  /* Mutual 1 Key16 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY17         (0x3F)                  /* Mutual 1 Key17 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY18         (0x3F)                  /* Mutual 1 Key18 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY19         (0x3F)                  /* Mutual 1 Key19 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY20         (0x3F)                  /* Mutual 1 Key20 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY21         (0x3F)                  /* Mutual 1 Key21 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY22         (0x3F)                  /* Mutual 1 Key22 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY23         (0x3F)                  /* Mutual 1 Key23 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY24         (0x3F)                  /* Mutual 1 Key24 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY25         (0x3F)                  /* Mutual 1 Key25 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY26         (0x3F)                  /* Mutual 1 Key26 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY27         (0x3F)                  /* Mutual 1 Key27 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY28         (0x3F)                  /* Mutual 1 Key28 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY29         (0x3F)                  /* Mutual 1 Key29 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY30         (0x3F)                  /* Mutual 1 Key30 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY31         (0x3F)                  /* Mutual 1 Key31 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY32         (0x3F)                  /* Mutual 1 Key32 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY33         (0x3F)                  /* Mutual 1 Key33 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY34         (0x3F)                  /* Mutual 1 Key34 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY35         (0x3F)                  /* Mutual 1 Key35 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY36         (0x3F)                  /* Mutual 1 Key36 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY37         (0x3F)                  /* Mutual 1 Key37 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY38         (0x3F)                  /* Mutual 1 Key38 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY39         (0x3F)                  /* Mutual 1 Key39 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY40         (0x3F)                  /* Mutual 1 Key40 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY41         (0x3F)                  /* Mutual 1 Key41 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY42         (0x3F)                  /* Mutual 1 Key42 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY43         (0x3F)                  /* Mutual 1 Key43 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY44         (0x3F)                  /* Mutual 1 Key44 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY45         (0x3F)                  /* Mutual 1 Key45 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY46         (0x3F)                  /* Mutual 1 Key46 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY47         (0x3F)                  /* Mutual 1 Key47 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY48         (0x3F)                  /* Mutual 1 Key48 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY49         (0x3F)                  /* Mutual 1 Key49 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY50         (0x3F)                  /* Mutual 1 Key50 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY51         (0x3F)                  /* Mutual 1 Key51 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY52         (0x3F)                  /* Mutual 1 Key52 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY53         (0x3F)                  /* Mutual 1 Key53 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY54         (0x3F)                  /* Mutual 1 Key54 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY55         (0x3F)                  /* Mutual 1 Key55 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY56         (0x3F)                  /* Mutual 1 Key56 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY57         (0x3F)                  /* Mutual 1 Key57 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY58         (0x3F)                  /* Mutual 1 Key58 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY59         (0x3F)                  /* Mutual 1 Key59 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY60         (0x3F)                  /* Mutual 1 Key60 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY61         (0x3F)                  /* Mutual 1 Key61 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY62         (0x3F)                  /* Mutual 1 Key62 CTSUICOA                            */
#define CTSURICOA_MUTUAL7_KEY63         (0x3F)                  /* Mutual 1 Key63 CTSUICOA                            */

/**********************************************************************************************************************/
/*    CTSU Base Clock Setting                                                                                         */
/*        Operating clock divided by 2     0x00                                                                       */
/*        Operating clock divided by 4     0x01                                                                       */
/*        Operating clock divided by 6     0x02                                                                       */
/*                       :                                                                                            */
/*                       :                                                                                            */
/*        Operating clock divided by 64    0x1F                                                                       */
/*                                                                                                                    */
/*    Case : CTSU Operating Clock 32MHz      Case : CTSU Operating Clock 24MHz      Case : CTSU Operating Clock 16MHz */
/*           4.0MHz <--- 0x03                       4.0MHz <--- 0x02                       4.0MHz <--- 0x01           */
/*           2.0MHz <--- 0x07                       2.0MHz <--- 0x05                       2.0MHz <--- 0x03           */
/*           1.0MHz <--- 0x0F                       1.0MHz <--- 0x0B                       1.0MHz <--- 0x07           */
/*           0.5MHz <--- 0x1F                       0.5MHz <--- 0x17                       0.5MHz <--- 0x0F           */
/**********************************************************************************************************************/
#define CTSUSDPA_MUTUAL7_KEY00          (7)                     /* Mutual 1 Key00 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY01          (7)                     /* Mutual 1 Key01 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY02          (7)                     /* Mutual 1 Key02 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY03          (7)                     /* Mutual 1 Key03 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY04          (7)                     /* Mutual 1 Key04 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY05          (7)                     /* Mutual 1 Key05 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY06          (7)                     /* Mutual 1 Key06 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY07          (7)                     /* Mutual 1 Key07 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY08          (7)                     /* Mutual 1 Key08 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY09          (7)                     /* Mutual 1 Key09 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY10          (7)                     /* Mutual 1 Key10 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY11          (7)                     /* Mutual 1 Key11 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY12          (7)                     /* Mutual 1 Key12 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY13          (7)                     /* Mutual 1 Key13 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY14          (7)                     /* Mutual 1 Key14 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY15          (7)                     /* Mutual 1 Key15 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY16          (7)                     /* Mutual 1 Key16 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY17          (7)                     /* Mutual 1 Key17 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY18          (7)                     /* Mutual 1 Key18 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY19          (7)                     /* Mutual 1 Key19 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY20          (7)                     /* Mutual 1 Key20 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY21          (7)                     /* Mutual 1 Key21 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY22          (7)                     /* Mutual 1 Key22 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY23          (7)                     /* Mutual 1 Key23 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY24          (7)                     /* Mutual 1 Key24 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY25          (7)                     /* Mutual 1 Key25 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY26          (7)                     /* Mutual 1 Key26 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY27          (7)                     /* Mutual 1 Key27 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY28          (7)                     /* Mutual 1 Key28 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY29          (7)                     /* Mutual 1 Key29 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY30          (7)                     /* Mutual 1 Key30 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY31          (7)                     /* Mutual 1 Key31 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY32          (7)                     /* Mutual 1 Key32 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY33          (7)                     /* Mutual 1 Key33 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY34          (7)                     /* Mutual 1 Key34 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY35          (7)                     /* Mutual 1 Key35 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY36          (7)                     /* Mutual 1 Key36 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY37          (7)                     /* Mutual 1 Key37 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY38          (7)                     /* Mutual 1 Key38 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY39          (7)                     /* Mutual 1 Key39 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY40          (7)                     /* Mutual 1 Key40 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY41          (7)                     /* Mutual 1 Key41 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY42          (7)                     /* Mutual 1 Key42 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY43          (7)                     /* Mutual 1 Key43 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY44          (7)                     /* Mutual 1 Key44 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY45          (7)                     /* Mutual 1 Key45 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY46          (7)                     /* Mutual 1 Key46 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY47          (7)                     /* Mutual 1 Key47 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY48          (7)                     /* Mutual 1 Key48 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY49          (7)                     /* Mutual 1 Key49 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY50          (7)                     /* Mutual 1 Key50 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY51          (7)                     /* Mutual 1 Key51 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY52          (7)                     /* Mutual 1 Key52 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY53          (7)                     /* Mutual 1 Key53 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY54          (7)                     /* Mutual 1 Key54 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY55          (7)                     /* Mutual 1 Key55 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY56          (7)                     /* Mutual 1 Key56 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY57          (7)                     /* Mutual 1 Key57 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY58          (7)                     /* Mutual 1 Key58 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY59          (7)                     /* Mutual 1 Key59 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY60          (7)                     /* Mutual 1 Key60 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY61          (7)                     /* Mutual 1 Key61 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY62          (7)                     /* Mutual 1 Key62 CTSUDPA                             */
#define CTSUSDPA_MUTUAL7_KEY63          (7)                     /* Mutual 1 Key63 CTSUDPA                             */

/**********************************************************************************************************************/
/*    CTSU ICO Gain Adjustment                                                                                        */
/*        0 : 100% gain                                                                                               */
/*        1 :  66% gain                                                                                               */
/*        2 :  50% gain                                                                                               */
/*        3 :  40% gain                                                                                               */
/**********************************************************************************************************************/
#define CTSUICOG_MUTUAL7_KEY00          (1)                     /* Mutual 7 Key00 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY01          (1)                     /* Mutual 7 Key01 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY02          (1)                     /* Mutual 7 Key02 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY03          (1)                     /* Mutual 7 Key03 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY04          (1)                     /* Mutual 7 Key04 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY05          (1)                     /* Mutual 7 Key05 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY06          (1)                     /* Mutual 7 Key06 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY07          (1)                     /* Mutual 7 Key07 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY08          (1)                     /* Mutual 7 Key08 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY09          (1)                     /* Mutual 7 Key09 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY10          (1)                     /* Mutual 7 Key10 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY11          (1)                     /* Mutual 7 Key11 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY12          (1)                     /* Mutual 7 Key12 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY13          (1)                     /* Mutual 7 Key13 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY14          (1)                     /* Mutual 7 Key14 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY15          (1)                     /* Mutual 7 Key15 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY16          (1)                     /* Mutual 7 Key16 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY17          (1)                     /* Mutual 7 Key17 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY18          (1)                     /* Mutual 7 Key18 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY19          (1)                     /* Mutual 7 Key19 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY20          (1)                     /* Mutual 7 Key20 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY21          (1)                     /* Mutual 7 Key21 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY22          (1)                     /* Mutual 7 Key22 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY23          (1)                     /* Mutual 7 Key23 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY24          (1)                     /* Mutual 7 Key24 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY25          (1)                     /* Mutual 7 Key25 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY26          (1)                     /* Mutual 7 Key26 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY27          (1)                     /* Mutual 7 Key27 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY28          (1)                     /* Mutual 7 Key28 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY29          (1)                     /* Mutual 7 Key29 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY30          (1)                     /* Mutual 7 Key30 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY31          (1)                     /* Mutual 7 Key31 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY32          (1)                     /* Mutual 7 Key32 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY33          (1)                     /* Mutual 7 Key33 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY34          (1)                     /* Mutual 7 Key34 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY35          (1)                     /* Mutual 7 Key35 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY36          (1)                     /* Mutual 7 Key36 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY37          (1)                     /* Mutual 7 Key37 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY38          (1)                     /* Mutual 7 Key38 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY39          (1)                     /* Mutual 7 Key39 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY40          (1)                     /* Mutual 7 Key40 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY41          (1)                     /* Mutual 7 Key41 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY42          (1)                     /* Mutual 7 Key42 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY43          (1)                     /* Mutual 7 Key43 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY44          (1)                     /* Mutual 7 Key44 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY45          (1)                     /* Mutual 7 Key45 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY46          (1)                     /* Mutual 7 Key46 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY47          (1)                     /* Mutual 7 Key47 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY48          (1)                     /* Mutual 7 Key48 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY49          (1)                     /* Mutual 7 Key49 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY50          (1)                     /* Mutual 7 Key50 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY51          (1)                     /* Mutual 7 Key51 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY52          (1)                     /* Mutual 7 Key52 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY53          (1)                     /* Mutual 7 Key53 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY54          (1)                     /* Mutual 7 Key54 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY55          (1)                     /* Mutual 7 Key55 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY56          (1)                     /* Mutual 7 Key56 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY57          (1)                     /* Mutual 7 Key57 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY58          (1)                     /* Mutual 7 Key58 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY59          (1)                     /* Mutual 7 Key59 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY60          (1)                     /* Mutual 7 Key60 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY61          (1)                     /* Mutual 7 Key61 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY62          (1)                     /* Mutual 7 Key62 CTSICOG                             */
#define CTSUICOG_MUTUAL7_KEY63          (1)                     /* Mutual 7 Key63 CTSICOG                             */

#define CTSUSO1_MUTUAL7_KEY00  ((CTSUICOG_MUTUAL7_KEY00 << 13) | (CTSUSDPA_MUTUAL7_KEY00 << 8) | CTSURICOA_MUTUAL7_KEY00)
#define CTSUSO1_MUTUAL7_KEY01  ((CTSUICOG_MUTUAL7_KEY01 << 13) | (CTSUSDPA_MUTUAL7_KEY01 << 8) | CTSURICOA_MUTUAL7_KEY01)
#define CTSUSO1_MUTUAL7_KEY02  ((CTSUICOG_MUTUAL7_KEY02 << 13) | (CTSUSDPA_MUTUAL7_KEY02 << 8) | CTSURICOA_MUTUAL7_KEY02)
#define CTSUSO1_MUTUAL7_KEY03  ((CTSUICOG_MUTUAL7_KEY03 << 13) | (CTSUSDPA_MUTUAL7_KEY03 << 8) | CTSURICOA_MUTUAL7_KEY03)
#define CTSUSO1_MUTUAL7_KEY04  ((CTSUICOG_MUTUAL7_KEY04 << 13) | (CTSUSDPA_MUTUAL7_KEY04 << 8) | CTSURICOA_MUTUAL7_KEY04)
#define CTSUSO1_MUTUAL7_KEY05  ((CTSUICOG_MUTUAL7_KEY05 << 13) | (CTSUSDPA_MUTUAL7_KEY05 << 8) | CTSURICOA_MUTUAL7_KEY05)
#define CTSUSO1_MUTUAL7_KEY06  ((CTSUICOG_MUTUAL7_KEY06 << 13) | (CTSUSDPA_MUTUAL7_KEY06 << 8) | CTSURICOA_MUTUAL7_KEY06)
#define CTSUSO1_MUTUAL7_KEY07  ((CTSUICOG_MUTUAL7_KEY07 << 13) | (CTSUSDPA_MUTUAL7_KEY07 << 8) | CTSURICOA_MUTUAL7_KEY07)
#define CTSUSO1_MUTUAL7_KEY08  ((CTSUICOG_MUTUAL7_KEY08 << 13) | (CTSUSDPA_MUTUAL7_KEY08 << 8) | CTSURICOA_MUTUAL7_KEY08)
#define CTSUSO1_MUTUAL7_KEY09  ((CTSUICOG_MUTUAL7_KEY09 << 13) | (CTSUSDPA_MUTUAL7_KEY09 << 8) | CTSURICOA_MUTUAL7_KEY09)
#define CTSUSO1_MUTUAL7_KEY10  ((CTSUICOG_MUTUAL7_KEY10 << 13) | (CTSUSDPA_MUTUAL7_KEY10 << 8) | CTSURICOA_MUTUAL7_KEY10)
#define CTSUSO1_MUTUAL7_KEY11  ((CTSUICOG_MUTUAL7_KEY11 << 13) | (CTSUSDPA_MUTUAL7_KEY11 << 8) | CTSURICOA_MUTUAL7_KEY11)
#define CTSUSO1_MUTUAL7_KEY12  ((CTSUICOG_MUTUAL7_KEY12 << 13) | (CTSUSDPA_MUTUAL7_KEY12 << 8) | CTSURICOA_MUTUAL7_KEY12)
#define CTSUSO1_MUTUAL7_KEY13  ((CTSUICOG_MUTUAL7_KEY13 << 13) | (CTSUSDPA_MUTUAL7_KEY13 << 8) | CTSURICOA_MUTUAL7_KEY13)
#define CTSUSO1_MUTUAL7_KEY14  ((CTSUICOG_MUTUAL7_KEY14 << 13) | (CTSUSDPA_MUTUAL7_KEY14 << 8) | CTSURICOA_MUTUAL7_KEY14)
#define CTSUSO1_MUTUAL7_KEY15  ((CTSUICOG_MUTUAL7_KEY15 << 13) | (CTSUSDPA_MUTUAL7_KEY15 << 8) | CTSURICOA_MUTUAL7_KEY15)
#define CTSUSO1_MUTUAL7_KEY16  ((CTSUICOG_MUTUAL7_KEY16 << 13) | (CTSUSDPA_MUTUAL7_KEY16 << 8) | CTSURICOA_MUTUAL7_KEY16)
#define CTSUSO1_MUTUAL7_KEY17  ((CTSUICOG_MUTUAL7_KEY17 << 13) | (CTSUSDPA_MUTUAL7_KEY17 << 8) | CTSURICOA_MUTUAL7_KEY17)
#define CTSUSO1_MUTUAL7_KEY18  ((CTSUICOG_MUTUAL7_KEY18 << 13) | (CTSUSDPA_MUTUAL7_KEY18 << 8) | CTSURICOA_MUTUAL7_KEY18)
#define CTSUSO1_MUTUAL7_KEY19  ((CTSUICOG_MUTUAL7_KEY19 << 13) | (CTSUSDPA_MUTUAL7_KEY19 << 8) | CTSURICOA_MUTUAL7_KEY19)
#define CTSUSO1_MUTUAL7_KEY20  ((CTSUICOG_MUTUAL7_KEY20 << 13) | (CTSUSDPA_MUTUAL7_KEY20 << 8) | CTSURICOA_MUTUAL7_KEY20)
#define CTSUSO1_MUTUAL7_KEY21  ((CTSUICOG_MUTUAL7_KEY21 << 13) | (CTSUSDPA_MUTUAL7_KEY21 << 8) | CTSURICOA_MUTUAL7_KEY21)
#define CTSUSO1_MUTUAL7_KEY22  ((CTSUICOG_MUTUAL7_KEY22 << 13) | (CTSUSDPA_MUTUAL7_KEY22 << 8) | CTSURICOA_MUTUAL7_KEY22)
#define CTSUSO1_MUTUAL7_KEY23  ((CTSUICOG_MUTUAL7_KEY23 << 13) | (CTSUSDPA_MUTUAL7_KEY23 << 8) | CTSURICOA_MUTUAL7_KEY23)
#define CTSUSO1_MUTUAL7_KEY24  ((CTSUICOG_MUTUAL7_KEY24 << 13) | (CTSUSDPA_MUTUAL7_KEY24 << 8) | CTSURICOA_MUTUAL7_KEY24)
#define CTSUSO1_MUTUAL7_KEY25  ((CTSUICOG_MUTUAL7_KEY25 << 13) | (CTSUSDPA_MUTUAL7_KEY25 << 8) | CTSURICOA_MUTUAL7_KEY25)
#define CTSUSO1_MUTUAL7_KEY26  ((CTSUICOG_MUTUAL7_KEY26 << 13) | (CTSUSDPA_MUTUAL7_KEY26 << 8) | CTSURICOA_MUTUAL7_KEY26)
#define CTSUSO1_MUTUAL7_KEY27  ((CTSUICOG_MUTUAL7_KEY27 << 13) | (CTSUSDPA_MUTUAL7_KEY27 << 8) | CTSURICOA_MUTUAL7_KEY27)
#define CTSUSO1_MUTUAL7_KEY28  ((CTSUICOG_MUTUAL7_KEY28 << 13) | (CTSUSDPA_MUTUAL7_KEY28 << 8) | CTSURICOA_MUTUAL7_KEY28)
#define CTSUSO1_MUTUAL7_KEY29  ((CTSUICOG_MUTUAL7_KEY29 << 13) | (CTSUSDPA_MUTUAL7_KEY29 << 8) | CTSURICOA_MUTUAL7_KEY29)
#define CTSUSO1_MUTUAL7_KEY30  ((CTSUICOG_MUTUAL7_KEY30 << 13) | (CTSUSDPA_MUTUAL7_KEY30 << 8) | CTSURICOA_MUTUAL7_KEY30)
#define CTSUSO1_MUTUAL7_KEY31  ((CTSUICOG_MUTUAL7_KEY31 << 13) | (CTSUSDPA_MUTUAL7_KEY31 << 8) | CTSURICOA_MUTUAL7_KEY31)
#define CTSUSO1_MUTUAL7_KEY32  ((CTSUICOG_MUTUAL7_KEY32 << 13) | (CTSUSDPA_MUTUAL7_KEY32 << 8) | CTSURICOA_MUTUAL7_KEY32)
#define CTSUSO1_MUTUAL7_KEY33  ((CTSUICOG_MUTUAL7_KEY33 << 13) | (CTSUSDPA_MUTUAL7_KEY33 << 8) | CTSURICOA_MUTUAL7_KEY33)
#define CTSUSO1_MUTUAL7_KEY34  ((CTSUICOG_MUTUAL7_KEY34 << 13) | (CTSUSDPA_MUTUAL7_KEY34 << 8) | CTSURICOA_MUTUAL7_KEY34)
#define CTSUSO1_MUTUAL7_KEY35  ((CTSUICOG_MUTUAL7_KEY35 << 13) | (CTSUSDPA_MUTUAL7_KEY35 << 8) | CTSURICOA_MUTUAL7_KEY35)
#define CTSUSO1_MUTUAL7_KEY36  ((CTSUICOG_MUTUAL7_KEY36 << 13) | (CTSUSDPA_MUTUAL7_KEY36 << 8) | CTSURICOA_MUTUAL7_KEY36)
#define CTSUSO1_MUTUAL7_KEY37  ((CTSUICOG_MUTUAL7_KEY37 << 13) | (CTSUSDPA_MUTUAL7_KEY37 << 8) | CTSURICOA_MUTUAL7_KEY37)
#define CTSUSO1_MUTUAL7_KEY38  ((CTSUICOG_MUTUAL7_KEY38 << 13) | (CTSUSDPA_MUTUAL7_KEY38 << 8) | CTSURICOA_MUTUAL7_KEY38)
#define CTSUSO1_MUTUAL7_KEY39  ((CTSUICOG_MUTUAL7_KEY39 << 13) | (CTSUSDPA_MUTUAL7_KEY39 << 8) | CTSURICOA_MUTUAL7_KEY39)
#define CTSUSO1_MUTUAL7_KEY40  ((CTSUICOG_MUTUAL7_KEY40 << 13) | (CTSUSDPA_MUTUAL7_KEY40 << 8) | CTSURICOA_MUTUAL7_KEY40)
#define CTSUSO1_MUTUAL7_KEY41  ((CTSUICOG_MUTUAL7_KEY41 << 13) | (CTSUSDPA_MUTUAL7_KEY41 << 8) | CTSURICOA_MUTUAL7_KEY41)
#define CTSUSO1_MUTUAL7_KEY42  ((CTSUICOG_MUTUAL7_KEY42 << 13) | (CTSUSDPA_MUTUAL7_KEY42 << 8) | CTSURICOA_MUTUAL7_KEY42)
#define CTSUSO1_MUTUAL7_KEY43  ((CTSUICOG_MUTUAL7_KEY43 << 13) | (CTSUSDPA_MUTUAL7_KEY43 << 8) | CTSURICOA_MUTUAL7_KEY43)
#define CTSUSO1_MUTUAL7_KEY44  ((CTSUICOG_MUTUAL7_KEY44 << 13) | (CTSUSDPA_MUTUAL7_KEY44 << 8) | CTSURICOA_MUTUAL7_KEY44)
#define CTSUSO1_MUTUAL7_KEY45  ((CTSUICOG_MUTUAL7_KEY45 << 13) | (CTSUSDPA_MUTUAL7_KEY45 << 8) | CTSURICOA_MUTUAL7_KEY45)
#define CTSUSO1_MUTUAL7_KEY46  ((CTSUICOG_MUTUAL7_KEY46 << 13) | (CTSUSDPA_MUTUAL7_KEY46 << 8) | CTSURICOA_MUTUAL7_KEY46)
#define CTSUSO1_MUTUAL7_KEY47  ((CTSUICOG_MUTUAL7_KEY47 << 13) | (CTSUSDPA_MUTUAL7_KEY47 << 8) | CTSURICOA_MUTUAL7_KEY47)
#define CTSUSO1_MUTUAL7_KEY48  ((CTSUICOG_MUTUAL7_KEY48 << 13) | (CTSUSDPA_MUTUAL7_KEY48 << 8) | CTSURICOA_MUTUAL7_KEY48)
#define CTSUSO1_MUTUAL7_KEY49  ((CTSUICOG_MUTUAL7_KEY49 << 13) | (CTSUSDPA_MUTUAL7_KEY49 << 8) | CTSURICOA_MUTUAL7_KEY49)
#define CTSUSO1_MUTUAL7_KEY50  ((CTSUICOG_MUTUAL7_KEY50 << 13) | (CTSUSDPA_MUTUAL7_KEY50 << 8) | CTSURICOA_MUTUAL7_KEY50)
#define CTSUSO1_MUTUAL7_KEY51  ((CTSUICOG_MUTUAL7_KEY51 << 13) | (CTSUSDPA_MUTUAL7_KEY51 << 8) | CTSURICOA_MUTUAL7_KEY51)
#define CTSUSO1_MUTUAL7_KEY52  ((CTSUICOG_MUTUAL7_KEY52 << 13) | (CTSUSDPA_MUTUAL7_KEY52 << 8) | CTSURICOA_MUTUAL7_KEY52)
#define CTSUSO1_MUTUAL7_KEY53  ((CTSUICOG_MUTUAL7_KEY53 << 13) | (CTSUSDPA_MUTUAL7_KEY53 << 8) | CTSURICOA_MUTUAL7_KEY53)
#define CTSUSO1_MUTUAL7_KEY54  ((CTSUICOG_MUTUAL7_KEY54 << 13) | (CTSUSDPA_MUTUAL7_KEY54 << 8) | CTSURICOA_MUTUAL7_KEY54)
#define CTSUSO1_MUTUAL7_KEY55  ((CTSUICOG_MUTUAL7_KEY55 << 13) | (CTSUSDPA_MUTUAL7_KEY55 << 8) | CTSURICOA_MUTUAL7_KEY55)
#define CTSUSO1_MUTUAL7_KEY56  ((CTSUICOG_MUTUAL7_KEY56 << 13) | (CTSUSDPA_MUTUAL7_KEY56 << 8) | CTSURICOA_MUTUAL7_KEY56)
#define CTSUSO1_MUTUAL7_KEY57  ((CTSUICOG_MUTUAL7_KEY57 << 13) | (CTSUSDPA_MUTUAL7_KEY57 << 8) | CTSURICOA_MUTUAL7_KEY57)
#define CTSUSO1_MUTUAL7_KEY58  ((CTSUICOG_MUTUAL7_KEY58 << 13) | (CTSUSDPA_MUTUAL7_KEY58 << 8) | CTSURICOA_MUTUAL7_KEY58)
#define CTSUSO1_MUTUAL7_KEY59  ((CTSUICOG_MUTUAL7_KEY59 << 13) | (CTSUSDPA_MUTUAL7_KEY59 << 8) | CTSURICOA_MUTUAL7_KEY59)
#define CTSUSO1_MUTUAL7_KEY60  ((CTSUICOG_MUTUAL7_KEY60 << 13) | (CTSUSDPA_MUTUAL7_KEY60 << 8) | CTSURICOA_MUTUAL7_KEY60)
#define CTSUSO1_MUTUAL7_KEY61  ((CTSUICOG_MUTUAL7_KEY61 << 13) | (CTSUSDPA_MUTUAL7_KEY61 << 8) | CTSURICOA_MUTUAL7_KEY61)
#define CTSUSO1_MUTUAL7_KEY62  ((CTSUICOG_MUTUAL7_KEY62 << 13) | (CTSUSDPA_MUTUAL7_KEY62 << 8) | CTSURICOA_MUTUAL7_KEY62)
#define CTSUSO1_MUTUAL7_KEY63  ((CTSUICOG_MUTUAL7_KEY63 << 13) | (CTSUSDPA_MUTUAL7_KEY63 << 8) | CTSURICOA_MUTUAL7_KEY63)
#endif // ( MUTUAL_METHOD_NUM >= 8 )

#if ( SELF_METHOD_NUM == 1 )
    #define SELF_WR_SIZE                (3*SELF_ENABLE_NUM)    /* CTSUSSC, CTSUSO0, CTSUSO1                           */
    #define SELF_RD_SIZE                (SELF_ENABLE_NUM)      /* Sensor counter, Reference counter                   */
#endif    // ( SELF_METHOD_NUM == 1 )

#if ( MUTUAL_METHOD_NUM >= 1 )
    #define MUTUAL0_WR_SIZE             (3*MUTUAL0_NUM)        /* CTSUSSC, CTSUSO0, CTSUSO1                           */
    #define MUTUAL0_RD_SIZE             (MUTUAL0_NUM)          /* Primary sensor counter, Reference sensor counter    */
#endif    // ( MUTUAL_METHOD_NUM >= 1 )

#if ( MUTUAL_METHOD_NUM >= 2 )
    #define MUTUAL1_WR_SIZE             (3*MUTUAL1_NUM)        /* CTSUSSC, CTSUSO0, CTSUSO1                           */
    #define MUTUAL1_RD_SIZE             (MUTUAL1_NUM)          /* Primary sensor counter, Reference sensor counter    */
#endif    // ( MUTUAL_METHOD_NUM >= 2 )

#if ( MUTUAL_METHOD_NUM >= 3 )
    #define MUTUAL2_WR_SIZE             (3*MUTUAL2_NUM)        /* CTSUSSC, CTSUSO0, CTSUSO1                           */
    #define MUTUAL2_RD_SIZE             (MUTUAL2_NUM)          /* Primary sensor counter, Reference sensor counter    */
#endif    // ( MUTUAL_METHOD_NUM >= 3 )

#if ( MUTUAL_METHOD_NUM >= 4 )
    #define MUTUAL3_WR_SIZE             (3*MUTUAL3_NUM)        /* CTSUSSC, CTSUSO0, CTSUSO1                           */
    #define MUTUAL3_RD_SIZE             (MUTUAL3_NUM)          /* Primary sensor counter, Reference sensor counter    */
#endif    // ( MUTUAL_METHOD_NUM >= 4 )

#if ( MUTUAL_METHOD_NUM >= 5 )
    #define MUTUAL4_WR_SIZE             (3*MUTUAL4_NUM)        /* CTSUSSC, CTSUSO0, CTSUSO1                           */
    #define MUTUAL4_RD_SIZE             (MUTUAL4_NUM)          /* Primary sensor counter, Reference sensor counter    */
#endif    // ( MUTUAL_METHOD_NUM >= 5 )

#if ( MUTUAL_METHOD_NUM >= 6 )
    #define MUTUAL5_WR_SIZE             (3*MUTUAL5_NUM)        /* CTSUSSC, CTSUSO0, CTSUSO1                           */
    #define MUTUAL5_RD_SIZE             (MUTUAL5_NUM)          /* Primary sensor counter, Reference sensor counter    */
#endif    // ( MUTUAL_METHOD_NUM >= 6 )

#if ( MUTUAL_METHOD_NUM >= 7 )
    #define MUTUAL6_WR_SIZE             (3*MUTUAL6_NUM)        /* CTSUSSC, CTSUSO0, CTSUSO1                           */
    #define MUTUAL6_RD_SIZE             (MUTUAL6_NUM)          /* Primary sensor counter, Reference sensor counter    */
#endif    // ( MUTUAL_METHOD_NUM >= 7 )

#if ( MUTUAL_METHOD_NUM >= 8 )
    #define MUTUAL7_WR_SIZE             (3*MUTUAL7_NUM)        /* CTSUSSC, CTSUSO0, CTSUSO1                           */
    #define MUTUAL7_RD_SIZE             (MUTUAL7_NUM)          /* Primary sensor counter, Reference sensor counter    */
#endif    // ( MUTUAL_METHOD_NUM >= 8 )

#define SENS_OK                         (0x00)
#define SENS_OVER                       (0x01)
#define REF_OVER                        (0x02)
#define SENS_REF_OVER                   (0x03)

#define GAIN_100                        (0)

#if (GAIN_100 == 1)
    #define TUNING_UPPER_LIMIT          (200)
    #define TUNING_LOWER_LIMIT          (150)
#else
    #define TUNING_UPPER_LIMIT          (150)
    #define TUNING_LOWER_LIMIT          (100)
#endif    // (GAIN_100 == 1)

#define OFFSET_UPPER_LIMIT              (200)
#define OFFSET_LOWER_LIMIT              (150)

#define OFFSET_CNT_PLUS                 (2)
#define OFFSET_CNT_MINUS                (-2)

#define ADD_TIME                        (4)

#define ADD4_WAIT_FREQUENCY             (42)
#define ADD5_WAIT_FREQUENCY             (56)
#define ADD6_WAIT_FREQUENCY             (67)
#define ADD7_WAIT_FREQUENCY             (78)
#define ADD8_WAIT_FREQUENCY             (90)

#define SET_SUCCESS                     (0)
#define SET_ERROR                       (1)

#define PHYSICAL_TS_ERR                 (0)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/
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

typedef union
{
    uint16_t        word;    /* flag data       */
    struct
    {
        uint16_t    ctsupon_sw_error    : 1;    /* bit0  */
        uint16_t    ctsuatune0_error    : 1;    /* bit1  */
        uint16_t    ctsuatune1_error    : 1;    /* bit2  */
        uint16_t    ctsuclk_error       : 1;    /* bit3  */
        uint16_t    ctsumd_error        : 1;    /* bit4  */
        uint16_t    ctsusdprs_error     : 1;    /* bit5  */
        uint16_t    ctsusst_error       : 1;    /* bit6  */
        uint16_t    dummy0_error        : 1;    /* bit7  */
        uint16_t    ctsuchac01_error    : 1;    /* bit8  */
        uint16_t    dummy1_error        : 1;    /* bit9  */
        uint16_t    dummy2_error        : 1;    /* bit10 */
        uint16_t    ctsuchtrc01_error   : 1;    /* bit11 */
        uint16_t    dummy3_error        : 1;    /* bit12 */
        uint16_t    dummy4_error        : 1;    /* bit13 */
        uint16_t    ctsussc_error       : 1;    /* bit14 */
        uint16_t    dummy5_error        : 1;    /* bit15 */
    } bit;
} ctsu_set_error_t;

typedef struct
{
    uint8_t    ctsu_snz;                       /* CTSUCR0    bit1   : CTSUSNZ     setting data storage                */
    uint8_t    ctsu_txvsel;                    /* CTSUCR0    bit7   : CTSUTXVSEL  setting data storage                */
    uint8_t    ctsu_pon;                       /* CTSUCR1    bit0   : CTSUPON     setting data storage                */
    uint8_t    ctsu_sw;                        /* CTSUCR1    bit1   : CTSUCSW     setting data storage                */
    uint8_t    ctsu_atune0;                    /* CTSUCR1    bit2   : CTSUATUNE0  setting data storage                */
    uint8_t    ctsu_atune1;                    /* CTSUCR1    bit3   : CTSUATUNE1  setting data storage                */
    uint8_t    ctsu_clk;                       /* CTSUCR1    bit5-4 : CTSUCLK     setting data storage                */
    uint8_t    ctsu_md;                        /* CTSUCR1    bit6-7 : CTSUMD      setting data storage                */
    uint8_t    ctsu_prratio;                   /* CTSUSDPRS  bit3-0 : CTSUPRRATIO setting data storage                */
    uint8_t    ctsu_prmode;                    /* CTSUSDPRS  bit5-4 : CTSUPRMODE  setting data storage                */
    uint8_t    ctsu_soff;                      /* CTSUSDPRS  bit6   : CTSUSOFF    setting data storage                */
    uint8_t    ctsu_sst;                       /* CTSUSST    bit7-0 : CTSUSST     setting data storage                */
    uint8_t    ctsu_mch0;                      /* CTSUMCH0   bit3-0 : CTSUMCH0    setting data storage                */
    uint16_t   ctsu_chac01;                    /* CTSUCHAC0  bit3-0 : CTSUCHAC0   setting data storage                */
                                               /* CTSUCHAC1  bit7-4 : CTSUCHAC1   setting data storage                */
    uint16_t   ctsu_chac23;                    /* CTSUCHAC2  bit3-0 : CTSUCHAC2   setting data storage                */
                                               /* CTSUCHAC3  bit7-4 : CTSUCHAC3   setting data storage                */
    uint16_t   ctsu_chac4;                     /* CTSUCHAC4  bit3-0 : CTSUCHAC4   setting data storage                */
    uint16_t   ctsu_chtrc01;                   /* CTSUCHTRC0 bit3-0 : CTSUCHTRC0  setting data storage                */
                                               /* CTSUCHTRC1 bit7-4 : CTSUCHTRC1  setting data storage                */
    uint16_t   ctsu_chtrc23;                   /* CTSUCHTRC0 bit3-0 : CTSUCHTRC2  setting data storage                */
                                               /* CTSUCHTRC1 bit7-4 : CTSUCHTRC3  setting data storage                */
    uint16_t   ctsu_chtrc4;                    /* CTSUCHTRC0 bit3-0 : CTSUCHTRC4  setting data storage                */
    uint8_t    ctsu_ssmod;                     /* CTSUDCLKC  bit1-0 : CTSUSSMOD   setting data storage                */
    uint8_t    ctsu_sscnt;                     /* CTSUDCLKC  bit5-4 : CTSUSSCNT   setting data storage                */
} ctsu_register_data_t;

typedef struct
{
    const uint16_t   *ctsu_ssc;                /* CTSUCR1    bit0   : CTSUPON     setting data storage                */
    const uint16_t   *ctsu_so0;                /* CTSUCR1    bit1   : CTSUCSW     setting data storage                */
    const uint16_t   *ctsu_so1;                /* CTSUCR1    bit0   : CTSUPON     setting data storage                */
} ctsu_transmit_data_t;

typedef struct
{
    uint16_t    sen;                           /* DTC ---> Sensor counter data                                        */
    uint16_t    ref;                           /* DTC ---> Reference counter data                                     */
} self_ico_t;

typedef struct
{
    uint16_t    pri_sen;                       /* DTC ---> Primary sensor data                                        */
    uint16_t    pri_ref;                       /* DTC ---> Primary reference data                                     */
    uint16_t    snd_sen;                       /* DTC ---> Secondary sensor data                                      */
    uint16_t    snd_ref;                       /* DTC ---> Secondary reference data                                   */
} mutual_ico_t;

/***********************************************************************************************************************
Global variables
***********************************************************************************************************************/
#endif    // __R_CTSU_H__

/***********************************************************************************************************************
* End of File
***********************************************************************************************************************/
