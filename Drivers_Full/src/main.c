//#include "LIB/BIT_MATHS.h"
//#include "LIB/STD_TYPES.h"
//#include "MCAL/GPIO/GPIO_Interface.h"
//#include "MCAL/GPIO/GPIO_Private.h"
//#include "MCAL/RCC/RCC_Interface.h"
//
//void turnLeds(u8 biNum);
//u8 getReading();
//
//int main(void){
////	RCC_voidInit();
////	RCC_voidEnablePeripheral(RCC_u8_AHB1ENR_GPIOA, RCC_u8_AHB1_BUS);
////	RCC_voidEnablePeripheral(RCC_u8_AHB1ENR_GPIOB, RCC_u8_AHB1_BUS);
////
////	for (int i = 0; i < 8; ++ i) {
////		GPIO_voidConfigPinMode(GPIO_u8PortA, i, GPIO_InputMode);
////		GPIO_voidConfigPullType(GPIO_u8PortA, i, GPIO_PullDown);
////	}
////	for (int i = 8; i < 11; ++ i) {
////			GPIO_voidConfigPinMode(GPIO_u8PortA, i, GPIO_OutputMode);
//////			GPIO_voidConfigOutputType(GPIO_u8PortB, 3, GPIO_OutputPush_Pull);
////	}
////	while(1){
////		u8 VALUE = getReading();
////		turnLeds(VALUE);
////	}
//	RCC_voidInit();
//	RCC_voidEnablePeripheral(RCC_u8_AHB1ENR_GPIOA, RCC_u8_AHB1_BUS);
//
//	for (int i = 0; i < 8; ++i) {
//		GPIO_voidConfigPinMode(GPIO_u8PortA, i, GPIO_OutputMode);
//		GPIO_voidConfigOutputType(GPIO_u8PortA , i, GPIO_OutputPush_Pull);
//	}
//	GPIO_voidchangePinoutvalue(GPIO_u8PortA, 1, 1);
//	GPIO_voidchangePinoutvalue(GPIO_u8PortA, 6, 1);
//
//
//}
