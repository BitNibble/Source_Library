/******************************************************************************
	STM32 XXX ADC3
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 28022024
Comment:
	
*******************************************************************************/
#ifndef _STM32FXXXADC3_H_
	#define _STM32FXXXADC3_H_

/*** Library ***/
#include "stm32fxxxadc.h"

/*** ADC TypeDef ***/
// ADC -> ADC3
typedef struct
{

	STM32FXXXADCCOMMONobj* common;
	/*** Bit Mapping ***/
	STM32FXXXADC_SR_TypeDef* sr;
	STM32FXXXADC_CR1_TypeDef* cr1;
	STM32FXXXADC_CR2_TypeDef* cr2;
	STM32FXXXADC_SMPR1_TypeDef* smpr1;
	STM32FXXXADC_SMPR2_TypeDef* smpr2;
	STM32FXXXADC_JOFRx_TypeDef* jofr1;
	STM32FXXXADC_JOFRx_TypeDef* jofr2;
	STM32FXXXADC_JOFRx_TypeDef* jofr3;
	STM32FXXXADC_JOFRx_TypeDef* jofr4;
	STM32FXXXADC_HTR_TypeDef* htr;
	STM32FXXXADC_LTR_TypeDef* ltr;
	STM32FXXXADC_SQR1_TypeDef* sqr1;
	STM32FXXXADC_SQR2_TypeDef* sqr2;
	STM32FXXXADC_SQR3_TypeDef* sqr3;
	STM32FXXXADC_JSQR_TypeDef* jsqr;
	STM32FXXXADC_JDRx_TypeDef* jdr1;
	STM32FXXXADC_JDRx_TypeDef* jdr2;
	STM32FXXXADC_JDRx_TypeDef* jdr3;
	STM32FXXXADC_JDRx_TypeDef* jdr4;
	STM32FXXXADC_DR_TypeDef* dr;
	/*** Other ***/
	STM32FXXXADC3single* single;
	void (*iclock)(uint8_t bool);
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
}STM32FXXXADC3obj;

// INIC
STM32FXXXADC3obj* adc3_enable(void);
STM32FXXXADC3obj* adc3(void);

/***** ADC3 Procedure & Function Header ******/
void STM32FXXXAdc3IClock(uint8_t bool);
void STM32FXXXAdc3Clock(uint8_t bool);
void STM32FXXXAdc3Nvic(uint8_t bool);
void STM32FXXXAdc3Inic(void);
void STM32FXXXAdc3Start(void);

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

