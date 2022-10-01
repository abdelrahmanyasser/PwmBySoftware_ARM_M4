/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu Hw
 *
 *  Description:  <Write File DESCRIPTION here>     
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS              0xE000E000

/* NVIC registers */
#define EN0_REG                 (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x100)))
#define EN1_REG                 (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x104)))
#define EN2_REG                 (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x108)))
#define EN3_REG                 (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x10C)))

#define PRI0_REG                (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x400)))
#define PRI1_REG                (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x404)))
#define PRI2_REG                (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x408)))
#define PRI3_REG                (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x40C)))
#define PRI4_REG                (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x410)))
#define PRI5_REG                (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x414)))
#define PRI6_REG                (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x418)))
#define PRI7_REG                (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x41C)))
#define PRI8_REG                (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x420)))
#define PRI9_REG                (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x424)))
#define PRI10_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x428)))
#define PRI11_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x42C)))
#define PRI12_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x430)))
#define PRI13_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x434)))
#define PRI14_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x438)))
#define PRI15_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x43C)))
#define PRI16_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x440)))
#define PRI17_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x444)))
#define PRI18_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x448)))
#define PRI19_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x44C)))
#define PRI20_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x450)))
#define PRI21_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x454)))
#define PRI22_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x458)))
#define PRI23_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x45C)))
#define PRI24_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x460)))
#define PRI25_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x464)))
#define PRI26_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x468)))
#define PRI27_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x46C)))
#define PRI28_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x470)))
#define PRI29_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x474)))
#define PRI30_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x478)))
#define PRI31_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x47C)))
#define PRI32_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x480)))
#define PRI33_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x484)))
#define PRI34_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0x488)))

/* SCB registers */
#define APINT_REG               (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD0C)))
#define INTCTRL_REG             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD04)))

#define SYSPRI1_REG             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD18)))
#define SYSPRI2_REG             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD1C)))
#define SYSPRI3_REG             (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD20)))
#define SYSHNDCTRL_REG          (*((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS + 0xD24)))

/* System control */
#define SYSCTRL_BASE_ADDRESS                    0x400FE000
#define RCGCGPIO_REG                            ((*(volatile uint32*)(SYSCTRL_BASE_ADDRESS + 0x608)))
#define RCGCTIMER_REG                           ((*(volatile uint32*)(SYSCTRL_BASE_ADDRESS + 0x604)))
#define RCGCWTIMER_REG                          ((*(volatile uint32*)(SYSCTRL_BASE_ADDRESS + 0x65C)))

/* GPIOs */
#define GPIOA_BASE_ADDRESS                      0x40004000
#define GPIOB_BASE_ADDRESS                      0x40005000
#define GPIOC_BASE_ADDRESS                      0x40006000
#define GPIOD_BASE_ADDRESS                      0x40007000
#define GPIOE_BASE_ADDRESS                      0x40024000
#define GPIOF_BASE_ADDRESS                      0x40025000

#define GPIODATA_OFFSET                         0x000
#define GPIODIR_OFFSET                          0x400

#define GPIOAFSEL_OFFSET                        0x420
#define GPIODR2R_OFFSET                         0x500
#define GPIODR4R_OFFSET                         0x504
#define GPIODR8R_OFFSET                         0x508

#define GPIOPUR_OFFSET                          0x510
#define GPIOPDR_OFFSET                          0x514

#define GPIODEN_OFFSET                          0x51C
#define GPIOLOCK_OFFSET                         0x520
#define GPIOCR_OFFSET                           0x524
#define GPIOAMSEL_OFFSET                        0x528
#define GPIOPCTL_OFFSET                         0x52C

#define GPIOLOCK_KEY                            0x4C4F434B

#define GPIODATA_BIT0_MASK                      0x3FC
#define GPIODATA_BIT1_MASK                      0x3FC                   
#define GPIODATA_BIT2_MASK                      0x3FC
#define GPIODATA_BIT3_MASK                      0x3FC
#define GPIODATA_BIT4_MASK                      0x3FC
#define GPIODATA_BIT5_MASK                      0x3FC
#define GPIODATA_BIT6_MASK                      0x3FC
#define GPIODATA_BIT7_MASK                      0x3FC

/* GPT */
#define TIMER0_BASE_ADDRESS                     0x40030000
#define TIMER1_BASE_ADDRESS                     0x40031000
#define TIMER2_BASE_ADDRESS                     0x40032000
#define TIMER3_BASE_ADDRESS                     0x40033000
#define TIMER4_BASE_ADDRESS                     0x40034000
#define TIMER5_BASE_ADDRESS                     0x40035000
#define WTIMER0_BASE_ADDRESS                    0x40036000
#define WTIMER1_BASE_ADDRESS                    0x40037000
#define WTIMER2_BASE_ADDRESS                    0x4004C000
#define WTIMER3_BASE_ADDRESS                    0x4004D000
#define WTIMER4_BASE_ADDRESS                    0x4004E000
#define WTIMER5_BASE_ADDRESS                    0x4004F000


#define GPTMCFG_OFFSET                          0x000
#define GPTMTAMR_OFFSET                         0x004
#define GPTMCTL_OFFSET                          0x00C
#define GPTMIMR_OFFSET                          0x018

#define GPTMTAILR_OFFSET                        0x028
#define GPTMTBILR_OFFSET                        0x02C
#define GPTMICR_OFFSET                          0x024

#define GPTMTAPR_OFFSET                         0x038
#define GPTMTBPR_OFFSET                         0x03C



/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/
#define SET_BIT(reg, bit)                       ((reg) = (reg) |  (1 << (bit)))
#define CLEAR_BIT(reg, bit)                     ((reg) = (reg) & ~(1 << (bit)))
#define TOGGLE_BIT(reg, bit)                    ((reg) = (reg) ^  (1 << (bit)))

#define BIT_IS_SET(reg, bit)                    ((reg) & (1 <<(bit)))
#define BIT_IS_CLEAR(reg, bit)                  (!((reg) & (1 <<(bit))))

#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
