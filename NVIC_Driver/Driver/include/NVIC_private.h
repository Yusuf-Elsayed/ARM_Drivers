/*******************************************/
/*                                         */
/*             NVIC_private.h              */
/*                                         */
/*******************************************/

/**
 * @file NVIC_private.h
 * @brief This file contains private definitions and macros for configuring the Nested Vector Interrupt Controller (NVIC).
 *
 * This file includes the necessary constants and macros to configure and manage the NVIC.
 * It is intended for internal use and should not be included or modified directly by the application.
 *
 * @date Aug 14, 2023
 * @author Yusuf-Elsayed
 */

#ifndef NVIC_PRIVATE_H_
#define NVIC_PRIVATE_H_

/*******************************************/
/* Structure representing NVIC registers   */
/*******************************************/

/**
 * @struct MNVIC_t
 * @brief Structure representing the Nested Vector Interrupt Controller (NVIC) registers.
 *
 * This structure defines the layout of NVIC registers for controlling and managing interrupts.
 * It is intended for internal use within the NVIC module and should not be accessed directly by the application.
 */
typedef struct {
	volatile u32 NVIC_ISER	[8]		;     /* Interrupt Set-Enable Registers (0x000 - 0x01C) */
    volatile u32 reserved1	[24]	;     /* Reserved space */
	volatile u32 NVIC_ICER	[8]		;     /* Interrupt Clear-Enable Registers (0x080 - 0x09C) */
    volatile u32 reserved2	[24]	;     /* Reserved space */
	volatile u32 NVIC_ISPR	[8]		;     /* Interrupt Set-Pending Registers (0x100 - 0x11C) */
    volatile u32 reserved3	[24]	;     /* Reserved space */
	volatile u32 NVIC_ICPR	[8]		;     /* Interrupt Clear-Pending Registers (0x180 - 0x19C) */
    volatile u32 reserved4	[24]	;     /* Reserved space */
	volatile u32 NVIC_IABR	[8];       	  /* Interrupt Active Bit Registers (0x200 - 0x21C) */
				  						  /* 0x400 - 0x31C =  E4 (228 decimal) / 4 (bytes for u32) = 57 - 1 (used) = 56 */
    volatile u32 reserved5	[56]	;     /*A Reserved space */
    									  /* NVIC_IPR0 --> NVIC_IPR59 EACH CONTAIN 4 REG) */
    volatile u32 NVIC_IPR	[60 * 4];	  /* Interrupt Priority Registers (0x300 - 0x4FC) */
             	                          /* 0xE00 - 0x4EC =  914 (2324 decimal) / 4 (bytes for u32) = 581 - 1 (used) = 580 */
    volatile u32 reserved6	[580]	;     /* Reserved space */
	volatile u32 NVIC_STIR			;     /* Software Trigger Interrupt Register (0xE00) */
} MNVIC_t;

/**
 * @def NVIC_BaseAdress
 * @brief Base address of the NVIC peripheral.
 */
#define NVIC_BaseAdress 0xE000E100

/**
 * @def NVIC
 * @brief Pointer to the NVIC peripheral base address.
 */
#define NVIC ((volatile MNVIC_t*) NVIC_BaseAdress)

/**
 * @def AIRCR
 * @brief Application Interrupt and Reset Control Register (in SCB).
 */
#define AIRCR *((volatile u32*) 0xE000ED0C)

/**
 * @def VECTKEY
 * @brief Value used for unlocking write access to certain control registers.
 */
#define VECTKEY 0x05FA0000   /* VECTKEY field, otherwise the processor ignores the write */

#define Reg_bits 32 		/* Number of bits in a register. */
#endif /* NVIC_PRIVATE_H_ */
