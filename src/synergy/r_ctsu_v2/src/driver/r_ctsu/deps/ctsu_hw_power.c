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
* Copyright (C) 2017 Renesas Electronics Corporation. All rights reserved.    
***********************************************************************************************************************/
/***********************************************************************************************************************
* File Name    : ctsu_hw_power.c
* Version      : 1.0 <- Optional as long as history is shown below
* Description  : This module solves all the world's problems
***********************************************************************************************************************/
/**********************************************************************************************************************
* History : DD.MM.YYYY Version  Description
*         : 15.01.2007 1.00     First Release
***********************************************************************************************************************/

/***********************************************************************************************************************
Includes   <System Includes> , "Project Includes"
***********************************************************************************************************************/
#include "bsp_api.h"
#include "r_ctsu_cfg.h"
/***********************************************************************************************************************
Macro definitions
***********************************************************************************************************************/
#if (CTSU_CFG_INTERRUPT_PRIORITY_LEVEL == 0)
#error "Invalid Setting for preprocessor CTSU_CFG_INTERRUPT_PRIORITY_LEVEL"
#endif
/***********************************************************************************************************************
Typedef definitions
***********************************************************************************************************************/

/***********************************************************************************************************************
Exported global variables (to be accessed by other files)
***********************************************************************************************************************/
uint32_t hw_ctsu_poweron (void);
uint32_t hw_ctsu_poweroff (void);
bool lock(void * const p);
void unlock(void * const p);
/***********************************************************************************************************************
Private global variables and functions
***********************************************************************************************************************/

SSP_VECTOR_DEFINE(cb_ctsu_write_isr, CTSU, WRITE);
SSP_VECTOR_DEFINE(cb_ctsu_read_isr, CTSU, READ);
SSP_VECTOR_DEFINE(cb_ctsu_end_isr, CTSU, END);

/* Defined in r_ctsu_synergy.c */
extern void ctsu_write_isr(void);
extern void ctsu_read_isr(void);
extern void ctsu_end_isr(void);

static IRQn_Type write_irq = {(IRQn_Type) 0U};
static IRQn_Type read_irq  = {(IRQn_Type) 0U};
static IRQn_Type end_irq   = {(IRQn_Type) 0U};

void cb_ctsu_write_isr(void)
{
    /* Save context if RTOS is used */
    SF_CONTEXT_SAVE

    /* Call CTSU library service routine */
    ctsu_write_isr();

    /* Clear interrupt */
#if (SSP_VERSION_MAJOR <= 1) && (SSP_VERSION_MINOR < 2)
    R_BSP_IrqStatusClear(CTSU_WRITE_IRQn);
#else
    R_BSP_IrqStatusClear(write_irq);
#endif

    /* Restore context if RTOS is used */
    SF_CONTEXT_RESTORE
}
void cb_ctsu_read_isr(void)
{
    /* Save context if RTOS is used */
    SF_CONTEXT_SAVE

    /* Call CTSU library service routine */
    ctsu_read_isr();

    /* Clear interrupt */
#if (SSP_VERSION_MAJOR <= 1) && (SSP_VERSION_MINOR < 2)
    R_BSP_IrqStatusClear(CTSU_READ_IRQn);
#else
    R_BSP_IrqStatusClear(read_irq);
#endif

    /* Restore context if RTOS is used */
    SF_CONTEXT_RESTORE
}
void cb_ctsu_end_isr(void)
{
    /* Save context if RTOS is used */
    SF_CONTEXT_SAVE

    /* Clear interrupt */
#if (SSP_VERSION_MAJOR <= 1) && (SSP_VERSION_MINOR < 2)
    R_BSP_IrqStatusClear(CTSU_END_IRQn);
#else
    R_BSP_IrqStatusClear(end_irq);
#endif
    /* Call CTSU library service routine */
    ctsu_end_isr();
    /* Restore context if RTOS is used */
    SF_CONTEXT_RESTORE
}


#if defined(BSP_API_H)
/***********************************************************************************************************************
* Function Name: hw_ctsu_poweron
* Description  : Enables CTSU operation by disabling low-power operation, lock the hardware, enabling, and clearing interrupts.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
uint32_t hw_ctsu_poweron (void)
{
    /** Enable writing to MSTP registers. */

    /** Bring module out of stop state. */
#if (SSP_VERSION_MAJOR <= 1) && (SSP_VERSION_MINOR < 2)
    (R_MSTP)->MSTPCRC_b.MSTPC3 = 0U;
