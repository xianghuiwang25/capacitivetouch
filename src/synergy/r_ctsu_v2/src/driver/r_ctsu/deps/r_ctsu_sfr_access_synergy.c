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
 * File Name    : r_ctsu_sfr_access_synergy.c
 * Version      : 1.0 <- Optional as long as history is shown below
 * Description  : This module solves all the world's problems
 ***********************************************************************************************************************/
/**********************************************************************************************************************
 * History : DD.MM.YYYY Version  Description
 *         : 15.01.2007 1.00     First Release
 ***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
 ***********************************************************************************************************************/

#include "r_cgc_api.h"
#include "../hw/r_ctsu_sfr_access_synergy.h"
/***********************************************************************************************************************
Macro definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
Private global variables and functions
 ***********************************************************************************************************************/

uint8_t HW_CTSU_CTSUCR0Get(void) {
    return R_CTSU->CTSUCR0;
}
uint8_t HW_CTSU_CTSUCR1Get(void) {
    return R_CTSU->CTSUCR1;
}
uint8_t HW_CTSU_CTSUSDPRSGet(void) {
    return R_CTSU->CTSUSDPRS;
}
uint8_t HW_CTSU_CTSUSSTGet(void) {
    return R_CTSU->CTSUSST;
}
uint8_t HW_CTSU_CTSUMCH0Get(void) {
    return R_CTSU->CTSUMCH0;
}
uint8_t HW_CTSU_CTSUMCH1Get(void) {
    return R_CTSU->CTSUMCH1;
}
uint8_t HW_CTSU_CTSUCHAC0Get(void) {
    return R_CTSU->CTSUCHAC0;
}
uint8_t HW_CTSU_CTSUCHAC1Get(void) {
    return R_CTSU->CTSUCHAC1;
}
#if !defined(BSP_MCU_RX113)
uint8_t HW_CTSU_CTSUCHAC2Get(void) {
    return R_CTSU->CTSUCHAC2;
}
uint8_t HW_CTSU_CTSUCHAC3Get(void) {
    return R_CTSU->CTSUCHAC3;
}
uint8_t HW_CTSU_CTSUCHAC4Get(void) {
    return R_CTSU->CTSUCHAC4;
}
#endif
uint8_t HW_CTSU_CTSUCHTRC0Get(void) {
    return R_CTSU->CTSUCHTRC0;
}
uint8_t HW_CTSU_CTSUCHTRC1Get(void) {
    return R_CTSU->CTSUCHTRC1;
}
#if !defined(BSP_MCU_RX113)
uint8_t HW_CTSU_CTSUCHTRC2Get(void) {
    return R_CTSU->CTSUCHTRC2;
}
uint8_t HW_CTSU_CTSUCHTRC3Get(void) {
    return R_CTSU->CTSUCHTRC3;
}
uint8_t HW_CTSU_CTSUCHTRC4Get(void) {
    return R_CTSU->CTSUCHTRC4;
}
#endif
uint8_t HW_CTSU_CTSUDCLKCGet(void) {
    return R_CTSU->CTSUDCLKC;
}
uint8_t HW_CTSU_CTSUSTGet(void) {
    return R_CTSU->CTSUST;
}
uint16_t HW_CTSU_CTSUSCGet(void) {
    return R_CTSU->CTSUSC;
}
uint16_t HW_CTSU_CTSURCGet(void) {
    return R_CTSU->CTSURC;
}
uint16_t HW_CTSU_CTSUERRSGet(void) {
    return R_CTSU->CTSUERRS;
}
/*
 * Set SFRs
 */
