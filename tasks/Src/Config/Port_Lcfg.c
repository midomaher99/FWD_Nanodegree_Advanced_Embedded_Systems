/*
 * main.c
 *
 *      Author: ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 */
/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port_Cfg.h"
#include "Port_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

//configrations array
const Port_ConfigType Port_Config[NUM_PINS_ACTICATED]=
{
    //channel  direction    function      internal attach                 outut driving current
    {Port_PF0, Port_INPUT,  Port_Digital, Port_PullUp,                    Port_OutputCurrentAsDefault},
    {Port_PF4, Port_INPUT,  Port_Digital, Port_PullUp,                    Port_OutputCurrentAsDefault},
    {Port_PF2, Port_OUTPUT, Port_Digital, Port_InternalAttachAsDefault,   Port_4ma}
};

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
