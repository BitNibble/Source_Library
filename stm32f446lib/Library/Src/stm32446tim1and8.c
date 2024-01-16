/******************************************************************************
	STM32 446 TIM 1 and 8
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 2262023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32446tim1and8.h"

/*** File Variables ***/
static STM32446TIM1_CR1 stm32446_tim1_cr1;
static STM32446TIM1_CR2 stm32446_tim1_cr2;
static STM32446TIM1_SMCR stm32446_tim1_smcr;
static STM32446TIM1_DIER stm32446_tim1_dier;
static STM32446TIM1_SR stm32446_tim1_sr;
static STM32446TIM1_EGR stm32446_tim1_egr;
static STM32446TIM1_CCMR1 stm32446_tim1_ccmr1;
static STM32446TIM1_CCMR2 stm32446_tim1_ccmr2;
static STM32446TIM1_CCER stm32446_tim1_ccer;
static STM32446TIM1_BDTR stm32446_tim1_bdtr;
static STM32446TIM1_DCR stm32446_tim1_dcr;
static STM32446TIM1obj stm32446_tim1;
static STM32446TIM8_CR1 stm32446_tim8_cr1;
static STM32446TIM8_CR2 stm32446_tim8_cr2;
static STM32446TIM8_SMCR stm32446_tim8_smcr;
static STM32446TIM8_DIER stm32446_tim8_dier;
static STM32446TIM8_SR stm32446_tim8_sr;
static STM32446TIM8_EGR stm32446_tim8_egr;
static STM32446TIM8_CCMR1 stm32446_tim8_ccmr1;
static STM32446TIM8_CCMR2 stm32446_tim8_ccmr2;
static STM32446TIM8_CCER stm32446_tim8_ccer;
static STM32446TIM8_BDTR stm32446_tim8_bdtr;
static STM32446TIM8_DCR stm32446_tim8_dcr;
static STM32446TIM8obj stm32446_tim8;

