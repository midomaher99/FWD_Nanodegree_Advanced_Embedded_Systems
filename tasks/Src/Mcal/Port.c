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
    
    GPIO_Type *GPIO = 0;
    for (i = 0; i < NUM_PINS_ACTICATED; i++)
    {
        bitOffset = (Port_Config[i].pin & 0xfu);
        portBase = (0x40000000u | (Port_Config[i].pin >> 4u));
        GPIO = (GPIO_Type *)(portBase);

        // set pin direction
        switch (Port_Config[i].direction)
        {
        case Port_INPUT:
            GPIO->GPIODIR &= ~(1u << bitOffset);
            break;
        case Port_OUTPUT:
            GPIO->GPIODIR |= (1u << bitOffset);
            break;
        }
        // set Pin mode
        // only digital mode is implemented
        switch (Port_Config[i].mode)
        {
        case Port_Digital:
            GPIO->GPIODEN |= 1u << bitOffset;
            break;
            // alternate functions are not implemented
        }
      
        // set pin internal attach
        switch (Port_Config[i].internalAttach)
        {
        case Port_InternalAttachAsDefault:
            break;
        default:
            regOffset = Port_Config[i].internalAttach;
            *((vuint32 *)(portBase + regOffset)) = 1u << bitOffset;
            break;
        }
        // set output driving current
        switch (Port_Config[i].outputcurrent)
        {
        case Port_OutputCurrentAsDefault:
            break;
        default:
            regOffset = Port_Config[i].outputcurrent;
            *((vuint32 *)(portBase + regOffset)) = 1u << bitOffset;
            break;
        }
    }
}

/**********************************************************************************************************************
 *  END OF FILE: Port.c
 *********************************************************************************************************************/