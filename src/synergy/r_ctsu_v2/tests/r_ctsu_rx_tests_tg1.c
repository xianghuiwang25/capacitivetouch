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
* Copyright (C) 2015 Renesas Electronics Corporation. All rights reserved.
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name	   : r_ctsu_synergy_tests_tg1.c
* Description  : Unity unit tests for RX Touch module (In self capacitance mode)
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 06.16.2016 1.00     First Release
***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @file
 ***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @ingroup TESTING
 * @defgroup TEST_GROUP1
 * @brief This is a brief description
 * @{
 * Sample Usage:
 *  TEST_GROUP_RUNNER(CTSU_TG1)
 *  {
 *      RUN_TEST_CASE(CTSU_TG1, TC_1_0_GetVersion);
 *      RUN_TEST_CASE(CTSU_TG1, TC_1_1_Open_Invalid_Param_test);
 *      RUN_TEST_CASE(CTSU_TG1, TC_1_2_Open_Close_Handle);
 *      RUN_TEST_CASE(CTSU_TG1, TC_1_3_Scan_Multiple_Handles);
 *      RUN_TEST_CASE(CTSU_TG1, TC_1_4_Read_Results);
 *      RUN_TEST_CASE(CTSU_TG1, TC_1_5_Control_Get_Tests);
 *      RUN_TEST_CASE(CTSU_TG1, TC_1_6_Control_Set_Tests);
 *      RUN_TEST_CASE(CTSU_TG1, TC_1_7_Calibrate_Handle);
 *  }
 *
 ***********************************************************************************************************************/
/***********************************************************************************************************************
* Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "unity_fixture.h"

#include "r_ctsu_synergy_common_test.h"


/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

#define CTSU_CFG_MAX_CONTROL_BLOCK_COUNT    (4)

#define TOUCH_CONFIG0    (g_ctsu_cfg_self_all)
#define TOUCH_CONFIG1    (g_ctsu_cfg_self_buttons)
#define TOUCH_CONFIG2    (g_ctsu_cfg_self_slider)
#define TOUCH_CONFIG3    (g_ctsu_cfg_self_inner_wheel)
#define TOUCH_CONFIG4    (g_ctsu_cfg_self_outer_wheel)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/


/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/
static void ctsu_event_callback_tg1(ctsu_callback_arg_t const * const p_arg);
//static uint32_t hdl_idx = UINT32_MAX;
static uint32_t scan_count = 0;
static uint32_t event_mask = 0;

extern ctsu_cfg_t TOUCH_CONFIG0;
extern ctsu_cfg_t TOUCH_CONFIG1;
extern ctsu_cfg_t TOUCH_CONFIG2;
extern ctsu_cfg_t TOUCH_CONFIG3;
extern ctsu_cfg_t TOUCH_CONFIG4;

/* Define test groups. */
TEST_GROUP(CTSU_TG1);

/***********************************************************************************************************************
* Function Name: TEST_CTSU_TG1_SETUP
* Description  : Setup for these unit tests. This will be run before every test case.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST_SETUP(CTSU_TG1)
{
	printf("Plug the \"Self-Capacitance Buttons/Wheels/Slider\" board into the kit.\n\r");
	printf("Press SW3 on MCU board to start test.\n\r");
	while(get_pin_level(SW3)!=SW_ACTIVE);
	while(get_pin_level(SW3)==SW_ACTIVE);
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG1_SETUP
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: TEST_CTSU_TG1_TEAR_DOWN
* Description  : Tear down for these unit tests. This will be run after each test case.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST_TEAR_DOWN(CTSU_TG1)
{
	scan_count = 0;
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG1_TEAR_DOWN
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: TC_1_0_GetVersion
* Description  : Checking GetVersion function.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(CTSU_TG1, TC_1_0_GetVersion)
{

}
/***********************************************************************************************************************
End of function TEST_CTSU_TG1_TC_1_0_GetVersion_
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: TC_1_1_Open_Invalid_Param_test
* Description  : Test invalid parameter rejection.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(CTSU_TG1, TC_1_1_Open_Invalid_Param_test)
{
	ctsu_cfg_t	ctsu_cfg_tg1;
	ctsu_cfg_t *	p_ctsu_cfg_tg1;
	ctsu_cfg_t *	p_ctsu_cfg_valid_extern;
	ctsu_instance_ctrl_t ctsu_ctrl;

	memset(&ctsu_ctrl, 0, sizeof(ctsu_ctrl));

	memset(&ctsu_cfg_tg1, 0, sizeof(ctsu_cfg_t));

	TEST_ASSERT_EQUAL( CTSU_ERR_INVALID_PARAM, R_CTSU_Open(NULL, NULL));
	p_ctsu_cfg_tg1 = NULL;
	TEST_ASSERT_EQUAL( CTSU_ERR_INVALID_PARAM, R_CTSU_Open(&ctsu_ctrl, p_ctsu_cfg_tg1));
	p_ctsu_cfg_tg1 = &ctsu_cfg_tg1;
	TEST_ASSERT_EQUAL( CTSU_ERR_INVALID_PARAM, R_CTSU_Open(&ctsu_ctrl, p_ctsu_cfg_tg1));
#if defined(BSP_MCU_GROUP_S3A7)
	p_ctsu_cfg_valid_extern = &TOUCH_CONFIG0;
#elif defined(YRX113CAPT01_H)
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self01;
	p_ctsu_cfg_valid_extern = &g_ctsu_cfg_yrx113capt01_self01;
#endif
	p_ctsu_cfg_tg1->pclkb_hz = p_ctsu_cfg_valid_extern->pclkb_hz;
	TEST_ASSERT_EQUAL( CTSU_ERR_INVALID_PARAM, R_CTSU_Open(&ctsu_ctrl, p_ctsu_cfg_tg1));
	p_ctsu_cfg_tg1->p_sensor_data = p_ctsu_cfg_valid_extern->p_sensor_data;
	TEST_ASSERT_EQUAL( CTSU_ERR_INVALID_PARAM, R_CTSU_Open(&ctsu_ctrl, p_ctsu_cfg_tg1));
	p_ctsu_cfg_tg1->p_sensor_settings = p_ctsu_cfg_valid_extern->p_sensor_settings;
	TEST_ASSERT_EQUAL( CTSU_ERR_INVALID_PARAM, R_CTSU_Open(&ctsu_ctrl, p_ctsu_cfg_tg1));
	memcpy(&p_ctsu_cfg_tg1->p_ctsu_settings, &p_ctsu_cfg_valid_extern->p_ctsu_settings, sizeof(ctsu_const_sfrs_t));
#if (CTSU_CFG_ENABLE_CORRECTION==true)
//	TEST_ASSERT_EQUAL( CTSU_ERR_INVALID_PARAM, R_CTSU_Open(&hdl_idx, p_ctsu_cfg_tg1));
//	p_ctsu_cfg_tg1->correction_ctsuso_delta = p_ctsu_cfg_valid_extern->correction_ctsuso_delta;
//	TEST_ASSERT_EQUAL( CTSU_ERR_INVALID_PARAM, R_CTSU_Open(&hdl_idx, p_ctsu_cfg_tg1));
//	p_ctsu_cfg_tg1->correction_factor_sec_cal = p_ctsu_cfg_valid_extern->correction_factor_sec_cal;
//	TEST_ASSERT_EQUAL( CTSU_ERR_INVALID_PARAM, R_CTSU_Open(&hdl_idx, p_ctsu_cfg_tg1));
//	p_ctsu_cfg_tg1->correction_factor_pri_cal = p_ctsu_cfg_valid_extern->correction_factor_pri_cal;
#endif //CTSU_CFG_ENABLE_CORRECTION==true
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG1_TC_1_1_Open_Invalid_Param_test_
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: TC_1_2_Open_Close_Handle
* Description  : Checking Open and closing handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(CTSU_TG1, TC_1_2_Open_Close_Handle)
{
	ctsu_cfg_t *	p_ctsu_cfg_valid_extern;
	ctsu_instance_ctrl_t ctsu_ctrl;
	memset(&ctsu_ctrl, 0, sizeof(ctsu_ctrl));
#if defined(BSP_MCU_GROUP_S3A7)
	p_ctsu_cfg_valid_extern = &TOUCH_CONFIG0;
#elif defined(YRX113CAPT01_H)
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self01;
	p_ctsu_cfg_valid_extern = &g_ctsu_cfg_yrx113capt01_self01;
#endif

	TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Open(&ctsu_ctrl, p_ctsu_cfg_valid_extern));
	TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Close(&ctsu_ctrl));
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG1_TC_1_2_Open_Close_Handle_
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: TC_1_3_Scan_Multiple_Handles
* Description  : Checking Open, scan and close with handles multiple handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(CTSU_TG1, TC_1_3_Scan_Multiple_Handles)
{
	ctsu_cfg_t * self_configs[CTSU_CFG_MAX_CONTROL_BLOCK_COUNT];
	ctsu_instance_ctrl_t self_hdl_idx[CTSU_CFG_MAX_CONTROL_BLOCK_COUNT];
	uint16_t num_sensors[CTSU_CFG_MAX_CONTROL_BLOCK_COUNT];
	uint32_t scan_count_copy;
	uint32_t itr;
	uint8_t max_itr_count;
	uint16_t* p_memory_before;
	uint16_t memory_before_value;
	uint16_t* p_memory_after;
	uint32_t memory_after_value;
    uint64_t tspin_mask = 0;
    memset(self_hdl_idx, 0, sizeof(self_hdl_idx));
#if defined(BSP_MCU_GROUP_S3A7)
	max_itr_count = ((sizeof(self_configs))/(sizeof(self_configs[0]))) - 1;

	self_configs[0] = &TOUCH_CONFIG1;
	num_sensors[0] = ctsu_get_pin_count(ctsu_get_tspin_mask(self_configs[0])) & UINT16_MAX;
	self_configs[1] = &TOUCH_CONFIG2;
	num_sensors[1] = ctsu_get_pin_count(ctsu_get_tspin_mask(self_configs[1])) & UINT16_MAX;
	self_configs[2] = &TOUCH_CONFIG3;
	num_sensors[2] = ctsu_get_pin_count(ctsu_get_tspin_mask(self_configs[2])) & UINT16_MAX;
	self_configs[3] = &TOUCH_CONFIG4;
	num_sensors[3] = ctsu_get_pin_count(ctsu_get_tspin_mask(self_configs[3])) & UINT16_MAX;
#elif defined(YRX113CAPT01_H)
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self02;
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self03;
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self04;
	max_itr_count = 3;

	self_configs[0] = &g_ctsu_cfg_yrx113capt01_self04;
	num_sensors[0] = 3;
	self_configs[1] = &g_ctsu_cfg_yrx113capt01_self02;
	num_sensors[1] = 5;
	self_configs[2] = &g_ctsu_cfg_yrx113capt01_self03;
	num_sensors[2] = 4;
#endif

	tspin_mask = 0;

	for(itr = 0; itr < max_itr_count; itr++)
	{
	    /* Open multiple handles */
		self_configs[itr]->p_callback = ctsu_event_callback_tg1;
		TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Open(&self_hdl_idx[itr], self_configs[itr]));
		tspin_mask |= ctsu_get_tspin_mask(self_configs[itr]);
	}

	ctsu_pin_init(tspin_mask);

	for(itr = 0; itr < max_itr_count; itr++)
	{
	    /* Scan with handle */
		scan_count = scan_count_copy = 0;

		p_memory_before = self_configs[itr]->p_sensor_data;
		p_memory_before = p_memory_before - 1;
		memory_before_value = *p_memory_before;
		p_memory_after = self_configs[itr]->p_sensor_data;
		p_memory_after = p_memory_after + (num_sensors[itr]*2);
		memory_after_value = *p_memory_after;

		/* Set all values for the sensor data to 0 */
		memset(self_configs[itr]->p_sensor_data, 0, (num_sensors[itr]*sizeof(uint16_t))*2);

		while(scan_count < 8)
		{
		    /* 8 Scans per configuration */
			TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Scan(&self_hdl_idx[itr]));
			do{;}while(scan_count==scan_count_copy);
			/* Test if data is actually written to the locations */
			uint16_t * p_output = self_configs[itr]->p_sensor_data;
			for(uint16_t sensor_itr = 0; sensor_itr < num_sensors[itr]; sensor_itr++)
			{
			    uint16_t ctsusc = p_output[(2*sensor_itr) + 0];
			    uint16_t ctsurc = p_output[(2*sensor_itr) + 1];
			    TEST_ASSERT_NOT_EQUAL(0, ctsusc);
			    TEST_ASSERT_NOT_EQUAL(0, ctsurc);
			}

			scan_count_copy = scan_count;

			/* Test for unexpected memory changes */
			TEST_ASSERT_EQUAL(memory_before_value, *p_memory_before);
			TEST_ASSERT_EQUAL(memory_after_value, *p_memory_after);
		}

		/* Test for unexpected memory changes */
		TEST_ASSERT_EQUAL(memory_before_value, *p_memory_before);
		TEST_ASSERT_EQUAL(memory_after_value, *p_memory_after);

	}

	for(itr = 0; itr < max_itr_count; itr++)
	{
	    /* Close multiple handles */
		TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Close(&self_hdl_idx[itr]));
	}

}
/***********************************************************************************************************************
End of function TEST_CTSU_TG1_TC_1_3_Scan_Multiple_Handles_
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: TC_1_4_Read_Results
* Description  : Checking Open and closing handles multiple handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(CTSU_TG1, TC_1_4_Read_Results)
{
	ctsu_cfg_t * self_configs[CTSU_CFG_MAX_CONTROL_BLOCK_COUNT];
	ctsu_instance_ctrl_t self_hdl_idx[CTSU_CFG_MAX_CONTROL_BLOCK_COUNT];
	uint16_t num_sensors[CTSU_CFG_MAX_CONTROL_BLOCK_COUNT];
	uint32_t itr;
	uint8_t max_itr_count;
	uint16_t sensor_itr;
	uint16_t* p_result_start;
	uint16_t compare_buffer[CAPTOUCH_SENSOR_COUNT*2];
	uint16_t sensor_output;
	ctsu_read_t result_read_cmd;
	uint16_t sensor_offset[CAPTOUCH_SENSOR_COUNT];
	uint64_t tspin_mask;
	memset(self_hdl_idx, 0, sizeof(self_hdl_idx));
#if defined(BSP_MCU_GROUP_S3A7)
	max_itr_count = (sizeof(self_configs))/(sizeof(self_configs[0])) - 1;

    self_configs[0] = &TOUCH_CONFIG1;
    num_sensors[0] = ctsu_get_pin_count(ctsu_get_tspin_mask(self_configs[0])) & UINT16_MAX;
    self_configs[1] = &TOUCH_CONFIG2;
    num_sensors[1] = ctsu_get_pin_count(ctsu_get_tspin_mask(self_configs[1])) & UINT16_MAX;
    self_configs[2] = &TOUCH_CONFIG3;
    num_sensors[2] = ctsu_get_pin_count(ctsu_get_tspin_mask(self_configs[2])) & UINT16_MAX;
    self_configs[3] = &TOUCH_CONFIG4;
    num_sensors[3] = ctsu_get_pin_count(ctsu_get_tspin_mask(self_configs[3])) & UINT16_MAX;
#elif defined(YRX113CAPT01_H)
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self02;
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self03;
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self04;
	max_itr_count = 3;

	self_configs[0] = &g_ctsu_cfg_yrx113capt01_self04;
	num_sensors[0] = 3;
	self_configs[1] = &g_ctsu_cfg_yrx113capt01_self02;
	num_sensors[1] = 5;
	self_configs[2] = &g_ctsu_cfg_yrx113capt01_self03;
	num_sensors[2] = 4;
#endif

	tspin_mask = 0;

	for(itr = 0; itr < max_itr_count; itr++)
	{
	    /* Open multiple handles */
		self_configs[itr]->p_callback = ctsu_event_callback_tg1;
		TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Open(&self_hdl_idx[itr], self_configs[itr]));
		tspin_mask |= ctsu_get_tspin_mask(self_configs[itr]);
	}

	ctsu_pin_init(tspin_mask);

	for(itr = 0; itr < max_itr_count; itr++)
	{
	    /* Open multiple handles */
		p_result_start = self_configs[itr]->p_sensor_data;
		memset(p_result_start, 0, ((p_result_start + (num_sensors[itr]*2U)) - p_result_start) & UINT16_MAX);
		memset(compare_buffer, 0, sizeof(compare_buffer));
		scan_count = 0;
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Scan(&self_hdl_idx[itr]));
		do{;}while(scan_count < 1);

		result_read_cmd.ctsu_result = CTSU_READ_BUFFER_ALL;
		result_read_cmd.p_dest = compare_buffer;
		result_read_cmd.size = sizeof(compare_buffer);
		result_read_cmd.count = num_sensors[itr];
		result_read_cmd.sensor_offset = &sensor_itr;
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Read(&self_hdl_idx[itr], &result_read_cmd));
		TEST_ASSERT_EQUAL(0 , memcmp(p_result_start, compare_buffer, num_sensors[itr]*2U*sizeof(uint16_t)));


		for(sensor_itr = 0; sensor_itr < num_sensors[itr]; sensor_itr++)
		{
			memset(compare_buffer, 0, sizeof(compare_buffer));
			sensor_output = 0;
			sensor_offset[sensor_itr] = sensor_itr;
			result_read_cmd.count = 1;
			result_read_cmd.sensor_offset = &sensor_offset[sensor_itr];

			result_read_cmd.ctsu_result = CTSU_READ_SENSOR_COUNT_PRIMARY;
			result_read_cmd.p_dest = &compare_buffer[0];
			TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Read(&self_hdl_idx[itr], &result_read_cmd));
			TEST_ASSERT_EQUAL(compare_buffer[0], p_result_start[sensor_itr*2]);

			result_read_cmd.ctsu_result = CTSU_READ_REFERENCE_COUNT_PRIMARY;
			result_read_cmd.p_dest = &compare_buffer[1];
			TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Read(&self_hdl_idx[itr], &result_read_cmd));
			TEST_ASSERT_EQUAL(compare_buffer[1], p_result_start[sensor_itr*2+1]);

			result_read_cmd.ctsu_result = CTSU_READ_SENSOR_COUNT_SECONDARY;
			result_read_cmd.p_dest = &compare_buffer[2];
			TEST_ASSERT_EQUAL(CTSU_ERR_INVALID_CMD, R_CTSU_Read(&self_hdl_idx[itr], &result_read_cmd));
			result_read_cmd.ctsu_result = CTSU_READ_REFERENCE_COUNT_SECONDARY;
			result_read_cmd.p_dest = &compare_buffer[3];
			TEST_ASSERT_EQUAL(CTSU_ERR_INVALID_CMD, R_CTSU_Read(&self_hdl_idx[itr], &result_read_cmd));

			result_read_cmd.ctsu_result = CTSU_READ_SENSOR_OUTPUT;
			result_read_cmd.p_dest = &sensor_output;
			TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Read(&self_hdl_idx[itr], &result_read_cmd));
			TEST_ASSERT_EQUAL(compare_buffer[0], sensor_output);
		}

		memset(compare_buffer, 0, sizeof(compare_buffer));
		result_read_cmd.sensor_offset = &sensor_offset[0];

		result_read_cmd.ctsu_result = CTSU_READ_SENSOR_COUNT_PRIMARY;
		result_read_cmd.p_dest = &compare_buffer[0];
		result_read_cmd.count = num_sensors[itr];
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Read(&self_hdl_idx[itr], &result_read_cmd));

		for(sensor_itr = 0; sensor_itr < num_sensors[itr]; sensor_itr++)
		{
			TEST_ASSERT_EQUAL(compare_buffer[sensor_itr], p_result_start[sensor_itr*2]);
		}

		result_read_cmd.ctsu_result = CTSU_READ_REFERENCE_COUNT_PRIMARY;
		result_read_cmd.p_dest = &compare_buffer[0];
		result_read_cmd.count = num_sensors[itr];
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Read(&self_hdl_idx[itr], &result_read_cmd));

		for(sensor_itr = 0; sensor_itr < num_sensors[itr]; sensor_itr++)
		{
			TEST_ASSERT_EQUAL(compare_buffer[sensor_itr], p_result_start[sensor_itr*2+1]);
		}

		result_read_cmd.ctsu_result = CTSU_READ_SENSOR_COUNT_SECONDARY;
		result_read_cmd.p_dest = &compare_buffer[0];
		result_read_cmd.count = num_sensors[itr];
		TEST_ASSERT_EQUAL(CTSU_ERR_INVALID_CMD, R_CTSU_Read(&self_hdl_idx[itr], &result_read_cmd));


		result_read_cmd.ctsu_result = CTSU_READ_REFERENCE_COUNT_SECONDARY;
		result_read_cmd.p_dest = &compare_buffer[0];
		result_read_cmd.count = num_sensors[itr];
		TEST_ASSERT_EQUAL(CTSU_ERR_INVALID_CMD, R_CTSU_Read(&self_hdl_idx[itr], &result_read_cmd));

		memset(compare_buffer, 0, sizeof(compare_buffer));
		result_read_cmd.ctsu_result = CTSU_READ_SENSOR_OUTPUT;
		result_read_cmd.p_dest = &compare_buffer[0];
		result_read_cmd.count = num_sensors[itr];
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Read(&self_hdl_idx[itr], &result_read_cmd));

		for(sensor_itr = 0; sensor_itr < num_sensors[itr]; sensor_itr++)
		{
			TEST_ASSERT_EQUAL(compare_buffer[sensor_itr], p_result_start[sensor_itr*2]);
		}
	}

	for(itr = 0; itr < max_itr_count; itr++)
	{
	    /* Close multiple handles */
		TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Close(&self_hdl_idx[itr]));
	}
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG1_TC_1_4_Read_Results_
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: TC_1_5_Control_Handle
* Description  : Checking Reading of Control Block information.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(CTSU_TG1, TC_1_5_Control_Get_Tests)
{
	ctsu_cfg_t *	p_ctsu_cfg_valid_extern;
	uint16_t itr;
	uint16_t num_sensors;
	uint8_t control_read_value_8bit;
	uint32_t control_read_value_32bit;
	ctsu_control_arg_t arg;
	ctsu_control_arg_ext_t arg_ext;
	uint64_t chac;
	uint64_t chtrc;
	ctsu_mode_t mode;
	uint16_t* p_output_buffer;
	uint64_t tspin_mask;
	ctsu_instance_ctrl_t ctsu_ctrl;
	memset(&ctsu_ctrl, 0, sizeof(ctsu_ctrl));
#if defined(BSP_MCU_GROUP_S3A7)
	p_ctsu_cfg_valid_extern = &TOUCH_CONFIG0;
	const uint32_t num_sensors_expected = ctsu_get_pin_count(ctsu_get_tspin_mask(p_ctsu_cfg_valid_extern));
	const ctsu_mode_t mode_expected = CTSU_MODE_SELF_CAPACITANCE;
	const uint32_t pclkb_hz_expected = p_ctsu_cfg_valid_extern->pclkb_hz;
	const uint8_t cr0_expected = p_ctsu_cfg_valid_extern->p_ctsu_settings->ctsucr0.byte;
	const uint8_t cr1_expected = p_ctsu_cfg_valid_extern->p_ctsu_settings->ctsucr1.byte;
	const uint8_t sdprs_expected = p_ctsu_cfg_valid_extern->p_ctsu_settings->ctsusdprs.byte;
	const uint8_t sst_expected = p_ctsu_cfg_valid_extern->p_ctsu_settings->ctsusst.byte;
	const uint64_t chac_expected = ctsu_get_tspin_mask(p_ctsu_cfg_valid_extern);
	const uint64_t chtrc_expected = 0;
	const uint8_t dclkc_expected = p_ctsu_cfg_valid_extern->p_ctsu_settings->ctsudclkc.byte;
	const uint16_t* p_output_buffer_expected = p_ctsu_cfg_valid_extern->p_sensor_data;
	const ctsu_sensor_setting_t* p_sensor_setting = p_ctsu_cfg_valid_extern->p_sensor_settings;
#elif defined(YRX113CAPT01_H)
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self01;
	p_ctsu_cfg_valid_extern = &g_ctsu_cfg_yrx113capt01_self01;
	const uint16_t num_sensors_expected = 12;
	const ctsu_mode_t mode_expected = CTSU_MODE_SELF_CAPACITANCE;
	const uint32_t pclkb_hz_expected = g_ctsu_cfg_yrx113capt01_self01.pclkb_hz;
	const uint8_t cr0_expected = g_ctsu_cfg_yrx113capt01_self01.p_ctsu_settings->ctsucr0.byte;
	const uint8_t cr1_expected = g_ctsu_cfg_yrx113capt01_self01.p_ctsu_settings->ctsucr1.byte;
	const uint8_t sdprs_expected = g_ctsu_cfg_yrx113capt01_self01.p_ctsu_settings->ctsusdprs.byte;
	const uint8_t sst_expected = g_ctsu_cfg_yrx113capt01_self01.p_ctsu_settings->ctsusst.byte;
	const uint64_t chac_expected = 0xfff;
	const uint64_t chtrc_expected = 0;
	const uint8_t dclkc_expected = g_ctsu_cfg_yrx113capt01_self01.p_ctsu_settings->ctsudclkc.byte;
	const uint16_t* p_output_buffer_expected = g_ctsu_cfg_yrx113capt01_self01.p_sensor_data;
	const ctsu_sensor_setting_t* p_sensor_setting = g_ctsu_cfg_yrx113capt01_self01.p_sensor_settings;
#endif

	TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Open(&ctsu_ctrl, p_ctsu_cfg_valid_extern));

    tspin_mask = ctsu_get_tspin_mask(&p_ctsu_cfg_valid_extern);

    ctsu_pin_init(tspin_mask);

	/* Test General information */
	arg.p_context = &num_sensors;
	arg.cmd = CTSU_CMD_GET_SENSOR_COUNT;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(num_sensors_expected, num_sensors);

	arg.p_context = &control_read_value_32bit;
	arg.cmd = CTSU_CMD_GET_PCLK;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(pclkb_hz_expected, control_read_value_32bit);

	arg.p_context = &mode;
	arg.cmd = CTSU_CMD_GET_MODE;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(mode_expected, mode);

	arg.p_context = &p_output_buffer;
	arg.cmd = CTSU_CMD_GET_RESULT_OUTPUT_BUFFER;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(p_output_buffer_expected, p_output_buffer);

	/* Test CTSU SFR settings */
	arg.p_context = &control_read_value_8bit;
	arg.cmd = CTSU_CMD_GET_CTSUCR0;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(cr0_expected, control_read_value_8bit);

	arg.cmd = CTSU_CMD_GET_CTSUCR1;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(cr1_expected, control_read_value_8bit);

	arg.cmd = CTSU_CMD_GET_CTSUSDPRS;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(sdprs_expected, control_read_value_8bit);

	arg.cmd = CTSU_CMD_GET_CTSUSST;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(sst_expected, control_read_value_8bit);

	arg.cmd = CTSU_CMD_GET_CTSUDCLKC;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(dclkc_expected, control_read_value_8bit);

	arg.cmd = CTSU_CMD_GET_CTSUCHAC;
	arg.p_context = &chac;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(chac_expected, chac);

	arg.cmd = CTSU_CMD_GET_CTSUCHTRC;
	arg.p_context = &chtrc;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(chtrc_expected, chtrc);

	/* Test sensor settings */
	arg.p_context = &arg_ext;
	arg.cmd = CTSU_CMD_GET_CTSUSSC;
	for(itr = 0; itr < num_sensors; itr++)
	{
		arg_ext.offset = itr;
		arg_ext.value = 0;

		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
		TEST_ASSERT_EQUAL(p_sensor_setting[itr].ctsussc, arg_ext.value);
	}

	arg.cmd = CTSU_CMD_GET_CTSUSO0;
	for(itr = 0; itr < num_sensors; itr++)
	{
		arg_ext.offset = itr;
		arg_ext.value = 0;

		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
		TEST_ASSERT_EQUAL(p_sensor_setting[itr].ctsuso0, arg_ext.value);
	}

	arg.cmd = CTSU_CMD_GET_CTSUSO1;
	for(itr = 0; itr < num_sensors; itr++)
	{
		arg_ext.offset = itr;
		arg_ext.value = 0;

		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
		TEST_ASSERT_EQUAL(p_sensor_setting[itr].ctsuso1, arg_ext.value);
	}

	TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Close(&ctsu_ctrl));
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG1_TC_1_5_Control_Get_Tests_
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: TC_1_5_Control_Handle
* Description  : Check Setting up Control Block information.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(CTSU_TG1, TC_1_6_Control_Set_Tests)
{
	ctsu_cfg_t *	p_ctsu_cfg_extern;
	uint16_t itr;
	uint64_t chac;
	uint64_t chtrc;
	uint16_t num_sensors;
	ctsu_control_arg_t arg;
	uint16_t* p_output_buffer;
	ctsu_callback_t * p_callback;
	ctsu_control_arg_ext_t arg_ext;
	ctsu_const_sfrs_t ctsu_const_sfrs;
	uint16_t ctsussc[CAPTOUCH_SENSOR_COUNT];
	uint16_t ctsuso0[CAPTOUCH_SENSOR_COUNT];
	uint16_t ctsuso1[CAPTOUCH_SENSOR_COUNT];
	const uint8_t test_pattern_8bit = 0xAA;
	const uint16_t test_pattern_16bit = 0xAAAA;
	const uint32_t test_pattern_32bit = 0xAAAAAAAA;
	const uint64_t test_pattern_64bit = 0xAAAAAAAAAAAAAAAA;
	uint64_t tspin_mask;
    ctsu_instance_ctrl_t ctsu_ctrl;
    memset(&ctsu_ctrl, 0, sizeof(ctsu_ctrl));
#if defined(BSP_MCU_GROUP_S3A7)
	p_ctsu_cfg_extern = &TOUCH_CONFIG0;
	num_sensors = ctsu_get_pin_count(ctsu_get_tspin_mask(&p_ctsu_cfg_extern)) & UINT16_MAX;
	const ctsu_sensor_setting_t* p_sensor_setting = p_ctsu_cfg_extern->p_sensor_settings;
	const ctsu_const_sfrs_t* p_ctsu_const_sfrs = p_ctsu_cfg_extern->p_ctsu_settings;
#elif defined(YRX113CAPT01_H)
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self01;
	p_ctsu_cfg_extern = &g_ctsu_cfg_yrx113capt01_self01;
	num_sensors = 12;
	const ctsu_sensor_setting_t* p_sensor_setting = g_ctsu_cfg_yrx113capt01_self01.p_sensor_settings;
	const ctsu_const_sfrs_t* p_ctsu_const_sfrs = g_ctsu_cfg_yrx113capt01_self01.p_ctsu_settings;
#endif

	TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Open(&ctsu_ctrl, p_ctsu_cfg_extern));

    tspin_mask = ctsu_get_tspin_mask(&p_ctsu_cfg_extern);

    ctsu_pin_init(tspin_mask);

	arg.p_context = &ctsu_const_sfrs.ctsucr0.byte;
	arg.cmd = CTSU_CMD_GET_CTSUCR0;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.p_context = &ctsu_const_sfrs.ctsucr1.byte;
	arg.cmd = CTSU_CMD_GET_CTSUCR1;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.p_context = &ctsu_const_sfrs.ctsusdprs.byte;
	arg.cmd = CTSU_CMD_GET_CTSUSDPRS;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.p_context = &ctsu_const_sfrs.ctsusst.byte;
	arg.cmd = CTSU_CMD_GET_CTSUSST;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.p_context = &ctsu_const_sfrs.ctsudclkc.byte;
	arg.cmd = CTSU_CMD_GET_CTSUDCLKC;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.cmd = CTSU_CMD_GET_CTSUCHAC;
	arg.p_context = &chac;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.cmd = CTSU_CMD_GET_CTSUCHTRC;
	arg.p_context = &chtrc;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.p_context = &arg_ext;
	for(itr = 0; itr < num_sensors; itr++)
	{
		arg_ext.offset = itr;
		arg_ext.value = 0;

		arg.cmd = CTSU_CMD_GET_CTSUSSC;
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
		ctsussc[itr] = arg_ext.value;

		arg.cmd = CTSU_CMD_GET_CTSUSO0;
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
		ctsuso0[itr] = arg_ext.value;

		arg.cmd = CTSU_CMD_GET_CTSUSO1;
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
		ctsuso1[itr] = arg_ext.value;
	}

	/* ********* */
	/* Set Tests */
	/* ********* */
	arg.p_context = (void*)&test_pattern_8bit;
	arg.cmd = CTSU_CMD_SET_CTSUCR0;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsucr0.byte);

	arg.cmd = CTSU_CMD_SET_CTSUCR1;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsucr1.byte);

	arg.cmd = CTSU_CMD_SET_CTSUSDPRS;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsusdprs.byte);


	arg.cmd = CTSU_CMD_SET_CTSUSST;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsusst.byte);


	arg.cmd = CTSU_CMD_SET_CTSUDCLKC;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsudclkc.byte);


	arg.p_context = (void*)&test_pattern_64bit;
	arg.cmd = CTSU_CMD_SET_CTSUCHAC;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsuchac0.byte);
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsuchac1.byte);
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsuchac2.byte);
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsuchac3.byte);
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsuchac4.byte);

	arg.cmd = CTSU_CMD_SET_CTSUCHTRC;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsuchtrc0.byte);
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsuchtrc1.byte);
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsuchtrc2.byte);
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsuchtrc3.byte);
	TEST_ASSERT_EQUAL(test_pattern_8bit, p_ctsu_const_sfrs->ctsuchtrc4.byte);

	arg.cmd = CTSU_CMD_SET_CALLBACK;
	arg.p_context = ctsu_event_callback_tg1;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.cmd = CTSU_CMD_GET_CALLBACK;
	arg.p_context = &p_callback;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(ctsu_event_callback_tg1, p_callback);

	arg.cmd = CTSU_CMD_SET_RESULT_OUTPUT_BUFFER;
	arg.p_context = (void*)test_pattern_32bit;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.cmd = CTSU_CMD_GET_RESULT_OUTPUT_BUFFER;
	arg.p_context = &p_output_buffer;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	TEST_ASSERT_EQUAL(test_pattern_32bit, p_output_buffer);


	arg.p_context = &arg_ext;
	for(itr = 0; itr < num_sensors; itr++)
	{
		arg_ext.offset = itr;
		arg_ext.value = test_pattern_16bit;

		arg.cmd = CTSU_CMD_SET_CTSUSSC;
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
		TEST_ASSERT_EQUAL(test_pattern_16bit, p_sensor_setting[itr].ctsussc);

		arg.cmd = CTSU_CMD_SET_CTSUSO0;
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
		TEST_ASSERT_EQUAL(test_pattern_16bit, p_sensor_setting[itr].ctsuso0);

		arg.cmd = CTSU_CMD_SET_CTSUSO1;
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
		TEST_ASSERT_EQUAL(test_pattern_16bit, p_sensor_setting[itr].ctsuso1);
	}

	/* ******************* */
	/* Restore information */
	/* ******************* */
	arg.cmd = CTSU_CMD_SET_CTSUCR0;
	arg.p_context = (void*)&ctsu_const_sfrs.ctsucr0.byte;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.cmd = CTSU_CMD_SET_CTSUCR1;
	arg.p_context = (void*)&ctsu_const_sfrs.ctsucr1.byte;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.cmd = CTSU_CMD_SET_CTSUSDPRS;
	arg.p_context = (void*)&ctsu_const_sfrs.ctsusdprs.byte;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.cmd = CTSU_CMD_SET_CTSUSST;
	arg.p_context = (void*)&ctsu_const_sfrs.ctsusst.byte;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.cmd = CTSU_CMD_SET_CTSUDCLKC;
	arg.p_context = (void*)&ctsu_const_sfrs.ctsudclkc.byte;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.cmd = CTSU_CMD_SET_CTSUCHAC;
	arg.p_context = (void*)&chac;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.cmd = CTSU_CMD_SET_CTSUCHTRC;
	arg.p_context = (void*)&chtrc;
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

	arg.p_context = &arg_ext;
	for(itr = 0; itr < num_sensors; itr++)
	{
		arg_ext.offset = itr;

		arg.cmd = CTSU_CMD_SET_CTSUSSC;
		arg_ext.value = ctsussc[itr];
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

		arg.cmd = CTSU_CMD_SET_CTSUSO0;
		arg_ext.value = ctsuso0[itr];
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));

		arg.cmd = CTSU_CMD_SET_CTSUSO1;
		arg_ext.value = ctsuso1[itr];
		TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&ctsu_ctrl, &arg));
	}

	TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Close(&ctsu_ctrl));
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG1_TC_1_6_Control_Set_Tests_
***********************************************************************************************************************/


