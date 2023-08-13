#include <STD_TYPES.h>
#include <BIT_MATHS.h>
#include <GPIO_Private.h>
#include <GPIO_Interface.h>
#include <GPIO_config.h>

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
void GPIO_voidConfigPinMode(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8PinMode){
    switch(Copy_u8Port){
        case GPIO_u8PortA: (GPIO_A->GPIOx_MODE) &= ~(0b11 << (Copy_u8PinNum * 2)); // Clear the bits for the specific pin
                           (GPIO_A->GPIOx_MODE) |= (Copy_u8PinMode << (Copy_u8PinNum * 2)); break;
        case GPIO_u8PortB: (GPIO_B->GPIOx_MODE) &= ~(0b11 << (Copy_u8PinNum * 2));
                           (GPIO_B->GPIOx_MODE) |= (Copy_u8PinMode << (Copy_u8PinNum * 2)); break;
        case GPIO_u8PortC: (GPIO_C->GPIOx_MODE) &= ~(0b11 << (Copy_u8PinNum * 2));
                           (GPIO_C->GPIOx_MODE) |= (Copy_u8PinMode << (Copy_u8PinNum * 2)); break;
    }
}

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
void GPIO_voidConfigOutputType(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8OutputType){
	switch(Copy_u8Port){
	        case GPIO_u8PortA: (GPIO_A->GPIOx_OTYPER) &= ~(1 << (Copy_u8PinNum)); // Clear the bits for the specific pin
	                           (GPIO_A->GPIOx_OTYPER) |= (Copy_u8OutputType << (Copy_u8PinNum)); break;
	        case GPIO_u8PortB: (GPIO_B->GPIOx_OTYPER) &= ~(1 << (Copy_u8PinNum));
	                           (GPIO_B->GPIOx_OTYPER) |= (Copy_u8OutputType << (Copy_u8PinNum)); break;
	        case GPIO_u8PortC: (GPIO_C->GPIOx_OTYPER) &= ~(1 << (Copy_u8PinNum));
	                           (GPIO_C->GPIOx_OTYPER) |= (Copy_u8OutputType << (Copy_u8PinNum)); break;
	    }
}

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
void GPIO_voidConfigOutputSpeed(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8PinOutputSpeed){
	switch(Copy_u8Port){
	        case GPIO_u8PortA: (GPIO_A->GPIOx_OSPEEDR) &= ~(0b11 << (Copy_u8PinNum * 2)); // Clear the bits for the specific pin
	                           (GPIO_A->GPIOx_OSPEEDR) |= (Copy_u8PinOutputSpeed << (Copy_u8PinNum * 2)); break;
	        case GPIO_u8PortB: (GPIO_B->GPIOx_OSPEEDR) &= ~(0b11 << (Copy_u8PinNum * 2));
	                           (GPIO_B->GPIOx_OSPEEDR) |= (Copy_u8PinOutputSpeed << (Copy_u8PinNum * 2)); break;
	        case GPIO_u8PortC: (GPIO_C->GPIOx_OSPEEDR) &= ~(0b11 << (Copy_u8PinNum * 2));
	                           (GPIO_C->GPIOx_OSPEEDR) |= (Copy_u8PinOutputSpeed << (Copy_u8PinNum * 2)); break;
	}
}

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
void GPIO_voidConfigPullType(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8PinPullType){
	switch(Copy_u8Port){
		        case GPIO_u8PortA: (GPIO_A->GPIOx_PUPDR) &= ~(0b11 << (Copy_u8PinNum * 2)); // Clear the bits for the specific pin
		                           (GPIO_A->GPIOx_PUPDR) |= (Copy_u8PinPullType << (Copy_u8PinNum * 2)); break;
		        case GPIO_u8PortB: (GPIO_B->GPIOx_PUPDR) &= ~(0b11 << (Copy_u8PinNum * 2));
		                           (GPIO_B->GPIOx_PUPDR) |= (Copy_u8PinPullType << (Copy_u8PinNum * 2)); break;
		        case GPIO_u8PortC: (GPIO_C->GPIOx_PUPDR) &= ~(0b11 << (Copy_u8PinNum * 2));
		                           (GPIO_C->GPIOx_PUPDR) |= (Copy_u8PinPullType << (Copy_u8PinNum * 2)); break;
	}
}

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
u8 GPIO_voidGetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNum){
	switch(Copy_u8Port){
		        case GPIO_u8PortA: return GET_BIT((GPIO_A->GPIOx_IDR),Copy_u8PinNum);
		        case GPIO_u8PortB: return GET_BIT((GPIO_B->GPIOx_IDR),Copy_u8PinNum);
		        case GPIO_u8PortC: return GET_BIT((GPIO_C->GPIOx_IDR),Copy_u8PinNum);
	}
}

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
void GPIO_voidSetPinValue(u8 Copy_u8Port, u8 Copy_u8PinNum){
	switch(Copy_u8Port){
			        case GPIO_u8PortA: SET_BIT((GPIO_A->GPIOx_ODR),Copy_u8PinNum);	break;
			        case GPIO_u8PortB: SET_BIT((GPIO_B->GPIOx_ODR),Copy_u8PinNum);	break;
			        case GPIO_u8PortC: SET_BIT((GPIO_C->GPIOx_ODR),Copy_u8PinNum);	break;
		}
}

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
void GPIO_voidPinValueSetReset(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8PinAction){
	if(Copy_u8PinNum < 16 && Copy_u8PinAction){
			switch(Copy_u8Port){
				        case GPIO_u8PortA: SET_BIT((GPIO_A->GPIOx_BSRR),Copy_u8PinNum);	break;
				        case GPIO_u8PortB: SET_BIT((GPIO_B->GPIOx_BSRR),Copy_u8PinNum);	break;
				        case GPIO_u8PortC: SET_BIT((GPIO_C->GPIOx_BSRR),Copy_u8PinNum);	break;
					}
	}
	else if(Copy_u8PinNum > 15 && Copy_u8PinAction){
		switch(Copy_u8Port){
						case GPIO_u8PortA: CLEAR_BIT((GPIO_A->GPIOx_BSRR),Copy_u8PinNum);	break;
						case GPIO_u8PortB: CLEAR_BIT((GPIO_B->GPIOx_BSRR),Copy_u8PinNum);	break;
						case GPIO_u8PortC: CLEAR_BIT((GPIO_C->GPIOx_BSRR),Copy_u8PinNum);	break;
					}
	}

}

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
/*GPIO alternate function low register : 						   */
/* 						1-	GPIOx_AFRL AF0-->AF15				   */
/* 						2-	GPIOx_AFRH AF0-->AF15				   */
/*                                                                 */
/*******************************************************************/
void GPIO_voidEnableAltFun(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8AltFun){
	if(Copy_u8PinNum < 16){
			switch(Copy_u8Port){
			        case GPIO_u8PortA: (GPIO_A->GPIOx_AFRL) &= ~(0b1111 << (Copy_u8PinNum * 4)); // Clear the bits for the specific pin
			                           (GPIO_A->GPIOx_AFRL) |= (Copy_u8AltFun << (Copy_u8PinNum * 4)); break;
			        case GPIO_u8PortB: (GPIO_B->GPIOx_AFRL) &= ~(0b1111 << (Copy_u8PinNum * 4));
			                           (GPIO_B->GPIOx_AFRL) |= (Copy_u8AltFun << (Copy_u8PinNum * 4)); break;
			        case GPIO_u8PortC: (GPIO_C->GPIOx_AFRL) &= ~(0b1111 << (Copy_u8PinNum * 4));
			                           (GPIO_C->GPIOx_AFRL) |= (Copy_u8AltFun << (Copy_u8PinNum * 4)); break;
			}
	}else if(Copy_u8PinNum > 15){
			switch(Copy_u8Port){

					case GPIO_u8PortA: (GPIO_A->GPIOx_AFRH) &= ~(0b1111 << (Copy_u8PinNum * 4)); // Clear the bits for the specific pin
									   (GPIO_A->GPIOx_AFRH) |= (Copy_u8AltFun << (Copy_u8PinNum * 4)); break;
					case GPIO_u8PortB: (GPIO_B->GPIOx_AFRH) &= ~(0b1111 << (Copy_u8PinNum * 4));
									   (GPIO_B->GPIOx_AFRH) |= (Copy_u8AltFun << (Copy_u8PinNum * 4)); break;
					case GPIO_u8PortC: (GPIO_C->GPIOx_AFRH) &= ~(0b1111 << (Copy_u8PinNum * 4));
									   (GPIO_C->GPIOx_AFRH) |= (Copy_u8AltFun << (Copy_u8PinNum * 4)); break;
			}
	}
}


void GPIO_voidchangePinoutvalue(u8 Copy_u8Port, u8 Copy_u8PinNum, u8 Copy_u8SetOrClear){
	switch(Copy_u8SetOrClear){
		case GPIO_setPin:
			switch(Copy_u8Port){
						case GPIO_u8PortA: SET_BIT((GPIO_A->GPIOx_ODR),Copy_u8PinNum);	break;
						case GPIO_u8PortB: SET_BIT((GPIO_B->GPIOx_ODR),Copy_u8PinNum);	break;
						case GPIO_u8PortC: SET_BIT((GPIO_C->GPIOx_ODR),Copy_u8PinNum);	break;
			}
		case GPIO_ClearPin:
			switch(Copy_u8Port){
						case GPIO_u8PortA: CLEAR_BIT((GPIO_A->GPIOx_ODR),Copy_u8PinNum);	break;
						case GPIO_u8PortB: CLEAR_BIT((GPIO_B->GPIOx_ODR),Copy_u8PinNum);	break;
						case GPIO_u8PortC: CLEAR_BIT((GPIO_C->GPIOx_ODR),Copy_u8PinNum);	break;
			}
	}
}
