/*
 * File: SYSTIC_interface.h
 * Author: Yusuf
 * Date: August 15, 2023
 * Description: Interface file for System Timer (SYSTICK) module.
 */

#ifndef MCAL_SYSTK_SYSTK_INTERFACE_H_
#define MCAL_SYSTK_SYSTK_INTERFACE_H_

/*
 * Bit 2: CLKSOURCE - Clock source selection
 * Bit 1: TICKINT   - SysTick exception request enable
 * Bit 0: ENABLE    - Counter enable
 */
/** Function to initialize the System Timer
 * Check CLK source in configuration */
void STK_voidInit(void);

/** Function to enable or disable the SysTick interrupt
 * Check ENABLE bit in configuration */
void STK_voidIntEnableDisable(void);

/** Function to start the System Timer with a specified preload value */
void STK_voidStart(u32 Copy_PreloadValue);

/** Function to get the elapsed time since the System Timer started
 * Returns a 24-bit value (u32) */
u32 STK_u32GetElapsedTime(void);

/** Function to get the remaining time for the System Timer to reach zero
 * Returns a 24-bit value (u32) */
u32 STK_u32GetRemainingTime(void);

/** Function to read the SysTick count flag in the Control and Status Register (CTRL)
 * Returns 1 if the count flag is set, 0 if not */
u8 STK_u8ReadFlag(void);

/** Function to implement a delay in milliseconds using the System Timer */
void STK_voidDelayMS(u32 Copy_u32DelayMS);

/** Function to implement a delay in microseconds using the System Timer */
void STK_voidDelayUS(u32 Copy_u32DelayUS);

/** Function to set a callback function to be executed when SysTick interrupt occurs */
void STK_voidSetCallBack(void (*ptr)(void));

void MSTK_vSetInterval_periodic (u32 A_u32Ticks, void (*CallbackFunction) (void));
#endif /* MCAL_SYSTK_SYSTK_INTERFACE_H_ */

