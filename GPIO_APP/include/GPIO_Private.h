/*
 * GPIO_Private.h
 *
 *  Created on: Aug 9, 2023
 *      Author: yusuf
 */

#ifndef GPIO_PRIVATE_H_
#define GPIO_PRIVATE_H_
typedef struct {
	volatile u32 GPIOx_MODE      ;
	volatile u32 GPIOx_OTYPER    ;
	volatile u32 GPIOx_OSPEEDR   ;
	volatile u32 GPIOx_PUPDR     ;
	volatile u32 GPIOx_IDR       ;
	volatile u32 GPIOx_ODR       ;
	volatile u32 GPIOx_BSRR      ;
	volatile u32 GPIOx_LCKR      ;
	volatile u32 GPIOx_AFRL      ;
	volatile u32 GPIOx_AFRH      ;

}GPIO_def;


#define GPIO_A ((GPIO_def*) 0x40020000)
#define GPIO_B ((GPIO_def*) 0x40020400)
#define GPIO_C ((GPIO_def*) 0x40020800)

#endif /* GPIO_PRIVATE_H_ */

