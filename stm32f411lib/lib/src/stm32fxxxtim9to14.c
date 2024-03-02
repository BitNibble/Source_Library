/******************************************************************************
	STM32 XXX TIM 9 to 14
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 22062023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxtim9to14.h"

/*** File Variable ***/
static STM32FXXXTIM9obj stm32fxxx_tim9;
static STM32FXXXTIM10obj stm32fxxx_tim10;
static STM32FXXXTIM11obj stm32fxxx_tim11;
#ifdef STM32F446xx
	static STM32FXXXTIM12obj stm32fxxx_tim12;
	static STM32FXXXTIM13obj stm32fxxx_tim13;
	static STM32FXXXTIM14obj stm32fxxx_tim14;
#endif
/*** TIMER 9 to 14 Procedure & Function Definition ***/
/************/
/*** TIM9 ***/
/************/
void STM32FXXXTim9Clock(uint8_t bool)
{
	if(bool){RCC->APB2ENR |= (1 << 16);}else{RCC->APB2ENR &= ~(1 << 16);}
}
void STM32FXXXTim9Nvic(uint8_t bool)
{ // 24
	if(bool){setbit(NVIC->ISER, 1, TIM1_BRK_TIM9_IRQn, 1);}else{setbit(NVIC->ICER, 1, TIM1_BRK_TIM9_IRQn, 1);}
}
/*************/
/*** TIM10 ***/
/*************/
void STM32FXXXTim10Clock(uint8_t bool)
{
	if(bool){RCC->APB2ENR |= (1 << 17);}else{RCC->APB2ENR &= ~(1 << 17);}
}
void STM32FXXXTim10Nvic(uint8_t bool)
{ // 25
	if(bool){setbit(NVIC->ISER, 1, TIM1_UP_TIM10_IRQn, 1);} else{setbit(NVIC->ICER, 1, TIM1_UP_TIM10_IRQn, 1);}
}
/*************/
/*** TIM11 ***/
/*************/
void STM32FXXXTim11Clock(uint8_t bool)
{
	if(bool){RCC->APB2ENR |= (1 << 18);}else{RCC->APB2ENR &= ~(1 << 18);}
}
void STM32FXXXTim11Nvic(uint8_t bool)
{ // 26
	if(bool){setbit(NVIC->ISER, 1, TIM1_TRG_COM_TIM11_IRQn, 1);} else{setbit(NVIC->ICER, 1, TIM1_TRG_COM_TIM11_IRQn, 1);}
}
#ifdef STM32F446xx
/*************/
/*** TIM12 ***/
/*************/
void STM32FXXXTim12Clock(uint8_t bool)
{
	if(bool){RCC->APB1ENR |= (1 << 6);}else{RCC->APB1ENR &= ~(1 << 6);}
}
void STM32FXXXTim12Nvic(uint8_t bool)
{ // 43
	if(bool){setbit(NVIC->ISER, 1, TIM8_BRK_TIM12_IRQn, 1);}else{setbit(NVIC->ICER, 1, TIM8_BRK_TIM12_IRQn, 1);}
}
/*************/
/*** TIM13 ***/
/*************/
void STM32FXXXTim13Clock(uint8_t bool)
{
	if(bool){
		RCC->APB1ENR |= (1 << 7); // timer 13 clock enabled
	}else{
		RCC->APB1ENR &= ~(1 << 7); //timer 13 clock disabled
	}
}
void STM32FXXXTim13Nvic(uint8_t bool)
{ // 44
	if(bool){setbit(NVIC->ISER, 1, TIM8_UP_TIM13_IRQn, 1);}else{setbit(NVIC->ICER, 1, TIM8_UP_TIM13_IRQn, 1);}
}
/*************/
/*** TIM14 ***/
/*************/
void STM32FXXXTim14Clock(uint8_t bool)
{
	if(bool){RCC->APB1ENR |= (1 << 8);}else{RCC->APB1ENR &= ~(1 << 8);}
}
void STM32FXXXTim14Nvic(uint8_t bool)
{ // 45
	if(bool){setbit(NVIC->ISER, 1, TIM8_TRG_COM_TIM14_IRQn, 1);}else{setbit(NVIC->ICER, 1, TIM8_TRG_COM_TIM14_IRQn, 1);}
}
#endif
/*** TIM9 Procedure & Function Definition ***/
STM32FXXXTIM9obj* tim9_enable(void)
{


	// CLOCK
	stm32fxxx_tim9.clock = STM32FXXXTim9Clock;
	// NVIC
	stm32fxxx_tim9.nvic = STM32FXXXTim9Nvic;
	/*** TIM9 Bit Mapping Link ***/
	stm32fxxx_tim9.cr1 = (STM32FXXXTIM9to14_CR1_TypeDef*) &TIM9->CR1;
	stm32fxxx_tim9.smcr = (STM32FXXXTIM9and12_SMCR_TypeDef*) &TIM9->SMCR;
	stm32fxxx_tim9.dier = (STM32FXXXTIM9and12_DIER_TypeDef*) &TIM9->DIER;
	stm32fxxx_tim9.sr = (STM32FXXXTIM9and12_SR_TypeDef*) &TIM9->SR;
	stm32fxxx_tim9.egr = (STM32FXXXTIM9and12_EGR_TypeDef*) &TIM9->EGR;
	stm32fxxx_tim9.ccmr1 = (STM32FXXXTIM9and12_CCMR1_TypeDef*) &TIM9->CCMR1;
	stm32fxxx_tim9.ccer = (STM32FXXXTIM9and12_CCER_TypeDef*) &TIM9->CCER;
	stm32fxxx_tim9.cnt = (STM32FXXXTIM9to14_CNT_TypeDef*) &TIM9->CNT;
	stm32fxxx_tim9.psc = (STM32FXXXTIM9to14_PSC_TypeDef*) &TIM9->PSC;
	stm32fxxx_tim9.arr = (STM32FXXXTIM9to14_ARR_TypeDef*) &TIM9->ARR;
	stm32fxxx_tim9.ccr1 = (STM32FXXXTIM9to14_CCR1_TypeDef*) &TIM9->CCR1;
	stm32fxxx_tim9.ccr2 = (STM32FXXXTIM9and12_CCR2_TypeDef*) &TIM9->CCR2;
	return &stm32fxxx_tim9;
}

