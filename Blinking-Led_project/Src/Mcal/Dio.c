/*
 * Dio.c
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
#include "Dio_Types.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
 * \Description     : reads the level of a GPIO channel
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Dio_ChannelType   the required GPIO channel to be read fron Dio_Types.h
 * \Parameters (out): None
 * \Return value:   : Dio_LevelType     the level of the channel channel
 *******************************************************************************/
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{
    uint32 bitMaskOffset = (ChannelId & 0xff);  //get the required pin
    uint32 portBase = (0x40000000u | (ChannelId >> 8u));    //get the required Port

    if (GPIO(portBase)->GPIODATA[bitMaskOffset] > 0)
        return Dio_HIGH;
    else
        return Dio_LOW;
}
/******************************************************************************
 * \Syntax          : void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
 * \Description     : write data to a certain channel in gpio
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Dio_ChannelType   the required channel to be writen from Dio_types.h
 *                    Dio_LevelType     the required level to be written on the channel from Dio_types.h
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
    uint32 bitMaskOffset = (ChannelId & 0xffu);
    uint32 portBase = (0x40000000u | (ChannelId >> 8u));

    GPIO(portBase)->GPIODATA[bitMaskOffset] = (Level * 255u) << 2u;
}

/******************************************************************************
 * \Syntax          : Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
 * \Description     : reads the level of a GPIO Port
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Dio_PortType    the required port to be writen from Dio_types.h
 * \Parameters (out): None
 * \Return value:   : Dio_PortLevelType     the level of the Port
 *******************************************************************************/
Dio_PortLevelType Dio_ReadPort(Dio_PortType PortId)
{

    return ((uint8)GPIO(PortId)->GPIODATA[255]);
}
/******************************************************************************
 * \Syntax          : void Dio_WritePort(Dio_PortLevelType PortId, Dio_PortLevelType Level)
 * \Description     : write data to a certain Port in gpio
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Reentrant
 * \Parameters (in) : Dio_PortType          the required Port to be writen from Dio_types.h
 *                    Dio_PortLevelType     the required level to be written on the Port from 0->255
 * \Parameters (out): None
 * \Return value:   : None
 *  *******************************************************************************/
void Dio_WritePort(Dio_PortType PortId, Dio_PortLevelType Level)
{

    GPIO(PortId)->GPIODATA[255] = Level;
}

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

void Dio_FlipChannel(Dio_ChannelType ChannelId)
{
    uint32 bitMaskOffset = (ChannelId & 0xffu);
    uint32 portBase = (0x40000000u | (ChannelId >> 8u));

    GPIO(portBase)->GPIODATA[255] ^=  ( ChannelId);
}
/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
