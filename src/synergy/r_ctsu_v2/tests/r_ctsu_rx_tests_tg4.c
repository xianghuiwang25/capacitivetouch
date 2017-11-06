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
 * File Name : r_ctsu_synergy_tests_tg4.c
 * Version : 1.0 : [Aug 22, 2016:Onkar.Raut:9:17:02 AM] Tested. More tests can be added as necessary.
 * Description : This file implements hybrid mode and remaining test specifications.
 ***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @file
 ***********************************************************************************************************************/
/*******************************************************************************************************************//**
 * @ingroup TESTING
 * @defgroup TEST_GROUP4
 * @brief This is a brief description 
 * @{
 * Sample Usage:
 *
 * TEST_GROUP_RUNNER(TOUCH_TG4)
 * {
 *     RUN_TEST_CASE(TOUCH_TG4, TC_4_1_CTSUICOMP_Error);
 *     RUN_TEST_CASE(TOUCH_TG4, TC_4_2_CTSUSOVF_Error);
 *     RUN_TEST_CASE(TOUCH_TG4, TC_4_3_CTSUROVF_Error);
 *     RUN_TEST_CASE(TOUCH_TG4, TC_4_4_Read_Handle);
 *     RUN_TEST_CASE(TOUCH_TG4, TC_4_5_Scan_Handle);
 *     RUN_TEST_CASE(TOUCH_TG4, TC_4_6_Control_Handle);
 *     RUN_TEST_CASE(TOUCH_TG4, TC_4_7_Close_Handle);
 * }
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
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include "unity_fixture.h"

#include "r_ctsu_synergy_common_test.h"

/***********************************************************************************************************************
Macro definitions
 ***********************************************************************************************************************/
#define CTSU_CFG_MAX_CONTROL_BLOCK_COUNT    (3)

#define TOUCH_CONFIG0    (g_ctsu_cfg_mutual_all_sensors)
#define TOUCH_CONFIG1    (g_ctsu_cfg_mutual_rcv_05_01)
#define TOUCH_CONFIG2    (g_ctsu_cfg_mutual_rcv_00_04)

/***********************************************************************************************************************
Typedef definitions
 ***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
 ***********************************************************************************************************************/

/***********************************************************************************************************************
Private global variables and functions
 ***********************************************************************************************************************/
static void ctsu_event_callback_tg4(ctsu_callback_arg_t const * const p_arg);
static uint32_t hdl_idx = UINT32_MAX;
static uint32_t scan_count = 0;

extern ctsu_cfg_t TOUCH_CONFIG0;
extern ctsu_cfg_t TOUCH_CONFIG1;
extern ctsu_cfg_t TOUCH_CONFIG2;

/* Define test groups. */
TEST_GROUP(TOUCH_TG4);

/***********************************************************************************************************************
 * Function Name: TEST_SETUP
 * Description  : Setup for these unit tests. This will be run before every test case.
 * Arguments    : none
 * Return Value : none
 ***********************************************************************************************************************/
TEST_SETUP(TOUCH_TG4)
{
    printf("Plug the \"Mutual Capacitance Button\" board into the kit.\n\r");
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
TEST_TEAR_DOWN(TOUCH_TG4)
{
	scan_count = 0;
}

TEST(TOUCH_TG4, TC_4_1_CTSUICOMP_Error)
{
    uint16_t ctsussc;
     uint16_t ctsuso0;
     uint16_t ctsuso1;
     ctsu_instance_ctrl_t id;
     uint64_t tspin_mask;
     ctsu_cfg_t cfg_copy;
     ctsu_cfg_t * p_cfg;
     p_cfg = &TOUCH_CONFIG0;
     memset(&id, 0, sizeof(id));
     memcpy(&cfg_copy, p_cfg, sizeof(ctsu_cfg_t));
     uint32_t err_info;
     ctsu_control_arg_t control_arg =
     {
        .cmd = CTSU_CMD_GET_ERROR_INFORMATION,
        .p_context = &err_info,
     };

     p_cfg = &cfg_copy;

     ctsussc = p_cfg->p_sensor_settings[0].ctsussc;
     ctsuso0 = p_cfg->p_sensor_settings[0].ctsuso0;
     ctsuso1 = p_cfg->p_sensor_settings[0].ctsuso1;

     p_cfg->p_callback = ctsu_event_callback_tg4;

     tspin_mask = ctsu_get_tspin_mask(p_cfg);
     ctsu_pin_init(0);                          // Passing 0 creates the abnormal TSCAP voltage.

     TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Open(&id, p_cfg));

     TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Scan(&id));

     do{;}while (0 == scan_count);

     TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&id, &control_arg));
     TEST_ASSERT_EQUAL(CTSU_ERR_CTSU_ICOMP, (err_info & CTSU_ERR_CTSU_ICOMP));

     p_cfg->p_sensor_settings[0].ctsussc = ctsussc;
     p_cfg->p_sensor_settings[0].ctsuso0 = ctsuso0;
     p_cfg->p_sensor_settings[0].ctsuso1 = ctsuso1;

}

