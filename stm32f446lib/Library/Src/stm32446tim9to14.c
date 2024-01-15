/******************************************************************************
	STM32 446 TIM 9 to 14
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 22062023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32446tim9to14.h"

/*** File Variable ***/
static STM32446TIM9_CR1 stm32446_tim9_cr1;
static STM32446TIM9_SMCR stm32446_tim9_smcr;
static STM32446TIM9_DIER stm32446_tim9_dier;
static STM32446TIM9_SR stm32446_tim9_sr;
static STM32446TIM9_EGR stm32446_tim9_egr;
static STM32446TIM9_CCMR1 stm32446_tim9_ccmr1;
static STM32446TIM9_CCER stm32446_tim9_ccer;
static STM32446TIM9obj stm32446_tim9;
static STM32446TIM10_CR1 stm32446_tim10_cr1;
static STM32446TIM10_DIER stm32446_tim10_dier;
static STM32446TIM10_SR stm32446_tim10_sr;
static STM32446TIM10_EGR stm32446_tim10_egr;
static STM32446TIM10_CCMR1 stm32446_tim10_ccmr1;
static STM32446TIM10_CCER stm32446_tim10_ccer;
static STM32446TIM10obj stm32446_tim10;
static STM32446TIM11_CR1 stm32446_tim11_cr1;
static STM32446TIM11_DIER stm32446_tim11_dier;
static STM32446TIM11_SR stm32446_tim11_sr;
static STM32446TIM11_EGR stm32446_tim11_egr;
static STM32446TIM11_CCMR1 stm32446_tim11_ccmr1;
static STM32446TIM11_CCER stm32446_tim11_ccer;
static STM32446TIM11obj stm32446_tim11;
static STM32446TIM12_CR1 stm32446_tim12_cr1;
static STM32446TIM12_SMCR stm32446_tim12_smcr;
static STM32446TIM12_DIER stm32446_tim12_dier;
static STM32446TIM12_SR stm32446_tim12_sr;
static STM32446TIM12_EGR stm32446_tim12_egr;
static STM32446TIM12_CCMR1 stm32446_tim12_ccmr1;
static STM32446TIM12_CCER stm32446_tim12_ccer;
static STM32446TIM12obj stm32446_tim12;
static STM32446TIM13_CR1 stm32446_tim13_cr1;
static STM32446TIM13_DIER stm32446_tim13_dier;
static STM32446TIM13_SR stm32446_tim13_sr;
static STM32446TIM13_EGR stm32446_tim13_egr;
static STM32446TIM13_CCMR1 stm32446_tim13_ccmr1;
static STM32446TIM13_CCER stm32446_tim13_ccer;
static STM32446TIM13obj stm32446_tim13;
static STM32446TIM14_CR1 stm32446_tim14_cr1;
static STM32446TIM14_DIER stm32446_tim14_dier;
static STM32446TIM14_SR stm32446_tim14_sr;
static STM32446TIM14_EGR stm32446_tim14_egr;
static STM32446TIM14_CCMR1 stm32446_tim14_ccmr1;
static STM32446TIM14_CCER stm32446_tim14_ccer;
static STM32446TIM14obj stm32446_tim14;

