/******************************************************************************
	STM32 XXX TIM 9 to 14
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 22062023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxtim9to14.h"

/*** File Variable ***/
static STM32FXXXTIM9_CR1 stm32fxxx_tim9_cr1;
static STM32FXXXTIM9_SMCR stm32fxxx_tim9_smcr;
static STM32FXXXTIM9_DIER stm32fxxx_tim9_dier;
static STM32FXXXTIM9_SR stm32fxxx_tim9_sr;
static STM32FXXXTIM9_EGR stm32fxxx_tim9_egr;
static STM32FXXXTIM9_CCMR1 stm32fxxx_tim9_ccmr1;
static STM32FXXXTIM9_CCER stm32fxxx_tim9_ccer;
static STM32FXXXTIM9obj stm32fxxx_tim9;
static STM32FXXXTIM10_CR1 stm32fxxx_tim10_cr1;
static STM32FXXXTIM10_DIER stm32fxxx_tim10_dier;
static STM32FXXXTIM10_SR stm32fxxx_tim10_sr;
static STM32FXXXTIM10_EGR stm32fxxx_tim10_egr;
static STM32FXXXTIM10_CCMR1 stm32fxxx_tim10_ccmr1;
static STM32FXXXTIM10_CCER stm32fxxx_tim10_ccer;
static STM32FXXXTIM10obj stm32fxxx_tim10;
static STM32FXXXTIM11_CR1 stm32fxxx_tim11_cr1;
static STM32FXXXTIM11_DIER stm32fxxx_tim11_dier;
static STM32FXXXTIM11_SR stm32fxxx_tim11_sr;
static STM32FXXXTIM11_EGR stm32fxxx_tim11_egr;
static STM32FXXXTIM11_CCMR1 stm32fxxx_tim11_ccmr1;
static STM32FXXXTIM11_CCER stm32fxxx_tim11_ccer;
static STM32FXXXTIM11obj stm32fxxx_tim11;
static STM32FXXXTIM12_CR1 stm32fxxx_tim12_cr1;
static STM32FXXXTIM12_SMCR stm32fxxx_tim12_smcr;
static STM32FXXXTIM12_DIER stm32fxxx_tim12_dier;
static STM32FXXXTIM12_SR stm32fxxx_tim12_sr;
static STM32FXXXTIM12_EGR stm32fxxx_tim12_egr;
static STM32FXXXTIM12_CCMR1 stm32fxxx_tim12_ccmr1;
static STM32FXXXTIM12_CCER stm32fxxx_tim12_ccer;
static STM32FXXXTIM12obj stm32fxxx_tim12;
static STM32FXXXTIM13_CR1 stm32fxxx_tim13_cr1;
static STM32FXXXTIM13_DIER stm32fxxx_tim13_dier;
static STM32FXXXTIM13_SR stm32fxxx_tim13_sr;
static STM32FXXXTIM13_EGR stm32fxxx_tim13_egr;
static STM32FXXXTIM13_CCMR1 stm32fxxx_tim13_ccmr1;
static STM32FXXXTIM13_CCER stm32fxxx_tim13_ccer;
static STM32FXXXTIM13obj stm32fxxx_tim13;
static STM32FXXXTIM14_CR1 stm32fxxx_tim14_cr1;
static STM32FXXXTIM14_DIER stm32fxxx_tim14_dier;
static STM32FXXXTIM14_SR stm32fxxx_tim14_sr;
static STM32FXXXTIM14_EGR stm32fxxx_tim14_egr;
static STM32FXXXTIM14_CCMR1 stm32fxxx_tim14_ccmr1;
static STM32FXXXTIM14_CCER stm32fxxx_tim14_ccer;
static STM32FXXXTIM14obj stm32fxxx_tim14;

