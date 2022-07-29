/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Sysctrl_Types.h
 *       Module:  System Control
 *
 *  Description:  types to be used in System Controller driver
 *
 *********************************************************************************************************************/
#ifndef SYSCTRL_TYPES_H
#define SYSCTRL_TYPES_H

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define RCGC_OFFSET 0x600u
#define PR_OFFSET 0xA00u

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    SysCtrl_WatchdogTimer0_Enable = 0x000u,
    SysCtrl_WatchdogTimer1_Enable = 0x001u,
    SysCtrl_16_32_Timer0_Enable = 0x040u,
    SysCtrl_16_32_Timer1_Enable = 0x041u,
    SysCtrl_16_32_Timer2_Enable = 0x042u,
    SysCtrl_16_32_Timer3_Enable = 0x043u,
    SysCtrl_16_32_Timer4_Enable = 0x044u,
    SysCtrl_16_32_Timer5_Enable = 0x045u,
    SysCtrl_GPIOA_Enable = 0x080u,
    SysCtrl_GPIOB_Enable = 0x081u,
    SysCtrl_GPIOC_Enable = 0x082u,
    SysCtrl_GPIOD_Enable = 0x083u,
    SysCtrl_GPIOE_Enable = 0x084u,
    SysCtrl_GPIOF_Enable = 0x085u,
    SysCtrl_DMA_Enable = 0x0C0u,
    SysCtrl_HIB_Enable = 0x140u,
    SysCtrl_UART0_Enable = 0x180u,
    SysCtrl_UART1_Enable = 0x181u,
    SysCtrl_UART2_Enable = 0x182u,
    SysCtrl_UART3_Enable = 0x183u,
    SysCtrl_UART4_Enable = 0x184u,
    SysCtrl_UART5_Enable = 0x185u,
    SysCtrl_UART6_Enable = 0x186u,
    SysCtrl_UART7_Enable = 0x187u,
    SysCtrl_SSI0_Enable = 0x1C0u,
    SysCtrl_SSI1_Enable = 0x1C1u,
    SysCtrl_SSI2_Enable = 0x1C2u,
    SysCtrl_SSI3_Enable = 0x1C3u,
    SysCtrl_I2C0_Enable = 0x200u,
    SysCtrl_I2C1_Enable = 0x201u,
    SysCtrl_I2C2_Enable = 0x202u,
    SysCtrl_I2C3_Enable = 0x203u,
    SysCtrl_USB_Enable = 0x280u,
    SysCtrl_CAN0_Enable = 0x340u,
    SysCtrl_CAN1_Enable = 0x341u,
    SysCtrl_ADC0_Enable = 0x380u,
    SysCtrl_ADC1_Enable = 0x381u,
    SysCtrl_AnalogCMP_Enable = 0x3C0u,
    SysCtrl_PWM0_Enable = 0x400u,
    SysCtrl_PWM1_Enable = 0x401u,
    SysCtrl_QEI0_Enable = 0x440u,
    SysCtrl_QEI1_Enable = 0x441u,
    SysCtrl_EEPROM_Enable = 0x580u,
    SysCtrl_32_64_Timer0_Enable = 0x5C0u,
    SysCtrl_32_64_Timer1_Enable = 0x5C1u,
    SysCtrl_32_64_Timer2_Enable = 0x5C2u,
    SysCtrl_32_64_Timer3_Enable = 0x5C3u,
    SysCtrl_32_64_Timer4_Enable = 0x5C4u,
    SysCtrl_32_64_Timer5_Enable = 0x5C5u
} SysCtrl_ClockGatingType;

typedef struct
{
    SysCtrl_ClockGatingType enebledPeriphiral;

} SysCtrl_ConfigType;

#endif /* SYSCTRL_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl_Types.h
 *********************************************************************************************************************/
