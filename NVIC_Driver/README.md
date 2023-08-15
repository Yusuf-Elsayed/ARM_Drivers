# Nested Vector Interrupt Controller (NVIC) Driver for STM32F401CCU6

This repository contains an implementation of a driver for the Nested Vector Interrupt Controller (NVIC) module, which is a crucial component of ARM Cortex-M processors for handling interrupts. The driver provides functions to configure and manage interrupts, set priorities, and handle interrupt states.

## Microcontroller Details

The driver is developed explicitly for the ARM-based STM32F401CCU6 microcontroller, which belongs to the STM32F4 family by STMicroelectronics. This microcontroller features a powerful ARM Cortex-M4 core, offering an optimal balance between performance and power efficiency.

## Features

- Enable and disable interrupts.
- Set and clear pending states for interrupts.
- Check if an interrupt is currently active.
- Configure interrupt priority levels.
- Support for multiple group and subgroup priority configurations.

## Usage

To use the NVIC driver in your STM32F401CCU6 project, follow these steps:

1. Clone or download this repository to your project directory.

2. Include the necessary header files in your project's source code:

```c
#include "NVIC_Interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"
```

3. Configure the interrupt group mode by calling `NVIC_voidSetGroupMode` with the desired configuration (e.g., `NVIC_4G_4SG`):

```c
NVIC_voidSetGroupMode(NVIC_4G_4SG);
```

4. Configure interrupt priorities using `NVIC_voidSetInterruptPriority`:

```c
// Configure interrupt with ID 20 (e.g., Timer1) with group priority 2 and subgroup priority 1
NVIC_voidSetInterruptPriority(20, 2, 1);
```

5. Enable or disable specific interrupts using `NVIC_voidInterruptSetEnable` and `NVIC_voidInterruptClearEnable`:

```c
// Enable interrupt with ID 20 (e.g., Timer1)
NVIC_voidInterruptSetEnable(20);

// Disable interrupt with ID 18 (e.g., ADC)
NVIC_voidInterruptClearEnable(18);
```

6. Use other functions like `NVIC_voidSetPending`, `NVIC_voidClearPending`, and `NVIC_voidGetActiveBit` as needed for managing interrupt states.

## Configuration

The `NVIC_config.h` file provides a space for any custom configuration options you might need in your STM32F401CCU6 project.

## Author

This NVIC driver was developed by [Yusuf-Elsayed](https://github.com/Yusuf-Elsayed).

---

Feel free to modify the above text to suit your project's specific details and conventions.
