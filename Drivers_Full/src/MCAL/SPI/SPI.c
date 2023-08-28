/*
 * SPI.c
 *
 *  Created on: Aug 28, 2023
 *      Author: yusuf
 */

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_TYPES.h"
#include "SPI_config.h"
#include "SPI_interface.h"
#include "SPI_private.h"

/**
 * Initialize the SPI1 peripheral.
 */
void SPI1_voidInit() {
    /* Disable SPI1 */
    CLEAR_BIT(SPI1->SPI_CR1, SPE_BIT);

    /* Configure Baud Rate Control (BR) for 256KHz
     * Use fpclk/64 as clock source (101)
     */
    SPI1->SPI_CR1 &= ~(0b111 << BR_StartBIT);
    SPI1->SPI_CR1 |= (BRControl_Value << BR_StartBIT);

    /* MAster or slave selection */
#if MSTR_BIT == MSTR
    SET_BIT(SPI1->SPI_CR1, MSTR_BIT); /* Enable Master mode */
#elif MSTR_BIT == SLV
    CLEAR_BIT(SPI1->SPI_CR1, MSTR_BIT); /* Disable Master mode */
#else
    #error "Invalid SPI mode selected"
#endif

    /* Configure clock phase (CPHA) and clock polarity (CPOL) */
#if SPI_MODE == 0
    	/* In this mode, data is sampled on the leading edge of the clock signal, and the clock signal is low when idle. */
        CLEAR_BIT(SPI1->SPI_CR1, CHPA_BIT);
        CLEAR_BIT(SPI1->SPI_CR1, CPOL_BIT);
#elif SPI_MODE == 1
    /* In this mode, data is sampled on the trailing edge of the clock signal, and the clock signal is low when idle. */
        SET_BIT(SPI1->SPI_CR1, CHPA_BIT);
		CLEAR_BIT(SPI1->SPI_CR1, CPOL_BIT);
#elif SPI_MODE == 2
    /* In this mode, data is sampled on the leading edge of the clock signal, and the clock signal is high when idle. */
		CLEAR_BIT(SPI1->SPI_CR1, CHPA_BIT);
		SET_BIT(SPI1->SPI_CR1, CPOL_BIT);
#elif SPI_MODE == 3
    /* In this mode, data is sampled on the trailing edge of the clock signal, and the clock signal is high when idle */
		SET_BIT(SPI1->SPI_CR1, CHPA_BIT);
		SET_BIT(SPI1->SPI_CR1, CPOL_BIT);
#else
    #error "Invalid SPI mode selected"
#endif

	    /* Configure frame format: LSB first or MSB */
#if LSB_FIRST == MSB
    /* Configure frame format: MSB first */
    CLEAR_BIT(SPI1->SPI_CR1, LSB_FIRST_BIT);
#elif  LSB_FIRST == LSB
    /* Configure frame format: LSB first */
    SET_BIT(SPI1->SPI_CR1, LSB_FIRST_BIT);
#else
    #error "Invalid frame format"
#endif

    /* Configure Data format: 8 or 16 */
#if DATA_FRAME_BITS == DATA_FRAME_8BIT
    /* Configure data frame format: 8-bit */
    CLEAR_BIT(SPI1->SPI_CR1, DFF_BIT);
#elif DATA_FRAME_BITS == DATA_FRAME_16BIT
    /* Configure data frame format: 16-bit */
    SET_BIT(SPI1->SPI_CR1, DFF_BIT);
#else
    #error "Invalid Data format"
#endif

    /* Enable SPI1 */
    SET_BIT(SPI1->SPI_CR1, SPE_BIT);
}

/**
 * Transmit data via SPI1.
 *
 * @param Copy_Data The data to be transmitted.
 */
void SPI_voidTransmit(u32 Copy_Data) {
    while (GET_BIT(SPI1->SPI_SR, 1)); /* Wait until TXE flag is set (transmit buffer empty) */
    SPI1->SPI_DR = Copy_Data;         /* Write data to SPI_DR to initiate transmission */
}

/**
 * Receive data via SPI1.
 *
 * @return The received data.
 */
u32 SPI_voidReceive(void) {
    while (GET_BIT(SPI1->SPI_SR, 0)); /* Wait until RXNE flag is set (receive buffer not empty) */
    return SPI1->SPI_DR;              /* Read received data from SPI_DR */
}

/**
 * Enable the SPI peripheral.
 */
void SPI_voidEnable() {
    SET_BIT(SPI1->SPI_CR1, SPE_BIT); // Set the enable bit to enable the SPI
}

/**
 * Disable the SPI peripheral.
 */
void SPI_voidDisable() {
    CLEAR_BIT(SPI1->SPI_CR1, SPE_BIT); // Clear the enable bit to disable the SPI
}

/**
 * Enable Interrupt of the SPI peripheral.
 */
void SPI_voidInterruptEnable(){
	SET_BIT(SPI1->SPI1_CR2, TXEIE_BIT);
}

/**
 * Disable Interrupt of the SPI peripheral.
 */
void SPI_voidInterruptDisanle(){
	SET_BIT(SPI1->SPI1_CR2, RXNEIE_BIT);
}
