/******************************************************************************
	STM32 XXX TIM 2 to 5
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 22062023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxtim2to5.h"

/*** File Variables ***/
static STM32FXXXTIM2obj stm32fxxx_tim2;
static STM32FXXXTIM3obj stm32fxxx_tim3;
static STM32FXXXTIM4obj stm32fxxx_tim4;
static STM32FXXXTIM5obj stm32fxxx_tim5;
/*** TIMER Procedure & Function Definition ***/
/************/
/*** TIM2 ***/
/************/
void STM32FXXXTim2Clock(uint8_t bool)
{
	if(bool){RCC->APB1ENR |= (1 << 0);}else{RCC->APB1ENR &= ~(1 << 0);}
}
void STM32FXXXTim2Nvic(uint8_t bool)
{ // 28
	if(bool){setbit(NVIC->ISER, 1, TIM2_IRQn, 1);} else{setbit(NVIC->ICER, 1, TIM2_IRQn, 1);}
}
/************/
/*** TIM3 ***/
/************/
void STM32FXXXTim3Clock(uint8_t bool)
{
	if(bool){RCC->APB1ENR |= (1 << 1);}else{RCC->APB1ENR &= ~(1 << 1);}
}
void STM32FXXXTim3Nvic(uint8_t bool)
{ // 29
	if(bool){setbit(NVIC->ISER, 1, TIM3_IRQn, 1);} else{setbit(NVIC->ICER, 1, TIM3_IRQn, 1);}
}
/************/
/*** TIM4 ***/
/************/
void STM32FXXXTim4Clock(uint8_t bool)
{
	if(bool){RCC->APB1ENR |= (1 << 2);}else{RCC->APB1ENR &= ~(1 << 2);}
}
void STM32FXXXTim4Nvic(uint8_t bool)
{ // 30
	if(bool){setbit(NVIC->ISER, 1, TIM4_IRQn, 1);} else{setbit(NVIC->ICER, 1, TIM4_IRQn, 1);}
}
/************/
/*** TIM5 ***/
/************/
void STM32FXXXTim5Clock(uint8_t bool)
{
	if(bool){RCC->APB1ENR |= (1 << 3);}else{RCC->APB1ENR &= ~(1 << 3);}
}
void STM32FXXXTim5Nvic(uint8_t bool)
{ // 50
	if(bool){setbit(NVIC->ISER, 1, TIM5_IRQn, 1);} else{setbit(NVIC->ICER, 1, TIM5_IRQn, 1);}
}
/*** TIM2 INIC Procedure & Function Definition ***/
STM32FXXXTIM2obj* tim2_enable(void)
{


	// CLOCK
	stm32fxxx_tim2.clock = STM32FXXXTim2Clock;
	// NVIC
	stm32fxxx_tim2.nvic = STM32FXXXTim2Nvic;
	/*** TIM2 Bit Mapping Link ***/
	stm32fxxx_tim2.cr1 = (STM32FXXXTIM2to5_CR1_TypeDef*) &TIM2->CR1;
	stm32fxxx_tim2.cr2 = (STM32FXXXTIM2to5_CR2_TypeDef*) &TIM2->CR2;
	stm32fxxx_tim2.smcr = (STM32FXXXTIM2to5_SMCR_TypeDef*) &TIM2->SMCR;
	stm32fxxx_tim2.dier = (STM32FXXXTIM2to5_DIER_TypeDef*) &TIM2->DIER;
	stm32fxxx_tim2.sr = (STM32FXXXTIM2to5_SR_TypeDef*) &TIM2->SR;
	stm32fxxx_tim2.egr = (STM32FXXXTIM2to5_EGR_TypeDef*) &TIM2->EGR;
	stm32fxxx_tim2.ccmr1 = (STM32FXXXTIM2to5_CCMR1_TypeDef*) &TIM2->CCMR1;
	stm32fxxx_tim2.ccmr2 = (STM32FXXXTIM2to5_CCMR2_TypeDef*) &TIM2->CCMR2;
	stm32fxxx_tim2.ccer = (STM32FXXXTIM2to5_CCER_TypeDef*) &TIM2->CCER;
	stm32fxxx_tim2.dcr = (STM32FXXXTIM2to5_DCR_TypeDef*) &TIM2->DCR;
	stm32fxxx_tim2.cnt = (STM32FXXXTIM2to5_CNT_TypeDef*) &TIM2->CNT;
	stm32fxxx_tim2.psc = (STM32FXXXTIM2to5_PSC_TypeDef*) &TIM2->PSC;
	stm32fxxx_tim2.arr = (STM32FXXXTIM2to5_ARR_TypeDef*) &TIM2->ARR;
	stm32fxxx_tim2.ccr1 = (STM32FXXXTIM2to5_CCR1_TypeDef*) &TIM2->CCR1;
	stm32fxxx_tim2.ccr2 = (STM32FXXXTIM2to5_CCR2_TypeDef*) &TIM2->CCR2;
	stm32fxxx_tim2.ccr3 = (STM32FXXXTIM2to5_CCR3_TypeDef*) &TIM2->CCR3;
	stm32fxxx_tim2.ccr4 = (STM32FXXXTIM2to5_CCR4_TypeDef*) &TIM2->CCR4;
	stm32fxxx_tim2.dmar = (STM32FXXXTIM2to5_DMAR_TypeDef*) &TIM2->DMAR;
	stm32fxxx_tim2.or = (STM32FXXXTIM2and5_OR_TypeDef*) &TIM2->OR;
	return &stm32fxxx_tim2;
}