/*** File Procedure & Function Header ***/
/*** Auxiliar 9 to 14 ***/
STM32446TIM9_CR1* stm32446_tim9_cr1_inic(void);
STM32446TIM9_SMCR* stm32446_tim9_smcr_inic(void);
STM32446TIM9_DIER* stm32446_tim9_dier_inic(void);
STM32446TIM9_SR* stm32446_tim9_sr_inic(void);
STM32446TIM9_EGR* stm32446_tim9_egr_inic(void);
STM32446TIM9_CCMR1* stm32446_tim9_ccmr1_inic(void);
STM32446TIM9_CCER* stm32446_tim9_ccer_inic(void);
STM32446TIM10_CR1* stm32446_tim10_cr1_inic(void);
STM32446TIM10_DIER* stm32446_tim10_dier_inic(void);
STM32446TIM10_SR* stm32446_tim10_sr_inic(void);
STM32446TIM10_EGR* stm32446_tim10_egr_inic(void);
STM32446TIM10_CCMR1* stm32446_tim10_ccmr1_inic(void);
STM32446TIM10_CCER* stm32446_tim10_ccer_inic(void);
STM32446TIM11_CR1* stm32446_tim11_cr1_inic(void);
STM32446TIM11_DIER* stm32446_tim11_dier_inic(void);
STM32446TIM11_SR* stm32446_tim11_sr_inic(void);
STM32446TIM11_EGR* stm32446_tim11_egr_inic(void);
STM32446TIM11_CCMR1* stm32446_tim11_ccmr1_inic(void);
STM32446TIM11_CCER* stm32446_tim11_ccer_inic(void);
STM32446TIM12_CR1* stm32446_tim12_cr1_inic(void);
STM32446TIM12_SMCR* stm32446_tim12_smcr_inic(void);
STM32446TIM12_DIER* stm32446_tim12_dier_inic(void);
STM32446TIM12_SR* stm32446_tim12_sr_inic(void);
STM32446TIM12_EGR* stm32446_tim12_egr_inic(void);
STM32446TIM12_CCMR1* stm32446_tim12_ccmr1_inic(void);
STM32446TIM12_CCER* stm32446_tim12_ccer_inic(void);
STM32446TIM13_CR1* stm32446_tim13_cr1_inic(void);
STM32446TIM13_DIER* stm32446_tim13_dier_inic(void);
STM32446TIM13_SR* stm32446_tim13_sr_inic(void);
STM32446TIM13_EGR* stm32446_tim13_egr_inic(void);
STM32446TIM13_CCMR1* stm32446_tim13_ccmr1_inic(void);
STM32446TIM13_CCER* stm32446_tim13_ccer_inic(void);
STM32446TIM14_CR1* stm32446_tim14_cr1_inic(void);
STM32446TIM14_DIER* stm32446_tim14_dier_inic(void);
STM32446TIM14_SR* stm32446_tim14_sr_inic(void);
STM32446TIM14_EGR* stm32446_tim14_egr_inic(void);
STM32446TIM14_CCMR1* stm32446_tim14_ccmr1_inic(void);
STM32446TIM14_CCER* stm32446_tim14_ccer_inic(void);
/*** TIMER 9 to 14 Procedure & Function Definition ***/
/************/
/*** TIM9 ***/
/************/
void STM32446Tim9Clock(uint8_t bool)
{
	if(bool){
		RCC->APB2ENR |= (1 << 16); // timer 9 clock enabled
	}else{
		RCC->APB2ENR &= ~(1 << 16); //timer 9 clock disabled
	}
}
void STM32446Tim9Nvic(uint8_t bool)
{ // 24
	if(bool){setbit(NVIC->ISER, 1, 24, 1);} else{setbit(NVIC->ICER, 1, 24, 1);}
}
/************************/
/*** TIM9 Bit Mapping ***/
/************************/
// CR1
void STM32446Tim9_ckd(uint8_t value)
{
	setreg(&TIM9->CR1, 2, 8, value);
}
uint8_t STM32446Tim9_get_ckd(void)
{
	return readreg(TIM9->CR1, 2, 8);
}
void STM32446Tim9_set_apre(uint8_t bool)
{
	setreg(&TIM9->CR1, 1, 7, bool);
}
void STM32446Tim9_set_opm(uint8_t bool)
{
	setreg(&TIM9->CR1, 1, 3, bool);
}
void STM32446Tim9_set_urs(uint8_t bool)
{
	setreg(&TIM9->CR1, 1, 2, bool);
}
void STM32446Tim9_set_udis(uint8_t bool)
{
	setreg(&TIM9->CR1, 1, 1, bool);
}
void STM32446Tim9_cen(uint8_t bool)
{
	setreg(&TIM9->CR1, 1, 0, bool);
}
// SMCR
void STM32446Tim9_msm(uint8_t bool)
{
	setreg(&TIM9->SMCR, 1, 7, bool);
}
void STM32446Tim9_ts(uint8_t value)
{
	setreg(&TIM9->SMCR, 3, 4, value);
}
void STM32446Tim9_sms(uint8_t value)
{
	setreg(&TIM9->SMCR, 3, 0, value);
}
// DIER
void STM32446Tim9_tie(uint8_t bool)
{
	setreg(&TIM9->DIER, 1, 6, bool);
}
void STM32446Tim9_cc2ie(uint8_t bool)
{
	setreg(&TIM9->DIER, 1, 2, bool);
}
void STM32446Tim9_cc1ie(uint8_t bool)
{
	setreg(&TIM9->DIER, 1, 1, bool);
}
void STM32446Tim9_uie(uint8_t bool)
{
	setreg(&TIM9->DIER, 1, 0, bool);
}
// SR
uint8_t STM32446Tim9_cc2of(void)
{
	return readreg(TIM9->SR, 1, 10);
}
void STM32446Tim9_clear_cc2of(void)
{
	setreg(&TIM9->SR, 1, 10, 0);
}
uint8_t STM32446Tim9_cc1of(void)
{
	return readreg(TIM9->SR, 1, 9);
}
void STM32446Tim9_clear_cc1of(void)
{
	setreg(&TIM9->SR, 1, 9, 0);
}
uint8_t STM32446Tim9_tif(void)
{
	return readreg(TIM9->SR, 1, 6);
}
void STM32446Tim9_clear_tif(void)
{
	setreg(&TIM9->SR, 1, 6, 0);
}
uint8_t STM32446Tim9_cc2if(void)
{
	return readreg(TIM9->SR, 1, 2);
}
void STM32446Tim9_clear_cc2if(void)
{
	setreg(&TIM9->SR, 1, 2, 0);
}
uint8_t STM32446Tim9_cc1if(void)
{
	return readreg(TIM9->SR, 1, 1);
}
void STM32446Tim9_clear_cc1if(void)
{
	setreg(&TIM9->SR, 1, 1, 0);
}
uint8_t STM32446Tim9_uif(void)
{
	return readreg(TIM9->SR, 1, 0);
}
void STM32446Tim9_clear_uif(void)
{
	setreg(&TIM9->SR, 1, 0, 0);
}
// EGR
void STM32446Tim9_tg(void)
{
	setreg(&TIM9->EGR, 1, 6, 1);
}
void STM32446Tim9_cc2g(void)
{
	setreg(&TIM9->EGR, 1, 2, 1);
}
void STM32446Tim9_cc1g(void)
{
	setreg(&TIM9->EGR, 1, 1, 1);
}
void STM32446Tim9_ug(void)
{
	setreg(&TIM9->EGR, 1, 0, 1);
}
// CCMR1
void STM32446Tim9_oc2m(uint8_t value)
{
	setreg(&TIM9->CCMR1, 3, 12, value);
}
void STM32446Tim9_ic2f(uint8_t value)
{
	setreg(&TIM9->CCMR1, 4, 12, value);
}
void STM32446Tim9_oc2pe(uint8_t bool)
{
	setreg(&TIM9->CCMR1, 1, 11, bool);
}
void STM32446Tim9_oc2fe(uint8_t bool)
{
	setreg(&TIM9->CCMR1, 1, 10, bool);
}
void STM32446Tim9_ic2psc(uint8_t value)
{
	setreg(&TIM9->CCMR1, 2, 10, value);
}
void STM32446Tim9_cc2s(uint8_t value)
{
	setreg(&TIM9->CCMR1, 2, 8, value);
}
void STM32446Tim9_oc1m(uint8_t value)
{
	setreg(&TIM9->CCMR1, 3, 4, value);
}
void STM32446Tim9_ic1f(uint8_t value)
{
	setreg(&TIM9->CCMR1, 4, 4, value);
}
void STM32446Tim9_oc1pe(uint8_t bool)
{
	setreg(&TIM9->CCMR1, 1, 3, bool);
}
void STM32446Tim9_oc1fe(uint8_t bool)
{
	setreg(&TIM9->CCMR1, 1, 2, bool);
}
void STM32446Tim9_ic1psc(uint8_t value)
{
	setreg(&TIM9->CCMR1, 2, 2, value);
}
void STM32446Tim9_cc1s(uint8_t value)
{
	setreg(&TIM9->CCMR1, 2, 0, value);
}
// CCER
void STM32446Tim9_cc2np(uint8_t bool)
{
	setreg(&TIM9->CCER, 1, 7, bool);
}
void STM32446Tim9_cc2p(uint8_t bool)
{
	setreg(&TIM9->CCER, 1, 5, bool);
}
void STM32446Tim9_cc2e(uint8_t bool)
{
	setreg(&TIM9->CCER, 1, 4, bool);
}
void STM32446Tim9_cc1np(uint8_t bool)
{
	setreg(&TIM9->CCER, 1, 3, bool);
}
void STM32446Tim9_cc1p(uint8_t bool)
{
	setreg(&TIM9->CCER, 1, 1, bool);
}
void STM32446Tim9_cc1e(uint8_t bool)
{
	setreg(&TIM9->CCER, 1, 0, bool);
}
// CNT
void STM32446Tim9_cnt(uint16_t value)
{
	TIM9->CNT = value;
}
uint16_t STM32446Tim9_get_cnt(void)
{
	return TIM9->CNT;
}
// ARR
void STM32446Tim9_arr(uint16_t value)
{
	TIM9->ARR = value;
}
// CCR1
void STM32446Tim9_ccr1(uint16_t value)
{
	TIM9->CCR1 = value;
}
// CCR2
void STM32446Tim9_ccr2(uint16_t value)
{
	TIM9->CCR2 = value;
}
// PSC
void STM32446Tim9_psc(uint16_t value)
{
	TIM9->PSC = value;
}
/*************/
/*** TIM10 ***/
/*************/
void STM32446Tim10Clock(uint8_t bool)
{
	if(bool){
		RCC->APB2ENR |= (1 << 17); // timer 10 clock enabled
	}else{
		RCC->APB2ENR &= ~(1 << 17); //timer 10 clock disabled
	}
}
void STM32446Tim10Nvic(uint8_t bool)
{ // 25
	if(bool){setbit(NVIC->ISER, 1, 25, 1);} else{setbit(NVIC->ICER, 1, 25, 1);}
}
/*************************/
/*** TIM10 Bit Mapping ***/
/*************************/
// CR1
void STM32446Tim10_ckd(uint8_t value)
{
	setreg(&TIM9->CR1, 2, 8, value);
}
uint8_t STM32446Tim10_get_ckd(void)
{
	return readreg(TIM10->CR1, 2, 8);
}
void STM32446Tim10_set_apre(uint8_t bool)
{
	setreg(&TIM10->CR1, 1, 7, bool);
}
void STM32446Tim10_set_opm(uint8_t bool)
{
	setreg(&TIM10->CR1, 1, 3, bool);
}
void STM32446Tim10_set_urs(uint8_t bool)
{
	setreg(&TIM10->CR1, 1, 2, bool);
}
void STM32446Tim10_set_udis(uint8_t bool)
{
	setreg(&TIM10->CR1, 1, 1, bool);
}
void STM32446Tim10_cen(uint8_t bool)
{
	setreg(&TIM10->CR1, 1, 0, bool);
}
// DIER
void STM32446Tim10_tie(uint8_t bool)
{
	setreg(&TIM10->DIER, 1, 6, bool);
}
void STM32446Tim10_cc2ie(uint8_t bool)
{
	setreg(&TIM10->DIER, 1, 2, bool);
}
void STM32446Tim10_cc1ie(uint8_t bool)
{
	setreg(&TIM10->DIER, 1, 1, bool);
}
void STM32446Tim10_uie(uint8_t bool)
{
	setreg(&TIM10->DIER, 1, 0, bool);
}
// SR
uint8_t STM32446Tim10_cc2of(void)
{
	return readreg(TIM10->SR, 1, 10);
}
void STM32446Tim10_clear_cc2of(void)
{
	setreg(&TIM10->SR, 1, 10, 0);
}
uint8_t STM32446Tim10_cc1of(void)
{
	return readreg(TIM10->SR, 1, 9);
}
void STM32446Tim10_clear_cc1of(void)
{
	setreg(&TIM10->SR, 1, 9, 0);
}
uint8_t STM32446Tim10_tif(void)
{
	return readreg(TIM10->SR, 1, 6);
}
void STM32446Tim10_clear_tif(void)
{
	setreg(&TIM10->SR, 1, 6, 0);
}
uint8_t STM32446Tim10_cc2if(void)
{
	return readreg(TIM10->SR, 1, 2);
}
void STM32446Tim10_clear_cc2if(void)
{
	setreg(&TIM10->SR, 1, 2, 0);
}
uint8_t STM32446Tim10_cc1if(void)
{
	return readreg(TIM10->SR, 1, 1);
}
void STM32446Tim10_clear_cc1if(void)
{
	setreg(&TIM10->SR, 1, 1, 0);
}
uint8_t STM32446Tim10_uif(void)
{
	return readreg(TIM10->SR, 1, 0);
}
void STM32446Tim10_clear_uif(void)
{
	setreg(&TIM10->SR, 1, 0, 0);
}
// EGR
void STM32446Tim10_tg(void)
{
	setreg(&TIM10->EGR, 1, 6, 1);
}
void STM32446Tim10_cc2g(void)
{
	setreg(&TIM10->EGR, 1, 2, 1);
}
void STM32446Tim10_cc1g(void)
{
	setreg(&TIM10->EGR, 1, 1, 1);
}
void STM32446Tim10_ug(void)
{
	setreg(&TIM10->EGR, 1, 0, 1);
}
// CCMR1
void STM32446Tim10_oc2m(uint8_t value)
{
	setreg(&TIM10->CCMR1, 3, 12, value);
}
void STM32446Tim10_ic2f(uint8_t value)
{
	setreg(&TIM10->CCMR1, 4, 12, value);
}
void STM32446Tim10_oc2pe(uint8_t bool)
{
	setreg(&TIM10->CCMR1, 1, 11, bool);
}
void STM32446Tim10_oc2fe(uint8_t bool)
{
	setreg(&TIM10->CCMR1, 1, 10, bool);
}
void STM32446Tim10_ic2psc(uint8_t value)
{
	setreg(&TIM10->CCMR1, 2, 10, value);
}
void STM32446Tim10_cc2s(uint8_t value)
{
	setreg(&TIM10->CCMR1, 2, 8, value);
}
void STM32446Tim10_oc1m(uint8_t value)
{
	setreg(&TIM10->CCMR1, 3, 4, value);
}
void STM32446Tim10_ic1f(uint8_t value)
{
	setreg(&TIM10->CCMR1, 4, 4, value);
}
void STM32446Tim10_oc1pe(uint8_t bool)
{
	setreg(&TIM10->CCMR1, 1, 3, bool);
}
void STM32446Tim10_oc1fe(uint8_t bool)
{
	setreg(&TIM10->CCMR1, 1, 2, bool);
}
void STM32446Tim10_ic1psc(uint8_t value)
{
	setreg(&TIM10->CCMR1, 2, 2, value);
}
void STM32446Tim10_cc1s(uint8_t value)
{
	setreg(&TIM10->CCMR1, 2, 0, value);
}
// CCER
void STM32446Tim10_cc2np(uint8_t bool)
{
	setreg(&TIM10->CCER, 1, 7, bool);
}
void STM32446Tim10_cc2p(uint8_t bool)
{
	setreg(&TIM10->CCER, 1, 5, bool);
}
void STM32446Tim10_cc2e(uint8_t bool)
{
	setreg(&TIM10->CCER, 1, 4, bool);
}
void STM32446Tim10_cc1np(uint8_t bool)
{
	setreg(&TIM10->CCER, 1, 3, bool);
}
void STM32446Tim10_cc1p(uint8_t bool)
{
	setreg(&TIM10->CCER, 1, 1, bool);
}
void STM32446Tim10_cc1e(uint8_t bool)
{
	setreg(&TIM10->CCER, 1, 0, bool);
}
// CNT
void STM32446Tim10_cnt(uint16_t value)
{
	TIM10->CNT = value;
}
uint16_t STM32446Tim10_get_cnt(void)
{
	return TIM10->CNT;
}
// PSC
void STM32446Tim10_psc(uint16_t value)
{
	TIM10->PSC = value;
}
// ARR
void STM32446Tim10_arr(uint16_t value)
{
	TIM10->ARR = value;
}
// CCR1
void STM32446Tim10_ccr1(uint16_t value)
{
	TIM10->CCR1 = value;
}
// OR
void STM32446Tim10_or(uint8_t value)
{
	setreg(&TIM10->OR, 2, 0, value);
}
/*************/
/*** TIM11 ***/
/*************/
void STM32446Tim11Clock(uint8_t bool)
{
	if(bool){
		RCC->APB2ENR |= (1 << 18); // timer 11 clock enabled
	}else{
		RCC->APB2ENR &= ~(1 << 18); //timer 11 clock disabled
	}
}
void STM32446Tim11Nvic(uint8_t bool)
{ // 26
	if(bool){setbit(NVIC->ISER, 1, 26, 1);} else{setbit(NVIC->ICER, 1, 26, 1);}
}
/************************/
/*** TIM11 Bit Mapping ***/
/************************/
// CR1
void STM32446Tim11_ckd(uint8_t value)
{
	setreg(&TIM9->CR1, 2, 8, value);
}
uint8_t STM32446Tim11_get_ckd(void)
{
	return readreg(TIM11->CR1, 2, 8);
}
void STM32446Tim11_set_apre(uint8_t bool)
{
	setreg(&TIM11->CR1, 1, 7, bool);
}
void STM32446Tim11_set_opm(uint8_t bool)
{
	setreg(&TIM11->CR1, 1, 3, bool);
}
void STM32446Tim11_set_urs(uint8_t bool)
{
	setreg(&TIM11->CR1, 1, 2, bool);
}
void STM32446Tim11_set_udis(uint8_t bool)
{
	setreg(&TIM11->CR1, 1, 1, bool);
}
void STM32446Tim11_cen(uint8_t bool)
{
	setreg(&TIM11->CR1, 1, 0, bool);
}
// DIER
void STM32446Tim11_tie(uint8_t bool)
{
	setreg(&TIM11->DIER, 1, 6, bool);
}
void STM32446Tim11_cc2ie(uint8_t bool)
{
	setreg(&TIM11->DIER, 1, 2, bool);
}
void STM32446Tim11_cc1ie(uint8_t bool)
{
	setreg(&TIM11->DIER, 1, 1, bool);
}
void STM32446Tim11_uie(uint8_t bool)
{
	setreg(&TIM11->DIER, 1, 0, bool);
}
// SR
uint8_t STM32446Tim11_cc2of(void)
{
	return readreg(TIM11->SR, 1, 10);
}
void STM32446Tim11_clear_cc2of(void)
{
	setreg(&TIM11->SR, 1, 10, 0);
}
uint8_t STM32446Tim11_cc1of(void)
{
	return readreg(TIM11->SR, 1, 9);
}
void STM32446Tim11_clear_cc1of(void)
{
	setreg(&TIM11->SR, 1, 9, 0);
}
uint8_t STM32446Tim11_tif(void)
{
	return readreg(TIM11->SR, 1, 6);
}
void STM32446Tim11_clear_tif(void)
{
	setreg(&TIM11->SR, 1, 6, 0);
}
uint8_t STM32446Tim11_cc2if(void)
{
	return readreg(TIM11->SR, 1, 2);
}
void STM32446Tim11_clear_cc2if(void)
{
	setreg(&TIM11->SR, 1, 2, 0);
}
uint8_t STM32446Tim11_cc1if(void)
{
	return readreg(TIM11->SR, 1, 1);
}
void STM32446Tim11_clear_cc1if(void)
{
	setreg(&TIM11->SR, 1, 1, 0);
}
uint8_t STM32446Tim11_uif(void)
{
	return readreg(TIM11->SR, 1, 0);
}
void STM32446Tim11_clear_uif(void)
{
	setreg(&TIM11->SR, 1, 0, 0);
}
// EGR
void STM32446Tim11_tg(void)
{
	setreg(&TIM11->EGR, 1, 6, 1);
}
void STM32446Tim11_cc2g(void)
{
	setreg(&TIM11->EGR, 1, 2, 1);
}
void STM32446Tim11_cc1g(void)
{
	setreg(&TIM11->EGR, 1, 1, 1);
}
void STM32446Tim11_ug(void)
{
	setreg(&TIM11->EGR, 1, 0, 1);
}
// CCMR1
void STM32446Tim11_oc2m(uint8_t value)
{
	setreg(&TIM11->CCMR1, 3, 12, value);
}
void STM32446Tim11_ic2f(uint8_t value)
{
	setreg(&TIM11->CCMR1, 4, 12, value);
}
void STM32446Tim11_oc2pe(uint8_t bool)
{
	setreg(&TIM11->CCMR1, 1, 11, bool);
}
void STM32446Tim11_oc2fe(uint8_t bool)
{
	setreg(&TIM11->CCMR1, 1, 10, bool);
}
void STM32446Tim11_ic2psc(uint8_t value)
{
	setreg(&TIM11->CCMR1, 2, 10, value);
}
void STM32446Tim11_cc2s(uint8_t value)
{
	setreg(&TIM11->CCMR1, 2, 8, value);
}
void STM32446Tim11_oc1m(uint8_t value)
{
	setreg(&TIM11->CCMR1, 3, 4, value);
}
void STM32446Tim11_ic1f(uint8_t value)
{
	setreg(&TIM11->CCMR1, 4, 4, value);
}
void STM32446Tim11_oc1pe(uint8_t bool)
{
	setreg(&TIM11->CCMR1, 1, 3, bool);
}
void STM32446Tim11_oc1fe(uint8_t bool)
{
	setreg(&TIM11->CCMR1, 1, 2, bool);
}
void STM32446Tim11_ic1psc(uint8_t value)
{
	setreg(&TIM11->CCMR1, 2, 2, value);
}
void STM32446Tim11_cc1s(uint8_t value)
{
	setreg(&TIM11->CCMR1, 2, 0, value);
}
// CCER
void STM32446Tim11_cc2np(uint8_t bool)
{
	setreg(&TIM11->CCER, 1, 7, bool);
}
void STM32446Tim11_cc2p(uint8_t bool)
{
	setreg(&TIM11->CCER, 1, 5, bool);
}
void STM32446Tim11_cc2e(uint8_t bool)
{
	setreg(&TIM11->CCER, 1, 4, bool);
}
void STM32446Tim11_cc1np(uint8_t bool)
{
	setreg(&TIM11->CCER, 1, 3, bool);
}
void STM32446Tim11_cc1p(uint8_t bool)
{
	setreg(&TIM11->CCER, 1, 1, bool);
}
void STM32446Tim11_cc1e(uint8_t bool)
{
	setreg(&TIM11->CCER, 1, 0, bool);
}
// CNT
void STM32446Tim11_cnt(uint16_t value)
{
	TIM11->CNT = value;
}
uint16_t STM32446Tim11_get_cnt(void)
{
	return TIM11->CNT;
}
// PSC
void STM32446Tim11_psc(uint16_t value)
{
	TIM11->PSC = value;
}
// ARR
void STM32446Tim11_arr(uint16_t value)
{
	TIM11->ARR = value;
}
// CCR1
void STM32446Tim11_ccr1(uint16_t value)
{
	TIM11->CCR1 = value;
}
// OR
void STM32446Tim11_or(uint8_t value)
{
	setreg(&TIM11->OR, 2, 0, value);
}
/*************/
/*** TIM12 ***/
/*************/
void STM32446Tim12Clock(uint8_t bool)
{
	if(bool){
		RCC->APB1ENR |= (1 << 6); // timer 12 clock enabled
	}else{
		RCC->APB1ENR &= ~(1 << 6); //timer 12 clock disabled
	}
}
void STM32446Tim12Nvic(uint8_t bool)
{ // 43
	if(bool){setbit(NVIC->ISER, 1, 43, 1);}else{setbit(NVIC->ICER, 1, 43, 1);}
}
/************************/
/*** TIM12 Bit Mapping ***/
/************************/
// CR1
void STM32446Tim12_ckd(uint8_t value)
{
	setreg(&TIM9->CR1, 2, 8, value);
}
uint8_t STM32446Tim12_get_ckd(void)
{
	return readreg(TIM12->CR1, 2, 8);
}
void STM32446Tim12_set_apre(uint8_t bool)
{
	setreg(&TIM12->CR1, 1, 7, bool);
}
void STM32446Tim12_set_opm(uint8_t bool)
{
	setreg(&TIM12->CR1, 1, 3, bool);
}
void STM32446Tim12_set_urs(uint8_t bool)
{
	setreg(&TIM12->CR1, 1, 2, bool);
}
void STM32446Tim12_set_udis(uint8_t bool)
{
	setreg(&TIM12->CR1, 1, 1, bool);
}
void STM32446Tim12_cen(uint8_t bool)
{
	setreg(&TIM12->CR1, 1, 0, bool);
}
// SMCR
void STM32446Tim12_msm(uint8_t bool)
{
	setreg(&TIM12->SMCR, 1, 7, bool);
}
void STM32446Tim12_ts(uint8_t value)
{
	setreg(&TIM12->SMCR, 3, 4, value);
}
void STM32446Tim12_sms(uint8_t value)
{
	setreg(&TIM12->SMCR, 3, 0, value);
}
// DIER
void STM32446Tim12_tie(uint8_t bool)
{
	setreg(&TIM12->DIER, 1, 6, bool);
}
void STM32446Tim12_cc2ie(uint8_t bool)
{
	setreg(&TIM12->DIER, 1, 2, bool);
}
void STM32446Tim12_cc1ie(uint8_t bool)
{
	setreg(&TIM12->DIER, 1, 1, bool);
}
void STM32446Tim12_uie(uint8_t bool)
{
	setreg(&TIM12->DIER, 1, 0, bool);
}
// SR
uint8_t STM32446Tim12_cc2of(void)
{
	return readreg(TIM12->SR, 1, 10);
}
void STM32446Tim12_clear_cc2of(void)
{
	setreg(&TIM12->SR, 1, 10, 0);
}
uint8_t STM32446Tim12_cc1of(void)
{
	return readreg(TIM12->SR, 1, 9);
}
void STM32446Tim12_clear_cc1of(void)
{
	setreg(&TIM12->SR, 1, 9, 0);
}
uint8_t STM32446Tim12_tif(void)
{
	return readreg(TIM12->SR, 1, 6);
}
void STM32446Tim12_clear_tif(void)
{
	setreg(&TIM12->SR, 1, 6, 0);
}
uint8_t STM32446Tim12_cc2if(void)
{
	return readreg(TIM12->SR, 1, 2);
}
void STM32446Tim12_clear_cc2if(void)
{
	setreg(&TIM12->SR, 1, 2, 0);
}
uint8_t STM32446Tim12_cc1if(void)
{
	return readreg(TIM12->SR, 1, 1);
}
void STM32446Tim12_clear_cc1if(void)
{
	setreg(&TIM12->SR, 1, 1, 0);
}
uint8_t STM32446Tim12_uif(void)
{
	return readreg(TIM12->SR, 1, 0);
}
void STM32446Tim12_clear_uif(void)
{
	setreg(&TIM12->SR, 1, 0, 0);
}
// EGR
void STM32446Tim12_tg(void)
{
	setreg(&TIM12->EGR, 1, 6, 1);
}
void STM32446Tim12_cc2g(void)
{
	setreg(&TIM12->EGR, 1, 2, 1);
}
void STM32446Tim12_cc1g(void)
{
	setreg(&TIM12->EGR, 1, 1, 1);
}
void STM32446Tim12_ug(void)
{
	setreg(&TIM12->EGR, 1, 0, 1);
}
// CCMR1
void STM32446Tim12_oc2m(uint8_t value)
{
	setreg(&TIM12->CCMR1, 3, 12, value);
}
void STM32446Tim12_ic2f(uint8_t value)
{
	setreg(&TIM12->CCMR1, 4, 12, value);
}
void STM32446Tim12_oc2pe(uint8_t bool)
{
	setreg(&TIM12->CCMR1, 1, 11, bool);
}
void STM32446Tim12_oc2fe(uint8_t bool)
{
	setreg(&TIM12->CCMR1, 1, 10, bool);
}
void STM32446Tim12_ic2psc(uint8_t value)
{
	setreg(&TIM12->CCMR1, 2, 10, value);
}
void STM32446Tim12_cc2s(uint8_t value)
{
	setreg(&TIM12->CCMR1, 2, 8, value);
}
void STM32446Tim12_oc1m(uint8_t value)
{
	setreg(&TIM12->CCMR1, 3, 4, value);
}
void STM32446Tim12_ic1f(uint8_t value)
{
	setreg(&TIM12->CCMR1, 4, 4, value);
}
void STM32446Tim12_oc1pe(uint8_t bool)
{
	setreg(&TIM12->CCMR1, 1, 3, bool);
}
void STM32446Tim12_oc1fe(uint8_t bool)
{
	setreg(&TIM12->CCMR1, 1, 2, bool);
}
void STM32446Tim12_ic1psc(uint8_t value)
{
	setreg(&TIM12->CCMR1, 2, 2, value);
}
void STM32446Tim12_cc1s(uint8_t value)
{
	setreg(&TIM12->CCMR1, 2, 0, value);
}
// CCER
void STM32446Tim12_cc2np(uint8_t bool)
{
	setreg(&TIM12->CCER, 1, 7, bool);
}
void STM32446Tim12_cc2p(uint8_t bool)
{
	setreg(&TIM12->CCER, 1, 5, bool);
}
void STM32446Tim12_cc2e(uint8_t bool)
{
	setreg(&TIM12->CCER, 1, 4, bool);
}
void STM32446Tim12_cc1np(uint8_t bool)
{
	setreg(&TIM12->CCER, 1, 3, bool);
}
void STM32446Tim12_cc1p(uint8_t bool)
{
	setreg(&TIM12->CCER, 1, 1, bool);
}
void STM32446Tim12_cc1e(uint8_t bool)
{
	setreg(&TIM12->CCER, 1, 0, bool);
}
// CNT
void STM32446Tim12_cnt(uint16_t value)
{
	TIM12->CNT = value;
}
uint16_t STM32446Tim12_get_cnt(void)
{
	return TIM12->CNT;
}
// ARR
void STM32446Tim12_arr(uint16_t value)
{
	TIM12->ARR = value;
}
// CCR1
void STM32446Tim12_ccr1(uint16_t value)
{
	TIM12->CCR1 = value;
}
// CCR2
void STM32446Tim12_ccr2(uint16_t value)
{
	TIM12->CCR2 = value;
}
// PSC
void STM32446Tim12_psc(uint16_t value)
{
	TIM12->PSC = value;
}
/*************/
/*** TIM13 ***/
/*************/
void STM32446Tim13Clock(uint8_t bool)
{
	if(bool){
		RCC->APB1ENR |= (1 << 7); // timer 13 clock enabled
	}else{
		RCC->APB1ENR &= ~(1 << 7); //timer 13 clock disabled
	}
}
void STM32446Tim13Nvic(uint8_t bool)
{ // 44
	if(bool){setbit(NVIC->ISER, 1, 44, 1);}else{setbit(NVIC->ICER, 1, 44, 1);}
}
/************************/
/*** TIM13 Bit Mapping ***/
/************************/
// CR1
void STM32446Tim13_ckd(uint8_t value)
{
	setreg(&TIM9->CR1, 2, 8, value);
}
uint8_t STM32446Tim13_get_ckd(void)
{
	return readreg(TIM13->CR1, 2, 8);
}
void STM32446Tim13_set_apre(uint8_t bool)
{
	setreg(&TIM13->CR1, 1, 7, bool);
}
void STM32446Tim13_set_opm(uint8_t bool)
{
	setreg(&TIM13->CR1, 1, 3, bool);
}
void STM32446Tim13_set_urs(uint8_t bool)
{
	setreg(&TIM13->CR1, 1, 2, bool);
}
void STM32446Tim13_set_udis(uint8_t bool)
{
	setreg(&TIM13->CR1, 1, 1, bool);
}
void STM32446Tim13_cen(uint8_t bool)
{
	setreg(&TIM13->CR1, 1, 0, bool);
}
// DIER
void STM32446Tim13_tie(uint8_t bool)
{
	setreg(&TIM13->DIER, 1, 6, bool);
}
void STM32446Tim13_cc2ie(uint8_t bool)
{
	setreg(&TIM13->DIER, 1, 2, bool);
}
void STM32446Tim13_cc1ie(uint8_t bool)
{
	setreg(&TIM13->DIER, 1, 1, bool);
}
void STM32446Tim13_uie(uint8_t bool)
{
	setreg(&TIM13->DIER, 1, 0, bool);
}
// SR
uint8_t STM32446Tim13_cc2of(void)
{
	return readreg(TIM13->SR, 1, 10);
}
void STM32446Tim13_clear_cc2of(void)
{
	setreg(&TIM13->SR, 1, 10, 0);
}
uint8_t STM32446Tim13_cc1of(void)
{
	return readreg(TIM13->SR, 1, 9);
}
void STM32446Tim13_clear_cc1of(void)
{
	setreg(&TIM13->SR, 1, 9, 0);
}
uint8_t STM32446Tim13_tif(void)
{
	return readreg(TIM13->SR, 1, 6);
}
void STM32446Tim13_clear_tif(void)
{
	setreg(&TIM13->SR, 1, 6, 0);
}
uint8_t STM32446Tim13_cc2if(void)
{
	return readreg(TIM13->SR, 1, 2);
}
void STM32446Tim13_clear_cc2if(void)
{
	setreg(&TIM13->SR, 1, 2, 0);
}
uint8_t STM32446Tim13_cc1if(void)
{
	return readreg(TIM13->SR, 1, 1);
}
void STM32446Tim13_clear_cc1if(void)
{
	setreg(&TIM13->SR, 1, 1, 0);
}
uint8_t STM32446Tim13_uif(void)
{
	return readreg(TIM13->SR, 1, 0);
}
void STM32446Tim13_clear_uif(void)
{
	setreg(&TIM13->SR, 1, 0, 0);
}
// EGR
void STM32446Tim13_tg(void)
{
	setreg(&TIM13->EGR, 1, 6, 1);
}
void STM32446Tim13_cc2g(void)
{
	setreg(&TIM13->EGR, 1, 2, 1);
}
void STM32446Tim13_cc1g(void)
{
	setreg(&TIM13->EGR, 1, 1, 1);
}
void STM32446Tim13_ug(void)
{
	setreg(&TIM13->EGR, 1, 0, 1);
}
// CCMR1
void STM32446Tim13_oc2m(uint8_t value)
{
	setreg(&TIM13->CCMR1, 3, 12, value);
}
void STM32446Tim13_ic2f(uint8_t value)
{
	setreg(&TIM13->CCMR1, 4, 12, value);
}
void STM32446Tim13_oc2pe(uint8_t bool)
{
	setreg(&TIM13->CCMR1, 1, 11, bool);
}
void STM32446Tim13_oc2fe(uint8_t bool)
{
	setreg(&TIM13->CCMR1, 1, 10, bool);
}
void STM32446Tim13_ic2psc(uint8_t value)
{
	setreg(&TIM13->CCMR1, 2, 10, value);
}
void STM32446Tim13_cc2s(uint8_t value)
{
	setreg(&TIM13->CCMR1, 2, 8, value);
}
void STM32446Tim13_oc1m(uint8_t value)
{
	setreg(&TIM13->CCMR1, 3, 4, value);
}
void STM32446Tim13_ic1f(uint8_t value)
{
	setreg(&TIM13->CCMR1, 4, 4, value);
}
void STM32446Tim13_oc1pe(uint8_t bool)
{
	setreg(&TIM13->CCMR1, 1, 3, bool);
}
void STM32446Tim13_oc1fe(uint8_t bool)
{
	setreg(&TIM13->CCMR1, 1, 2, bool);
}
void STM32446Tim13_ic1psc(uint8_t value)
{
	setreg(&TIM13->CCMR1, 2, 2, value);
}
void STM32446Tim13_cc1s(uint8_t value)
{
	setreg(&TIM13->CCMR1, 2, 0, value);
}
// CCER
void STM32446Tim13_cc2np(uint8_t bool)
{
	setreg(&TIM13->CCER, 1, 7, bool);
}
void STM32446Tim13_cc2p(uint8_t bool)
{
	setreg(&TIM13->CCER, 1, 5, bool);
}
void STM32446Tim13_cc2e(uint8_t bool)
{
	setreg(&TIM13->CCER, 1, 4, bool);
}
void STM32446Tim13_cc1np(uint8_t bool)
{
	setreg(&TIM13->CCER, 1, 3, bool);
}
void STM32446Tim13_cc1p(uint8_t bool)
{
	setreg(&TIM13->CCER, 1, 1, bool);
}
void STM32446Tim13_cc1e(uint8_t bool)
{
	setreg(&TIM13->CCER, 1, 0, bool);
}
// CNT
void STM32446Tim13_cnt(uint16_t value)
{
	TIM13->CNT = value;
}
uint16_t STM32446Tim13_get_cnt(void)
{
	return TIM13->CNT;
}
// PSC
void STM32446Tim13_psc(uint16_t value)
{
	TIM13->PSC = value;
}
// ARR
void STM32446Tim13_arr(uint16_t value)
{
	TIM13->ARR = value;
}
// CCR1
void STM32446Tim13_ccr1(uint16_t value)
{
	TIM13->CCR1 = value;
}
// OR
void STM32446Tim13_or(uint8_t value)
{
	setreg(&TIM13->OR, 2, 0, value);
}
/*************/
/*** TIM14 ***/
/*************/
void STM32446Tim14Clock(uint8_t bool)
{
	if(bool){
		RCC->APB1ENR |= (1 << 8); // timer 14 clock enabled
	}else{
		RCC->APB1ENR &= ~(1 << 8); //timer 14 clock disabled
	}
}
void STM32446Tim14Nvic(uint8_t bool)
{ // 45
	if(bool){setbit(NVIC->ISER, 1, 45, 1);}else{setbit(NVIC->ICER, 1, 45, 1);}
}
/************************/
/*** TIM14 Bit Mapping ***/
/************************/
// CR1
void STM32446Tim14_ckd(uint8_t value)
{
	setreg(&TIM9->CR1, 2, 8, value);
}
uint8_t STM32446Tim14_get_ckd(void)
{
	return readreg(TIM14->CR1, 2, 8);
}
void STM32446Tim14_set_apre(uint8_t bool)
{
	setreg(&TIM14->CR1, 1, 7, bool);
}
void STM32446Tim14_set_opm(uint8_t bool)
{
	setreg(&TIM14->CR1, 1, 3, bool);
}
void STM32446Tim14_set_urs(uint8_t bool)
{
	setreg(&TIM14->CR1, 1, 2, bool);
}
void STM32446Tim14_set_udis(uint8_t bool)
{
	setreg(&TIM14->CR1, 1, 1, bool);
}
void STM32446Tim14_cen(uint8_t bool)
{
	setreg(&TIM14->CR1, 1, 0, bool);
}
// DIER
void STM32446Tim14_tie(uint8_t bool)
{
	setreg(&TIM14->DIER, 1, 6, bool);
}
void STM32446Tim14_cc2ie(uint8_t bool)
{
	setreg(&TIM14->DIER, 1, 2, bool);
}
void STM32446Tim14_cc1ie(uint8_t bool)
{
	setreg(&TIM14->DIER, 1, 1, bool);
}
void STM32446Tim14_uie(uint8_t bool)
{
	setreg(&TIM14->DIER, 1, 0, bool);
}
// SR
uint8_t STM32446Tim14_cc2of(void)
{
	return readreg(TIM14->SR, 1, 10);
}
void STM32446Tim14_clear_cc2of(void)
{
	setreg(&TIM14->SR, 1, 10, 0);
}
uint8_t STM32446Tim14_cc1of(void)
{
	return readreg(TIM14->SR, 1, 9);
}
void STM32446Tim14_clear_cc1of(void)
{
	setreg(&TIM14->SR, 1, 9, 0);
}
uint8_t STM32446Tim14_tif(void)
{
	return readreg(TIM14->SR, 1, 6);
}
void STM32446Tim14_clear_tif(void)
{
	setreg(&TIM14->SR, 1, 6, 0);
}
uint8_t STM32446Tim14_cc2if(void)
{
	return readreg(TIM14->SR, 1, 2);
}
void STM32446Tim14_clear_cc2if(void)
{
	setreg(&TIM14->SR, 1, 2, 0);
}
uint8_t STM32446Tim14_cc1if(void)
{
	return readreg(TIM14->SR, 1, 1);
}
void STM32446Tim14_clear_cc1if(void)
{
	setreg(&TIM14->SR, 1, 1, 0);
}
uint8_t STM32446Tim14_uif(void)
{
	return readreg(TIM14->SR, 1, 0);
}
void STM32446Tim14_clear_uif(void)
{
	setreg(&TIM14->SR, 1, 0, 0);
}
// EGR
void STM32446Tim14_tg(void)
{
	setreg(&TIM14->EGR, 1, 6, 1);
}
void STM32446Tim14_cc2g(void)
{
	setreg(&TIM14->EGR, 1, 2, 1);
}
void STM32446Tim14_cc1g(void)
{
	setreg(&TIM14->EGR, 1, 1, 1);
}
void STM32446Tim14_ug(void)
{
	setreg(&TIM14->EGR, 1, 0, 1);
}
// CCMR1
void STM32446Tim14_oc2m(uint8_t value)
{
	setreg(&TIM14->CCMR1, 3, 12, value);
}
void STM32446Tim14_ic2f(uint8_t value)
{
	setreg(&TIM14->CCMR1, 4, 12, value);
}
void STM32446Tim14_oc2pe(uint8_t bool)
{
	setreg(&TIM14->CCMR1, 1, 11, bool);
}
void STM32446Tim14_oc2fe(uint8_t bool)
{
	setreg(&TIM14->CCMR1, 1, 10, bool);
}
void STM32446Tim14_ic2psc(uint8_t value)
{
	setreg(&TIM14->CCMR1, 2, 10, value);
}
void STM32446Tim14_cc2s(uint8_t value)
{
	setreg(&TIM14->CCMR1, 2, 8, value);
}
void STM32446Tim14_oc1m(uint8_t value)
{
	setreg(&TIM14->CCMR1, 3, 4, value);
}
void STM32446Tim14_ic1f(uint8_t value)
{
	setreg(&TIM14->CCMR1, 4, 4, value);
}
void STM32446Tim14_oc1pe(uint8_t bool)
{
	setreg(&TIM14->CCMR1, 1, 3, bool);
}
void STM32446Tim14_oc1fe(uint8_t bool)
{
	setreg(&TIM14->CCMR1, 1, 2, bool);
}
void STM32446Tim14_ic1psc(uint8_t value)
{
	setreg(&TIM14->CCMR1, 2, 2, value);
}
void STM32446Tim14_cc1s(uint8_t value)
{
	setreg(&TIM14->CCMR1, 2, 0, value);
}
// CCER
void STM32446Tim14_cc2np(uint8_t bool)
{
	setreg(&TIM14->CCER, 1, 7, bool);
}
void STM32446Tim14_cc2p(uint8_t bool)
{
	setreg(&TIM14->CCER, 1, 5, bool);
}
void STM32446Tim14_cc2e(uint8_t bool)
{
	setreg(&TIM14->CCER, 1, 4, bool);
}
void STM32446Tim14_cc1np(uint8_t bool)
{
	setreg(&TIM14->CCER, 1, 3, bool);
}
void STM32446Tim14_cc1p(uint8_t bool)
{
	setreg(&TIM14->CCER, 1, 1, bool);
}
void STM32446Tim14_cc1e(uint8_t bool)
{
	setreg(&TIM14->CCER, 1, 0, bool);
}
// CNT
void STM32446Tim14_cnt(uint16_t value)
{
	TIM14->CNT = value;
}
uint16_t STM32446Tim14_get_cnt(void)
{
	return TIM14->CNT;
}
// PSC
void STM32446Tim14_psc(uint16_t value)
{
	TIM14->PSC = value;
}
// ARR
void STM32446Tim14_arr(uint16_t value)
{
	TIM14->ARR = value;
}
// CCR1
void STM32446Tim14_ccr1(uint16_t value)
{
	TIM14->CCR1 = value;
}
// OR
void STM32446Tim14_or(uint8_t value)
{
	setreg(&TIM14->OR, 2, 0, value);
}
/*** TIM9 AUX Procedure & Function Definition ***/
STM32446TIM9_CR1* stm32446_tim9_cr1_inic(void)
{

	// CR1
	stm32446_tim9_cr1.get_ckd = STM32446Tim9_get_ckd;
	stm32446_tim9_cr1.apre = STM32446Tim9_set_apre;
	stm32446_tim9_cr1.opm = STM32446Tim9_set_opm;
	stm32446_tim9_cr1.urs = STM32446Tim9_set_urs;
	stm32446_tim9_cr1.udis = STM32446Tim9_set_udis;
	stm32446_tim9_cr1.cen = STM32446Tim9_cen;
	return &stm32446_tim9_cr1;
}
STM32446TIM9_SMCR* stm32446_tim9_smcr_inic(void)
{

	// SMCR
	stm32446_tim9_smcr.msm = STM32446Tim9_msm;
	stm32446_tim9_smcr.ts = STM32446Tim9_ts;
	stm32446_tim9_smcr.sms = STM32446Tim9_sms;
	return &stm32446_tim9_smcr;
}
STM32446TIM9_DIER* stm32446_tim9_dier_inic(void)
{

	// DIER
	stm32446_tim9_dier.tie = STM32446Tim9_tie;
	stm32446_tim9_dier.cc2ie = STM32446Tim9_cc2ie;
	stm32446_tim9_dier.cc1ie = STM32446Tim9_cc1ie;
	stm32446_tim9_dier.uie = STM32446Tim9_uie;
	return &stm32446_tim9_dier;
}
STM32446TIM9_SR* stm32446_tim9_sr_inic(void)
{

	// SR
	stm32446_tim9_sr.cc2of = STM32446Tim9_cc2of;
	stm32446_tim9_sr.clear_cc2of = STM32446Tim9_clear_cc2of;
	stm32446_tim9_sr.cc1of = STM32446Tim9_cc1of;
	stm32446_tim9_sr.clear_cc1of = STM32446Tim9_clear_cc1of;
	stm32446_tim9_sr.tif = STM32446Tim9_tif;
	stm32446_tim9_sr.clear_tif = STM32446Tim9_clear_tif;
	stm32446_tim9_sr.cc2if = STM32446Tim9_cc2if;
	stm32446_tim9_sr.clear_cc2if = STM32446Tim9_clear_cc2if;
	stm32446_tim9_sr.cc1if = STM32446Tim9_cc1if;
	stm32446_tim9_sr.clear_cc1if = STM32446Tim9_clear_cc1if;
	stm32446_tim9_sr.uif = STM32446Tim9_uif;
	stm32446_tim9_sr.clear_uif = STM32446Tim9_clear_uif;
	return &stm32446_tim9_sr;
}
STM32446TIM9_EGR* stm32446_tim9_egr_inic(void)
{

	// EGR
	stm32446_tim9_egr.tg = STM32446Tim9_tg;
	stm32446_tim9_egr.cc2g = STM32446Tim9_cc2g;
	stm32446_tim9_egr.cc1g = STM32446Tim9_cc1g;
	stm32446_tim9_egr.ug = STM32446Tim9_ug;
	return &stm32446_tim9_egr;
}
STM32446TIM9_CCMR1* stm32446_tim9_ccmr1_inic(void)
{

	// CCMR1
	stm32446_tim9_ccmr1.oc2m = STM32446Tim9_oc2m;
	stm32446_tim9_ccmr1.ic2f = STM32446Tim9_ic2f;
	stm32446_tim9_ccmr1.oc2pe = STM32446Tim9_oc2pe;
	stm32446_tim9_ccmr1.oc2fe = STM32446Tim9_oc2fe;
	stm32446_tim9_ccmr1.ic2psc = STM32446Tim9_ic2psc;
	stm32446_tim9_ccmr1.cc2s = STM32446Tim9_cc2s;
	stm32446_tim9_ccmr1.oc1m = STM32446Tim9_oc1m;
	stm32446_tim9_ccmr1.ic1f = STM32446Tim9_ic1f;
	stm32446_tim9_ccmr1.oc1pe = STM32446Tim9_oc1pe;
	stm32446_tim9_ccmr1.oc1fe = STM32446Tim9_oc1fe;
	stm32446_tim9_ccmr1.ic1psc = STM32446Tim9_ic1psc;
	stm32446_tim9_ccmr1.cc1s = STM32446Tim9_cc1s;
	return &stm32446_tim9_ccmr1;
}
STM32446TIM9_CCER* stm32446_tim9_ccer_inic(void)
{

	// CCER
	stm32446_tim9_ccer.cc2np = STM32446Tim9_cc2np;
	stm32446_tim9_ccer.cc2p = STM32446Tim9_cc2p;
	stm32446_tim9_ccer.cc2e = STM32446Tim9_cc2e;
	stm32446_tim9_ccer.cc1np = STM32446Tim9_cc1np;
	stm32446_tim9_ccer.cc1p = STM32446Tim9_cc1p;
	stm32446_tim9_ccer.cc1e = STM32446Tim9_cc1e;
	return &stm32446_tim9_ccer;
}
/*** TIM9 Procedure & Function Definition ***/
STM32446TIM9obj tim9_enable(void)
{


	// CLOCK
	stm32446_tim9.clock = STM32446Tim9Clock;
	// NVIC
	stm32446_tim9.nvic = STM32446Tim9Nvic;
	/*** TIM9 Bit Mapping Link ***/
	stm32446_tim9.cr1 = stm32446_tim9_cr1_inic();
	stm32446_tim9.smcr = stm32446_tim9_smcr_inic();
	stm32446_tim9.dier = stm32446_tim9_dier_inic();
	stm32446_tim9.sr = stm32446_tim9_sr_inic();
	stm32446_tim9.egr = stm32446_tim9_egr_inic();
	stm32446_tim9.ccmr1 = stm32446_tim9_ccmr1_inic();
	stm32446_tim9.ccer = stm32446_tim9_ccer_inic();
	stm32446_tim9.cnt = STM32446Tim9_cnt;
	stm32446_tim9.get_cnt = STM32446Tim9_get_cnt;
	stm32446_tim9.arr = STM32446Tim9_arr;
	stm32446_tim9.ccr1 = STM32446Tim9_ccr1;
	stm32446_tim9.ccr2 = STM32446Tim9_ccr2;
	stm32446_tim9.psc = STM32446Tim9_psc;
	return stm32446_tim9;
}