STM32FXXXTIM9obj* tim9(void){ return (STM32FXXXTIM9obj*) &stm32fxxx_tim9; }

/*** TIM10 Procedure & Function Definition***/
STM32FXXXTIM10obj* tim10_enable(void)
{


	// CLOCK
	stm32fxxx_tim10.clock = STM32FXXXTim10Clock;
	// NVIC
	stm32fxxx_tim10.nvic = STM32FXXXTim10Nvic;
	/*** TIM10 Bit Mapping Link ***/
	stm32fxxx_tim10.cr1 = (STM32FXXXTIM9to14_CR1_TypeDef*) &TIM10->CR1;
	stm32fxxx_tim10.dier = (STM32FXXXTIM10and11_DIER_TypeDef*) &TIM10->DIER;
	stm32fxxx_tim10.sr = (STM32FXXXTIM10and11_SR_TypeDef*) &TIM10->SR;
	stm32fxxx_tim10.egr = (STM32FXXXTIM10and11_EGR_TypeDef*) &TIM10->EGR;
	stm32fxxx_tim10.ccmr1 = (STM32FXXXTIM10and11_CCMR1_TypeDef*) &TIM10->CCMR1;
	stm32fxxx_tim10.ccer = (STM32FXXXTIM10and11_CCER_TypeDef*) &TIM10->CCER;
	stm32fxxx_tim10.cnt = (STM32FXXXTIM9to14_CNT_TypeDef*) &TIM10->CNT;
	stm32fxxx_tim10.psc = (STM32FXXXTIM9to14_PSC_TypeDef*) &TIM10->PSC;
	stm32fxxx_tim10.arr = (STM32FXXXTIM9to14_ARR_TypeDef*) &TIM10->ARR;
	stm32fxxx_tim10.ccr1 = (STM32FXXXTIM9to14_CCR1_TypeDef*) &TIM10->CCR1;
	stm32fxxx_tim10.or = (STM32FXXXTIM10and11_OR_TypeDef*) &TIM10->OR;
	return &stm32fxxx_tim10;
}

