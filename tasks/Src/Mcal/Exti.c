/*
 * Exti.c
 *
 *  Created on: Jul 21, 2022
 *      Author: ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "PlatformTypes.h"
#include "MemoryMap.h"
#include "Exti_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
Exti_Notification callbacksArray[6] = {NULL};

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
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
 *******************************************************************************/
void Exti_InterruptsIn(Exti_PinType channelId, Exti_TriggerLevelType level, Exti_Notification callbackPtr)
{
    vuint32 bitOffset = 0;
    vuint32 portBase = 0;
    vuint32 regOffset = 0;
    
    // get the pin offset to be used inside the regesters
    bitOffset = (channelId & 0xfu); 

    // get the requiered port
    portBase = (0x40000000u | (channelId >> 0x4u));

    //set level to trigger interrupt
    switch (level)
    {
    case Exti_HighLevelTrigger:
        GPIO(portBase)->GPIOIS |= 1 << bitOffset;
        GPIO(portBase)->GPIOIEV |= 1 << bitOffset;
        break;
    case Exti_LowLevelTrigger:
        GPIO(portBase)->GPIOIS |= 1 << bitOffset;
        GPIO(portBase)->GPIOIEV &= ~(1 << bitOffset);
        break;
    case Exti_BothEdgesTrigger:
        GPIO(portBase)->GPIOIS &= ~(1 << bitOffset);
        GPIO(portBase)->GPIOIBE |= 1 << bitOffset;
        break;
    case Exti_RisingEdgeTrigger:
        GPIO(portBase)->GPIOIS &= ~(1 << bitOffset);
        GPIO(portBase)->GPIOIBE &= ~(1 << bitOffset);
        GPIO(portBase)->GPIOIEV |= 1 << bitOffset;
        break;
    case Exti_FallingEdgeTrigger:
        GPIO(portBase)->GPIOIS &= ~(1 << bitOffset);
        GPIO(portBase)->GPIOIBE &= ~(1 << bitOffset);
        GPIO(portBase)->GPIOIEV &= ~(1 << bitOffset);
        break;
    }

    //set callback
    switch (channelId)
    {
    case Exti_PA0 ... Exti_PA7:
        callbacksArray[0] = callbackPtr;
        break;
    case Exti_PB0 ... Exti_PB7:
        callbacksArray[1] = callbackPtr;
        break;
    case Exti_PC0 ... Exti_PC7:
        callbacksArray[2] = callbackPtr;
        break;
    case Exti_PD0 ... Exti_PD7:
        callbacksArray[3] = callbackPtr;
        break;
    case Exti_PE0 ... Exti_PE7:
        callbacksArray[4] = callbackPtr;
        break;
    case Exti_PF0 ... Exti_PF7:
        callbacksArray[5] = callbackPtr;
        break;
    }

    
    GPIO(portBase)->GPIOICR |= 1 << bitOffset; //clear interrupt flag
    GPIO(portBase)->GPIOIM |= 1 << bitOffset;   //Mask the interrupt with 1 (enable)
}



void GPIOF_Handler()
{
    callbacksArray[5]();
}

/**********************************************************************************************************************
 *  END OF FILE: Exti.c
 *********************************************************************************************************************/
