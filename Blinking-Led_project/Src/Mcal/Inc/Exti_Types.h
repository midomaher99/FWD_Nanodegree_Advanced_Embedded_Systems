/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Exti_Types.h
 *       Module:  GPIO External Interrupts
 *
 *  Description:  types to be used in external interrupt driver
 *
 *********************************************************************************************************************/
#ifndef EXTI_TYPES_H
#define EXTI_TYPES_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "PlatformTypes.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef enum
{
    Exti_PA0 = 0x40000u,
    Exti_PA1 = 0x40001u,
    Exti_PA2 = 0x40002u,
    Exti_PA3 = 0x40003u,
    Exti_PA4 = 0x40004u,
    Exti_PA5 = 0x40005u,
    Exti_PA6 = 0x40006u,
    Exti_PA7 = 0x40007u,

    Exti_PB0 = 0x50000u,
    Exti_PB1 = 0x50001u,
    Exti_PB2 = 0x50002u,
    Exti_PB3 = 0x50002u,
    Exti_PB4 = 0x50003u,
    Exti_PB5 = 0x50004u,
    Exti_PB6 = 0x50005u,
    Exti_PB7 = 0x50007u,

    Exti_PC0 = 0x60000u,
    Exti_PC1 = 0x60001u,
    Exti_PC2 = 0x60002u,
    Exti_PC3 = 0x60003u,
    Exti_PC4 = 0x60004u,
    Exti_PC5 = 0x60005u,
    Exti_PC6 = 0x60006u,
    Exti_PC7 = 0x60006u,

    Exti_PD0 = 0x70000u,
    Exti_PD1 = 0x70001u,
    Exti_PD2 = 0x70002u,
    Exti_PD3 = 0x70003u,
    Exti_PD4 = 0x70004u,
    Exti_PD5 = 0x70005u,
    Exti_PD6 = 0x70006u,
    Exti_PD7 = 0x70007u,

    Exti_PE0 = 0x240000u,
    Exti_PE1 = 0x240001u,
    Exti_PE2 = 0x240002u,
    Exti_PE3 = 0x240003u,
    Exti_PE4 = 0x240004u,
    Exti_PE5 = 0x240005u,
    Exti_PE6 = 0x240006u,
    Exti_PE7 = 0x240007u,

    Exti_PF0 = 0x250000u,
    Exti_PF1 = 0x250001u,
    Exti_PF2 = 0x250002u,
    Exti_PF3 = 0x250003u,
    Exti_PF4 = 0x250004u,
    Exti_PF5 = 0x250005u,
    Exti_PF6 = 0x250006u,
    Exti_PF7 = 0x250007u
} Exti_PinType;

typedef enum
{
    Exti_LowLevelTrigger,
    Exti_HighLevelTrigger,
    Exti_RisingEdgeTrigger,
    Exti_FallingEdgeTrigger,
    Exti_BothEdgesTrigger
} Exti_TriggerLevelType;

typedef void (*Exti_Notification)();

#endif /* EXTI_TYPES_H */

/**********************************************************************************************************************
 *  END OF FILE: Exti_Types.h
 *********************************************************************************************************************/
