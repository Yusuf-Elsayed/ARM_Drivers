/*
 * main.c
 *
 *  Created on: Aug 7, 2023
 *      Author: yusuf
 */
#include <STD_TYPES.h>
#include <BIT_MATHS.h>
#include <RCC_Interface.h>

int main(void){
	RCC_voidInit();
	while(1){
		RCC_voidEnablePeripheral(0, RCC_u8_AHB1_BUS);
	}
	return 0;
}
