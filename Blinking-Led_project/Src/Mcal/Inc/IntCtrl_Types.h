/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Types.h
 *       Module:  NVIC
 *
 *  Description:  types to be used in interrupt controller driver
 *
 *********************************************************************************************************************/
#ifndef INTCTRL_TYPES_H
#define INTCTRL_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"
#include "PlatformTypes.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// Priority grouping macros used in intCtrl_Cfg.h
#define xxx__ (4u)
#define xxy__ (5u)
#define xyy__ (6u)
#define yyy__ (7u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    NVIC_GPIO_PORT_A,
    NVIC_GPIO_PORT_B,
    NVIC_GPIO_PORT_C,
    NVIC_GPIO_PORT_D,
    NVIC_GPIO_PORT_E,
    NVIC_UART_0,
    NVIC_UART_1,
    NVIC_SSI_0,
    NVIC_I2C_0,
    NVIC_PWM_0_FAULT,
    NVIC_PWM_0_GEN_0,
    NVIC_PWM_0_GEN_1,
    NVIC_PWM_0_GEN_2,
    NVIC_QEI_0,
    NVIC_ADC_0_SEQ_0,
    NVIC_ADC_0_SEQ_1,
    NVIC_ADC_0_SEQ_2,
    NVIC_ADC_0_SEQ_3,
    NVIC_TIMER_WATCHDOG_0_1,
    NVIC_16_32_TIMER_0_A,
    NVIC_16_32_TIMER_0_B,
    NVIC_16_32_TIMER_1_A,
    NVIC_16_32_TIMER_1_B,
    NVIC_16_32_TIMER_2_A,
    NVIC_16_32_TIMER_2_B,
    NVIC_ANALOG_COMPARATOR_0,
    NVIC_ANALOG_COMPARATOR_1,
    NVIC_SYSTEM_CONTROL = 28,
    NVIC_FLASH_EEPROM_MEMORY_CONTROL,
    NVIC_GPIO_PORT_F,
    NVIC_UART_2 = 33,
    NVIC_SSI_1,
    NVIC_16_32_TIMER_3_A,
    NVIC_16_32_TIMER_3_B,
    NVIC_I2C_1,
    NVIC_QEI_1,
    NVIC_CAN_0,
    NVIC_CAN_1,
    NVIC_HIBERNATION = 43,
    NVIC_USB,
    NVIC_PWM_GEN_3,
    NVIC_UDMA_SOFTWARE,
    NVIC_UDMA_ERROR,
    NVIC_ADC_1_SEQ_0,
    NVIC_ADC_1_SEQ_1,
    NVIC_ADC_1_SEQ_2,
    NVIC_ADC_1_SEQ_3,
    NVIC_SSI_2 = 57,
    NVIC_SSI_3,
    NVIC_UART_3,
    NVIC_UART_4,
    NVIC_UART_5,
    NVIC_UART_6,
    NVIC_UART_7,
    NVIC_I2C_2 = 68,
    NVIC_I2C_3,
    NVIC_16_32_TIMER_4_A,
    NVIC_16_32_TIMER_4_B,
    NVIC_16_32_TIMER_5_A = 92,
    NVIC_16_32_TIMER_5_B,
    NVIC_32_64_TIMER_0_A,
    NVIC_32_64_TIMER_0_B,
    NVIC_32_64_TIMER_1_A,
    NVIC_32_64_TIMER_1_B,
    NVIC_32_64_TIMER_2_A,
    NVIC_32_64_TIMER_2_B,
    NVIC_32_64_TIMER_3_A,
    NVIC_32_64_TIMER_3_B,
    NVIC_32_64_TIMER_4_A,
    NVIC_32_64_TIMER_4_B,
    NVIC_32_64_TIMER_5_A,
    NVIC_32_64_TIMER_5_B,
    NVIC_SYSTEM_EXCEPTION,
    NVIC_PWM_1_GEN_0 = 134,
    NVIC_PWM_1_GEN_1,
    NVIC_PWM_1_GEN_2,
    NVIC_PWM_1_GEN_3,
    NVIC_PWM_1_FAULT
} Nvic_InterruptsType;

typedef struct
{
    Nvic_InterruptsType vectorName; // name from Nvic_InterruptsType in IntCtlc.h

    // priorities is givin fom 0->7 depending on the PRIGROUPING macro
    uint32 groupPriority;
    uint32 subGroupPriority;
} NVIC_ConfigType;

#endif /* INTCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Types.h
 *********************************************************************************************************************/