#else
    ssp_feature_t ssp_feature = {{(ssp_ip_t) 0U}};
    ssp_feature.channel = 0U;
    ssp_feature.unit = 0U;
    ssp_feature.id = SSP_IP_CTSU;

    R_BSP_ModuleStart(&ssp_feature);
#endif
    /** Disable writing to MSTP registers. */

    /** Lock the hardware. */

    /** Enable interrupts. */
#if (SSP_VERSION_MAJOR <= 1) && (SSP_VERSION_MINOR < 2)

    /* Synergy MCU NVIC setup Synergy sets IPRs through bsp_irq_cfg.h files. Look for:
     * BSP_IRQ_CFG_CTSU_WRITE,
     * BSP_IRQ_CFG_CTSU_READ,
     * BSP_IRQ_CFG_CTSU_END.
     */

    R_BSP_IrqStatusClear(CTSU_WRITE_IRQn);
    R_BSP_IrqStatusClear(CTSU_READ_IRQn);
    R_BSP_IrqStatusClear(CTSU_END_IRQn);

    NVIC_ClearPendingIRQ(CTSU_WRITE_IRQn);
    NVIC_ClearPendingIRQ(CTSU_READ_IRQn);
    NVIC_ClearPendingIRQ(CTSU_END_IRQn);

    NVIC_EnableIRQ(CTSU_WRITE_IRQn);
    NVIC_EnableIRQ(CTSU_READ_IRQn);
    NVIC_EnableIRQ(CTSU_END_IRQn);

#else
    if (R_BSP_HardwareLock (&ssp_feature) != SSP_SUCCESS)
    {
        /* Hardware is busy scanning */
        return SSP_ERR_HW_LOCKED;
    }

    ssp_vector_info_t * p_vector_info;
    fmi_event_info_t event_info = {(IRQn_Type) 0U};

    g_fmi_on_fmi.eventInfoGet(&ssp_feature, SSP_SIGNAL_CTSU_WRITE, &event_info);
    write_irq = event_info.irq;
    g_fmi_on_fmi.eventInfoGet(&ssp_feature, SSP_SIGNAL_CTSU_READ, &event_info);
    read_irq = event_info.irq;
    g_fmi_on_fmi.eventInfoGet(&ssp_feature, SSP_SIGNAL_CTSU_END, &event_info);
    end_irq = event_info.irq;

    R_SSP_VectorInfoGet(write_irq, &p_vector_info);
    NVIC_SetPriority(write_irq, CTSU_CFG_INTERRUPT_PRIORITY_LEVEL-1);
    R_SSP_VectorInfoGet(read_irq, &p_vector_info);
    NVIC_SetPriority(read_irq, CTSU_CFG_INTERRUPT_PRIORITY_LEVEL-1);
    R_SSP_VectorInfoGet(end_irq, &p_vector_info);
    NVIC_SetPriority(end_irq, CTSU_CFG_INTERRUPT_PRIORITY_LEVEL);

    R_BSP_IrqStatusClear(write_irq);
    R_BSP_IrqStatusClear(read_irq);
    R_BSP_IrqStatusClear(end_irq);

    NVIC_ClearPendingIRQ(write_irq);
    NVIC_ClearPendingIRQ(read_irq);
    NVIC_ClearPendingIRQ(end_irq);

    NVIC_EnableIRQ(write_irq);
    NVIC_EnableIRQ(read_irq);
    NVIC_EnableIRQ(end_irq);
