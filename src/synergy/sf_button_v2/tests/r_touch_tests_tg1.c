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
* File Name : r_touch_tests_tg1.c
* Version : XXX: [Aug 12, 2016:Onkar.Raut:3:38:07 PM] TODO: Insert Release Note.
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
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "unity_fixture.h"

/* r_bsp support. */
#include "r_touch_button_rx_common_test.h"


#if defined(BSP_MCU_RX130)
#define CAPTOUCH_BUTTON_COUNT	(20)
#endif

void touch_event_callback_tg1(touch_button_callback_arg_t * const arg);
static touch_button_instance_ctrl_t g_touch_button_ctrl_tg1 ;
static uint32_t scan_count = 0;
static uint16_t touch_count = 0;
static uint16_t results[256];

static const char console_messages[][32] =
{
		"\n\rPlease Touch Buttons",
};

/* Define test groups. */
TEST_GROUP(TOUCH_BUTTON_TG1);

/***********************************************************************************************************************
* Function Name: TEST_SETUP
* Description  : Setup for these unit tests. This will be run before every test case.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST_SETUP(TOUCH_BUTTON_TG1)
{
    printf("\n\rPlug the \"Self-Capacitance Buttons/Wheels/Slider\" board into the kit.\n\r");
    printf("\n\rPress SW3 on MCU board to start test.\n\r");
    while(get_pin_level(SW3)!=SW_ACTIVE);
    while(get_pin_level(SW3)==SW_ACTIVE);
}

/***********************************************************************************************************************
* Function Name: TEST_TEAR_DOWN
* Description  : Tear down for these unit tests. This will be run after each test case.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST_TEAR_DOWN(TOUCH_BUTTON_TG1)
{
	scan_count = 0;
	touch_count = 0;
}

/***********************************************************************************************************************
* Function Name: TC_1_0_GetVersion
* Description  : Checking GetVersion function.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_BUTTON_TG1, TC_1_0_GetVersion)
{
    ssp_version_t version;

    ssp_err_t err = R_TOUCH_ButtonGetVersion(&version);

    TEST_ASSERT_EQUAL( TOUCH_SUCCESS, err);

    TEST_ASSERT_EQUAL_UINT32(version.api_version_major, TOUCH_BUTTON_API_VERSION_MAJOR);
    TEST_ASSERT_EQUAL_UINT32(version.api_version_minor, TOUCH_BUTTON_API_VERSION_MINOR);
    TEST_ASSERT_EQUAL_UINT32(version.code_version_major, 2);
    TEST_ASSERT_EQUAL_UINT32(version.code_version_minor, 0);
}

/***********************************************************************************************************************
* Function Name: TC_1_1_Open_Invalid_Param_test
* Description  : Test invalid parameter rejection.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_BUTTON_TG1, TC_1_1_Open_Invalid_Param_test)
{
	touch_button_cfg_t	touch_button_tg1;
	touch_button_cfg_t * p_cfg_valid_extern;
	memset(&touch_button_tg1, 0, sizeof(touch_button_cfg_t));

	TEST_ASSERT_EQUAL( TOUCH_BUTTON_ERR_INVALID_PARAM, R_TOUCH_ButtonOpen(NULL, NULL));
	TEST_ASSERT_EQUAL( TOUCH_BUTTON_ERR_INVALID_PARAM, R_TOUCH_ButtonOpen((touch_button_ctrl_t *)&g_touch_button_ctrl_tg1, NULL));
	TEST_ASSERT_EQUAL( TOUCH_BUTTON_ERR_INVALID_PARAM, R_TOUCH_ButtonOpen((touch_button_ctrl_t *)&g_touch_button_ctrl_tg1, &touch_button_tg1));
#if defined(BSP_MCU_GROUP_S3A7)
	extern touch_button_cfg_t Button_RX00_on_g_touch_cfg_on_g_ctsu_cfg_self;
	p_cfg_valid_extern = &Button_RX00_on_g_touch_cfg_on_g_ctsu_cfg_self;
#endif

	memcpy( &touch_button_tg1,
			p_cfg_valid_extern,
			sizeof(touch_button_cfg_t));
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonOpen((touch_button_ctrl_t *)&g_touch_button_ctrl_tg1, &touch_button_tg1));
}

/***********************************************************************************************************************
* Function Name: TC_1_2_Open_Close_Handle
* Description  : Checking Open and closing handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_BUTTON_TG1, TC_1_2_Open_Close_Handle)
{
	touch_button_cfg_t * p_cfg_valid_extern;
#if defined(BSP_MCU_GROUP_S3A7)
	extern touch_button_cfg_t Button_RX00_on_g_touch_cfg_on_g_ctsu_cfg_self;
	p_cfg_valid_extern = &Button_RX00_on_g_touch_cfg_on_g_ctsu_cfg_self;
#endif
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonOpen((touch_button_ctrl_t *)&g_touch_button_ctrl_tg1, p_cfg_valid_extern));
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonClose(&g_touch_button_ctrl_tg1));
}


/***********************************************************************************************************************
* Function Name: TC_1_3_Control_Handle
* Description  : Checking Controlling Button handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_BUTTON_TG1, TC_1_3_Control_Handle)
{
	touch_button_cfg_t * p_cfg_valid_extern;
	touch_button_control_arg_t control_arg;

	typedef union
	{
		uint32_t touch_hdl;
		touch_sensor_t sensor;
		touch_button_callback_t p_callback;
		uint8_t enable_mask;
		touch_button_event_t event;
		uint16_t debounce_counter;
		uint16_t active_counter;
	}result_t;

	result_t result;

#if defined(BSP_MCU_GROUP_S3A7)
	extern touch_button_cfg_t Button_RX00_on_g_touch_cfg_on_g_ctsu_cfg_self;
	p_cfg_valid_extern = &Button_RX00_on_g_touch_cfg_on_g_ctsu_cfg_self;
#endif
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonOpen((touch_button_ctrl_t *)&g_touch_button_ctrl_tg1, p_cfg_valid_extern));

	result.sensor.rx = 0xAA;
	result.sensor.tx = 0xBB;

	control_arg.cmd = TOUCH_BUTTON_SET_CHANNELS;
	control_arg.p_dest = &result.sensor;
	control_arg.size = sizeof(&result.sensor);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_CHANNELS;
	control_arg.p_dest = &result.sensor;
	control_arg.size = sizeof(&result.sensor);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));
	TEST_ASSERT_EQUAL( 0xAA, result.sensor.rx );
	TEST_ASSERT_EQUAL( 0xBB, result.sensor.tx );

	result.p_callback = touch_event_callback_tg1;
	control_arg.cmd = TOUCH_BUTTON_SET_CALLBACK;
	control_arg.p_dest = &result.p_callback;
	control_arg.size = sizeof(result.p_callback);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_CALLBACK;
	control_arg.p_dest = &result.p_callback;
	control_arg.size = sizeof(result.p_callback);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));
	TEST_ASSERT_EQUAL( touch_event_callback_tg1, result.p_callback );

	result.enable_mask = 0x07;
	control_arg.cmd = TOUCH_BUTTON_SET_ENABLE_MASK;
	control_arg.p_dest = &result.enable_mask;
	control_arg.size = sizeof(result.enable_mask);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_ENABLE_MASK;
	control_arg.p_dest = &result.enable_mask;
	control_arg.size = sizeof(result.enable_mask);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));
	TEST_ASSERT_EQUAL( 0x7, result.enable_mask );

	result.event = TOUCH_BUTTON_EVENT_RELEASED;
	control_arg.cmd = TOUCH_BUTTON_SET_STATE;
	control_arg.p_dest = &result.event;
	control_arg.size = sizeof(result.event);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_STATE;
	control_arg.p_dest = &result.event;
	control_arg.size = sizeof(result.event);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));
	TEST_ASSERT_EQUAL( TOUCH_BUTTON_EVENT_RELEASED, result.event);

	result.debounce_counter = 0x55;
	control_arg.cmd = TOUCH_BUTTON_SET_DEBOUNCE_COUNTER;
	control_arg.p_dest = &result.debounce_counter;
	control_arg.size = sizeof(result.debounce_counter);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_DEBOUNCE_COUNTER;
	control_arg.p_dest = &result.debounce_counter;
	control_arg.size = sizeof(result.debounce_counter);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));
	TEST_ASSERT_EQUAL( 0x55, result.debounce_counter );

	result.active_counter = 0xAA;
	control_arg.cmd = TOUCH_BUTTON_SET_HOLD_COUNTER;
	control_arg.p_dest = &result.active_counter;
	control_arg.size = sizeof(result.active_counter);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_HOLD_COUNTER;
	control_arg.p_dest = &result.active_counter;
	control_arg.size = sizeof(result.active_counter);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));
	TEST_ASSERT_EQUAL( 0xAA, result.active_counter );

	result.touch_hdl = 1;

	control_arg.cmd = TOUCH_BUTTON_SET_TOUCH_HANDLE;
	control_arg.p_dest = &result.touch_hdl;
	control_arg.size = sizeof(&result.touch_hdl);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_TOUCH_HANDLE;
	control_arg.p_dest = &result.touch_hdl;
	control_arg.size = sizeof(&result.touch_hdl);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(&g_touch_button_ctrl_tg1, &control_arg));
	TEST_ASSERT_EQUAL( 1, result.touch_hdl );



	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonClose(&g_touch_button_ctrl_tg1));
}

/***********************************************************************************************************************
* Function Name: TC_1_4_Update_Test
* Description  : Test if buttons get reported back correctly.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_BUTTON_TG1, TC_1_4_Update_Test)
{
	touch_button_cfg_t touch_button_cfg[3];
	uint32_t button_hdl_idx[3];
	uint32_t touch_hdl_idx[3];
	uint32_t itr;

	touch_button_control_arg_t control_arg;

#if defined(BSP_MCU_GROUP_S3A7)
	extern touch_button_cfg_t Button_RX00_on_g_touch_cfg_on_g_ctsu_cfg_self;
	extern touch_button_cfg_t Button_RX01_on_g_touch_cfg_on_g_ctsu_cfg_self;
	extern touch_button_cfg_t Button_RX21_on_g_touch_cfg_on_g_ctsu_cfg_self;

	memcpy(&touch_button_cfg[0], &Button_RX00_on_g_touch_cfg_on_g_ctsu_cfg_self, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[1], &Button_RX01_on_g_touch_cfg_on_g_ctsu_cfg_self, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[2], &Button_RX21_on_g_touch_cfg_on_g_ctsu_cfg_self, sizeof(touch_button_cfg_t));

	const uint8_t max_itr_count = 3;
#endif

	for(itr = 0; itr < max_itr_count; itr++)
	{	/* Open multiple handles */
	    touch_button_cfg[itr].enable.bit.hold = true;
		touch_button_cfg[itr].p_callback = touch_event_callback_tg1;
		TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonOpen(&button_hdl_idx[itr], &touch_button_cfg[itr]));
		control_arg.cmd = TOUCH_BUTTON_GET_TOUCH_HANDLE;
		control_arg.p_dest = &touch_hdl_idx[itr];
		control_arg.size = sizeof(touch_hdl_idx[itr]);
		TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(button_hdl_idx[itr], &control_arg));
	}

	while(touch_count != 23)
	{
		for(itr = 0; itr < max_itr_count; itr++)
		{	/* Scan with handle */
			TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_StartScan(touch_hdl_idx[itr]));
			while(TOUCH_SUCCESS != R_TOUCH_Update(touch_hdl_idx[itr]));
		}

		if(touch_count > 23)
		{
			touch_count = 0;
		}
	}

	for(itr = 0; itr < max_itr_count; itr++)
	{	/* Close multiple handles */
		TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonClose(button_hdl_idx[itr]));
		R_TOUCH_Close(touch_hdl_idx[itr]);
	}

}

void touch_event_callback_tg1(touch_button_callback_arg_t * const p_arg)
{
	if(TOUCH_BUTTON_EVENT_REQUEST_DELAY == p_arg->event)
	{
		R_BSP_SoftwareDelay(500, BSP_DELAY_UNITS_MICROSECONDS);
	}
	else if(TOUCH_BUTTON_EVENT_HOLD==p_arg->event)
	{
		if(0 == p_arg->id)
		{
			touch_count += 5;
		}
		else if(1 == p_arg->id)
		{
			touch_count += 7;
		}
		else if(2 == p_arg->id)
		{
			touch_count += 11;
		}
#if 0
		if(touch_count != p_arg->info)
		{
			if(p_arg->info > touch_count)
			{
				printf("Touched!\n\r");
			}
			else if(p_arg->info < touch_count)
			{
				printf("Released!\n\r");
			}
		}

		touch_count = p_arg->info;

		if(touch_count > 0)
		{
			LED1 = LED_ON;
		}
		else
		{
			LED1 = LED_OFF;
		}
#endif
	}
}
