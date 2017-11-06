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
 * Copyright (C) 2014 Renesas Electronics Corporation. All rights reserved.
 *
 * NOTE: The contents of this file are confidential, and are covered under the SC32 non-disclosure agreement.
 ***********************************************************************************************************************/
/**********************************************************************************************************************
 * File Name    : r_ctsu_sfr_access_rx.h
 * Description  : This file implements the Hardware Abstraction Layer for the CTSU module. Provides functions to
 * 					manipulate SFRs.
 ***********************************************************************************************************************
 * History : DD.MM.YYYY Version Description
 *           12.11.2014 1.00    Initial Release.
 ***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @file
 ***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @ingroup HAL_Library
 * @defgroup r_ctsu_hw r_ctsu_hw
 * @brief Provides functions to manipulate Special Function Registers which operate the R_CTSU->
 *
 *  It implements the following interface:
 *  - @ref r_ctsu_sfr_access_rx.h
 * @{
 ***********************************************************************************************************************/

#ifndef R_CTSU_SFR_ACCESS_RX_H_
#define R_CTSU_SFR_ACCESS_RX_H_

/*
 * Get SFRs
 */
uint8_t HW_CTSU_CTSUCR0Get(void)    ;
uint8_t HW_CTSU_CTSUCR1Get(void)    ;
uint8_t HW_CTSU_CTSUSDPRSGet(void)  ;
uint8_t HW_CTSU_CTSUSSTGet(void)    ;
uint8_t HW_CTSU_CTSUMCH0Get(void)   ;
uint8_t HW_CTSU_CTSUMCH1Get(void)   ;
uint8_t HW_CTSU_CTSUCHAC0Get(void)  ;
uint8_t HW_CTSU_CTSUCHAC1Get(void)  ;
uint8_t HW_CTSU_CTSUCHAC2Get(void)  ;
uint8_t HW_CTSU_CTSUCHAC3Get(void)  ;
uint8_t HW_CTSU_CTSUCHAC4Get(void)  ;
uint8_t HW_CTSU_CTSUCHTRC0Get(void) ;
uint8_t HW_CTSU_CTSUCHTRC1Get(void) ;
uint8_t HW_CTSU_CTSUCHTRC2Get(void) ;
uint8_t HW_CTSU_CTSUCHTRC3Get(void) ;
uint8_t HW_CTSU_CTSUCHTRC4Get(void) ;
uint8_t HW_CTSU_CTSUDCLKCGet(void)  ;
uint8_t HW_CTSU_CTSUSTGet(void)     ;
uint16_t HW_CTSU_CTSUSCGet(void)    ;
uint16_t HW_CTSU_CTSURCGet(void)    ;
uint16_t HW_CTSU_CTSUERRSGet(void)  ;

/*
 * Set SFRs
 */
void HW_CTSU_CTSUCR0Set(uint8_t value)     ;
void HW_CTSU_CTSUCR1Set(uint8_t value)     ;
void HW_CTSU_CTSUSDPRSSet(uint8_t value)   ;
void HW_CTSU_CTSUSSTSet(uint8_t value)     ;
void HW_CTSU_CTSUMCH0Set(uint8_t value)    ;
void HW_CTSU_CTSUMCH1Set(uint8_t value)    ;
void HW_CTSU_CTSUCHAC0Set(uint8_t value)   ;
void HW_CTSU_CTSUCHAC1Set(uint8_t value)   ;
void HW_CTSU_CTSUCHAC2Set(uint8_t value)   ;
void HW_CTSU_CTSUCHAC3Set(uint8_t value)   ;
void HW_CTSU_CTSUCHAC4Set(uint8_t value)   ;
void HW_CTSU_CTSUCHTRC0Set(uint8_t value)  ;
void HW_CTSU_CTSUCHTRC1Set(uint8_t value)  ;
void HW_CTSU_CTSUCHTRC2Set(uint8_t value)  ;
void HW_CTSU_CTSUCHTRC3Set(uint8_t value)  ;
void HW_CTSU_CTSUCHTRC4Set(uint8_t value)  ;
void HW_CTSU_CTSUDCLKCSet(uint8_t value)   ;
void HW_CTSU_CTSUSTSet(uint8_t value)      ;
void HW_CTSU_CTSUSSCSet(uint16_t value)    ;
void HW_CTSU_CTSUSO0Set(uint16_t value)    ;
void HW_CTSU_CTSUSO1Set(uint16_t value)    ;
void HW_CTSU_CTSUERRSSet(uint16_t value)   ;

/*
 * SFR Bit Get
 */
