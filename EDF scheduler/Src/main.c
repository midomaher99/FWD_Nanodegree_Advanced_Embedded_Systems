/*
 * FreeRTOS Kernel V10.2.0
 * Copyright (C) 2019 Amazon.com, Inc. or its affiliates.  All Rights Reserved.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy of
 * this software and associated documentation files (the "Software"), to deal in
 * the Software without restriction, including without limitation the rights to
 * use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
 * the Software, and to permit persons to whom the Software is furnished to do so,
 * subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
 * FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
 * COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
 * IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
 * CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 *
 * http://www.FreeRTOS.org
 * http://aws.amazon.com/freertos
 *
 * 1 tab == 4 spaces!
 */

/* 
	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used.
*/


/*
 * Creates all the demo application tasks, then starts the scheduler.  The WEB
 * documentation provides more details of the demo application tasks.
 * 
 * Main.c also creates a task called "Check".  This only executes every three 
 * seconds but has the highest priority so is guaranteed to get processor time.  
 * Its main function is to check that all the other tasks are still operational.
 * Each task (other than the "flash" tasks) maintains a unique count that is 
 * incremented each time the task successfully completes its function.  Should 
 * any error occur within such a task the count is permanently halted.  The 
 * check task inspects the count of each task to ensure it has changed since
 * the last time the check task executed.  If all the count variables have 
 * changed all the tasks are still executing error free, and the check task
 * toggles the onboard LED.  Should any task contain an error at any time 
 * the LED toggle rate will change from 3 seconds to 500ms.
 *
 */

/* Standard includes. */
#include <stdlib.h>
#include <stdio.h>

/* Scheduler includes. */
#include "FreeRTOS.h"
#include "task.h"
#include "lpc21xx.h"

/* Peripheral includes. */
#include "serial.h"
#include "GPIO.h"
#include "semphr.h"

#include "fifo.h"


/*-----------------------------------------------------------*/

/* Constants to setup I/O and processor. */
#define mainBUS_CLK_FULL	( ( unsigned char ) 0x01 )

/* Constants for the ComTest demo application tasks. */
#define mainCOM_TEST_BAUD_RATE	( ( unsigned long ) 115200 )





/*
 * Configure the processor for use with the Keil demo board.  This is very
 * minimal as most of the setup is managed by the settings in the project
 * file.
 */
static void prvSetupHardware( void );
/*-----------------------------------------------------------*/
#define BUTTON_1_RISING_MESSAGE	"Button_1_Rising_Edge\n"
#define BUTTON_1_RISING_MESSAGE_length 21UL
#define BUTTON_1_FALLING_MESSAGE	"Button_1_Falling_Edge\n"
#define BUTTON_1_FALLING_MESSAGE_length 22UL
#define BUTTON_2_RISING_MESSAGE	"Button_2_Rising_Edge\n"
#define BUTTON_2_RISING_MESSAGE_length 21UL
#define BUTTON_2_FALLING_MESSAGE	"Button_2_Falling_Edge\n"
#define BUTTON_2_FALLING_MESSAGE_length 22UL
#define PERIODIC_TRANSMITTER_MESSAGE	"Periodic_Transmitter\n"
#define PERIODIC_TRANSMITTER_MESSAGE_length 21UL


#define BUTTON_1_PIN	PIN0
#define BUTTON_2_PIN	PIN1



TaskHandle_t 	Button_1_Monitor_Handle 		= NULL;
TaskHandle_t 	Button_2_Monitor_Handle 		= NULL;
TaskHandle_t	Periodic_Transmitter_Handle	= NULL;
TaskHandle_t 	Uart_Receiver_Handle				= NULL;

TaskHandle_t 	Load_1_Simulation_handle 		= NULL;
TaskHandle_t 	Load_2_Simulation_handle 		= NULL;




fifo_t messagesBuffer;
message_t messages[20];


void vApplicationTickHook()
{
	GPIO_write(PORT_0, PIN0, PIN_IS_HIGH);
	GPIO_write(PORT_0, PIN0, PIN_IS_LOW);
}


void Button_1_Monitor(void *pvParameter)
{ 
	TickType_t xLastWakeTime = xTaskGetTickCount();
	pinState_t Button_1_Previous_State = PIN_IS_LOW;
	pinState_t Button_1_Current_State = PIN_IS_LOW;
	message_t button1_message;
	for(;;)
	{
			Button_1_Current_State=GPIO_read(PORT_1, BUTTON_1_PIN);
			
			if(Button_1_Current_State!= Button_1_Previous_State )
			{
				if(Button_1_Current_State == PIN_IS_HIGH)
				{
					button1_message.message = BUTTON_1_RISING_MESSAGE;
					button1_message.messageLength = BUTTON_1_RISING_MESSAGE_length;
					fifo_push(&messagesBuffer,button1_message);
						//buttin1 rising
				}
				else
				{
						//add to queue
						//buttin1 falling
					button1_message.message = BUTTON_1_FALLING_MESSAGE;
					button1_message.messageLength = BUTTON_1_FALLING_MESSAGE_length;
					fifo_push(&messagesBuffer,button1_message);
				}
			}
			Button_1_Previous_State=Button_1_Current_State;
		vTaskDelayUntil(&xLastWakeTime,50);
	}

}


