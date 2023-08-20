#ifndef GPIO_INTERFACE
#define GPIO_INTERFACE

#define GPIO_u8PortA  0
#define GPIO_u8PortB  1
#define GPIO_u8PortC  2

/*******************************************************************/
/* 							GPIOx_MODER							   */
/* Copy_y8Port:                                                    */
/* 						1-GPIO_A                                   */
/*                      2-GPIO_B                                   */
/*                      3-GPIO_C                                   */
/*																   */
/*Copy_y8PinNum: N*2 & N*2 +1,  N = 0 --> 15  except c 13 -->15	   */
/*																   */
/*GPIO port mode register Maybe :   		                       */
/*                       1-GPIO_InputMode        	           	   */
/*                       2-GPIO_OutputMode            			   */
/*                       3-GPIO_AlternateMode                 	   */
/*                       4-GPIO_AnalogMode                         */
/*                                                                 */
/*******************************************************************/
void GPIO_voidConfigPinMode(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8PinMode);
#define GPIO_InputMode 		0b00
#define GPIO_OutputMode 	0b01
#define GPIO_AlternateMode 	0b10
#define GPIO_AnalogMode		0b11

/*******************************************************************/
/* 							GPIOx_OTYPER						   */
/* Copy_y8Port:                                                    */
/* 						1-GPIO-A                                   */
/*                      2-GPIO-B                                   */
/*                      3-GPIO-C								   */
/*                                								   */
/*Copy_y8PinNum:		0 --> 15  			Except C 13 -->15	   */
/*																   */
/*GPIO port output type register :   		                       */
/*                       1-GPIO_OutputPush_Pull         		   */
/*                       2-GPIO_OutputOpen_Drain                   */
/*                                                                 */
/*******************************************************************/
void GPIO_voidConfigOutputType(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8OutputType);
#define GPIO_OutputPush_Pull	0b00
#define GPIO_OutputOpen_Drain 	0b01

/*******************************************************************/
/* 							GPIOx_OSPEEDR						   */
/* Copy_y8Port:                                                    */
/* 						1-GPIO-A                                   */
/*                      2-GPIO-B                                   */
/*                      3-GPIO-C								   */
/*                                								   */
/*Copy_y8PinNum: N*2 & N*2 +1,  N = 0 --> 15  except c 13 -->15	   */
/*																   */
/*GPIO port output speed register :   		                       */
/*                       1-GPIO_LowSpeed       	           	 	   */
/*                       2-GPIO_MedSpeed            			   */
/*                       3-GPIO_HighSpeed                 	  	   */
/*                       4-GPIO_VeryHighSpeed                      */
/*                                                                 */
/*******************************************************************/
void GPIO_voidConfigOutputSpeed(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8PinOutputSpeed);
#define GPIO_LowSpeed		0b00
#define GPIO_MedSpeed		0b01
#define GPIO_HighSpeed		0b10
#define GPIO_VeryHighSpeed	0b11

/*******************************************************************/
/* 							GPIOx_PUPDR							   */
/* Copy_y8Port:                                                    */
/* 						1-GPIO-A                                   */
/*                      2-GPIO-B                                   */
/*                      3-GPIO-C								   */
/*                                								   */
/*Copy_y8PinNum: N*2 & N*2 +1,  N = 0 --> 15  except c 13 -->15	   */
/*																   */
/*GPIO port pull-up/pull-down register :   		                   */
/*                       1-GPIO_NoPullUpOrDown             	 	   */
/*                       2-GPIO_PullUp               			   */
/*                       3-GPIO_PullDown                 	   	   */
/*                       4-Reserved			                       */
/*                                                                 */
/*******************************************************************/
void GPIO_voidConfigPullType(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8PinPullType);
#define GPIO_NoPullUpOrDown  0b00
#define GPIO_PullUp          0b01
#define GPIO_PullDown        0b10

/*******************************************************************/
/* 							GPIOx_IDR								   */
/* Copy_y8Port:                                                    */
/* 						1-GPIO-A                                   */
/*                      2-GPIO-B                                   */
/*                      3-GPIO-C								   */
/*                                								   */
/*Copy_y8PinNum:		0 --> 15  			Except C 13 -->15	   */
/*                                                                 */
/*******************************************************************/
u8 GPIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNum);

/*******************************************************************/
/* 							GPIOx_ODR							   */
/* Copy_y8Port:                                                    */
/* 						1-GPIO-A                                   */
/*                      2-GPIO-B                                   */
/*                      3-GPIO-C								   */
/*                                								   */
/*Copy_y8PinNum:		0 --> 15  			Except C 13 -->15	   */
/*                                                                 */
/*******************************************************************/
void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNum);

/*******************************************************************/
/* 							GPIOx_BSRR							   */
/* Copy_y8Port:                                                    */
/* 						1-GPIO-A                                   */
/*                      2-GPIO-B                                   */
/*                      3-GPIO-C								   */
/*                                								   */
/*Copy_y8PinNum:		1-set bit  0..15		        		   */
/*                      2-Reset bit  16..31	        		   	   */
/*																   */
/*GPIO port bit set/reset register : 							   */
/* 						0: No action on the corresponding ODRx bit */
/*					1: Action Set/Resets the corresponding ODRx bit*/
/*                                                                 */
/*******************************************************************/
void GPIO_voidPinValueSetReset(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8PinAction);

//To be Implemented
/*******************************************************************/
/* 							GPIOx_LCKR							   */
/* Copy_y8Port:                                                    */
/* 						1-GPIO-A                                   */
/*                      2-GPIO-B                                   */
/*                      3-GPIO-C								   */
/*                                								   */
/*Copy_y8PinNum:		0-->15				        		   	   */
/*																   */
/*GPIO port configuration lock register : 						   */
/* 						1-GPIO_PortNotLocked 0					   */
/* 						1-GPIO_PortLocked 	 1					   */
/*                                                                 */
/*******************************************************************/
void GPIO_voidPinLock(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8PinAction);
#define GPIO_PortNotLocked 	0b00
#define GPIO_PortLocked		0b01

/*******************************************************************/
/* 							GPIOx_AFRL/GPIOx_AFRH				   */
/* Copy_y8Port:                                                    */
/* 						1-GPIO-A                                   */
/*                      2-GPIO-B                                   */
/*                      3-GPIO-C								   */
/*                                								   */
/*Copy_y8PinNum:		4*N										   */
/* 						1- 0-->15 		GPIOx_AFRL				   */
/* 						2- 16 --> 31	GPIOx_AFRH			       */
/*																   */
/*GPIO alternate function low registe : 						   */
/* 						1-	GPIOx_AFRL AF0-->AF15				   */
/* 						2-	GPIOx_AFRH AF0-->AF15				   */
/*                                                                 */
/*******************************************************************/
void GPIO_voidEnableAltFun(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8AltFun);
#define AF0  0b0000
#define AF1  0b0001
#define AF2  0b0010
#define AF3  0b0011
#define AF4  0b0100
#define AF5  0b0101
#define AF6  0b0110
#define AF7  0b0111
#define AF8  0b1000
#define AF9  0b1001
#define AF10 0b1010
#define AF11 0b1011
#define AF12 0b1100
#define AF13 0b1101
#define AF14 0b1110
#define AF15 0b1111

void GPIO_voidchangePinoutvalue(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8SetOrClearOrTgl);
#define GPIO_setPin 1
#define GPIO_ClearPin 0
#define GPIO_TGLPin 2

#endif
