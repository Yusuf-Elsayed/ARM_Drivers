# SPI Driver for STM32F401CCU6

This repository contains an implementation of a driver for the Serial Peripheral Interface (SPI) module for the STM32F401CCU6 microcontroller. SPI is a synchronous serial communication protocol commonly used to interface microcontrollers with peripheral devices such as sensors, displays, and memory chips. The driver provides functions to configure and manage the SPI module, perform data transmission and reception, and enable/disable interrupts.

## Microcontroller Details

The driver is specifically developed for the ARM-based STM32F401CCU6 microcontroller, which is part of the STM32F4 family by STMicroelectronics. The STM32F401CCU6 features an ARM Cortex-M4 core, offering a balance between performance and power efficiency.

## Features

- Initialize the SPI module with configurable parameters.
- Transmit data via SPI with optional interrupt-based operation.
- Receive data via SPI with optional interrupt-based operation.
- Enable and disable the SPI module.
- Configure clock polarity, clock phase, frame format, and data frame size.
- Support for both master and slave modes.
- Support for various interrupt configurations.

## Usage

To use the SPI driver in your STM32F401CCU6 project, follow these steps:

1. Clone or download this repository to your project directory.

2. Include the necessary header files in your project's source code:

```c
#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"
```

3. Configure the SPI module by editing the `SPI_config.h` file. Adjust settings such as the SPI mode, clock polarity, clock phase, and data frame size.

4. Initialize the SPI module by calling `SPI1_voidInit` in your main code:

```c
SPI1_voidInit();
```

5. Transmit and receive data using the `SPI_voidTransmit` and `SPI_voidReceive` functions.

6. Optionally, enable interrupts and configure interrupt behavior using functions like `SPI_voidInterruptEnable` and `SPI_voidInterruptDisanle`.

7. Use the provided functions to enable and disable the SPI module as needed.

## Configuration

The `SPI_config.h` file allows you to configure various settings for the SPI module according to your project's requirements.

## Author

This SPI driver was developed by [Yusuf-Elsayed](https://github.com/Yusuf-Elsayed).

---
