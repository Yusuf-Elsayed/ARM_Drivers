/*
 * SPI_config.h
 *
 *  Created on: Aug 28, 2023
 *      Author: yusuf
 */

#ifndef MCAL_SPI_SPI_CONFIG_H_
#define MCAL_SPI_SPI_CONFIG_H_

/*
 * MSTR_BIT
 * options: MSTR
 *          SLV
 */
#define MSTR_BIT MSTR

/* BR control selection
 * BR[2:0]: Baud rate control
 * fPCLK_DIV2
 * fPCLK_DIV4
 * fPCLK_DIV8
 * fPCLK_DIV16
 * fPCLK_DIV32
 * fPCLK_DIV64
 * fPCLK_DIV128
 * fPCLK_DIV256
 */
#define BRControl_Value fPCLK_DIV64

/*
 * LSB_FIRST
 * options: MSB
 *          LSB
 */
#define LSB_FIRST MSB

/*
 * DATA_FRAME_BITS
 * options: DATA_FRAME_8BIT
 *          DATA_FRAME_16BIT
 */
#define DATA_FRAME_BITS DATA_FRAME_8BIT

/* Bit 7 TXEIE: Tx buffer empty interrupt enable
 * DIS: TXE interrupt masked
 * EN: TXE interrupt not masked. Used to generate an interrupt request when the TXE flag is set.
*/
#define TXEIE DIS
/*
 * Bit 6 RXNEIE: RX buffer not empty interrupt enable
 * DIS: RXNE interrupt masked
 * EN: RXNE interrupt not masked. Used to generate an interrupt request when the RXNE flag is set.
 */
#define RXNE DIS
 /*
  * modes of SPI
  * options: 	MODE0
  * 			MODE1
  * 			MODE2
  * 			MODE3
  */
#define SPI_MODE MODE0

#endif /* MCAL_SPI_SPI_CONFIG_H_ */
