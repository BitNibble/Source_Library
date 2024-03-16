/******************************************************************************
	STM32 XXX TIM 1 and 8
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 2262023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxtim1and8.h"

/*** File Variables ***/
static STM32FXXXTIM1obj stm32fxxx_tim1;
#ifdef STM32F446xx
	static STM32FXXXTIM8obj stm32fxxx_tim8;
#endif
/************/
/*** TIM1 ***/
/************/
void STM32FXXXTim1Clock(uint8_t bool)
{
	if(bool){RCC->APB2ENR |= (1 << 0);}else{RCC->APB2ENR &= ~(1 << 0);}
}
void STM32FXXXTim1Nvic(uint8_t value)
{ // 24, 25, 26, 27
	switch(value){
		case 0b1000:
			setbit(NVIC->ISER, 1, TIM1_BRK_TIM9_IRQn, 1);
		break;
		case 0b0100:
			setbit(NVIC->ISER, 1, TIM1_UP_TIM10_IRQn, 1);
		break;
		case 0b0010:
			setbit(NVIC->ISER, 1, TIM1_TRG_COM_TIM11_IRQn, 1);
		break;
		case 0b0001:
			setbit(NVIC->ISER, 1, TIM1_CC_IRQn, 1);
		break;
		case 0b11000:
			setbit(NVIC->ICER, 1, TIM1_BRK_TIM9_IRQn, 1);
		break;
		case 0b10100:
			setbit(NVIC->ICER, 1, TIM1_UP_TIM10_IRQn, 1);
		break;
		case 0b10010:
			setbit(NVIC->ICER, 1, TIM1_TRG_COM_TIM11_IRQn, 1);
		break;
		case 0b10001:
			setbit(NVIC->ICER, 1, TIM1_CC_IRQn, 1);
		break;
	default:
	break;
	}
}
#ifdef STM32F446xx
/************/
/*** TIM8 ***/
/************/
void STM32FXXXTim8Clock(uint8_t bool)
{
	if(bool){RCC->APB2ENR |= (1 << 1);}else{RCC->APB2ENR &= ~(1 << 1);}
}
void STM32FXXXTim8Nvic(uint8_t value)
{ // 43, 44, 45, 46
	switch(value){
		case 0b1000:
			setbit(NVIC->ISER, 1, TIM8_BRK_TIM12_IRQn, 1);
		break;
		case 0b0100:
			setbit(NVIC->ISER, 1, TIM8_UP_TIM13_IRQn, 1);
		break;
		case 0b0010:
			setbit(NVIC->ISER, 1, TIM8_TRG_COM_TIM14_IRQn, 1);
		break;
		case 0b0001:
			setbit(NVIC->ISER, 1, TIM8_CC_IRQn, 1);
		break;
		case 0b11000:
			setbit(NVIC->ICER, 1, TIM8_BRK_TIM12_IRQn, 1);
		break;
		case 0b10100:
			setbit(NVIC->ICER, 1, TIM8_UP_TIM13_IRQn, 1);
		break;
		case 0b10010:
			setbit(NVIC->ICER, 1, TIM8_TRG_COM_TIM14_IRQn, 1);
		break;
		case 0b10001:
			setbit(NVIC->ICER, 1, TIM8_CC_IRQn, 1);
		break;
	default:
	break;
	}
}

#endif

/*** TIM1 INIC Procedure & Function Definition ***/
STM32FXXXTIM1obj* tim1_enable(void)
{
	// CLOCK
	stm32fxxx_tim1.clock = STM32FXXXTim1Clock;
	// NVIC
	stm32fxxx_tim1.nvic = STM32FXXXTim1Nvic;
	/*** TIM1 Bit Field ***/
	stm32fxxx_tim1.cr1 = (STM32FXXXTIM1and8_CR1_TypeDef*) &TIM1->CR1;
	stm32fxxx_tim1.cr2 = (STM32FXXXTIM1and8_CR2_TypeDef*) &TIM1->CR2;
	stm32fxxx_tim1.smcr = (STM32FXXXTIM1and8_SMCR_TypeDef*) &TIM1->SMCR;
	stm32fxxx_tim1.dier = (STM32FXXXTIM1and8_DIER_TypeDef*) &TIM1->DIER;
	stm32fxxx_tim1.sr = (STM32FXXXTIM1and8_SR_TypeDef*) &TIM1->SR;
	stm32fxxx_tim1.egr = (STM32FXXXTIM1and8_EGR_TypeDef*) &TIM1->EGR;
	stm32fxxx_tim1.ccmr1 = (STM32FXXXTIM1and8_CCMR1_TypeDef*) &TIM1->CCMR1;
	stm32fxxx_tim1.ccmr2 = (STM32FXXXTIM1and8_CCMR2_TypeDef*) &TIM1->CCMR2;
	stm32fxxx_tim1.ccer = (STM32FXXXTIM1and8_CCER_TypeDef*) &TIM1->CCER;
	stm32fxxx_tim1.cnt = (STM32FXXXTIM1and8_CNT_TypeDef*) &TIM1->CNT;
	stm32fxxx_tim1.psc = (STM32FXXXTIM1and8_PSC_TypeDef*) &TIM1->PSC;
	stm32fxxx_tim1.arr = (STM32FXXXTIM1and8_ARR_TypeDef*) &TIM1->ARR;
	stm32fxxx_tim1.rcr = (STM32FXXXTIM1and8_RCR_TypeDef*) &TIM1->RCR;
	stm32fxxx_tim1.ccr1 = (STM32FXXXTIM1and8_CCR1_TypeDef*) &TIM1->CCR1;
	stm32fxxx_tim1.ccr2 = (STM32FXXXTIM1and8_CCR2_TypeDef*) &TIM1->CCR2;
	stm32fxxx_tim1.ccr3 = (STM32FXXXTIM1and8_CCR3_TypeDef*) &TIM1->CCR3;
	stm32fxxx_tim1.ccr4 = (STM32FXXXTIM1and8_CCR4_TypeDef*) &TIM1->CCR4;
	stm32fxxx_tim1.bdtr = (STM32FXXXTIM1and8_BDTR_TypeDef*) &TIM1->BDTR;
	stm32fxxx_tim1.dcr = (STM32FXXXTIM1and8_DCR_TypeDef*) &TIM1->DCR;
	stm32fxxx_tim1.dmar = (STM32FXXXTIM1and8_DMAR_TypeDef*) &TIM1->DMAR;
	return &stm32fxxx_tim1;
}