uint32_t HW_CTSU_CTSUCR0GetBitCTSUSTRT(void)      ;
uint32_t HW_CTSU_CTSUCR0GetBitCTSUCAP(void)       ;
uint32_t HW_CTSU_CTSUCR0GetBitCTSUSNZ(void)       ;
uint32_t HW_CTSU_CTSUCR0GetBitCTSUINIT(void)      ;
uint32_t HW_CTSU_CTSUCR1GetBitCTSUPON(void)       ;
uint32_t HW_CTSU_CTSUCR1GetBitCTSUCSW(void)       ;
uint32_t HW_CTSU_CTSUCR1GetBitCTSUATUNE0(void)    ;
uint32_t HW_CTSU_CTSUCR1GetBitCTSUATUNE1(void)    ;
uint32_t HW_CTSU_CTSUCR1GetBitCTSUCLK(void)       ;
uint32_t HW_CTSU_CTSUCR1GetBitCTSUMD(void)        ;
uint32_t HW_CTSU_CTSUSDPRSGetBitCTSUPRRATIO(void) ;
uint32_t HW_CTSU_CTSUSDPRSGetBitCTSUPRMODE(void)  ;
uint32_t HW_CTSU_CTSUSDPRSGetBitCTSUSOFF(void)    ;
uint32_t HW_CTSU_CTSUSSTGetBitCTSUSST(void)       ;
uint32_t HW_CTSU_CTSUMCH0GetBitCTSUMCH0(void)     ;
uint32_t HW_CTSU_CTSUMCH1GetBitCTSUMCH1(void)     ;
uint32_t HW_CTSU_CTSUDCLKCGetBitCTSUSSMOD(void)   ;
uint32_t HW_CTSU_CTSUDCLKCGetBitCTSUSSCNT(void)   ;
uint32_t HW_CTSU_CTSUSTGetBitCTSUSTC(void)        ;
uint32_t HW_CTSU_CTSUSTGetBitCTSUDTSR(void)       ;
uint32_t HW_CTSU_CTSUSTGetBitCTSUSOVF(void)       ;
uint32_t HW_CTSU_CTSUSTGetBitCTSUROVF(void)       ;
uint32_t HW_CTSU_CTSUSTGetBitCTSUPS(void)         ;
uint32_t HW_CTSU_CTSUSCGetBitCTSUSC(void)         ;
uint32_t HW_CTSU_CTSURCGetBitCTSURC(void)         ;
uint32_t HW_CTSU_CTSUERRSGetBitCTSUICOMP(void)    ;
uint32_t HW_CTSU_PCLKB_Frequency(void)            ;

/*
 * SFR Bit Set
 */
void HW_CTSU_CTSUCR0SetBitCTSUSTRT(uint32_t value)     ;
void HW_CTSU_CTSUCR0SetBitCTSUCAP(uint32_t value)      ;
void HW_CTSU_CTSUCR0SetBitCTSUSNZ(uint32_t value)      ;
void HW_CTSU_CTSUCR0SetBitCTSUINIT(uint32_t value)     ;
void HW_CTSU_CTSUCR1SetBitCTSUPON(uint32_t value)      ;
void HW_CTSU_CTSUCR1SetBitCTSUCSW(uint32_t value)      ;
void HW_CTSU_CTSUCR1SetBitCTSUATUNE0(uint32_t value)   ;
void HW_CTSU_CTSUCR1SetBitCTSUATUNE1(uint32_t value)   ;
void HW_CTSU_CTSUCR1SetBitCTSUCLK(uint32_t value)      ;
void HW_CTSU_CTSUCR1SetBitCTSUMD(uint32_t value)       ;
void HW_CTSU_CTSUSDPRSSetBitCTSUPRRATIO(uint32_t value);
void HW_CTSU_CTSUSDPRSSetBitCTSUPRMODE(uint32_t value) ;
void HW_CTSU_CTSUSDPRSSetBitCTSUSOFF(uint32_t value)   ;
void HW_CTSU_CTSUSSTSetBitCTSUSST(uint32_t value)      ;
void HW_CTSU_CTSUMCH0SetBitCTSUMCH0(uint32_t value)    ;
void HW_CTSU_CTSUMCH1SetBitCTSUMCH1(uint32_t value)    ;
void HW_CTSU_CTSUDCLKCSetBitCTSUSSMOD(uint32_t value)  ;
void HW_CTSU_CTSUDCLKCSetBitCTSUSSCNT(uint32_t value)  ;
void HW_CTSU_CTSUSTSetBitCTSUSTC(uint32_t value)       ;
void HW_CTSU_CTSUSTSetBitCTSUDTSR(uint32_t value)      ;
void HW_CTSU_CTSUSTSetBitCTSUSOVF(uint32_t value)      ;
void HW_CTSU_CTSUSTSetBitCTSUROVF(uint32_t value)      ;
void HW_CTSU_CTSUSTSetBitCTSUPS(uint32_t value)        ;
void HW_CTSU_CTSUSSCSetBitCTSUSSDIV(uint32_t value)    ;
void HW_CTSU_CTSUSO0SetBitCTSUSO(uint32_t value)       ;
void HW_CTSU_CTSUSO0SetBitCTSUSNUM(uint32_t value)     ;
void HW_CTSU_CTSUSO1SetBitCTSURICOA(uint32_t value)    ;
void HW_CTSU_CTSUSO1SetBitCTSUSDPA(uint32_t value)     ;
void HW_CTSU_CTSUSO1SetBitCTSUICOG(uint32_t value)     ;
void HW_CTSU_CTSUERRSSetBitCTSUICOMP(uint32_t value)   ;
#endif /* R_CTSU_SFR_ACCESS_RX_H_ */
/*******************************************************************************************************************//**
 * @} (end defgroup r_ctsu)
 ***********************************************************************************************************************/
