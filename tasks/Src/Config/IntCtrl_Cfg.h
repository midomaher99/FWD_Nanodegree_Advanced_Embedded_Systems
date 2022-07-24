/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  IntCtrl_Cfg.h
 *       Module:  NVIC
 *
 *  Description:  to use the NVIC drive you should configure the interrupts from
 *      		  this file and the IntCtrl_Lcfg.c file
 *  
 *********************************************************************************************************************/
#ifndef INTCTRL_CFG_H
#define INTCTRL_CFG_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl.h"
#include "PlatformTypes.h"
/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/

/*
 * xxx__ for group priority(0->7), subgroup priority (0)
 * xxy__ for group priority(0->3), subgroup priority (0->1)
 * xyy__ for group priority(0->1), subgroup priority (0->3)
 * yyy__ for group priority(0)	 , subgroup priority (0->7)
 */
#define PRIGROUPING		(xxy__)


//the number of interrupts that will be activated
#define NUM_INT_ACTIVATED	(3u)

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct
{
	Nvic_InterruptsType vectorName;		//name from Nvic_InterruptsType in IntCtlc.h

	//priorities is givin fom 0->7 depending on the PRIGROUPING macro
	uint32 groupPriority;
	uint32 subGroupPriority;
}NVIC_ConfigType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/
extern const NVIC_ConfigType NVIC_Cofig[NUM_INT_ACTIVATED];

#endif /* INTCTRL_CFG_H */
/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Cfg.h
 *********************************************************************************************************************/

