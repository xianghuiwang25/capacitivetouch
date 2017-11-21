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
#if defined(BSP_MCU_GROUP_S3A7) || defined(BSP_MCU_RX130) || defined(BSP_MCU_RX230) || defined(BSP_MCU_RX231)
#include "r_touch_button_rx_common_test.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#define NUM_OPEN_CONFIGS   BUTTON_CFG_MAX_CONTROL_BLOCK_COUNT

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

TEST_GROUP_RUNNER(TOUCH_BUTTON_TG1)
{	/** Test operation of API in self-capacitance mode. */
	RUN_TEST_CASE(TOUCH_BUTTON_TG1, TC_1_0_GetVersion);
	RUN_TEST_CASE(TOUCH_BUTTON_TG1, TC_1_1_Open_Invalid_Param_test);
	RUN_TEST_CASE(TOUCH_BUTTON_TG1, TC_1_2_Open_Close_Handle);
	RUN_TEST_CASE(TOUCH_BUTTON_TG1, TC_1_3_Control_Handle);
	RUN_TEST_CASE(TOUCH_BUTTON_TG1, TC_1_4_Update_Test);
}

TEST_GROUP_RUNNER(TOUCH_BUTTON_TG2)
{	/** Test operation of API in mutual-capacitance mode */
	RUN_TEST_CASE(TOUCH_BUTTON_TG2, TC_2_0_GetVersion);
	RUN_TEST_CASE(TOUCH_BUTTON_TG2, TC_2_1_Open_Invalid_Param_test);
	RUN_TEST_CASE(TOUCH_BUTTON_TG2, TC_2_2_Open_Close_Handle);
//	RUN_TEST_CASE(TOUCH_BUTTON_TG2, TC_2_3_Control_Test);
	RUN_TEST_CASE(TOUCH_BUTTON_TG2, TC_2_4_Update_Test);
}

TEST_GROUP_RUNNER(TOUCH_BUTTON_TG3)
{ /** Test operation of API with self-mutual-capacitance combination */

}

/***********************************************************************************************************************
* Function Name: RunAllTests
* Description  : Call test groups
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
static void RunAllTests(void)
{
	RUN_TEST_GROUP(TOUCH_BUTTON_TG1);
//	RUN_TEST_GROUP(TOUCH_BUTTON_TG2);
//	RUN_TEST_GROUP(TOUCH_BUTTON_TG3);
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
void test_button(void)
{
    touch_cfg_t * p_configs[NUM_OPEN_CONFIGS];
    uint32_t id[NUM_OPEN_CONFIGS];
    touch_err_t touch_err;
    uint32_t run_id;
    uint32_t itr;

    printf("\n\r-------- Test Project Compiled on %s %s--------\n\r", __DATE__, __TIME__);
    char* args[2] = {"", "-v"};
    UnityMain(2, args, RunAllTests);
#if 0
#if defined(CTSENSOR_RX130_H)
    extern void touch_rx130_init_ports(void);

    touch_rx130_init_ports();
    printf("\n\r Press SW5 to free run TOUCH with Button/Slider/Wheel board (self-capacitance mode).");
    printf("\n\r -OR-");
    printf("\n\r Press SW4 to free run TOUCH with Buttons board (mutual-capacitance mode).");
    extern touch_cfg_t g_touch_cfg_ctsensor_rx130_self01;
    extern touch_cfg_t g_touch_cfg_ctsensor_rx130_mutual01;
    p_configs[0] = &g_touch_cfg_ctsensor_rx130_self01;
    p_configs[1] = &g_touch_cfg_ctsensor_rx130_mutual01;
#endif

    for(itr = 0; itr < sizeof(p_configs)/sizeof(p_configs[0]); itr++)
    {
    	touch_err = R_TOUCH_Open(&id[itr], p_configs[itr]);
    	printf("\n\rtouch_err = %d", touch_err);
    }

    while((SW5!=SW_ACTIVE) && (SW4 !=SW_ACTIVE));
    if(SW5 == SW_ACTIVE)
    {
    	run_id = 0;
    	while(SW5==SW_ACTIVE);
    	printf("\n\rTOUCH with Button/Slider/Wheel board (self-capacitance mode).");
    }
    else if(SW4 == SW_ACTIVE)
    {
    	run_id = 1;
    	while(SW4==SW_ACTIVE);
    	printf("\n\rTOUCH with Buttons board (mutual-capacitance mode).");
    }
#if !defined(HARNESS_TESTING)
    touch_err = R_TOUCH_Calibrate(id[run_id]);
    printf("\n\rtouch_err = %d", touch_err);
#endif
    while(1)
    {
        /* Infinite loop. */
    	touch_err = R_TOUCH_Update(id[run_id]);
    	if(TOUCH_SUCCESS == touch_err)
    	{
    		touch_err = R_TOUCH_Start_Scan(id[run_id]);
    	}
    }
#endif
}

#endif	//defined(BSP_MCU_RX113) || defined(BSP_MCU_RX130) || defined(BSP_MCU_RX230) || defined(BSP_MCU_RX231)
