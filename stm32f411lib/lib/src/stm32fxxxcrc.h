/******************************************************************************
	STM32 XXX CRC
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 19062023
Comment:
	
*******************************************************************************/
#ifndef _STM32FXXXCRC_H_
	#define _STM32FXXXCRC_H_
/*** Library ***/
#include "stm32fxxxhandler.h"
#include "armquery.h"
/*** CRC TypeDef ***/
typedef struct
{

	/*** Bit Mapping ***/
	void (*dr)(uint32_t value);
	uint32_t (*get_dr)(void);
	void (*idr)(uint8_t value);
	uint8_t (*get_idr)(void);
	void (*reset)(void);
	/*** Other ***/
	void (*clock)(uint8_t bool);
}STM32FXXXCRCobj;

STM32FXXXCRCobj* crc_enable(void);
STM32FXXXCRCobj* crc(void);

/***** CRC Procedure & Function Header ******/
void STM32FXXXCRC_dr(uint32_t value);
uint32_t STM32FXXXCRC_get_dr(void);
void STM32FXXXCRC_idr(uint8_t value);
uint8_t STM32FXXXCRC_get_idr(void);
void STM32FXXXCRC_reset(void);
/*** Other ***/
void STM32FXXXCRC_clock(uint8_t bool);

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

