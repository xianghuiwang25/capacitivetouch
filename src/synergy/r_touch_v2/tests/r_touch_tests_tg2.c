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
* Version : XXX: [Aug 13, 2016:Onkar.Raut:3:49:56 PM] TODO: Insert Release Note.
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

#include "r_touch_rx_common_test.h"

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#if defined(BSP_MCU_GROUP_S3A7)
#define CAPTOUCH_SENSOR_COUNT	(20)
#endif

#if !defined(TOUCH_CFG_PARAM_CHECKING_ENABLE) || (TOUCH_CFG_PARAM_CHECKING_ENABLE==false)
#error TOUCH_CFG_PARAM_CHECKING_ENABLE must be set to true in r_touch_config.h
#endif

#define TOUCH_CONFIG0    (g_touch_cfg_on_g_ctsu_cfg_mutual0)
#define TOUCH_CONFIG1    (g_touch_cfg_on_g_ctsu_cfg_mutual0_rcv_00_04)
#define TOUCH_CONFIG2    (g_touch_cfg_on_g_ctsu_cfg_mutual0_rcv_05_01)

#define TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT   (3)

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/

/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/
static void touch_event_callback_tg2(touch_callback_arg_t const * const arg);
static touch_instance_ctrl_t g_touch_ctrl_tg2;
static uint32_t scan_count = 0;
static uint16_t touch_count_mutual = 0;
static uint16_t results[256];
static uint16_t event_mask = 0;

static const char console_messages[][128] =
{
		"\n\rPlease Touch any of the following Keys: 0, 1, 2, 3, 4, 10, 11, 12, 13, 14\n\r",
		"\n\rPlease Touch any of the following Keys: 5, 6, 7, 8, 9, 15, 16, 17, 18, 19\n\r",
};

extern touch_cfg_t TOUCH_CONFIG0;
extern touch_cfg_t TOUCH_CONFIG1;
extern touch_cfg_t TOUCH_CONFIG2;


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
    printf("Plug the \"Mutual-Capacitance Buttons\" board into the kit.\n\r");
    printf("Press SW3 on MCU board to start test.\n\r");
    while(get_pin_level(SW3)!=SW_ACTIVE);
    while(get_pin_level(SW3)==SW_ACTIVE);
}

