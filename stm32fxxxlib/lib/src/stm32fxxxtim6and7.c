/******************************************************************************
	STM32 XXX TIM 6 and 7
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 22062023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxtim6and7.h"

/*** File Variable ***/
#ifdef STM32F446xx
static STM32FXXXTIM6obj stm32fxxx_tim6;
static STM32FXXXTIM7obj stm32fxxx_tim7;
/************/
/*** TIM6 ***/
/************/
void STM32FXXXTim6Clock(uint8_t bool)
{
	if(bool){RCC->APB1ENR |= (1 << 4);}else{RCC->APB1ENR &= ~(1 << 4);}
}
void STM32FXXXTim6Nvic(uint8_t bool)
{ // 54
	if(bool){setbit(NVIC->ISER, 1, TIM6_DAC_IRQn, 1);}else{setbit(NVIC->ICER, 1, TIM6_DAC_IRQn, 1);}
}
/************/
/*** TIM7 ***/
/************/
void STM32FXXXTim7Clock(uint8_t bool)
{
	if(bool){RCC->APB1ENR |= (1 << 5);}else{RCC->APB1ENR &= ~(1 << 5);}
}
void STM32FXXXTim7Nvic(uint8_t bool)
{ // 55
	if(bool){setbit(NVIC->ISER, 1, TIM7_IRQn, 1);}else{setbit(NVIC->ICER, 1, TIM7_IRQn, 1);}
}
/*** TIM6 INIC Procedure & Function Definition ***/
STM32FXXXTIM6obj* tim6_enable(void)
{
	// CLOCK
	stm32fxxx_tim6.clock = STM32FXXXTim6Clock;
	// NVIC
	stm32fxxx_tim6.nvic = STM32FXXXTim6Nvic;
	/*** TIM6 Bit Mapping Link ***/
	stm32fxxx_tim6.cr1 = (STM32FXXXTIM6and7_CR1_TypeDef*) &TIM6->CR1;
	stm32fxxx_tim6.cr2 = (STM32FXXXTIM6and7_CR2_TypeDef*) &TIM6->CR2;
	stm32fxxx_tim6.dier = (STM32FXXXTIM6and7_DIER_TypeDef*) &TIM6->DIER;
	stm32fxxx_tim6.sr = (STM32FXXXTIM6and7_SR_TypeDef*) &TIM6->SR;
	stm32fxxx_tim6.egr = (STM32FXXXTIM6and7_EGR_TypeDef*) &TIM6->EGR;
	stm32fxxx_tim6.cnt = (STM32FXXXTIM6and7_CNT_TypeDef*) &TIM6->CNT;
	stm32fxxx_tim6.psc = (STM32FXXXTIM6and7_PSC_TypeDef*) &TIM6->PSC;
	stm32fxxx_tim6.arr = (STM32FXXXTIM6and7_ARR_TypeDef*) &TIM6->ARR;
	return &stm32fxxx_tim6;
}
STM32FXXXTIM6obj* tim6(void){ return (STM32FXXXTIM6obj*) &stm32fxxx_tim6; }
/*** TIM7 INIC Procedure & Function Definition ***/
STM32FXXXTIM7obj* tim7_enable(void)
{
	// CLOCK
	stm32fxxx_tim7.clock = STM32FXXXTim7Clock;
	// NVIC
	stm32fxxx_tim7.nvic = STM32FXXXTim7Nvic;
	/*** TIM7 Bit Mapping Link ***/
	stm32fxxx_tim7.cr1 = (STM32FXXXTIM6and7_CR1_TypeDef*) &TIM7->CR1;
	stm32fxxx_tim7.cr2 = (STM32FXXXTIM6and7_CR2_TypeDef*) &TIM7->CR2;
	stm32fxxx_tim7.dier = (STM32FXXXTIM6and7_DIER_TypeDef*) &TIM7->DIER;
	stm32fxxx_tim7.sr = (STM32FXXXTIM6and7_SR_TypeDef*) &TIM7->SR;
	stm32fxxx_tim7.egr = (STM32FXXXTIM6and7_EGR_TypeDef*) &TIM7->EGR;
	stm32fxxx_tim7.cnt = (STM32FXXXTIM6and7_CNT_TypeDef*) &TIM7->CNT;
	stm32fxxx_tim7.psc = (STM32FXXXTIM6and7_PSC_TypeDef*) &TIM7->PSC;
	stm32fxxx_tim7.arr = (STM32FXXXTIM6and7_ARR_TypeDef*) &TIM7->ARR;
	return &stm32fxxx_tim7;
}
STM32FXXXTIM7obj* tim7(void) { return (STM32FXXXTIM7obj*) &stm32fxxx_tim7; }
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