STM32FXXXTIM10obj* tim10(void){ return (STM32FXXXTIM10obj*) &stm32fxxx_tim10; }

/*** TIM11 Procedure & Function Definition***/
STM32FXXXTIM11obj* tim11_enable(void)
{


	// CLOCK
	stm32fxxx_tim11.clock = STM32FXXXTim11Clock;
	// NVIC
	stm32fxxx_tim11.nvic = STM32FXXXTim11Nvic;
	/*** TIM11 Bit Mapping Link ***/
	stm32fxxx_tim11.cr1 = (STM32FXXXTIM9to14_CR1_TypeDef*) &TIM11->CR1;
	stm32fxxx_tim11.dier = (STM32FXXXTIM10and11_DIER_TypeDef*) &TIM11->DIER;
	stm32fxxx_tim11.sr = (STM32FXXXTIM10and11_SR_TypeDef*) &TIM11->SR;
	stm32fxxx_tim11.egr = (STM32FXXXTIM10and11_EGR_TypeDef*) &TIM11->EGR;
	stm32fxxx_tim11.ccmr1 = (STM32FXXXTIM10and11_CCMR1_TypeDef*) &TIM11->CCMR1;
	stm32fxxx_tim11.ccer = (STM32FXXXTIM10and11_CCER_TypeDef*) &TIM11->CCER;
	stm32fxxx_tim11.cnt = (STM32FXXXTIM9to14_CNT_TypeDef*) &TIM11->CNT;
	stm32fxxx_tim11.psc = (STM32FXXXTIM9to14_PSC_TypeDef*) &TIM11->PSC;
	stm32fxxx_tim11.arr = (STM32FXXXTIM9to14_ARR_TypeDef*) &TIM11->ARR;
	stm32fxxx_tim11.ccr1 = (STM32FXXXTIM9to14_CCR1_TypeDef*) &TIM11->CCR1;
	stm32fxxx_tim11.or = (STM32FXXXTIM10and11_OR_TypeDef*) &TIM11->OR;
	return &stm32fxxx_tim11;
}

STM32FXXXTIM11obj* tim11(void){ return (STM32FXXXTIM11obj*) &stm32fxxx_tim11; }

#ifdef STM32F446xx
/*** TIM12 Procedure & Function Definition***/
STM32FXXXTIM12obj* tim12_enable(void)
{


	// CLOCK
	stm32fxxx_tim12.clock = STM32FXXXTim12Clock;
	// NVIC
	stm32fxxx_tim12.nvic = STM32FXXXTim12Nvic;
	/*** TIM12 Bit Mapping Link ***/
	stm32fxxx_tim12.cr1 = (STM32FXXXTIM9to14_CR1_TypeDef*) &TIM12->CR1;
	stm32fxxx_tim12.smcr = (STM32FXXXTIM9and12_SMCR_TypeDef*) &TIM12->SMCR;
	stm32fxxx_tim12.dier = (STM32FXXXTIM9and12_DIER_TypeDef*) &TIM12->DIER;
	stm32fxxx_tim12.sr = (STM32FXXXTIM9and12_SR_TypeDef*) &TIM12->SR;
	stm32fxxx_tim12.egr = (STM32FXXXTIM9and12_EGR_TypeDef*) &TIM12->EGR;
	stm32fxxx_tim12.ccmr1 = (STM32FXXXTIM9and12_CCMR1_TypeDef*) &TIM12->CCMR1;
	stm32fxxx_tim12.ccer = (STM32FXXXTIM9and12_CCER_TypeDef*) &TIM12->CCER;
	stm32fxxx_tim12.cnt = (STM32FXXXTIM9to14_CNT_TypeDef*) &TIM12->CNT;
	stm32fxxx_tim12.psc = (STM32FXXXTIM9to14_PSC_TypeDef*) &TIM12->PSC;
	stm32fxxx_tim12.arr = (STM32FXXXTIM9to14_ARR_TypeDef*) &TIM12->ARR;
	stm32fxxx_tim12.ccr1 = (STM32FXXXTIM9to14_CCR1_TypeDef*) &TIM12->CCR1;
	stm32fxxx_tim12.ccr2 = (STM32FXXXTIM9and12_CCR2_TypeDef*) &TIM12->CCR2;
	return &stm32fxxx_tim12;
}