void HW_CTSU_CTSUCR0Set(uint8_t value) {
    R_CTSU->CTSUCR0 = value;
}
void HW_CTSU_CTSUCR1Set(uint8_t value) {
    R_CTSU->CTSUCR1 = value;
}
void HW_CTSU_CTSUSDPRSSet(uint8_t value) {
    R_CTSU->CTSUSDPRS = value;
}
void HW_CTSU_CTSUSSTSet(uint8_t value) {
    R_CTSU->CTSUSST = value;
}
void HW_CTSU_CTSUMCH0Set(uint8_t value) {
    R_CTSU->CTSUMCH0 = value;
}
void HW_CTSU_CTSUMCH1Set(uint8_t value) {
    R_CTSU->CTSUMCH1 = value;
}
void HW_CTSU_CTSUCHAC0Set(uint8_t value) {
    R_CTSU->CTSUCHAC0 = value;
}
void HW_CTSU_CTSUCHAC1Set(uint8_t value) {
    R_CTSU->CTSUCHAC1 = value;
}
#if !defined(BSP_MCU_RX113)
void HW_CTSU_CTSUCHAC2Set(uint8_t value) {
    R_CTSU->CTSUCHAC2 = value;
}
void HW_CTSU_CTSUCHAC3Set(uint8_t value) {
    R_CTSU->CTSUCHAC3 = value;
}
void HW_CTSU_CTSUCHAC4Set(uint8_t value) {
    R_CTSU->CTSUCHAC4 = value;
}
#endif
void HW_CTSU_CTSUCHTRC0Set(uint8_t value) {
    R_CTSU->CTSUCHTRC0 = value;
}
void HW_CTSU_CTSUCHTRC1Set(uint8_t value) {
    R_CTSU->CTSUCHTRC1 = value;
}
#if !defined(BSP_MCU_RX113)
void HW_CTSU_CTSUCHTRC2Set(uint8_t value) {
    R_CTSU->CTSUCHTRC2 = value;
}
void HW_CTSU_CTSUCHTRC3Set(uint8_t value) {
    R_CTSU->CTSUCHTRC3 = value;
}
void HW_CTSU_CTSUCHTRC4Set(uint8_t value) {
    R_CTSU->CTSUCHTRC4 = value;
}
#endif
void HW_CTSU_CTSUDCLKCSet(uint8_t value) {
    R_CTSU->CTSUDCLKC = value;
}
void HW_CTSU_CTSUSTSet(uint8_t value) {
    R_CTSU->CTSUST = value;
}
void HW_CTSU_CTSUSSCSet(uint16_t value) {
    R_CTSU->CTSUSSC = value;
}
void HW_CTSU_CTSUSO0Set(uint16_t value) {
    R_CTSU->CTSUSO0 = value;
}
void HW_CTSU_CTSUSO1Set(uint16_t value) {
    R_CTSU->CTSUSO1 = value;
}
void HW_CTSU_CTSUERRSSet(uint16_t value) {
    R_CTSU->CTSUERRS = value;
}

/*
 * SFR Bit Get
 */