STM32446TIM9obj* tim9(void){ return (STM32446TIM9obj*) &stm32446_tim9; }

/*** TIM10 AUX Procedure & Function Definition ***/
STM32446TIM10_CR1* stm32446_tim10_cr1_inic(void)
{

	// CR1
	stm32446_tim10_cr1.get_ckd = STM32446Tim10_get_ckd;
	stm32446_tim10_cr1.apre = STM32446Tim10_set_apre;
	stm32446_tim10_cr1.urs = STM32446Tim10_set_urs;
	stm32446_tim10_cr1.udis = STM32446Tim10_set_udis;
	stm32446_tim10_cr1.cen = STM32446Tim10_cen;
	return &stm32446_tim10_cr1;
}
STM32446TIM10_DIER* stm32446_tim10_dier_inic(void)
{

	// DIER
	stm32446_tim10_dier.cc1ie = STM32446Tim10_cc1ie;
	stm32446_tim10_dier.uie = STM32446Tim10_uie;
	return &stm32446_tim10_dier;
}
STM32446TIM10_SR* stm32446_tim10_sr_inic(void)
{

	// SR
	stm32446_tim10_sr.cc1of = STM32446Tim10_cc1of;
	stm32446_tim10_sr.clear_cc1of = STM32446Tim10_clear_cc1of;
	stm32446_tim10_sr.cc1if = STM32446Tim10_cc1if;
	stm32446_tim10_sr.clear_cc1if = STM32446Tim10_clear_cc1if;
	stm32446_tim10_sr.uif = STM32446Tim10_uif;
	stm32446_tim10_sr.clear_uif = STM32446Tim10_clear_uif;
	return &stm32446_tim10_sr;
}
STM32446TIM10_EGR* stm32446_tim10_egr_inic(void)
{

	// EGR
	stm32446_tim10_egr.cc1g = STM32446Tim10_cc1g;
	stm32446_tim10_egr.ug = STM32446Tim10_ug;
	return &stm32446_tim10_egr;
}
STM32446TIM10_CCMR1* stm32446_tim10_ccmr1_inic(void)
{

	// CCMR1
	stm32446_tim10_ccmr1.oc1m = STM32446Tim10_oc1m;
	stm32446_tim10_ccmr1.ic1f = STM32446Tim10_ic1f;
	stm32446_tim10_ccmr1.oc1pe = STM32446Tim10_oc1pe;
	stm32446_tim10_ccmr1.oc1fe = STM32446Tim10_oc1fe;
	stm32446_tim10_ccmr1.ic1psc = STM32446Tim10_ic1psc;
	stm32446_tim10_ccmr1.cc1s = STM32446Tim10_cc1s;
	return &stm32446_tim10_ccmr1;
}
STM32446TIM10_CCER* stm32446_tim10_ccer_inic(void)
{

	// CCER
	stm32446_tim10_ccer.cc1np = STM32446Tim10_cc1np;
	stm32446_tim10_ccer.cc1p = STM32446Tim10_cc1p;
	stm32446_tim10_ccer.cc1e = STM32446Tim10_cc1e;
	return &stm32446_tim10_ccer;
}
/*** TIM10 Procedure & Function Definition***/
STM32446TIM10obj tim10_enable(void)
{


	// CLOCK
	stm32446_tim10.clock = STM32446Tim10Clock;
	// NVIC
	stm32446_tim10.nvic = STM32446Tim10Nvic;
	/*** TIM10 Bit Mapping Link ***/
	stm32446_tim10.cr1 = stm32446_tim10_cr1_inic();
	stm32446_tim10.dier = stm32446_tim10_dier_inic();
	stm32446_tim10.sr = stm32446_tim10_sr_inic();
	stm32446_tim10.egr = stm32446_tim10_egr_inic();
	stm32446_tim10.ccmr1 = stm32446_tim10_ccmr1_inic();
	stm32446_tim10.ccer = stm32446_tim10_ccer_inic();
	stm32446_tim10.cnt = STM32446Tim10_cnt;
	stm32446_tim10.get_cnt = STM32446Tim10_get_cnt;
	stm32446_tim10.psc = STM32446Tim10_psc;
	stm32446_tim10.arr = STM32446Tim10_arr;
	stm32446_tim10.ccr1 = STM32446Tim10_ccr1;
	stm32446_tim10.or = STM32446Tim10_or;
	return stm32446_tim10;
}

