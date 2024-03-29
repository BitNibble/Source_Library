/******************************************************************************
	STM32 446 TIM 6 and 7
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 22062023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32446tim6and7.h"

/*** File Variable ***/
static STM32446TIM6_CR1 stm32446_tim6_cr1;
static STM32446TIM6_CR2 stm32446_tim6_cr2;
static STM32446TIM6_DIER stm32446_tim6_dier;
static STM32446TIM6_SR stm32446_tim6_sr;
static STM32446TIM6_EGR stm32446_tim6_egr;
static STM32446TIM6obj stm32446_tim6;
static STM32446TIM7_CR1 stm32446_tim7_cr1;
static STM32446TIM7_CR2 stm32446_tim7_cr2;
static STM32446TIM7_DIER stm32446_tim7_dier;
static STM32446TIM7_SR stm32446_tim7_sr;
static STM32446TIM7_EGR stm32446_tim7_egr;
static STM32446TIM7obj stm32446_tim7;

/*** File Procedure & Function Header ***/
/*** Auxiliar ***/
STM32446TIM6_CR1* stm32446_tim6_cr1_inic(void);
STM32446TIM6_CR2* stm32446_tim6_cr2_inic(void);
STM32446TIM6_DIER* stm32446_tim6_dier_inic(void);
STM32446TIM6_SR* stm32446_tim6_sr_inic(void);
STM32446TIM6_EGR* stm32446_tim6_egr_inic(void);
STM32446TIM7_CR1* stm32446_tim7_cr1_inic(void);
STM32446TIM7_CR2* stm32446_tim7_cr2_inic(void);
STM32446TIM7_DIER* stm32446_tim7_dier_inic(void);
STM32446TIM7_SR* stm32446_tim7_sr_inic(void);
STM32446TIM7_EGR* stm32446_tim7_egr_inic(void);
/*** TIMER Procedure & Function Definition ***/
/************/
/*** TIM6 ***/
/************/
void STM32446Tim6Clock(uint8_t bool)
{
	if(bool){RCC->APB1ENR |= (1 << 4);}else{RCC->APB1ENR &= ~(1 << 4);}
}
void STM32446Tim6Nvic(uint8_t bool)
{ // 54
	if(bool){setbit(NVIC->ISER, 1, TIM6_DAC_IRQn, 1);}else{setbit(NVIC->ICER, 1, TIM6_DAC_IRQn, 1);}
}
/************************/
/*** TIM6 Bit Mapping ***/
/************************/
// CR1
void STM32446Tim6_set_apre(uint8_t bool)
{
	setreg(&TIM6->CR1, 1, 7, bool);
}
void STM32446Tim6_set_opm(uint8_t bool)
{
	setreg(&TIM6->CR1, 1, 3, bool);
}
void STM32446Tim6_set_urs(uint8_t bool)
{
	setreg(&TIM6->CR1, 1, 2, bool);
}
void STM32446Tim6_set_udis(uint8_t bool)
{
	setreg(&TIM6->CR1, 1, 1, bool);
}
void STM32446Tim6_cen(uint8_t bool)
{
	setreg(&TIM6->CR1, 1, 0, bool);
}
// CR2
void STM32446Tim6_mms(uint8_t value)
{
	setreg(&TIM6->CR2, 3, 4, value);
}
// DIER
void STM32446Tim6_ude(uint8_t bool)
{
	setreg(&TIM6->DIER, 1, 8, bool);
}
void STM32446Tim6_uie(uint8_t bool)
{
	setreg(&TIM6->DIER, 1, 0, bool);
}
// SR
uint8_t STM32446Tim6_uif(void)
{
	return readreg(TIM6->SR, 1, 0);
}
void STM32446Tim6_clear_uif(void)
{
	setreg(&TIM6->SR, 1, 0, 0);
}
// EGR
void STM32446Tim6_ug(void)
{
	setreg(&TIM6->EGR, 1, 0, 1);
}
// CNT
void STM32446Tim6_cnt(uint16_t value)
{
	TIM6->CNT = value;
}
uint16_t STM32446Tim6_get_cnt(void)
{
	return TIM6->CNT;
}
// PSC
void STM32446Tim6_psc(uint16_t value)
{
	TIM6->PSC = value;
}
// ARR
void STM32446Tim6_arr(uint16_t value)
{
	TIM6->ARR = value;
}
/************/
/*** TIM7 ***/
/************/
void STM32446Tim7Clock(uint8_t bool)
{
	if(bool){RCC->APB1ENR |= (1 << 5);}else{RCC->APB1ENR &= ~(1 << 5);}
}
void STM32446Tim7Nvic(uint8_t bool)
{ // 55
	if(bool){setbit(NVIC->ISER, 1, TIM7_IRQn, 1);}else{setbit(NVIC->ICER, 1, TIM7_IRQn, 1);}
}
/************************/
/*** TIM7 Bit Mapping ***/
/************************/
// CR1
void STM32446Tim7_set_apre(uint8_t bool)
{
	setreg(&TIM7->CR1, 1, 7, bool);
}
void STM32446Tim7_set_opm(uint8_t bool)
{
	setreg(&TIM7->CR1, 1, 3, bool);
}
void STM32446Tim7_set_urs(uint8_t bool)
{
	setreg(&TIM7->CR1, 1, 2, bool);
}
void STM32446Tim7_set_udis(uint8_t bool)
{
	setreg(&TIM7->CR1, 1, 1, bool);
}
void STM32446Tim7_cen(uint8_t bool)
{
	setreg(&TIM7->CR1, 1, 0, bool);
}
// CR2
void STM32446Tim7_mms(uint8_t value)
{
	setreg(&TIM7->CR2, 3, 4, value);
}
// DIER
void STM32446Tim7_ude(uint8_t bool)
{
	setreg(&TIM7->DIER, 1, 8, bool);
}
void STM32446Tim7_uie(uint8_t bool)
{
	setreg(&TIM7->DIER, 1, 0, bool);
}
// SR
uint8_t STM32446Tim7_uif(void)
{
	return readreg(TIM7->SR, 1, 0);
}
void STM32446Tim7_clear_uif(void)
{
	setreg(&TIM7->SR, 1, 0, 0);
}
// EGR
void STM32446Tim7_ug(void)
{
	setreg(&TIM7->EGR, 1, 0, 1);
}
// CNT
void STM32446Tim7_cnt(uint16_t value)
{
	TIM7->CNT = value;
}
uint16_t STM32446Tim7_get_cnt(void)
{
	return TIM7->CNT;
}
// PSC
void STM32446Tim7_psc(uint16_t value)
{
	TIM7->PSC = value;
}
// ARR
void STM32446Tim7_arr(uint16_t value)
{
	TIM7->ARR = value;
}
/********************************************/
/*** INIC Procedure & Function Definition ***/
/********************************************/
/*** TIM6 Auxiliar ***/
STM32446TIM6_CR1* stm32446_tim6_cr1_inic(void)
{

	// CR1
	stm32446_tim6_cr1.apre = STM32446Tim6_set_apre;
	stm32446_tim6_cr1.opm = STM32446Tim6_set_opm;
	stm32446_tim6_cr1.urs = STM32446Tim6_set_urs;
	stm32446_tim6_cr1.udis = STM32446Tim6_set_udis;
	stm32446_tim6_cr1.cen = STM32446Tim6_cen;
	return &stm32446_tim6_cr1;
}
STM32446TIM6_CR2* stm32446_tim6_cr2_inic(void)
{

	// CR2
	stm32446_tim6_cr2.mms = STM32446Tim6_mms;
	return &stm32446_tim6_cr2;
}
STM32446TIM6_DIER* stm32446_tim6_dier_inic(void)
{

	// DIER
	stm32446_tim6_dier.ude = STM32446Tim6_ude;
	stm32446_tim6_dier.uie = STM32446Tim6_uie;
	return &stm32446_tim6_dier;
}
STM32446TIM6_SR* stm32446_tim6_sr_inic(void)
{

	// SR
	stm32446_tim6_sr.uif = STM32446Tim6_uif;
	stm32446_tim6_sr.clear_uif = STM32446Tim6_clear_uif;
	return &stm32446_tim6_sr;
}
STM32446TIM6_EGR* stm32446_tim6_egr_inic(void)
{

	// EGR
	stm32446_tim6_egr.ug = STM32446Tim6_ug;
	return &stm32446_tim6_egr;
}
/*** TIM6 INIC Procedure & Function Definition ***/
STM32446TIM6obj tim6_enable(void)
{


	// CLOCK
	stm32446_tim6.clock = STM32446Tim6Clock;
	// NVIC
	stm32446_tim6.nvic = STM32446Tim6Nvic;
	/*** TIM6 Bit Mapping Link ***/
	stm32446_tim6.cr1 = stm32446_tim6_cr1_inic();
	stm32446_tim6.cr2 = stm32446_tim6_cr2_inic();
	stm32446_tim6.dier = stm32446_tim6_dier_inic();
	stm32446_tim6.sr = stm32446_tim6_sr_inic();
	stm32446_tim6.egr = stm32446_tim6_egr_inic();
	stm32446_tim6.cnt = STM32446Tim6_cnt;
	stm32446_tim6.get_cnt = STM32446Tim6_get_cnt;
	stm32446_tim6.psc = STM32446Tim6_psc;
	stm32446_tim6.arr = STM32446Tim6_arr;
	return stm32446_tim6;
}