/*** File Procedure & Function Header ***/
/*** TIM Auxiliar ***/
STM32446TIM1_CR1* stm32446_tim1_cr1_inic(void);
STM32446TIM1_CR2* stm32446_tim1_cr2_inic(void);
STM32446TIM1_SMCR* stm32446_tim1_smcr_inic(void);
STM32446TIM1_DIER* stm32446_tim1_dier_inic(void);
STM32446TIM1_SR* stm32446_tim1_sr_inic(void);
STM32446TIM1_EGR* stm32446_tim1_egr_inic(void);
STM32446TIM1_CCMR1* stm32446_tim1_ccmr1_inic(void);
STM32446TIM1_CCMR2* stm32446_tim1_ccmr2_inic(void);
STM32446TIM1_CCER* stm32446_tim1_ccer_inic(void);
STM32446TIM1_BDTR* stm32446_tim1_bdtr_inic(void);
STM32446TIM1_DCR* stm32446_tim1_dcr_inic(void);
STM32446TIM8_CR1* stm32446_tim8_cr1_inic(void);
STM32446TIM8_CR2* stm32446_tim8_cr2_inic(void);
STM32446TIM8_SMCR* stm32446_tim8_smcr_inic(void);
STM32446TIM8_DIER* stm32446_tim8_dier_inic(void);
STM32446TIM8_SR* stm32446_tim8_sr_inic(void);
STM32446TIM8_EGR* stm32446_tim8_egr_inic(void);
STM32446TIM8_CCMR1* stm32446_tim8_ccmr1_inic(void);
STM32446TIM8_CCMR2* stm32446_tim8_ccmr2_inic(void);
STM32446TIM8_CCER* stm32446_tim8_ccer_inic(void);
STM32446TIM8_BDTR* stm32446_tim8_bdtr_inic(void);
STM32446TIM8_DCR* stm32446_tim8_dcr_inic(void);
/*** TIMER Procedure & Function Definition ***/
/************/
/*** TIM1 ***/
/************/
void STM32446Tim1Clock(uint8_t bool)
{
	if(bool){RCC->APB2ENR |= (1 << 0);}else{RCC->APB2ENR &= ~(1 << 0);}
}
void STM32446Tim1Nvic(uint8_t value)
{ // 24, 25, 26, 27
	switch(value){
		case 0b1000:
			setbit(NVIC->ISER, 1, TIM1_BRK_TIM9_IRQn, 1);
		break;
		case 0b0100:
			setbit(NVIC->ISER, 1, TIM1_UP_TIM10_IRQn, 1);
		break;
		case 0b0010:
			setbit(NVIC->ISER, 1, TIM1_TRG_COM_TIM11_IRQn, 1);
		break;
		case 0b0001:
			setbit(NVIC->ISER, 1, TIM1_CC_IRQn, 1);
		break;
		case 0b11000:
			setbit(NVIC->ICER, 1, TIM1_BRK_TIM9_IRQn, 1);
		break;
		case 0b10100:
			setbit(NVIC->ICER, 1, TIM1_UP_TIM10_IRQn, 1);
		break;
		case 0b10010:
			setbit(NVIC->ICER, 1, TIM1_TRG_COM_TIM11_IRQn, 1);
		break;
		case 0b10001:
			setbit(NVIC->ICER, 1, TIM1_CC_IRQn, 1);
		break;
	default:
	break;
	}
}
/************************/
/*** TIM1 Bit Mapping ***/
/************************/
// CR1
void STM32446Tim1_ckd(uint8_t value)
{
	setreg(&TIM1->CR1, 1, 8, value);
}
uint8_t STM32446Tim1_get_ckd(void)
{
	return readreg(TIM1->CR1, 2, 8);
}
void STM32446Tim1_set_apre(uint8_t bool)
{
	setreg(&TIM1->CR1, 1, 7, bool);
}
void STM32446Tim1_set_cms(uint8_t value)
{
	setreg(&TIM1->CR1, 2, 5, value);
}
void STM32446Tim1_set_dir(uint8_t bool)
{
	setreg(&TIM1->CR1, 1, 4, bool);
}
void STM32446Tim1_set_opm(uint8_t bool)
{
	setreg(&TIM1->CR1, 1, 3, bool);
}
void STM32446Tim1_set_urs(uint8_t bool)
{
	setreg(&TIM1->CR1, 1, 2, bool);
}
void STM32446Tim1_set_udis(uint8_t bool)
{
	setreg(&TIM1->CR1, 1, 1, bool);
}
void STM32446Tim1_cen(uint8_t bool)
{
	setreg(&TIM1->CR1, 1, 0, bool);
}
// CR2
void STM32446Tim1_ois4(uint8_t bool)
{
	setreg(&TIM1->CR2, 1, 14, bool);
}
void STM32446Tim1_ois3n(uint8_t bool)
{
	setreg(&TIM1->CR2, 1, 13, bool);
}
void STM32446Tim1_ois3(uint8_t bool)
{
	setreg(&TIM1->CR2, 1, 12, bool);
}
void STM32446Tim1_ois2n(uint8_t bool)
{
	setreg(&TIM1->CR2, 1, 11, bool);
}
void STM32446Tim1_ois2(uint8_t bool)
{
	setreg(&TIM1->CR2, 1, 10, bool);
}
void STM32446Tim1_ois1n(uint8_t bool)
{
	setreg(&TIM1->CR2, 1, 9, bool);
}
void STM32446Tim1_ois1(uint8_t bool)
{
	setreg(&TIM1->CR2, 1, 8, bool);
}
void STM32446Tim1_ti1s(uint8_t bool)
{
	setreg(&TIM1->CR2, 1, 7, bool);
}
void STM32446Tim1_mms(uint8_t value)
{
	setreg(&TIM1->CR2, 3, 4, value);
}
void STM32446Tim1_ccds(uint8_t bool)
{
	setreg(&TIM1->CR2, 1, 3, bool);
}
void STM32446Tim1_ccus(uint8_t bool)
{
	setreg(&TIM1->CR2, 1, 2, bool);
}
void STM32446Tim1_ccpc(uint8_t bool)
{
	setreg(&TIM1->CR2, 1, 0, bool);
}
// SMCR
void STM32446Tim1_etp(uint8_t bool)
{
	setreg(&TIM1->SMCR, 1, 15, bool);
}
void STM32446Tim1_ece(uint8_t bool)
{
	setreg(&TIM1->SMCR, 1, 14, bool);
}
void STM32446Tim1_etps(uint8_t value)
{
	setreg(&TIM1->SMCR, 2, 12, value);
}
void STM32446Tim1_etf(uint8_t value)
{
	setreg(&TIM1->SMCR, 4, 8, value);
}
void STM32446Tim1_msm(uint8_t bool)
{
	setreg(&TIM1->SMCR, 1, 7, bool);
}
void STM32446Tim1_ts(uint8_t value)
{
	setreg(&TIM1->SMCR, 3, 4, value);
}
void STM32446Tim1_sms(uint8_t value)
{
	setreg(&TIM1->SMCR, 3, 0, value);
}
// DIER
void STM32446Tim1_tde(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 14, bool);
}
void STM32446Tim1_comde(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 14, bool);
}
void STM32446Tim1_cc4de(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 12, bool);
}
void STM32446Tim1_cc3de(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 11, bool);
}
void STM32446Tim1_cc2de(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 10, bool);
}
void STM32446Tim1_cc1de(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 9, bool);
}
void STM32446Tim1_ude(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 8, bool);
}
void STM32446Tim1_bie(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 7, bool);
}
void STM32446Tim1_tie(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 6, bool);
}
void STM32446Tim1_comie(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 5, bool);
}
void STM32446Tim1_cc4ie(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 4, bool);
}
void STM32446Tim1_cc3ie(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 3, bool);
}
void STM32446Tim1_cc2ie(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 2, bool);
}
void STM32446Tim1_cc1ie(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 1, bool);
}
void STM32446Tim1_uie(uint8_t bool)
{
	setreg(&TIM1->DIER, 1, 0, bool);
}
// SR
uint8_t STM32446Tim1_cc4of(void)
{
	return readreg(TIM1->SR, 1, 12);
}
void STM32446Tim1_clear_cc4of(void)
{
	setreg(&TIM1->SR, 1, 12, 0);
}
uint8_t STM32446Tim1_cc3of(void)
{
	return readreg(TIM1->SR, 1, 11);
}
void STM32446Tim1_clear_cc3of(void)
{
	setreg(&TIM1->SR, 1, 11, 0);
}
uint8_t STM32446Tim1_cc2of(void)
{
	return readreg(TIM1->SR, 1, 10);
}
void STM32446Tim1_clear_cc2of(void)
{
	setreg(&TIM1->SR, 1, 10, 0);
}
uint8_t STM32446Tim1_cc1of(void)
{
	return readreg(TIM1->SR, 1, 9);
}
void STM32446Tim1_clear_cc1of(void)
{
	setreg(&TIM1->SR, 1, 9, 0);
}
uint8_t STM32446Tim1_bif(void)
{
	return readreg(TIM1->SR, 1, 7);
}
void STM32446Tim1_clear_bif(void)
{
	setreg(&TIM1->SR, 1, 7, 0);
}
uint8_t STM32446Tim1_tif(void)
{
	return readreg(TIM1->SR, 1, 6);
}
void STM32446Tim1_clear_tif(void)
{
	setreg(&TIM1->SR, 1, 6, 0);
}
uint8_t STM32446Tim1_comif(void)
{
	return readreg(TIM1->SR, 1, 5);
}
void STM32446Tim1_clear_comif(void)
{
	setreg(&TIM1->SR, 1, 5, 0);
}
uint8_t STM32446Tim1_cc4if(void)
{
	return readreg(TIM1->SR, 1, 4);
}
void STM32446Tim1_clear_cc4if(void)
{
	setreg(&TIM1->SR, 1, 4, 0);
}
uint8_t STM32446Tim1_cc3if(void)
{
	return readreg(TIM1->SR, 1, 3);
}
void STM32446Tim1_clear_cc3if(void)
{
	setreg(&TIM1->SR, 1, 3, 0);
}
uint8_t STM32446Tim1_cc2if(void)
{
	return readreg(TIM1->SR, 1, 2);
}
void STM32446Tim1_clear_cc2if(void)
{
	setreg(&TIM1->SR, 1, 2, 0);
}
uint8_t STM32446Tim1_cc1if(void)
{
	return readreg(TIM1->SR, 1, 1);
}
void STM32446Tim1_clear_cc1if(void)
{
	setreg(&TIM1->SR, 1, 1, 0);
}
uint8_t STM32446Tim1_uif(void)
{
	return readreg(TIM1->SR, 1, 0);
}
void STM32446Tim1_clear_uif(void)
{
	setreg(&TIM1->SR, 1, 0, 0);
}
// EGR
void STM32446Tim1_bg(void)
{
	setreg(&TIM1->EGR, 1, 7, 1);
}
void STM32446Tim1_tg(void)
{
	setreg(&TIM1->EGR, 1, 6, 1);
}
void STM32446Tim1_comg(void)
{
	setreg(&TIM1->EGR, 1, 5, 1);
}
void STM32446Tim1_cc4g(void)
{
	setreg(&TIM1->EGR, 1, 4, 1);
}
void STM32446Tim1_cc3g(void)
{
	setreg(&TIM1->EGR, 1, 3, 1);
}
void STM32446Tim1_cc2g(void)
{
	setreg(&TIM1->EGR, 1, 2, 1);
}
void STM32446Tim1_cc1g(void)
{
	setreg(&TIM1->EGR, 1, 1, 1);
}
void STM32446Tim1_ug(void)
{
	setreg(&TIM1->EGR, 1, 0, 1);
}
// CCMR1
void STM32446Tim1_oc2ce(uint8_t value)
{
	setreg(&TIM1->CCMR1, 1, 15, value);
}
void STM32446Tim1_oc2m(uint8_t value)
{
	setreg(&TIM1->CCMR1, 3, 12, value);
}
void STM32446Tim1_ic2f(uint8_t value)
{
	setreg(&TIM1->CCMR1, 4, 12, value);
}
void STM32446Tim1_oc2pe(uint8_t bool)
{
	setreg(&TIM1->CCMR1, 1, 11, bool);
}
void STM32446Tim1_oc2fe(uint8_t bool)
{
	setreg(&TIM1->CCMR1, 1, 10, bool);
}
void STM32446Tim1_ic2psc(uint8_t value)
{
	setreg(&TIM1->CCMR1, 2, 10, value);
}
void STM32446Tim1_cc2s(uint8_t value)
{
	setreg(&TIM1->CCMR1, 2, 8, value);
}
void STM32446Tim1_oc1ce(uint8_t value)
{
	setreg(&TIM1->CCMR1, 1, 7, value);
}
void STM32446Tim1_oc1m(uint8_t value)
{
	setreg(&TIM1->CCMR1, 3, 4, value);
}
void STM32446Tim1_ic1f(uint8_t value)
{
	setreg(&TIM1->CCMR1, 4, 4, value);
}
void STM32446Tim1_oc1pe(uint8_t bool)
{
	setreg(&TIM1->CCMR1, 1, 3, bool);
}
void STM32446Tim1_oc1fe(uint8_t bool)
{
	setreg(&TIM1->CCMR1, 1, 2, bool);
}
void STM32446Tim1_ic1psc(uint8_t value)
{
	setreg(&TIM1->CCMR1, 2, 2, value);
}
void STM32446Tim1_cc1s(uint8_t value)
{
	setreg(&TIM1->CCMR1, 2, 0, value);
}
// CCMR2
void STM32446Tim1_oc4ce(uint8_t value)
{
	setreg(&TIM1->CCMR2, 1, 15, value);
}
void STM32446Tim1_oc4m(uint8_t value)
{
	setreg(&TIM1->CCMR2, 3, 12, value);
}
void STM32446Tim1_ic4f(uint8_t value)
{
	setreg(&TIM1->CCMR2, 4, 12, value);
}
void STM32446Tim1_oc4pe(uint8_t bool)
{
	setreg(&TIM1->CCMR2, 1, 11, bool);
}
void STM32446Tim1_oc4fe(uint8_t bool)
{
	setreg(&TIM1->CCMR2, 1, 10, bool);
}
void STM32446Tim1_ic4psc(uint8_t value)
{
	setreg(&TIM1->CCMR2, 2, 10, value);
}
void STM32446Tim1_cc4s(uint8_t value)
{
	setreg(&TIM1->CCMR2, 2, 8, value);
}
void STM32446Tim1_oc3ce(uint8_t value)
{
	setreg(&TIM1->CCMR2, 1, 7, value);
}
void STM32446Tim1_oc3m(uint8_t value)
{
	setreg(&TIM1->CCMR2, 3, 4, value);
}
void STM32446Tim1_ic3f(uint8_t value)
{
	setreg(&TIM1->CCMR2, 4, 4, value);
}
void STM32446Tim1_oc3pe(uint8_t bool)
{
	setreg(&TIM1->CCMR2, 1, 3, bool);
}
void STM32446Tim1_oc3fe(uint8_t bool)
{
	setreg(&TIM1->CCMR2, 1, 2, bool);
}
void STM32446Tim1_ic3psc(uint8_t value)
{
	setreg(&TIM1->CCMR2, 2, 2, value);
}
void STM32446Tim1_cc3s(uint8_t value)
{
	setreg(&TIM1->CCMR2, 2, 0, value);
}
// CCER
void STM32446Tim1_cc4np(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 15, bool);
}
void STM32446Tim1_cc4p(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 13, bool);
}
void STM32446Tim1_cc4e(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 12, bool);
}
void STM32446Tim1_cc3np(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 11, bool);
}
void STM32446Tim1_cc3ne(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 11, bool);
}
void STM32446Tim1_cc3p(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 9, bool);
}
void STM32446Tim1_cc3e(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 8, bool);
}
void STM32446Tim1_cc2np(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 7, bool);
}
void STM32446Tim1_cc2ne(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 6, bool);
}
void STM32446Tim1_cc2p(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 5, bool);
}
void STM32446Tim1_cc2e(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 4, bool);
}
void STM32446Tim1_cc1np(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 3, bool);
}
void STM32446Tim1_cc1ne(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 2, bool);
}
void STM32446Tim1_cc1p(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 1, bool);
}
void STM32446Tim1_cc1e(uint8_t bool)
{
	setreg(&TIM1->CCER, 1, 0, bool);
}
// CNT
void STM32446Tim1_cnt(uint16_t value)
{
	TIM1->CNT = value;
}
uint16_t STM32446Tim1_get_cnt(void)
{
	return TIM1->CNT;
}
// PSC
void STM32446Tim1_psc(uint16_t value)
{
	TIM1->PSC = value;
}
// ARR
void STM32446Tim1_arr(uint16_t value)
{
	TIM1->ARR = value;
}
// RCR
void STM32446Tim1_rcr(uint8_t value)
{
	TIM1->RCR = value;
}
// CCR1
void STM32446Tim1_ccr1(uint16_t value)
{
	TIM1->CCR1 = value;
}
// CCR2
void STM32446Tim1_ccr2(uint16_t value)
{
	TIM1->CCR2 = value;
}
// CCR3
void STM32446Tim1_ccr3(uint16_t value)
{
	TIM1->CCR3 = value;
}
// CCR4
void STM32446Tim1_ccr4(uint16_t value)
{
	TIM1->CCR4 = value;
}
// BDTR
void STM32446Tim1_moe(uint8_t bool)
{
	setreg(&TIM1->BDTR, 1, 15, bool);
}
void STM32446Tim1_aoe(uint8_t bool)
{
	setreg(&TIM1->BDTR, 1, 14, bool);
}
void STM32446Tim1_bkp(uint8_t bool)
{
	setreg(&TIM1->BDTR, 1, 13, bool);
}
void STM32446Tim1_bke(uint8_t bool)
{
	setreg(&TIM1->BDTR, 1, 12, bool);
}
void STM32446Tim1_ossr(uint8_t bool)
{
	setreg(&TIM1->BDTR, 1, 11, bool);
}
void STM32446Tim1_ossi(uint8_t bool)
{
	setreg(&TIM1->BDTR, 1, 10, bool);
}
void STM32446Tim1_lock(uint8_t value)
{
	setreg(&TIM1->BDTR, 2, 8, value);
}
void STM32446Tim1_dtg(uint8_t value)
{
	setreg(&TIM1->BDTR, 8, 0, value);
}
// DCR
void STM32446Tim1_dbl(uint8_t value)
{
	setreg(&TIM1->DCR, 5, 8, value);
}
void STM32446Tim1_dba(uint8_t value)
{
	setreg(&TIM1->DCR, 5, 0, value);
}
// DMAR
void STM32446Tim1_dmab(uint16_t value)
{
	TIM1->DMAR = value;
}
uint16_t STM32446Tim1_get_dmab(void)
{
	return TIM1->DMAR;
}
/************/
/*** TIM8 ***/
/************/
void STM32446Tim8Clock(uint8_t bool)
{
	if(bool){RCC->APB2ENR |= (1 << 1);}else{RCC->APB2ENR &= ~(1 << 1);}
}
void STM32446Tim8Nvic(uint8_t value)
{ // 43, 44, 45, 46
	switch(value){
		case 0b1000:
			setbit(NVIC->ISER, 1, TIM8_BRK_TIM12_IRQn, 1);
		break;
		case 0b0100:
			setbit(NVIC->ISER, 1, TIM8_UP_TIM13_IRQn, 1);
		break;
		case 0b0010:
			setbit(NVIC->ISER, 1, TIM8_TRG_COM_TIM14_IRQn, 1);
		break;
		case 0b0001:
			setbit(NVIC->ISER, 1, TIM8_CC_IRQn, 1);
		break;
		case 0b11000:
			setbit(NVIC->ICER, 1, TIM8_BRK_TIM12_IRQn, 1);
		break;
		case 0b10100:
			setbit(NVIC->ICER, 1, TIM8_UP_TIM13_IRQn, 1);
		break;
		case 0b10010:
			setbit(NVIC->ICER, 1, TIM8_TRG_COM_TIM14_IRQn, 1);
		break;
		case 0b10001:
			setbit(NVIC->ICER, 1, TIM8_CC_IRQn, 1);
		break;
	default:
	break;
	}
}
/************************/
/*** TIM8 Bit Mapping ***/
/************************/
// CR1
void STM32446Tim8_ckd(uint8_t value)
{
	setreg(&TIM8->CR1, 1, 8, value);
}
uint8_t STM32446Tim8_get_ckd(void)
{
	return readreg(TIM8->CR1, 2, 8);
}
void STM32446Tim8_set_apre(uint8_t bool)
{
	setreg(&TIM8->CR1, 1, 7, bool);
}
void STM32446Tim8_set_cms(uint8_t value)
{
	setreg(&TIM8->CR1, 2, 5, value);
}
void STM32446Tim8_set_dir(uint8_t bool)
{
	setreg(&TIM8->CR1, 1, 4, bool);
}
void STM32446Tim8_set_opm(uint8_t bool)
{
	setreg(&TIM8->CR1, 1, 3, bool);
}
void STM32446Tim8_set_urs(uint8_t bool)
{
	setreg(&TIM8->CR1, 1, 2, bool);
}
void STM32446Tim8_set_udis(uint8_t bool)
{
	setreg(&TIM8->CR1, 1, 1, bool);
}
void STM32446Tim8_cen(uint8_t bool)
{
	setreg(&TIM8->CR1, 1, 0, bool);
}
// CR2
void STM32446Tim8_ois4(uint8_t bool)
{
	setreg(&TIM8->CR2, 1, 14, bool);
}
void STM32446Tim8_ois3n(uint8_t bool)
{
	setreg(&TIM8->CR2, 1, 13, bool);
}
void STM32446Tim8_ois3(uint8_t bool)
{
	setreg(&TIM8->CR2, 1, 12, bool);
}
void STM32446Tim8_ois2n(uint8_t bool)
{
	setreg(&TIM8->CR2, 1, 11, bool);
}
void STM32446Tim8_ois2(uint8_t bool)
{
	setreg(&TIM8->CR2, 1, 10, bool);
}
void STM32446Tim8_ois1n(uint8_t bool)
{
	setreg(&TIM8->CR2, 1, 9, bool);
}
void STM32446Tim8_ois1(uint8_t bool)
{
	setreg(&TIM8->CR2, 1, 8, bool);
}
void STM32446Tim8_ti1s(uint8_t bool)
{
	setreg(&TIM8->CR2, 1, 7, bool);
}
void STM32446Tim8_mms(uint8_t value)
{
	setreg(&TIM8->CR2, 3, 4, value);
}
void STM32446Tim8_ccds(uint8_t bool)
{
	setreg(&TIM8->CR2, 1, 3, bool);
}
void STM32446Tim8_ccus(uint8_t bool)
{
	setreg(&TIM8->CR2, 1, 2, bool);
}
void STM32446Tim8_ccpc(uint8_t bool)
{
	setreg(&TIM8->CR2, 1, 0, bool);
}
// SMCR
void STM32446Tim8_etp(uint8_t bool)
{
	setreg(&TIM8->SMCR, 1, 15, bool);
}
void STM32446Tim8_ece(uint8_t bool)
{
	setreg(&TIM8->SMCR, 1, 14, bool);
}
void STM32446Tim8_etps(uint8_t value)
{
	setreg(&TIM8->SMCR, 2, 12, value);
}
void STM32446Tim8_etf(uint8_t value)
{
	setreg(&TIM8->SMCR, 4, 8, value);
}
void STM32446Tim8_msm(uint8_t bool)
{
	setreg(&TIM8->SMCR, 1, 7, bool);
}
void STM32446Tim8_ts(uint8_t value)
{
	setreg(&TIM8->SMCR, 3, 4, value);
}
void STM32446Tim8_sms(uint8_t value)
{
	setreg(&TIM8->SMCR, 3, 0, value);
}
// DIER
void STM32446Tim8_tde(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 14, bool);
}
void STM32446Tim8_comde(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 14, bool);
}
void STM32446Tim8_cc4de(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 12, bool);
}
void STM32446Tim8_cc3de(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 11, bool);
}
void STM32446Tim8_cc2de(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 10, bool);
}
void STM32446Tim8_cc1de(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 9, bool);
}
void STM32446Tim8_ude(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 8, bool);
}
void STM32446Tim8_bie(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 7, bool);
}
void STM32446Tim8_tie(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 6, bool);
}
void STM32446Tim8_comie(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 5, bool);
}
void STM32446Tim8_cc4ie(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 4, bool);
}
void STM32446Tim8_cc3ie(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 3, bool);
}
void STM32446Tim8_cc2ie(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 2, bool);
}
void STM32446Tim8_cc1ie(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 1, bool);
}
void STM32446Tim8_uie(uint8_t bool)
{
	setreg(&TIM8->DIER, 1, 0, bool);
}
// SR
uint8_t STM32446Tim8_cc4of(void)
{
	return readreg(TIM8->SR, 1, 12);
}
void STM32446Tim8_clear_cc4of(void)
{
	setreg(&TIM8->SR, 1, 12, 0);
}
uint8_t STM32446Tim8_cc3of(void)
{
	return readreg(TIM8->SR, 1, 11);
}
void STM32446Tim8_clear_cc3of(void)
{
	setreg(&TIM8->SR, 1, 11, 0);
}
uint8_t STM32446Tim8_cc2of(void)
{
	return readreg(TIM8->SR, 1, 10);
}
void STM32446Tim8_clear_cc2of(void)
{
	setreg(&TIM8->SR, 1, 10, 0);
}
uint8_t STM32446Tim8_cc1of(void)
{
	return readreg(TIM8->SR, 1, 9);
}
void STM32446Tim8_clear_cc1of(void)
{
	setreg(&TIM8->SR, 1, 9, 0);
}
uint8_t STM32446Tim8_bif(void)
{
	return readreg(TIM8->SR, 1, 7);
}
void STM32446Tim8_clear_bif(void)
{
	setreg(&TIM8->SR, 1, 7, 0);
}
uint8_t STM32446Tim8_tif(void)
{
	return readreg(TIM8->SR, 1, 6);
}
void STM32446Tim8_clear_tif(void)
{
	setreg(&TIM8->SR, 1, 6, 0);
}
uint8_t STM32446Tim8_comif(void)
{
	return readreg(TIM8->SR, 1, 5);
}
void STM32446Tim8_clear_comif(void)
{
	setreg(&TIM8->SR, 1, 5, 0);
}
uint8_t STM32446Tim8_cc4if(void)
{
	return readreg(TIM8->SR, 1, 4);
}
void STM32446Tim8_clear_cc4if(void)
{
	setreg(&TIM8->SR, 1, 4, 0);
}
uint8_t STM32446Tim8_cc3if(void)
{
	return readreg(TIM8->SR, 1, 3);
}
void STM32446Tim8_clear_cc3if(void)
{
	setreg(&TIM8->SR, 1, 3, 0);
}
uint8_t STM32446Tim8_cc2if(void)
{
	return readreg(TIM8->SR, 1, 2);
}
void STM32446Tim8_clear_cc2if(void)
{
	setreg(&TIM8->SR, 1, 2, 0);
}
uint8_t STM32446Tim8_cc1if(void)
{
	return readreg(TIM8->SR, 1, 1);
}
void STM32446Tim8_clear_cc1if(void)
{
	setreg(&TIM8->SR, 1, 1, 0);
}
uint8_t STM32446Tim8_uif(void)
{
	return readreg(TIM8->SR, 1, 0);
}
void STM32446Tim8_clear_uif(void)
{
	setreg(&TIM8->SR, 1, 0, 0);
}
// EGR
void STM32446Tim8_bg(void)
{
	setreg(&TIM8->EGR, 1, 7, 1);
}
void STM32446Tim8_tg(void)
{
	setreg(&TIM8->EGR, 1, 6, 1);
}
void STM32446Tim8_comg(void)
{
	setreg(&TIM8->EGR, 1, 5, 1);
}
void STM32446Tim8_cc4g(void)
{
	setreg(&TIM8->EGR, 1, 4, 1);
}
void STM32446Tim8_cc3g(void)
{
	setreg(&TIM8->EGR, 1, 3, 1);
}
void STM32446Tim8_cc2g(void)
{
	setreg(&TIM8->EGR, 1, 2, 1);
}
void STM32446Tim8_cc1g(void)
{
	setreg(&TIM8->EGR, 1, 1, 1);
}
void STM32446Tim8_ug(void)
{
	setreg(&TIM8->EGR, 1, 0, 1);
}
// CCMR1
void STM32446Tim8_oc2ce(uint8_t value)
{
	setreg(&TIM8->CCMR1, 1, 15, value);
}
void STM32446Tim8_oc2m(uint8_t value)
{
	setreg(&TIM8->CCMR1, 3, 12, value);
}
void STM32446Tim8_ic2f(uint8_t value)
{
	setreg(&TIM8->CCMR1, 4, 12, value);
}
void STM32446Tim8_oc2pe(uint8_t bool)
{
	setreg(&TIM8->CCMR1, 1, 11, bool);
}
void STM32446Tim8_oc2fe(uint8_t bool)
{
	setreg(&TIM8->CCMR1, 1, 10, bool);
}
void STM32446Tim8_ic2psc(uint8_t value)
{
	setreg(&TIM8->CCMR1, 2, 10, value);
}
void STM32446Tim8_cc2s(uint8_t value)
{
	setreg(&TIM8->CCMR1, 2, 8, value);
}
void STM32446Tim8_oc1ce(uint8_t value)
{
	setreg(&TIM8->CCMR1, 1, 7, value);
}
void STM32446Tim8_oc1m(uint8_t value)
{
	setreg(&TIM8->CCMR1, 3, 4, value);
}
void STM32446Tim8_ic1f(uint8_t value)
{
	setreg(&TIM8->CCMR1, 4, 4, value);
}
void STM32446Tim8_oc1pe(uint8_t bool)
{
	setreg(&TIM8->CCMR1, 1, 3, bool);
}
void STM32446Tim8_oc1fe(uint8_t bool)
{
	setreg(&TIM8->CCMR1, 1, 2, bool);
}
void STM32446Tim8_ic1psc(uint8_t value)
{
	setreg(&TIM8->CCMR1, 2, 2, value);
}
void STM32446Tim8_cc1s(uint8_t value)
{
	setreg(&TIM8->CCMR1, 2, 0, value);
}
// CCMR2
void STM32446Tim8_oc4ce(uint8_t value)
{
	setreg(&TIM8->CCMR2, 1, 15, value);
}
void STM32446Tim8_oc4m(uint8_t value)
{
	setreg(&TIM8->CCMR2, 3, 12, value);
}
void STM32446Tim8_ic4f(uint8_t value)
{
	setreg(&TIM8->CCMR2, 4, 12, value);
}
void STM32446Tim8_oc4pe(uint8_t bool)
{
	setreg(&TIM8->CCMR2, 1, 11, bool);
}
void STM32446Tim8_oc4fe(uint8_t bool)
{
	setreg(&TIM8->CCMR2, 1, 10, bool);
}
void STM32446Tim8_ic4psc(uint8_t value)
{
	setreg(&TIM8->CCMR2, 2, 10, value);
}
void STM32446Tim8_cc4s(uint8_t value)
{
	setreg(&TIM8->CCMR2, 2, 8, value);
}
void STM32446Tim8_oc3ce(uint8_t value)
{
	setreg(&TIM8->CCMR2, 1, 7, value);
}
void STM32446Tim8_oc3m(uint8_t value)
{
	setreg(&TIM8->CCMR2, 3, 4, value);
}
void STM32446Tim8_ic3f(uint8_t value)
{
	setreg(&TIM8->CCMR2, 4, 4, value);
}
void STM32446Tim8_oc3pe(uint8_t bool)
{
	setreg(&TIM8->CCMR2, 1, 3, bool);
}
void STM32446Tim8_oc3fe(uint8_t bool)
{
	setreg(&TIM8->CCMR2, 1, 2, bool);
}
void STM32446Tim8_ic3psc(uint8_t value)
{
	setreg(&TIM8->CCMR2, 2, 2, value);
}
void STM32446Tim8_cc3s(uint8_t value)
{
	setreg(&TIM8->CCMR2, 2, 0, value);
}
// CCER
void STM32446Tim8_cc4np(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 15, bool);
}
void STM32446Tim8_cc4p(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 13, bool);
}
void STM32446Tim8_cc4e(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 12, bool);
}
void STM32446Tim8_cc3np(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 11, bool);
}
void STM32446Tim8_cc3ne(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 11, bool);
}
void STM32446Tim8_cc3p(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 9, bool);
}
void STM32446Tim8_cc3e(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 8, bool);
}
void STM32446Tim8_cc2np(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 7, bool);
}
void STM32446Tim8_cc2ne(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 6, bool);
}
void STM32446Tim8_cc2p(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 5, bool);
}
void STM32446Tim8_cc2e(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 4, bool);
}
void STM32446Tim8_cc1np(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 3, bool);
}
void STM32446Tim8_cc1ne(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 2, bool);
}
void STM32446Tim8_cc1p(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 1, bool);
}
void STM32446Tim8_cc1e(uint8_t bool)
{
	setreg(&TIM8->CCER, 1, 0, bool);
}
// CNT
void STM32446Tim8_cnt(uint16_t value)
{
	TIM8->CNT = value;
}
uint16_t STM32446Tim8_get_cnt(void)
{
	return TIM8->CNT;
}
// PSC
void STM32446Tim8_psc(uint16_t value)
{
	TIM8->PSC = value;
}
// ARR
void STM32446Tim8_arr(uint16_t value)
{
	TIM8->ARR = value;
}
// RCR
void STM32446Tim8_rcr(uint8_t value)
{
	TIM8->RCR = value;
}
// CCR1
void STM32446Tim8_ccr1(uint16_t value)
{
	TIM8->CCR1 = value;
}
// CCR2
void STM32446Tim8_ccr2(uint16_t value)
{
	TIM8->CCR2 = value;
}
// CCR3
void STM32446Tim8_ccr3(uint16_t value)
{
	TIM8->CCR3 = value;
}
// CCR4
void STM32446Tim8_ccr4(uint16_t value)
{
	TIM8->CCR4 = value;
}
// BDTR
void STM32446Tim8_moe(uint8_t bool)
{
	setreg(&TIM8->BDTR, 1, 15, bool);
}
void STM32446Tim8_aoe(uint8_t bool)
{
	setreg(&TIM8->BDTR, 1, 14, bool);
}
void STM32446Tim8_bkp(uint8_t bool)
{
	setreg(&TIM8->BDTR, 1, 13, bool);
}
void STM32446Tim8_bke(uint8_t bool)
{
	setreg(&TIM8->BDTR, 1, 12, bool);
}
void STM32446Tim8_ossr(uint8_t bool)
{
	setreg(&TIM8->BDTR, 1, 11, bool);
}
void STM32446Tim8_ossi(uint8_t bool)
{
	setreg(&TIM8->BDTR, 1, 10, bool);
}
void STM32446Tim8_lock(uint8_t value)
{
	setreg(&TIM8->BDTR, 2, 8, value);
}
void STM32446Tim8_dtg(uint8_t value)
{
	setreg(&TIM8->BDTR, 8, 0, value);
}
// DCR
void STM32446Tim8_dbl(uint8_t value)
{
	setreg(&TIM8->DCR, 5, 8, value);
}
void STM32446Tim8_dba(uint8_t value)
{
	setreg(&TIM8->DCR, 5, 0, value);
}
// DMAR
void STM32446Tim8_dmab(uint16_t value)
{
	TIM8->DMAR = value;
}
uint16_t STM32446Tim8_get_dmab(void)
{
	return TIM8->DMAR;
}
/********************************************/
/*** INIC Procedure & Function Definition ***/
/********************************************/
/*** TIM1 Auxiliar ***/
STM32446TIM1_CR1* stm32446_tim1_cr1_inic(void)
{

	// CR1
	stm32446_tim1_cr1.ckd = STM32446Tim1_ckd;
	stm32446_tim1_cr1.get_ckd = STM32446Tim1_get_ckd;
	stm32446_tim1_cr1.apre = STM32446Tim1_set_apre;
	stm32446_tim1_cr1.cms = STM32446Tim1_set_cms;
	stm32446_tim1_cr1.dir = STM32446Tim1_set_dir;
	stm32446_tim1_cr1.opm = STM32446Tim1_set_opm;
	stm32446_tim1_cr1.urs = STM32446Tim1_set_urs;
	stm32446_tim1_cr1.udis = STM32446Tim1_set_udis;
	stm32446_tim1_cr1.cen = STM32446Tim1_cen;
	return &stm32446_tim1_cr1;
}
STM32446TIM1_CR2* stm32446_tim1_cr2_inic(void)
{

	// CR2
	stm32446_tim1_cr2.ois4 = STM32446Tim1_ois4;
	stm32446_tim1_cr2.ois3n = STM32446Tim1_ois3n;
	stm32446_tim1_cr2.ois3 = STM32446Tim1_ois3;
	stm32446_tim1_cr2.ois2n = STM32446Tim1_ois2n;
	stm32446_tim1_cr2.ois1 = STM32446Tim1_ois1;
	stm32446_tim1_cr2.ti1s = STM32446Tim1_ti1s;
	stm32446_tim1_cr2.mms = STM32446Tim1_mms;
	stm32446_tim1_cr2.ccds = STM32446Tim1_ccds;
	stm32446_tim1_cr2.ccus = STM32446Tim1_ccus;
	stm32446_tim1_cr2.ccpc = STM32446Tim1_ccpc;
	return &stm32446_tim1_cr2;
}
STM32446TIM1_SMCR* stm32446_tim1_smcr_inic(void)
{

	// SMCR
	stm32446_tim1_smcr.etp = STM32446Tim1_etp;
	stm32446_tim1_smcr.ece = STM32446Tim1_ece;
	stm32446_tim1_smcr.etps = STM32446Tim1_etps;
	stm32446_tim1_smcr.etf = STM32446Tim1_etf;
	stm32446_tim1_smcr.msm = STM32446Tim1_msm;
	stm32446_tim1_smcr.ts = STM32446Tim1_ts;
	stm32446_tim1_smcr.sms = STM32446Tim1_sms;
	return &stm32446_tim1_smcr;
}
STM32446TIM1_DIER* stm32446_tim1_dier_inic(void)
{

	// DIER
	stm32446_tim1_dier.tde = STM32446Tim1_tde;
	stm32446_tim1_dier.cc4de = STM32446Tim1_cc4de;
	stm32446_tim1_dier.cc3de = STM32446Tim1_cc3de;
	stm32446_tim1_dier.cc2de = STM32446Tim1_cc2de;
	stm32446_tim1_dier.cc1de = STM32446Tim1_cc1de;
	stm32446_tim1_dier.ude = STM32446Tim1_ude;
	stm32446_tim1_dier.bie = STM32446Tim1_bie;
	stm32446_tim1_dier.tie = STM32446Tim1_tie;
	stm32446_tim1_dier.comie = STM32446Tim1_comie;
	stm32446_tim1_dier.cc4ie = STM32446Tim1_cc4ie;
	stm32446_tim1_dier.cc3ie = STM32446Tim1_cc3ie;
	stm32446_tim1_dier.cc2ie = STM32446Tim1_cc2ie;
	stm32446_tim1_dier.cc1ie = STM32446Tim1_cc1ie;
	stm32446_tim1_dier.uie = STM32446Tim1_uie;
	return &stm32446_tim1_dier;
}
STM32446TIM1_SR* stm32446_tim1_sr_inic(void)
{

	// SR
	stm32446_tim1_sr.cc4of = STM32446Tim1_cc4of;
	stm32446_tim1_sr.clear_cc4of = STM32446Tim1_clear_cc4of;
	stm32446_tim1_sr.cc3of = STM32446Tim1_cc3of;
	stm32446_tim1_sr.clear_cc3of = STM32446Tim1_clear_cc3of;
	stm32446_tim1_sr.cc2of = STM32446Tim1_cc2of;
	stm32446_tim1_sr.clear_cc2of = STM32446Tim1_clear_cc2of;
	stm32446_tim1_sr.cc1of = STM32446Tim1_cc1of;
	stm32446_tim1_sr.clear_cc1of = STM32446Tim1_clear_cc1of;
	stm32446_tim1_sr.bif = STM32446Tim1_bif;
	stm32446_tim1_sr.clear_bif = STM32446Tim1_clear_bif;
	stm32446_tim1_sr.tif = STM32446Tim1_tif;
	stm32446_tim1_sr.clear_tif = STM32446Tim1_clear_tif;
	stm32446_tim1_sr.comif = STM32446Tim1_comif;
	stm32446_tim1_sr.clear_comif = STM32446Tim1_clear_comif;
	stm32446_tim1_sr.cc4if = STM32446Tim1_cc4if;
	stm32446_tim1_sr.clear_cc4if = STM32446Tim1_clear_cc4if;
	stm32446_tim1_sr.cc3if = STM32446Tim1_cc3if;
	stm32446_tim1_sr.clear_cc3if = STM32446Tim1_clear_cc3if;
	stm32446_tim1_sr.cc2if = STM32446Tim1_cc2if;
	stm32446_tim1_sr.clear_cc2if = STM32446Tim1_clear_cc2if;
	stm32446_tim1_sr.cc1if = STM32446Tim1_cc1if;
	stm32446_tim1_sr.clear_cc1if = STM32446Tim1_clear_cc1if;
	stm32446_tim1_sr.uif = STM32446Tim1_uif;
	stm32446_tim1_sr.clear_uif = STM32446Tim1_clear_uif;
	return &stm32446_tim1_sr;
}
STM32446TIM1_EGR* stm32446_tim1_egr_inic(void)
{

	// EGR
	stm32446_tim1_egr.tg = STM32446Tim1_tg;
	stm32446_tim1_egr.cc4g = STM32446Tim1_cc4g;
	stm32446_tim1_egr.cc3g = STM32446Tim1_cc3g;
	stm32446_tim1_egr.cc2g = STM32446Tim1_cc2g;
	stm32446_tim1_egr.cc1g = STM32446Tim1_cc1g;
	stm32446_tim1_egr.ug = STM32446Tim1_ug;
	return &stm32446_tim1_egr;
}
STM32446TIM1_CCMR1* stm32446_tim1_ccmr1_inic(void)
{

	// CCMR1
	stm32446_tim1_ccmr1.oc2ce = STM32446Tim1_oc2ce;
	stm32446_tim1_ccmr1.oc2m = STM32446Tim1_oc2m;
	stm32446_tim1_ccmr1.ic2f = STM32446Tim1_ic2f;
	stm32446_tim1_ccmr1.oc2pe = STM32446Tim1_oc2pe;
	stm32446_tim1_ccmr1.oc2fe = STM32446Tim1_oc2fe;
	stm32446_tim1_ccmr1.ic2psc = STM32446Tim1_ic2psc;
	stm32446_tim1_ccmr1.cc2s = STM32446Tim1_cc2s;
	stm32446_tim1_ccmr1.oc1ce = STM32446Tim1_oc1ce;
	stm32446_tim1_ccmr1.oc1m = STM32446Tim1_oc1m;
	stm32446_tim1_ccmr1.ic1f = STM32446Tim1_ic1f;
	stm32446_tim1_ccmr1.oc1pe = STM32446Tim1_oc1pe;
	stm32446_tim1_ccmr1.oc1fe = STM32446Tim1_oc1fe;
	stm32446_tim1_ccmr1.ic1psc = STM32446Tim1_ic1psc;
	stm32446_tim1_ccmr1.cc1s = STM32446Tim1_cc1s;
	return &stm32446_tim1_ccmr1;
}
STM32446TIM1_CCMR2* stm32446_tim1_ccmr2_inic(void)
{

	// CCMR2
	stm32446_tim1_ccmr2.oc4ce = STM32446Tim1_oc4ce;
	stm32446_tim1_ccmr2.oc4m = STM32446Tim1_oc4m;
	stm32446_tim1_ccmr2.ic4f = STM32446Tim1_ic4f;
	stm32446_tim1_ccmr2.oc4pe = STM32446Tim1_oc4pe;
	stm32446_tim1_ccmr2.oc4fe = STM32446Tim1_oc4fe;
	stm32446_tim1_ccmr2.ic4psc = STM32446Tim1_ic4psc;
	stm32446_tim1_ccmr2.cc4s = STM32446Tim1_cc4s;
	stm32446_tim1_ccmr2.oc3ce = STM32446Tim1_oc3ce;
	stm32446_tim1_ccmr2.oc3m = STM32446Tim1_oc3m;
	stm32446_tim1_ccmr2.ic3f = STM32446Tim1_ic3f;
	stm32446_tim1_ccmr2.oc3pe = STM32446Tim1_oc3pe;
	stm32446_tim1_ccmr2.oc3fe = STM32446Tim1_oc3fe;
	stm32446_tim1_ccmr2.ic3psc = STM32446Tim1_ic3psc;
	stm32446_tim1_ccmr2.cc3s = STM32446Tim1_cc3s;
	return &stm32446_tim1_ccmr2;
}
STM32446TIM1_CCER* stm32446_tim1_ccer_inic(void)
{

	// CCER
	stm32446_tim1_ccer.cc4p = STM32446Tim1_cc4p;
	stm32446_tim1_ccer.cc4e = STM32446Tim1_cc4e;
	stm32446_tim1_ccer.cc3np = STM32446Tim1_cc3np;
	stm32446_tim1_ccer.cc3ne = STM32446Tim1_cc3ne;
	stm32446_tim1_ccer.cc3p = STM32446Tim1_cc3p;
	stm32446_tim1_ccer.cc3e = STM32446Tim1_cc3e;
	stm32446_tim1_ccer.cc2np = STM32446Tim1_cc2np;
	stm32446_tim1_ccer.cc2ne = STM32446Tim1_cc2ne;
	stm32446_tim1_ccer.cc2p = STM32446Tim1_cc2p;
	stm32446_tim1_ccer.cc2e = STM32446Tim1_cc2e;
	stm32446_tim1_ccer.cc1np = STM32446Tim1_cc1np;
	stm32446_tim1_ccer.cc1ne = STM32446Tim1_cc1ne;
	stm32446_tim1_ccer.cc1p = STM32446Tim1_cc1p;
	stm32446_tim1_ccer.cc1e = STM32446Tim1_cc1e;
	return &stm32446_tim1_ccer;
}
STM32446TIM1_BDTR* stm32446_tim1_bdtr_inic(void)
{

	// CCER
	stm32446_tim1_bdtr.moe = STM32446Tim1_moe;
	stm32446_tim1_bdtr.aoe = STM32446Tim1_aoe;
	stm32446_tim1_bdtr.bkp = STM32446Tim1_bkp;
	stm32446_tim1_bdtr.bke = STM32446Tim1_bke;
	stm32446_tim1_bdtr.ossr = STM32446Tim1_ossr;
	stm32446_tim1_bdtr.ossi = STM32446Tim1_ossi;
	stm32446_tim1_bdtr.lock = STM32446Tim1_lock;
	stm32446_tim1_bdtr.dtg = STM32446Tim1_dtg;
	return &stm32446_tim1_bdtr;
}
STM32446TIM1_DCR* stm32446_tim1_dcr_inic(void)
{

	// CCER
	stm32446_tim1_dcr.dbl = STM32446Tim1_dbl;
	stm32446_tim1_dcr.dba = STM32446Tim1_dba;
	return &stm32446_tim1_dcr;
}
/*** TIM1 INIC Procedure & Function Definition ***/
STM32446TIM1obj tim1_enable(void)
{


	// CLOCK
	stm32446_tim1.clock = STM32446Tim1Clock;
	// NVIC
	stm32446_tim1.nvic = STM32446Tim1Nvic;
	/*** TIM1 Bit Mapping Link ***/
	stm32446_tim1.cr1 = stm32446_tim1_cr1_inic();
	stm32446_tim1.cr2 = stm32446_tim1_cr2_inic();
	stm32446_tim1.smcr = stm32446_tim1_smcr_inic();
	stm32446_tim1.dier = stm32446_tim1_dier_inic();
	stm32446_tim1.sr = stm32446_tim1_sr_inic();
	stm32446_tim1.egr = stm32446_tim1_egr_inic();
	stm32446_tim1.ccmr1 = stm32446_tim1_ccmr1_inic();
	stm32446_tim1.ccmr2 = stm32446_tim1_ccmr2_inic();
	stm32446_tim1.ccer = stm32446_tim1_ccer_inic();
	stm32446_tim1.bdtr = stm32446_tim1_bdtr_inic();
	stm32446_tim1.dcr = stm32446_tim1_dcr_inic();
	stm32446_tim1.cnt = STM32446Tim1_cnt;
	stm32446_tim1.get_cnt = STM32446Tim1_get_cnt;
	stm32446_tim1.psc = STM32446Tim1_psc;
	stm32446_tim1.arr = STM32446Tim1_arr;
	stm32446_tim1.rep = STM32446Tim1_rcr;
	stm32446_tim1.ccr1 = STM32446Tim1_ccr1;
	stm32446_tim1.ccr2 = STM32446Tim1_ccr2;
	stm32446_tim1.ccr3 = STM32446Tim1_ccr3;
	stm32446_tim1.ccr4 = STM32446Tim1_ccr4;
	stm32446_tim1.dmar = STM32446Tim1_dmab;
	return stm32446_tim1;
}

