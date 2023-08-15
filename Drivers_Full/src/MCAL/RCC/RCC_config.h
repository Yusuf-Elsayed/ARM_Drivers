/*
 * File Name: RCC_config.h
 * Author: Yusuf Elsayed
 * Date: 8/8/2023
 * Description: Configuration options for RCC (Reset and Clock Control) module.
 * Version: 2
 */

#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H

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
#define RCC_SYSCLK RCC_HSE

/**
 * @brief HSE (External High-Speed oscillator) mode selection.
 *
 * Choose the mode of operation for the external crystal oscillator.
 *
 * Options:
 * - RCC_HSE_BYPASS: HSE bypass mode
 * - RCC_HSE_CRYSTAL: HSE crystal mode (default)
 */
#define RCC_HSE_MODE RCC_HSE_BYPASS

/**
 * @brief PLL Clock Source selection.
 *
 * Choose the clock source for the PLL (Phase-Locked Loop).
 *
 * Options:
 * - RCC_u32_PLL_SRC_HSI: Use HSI (High-Speed Internal) oscillator as PLL source
 * - RCC_u32_PLL_SRC_HSE: Use HSE (External High-Speed) oscillator as PLL source
 */
#define RCC_u32_PLL_SRC RCC_u32_PLL_SRC_HSI

/**
 * @brief PLL input clock frequency divider (PLLM value).
 *
 * VCO input frequency = PLL input clock frequency / PLLM
 * Choose a value between 2 and 63 to be within the range of 1~2MHz.
 */
#define RCC_u32_PLLM 3

/**
 * @brief PLL output clock frequency multiplier (PLLN value).
 *
 * VCO output frequency = VCO input frequency x PLLN
 * Choose a value between 2 and 432 to achieve the desired VCO output frequency.
 */
#define RCC_u32_PLLN 2

/**
 * @brief PLL output clock frequency divider (PLLP value).
 *
 * PLL output clock frequency = VCO frequency / PLLP
 * Choose a value to set the desired PLL output clock frequency.
 *
 * Options:
 * - RCC_u32_PLLP2: Divide VCO frequency by 2
 * - RCC_u32_PLLP4: Divide VCO frequency by 4
 * - RCC_u32_PLLP6: Divide VCO frequency by 6
 * - RCC_u32_PLLP8: Divide VCO frequency by 8
 */
#define RCC_u32_PLLP RCC_u32_PLLP2

#endif /* RCC_CONFIG_H */