/*** File Procedure & Function Header ***/
/*** Auxiliar 9 to 14 ***/
STM32FXXXTIM9_CR1* stm32fxxx_tim9_cr1_inic(void);
STM32FXXXTIM9_SMCR* stm32fxxx_tim9_smcr_inic(void);
STM32FXXXTIM9_DIER* stm32fxxx_tim9_dier_inic(void);
STM32FXXXTIM9_SR* stm32fxxx_tim9_sr_inic(void);
STM32FXXXTIM9_EGR* stm32fxxx_tim9_egr_inic(void);
STM32FXXXTIM9_CCMR1* stm32fxxx_tim9_ccmr1_inic(void);
STM32FXXXTIM9_CCER* stm32fxxx_tim9_ccer_inic(void);
STM32FXXXTIM10_CR1* stm32fxxx_tim10_cr1_inic(void);
STM32FXXXTIM10_DIER* stm32fxxx_tim10_dier_inic(void);
STM32FXXXTIM10_SR* stm32fxxx_tim10_sr_inic(void);
STM32FXXXTIM10_EGR* stm32fxxx_tim10_egr_inic(void);
STM32FXXXTIM10_CCMR1* stm32fxxx_tim10_ccmr1_inic(void);
STM32FXXXTIM10_CCER* stm32fxxx_tim10_ccer_inic(void);
STM32FXXXTIM11_CR1* stm32fxxx_tim11_cr1_inic(void);
STM32FXXXTIM11_DIER* stm32fxxx_tim11_dier_inic(void);
STM32FXXXTIM11_SR* stm32fxxx_tim11_sr_inic(void);
STM32FXXXTIM11_EGR* stm32fxxx_tim11_egr_inic(void);
STM32FXXXTIM11_CCMR1* stm32fxxx_tim11_ccmr1_inic(void);
STM32FXXXTIM11_CCER* stm32fxxx_tim11_ccer_inic(void);
STM32FXXXTIM12_CR1* stm32fxxx_tim12_cr1_inic(void);
STM32FXXXTIM12_SMCR* stm32fxxx_tim12_smcr_inic(void);
STM32FXXXTIM12_DIER* stm32fxxx_tim12_dier_inic(void);
STM32FXXXTIM12_SR* stm32fxxx_tim12_sr_inic(void);
STM32FXXXTIM12_EGR* stm32fxxx_tim12_egr_inic(void);
STM32FXXXTIM12_CCMR1* stm32fxxx_tim12_ccmr1_inic(void);
STM32FXXXTIM12_CCER* stm32fxxx_tim12_ccer_inic(void);
STM32FXXXTIM13_CR1* stm32fxxx_tim13_cr1_inic(void);
STM32FXXXTIM13_DIER* stm32fxxx_tim13_dier_inic(void);
STM32FXXXTIM13_SR* stm32fxxx_tim13_sr_inic(void);
STM32FXXXTIM13_EGR* stm32fxxx_tim13_egr_inic(void);
STM32FXXXTIM13_CCMR1* stm32fxxx_tim13_ccmr1_inic(void);
STM32FXXXTIM13_CCER* stm32fxxx_tim13_ccer_inic(void);
STM32FXXXTIM14_CR1* stm32fxxx_tim14_cr1_inic(void);
STM32FXXXTIM14_DIER* stm32fxxx_tim14_dier_inic(void);
STM32FXXXTIM14_SR* stm32fxxx_tim14_sr_inic(void);
STM32FXXXTIM14_EGR* stm32fxxx_tim14_egr_inic(void);
STM32FXXXTIM14_CCMR1* stm32fxxx_tim14_ccmr1_inic(void);
STM32FXXXTIM14_CCER* stm32fxxx_tim14_ccer_inic(void);
/*** TIMER 9 to 14 Procedure & Function Definition ***/
/************/
/*** TIM9 ***/
/************/
void STM32FXXXTim9Clock(uint8_t bool)
{
	if(bool){RCC->APB2ENR |= (1 << 16);}else{RCC->APB2ENR &= ~(1 << 16);}
}
void STM32FXXXTim9Nvic(uint8_t bool)
{ // 24
	if(bool){setbit(NVIC->ISER, 1, TIM1_BRK_TIM9_IRQn, 1);}else{setbit(NVIC->ICER, 1, TIM1_BRK_TIM9_IRQn, 1);}
}
/************************/
/*** TIM9 Bit Mapping ***/
/************************/
// CR1
void STM32FXXXTim9_ckd(uint8_t value)
{
	setreg(&TIM9->CR1, 2, 8, value);
}
uint8_t STM32FXXXTim9_get_ckd(void)
{
	return readreg(TIM9->CR1, 2, 8);
}
void STM32FXXXTim9_set_apre(uint8_t bool)
{
	setreg(&TIM9->CR1, 1, 7, bool);
}
void STM32FXXXTim9_set_opm(uint8_t bool)
{
	setreg(&TIM9->CR1, 1, 3, bool);
}
void STM32FXXXTim9_set_urs(uint8_t bool)
{
	setreg(&TIM9->CR1, 1, 2, bool);
}
void STM32FXXXTim9_set_udis(uint8_t bool)
{
	setreg(&TIM9->CR1, 1, 1, bool);
}
void STM32FXXXTim9_cen(uint8_t bool)
{
	setreg(&TIM9->CR1, 1, 0, bool);
}
// SMCR
void STM32FXXXTim9_msm(uint8_t bool)
{
	setreg(&TIM9->SMCR, 1, 7, bool);
}
void STM32FXXXTim9_ts(uint8_t value)
{
	setreg(&TIM9->SMCR, 3, 4, value);
}
void STM32FXXXTim9_sms(uint8_t value)
{
	setreg(&TIM9->SMCR, 3, 0, value);
}
// DIER
void STM32FXXXTim9_tie(uint8_t bool)
{
	setreg(&TIM9->DIER, 1, 6, bool);
}
void STM32FXXXTim9_cc2ie(uint8_t bool)
{
	setreg(&TIM9->DIER, 1, 2, bool);
}
void STM32FXXXTim9_cc1ie(uint8_t bool)
{
	setreg(&TIM9->DIER, 1, 1, bool);
}
void STM32FXXXTim9_uie(uint8_t bool)
{
	setreg(&TIM9->DIER, 1, 0, bool);
}
// SR
uint8_t STM32FXXXTim9_cc2of(void)
{
	return readreg(TIM9->SR, 1, 10);
}
void STM32FXXXTim9_clear_cc2of(void)
{
	setreg(&TIM9->SR, 1, 10, 0);
}
uint8_t STM32FXXXTim9_cc1of(void)
{
	return readreg(TIM9->SR, 1, 9);
}
void STM32FXXXTim9_clear_cc1of(void)
{
	setreg(&TIM9->SR, 1, 9, 0);
}
uint8_t STM32FXXXTim9_tif(void)
{
	return readreg(TIM9->SR, 1, 6);
}
void STM32FXXXTim9_clear_tif(void)
{
	setreg(&TIM9->SR, 1, 6, 0);
}
uint8_t STM32FXXXTim9_cc2if(void)
{
	return readreg(TIM9->SR, 1, 2);
}
void STM32FXXXTim9_clear_cc2if(void)
{
	setreg(&TIM9->SR, 1, 2, 0);
}
uint8_t STM32FXXXTim9_cc1if(void)
{
	return readreg(TIM9->SR, 1, 1);
}
void STM32FXXXTim9_clear_cc1if(void)
{
	setreg(&TIM9->SR, 1, 1, 0);
}
uint8_t STM32FXXXTim9_uif(void)
{
	return readreg(TIM9->SR, 1, 0);
}
void STM32FXXXTim9_clear_uif(void)
{
	setreg(&TIM9->SR, 1, 0, 0);
}
// EGR
void STM32FXXXTim9_tg(void)
{
	setreg(&TIM9->EGR, 1, 6, 1);
}
void STM32FXXXTim9_cc2g(void)
{
	setreg(&TIM9->EGR, 1, 2, 1);
}
void STM32FXXXTim9_cc1g(void)
{
	setreg(&TIM9->EGR, 1, 1, 1);
}
void STM32FXXXTim9_ug(void)
{
	setreg(&TIM9->EGR, 1, 0, 1);
}
// CCMR1
void STM32FXXXTim9_oc2m(uint8_t value)
{
	setreg(&TIM9->CCMR1, 3, 12, value);
}
void STM32FXXXTim9_ic2f(uint8_t value)
{
	setreg(&TIM9->CCMR1, 4, 12, value);
}
void STM32FXXXTim9_oc2pe(uint8_t bool)
{
	setreg(&TIM9->CCMR1, 1, 11, bool);
}
void STM32FXXXTim9_oc2fe(uint8_t bool)
{
	setreg(&TIM9->CCMR1, 1, 10, bool);
}
void STM32FXXXTim9_ic2psc(uint8_t value)
{
	setreg(&TIM9->CCMR1, 2, 10, value);
}
void STM32FXXXTim9_cc2s(uint8_t value)
{
	setreg(&TIM9->CCMR1, 2, 8, value);
}
void STM32FXXXTim9_oc1m(uint8_t value)
{
	setreg(&TIM9->CCMR1, 3, 4, value);
}
void STM32FXXXTim9_ic1f(uint8_t value)
{
	setreg(&TIM9->CCMR1, 4, 4, value);
}
void STM32FXXXTim9_oc1pe(uint8_t bool)
{
	setreg(&TIM9->CCMR1, 1, 3, bool);
}
void STM32FXXXTim9_oc1fe(uint8_t bool)
{
	setreg(&TIM9->CCMR1, 1, 2, bool);
}
void STM32FXXXTim9_ic1psc(uint8_t value)
{
	setreg(&TIM9->CCMR1, 2, 2, value);
}
void STM32FXXXTim9_cc1s(uint8_t value)
{
	setreg(&TIM9->CCMR1, 2, 0, value);
}
// CCER
void STM32FXXXTim9_cc2np(uint8_t bool)
{
	setreg(&TIM9->CCER, 1, 7, bool);
}
void STM32FXXXTim9_cc2p(uint8_t bool)
{
	setreg(&TIM9->CCER, 1, 5, bool);
}
void STM32FXXXTim9_cc2e(uint8_t bool)
{
	setreg(&TIM9->CCER, 1, 4, bool);
}
void STM32FXXXTim9_cc1np(uint8_t bool)
{
	setreg(&TIM9->CCER, 1, 3, bool);
}
void STM32FXXXTim9_cc1p(uint8_t bool)
{
	setreg(&TIM9->CCER, 1, 1, bool);
}
void STM32FXXXTim9_cc1e(uint8_t bool)
{
	setreg(&TIM9->CCER, 1, 0, bool);
}
// CNT
void STM32FXXXTim9_cnt(uint16_t value)
{
	TIM9->CNT = value;
}
uint16_t STM32FXXXTim9_get_cnt(void)
{
	return TIM9->CNT;
}
// ARR
void STM32FXXXTim9_arr(uint16_t value)
{
	TIM9->ARR = value;
}
// CCR1
void STM32FXXXTim9_ccr1(uint16_t value)
{
	TIM9->CCR1 = value;
}
// CCR2
void STM32FXXXTim9_ccr2(uint16_t value)
{
	TIM9->CCR2 = value;
}
// PSC
void STM32FXXXTim9_psc(uint16_t value)
{
	TIM9->PSC = value;
}
/*************/
/*** TIM10 ***/
/*************/
void STM32FXXXTim10Clock(uint8_t bool)
{
	if(bool){RCC->APB2ENR |= (1 << 17);}else{RCC->APB2ENR &= ~(1 << 17);}
}
void STM32FXXXTim10Nvic(uint8_t bool)
{ // 25
	if(bool){setbit(NVIC->ISER, 1, TIM1_UP_TIM10_IRQn, 1);} else{setbit(NVIC->ICER, 1, TIM1_UP_TIM10_IRQn, 1);}
}
/*************************/
/*** TIM10 Bit Mapping ***/
/*************************/
// CR1
void STM32FXXXTim10_ckd(uint8_t value)
{
	setreg(&TIM9->CR1, 2, 8, value);
}
uint8_t STM32FXXXTim10_get_ckd(void)
{
	return readreg(TIM10->CR1, 2, 8);
}
void STM32FXXXTim10_set_apre(uint8_t bool)
{
	setreg(&TIM10->CR1, 1, 7, bool);
}
void STM32FXXXTim10_set_opm(uint8_t bool)
{
	setreg(&TIM10->CR1, 1, 3, bool);
}
void STM32FXXXTim10_set_urs(uint8_t bool)
{
	setreg(&TIM10->CR1, 1, 2, bool);
}
void STM32FXXXTim10_set_udis(uint8_t bool)
{
	setreg(&TIM10->CR1, 1, 1, bool);
}
void STM32FXXXTim10_cen(uint8_t bool)
{
	setreg(&TIM10->CR1, 1, 0, bool);
}
// DIER
void STM32FXXXTim10_tie(uint8_t bool)
{
	setreg(&TIM10->DIER, 1, 6, bool);
}
void STM32FXXXTim10_cc2ie(uint8_t bool)
{
	setreg(&TIM10->DIER, 1, 2, bool);
}
void STM32FXXXTim10_cc1ie(uint8_t bool)
{
	setreg(&TIM10->DIER, 1, 1, bool);
}
void STM32FXXXTim10_uie(uint8_t bool)
{
	setreg(&TIM10->DIER, 1, 0, bool);
}
// SR
uint8_t STM32FXXXTim10_cc2of(void)
{
	return readreg(TIM10->SR, 1, 10);
}
void STM32FXXXTim10_clear_cc2of(void)
{
	setreg(&TIM10->SR, 1, 10, 0);
}
uint8_t STM32FXXXTim10_cc1of(void)
{
	return readreg(TIM10->SR, 1, 9);
}
void STM32FXXXTim10_clear_cc1of(void)
{
	setreg(&TIM10->SR, 1, 9, 0);
}
uint8_t STM32FXXXTim10_tif(void)
{
	return readreg(TIM10->SR, 1, 6);
}
void STM32FXXXTim10_clear_tif(void)
{
	setreg(&TIM10->SR, 1, 6, 0);
}
uint8_t STM32FXXXTim10_cc2if(void)
{
	return readreg(TIM10->SR, 1, 2);
}
void STM32FXXXTim10_clear_cc2if(void)
{
	setreg(&TIM10->SR, 1, 2, 0);
}
uint8_t STM32FXXXTim10_cc1if(void)
{
	return readreg(TIM10->SR, 1, 1);
}
void STM32FXXXTim10_clear_cc1if(void)
{
	setreg(&TIM10->SR, 1, 1, 0);
}
uint8_t STM32FXXXTim10_uif(void)
{
	return readreg(TIM10->SR, 1, 0);
}
void STM32FXXXTim10_clear_uif(void)
{
	setreg(&TIM10->SR, 1, 0, 0);
}
// EGR
void STM32FXXXTim10_tg(void)
{
	setreg(&TIM10->EGR, 1, 6, 1);
}
void STM32FXXXTim10_cc2g(void)
{
	setreg(&TIM10->EGR, 1, 2, 1);
}
void STM32FXXXTim10_cc1g(void)
{
	setreg(&TIM10->EGR, 1, 1, 1);
}
void STM32FXXXTim10_ug(void)
{
	setreg(&TIM10->EGR, 1, 0, 1);
}
// CCMR1
void STM32FXXXTim10_oc2m(uint8_t value)
{
	setreg(&TIM10->CCMR1, 3, 12, value);
}
void STM32FXXXTim10_ic2f(uint8_t value)
{
	setreg(&TIM10->CCMR1, 4, 12, value);
}
void STM32FXXXTim10_oc2pe(uint8_t bool)
{
	setreg(&TIM10->CCMR1, 1, 11, bool);
}
void STM32FXXXTim10_oc2fe(uint8_t bool)
{
	setreg(&TIM10->CCMR1, 1, 10, bool);
}
void STM32FXXXTim10_ic2psc(uint8_t value)
{
	setreg(&TIM10->CCMR1, 2, 10, value);
}
void STM32FXXXTim10_cc2s(uint8_t value)
{
	setreg(&TIM10->CCMR1, 2, 8, value);
}
void STM32FXXXTim10_oc1m(uint8_t value)
{
	setreg(&TIM10->CCMR1, 3, 4, value);
}
void STM32FXXXTim10_ic1f(uint8_t value)
{
	setreg(&TIM10->CCMR1, 4, 4, value);
}
void STM32FXXXTim10_oc1pe(uint8_t bool)
{
	setreg(&TIM10->CCMR1, 1, 3, bool);
}
void STM32FXXXTim10_oc1fe(uint8_t bool)
{
	setreg(&TIM10->CCMR1, 1, 2, bool);
}
void STM32FXXXTim10_ic1psc(uint8_t value)
{
	setreg(&TIM10->CCMR1, 2, 2, value);
}
void STM32FXXXTim10_cc1s(uint8_t value)
{
	setreg(&TIM10->CCMR1, 2, 0, value);
}
// CCER
void STM32FXXXTim10_cc2np(uint8_t bool)
{
	setreg(&TIM10->CCER, 1, 7, bool);
}
void STM32FXXXTim10_cc2p(uint8_t bool)
{
	setreg(&TIM10->CCER, 1, 5, bool);
}
void STM32FXXXTim10_cc2e(uint8_t bool)
{
	setreg(&TIM10->CCER, 1, 4, bool);
}
void STM32FXXXTim10_cc1np(uint8_t bool)
{
	setreg(&TIM10->CCER, 1, 3, bool);
}
void STM32FXXXTim10_cc1p(uint8_t bool)
{
	setreg(&TIM10->CCER, 1, 1, bool);
}
void STM32FXXXTim10_cc1e(uint8_t bool)
{
	setreg(&TIM10->CCER, 1, 0, bool);
}
// CNT
void STM32FXXXTim10_cnt(uint16_t value)
{
	TIM10->CNT = value;
}
uint16_t STM32FXXXTim10_get_cnt(void)
{
	return TIM10->CNT;
}
// PSC
void STM32FXXXTim10_psc(uint16_t value)
{
	TIM10->PSC = value;
}
// ARR
void STM32FXXXTim10_arr(uint16_t value)
{
	TIM10->ARR = value;
}
// CCR1
void STM32FXXXTim10_ccr1(uint16_t value)
{
	TIM10->CCR1 = value;
}
// OR
void STM32FXXXTim10_or(uint8_t value)
{
	setreg(&TIM10->OR, 2, 0, value);
}
/*************/
/*** TIM11 ***/
/*************/
void STM32FXXXTim11Clock(uint8_t bool)
{
	if(bool){RCC->APB2ENR |= (1 << 18);}else{RCC->APB2ENR &= ~(1 << 18);}
}
void STM32FXXXTim11Nvic(uint8_t bool)
{ // 26
	if(bool){setbit(NVIC->ISER, 1, TIM1_TRG_COM_TIM11_IRQn, 1);} else{setbit(NVIC->ICER, 1, TIM1_TRG_COM_TIM11_IRQn, 1);}
}
/************************/
/*** TIM11 Bit Mapping ***/
/************************/
// CR1
void STM32FXXXTim11_ckd(uint8_t value)
{
	setreg(&TIM9->CR1, 2, 8, value);
}
uint8_t STM32FXXXTim11_get_ckd(void)
{
	return readreg(TIM11->CR1, 2, 8);
}
void STM32FXXXTim11_set_apre(uint8_t bool)
{
	setreg(&TIM11->CR1, 1, 7, bool);
}
void STM32FXXXTim11_set_opm(uint8_t bool)
{
	setreg(&TIM11->CR1, 1, 3, bool);
}
void STM32FXXXTim11_set_urs(uint8_t bool)
{
	setreg(&TIM11->CR1, 1, 2, bool);
}
void STM32FXXXTim11_set_udis(uint8_t bool)
{
	setreg(&TIM11->CR1, 1, 1, bool);
}
void STM32FXXXTim11_cen(uint8_t bool)
{
	setreg(&TIM11->CR1, 1, 0, bool);
}
// DIER
void STM32FXXXTim11_tie(uint8_t bool)
{
	setreg(&TIM11->DIER, 1, 6, bool);
}
void STM32FXXXTim11_cc2ie(uint8_t bool)
{
	setreg(&TIM11->DIER, 1, 2, bool);
}
void STM32FXXXTim11_cc1ie(uint8_t bool)
{
	setreg(&TIM11->DIER, 1, 1, bool);
}
void STM32FXXXTim11_uie(uint8_t bool)
{
	setreg(&TIM11->DIER, 1, 0, bool);
}
// SR
uint8_t STM32FXXXTim11_cc2of(void)
{
	return readreg(TIM11->SR, 1, 10);
}
void STM32FXXXTim11_clear_cc2of(void)
{
	setreg(&TIM11->SR, 1, 10, 0);
}
uint8_t STM32FXXXTim11_cc1of(void)
{
	return readreg(TIM11->SR, 1, 9);
}
void STM32FXXXTim11_clear_cc1of(void)
{
	setreg(&TIM11->SR, 1, 9, 0);
}
uint8_t STM32FXXXTim11_tif(void)
{
	return readreg(TIM11->SR, 1, 6);
}
void STM32FXXXTim11_clear_tif(void)
{
	setreg(&TIM11->SR, 1, 6, 0);
}
uint8_t STM32FXXXTim11_cc2if(void)
{
	return readreg(TIM11->SR, 1, 2);
}
void STM32FXXXTim11_clear_cc2if(void)
{
	setreg(&TIM11->SR, 1, 2, 0);
}
uint8_t STM32FXXXTim11_cc1if(void)
{
	return readreg(TIM11->SR, 1, 1);
}
void STM32FXXXTim11_clear_cc1if(void)
{
	setreg(&TIM11->SR, 1, 1, 0);
}
uint8_t STM32FXXXTim11_uif(void)
{
	return readreg(TIM11->SR, 1, 0);
}
void STM32FXXXTim11_clear_uif(void)
{
	setreg(&TIM11->SR, 1, 0, 0);
}
// EGR
void STM32FXXXTim11_tg(void)
{
	setreg(&TIM11->EGR, 1, 6, 1);
}
void STM32FXXXTim11_cc2g(void)
{
	setreg(&TIM11->EGR, 1, 2, 1);
}
void STM32FXXXTim11_cc1g(void)
{
	setreg(&TIM11->EGR, 1, 1, 1);
}
void STM32FXXXTim11_ug(void)
{
	setreg(&TIM11->EGR, 1, 0, 1);
}
// CCMR1
void STM32FXXXTim11_oc2m(uint8_t value)
{
	setreg(&TIM11->CCMR1, 3, 12, value);
}
void STM32FXXXTim11_ic2f(uint8_t value)
{
	setreg(&TIM11->CCMR1, 4, 12, value);
}
void STM32FXXXTim11_oc2pe(uint8_t bool)
{
	setreg(&TIM11->CCMR1, 1, 11, bool);
}
void STM32FXXXTim11_oc2fe(uint8_t bool)
{
	setreg(&TIM11->CCMR1, 1, 10, bool);
}
void STM32FXXXTim11_ic2psc(uint8_t value)
{
	setreg(&TIM11->CCMR1, 2, 10, value);
}
void STM32FXXXTim11_cc2s(uint8_t value)
{
	setreg(&TIM11->CCMR1, 2, 8, value);
}
void STM32FXXXTim11_oc1m(uint8_t value)
{
	setreg(&TIM11->CCMR1, 3, 4, value);
}
void STM32FXXXTim11_ic1f(uint8_t value)
{
	setreg(&TIM11->CCMR1, 4, 4, value);
}
void STM32FXXXTim11_oc1pe(uint8_t bool)
{
	setreg(&TIM11->CCMR1, 1, 3, bool);
}
void STM32FXXXTim11_oc1fe(uint8_t bool)
{
	setreg(&TIM11->CCMR1, 1, 2, bool);
}
void STM32FXXXTim11_ic1psc(uint8_t value)
{
	setreg(&TIM11->CCMR1, 2, 2, value);
}
void STM32FXXXTim11_cc1s(uint8_t value)
{
	setreg(&TIM11->CCMR1, 2, 0, value);
}
// CCER
void STM32FXXXTim11_cc2np(uint8_t bool)
{
	setreg(&TIM11->CCER, 1, 7, bool);
}
void STM32FXXXTim11_cc2p(uint8_t bool)
{
	setreg(&TIM11->CCER, 1, 5, bool);
}
void STM32FXXXTim11_cc2e(uint8_t bool)
{
	setreg(&TIM11->CCER, 1, 4, bool);
}
void STM32FXXXTim11_cc1np(uint8_t bool)
{
	setreg(&TIM11->CCER, 1, 3, bool);
}
void STM32FXXXTim11_cc1p(uint8_t bool)
{
	setreg(&TIM11->CCER, 1, 1, bool);
}
void STM32FXXXTim11_cc1e(uint8_t bool)
{
	setreg(&TIM11->CCER, 1, 0, bool);
}
// CNT
void STM32FXXXTim11_cnt(uint16_t value)
{
	TIM11->CNT = value;
}
uint16_t STM32FXXXTim11_get_cnt(void)
{
	return TIM11->CNT;
}
// PSC
void STM32FXXXTim11_psc(uint16_t value)
{
	TIM11->PSC = value;
}
// ARR
void STM32FXXXTim11_arr(uint16_t value)
{
	TIM11->ARR = value;
}
// CCR1
void STM32FXXXTim11_ccr1(uint16_t value)
{
	TIM11->CCR1 = value;
}
// OR
void STM32FXXXTim11_or(uint8_t value)
{
	setreg(&TIM11->OR, 2, 0, value);
}
#ifdef STM32F446xx
/*************/
/*** TIM12 ***/
/*************/
void STM32FXXXTim12Clock(uint8_t bool)
{
	if(bool){RCC->APB1ENR |= (1 << 6);}else{RCC->APB1ENR &= ~(1 << 6);}
}
void STM32FXXXTim12Nvic(uint8_t bool)
{ // 43
	if(bool){setbit(NVIC->ISER, 1, TIM8_BRK_TIM12_IRQn, 1);}else{setbit(NVIC->ICER, 1, TIM8_BRK_TIM12_IRQn, 1);}
}
/************************/
/*** TIM12 Bit Mapping ***/
/************************/
// CR1
void STM32FXXXTim12_ckd(uint8_t value)
{
	setreg(&TIM9->CR1, 2, 8, value);
}
uint8_t STM32FXXXTim12_get_ckd(void)
{
	return readreg(TIM12->CR1, 2, 8);
}
void STM32FXXXTim12_set_apre(uint8_t bool)
{
	setreg(&TIM12->CR1, 1, 7, bool);
}
void STM32FXXXTim12_set_opm(uint8_t bool)
{
	setreg(&TIM12->CR1, 1, 3, bool);
}
void STM32FXXXTim12_set_urs(uint8_t bool)
{
	setreg(&TIM12->CR1, 1, 2, bool);
}
void STM32FXXXTim12_set_udis(uint8_t bool)
{
	setreg(&TIM12->CR1, 1, 1, bool);
}
void STM32FXXXTim12_cen(uint8_t bool)
{
	setreg(&TIM12->CR1, 1, 0, bool);
}
// SMCR
void STM32FXXXTim12_msm(uint8_t bool)
{
	setreg(&TIM12->SMCR, 1, 7, bool);
}
void STM32FXXXTim12_ts(uint8_t value)
{
	setreg(&TIM12->SMCR, 3, 4, value);
}
void STM32FXXXTim12_sms(uint8_t value)
{
	setreg(&TIM12->SMCR, 3, 0, value);
}
// DIER
void STM32FXXXTim12_tie(uint8_t bool)
{
	setreg(&TIM12->DIER, 1, 6, bool);
}
void STM32FXXXTim12_cc2ie(uint8_t bool)
{
	setreg(&TIM12->DIER, 1, 2, bool);
}
void STM32FXXXTim12_cc1ie(uint8_t bool)
{
	setreg(&TIM12->DIER, 1, 1, bool);
}
void STM32FXXXTim12_uie(uint8_t bool)
{
	setreg(&TIM12->DIER, 1, 0, bool);
}
// SR
uint8_t STM32FXXXTim12_cc2of(void)
{
	return readreg(TIM12->SR, 1, 10);
}
void STM32FXXXTim12_clear_cc2of(void)
{
	setreg(&TIM12->SR, 1, 10, 0);
}
uint8_t STM32FXXXTim12_cc1of(void)
{
	return readreg(TIM12->SR, 1, 9);
}
void STM32FXXXTim12_clear_cc1of(void)
{
	setreg(&TIM12->SR, 1, 9, 0);
}
uint8_t STM32FXXXTim12_tif(void)
{
	return readreg(TIM12->SR, 1, 6);
}
void STM32FXXXTim12_clear_tif(void)
{
	setreg(&TIM12->SR, 1, 6, 0);
}
uint8_t STM32FXXXTim12_cc2if(void)
{
	return readreg(TIM12->SR, 1, 2);
}
void STM32FXXXTim12_clear_cc2if(void)
{
	setreg(&TIM12->SR, 1, 2, 0);
}
uint8_t STM32FXXXTim12_cc1if(void)
{
	return readreg(TIM12->SR, 1, 1);
}
void STM32FXXXTim12_clear_cc1if(void)
{
	setreg(&TIM12->SR, 1, 1, 0);
}
uint8_t STM32FXXXTim12_uif(void)
{
	return readreg(TIM12->SR, 1, 0);
}
void STM32FXXXTim12_clear_uif(void)
{
	setreg(&TIM12->SR, 1, 0, 0);
}
// EGR
void STM32FXXXTim12_tg(void)
{
	setreg(&TIM12->EGR, 1, 6, 1);
}
void STM32FXXXTim12_cc2g(void)
{
	setreg(&TIM12->EGR, 1, 2, 1);
}
void STM32FXXXTim12_cc1g(void)
{
	setreg(&TIM12->EGR, 1, 1, 1);
}
void STM32FXXXTim12_ug(void)
{
	setreg(&TIM12->EGR, 1, 0, 1);
}
// CCMR1
void STM32FXXXTim12_oc2m(uint8_t value)
{
	setreg(&TIM12->CCMR1, 3, 12, value);
}
void STM32FXXXTim12_ic2f(uint8_t value)
{
	setreg(&TIM12->CCMR1, 4, 12, value);
}
void STM32FXXXTim12_oc2pe(uint8_t bool)
{
	setreg(&TIM12->CCMR1, 1, 11, bool);
}
void STM32FXXXTim12_oc2fe(uint8_t bool)
{
	setreg(&TIM12->CCMR1, 1, 10, bool);
}
void STM32FXXXTim12_ic2psc(uint8_t value)
{
	setreg(&TIM12->CCMR1, 2, 10, value);
}
void STM32FXXXTim12_cc2s(uint8_t value)
{
	setreg(&TIM12->CCMR1, 2, 8, value);
}
void STM32FXXXTim12_oc1m(uint8_t value)
{
	setreg(&TIM12->CCMR1, 3, 4, value);
}
void STM32FXXXTim12_ic1f(uint8_t value)
{
	setreg(&TIM12->CCMR1, 4, 4, value);
}
void STM32FXXXTim12_oc1pe(uint8_t bool)
{
	setreg(&TIM12->CCMR1, 1, 3, bool);
}
void STM32FXXXTim12_oc1fe(uint8_t bool)
{
	setreg(&TIM12->CCMR1, 1, 2, bool);
}
void STM32FXXXTim12_ic1psc(uint8_t value)
{
	setreg(&TIM12->CCMR1, 2, 2, value);
}
void STM32FXXXTim12_cc1s(uint8_t value)
{
	setreg(&TIM12->CCMR1, 2, 0, value);
}
// CCER
void STM32FXXXTim12_cc2np(uint8_t bool)
{
	setreg(&TIM12->CCER, 1, 7, bool);
}
void STM32FXXXTim12_cc2p(uint8_t bool)
{
	setreg(&TIM12->CCER, 1, 5, bool);
}
void STM32FXXXTim12_cc2e(uint8_t bool)
{
	setreg(&TIM12->CCER, 1, 4, bool);
}
void STM32FXXXTim12_cc1np(uint8_t bool)
{
	setreg(&TIM12->CCER, 1, 3, bool);
}
void STM32FXXXTim12_cc1p(uint8_t bool)
{
	setreg(&TIM12->CCER, 1, 1, bool);
}
void STM32FXXXTim12_cc1e(uint8_t bool)
{
	setreg(&TIM12->CCER, 1, 0, bool);
}
// CNT
void STM32FXXXTim12_cnt(uint16_t value)
{
	TIM12->CNT = value;
}
uint16_t STM32FXXXTim12_get_cnt(void)
{
	return TIM12->CNT;
}
// ARR
void STM32FXXXTim12_arr(uint16_t value)
{
	TIM12->ARR = value;
}
// CCR1
void STM32FXXXTim12_ccr1(uint16_t value)
{
	TIM12->CCR1 = value;
}
// CCR2
void STM32FXXXTim12_ccr2(uint16_t value)
{
	TIM12->CCR2 = value;
}
// PSC
void STM32FXXXTim12_psc(uint16_t value)
{
	TIM12->PSC = value;
}
/*************/
/*** TIM13 ***/
/*************/
void STM32FXXXTim13Clock(uint8_t bool)
{
	if(bool){
		RCC->APB1ENR |= (1 << 7); // timer 13 clock enabled
	}else{
		RCC->APB1ENR &= ~(1 << 7); //timer 13 clock disabled
	}
}
void STM32FXXXTim13Nvic(uint8_t bool)
{ // 44
	if(bool){setbit(NVIC->ISER, 1, TIM8_UP_TIM13_IRQn, 1);}else{setbit(NVIC->ICER, 1, TIM8_UP_TIM13_IRQn, 1);}
}
/************************/
/*** TIM13 Bit Mapping ***/
/************************/
// CR1
void STM32FXXXTim13_ckd(uint8_t value)
{
	setreg(&TIM9->CR1, 2, 8, value);
}
uint8_t STM32FXXXTim13_get_ckd(void)
{
	return readreg(TIM13->CR1, 2, 8);
}
void STM32FXXXTim13_set_apre(uint8_t bool)
{
	setreg(&TIM13->CR1, 1, 7, bool);
}
void STM32FXXXTim13_set_opm(uint8_t bool)
{
	setreg(&TIM13->CR1, 1, 3, bool);
}
void STM32FXXXTim13_set_urs(uint8_t bool)
{
	setreg(&TIM13->CR1, 1, 2, bool);
}
void STM32FXXXTim13_set_udis(uint8_t bool)
{
	setreg(&TIM13->CR1, 1, 1, bool);
}
void STM32FXXXTim13_cen(uint8_t bool)
{
	setreg(&TIM13->CR1, 1, 0, bool);
}
// DIER
void STM32FXXXTim13_tie(uint8_t bool)
{
	setreg(&TIM13->DIER, 1, 6, bool);
}
void STM32FXXXTim13_cc2ie(uint8_t bool)
{
	setreg(&TIM13->DIER, 1, 2, bool);
}
void STM32FXXXTim13_cc1ie(uint8_t bool)
{
	setreg(&TIM13->DIER, 1, 1, bool);
}
void STM32FXXXTim13_uie(uint8_t bool)
{
	setreg(&TIM13->DIER, 1, 0, bool);
}
// SR
uint8_t STM32FXXXTim13_cc2of(void)
{
	return readreg(TIM13->SR, 1, 10);
}
void STM32FXXXTim13_clear_cc2of(void)
{
	setreg(&TIM13->SR, 1, 10, 0);
}
uint8_t STM32FXXXTim13_cc1of(void)
{
	return readreg(TIM13->SR, 1, 9);
}
void STM32FXXXTim13_clear_cc1of(void)
{
	setreg(&TIM13->SR, 1, 9, 0);
}
uint8_t STM32FXXXTim13_tif(void)
{
	return readreg(TIM13->SR, 1, 6);
}
void STM32FXXXTim13_clear_tif(void)
{
	setreg(&TIM13->SR, 1, 6, 0);
}
uint8_t STM32FXXXTim13_cc2if(void)
{
	return readreg(TIM13->SR, 1, 2);
}
void STM32FXXXTim13_clear_cc2if(void)
{
	setreg(&TIM13->SR, 1, 2, 0);
}
uint8_t STM32FXXXTim13_cc1if(void)
{
	return readreg(TIM13->SR, 1, 1);
}
void STM32FXXXTim13_clear_cc1if(void)
{
	setreg(&TIM13->SR, 1, 1, 0);
}
uint8_t STM32FXXXTim13_uif(void)
{
	return readreg(TIM13->SR, 1, 0);
}
void STM32FXXXTim13_clear_uif(void)
{
	setreg(&TIM13->SR, 1, 0, 0);
}
// EGR
void STM32FXXXTim13_tg(void)
{
	setreg(&TIM13->EGR, 1, 6, 1);
}
void STM32FXXXTim13_cc2g(void)
{
	setreg(&TIM13->EGR, 1, 2, 1);
}
void STM32FXXXTim13_cc1g(void)
{
	setreg(&TIM13->EGR, 1, 1, 1);
}
void STM32FXXXTim13_ug(void)
{
	setreg(&TIM13->EGR, 1, 0, 1);
}
// CCMR1
void STM32FXXXTim13_oc2m(uint8_t value)
{
	setreg(&TIM13->CCMR1, 3, 12, value);
}
void STM32FXXXTim13_ic2f(uint8_t value)
{
	setreg(&TIM13->CCMR1, 4, 12, value);
}
void STM32FXXXTim13_oc2pe(uint8_t bool)
{
	setreg(&TIM13->CCMR1, 1, 11, bool);
}
void STM32FXXXTim13_oc2fe(uint8_t bool)
{
	setreg(&TIM13->CCMR1, 1, 10, bool);
}
void STM32FXXXTim13_ic2psc(uint8_t value)
{
	setreg(&TIM13->CCMR1, 2, 10, value);
}
void STM32FXXXTim13_cc2s(uint8_t value)
{
	setreg(&TIM13->CCMR1, 2, 8, value);
}
void STM32FXXXTim13_oc1m(uint8_t value)
{
	setreg(&TIM13->CCMR1, 3, 4, value);
}
void STM32FXXXTim13_ic1f(uint8_t value)
{
	setreg(&TIM13->CCMR1, 4, 4, value);
}
void STM32FXXXTim13_oc1pe(uint8_t bool)
{
	setreg(&TIM13->CCMR1, 1, 3, bool);
}
void STM32FXXXTim13_oc1fe(uint8_t bool)
{
	setreg(&TIM13->CCMR1, 1, 2, bool);
}
void STM32FXXXTim13_ic1psc(uint8_t value)
{
	setreg(&TIM13->CCMR1, 2, 2, value);
}
void STM32FXXXTim13_cc1s(uint8_t value)
{
	setreg(&TIM13->CCMR1, 2, 0, value);
}
// CCER
void STM32FXXXTim13_cc2np(uint8_t bool)
{
	setreg(&TIM13->CCER, 1, 7, bool);
}
void STM32FXXXTim13_cc2p(uint8_t bool)
{
	setreg(&TIM13->CCER, 1, 5, bool);
}
void STM32FXXXTim13_cc2e(uint8_t bool)
{
	setreg(&TIM13->CCER, 1, 4, bool);
}
void STM32FXXXTim13_cc1np(uint8_t bool)
{
	setreg(&TIM13->CCER, 1, 3, bool);
}
void STM32FXXXTim13_cc1p(uint8_t bool)
{
	setreg(&TIM13->CCER, 1, 1, bool);
}
void STM32FXXXTim13_cc1e(uint8_t bool)
{
	setreg(&TIM13->CCER, 1, 0, bool);
}
// CNT
void STM32FXXXTim13_cnt(uint16_t value)
{
	TIM13->CNT = value;
}
uint16_t STM32FXXXTim13_get_cnt(void)
{
	return TIM13->CNT;
}
// PSC
void STM32FXXXTim13_psc(uint16_t value)
{
	TIM13->PSC = value;
}
// ARR
void STM32FXXXTim13_arr(uint16_t value)
{
	TIM13->ARR = value;
}
// CCR1
void STM32FXXXTim13_ccr1(uint16_t value)
{
	TIM13->CCR1 = value;
}
// OR
void STM32FXXXTim13_or(uint8_t value)
{
	setreg(&TIM13->OR, 2, 0, value);
}
/*************/
/*** TIM14 ***/
/*************/
void STM32FXXXTim14Clock(uint8_t bool)
{
	if(bool){RCC->APB1ENR |= (1 << 8);}else{RCC->APB1ENR &= ~(1 << 8);}
}
void STM32FXXXTim14Nvic(uint8_t bool)
{ // 45
	if(bool){setbit(NVIC->ISER, 1, TIM8_TRG_COM_TIM14_IRQn, 1);}else{setbit(NVIC->ICER, 1, TIM8_TRG_COM_TIM14_IRQn, 1);}
}
/************************/
/*** TIM14 Bit Mapping ***/
/************************/
// CR1
void STM32FXXXTim14_ckd(uint8_t value)
{
	setreg(&TIM9->CR1, 2, 8, value);
}
uint8_t STM32FXXXTim14_get_ckd(void)
{
	return readreg(TIM14->CR1, 2, 8);
}
void STM32FXXXTim14_set_apre(uint8_t bool)
{
	setreg(&TIM14->CR1, 1, 7, bool);
}
void STM32FXXXTim14_set_opm(uint8_t bool)
{
	setreg(&TIM14->CR1, 1, 3, bool);
}
void STM32FXXXTim14_set_urs(uint8_t bool)
{
	setreg(&TIM14->CR1, 1, 2, bool);
}
void STM32FXXXTim14_set_udis(uint8_t bool)
{
	setreg(&TIM14->CR1, 1, 1, bool);
}
void STM32FXXXTim14_cen(uint8_t bool)
{
	setreg(&TIM14->CR1, 1, 0, bool);
}
// DIER
void STM32FXXXTim14_tie(uint8_t bool)
{
	setreg(&TIM14->DIER, 1, 6, bool);
}
void STM32FXXXTim14_cc2ie(uint8_t bool)
{
	setreg(&TIM14->DIER, 1, 2, bool);
}
void STM32FXXXTim14_cc1ie(uint8_t bool)
{
	setreg(&TIM14->DIER, 1, 1, bool);
}
void STM32FXXXTim14_uie(uint8_t bool)
{
	setreg(&TIM14->DIER, 1, 0, bool);
}
// SR
uint8_t STM32FXXXTim14_cc2of(void)
{
	return readreg(TIM14->SR, 1, 10);
}
void STM32FXXXTim14_clear_cc2of(void)
{
	setreg(&TIM14->SR, 1, 10, 0);
}
uint8_t STM32FXXXTim14_cc1of(void)
{
	return readreg(TIM14->SR, 1, 9);
}
void STM32FXXXTim14_clear_cc1of(void)
{
	setreg(&TIM14->SR, 1, 9, 0);
}
uint8_t STM32FXXXTim14_tif(void)
{
	return readreg(TIM14->SR, 1, 6);
}
void STM32FXXXTim14_clear_tif(void)
{
	setreg(&TIM14->SR, 1, 6, 0);
}
uint8_t STM32FXXXTim14_cc2if(void)
{
	return readreg(TIM14->SR, 1, 2);
}
void STM32FXXXTim14_clear_cc2if(void)
{
	setreg(&TIM14->SR, 1, 2, 0);
}
uint8_t STM32FXXXTim14_cc1if(void)
{
	return readreg(TIM14->SR, 1, 1);
}
void STM32FXXXTim14_clear_cc1if(void)
{
	setreg(&TIM14->SR, 1, 1, 0);
}
uint8_t STM32FXXXTim14_uif(void)
{
	return readreg(TIM14->SR, 1, 0);
}
void STM32FXXXTim14_clear_uif(void)
{
	setreg(&TIM14->SR, 1, 0, 0);
}
// EGR
void STM32FXXXTim14_tg(void)
{
	setreg(&TIM14->EGR, 1, 6, 1);
}
void STM32FXXXTim14_cc2g(void)
{
	setreg(&TIM14->EGR, 1, 2, 1);
}
void STM32FXXXTim14_cc1g(void)
{
	setreg(&TIM14->EGR, 1, 1, 1);
}
void STM32FXXXTim14_ug(void)
{
	setreg(&TIM14->EGR, 1, 0, 1);
}
// CCMR1
void STM32FXXXTim14_oc2m(uint8_t value)
{
	setreg(&TIM14->CCMR1, 3, 12, value);
}
void STM32FXXXTim14_ic2f(uint8_t value)
{
	setreg(&TIM14->CCMR1, 4, 12, value);
}
void STM32FXXXTim14_oc2pe(uint8_t bool)
{
	setreg(&TIM14->CCMR1, 1, 11, bool);
}
void STM32FXXXTim14_oc2fe(uint8_t bool)
{
	setreg(&TIM14->CCMR1, 1, 10, bool);
}
void STM32FXXXTim14_ic2psc(uint8_t value)
{
	setreg(&TIM14->CCMR1, 2, 10, value);
}
void STM32FXXXTim14_cc2s(uint8_t value)
{
	setreg(&TIM14->CCMR1, 2, 8, value);
}
void STM32FXXXTim14_oc1m(uint8_t value)
{
	setreg(&TIM14->CCMR1, 3, 4, value);
}
void STM32FXXXTim14_ic1f(uint8_t value)
{
	setreg(&TIM14->CCMR1, 4, 4, value);
}
void STM32FXXXTim14_oc1pe(uint8_t bool)
{
	setreg(&TIM14->CCMR1, 1, 3, bool);
}
void STM32FXXXTim14_oc1fe(uint8_t bool)
{
	setreg(&TIM14->CCMR1, 1, 2, bool);
}
void STM32FXXXTim14_ic1psc(uint8_t value)
{
	setreg(&TIM14->CCMR1, 2, 2, value);
}
void STM32FXXXTim14_cc1s(uint8_t value)
{
	setreg(&TIM14->CCMR1, 2, 0, value);
}
// CCER
void STM32FXXXTim14_cc2np(uint8_t bool)
{
	setreg(&TIM14->CCER, 1, 7, bool);
}
void STM32FXXXTim14_cc2p(uint8_t bool)
{
	setreg(&TIM14->CCER, 1, 5, bool);
}
void STM32FXXXTim14_cc2e(uint8_t bool)
{
	setreg(&TIM14->CCER, 1, 4, bool);
}
void STM32FXXXTim14_cc1np(uint8_t bool)
{
	setreg(&TIM14->CCER, 1, 3, bool);
}
void STM32FXXXTim14_cc1p(uint8_t bool)
{
	setreg(&TIM14->CCER, 1, 1, bool);
}
void STM32FXXXTim14_cc1e(uint8_t bool)
{
	setreg(&TIM14->CCER, 1, 0, bool);
}
// CNT
void STM32FXXXTim14_cnt(uint16_t value)
{
	TIM14->CNT = value;
}
uint16_t STM32FXXXTim14_get_cnt(void)
{
	return TIM14->CNT;
}
// PSC
void STM32FXXXTim14_psc(uint16_t value)
{
	TIM14->PSC = value;
}
// ARR
void STM32FXXXTim14_arr(uint16_t value)
{
	TIM14->ARR = value;
}
// CCR1
void STM32FXXXTim14_ccr1(uint16_t value)
{
	TIM14->CCR1 = value;
}
// OR
void STM32FXXXTim14_or(uint8_t value)
{
	setreg(&TIM14->OR, 2, 0, value);
}
#endif
/*** TIM9 AUX Procedure & Function Definition ***/
STM32FXXXTIM9_CR1* stm32fxxx_tim9_cr1_inic(void)
{

	// CR1
	stm32fxxx_tim9_cr1.get_ckd = STM32FXXXTim9_get_ckd;
	stm32fxxx_tim9_cr1.apre = STM32FXXXTim9_set_apre;
	stm32fxxx_tim9_cr1.opm = STM32FXXXTim9_set_opm;
	stm32fxxx_tim9_cr1.urs = STM32FXXXTim9_set_urs;
	stm32fxxx_tim9_cr1.udis = STM32FXXXTim9_set_udis;
	stm32fxxx_tim9_cr1.cen = STM32FXXXTim9_cen;
	return &stm32fxxx_tim9_cr1;
}
STM32FXXXTIM9_SMCR* stm32fxxx_tim9_smcr_inic(void)
{

	// SMCR
	stm32fxxx_tim9_smcr.msm = STM32FXXXTim9_msm;
	stm32fxxx_tim9_smcr.ts = STM32FXXXTim9_ts;
	stm32fxxx_tim9_smcr.sms = STM32FXXXTim9_sms;
	return &stm32fxxx_tim9_smcr;
}
STM32FXXXTIM9_DIER* stm32fxxx_tim9_dier_inic(void)
{

	// DIER
	stm32fxxx_tim9_dier.tie = STM32FXXXTim9_tie;
	stm32fxxx_tim9_dier.cc2ie = STM32FXXXTim9_cc2ie;
	stm32fxxx_tim9_dier.cc1ie = STM32FXXXTim9_cc1ie;
	stm32fxxx_tim9_dier.uie = STM32FXXXTim9_uie;
	return &stm32fxxx_tim9_dier;
}
STM32FXXXTIM9_SR* stm32fxxx_tim9_sr_inic(void)
{

	// SR
	stm32fxxx_tim9_sr.cc2of = STM32FXXXTim9_cc2of;
	stm32fxxx_tim9_sr.clear_cc2of = STM32FXXXTim9_clear_cc2of;
	stm32fxxx_tim9_sr.cc1of = STM32FXXXTim9_cc1of;
	stm32fxxx_tim9_sr.clear_cc1of = STM32FXXXTim9_clear_cc1of;
	stm32fxxx_tim9_sr.tif = STM32FXXXTim9_tif;
	stm32fxxx_tim9_sr.clear_tif = STM32FXXXTim9_clear_tif;
	stm32fxxx_tim9_sr.cc2if = STM32FXXXTim9_cc2if;
	stm32fxxx_tim9_sr.clear_cc2if = STM32FXXXTim9_clear_cc2if;
	stm32fxxx_tim9_sr.cc1if = STM32FXXXTim9_cc1if;
	stm32fxxx_tim9_sr.clear_cc1if = STM32FXXXTim9_clear_cc1if;
	stm32fxxx_tim9_sr.uif = STM32FXXXTim9_uif;
	stm32fxxx_tim9_sr.clear_uif = STM32FXXXTim9_clear_uif;
	return &stm32fxxx_tim9_sr;
}
STM32FXXXTIM9_EGR* stm32fxxx_tim9_egr_inic(void)
{

	// EGR
	stm32fxxx_tim9_egr.tg = STM32FXXXTim9_tg;
	stm32fxxx_tim9_egr.cc2g = STM32FXXXTim9_cc2g;
	stm32fxxx_tim9_egr.cc1g = STM32FXXXTim9_cc1g;
	stm32fxxx_tim9_egr.ug = STM32FXXXTim9_ug;
	return &stm32fxxx_tim9_egr;
}
STM32FXXXTIM9_CCMR1* stm32fxxx_tim9_ccmr1_inic(void)
{

	// CCMR1
	stm32fxxx_tim9_ccmr1.oc2m = STM32FXXXTim9_oc2m;
	stm32fxxx_tim9_ccmr1.ic2f = STM32FXXXTim9_ic2f;
	stm32fxxx_tim9_ccmr1.oc2pe = STM32FXXXTim9_oc2pe;
	stm32fxxx_tim9_ccmr1.oc2fe = STM32FXXXTim9_oc2fe;
	stm32fxxx_tim9_ccmr1.ic2psc = STM32FXXXTim9_ic2psc;
	stm32fxxx_tim9_ccmr1.cc2s = STM32FXXXTim9_cc2s;
	stm32fxxx_tim9_ccmr1.oc1m = STM32FXXXTim9_oc1m;
	stm32fxxx_tim9_ccmr1.ic1f = STM32FXXXTim9_ic1f;
	stm32fxxx_tim9_ccmr1.oc1pe = STM32FXXXTim9_oc1pe;
	stm32fxxx_tim9_ccmr1.oc1fe = STM32FXXXTim9_oc1fe;
	stm32fxxx_tim9_ccmr1.ic1psc = STM32FXXXTim9_ic1psc;
	stm32fxxx_tim9_ccmr1.cc1s = STM32FXXXTim9_cc1s;
	return &stm32fxxx_tim9_ccmr1;
}
STM32FXXXTIM9_CCER* stm32fxxx_tim9_ccer_inic(void)
{

	// CCER
	stm32fxxx_tim9_ccer.cc2np = STM32FXXXTim9_cc2np;
	stm32fxxx_tim9_ccer.cc2p = STM32FXXXTim9_cc2p;
	stm32fxxx_tim9_ccer.cc2e = STM32FXXXTim9_cc2e;
	stm32fxxx_tim9_ccer.cc1np = STM32FXXXTim9_cc1np;
	stm32fxxx_tim9_ccer.cc1p = STM32FXXXTim9_cc1p;
	stm32fxxx_tim9_ccer.cc1e = STM32FXXXTim9_cc1e;
	return &stm32fxxx_tim9_ccer;
}
/*** TIM9 Procedure & Function Definition ***/
STM32FXXXTIM9obj tim9_enable(void)
{


	// CLOCK
	stm32fxxx_tim9.clock = STM32FXXXTim9Clock;
	// NVIC
	stm32fxxx_tim9.nvic = STM32FXXXTim9Nvic;
	/*** TIM9 Bit Mapping Link ***/
	stm32fxxx_tim9.cr1 = stm32fxxx_tim9_cr1_inic();
	stm32fxxx_tim9.smcr = stm32fxxx_tim9_smcr_inic();
	stm32fxxx_tim9.dier = stm32fxxx_tim9_dier_inic();
	stm32fxxx_tim9.sr = stm32fxxx_tim9_sr_inic();
	stm32fxxx_tim9.egr = stm32fxxx_tim9_egr_inic();
	stm32fxxx_tim9.ccmr1 = stm32fxxx_tim9_ccmr1_inic();
	stm32fxxx_tim9.ccer = stm32fxxx_tim9_ccer_inic();
	stm32fxxx_tim9.cnt = STM32FXXXTim9_cnt;
	stm32fxxx_tim9.get_cnt = STM32FXXXTim9_get_cnt;
	stm32fxxx_tim9.arr = STM32FXXXTim9_arr;
	stm32fxxx_tim9.ccr1 = STM32FXXXTim9_ccr1;
	stm32fxxx_tim9.ccr2 = STM32FXXXTim9_ccr2;
	stm32fxxx_tim9.psc = STM32FXXXTim9_psc;
	return stm32fxxx_tim9;
}

