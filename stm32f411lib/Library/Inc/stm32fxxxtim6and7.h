/******************************************************************************
	STM32 XXX TIM 6 and 7
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 22062023
Comment:
	
*******************************************************************************/
#ifndef _STM32FXXXTIM6AND7_H_
	#define _STM32FXXXTIM6AND7_H_
/*** Library ***/
#include "armquery.h"
#include "stm32timbf.h"
/*** TIMER Bit Mapping TypeDef ***/
// CR1
typedef struct{
	void (*apre)(uint8_t bool);
	void (*opm)(uint8_t bool);
	void (*urs)(uint8_t bool);
	void (*udis)(uint8_t bool);
	void (*cen)(uint8_t bool);
}STM32FXXXTIM6_CR1, STM32FXXXTIM7_CR1;
// CR2
typedef struct{
	void (*mms)(uint8_t value);
}STM32FXXXTIM6_CR2, STM32FXXXTIM7_CR2;
// DIER
typedef struct{
	void (*ude)(uint8_t bool);
	void (*uie)(uint8_t bool);
}STM32FXXXTIM6_DIER, STM32FXXXTIM7_DIER;
// SR
typedef struct{
	uint8_t (*uif)(void);
	void (*clear_uif)(void);
}STM32FXXXTIM6_SR, STM32FXXXTIM7_SR;
// EGR
typedef struct{
	void (*ug)(void);
}STM32FXXXTIM6_EGR, STM32FXXXTIM7_EGR;
/*** TIMER TypeDef***/
// ( 6 and 7 ) TIM 
typedef struct
{

	/*** Bit Mapping ***/
	STM32FXXXTIM6_CR1* cr1;
	STM32FXXXTIM6_CR2* cr2;
	STM32FXXXTIM6_DIER* dier;
	STM32FXXXTIM6_SR* sr;
	STM32FXXXTIM6_EGR* egr;
	void (*cnt)(uint16_t value);
	uint16_t (*get_cnt)(void);
	void (*psc)(uint16_t value);
	void (*arr)(uint16_t value);
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
}STM32FXXXTIM6obj, STM32FXXXTIM7obj;
/************************/
/*** INIC TIM 6 AND 7 ***/
/***********************/
STM32FXXXTIM6obj tim6_enable(void);
STM32FXXXTIM6obj* tim6(void);
STM32FXXXTIM7obj tim7_enable(void);
STM32FXXXTIM7obj* tim7(void);
/****************************************/
/*** TIM6 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim6Clock(uint8_t bool);
void STM32FXXXTim6Nvic(uint8_t bool);
/*** TIM6 Bit Mapping Header ***/
// CR1
void STM32FXXXTim6_set_apre(uint8_t bool);
void STM32FXXXTim6_set_opm(uint8_t bool);
void STM32FXXXTim6_set_urs(uint8_t bool);
void STM32FXXXTim6_set_udis(uint8_t bool);
void STM32FXXXTim6_cen(uint8_t bool);
// CR2
void STM32FXXXTim6_mms(uint8_t value);
// DIER
void STM32FXXXTim6_ude(uint8_t bool);
void STM32FXXXTim6_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim6_uif(void);
void STM32FXXXTim6_clear_uif(void);
// EGR
void STM32FXXXTim6_ug(void);
// CNT
void STM32FXXXTim6_cnt(uint16_t value);
uint16_t STM32FXXXTim6_get_cnt(void);
// PSC
void STM32FXXXTim6_psc(uint16_t value);
// ARR
void STM32FXXXTim6_arr(uint16_t value);
/****************************************/
/*** TIM7 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim7Clock(uint8_t bool);
void STM32FXXXTim7Nvic(uint8_t bool);
/*** TIM7 Bit Mapping Header ***/
// CR1
void STM32FXXXTim7_set_apre(uint8_t bool);
void STM32FXXXTim7_set_opm(uint8_t bool);
void STM32FXXXTim7_set_urs(uint8_t bool);
void STM32FXXXTim7_set_udis(uint8_t bool);
void STM32FXXXTim7_cen(uint8_t bool);
// CR2
void STM32FXXXTim7_mms(uint8_t value);
// DIER
void STM32FXXXTim7_ude(uint8_t bool);
void STM32FXXXTim7_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim7_uif(void);
void STM32FXXXTim7_clear_uif(void);
// EGR
void STM32FXXXTim7_ug(void);
// CNT
void STM32FXXXTim7_cnt(uint16_t value);
uint16_t STM32FXXXTim7_get_cnt(void);
// PSC
void STM32FXXXTim7_psc(uint16_t value);
// ARR
void STM32FXXXTim7_arr(uint16_t value);
/****************************************/

/*** INTERRUPT HEADER ***/
void TIM6_DAC_IRQHandler(void);
void TIM7_IRQHandler(void);

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

