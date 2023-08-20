/*
 * RCC_voidInit
 * returns : void, error state
 * Desc: Init RCC
 * copyu8Clock:
 * 			1
 * 			2
 */
/*
 * File Name: RCC.Interface.h
 * Author:Yusuf Elsayed
 * Date: 8/8/2023
 * Desc: Prototypes and user use in main
 * Version: 2
 */

//ProtoTypes
#ifndef RCC_INTERFACE_H_
#define RCC_INTERFACE_H_

void RCC_voidInit(void);
/*
 * Function name: RCC_voidEnablePeripheral
 * return: void
 * Parameters:
 * 			1-Copyu8PerName:
 * 						//AHB1 Peripherals Clock enable
 * 							RCC_u8_AHB1ENR_GPIOA
 * 							RCC_u8_AHB1ENR_GPIOB
 * 							RCC_u8_AHB1ENR_GPIOC
 * 							RCC_u8_AHB1ENR_GPIOD
 * 							RCC_u8_AHB1ENR_GPIOE
 * 							RCC_u8 AHB1ENR GPIOH
 * 							RCC_u8_AHB1ENR_CRC
 * 							RCC_u8_AHB1ENR_DMA1
 * 							RCC_u8_AHB1ENR_DMA2
 * 						//AHB2 PREPHERALS CLOCK ENABLE
 * 							RCC_u8_AHB2_OTGFS
 * 						//APB1 PREPHERALS CLOCK ENABLE
 * 							RCC_u8_APB1ENR_TIM2RST
 * 							RCC_u8_APB1ENR_TIM3RST
 * 							RCC_u8_APB1ENR_TIM4RST
 * 							RCC_u8_APB1ENR_TIM5RST
 * 							RCC_u8_APB1ENR_WWDGRST
 * 							RCC_u8_APB1ENR_SPI2RST
 * 							RCC_u8_APB1ENR_SPI3RST
 * 							RCC_u8_APB1ENR_USART2RST
 * 							RCC_u8_APB1ENR_I2C1RST
 * 							RCC_u8_APB1ENR_I2C2RST
 * 							RCC_u8_APB1ENR_I2C3RST
 * 							RCC_u8_APB1ENR_PWRRST
 * 						//APB2 PREPHERALS CLOCK ENABLE
 * 							 RCC_u8_APB2ENR_TIM1RST
 * 							 RCC_u8_APB2ENR_USART1RST
 * 							 RCC_u8_APB2ENR_USART2RST
 * 							 RCC_u8_APB2ENR_ADC1RST
 * 							 RCC_u8_APB2ENR_SDI0RST
 * 							 RCC_u8_APB2ENR_SDI1RST
 * 							 RCC_u8_APB2ENR_SDI4RST
 * 							 RCC_u8_APB2ENR_SYSCFG
 * 							 RCC_u8_APB2ENR_TIM9RST
 * 							 RCC_u8_APB2ENR_TIM10RST
 * 							 RCC_u8_APB2ENR_TIM11RST
 * 			2- Copyu8BUSNumber
 * 						//BUSSES
 * 							RCC_u8_AHB1_BUS
 * 							RCC_u8_AHB2_BUS
 * 							RCC_u8_APB1_BUS
 * 							RCC_u8_APB2_BUS
 */
void RCC_voidEnablePeripheral(u8 Copyu8PerName, u8 Copyu8BUSNumber);
void RCC_voidDisablePeripheral(u8 Copyu8PerName, u8 Copyu8BUSNumber);

//BUSSES
#define RCC_u8_AHB1_BUS 0
#define RCC_u8_AHB2_BUS 1
#define RCC_u8_APB1_BUS 2
#define RCC_u8_APB2_BUS 3

//Peripherals IDS
//AHB1 Peripherals Clock enable
#define RCC_u8_AHB1ENR_GPIOA 0
#define RCC_u8_AHB1ENR_GPIOB 1
#define RCC_u8_AHB1ENR_GPIOC 2
#define RCC_u8_AHB1ENR_GPIOD 3
#define RCC_u8_AHB1ENR_GPIOE 4
#define RCC_u8 AHB1ENR GPIOH 7
#define RCC_u8_AHB1ENR_CRC 12
#define RCC_u8_AHB1ENR_DMA1 21
#define RCC_u8_AHB1ENR_DMA2 22

//AHB2 PREPHERALS CLOCK ENABLE
#define RCC_u8_AHB2_OTGFS 7

//APB1 PREPHERALS CLOCK ENABLE
#define  RCC_u8_APB1ENR_TIM2RST 0
#define  RCC_u8_APB1ENR_TIM3RST 1
#define  RCC_u8_APB1ENR_TIM4RST 2
#define  RCC_u8_APB1ENR_TIM5RST 3
#define  RCC_u8_APB1ENR_WWDGRST 11
#define  RCC_u8_APB1ENR_SPI2RST 14
#define  RCC_u8_APB1ENR_SPI3RST 15
#define  RCC_u8_APB1ENR_USART2RST 17
#define  RCC_u8_APB1ENR_I2C1RST 21
#define  RCC_u8_APB1ENR_I2C2RST 22
#define  RCC_u8_APB1ENR_I2C3RST 23
#define  RCC_u8_APB1ENR_PWRRST 28

//APB2 PREPHERALS CLOCK ENABLE
#define  RCC_u8_APB2ENR_TIM1RST 0
#define  RCC_u8_APB2ENR_USART1RST 4
#define  RCC_u8_APB2ENR_USART2RST 5
#define  RCC_u8_APB2ENR_ADC1RST 8
#define  RCC_u8_APB2ENR_SDI0RST 11
#define  RCC_u8_APB2ENR_SDI1RST 12
#define  RCC_u8_APB2ENR_SDI4RST 13
#define  RCC_u8_APB2ENR_SYSCFG 14
#define  RCC_u8_APB2ENR_TIM9RST 16
#define  RCC_u8_APB2ENR_TIM10RST 17
#define  RCC_u8_APB2ENR_TIM11RST 18


#endif