STM32FXXXTIM9obj* tim9(void){ return (STM32FXXXTIM9obj*) &stm32fxxx_tim9; }

/*** TIM10 AUX Procedure & Function Definition ***/
STM32FXXXTIM10_CR1* stm32fxxx_tim10_cr1_inic(void)
{

	// CR1
	stm32fxxx_tim10_cr1.get_ckd = STM32FXXXTim10_get_ckd;
	stm32fxxx_tim10_cr1.apre = STM32FXXXTim10_set_apre;
	stm32fxxx_tim10_cr1.urs = STM32FXXXTim10_set_urs;
	stm32fxxx_tim10_cr1.udis = STM32FXXXTim10_set_udis;
	stm32fxxx_tim10_cr1.cen = STM32FXXXTim10_cen;
	return &stm32fxxx_tim10_cr1;
}
STM32FXXXTIM10_DIER* stm32fxxx_tim10_dier_inic(void)
{

	// DIER
	stm32fxxx_tim10_dier.cc1ie = STM32FXXXTim10_cc1ie;
	stm32fxxx_tim10_dier.uie = STM32FXXXTim10_uie;
	return &stm32fxxx_tim10_dier;
}
STM32FXXXTIM10_SR* stm32fxxx_tim10_sr_inic(void)
{

	// SR
	stm32fxxx_tim10_sr.cc1of = STM32FXXXTim10_cc1of;
	stm32fxxx_tim10_sr.clear_cc1of = STM32FXXXTim10_clear_cc1of;
	stm32fxxx_tim10_sr.cc1if = STM32FXXXTim10_cc1if;
	stm32fxxx_tim10_sr.clear_cc1if = STM32FXXXTim10_clear_cc1if;
	stm32fxxx_tim10_sr.uif = STM32FXXXTim10_uif;
	stm32fxxx_tim10_sr.clear_uif = STM32FXXXTim10_clear_uif;
	return &stm32fxxx_tim10_sr;
}
STM32FXXXTIM10_EGR* stm32fxxx_tim10_egr_inic(void)
{

	// EGR
	stm32fxxx_tim10_egr.cc1g = STM32FXXXTim10_cc1g;
	stm32fxxx_tim10_egr.ug = STM32FXXXTim10_ug;
	return &stm32fxxx_tim10_egr;
}
STM32FXXXTIM10_CCMR1* stm32fxxx_tim10_ccmr1_inic(void)
{

	// CCMR1
	stm32fxxx_tim10_ccmr1.oc1m = STM32FXXXTim10_oc1m;
	stm32fxxx_tim10_ccmr1.ic1f = STM32FXXXTim10_ic1f;
	stm32fxxx_tim10_ccmr1.oc1pe = STM32FXXXTim10_oc1pe;
	stm32fxxx_tim10_ccmr1.oc1fe = STM32FXXXTim10_oc1fe;
	stm32fxxx_tim10_ccmr1.ic1psc = STM32FXXXTim10_ic1psc;
	stm32fxxx_tim10_ccmr1.cc1s = STM32FXXXTim10_cc1s;
	return &stm32fxxx_tim10_ccmr1;
}
STM32FXXXTIM10_CCER* stm32fxxx_tim10_ccer_inic(void)
{

	// CCER
	stm32fxxx_tim10_ccer.cc1np = STM32FXXXTim10_cc1np;
	stm32fxxx_tim10_ccer.cc1p = STM32FXXXTim10_cc1p;
	stm32fxxx_tim10_ccer.cc1e = STM32FXXXTim10_cc1e;
	return &stm32fxxx_tim10_ccer;
}
/*** TIM10 Procedure & Function Definition***/
STM32FXXXTIM10obj tim10_enable(void)
{


	// CLOCK
	stm32fxxx_tim10.clock = STM32FXXXTim10Clock;
	// NVIC
	stm32fxxx_tim10.nvic = STM32FXXXTim10Nvic;
	/*** TIM10 Bit Mapping Link ***/
	stm32fxxx_tim10.cr1 = stm32fxxx_tim10_cr1_inic();
	stm32fxxx_tim10.dier = stm32fxxx_tim10_dier_inic();
	stm32fxxx_tim10.sr = stm32fxxx_tim10_sr_inic();
	stm32fxxx_tim10.egr = stm32fxxx_tim10_egr_inic();
	stm32fxxx_tim10.ccmr1 = stm32fxxx_tim10_ccmr1_inic();
	stm32fxxx_tim10.ccer = stm32fxxx_tim10_ccer_inic();
	stm32fxxx_tim10.cnt = STM32FXXXTim10_cnt;
	stm32fxxx_tim10.get_cnt = STM32FXXXTim10_get_cnt;
	stm32fxxx_tim10.psc = STM32FXXXTim10_psc;
	stm32fxxx_tim10.arr = STM32FXXXTim10_arr;
	stm32fxxx_tim10.ccr1 = STM32FXXXTim10_ccr1;
	stm32fxxx_tim10.or = STM32FXXXTim10_or;
	return stm32fxxx_tim10;
}

