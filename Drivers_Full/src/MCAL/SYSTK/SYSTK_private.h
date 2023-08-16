/*
 * SYSTIC_private.h
 *
 *  Created on: Aug 15, 2023
 *      Author: yusuf
 */

#ifndef MCAL_SYSTK_SYSTK_PRIVATE_H_
#define MCAL_SYSTK_SYSTK_PRIVATE_H_

typedef struct{
	volatile u32 STK_CTRL  ;
	volatile u32 STK_LOAD  ;
	volatile u32 STK_VAL   ;
	volatile u32 STK_CALIB   ;
}STK_t;

#define BASE_ADDRESS 0xE000E010
#define STK ((volatile STK_t*) BASE_ADDRESS)

/* STK_CTRL */
#define STK_CNTRL_ENABLE 0
#define STK_CTRL_TICKINT 1
#define STK_CTRL_CLKSOURCE 2
#define STK_CTRL_COUNTFLAG 16

/* CLKSOURCE in  STK_CTRL*/
#define  STK_AHB_DIV8 0
#define  STK_AHB 1

/* COnfigration Vaules for statusFun --> STK_voidIntStatus */
#define ENABLE 1
#define DISABLE 0

#endif /* MCAL_SYSTK_SYSTK_PRIVATE_H_ */
