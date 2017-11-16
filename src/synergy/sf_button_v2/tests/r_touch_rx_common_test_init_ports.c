/*******************************************************************************
* DISCLAIMER
* This software is supplied by Renesas Electronics Corporation and is only
* intended for use with Renesas products. No other uses are authorized. This
* software is owned by Renesas Electronics Corporation and is protected under
* all applicable laws, including copyright laws.
* THIS SOFTWARE IS PROVIDED "AS IS" AND RENESAS MAKES NO WARRANTIES REGARDING
* THIS SOFTWARE, WHETHER EXPRESS, IMPLIED OR STATUTORY, INCLUDING BUT NOT
* LIMITED TO WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NON-INFRINGEMENT. ALL SUCH WARRANTIES ARE EXPRESSLY DISCLAIMED.
* TO THE MAXIMUM EXTENT PERMITTED NOT PROHIBITED BY LAW, NEITHER RENESAS
* ELECTRONICS CORPORATION NOR ANY OF ITS AFFILIATED COMPANIES SHALL BE LIABLE
* FOR ANY DIRECT, INDIRECT, SPECIAL, INCIDENTAL OR CONSEQUENTIAL DAMAGES FOR
* ANY REASON RELATED TO THIS SOFTWARE, EVEN IF RENESAS OR ITS AFFILIATES HAVE
* BEEN ADVISED OF THE POSSIBILITY OF SUCH DAMAGES.
* Renesas reserves the right, without notice, to make changes to this software
* and to discontinue the availability of this software. By using this software,
* you agree to the additional terms and conditions found by accessing the
* following link:
* <b href="http://www.renesas.com/disclaimer">http://www.renesas.com/disclaimer.</b>
* http://www.renesas.com/disclaimer
* © 2012-2016 Renesas Electronics Corporation All rights reserved.
*******************************************************************************/

/***********************************************************************************************************************
* File Name : r_touch_rx_common_test_init_ports.c
* Version : XXX: [Aug 11, 2016:Onkar.Raut:4:41:14 PM] TODO: Insert Release Note.
* Description : Short Description.
***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @file
 ***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @ingroup XXX
 * @defgroup XXX
 * @brief This is a brief description 
 * @{
 * Sample Usage:
 *
 ***********************************************************************************************************************/


/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include <stdio.h>
#include "platform.h"

#if defined(BSP_MCU_RX113) || defined(BSP_MCU_RX130) || defined(BSP_MCU_RX230) || defined(BSP_MCU_RX231)

#include "unity_fixture.h"
#include "r_touch_rx_common_test.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#if defined(BSP_MCU_RX130)
#define RX130_MPC_PIN_FUNCTION_CTSU		(0x19)
#endif

#define PORT_DIR(x,y)    PORT##x.PDR.BIT.B##y
#define PORT_MODE(x,y)   PORT##x.PMR.BIT.B##y
#define PORT_FUNC(x,y)   MPC.P##x##y##PFS.BIT.PSEL

#define TS_INIT(x,y)	do{ \
							PORT_DIR(x,y) = 0; \
							PORT_FUNC(x,y) = RX130_MPC_PIN_FUNCTION_CTSU; \
							PORT_MODE(x,y) = 1;\
						}while(0)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/
#if defined(BSP_MCU_RX113)
/*****************************************************************************
* Function Name: touch_rx113_init_ports
* Description  : YRX113CAPT01 (http://am.renesas.com/products/tools/introductory_evaluation_tools/renesas_starter_kits/yrx113capt01/index.jsp)
* Arguments    : none
* Return Value : none
******************************************************************************/
void touch_rx113_init_ports(void)
{
	R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

	R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}
#endif// defined(BSP_MCU_RX113)
/*****************************************************************************
* Function Name: touch_rx130_init_ports
* Description  : CTSENSOR_RX130 (http://am.renesas.com/products/tools/introductory_evaluation_tools/renesas_solution_starter_kits/ctsensor/ctsensor_rx130/index.jsp)
* 				 RSKRX130(http://am.renesas.com/products/tools/introductory_evaluation_tools/renesas_starter_kits/rsk_rx130/index.jsp)
* Arguments    : none
* Return Value : none
******************************************************************************/
#if defined(BSP_MCU_RX130)
void touch_rx130_init_ports(void)
{
	R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);
