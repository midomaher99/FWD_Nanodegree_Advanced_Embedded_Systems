/*
 * main.c
 *
 *      Author: ENG: Mohame Mostafa Maher
 *      contact: mohamed.mostafa.maher.999@gmail.com
 */

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "MemoryMap.h"
#include "IntCtrl.h"
#include "SysCtrl.h"
#include "Port.h"
#include "Dio.h"
#include "Gpt.h"
#include "Exti.h"

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/
uint8 onTime = 4;
uint8 offTime = 4;

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void setup(void);
void flip(void);
void GetOnOffPeriods(void);

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

int main()
{
	// Initializations
	setup();
	// pass callback to timer1
	Gpt_EnableNotification(Gpt_Timer1, flip);
	// start counting the timer with the offtime period
	Gpt_StartTimer(Gpt_Timer1, offTime);
	// Enable Channels PF0, PF4 to cause an external interrupt and passing callbacks
	Exti_InterruptsIn(Exti_PF0, Exti_RisingEdgeTrigger, GetOnOffPeriods);
	Exti_InterruptsIn(Exti_PF4, Exti_RisingEdgeTrigger, GetOnOffPeriods);

	while (1)
	{
	}
}
/******************************************************************************
 * \Syntax          : void setup(void);
 * \Description     : this functoin is called to set all predefined system configurations
 *
 * \Sync\Async      : Synchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void setup(void)
{
	// configure the NVIC module to enable requred interrupts and set priorities
	IntCrtl_Init();
	// configure clock gating for required peripherals
	SysCtrl_Init();
	// Unlock PF0 to use the switch attached to it
	GPIOF->GPIOLOCK = 0x4C4F434B;
	while (GPIOF->GPIOLOCK)
	{
	}
	GPIOF->GPIOCR |= 1 << 0;
	// Configure the GPIO channels directions, internal attachement, 
	//alternative functions and driving current
	Port_Init();
	// Configure Timers
	Gpt_Init();
}
/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/

/******************************************************************************
 * \Syntax          : void GetOnOffTimes(void)
 * \Description     : the external interrupt callback to get the on and off periods
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void GetOnOffPeriods(void)
{
	static uint32 flag = 0;
	static uint8 clicks = 0;

	// check the interrupt source
	if (((GPIOF->GPIOMIS & (1 << 4)) >> 4) == 1)
	{
		GPIOF->GPIOICR |= 1 << 4; // clear interrupt status flag
		clicks++;				  // the number of clicks
	}
	else if (((GPIOF->GPIOMIS & (1 << 0)) >> 0) == 1)
	{
		GPIOF->GPIOICR |= 1 << 0; // clear interrupt status flag
		if ((flag % 2) == 0)	  // for even number of clicks
		{
			onTime = clicks; // update onTime period with number of clicks
		}
		else // for even number of clicks
		{
			offTime = clicks; // for even number of clicks
		}

		flag++;
		clicks = 0;
	}
}
/******************************************************************************
 * \Syntax          : void flip(void)
 * \Description     : Timer1 callback to control output signal with the on and off periods
 *
 * \Sync\Async      : Asynchronous
 * \Reentrancy      : Non Reentrant
 * \Parameters (in) : None
 * \Parameters (out): None
 * \Return value:   : None
 *******************************************************************************/
void flip(void)
{
	static uint8 flag = 0;
	if ((flag % 2) == 0)
	{
		Dio_FlipChannel(Dio_PF2);
		Gpt_StartTimer(Gpt_Timer1, onTime);
		flag++;
	}
	else
	{
		Dio_FlipChannel(Dio_PF2);
		Gpt_StartTimer(Gpt_Timer1, offTime);
		flag++;
	}
}

/**********************************************************************************************************************
 *  END OF FILE: FileName.c
 *********************************************************************************************************************/