STM32FXXXTIM1obj* tim1(void){ return (STM32FXXXTIM1obj*) &stm32fxxx_tim1;}

#ifdef STM32F446xx
/*** TIM8 INIC Procedure & Function Definition ***/
STM32FXXXTIM8obj* tim8_enable(void)
{
	// CLOCK
	stm32fxxx_tim8.clock = STM32FXXXTim8Clock;
	// NVIC
	stm32fxxx_tim8.nvic = STM32FXXXTim8Nvic;
	/*** TIM8 Bit Field ***/
	stm32fxxx_tim8.cr1 = (STM32FXXXTIM1and8_CR1_TypeDef*) &TIM8->CR1;
	stm32fxxx_tim8.cr2 = (STM32FXXXTIM1and8_CR2_TypeDef*) &TIM8->CR2;
	stm32fxxx_tim8.smcr = (STM32FXXXTIM1and8_SMCR_TypeDef*) &TIM8->SMCR;
	stm32fxxx_tim8.dier = (STM32FXXXTIM1and8_DIER_TypeDef*) &TIM8->DIER;
	stm32fxxx_tim8.sr = (STM32FXXXTIM1and8_SR_TypeDef*) &TIM8->SR;
	stm32fxxx_tim8.egr = (STM32FXXXTIM1and8_EGR_TypeDef*) &TIM8->EGR;
	stm32fxxx_tim8.ccmr1 = (STM32FXXXTIM1and8_CCMR1_TypeDef*) &TIM8->CCMR1;
	stm32fxxx_tim8.ccmr2 = (STM32FXXXTIM1and8_CCMR2_TypeDef*) &TIM8->CCMR2;
	stm32fxxx_tim8.ccer = (STM32FXXXTIM1and8_CCER_TypeDef*) &TIM8->CCER;
	stm32fxxx_tim8.cnt = (STM32FXXXTIM1and8_CNT_TypeDef*) &TIM8->CNT;
	stm32fxxx_tim8.psc = (STM32FXXXTIM1and8_PSC_TypeDef*) &TIM8->PSC;
	stm32fxxx_tim8.arr = (STM32FXXXTIM1and8_ARR_TypeDef*) &TIM8->ARR;
	stm32fxxx_tim8.rcr = (STM32FXXXTIM1and8_RCR_TypeDef*) &TIM8->RCR;
	stm32fxxx_tim8.ccr1 = (STM32FXXXTIM1and8_CCR1_TypeDef*) &TIM8->CCR1;
	stm32fxxx_tim8.ccr2 = (STM32FXXXTIM1and8_CCR2_TypeDef*) &TIM8->CCR2;
	stm32fxxx_tim8.ccr3 = (STM32FXXXTIM1and8_CCR3_TypeDef*) &TIM8->CCR3;
	stm32fxxx_tim8.ccr4 = (STM32FXXXTIM1and8_CCR4_TypeDef*) &TIM8->CCR4;
	stm32fxxx_tim8.bdtr = (STM32FXXXTIM1and8_BDTR_TypeDef*) &TIM8->BDTR;
	stm32fxxx_tim8.dcr = (STM32FXXXTIM1and8_DCR_TypeDef*) &TIM8->DCR;
	stm32fxxx_tim8.dmar = (STM32FXXXTIM1and8_DMAR_TypeDef*) &TIM8->DMAR;
	return &stm32fxxx_tim8;
}

STM32FXXXTIM8obj* tim8(void){ return (STM32FXXXTIM8obj*) &stm32fxxx_tim8; }

#endif

/*** TIM1 CC IRQ Request ***/
void TIM1_CC_IRQHandler(void){

	if(tim1()->sr->tim1and8_par.uif){
		tim1_ui_callback();
		tim1()->sr->tim1and8_par.uif = 0;
	}
	if(tim1()->sr->tim1and8_par.cc1if){
		tim1_cc1_callback();
		tim1()->sr->tim1and8_par.cc1if = 0;
	}
	if(tim1()->sr->tim1and8_par.cc2if){
		tim1_cc2_callback();
		tim1()->sr->tim1and8_par.cc2if = 0;
	}
	if(tim1()->sr->tim1and8_par.tif){
		tim1_t_callback();
		tim1()->sr->tim1and8_par.tif = 0;
	}
	if(tim1()->sr->tim1and8_par.comif){
		tim1_com_callback();
		tim1()->sr->tim1and8_par.comif = 0;
	}
	if(tim1()->sr->tim1and8_par.bif){
		tim1_b_callback();
		tim1()->sr->tim1and8_par.bif = 0;
	}
}
/***/

/*** EOF ***/

/******
1º Sequence
2º Scope
	- Library Scope
	- File Scope
	- Function Scope
	- Precedence Scope
3º Pointer and Variable
4º Casting
******/