/***********************************************************************************************************************
* Function Name: TEST_TEAR_DOWN
* Description  : Tear down for these unit tests. This will be run after each test case.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST_TEAR_DOWN(TOUCH_TG2)
{
	scan_count = 0;
	touch_count_mutual = 0;
}

/***********************************************************************************************************************
* Function Name: TC_2_0_GetVersion
* Description  : Checking GetVersion function.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_0_GetVersion)
{
    ssp_version_t version;

    ssp_err_t err = R_TOUCH_GetVersion(&version);

    TEST_ASSERT_EQUAL( TOUCH_SUCCESS, err);

    TEST_ASSERT_EQUAL_UINT32(version.api_version_major, TOUCH_API_VERSION_MAJOR);
    TEST_ASSERT_EQUAL_UINT32(version.api_version_minor, TOUCH_API_VERSION_MINOR);
    TEST_ASSERT_EQUAL_UINT32(version.code_version_major, 2);
    TEST_ASSERT_EQUAL_UINT32(version.code_version_minor, 0);
}

/***********************************************************************************************************************
* Function Name: TC_1_1_Open_Invalid_Param_test
* Description  : Test invalid parameter rejection.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_1_Open_Invalid_Param_test)
{
	touch_cfg_t	touch_cfg_tg2;
	touch_cfg_t *	p_touch_cfg_tg2;
	touch_cfg_t *	p_touch_cfg_valid_extern;
	memset(&touch_cfg_tg2, 0, sizeof(touch_cfg_t));

	TEST_ASSERT(TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT <= TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS );

	TEST_ASSERT_EQUAL( TOUCH_ERR_INVALID_PARAM, R_TOUCH_Open(NULL, NULL));
	p_touch_cfg_tg2 = NULL;
	TEST_ASSERT_EQUAL( TOUCH_ERR_INVALID_PARAM, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, p_touch_cfg_tg2));
	p_touch_cfg_tg2 = &touch_cfg_tg2;
	TEST_ASSERT_EQUAL( TOUCH_ERR_INVALID_PARAM, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, p_touch_cfg_tg2));
#if defined(BSP_MCU_GROUP_S3A7)
	p_touch_cfg_valid_extern = &TOUCH_CONFIG0;
#endif
	memcpy((void*)&p_touch_cfg_tg2->p_binary_result,
			(void*)&p_touch_cfg_valid_extern->p_binary_result,
			sizeof(uint8_t*));
	TEST_ASSERT_EQUAL( TOUCH_ERR_INVALID_PARAM, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, p_touch_cfg_tg2));

	memcpy((void*)&p_touch_cfg_tg2->p_sensor,
			(void*)&p_touch_cfg_valid_extern->p_sensor,
			sizeof(touch_sensor_parameter_t*));
	TEST_ASSERT_EQUAL( TOUCH_ERR_INVALID_PARAM, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, p_touch_cfg_tg2));

	memcpy((void*)&p_touch_cfg_tg2->p_common,
			(void*)&p_touch_cfg_valid_extern->p_common,
			sizeof(touch_common_parameter_t*));
	TEST_ASSERT_EQUAL( TOUCH_ERR_INVALID_PARAM, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, p_touch_cfg_tg2));

    memcpy((void*)&p_touch_cfg_tg2->p_ctsu->p_cfg,
            (void*)&p_touch_cfg_valid_extern->p_ctsu->p_cfg,
            sizeof(ctsu_cfg_t*));
	TEST_ASSERT_EQUAL( TOUCH_ERR_INVALID_PARAM, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, p_touch_cfg_tg2));

	memcpy((void*)&p_touch_cfg_tg2->buffer.p_start,
			(void*)&p_touch_cfg_valid_extern->buffer.p_start,
			sizeof(uint8_t*));
	TEST_ASSERT_EQUAL( TOUCH_ERR_INSUFFICIENT_MEMORY, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, p_touch_cfg_tg2));

	memcpy((void*)&p_touch_cfg_tg2->buffer.size,
			(void*)&p_touch_cfg_valid_extern->buffer.size,
			sizeof(size_t));
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, p_touch_cfg_tg2));
}

/***********************************************************************************************************************
* Function Name: TC_1_2_Open_Close_Handle
* Description  : Checking Open and closing handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_2_Open_Close_Handle)
{
	touch_cfg_t *	p_touch_cfg_valid_extern;
#if defined(BSP_MCU_GROUP_S3A7)
	p_touch_cfg_valid_extern = &TOUCH_CONFIG0;
#endif
	TEST_ASSERT(TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT <= TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS );

	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, p_touch_cfg_valid_extern));
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Close((touch_ctrl_t*)&g_touch_ctrl_tg2));
}

/***********************************************************************************************************************
* Function Name: TC_2_3_Scan_Multiple_Handles
* Description  : Checking Open, scan and close with handles multiple handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_3_Scan_Multiple_Handles)
{
	touch_cfg_t * touch_config_mutual_mode[TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT];
	uint32_t touch_hdl_idx[TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT];
	uint16_t num_sensors[TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT];
	uint32_t itr;
	uint8_t max_itr_count;
	uint64_t tspin_mask = 0;
#if defined(BSP_MCU_GROUP_S3A7)
	max_itr_count = 2;

	touch_config_mutual_mode[0] = &TOUCH_CONFIG1;
	num_sensors[0] = (ctsu_get_pin_count(ctsu_get_rxpin_mask(touch_config_mutual_mode[0]->p_ctsu->p_cfg))
	                * ctsu_get_pin_count(ctsu_get_txpin_mask(touch_config_mutual_mode[0]->p_ctsu->p_cfg)))
	                & UINT16_MAX;
	touch_config_mutual_mode[1] = &TOUCH_CONFIG2;
	num_sensors[1] = (ctsu_get_pin_count(ctsu_get_rxpin_mask(touch_config_mutual_mode[1]->p_ctsu->p_cfg))
                    * ctsu_get_pin_count(ctsu_get_txpin_mask(touch_config_mutual_mode[1]->p_ctsu->p_cfg)))
                    & UINT16_MAX;;
#endif

	TEST_ASSERT(TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT <= TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS );

	for(itr = 0; itr < max_itr_count; itr++)
	{	/* Open multiple handles */
	    touch_config_mutual_mode[itr]->p_callback = touch_event_callback_tg2;
		TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Open(&touch_hdl_idx[itr], touch_config_mutual_mode[itr]));
		tspin_mask |= ctsu_get_tspin_mask(touch_config_mutual_mode[itr]->p_ctsu->p_cfg);
	}

	ctsu_pin_init(tspin_mask);

	for(itr = 0; itr < max_itr_count; itr++)
	{	/* Scan with handle */
		scan_count = 0;
		TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_StartScan(touch_hdl_idx[itr]));
		while(scan_count == 0);
	}

	for(itr = 0; itr < max_itr_count; itr++)
	{	/* Close multiple handles */
		TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Close(touch_hdl_idx[itr]));
	}
}

