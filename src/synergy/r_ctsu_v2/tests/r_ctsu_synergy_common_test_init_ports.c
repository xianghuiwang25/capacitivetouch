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
* File Name    : r_ctsu_synergy_common_test_init_ports
* Description  : Unity unit tests for <Module Name>
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*           04.05.2015 1.00     Initial Release
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include <stdio.h>
#include "unity_fixture.h"
#include "r_ctsu_synergy_common_test.h"

#if defined(BSP_MCU_GROUP_S124) || defined(BSP_MCU_GROUP_S3A7) || defined(BSP_MCU_GROUP_S5D9) || defined(BSP_MCU_GROUP_S7G2)

/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/


/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/
extern const ioport_instance_t g_ioport;
extern ioport_port_pin_t const g_ctsu_tspin_info[];
extern size_t const g_tspin_count;

extern ioport_port_pin_t g_ctsu_tscap_info[];

/***********************************************************************************************************************
* Function Name: get_pin_level
* Description  : Gets the logic level of a GPIO pin
* Arguments    : pin - GPIO pin to query
* Return Value : IOPORT_LEVEL_LOW, or IOPORT_LEVEL_HIGH
***********************************************************************************************************************/
ioport_level_t get_pin_level(ioport_port_pin_t pin)
{
    ioport_level_t level;
    g_ioport.p_api->pinRead(pin, &level);
    return level;
}
/***********************************************************************************************************************
End of function get_pin_level
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: get_tspin_mask
* Description  : Get all TS pins enabled by a CTSU configuration.
* Arguments    : p_cfg -
*                    Pointer to CTSU configuration data.
* Return Value : Pins enabled as a bit mask
***********************************************************************************************************************/
uint64_t ctsu_get_tspin_mask(ctsu_cfg_t const*const p_cfg)
{
    uint64_t tspin_mask = 0;
    tspin_mask |= p_cfg->p_ctsu_settings->ctsuchac4.byte;
    tspin_mask <<= 8;
    tspin_mask |= p_cfg->p_ctsu_settings->ctsuchac3.byte;
    tspin_mask <<= 8;
    tspin_mask |= p_cfg->p_ctsu_settings->ctsuchac2.byte;
    tspin_mask <<= 8;
    tspin_mask |= p_cfg->p_ctsu_settings->ctsuchac1.byte;
    tspin_mask <<= 8;
    tspin_mask |= p_cfg->p_ctsu_settings->ctsuchac0.byte;

    return tspin_mask;
}
/***********************************************************************************************************************
End of function get_tspin_mask
***********************************************************************************************************************/

uint64_t ctsu_get_txpin_mask(ctsu_cfg_t const*const p_cfg)
{
    uint64_t tspin_mask = 0;

    tspin_mask |= p_cfg->p_ctsu_settings->ctsuchtrc4.byte;
    tspin_mask <<= 8;
    tspin_mask |= p_cfg->p_ctsu_settings->ctsuchtrc3.byte;
    tspin_mask <<= 8;
    tspin_mask |= p_cfg->p_ctsu_settings->ctsuchtrc2.byte;
    tspin_mask <<= 8;
    tspin_mask |= p_cfg->p_ctsu_settings->ctsuchtrc1.byte;
    tspin_mask <<= 8;
    tspin_mask |= p_cfg->p_ctsu_settings->ctsuchtrc0.byte;

    return tspin_mask;
}

uint64_t ctsu_get_rxpin_mask(ctsu_cfg_t const*const p_cfg)
{
    uint64_t tspin_mask = ctsu_get_tspin_mask(p_cfg);
    uint64_t txpin_mask = ctsu_get_txpin_mask(p_cfg);

    uint64_t rxpin_mask = txpin_mask ^ tspin_mask;

    return rxpin_mask;
}

uint32_t ctsu_get_pin_count(uint64_t tspin_mask)
{
    uint32_t pin_count = 0;

    /* Iterate until TS35 */
    for(uint32_t itr = 0; itr < 36; itr++)
    {
        if((tspin_mask & 0x01U)==1)
        {
            /* TS pin Enabled */
            pin_count += 1U;
        }
        tspin_mask >>= 1;
    }
    return pin_count;
}
/***********************************************************************************************************************
* Function Name: ctsu_pin_init
* Description  : Initialize CTSU TSCAP and TS pins.
* Arguments    : pin_mask -
*                    pin_mask Bit field which describes pins being used as TS pins.
* Return Value : None
***********************************************************************************************************************/
void ctsu_pin_init(uint64_t pin_mask)
{
    ioport_pin_cfg_t pin_config;

    /* Discharge TSCAP */
    pin_config.pin = g_ctsu_tscap_info[0];
    pin_config.pin_cfg = (IOPORT_CFG_PORT_DIRECTION_OUTPUT);

    g_ioport.p_api->pinCfg(pin_config.pin, pin_config.pin_cfg);
    g_ioport.p_api->pinWrite(pin_config.pin, IOPORT_LEVEL_LOW);

    R_BSP_SoftwareDelay(10, BSP_DELAY_UNITS_MILLISECONDS);

    /* Set the pin to GPIO input mode */
    g_ioport.p_api->pinDirectionSet(pin_config.pin, IOPORT_CFG_PORT_DIRECTION_INPUT);

    /* Set up the pin to operate as a CTSU TS pin*/
    pin_config.pin_cfg = (IOPORT_CFG_PERIPHERAL_PIN | IOPORT_PERIPHERAL_CTSU);
    g_ioport.p_api->pinCfg(pin_config.pin, pin_config.pin_cfg);

    /* Iterate through all available pins */
    for(uint32_t itr = 0; itr < g_tspin_count; itr++)
    {
        if((pin_mask & 0x1U)==1U)
        {
            /* TS pin is enabled in the mask */
            pin_config.pin = g_ctsu_tspin_info[itr];

            /* Set the pin direction to input */
            g_ioport.p_api->pinDirectionSet(pin_config.pin, IOPORT_CFG_PORT_DIRECTION_INPUT);

            /* Set up the pin to operate as a GPIO input with pull up-disabled. */
            pin_config.pin_cfg = (IOPORT_CFG_PORT_DIRECTION_INPUT);
            g_ioport.p_api->pinCfg(pin_config.pin, pin_config.pin_cfg);

            /* Set up the pin to operate as a CTSU TS pin*/
            pin_config.pin_cfg = (IOPORT_CFG_PERIPHERAL_PIN | IOPORT_PERIPHERAL_CTSU);
            g_ioport.p_api->pinCfg(pin_config.pin, pin_config.pin_cfg);
        }
        else
        {
            /* TS pin is enabled in the mask */
            pin_config.pin = g_ctsu_tspin_info[itr];

            /* Set up the pin to operate as a GPIO and set to GND. */
            pin_config.pin_cfg = (IOPORT_CFG_PORT_DIRECTION_OUTPUT);

            g_ioport.p_api->pinCfg(pin_config.pin, pin_config.pin_cfg);
        }

        pin_mask >>= 1U;
    }


}
/***********************************************************************************************************************
End of function ctsu_pin_init
***********************************************************************************************************************/
#endif

/* defined(BSP_MCU_GROUP_S124) || defined(BSP_MCU_GROUP_S3A7) || defined(BSP_MCU_GROUP_S5D9) || defined(BSP_MCU_GROUP_S7G2) */
