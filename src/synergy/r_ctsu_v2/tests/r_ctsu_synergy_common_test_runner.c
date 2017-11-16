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
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : r_ctsu_synergy_common_test_runner.c
* Description  : Unity unit tests for <Module Name>
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*           04.05.2015 1.00     Initial Release
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "bsp_api.h"
#include "unity_fixture.h"


#if defined(BSP_MCU_GROUP_S124) || defined(BSP_MCU_GROUP_S3A7) || defined(BSP_MCU_GROUP_S5D9) || defined(BSP_MCU_GROUP_S7G2)
#include "r_ctsu_synergy_common_test.h"
/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define RUN_TG1     (true)
#define RUN_TG2     (true)
#define RUN_TG3     (false)
#define RUN_TG4     (true)

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

/***********************************************************************************************************************
* Function Name: TEST_CTSU_TG1_GROUP_RUNNER_runAll
* Description  : Test operation of API in self-capacitance mode.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
TEST_GROUP_RUNNER(CTSU_TG1)
{
#if RUN_TG1==true
    /* Test operation of API in self-capacitance mode. */
	RUN_TEST_CASE(CTSU_TG1, TC_1_0_GetVersion);
	RUN_TEST_CASE(CTSU_TG1, TC_1_1_Open_Invalid_Param_test);
	RUN_TEST_CASE(CTSU_TG1, TC_1_2_Open_Close_Handle);
	RUN_TEST_CASE(CTSU_TG1, TC_1_3_Scan_Multiple_Handles);
	RUN_TEST_CASE(CTSU_TG1, TC_1_7_Calibrate_Handle);
	RUN_TEST_CASE(CTSU_TG1, TC_1_4_Read_Results);
	RUN_TEST_CASE(CTSU_TG1, TC_1_5_Control_Get_Tests);
	RUN_TEST_CASE(CTSU_TG1, TC_1_6_Control_Set_Tests);
	RUN_TEST_CASE(CTSU_TG1, TC_1_8_Event_Check);
#endif
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG1_GROUP_RUNNER_runAll
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: TEST_CTSU_TG2_GROUP_RUNNER_runAll
* Description  : Test operation of API in mutual-capacitance mode.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
TEST_GROUP_RUNNER(CTSU_TG2)
{
#if RUN_TG2==true
    /* Test operation of API in mutual-capacitance mode */
	RUN_TEST_CASE(CTSU_TG2, TC_2_0_GetVersion);
	RUN_TEST_CASE(CTSU_TG2, TC_2_1_Open_Invalid_Param_test);
	RUN_TEST_CASE(CTSU_TG2, TC_2_2_Open_Close_Handle);
	RUN_TEST_CASE(CTSU_TG2, TC_2_3_Scan_Multiple_Handles);
	RUN_TEST_CASE(CTSU_TG2, TC_2_7_Calibrate_Handle);
	RUN_TEST_CASE(CTSU_TG2, TC_2_4_Read_Results);
	RUN_TEST_CASE(CTSU_TG2, TC_2_5_Control_Get_Tests);
	RUN_TEST_CASE(CTSU_TG2, TC_2_6_Control_Set_Tests);
	RUN_TEST_CASE(CTSU_TG2, TC_2_8_Event_Check);
#endif
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG2_GROUP_RUNNER_runAll
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: TEST_CTSU_TG3_GROUP_RUNNER_runAll
* Description  : Test Operation of CTSU in hybrid mode (i.e. Self + Mutual operation).
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
TEST_GROUP_RUNNER(CTSU_TG3)
{
#if RUN_TG3 == true
    /* Test operation of API in hybrid mode */
//	RUN_TEST_CASE(CTSU_TG3, TC_3_1_Open_Scan_Close);
//	RUN_TEST_CASE(CTSU_TG3, TC_3_2_Read_Hybrid);
#endif
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG3_GROUP_RUNNER_runAll
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: TEST_CTSU_TG4_GROUP_RUNNER_runAll
* Description  : Left over feature/API tests.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
TEST_GROUP_RUNNER(CTSU_TG4)
{
#if RUN_TG4 == true
    /* Test Error reporting from API */
	RUN_TEST_CASE(CTSU_TG4, TC_4_1_CTSUICOMP_Error);
	RUN_TEST_CASE(CTSU_TG4, TC_4_2_CTSUSOVF_Error);
	RUN_TEST_CASE(CTSU_TG4, TC_4_3_CTSUROVF_Error);
	RUN_TEST_CASE(CTSU_TG4, TC_4_4_Read_Handle);
	RUN_TEST_CASE(CTSU_TG4, TC_4_5_Scan_Handle);
	RUN_TEST_CASE(CTSU_TG4, TC_4_6_Control_Handle);
	RUN_TEST_CASE(CTSU_TG4, TC_4_7_Close_Handle);
#endif
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG4_GROUP_RUNNER_runAll
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: RunAllTests
* Description  : Call test groups
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
static void RunAllTests(void)
{
	/* Get module software versions */
	printf ("\n  Touch Driver Version: V%d.%d\n", (CTSU_CODE_VERSION_MAJOR), (CTSU_CODE_VERSION_MINOR));

	RUN_TEST_GROUP(CTSU_TG1);
	RUN_TEST_GROUP(CTSU_TG2);
	RUN_TEST_GROUP(CTSU_TG3);
	RUN_TEST_GROUP(CTSU_TG4);
}
/***********************************************************************************************************************
End of function RunAllTests
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: test_ctsu
* Description  : Tear down for these unit tests
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
void test_ctsu(void)
{
	printf("\n\r-------- Test Project Compiled on %s %s--------\n\r", __DATE__, __TIME__);
    char* args[2] = {"", "-v"};
    UnityMain(2, args, RunAllTests);

    while(1)
    {
        /* Infinite loop. */
    }
}
/***********************************************************************************************************************
End of function test_ctsu
***********************************************************************************************************************/

#endif
/* defined(BSP_MCU_GROUP_S124) || defined(BSP_MCU_GROUP_S3A7) || defined(BSP_MCU_GROUP_S5D9) || defined(BSP_MCU_GROUP_S7G2) */