STM32FXXXTIM10obj* tim10(void){ return (STM32FXXXTIM10obj*) &stm32fxxx_tim10; }

/*** TIM11 AUX Procedure & Function Definition***/
STM32FXXXTIM11_CR1* stm32fxxx_tim11_cr1_inic(void)
{

	// CR1
	stm32fxxx_tim11_cr1.get_ckd = STM32FXXXTim11_get_ckd;
	stm32fxxx_tim11_cr1.apre = STM32FXXXTim11_set_apre;
	stm32fxxx_tim11_cr1.urs = STM32FXXXTim11_set_urs;
	stm32fxxx_tim11_cr1.udis = STM32FXXXTim11_set_udis;
	stm32fxxx_tim11_cr1.cen = STM32FXXXTim11_cen;
	return &stm32fxxx_tim11_cr1;
}
STM32FXXXTIM11_DIER* stm32fxxx_tim11_dier_inic(void)
{

	// DIER
	stm32fxxx_tim11_dier.cc1ie = STM32FXXXTim11_cc1ie;
	stm32fxxx_tim11_dier.uie = STM32FXXXTim11_uie;
	return &stm32fxxx_tim11_dier;
}
STM32FXXXTIM11_SR* stm32fxxx_tim11_sr_inic(void)
{

	// SR
	stm32fxxx_tim11_sr.cc1of = STM32FXXXTim11_cc1of;
	stm32fxxx_tim11_sr.clear_cc1of = STM32FXXXTim11_clear_cc1of;
	stm32fxxx_tim11_sr.cc1if = STM32FXXXTim11_cc1if;
	stm32fxxx_tim11_sr.clear_cc1if = STM32FXXXTim11_clear_cc1if;
	stm32fxxx_tim11_sr.uif = STM32FXXXTim11_uif;
	stm32fxxx_tim11_sr.clear_uif = STM32FXXXTim11_clear_uif;
	return &stm32fxxx_tim11_sr;
}
STM32FXXXTIM11_EGR* stm32fxxx_tim11_egr_inic(void)
{

	// EGR
	stm32fxxx_tim11_egr.cc1g = STM32FXXXTim11_cc1g;
	stm32fxxx_tim11_egr.ug = STM32FXXXTim11_ug;
	return &stm32fxxx_tim11_egr;
}
STM32FXXXTIM11_CCMR1* stm32fxxx_tim11_ccmr1_inic(void)
{

	// CCMR1
	stm32fxxx_tim11_ccmr1.oc1m = STM32FXXXTim11_oc1m;
	stm32fxxx_tim11_ccmr1.ic1f = STM32FXXXTim11_ic1f;
	stm32fxxx_tim11_ccmr1.oc1pe = STM32FXXXTim11_oc1pe;
	stm32fxxx_tim11_ccmr1.oc1fe = STM32FXXXTim11_oc1fe;
	stm32fxxx_tim11_ccmr1.ic1psc = STM32FXXXTim11_ic1psc;
	stm32fxxx_tim11_ccmr1.cc1s = STM32FXXXTim11_cc1s;
	return &stm32fxxx_tim11_ccmr1;
}
STM32FXXXTIM11_CCER* stm32fxxx_tim11_ccer_inic(void)
{

	// CCER
	stm32fxxx_tim11_ccer.cc1np = STM32FXXXTim11_cc1np;
	stm32fxxx_tim11_ccer.cc1p = STM32FXXXTim11_cc1p;
	stm32fxxx_tim11_ccer.cc1e = STM32FXXXTim11_cc1e;
	return &stm32fxxx_tim11_ccer;
}
/*** TIM11 Procedure & Function Definition***/
STM32FXXXTIM11obj tim11_enable(void)
{


	// CLOCK
	stm32fxxx_tim11.clock = STM32FXXXTim11Clock;
	// NVIC
	stm32fxxx_tim11.nvic = STM32FXXXTim11Nvic;
	/*** TIM11 Bit Mapping Link ***/
	stm32fxxx_tim11.cr1 = stm32fxxx_tim11_cr1_inic();
	stm32fxxx_tim11.dier = stm32fxxx_tim11_dier_inic();
	stm32fxxx_tim11.sr = stm32fxxx_tim11_sr_inic();
	stm32fxxx_tim11.egr = stm32fxxx_tim11_egr_inic();
	stm32fxxx_tim11.ccmr1 = stm32fxxx_tim11_ccmr1_inic();
	stm32fxxx_tim11.ccer = stm32fxxx_tim11_ccer_inic();
	stm32fxxx_tim11.cnt = STM32FXXXTim11_cnt;
	stm32fxxx_tim11.get_cnt = STM32FXXXTim11_get_cnt;
	stm32fxxx_tim11.psc = STM32FXXXTim11_psc;
	stm32fxxx_tim11.arr = STM32FXXXTim11_arr;
	stm32fxxx_tim11.ccr1 = STM32FXXXTim11_ccr1;
	stm32fxxx_tim11.or = STM32FXXXTim11_or;
	return stm32fxxx_tim11;
}

