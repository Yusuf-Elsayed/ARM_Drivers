#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_TYPES.h"
#include "FD_inteface.h"
#include "FD_config.h"
#include "FD_private.h"

void Flash_voidMassErase(void){
	u8 loca_u8Counter;
	for(loca_u8Counter = 1; loca_u8Counter < 6; loca_u8Counter++){
		Flash_voidSectorErase(loca_u8Counter); // index = section
	}
}
void Flash_voidSectorErase(u8 Copy_u8SectorNumber){
	/* wait if bsy ==1 in SR */
	while (GET_BIT(FLASH->FLASH_SR, 16));

	// if locked --> allow program and erase operation
	if(GET_BIT(FLASH->FLASH_CR, 31) == 1){
		// unlock
		FLASH->FLASH_KEYR = KEY1;
		FLASH->FLASH_KEYR = KEY2;
	}
	/* set sector num in CR */
	FLASH->FLASH_CR &= ~(0b1111 << 3);
	FLASH->FLASH_CR |=  (Copy_u8SectorNumber << 3);

	/*  Bit 1 SER: Sector Erase --> Sector Erase activated. in CR */
	SET_BIT(FLASH->FLASH_CR, 1);
	/* Start Erasing by set 1 in SRT bit*/
	SET_BIT(FLASH->FLASH_CR, 16);
	/* wait until op ends */
	while (GET_BIT(FLASH->FLASH_SR, 16));

	SET_BIT(FLASH->FLASH_CR, 1);

}
void Flash_voidFlashWrite(u32 Copy_u32Address, u32 *Copy_ptrData, u8 DataLength) {
    u8 i;

    // Make sure the Flash memory is not busy (wait for BSY bit to be cleared)
    while (GET_BIT(FLASH->FLASH_SR, 16));

    // Check if the Flash controller is locked, and if so, unlock it
    if (GET_BIT(FLASH->FLASH_CR, 31) == 1) {
        FLASH->FLASH_KEYR = KEY1;
        FLASH->FLASH_KEYR = KEY2;
    }

    // Enable programming in the control register (PG bit)
    SET_BIT(FLASH->FLASH_CR, 0);

    // Perform the Flash programming
    for (i = 0; i < DataLength; i++) {
        // Write the data to the Flash memory address
        *((volatile u32*)(Copy_u32Address + (i * 4))) = Copy_ptrData[i];

        // Wait for the programming to complete (wait for BSY bit to be cleared)
        while (GET_BIT(FLASH->FLASH_SR, 16));
    }

    // Disable programming (clear the PG bit)
    CLEAR_BIT(FLASH->FLASH_CR, 0);
}

