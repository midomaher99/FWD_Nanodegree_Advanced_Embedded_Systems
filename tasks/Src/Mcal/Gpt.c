/*
 * Gpt.c
 *
 *  Created on: Jul 21, 2022
 *      Author: ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Gpt_Types.h"
#include "Gpt_Cfg.h"
#include "MemoryMap.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
Gpt_Notification callBacksArray[12] = {NULL};

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void Gpt_Init()
 * \Description     : Initialize the General Purpose Timers module
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Gpt_Init()
{
    vuint8 i;
    vuint32 timerBase = 0;

    for (i = 0; i < NUM_TIMERS_ACTIVATED; i++)
    {
        timerBase = gpt_config[i].channelID;

        // Disable timer
        Timer(timerBase)->GPTMCTL = 0;
        // Concatenated
        Timer(timerBase)->GPTMCFG = 0x0u;
        // CountDown
        Timer(timerBase)->GPTMTAMR &= ~(1u << 4u);
        // Mode selection
        switch (gpt_config[i].channelMode)
        {
        case Gpt_OneShot:
            Timer(timerBase)->GPTMTAMR |= 1u << 0u;
            break;
        case Gpt_Periodic:
            Timer(timerBase)->GPTMTAMR |= 1u << 1u;
            break;
        }
    }
}

/******************************************************************************
 * \Syntax          : void Gpt_StartTimer(Gpt_ChannelType channelId, GPT_ValueType loadValue)
 * \Description     : load the Interval value and start counting
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Gpt_ChannelType   The GPt required channel from Gpt_Types.h
 *                  : GPT_ValueType     The required interval value from 0 ->(2^32)-1
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Gpt_StartTimer(Gpt_ChannelType channelId, GPT_ValueType loadValue)
{
    Timer(channelId)->GPTMTAILR = loadValue * 0xF423FF;
    Timer(channelId)->GPTMCTL |= 1u << 0;
}

/******************************************************************************
 * \Syntax          : void Gpt_EnableNotification(Gpt_ChannelType channelId, Gpt_Notification callbackPtr)
 * \Description     : Enable channel to trigger an interrupt when time out and setting callBack Functoin
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Gpt_ChannelType   The GPt required channel from Gpt_Types.h
 *                  : Gpt_Notification     Pointer to the required callback function
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void Gpt_EnableNotification(Gpt_ChannelType channelId, Gpt_Notification callbackPtr)
{

    // set call back to global array
    switch (channelId)
    {
    case Gpt_Timer0:
        callBacksArray[0] = callbackPtr;
        break;
    case Gpt_Timer1:
        callBacksArray[1] = callbackPtr;
        break;
    case Gpt_Timer2:
        callBacksArray[2] = callbackPtr;
        break;
    case Gpt_Timer3:
        callBacksArray[3] = callbackPtr;
        break;
    case Gpt_Timer4:
        callBacksArray[4] = callbackPtr;
        break;
    case Gpt_Timer5:
        callBacksArray[5] = callbackPtr;
        break;
    case Gpt_WTimer0:
        callBacksArray[6] = callbackPtr;
        break;
    case Gpt_WTimer1:
        callBacksArray[7] = callbackPtr;
        break;
    case Gpt_WTimer2:
        callBacksArray[8] = callbackPtr;
        break;
    case Gpt_WTimer3:
        callBacksArray[9] = callbackPtr;
        break;
    case Gpt_WTimer4:
        callBacksArray[10] = callbackPtr;
        break;
    case Gpt_WTimer5:
        callBacksArray[11] = callbackPtr;
        break;
    }
    //enable time out interrupt
    Timer(channelId)->GPTMIMR |= 1;
}
/******************************************************************************
 * \Syntax          : void Gpt_DisableNotification(Gpt_ChannelType channelId, Gpt_Notification callbackPtr)
 * \Description     : disable channel triggering an interrupt 
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Gpt_ChannelType   The GPt required channel from Gpt_Types.h
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType channelId)
{

    //disable interrupts
    Timer(channelId)->GPTMICR = 0x10F1F;
}




void TIMER1A_Handler(void)
{

    Gpt_Notification callback = callBacksArray[1];

    if (callback != NULL)
    {   
        //clear interrupt status flag
        Timer1->GPTMICR |= 1 << 0;
        //jump to callback
        callback();
    }
}

/**********************************************************************************************************************
 *  END OF FILE: Gpt.c
 *********************************************************************************************************************/