void Button_2_Monitor(void *pvParameter)
{ 
	TickType_t xLastWakeTime = xTaskGetTickCount();
	pinState_t Button_2_Previous_State = PIN_IS_LOW;
	pinState_t Button_2_Current_State = PIN_IS_LOW;
	
	message_t button2_message;
	for(;;)
	{
			Button_2_Current_State=GPIO_read(PORT_1, BUTTON_2_PIN);
			
			if(Button_2_Current_State!= Button_2_Previous_State )
			{
				if(Button_2_Current_State == PIN_IS_HIGH)
				{
					//buttin1 rising
					button2_message.message = BUTTON_2_RISING_MESSAGE;
					button2_message.messageLength = BUTTON_2_RISING_MESSAGE_length;
					fifo_push(&messagesBuffer,button2_message);
				}
				else
				{
						//add to queue
						//buttin1 falling
					button2_message.message = BUTTON_2_FALLING_MESSAGE;
					button2_message.messageLength = BUTTON_2_FALLING_MESSAGE_length;
					fifo_push(&messagesBuffer,button2_message);
				}
			}
			Button_2_Previous_State=Button_2_Current_State;

		vTaskDelayUntil(&xLastWakeTime,50);
	}
}


void Periodic_Transmitter(void *pvParameter)
{ 
	TickType_t xLastWakeTime = xTaskGetTickCount();
	message_t periodicTransmitter_message;
	periodicTransmitter_message.message =PERIODIC_TRANSMITTER_MESSAGE;
	periodicTransmitter_message.messageLength =PERIODIC_TRANSMITTER_MESSAGE_length;

	for(;;)
	{
			
			
			fifo_push(&messagesBuffer,periodicTransmitter_message);
		
			vTaskDelayUntil(&xLastWakeTime,100);

	}

}



void Uart_Receiver(void *pvParameter)
{ 
	TickType_t xLastWakeTime = xTaskGetTickCount();
	message_t temp;
	for(;;)
	{
			
			//add to queue
			//periodic 100
			if(fifo_get(&messagesBuffer,&temp) == fifo_succeded)
			{
				if (vSerialPutString(temp.message,temp.messageLength) == pdTRUE )
				{
					fifo_pop(&messagesBuffer,&temp);
				}
			}
		
		
			vTaskDelayUntil(&xLastWakeTime,20);

	}

}

void Load_1_Simulation(void *pvParameter)
{ 
	TickType_t xLastWakeTime = xTaskGetTickCount();
	int i;
	for(;;)
	{	
		for(i=0; i<36890;i++) //execute 5ms
		{}
			vTaskDelayUntil(&xLastWakeTime,10);
	}
}
void Load_2_Simulation(void *pvParameter)
{ 
	TickType_t xLastWakeTime = xTaskGetTickCount();
	int i;
	for(;;)
	{
		for(i=0; i<88536;i++) //execute 12ms
		{}	
			vTaskDelayUntil(&xLastWakeTime,100);
	}
}

/*
 * Application entry point:
 * Starts all the other tasks, then starts the scheduler. 
 */
int main( void )
 {

	/* Setup the hardware for use with the Keil demo board. */
	prvSetupHardware();
	
	 
	fifo_init(&messagesBuffer,messages,20);

    /* Create Tasks here */

		xTaskPeriodicCreate(Button_1_Monitor,
												"button1",
												50,
												(void*)0,
												2,
												&Button_1_Monitor_Handle,
												50);
		xTaskPeriodicCreate(Button_2_Monitor,
												"button2",
												50,
												(void*)0,
												1,
												&Button_2_Monitor_Handle,
												50);					
		xTaskPeriodicCreate(Periodic_Transmitter,
												"periodicTransmitter",
												50,
												(void*)0,
												1,
												&Periodic_Transmitter_Handle,
												100);					
		xTaskPeriodicCreate(Uart_Receiver,
												"Uart_Receiver",
												50,
												(void*)0,
												1,
												&Uart_Receiver_Handle,
												20);	
	xTaskPeriodicCreate(Load_1_Simulation, 
											"Load_1_Simulation",
											50,
											(void*)0,
											1,
											&Load_1_Simulation_handle,
											10);
	xTaskPeriodicCreate(Load_2_Simulation, 
											"Load_1_Simulation",
											50,
											(void*)0,
											1,
											&Load_2_Simulation_handle,
											100);
	/* Now all the tasks have been started - start the scheduler.

	NOTE : Tasks run in system mode and the scheduler runs in Supervisor mode.
	The processor MUST be in supervisor mode when vTaskStartScheduler is 
	called.  The demo applications included in the FreeRTOS.org download switch
	to supervisor mode prior to main being called.  If you are not using one of
	these demo application projects then ensure Supervisor mode is used here. */
	

	vTaskStartScheduler();
	/* Should never reach here!  If you do then there was not enough heap
	available for the idle task to be created. */
	for( ;; );
}
/*-----------------------------------------------------------*/

/* Function to reset timer 1 */
void timer1Reset(void)
{
	T1TCR |= 0x2;
	T1TCR &= ~0x2;
}

/* Function to initialize and start timer 1 */
static void configTimer1(void)
{
	T1PR = 1000;
	T1TCR |= 0x1;
}

static void prvSetupHardware( void )
{
	/* Perform the hardware setup required.  This is minimal as most of the
	setup is managed by the settings in the project file. */

	/* Configure UART */
	xSerialPortInitMinimal(mainCOM_TEST_BAUD_RATE);

	/* Configure GPIO */
	GPIO_init();
	
	/* Config trace timer 1 and read T1TC to get current tick */
	configTimer1();

	/* Setup the peripheral bus to be the same as the PLL output. */
	VPBDIV = mainBUS_CLK_FULL;
}


/*-----------------------------------------------------------*/

