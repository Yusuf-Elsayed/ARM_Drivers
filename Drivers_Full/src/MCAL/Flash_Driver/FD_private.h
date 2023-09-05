/*
 * FD_private.h
 *
 *  Created on: Sep 4, 2023
 *      Author: yusuf
 */

#ifndef MCAL_FLASH_DRIVER_FD_PRIVATE_H_
#define MCAL_FLASH_DRIVER_FD_PRIVATE_H_



typedef struct
{
	volatile u32 FLASH_ACR        ;
	volatile u32 FLASH_KEYR       ;
	volatile u32 FLASH_OPTKEYR    ;
	volatile u32 FLASH_SR         ;
	volatile u32 FLASH_CR         ;
	volatile u32 FLASH_OPTCR      ;
}FLASH_t;

#define FD_BASE_ADDRESS 0x40023C00
#define FLASH ((volatile FLASH_t*) FD_BASE_ADDRESS)

#define KEY1 0x45670123
#define KEY2 0xCDEF89AB

#endif /* MCAL_FLASH_DRIVER_FD_PRIVATE_H_ */
