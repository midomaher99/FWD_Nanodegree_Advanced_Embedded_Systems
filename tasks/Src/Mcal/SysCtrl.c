/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  FileName.c
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
#include "SysCtrl_Cfg.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void SysCtrl_Init(void)
 * \Description     : initialize System Control module to enable clock gating
 *                    for required peripherals
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : none
 * \Parameters (out): none
 * \Return value:   : none
 *******************************************************************************/
void SysCtrl_Init(void)
{
	vuint32 i;

	vuint32 bitOffset = 0;
	vuint32 regOffset = 0;

	vuint32 *RCGCxxx = 0;
	vuint32 *PRxxx = 0;

	// enabling clock gateing for require peripherals
	for (i = 0; i < NUM_PERIPHIRALS_ACTICATED; i++)
	{
		// get the required RCGC register for this peripheral
		regOffset = (SysCtrl_Config[i].enebledPeriphiral) >> 4u;
		// get the required bit in RCGC and PR registers
		bitOffset = SysCtrl_Config[i].enebledPeriphiral & 0xfu;
		// assign the sequired RCGC and PR registers
		RCGCxxx = (vuint32 *)((SysCtrl_BASE) + (RCGC_OFFSET) + (regOffset));
		PRxxx = (vuint32 *)((SysCtrl_BASE) + (PR_OFFSET) + (regOffset));

		// enable clock gating for the peripheral
		*RCGCxxx |= 1u << (uint32)bitOffset;

		// wait for peripheral to be ready
		//while (!(*PRxxx & (1u << (uint32)bitOffset)))
		//{
		//}
	}
}

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl.c
 *********************************************************************************************************************/
