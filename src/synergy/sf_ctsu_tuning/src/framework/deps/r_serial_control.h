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
* File Name    : r_serial_control.h
* Version      : 1.00
* Device(s)    : R5F5113xAxFP,R5F5231xAxFP,R5F51305AxFN
* Description  : This file includes the serial command.
***********************************************************************************************************************/

/***********************************************************************************************************************
* History      : DD.MM.YYYY Version    Description
*              : xx.xx.2015   1.00     First Release
***********************************************************************************************************************/

#ifndef	__R_SERIAL_CONTROL_H__	//[
#define	__R_SERIAL_CONTROL_H__
/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global functions (to be accessed by other files);
***********************************************************************************************************************/
int SerialCommandInitial(ctsu_instance_t * p_ctsu, const uint8_t itr);    // serial communication initialization
int SerialCommandInitialTouch(touch_instance_t * p_touch, const uint8_t itr);
uint8_t SerialCommandReceive(uint8_t * value, uint16_t length);
uint8_t GetReplayMessage(uint8_t * value, uint16_t * length);
void PrepareReplayMessage(void);    // Replay message for IDE communication preparing
void TouchParamUpdate(void);
void BurstMonitorSendSensorValue(void);

#endif	//] __R_SERIAL_CONTROL_H__
