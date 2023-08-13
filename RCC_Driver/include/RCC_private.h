/*
 * File Name: RCC_Private.h
 * Author:Yusuf Elsayed
 * Date: 8/8/2023
 * Desc: Developer edit
 * Version: 2
 */

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H
//#define RCC_BASE volatile *((u32 *)0x40023800)
//#define RCC_CR volatile *((u32 *)RCC_BASE+0x00)
//#define RCC_PLLCFGR volatile *((u32 *)RCC_BASE+0x04)


typedef struct{
	volatile u32 RCC_CR;
	volatile u32 RCC_PLLCFGR;
	volatile u32 RCC_CFGR;
	volatile u32 RCC_CIR;
	volatile u32 RCC_AHB1RST;
	volatile u32 RCC_AHB2RST;
	volatile u32 Reserved1;
	volatile u32 Reserved2;
	volatile u32 RCC_APB1RST;
	volatile u32 RCC_APB2RST;
	volatile u32 Reserved3;
	volatile u32 Reserved4;
	volatile u32 RCC_AHB1ENR;
	volatile u32 RCC_AHB2ENR;
	volatile u32 Reserved5;
	volatile u32 Reserved6;
	volatile u32 RCC_APB1ENR;
	volatile u32 RCC_APB2ENR;
	volatile u32 Reserved7;
	volatile u32 Reserved8;
	volatile u32 RCC_AHB1LPENR;
	volatile u32 RCC_AHB2LPENR;
	volatile u32 Reserved9;
	volatile u32 Reserved10;
	volatile u32 RCC_APB1LPENR;
	volatile u32 RCC_APB2LPENR;
	volatile u32 Reserved11;
	volatile u32 Reserved12;
	volatile u32 RCC_BDCR;
	volatile u32 RCC_CSR;
	volatile u32 Reserved13;
	volatile u32 Reserved14;
	volatile u32 RCC_SSCGR;
	volatile u32 RCC_PLLI2SCFGR;
	volatile u32 Reserved15;
	volatile u32 RCC_DCKCFGR;
}RCC_T;

#define RCC_BASE 0x40023800
#define RCC (((RCC_T *)RCC_BASE))

#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2

#define RCC_HSE_BYPASS 1
#define RCC_HSE_CRYSTAL 2

#define RCC_u32_PLL_SRC_HSI 0
#define RCC_u32_PLL_SRC_HSE 1

////P value
//#define RCC_u32_PLLP2 0x00000000
//#define RCC_u32_PLLP4 0x00010000
//#define RCC_u32_PLLP6 0x00020000
//#define RCC_u32_PLLP8 0x00030000
//
////Main PLL division factor
//#define RCC_u32_PLL_DIV_FACTOR_NONE 0x00000000	???
//#define RCC_u32_PLL_DIV_FACTOR_2 0x00020000 //VALUE of RCC_CFGR PLLXTPRE


#endif
