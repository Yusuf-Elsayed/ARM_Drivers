/**
 * @file EXTI_private.h
 * @brief This file contains private definitions and macros for the External Interrupt (EXTI) module.
 *
 * This file includes the necessary constants and macros for configuring and managing the EXTI module.
 * It defines the register structures, base addresses, and masks for EXTI and related peripherals.
 *
 * @date Aug 14, 2023
 * @author Yusuf-Elsayed
 */

#ifndef MCAL_EXTI_EXTI_PRIVATE_H_
#define MCAL_EXTI_EXTI_PRIVATE_H_



/* Masks for configuring EXTI pins */

/* Mask values for SYSCFG_EXTICR1, SYSCFG_EXTICR2, SYSCFG_EXTICR3, and SYSCFG_EXTICR4 for Port A */
#define EXT1_CONFIG_MASK1A 0xFFFFFFF0
#define EXT1_CONFIG_MASK2A 0xFFFFFF0F
#define EXT1_CONFIG_MASK3A 0xFFFFF0FF
#define EXT1_CONFIG_MASK4A 0xFFFF0FFF

/* Mask values for SYSCFG_EXTICR1, SYSCFG_EXTICR2, SYSCFG_EXTICR3, and SYSCFG_EXTICR4 for Port B */
#define EXT1_CONFIG_MASK1B 0xFFFFFFF1
#define EXT1_CONFIG_MASK2B 0xFFFFFF1F
#define EXT1_CONFIG_MASK3B 0xFFFFF1FF
#define EXT1_CONFIG_MASK4B 0xFFFF1FFF

/* Mask values for SYSCFG_EXTICR4 for Port C (only pins 13, 14, and 15) */
#define EXT1_CONFIG_MASK2C 0xFFFFFF2F
#define EXT1_CONFIG_MASK3C 0xFFFFF2FF
#define EXT1_CONFIG_MASK4C 0xFFFF2FFF

/**
 * @struct EXTI_t
 * @brief Structure representing the External Interrupt (EXTI) registers.
 *
 * This structure defines the layout of EXTI registers for configuring and managing external interrupts.
 * It is intended for internal use within the EXTI module and should not be accessed directly by the application.
 */
typedef struct {
    volatile u32 EXTI_IMR;
    volatile u32 EXTI_EMR;
    volatile u32 EXTI_RTSR;
    volatile u32 EXTI_FTSR;
    volatile u32 EXTI_SWIER;
    volatile u32 EXTI_PR;
} EXTI_t;

/**
 * @def EXTI_Base_Adderss
 * @brief Base address of the EXTI peripheral.
 */
#define EXTI_Base_Adderss 0x40013C00

/**
 * @def EXTI
 * @brief Pointer to the EXTI peripheral base address.
 */
#define EXTI ((volatile EXTI_t*) EXTI_Base_Adderss)

/**
 * @def SYSCFG_EXTICR1_BaseAdress
 * @brief Base address of the SYSCFG_EXTICR1 register.
 */
#define SYSCFG_EXTICR1_BaseAdress 0x400380C

/**
 * @def SYSCFG_EXTICR2_BaseAdress
 * @brief Base address of the SYSCFG_EXTICR2 register.
 */
#define SYSCFG_EXTICR2_BaseAdress 0x4003810

/**
 * @def SYSCFG_EXTICR3_BaseAdress
 * @brief Base address of the SYSCFG_EXTICR3 register.
 */
#define SYSCFG_EXTICR3_BaseAdress 0x4003814

/**
 * @def SYSCFG_EXTICR4_BaseAdress
 * @brief Base address of the SYSCFG_EXTICR4 register.
 */
#define SYSCFG_EXTICR4_BaseAdress 0x4003820

/**
 * @def SYSCFG_EXTICR1
 * @brief Pointer to the SYSCFG_EXTICR1 register.
 */
#define SYSCFG_EXTICR1 ((volatile u32*) SYSCFG_EXTICR1_BaseAdress)

/**
 * @def SYSCFG_EXTICR2
 * @brief Pointer to the SYSCFG_EXTICR2 register.
 */
#define SYSCFG_EXTICR2 ((volatile u32*) SYSCFG_EXTICR2_BaseAdress)

/**
 * @def SYSCFG_EXTICR3
 * @brief Pointer to the SYSCFG_EXTICR3 register.
 */
#define SYSCFG_EXTICR3 ((volatile u32*) SYSCFG_EXTICR3_BaseAdress)

/**
 * @def SYSCFG_EXTICR4
 * @brief Pointer to the SYSCFG_EXTICR4 register.
 */
#define SYSCFG_EXTICR4 ((volatile u32*) SYSCFG_EXTICR4_BaseAdress)

#endif /* MCAL_EXTI_EXTI_PRIVATE_H_ */
