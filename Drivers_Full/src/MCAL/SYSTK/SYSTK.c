/*
 * SYSTIC.c
 *
 *  Created on: Aug 15, 2023
 *      Author: yusuf
 */


#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_TYPES.h"
#include "SYSTK_config.h"
#include "SYSTK_interface.h"
#include "SYSTK_private.h"

//Check CLk in config
void STK_voidInit( void ){

#if CONFIG_CLKSOURCE == STK_AHB_DIV8
		CLEAR_BIT(STK->STK_CTRL, CONFIG_CLKSOURCE);
#elif CONFIG_CLKSOURCE == STK_AHB
		SET_BIT(STK->STK_CTRL, CONFIG_CLKSOURCE);
#endif

}
//Check EN in config
void STK_voidIntStatus( void ){
#if SYSTICK_INT_DISABLE == DISABLE
		CLEAR_BIT(STK->STK_CTRL, STK_CNTRL_ENABLE);
#elif SYSTICK_INT_DISABLE == ENABLE
		SET_BIT(STK->STK_CTRL, STK_CNTRL_ENABLE);
#endif
}

void STK_voidStart( u32 Copy_PreloadValue ){
	STK->STK_LOAD = Copy_PreloadValue ; /* Not -1 bec. MultiMode(periodic) */
	STK->STK_VAL = 0;
	SET_BIT(STK->STK_CTRL, STK_CNTRL_ENABLE);
}

/* 24bit so u32 */
u32 STK_u32GetElsapsedTime( void ){
	/* to be implemented */
}

u32 STK_u32GetReaminingTime( void ){
	/* to be implemented */
}

/* count Flag in CTRL*/
u8 STK_u8ReadFlag( void ){
	return GET_BIT(STK->STK_CTRL, STK_CTRL_COUNTFLAG);
}
void STK_voidDelayMS( u32 Copy_u32DelayMS ){
	/* to be implemented */
}
void STK_voidDelayUS( u32 Copy_u32DelayUS ){
	/* to be implemented */
}
void STK_voidSetCallBack( void (*ptr)(void) ){
	/* to be implemented */
}