TEST(TOUCH_TG4, TC_4_2_CTSUSOVF_Error)
{
    uint16_t ctsussc;
    uint16_t ctsuso0;
    uint16_t ctsuso1;
    ctsu_instance_ctrl_t id;
    uint64_t tspin_mask;
    ctsu_cfg_t cfg_copy;
    ctsu_cfg_t * p_cfg;
    p_cfg = &TOUCH_CONFIG0;
    memset(&id, 0, sizeof(id));
    memcpy(&cfg_copy, p_cfg, sizeof(ctsu_cfg_t));
    uint32_t err_info;
    ctsu_control_arg_t control_arg =
    {
       .cmd = CTSU_CMD_GET_ERROR_INFORMATION,
       .p_context = &err_info,
    };

    p_cfg = &cfg_copy;

    ctsussc = p_cfg->p_sensor_settings[0].ctsussc;
    ctsuso0 = p_cfg->p_sensor_settings[0].ctsuso0;
    ctsuso1 = p_cfg->p_sensor_settings[0].ctsuso1;

    p_cfg->p_sensor_settings[0].ctsuso0 &= ~0x3FFU;
    p_cfg->p_sensor_settings[0].ctsuso0 = ((p_cfg->p_sensor_settings[0].ctsuso0>>10)+1)<<10;    // Causes the Sensor Counter to overflow.

    p_cfg->p_callback = ctsu_event_callback_tg4;

    tspin_mask = ctsu_get_tspin_mask(p_cfg);
    ctsu_pin_init(tspin_mask);

    TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Open(&id, p_cfg));

    TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Scan(&id));

    do{;}while (0 == scan_count);

    TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&id, &control_arg));
    TEST_ASSERT_EQUAL(CTSU_ERR_CTSU_SC_OVF, (err_info & CTSU_ERR_CTSU_SC_OVF));

    p_cfg->p_sensor_settings[0].ctsussc = ctsussc;
    p_cfg->p_sensor_settings[0].ctsuso0 = ctsuso0;
    p_cfg->p_sensor_settings[0].ctsuso1 = ctsuso1;
}

TEST(TOUCH_TG4, TC_4_3_CTSUROVF_Error)
{
    uint16_t ctsussc;
    uint16_t ctsuso0;
    uint16_t ctsuso1;
    ctsu_instance_ctrl_t id;
    uint64_t tspin_mask;
    ctsu_cfg_t cfg_copy;
    ctsu_cfg_t * p_cfg;
    memset(&id, 0, sizeof(id));
    p_cfg = &TOUCH_CONFIG0;
    memcpy(&cfg_copy, p_cfg, sizeof(ctsu_cfg_t));
    uint32_t err_info;
    ctsu_control_arg_t control_arg =
    {
       .cmd = CTSU_CMD_GET_ERROR_INFORMATION,
       .p_context = &err_info,
    };

    p_cfg = &cfg_copy;

    ctsussc = p_cfg->p_sensor_settings[0].ctsussc;
    ctsuso0 = p_cfg->p_sensor_settings[0].ctsuso0;
    ctsuso1 = p_cfg->p_sensor_settings[0].ctsuso1;

    p_cfg->p_sensor_settings[0].ctsuso1 |= 0xFFFU;          //Causes the reference counter to overflow.

    p_cfg->p_callback = ctsu_event_callback_tg4;

    tspin_mask = ctsu_get_tspin_mask(p_cfg);
    ctsu_pin_init(tspin_mask);

    TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Open(&id, p_cfg));

    TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Scan(&id));

    do{;}while (0 == scan_count);

    TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Control(&id, &control_arg));
    TEST_ASSERT_EQUAL(CTSU_ERR_CTSU_RC_OVF, (err_info & CTSU_ERR_CTSU_RC_OVF));

    p_cfg->p_sensor_settings[0].ctsussc = ctsussc;
    p_cfg->p_sensor_settings[0].ctsuso0 = ctsuso0;
    p_cfg->p_sensor_settings[0].ctsuso1 = ctsuso1;
}

