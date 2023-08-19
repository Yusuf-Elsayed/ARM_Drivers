/** File: SYSTIC_private.h
 * Author: Yusuf
 * Date: August 15, 2023
 * Description: Private header file for System Timer (SYSTICK) module.
 */

#ifndef MCAL_SYSTK_SYSTK_PRIVATE_H_
#define MCAL_SYSTK_SYSTK_PRIVATE_H_

/** Structure to define the SysTick registers */
typedef struct {
    volatile u32 STK_CTRL;   /**< SysTick Control and Status Register */
    volatile u32 STK_LOAD;   /**< SysTick Reload Value Register */
    volatile u32 STK_VAL;    /**< SysTick Current Value Register */
    volatile u32 STK_CALIB;  /**< SysTick Calibration Value Register */
} STK_t;

/** Base address of the SysTick peripheral */
#define BASE_ADDRESS   0xE000E010
#define STK            ((volatile STK_t*) BASE_ADDRESS)

/** Bits in STK_CTRL register */
#define STK_CNTRL_ENABLE     0
#define STK_CTRL_TICKINT     1
#define STK_CTRL_CLKSOURCE   2
#define STK_CTRL_COUNTFLAG   16

/** Clock sources in STK_CTRL */
#define STK_AHB_DIV8         0
#define STK_AHB              1

/** Configuration values for status functions (e.g., STK_voidIntStatus) */
#define ENABLE               1
#define DISABLE              0

/** Clock source options */
#define RCC_HSI              0
#define RCC_HSE              1
#define RCC_PLL              2

/** Conversion factors for delays */
#define DELAY_FOR_MS         16000  /**< systemTick = 1/f, delay in milliseconds */
#define DELAY_FOR_US         16     /**< systemTick = 1/f, delay in microseconds */

#endif /* MCAL_SYSTK_SYSTK_PRIVATE_H_ */
