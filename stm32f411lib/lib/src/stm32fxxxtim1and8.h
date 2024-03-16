/******************************************************************************
	STM32 XXX TIM 1 and 8
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 22062023
Comment:
	
*******************************************************************************/
#ifndef _STM32FXXXTIM1AND8_H_
	#define _STM32FXXXTIM1AND8_H_
/*** Library ***/
#include "armquery.h"
#include "stm32timbf.h"

/*************************/
/*** TIMER1and8 TypeDef***/
/*************************/
typedef struct
{
	/*** Bit Field ***/
	STM32FXXXTIM1and8_CR1_TypeDef* cr1;
	STM32FXXXTIM1and8_CR2_TypeDef* cr2;
	STM32FXXXTIM1and8_SMCR_TypeDef* smcr;
	STM32FXXXTIM1and8_DIER_TypeDef* dier;
	STM32FXXXTIM1and8_SR_TypeDef* sr;
	STM32FXXXTIM1and8_EGR_TypeDef* egr;
	STM32FXXXTIM1and8_CCMR1_TypeDef* ccmr1;
	STM32FXXXTIM1and8_CCMR2_TypeDef* ccmr2;
	STM32FXXXTIM1and8_CCER_TypeDef* ccer;
	STM32FXXXTIM1and8_CNT_TypeDef* cnt;
	STM32FXXXTIM1and8_PSC_TypeDef* psc;
	STM32FXXXTIM1and8_ARR_TypeDef* arr;
	STM32FXXXTIM1and8_RCR_TypeDef* rcr;
	STM32FXXXTIM1and8_CCR1_TypeDef* ccr1;
	STM32FXXXTIM1and8_CCR2_TypeDef* ccr2;
	STM32FXXXTIM1and8_CCR3_TypeDef* ccr3;
	STM32FXXXTIM1and8_CCR4_TypeDef* ccr4;
	STM32FXXXTIM1and8_BDTR_TypeDef* bdtr;
	STM32FXXXTIM1and8_DCR_TypeDef* dcr;
	STM32FXXXTIM1and8_DMAR_TypeDef* dmar;
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t value);
}STM32FXXXTIM1obj, STM32FXXXTIM8obj;
/*******************/
/*** INIC 1 and 8 ***/
/*******************/
STM32FXXXTIM1obj* tim1_enable(void);
STM32FXXXTIM1obj* tim1(void);
STM32FXXXTIM8obj* tim8_enable(void);
STM32FXXXTIM8obj* tim8(void);
/****************************************/
/*** TIM1 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim1Clock(uint8_t bool);
void STM32FXXXTim1Nvic(uint8_t value);
/****************************************/
/*** TIM8 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim8Clock(uint8_t bool);
void STM32FXXXTim8Nvic(uint8_t value);
/****************************************/
/*** INTERRUPT TIM1 CC CALLBACK HEADER ***/
void tim1_ui_callback(void)__attribute__((weak));
void tim1_cc1_callback(void)__attribute__((weak));
void tim1_cc2_callback(void)__attribute__((weak));
void tim1_t_callback(void)__attribute__((weak));
void tim1_com_callback(void)__attribute__((weak));
void tim1_b_callback(void)__attribute__((weak));
/*** INTERRUPT HEADER ***/
void TIM1_BRK_TIM9_IRQHandler(void);
void TIM1_UP_TIM10_IRQHandler(void);
void TIM1_TRG_COM_TIM11_IRQHandler(void);
void TIM1_CC_IRQHandler(void);
void TIM8_BRK_TIM12_IRQHandler(void);
void TIM8_UP_TIM13_IRQHandler(void);
void TIM8_TRG_COM_TIM14_IRQHandler(void);
void TIM8_CC_IRQHandler(void);

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

