# System Timer (SYSTICK) Driver for STM32F401CCU6

This repository contains an implementation of a driver for the System Timer (SYSTICK) module in the STM32F401CCU6 microcontroller. The SYSTICK module is used for generating time delays, measuring time intervals, and implementing periodic tasks.

## Microcontroller Details

The driver is developed specifically for the ARM-based STM32F401CCU6 microcontroller, which belongs to the STM32F4 family by STMicroelectronics. This microcontroller features an ARM Cortex-M4 core, providing a balance between performance and power efficiency.

## Features

- Initialize the SYSTICK timer with a specified clock source.
- Enable or disable the SYSTICK interrupt based on configuration.
- Start the SYSTICK timer with a specified preload value.
- Get the elapsed time since the SYSTICK timer started.
- Get the remaining time for the SYSTICK timer to reach zero.
- Read the SYSTICK count flag in the Control and Status Register (CTRL).
- Implement delays in milliseconds and microseconds using the SYSTICK timer.
- Set a callback function to be executed when the SYSTICK interrupt occurs.

## Usage

To use the SYSTICK driver in your STM32F401CCU6 project, follow these steps:

1. Clone or download this repository to your project directory.

2. Include the necessary header files in your project's source code:

```c
#include "SYSTIC_interface.h"
#include "SYSTIC_private.h"
```

3. Initialize the SYSTICK module and configure interrupt settings:

```c
STK_voidInit();
STK_voidIntEnableDisable();  // Enable or disable SYSTICK interrupt
```

4. Utilize the driver functions for your application needs:

```c
STK_voidStart(preloadValue);  // Start the SYSTICK timer with a preload value
u32 elapsedTime = STK_u32GetElapsedTime();  // Get elapsed time since start
u32 remainingTime = STK_u32GetRemainingTime();  // Get remaining time
STK_voidDelayMS(delayInMilliseconds);  // Implement delay in milliseconds
STK_voidSetCallBack(callbackFunction);  // Set a callback for SYSTICK interrupt
```

5. Customize configuration options in the `SYSTK_config.h` file if needed.

## Configuration

The `SYSTK_config.h` file provides configuration options such as clock source and interrupt settings.

## Author

This SYSTICK driver was developed by [Yusuf-Elsayed](https://github.com/Yusuf-Elsayed).

---
