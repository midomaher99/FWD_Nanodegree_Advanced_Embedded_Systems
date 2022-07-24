/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCrtl.c
 *        \brief  NVIC driver (static code)
 *
 *      \details  Simple NVIC driver to enable required interrupts and set their group and subgroup priorities 
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"
#include "IntCtrl_Cfg.h"
#include "MemoryMap.h"
#include "PlatformTypes.h"

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
* \Syntax          : void IntCrtl_Init(void)                                      
* \Description     : initialize NVIC module to enable and prioritize the required interrupts
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/

void IntCrtl_Init(void)
{
	//local variables
	vuint8 i=0;
	vuint8 IRQNumber=0;
	vuint8 PRI_BitOffset=0;
	vuint8 EN_BitOffset=0;
	vuint8 PRI_offset =0;
	
	/*configuring Prioritizing system of interrupts*/
    SCB->APINT = ((0x05FAu <<16)|(PRIGROUPING <<8));

    /*Prioritize required interrupts*/
    for(i=0; i < NUM_INT_ACTIVATED; i++)
    {
    	IRQNumber = NVIC_Cofig[i].vectorName;

    	PRI_BitOffset = (((IRQNumber % 4) * 8) +5) ;
			PRI_offset= IRQNumber / 4;
		#if		(PRIGROUPING == xxx__)
    		NVIC->PRI[IRQNumber / 4] |= (NVIC_Cofig[i].groupPriority <<PRI_BitOffset);
		#elif	(PRIGROUPING == xxy__)
    		NVIC->PRI[IRQNumber / 4] |= (NVIC_Cofig[i].groupPriority <<(PRI_BitOffset+1));
    		NVIC->PRI[IRQNumber / 4] |= (NVIC_Cofig[i].subGroupPriority <<PRI_BitOffset);
    	#elif	(PRIGROUPING == xyy__)	
			NVIC->PRI[PRI_offset] |= (NVIC_Cofig[i].groupPriority <<(PRI_BitOffset+2));
			NVIC->PRI[PRI_offset] |= (NVIC_Cofig[i].subGroupPriority << PRI_BitOffset);
   		#elif	(PRIGROUPING == yyy__)
    		NVIC->PRI[IRQNumber / 4] |= (NVIC_Cofig[i].subGroupPriority <<PRI_BitOffset);
    	#endif
    }

	/*enable required interrupts by writing in NVIC_ENn register*/
    for(i=0; i < NUM_INT_ACTIVATED; i++)
    {
    	IRQNumber = NVIC_Cofig[i].vectorName;
    	EN_BitOffset = (IRQNumber %32) ;
    	NVIC->EN[IRQNumber/32] |= (1u) << EN_BitOffset;
    }
}

/**********************************************************************************************************************
 *  END OF FILE: IntCrtl.c
 *********************************************************************************************************************/
