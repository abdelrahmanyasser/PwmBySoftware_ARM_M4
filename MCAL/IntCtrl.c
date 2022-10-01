/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl.c
 *        \brief  Implementation for interrupt control driver for TM4C123GH6PM
 *
 *      \details  
 *
 *
 *********************************************************************************************************************/

 /**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
static void IntCtrl_configureFaultExceptions (void);
static void IntCtrl_configureSystemExceptions (void);
static void IntCtrl_configureInterruptExceptions (void);
static volatile uint32* IntCtrl_getInterruptPriorityRegister(IntCtrl_InterruptType irq);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : volatile uint32* IntCtrl_getInterruptPriorityRegister(IntCtrl_InterruptType irq)        
* \Description     : This function returns required priority register from NVIC register block.                                                                         
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non-Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : volatile uint32*  
*                                                                      
*******************************************************************************/
static volatile uint32* IntCtrl_getInterruptPriorityRegister(IntCtrl_InterruptType irq)
{
    if(irq >= 0 && irq <4)
    {
        return &PRI0_REG;
    }
    else if(irq >= 4 && irq <8)
    {
        return &PRI1_REG;
    }
    else if(irq >= 8 && irq <12)
    {
        return &PRI2_REG;
    }
    else if(irq >= 12 && irq <16)
    {
        return &PRI3_REG;
    }
    else if(irq >= 16 && irq <20)
    {
        return &PRI4_REG;
    }
    else if(irq >= 20 && irq <24)
    {
        return &PRI5_REG;
    }
    else if(irq >= 24 && irq <28)
    {
        return &PRI6_REG;
    }
    else if(irq >= 28 && irq <32)
    {
        return &PRI7_REG;
    }
    else if(irq >= 32 && irq <36)
    {
        return &PRI8_REG;
    }
    else if(irq >= 36 && irq <40)
    {
        return &PRI9_REG;
    }
    else if(irq >= 40 && irq <44)
    {
        return &PRI10_REG;
    }
    else if(irq >= 44 && irq <48)
    {
        return &PRI11_REG;
    }
    else if(irq >= 48 && irq <52)
    {
        return &PRI12_REG;
    }
    else if(irq >= 52 && irq <56)
    {
        return &PRI13_REG;
    }
    else if(irq >= 56 && irq <60)
    {
        return &PRI14_REG;
    }
    else if(irq >= 60 && irq <64)
    {
        return &PRI15_REG;
    }
    else if(irq >= 64 && irq <68)
    {
        return &PRI16_REG;
    }
    else if(irq >= 68 && irq <72)
    {
        return &PRI17_REG;
    }
    else if(irq >= 72 && irq <76)
    {
        return &PRI18_REG;
    }
    else if(irq >= 76 && irq <80)
    {
        return &PRI19_REG;
    }
    else if(irq >= 80 && irq <84)
    {
        return &PRI20_REG;
    }
    else if(irq >= 84 && irq <88)
    {
        return &PRI21_REG;
    }
    else if(irq >= 88 && irq <92)
    {
        return &PRI22_REG;
    }
    else if(irq >= 92 && irq <96)
    {
        return &PRI23_REG;
    }
    else if(irq >= 96 && irq <100)
    {
        return &PRI24_REG;
    }
    else if(irq >= 100 && irq <104)
    {
        return &PRI25_REG;
    }
    else if(irq >= 104 && irq <108)
    {
        return &PRI26_REG;
    }
    else if(irq >= 108 && irq <112)
    {
        return &PRI27_REG;
    }
    else if(irq >= 112 && irq <116)
    {
        return &PRI28_REG;
    }
    else if(irq >= 116 && irq <120)
    {
        return &PRI29_REG;
    }
    else if(irq >= 120 && irq <124)
    {
        return &PRI30_REG;
    }
    else if(irq >= 124 && irq <128)
    {
        return &PRI31_REG;
    }
    else if(irq >= 128 && irq <132)
    {
        return &PRI32_REG;
    }
    else if(irq >= 132 && irq <136)
    {
        return &PRI33_REG;
    }
    else if(irq >= 136 && irq <139)
    {
        return &PRI34_REG;
    }

    /* ERR: */
    return NULL;
}

/******************************************************************************
* \Syntax          : void IntCtrl_configureFaultExceptions (void)        
* \Description     : This function configures Fault handlers priority then
                     Enable or Disable the handlers according to config -
                     structure.                                                                           
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non-Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None  
*                                                                      
*******************************************************************************/
static void IntCtrl_configureFaultExceptions (void)
{
    uint8 i, priority;

    for (i = 0; i < NUM_OF_CONFIG_FAULT_EXCEPTIONS; i++)
    {
        /* get exception priority */
        priority = PRIORITY_MACRO (APINT_BINARY_POINT, IntCtrl_FaultExceptionConfigSet[i].groupPri,\
         IntCtrl_FaultExceptionConfigSet[i].subgroupPri);

        /* Set prioriy and enable */
        switch (IntCtrl_FaultExceptionConfigSet[i].exception)
        {
            case MEM_FAULT_HANDLER:
            SYSPRI1_REG |= (priority << 5);
            if (IntCtrl_FaultExceptionConfigSet[i].state == ENABLE)
            {
                SET_BIT(SYSHNDCTRL_REG, 16);
            }
            else
            {
                CLEAR_BIT(SYSHNDCTRL_REG, 16);
            }
            break;

            case BUS_FAULT_HANDLER:
            SYSPRI1_REG |= (priority << 13);
            if (IntCtrl_FaultExceptionConfigSet[i].state == ENABLE)
            {
                SET_BIT(SYSHNDCTRL_REG, 17);
            }
            else
            {
                CLEAR_BIT(SYSHNDCTRL_REG, 17);
            }
            break;
            
            case USAGE_FAULT_HANDLER:
            SYSPRI1_REG |= (priority << 21);
            if (IntCtrl_FaultExceptionConfigSet[i].state == ENABLE)
            {
                SET_BIT(SYSHNDCTRL_REG, 18);
            }
            else
            {
                CLEAR_BIT(SYSHNDCTRL_REG, 18);
            }
            break;

            default: /* ERR unknown Handler */;
        }
    }
}