STM32446TIM10obj* tim10(void){ return (STM32446TIM10obj*) &stm32446_tim10; }

/*** TIM11 AUX Procedure & Function Definition***/
STM32446TIM11_CR1* stm32446_tim11_cr1_inic(void)
{

	// CR1
	stm32446_tim11_cr1.get_ckd = STM32446Tim11_get_ckd;
	stm32446_tim11_cr1.apre = STM32446Tim11_set_apre;
	stm32446_tim11_cr1.urs = STM32446Tim11_set_urs;
	stm32446_tim11_cr1.udis = STM32446Tim11_set_udis;
	stm32446_tim11_cr1.cen = STM32446Tim11_cen;
	return &stm32446_tim11_cr1;
}
STM32446TIM11_DIER* stm32446_tim11_dier_inic(void)
{

	// DIER
	stm32446_tim11_dier.cc1ie = STM32446Tim11_cc1ie;
	stm32446_tim11_dier.uie = STM32446Tim11_uie;
	return &stm32446_tim11_dier;
}
STM32446TIM11_SR* stm32446_tim11_sr_inic(void)
{

	// SR
	stm32446_tim11_sr.cc1of = STM32446Tim11_cc1of;
	stm32446_tim11_sr.clear_cc1of = STM32446Tim11_clear_cc1of;
	stm32446_tim11_sr.cc1if = STM32446Tim11_cc1if;
	stm32446_tim11_sr.clear_cc1if = STM32446Tim11_clear_cc1if;
	stm32446_tim11_sr.uif = STM32446Tim11_uif;
	stm32446_tim11_sr.clear_uif = STM32446Tim11_clear_uif;
	return &stm32446_tim11_sr;
}
STM32446TIM11_EGR* stm32446_tim11_egr_inic(void)
{

	// EGR
	stm32446_tim11_egr.cc1g = STM32446Tim11_cc1g;
	stm32446_tim11_egr.ug = STM32446Tim11_ug;
	return &stm32446_tim11_egr;
}
STM32446TIM11_CCMR1* stm32446_tim11_ccmr1_inic(void)
{

	// CCMR1
	stm32446_tim11_ccmr1.oc1m = STM32446Tim11_oc1m;
	stm32446_tim11_ccmr1.ic1f = STM32446Tim11_ic1f;
	stm32446_tim11_ccmr1.oc1pe = STM32446Tim11_oc1pe;
	stm32446_tim11_ccmr1.oc1fe = STM32446Tim11_oc1fe;
	stm32446_tim11_ccmr1.ic1psc = STM32446Tim11_ic1psc;
	stm32446_tim11_ccmr1.cc1s = STM32446Tim11_cc1s;
	return &stm32446_tim11_ccmr1;
}
STM32446TIM11_CCER* stm32446_tim11_ccer_inic(void)
{

	// CCER
	stm32446_tim11_ccer.cc1np = STM32446Tim11_cc1np;
	stm32446_tim11_ccer.cc1p = STM32446Tim11_cc1p;
	stm32446_tim11_ccer.cc1e = STM32446Tim11_cc1e;
	return &stm32446_tim11_ccer;
}
/*** TIM11 Procedure & Function Definition***/
STM32446TIM11obj tim11_enable(void)
{


	// CLOCK
	stm32446_tim11.clock = STM32446Tim11Clock;
	// NVIC
	stm32446_tim11.nvic = STM32446Tim11Nvic;
	/*** TIM11 Bit Mapping Link ***/
	stm32446_tim11.cr1 = stm32446_tim11_cr1_inic();
	stm32446_tim11.dier = stm32446_tim11_dier_inic();
	stm32446_tim11.sr = stm32446_tim11_sr_inic();
	stm32446_tim11.egr = stm32446_tim11_egr_inic();
	stm32446_tim11.ccmr1 = stm32446_tim11_ccmr1_inic();
	stm32446_tim11.ccer = stm32446_tim11_ccer_inic();
	stm32446_tim11.cnt = STM32446Tim11_cnt;
	stm32446_tim11.get_cnt = STM32446Tim11_get_cnt;
	stm32446_tim11.psc = STM32446Tim11_psc;
	stm32446_tim11.arr = STM32446Tim11_arr;
	stm32446_tim11.ccr1 = STM32446Tim11_ccr1;
	stm32446_tim11.or = STM32446Tim11_or;
	return stm32446_tim11;
}

