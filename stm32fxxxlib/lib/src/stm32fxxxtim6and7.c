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
static STM32FXXXTIM6_CR1 stm32fxxx_tim6_cr1;
static STM32FXXXTIM6_CR2 stm32fxxx_tim6_cr2;
static STM32FXXXTIM6_DIER stm32fxxx_tim6_dier;
static STM32FXXXTIM6_SR stm32fxxx_tim6_sr;
static STM32FXXXTIM6_EGR stm32fxxx_tim6_egr;
static STM32FXXXTIM6obj stm32fxxx_tim6;
static STM32FXXXTIM7_CR1 stm32fxxx_tim7_cr1;
static STM32FXXXTIM7_CR2 stm32fxxx_tim7_cr2;
static STM32FXXXTIM7_DIER stm32fxxx_tim7_dier;
static STM32FXXXTIM7_SR stm32fxxx_tim7_sr;
static STM32FXXXTIM7_EGR stm32fxxx_tim7_egr;
static STM32FXXXTIM7obj stm32fxxx_tim7;

/*** File Procedure & Function Header ***/
/*** Auxiliar ***/
STM32FXXXTIM6_CR1* stm32fxxx_tim6_cr1_inic(void);
STM32FXXXTIM6_CR2* stm32fxxx_tim6_cr2_inic(void);
STM32FXXXTIM6_DIER* stm32fxxx_tim6_dier_inic(void);
STM32FXXXTIM6_SR* stm32fxxx_tim6_sr_inic(void);
STM32FXXXTIM6_EGR* stm32fxxx_tim6_egr_inic(void);
STM32FXXXTIM7_CR1* stm32fxxx_tim7_cr1_inic(void);
STM32FXXXTIM7_CR2* stm32fxxx_tim7_cr2_inic(void);
STM32FXXXTIM7_DIER* stm32fxxx_tim7_dier_inic(void);
STM32FXXXTIM7_SR* stm32fxxx_tim7_sr_inic(void);
STM32FXXXTIM7_EGR* stm32fxxx_tim7_egr_inic(void);
/*** TIMER Procedure & Function Definition ***/
#ifdef STM32F446xx
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
/************************/
/*** TIM6 Bit Mapping ***/
/************************/
// CR1
void STM32FXXXTim6_set_apre(uint8_t bool)
{
	setreg(&TIM6->CR1, 1, 7, bool);
}
void STM32FXXXTim6_set_opm(uint8_t bool)
{
	setreg(&TIM6->CR1, 1, 3, bool);
}
void STM32FXXXTim6_set_urs(uint8_t bool)
{
	setreg(&TIM6->CR1, 1, 2, bool);
}
void STM32FXXXTim6_set_udis(uint8_t bool)
{
	setreg(&TIM6->CR1, 1, 1, bool);
}
void STM32FXXXTim6_cen(uint8_t bool)
{
	setreg(&TIM6->CR1, 1, 0, bool);
}
// CR2
void STM32FXXXTim6_mms(uint8_t value)
{
	setreg(&TIM6->CR2, 3, 4, value);
}
// DIER
void STM32FXXXTim6_ude(uint8_t bool)
{
	setreg(&TIM6->DIER, 1, 8, bool);
}
void STM32FXXXTim6_uie(uint8_t bool)
{
	setreg(&TIM6->DIER, 1, 0, bool);
}
// SR
uint8_t STM32FXXXTim6_uif(void)
{
	return readreg(TIM6->SR, 1, 0);
}
void STM32FXXXTim6_clear_uif(void)
{
	setreg(&TIM6->SR, 1, 0, 0);
}
// EGR
void STM32FXXXTim6_ug(void)
{
	setreg(&TIM6->EGR, 1, 0, 1);
}
// CNT
void STM32FXXXTim6_cnt(uint16_t value)
{
	TIM6->CNT = value;
}
uint16_t STM32FXXXTim6_get_cnt(void)
{
	return TIM6->CNT;
}
// PSC
void STM32FXXXTim6_psc(uint16_t value)
{
	TIM6->PSC = value;
}
// ARR
void STM32FXXXTim6_arr(uint16_t value)
{
	TIM6->ARR = value;
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
/************************/
/*** TIM7 Bit Mapping ***/
/************************/
// CR1
void STM32FXXXTim7_set_apre(uint8_t bool)
{
	setreg(&TIM7->CR1, 1, 7, bool);
}
void STM32FXXXTim7_set_opm(uint8_t bool)
{
	setreg(&TIM7->CR1, 1, 3, bool);
}
void STM32FXXXTim7_set_urs(uint8_t bool)
{
	setreg(&TIM7->CR1, 1, 2, bool);
}
void STM32FXXXTim7_set_udis(uint8_t bool)
{
	setreg(&TIM7->CR1, 1, 1, bool);
}
void STM32FXXXTim7_cen(uint8_t bool)
{
	setreg(&TIM7->CR1, 1, 0, bool);
}
// CR2
void STM32FXXXTim7_mms(uint8_t value)
{
	setreg(&TIM7->CR2, 3, 4, value);
}
// DIER
void STM32FXXXTim7_ude(uint8_t bool)
{
	setreg(&TIM7->DIER, 1, 8, bool);
}
void STM32FXXXTim7_uie(uint8_t bool)
{
	setreg(&TIM7->DIER, 1, 0, bool);
}
// SR
uint8_t STM32FXXXTim7_uif(void)
{
	return readreg(TIM7->SR, 1, 0);
}
void STM32FXXXTim7_clear_uif(void)
{
	setreg(&TIM7->SR, 1, 0, 0);
}
// EGR
void STM32FXXXTim7_ug(void)
{
	setreg(&TIM7->EGR, 1, 0, 1);
}
// CNT
void STM32FXXXTim7_cnt(uint16_t value)
{
	TIM7->CNT = value;
}
uint16_t STM32FXXXTim7_get_cnt(void)
{
	return TIM7->CNT;
}
// PSC
void STM32FXXXTim7_psc(uint16_t value)
{
	TIM7->PSC = value;
}
// ARR
void STM32FXXXTim7_arr(uint16_t value)
{
	TIM7->ARR = value;
}
#endif
/********************************************/
/*** INIC Procedure & Function Definition ***/
/********************************************/
/*** TIM6 Auxiliar ***/
STM32FXXXTIM6_CR1* stm32fxxx_tim6_cr1_inic(void)
{

	// CR1
	stm32fxxx_tim6_cr1.apre = STM32FXXXTim6_set_apre;
	stm32fxxx_tim6_cr1.opm = STM32FXXXTim6_set_opm;
	stm32fxxx_tim6_cr1.urs = STM32FXXXTim6_set_urs;
	stm32fxxx_tim6_cr1.udis = STM32FXXXTim6_set_udis;
	stm32fxxx_tim6_cr1.cen = STM32FXXXTim6_cen;
	return &stm32fxxx_tim6_cr1;
}
STM32FXXXTIM6_CR2* stm32fxxx_tim6_cr2_inic(void)
{

	// CR2
	stm32fxxx_tim6_cr2.mms = STM32FXXXTim6_mms;
	return &stm32fxxx_tim6_cr2;
}
STM32FXXXTIM6_DIER* stm32fxxx_tim6_dier_inic(void)
{

	// DIER
	stm32fxxx_tim6_dier.ude = STM32FXXXTim6_ude;
	stm32fxxx_tim6_dier.uie = STM32FXXXTim6_uie;
	return &stm32fxxx_tim6_dier;
}
STM32FXXXTIM6_SR* stm32fxxx_tim6_sr_inic(void)
{

	// SR
	stm32fxxx_tim6_sr.uif = STM32FXXXTim6_uif;
	stm32fxxx_tim6_sr.clear_uif = STM32FXXXTim6_clear_uif;
	return &stm32fxxx_tim6_sr;
}
STM32FXXXTIM6_EGR* stm32fxxx_tim6_egr_inic(void)
{

	// EGR
	stm32fxxx_tim6_egr.ug = STM32FXXXTim6_ug;
	return &stm32fxxx_tim6_egr;
}
/*** TIM6 INIC Procedure & Function Definition ***/
STM32FXXXTIM6obj* tim6_enable(void)
{


	// CLOCK
	stm32fxxx_tim6.clock = STM32FXXXTim6Clock;
	// NVIC
	stm32fxxx_tim6.nvic = STM32FXXXTim6Nvic;
	/*** TIM6 Bit Mapping Link ***/
	stm32fxxx_tim6.cr1 = stm32fxxx_tim6_cr1_inic();
	stm32fxxx_tim6.cr2 = stm32fxxx_tim6_cr2_inic();
	stm32fxxx_tim6.dier = stm32fxxx_tim6_dier_inic();
	stm32fxxx_tim6.sr = stm32fxxx_tim6_sr_inic();
	stm32fxxx_tim6.egr = stm32fxxx_tim6_egr_inic();
	stm32fxxx_tim6.cnt = STM32FXXXTim6_cnt;
	stm32fxxx_tim6.get_cnt = STM32FXXXTim6_get_cnt;
	stm32fxxx_tim6.psc = STM32FXXXTim6_psc;
	stm32fxxx_tim6.arr = STM32FXXXTim6_arr;
	return &stm32fxxx_tim6;
}

STM32FXXXTIM6obj* tim6(void){ return (STM32FXXXTIM6obj*) &stm32fxxx_tim6; }

/*** TIM7 Auxiliar ***/
STM32FXXXTIM7_CR1* stm32fxxx_tim7_cr1_inic(void)
{

	// CR1
	stm32fxxx_tim7_cr1.apre = STM32FXXXTim7_set_apre;
	stm32fxxx_tim7_cr1.opm = STM32FXXXTim7_set_opm;
	stm32fxxx_tim7_cr1.urs = STM32FXXXTim7_set_urs;
	stm32fxxx_tim7_cr1.udis = STM32FXXXTim7_set_udis;
	stm32fxxx_tim7_cr1.cen = STM32FXXXTim7_cen;
	return &stm32fxxx_tim7_cr1;
}
STM32FXXXTIM7_CR2* stm32fxxx_tim7_cr2_inic(void)
{

	// CR2
	stm32fxxx_tim7_cr2.mms = STM32FXXXTim7_mms;
	return &stm32fxxx_tim7_cr2;
}
STM32FXXXTIM7_DIER* stm32fxxx_tim7_dier_inic(void)
{

	// DIER
	stm32fxxx_tim7_dier.ude = STM32FXXXTim7_ude;
	stm32fxxx_tim7_dier.uie = STM32FXXXTim7_uie;
	return &stm32fxxx_tim7_dier;
}
STM32FXXXTIM7_SR* stm32fxxx_tim7_sr_inic(void)
{

	// SR
	stm32fxxx_tim7_sr.uif = STM32FXXXTim7_uif;
	stm32fxxx_tim7_sr.clear_uif = STM32FXXXTim7_clear_uif;
	return &stm32fxxx_tim7_sr;
}
STM32FXXXTIM7_EGR* stm32fxxx_tim7_egr_inic(void)
{

	// EGR
	stm32fxxx_tim7_egr.ug = STM32FXXXTim7_ug;
	return &stm32fxxx_tim7_egr;
}
/*** TIM7 INIC Procedure & Function Definition ***/
STM32FXXXTIM7obj* tim7_enable(void)
{


	// CLOCK
	stm32fxxx_tim7.clock = STM32FXXXTim7Clock;
	// NVIC
	stm32fxxx_tim7.nvic = STM32FXXXTim7Nvic;
	/*** TIM7 Bit Mapping Link ***/
	stm32fxxx_tim7.cr1 = stm32fxxx_tim7_cr1_inic();
	stm32fxxx_tim7.cr2 = stm32fxxx_tim7_cr2_inic();
	stm32fxxx_tim7.dier = stm32fxxx_tim7_dier_inic();
	stm32fxxx_tim7.sr = stm32fxxx_tim7_sr_inic();
	stm32fxxx_tim7.egr = stm32fxxx_tim7_egr_inic();
	stm32fxxx_tim7.cnt = STM32FXXXTim7_cnt;
	stm32fxxx_tim7.get_cnt = STM32FXXXTim7_get_cnt;
	stm32fxxx_tim7.psc = STM32FXXXTim7_psc;
	stm32fxxx_tim7.arr = STM32FXXXTim7_arr;
	return &stm32fxxx_tim7;
}

STM32FXXXTIM7obj* tim7(void) { return (STM32FXXXTIM7obj*) &stm32fxxx_tim7; }

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

