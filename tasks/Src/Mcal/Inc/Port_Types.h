/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  PortTypes.h
 *       Module:  GPIO
 *
 *  Description:  types to be used in Gpio Port driver
 *
 *********************************************************************************************************************/
#ifndef PORT_TYPES_H
#define PORT_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PlatformTypes.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
// PinMode macros
#define Port_Digital (16u)
#define Port_Analog (17u)

#define PA0_U0RX (1u)
#define PA0_CAN1RX (8u)
#define PA1_U0TX (1u)
#define PA1_CAN1TX (8u)
#define PA2_SSI0CLK (2u)
#define PA3_SSI0FSS (2u)
#define PA4_SSI0RX (2u)
#define PA5_SSI0TX (2u)
#define PA6_I2C1SCL (3u)
#define PA6_M1PWM2 (5u)
#define PA7_I2C1SDA (3u)
#define PA7_M1PWM3 (5u)
#define PB0_U1RX (1u)
#define PB0_T2CCP0 (7u)
#define PB1_U1TX (1u)
#define PB1_T2CCP1 (7u)
#define PB2_I2C0SCL (3u)
#define PB2_T3CCP0 (7u)
#define PB3_I2C0SDA (3u)
#define PB3_T3CCP1 (7u)
#define PB4_SSI2CLK (2u)
#define PB4_M0PWM2 (4u)
#define PB4_T1CCP0 (7u)
#define PB4_CAN0RX (8u)
#define PB5_SSI2FSS (2u)
#define PB5_M0PWM3 (4u)
#define PB5_T1CCP1 (7u)
#define PB5_CAN0TX (8u)
#define PB6_SSI2RX (2u)
#define PB6_M0PWM0 (4u)
#define PB6_T0CCP0 (7u)
#define PB7_SSI2TX (2u)
#define PB7_M0PWM1 (4u)
#define PB7_T0CCP1 (7u)
#define PC0_TCK_SWCLK (1u)
#define PC0_T4CCP0 (7u)
#define PC1_TCK_SWDIO (1u)
#define PC1_T4CCP1 (7u)
#define PC2_TDI (1u)
#define PC2_T5CCP0 (7u)
#define PC3_TDO_SWO (1u)
#define PC3_T5CCP1 (7u)
#define PC4_U4RX (1u)
#define PC4_U1RX (2u)
#define PC4_M0PWM6 (4u)
#define PC4_IDX1 (6u)
#define PC4_WT0CCP0 (7u)
#define PC4_U1RTS (8u)
#define PC5_U4TX (1u)
#define PC5_U1TX (2u)
#define PC5_M0PWM7 (4u)
#define PC5_PHA1 (6u)
#define PC5_WT0CCP1 (7u)
#define PC5_U1CTS (8u)
#define PC6_U3RX (1u)
#define PC6_PHB1 (6u)
#define PC6_WT1CCP0 (7u)
#define PC6_USB0EPEN (8u)
#define PC7_U3TX (1u)
#define PC7_WT1CCP1 (7u)
#define PC7_USB0PFLT (8u)
#define PD0_SSI3CLK (1u)
#define PD0_SSI1CLK (2u)
#define PD0_I2C3SCL (3u)
#define PD0_M0PWM6 (4u)
#define PD0_M1PWM0 (5u)
#define PD0_WT2CCP0 (7u)
#define PD1_SSI3FSS (1u)
#define PD1_SSI1FSS (2u)
#define PD1_I2C3SDA (3u)
#define PD1_M0PWM7 (4u)
#define PD1_M1PWM1 (5u)
#define PD1_WT2CCP1 (7u)
#define PD2_SSI3RX (1u)
#define PD2_SSI1RX (2u)
#define PD2_M0FAULT0 (4u)
#define PD2_WT3CCP0 (7u)
#define PD2_USB0EPEN (8u)
#define PD3_SSI3TX (1u)
#define PD3_SSI1TX (2u)
#define PD3_IDX0 (6u)
#define PD3_WT3CCP1 (7u)
#define PD3_USB0PFLT (8u)
#define PD4_U6RX (1u)
#define PD4_WT4CCP0 (7u)
#define PD5_U6TX (1u)
#define PD5_WT4CCP1 (7u)
#define PD6_U2RX (1u)
#define PD6_M0FAULT0 (4u)
#define PD6_PHA0 (6u)
#define PD6_WT5CCP0 (7u)
#define PD7_U2TX (1u)
#define PD7_PHB0 (6u)
#define PD7_WT5CCP1 (7u)
#define PD7_NMI (8u)
#define PE0_U7RX (1u)
#define PE1_U7TX (1u)
#define PE4_U5RX (1u)
#define PE4_I2C2SCL (3u)
#define PE4_M0PWM4 (4u)
#define PE4_M1PWM2 (5u)
#define PE4_CAN0RX (8u)
#define PE5_U5TX (1u)
#define PE5_I2C2SDA (3u)
#define PE5_M0PWM5 (4u)
#define PE5_M1PWM2 (5u)
#define PE5_CAN0TX (8u)
#define PF0_U1RTS (1u)
#define PF0_SSI1RX (2u)
#define PF0_CAN0RX (3u)
#define PF0_M1PWM4 (5u)
#define PF0_PHA0 (6u)
#define PF0_T0CCP0 (7u)
#define PF0_NMI (8u)
#define PF0_C0O (9u)
#define PF1_U1CTS (1u)
#define PF1_SSI1TX (2u)
#define PF1_M1PWM5 (5u)
#define PF1_PHB0 (6u)
#define PF1_T0CCP1 (7u)
#define PF1_C1O (9u)
#define PF1_TRD1 (14u)
#define PF2_SSI1CLK (2u)
#define PF2_M0FAULT0 (4u)
#define PF2_M1PWM6 (5u)
#define PF2_T1CCP0 (7u)
#define PF2_TRD10 (14u)
#define PF3_SSI1FSS (2u)
#define PF3_CAN0TX (3u)
#define PF3_M1PWM7 (5u)
#define PF3_T1CCP1 (7u)
#define PF3_TRCLK (14u)
#define PF4_M1FAULT0 (5u)
#define PF4_IDX0 (6u)
#define PF4_T2CCP0 (7u)
#define _PF4_USB0EPEN (8u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef uint8 Port_PinModeType;

