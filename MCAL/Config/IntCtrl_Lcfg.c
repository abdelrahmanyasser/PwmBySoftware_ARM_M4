/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  Link-time configuration implementation for NVIC driver
 *
 *      \details  
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
IntCtrl_FaultExceptionConfigType IntCtrl_FaultExceptionConfigSet[NUM_OF_CONFIG_FAULT_EXCEPTIONS] = {
    {MEM_FAULT_HANDLER, ENABLE, 0, 0},
    {BUS_FAULT_HANDLER, ENABLE, 0, 0},
    {USAGE_FAULT_HANDLER, ENABLE, 0, 0}
};

IntCtrl_SystemExceptionConfigType IntCtrl_SystemExceptionConfigSet[NUM_OF_CONFIG_SYSTEM_EXCEPTIONS] = {
    {SVCALL_HANDLER, 0, 0},
    {DEBUG_MONITOR_HANDLER, 0, 0},
    {PENDSV_HANDLER, 7, 0},
    {SYSTICK_HANDLER, 0, 0}
};

IntCtrl_InterruptExceptionConfigType IntCtrl_InterruptExceptionConfigSet[NUM_OF_CONFIG_INTERRUPT_EXCEPTIONS] = {
    {TIMER_0A_IRQ, ENABLE, 5, 0} /* IRQ = TIMER0A, State = ENABLE, priority = 5, subpriority = 0 */
};



/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
