/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  IntCtrl_Lcfg.c
 *        \brief  NVIC driver (dynamic code)
 *
 *      \details  to use the NVIC drive you should configure the interrupts from
 *      		  this file and the IntCtrl_cfg.h file
 *
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "IntCtrl_Cfg.h"
#include "IntCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

//configrations array
const NVIC_ConfigType NVIC_Cofig[NUM_INT_ACTIVATED]=
{
	//Peripheral			group priority 	subgroup priority
	{NVIC_GPIO_PORT_F,			0u,			0u},
	{NVIC_16_32_TIMER_1_A,		1u,			0u}

};
/**********************************************************************************************************************
 *  END OF FILE: IntCtrl_Lcfg.c
 *********************************************************************************************************************/