STM32446TIM11obj* tim11(void){ return (STM32446TIM11obj*) &stm32446_tim11; }

/*** TIM12 AUX Procedure & Function Definition***/
STM32446TIM12_CR1* stm32446_tim12_cr1_inic(void)
{

	// CR1
	stm32446_tim12_cr1.get_ckd = STM32446Tim12_get_ckd;
	stm32446_tim12_cr1.apre = STM32446Tim12_set_apre;
	stm32446_tim12_cr1.opm = STM32446Tim12_set_opm;
	stm32446_tim12_cr1.urs = STM32446Tim12_set_urs;
	stm32446_tim12_cr1.udis = STM32446Tim12_set_udis;
	stm32446_tim12_cr1.cen = STM32446Tim12_cen;
	return &stm32446_tim12_cr1;
}
STM32446TIM12_SMCR* stm32446_tim12_smcr_inic(void)
{

	// SMCR
	stm32446_tim12_smcr.msm = STM32446Tim12_msm;
	stm32446_tim12_smcr.ts = STM32446Tim12_ts;
	stm32446_tim12_smcr.sms = STM32446Tim12_sms;
	return &stm32446_tim12_smcr;
}
STM32446TIM12_DIER* stm32446_tim12_dier_inic(void)
{

	// DIER
	stm32446_tim12_dier.tie = STM32446Tim12_tie;
	stm32446_tim12_dier.cc2ie = STM32446Tim12_cc2ie;
	stm32446_tim12_dier.cc1ie = STM32446Tim12_cc1ie;
	stm32446_tim12_dier.uie = STM32446Tim12_uie;
	return &stm32446_tim12_dier;
}
STM32446TIM12_SR* stm32446_tim12_sr_inic(void)
{

	// SR
	stm32446_tim12_sr.cc2of = STM32446Tim12_cc2of;
	stm32446_tim12_sr.clear_cc2of = STM32446Tim12_clear_cc2of;
	stm32446_tim12_sr.cc1of = STM32446Tim12_cc1of;
	stm32446_tim12_sr.clear_cc1of = STM32446Tim12_clear_cc1of;
	stm32446_tim12_sr.tif = STM32446Tim12_tif;
	stm32446_tim12_sr.clear_tif = STM32446Tim12_clear_tif;
	stm32446_tim12_sr.cc2if = STM32446Tim12_cc2if;
	stm32446_tim12_sr.clear_cc2if = STM32446Tim12_clear_cc2if;
	stm32446_tim12_sr.cc1if = STM32446Tim12_cc1if;
	stm32446_tim12_sr.clear_cc1if = STM32446Tim12_clear_cc1if;
	stm32446_tim12_sr.uif = STM32446Tim12_uif;
	stm32446_tim12_sr.clear_uif = STM32446Tim12_clear_uif;
	return &stm32446_tim12_sr;
}
STM32446TIM12_EGR* stm32446_tim12_egr_inic(void)
{

	// EGR
	stm32446_tim12_egr.tg = STM32446Tim12_tg;
	stm32446_tim12_egr.cc2g = STM32446Tim12_cc2g;
	stm32446_tim12_egr.cc1g = STM32446Tim12_cc1g;
	stm32446_tim12_egr.ug = STM32446Tim12_ug;
	return &stm32446_tim12_egr;
}
STM32446TIM12_CCMR1* stm32446_tim12_ccmr1_inic(void)
{

	// CCMR1
	stm32446_tim12_ccmr1.oc2m = STM32446Tim12_oc2m;
	stm32446_tim12_ccmr1.ic2f = STM32446Tim12_ic2f;
	stm32446_tim12_ccmr1.oc2pe = STM32446Tim12_oc2pe;
	stm32446_tim12_ccmr1.oc2fe = STM32446Tim12_oc2fe;
	stm32446_tim12_ccmr1.ic2psc = STM32446Tim12_ic2psc;
	stm32446_tim12_ccmr1.cc2s = STM32446Tim12_cc2s;
	stm32446_tim12_ccmr1.oc1m = STM32446Tim12_oc1m;
	stm32446_tim12_ccmr1.ic1f = STM32446Tim12_ic1f;
	stm32446_tim12_ccmr1.oc1pe = STM32446Tim12_oc1pe;
	stm32446_tim12_ccmr1.oc1fe = STM32446Tim12_oc1fe;
	stm32446_tim12_ccmr1.ic1psc = STM32446Tim12_ic1psc;
	stm32446_tim12_ccmr1.cc1s = STM32446Tim12_cc1s;
	return &stm32446_tim12_ccmr1;
}
STM32446TIM12_CCER* stm32446_tim12_ccer_inic(void)
{

	// CCER
	stm32446_tim12_ccer.cc2np = STM32446Tim12_cc2np;
	stm32446_tim12_ccer.cc2p = STM32446Tim12_cc2p;
	stm32446_tim12_ccer.cc2e = STM32446Tim12_cc2e;
	stm32446_tim12_ccer.cc1np = STM32446Tim12_cc1np;
	stm32446_tim12_ccer.cc1p = STM32446Tim12_cc1p;
	stm32446_tim12_ccer.cc1e = STM32446Tim12_cc1e;
	return &stm32446_tim12_ccer;
}
/*** TIM12 Procedure & Function Definition***/
STM32446TIM12obj tim12_enable(void)
{


	// CLOCK
	stm32446_tim12.clock = STM32446Tim12Clock;
	// NVIC
	stm32446_tim12.nvic = STM32446Tim12Nvic;
	/*** TIM12 Bit Mapping Link ***/
	stm32446_tim12.cr1 = stm32446_tim12_cr1_inic();
	stm32446_tim12.smcr = stm32446_tim12_smcr_inic();
	stm32446_tim12.dier = stm32446_tim12_dier_inic();
	stm32446_tim12.sr = stm32446_tim12_sr_inic();
	stm32446_tim12.egr = stm32446_tim12_egr_inic();
	stm32446_tim12.ccmr1 = stm32446_tim12_ccmr1_inic();
	stm32446_tim12.ccer = stm32446_tim12_ccer_inic();
	stm32446_tim12.cnt = STM32446Tim12_cnt;
	stm32446_tim12.get_cnt = STM32446Tim12_get_cnt;
	stm32446_tim12.arr = STM32446Tim12_arr;
	stm32446_tim12.ccr1 = STM32446Tim12_ccr1;
	stm32446_tim12.ccr2 = STM32446Tim12_ccr2;
	stm32446_tim12.psc = STM32446Tim12_psc;
	return stm32446_tim12;
}

