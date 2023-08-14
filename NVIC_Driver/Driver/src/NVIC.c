/*******************************************/
/*                                         */
/*                NVIC.c                   */
/*                                         */
/*******************************************/

/**
 * @file NVIC.c
 * @brief This file contains the implementation of functions for configuring and managing interrupts using the Nested Vector Interrupt Controller (NVIC) module.
 *
 * This module provides functions to enable, disable, set pending, clear pending, check active status,
 * set group mode, and set interrupt priority using the NVIC.
 *
 * @date Aug 14, 2023
 * @version 1.0
 * @author Yusuf-Elsayed
 */

#include "BIT_MATHS.h"
#include "STD_TYPES.h"
#include <NVIC_private.h>
#include <NVIC_Interface.h>
#include <NVIC_config.h>

/*******************************************/
/*           API's Definitions             */
/*******************************************/

/**
 * @brief Enable interrupt of the given ID using NVIC_ISERx register.
 *
 * This function enables the interrupt corresponding to the provided ID.
 *
 * @param copy_InterruptId The ID of the interrupt to be enabled.
 *
 * Write: (atomic)
 * 		0: No effect
 * 		1: Enable interrupt
 * Read:
 * 		0: Interrupt disabled
 * 		1: Interrupt enabled.
 */
void NVIC_voidInterruptSetEnable(u8 copy_InterruptId){
	u8 interruptRegNum = copy_InterruptId / Reg_bits;
	u8 RegBitNum = copy_InterruptId % Reg_bits;
	NVIC->NVIC_ISER[interruptRegNum] |= (1<<RegBitNum);
}
/*******************************************************************************************************************/

/**
 * @brief Disable interrupt of the given ID using NVIC_ICERx register.
 *
 * This function disables the interrupt corresponding to the provided ID.
 *
 * @param copy_InterruptId The ID of the interrupt to be disabled.
 *
 * Write: (atomic)
 * 		0: No effect
 * 		1:  Disable interrupt
 * Read:
 * 		0: Interrupt disabled
 * 		1: Interrupt enabled.
 */
void NVIC_voidInterruptClearEnable(u8 copy_InterruptId){
	u8 interruptRegNum = copy_InterruptId / Reg_bits;
	u8 RegBitNum = copy_InterruptId % Reg_bits;
	NVIC->NVIC_ICER[interruptRegNum] |= (1<<RegBitNum);
}
/*******************************************************************************************************************/

/**
 * @brief Set pending state for the given interrupt ID using NVIC_ISPRx register.
 *
 * This function sets the pending state for the interrupt corresponding to the provided ID.
 *
 * @param copy_InterruptId The ID of the interrupt to set pending.
 *
 * Write: (atomic)
 * 		0: No effect
 * 		1: Changes interrupt state to pending
 * Read:
 * 		0: Interrupt is not pending
 * 		1: Interrupt is pending
 */
void NVIC_voidSetPending(u8 copy_InterruptId){
	u8 interruptRegNum = copy_InterruptId / Reg_bits;
	u8 RegBitNum = copy_InterruptId % Reg_bits;
	NVIC->NVIC_ISPR[interruptRegNum] |= (1<<RegBitNum);
}
/*******************************************************************************************************************/

/**
 * @brief Clear pending state for the given interrupt ID using NVIC_ICPRx register.
 *
 * This function clears the pending state for the interrupt corresponding to the provided ID.
 *
 * @param copy_InterruptId The ID of the interrupt to clear pending.
 *
* Write: (atomic)
 * 		0: No effect
 * 		1:  Removes the pending state of an interrupt
 * Read:
 * 		0: Interrupt is not pending
 * 		1: Interrupt is pending
 */
void NVIC_voidClearPending(u8 copy_InterruptId){
	u8 interruptRegNum = copy_InterruptId / Reg_bits;
	u8 RegBitNum = copy_InterruptId % Reg_bits;
	NVIC->NVIC_ICPR[interruptRegNum] |= (1<<RegBitNum);
}
/*******************************************************************************************************************/

