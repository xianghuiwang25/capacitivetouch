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
* File Name : r_touch_tests_tg2.c
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
#include "platform.h"
#include "r_touch_rx_common_test.h"
#include "r_touch_button_config.h"
#include "r_touch_button_if.h"


#if defined(BSP_MCU_RX130)
#define CAPTOUCH_BUTTON_COUNT	(20)
#endif

static void touch_event_callback_tg2(void* p_arg);
static uint32_t hdl_idx = UINT32_MAX;
static uint32_t scan_count = 0;
static uint16_t touch_count = 0;
static uint16_t results[256];

static const char console_messages[][32] =
{
		"\n\rPlease Touch Buttons",
};

/* Define test groups. */
TEST_GROUP(TOUCH_TG2);

/***********************************************************************************************************************
* Function Name: TEST_SETUP
* Description  : Setup for these unit tests. This will be run before every test case.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST_SETUP(TOUCH_TG2)
{
#if defined(BSP_MCU_RX113)
	touch_rx113_init_ports();
#elif defined(BSP_MCU_RX130)
	touch_rx130_init_ports();
	printf("\n\rPlug the \"Self-Capacitance Buttons/Wheels/Slider\" board into the kit.");
	printf("\n\rPress SW5 on MCU board to start test.");
	while(SW5!=SW_ACTIVE);
	while(SW5==SW_ACTIVE);
	printf("Running Test...");
#elif defined(BSP_MCU_RX230)
	touch_rx230_init_ports();
#elif defined(BSP_MCU_RX231)
	touch_rx231_init_ports();
#else
#error "Undefined Board Support package"
#endif
}

/***********************************************************************************************************************
* Function Name: TEST_TEAR_DOWN
* Description  : Tear down for these unit tests. This will be run after each test case.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST_TEAR_DOWN(TOUCH_TG2)
{
	hdl_idx = UINT32_MAX;
	scan_count = 0;
	touch_count = 0;
	for(uint32_t itr = 0; itr < BUTTON_CFG_MAX_CONTROL_BLOCK_COUNT; itr++)
	{	/* Close any open blocks */
		R_TOUCH_ButtonClose(itr);
	}
}

