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
/************************/
/*** TIM9 Bit Mapping ***/
/************************/
// CNT
void STM32FXXXTim9_cnt(uint16_t value)
{
	TIM9->CNT = value;
}
uint16_t STM32FXXXTim9_get_cnt(void)
{
	return TIM9->CNT;
}
// ARR
void STM32FXXXTim9_arr(uint16_t value)
{
	TIM9->ARR = value;
}
// CCR1
void STM32FXXXTim9_ccr1(uint16_t value)
{
	TIM9->CCR1 = value;
}
// CCR2
void STM32FXXXTim9_ccr2(uint16_t value)
{
	TIM9->CCR2 = value;
}
// PSC
void STM32FXXXTim9_psc(uint16_t value)
{
	TIM9->PSC = value;
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
/*************************/
/*** TIM10 Bit Mapping ***/
/*************************/
// CNT
void STM32FXXXTim10_cnt(uint16_t value)
{
	TIM10->CNT = value;
}
uint16_t STM32FXXXTim10_get_cnt(void)
{
	return TIM10->CNT;
}
// PSC
void STM32FXXXTim10_psc(uint16_t value)
{
	TIM10->PSC = value;
}
// ARR
void STM32FXXXTim10_arr(uint16_t value)
{
	TIM10->ARR = value;
}
// CCR1
void STM32FXXXTim10_ccr1(uint16_t value)
{
	TIM10->CCR1 = value;
}
// OR
void STM32FXXXTim10_or(uint8_t value)
{
	setreg(&TIM10->OR, 2, 0, value);
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
/************************/
/*** TIM11 Bit Mapping ***/
/************************/
// CNT
void STM32FXXXTim11_cnt(uint16_t value)
{
	TIM11->CNT = value;
}
uint16_t STM32FXXXTim11_get_cnt(void)
{
	return TIM11->CNT;
}
// PSC
void STM32FXXXTim11_psc(uint16_t value)
{
	TIM11->PSC = value;
}
// ARR
void STM32FXXXTim11_arr(uint16_t value)
{
	TIM11->ARR = value;
}
// CCR1
void STM32FXXXTim11_ccr1(uint16_t value)
{
	TIM11->CCR1 = value;
}
// OR
void STM32FXXXTim11_or(uint8_t value)
{
	setreg(&TIM11->OR, 2, 0, value);
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
/************************/
/*** TIM12 Bit Mapping ***/
/************************/
// CNT
void STM32FXXXTim12_cnt(uint16_t value)
{
	TIM12->CNT = value;
}
uint16_t STM32FXXXTim12_get_cnt(void)
{
	return TIM12->CNT;
}
// ARR
void STM32FXXXTim12_arr(uint16_t value)
{
	TIM12->ARR = value;
}
// CCR1
void STM32FXXXTim12_ccr1(uint16_t value)
{
	TIM12->CCR1 = value;
}
// CCR2
void STM32FXXXTim12_ccr2(uint16_t value)
{
	TIM12->CCR2 = value;
}
// PSC
void STM32FXXXTim12_psc(uint16_t value)
{
	TIM12->PSC = value;
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
/************************/
/*** TIM13 Bit Mapping ***/
/************************/
// CNT
void STM32FXXXTim13_cnt(uint16_t value)
{
	TIM13->CNT = value;
}
uint16_t STM32FXXXTim13_get_cnt(void)
{
	return TIM13->CNT;
}
// PSC
void STM32FXXXTim13_psc(uint16_t value)
{
	TIM13->PSC = value;
}
// ARR
void STM32FXXXTim13_arr(uint16_t value)
{
	TIM13->ARR = value;
}
// CCR1
void STM32FXXXTim13_ccr1(uint16_t value)
{
	TIM13->CCR1 = value;
}
// OR
void STM32FXXXTim13_or(uint8_t value)
{
	setreg(&TIM13->OR, 2, 0, value);
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
/************************/
/*** TIM14 Bit Mapping ***/
/************************/
// CNT
void STM32FXXXTim14_cnt(uint16_t value)
{
	TIM14->CNT = value;
}
uint16_t STM32FXXXTim14_get_cnt(void)
{
	return TIM14->CNT;
}
// PSC
void STM32FXXXTim14_psc(uint16_t value)
{
	TIM14->PSC = value;
}
// ARR
void STM32FXXXTim14_arr(uint16_t value)
{
	TIM14->ARR = value;
}
// CCR1
void STM32FXXXTim14_ccr1(uint16_t value)
{
	TIM14->CCR1 = value;
}
// OR
void STM32FXXXTim14_or(uint8_t value)
{
	setreg(&TIM14->OR, 2, 0, value);
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
	stm32fxxx_tim9.cnt = STM32FXXXTim9_cnt;
	stm32fxxx_tim9.get_cnt = STM32FXXXTim9_get_cnt;
	stm32fxxx_tim9.arr = STM32FXXXTim9_arr;
	stm32fxxx_tim9.ccr1 = STM32FXXXTim9_ccr1;
	stm32fxxx_tim9.ccr2 = STM32FXXXTim9_ccr2;
	stm32fxxx_tim9.psc = STM32FXXXTim9_psc;
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
	stm32fxxx_tim10.cnt = STM32FXXXTim10_cnt;
	stm32fxxx_tim10.get_cnt = STM32FXXXTim10_get_cnt;
	stm32fxxx_tim10.psc = STM32FXXXTim10_psc;
	stm32fxxx_tim10.arr = STM32FXXXTim10_arr;
	stm32fxxx_tim10.ccr1 = STM32FXXXTim10_ccr1;
	stm32fxxx_tim10.or = STM32FXXXTim10_or;
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
	stm32fxxx_tim11.cnt = STM32FXXXTim11_cnt;
	stm32fxxx_tim11.get_cnt = STM32FXXXTim11_get_cnt;
	stm32fxxx_tim11.psc = STM32FXXXTim11_psc;
	stm32fxxx_tim11.arr = STM32FXXXTim11_arr;
	stm32fxxx_tim11.ccr1 = STM32FXXXTim11_ccr1;
	stm32fxxx_tim11.or = STM32FXXXTim11_or;
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
	stm32fxxx_tim12.cnt = STM32FXXXTim12_cnt;
	stm32fxxx_tim12.get_cnt = STM32FXXXTim12_get_cnt;
	stm32fxxx_tim12.arr = STM32FXXXTim12_arr;
	stm32fxxx_tim12.ccr1 = STM32FXXXTim12_ccr1;
	stm32fxxx_tim12.ccr2 = STM32FXXXTim12_ccr2;
	stm32fxxx_tim12.psc = STM32FXXXTim12_psc;
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
	stm32fxxx_tim13.cnt = STM32FXXXTim13_cnt;
	stm32fxxx_tim13.get_cnt = STM32FXXXTim13_get_cnt;
	stm32fxxx_tim13.psc = STM32FXXXTim13_psc;
	stm32fxxx_tim13.arr = STM32FXXXTim13_arr;
	stm32fxxx_tim13.ccr1 = STM32FXXXTim13_ccr1;
	stm32fxxx_tim13.or = STM32FXXXTim13_or;
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
	stm32fxxx_tim14.cnt = STM32FXXXTim14_cnt;
	stm32fxxx_tim14.get_cnt = STM32FXXXTim14_get_cnt;
	stm32fxxx_tim14.psc = STM32FXXXTim14_psc;
	stm32fxxx_tim14.arr = STM32FXXXTim14_arr;
	stm32fxxx_tim14.ccr1 = STM32FXXXTim14_ccr1;
	stm32fxxx_tim14.or = STM32FXXXTim14_or;
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