TEST(TOUCH_TG4, TC_4_4_Read_Handle)
{
    ctsu_instance_ctrl_t id;
	ctsu_cfg_t * p_cfg;
	ctsu_read_t read_arg;
	uint16_t ctsu_counters[4];
	uint16_t sensor_offset = 0;

	memset(&id, 0, sizeof(id));
	p_cfg = &TOUCH_CONFIG0;
	p_cfg->p_callback = ctsu_event_callback_tg4;

	TEST_ASSERT_EQUAL(CTSU_ERR_INVALID_PARAM, R_CTSU_Read(&id, &read_arg));
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Open(&id, p_cfg));

	memset(&read_arg, 0, sizeof(read_arg));
	TEST_ASSERT_EQUAL(CTSU_ERR_INVALID_PARAM, R_CTSU_Read(&id, &read_arg));

	read_arg.sensor_offset = &sensor_offset;
	TEST_ASSERT_EQUAL(CTSU_ERR_INVALID_PARAM, R_CTSU_Read(&id, &read_arg));

	read_arg.size = sizeof(ctsu_counters);
	TEST_ASSERT_EQUAL(CTSU_ERR_INVALID_PARAM, R_CTSU_Read(&id, &read_arg));

	read_arg.ctsu_result = CTSU_READ_BUFFER_ALL;
	TEST_ASSERT_EQUAL(CTSU_ERR_INVALID_PARAM, R_CTSU_Read(&id, &read_arg));

    /* Add more invalid argument tests here. */
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Close(&id));
}

TEST(TOUCH_TG4, TC_4_5_Scan_Handle)
{
    ctsu_instance_ctrl_t id;
	ctsu_cfg_t * p_cfg;
	uint64_t tspin_mask;

	memset(&id, 0, sizeof(id));
	p_cfg = &TOUCH_CONFIG0;
	p_cfg->p_callback = ctsu_event_callback_tg4;

	tspin_mask = ctsu_get_tspin_mask(p_cfg);
	ctsu_pin_init(tspin_mask);

	TEST_ASSERT_EQUAL(CTSU_ERR_INVALID_PARAM, R_CTSU_Scan(&id));
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Open(&id, p_cfg));
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Scan(&id));
	TEST_ASSERT_EQUAL(CTSU_ERR_CTSU_OPERATIONAL, R_CTSU_Scan(&id));
    do{;}while (0 == scan_count);

	/* Add more invalid argument tests here. */

	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Close(&id));
}

TEST(TOUCH_TG4, TC_4_6_Control_Handle)
{
    ctsu_instance_ctrl_t id;
	ctsu_cfg_t * p_cfg;
	ctsu_control_arg_t control_arg;
	ctsu_control_arg_ext_t ext;
    uint64_t tspin_mask;

    memset(&id, 0, sizeof(id));
    p_cfg = &TOUCH_CONFIG0;
    p_cfg->p_callback = ctsu_event_callback_tg4;

    tspin_mask = ctsu_get_tspin_mask(p_cfg);
    ctsu_pin_init(tspin_mask);

	TEST_ASSERT_EQUAL(CTSU_ERR_INVALID_PARAM, R_CTSU_Control(&id, &control_arg));
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Open(&id, p_cfg));

	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Close(&id));
}

TEST(TOUCH_TG4, TC_4_7_Close_Handle)
{
    ctsu_instance_ctrl_t id;
	ctsu_cfg_t * p_cfg;
	ctsu_control_arg_t control_arg;
	ctsu_control_arg_ext_t ext;
    uint64_t tspin_mask;

    memset(&id, 0, sizeof(id));
    p_cfg = &TOUCH_CONFIG0;
    p_cfg->p_callback = ctsu_event_callback_tg4;

    tspin_mask = ctsu_get_tspin_mask(p_cfg);
    ctsu_pin_init(tspin_mask);

	TEST_ASSERT_EQUAL(CTSU_ERR_INVALID_PARAM, R_CTSU_Close(&id));
	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Open(&id, p_cfg));

	TEST_ASSERT_EQUAL(CTSU_SUCCESS, R_CTSU_Close(&id));
}

void ctsu_event_callback_tg4(ctsu_callback_arg_t const * const p_arg)
{

	//	TEST_ASSERT_EQUAL(hdl_idx, p_arg->handle_num);

    if (CTSU_EVENT_SCAN_COMPLETED == p_arg->event_mask)
	{
        if( strcmp(Unity.CurrentTestName, "TEST(TOUCH_TG4, TC_4_1_CTSUICOMP_Error)") ) {;}
        else if( strcmp(Unity.CurrentTestName, "TEST(TOUCH_TG4, TC_4_2_CTSUSOVF_Error)") ) {;}
        else if( strcmp(Unity.CurrentTestName, "TEST(TOUCH_TG4, TC_4_3_CTSUROVF_Error)") ) {;}
        else TEST_ASSERT_EQUAL( 0, p_arg->info);

		scan_count += 1U;
	}
    else if ((p_arg->event_mask & CTSU_EVENT_SFRS_CHANGED) == CTSU_EVENT_SFRS_CHANGED)
    {
        R_BSP_SoftwareDelay (1, BSP_DELAY_UNITS_MILLISECONDS);
    }
    else
    {
        ;
    }

}
