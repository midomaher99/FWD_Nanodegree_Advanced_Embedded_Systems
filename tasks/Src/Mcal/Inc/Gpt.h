/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Gpt.h
 *       Module:  General Purpose Timer
 *
 *  Description:  header file of Gpt driver
 *
 *********************************************************************************************************************/
#ifndef GPT_H
#define GPT_H
/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Gpt_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
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
extern void Gpt_Init();

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
extern void Gpt_StartTimer(Gpt_ChannelType channelId, GPT_ValueType loadValue);

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
extern void Gpt_EnableNotification(Gpt_ChannelType channelId, Gpt_Notification callbackPtr);

/******************************************************************************
 * \Syntax          : void Gpt_DisableNotification(Gpt_ChannelType channelId, Gpt_Notification callbackPtr)
 * \Description     : disable channel triggering an interrupt
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Gpt_ChannelType   The GPt required channel from Gpt_Types.h
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Gpt_DisableNotification(Gpt_ChannelType channelId);
#endif /* GPT_H */

/**********************************************************************************************************************
 *  END OF FILE: Gpt.h
 *********************************************************************************************************************/
