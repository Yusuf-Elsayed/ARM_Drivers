/*
 * File Name: RCC_config.h
 * Author:Yusuf Elsayed
 * Date: 8/8/2023
 * Desc: configuration for user edit
 * Version: 2
 */


#ifndef RCC_CONFIG_H
#define RCC_CONFIG_H
/*
 * OPTIONS:
 * 		RCC_HSI
 * 		RCC_HSE
 * 		RCC_PLL
 */
#define RCC_SYSCLK RCC_HSE
/*
 * OPTIONS:
 * 		RCC_HSE_BYPASS
 * 		RCC_HSE_CRYSTAL
 */
#define RCC_HSE_MODE RCC_HSE_BYPASS

// =========================================
/*PLL Clock Source
 *
 *Options: 	1- RCC_u32_PLL_SRC_HSI

			2- RCC_u32_PLL_SRC_HSE
*/
#define RCC_u32_PLL_SRC RCC_u32_PLL_SRC_HSI

/*
 * f(VCO clock) = f(PLL clock input) × (PLLN / PLLM)
 * f(PLL general clock output) = f(VCO clock) / PLLP
 * f(USB OTG FS, SDIO, RNG clock output) = f(VCO clock)
 */

/*VCO input frequency = PLL input clock frequency / PLLM with 2 <=PLLM <=63 TO
 * BE WITHIN 1~2MHZ
 * PLLM 2 --> 63
*/
#define RCC_u32_PLLM 3

/*VCO output frequency = VCO input frequency x PLLN with range 192MHZ <=VCO <=435
 * PLLN 2 --> 432
*/
#define RCC_u32_PLLN 2



//The software has to set these bits correctly not to exceed 84 MHz
/*PLL output clock frequency = VCO frequency / PLLP
 PLLP options:
				RCC PLLP2 = 2
				RCC PLLP4 = 4
				RCC PLLP6 = 6
				RCC_PLLP8 = 8
*/
#define RCC_u32_PLLP 2

//#define PLL_MUL PLL_MUL7

#endif
