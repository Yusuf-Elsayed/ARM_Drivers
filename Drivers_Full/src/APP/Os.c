/*
 * Os.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Yusuf-Elsayed
 *
 *  Description:
 *  This file implements a simple example of a multitasking system using a Real-Time Operating System (RTOS).
 *  The system manages multiple LED tasks, where each LED task toggles the state of an LED with a specific
 *  periodicity. The tasks are executed by the RTOS scheduler, providing time-sharing and synchronization.
 *
 *  The main purpose of this code is to demonstrate task scheduling and synchronization in an RTOS environment
 *  using GPIO control for LED manipulation.
 *
 *  This code initializes the system, configures GPIO pins for LEDs, creates LED tasks, and starts the RTOS
 *  scheduler to manage task execution.
 *
 *  Note: This code serves as an educational example and may need adaptation for different platforms or RTOSs.
 */


#include "../LIB/BIT_MATHS.h"
#include "../LIB/STD_TYPES.h"

#include "../MCAL/RTOS/RTOS_INTERFACE.h"
#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/RCC/RCC_Interface.h"
#include "../MCAL/SYSTK/SYSTK_interface.h"
#include "../MCAL/GPIO/GPIO_Interface.h"

/* Define LED GPIO pins */
#define LED1 0
#define LED2 1
#define LED3 2
#define LED4 3
#define LED5 4
#define LED6 5
#define LED7 6
#define LED8 7

/* Led1_Task: Toggles the state of LED1.
 * This task is executed periodically with a 100 ms interval.
 */
void Led1_Task(void) {
    /* Replace with actual GPIO control function */
    /* Example: GPIO_TogglePin(LED1_PIN); */
    GPIO_voidchangePinoutvalue(GPIO_u8PortA, LED1, GPIO_TGLPin);
}

/* Led2_Task: Toggles the state of LED2.
 * This task is executed periodically with a 150 ms interval.
 */
void Led2_Task(void) {
    /* Replace with actual GPIO control function */
    /* Example: GPIO_TogglePin(LED2_PIN); */
    GPIO_voidchangePinoutvalue(GPIO_u8PortA, LED2, GPIO_TGLPin);
}

/* Led3_Task: Toggles the state of LED3.
 * This task is executed periodically with a 200 ms interval.
 */
void Led3_Task(void) {
    /* Replace with actual GPIO control function */
    /* Example: GPIO_TogglePin(LED3_PIN); */
    GPIO_voidchangePinoutvalue(GPIO_u8PortA, LED3, GPIO_TGLPin);
}

/* Led4_Task: Toggles the state of LED4.
 * This task is executed periodically with a 240 ms interval.
 */
void Led4_Task(void) {
    /* Replace with actual GPIO control function */
    /* Example: GPIO_TogglePin(LED4_PIN); */
    GPIO_voidchangePinoutvalue(GPIO_u8PortA, LED4, GPIO_TGLPin);
}

/* Led5_Task: Toggles the state of LED5.
 * This task is executed periodically with a 250 ms interval.
 */
void Led5_Task(void) {
    /* Replace with actual GPIO control function */
    /* Example: GPIO_TogglePin(LED5_PIN); */
    GPIO_voidchangePinoutvalue(GPIO_u8PortA, LED5, GPIO_TGLPin);
}

/* Led6_Task: Toggles the state of LED6.
 * This task is executed periodically with a 320 ms interval.
 */
void Led6_Task(void) {
    /* Replace with actual GPIO control function */
    /* Example: GPIO_TogglePin(LED6_PIN); */
    GPIO_voidchangePinoutvalue(GPIO_u8PortA, LED6, GPIO_TGLPin);
}

/* Led7_Task: Toggles the state of LED7.
 * This task is executed periodically with a 460 ms interval.
 */
void Led7_Task(void) {
    /* Replace with actual GPIO control function */
    /* Example: GPIO_TogglePin(LED7_PIN); */
    GPIO_voidchangePinoutvalue(GPIO_u8PortA, LED7, GPIO_TGLPin);
}

/* Led8_Task: Toggles the state of LED8.
 * This task is executed periodically with a 540 ms interval.
 */
void Led8_Task(void) {
    /* Replace with actual GPIO control function */
    /* Example: GPIO_TogglePin(LED8_PIN); */
    GPIO_voidchangePinoutvalue(GPIO_u8PortA, LED8, GPIO_TGLPin);
}

/* Define similar tasks for the other LEDs (Led9_Task, Led10_Task, ...) */

int main(void) {
    RCC_voidInit();
    RCC_voidEnablePeripheral(RCC_u8_AHB1ENR_GPIOA, RCC_u8_AHB1_BUS);

    for (int i = 0; i < 8; ++i) {
        GPIO_voidConfigPinMode(GPIO_u8PortA, i, GPIO_OutputMode);
        GPIO_voidConfigOutputType(GPIO_u8PortA, i, GPIO_OutputPush_Pull);
    }

    /* Initialize the OS and create LED tasks */
    RTOS_u8CreateTask(Led1_Task, 100, 0, 0);  /* LED1 task with 100 ms periodicity */
    RTOS_u8CreateTask(Led2_Task, 150, 1, 0);  /* LED2 task with 150 ms periodicity */
    RTOS_u8CreateTask(Led3_Task, 200, 2, 0);  /* LED3 task with 200 ms periodicity */
    RTOS_u8CreateTask(Led4_Task, 240, 3, 0);  /* LED4 task with 240 ms periodicity */
    RTOS_u8CreateTask(Led5_Task, 250, 4, 0);  /* LED5 task with 250 ms periodicity */
    RTOS_u8CreateTask(Led6_Task, 320, 5, 0);  /* LED6 task with 320 ms periodicity */
    RTOS_u8CreateTask(Led7_Task, 460, 6, 0);  /* LED7 task with 460 ms periodicity */
    RTOS_u8CreateTask(Led8_Task, 540, 7, 0);  /* LED8 task with 540 ms periodicity */

    /* Create similar tasks for the other LEDs (Led9_Task, Led10_Task, ...) */

    Start_OS();  /* Start the operating system scheduler */

    while (1) {
        /* Main application loop */
    }

    return 0;
}
