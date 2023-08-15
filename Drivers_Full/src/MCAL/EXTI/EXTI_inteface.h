/**
 * @file EXTI_interface.h
 * @brief This file contains the interface for configuring and managing the External Interrupt (EXTI) module.
 *
 * This module provides functions to enable, disable, initialize, and trigger software interrupts for EXTI lines.
 * It also includes functions for setting configuration and callback functions for specific EXTI lines.
 *
 * @date Aug 14, 2023
 * @author Yusuf-Elsayed
 */

#ifndef MCAL_EXTI_EXTI_INTERFACE_H_
#define MCAL_EXTI_EXTI_INTERFACE_H_

/**
 * @enum EXTI_LINE_t
 * @brief Enumeration representing different EXTI lines.
 */
typedef enum {
    EXTILINE_0 = 0,
    EXTILINE_1,
    EXTILINE_2,
    EXTILINE_3,
    EXTILINE_4,
    EXTILINE_5,
    EXTILINE_6,
    EXTILINE_7,
    EXTILINE_8,
    EXTILINE_9,
    EXTILINE_10,
    EXTILINE_11,
    EXTILINE_12,
    EXTILINE_13,
    EXTILINE_14,
    EXTILINE_15
} EXTI_LINE_t;

/**
 * @enum EXTI_TriggerMode_t
 * @brief Enumeration representing different trigger modes for EXTI lines.
 */
typedef enum {
    EXTI_RISING_EDGE,
    EXTI_FALLING_EDGE,
    EXTI_ONCHANGE_EDGE
} EXTI_TriggerMode_t;

/**
 * @enum EXTI_Port_t
 * @brief Enumeration representing different GPIO ports for EXTI configuration.
 */
typedef enum {
    EXTI_PORTA,
    EXTI_PORTB,
    EXTI_PORTC
} EXTI_Port_t;

/**
 * @brief Enable the given EXTI line.
 *
 * This function enables the EXTI line specified by the line number.
 *
 * @param copy_tLineNum The EXTI line number to be enabled.
 */
void EXTI_voidEnable(u8 copy_tLineNum);

/**
 * @brief Disable the given EXTI line.
 *
 * This function disables the EXTI line specified by the line number.
 *
 * @param copy_tLineNum The EXTI line number to be disabled.
 */
void EXTI_voidDisable(u8 copy_tLineNum);

/**
 * @brief Initialize the EXTI line with the specified trigger mode.
 *
 * This function initializes the EXTI line specified by the line number with the specified trigger mode.
 *
 * @param copy_tLineNum The EXTI line number to be initialized.
 * @param copy_tTriggerMode The trigger mode for the EXTI line (rising edge, falling edge, or both edges).
 */
void EXTI_voidInit(u8 copy_tLineNum, u8 copy_tTriggerMode);

/**
 * @brief Trigger a software interrupt on the given EXTI line.
 *
 * This function triggers a software interrupt on the EXTI line specified by the line number.
 *
 * @param copy_tLineNum The EXTI line number to trigger a software interrupt.
 */
void EXTI_voidSoftwareInterrupt(u8 copy_tLineNum);

/**
 * @brief Set the configuration for the given EXTI line.
 *
 * This function sets the configuration for the EXTI line specified by the line number and GPIO port.
 *
 * @param copy_tLineNum The EXTI line number to set configuration.
 * @param copy_tGpioPortNum The GPIO port for the EXTI line configuration.
 */
void EXTI_voidSetConfig(EXTI_LINE_t copy_tLineNum, u8 copy_tGpioPortNum);

/**
 * @brief Set the callback function for EXTI line 0.
 *
 * This function sets the callback function for EXTI line 0.
 *
 * @param ptr Pointer to the callback function.
 */
void EXTI0_voidCallBack(void (*ptr)(void));

/**
 * @brief Set the callback function for EXTI line 1.
 *
 * This function sets the callback function for EXTI line 1.
 *
 * @param ptr Pointer to the callback function.
 */
void EXTI1_voidCallBack(void (*ptr)(void));

#endif /* MCAL_EXTI_EXTI_INTERFACE_H_ */
