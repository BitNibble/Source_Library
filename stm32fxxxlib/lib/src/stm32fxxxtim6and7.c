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
#ifdef __STM32F446xx_H
static STM32FXXX_TIM6 stm32fxxx_tim6;
static STM32FXXX_TIM7 stm32fxxx_tim7;
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
STM32FXXX_TIM6* tim6_enable(void)
{
	/*** TIM6 Bit Mapping Link ***/
	stm32fxxx_tim6.handle = tim6_handle();
	// CLOCK
	stm32fxxx_tim6.clock = STM32FXXXTim6Clock;
	// NVIC
	stm32fxxx_tim6.nvic = STM32FXXXTim6Nvic;

	return &stm32fxxx_tim6;
}
STM32FXXX_TIM6* tim6(void){ return (STM32FXXX_TIM6*) &stm32fxxx_tim6; }
/*** TIM7 INIC Procedure & Function Definition ***/
STM32FXXX_TIM7* tim7_enable(void)
{
	/*** TIM7 Bit Mapping Link ***/
	stm32fxxx_tim7.handle = tim7_handle();
	// CLOCK
	stm32fxxx_tim7.clock = STM32FXXXTim7Clock;
	// NVIC
	stm32fxxx_tim7.nvic = STM32FXXXTim7Nvic;

	return &stm32fxxx_tim7;
}
STM32FXXX_TIM7* tim7(void) { return (STM32FXXX_TIM7*) &stm32fxxx_tim7; }
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

