/************************************************************************
	74HC595
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: 74HC595
Date: 25/10/2020
Update: 05/01/2024
Comment:
	tested Atemga128 16Mhz and Atmega328 8Mhz and STM32F446RET
************************************************************************/
#ifndef _74HC595_H_
	#define _74HC595_H_

/*** File Library ***/
#include <inttypes.h>

/*** File TypeDef ***/
#if defined (STM32F446xx)
typedef struct{
	uint8_t HC595_datapin;
	uint8_t HC595_clkpin;
	uint8_t HC595_outpin;
	volatile uint32_t *hc595_DDR;
	volatile uint32_t *hc595_PORT;
}hc595_parameter;
#else
typedef struct{
	uint8_t HC595_datapin;
	uint8_t HC595_clkpin;
	uint8_t HC595_outpin;
	volatile uint8_t *hc595_DDR;
	volatile uint8_t *hc595_PORT;
}hc595_parameter;
#endif

/*** 74HC595 TypeDef ***/
typedef struct
{
	hc595_parameter par;
	/******/
	void (*bit)(hc595_parameter* par, uint8_t bool);
	void (*ibyte)(hc595_parameter* par, uint8_t byte);
	void (*byte)(hc595_parameter* par, uint8_t byte);
	void (*out)(hc595_parameter* par);
}HC595;

#if defined (STM32F446xx)
HC595 HC595enable(volatile uint32_t *ddr, volatile uint32_t *port, uint8_t datapin, uint8_t clkpin, uint8_t outpin);
#else
HC595 HC595enable(volatile uint8_t *ddr, volatile uint8_t *port, uint8_t datapin, uint8_t clkpin, uint8_t outpin);
#endif

#endif

/***EOF***/

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