/***********************************************************************************************************************
* Function Name: TC_2_0_GetVersion
* Description  : Checking GetVersion function.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_0_GetVersion)
{
    TEST_ASSERT_EQUAL_UINT32((uint32_t)((TOUCH_BUTTON_VERSION_MAJOR << 16) | (TOUCH_BUTTON_VERSION_MINOR)), R_TOUCH_ButtonGetVersion());
}

/***********************************************************************************************************************
* Function Name: TC_2_1_Open_Invalid_Param_test
* Description  : Test invalid parameter rejection.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_1_Open_Invalid_Param_test)
{
	touch_button_cfg_t	touch_button_tg2;
	touch_button_cfg_t * p_cfg_valid_extern;
	memset(&touch_button_tg2, 0, sizeof(touch_button_cfg_t));

	TEST_ASSERT_EQUAL( TOUCH_BUTTON_ERR_INVALID_PARAM, R_TOUCH_ButtonOpen(NULL, NULL));
	TEST_ASSERT_EQUAL( TOUCH_BUTTON_ERR_INVALID_PARAM, R_TOUCH_ButtonOpen(&hdl_idx, NULL));
	TEST_ASSERT_EQUAL( TOUCH_BUTTON_ERR_INVALID_PARAM, R_TOUCH_ButtonOpen(&hdl_idx, &touch_button_tg2));
#if defined(CTSENSOR_RX130_H)
	extern touch_button_cfg_t const Button_RX27_TX05_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	p_cfg_valid_extern = (touch_button_cfg_t * )&Button_RX27_TX05_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
#endif

	memcpy( &touch_button_tg2,
			p_cfg_valid_extern,
			sizeof(touch_button_cfg_t));
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonOpen(&hdl_idx, &touch_button_tg2));
}

/***********************************************************************************************************************
* Function Name: TC_2_2_Open_Close_Handle
* Description  : Checking Open and closing handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_2_Open_Close_Handle)
{
	touch_button_cfg_t * p_cfg_valid_extern;
#if defined(CTSENSOR_RX130_H)
	extern touch_button_cfg_t const Button_RX27_TX05_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	p_cfg_valid_extern = (touch_button_cfg_t * )&Button_RX27_TX05_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
#endif
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonOpen(&hdl_idx, p_cfg_valid_extern));
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonClose(hdl_idx));
}

/***********************************************************************************************************************
* Function Name: TC_2_3_Control_Handle
* Description  : Checking Controlling Button handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_3_Control_Handle)
{
	touch_button_cfg_t * p_cfg_valid_extern;
	touch_button_control_arg_t control_arg;

	typedef union
	{
		uint32_t touch_hdl;
		touch_sensor_t sensor;
		fit_callback_t p_callback;
		uint8_t enable_mask;
		touch_button_event_t event;
		uint16_t debounce_counter;
		uint16_t active_counter;
	}result_t;

	result_t result;

#if defined(CTSENSOR_RX130_H)
	extern touch_button_cfg_t Button_RX00_on_g_touch_cfg_on_g_ctsu_cfg_self;
	p_cfg_valid_extern = &Button_RX00_on_g_touch_cfg_on_g_ctsu_cfg_self;
#endif
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonOpen(&hdl_idx, p_cfg_valid_extern));

	result.sensor.rx = 0xAA;
	result.sensor.tx = 0xBB;

	control_arg.cmd = TOUCH_BUTTON_SET_CHANNELS;
	control_arg.p_dest = &result.sensor;
	control_arg.size = sizeof(&result.sensor);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_CHANNELS;
	control_arg.p_dest = &result.sensor;
	control_arg.size = sizeof(&result.sensor);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));
	TEST_ASSERT_EQUAL( 0xAA, result.sensor.rx );
	TEST_ASSERT_EQUAL( 0xBB, result.sensor.tx );

	result.p_callback = touch_event_callback_tg2;
	control_arg.cmd = TOUCH_BUTTON_SET_CALLBACK;
	control_arg.p_dest = &result.p_callback;
	control_arg.size = sizeof(result.p_callback);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_CALLBACK;
	control_arg.p_dest = &result.p_callback;
	control_arg.size = sizeof(result.p_callback);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));
	TEST_ASSERT_EQUAL( touch_event_callback_tg2, result.p_callback );

	result.enable_mask = 0x07;
	control_arg.cmd = TOUCH_BUTTON_SET_ENABLE_MASK;
	control_arg.p_dest = &result.enable_mask;
	control_arg.size = sizeof(result.enable_mask);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_ENABLE_MASK;
	control_arg.p_dest = &result.enable_mask;
	control_arg.size = sizeof(result.enable_mask);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));
	TEST_ASSERT_EQUAL( 0x7, result.enable_mask );

	result.event = TOUCH_BUTTON_EVENT_RELEASED;
	control_arg.cmd = TOUCH_BUTTON_SET_STATE;
	control_arg.p_dest = &result.event;
	control_arg.size = sizeof(result.event);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_STATE;
	control_arg.p_dest = &result.event;
	control_arg.size = sizeof(result.event);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));
	TEST_ASSERT_EQUAL( TOUCH_BUTTON_EVENT_RELEASED, result.event);

	result.debounce_counter = 0x55;
	control_arg.cmd = TOUCH_BUTTON_SET_DEBOUNCE_COUNTER;
	control_arg.p_dest = &result.debounce_counter;
	control_arg.size = sizeof(result.debounce_counter);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_DEBOUNCE_COUNTER;
	control_arg.p_dest = &result.debounce_counter;
	control_arg.size = sizeof(result.debounce_counter);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));
	TEST_ASSERT_EQUAL( 0x55, result.debounce_counter );

	result.active_counter = 0xAA;
	control_arg.cmd = TOUCH_BUTTON_SET_HOLD_COUNTER;
	control_arg.p_dest = &result.active_counter;
	control_arg.size = sizeof(result.active_counter);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_HOLD_COUNTER;
	control_arg.p_dest = &result.active_counter;
	control_arg.size = sizeof(result.active_counter);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));
	TEST_ASSERT_EQUAL( 0xAA, result.active_counter );

	result.touch_hdl = 1;

	control_arg.cmd = TOUCH_BUTTON_SET_TOUCH_HANDLE;
	control_arg.p_dest = &result.touch_hdl;
	control_arg.size = sizeof(&result.touch_hdl);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));

	control_arg.cmd = TOUCH_BUTTON_GET_TOUCH_HANDLE;
	control_arg.p_dest = &result.touch_hdl;
	control_arg.size = sizeof(&result.touch_hdl);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonControl(hdl_idx, &control_arg));
	TEST_ASSERT_EQUAL( 1, result.touch_hdl );



	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_ButtonClose(hdl_idx));
}

/***********************************************************************************************************************
* Function Name: TC_2_4_Update_Test
* Description  : Test if buttons get reported back correctly.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
touch_button_cfg_t touch_button_cfg[20];
uint32_t button_hdl_idx[20];
uint32_t touch_hdl_idx[20];
TEST(TOUCH_TG2, TC_2_4_Update_Test)
{
	uint32_t itr;
	touch_button_control_arg_t control_arg;

#if defined(CTSENSOR_RX130_H)
	extern touch_button_cfg_t const Button_RX27_TX05_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX27_TX06_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX27_TX07_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX27_TX08_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX27_TX09_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX30_TX05_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX30_TX06_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX30_TX07_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX30_TX08_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX30_TX09_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX33_TX05_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX33_TX06_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX33_TX07_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX33_TX08_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX33_TX09_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX35_TX05_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX35_TX06_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX35_TX07_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX35_TX08_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;
	extern touch_button_cfg_t const Button_RX35_TX08_on_g_touch_cfg_on_g_ctsu_cfg_mutual0;

	memcpy(&touch_button_cfg[0] , &Button_RX27_TX05_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[1] , &Button_RX27_TX06_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[2] , &Button_RX27_TX07_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[3] , &Button_RX27_TX08_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[4] , &Button_RX27_TX09_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[5] , &Button_RX30_TX05_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[6] , &Button_RX30_TX06_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[7] , &Button_RX30_TX07_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[8] , &Button_RX30_TX08_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[9] , &Button_RX30_TX09_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[10], &Button_RX33_TX05_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[11], &Button_RX33_TX06_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[12], &Button_RX33_TX07_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[13], &Button_RX33_TX08_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[14], &Button_RX33_TX09_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[15], &Button_RX35_TX05_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[16], &Button_RX35_TX06_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[17], &Button_RX35_TX07_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[18], &Button_RX35_TX08_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));
	memcpy(&touch_button_cfg[19], &Button_RX35_TX08_on_g_touch_cfg_on_g_ctsu_cfg_mutual0, sizeof(touch_button_cfg_t));

	const uint8_t max_itr_count = 20;
#endif

	for(itr = 0; itr < max_itr_count; itr++)
	{	/* Open multiple handles */
	    touch_button_cfg[itr].enable.hold = true;
		touch_button_cfg[itr].p_callback = touch_event_callback_tg2;
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

void touch_event_callback_tg2(void* arg)
{
	touch_button_callback_arg_t * p_arg = arg;

	if(TOUCH_BUTTON_EVENT_REQUEST_DELAY == p_arg->event)
	{
		R_BSP_SoftwareDelay(500, BSP_DELAY_MICROSECS);
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
