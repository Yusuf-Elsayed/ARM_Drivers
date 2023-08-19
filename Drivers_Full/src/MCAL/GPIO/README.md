# GPIO Driver for STM32F401CCU6

This repository contains an implementation of a GPIO (General-Purpose Input/Output) driver for the STM32F401CCU6 microcontroller, which is a member of the STM32F4 family by STMicroelectronics. The driver provides functions to configure and control GPIO pins, allowing you to easily set pin modes, output types, output speeds, pull-up/pull-down resistors, and more.

## Microcontroller Details

The driver is developed explicitly for the ARM-based STM32F401CCU6 microcontroller, which features a powerful ARM Cortex-M4 core, offering an optimal balance between performance and power efficiency.

## Features

- Configure GPIO pin modes (Input, Output, Alternate Function).
- Set GPIO pin output types (Push-Pull, Open-Drain).
- Configure GPIO pin output speeds (Low, Medium, High, Very High).
- Set GPIO pin pull-up/pull-down resistors.
- Get the value of an input GPIO pin.
- Set the value of an output GPIO pin.
- Set or reset the value of an output GPIO pin using the bit set/reset register.
- Enable alternate function mode for a GPIO pin.

## Usage

To use the GPIO driver in your STM32F401CCU6 project, follow these steps:

1. Clone or download this repository to your project directory.

2. Include the necessary header files in your project's source code:

```c
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_config.h"
```

3. Use the provided functions to configure and control GPIO pins as needed:

```c
// Configure GPIO pin PA5 as an output pin
GPIO_voidConfigPinMode(GPIO_u8PortA, 5, GPIO_OutputMode);

// Set GPIO pin PB0 to high
GPIO_voidSetPinValue(GPIO_u8PortB, 0);

// Configure GPIO pin PC13 with a pull-up resistor
GPIO_voidConfigPullType(GPIO_u8PortC, 13, GPIO_PullUp);
```

4. Refer to the comments in the header files (`GPIO_Interface.h`, `GPIO_Private.h`, `GPIO_config.h`) for detailed explanations of each function and its parameters.

## Configuration

The `GPIO_config.h` file provides a space for any custom configuration options you might need in your STM32F401CCU6 project.

## Author

This GPIO driver was developed by [Yusuf-Elsayed](https://github.com/Yusuf-Elsayed).

---