STM32446TIM12obj* tim12(void){ return (STM32446TIM12obj*) &stm32446_tim12; }

/*** TIM13 AUX Procedure & Function Definition***/
STM32446TIM13_CR1* stm32446_tim13_cr1_inic(void)
{

	// CR1
	stm32446_tim13_cr1.get_ckd = STM32446Tim13_get_ckd;
	stm32446_tim13_cr1.apre = STM32446Tim13_set_apre;
	stm32446_tim13_cr1.urs = STM32446Tim13_set_urs;
	stm32446_tim13_cr1.udis = STM32446Tim13_set_udis;
	stm32446_tim13_cr1.cen = STM32446Tim13_cen;
	return &stm32446_tim13_cr1;
}
STM32446TIM13_DIER* stm32446_tim13_dier_inic(void)
{

	// DIER
	stm32446_tim13_dier.cc1ie = STM32446Tim13_cc1ie;
	stm32446_tim13_dier.uie = STM32446Tim13_uie;
	return &stm32446_tim13_dier;
}
STM32446TIM13_SR* stm32446_tim13_sr_inic(void)
{

	// SR
	stm32446_tim13_sr.cc1of = STM32446Tim13_cc1of;
	stm32446_tim13_sr.clear_cc1of = STM32446Tim13_clear_cc1of;
	stm32446_tim13_sr.cc1if = STM32446Tim13_cc1if;
	stm32446_tim13_sr.clear_cc1if = STM32446Tim13_clear_cc1if;
	stm32446_tim13_sr.uif = STM32446Tim13_uif;
	stm32446_tim13_sr.clear_uif = STM32446Tim13_clear_uif;
	return &stm32446_tim13_sr;
}
STM32446TIM13_EGR* stm32446_tim13_egr_inic(void)
{

	// EGR
	stm32446_tim13_egr.cc1g = STM32446Tim13_cc1g;
	stm32446_tim13_egr.ug = STM32446Tim13_ug;
	return &stm32446_tim13_egr;
}
STM32446TIM13_CCMR1* stm32446_tim13_ccmr1_inic(void)
{

	// CCMR1
	stm32446_tim13_ccmr1.oc1m = STM32446Tim13_oc1m;
	stm32446_tim13_ccmr1.ic1f = STM32446Tim13_ic1f;
	stm32446_tim13_ccmr1.oc1pe = STM32446Tim13_oc1pe;
	stm32446_tim13_ccmr1.oc1fe = STM32446Tim13_oc1fe;
	stm32446_tim13_ccmr1.ic1psc = STM32446Tim13_ic1psc;
	stm32446_tim13_ccmr1.cc1s = STM32446Tim13_cc1s;
	return &stm32446_tim13_ccmr1;
}
STM32446TIM13_CCER* stm32446_tim13_ccer_inic(void)
{

	// CCER
	stm32446_tim13_ccer.cc1np = STM32446Tim13_cc1np;
	stm32446_tim13_ccer.cc1p = STM32446Tim13_cc1p;
	stm32446_tim13_ccer.cc1e = STM32446Tim13_cc1e;
	return &stm32446_tim13_ccer;
}
/*** TIM13 Procedure & Function Definition***/
STM32446TIM13obj tim13_enable(void)
{


	// CLOCK
	stm32446_tim13.clock = STM32446Tim13Clock;
	// NVIC
	stm32446_tim13.nvic = STM32446Tim13Nvic;
	/*** TIM13 Bit Mapping Link ***/
	stm32446_tim13.cr1 = stm32446_tim13_cr1_inic();
	stm32446_tim13.dier = stm32446_tim13_dier_inic();
	stm32446_tim13.sr = stm32446_tim13_sr_inic();
	stm32446_tim13.egr = stm32446_tim13_egr_inic();
	stm32446_tim13.ccmr1 = stm32446_tim13_ccmr1_inic();
	stm32446_tim13.ccer = stm32446_tim13_ccer_inic();
	stm32446_tim13.cnt = STM32446Tim13_cnt;
	stm32446_tim13.get_cnt = STM32446Tim13_get_cnt;
	stm32446_tim13.psc = STM32446Tim13_psc;
	stm32446_tim13.arr = STM32446Tim13_arr;
	stm32446_tim13.ccr1 = STM32446Tim13_ccr1;
	stm32446_tim13.or = STM32446Tim13_or;
	return stm32446_tim13;
}

