/******************************************************************************
	STM32 XXX TIM 9 to 14
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 22062023
Comment:
	
*******************************************************************************/
#ifndef _STM32FXXXTIM9TO14_H_
	#define _STM32FXXXTIM9TO14_H_
/*** Library ***/
#include "armquery.h"
#include "stm32timbf.h"
/*** TIMER 9 TO 14 TypeDef***/
// ( 9/12 ) TIM
typedef struct
{
	/*** Bit Field ***/
	STM32FXXXTIM9to14_CR1_TypeDef* cr1;
	STM32FXXXTIM9and12_SMCR_TypeDef* smcr;
	STM32FXXXTIM9and12_DIER_TypeDef* dier;
	STM32FXXXTIM9and12_SR_TypeDef* sr;
	STM32FXXXTIM9and12_EGR_TypeDef* egr;
	STM32FXXXTIM9and12_CCMR1_TypeDef* ccmr1;
	STM32FXXXTIM9and12_CCER_TypeDef* ccer;
	STM32FXXXTIM9to14_CNT_TypeDef* cnt;
	STM32FXXXTIM9to14_PSC_TypeDef* psc;
	STM32FXXXTIM9to14_ARR_TypeDef* arr;
	STM32FXXXTIM9to14_CCR1_TypeDef* ccr1;
	STM32FXXXTIM9and12_CCR2_TypeDef* ccr2;
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
}STM32FXXXTIM9obj, STM32FXXXTIM12obj;
// ( 10/11/13/14 ) TIM
typedef struct
{
	/*** Bit Field ***/
	STM32FXXXTIM9to14_CR1_TypeDef* cr1;
	STM32FXXXTIM10and11_DIER_TypeDef* dier;
	STM32FXXXTIM10and11_SR_TypeDef* sr;
	STM32FXXXTIM10and11_EGR_TypeDef* egr;
	STM32FXXXTIM10and11_CCMR1_TypeDef* ccmr1;
	STM32FXXXTIM10and11_CCER_TypeDef* ccer;
	STM32FXXXTIM9to14_CNT_TypeDef* cnt;
	STM32FXXXTIM9to14_PSC_TypeDef* psc;
	STM32FXXXTIM9to14_ARR_TypeDef* arr;
	STM32FXXXTIM9to14_CCR1_TypeDef* ccr1;
	STM32FXXXTIM10and11_OR_TypeDef* or;
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
}STM32FXXXTIM10obj, STM32FXXXTIM11obj, STM32FXXXTIM13obj, STM32FXXXTIM14obj;
/************************/
/*** INIC TIM 9 to 14 ***/
/************************/
STM32FXXXTIM9obj* tim9_enable(void);
STM32FXXXTIM9obj* tim9(void);
STM32FXXXTIM10obj* tim10_enable(void);
STM32FXXXTIM10obj* tim10(void);
STM32FXXXTIM11obj* tim11_enable(void);
STM32FXXXTIM11obj* tim11(void);
STM32FXXXTIM12obj* tim12_enable(void);
STM32FXXXTIM12obj* tim12(void);
STM32FXXXTIM13obj* tim13_enable(void);
STM32FXXXTIM13obj* tim13(void);
STM32FXXXTIM14obj* tim14_enable(void);
STM32FXXXTIM14obj* tim14(void);
/****************************************/
/*** TIM9 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim9Clock(uint8_t bool);
void STM32FXXXTim9Nvic(uint8_t bool);
/*****************************************/
/*** TIM10 Procedure & Function Header ***/
/*****************************************/
void STM32FXXXTim10Clock(uint8_t bool);
void STM32FXXXTim10Nvic(uint8_t bool);
/*****************************************/
/*** TIM11 Procedure & Function Header ***/
/*****************************************/
void STM32FXXXTim11Clock(uint8_t bool);
void STM32FXXXTim11Nvic(uint8_t bool);
/*****************************************/
/*** TIM12 Procedure & Function Header ***/
/*****************************************/
void STM32FXXXTim12Clock(uint8_t bool);
void STM32FXXXTim12Nvic(uint8_t bool);
/*****************************************/
/*** TIM13 Procedure & Function Header ***/
/*****************************************/
void STM32FXXXTim13Clock(uint8_t bool);
void STM32FXXXTim13Nvic(uint8_t bool);
/*****************************************/
/*** TIM14 Procedure & Function Header ***/
/*****************************************/
void STM32FXXXTim14Clock(uint8_t bool);
void STM32FXXXTim14Nvic(uint8_t bool);
/*** INTERRUPT HEADER ***/
void TIM1_BRK_TIM9_IRQHandler(void);
void TIM1_UP_TIM10_IRQHandler(void);
void TIM1_TRG_COM_TIM11_IRQHandler(void);
void TIM8_BRK_TIM12_IRQHandler(void);
void TIM8_UP_TIM13_IRQHandler(void);
void TIM8_TRG_COM_TIM14_IRQHandler(void);

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