/***********************************************************************************************************************
* Function Name: TC_2_4_Update_Touch_Test
* Description  : Checking Open, scan and close with handles multiple handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_4_Update_Touch_Test)
{
	touch_cfg_t *	p_touch_cfg_valid_extern;
	uint64_t tspin_mask = 0;
#if defined(BSP_MCU_GROUP_S3A7)
	p_touch_cfg_valid_extern = &TOUCH_CONFIG0;
#endif
	TEST_ASSERT(TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT <= TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS );

	p_touch_cfg_valid_extern->p_callback = touch_event_callback_tg2;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, p_touch_cfg_valid_extern));

	tspin_mask |= ctsu_get_tspin_mask(p_touch_cfg_valid_extern->p_ctsu->p_cfg);

	ctsu_pin_init(tspin_mask);

	printf(" Please Touch Board ...\n\r");

	do{
		TEST_ASSERT_EQUAL(TOUCH_SUCCESS, R_TOUCH_StartScan((touch_ctrl_t*)&g_touch_ctrl_tg2));
		while(TOUCH_SUCCESS != R_TOUCH_Update((touch_ctrl_t*)&g_touch_ctrl_tg2));
	}while(touch_count_mutual < 1);

	printf("Touch Detected!\n\r");

	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Close((touch_ctrl_t*)&g_touch_ctrl_tg2));
}

/***********************************************************************************************************************
* Function Name: TC_2_5_Touch_Multiple_Open
* Description  : Checking Open, scan, update, and close with handles multiple handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_5_Touch_Multiple_Open)
{
	touch_cfg_t * touch_config_mutual_mode[TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT];
	uint32_t touch_hdl_idx[TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT];
	uint16_t num_sensors[TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT];
	uint32_t itr;
	uint8_t max_itr_count;
	uint64_t tspin_mask = 0;

#if defined(BSP_MCU_GROUP_S3A7)
	max_itr_count = 2;

	touch_config_mutual_mode[0] = &TOUCH_CONFIG1;
	num_sensors[0] = (ctsu_get_pin_count(ctsu_get_rxpin_mask(touch_config_mutual_mode[0]->p_ctsu->p_cfg))
                    * ctsu_get_pin_count(ctsu_get_txpin_mask(touch_config_mutual_mode[0]->p_ctsu->p_cfg)))
                    & UINT16_MAX;
	touch_config_mutual_mode[1] = &TOUCH_CONFIG2;
	num_sensors[1] = (ctsu_get_pin_count(ctsu_get_rxpin_mask(touch_config_mutual_mode[1]->p_ctsu->p_cfg))
                    * ctsu_get_pin_count(ctsu_get_txpin_mask(touch_config_mutual_mode[1]->p_ctsu->p_cfg)))
                    & UINT16_MAX;;
#endif

	TEST_ASSERT(TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT <= TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS );

	for(itr = 0; itr < max_itr_count; itr++)
	{	/* Open multiple handles */
		touch_config_mutual_mode[itr]->p_callback = touch_event_callback_tg2;
		TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Open(&touch_hdl_idx[itr], touch_config_mutual_mode[itr]));
		tspin_mask |= ctsu_get_tspin_mask(touch_config_mutual_mode[itr]->p_ctsu->p_cfg);
	}

	ctsu_pin_init(tspin_mask);

	for(itr = 0; itr < max_itr_count; itr++)
	{
		touch_count_mutual = 0;
		printf("%s", console_messages[itr]);
		do
		{	/* Scan with handle */
			while(TOUCH_SUCCESS != R_TOUCH_StartScan(touch_hdl_idx[itr]));
			while(TOUCH_SUCCESS != R_TOUCH_Update(touch_hdl_idx[itr]));
		}while(touch_count_mutual < 1);
		printf("... Touch Detected!\n\r");
	}

	printf("\n\rTest Complete ... \n\r");

	for(itr = 0; itr < max_itr_count; itr++)
	{	/* Close multiple handles */
		TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Close(touch_hdl_idx[itr]));
	}
}