STM32446TIM13obj* tim13(void){ return (STM32446TIM13obj*) &stm32446_tim13; }

/*** TIM14 AUX Procedure & Function Definition ***/
STM32446TIM14_CR1* stm32446_tim14_cr1_inic(void)
{

	// CR1
	stm32446_tim14_cr1.get_ckd = STM32446Tim14_get_ckd;
	stm32446_tim14_cr1.apre = STM32446Tim14_set_apre;
	stm32446_tim14_cr1.urs = STM32446Tim14_set_urs;
	stm32446_tim14_cr1.udis = STM32446Tim14_set_udis;
	stm32446_tim14_cr1.cen = STM32446Tim14_cen;
	return &stm32446_tim14_cr1;
}
STM32446TIM14_DIER* stm32446_tim14_dier_inic(void)
{

	// DIER
	stm32446_tim14_dier.cc1ie = STM32446Tim14_cc1ie;
	stm32446_tim14_dier.uie = STM32446Tim14_uie;
	return &stm32446_tim14_dier;
}
STM32446TIM14_SR* stm32446_tim14_sr_inic(void)
{

	// SR
	stm32446_tim14_sr.cc1of = STM32446Tim14_cc1of;
	stm32446_tim14_sr.clear_cc1of = STM32446Tim14_clear_cc1of;
	stm32446_tim14_sr.cc1if = STM32446Tim14_cc1if;
	stm32446_tim14_sr.clear_cc1if = STM32446Tim14_clear_cc1if;
	stm32446_tim14_sr.uif = STM32446Tim14_uif;
	stm32446_tim14_sr.clear_uif = STM32446Tim14_clear_uif;
	return &stm32446_tim14_sr;
}
STM32446TIM14_EGR* stm32446_tim14_egr_inic(void)
{

	// EGR
	stm32446_tim14_egr.cc1g = STM32446Tim14_cc1g;
	stm32446_tim14_egr.ug = STM32446Tim14_ug;
	return &stm32446_tim14_egr;
}
STM32446TIM14_CCMR1* stm32446_tim14_ccmr1_inic(void)
{

	// CCMR1
	stm32446_tim14_ccmr1.oc1m = STM32446Tim14_oc1m;
	stm32446_tim14_ccmr1.ic1f = STM32446Tim14_ic1f;
	stm32446_tim14_ccmr1.oc1pe = STM32446Tim14_oc1pe;
	stm32446_tim14_ccmr1.oc1fe = STM32446Tim14_oc1fe;
	stm32446_tim14_ccmr1.ic1psc = STM32446Tim14_ic1psc;
	stm32446_tim14_ccmr1.cc1s = STM32446Tim14_cc1s;
	return &stm32446_tim14_ccmr1;
}
STM32446TIM14_CCER* stm32446_tim14_ccer_inic(void)
{

	// CCER
	stm32446_tim14_ccer.cc1np = STM32446Tim14_cc1np;
	stm32446_tim14_ccer.cc1p = STM32446Tim14_cc1p;
	stm32446_tim14_ccer.cc1e = STM32446Tim14_cc1e;
	return &stm32446_tim14_ccer;
}
/*** TIM14 Procedure & Function Definition ***/
STM32446TIM14obj tim14_enable(void)
{


	// CLOCK
	stm32446_tim14.clock = STM32446Tim14Clock;
	// NVIC
	stm32446_tim14.nvic = STM32446Tim14Nvic;
	/*** TIM14 Bit Mapping Link ***/
	stm32446_tim14.cr1 = stm32446_tim14_cr1_inic();
	stm32446_tim14.dier = stm32446_tim14_dier_inic();
	stm32446_tim14.sr = stm32446_tim14_sr_inic();
	stm32446_tim14.egr = stm32446_tim14_egr_inic();
	stm32446_tim14.ccmr1 = stm32446_tim14_ccmr1_inic();
	stm32446_tim14.ccer = stm32446_tim14_ccer_inic();
	stm32446_tim14.cnt = STM32446Tim14_cnt;
	stm32446_tim14.get_cnt = STM32446Tim14_get_cnt;
	stm32446_tim14.psc = STM32446Tim14_psc;
	stm32446_tim14.arr = STM32446Tim14_arr;
	stm32446_tim14.ccr1 = STM32446Tim14_ccr1;
	stm32446_tim14.or = STM32446Tim14_or;
	return stm32446_tim14;
}

STM32446TIM14obj* tim14(void){ return (STM32446TIM14obj*) &stm32446_tim14; }

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


