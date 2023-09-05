/*
 * FD_inteface.h
 *
 *  Created on: Sep 4, 2023
 *      Author: yusuf
 */

#ifndef MCAL_FLASH_DRIVER_FD_INTEFACE_H_
#define MCAL_FLASH_DRIVER_FD_INTEFACE_H_

#define Sector_zero_Address 0x08000000

void Flash_voidMassErase(void);
void Flash_voidSectorErase(u8 Copy_u8SectorNumber);
void Flash_voidFlashWrite(u32 Copy_u32Address, u32 *Copy_ptrData, u8 DataLength);




#endif /* MCAL_FLASH_DRIVER_FD_INTEFACE_H_ */
