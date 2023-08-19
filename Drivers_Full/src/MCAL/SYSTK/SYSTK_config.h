/*
 * File: SYSTIC_config.h
 * Author: Yusuf-Elsayed
 * Date: August 15, 2023
 * Description: Configuration file for System Timer (SYSTICK) module.
 */

#ifndef MCAL_SYSTK_SYSTK_CONFIG_H_
#define MCAL_SYSTK_SYSTK_CONFIG_H_

/*
 * CLKSOURCE: Clock source selection
 * Selects the clock source.
 * 0: AHB/8                --> STK_AHB_DIV8
 * 1: Processor clock (AHB) --> STK_AHB
 */
#define CONFIG_CLKSOURCE       STK_AHB_DIV8

/* INT En bit 0
 * En --> ENABLE
 * Dis --> DISABLE
 */
#define SYSTICK_INT_DISABLE    ENABLE
#define SYSTICK_INT_ENABLE     DISABLE

/**
 * @brief System clock source selection.
 *
 * Choose the system clock source from the available options.
 *
 * Options:
 * - RCC_HSI: Internal High-Speed oscillator (default)
 * - RCC_HSE: External High-Speed oscillator
 * - RCC_PLL: Phase-Locked Loop
 */
#define RCC_SYSCLK             RCC_HSI

#endif /* MCAL_SYSTK_SYSTK_CONFIG_H_ */
