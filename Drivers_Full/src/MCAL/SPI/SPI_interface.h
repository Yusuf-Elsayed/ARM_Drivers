/*
 * SPI_interface.h
 *
 *  Created on: Aug 28, 2023
 *      Author: yusuf
 */

#ifndef MCAL_SPI_SPI_INTERFACE_H_
#define MCAL_SPI_SPI_INTERFACE_H_

/**
 * Initialize the SPI.
 */
void SPI1_voidInit();

/**
 * Transmit data via SPI.
 *
 * @param Copy_Data The data to be transmitted.
 */
void SPI_voidTransmit(u32 Copy_Data);

/**
 * Receive data via SPI.
 *
 * @return The received data.
 */
u32 SPI_voidRecieve(void);

/**
 * Enable the SPI peripheral.
 */
void SPI_voidEnable();

/**
 * Disable the SPI peripheral.
 */
void SPI_voidDisanle();

/**
 * Enable Interrupt of the SPI peripheral.
 */
void SPI_voidInterruptEnable();

/**
 * Disable Interrupt of the SPI peripheral.
 */
void SPI_voidInterruptDisanle();

#endif /* MCAL_SPI_SPI_INTERFACE_H_ */