#endif

    return SSP_SUCCESS;
}
/***********************************************************************************************************************
End of function hw_ctsu_poweron
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: hw_ctsu_poweroff
* Description  : Disables CTSU operation by enabling low-power operation.
* Arguments    : None
* Return Value : None
***********************************************************************************************************************/
uint32_t hw_ctsu_poweroff (void)
{
    /** a. Enable writing to MSTP registers. */

    /** b. Bring module in to stop state. */
#if (SSP_VERSION_MAJOR <= 1) && (SSP_VERSION_MINOR < 2)
    (R_MSTP)->MSTPCRC_b.MSTPC3 = 1U;
#else
    ssp_feature_t ssp_feature = {{(ssp_ip_t) 0U}};
    ssp_feature.channel = 0U;
    ssp_feature.unit = 0U;
    ssp_feature.id = SSP_IP_CTSU;
    R_BSP_ModuleStop(&ssp_feature);
#endif
    /** c. Disable writing to MSTP registers. */

#if (SSP_VERSION_MAJOR <= 1) && (SSP_VERSION_MINOR < 2)

#if defined(BSP_API_H)
    /* Synergy sets IPRs through bsp_irq_cfg.h files. Look for:
     * BSP_IRQ_CFG_CTSU_WRITE,
     * BSP_IRQ_CFG_CTSU_READ,
     * BSP_IRQ_CFG_CTSU_END.
     */
    NVIC_DisableIRQ(CTSU_WRITE_IRQn);
    NVIC_DisableIRQ(CTSU_READ_IRQn);
    NVIC_DisableIRQ(CTSU_END_IRQn);

    R_BSP_IrqStatusClear(CTSU_WRITE_IRQn);
    R_BSP_IrqStatusClear(CTSU_READ_IRQn);
    R_BSP_IrqStatusClear(CTSU_END_IRQn);

    NVIC_ClearPendingIRQ(CTSU_WRITE_IRQn);
    NVIC_ClearPendingIRQ(CTSU_READ_IRQn);
    NVIC_ClearPendingIRQ(CTSU_END_IRQn);
#endif /* #if defined(BSP_API_H) */

#else
//    ssp_vector_info_t * p_vector_info;
    fmi_event_info_t event_info = {(IRQn_Type) 0U};
    g_fmi_on_fmi.eventInfoGet(&ssp_feature, SSP_SIGNAL_CTSU_WRITE, &event_info);
    write_irq = event_info.irq;
    g_fmi_on_fmi.eventInfoGet(&ssp_feature, SSP_SIGNAL_CTSU_READ, &event_info);
    read_irq = event_info.irq;
    g_fmi_on_fmi.eventInfoGet(&ssp_feature, SSP_SIGNAL_CTSU_END, &event_info);
    end_irq = event_info.irq;

    NVIC_DisableIRQ(write_irq);
    NVIC_DisableIRQ(read_irq);
    NVIC_DisableIRQ(end_irq);

    R_BSP_IrqStatusClear(write_irq);
    R_BSP_IrqStatusClear(read_irq);
    R_BSP_IrqStatusClear(end_irq);

    NVIC_ClearPendingIRQ(write_irq);
    NVIC_ClearPendingIRQ(read_irq);
    NVIC_ClearPendingIRQ(end_irq);
#if 0
    R_SSP_VectorInfoGet(write_irq, &p_vector_info);
    *(p_vector_info->pp_ctrl) = NULL;
    R_SSP_VectorInfoGet(read_irq, &p_vector_info);
    *(p_vector_info->pp_ctrl) = NULL;
    R_SSP_VectorInfoGet(end_irq, &p_vector_info);
    *(p_vector_info->pp_ctrl) = NULL;
#endif

#endif

    /** f. Unlock the CTSU hardware (locked when @ref R_CTSU_Scan was invoked). */
#if defined(BSP_API_H)
#if (SSP_VERSION_MAJOR <= 1) && (SSP_VERSION_MINOR < 2)
    R_BSP_HardwareUnlock(BSP_HW_LOCK_CTSU);
#else
    R_BSP_HardwareUnlock(&ssp_feature);
#endif
#endif // defined(BSP_API_H)

    return SSP_SUCCESS;
}
/***********************************************************************************************************************
End of function hw_ctsu_poweroff
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: lock
* Description  : Lock a resource
* Arguments    : p -
*                   Pointer to a lock variable (of type bsp_lock_t).
* Return Value : true - Lock was acquired
*                false - Lock was not acquired (locked previously may be?)
***********************************************************************************************************************/
bool lock(void * const p)
{
    bsp_lock_t * const plock = p;
    bool lock_acquired = (R_BSP_SoftwareLock(plock) == SSP_SUCCESS) ? true : false;
    return lock_acquired;
}
/***********************************************************************************************************************
End of function lock
***********************************************************************************************************************/

/***********************************************************************************************************************
* Function Name: unlock
* Description  : Unlock a resource
* Arguments    : p -
*                   Pointer to a lock variable (of type bsp_lock_t).
* Return Value : None
***********************************************************************************************************************/
void unlock(void * const p)
{
    R_BSP_SoftwareUnlock((bsp_lock_t * const)p);
}
/***********************************************************************************************************************
End of function unlock
***********************************************************************************************************************/
#endif /* #if defined(BSP_API_H) */