STM32FXXXTIM2obj* tim2(void){ return (STM32FXXXTIM2obj*) &stm32fxxx_tim2; }

/*** TIM3 INIC Procedure & Function Definition ***/
STM32FXXXTIM3obj* tim3_enable(void)
{


	// CLOCK
	stm32fxxx_tim3.clock = STM32FXXXTim3Clock;
	// NVIC
	stm32fxxx_tim3.nvic = STM32FXXXTim3Nvic;
	/*** TIM3 Bit Mapping Link ***/
	stm32fxxx_tim3.cr1 = (STM32FXXXTIM2to5_CR1_TypeDef*) &TIM3->CR1;
	stm32fxxx_tim3.cr2 = (STM32FXXXTIM2to5_CR2_TypeDef*) &TIM3->CR2;
	stm32fxxx_tim3.smcr = (STM32FXXXTIM2to5_SMCR_TypeDef*) &TIM3->SMCR;
	stm32fxxx_tim3.dier = (STM32FXXXTIM2to5_DIER_TypeDef*) &TIM3->DIER;
	stm32fxxx_tim3.sr = (STM32FXXXTIM2to5_SR_TypeDef*) &TIM3->SR;
	stm32fxxx_tim3.egr = (STM32FXXXTIM2to5_EGR_TypeDef*) &TIM3->EGR;
	stm32fxxx_tim3.ccmr1 = (STM32FXXXTIM2to5_CCMR1_TypeDef*) &TIM3->CCMR1;
	stm32fxxx_tim3.ccmr2 = (STM32FXXXTIM2to5_CCMR2_TypeDef*) &TIM3->CCMR2;
	stm32fxxx_tim3.ccer = (STM32FXXXTIM2to5_CCER_TypeDef*) &TIM3->CCER;
	stm32fxxx_tim3.dcr = (STM32FXXXTIM2to5_DCR_TypeDef*) &TIM3->DCR;
	stm32fxxx_tim3.cnt = (STM32FXXXTIM2to5_CNT_TypeDef*) &TIM3->CNT;
	stm32fxxx_tim3.psc = (STM32FXXXTIM2to5_PSC_TypeDef*) &TIM3->PSC;
	stm32fxxx_tim3.arr = (STM32FXXXTIM2to5_ARR_TypeDef*) &TIM3->ARR;
	stm32fxxx_tim3.ccr1 = (STM32FXXXTIM2to5_CCR1_TypeDef*) &TIM3->CCR1;
	stm32fxxx_tim3.ccr2 = (STM32FXXXTIM2to5_CCR2_TypeDef*) &TIM3->CCR2;
	stm32fxxx_tim3.ccr3 = (STM32FXXXTIM2to5_CCR3_TypeDef*) &TIM3->CCR3;
	stm32fxxx_tim3.ccr4 = (STM32FXXXTIM2to5_CCR4_TypeDef*) &TIM3->CCR4;
	stm32fxxx_tim3.dmar = (STM32FXXXTIM2to5_DMAR_TypeDef*) &TIM3->DMAR;
	return &stm32fxxx_tim3;
}

STM32FXXXTIM3obj* tim3(void){ return (STM32FXXXTIM3obj*) &stm32fxxx_tim3; }

