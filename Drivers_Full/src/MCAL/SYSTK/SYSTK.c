/* File: SYSTIC.c */

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_TYPES.h"
#include "SYSTK_config.h"
#include "SYSTK_interface.h"
#include "SYSTK_private.h"

/** Initialize the System Timer with the specified clock source */
void STK_voidInit(void) {
    /* Check CLK source in configuration */
#if CONFIG_CLKSOURCE == STK_AHB_DIV8
    CLEAR_BIT(STK->STK_CTRL, STK_CTRL_CLKSOURCE);
#elif CONFIG_CLKSOURCE == STK_AHB
    SET_BIT(STK->STK_CTRL, STK_CTRL_CLKSOURCE);
#endif
}

/** Enable or disable the SysTick interrupt based on configuration */
void STK_voidIntEnableDisable(void) {
    /* Check ENABLE bit in configuration */
#if SYSTICK_INT_DISABLE == DISABLE
    CLEAR_BIT(STK->STK_CTRL, STK_CNTRL_ENABLE);
#elif SYSTICK_INT_DISABLE == ENABLE
    SET_BIT(STK->STK_CTRL, STK_CNTRL_ENABLE);
#endif
}

/** Start the System Timer with a specified preload value */
void STK_voidStart(u32 Copy_PreloadValue) {
    STK->STK_LOAD = Copy_PreloadValue; /* Not -1 because of single mode */
    STK->STK_VAL = 0;
    SET_BIT(STK->STK_CTRL, STK_CNTRL_ENABLE);
}

/** Get the elapsed time since the System Timer started */
u32 STK_u32GetElapsedTime(void) {
    return (STK->STK_LOAD - STK->STK_VAL);
}

/** Get the remaining time for the System Timer to reach zero */
u32 STK_u32GetRemainingTime(void) {
    return STK->STK_VAL;
}

/** Read the SysTick count flag in the Control and Status Register (CTRL) */
u8 STK_u8ReadFlag(void) {
    return GET_BIT(STK->STK_CTRL, STK_CTRL_COUNTFLAG);
}

/** Implement a delay in milliseconds using the System Timer */
void STK_voidDelayMS(u32 Copy_u32DelayMS) {
    u32 delayForMs;
    /* let Clock = HSI (16M) */
    if (RCC_SYSCLK == RCC_HSI) {
        delayForMs = DELAY_FOR_MS;
    }
    STK_voidStart(delayForMs * Copy_u32DelayMS);
}

/** Implement a delay in microseconds using the System Timer */
void STK_voidDelayUS(u32 Copy_u32DelayUS) {
    u32 delayForUs;
    /* let Clock = HSI (16M) */
    if (RCC_SYSCLK == RCC_HSI) {
        delayForUs = DELAY_FOR_US;
    }
    STK_voidStart(delayForUs * Copy_u32DelayUS);
}

static void (*STK_CallBack)(void); /* Callback function pointer */

/** Set a callback function to be executed when SysTick interrupt occurs */
void STK_voidSetCallBack(void (*ptr)(void)) {
    STK_CallBack = ptr;
}

/** SysTick Interrupt Service Routine */
void SysTick_Handler(void) {
    if (STK_CallBack != NULL) {
        STK_CallBack();
    }
}
