/*
 * File Name: RCC_Private.h
 * Author: Yusuf-Elsayed
 * Date: 8/8/2023
 * Description: Private header file for RCC (Reset and Clock Control) module.
 * Version: 2
 */

#ifndef RCC_PRIVATE_H
#define RCC_PRIVATE_H

/* RCC register structure */
typedef struct {
    volatile u32 RCC_CR;         /* Clock Control Register */
    volatile u32 RCC_PLLCFGR;    /* PLL Configuration Register */
    volatile u32 RCC_CFGR;       /* Clock Configuration Register */
    volatile u32 RCC_CIR;        /* Clock Interrupt Register */
    volatile u32 RCC_AHB1RST;    /* AHB1 Peripheral Reset Register */
    volatile u32 RCC_AHB2RST;    /* AHB2 Peripheral Reset Register */
    volatile u32 Reserved1;      /* Reserved */
    volatile u32 Reserved2;      /* Reserved */
    volatile u32 RCC_APB1RST;    /* APB1 Peripheral Reset Register */
    volatile u32 RCC_APB2RST;    /* APB2 Peripheral Reset Register */
    volatile u32 Reserved3;      /* Reserved */
    volatile u32 Reserved4;      /* Reserved */
    volatile u32 RCC_AHB1ENR;    /* AHB1 Peripheral Clock Enable Register */
    volatile u32 RCC_AHB2ENR;    /* AHB2 Peripheral Clock Enable Register */
    volatile u32 Reserved5;      /* Reserved */
    volatile u32 Reserved6;      /* Reserved */
    volatile u32 RCC_APB1ENR;    /* APB1 Peripheral Clock Enable Register */
    volatile u32 RCC_APB2ENR;    /* APB2 Peripheral Clock Enable Register */
    volatile u32 Reserved7;      /* Reserved */
    volatile u32 Reserved8;      /* Reserved */
    volatile u32 RCC_AHB1LPENR;  /* AHB1 Peripheral Low-Power Clock Enable Register */
    volatile u32 RCC_AHB2LPENR;  /* AHB2 Peripheral Low-Power Clock Enable Register */
    volatile u32 Reserved9;      /* Reserved */
    volatile u32 Reserved10;     /* Reserved */
    volatile u32 RCC_APB1LPENR;  /* APB1 Peripheral Low-Power Clock Enable Register */
    volatile u32 RCC_APB2LPENR;  /* APB2 Peripheral Low-Power Clock Enable Register */
    volatile u32 Reserved11;     /* Reserved */
    volatile u32 Reserved12;     /* Reserved */
    volatile u32 RCC_BDCR;       /* Backup Domain Control Register */
    volatile u32 RCC_CSR;        /* Control/Status Register */
    volatile u32 Reserved13;     /* Reserved */
    volatile u32 Reserved14;     /* Reserved */
    volatile u32 RCC_SSCGR;      /* Spread Spectrum Clock Generation Register */
    volatile u32 RCC_PLLI2SCFGR; /* PLLI2S Configuration Register */
    volatile u32 Reserved15;     /* Reserved */
    volatile u32 RCC_DCKCFGR;    /* Dedicated Clock Configuration Register */
} RCC_T;

#define RCC_BASE 0x40023800
#define RCC (((RCC_T *)RCC_BASE))

/* Clock sources */
#define RCC_HSI 0
#define RCC_HSE 1
#define RCC_PLL 2

/* HSE modes */
#define RCC_HSE_BYPASS 1
#define RCC_HSE_CRYSTAL 2

/* PLL sources */
#define RCC_u32_PLL_SRC_HSI 0
#define RCC_u32_PLL_SRC_HSE 1

/* P values for PLLP division */
#define RCC_u32_PLLP2 0x00000000
#define RCC_u32_PLLP4 0x00010000
#define RCC_u32_PLLP6 0x00020000
#define RCC_u32_PLLP8 0x00030000

/* Main PLL division factor */
#define RCC_u32_PLL_DIV_FACTOR_NONE 0x00000000 /* ??? */
#define RCC_u32_PLL_DIV_FACTOR_2 0x00020000    /* VALUE of RCC_CFGR PLLXTPRE */

#endif