typedef enum
{
    Port_PA0 = 0x40000u,
    Port_PA1 = 0x40001u,
    Port_PA2 = 0x40002u,
    Port_PA3 = 0x40003u,
    Port_PA4 = 0x40004u,
    Port_PA5 = 0x40005u,
    Port_PA6 = 0x40006u,
    Port_PA7 = 0x40007u,

    Port_0PB = 0x50000u,
    Port_PB1 = 0x50001u,
    Port_PB2 = 0x50002u,
    Port_PB3 = 0x50002u,
    Port_PB4 = 0x50003u,
    Port_PB5 = 0x50004u,
    Port_PB6 = 0x50005u,
    Port_PB7 = 0x50007u,

    Port_PC0 = 0x60000u,
    Port_PC1 = 0x60001u,
    Port_PC2 = 0x60002u,
    Port_PC3 = 0x60003u,
    Port_PC4 = 0x60004u,
    Port_PC5 = 0x60005u,
    Port_PC6 = 0x60006u,
    Port_PC7 = 0x60006u,

    Port_PD0 = 0x70000u,
    Port_PD1 = 0x70001u,
    Port_PD2 = 0x70002u,
    Port_PD3 = 0x70003u,
    Port_PD4 = 0x70004u,
    Port_PD5 = 0x70005u,
    Port_PD6 = 0x70006u,
    Port_PD7 = 0x70007u,

    Port_PE0 = 0x240000u,
    Port_PE1 = 0x240001u,
    Port_PE2 = 0x240002u,
    Port_PE3 = 0x240003u,
    Port_PE4 = 0x240004u,
    Port_PE5 = 0x240005u,
    Port_PE6 = 0x240006u,
    Port_PE7 = 0x240007u,

    Port_PF0 = 0x250000u,
    Port_PF1 = 0x250001u,
    Port_PF2 = 0x250002u,
    Port_PF3 = 0x250003u,
    Port_PF4 = 0x250004u,
    Port_PF5 = 0x250005u,
    Port_PF6 = 0x250006u,
    Port_PF7 = 0x250007u
} Port_PinType;

typedef enum
{
    Port_INPUT = 0u,
    Port_OUTPUT
} Port_PinDirectionType;

typedef enum
{
    Port_InternalAttachAsDefault = 0u,

    Port_OpenDrain = 0x50Cu,
    Port_PullUp = 0x510u,
    Port_PullDown = 0x514u

} PORT_PinInternalAttachType;

typedef enum
{
    Port_OutputCurrentAsDefault = 0u,

    Port_2ma = 0x500u,
    Port_4ma = 0x504u,
    Port_8ma = 0x508u

} PORT_PinOutputCurrentType;

typedef struct
{
    Port_PinType pin;
    Port_PinDirectionType direction;
    Port_PinModeType mode;
    PORT_PinInternalAttachType internalAttach;
    PORT_PinOutputCurrentType outputcurrent;
} Port_ConfigType;

#endif /* PORT_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: PORT_Types.h
 *********************************************************************************************************************/