STM32FXXXTIM11obj* tim11(void){ return (STM32FXXXTIM11obj*) &stm32fxxx_tim11; }

/*** TIM12 AUX Procedure & Function Definition***/
STM32FXXXTIM12_CR1* stm32fxxx_tim12_cr1_inic(void)
{

	// CR1
	stm32fxxx_tim12_cr1.get_ckd = STM32FXXXTim12_get_ckd;
	stm32fxxx_tim12_cr1.apre = STM32FXXXTim12_set_apre;
	stm32fxxx_tim12_cr1.opm = STM32FXXXTim12_set_opm;
	stm32fxxx_tim12_cr1.urs = STM32FXXXTim12_set_urs;
	stm32fxxx_tim12_cr1.udis = STM32FXXXTim12_set_udis;
	stm32fxxx_tim12_cr1.cen = STM32FXXXTim12_cen;
	return &stm32fxxx_tim12_cr1;
}
STM32FXXXTIM12_SMCR* stm32fxxx_tim12_smcr_inic(void)
{

	// SMCR
	stm32fxxx_tim12_smcr.msm = STM32FXXXTim12_msm;
	stm32fxxx_tim12_smcr.ts = STM32FXXXTim12_ts;
	stm32fxxx_tim12_smcr.sms = STM32FXXXTim12_sms;
	return &stm32fxxx_tim12_smcr;
}
STM32FXXXTIM12_DIER* stm32fxxx_tim12_dier_inic(void)
{

	// DIER
	stm32fxxx_tim12_dier.tie = STM32FXXXTim12_tie;
	stm32fxxx_tim12_dier.cc2ie = STM32FXXXTim12_cc2ie;
	stm32fxxx_tim12_dier.cc1ie = STM32FXXXTim12_cc1ie;
	stm32fxxx_tim12_dier.uie = STM32FXXXTim12_uie;
	return &stm32fxxx_tim12_dier;
}
STM32FXXXTIM12_SR* stm32fxxx_tim12_sr_inic(void)
{

	// SR
	stm32fxxx_tim12_sr.cc2of = STM32FXXXTim12_cc2of;
	stm32fxxx_tim12_sr.clear_cc2of = STM32FXXXTim12_clear_cc2of;
	stm32fxxx_tim12_sr.cc1of = STM32FXXXTim12_cc1of;
	stm32fxxx_tim12_sr.clear_cc1of = STM32FXXXTim12_clear_cc1of;
	stm32fxxx_tim12_sr.tif = STM32FXXXTim12_tif;
	stm32fxxx_tim12_sr.clear_tif = STM32FXXXTim12_clear_tif;
	stm32fxxx_tim12_sr.cc2if = STM32FXXXTim12_cc2if;
	stm32fxxx_tim12_sr.clear_cc2if = STM32FXXXTim12_clear_cc2if;
	stm32fxxx_tim12_sr.cc1if = STM32FXXXTim12_cc1if;
	stm32fxxx_tim12_sr.clear_cc1if = STM32FXXXTim12_clear_cc1if;
	stm32fxxx_tim12_sr.uif = STM32FXXXTim12_uif;
	stm32fxxx_tim12_sr.clear_uif = STM32FXXXTim12_clear_uif;
	return &stm32fxxx_tim12_sr;
}
STM32FXXXTIM12_EGR* stm32fxxx_tim12_egr_inic(void)
{

	// EGR
	stm32fxxx_tim12_egr.tg = STM32FXXXTim12_tg;
	stm32fxxx_tim12_egr.cc2g = STM32FXXXTim12_cc2g;
	stm32fxxx_tim12_egr.cc1g = STM32FXXXTim12_cc1g;
	stm32fxxx_tim12_egr.ug = STM32FXXXTim12_ug;
	return &stm32fxxx_tim12_egr;
}
STM32FXXXTIM12_CCMR1* stm32fxxx_tim12_ccmr1_inic(void)
{

	// CCMR1
	stm32fxxx_tim12_ccmr1.oc2m = STM32FXXXTim12_oc2m;
	stm32fxxx_tim12_ccmr1.ic2f = STM32FXXXTim12_ic2f;
	stm32fxxx_tim12_ccmr1.oc2pe = STM32FXXXTim12_oc2pe;
	stm32fxxx_tim12_ccmr1.oc2fe = STM32FXXXTim12_oc2fe;
	stm32fxxx_tim12_ccmr1.ic2psc = STM32FXXXTim12_ic2psc;
	stm32fxxx_tim12_ccmr1.cc2s = STM32FXXXTim12_cc2s;
	stm32fxxx_tim12_ccmr1.oc1m = STM32FXXXTim12_oc1m;
	stm32fxxx_tim12_ccmr1.ic1f = STM32FXXXTim12_ic1f;
	stm32fxxx_tim12_ccmr1.oc1pe = STM32FXXXTim12_oc1pe;
	stm32fxxx_tim12_ccmr1.oc1fe = STM32FXXXTim12_oc1fe;
	stm32fxxx_tim12_ccmr1.ic1psc = STM32FXXXTim12_ic1psc;
	stm32fxxx_tim12_ccmr1.cc1s = STM32FXXXTim12_cc1s;
	return &stm32fxxx_tim12_ccmr1;
}
STM32FXXXTIM12_CCER* stm32fxxx_tim12_ccer_inic(void)
{

	// CCER
	stm32fxxx_tim12_ccer.cc2np = STM32FXXXTim12_cc2np;
	stm32fxxx_tim12_ccer.cc2p = STM32FXXXTim12_cc2p;
	stm32fxxx_tim12_ccer.cc2e = STM32FXXXTim12_cc2e;
	stm32fxxx_tim12_ccer.cc1np = STM32FXXXTim12_cc1np;
	stm32fxxx_tim12_ccer.cc1p = STM32FXXXTim12_cc1p;
	stm32fxxx_tim12_ccer.cc1e = STM32FXXXTim12_cc1e;
	return &stm32fxxx_tim12_ccer;
}
/*** TIM12 Procedure & Function Definition***/
STM32FXXXTIM12obj tim12_enable(void)
{


	// CLOCK
	stm32fxxx_tim12.clock = STM32FXXXTim12Clock;
	// NVIC
	stm32fxxx_tim12.nvic = STM32FXXXTim12Nvic;
	/*** TIM12 Bit Mapping Link ***/
	stm32fxxx_tim12.cr1 = stm32fxxx_tim12_cr1_inic();
	stm32fxxx_tim12.smcr = stm32fxxx_tim12_smcr_inic();
	stm32fxxx_tim12.dier = stm32fxxx_tim12_dier_inic();
	stm32fxxx_tim12.sr = stm32fxxx_tim12_sr_inic();
	stm32fxxx_tim12.egr = stm32fxxx_tim12_egr_inic();
	stm32fxxx_tim12.ccmr1 = stm32fxxx_tim12_ccmr1_inic();
	stm32fxxx_tim12.ccer = stm32fxxx_tim12_ccer_inic();
	stm32fxxx_tim12.cnt = STM32FXXXTim12_cnt;
	stm32fxxx_tim12.get_cnt = STM32FXXXTim12_get_cnt;
	stm32fxxx_tim12.arr = STM32FXXXTim12_arr;
	stm32fxxx_tim12.ccr1 = STM32FXXXTim12_ccr1;
	stm32fxxx_tim12.ccr2 = STM32FXXXTim12_ccr2;
	stm32fxxx_tim12.psc = STM32FXXXTim12_psc;
	return stm32fxxx_tim12;
}

