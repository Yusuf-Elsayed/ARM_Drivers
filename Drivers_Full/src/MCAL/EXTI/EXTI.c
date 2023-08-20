/*
 * EXTI.c
 *
 *  Created on: Aug 14, 2023
 *      Author: Yusuf-Elsayed
 */

#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_TYPES.h"
#include "EXTI_private.h"
#include "EXTI_inteface.h"
#include "EXTI_Config.h"

/* Static callback function pointers */
static void (*EXTI0_CallBack)(void) = NULL;
static void (*EXTI1_CallBack)(void) = NULL;

/**
 * @brief Enable the specified EXTI line.
 *
 * This function enables the specified EXTI line.
 *
 * @param copy_tLineNum The EXTI line number to be enabled.
 */
void EXTI_voidEnable(u8 copy_tLineNum) {
    SET_BIT(EXTI->EXTI_IMR, copy_tLineNum);
}

/**
 * @brief Disable the specified EXTI line.
 *
 * This function disables the specified EXTI line.
 *
 * @param copy_tLineNum The EXTI line number to be disabled.
 */
void EXTI_voidDisable(u8 copy_tLineNum) {
    CLEAR_BIT(EXTI->EXTI_IMR, copy_tLineNum);
}

/**
 * @brief Initialize the specified EXTI line with the specified trigger mode.
 *
 * This function initializes the specified EXTI line with the specified trigger mode.
 *
 * @param copy_tLineNum The EXTI line number to be initialized.
 * @param copy_tTriggerMode The trigger mode for the EXTI line.
 */
void EXTI_voidInit(u8 copy_tLineNum, u8 copy_tTriggerMode) {
    switch (copy_tTriggerMode) {
        case EXTI_RISING_EDGE:
            SET_BIT(EXTI->EXTI_RTSR, copy_tLineNum);
            break;
        case EXTI_FALLING_EDGE:
            SET_BIT(EXTI->EXTI_FTSR, copy_tLineNum);
            break;
        case EXTI_ONCHANGE_EDGE:
            SET_BIT(EXTI->EXTI_RTSR, copy_tLineNum);
            SET_BIT(EXTI->EXTI_FTSR, copy_tLineNum);
            break;
        default:
            /* Do nothing */
            break;
    }
}

/**
 * @brief Trigger a software interrupt on the specified EXTI line.
 *
 * This function triggers a software interrupt on the specified EXTI line.
 *
 * @param copy_tLineNum The EXTI line number to trigger a software interrupt.
 */
void EXTI_voidSoftwareInterrupt(u8 copy_tLineNum) {
    SET_BIT(EXTI->EXTI_SWIER, copy_tLineNum);
}

/**
 * @brief Set the configuration for the specified EXTI line.
 *
 * This function sets the configuration for the specified EXTI line and GPIO port.
 *
 * @param copy_tLineNum The EXTI line number to set configuration.
 * @param copy_tGpioPortNum The GPIO port for the EXTI line configuration.
 */
void EXTI_voidSetConfig(EXTI_LINE_t copy_tLineNum, u8 copy_tGpioPortNum) {
    u32* exticr_register = NULL;  // Pointer to the appropriate EXTI configuration register

    // Determine the EXTI configuration register based on the EXTI line number
    if (copy_tLineNum < 4) {
        exticr_register = SYSCFG_EXTICR1;
    } else if (copy_tLineNum < 8) {
        exticr_register = SYSCFG_EXTICR2;
    } else if (copy_tLineNum < 12) {
        exticr_register = SYSCFG_EXTICR3;
    } else if (copy_tLineNum < 16) {
        exticr_register = SYSCFG_EXTICR4;
    } else {
        // Invalid EXTI line number
        return;
    }

    // Calculate the bit position within the register
    u8 bit_position = (copy_tLineNum % 4) * 4;

    // Clear the existing configuration for the specific EXTI line
    *exticr_register &= ~(0x0F << bit_position);

    // Set the new configuration based on the GPIO port
    switch (copy_tGpioPortNum) {
        case EXTI_PORTA:
            *exticr_register |= (0x00 << bit_position);
            break;
        case EXTI_PORTB:
            *exticr_register |= (0x01 << bit_position);
            break;
        case EXTI_PORTC:
            *exticr_register |= (0x02 << bit_position);
            break;
        default:
            // Invalid GPIO port
            break;
    }
}


/**
 * @brief Set the callback function for EXTI line 1.
 *
 * This function sets the callback function for EXTI line 1.
 *
 * @param ptr Pointer to the callback function.
 */
void EXTI1_voidCallBack(void (*ptr)(void)) {
	EXTI1_CallBack = ptr;
}

/**
 * @brief EXTI1 interrupt handler.
 *
 * This function is the interrupt handler for EXTI line 1.
 * It executes the registered callback function (if any) when the interrupt occurs.
 */
void EXTI1_IRQHandler(void) {
	if (EXTI1_CallBack != NULL) {
		EXTI1_CallBack();
	}
}

