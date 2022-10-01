/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  NVIC driver
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    /* Exception vectors from 0 to 15 */
    RESET_HANDLER          = 1,          
    NMI_HANDLER            = 2,                
    HARD_FAULT_HANDLER     = 3,         
    MEM_FAULT_HANDLER      = 4,     
    BUS_FAULT_HANDLER      = 5,          
    USAGE_FAULT_HANDLER    = 6,
    SVCALL_HANDLER         = 11,
    DEBUG_MONITOR_HANDLER  = 12,
    PENDSV_HANDLER         = 14,
    SYSTICK_HANDLER        = 15

}IntCtrl_ExceptionType;


typedef enum
{
    /* Vectors from 16 to 154 */
    /* Interrupt numbers from 0 ... 138 */
    GPIO_PORT_A_IRQ,
    GPIO_PORT_B_IRQ,
    GPIO_PORT_C_IRQ,
    GPIO_PORT_D_IRQ,
    GPIO_PORT_E_IRQ,
    UART0_IRQ,
    UART1_IRQ,
    SSI0_IRQ,
    I2C0_IRQ,
    PWM0_FAULT_IRQ,
    PWM0_GENERATOR_0_IRQ,
    PWM0_GENERATOR_1_IRQ,
    PWM0_GENERATOR_2_IRQ,
    QEI0_IRQ,
    ADC0_SEQUENCE_0_IRQ,
    ADC0_SEQUENCE_1_IRQ,
    ADC0_SEQUENCE_2_IRQ,
    ADC0_SEQUENCE_3_IRQ,
    WATCHDOG_TIMERS_IRQ,
    TIMER_0A_IRQ,
    TIMER_0B_IRQ,
    TIMER_1A_IRQ,
    TIMER_1B_IRQ,
    TIMER_2A_IRQ,
    TIMER_2B_IRQ,
    ANALOG_COMPARATOR_0_IRQ,
    ANALOG_COMPARATOR_1_IRQ,
    SYSTEM_CONTROL_IRQ = 28,
    EEPROM_CONTROL_IRQ,
    GPIO_PORT_F_IRQ,
    UART2_IRQ = 33,
    SSI1_IRQ,
    TIMER_3A_IRQ,
    TIMER_3B_IRQ,
    I2C1_IRQ,
    QEI1_IRQ,
    CAN0_IRQ,
    CAN1_IRQ,
    HIBERNATION_MODULE_IRQ = 43,
    USB_IRQ,
    PWM0_GENERATOR_3_IRQ,
    DMA_SOFTWARE_IRQ,
    DMA_ERROR_IRQ,
    ADC1_SEQUENCE_0_IRQ,
    ADC1_SEQUENCE_1_IRQ,
    ADC1_SEQUENCE_2_IRQ,
    ADC1_SEQUENCE_3_IRQ,
    SSI2_IRQ = 57,
    SSI3_IRQ,
    UART3_IRQ,
    UART4_IRQ,
    UART5_IRQ,
    UART6_IRQ,
    UART7_IRQ,
    I2C2_IRQ = 68,
    I2C3_IRQ,
    TIMER_4A_IRQ,
    TIMER_4B_IRQ,
    TIMER_5A_IRQ = 92,
    TIMER_5B_IRQ,
    WTIMER_0A_IRQ,
    WTIMER_0B_IRQ,
    WTIMER_1A_IRQ,
    WTIMER_1B_IRQ,
    WTIMER_2A_IRQ,
    WTIMER_2B_IRQ,
    WTIMER_3A_IRQ,
    WTIMER_3B_IRQ,
    WTIMER_4A_IRQ,
    WTIMER_4B_IRQ,
    WTIMER_5A_IRQ,
    WTIMER_5B_IRQ,
    SYSTEM_EXCEPTION_IRQ,
    PWM1_GENERATOR_0_IRQ = 134,
    PWM1_GENERATOR_1_IRQ,
    PWM1_GENERATOR_2_IRQ,
    PWM1_GENERATOR_3_IRQ,
    PWM1_FAULT_IRQ
    
}IntCtrl_InterruptType;

typedef struct
{
    IntCtrl_ExceptionType exception;
    uint8 state;
    uint8 groupPri;
    uint8 subgroupPri;

}IntCtrl_FaultExceptionConfigType;

typedef struct
{
    IntCtrl_ExceptionType exception;
    uint8 state;
    uint8 groupPri;
    uint8 subgroupPri;

}IntCtrl_SystemExceptionConfigType;

typedef struct
{
    IntCtrl_InterruptType irq;
    uint8 state;
    uint8 groupPri;
    uint8 subgroupPri;
}IntCtrl_InterruptExceptionConfigType;

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/


#endif  /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
