/*
 * Lab 05.c
 *
 * Created: 4/7/2024 10:50:32 PM
 * Author : jessi
 */ 

#define F_CPU 16000000UL
#define BAUD_RATE 9600
#define BAUD_PRESCALER (((F_CPU / (BAUD_RATE * 16UL))) - 1)

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include <util/delay.h>
#include "FreeRTOS.h"
#include "task.h"
#include "uart.h"


//#include "FreeRTOSBoardDefs.h"
//#include "croutine.h"
//#include "event_groups.h"
//#include "FreeRTOS.h"
//#include "FreeRTOSConfig.h"
//#include "list.h"
//#include "message_buffer.h"
//#include "mpu_wrappers.h"
//#include "portable.h"
//#include "portmacro.h"
//#include "projdefs.h"
//#include "queue.h"
//#include "stack_macros.h"
//#include "stream_buffer.h"
//#include "tasks.h"
//#include "timers.h"



char String[25];

void Initialize()
{
	
	DDRB &= ~(1 << DDB0);	 // Set PB0 as an output	
	DDRB &= ~(1 << DDB1);	 // Set PB0 as an output	
	DDRB &= ~(1 << DDB2);	 // Set PB0 as an output	
}



void vTaskA(void *pvParameters) {
	while (1) {
		PORTB |= (1 << DDB0);   // Turn on LED A
		vTaskDelay(150 / portTICK_PERIOD_MS);
		PORTB &= ~(1 << DDB0);  // Turn off LED A
		vTaskDelay((750 - 150) / portTICK_PERIOD_MS);
	}
		
		sprintf(String,"wtf");
		UART_putstring(String);
	
}

void vTaskB(void *pvParameters) {
	while (1) {
		PORTB |= (1 << DDB1);   // Turn on LED B
		vTaskDelay(300 / portTICK_PERIOD_MS);
		PORTB &= ~(1 << DDB1);  // Turn off LED B
		vTaskDelay((1200 - 300) / portTICK_PERIOD_MS);
	}
	
}

void vTaskC(void *pvParameters) {
		while (1)
		{
			PORTB |= (1 << DDB2);   // Turn on LED C
			vTaskDelay(450 / portTICK_PERIOD_MS);
			PORTB &= ~(1 << DDB2);  // Turn off LED C
			vTaskDelay((1500 - 450) / portTICK_PERIOD_MS);

		}	
}


int main(void)
{
	UART_init(BAUD_PRESCALER);
	
	Initialize();
	
	 // Create tasks
	 xTaskCreate(vTaskA, "Task A", 256, NULL, 3, NULL);
	 xTaskCreate(vTaskB, "Task B", 256, NULL, 2, NULL);
	 xTaskCreate(vTaskC, "Task C", 256, NULL, 1, NULL);

	 // Start the scheduler
	 vTaskStartScheduler();

	 // Will only get here if there was insufficient memory to create the idle task.
	 return 0;
	 
	//while(1)
	//{
		//sprintf(String,"can this even work", 2020);
		//UART_putstring(String);
		//_delay_ms(1000);
	//}
}