/***********************************************************************************************************************
* Function Name: TC_2_6_Read_Touch_Test
* Description  : Checking Open, scan and close with handles multiple handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_6_Read_Touch_Test)
{
	touch_cfg_t *	p_touch_cfg_valid_extern;
	uint16_t sensor_count;
	uint32_t itr;
	uint64_t binary_result;
	uint64_t tspin_mask = 0;
#if defined(BSP_MCU_GROUP_S3A7)
	p_touch_cfg_valid_extern = &TOUCH_CONFIG0;
	sensor_count = (ctsu_get_pin_count(ctsu_get_rxpin_mask(p_touch_cfg_valid_extern->p_ctsu->p_cfg))
            * ctsu_get_pin_count(ctsu_get_txpin_mask(p_touch_cfg_valid_extern->p_ctsu->p_cfg)))
            & UINT16_MAX;;
	touch_sensor_t rx130_mutual01_sensors[] = {
			[0] =  {.rx = 0, .tx = 18,},
			[1] =  {.rx = 0, .tx = 19,},
			[2] =  {.rx = 0, .tx = 20,},
			[3] =  {.rx = 0, .tx = 21,},
			[4] =  {.rx = 0, .tx = 26,},
			[5] =  {.rx = 1, .tx = 18,},
			[6] =  {.rx = 1, .tx = 19,},
			[7] =  {.rx = 1, .tx = 20,},
			[8] =  {.rx = 1, .tx = 21,},
			[9] =  {.rx = 1, .tx = 26,},
			[10] = {.rx = 4, .tx = 18,},
			[11] = {.rx = 4, .tx = 19,},
			[12] = {.rx = 4, .tx = 20,},
			[13] = {.rx = 4, .tx = 21,},
			[14] = {.rx = 4, .tx = 26,},
			[15] = {.rx = 5, .tx = 18,},
			[16] = {.rx = 5, .tx = 19,},
			[17] = {.rx = 5, .tx = 20,},
			[18] = {.rx = 5, .tx = 21,},
			[19] = {.rx = 5, .tx = 26,},
	};
	touch_read_t read_args =
	{
			.sensor = &rx130_mutual01_sensors[0],
			.sensor_count = sensor_count,
			.p_dest = &results[0],
			.size = sizeof(results),
	};
	sensor_info_t *const p_sensor_info = (sensor_info_t *)p_touch_cfg_valid_extern->buffer.p_start;
#endif
	TEST_ASSERT(TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT <= TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS );

	p_touch_cfg_valid_extern->p_callback = touch_event_callback_tg2;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, p_touch_cfg_valid_extern));
	tspin_mask |= ctsu_get_tspin_mask(p_touch_cfg_valid_extern->p_ctsu->p_cfg);

	ctsu_pin_init(tspin_mask);

	printf("... Please Touch a sensor ...\n\r");

	do{
		TEST_ASSERT_EQUAL(TOUCH_SUCCESS, R_TOUCH_StartScan((touch_ctrl_t*)&g_touch_ctrl_tg2));
		while(TOUCH_SUCCESS != R_TOUCH_Update((touch_ctrl_t*)&g_touch_ctrl_tg2));
	}while(touch_count_mutual < 1);

	printf("... \n\rTouch Detected ... Reading parameters ...\n\r");

	read_args.read_cmd = TOUCH_DATA_FILTERED_COUNT;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].input, results[itr]);
	}

	read_args.read_cmd = TOUCH_DATA_BASELINE_COUNT;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].baseline, results[itr]);
	}

	read_args.read_cmd = TOUCH_DATA_DELTA_COUNT;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].delta, results[itr]);
	}

	read_args.read_cmd = TOUCH_DATA_DELAY_TO_TOUCH_COUNTER;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].dt_count, ((uint8_t*)results)[itr]);
	}

	read_args.read_cmd = TOUCH_DATA_DELAY_TO_RELEASE_COUNTER;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].dr_count, ((uint8_t*)results)[itr]);
	}

	read_args.read_cmd = TOUCH_DATA_AVERAGE_INPUT;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].avg_input, results[itr]);
	}

	read_args.read_cmd = TOUCH_DATA_MINIMUM_INPUT;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].min_input, results[itr]);
	}

	read_args.read_cmd = TOUCH_DATA_MAXIMUM_INPUT;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].max_input, results[itr]);
	}

	read_args.read_cmd = TOUCH_DATA_DRIFT_COUNTER;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].drift_counter, results[itr]);
	}

#if defined(TOUCH_CFG_VARIABLE_DRIFT_RATES)&&(TOUCH_CFG_VARIABLE_DRIFT_RATES==1)
	read_args.read_cmd = TOUCH_READ_DRIFT_INTERVAL;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].drift_interval, results[itr]);
	}
#endif

	read_args.read_cmd = TOUCH_DATA_AVG_SEN_COUNTER_PRI;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].avg_sen_cnt_pri, results[itr]);
	}

	read_args.read_cmd = TOUCH_DATA_AVG_REF_COUNTER_PRI;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].avg_ref_cnt_sec, results[itr]);
	}

	read_args.read_cmd = TOUCH_DATA_RECALIBRATION_COUNTER;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
	for(itr = 0; itr < sensor_count; itr++)
	{
		TEST_ASSERT_EQUAL(p_sensor_info[itr].recalib_counter, results[itr]);
	}
	binary_result = 0;
	read_args.p_dest = &binary_result;
	read_args.read_cmd = TOUCH_DATA_BINARY;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));

	printf("Binary Result: %llxh\n\r", binary_result);

	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Close((touch_ctrl_t*)&g_touch_ctrl_tg2));
}

/***********************************************************************************************************************
* Function Name: TC_2_7_Calibrate_Test
* Description  : Checking Open, scan and close with handles multiple handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_7_Calibrate_Test)
{
	touch_cfg_t *	p_touch_cfg_valid_extern;
	uint64_t tspin_mask = 0;
#if defined(BSP_MCU_GROUP_S3A7)
	p_touch_cfg_valid_extern = &TOUCH_CONFIG0;
#endif
	TEST_ASSERT(TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT <= TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS );

	p_touch_cfg_valid_extern->p_callback = touch_event_callback_tg2;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, p_touch_cfg_valid_extern));
	tspin_mask |= ctsu_get_tspin_mask(p_touch_cfg_valid_extern->p_ctsu->p_cfg);

	ctsu_pin_init(tspin_mask);

	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Calibrate((touch_ctrl_t*)&g_touch_ctrl_tg2));

	printf("\n\r Calibration Complete! Please touch a sensor ... \n\r");

	do{
		TEST_ASSERT_EQUAL(TOUCH_SUCCESS, R_TOUCH_StartScan((touch_ctrl_t*)&g_touch_ctrl_tg2));
		while(TOUCH_SUCCESS != R_TOUCH_Update((touch_ctrl_t*)&g_touch_ctrl_tg2));
	}while(touch_count_mutual < 1);

	printf("Touch Detected!");

	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Close((touch_ctrl_t*)&g_touch_ctrl_tg2));
}

/***********************************************************************************************************************
* Function Name: TC_2_8_Excluded_Channel_Test
* Description  : Checking Open, scan and close with handles multiple handles.
* Arguments    : none
* Return Value : none
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_8_Excluded_Channel_Test)
{
	touch_cfg_t *	p_touch_cfg_valid_extern;
	uint64_t tspin_mask = 0;
#if defined(BSP_MCU_GROUP_S3A7)
	const touch_sensor_t excluded_pairs[] = {
		[0] = {.rx = 0, .tx = 18},
		[1] = {.rx = 4, .tx = 21},
		[2] = {.rx = 5, .tx = 26},
	};
	p_touch_cfg_valid_extern = &TOUCH_CONFIG0;
#endif
	TEST_ASSERT(TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT <= TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS );

	touch_cfg_t touch_local;
	uint64_t binary_result;
	touch_read_t read_args =
	{
			.p_dest = &results[0],
			.size = sizeof(binary_result),
	};
	touch_sensor_t const *const p_excluded = excluded_pairs;
	memcpy(&touch_local, p_touch_cfg_valid_extern, sizeof(touch_cfg_t));
	memcpy((void*)&touch_local.p_ignored, (void*)&p_excluded, sizeof(touch_sensor_t *));
	memset((void*)&touch_local.num_ignored, sizeof(excluded_pairs)/sizeof(touch_sensor_t), sizeof(touch_local.num_ignored));
	printf("\n\r Key 0, 12, and 19 are excluded. Please touch any other sensors ... \n\r");

	touch_local.p_callback = touch_event_callback_tg2;
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, &touch_local));
	tspin_mask |= ctsu_get_tspin_mask(p_touch_cfg_valid_extern->p_ctsu->p_cfg);

	ctsu_pin_init(tspin_mask);

	do{
		TEST_ASSERT_EQUAL(TOUCH_SUCCESS, R_TOUCH_StartScan((touch_ctrl_t*)&g_touch_ctrl_tg2));
		while(TOUCH_SUCCESS != R_TOUCH_Update((touch_ctrl_t*)&g_touch_ctrl_tg2));
	}while(touch_count_mutual < 1);

	printf("Touch Detected!\n\r");
#if defined(BSP_MCU_GROUP_S3A7)
	binary_result = 0;
	binary_result |= touch_local.p_binary_result[2];
	binary_result <<= 8;
	binary_result |= touch_local.p_binary_result[1];
	binary_result <<= 8;
	binary_result |= touch_local.p_binary_result[0];
#endif

	printf("Binary Result: %llxh\n\r", binary_result);
	TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Close((touch_ctrl_t*)&g_touch_ctrl_tg2));
}

TEST(TOUCH_TG2, TC_2_9_Continuous_Touch_Release_Test)
{
    touch_cfg_t *   p_touch_cfg_valid_extern;
    uint64_t tspin_mask = 0;
#if defined(BSP_MCU_GROUP_S3A7)
    p_touch_cfg_valid_extern = &TOUCH_CONFIG0;
    uint32_t continuous_on_counter = 0;
    uint32_t continuous_on_limit = 0;
    touch_read_t read_args =
    {
     .read_cmd = TOUCH_DATA_COMMON_CONTINUOUS_ON_COUNTER,
     .sensor = NULL,
     .sensor_count = 0,
     .p_dest = &continuous_on_counter,
     .size = sizeof(continuous_on_counter),
    };
#endif
    TEST_ASSERT(TOUCH_CFG_MAX_CONTROL_BLOCK_COUNT <= TOUCH_CFG_MAX_OPEN_TOUCH_CONFIGS );

    touch_cfg_t touch_local;
    memcpy(&touch_local, p_touch_cfg_valid_extern, sizeof(touch_cfg_t));
    touch_local.p_callback = touch_event_callback_tg2;

    TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Open((touch_ctrl_t*)&g_touch_ctrl_tg2, &touch_local));
    tspin_mask |= ctsu_get_tspin_mask(p_touch_cfg_valid_extern->p_ctsu->p_cfg);

    ctsu_pin_init(tspin_mask);

    printf("Please touch any sensor\n\r");

    do{

        TEST_ASSERT_EQUAL(TOUCH_SUCCESS, R_TOUCH_StartScan((touch_ctrl_t*)&g_touch_ctrl_tg2));
        while(TOUCH_SUCCESS != R_TOUCH_Update((touch_ctrl_t*)&g_touch_ctrl_tg2));
    }while(touch_count_mutual < 1);

    printf("A sensor is touched.\n\r");
    printf("Continue to hold down sensor. Sensor will release automatically due to limiter.\n\r");

    do{
        TEST_ASSERT_EQUAL(TOUCH_SUCCESS, R_TOUCH_StartScan((touch_ctrl_t*)&g_touch_ctrl_tg2));
        do{;}while (R_TOUCH_Update ((touch_ctrl_t*)&g_touch_ctrl_tg2) != TOUCH_SUCCESS);
        read_args.read_cmd = TOUCH_DATA_COMMON_CONTINUOUS_ON_COUNTER;
        read_args.p_dest = &continuous_on_counter;
        TEST_ASSERT_EQUAL(TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
        read_args.read_cmd = TOUCH_DATA_COMMON_CONTINUOUS_ON_INTERVAL;
        read_args.p_dest = &continuous_on_limit;
        TEST_ASSERT_EQUAL(TOUCH_SUCCESS, R_TOUCH_Read((touch_ctrl_t*)&g_touch_ctrl_tg2, &read_args));
        uint32_t percent = (continuous_on_counter<<10)/(continuous_on_limit*10);
        static uint32_t prev_percent = 0;
        if((percent - prev_percent) == 9)
        {
            printf("continuous on count at: %lu %%\n", percent);
            prev_percent = percent;
        }
    }while(touch_count_mutual > 0);

    TEST_ASSERT_EQUAL( TOUCH_SUCCESS, R_TOUCH_Close((touch_ctrl_t*)&g_touch_ctrl_tg2));
}

/***********************************************************************************************************************
* Function Name: TC_2_10_Event_Test
* Description  : Test if all events supported have been generated during tests conducted so far..
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
TEST(TOUCH_TG2, TC_2_10_Event_Test)
{
    const uint32_t expected = (TOUCH_EVENT_REQUEST_DELAY |
                            TOUCH_EVENT_SCAN_STARTING |
                            TOUCH_EVENT_SCAN_STARTED |
                            TOUCH_EVENT_SCAN_COMPLETE |
                            TOUCH_EVENT_PARAMETERS_UPDATED);
    TEST_ASSERT_EQUAL(expected, event_mask);

}
/***********************************************************************************************************************
End of function TEST_TOUCH_TG2_TC_2_10_Event_Test_
***********************************************************************************************************************/

static void touch_event_callback_tg2(touch_callback_arg_t const * const p_arg)
{
    event_mask |= p_arg->event;
	if(TOUCH_EVENT_SCAN_COMPLETE==p_arg->event)
	{
        if (0 == p_arg->info)
        {
            scan_count += 1;
        }
	}
	else if(TOUCH_EVENT_REQUEST_DELAY == p_arg->event)
	{
		R_BSP_SoftwareDelay(500, BSP_DELAY_UNITS_MICROSECONDS);
	}
	else if(TOUCH_EVENT_PARAMETERS_UPDATED==p_arg->event)
	{
		if(touch_count_mutual != p_arg->info)
		{
			if(p_arg->info > touch_count_mutual)
			{
				printf("Touched!\n\r");
			}
			else if(p_arg->info < touch_count_mutual)
			{
				printf("Released!\n\r");
			}
		}

		touch_count_mutual = p_arg->info;

		if(touch_count_mutual > 0)
		{
//			LED1 = LED_ON;
		}
		else
		{
//			LED1 = LED_OFF;
		}

	}
}
