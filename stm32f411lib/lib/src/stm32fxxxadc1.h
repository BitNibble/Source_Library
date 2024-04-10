/******************************************************************************
	STM32 XXX ADC1
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 28022024
Comment:
	
*******************************************************************************/
#ifndef _STM32FXXXADC1_H_
	#define _STM32FXXXADC1_H_

/*** Library ***/
#include "stm32fxxxadc.h"

/*** ADC TypeDef ***/
// ADC -> ADC1
typedef struct
{

	/*** BitField Mapping ***/
	STM32FXXXADC_TypeDef* handle;
	STM32FXXXADC_COMMON_TypeDef* common_handle;
	/*** Other ***/
	STM32FXXXADC1single* single;
	void (*start)(void);
	void (*iclock)(uint8_t bool);
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
}STM32FXXX_ADC1;

// INIC
STM32FXXX_ADC1* adc1_enable(void);
STM32FXXX_ADC1* adc1(void);

/***** ADC1 Procedure & Function Header ******/
void STM32FXXXAdc1IClock(uint8_t bool);
void STM32FXXXAdc1Clock(uint8_t bool);
void STM32FXXXAdc1Nvic(uint8_t bool);
void STM32FXXXAdc1Inic(void);
void STM32FXXXAdc1VBAT(void);
void STM32FXXXAdc1TEMP(void);
void STM32FXXXAdc1Start(void);

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