STM32FXXXTIM12obj* tim12(void){ return (STM32FXXXTIM12obj*) &stm32fxxx_tim12; }

/*** TIM13 Procedure & Function Definition***/
STM32FXXXTIM13obj* tim13_enable(void)
{


	// CLOCK
	stm32fxxx_tim13.clock = STM32FXXXTim13Clock;
	// NVIC
	stm32fxxx_tim13.nvic = STM32FXXXTim13Nvic;
	/*** TIM13 Bit Mapping Link ***/
	stm32fxxx_tim13.cr1 = (STM32FXXXTIM9to14_CR1_TypeDef*) &TIM13->CR1;
	stm32fxxx_tim13.dier = (STM32FXXXTIM10and11_DIER_TypeDef*) &TIM13->DIER;
	stm32fxxx_tim13.sr = (STM32FXXXTIM10and11_SR_TypeDef*) &TIM13->SR;
	stm32fxxx_tim13.egr = (STM32FXXXTIM10and11_EGR_TypeDef*) &TIM13->EGR;
	stm32fxxx_tim13.ccmr1 = (STM32FXXXTIM10and11_CCMR1_TypeDef*) &TIM13->CCMR1;
	stm32fxxx_tim13.ccer = (STM32FXXXTIM10and11_CCER_TypeDef*) &TIM13->CCER;
	stm32fxxx_tim13.cnt = (STM32FXXXTIM9to14_CNT_TypeDef*) &TIM13->CNT;
	stm32fxxx_tim13.psc = (STM32FXXXTIM9to14_PSC_TypeDef*) &TIM13->PSC;
	stm32fxxx_tim13.arr = (STM32FXXXTIM9to14_ARR_TypeDef*) &TIM13->ARR;
	stm32fxxx_tim13.ccr1 = (STM32FXXXTIM9to14_CCR1_TypeDef*) &TIM13->CCR1;
	stm32fxxx_tim13.or = (STM32FXXXTIM10and11_OR_TypeDef*) &TIM13->OR;
	return &stm32fxxx_tim13;
}

STM32FXXXTIM13obj* tim13(void){ return (STM32FXXXTIM13obj*) &stm32fxxx_tim13; }

/*** TIM14 Procedure & Function Definition ***/
STM32FXXXTIM14obj* tim14_enable(void)
{


	// CLOCK
	stm32fxxx_tim14.clock = STM32FXXXTim14Clock;
	// NVIC
	stm32fxxx_tim14.nvic = STM32FXXXTim14Nvic;
	/*** TIM14 Bit Mapping Link ***/
	stm32fxxx_tim14.cr1 = (STM32FXXXTIM9to14_CR1_TypeDef*) &TIM14->CR1;
	stm32fxxx_tim14.dier = (STM32FXXXTIM10and11_DIER_TypeDef*) &TIM14->DIER;
	stm32fxxx_tim14.sr = (STM32FXXXTIM10and11_SR_TypeDef*) &TIM14->SR;
	stm32fxxx_tim14.egr = (STM32FXXXTIM10and11_EGR_TypeDef*) &TIM14->EGR;
	stm32fxxx_tim14.ccmr1 = (STM32FXXXTIM10and11_CCMR1_TypeDef*) &TIM14->CCMR1;
	stm32fxxx_tim14.ccer = (STM32FXXXTIM10and11_CCER_TypeDef*) &TIM14->CCER;
	stm32fxxx_tim14.cnt = (STM32FXXXTIM9to14_CNT_TypeDef*) &TIM14->CNT;
	stm32fxxx_tim14.psc = (STM32FXXXTIM9to14_PSC_TypeDef*) &TIM14->PSC;
	stm32fxxx_tim14.arr = (STM32FXXXTIM9to14_ARR_TypeDef*) &TIM14->ARR;
	stm32fxxx_tim14.ccr1 = (STM32FXXXTIM9to14_CCR1_TypeDef*) &TIM14->CCR1;
	stm32fxxx_tim14.or = (STM32FXXXTIM10and11_OR_TypeDef*) &TIM14->OR;
	return &stm32fxxx_tim14;
}

STM32FXXXTIM14obj* tim14(void){ return (STM32FXXXTIM14obj*) &stm32fxxx_tim14; }

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

