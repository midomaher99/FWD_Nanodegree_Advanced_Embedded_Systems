/*
 * main.c
 *
 *      Author: ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "SysCtrl_Cfg.h"
#include "SysCtrl_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

//configrations array
const SysCtrl_ConfigType SysCtrl_Config[NUM_PERIPHIRALS_ACTICATED] =
{
    // Peripheral to be enables
    {SysCtrl_GPIOF_Enable},
    {SysCtrl_16_32_Timer1_Enable}

};

/**********************************************************************************************************************
 *  END OF FILE: SysCtrl_Lcfg.c
 *********************************************************************************************************************/
