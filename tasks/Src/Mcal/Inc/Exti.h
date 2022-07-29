/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Exti.h
 *       Module:  GPIO External interrupts
 *
 *  Description: header file of Exti driver
 *
 *********************************************************************************************************************/
#ifndef EXTI_H
#define EXTI_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Exti_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void Exti_InterruptsIn(Exti_PinType channelId, Exti_TriggerLevelType level, Exti_Notification callbackPtr)
 * \Description     : enable external interrupt for a GPIO channel with edge or level detection
 * 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * 
 * \Parameters (in) : Exti_PinType              the channel requred to enable extenal interrupt for it from Exti_Types.h
 *                  : Exti_TriggerLevelType     the the required level to trigger interrupt when detectd from Exti_Types.h
 *                  : Exti_Notification         Pointer to the required callback function 
 * 
 * \Parameters (out): None
 * \Return value:   : None
 * 
 * NOTE:            : User MUST clear the interrupt flag in the callback function
 *******************************************************************************/
extern void Exti_InterruptsIn(Exti_PinType channelId, Exti_TriggerLevelType level, Exti_Notification callbackPtr);

#endif /* EXTI_H */

/**********************************************************************************************************************
 *  END OF FILE: Exti.h
 *********************************************************************************************************************/