/***********************************************************************************************************************
* Function Name: TC_1_7_Calibrate_Handle
* Description  : Checking changing handle parameters on the fly.
* Arguments    : none
* Return Value : none
* TODO: Put in a section on how to calibrate Sensor Offset if drive frequency is known
***********************************************************************************************************************/
TEST(CTSU_TG1, TC_1_7_Calibrate_Handle)
{
#if (CTSU_CFG_CALIBRATION_ENABLE == 1)
	ctsu_cfg_t * self_configs[CTSU_CFG_MAX_CONTROL_BLOCK_COUNT];
	ctsu_instance_ctrl_t self_hdl_idx[CTSU_CFG_MAX_CONTROL_BLOCK_COUNT];
	uint16_t num_sensors[CTSU_CFG_MAX_CONTROL_BLOCK_COUNT];
	uint32_t itr;
	uint16_t sensor_itr;
	uint8_t max_itr_count;
	uint16_t * p_result;
	uint64_t tspin_mask = 0;
	memset(self_hdl_idx, 0, sizeof(self_hdl_idx));
#if defined(BSP_MCU_GROUP_S3A7)
	extern ctsu_cfg_t g_ctsu_cfg_self_inner_wheel;
	extern ctsu_cfg_t g_ctsu_cfg_self_slider;
	extern ctsu_cfg_t g_ctsu_cfg_self_outer_wheel;
	extern ctsu_cfg_t g_ctsu_cfg_self_buttons;
	max_itr_count = 4;

	self_configs[0] = &g_ctsu_cfg_self_buttons;
	num_sensors[0] = 3;
	self_configs[1] = &g_ctsu_cfg_self_slider;
	num_sensors[1] = 5;
	self_configs[2] = &g_ctsu_cfg_self_inner_wheel;
	num_sensors[2] = 4;
	self_configs[3] = &g_ctsu_cfg_self_outer_wheel;
	num_sensors[3] = 8;
#elif defined(YRX113CAPT01_H)
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self02;
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self03;
	extern ctsu_cfg_t g_ctsu_cfg_yrx113capt01_self04;
	max_itr_count = 3;

	self_configs[0] = &g_ctsu_cfg_yrx113capt01_self04;
	num_sensors[0] = 3;
	self_configs[1] = &g_ctsu_cfg_yrx113capt01_self02;
	num_sensors[1] = 5;
	self_configs[2] = &g_ctsu_cfg_yrx113capt01_self03;
	num_sensors[2] = 4;
#endif

	tspin_mask = 0;

	for(itr = 0; itr < max_itr_count; itr++)
	{	/* Open multiple handles */
		self_configs[itr]->p_callback = ctsu_event_callback_tg1;
		TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Open(&self_hdl_idx[itr], self_configs[itr]));
	}





	for(itr = 0; itr < max_itr_count; itr++)
	{	/* Scan with handle */
	    tspin_mask = 0;
	    tspin_mask |= ctsu_get_tspin_mask(self_configs[itr]);
#if CTSU_CFG_ENABLE_CORRECTION
	    tspin_mask |= (UINT64_C(1)<<self_configs[itr]->tscal_pin);
#endif
	    R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MILLISECONDS);
	    ctsu_pin_init(tspin_mask);

		TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Calibrate(&self_hdl_idx[itr]));
		p_result = self_configs[itr]->p_sensor_data;

		for(sensor_itr = 0; sensor_itr < num_sensors[itr]; sensor_itr++)
		{	/* Test if ctsusc and ctsurc counters are almost equal. */
			TEST_ASSERT_UINT_WITHIN(2000, p_result[2*sensor_itr + 1], p_result[2*sensor_itr + 0]);
		}
	}

	for(itr = 0; itr < max_itr_count; itr++)
	{	/* Close multiple handles */
		TEST_ASSERT_EQUAL( CTSU_SUCCESS, R_CTSU_Close(&self_hdl_idx[itr]));
	}
