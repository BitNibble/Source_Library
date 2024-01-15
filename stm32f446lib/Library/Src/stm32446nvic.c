/******************************************************************************
	STM32446 NVIC
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 19062023
Comment:
	Interrupt Vector
*******************************************************************************/
/*** File Library ***/
#include "stm32446nvic.h"

/*** File Variable ***/
static STM32446NVICobj stm32446_nvic;

/*** NVIC Procedure & Function Definition ***/
void STM32446NVIC_set_enable( uint8_t IRQn )
{
	setbit(NVIC->ISER, 1, IRQn, 1);
}
void STM32446NVIC_clear_enable( uint8_t IRQn )
{
	setbit(NVIC->ICER, 1, IRQn, 1);
}
void STM32446NVIC_set_pending( uint8_t IRQn )
{
	setbit(NVIC->ISPR, 1, IRQn, 1);
}
void STM32446NVIC_clear_pending( uint8_t IRQn )
{
	setbit(NVIC->ICPR, 1, IRQn, 1);
}
uint8_t STM32446NVIC_active( uint8_t IRQn ) // Query
{
	volatile uint32_t* reg = NVIC->IABR;
	uint8_t bool; uint32_t n = 0;
	if(IRQn > 31){ n = IRQn/32; IRQn = IRQn - (n * 32); }
	if( *(reg + n ) & (1 << IRQn) ) bool = 1; else bool = 0 ;
	//return nvic_getsetbit(NVIC->ICPR, 1, IRQn);
	return bool;
}
void STM32446NVIC_priority(uint32_t IRQn, uint32_t priority)
{
	volatile uint8_t* reg = (uint8_t*) NVIC->IP;
	*(reg + IRQn ) = priority;
}
void STM32446NVIC_trigger(uint32_t IRQn)
{
	writereg(&NVIC->STIR, 9, 0, IRQn);
}
/*** INIC Procedure & Function Definition ***/
STM32446NVICobj nvic_enable(void)
{

	/*** NVIC Bit Mapping Link ***/
	stm32446_nvic.set_enable = STM32446NVIC_set_enable;
	stm32446_nvic.clear_enable = STM32446NVIC_clear_enable;
	stm32446_nvic.set_pending = STM32446NVIC_set_pending;
	stm32446_nvic.clear_pending = STM32446NVIC_clear_pending;
	stm32446_nvic.active = STM32446NVIC_active;
	stm32446_nvic.priority = STM32446NVIC_priority;
	stm32446_nvic.trigger = STM32446NVIC_trigger;
	return stm32446_nvic;
}

STM32446NVICobj* nvic(void){ return (STM32446NVICobj*) &stm32446_nvic; }

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