#if defined(RSKRX130_H)
	/* TSCAP */
	TS_INIT(C,4);
	/* TS11 */
	TS_INIT(5,5);
	/* TS12 */
	TS_INIT(5,4);
	/* TS07 */
	TS_INIT(H,3);
	/* TS08 */
	TS_INIT(H,2);
	/* TS09 */
	TS_INIT(H,1);
	/* TS10 */
	TS_INIT(H,0);

	/* LED operation */
	LED0_PDR = 1;
	LED1_PDR = 1;
	LED2_PDR = 1;
	LED0 = LED_OFF;
	LED1 = LED_OFF;
	LED2 = LED_OFF;

	/* Switch operation*/
	SW1_PDR = 0;
	SW2_PDR = 0;
	SW3_PDR = 0;

#elif defined(CTSENSOR_RX130_H)
	/* TSCAP */
	TS_INIT(C,4);
	/* TS00 */
	TS_INIT(3,2);
	/* TS01 */
	TS_INIT(3,1);
	/* TS02 */
	TS_INIT(3,0);
	/* TS03 */
	TS_INIT(2,7);
	/* TS04 */
	TS_INIT(2,6);
	/* TS05 */
	TS_INIT(1,5);
	/* TS06 */
	TS_INIT(1,4);
	/* TS07 */
	TS_INIT(H,3);
	/* TS08 */
	TS_INIT(H,2);
	/* TS09 */
	TS_INIT(H,1);
	/* TS10 */
	TS_INIT(H,0);
	/* TS11 */
	TS_INIT(5,5);
	/* TS12 */
	TS_INIT(5,4);
	/* TS13 */
	TS_INIT(C,7);
	/* TS14 */
	TS_INIT(C,6);
	/* TS15 */
	TS_INIT(C,5);
	/* TS16 */
	TS_INIT(C,3);
	/* TS17 */
	TS_INIT(C,2);
	/* TS18 */
	TS_INIT(B,7);
	/* TS19 */
	TS_INIT(B,6);
	/* TS20 */
	TS_INIT(B,5);
	/* TS21 */
	TS_INIT(B,4);
	/* TS22 */
	TS_INIT(B,3);
	/* TS23 */
	TS_INIT(B,2);
	/* TS24 */
	TS_INIT(B,1);
	/* TS25 */
	TS_INIT(B,0);
	/* TS26 */
	TS_INIT(A,6);
	/* TS27 */
	TS_INIT(A,5);
	/* TS28 */
	TS_INIT(A,4);
	/* TS29 */
	TS_INIT(A,3);
	/* TS30 */
	TS_INIT(A,2);
	/* TS31 */
	TS_INIT(A,1);
	/* TS32 */
	TS_INIT(A,0);
	/* TS33 */
	TS_INIT(E,4);
	/* TS34 */
	TS_INIT(E,3);
	/* TS35 */
	TS_INIT(E,2);

	/* LED operation */
	LED1_PDR = 1;
	LED2_PDR = 1;
	LED3_PDR = 1;
	LED1 = LED_OFF;
	LED2 = LED_OFF;
	LED3 = LED_OFF;

	/* Switch operation*/
	SW4_PCR = 1;
	SW5_PCR = 1;
//	SW3_PDR = 0;
	SW4_PDR = 0;
	SW5_PDR = 0;
#else
#error "Undefined Board Support Package."
#endif//defined(RSKRX130_H)
	R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}
#endif//defined(BSP_MCU_RX130)

/*****************************************************************************
* Function Name: touch_rx230_init_ports
* Description  :
* Arguments    : none
* Return Value : none
******************************************************************************/
#if defined(BSP_MCU_RX230)
void touch_rx230_init_ports(void)
{
	R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);

	R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}
#endif//defined(BSP_MCU_RX230)

/*****************************************************************************
* Function Name: touch_rx231_init_ports
* Description  : RSKRX231 (http://am.renesas.com/products/tools/introductory_evaluation_tools/renesas_starter_kits/rsk_rx231/index.jsp
* Arguments    : none
* Return Value : none
******************************************************************************/
#if defined(BSP_MCU_RX231)
void touch_rx231_init_ports(void)
{
	R_BSP_RegisterProtectDisable(BSP_REG_PROTECT_MPC);
#if defined(RSKRX231_H)

#endif//defined(RSKRX231_H)
	R_BSP_RegisterProtectEnable(BSP_REG_PROTECT_MPC);
}
#endif//defined(BSP_MCU_RX231)

#endif//defined(BSP_MCU_RX113) || defined(BSP_MCU_RX130) || defined(BSP_MCU_RX230) || defined(BSP_MCU_RX231)
