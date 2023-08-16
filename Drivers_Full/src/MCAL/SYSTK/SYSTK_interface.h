/*
 * SYSTIC_interface.h
 *
 *  Created on: Aug 15, 2023
 *      Author: yusuf
 */

#ifndef MCAL_SYSTK_SYSTK_INTERFACE_H_
#define MCAL_SYSTK_SYSTK_INTERFACE_H_

/*
 * Bit 2: CLKSOURCE - Clock source selection
 * Bit 1: TICKINT   - SysTick exception request enable
 * Bit 0: ENABLE    - Counter enable
*/
//Check CLk in config
void STK_voidInit( void );
//Check EN in config
void STK_voidIntStatus( void );

void STK_voidStart( u32 Copy_PreloadValue );

/* 24bit so u32 */
u32 STK_u32GetElsapsedTime( void );

u32 STK_u32GetReaminingTime( void );

/* count Flag in CTRL*/
u8 STK_u8ReadFlag( void );

void STK_voidDelayMS( u32 Copy_u32DelayMS );

void STK_voidDelayUS( u32 Copy_u32DelayUS );

void STK_voidSetCallBack( void (*ptr)(void) );

#endif /* MCAL_SYSTK_SYSTK_INTERFACE_H_ */
