/*
 * RCC.c
 *
 *  Created on: Aug 7, 2023
 *      Author: Yusuf-Elsayed
 */

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_TYPES.h"
#include "RCC_private.h"
#include "RCC_Interface.h"
#include "RCC_config.h"

/**
 * @brief Initialize the RCC module based on the selected system clock source.
 *
 * This function initializes the RCC module based on the selected system clock source.
 */
void RCC_voidInit(void) {
    /* Check and configure the system clock source */
#if RCC_SYSCLK == RCC_HSI
    /* Enable HSI and wait for stabilization */
    SET_BIT(RCC->RCC_CR, 0);
    while (!GET_BIT(RCC->RCC_CR, 1));

    /* Configure HSI as the system clock */
    CLEAR_BIT(RCC->RCC_CFGR, 0);
    CLEAR_BIT(RCC->RCC_CFGR, 1);

#elif RCC_SYSCLK == RCC_HSE
    /* Check and configure HSE mode */
    #if RCC_HSE_MODE == RCC_HSE_BYPASS
        SET_BIT(RCC->RCC_CR, 18);
    #elif RCC_HSE_MODE == RCC_HSE_CRYSTAL
        CLEAR_BIT(RCC->RCC_CR, 18);
    #endif

    /* Enable HSE and wait for stabilization */
    SET_BIT(RCC->RCC_CR, 16);
    while (!GET_BIT(RCC->RCC_CR, 17));

    /* Configure HSE as the system clock */
    SET_BIT(RCC->RCC_CFGR, 0);
    CLEAR_BIT(RCC->RCC_CFGR, 1);

#elif RCC_SYSCLK == RCC_PLL
    /* Check and configure PLL source */
    #if RCC_u32_PLL_SRC == RCC_u32_PLL_SRC_HSI
        SET_BIT(RCC->RCC_CR, 0);
        while (!GET_BIT(RCC->RCC_CR, 1));
        CLEAR_BIT(RCC->RCC_PLLCFGR, 22);
    #elif RCC_u32_PLL_SRC == RCC_u32_PLL_SRC_HSE
        #if RCC_HSE_MODE == RCC_HSE_BYPASS
            SET_BIT(RCC->RCC_CR, 18);
        #elif RCC_HSE_MODE == RCC_HSE_CRYSTAL
            CLEAR_BIT(RCC->RCC_CR, 18);
        #endif
        SET_BIT(RCC->RCC_CR, 16);
        while (!GET_BIT(RCC->RCC_CR, 17));
        SET_BIT(RCC->RCC_PLLCFGR, 22);
    #endif

    /* Configure PLL settings */
    RCC_PLLCFGR |= (RCC_u32_PLLM << 0);
    RCC_PLLCFGR |= (RCC_u32_PLLN << 6);
    switch (RCC_u32_PLLP) {
        case 2:
            CLEAR_BIT(RCC->RCC_CR, 16);
            CLEAR_BIT(RCC->RCC_CR, 17);
            break;
        case 4:
            SET_BIT(RCC->RCC_CR, 16);
            CLEAR_BIT(RCC->RCC_CR, 17);
            break;
        case 8:
            CLEAR_BIT(RCC->RCC_CR, 16);
            SET_BIT(RCC->RCC_CR, 17);
            break;
        case 16:
            SET_BIT(RCC->RCC_CR, 16);
            SET_BIT(RCC->RCC_CR, 17);
            break;
    }

    /* Enable PLL and wait for stabilization */
    SET_BIT(RCC->RCC_CR, 24);
    while (!GET_BIT(RCC->RCC_CR, 25));

    /* Configure PLL as the system clock */
    CLEAR_BIT(RCC->RCC_CFGR, 0);
    SET_BIT(RCC->RCC_CFGR, 1);

#else
    #error "Wrong System clock configuration" // Prevent building
#endif
}

/**
 * @brief Enable a peripheral on the specified bus.
 *
 * This function enables a peripheral on the specified bus.
 *
 * @param Copyu8PerName The peripheral name to be enabled.
 * @param Copyu8BUSNumber The bus number to which the peripheral is connected.
 */
void RCC_voidEnablePeripheral(u8 Copyu8PerName, u8 Copyu8BUSNumber) {
    switch (Copyu8BUSNumber) {
        case RCC_u8_AHB1_BUS:
            SET_BIT(RCC->RCC_AHB1ENR, Copyu8PerName);
            break;
        case RCC_u8_AHB2_BUS:
            SET_BIT(RCC->RCC_AHB2ENR, Copyu8PerName);
            break;
        case RCC_u8_APB1_BUS:
            SET_BIT(RCC->RCC_APB1ENR, Copyu8PerName);
            break;
        case RCC_u8_APB2_BUS:
            SET_BIT(RCC->RCC_APB2ENR, Copyu8PerName);
            break;
    }
}

/**
 * @brief Disable a peripheral on the specified bus.
 *
 * This function disables a peripheral on the specified bus.
 *
 * @param Copyu8PerName The peripheral name to be disabled.
 * @param Copyu8BUSNumber The bus number to which the peripheral is connected.
 */
void RCC_voidDisablePeripheral(u8 Copyu8PerName, u8 Copyu8BUSNumber) {
    switch (Copyu8BUSNumber) {
        case RCC_u8_AHB1_BUS:
            CLEAR_BIT(RCC->RCC_AHB1ENR, Copyu8PerName);
            break;
        case RCC_u8_AHB2_BUS:
            CLEAR_BIT(RCC->RCC_AHB2ENR, Copyu8PerName);
            break;
        case RCC_u8_APB1_BUS:
            CLEAR_BIT(RCC->RCC_APB1ENR, Copyu8PerName);
            break;
        case RCC_u8_APB2_BUS:
            CLEAR_BIT(RCC->RCC_APB2ENR, Copyu8PerName);
            break;
    }
}
