
#include <STD_TYPES.h>
#include <BIT_MATHS.h>
#include <GPIO_Interface.h>
#include <GPIO_Private.h>
#include <RCC_Interface.h>

void turnLeds(u8 biNum);
u8 getReading();

int main(void){
	RCC_voidInit();
	RCC_voidEnablePeripheral(RCC_u8_AHB1ENR_GPIOA, RCC_u8_AHB1_BUS);
	RCC_voidEnablePeripheral(RCC_u8_AHB1ENR_GPIOB, RCC_u8_AHB1_BUS);

	for (int i = 0; i < 8; ++ i) {
		GPIO_voidConfigPinMode(GPIO_u8PortA, i, GPIO_InputMode);
		GPIO_voidConfigPullType(GPIO_u8PortA, i, GPIO_PullDown);
	}
	for (int i = 8; i < 11; ++ i) {
			GPIO_voidConfigPinMode(GPIO_u8PortA, i, GPIO_OutputMode);
//			GPIO_voidConfigOutputType(GPIO_u8PortB, 3, GPIO_OutputPush_Pull);
	}
	while(1){
		u8 VALUE = getReading();
		turnLeds(VALUE);
	}
}
u8 getReading(){
	for (int i = 7; i >= 0; -- i) {
		if(GPIO_voidGetPinValue(GPIO_u8PortA, i))
			return i;
	}
	return 0;
}
void turnLeds(u8 biNum){
	for (int i = 0; i < 4; ++ i) {
		if(GET_BIT(biNum,i))
			GPIO_voidchangePinoutvalue(GPIO_u8PortA, i + 8, GPIO_setPin);
//		else{
//			GPIO_voidchangePinoutvalue(GPIO_u8PortB, i, GPIO_ClearPin);
//		}
	}
}
