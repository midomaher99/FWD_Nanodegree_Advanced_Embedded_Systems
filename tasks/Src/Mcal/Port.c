/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  Port.c
 *        \brief
 *
 *      \details
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/

#include "MemoryMap.h"
#include "PlatformTypes.h"
#include "Port_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void Port_Init()
 * \Description     : configre the required I/O pins direction, alternate function, internal attach
 *                    and the required driving output current
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void Port_Init()
{
    vuint8 i;

    vuint32 bitOffset = 0;
    vuint32 portBase = 0;
    vuint32 regOffset = 0;

    for (i = 0; i < NUM_PINS_ACTICATED; i++)
    {
        // get the pin offset to be used inside the regesters
        bitOffset = (Port_Config[i].pin & 0xfu);
        // get the required port
        portBase = (0x40000000u | (Port_Config[i].pin >> 4u));

        // set pin direction
        switch (Port_Config[i].direction)
        {
        case Port_INPUT:
            GPIO(portBase)->GPIODIR &= ~(1u << bitOffset);
            break;
        case Port_OUTPUT:
            GPIO(portBase)->GPIODIR |= (1u << bitOffset);
            break;
        }

        // set Pin mode
        // the analog alternate functions are not implemented
        switch (Port_Config[i].mode)
        {
        case Port_Digital: // digital
            GPIO(portBase)->GPIOAFSEL &= ~(1u << bitOffset);
            GPIO(portBase)->GPIODEN |= 1u << bitOffset;
            break;
        default: // alternate functions
            GPIO(portBase)->GPIOAFSEL &= ~(1u << bitOffset);
            GPIO(portBase)->GPIOPCTL &= ~(0b1111 << (bitOffset * 4));
            GPIO(portBase)->GPIOPCTL |= (Port_Config[i].mode << (bitOffset * 4));
            break;
        }

        // set pin internal attach
        switch (Port_Config[i].internalAttach)
        {
        case Port_InternalAttachAsDefault:
            break;
        default:
            regOffset = Port_Config[i].internalAttach; // the requied reg OD, PU, PD
            *((vuint32 *)(portBase + regOffset)) = 1u << bitOffset;
            break;
        }
        // set output driving current
        switch (Port_Config[i].outputcurrent)
        {
        case Port_OutputCurrentAsDefault:
            break;
        default:
            regOffset = Port_Config[i].outputcurrent; // the required reg R2R, R8R, R4R
            *((vuint32 *)(portBase + regOffset)) = 1u << bitOffset;
            break;
        }
    }
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/
