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
* File Name : r_touch_rx_common_test_runner.c
* Version : XXX: [Aug 12, 2016:Onkar.Raut:3:38:37 PM] TODO: Insert Release Note.
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
#include "bsp_api.h"
#include "unity_fixture.h"

#if defined(BSP_MCU_GROUP_S124) || defined(BSP_MCU_GROUP_S3A7) || defined(BSP_MCU_GROUP_S5D9) || defined(BSP_MCU_GROUP_S7G2)
#include "r_touch_rx_common_test.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define RUN_TG1 (true)
#define RUN_TG2 (false)
#define RUN_TG3 (false)
/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/
static void RunAllTests(void);

TEST_GROUP_RUNNER(TOUCH_TG1)
{
    /** Test operation of API in self-capacitance mode. */
#if (RUN_TG1 == true)
	RUN_TEST_CASE(TOUCH_TG1, TC_1_0_GetVersion);
	RUN_TEST_CASE(TOUCH_TG1, TC_1_1_Open_Invalid_Param_test);
	RUN_TEST_CASE(TOUCH_TG1, TC_1_2_Open_Close_Handle);
	RUN_TEST_CASE(TOUCH_TG1, TC_1_3_Scan_Multiple_Handles);
	RUN_TEST_CASE(TOUCH_TG1, TC_1_4_Update_Touch_Test);
	RUN_TEST_CASE(TOUCH_TG1, TC_1_5_Touch_Multiple_Open);
	RUN_TEST_CASE(TOUCH_TG1, TC_1_6_Read_Touch_Test);
	RUN_TEST_CASE(TOUCH_TG1, TC_1_7_Calibrate_Test);
	RUN_TEST_CASE(TOUCH_TG1, TC_1_8_Excluded_Channel_Test);
	RUN_TEST_CASE(TOUCH_TG1, TC_1_9_Continuous_Touch_Release_Test);
	RUN_TEST_CASE(TOUCH_TG1, TC_1_10_Event_Check);
#endif
}

TEST_GROUP_RUNNER(TOUCH_TG2)
{
    /** Test operation of API in mutual-capacitance mode */
#if (RUN_TG2 == true)
	RUN_TEST_CASE(TOUCH_TG2, TC_2_0_GetVersion);
	RUN_TEST_CASE(TOUCH_TG2, TC_2_1_Open_Invalid_Param_test);
	RUN_TEST_CASE(TOUCH_TG2, TC_2_2_Open_Close_Handle);
	RUN_TEST_CASE(TOUCH_TG2, TC_2_3_Scan_Multiple_Handles);
	RUN_TEST_CASE(TOUCH_TG2, TC_2_4_Update_Touch_Test);
	RUN_TEST_CASE(TOUCH_TG2, TC_2_5_Touch_Multiple_Open);
	RUN_TEST_CASE(TOUCH_TG2, TC_2_6_Read_Touch_Test);
	RUN_TEST_CASE(TOUCH_TG2, TC_2_7_Calibrate_Test);
	RUN_TEST_CASE(TOUCH_TG2, TC_2_8_Excluded_Channel_Test);
	RUN_TEST_CASE(TOUCH_TG2, TC_2_9_Continuous_Touch_Release_Test);
	RUN_TEST_CASE(TOUCH_TG2, TC_2_10_Event_Test);
#endif
}

TEST_GROUP_RUNNER(TOUCH_TG3)
{
    /** Test operation of API with self-mutual-capacitance combination */
#if (RUN_TG3 == true)
	RUN_TEST_CASE(TOUCH_TG3, TC_3_0_GetVersion);
	RUN_TEST_CASE(TOUCH_TG3, TC_3_1_Open_Touch_Close);
	RUN_TEST_CASE(TOUCH_TG3, TC_3_2_Custom_Filter_Operation);
#endif
}

TEST_GROUP_RUNNER(TOUCH_TG4)
{
    /** Test operation of API with Test Harness (CTSU-over-SCI) */
#if (RUN_TG == true)
	RUN_TEST_CASE(TOUCH_TG4, TC_4_0_GetVersion);
	RUN_TEST_CASE(TOUCH_TG4, TC_4_1_Scan_test);
	RUN_TEST_CASE(TOUCH_TG4, TC_4_2_Read_test);
#endif
}

/***********************************************************************************************************************
* Function Name: RunAllTests
* Description  : Call test groups
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
static void RunAllTests(void)
{
	/* Get module software versions */
    ssp_version_t version;

    ssp_err_t err = R_TOUCH_GetVersion(&version);

    while(SSP_SUCCESS != err);

	printf ("\n  Touch Driver Code Version: V%u.%u\n\r", version.code_version_major, version.code_version_minor);
	printf ("\n  Touch Driver API  Version: V%u.%u\n\r", version.api_version_major , version.api_version_minor );

	RUN_TEST_GROUP(TOUCH_TG1);
	RUN_TEST_GROUP(TOUCH_TG2);
	RUN_TEST_GROUP(TOUCH_TG3);
}

#if defined(BSP_MCU_RX130)
#define CAPTOUCH_SENSOR_COUNT	(20)
#define NUM_OPEN_CONFIGS		(2)
#endif

/***********************************************************************************************************************
* Function Name: TEST_SETUP
* Description  : Tear down for these unit tests
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void test_touch(void)
{
    printf("\n\r-------- Test Project Compiled on %s %s--------\n\r", __DATE__, __TIME__);
    char* args[2] = {"", "-v"};
    UnityMain(2, args, RunAllTests);
}

#endif	//defined(BSP_MCU_RX113) || defined(BSP_MCU_RX130) || defined(BSP_MCU_RX230) || defined(BSP_MCU_RX231)