STM32FXXXTIM12obj* tim12(void){ return (STM32FXXXTIM12obj*) &stm32fxxx_tim12; }

/*** TIM13 AUX Procedure & Function Definition***/
STM32FXXXTIM13_CR1* stm32fxxx_tim13_cr1_inic(void)
{

	// CR1
	stm32fxxx_tim13_cr1.get_ckd = STM32FXXXTim13_get_ckd;
	stm32fxxx_tim13_cr1.apre = STM32FXXXTim13_set_apre;
	stm32fxxx_tim13_cr1.urs = STM32FXXXTim13_set_urs;
	stm32fxxx_tim13_cr1.udis = STM32FXXXTim13_set_udis;
	stm32fxxx_tim13_cr1.cen = STM32FXXXTim13_cen;
	return &stm32fxxx_tim13_cr1;
}
STM32FXXXTIM13_DIER* stm32fxxx_tim13_dier_inic(void)
{

	// DIER
	stm32fxxx_tim13_dier.cc1ie = STM32FXXXTim13_cc1ie;
	stm32fxxx_tim13_dier.uie = STM32FXXXTim13_uie;
	return &stm32fxxx_tim13_dier;
}
STM32FXXXTIM13_SR* stm32fxxx_tim13_sr_inic(void)
{

	// SR
	stm32fxxx_tim13_sr.cc1of = STM32FXXXTim13_cc1of;
	stm32fxxx_tim13_sr.clear_cc1of = STM32FXXXTim13_clear_cc1of;
	stm32fxxx_tim13_sr.cc1if = STM32FXXXTim13_cc1if;
	stm32fxxx_tim13_sr.clear_cc1if = STM32FXXXTim13_clear_cc1if;
	stm32fxxx_tim13_sr.uif = STM32FXXXTim13_uif;
	stm32fxxx_tim13_sr.clear_uif = STM32FXXXTim13_clear_uif;
	return &stm32fxxx_tim13_sr;
}
STM32FXXXTIM13_EGR* stm32fxxx_tim13_egr_inic(void)
{

	// EGR
	stm32fxxx_tim13_egr.cc1g = STM32FXXXTim13_cc1g;
	stm32fxxx_tim13_egr.ug = STM32FXXXTim13_ug;
	return &stm32fxxx_tim13_egr;
}
STM32FXXXTIM13_CCMR1* stm32fxxx_tim13_ccmr1_inic(void)
{

	// CCMR1
	stm32fxxx_tim13_ccmr1.oc1m = STM32FXXXTim13_oc1m;
	stm32fxxx_tim13_ccmr1.ic1f = STM32FXXXTim13_ic1f;
	stm32fxxx_tim13_ccmr1.oc1pe = STM32FXXXTim13_oc1pe;
	stm32fxxx_tim13_ccmr1.oc1fe = STM32FXXXTim13_oc1fe;
	stm32fxxx_tim13_ccmr1.ic1psc = STM32FXXXTim13_ic1psc;
	stm32fxxx_tim13_ccmr1.cc1s = STM32FXXXTim13_cc1s;
	return &stm32fxxx_tim13_ccmr1;
}
STM32FXXXTIM13_CCER* stm32fxxx_tim13_ccer_inic(void)
{

	// CCER
	stm32fxxx_tim13_ccer.cc1np = STM32FXXXTim13_cc1np;
	stm32fxxx_tim13_ccer.cc1p = STM32FXXXTim13_cc1p;
	stm32fxxx_tim13_ccer.cc1e = STM32FXXXTim13_cc1e;
	return &stm32fxxx_tim13_ccer;
}
/*** TIM13 Procedure & Function Definition***/
STM32FXXXTIM13obj tim13_enable(void)
{


	// CLOCK
	stm32fxxx_tim13.clock = STM32FXXXTim13Clock;
	// NVIC
	stm32fxxx_tim13.nvic = STM32FXXXTim13Nvic;
	/*** TIM13 Bit Mapping Link ***/
	stm32fxxx_tim13.cr1 = stm32fxxx_tim13_cr1_inic();
	stm32fxxx_tim13.dier = stm32fxxx_tim13_dier_inic();
	stm32fxxx_tim13.sr = stm32fxxx_tim13_sr_inic();
	stm32fxxx_tim13.egr = stm32fxxx_tim13_egr_inic();
	stm32fxxx_tim13.ccmr1 = stm32fxxx_tim13_ccmr1_inic();
	stm32fxxx_tim13.ccer = stm32fxxx_tim13_ccer_inic();
	stm32fxxx_tim13.cnt = STM32FXXXTim13_cnt;
	stm32fxxx_tim13.get_cnt = STM32FXXXTim13_get_cnt;
	stm32fxxx_tim13.psc = STM32FXXXTim13_psc;
	stm32fxxx_tim13.arr = STM32FXXXTim13_arr;
	stm32fxxx_tim13.ccr1 = STM32FXXXTim13_ccr1;
	stm32fxxx_tim13.or = STM32FXXXTim13_or;
	return stm32fxxx_tim13;
}

