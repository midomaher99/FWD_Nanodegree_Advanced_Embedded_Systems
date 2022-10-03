/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Dio.h
 *       Module:  GPIO digital I/O
 *
 *  Description:  header file for Dio driver
 *
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Dio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
extern Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);
extern void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
extern Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId);
extern void Dio_WritePort(Dio_PortLevelType PortId, Dio_PortLevelType Level);

/******************************************************************************
 * \Syntax          : void Dio_FlipChannel(Dio_ChannelType ChannelId)
 * \Description     : toggle th logic on a certain GPIO channel
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : Dio_channelType          the required channel to be Flipped from Dio_types.h
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/

void Dio_FlipChannel(Dio_ChannelType ChannelId);

#endif /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: Std_Types.h
 *********************************************************************************************************************/