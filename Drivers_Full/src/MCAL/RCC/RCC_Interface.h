/*
 * File Name: RCC_Interface.h
 * Author: Yusuf Elsayed
 * Date: 8/8/2023
 * Description: Prototypes and user-use in the main program for RCC (Reset and Clock Control) module.
 * Version: 2
 */

#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

/**
 * @brief Initialize the RCC module.
 *
 * This function initializes the Reset and Clock Control module.
 *
 * @return void
 */
void RCC_voidInit(void);

/**
 * @brief Enable peripheral clock.
 *
 * This function enables the clock for the specified peripheral.
 *
 * @param Copyu8PerName: Peripheral identifier.
 * @param Copyu8BUSNumber: Bus number where the peripheral is connected.
 *
 * @return void
 */
void RCC_voidEnablePeripheral(u8 Copyu8PerName, u8 Copyu8BUSNumber);

/**
 * @brief Disable peripheral clock.
 *
 * This function disables the clock for the specified peripheral.
 *
 * @param Copyu8PerName: Peripheral identifier.
 * @param Copyu8BUSNumber: Bus number where the peripheral is connected.
 *
 * @return void
 */
void RCC_voidDisablePeripheral(u8 Copyu8PerName, u8 Copyu8BUSNumber);

/* Bus numbers */
#define RCC_u8_AHB1_BUS 0
#define RCC_u8_AHB2_BUS 1
#define RCC_u8_APB1_BUS 2
#define RCC_u8_APB2_BUS 3

/* Peripheral IDs */
/* AHB1 Peripherals Clock enable */
#define RCC_u8_AHB1ENR_GPIOA 0
#define RCC_u8_AHB1ENR_GPIOB 1
#define RCC_u8_AHB1ENR_GPIOC 2
#define RCC_u8_AHB1ENR_GPIOD 3
#define RCC_u8_AHB1ENR_GPIOE 4
#define RCC_u8_AHB1ENR_GPIOH 7
#define RCC_u8_AHB1ENR_CRC 12
#define RCC_u8_AHB1ENR_DMA1 21
#define RCC_u8_AHB1ENR_DMA2 22

/* AHB2 PREPHERALS CLOCK ENABLE */
#define RCC_u8_AHB2_OTGFS 7

/* APB1 PREPHERALS CLOCK ENABLE */
#define RCC_u8_APB1ENR_TIM2RST 0
#define RCC_u8_APB1ENR_TIM3RST 1
#define RCC_u8_APB1ENR_TIM4RST 2
#define RCC_u8_APB1ENR_TIM5RST 3
#define RCC_u8_APB1ENR_WWDGRST 11
#define RCC_u8_APB1ENR_SPI2RST 14
#define RCC_u8_APB1ENR_SPI3RST 15
#define RCC_u8_APB1ENR_USART2RST 17
#define RCC_u8_APB1ENR_I2C1RST 21
#define RCC_u8_APB1ENR_I2C2RST 22
#define RCC_u8_APB1ENR_I2C3RST 23
#define RCC_u8_APB1ENR_PWRRST 28

/* APB2 PREPHERALS CLOCK ENABLE */
#define RCC_u8_APB2ENR_TIM1RST 0
#define RCC_u8_APB2ENR_USART1RST 4
#define RCC_u8_APB2ENR_USART2RST 5
#define RCC_u8_APB2ENR_ADC1RST 8
#define RCC_u8_APB2ENR_SDI0RST 11
#define RCC_u8_APB2ENR_SDI1RST 12
#define RCC_u8_APB2ENR_SDI4RST 13
#define RCC_u8_APB2ENR_SYSCFG 14
#define RCC_u8_APB2ENR_TIM9RST 16
#define RCC_u8_APB2ENR_TIM10RST 17
#define RCC_u8_APB2ENR_TIM11RST 18

#endif /* RCC_INTERFACE_H_ */