STM32446TIM1obj* tim1(void){ return (STM32446TIM1obj*) &stm32446_tim1;}

/*** TIM8 Auxiliar ***/
STM32446TIM8_CR1* stm32446_tim8_cr1_inic(void)
{

	// CR1
	stm32446_tim8_cr1.get_ckd = STM32446Tim8_get_ckd;
	stm32446_tim8_cr1.apre = STM32446Tim8_set_apre;
	stm32446_tim8_cr1.cms = STM32446Tim8_set_cms;
	stm32446_tim8_cr1.dir = STM32446Tim8_set_dir;
	stm32446_tim8_cr1.opm = STM32446Tim8_set_opm;
	stm32446_tim8_cr1.urs = STM32446Tim8_set_urs;
	stm32446_tim8_cr1.udis = STM32446Tim8_set_udis;
	stm32446_tim8_cr1.cen = STM32446Tim8_cen;
	return &stm32446_tim8_cr1;
}
STM32446TIM8_CR2* stm32446_tim8_cr2_inic(void)
{

	// CR2
	stm32446_tim8_cr2.ois4 = STM32446Tim8_ois4;
	stm32446_tim8_cr2.ois3n = STM32446Tim8_ois3n;
	stm32446_tim8_cr2.ois3 = STM32446Tim8_ois3;
	stm32446_tim8_cr2.ois2n = STM32446Tim8_ois2n;
	stm32446_tim8_cr2.ois1 = STM32446Tim8_ois1;
	stm32446_tim8_cr2.ti1s = STM32446Tim8_ti1s;
	stm32446_tim8_cr2.mms = STM32446Tim8_mms;
	stm32446_tim8_cr2.ccds = STM32446Tim8_ccds;
	stm32446_tim8_cr2.ccus = STM32446Tim8_ccus;
	stm32446_tim8_cr2.ccpc = STM32446Tim8_ccpc;
	return &stm32446_tim8_cr2;
}
STM32446TIM8_SMCR* stm32446_tim8_smcr_inic(void)
{

	// SMCR
	stm32446_tim8_smcr.etp = STM32446Tim8_etp;
	stm32446_tim8_smcr.ece = STM32446Tim8_ece;
	stm32446_tim8_smcr.etps = STM32446Tim8_etps;
	stm32446_tim8_smcr.etf = STM32446Tim8_etf;
	stm32446_tim8_smcr.msm = STM32446Tim8_msm;
	stm32446_tim8_smcr.ts = STM32446Tim8_ts;
	stm32446_tim8_smcr.sms = STM32446Tim8_sms;
	return &stm32446_tim8_smcr;
}
STM32446TIM8_DIER* stm32446_tim8_dier_inic(void)
{

	// DIER
	stm32446_tim8_dier.tde = STM32446Tim8_tde;
	stm32446_tim8_dier.cc4de = STM32446Tim8_cc4de;
	stm32446_tim8_dier.cc3de = STM32446Tim8_cc3de;
	stm32446_tim8_dier.cc2de = STM32446Tim8_cc2de;
	stm32446_tim8_dier.cc1de = STM32446Tim8_cc1de;
	stm32446_tim8_dier.ude = STM32446Tim8_ude;
	stm32446_tim8_dier.bie = STM32446Tim8_bie;
	stm32446_tim8_dier.tie = STM32446Tim8_tie;
	stm32446_tim8_dier.comie = STM32446Tim8_comie;
	stm32446_tim8_dier.cc4ie = STM32446Tim8_cc4ie;
	stm32446_tim8_dier.cc3ie = STM32446Tim8_cc3ie;
	stm32446_tim8_dier.cc2ie = STM32446Tim8_cc2ie;
	stm32446_tim8_dier.cc1ie = STM32446Tim8_cc1ie;
	stm32446_tim8_dier.uie = STM32446Tim8_uie;
	return &stm32446_tim8_dier;
}
STM32446TIM8_SR* stm32446_tim8_sr_inic(void)
{

	// SR
	stm32446_tim8_sr.cc4of = STM32446Tim8_cc4of;
	stm32446_tim8_sr.clear_cc4of = STM32446Tim8_clear_cc4of;
	stm32446_tim8_sr.cc3of = STM32446Tim8_cc3of;
	stm32446_tim8_sr.clear_cc3of = STM32446Tim8_clear_cc3of;
	stm32446_tim8_sr.cc2of = STM32446Tim8_cc2of;
	stm32446_tim8_sr.clear_cc2of = STM32446Tim8_clear_cc2of;
	stm32446_tim8_sr.cc1of = STM32446Tim8_cc1of;
	stm32446_tim8_sr.clear_cc1of = STM32446Tim8_clear_cc1of;
	stm32446_tim8_sr.bif = STM32446Tim8_bif;
	stm32446_tim8_sr.clear_bif = STM32446Tim8_clear_bif;
	stm32446_tim8_sr.tif = STM32446Tim8_tif;
	stm32446_tim8_sr.clear_tif = STM32446Tim8_clear_tif;
	stm32446_tim8_sr.comif = STM32446Tim8_comif;
	stm32446_tim8_sr.clear_comif = STM32446Tim8_clear_comif;
	stm32446_tim8_sr.cc4if = STM32446Tim8_cc4if;
	stm32446_tim8_sr.clear_cc4if = STM32446Tim8_clear_cc4if;
	stm32446_tim8_sr.cc3if = STM32446Tim8_cc3if;
	stm32446_tim8_sr.clear_cc3if = STM32446Tim8_clear_cc3if;
	stm32446_tim8_sr.cc2if = STM32446Tim8_cc2if;
	stm32446_tim8_sr.clear_cc2if = STM32446Tim8_clear_cc2if;
	stm32446_tim8_sr.cc1if = STM32446Tim8_cc1if;
	stm32446_tim8_sr.clear_cc1if = STM32446Tim8_clear_cc1if;
	stm32446_tim8_sr.uif = STM32446Tim8_uif;
	stm32446_tim8_sr.clear_uif = STM32446Tim8_clear_uif;
	return &stm32446_tim8_sr;
}
STM32446TIM8_EGR* stm32446_tim8_egr_inic(void)
{

	// EGR
	stm32446_tim8_egr.bg = STM32446Tim8_bg;
	stm32446_tim8_egr.tg = STM32446Tim8_tg;
	stm32446_tim8_egr.cc4g = STM32446Tim8_cc4g;
	stm32446_tim8_egr.cc3g = STM32446Tim8_cc3g;
	stm32446_tim8_egr.cc2g = STM32446Tim8_cc2g;
	stm32446_tim8_egr.cc1g = STM32446Tim8_cc1g;
	stm32446_tim8_egr.ug = STM32446Tim8_ug;
	return &stm32446_tim8_egr;
}
STM32446TIM8_CCMR1* stm32446_tim8_ccmr1_inic(void)
{

	// CCMR1
	stm32446_tim8_ccmr1.oc2ce = STM32446Tim8_oc2ce;
	stm32446_tim8_ccmr1.oc2m = STM32446Tim8_oc2m;
	stm32446_tim8_ccmr1.ic2f = STM32446Tim8_ic2f;
	stm32446_tim8_ccmr1.oc2pe = STM32446Tim8_oc2pe;
	stm32446_tim8_ccmr1.oc2fe = STM32446Tim8_oc2fe;
	stm32446_tim8_ccmr1.ic2psc = STM32446Tim8_ic2psc;
	stm32446_tim8_ccmr1.cc2s = STM32446Tim8_cc2s;
	stm32446_tim8_ccmr1.oc1ce = STM32446Tim8_oc1ce;
	stm32446_tim8_ccmr1.oc1m = STM32446Tim8_oc1m;
	stm32446_tim8_ccmr1.ic1f = STM32446Tim8_ic1f;
	stm32446_tim8_ccmr1.oc1pe = STM32446Tim8_oc1pe;
	stm32446_tim8_ccmr1.oc1fe = STM32446Tim8_oc1fe;
	stm32446_tim8_ccmr1.ic1psc = STM32446Tim8_ic1psc;
	stm32446_tim8_ccmr1.cc1s = STM32446Tim8_cc1s;
	return &stm32446_tim8_ccmr1;
}
STM32446TIM8_CCMR2* stm32446_tim8_ccmr2_inic(void)
{

	// CCMR2
	stm32446_tim8_ccmr2.oc4ce = STM32446Tim8_oc4ce;
	stm32446_tim8_ccmr2.oc4m = STM32446Tim8_oc4m;
	stm32446_tim8_ccmr2.ic4f = STM32446Tim8_ic4f;
	stm32446_tim8_ccmr2.oc4pe = STM32446Tim8_oc4pe;
	stm32446_tim8_ccmr2.oc4fe = STM32446Tim8_oc4fe;
	stm32446_tim8_ccmr2.ic4psc = STM32446Tim8_ic4psc;
	stm32446_tim8_ccmr2.cc4s = STM32446Tim8_cc4s;
	stm32446_tim8_ccmr2.oc3ce = STM32446Tim8_oc3ce;
	stm32446_tim8_ccmr2.oc3m = STM32446Tim8_oc3m;
	stm32446_tim8_ccmr2.ic3f = STM32446Tim8_ic3f;
	stm32446_tim8_ccmr2.oc3pe = STM32446Tim8_oc3pe;
	stm32446_tim8_ccmr2.oc3fe = STM32446Tim8_oc3fe;
	stm32446_tim8_ccmr2.ic3psc = STM32446Tim8_ic3psc;
	stm32446_tim8_ccmr2.cc3s = STM32446Tim8_cc3s;
	return &stm32446_tim8_ccmr2;
}
STM32446TIM8_CCER* stm32446_tim8_ccer_inic(void)
{

	// CCER
	stm32446_tim8_ccer.cc4p = STM32446Tim8_cc4p;
	stm32446_tim8_ccer.cc4e = STM32446Tim8_cc4e;
	stm32446_tim8_ccer.cc3np = STM32446Tim8_cc3np;
	stm32446_tim8_ccer.cc3ne = STM32446Tim8_cc3ne;
	stm32446_tim8_ccer.cc3p = STM32446Tim8_cc3p;
	stm32446_tim8_ccer.cc3e = STM32446Tim8_cc3e;
	stm32446_tim8_ccer.cc2np = STM32446Tim8_cc2np;
	stm32446_tim8_ccer.cc2ne = STM32446Tim8_cc2ne;
	stm32446_tim8_ccer.cc2p = STM32446Tim8_cc2p;
	stm32446_tim8_ccer.cc2e = STM32446Tim8_cc2e;
	stm32446_tim8_ccer.cc1np = STM32446Tim8_cc1np;
	stm32446_tim8_ccer.cc1ne = STM32446Tim8_cc1ne;
	stm32446_tim8_ccer.cc1p = STM32446Tim8_cc1p;
	stm32446_tim8_ccer.cc1e = STM32446Tim8_cc1e;
	return &stm32446_tim8_ccer;
}
STM32446TIM8_BDTR* stm32446_tim8_bdtr_inic(void)
{

	// CCER
	stm32446_tim8_bdtr.moe = STM32446Tim8_moe;
	stm32446_tim8_bdtr.aoe = STM32446Tim8_aoe;
	stm32446_tim8_bdtr.bkp = STM32446Tim8_bkp;
	stm32446_tim8_bdtr.bke = STM32446Tim8_bke;
	stm32446_tim8_bdtr.ossr = STM32446Tim8_ossr;
	stm32446_tim8_bdtr.ossi = STM32446Tim8_ossi;
	stm32446_tim8_bdtr.lock = STM32446Tim8_lock;
	stm32446_tim8_bdtr.dtg = STM32446Tim8_dtg;
	return &stm32446_tim8_bdtr;
}
STM32446TIM8_DCR* stm32446_tim8_dcr_inic(void)
{

	// CCER
	stm32446_tim8_dcr.dbl = STM32446Tim8_dbl;
	stm32446_tim8_dcr.dba = STM32446Tim8_dba;
	return &stm32446_tim8_dcr;
}
/*** TIM8 INIC Procedure & Function Definition ***/
STM32446TIM8obj tim8_enable(void)
{


	// CLOCK
	stm32446_tim8.clock = STM32446Tim8Clock;
	// NVIC
	stm32446_tim8.nvic = STM32446Tim8Nvic;
	/*** TIM8 Bit Mapping Link ***/
	stm32446_tim8.cr1 = stm32446_tim8_cr1_inic();
	stm32446_tim8.cr2 = stm32446_tim8_cr2_inic();
	stm32446_tim8.smcr = stm32446_tim8_smcr_inic();
	stm32446_tim8.dier = stm32446_tim8_dier_inic();
	stm32446_tim8.sr = stm32446_tim8_sr_inic();
	stm32446_tim8.egr = stm32446_tim8_egr_inic();
	stm32446_tim8.ccmr1 = stm32446_tim8_ccmr1_inic();
	stm32446_tim8.ccmr2 = stm32446_tim8_ccmr2_inic();
	stm32446_tim8.ccer = stm32446_tim8_ccer_inic();
	stm32446_tim8.bdtr = stm32446_tim8_bdtr_inic();
	stm32446_tim8.dcr = stm32446_tim8_dcr_inic();
	stm32446_tim8.cnt = STM32446Tim8_cnt;
	stm32446_tim8.get_cnt = STM32446Tim8_get_cnt;
	stm32446_tim8.psc = STM32446Tim8_psc;
	stm32446_tim8.arr = STM32446Tim8_arr;
	stm32446_tim8.rep = STM32446Tim8_rcr;
	stm32446_tim8.ccr1 = STM32446Tim8_ccr1;
	stm32446_tim8.ccr2 = STM32446Tim8_ccr2;
	stm32446_tim8.ccr3 = STM32446Tim8_ccr3;
	stm32446_tim8.ccr4 = STM32446Tim8_ccr4;
	stm32446_tim8.dmar = STM32446Tim8_dmab;
	return stm32446_tim8;
}

STM32446TIM8obj* tim8(void){ return (STM32446TIM8obj*) &stm32446_tim8; }

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


