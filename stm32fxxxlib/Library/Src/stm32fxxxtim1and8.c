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
/************************/
/*** TIM1 Bit Mapping ***/
/************************/
// CNT
void STM32FXXXTim1_cnt(uint16_t value)
{
	TIM1->CNT = value;
}
uint16_t STM32FXXXTim1_get_cnt(void)
{
	return TIM1->CNT;
}
// PSC
void STM32FXXXTim1_psc(uint16_t value)
{
	TIM1->PSC = value;
}
// ARR
void STM32FXXXTim1_arr(uint16_t value)
{
	TIM1->ARR = value;
}
// RCR
void STM32FXXXTim1_rcr(uint8_t value)
{
	TIM1->RCR = value;
}
// CCR1
void STM32FXXXTim1_ccr1(uint16_t value)
{
	TIM1->CCR1 = value;
}
// CCR2
void STM32FXXXTim1_ccr2(uint16_t value)
{
	TIM1->CCR2 = value;
}
// CCR3
void STM32FXXXTim1_ccr3(uint16_t value)
{
	TIM1->CCR3 = value;
}
// CCR4
void STM32FXXXTim1_ccr4(uint16_t value)
{
	TIM1->CCR4 = value;
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
/************************/
/*** TIM8 Bit Mapping ***/
/************************/
// CNT
void STM32FXXXTim8_cnt(uint16_t value)
{
	TIM8->CNT = value;
}
uint16_t STM32FXXXTim8_get_cnt(void)
{
	return TIM8->CNT;
}
// PSC
void STM32FXXXTim8_psc(uint16_t value)
{
	TIM8->PSC = value;
}
// ARR
void STM32FXXXTim8_arr(uint16_t value)
{
	TIM8->ARR = value;
}
// RCR
void STM32FXXXTim8_rcr(uint8_t value)
{
	TIM8->RCR = value;
}
// CCR1
void STM32FXXXTim8_ccr1(uint16_t value)
{
	TIM8->CCR1 = value;
}
// CCR2
void STM32FXXXTim8_ccr2(uint16_t value)
{
	TIM8->CCR2 = value;
}
// CCR3
void STM32FXXXTim8_ccr3(uint16_t value)
{
	TIM8->CCR3 = value;
}
// CCR4
void STM32FXXXTim8_ccr4(uint16_t value)
{
	TIM8->CCR4 = value;
}
#endif
/*** TIM1 INIC Procedure & Function Definition ***/
STM32FXXXTIM1obj tim1_enable(void)
{
	// CLOCK
	stm32fxxx_tim1.clock = STM32FXXXTim1Clock;
	// NVIC
	stm32fxxx_tim1.nvic = STM32FXXXTim1Nvic;
	/*** TIM1 Bit Mapping Link ***/
	stm32fxxx_tim1.cr1 = (STM32FXXXTIM1_CR1_TypeDef*) &TIM1->CR1;
	stm32fxxx_tim1.cr2 = (STM32FXXXTIM1_CR2_TypeDef*) &TIM1->CR2;
	stm32fxxx_tim1.smcr = (STM32FXXXTIM1_SMCR_TypeDef*) &TIM1->SMCR;
	stm32fxxx_tim1.dier = (STM32FXXXTIM1_DIER_TypeDef*) &TIM1->DIER;
	stm32fxxx_tim1.sr = (STM32FXXXTIM1_SR_TypeDef*) &TIM1->SR;
	stm32fxxx_tim1.egr = (STM32FXXXTIM1_EGR_TypeDef*) &TIM1->EGR;
	stm32fxxx_tim1.ccmr1 = (STM32FXXXTIM1_CCMR1_TypeDef*) &TIM1->CCMR1;
	stm32fxxx_tim1.ccmr2 = (STM32FXXXTIM1_CCMR2_TypeDef*) &TIM1->CCMR2;
	stm32fxxx_tim1.ccer = (STM32FXXXTIM1_CCER_TypeDef*) &TIM1->CCER;
	stm32fxxx_tim1.cnt = STM32FXXXTim1_cnt;
	stm32fxxx_tim1.get_cnt = STM32FXXXTim1_get_cnt;
	stm32fxxx_tim1.psc = STM32FXXXTim1_psc;
	stm32fxxx_tim1.arr = STM32FXXXTim1_arr;
	stm32fxxx_tim1.rep = STM32FXXXTim1_rcr;
	stm32fxxx_tim1.ccr1 = STM32FXXXTim1_ccr1;
	stm32fxxx_tim1.ccr2 = STM32FXXXTim1_ccr2;
	stm32fxxx_tim1.ccr3 = STM32FXXXTim1_ccr3;
	stm32fxxx_tim1.ccr4 = STM32FXXXTim1_ccr4;
	stm32fxxx_tim1.bdtr = (STM32FXXXTIM1_BDTR_TypeDef*) &TIM1->BDTR;
	stm32fxxx_tim1.dcr = (STM32FXXXTIM1_DCR_TypeDef*) &TIM1->DCR;
	stm32fxxx_tim1.dmar = (STM32FXXXTIM1_DMAR_TypeDef*) &TIM1->DMAR;
	return stm32fxxx_tim1;
}

STM32FXXXTIM1obj* tim1(void){ return (STM32FXXXTIM1obj*) &stm32fxxx_tim1;}

#ifdef STM32F446xx
/*** TIM8 INIC Procedure & Function Definition ***/
STM32FXXXTIM8obj tim8_enable(void)
{
	// CLOCK
	stm32fxxx_tim8.clock = STM32FXXXTim8Clock;
	// NVIC
	stm32fxxx_tim8.nvic = STM32FXXXTim8Nvic;
	/*** TIM8 Bit Mapping Link ***/
	stm32fxxx_tim8.cr1 = (STM32FXXXTIM8_CR1_TypeDef*) &TIM8->CR1;
	stm32fxxx_tim8.cr2 = (STM32FXXXTIM8_CR2_TypeDef*) &TIM8->CR2;
	stm32fxxx_tim8.smcr = (STM32FXXXTIM8_SMCR_TypeDef*) &TIM8->SMCR;
	stm32fxxx_tim8.dier = (STM32FXXXTIM8_DIER_TypeDef*) &TIM8->DIER;
	stm32fxxx_tim8.sr = (STM32FXXXTIM8_SR_TypeDef*) &TIM8->SR;
	stm32fxxx_tim8.egr = (STM32FXXXTIM8_EGR_TypeDef*) &TIM8->EGR;
	stm32fxxx_tim8.ccmr1 = (STM32FXXXTIM8_CCMR1_TypeDef*) &TIM8->CCMR1;
	stm32fxxx_tim8.ccmr2 = (STM32FXXXTIM8_CCMR2_TypeDef*) &TIM8->CCMR2;
	stm32fxxx_tim8.ccer = (STM32FXXXTIM8_CCER_TypeDef*) &TIM8->CCER;
	stm32fxxx_tim8.cnt = STM32FXXXTim8_cnt;
	stm32fxxx_tim8.get_cnt = STM32FXXXTim8_get_cnt;
	stm32fxxx_tim8.psc = STM32FXXXTim8_psc;
	stm32fxxx_tim8.arr = STM32FXXXTim8_arr;
	stm32fxxx_tim8.rep = STM32FXXXTim8_rcr;
	stm32fxxx_tim8.ccr1 = STM32FXXXTim8_ccr1;
	stm32fxxx_tim8.ccr2 = STM32FXXXTim8_ccr2;
	stm32fxxx_tim8.ccr3 = STM32FXXXTim8_ccr3;
	stm32fxxx_tim8.ccr4 = STM32FXXXTim8_ccr4;
	stm32fxxx_tim8.bdtr = (STM32FXXXTIM8_BDTR_TypeDef*) &TIM8->BDTR;
	stm32fxxx_tim8.dcr = (STM32FXXXTIM8_DCR_TypeDef*) &TIM8->DCR;
	stm32fxxx_tim8.dmar = (STM32FXXXTIM1_DMAR_TypeDef*) &TIM8->DMAR;
	return stm32fxxx_tim8;
}

STM32FXXXTIM8obj* tim8(void){ return (STM32FXXXTIM8obj*) &stm32fxxx_tim8; }

#endif

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