#endif
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG1_TC_1_7_Calibrate_Handle_
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: TC_1_8_Event_Check
* Description  : Check if all events listed by the interface can be generated (in this mode).
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
TEST(CTSU_TG1, TC_1_8_Event_Check)
{
    const uint32_t expected_mask = (CTSU_EVENT_SFRS_CHANGED | CTSU_EVENT_STARTING_SCAN) | CTSU_EVENT_SCAN_COMPLETED;
    TEST_ASSERT_EQUAL(expected_mask, event_mask);
}
/***********************************************************************************************************************
End of function TEST_CTSU_TG1_TC_1_8_Event_Check_
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: ctsu_event_callback_tg1
* Description  : Callback function used for this test group.
* Arguments    : p_arg - Pointer to arguments provided/populated by the driver.
* Return Value : None
***********************************************************************************************************************/
static void ctsu_event_callback_tg1(ctsu_callback_arg_t const * const p_arg)
{
    event_mask |= p_arg->event_mask;
    if (CTSU_EVENT_SCAN_COMPLETED == p_arg->event_mask)
	{
		TEST_ASSERT_EQUAL( 0, p_arg->info);
		scan_count += 1U;
	}
    else if ((p_arg->event_mask & CTSU_EVENT_SFRS_CHANGED) == CTSU_EVENT_SFRS_CHANGED)
	{
		R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MILLISECONDS);
	}
	else
	{
	    ;
	}
}
/***********************************************************************************************************************
End of function ctsu_event_callback_tg1
***********************************************************************************************************************/