STM32446TIM6obj* tim6(void){ return (STM32446TIM6obj*) &stm32446_tim6; }

/*** TIM7 Auxiliar ***/
STM32446TIM7_CR1* stm32446_tim7_cr1_inic(void)
{

	// CR1
	stm32446_tim7_cr1.apre = STM32446Tim7_set_apre;
	stm32446_tim7_cr1.opm = STM32446Tim7_set_opm;
	stm32446_tim7_cr1.urs = STM32446Tim7_set_urs;
	stm32446_tim7_cr1.udis = STM32446Tim7_set_udis;
	stm32446_tim7_cr1.cen = STM32446Tim7_cen;
	return &stm32446_tim7_cr1;
}
STM32446TIM7_CR2* stm32446_tim7_cr2_inic(void)
{

	// CR2
	stm32446_tim7_cr2.mms = STM32446Tim7_mms;
	return &stm32446_tim7_cr2;
}
STM32446TIM7_DIER* stm32446_tim7_dier_inic(void)
{

	// DIER
	stm32446_tim7_dier.ude = STM32446Tim7_ude;
	stm32446_tim7_dier.uie = STM32446Tim7_uie;
	return &stm32446_tim7_dier;
}
STM32446TIM7_SR* stm32446_tim7_sr_inic(void)
{

	// SR
	stm32446_tim7_sr.uif = STM32446Tim7_uif;
	stm32446_tim7_sr.clear_uif = STM32446Tim7_clear_uif;
	return &stm32446_tim7_sr;
}
STM32446TIM7_EGR* stm32446_tim7_egr_inic(void)
{

	// EGR
	stm32446_tim7_egr.ug = STM32446Tim7_ug;
	return &stm32446_tim7_egr;
}
/*** TIM7 INIC Procedure & Function Definition ***/
STM32446TIM7obj tim7_enable(void)
{


	// CLOCK
	stm32446_tim7.clock = STM32446Tim7Clock;
	// NVIC
	stm32446_tim7.nvic = STM32446Tim7Nvic;
	/*** TIM7 Bit Mapping Link ***/
	stm32446_tim7.cr1 = stm32446_tim7_cr1_inic();
	stm32446_tim7.cr2 = stm32446_tim7_cr2_inic();
	stm32446_tim7.dier = stm32446_tim7_dier_inic();
	stm32446_tim7.sr = stm32446_tim7_sr_inic();
	stm32446_tim7.egr = stm32446_tim7_egr_inic();
	stm32446_tim7.cnt = STM32446Tim7_cnt;
	stm32446_tim7.get_cnt = STM32446Tim7_get_cnt;
	stm32446_tim7.psc = STM32446Tim7_psc;
	stm32446_tim7.arr = STM32446Tim7_arr;
	return stm32446_tim7;
}

STM32446TIM7obj* tim7(void) { return (STM32446TIM7obj*) &stm32446_tim7; }

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