uint32_t HW_CTSU_CTSUCR0GetBitCTSUSTRT(void) {
    return R_CTSU->CTSUCR0_b.CTSUSTRT;
}
uint32_t HW_CTSU_CTSUCR0GetBitCTSUCAP(void) {
    return R_CTSU->CTSUCR0_b.CTSUCAP;
}
uint32_t HW_CTSU_CTSUCR0GetBitCTSUSNZ(void) {
    return R_CTSU->CTSUCR0_b.CTSUSNZ;
}
uint32_t HW_CTSU_CTSUCR0GetBitCTSUINIT(void) {
    return R_CTSU->CTSUCR0_b.CTSUINIT;
}
uint32_t HW_CTSU_CTSUCR1GetBitCTSUPON(void) {
    return R_CTSU->CTSUCR1_b.CTSUPON;
}
uint32_t HW_CTSU_CTSUCR1GetBitCTSUCSW(void) {
    return R_CTSU->CTSUCR1_b.CTSUCSW;
}
uint32_t HW_CTSU_CTSUCR1GetBitCTSUATUNE0(void) {
    return R_CTSU->CTSUCR1_b.CTSUATUNE0;
}
uint32_t HW_CTSU_CTSUCR1GetBitCTSUATUNE1(void) {
    return R_CTSU->CTSUCR1_b.CTSUATUNE1;
}
uint32_t HW_CTSU_CTSUCR1GetBitCTSUCLK(void) {
    return R_CTSU->CTSUCR1_b.CTSUCLK;
}
uint32_t HW_CTSU_CTSUCR1GetBitCTSUMD(void) {
    return R_CTSU->CTSUCR1_b.CTSUMD;
}
uint32_t HW_CTSU_CTSUSDPRSGetBitCTSUPRRATIO(void) {
    return R_CTSU->CTSUSDPRS_b.CTSUPRRATIO;
}
uint32_t HW_CTSU_CTSUSDPRSGetBitCTSUPRMODE(void) {
    return R_CTSU->CTSUSDPRS_b.CTSUPRMODE;
}
uint32_t HW_CTSU_CTSUSDPRSGetBitCTSUSOFF(void) {
    return R_CTSU->CTSUSDPRS_b.CTSUSOFF;
}
uint32_t HW_CTSU_CTSUSSTGetBitCTSUSST(void) {
    return R_CTSU->CTSUSST_b.CTSUSST;
}
uint32_t HW_CTSU_CTSUMCH0GetBitCTSUMCH0(void) {
    return R_CTSU->CTSUMCH0_b.CTSUMCH0;
}
uint32_t HW_CTSU_CTSUMCH1GetBitCTSUMCH1(void) {
    return R_CTSU->CTSUMCH1_b.CTSUMCH1;
}
uint32_t HW_CTSU_CTSUDCLKCGetBitCTSUSSMOD(void) {
    return R_CTSU->CTSUDCLKC_b.CTSUSSMOD;
}
uint32_t HW_CTSU_CTSUDCLKCGetBitCTSUSSCNT(void) {
    return R_CTSU->CTSUDCLKC_b.CTSUSSCNT;
}
uint32_t HW_CTSU_CTSUSTGetBitCTSUSTC(void) {
    return R_CTSU->CTSUST_b.CTSUSTC;
}
uint32_t HW_CTSU_CTSUSTGetBitCTSUDTSR(void) {
    return R_CTSU->CTSUST_b.CTSUDTSR;
}
uint32_t HW_CTSU_CTSUSTGetBitCTSUSOVF(void) {
    return R_CTSU->CTSUST_b.CTSUSOVF;
}
uint32_t HW_CTSU_CTSUSTGetBitCTSUROVF(void) {
    return R_CTSU->CTSUST_b.CTSUROVF;
}
uint32_t HW_CTSU_CTSUSTGetBitCTSUPS(void) {
    return R_CTSU->CTSUST_b.CTSUPS;
}
uint32_t HW_CTSU_CTSUSCGetBitCTSUSC(void) {
    return R_CTSU->CTSUSC_b.CTSUSC;
}
uint32_t HW_CTSU_CTSURCGetBitCTSURC(void) {
    return R_CTSU->CTSURC_b.CTSURC;
}
uint32_t HW_CTSU_CTSUERRSGetBitCTSUICOMP(void) {
    return R_CTSU->CTSUERRS_b.CTSUICOMP;
}

/*
 * SFR Bit Set
 */