/**
 * @brief Check if an interrupt is currently active for the given interrupt ID using NVIC_IABRx register.
 *
 * This function checks whether the interrupt corresponding to the provided ID is currently active.
 *
 * @param copy_InterruptId The ID of the interrupt to check for activity.
 *
 * Interrupt active flags
 *  	0: Interrupt not active
 *  	1: Interrupt active
 *
 * @return u8 Returns 0 if the interrupt is not active, and 1 if the interrupt is active.
 */
u8 NVIC_voidGetActiveBit(u8 copy_InterruptId){
	return GET_BIT(NVIC->NVIC_IABR[copy_InterruptId / Reg_bits], copy_InterruptId % Reg_bits);
	/* 1: Interrupt active */	/*0: Interrupt not active */
}
/*******************************************************************************************************************/

/**
 * @brief Set the group mode for NVIC priority configuration.
 *
 * This function sets the group and subgroup configuration mode for NVIC priority.
 *
 * @param copy_groupType The desired group configuration type.
 *
 * It's important to call this function first before setting interrupt priorities using NVIC_voidSetInterruptPriority.
 */
void NVIC_voidSetGroupMode(Group_t copy_groupType){
	GLOBAL_GroupMode = copy_groupType;
	AIRCR = VECTKEY | (copy_groupType << 8); 	/* set PRIGROUP in SCB at bit 8, 9, 10 | with VECTKEY field */
}
/*******************************************************************************************************************/

/**
 * @brief Set the priority of an interrupt using NVIC_IPRx register.
 *
 * This function sets the priority of an interrupt based on the provided group and subgroup priorities.
 *
 * @param copy_InterruptId The ID of the interrupt to set priority.
 * @param Copy_u8GroupPriority The priority level for the group.
 * @param Copy_u8SubPriority The priority level for the subgroup.
 */
void NVIC_voidSetInterruptPriority(u8 copy_InterruptId, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority) {
    switch(GLOBAL_GroupMode) {
        case NVIC_16G_0SG:
            NVIC->NVIC_IPR[copy_InterruptId] = (Copy_u8GroupPriority << 4);		/* Only set the Group priority */
            break;
        case NVIC_8G_2SG:
            NVIC->NVIC_IPR[copy_InterruptId] = (Copy_u8GroupPriority << 5);		/* Set Group priority in bits 7:5 */
            NVIC->NVIC_IPR[copy_InterruptId] &= ~(0b0001 << 4); 				/* Clear subgroup priority bits */
            NVIC->NVIC_IPR[copy_InterruptId] |= (Copy_u8SubPriority << 4); 		/* Set subgroup priority bit 4 */
            break;
        case NVIC_4G_4SG:
			NVIC->NVIC_IPR[copy_InterruptId] = (Copy_u8GroupPriority << 6);		/* Set Group priority in bits 7:6 */
			NVIC->NVIC_IPR[copy_InterruptId] &= ~(0b0011 << 4); 				/* Clear subgroup priority bits */
			NVIC->NVIC_IPR[copy_InterruptId] |= (Copy_u8SubPriority << 4); 		/* Set subgroup priority bits 5:4 */
			break;
        case NVIC_2G_8SG:
			NVIC->NVIC_IPR[copy_InterruptId] = (Copy_u8GroupPriority << 7);		/* Set Group priority in bit 7 */
			NVIC->NVIC_IPR[copy_InterruptId] &= ~(0b0111 << 4); 				/* Clear subgroup priority bits */
			NVIC->NVIC_IPR[copy_InterruptId] |= (Copy_u8SubPriority << 4); 		/* Set subgroup priority bits 6:4 */
			break;
        case NVIC_0G_16SG:
			NVIC->NVIC_IPR[copy_InterruptId] |= (Copy_u8SubPriority << 4); 		/* Only set the subgroup priority */
			break;
    }
}
/*******************************************************************************************************************/