/*** TIM4 INIC Procedure & Function Definition ***/
STM32FXXXTIM4obj* tim4_enable(void)
{


	// CLOCK
	stm32fxxx_tim4.clock = STM32FXXXTim4Clock;
	// NVIC
	stm32fxxx_tim4.nvic = STM32FXXXTim4Nvic;
	/*** TIM4 Bit Mapping Link ***/
	stm32fxxx_tim4.cr1 = (STM32FXXXTIM2to5_CR1_TypeDef*) &TIM4->CR1;
	stm32fxxx_tim4.cr2 = (STM32FXXXTIM2to5_CR2_TypeDef*) &TIM4->CR2;
	stm32fxxx_tim4.smcr = (STM32FXXXTIM2to5_SMCR_TypeDef*) &TIM4->SMCR;
	stm32fxxx_tim4.dier = (STM32FXXXTIM2to5_DIER_TypeDef*) &TIM4->DIER;
	stm32fxxx_tim4.sr = (STM32FXXXTIM2to5_SR_TypeDef*) &TIM4->SR;
	stm32fxxx_tim4.egr = (STM32FXXXTIM2to5_EGR_TypeDef*) &TIM4->EGR;
	stm32fxxx_tim4.ccmr1 = (STM32FXXXTIM2to5_CCMR1_TypeDef*) &TIM4->CCMR1;
	stm32fxxx_tim4.ccmr2 = (STM32FXXXTIM2to5_CCMR2_TypeDef*) &TIM4->CCMR2;
	stm32fxxx_tim4.ccer = (STM32FXXXTIM2to5_CCER_TypeDef*) &TIM4->CCER;
	stm32fxxx_tim4.dcr = (STM32FXXXTIM2to5_DCR_TypeDef*) &TIM4->DCR;
	stm32fxxx_tim4.cnt = (STM32FXXXTIM2to5_CNT_TypeDef*) &TIM4->CNT;
	stm32fxxx_tim4.psc = (STM32FXXXTIM2to5_PSC_TypeDef*) &TIM4->PSC;
	stm32fxxx_tim4.arr = (STM32FXXXTIM2to5_ARR_TypeDef*) &TIM4->ARR;
	stm32fxxx_tim4.ccr1 = (STM32FXXXTIM2to5_CCR1_TypeDef*) &TIM4->CCR1;
	stm32fxxx_tim4.ccr2 = (STM32FXXXTIM2to5_CCR2_TypeDef*) &TIM4->CCR2;
	stm32fxxx_tim4.ccr3 = (STM32FXXXTIM2to5_CCR3_TypeDef*) &TIM4->CCR3;
	stm32fxxx_tim4.ccr4 = (STM32FXXXTIM2to5_CCR4_TypeDef*) &TIM4->CCR4;
	stm32fxxx_tim4.dmar = (STM32FXXXTIM2to5_DMAR_TypeDef*) &TIM4->DMAR;
	return &stm32fxxx_tim4;
}

STM32FXXXTIM4obj* tim4(void){ return (STM32FXXXTIM4obj*) &stm32fxxx_tim4; }

/*** TIM5 INIC Procedure & Function Definition ***/
STM32FXXXTIM5obj* tim5_enable(void)
{


	// CLOCK
	stm32fxxx_tim5.clock = STM32FXXXTim5Clock;
	// NVIC
	stm32fxxx_tim5.nvic = STM32FXXXTim5Nvic;
	/*** TIM5 Bit Mapping Link ***/
	stm32fxxx_tim5.cr1 = (STM32FXXXTIM2to5_CR1_TypeDef*) &TIM5->CR1;
	stm32fxxx_tim5.cr2 = (STM32FXXXTIM2to5_CR2_TypeDef*) &TIM5->CR2;
	stm32fxxx_tim5.smcr = (STM32FXXXTIM2to5_SMCR_TypeDef*) &TIM5->SMCR;
	stm32fxxx_tim5.dier = (STM32FXXXTIM2to5_DIER_TypeDef*) &TIM5->DIER;
	stm32fxxx_tim5.sr = (STM32FXXXTIM2to5_SR_TypeDef*) &TIM5->SR;
	stm32fxxx_tim5.egr = (STM32FXXXTIM2to5_EGR_TypeDef*) &TIM5->EGR;
	stm32fxxx_tim5.ccmr1 = (STM32FXXXTIM2to5_CCMR1_TypeDef*) &TIM5->CCMR1;
	stm32fxxx_tim5.ccmr2 = (STM32FXXXTIM2to5_CCMR2_TypeDef*) &TIM5->CCMR2;
	stm32fxxx_tim5.ccer = (STM32FXXXTIM2to5_CCER_TypeDef*) &TIM5->CCER;
	stm32fxxx_tim5.dcr = (STM32FXXXTIM2to5_DCR_TypeDef*) &TIM5->DCR;
	stm32fxxx_tim5.cnt = (STM32FXXXTIM2to5_CNT_TypeDef*) &TIM5->CNT;
	stm32fxxx_tim5.psc = (STM32FXXXTIM2to5_PSC_TypeDef*) &TIM5->PSC;
	stm32fxxx_tim5.arr = (STM32FXXXTIM2to5_ARR_TypeDef*) &TIM5->ARR;
	stm32fxxx_tim5.ccr1 = (STM32FXXXTIM2to5_CCR1_TypeDef*) &TIM5->CCR1;
	stm32fxxx_tim5.ccr2 = (STM32FXXXTIM2to5_CCR2_TypeDef*) &TIM5->CCR2;
	stm32fxxx_tim5.ccr3 = (STM32FXXXTIM2to5_CCR3_TypeDef*) &TIM5->CCR3;
	stm32fxxx_tim5.ccr4 = (STM32FXXXTIM2to5_CCR4_TypeDef*) &TIM5->CCR4;
	stm32fxxx_tim5.dmar = (STM32FXXXTIM2to5_DMAR_TypeDef*) &TIM5->DMAR;
	stm32fxxx_tim5.or = (STM32FXXXTIM2and5_OR_TypeDef*) &TIM5->OR;
	return &stm32fxxx_tim5;
}

STM32FXXXTIM5obj* tim5(void){ return (STM32FXXXTIM5obj*) &stm32fxxx_tim5; }

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