STM32FXXXTIM13obj* tim13(void){ return (STM32FXXXTIM13obj*) &stm32fxxx_tim13; }

/*** TIM14 AUX Procedure & Function Definition ***/
STM32FXXXTIM14_CR1* stm32fxxx_tim14_cr1_inic(void)
{

	// CR1
	stm32fxxx_tim14_cr1.get_ckd = STM32FXXXTim14_get_ckd;
	stm32fxxx_tim14_cr1.apre = STM32FXXXTim14_set_apre;
	stm32fxxx_tim14_cr1.urs = STM32FXXXTim14_set_urs;
	stm32fxxx_tim14_cr1.udis = STM32FXXXTim14_set_udis;
	stm32fxxx_tim14_cr1.cen = STM32FXXXTim14_cen;
	return &stm32fxxx_tim14_cr1;
}
STM32FXXXTIM14_DIER* stm32fxxx_tim14_dier_inic(void)
{

	// DIER
	stm32fxxx_tim14_dier.cc1ie = STM32FXXXTim14_cc1ie;
	stm32fxxx_tim14_dier.uie = STM32FXXXTim14_uie;
	return &stm32fxxx_tim14_dier;
}
STM32FXXXTIM14_SR* stm32fxxx_tim14_sr_inic(void)
{

	// SR
	stm32fxxx_tim14_sr.cc1of = STM32FXXXTim14_cc1of;
	stm32fxxx_tim14_sr.clear_cc1of = STM32FXXXTim14_clear_cc1of;
	stm32fxxx_tim14_sr.cc1if = STM32FXXXTim14_cc1if;
	stm32fxxx_tim14_sr.clear_cc1if = STM32FXXXTim14_clear_cc1if;
	stm32fxxx_tim14_sr.uif = STM32FXXXTim14_uif;
	stm32fxxx_tim14_sr.clear_uif = STM32FXXXTim14_clear_uif;
	return &stm32fxxx_tim14_sr;
}
STM32FXXXTIM14_EGR* stm32fxxx_tim14_egr_inic(void)
{

	// EGR
	stm32fxxx_tim14_egr.cc1g = STM32FXXXTim14_cc1g;
	stm32fxxx_tim14_egr.ug = STM32FXXXTim14_ug;
	return &stm32fxxx_tim14_egr;
}
STM32FXXXTIM14_CCMR1* stm32fxxx_tim14_ccmr1_inic(void)
{

	// CCMR1
	stm32fxxx_tim14_ccmr1.oc1m = STM32FXXXTim14_oc1m;
	stm32fxxx_tim14_ccmr1.ic1f = STM32FXXXTim14_ic1f;
	stm32fxxx_tim14_ccmr1.oc1pe = STM32FXXXTim14_oc1pe;
	stm32fxxx_tim14_ccmr1.oc1fe = STM32FXXXTim14_oc1fe;
	stm32fxxx_tim14_ccmr1.ic1psc = STM32FXXXTim14_ic1psc;
	stm32fxxx_tim14_ccmr1.cc1s = STM32FXXXTim14_cc1s;
	return &stm32fxxx_tim14_ccmr1;
}
STM32FXXXTIM14_CCER* stm32fxxx_tim14_ccer_inic(void)
{

	// CCER
	stm32fxxx_tim14_ccer.cc1np = STM32FXXXTim14_cc1np;
	stm32fxxx_tim14_ccer.cc1p = STM32FXXXTim14_cc1p;
	stm32fxxx_tim14_ccer.cc1e = STM32FXXXTim14_cc1e;
	return &stm32fxxx_tim14_ccer;
}
/*** TIM14 Procedure & Function Definition ***/
STM32FXXXTIM14obj tim14_enable(void)
{


	// CLOCK
	stm32fxxx_tim14.clock = STM32FXXXTim14Clock;
	// NVIC
	stm32fxxx_tim14.nvic = STM32FXXXTim14Nvic;
	/*** TIM14 Bit Mapping Link ***/
	stm32fxxx_tim14.cr1 = stm32fxxx_tim14_cr1_inic();
	stm32fxxx_tim14.dier = stm32fxxx_tim14_dier_inic();
	stm32fxxx_tim14.sr = stm32fxxx_tim14_sr_inic();
	stm32fxxx_tim14.egr = stm32fxxx_tim14_egr_inic();
	stm32fxxx_tim14.ccmr1 = stm32fxxx_tim14_ccmr1_inic();
	stm32fxxx_tim14.ccer = stm32fxxx_tim14_ccer_inic();
	stm32fxxx_tim14.cnt = STM32FXXXTim14_cnt;
	stm32fxxx_tim14.get_cnt = STM32FXXXTim14_get_cnt;
	stm32fxxx_tim14.psc = STM32FXXXTim14_psc;
	stm32fxxx_tim14.arr = STM32FXXXTim14_arr;
	stm32fxxx_tim14.ccr1 = STM32FXXXTim14_ccr1;
	stm32fxxx_tim14.or = STM32FXXXTim14_or;
	return stm32fxxx_tim14;
}

STM32FXXXTIM14obj* tim14(void){ return (STM32FXXXTIM14obj*) &stm32fxxx_tim14; }

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

