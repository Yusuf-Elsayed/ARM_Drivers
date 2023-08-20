# Real-Time Operating System (RTOS) Application for STM32F401CCU6 Black Pill

This repository contains a simple example of a multitasking system using a Real-Time Operating System (RTOS) on the STM32F401CCU6 microcontroller. The system manages multiple LED tasks, where each LED task toggles the state of an LED with a specific periodicity. The tasks are executed by the RTOS scheduler, providing time-sharing and synchronization.

## Microcontroller Details

The application is developed for the ARM-based STM32F401CCU6 microcontroller. The STM32F401CCU6 belongs to the STM32F4 family by STMicroelectronics and features an ARM Cortex-M4 core, providing a balance between performance and power efficiency.

## Features

- Demonstrates task scheduling and synchronization in an RTOS environment.
- Uses GPIO control for LED manipulation.
- Implements a simple RTOS with LED tasks running at various periodicities.
- Demonstrates configuring GPIO pins, creating tasks, and starting the RTOS scheduler.
## Video Demonstration

Check out this [video demonstration](https://github.com/Yusuf-Elsayed/ARM_Drivers/blob/main/Drivers_Full/src/APP/OS_App.mp4) to see the application in action!

## Usage

To use this RTOS application on your STM32F401CCU6 Black Pill, follow these steps:

1. Clone or download this repository to your project directory.

2. Include the necessary header files in your project's source code:

```c
#include "../LIB/BIT_MATHS.h"
#include "../LIB/STD_TYPES.h"
#include "../MCAL/RTOS/RTOS_INTERFACE.h"
#include "../MCAL/GPIO/GPIO_Interface.h"
#include "../MCAL/RCC/RCC_Interface.h"
#include "../MCAL/SYSTK/SYSTK_interface.h"
```

3. Configure the LED GPIO pins and create LED tasks in your `main` function:

```c
#define LED1 0
#define LED2 1
// ... Define other LED pins similarly

// Create LED tasks with different periodicities
RTOS_u8CreateTask(Led1_Task, 100, 0, 0);  // LED1 task with 100 ms periodicity
RTOS_u8CreateTask(Led2_Task, 150, 1, 0);  // LED2 task with 150 ms periodicity
// ... Create tasks for other LEDs
```

4. Build and flash the code onto your STM32F401CCU6 microcontroller.

## Notes

- This code serves as an educational example and may require adjustments for different platforms or RTOSs.
- Make sure to configure the GPIO pins, RTOS tasks, and other settings according to your platform.

## Author

This RTOS application was developed by [Yusuf-Elsayed](https://github.com/Yusuf-Elsayed).

---