/******************************************************************************
* \Syntax          : void IntCtrl_configureSystemExceptions (void)        
* \Description     : Private function that configures Fault handlers priority,
                     these system handlers does not have NVIC enable\disable
                     gates to configure.                                                                        
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non-Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None  
*                                                                      
*******************************************************************************/
static void IntCtrl_configureSystemExceptions (void) 
{
    uint8 i, priority;
    
    for (i = 0; i < NUM_OF_CONFIG_SYSTEM_EXCEPTIONS; i++)
    {
        /* get priority */
        priority = PRIORITY_MACRO (APINT_BINARY_POINT, IntCtrl_SystemExceptionConfigSet[i].groupPri,\
         IntCtrl_SystemExceptionConfigSet[i].subgroupPri);
        
        /* Set priority */
        switch (IntCtrl_SystemExceptionConfigSet[i].exception)
        {
            case SVCALL_HANDLER:
            SYSPRI2_REG |= (priority << 29);
            break;

            case DEBUG_MONITOR_HANDLER:
            SYSPRI3_REG |= (priority << 5);
            break;

            case PENDSV_HANDLER:
            SYSPRI3_REG |= (priority << 21);
            break;

            case SYSTICK_HANDLER:
            SYSPRI3_REG |= (priority << 29);
            break;

            default: /* ERR in System exception configuration */;
        }
    }
}

/******************************************************************************
* \Syntax          : void IntCtrl_configureInterruptExceptions (void) 
* \Description     : Private function that configures Interrupts handlers priority,
                     and enable respictive interrupt Bit in NVIC registers.                                                                    
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non-Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None  
*                                                                      
*******************************************************************************/
static void IntCtrl_configureInterruptExceptions (void) 
{
    uint8 i, priority;
    volatile uint32* regPtr = NULL;

    for (i = 0; i < NUM_OF_CONFIG_INTERRUPT_EXCEPTIONS; i++)
    {
        /* Get priority */
        priority = PRIORITY_MACRO (APINT_BINARY_POINT, IntCtrl_InterruptExceptionConfigSet[i].groupPri,\
         IntCtrl_InterruptExceptionConfigSet[i].subgroupPri);

        regPtr = (volatile uint32*) IntCtrl_getInterruptPriorityRegister(IntCtrl_InterruptExceptionConfigSet[i].irq);

       /* Set priority */
        switch((IntCtrl_InterruptExceptionConfigSet[i].irq) % 4)
        {
            case 0:
            (*regPtr) |= (priority << 5);
            break;
            case 1:
            (*regPtr) |= (priority << 13);
            break;
            case 2:
            (*regPtr) |= (priority << 21);
            break;
            case 3:
            (*regPtr) |= (priority << 29);
            break;
            default: /* ERR */;
        }

        /* Enable Interupt in NVIC */
        switch((IntCtrl_InterruptExceptionConfigSet[i].irq) / 32 )
        {
            case 0:
            EN0_REG |= (1 << ((IntCtrl_InterruptExceptionConfigSet[i].irq) % 32));
            break;
            case 1:
            EN1_REG |= (1 << ((IntCtrl_InterruptExceptionConfigSet[i].irq) % 32));
            break;
            case 2:
            EN2_REG |= (1 << ((IntCtrl_InterruptExceptionConfigSet[i].irq) % 32));
            break;
            case 3:
            EN3_REG |= (1 << ((IntCtrl_InterruptExceptionConfigSet[i].irq) % 32));
            break;
            default: /* ERR */;
        }
    }
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void IntCtrl_init(void)        
* \Description     : This function initializes NVIC\SCB module (Sets priority and
*                    Enable exception) based on configuration provided by user 
*                    in IntCtrl_LCfg.c file.                                                                            
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non-Reentrant                                             
* \Parameters (in) : None
* \Parameters (out): None                                                      
* \Return value:   : None  
*                                                                      
*******************************************************************************/
void IntCtrl_Init (void)
{
    /* Configure grouping\subgrouping system in APINT register in SCB */
    #if (APINT_BINARY_POINT == INTCTRL_BP_XXX)
    /* CONFIG XXX */
    APINT_REG = APINT_VECTKEY | APINT_XXX_PRIGROUP_MASK;

    #elif (APINT_BINARY_POINT == INTCTRL_BP_XXY)
    /* CONFIG XXY */
    APINT_REG = APINT_VECTKEY | APINT_XXY_PRIGROUP_MASK;

    #elif (APINT_BINARY_POINT == INTCTRL_BP_XYY)
    /* CONFIG XYY */
    APINT_REG = APINT_VECTKEY | APINT_XYY_PRIGROUP_MASK;

    #elif (APINT_BINARY_POINT == INTCTRL_BP_YYY)
    /* CONFIG YYY */
    APINT_REG = APINT_VECTKEY | APINT_YYY_PRIGROUP_MASK;

    #endif


    /* Assign Group\Subgroup priority in NVIC_PRIx NVIC and SCB_SYSPRIx Registers */ 
    /* Enable\Disable based on user configurations in NVIC_ENx and SCB_Sys Registers */

    IntCtrl_configureFaultExceptions();

    IntCtrl_configureSystemExceptions();

    IntCtrl_configureInterruptExceptions();

}

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl.c
 *********************************************************************************************************************/
