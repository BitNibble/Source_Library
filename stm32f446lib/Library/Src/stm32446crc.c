/******************************************************************************
	STM32 446 CRC
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 19062023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32446crc.h"

/***File Variable ***/
static STM32446CRCobj stm32446_crc;

/*** File Procedure & Function Header ***/
/*** CRC Bit Mapping ***/
void STM32446CRC_dr(uint32_t value)
{
	CRC->DR = value;
}
uint32_t STM32446CRC_get_dr(void)
{
	return CRC->DR;
}
void STM32446CRC_idr(uint8_t value)
{
	CRC->IDR = value;
}
uint8_t STM32446CRC_get_idr(void)
{
	return CRC->IDR;
}
void STM32446CRC_reset(void)
{
	CRC->CR = 1;
}
void STM32446CRC_clock(uint8_t bool)
{
	if(bool){ RCC->AHB1ENR |= (1 << 12); } else{ RCC->AHB1ENR &= ~(1 << 12); }
}
/*** INIC Procedure & Function Definition ***/
STM32446CRCobj crc_inic(void)
{

	stm32446_crc.reg = CRC;
	/***CRC Bit Mapping Link***/
	stm32446_crc.dr = STM32446CRC_dr;
	stm32446_crc.get_dr = STM32446CRC_get_dr;
	stm32446_crc.idr = STM32446CRC_idr;
	stm32446_crc.get_idr = STM32446CRC_get_idr;
	stm32446_crc.reset = STM32446CRC_reset;
	return stm32446_crc;
}

STM32446CRCobj* crc(void){ return (STM32446CRCobj*) &stm32446_crc; }

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


