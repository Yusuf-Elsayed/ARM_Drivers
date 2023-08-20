/*
 * RCC.c
 *
 *  Created on: Aug 7, 2023
 *      Author: yusuf
 */
#include "../../LIB/BIT_MATHS.h"
#include "../../LIB/STD_TYPES.h"
#include "RCC_private.h"
#include "RCC_Interface.h"
#include "RCC_config.h"




void RCC_voidInit(void){
	//preprocessor not to compiled
#if RCC_SYSCLK==RCC_HSI
	SET_BIT(RCC->RCC_CR, 0); 		//HSI Enable
	while(!GET_BIT(RCC->RCC_CR,1));	//stabilization HSIREADY

	CLEAR_BIT(RCC->RCC_CFGR,0);		//00: HSI oscillator selected as system clock
	CLEAR_BIT(RCC->RCC_CFGR,1);		//RCC CFGR

#elif RCC_SYSCLK==RCC_HSE
	//CRYSTAL OR BYPASS (RCC_CR)
	#if RCC_HSE_MODE==RCC_HSE_BYPASS
	SET_BIT(RCC->RCC_CR, 18);		//select HSE clock BYPASS

	#elif RCC_HSE_MODE==RCC_HSE_CRYSTAL
	CLEAR_BIT(RCC->RCC_CR, 18); 	//select HSE clock CRYSTAL

	#endif

	SET_BIT(RCC->RCC_CR, 16); 		//HSE Enable
	while(!GET_BIT(RCC->RCC_CR,17));//stabilization HSEREADY

	SET_BIT(RCC->RCC_CFGR, 0);		//01: HSE oscillator selected as system clock
	CLEAR_BIT(RCC->RCC_CFGR, 1);	//RCC CFGR

#elif RCC_SYSCLK==RCC_PLL
	#if RCC_u32_PLL_SRC==RCC_u32_PLL_SRC_HSI
	SET_BIT(RCC->RCC_CR, 0); 		//HSI Enable
	while(!GET_BIT(RCC->RCC_CR,1));	//stabilization HSIREADY

	CLEAR_BIT(RCC->RCC_PLLCFGR, 22);

	#elif RCC_u32_PLL_SRC==RCC_u32_PLL_SRC_HSE
	//CRYSTAL OR BYPASS (RCC_CR)
		#if RCC_HSE_MODE==RCC_HSE_BYPASS
		SET_BIT(RCC->RCC_CR, 18);		//select HSE clock BYPASS

		#elif RCC_HSE_MODE==RCC_HSE_CRYSTAL
		CLEAR_BIT(RCC->RCC_CR, 18); 	//select HSE clock CRYSTAL

		#endif
	SET_BIT(RCC->RCC_CR, 16); 		//HSE Enable
	while(!GET_BIT(RCC->RCC_CR,17));//stabilization HSEREADY

	SET_BIT(RCC->RCC_PLLCFGR, 22);

	#endif
	/* PLLM */
	RCC_PLLCFGR |= (RCC_u32_PLLM<<0);
	/* PLLN */
	RCC_PLLCFGR |= (RCC_u32_PLLM<<6);
	/* PLLP */
	switch(RCC_u32_PLLP){
	case 2:
		CLEAR_BIT(RCC->RCC_CR,16);
		CLEAR_BIT(RCC->RCC_CR,17);
		break;
	case 4:
		SET_BIT(RCC->RCC_CR,16);
		CLEAR_BIT(RCC->RCC_CR,17);
		break;
	case 4:
		CLEAR_BIT(RCC->RCC_CR,16);
		SET_BIT(RCC->RCC_CR,17);
		break;
	case 4:
		SET_BIT(RCC->RCC_CR,16);
		SET_BIT(RCC->RCC_CR,17);
		break;
	}
	SET_BIT(RCC->RCC_CR, 24); 		//PLL Enable
	while(!GET_BIT(RCC->RCC_CR,25));//stabilization PLL
	CLEAR_BIT(RCC->RCC_CFGR, 0);	//10: PLL selected as system clock
	SET_BIT(RCC->RCC_CFGR, 1);		//CFGR

#else
	#error	"Wrong System clock not config"	//no build
#endif

}
// POST NOT PRE
void RCC_voidEnablePeripheral(u8 Copyu8PerName, u8 Copyu8BUSNumber){
	switch(Copyu8BUSNumber){
		case RCC_u8_AHB1_BUS:
	           SET_BIT(RCC->RCC_AHB1ENR, Copyu8PerName);
			break;
		case RCC_u8_AHB2_BUS:
			SET_BIT(RCC->RCC_AHB2ENR, Copyu8PerName);
			break;
		case RCC_u8_APB1_BUS:
			SET_BIT(RCC->RCC_APB1ENR, Copyu8PerName);
			break;
		case RCC_u8_APB2_BUS:
			SET_BIT(RCC->RCC_APB2ENR, Copyu8PerName);
			break;
	}
}
void RCC_voidDisablePeripheral(u8 Copyu8PerName, u8 Copyu8BUSNumber){
	switch(Copyu8BUSNumber){
		case RCC_u8_AHB1_BUS:
			CLEAR_BIT(RCC->RCC_AHB1ENR, Copyu8PerName);
			break;
		case RCC_u8_AHB2_BUS:
			CLEAR_BIT(RCC->RCC_AHB2ENR, Copyu8PerName);
			break;
		case RCC_u8_APB1_BUS:
			CLEAR_BIT(RCC->RCC_APB1ENR, Copyu8PerName);
			break;
		case RCC_u8_APB2_BUS:
			CLEAR_BIT(RCC->RCC_APB2ENR, Copyu8PerName);
			break;
	}
}
