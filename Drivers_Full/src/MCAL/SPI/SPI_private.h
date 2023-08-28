/*
 * SPI_private.h
 *
 *  Created on: Aug 28, 2023
 *      Author: yusuf
 */

#ifndef MCAL_SPI_SPI_PRIVATE_H_
#define MCAL_SPI_SPI_PRIVATE_H_

/* Base addresses for different SPI peripherals */
#define SPI1_BASE_ADDRESS   0x40013000
#define SPI2_BASE_ADDRESS   0x40003800
#define SPI3_BASE_ADDRESS   0x40003C00
#define SPI4_BASE_ADDRESS   0x40013400

/* Structure representing the layout of an SPI peripheral's registers */
typedef struct {
    volatile u32 SPI_CR1;       /* Control Register 1 */
    volatile u32 SPI1_CR2;      /* Reserved space */
    volatile u32 SPI_SR;        /* Status Register */
    volatile u32 SPI_DR;        /* Data Register */
    volatile u32 SPI_CRCPR;     /* CRC Polynomial Register */
    volatile u32 SPI_RXCRCR;    /* RX CRC Register */
    volatile u32 SPI_TXCRCR;    /* TX CRC Register */
    volatile u32 SPI_I2SCFGR;   /* I2S Configuration Register */
    volatile u32 SPI_I2SPR;     /* I2S Prescaler Register */
} SPI_t;

/* Define SPI1 as a pointer to SPI_t at SPI1's base address */
#define SPI1 ((volatile SPI_t*) SPI1_BASE_ADDRESS)

/* Bit positions in SPI_CR1 */
#define CHPA_BIT      0
#define CPOL_BIT      1
#define BR_StartBIT   3
#define SPE_BIT       6
#define LSB_FIRST_BIT 7
#define DFF_BIT       11

/* Baud rate control selection values */
#define fPCLK_DIV2   0b000
#define fPCLK_DIV4   0b001
#define fPCLK_DIV8   0b010
#define fPCLK_DIV16  0b011
#define fPCLK_DIV32  0b100
#define fPCLK_DIV64  0b101
#define fPCLK_DIV128 0b110
#define fPCLK_DIV256 0b111

/* Least Significant Bit (LSB) and Most Significant Bit (MSB) options */
#define MSB 0
#define LSB 1

/* Data frame format options */
#define DATA_FRAME_8BIT  0
#define DATA_FRAME_16BIT 1

/* Define constants for enabling (EN) and disabling (DIS) */
#define DIS 0  /* Constant representing the "disable" state */
#define EN  1  /* Constant representing the "enable" state */

/* Define bit positions for interrupt enable flags */
#define RXNEIE_BIT 6 /* Bit position for RX buffer not empty interrupt enable */
#define TXEIE_BIT 7  /* Bit position for TX buffer empty interrupt enable */

/* Define SPI modes */
#define MODE0 0 /* SPI mode 0 */
#define MODE1 1 /* SPI mode 1 */
#define MODE2 2 /* SPI mode 2 */
#define MODE3 3 /* SPI mode 3 */

/* Define constants for SPI modes */
#define MSTR 1 /* Master mode */
#define SLV  0 /* Slave mode */




#endif /* MCAL_SPI_SPI_PRIVATE_H_ */
