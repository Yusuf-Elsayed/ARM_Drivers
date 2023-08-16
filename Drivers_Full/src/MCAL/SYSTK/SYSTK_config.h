/*
 * SYSTIC_config.h
 *
 *  Created on: Aug 15, 2023
 *      Author: yusuf
 */

#ifndef MCAL_SYSTK_SYSTK_CONFIG_H_
#define MCAL_SYSTK_SYSTK_CONFIG_H_

/*
 * CLKSOURCE: Clock source selection
 * Selects the clock source.
 * 0: AHB/8 				--> STK_AHB_DIV8
 * 1: Processor clock (AHB)	--> STK_AHB
 */
#define CONFIG_CLKSOURCE STK_AHB_DIV8

/* INT En bit 0
 * En --> ENABLE
 * Dis -->DISABLE
 * */
#define SYSTICK_INT_DISABLE     ENABLE
#define SYSTICK_INT_ENABLE      DISABLE




#endif /* MCAL_SYSTK_SYSTK_CONFIG_H_ */
