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



// Function to create a busy loop for the specified duration in milliseconds
void busyWait(uint32_t duration_ms1) {
	volatile uint32_t i, j;
	for (i = 0; i < duration_ms1; i++) {
		
	}
}

void vTaskA(void *pvParameters) {
	volatile uint32_t i;
	//TickType_t xLastWakeTime = xTaskGetTickCount();
	for (;;) {
		PORTB |= (1 << DDB0);   // Turn on LED A
		vTaskSuspendAll();           // Block other tasks
		vTaskResume(vTaskA);
		
		//busyWait(220000);               // Busy wait for 150ms
		for (i = 0; i < 220000; i++) {
		
	}
		PORTB &= ~(1 << DDB0);		
		xTaskResumeAll();            // Unblock other tasks
		//vTaskDelayUntil(&xLastWakeTime, 750 / portTICK_PERIOD_MS);
		vTaskDelay(pdMS_TO_TICKS(600));
	}
}

void vTaskB(void *pvParameters) {
		volatile uint32_t i;

	//TickType_t xLastWakeTime = xTaskGetTickCount();
	for (;;) {
		PORTB |= (1 << DDB1);
		vTaskSuspendAll();
		vTaskResume(vTaskB);
		
		//busyWait(500000);
		for (i = 0; i < 500000; i++) {
		
	}
		PORTB &= ~(1 << DDB1);
		xTaskResumeAll();
		//vTaskDelayUntil(&xLastWakeTime, 1200 / portTICK_PERIOD_MS);
		vTaskDelay(pdMS_TO_TICKS(900));

	}
}

void vTaskC(void *pvParameters) {
	volatile uint32_t i;

	//TickType_t xLastWakeTime = xTaskGetTickCount();
	for (;;) {
		PORTB |= (1 << DDB2);
		vTaskSuspendAll();
		vTaskResume(vTaskC);
		
		//busyWait(650000);              // Changed CPU time to 1400ms
		for (i = 0; i < 650000; i++) {
		
	}
		PORTB &= ~(1 << DDB2);
		xTaskResumeAll();
		//vTaskDelayUntil(&xLastWakeTime, 1500 / portTICK_PERIOD_MS);
		vTaskDelay(pdMS_TO_TICKS(1050));

	}
}

int main(void) {
	
	UART_init(BAUD_PRESCALER);
	
	Initialize();

	// Create tasks with a stack depth of 256
	xTaskCreate(vTaskA, "Task A", 256, NULL, 3, NULL);
	xTaskCreate(vTaskB, "Task B", 256, NULL, 2, NULL);
	xTaskCreate(vTaskC, "Task C", 256, NULL, 1, NULL);

	// Start the scheduler
	vTaskStartScheduler();

	return 0;
}