void HW_CTSU_CTSUCR0SetBitCTSUSTRT(uint32_t value) {
    R_CTSU->CTSUCR0_b.CTSUSTRT =
            (value & 0x01);
}
void HW_CTSU_CTSUCR0SetBitCTSUCAP(uint32_t value) {
    R_CTSU->CTSUCR0_b.CTSUCAP =
            (value & 0x01);
}
void HW_CTSU_CTSUCR0SetBitCTSUSNZ(uint32_t value) {
    R_CTSU->CTSUCR0_b.CTSUSNZ =
            (value & 0x01);
}
void HW_CTSU_CTSUCR0SetBitCTSUINIT(uint32_t value) {
    R_CTSU->CTSUCR0_b.CTSUINIT =
            (value & 0x01);
}
void HW_CTSU_CTSUCR1SetBitCTSUPON(uint32_t value) {
    R_CTSU->CTSUCR1_b.CTSUPON =
            (value & 0x01);
}
void HW_CTSU_CTSUCR1SetBitCTSUCSW(uint32_t value) {
    R_CTSU->CTSUCR1_b.CTSUCSW =
            (value & 0x01);
}
void HW_CTSU_CTSUCR1SetBitCTSUATUNE0(uint32_t value) {
    R_CTSU->CTSUCR1_b.CTSUATUNE0 =
            (value & 0x01);
}
void HW_CTSU_CTSUCR1SetBitCTSUATUNE1(uint32_t value) {
    R_CTSU->CTSUCR1_b.CTSUATUNE1 =
            (value & 0x01);
}
void HW_CTSU_CTSUCR1SetBitCTSUCLK(uint32_t value) {
    R_CTSU->CTSUCR1_b.CTSUCLK =
            (value & 0x01);
}
void HW_CTSU_CTSUCR1SetBitCTSUMD(uint32_t value) {
    R_CTSU->CTSUCR1_b.CTSUMD =
            (value & 0x01);
}
void HW_CTSU_CTSUSDPRSSetBitCTSUPRRATIO(uint32_t value) {
    R_CTSU->CTSUSDPRS_b.CTSUPRRATIO =
            (value & 0x01);
}
void HW_CTSU_CTSUSDPRSSetBitCTSUPRMODE(uint32_t value) {
    R_CTSU->CTSUSDPRS_b.CTSUPRMODE =
            (value & 0x01);
}
void HW_CTSU_CTSUSDPRSSetBitCTSUSOFF(uint32_t value) {
    R_CTSU->CTSUSDPRS_b.CTSUSOFF =
            (value & 0x01);
}
void HW_CTSU_CTSUSSTSetBitCTSUSST(uint32_t value) {
    R_CTSU->CTSUSST_b.CTSUSST =
            (value & 0x01);
}
void HW_CTSU_CTSUMCH0SetBitCTSUMCH0(uint32_t value) {
    R_CTSU->CTSUMCH0_b.CTSUMCH0 =
            (value & 0x01);
}
void HW_CTSU_CTSUMCH1SetBitCTSUMCH1(uint32_t value) {
    R_CTSU->CTSUMCH1_b.CTSUMCH1 =
            (value & 0x01);
}
void HW_CTSU_CTSUDCLKCSetBitCTSUSSMOD(uint32_t value) {
    R_CTSU->CTSUDCLKC_b.CTSUSSMOD =
            (value & 0x01);
}
void HW_CTSU_CTSUDCLKCSetBitCTSUSSCNT(uint32_t value) {
    R_CTSU->CTSUDCLKC_b.CTSUSSCNT =
            (value & 0x01);
}
void HW_CTSU_CTSUSTSetBitCTSUSTC(uint32_t value) {
    R_CTSU->CTSUST_b.CTSUSTC =
            (value & 0x01);
}
void HW_CTSU_CTSUSTSetBitCTSUDTSR(uint32_t value) {
    R_CTSU->CTSUST_b.CTSUDTSR =
            (value & 0x01);
}
void HW_CTSU_CTSUSTSetBitCTSUSOVF(uint32_t value) {
    R_CTSU->CTSUST_b.CTSUSOVF =
            (value & 0x01);
}
void HW_CTSU_CTSUSTSetBitCTSUROVF(uint32_t value) {
    R_CTSU->CTSUST_b.CTSUROVF =
            (value & 0x01);
}
void HW_CTSU_CTSUSTSetBitCTSUPS(uint32_t value) {
    R_CTSU->CTSUST_b.CTSUPS =
            (value & 0x01);
}
void HW_CTSU_CTSUSSCSetBitCTSUSSDIV(uint32_t value) {
    R_CTSU->CTSUSSC_b.CTSUSSDIV =
            (value & 0x01);
}
void HW_CTSU_CTSUSO0SetBitCTSUSO(uint32_t value) {
    R_CTSU->CTSUSO0_b.CTSUSO =
            (value & 0x01);
}
void HW_CTSU_CTSUSO0SetBitCTSUSNUM(uint32_t value) {
    R_CTSU->CTSUSO0_b.CTSUSNUM =
            (value & 0x01);
}
void HW_CTSU_CTSUSO1SetBitCTSURICOA(uint32_t value) {
    R_CTSU->CTSUSO1_b.CTSURICOA =
            (value & 0x01);
}
void HW_CTSU_CTSUSO1SetBitCTSUSDPA(uint32_t value) {
    R_CTSU->CTSUSO1_b.CTSUSDPA =
            (value & 0x01);
}
void HW_CTSU_CTSUSO1SetBitCTSUICOG(uint32_t value) {
    R_CTSU->CTSUSO1_b.CTSUICOG =
            (value & 0x01);
}
void HW_CTSU_CTSUERRSSetBitCTSUICOMP(uint32_t value) {
    R_CTSU->CTSUERRS_b.CTSUICOMP =
            (value & 0x01);
}

uint32_t HW_CTSU_PCLKB_Frequency(void)
{
    uint32_t pclkb_freq = 0;
    extern const cgc_api_t g_cgc_on_cgc;
    g_cgc_on_cgc.systemClockFreqGet(CGC_SYSTEM_CLOCKS_PCLKB, &pclkb_freq);

    return pclkb_freq;
}
