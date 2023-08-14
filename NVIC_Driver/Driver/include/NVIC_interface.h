/*******************************************/
/*                                         */
/*          NVIC_interface.h               */
/*                                         */
/*******************************************/

/**
 * @file NVIC_interface.h
 * @brief This file contains the interface for the Nested Vectored Interrupt Controller (NVIC) module.
 *
 * This module provides functions to configure and manage interrupts using the NVIC.
 *
 * @date Aug 14, 2023
 * @version 1.0
 * @author Yusuf-Elsayed
 */

#ifndef NVIC_INTERFACE_H_
#define NVIC_INTERFACE_H_

/*******************************************/
/*          Variable Declarations          */
/*******************************************/

/**
 * @var GLOBAL_GroupMode
 * @brief Global variable to store the currently configured group mode.
 */
u8 GLOBAL_GroupMode;

/**
 * @enum Group_t
 * @brief Enumeration representing different group and subgroup configurations for NVIC priority.
 */
typedef enum {
    NVIC_16G_0SG = 3, /**< 16 groups, 0 subgroups (0 bits for subpriority) */
    NVIC_8G_2SG,     /**< 8 groups, 2 subgroups (1 bit for subpriority) */
    NVIC_4G_4SG,     /**< 4 groups, 4 subgroups (2 bits for subpriority) */
    NVIC_2G_8SG,     /**< 2 groups, 8 subgroups (3 bits for subpriority) */
    NVIC_0G_16SG     /**< 0 groups, 16 subgroups (4 bits for subpriority) */
} Group_t;
/*******************************************************************************************************************/

/*******************************************/
/*           Function Prototypes           */
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
void NVIC_voidInterruptSetEnable(u8 copy_InterruptId);
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
void NVIC_voidInterruptClearEnable(u8 copy_InterruptId);
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
void NVIC_voidSetPending(u8 copy_InterruptId);
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
void NVIC_voidClearPending(u8 copy_InterruptId);
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
u8 NVIC_voidGetActiveBit(u8 copy_InterruptId);
/*******************************************************************************************************************/

/**
 * @brief Set the group mode for NVIC priority configuration.
 *
 * This function sets the group and subgroup configuration mode for NVIC priority.
 *
 * @param copy_groupType The desired group configuration type.
 */
void NVIC_voidSetGroupMode(Group_t copy_groupType);

/**
 * @brief Set the priority of an interrupt using NVIC_IPRx register.
 *
 * This function sets the priority of an interrupt based on the provided group and subgroup priorities.
 *
 * @param copy_InterruptId The ID of the interrupt to set priority.
 * @param Copy_u8GroupPriority The priority level for the group.
 * @param Copy_u8SubPriority The priority level for the subgroup.
 */
void NVIC_voidSetInterruptPriority(u8 copy_InterruptId, u8 Copy_u8GroupPriority, u8 Copy_u8SubPriority);
/*******************************************************************************************************************/

#endif /* NVIC_INTERFACE_H_ */
