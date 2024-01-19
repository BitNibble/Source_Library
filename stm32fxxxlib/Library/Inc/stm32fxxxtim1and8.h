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
/*** TIMER Bit Mapping TypeDef ***/
typedef struct{
	void (*ckd)(uint8_t value);
	uint8_t (*get_ckd)(void);
	void (*apre)(uint8_t bool);
	void (*cms)(uint8_t value);
	void (*dir)(uint8_t bool);
	void (*opm)(uint8_t bool);
	void (*urs)(uint8_t bool);
	void (*udis)(uint8_t bool);
	void (*cen)(uint8_t bool);
}STM32FXXXTIM1_CR1, STM32FXXXTIM8_CR1;
typedef struct{
	void (*ois4)(uint8_t bool);
	void (*ois3n)(uint8_t bool);
	void (*ois3)(uint8_t bool);
	void (*ois2n)(uint8_t bool);
	void (*ois2)(uint8_t bool);
	void (*ois1n)(uint8_t bool);
	void (*ois1)(uint8_t bool);
	void (*ti1s)(uint8_t bool);
	void (*mms)(uint8_t value);
	void (*ccds)(uint8_t bool);
	void (*ccus)(uint8_t bool);
	void (*ccpc)(uint8_t bool);
}STM32FXXXTIM1_CR2, STM32FXXXTIM8_CR2;
typedef struct{
	void (*etp)(uint8_t bool);
	void (*ece)(uint8_t bool);
	void (*etps)(uint8_t value);
	void (*etf)(uint8_t value);
	void (*msm)(uint8_t bool);
	void (*ts)(uint8_t value);
	void (*sms)(uint8_t value);
}STM32FXXXTIM1_SMCR, STM32FXXXTIM8_SMCR;
typedef struct{
	void (*tde)(uint8_t bool);
	void (*comde)(uint8_t bool);
	void (*cc4de)(uint8_t bool);
	void (*cc3de)(uint8_t bool);
	void (*cc2de)(uint8_t bool);
	void (*cc1de)(uint8_t bool);
	void (*ude)(uint8_t bool);
	void (*bie)(uint8_t bool);
	void (*tie)(uint8_t bool);
	void (*comie)(uint8_t bool);
	void (*cc4ie)(uint8_t bool);
	void (*cc3ie)(uint8_t bool);
	void (*cc2ie)(uint8_t bool);
	void (*cc1ie)(uint8_t bool);
	void (*uie)(uint8_t bool);
}STM32FXXXTIM1_DIER, STM32FXXXTIM8_DIER;
typedef struct{
	uint8_t (*cc4of)(void);
	void (*clear_cc4of)(void);
	uint8_t (*cc3of)(void);
	void (*clear_cc3of)(void);
	uint8_t (*cc2of)(void);
	void (*clear_cc2of)(void);
	uint8_t (*cc1of)(void);
	void (*clear_cc1of)(void);
	uint8_t (*bif)(void);
	void (*clear_bif)(void);
	uint8_t (*tif)(void);
	void (*clear_tif)(void);
	uint8_t (*comif)(void);
	void (*clear_comif)(void);
	uint8_t (*cc4if)(void);
	void (*clear_cc4if)(void);
	uint8_t (*cc3if)(void);
	void (*clear_cc3if)(void);
	uint8_t (*cc2if)(void);
	void (*clear_cc2if)(void);
	uint8_t (*cc1if)(void);
	void (*clear_cc1if)(void);
	uint8_t (*uif)(void);
	void (*clear_uif)(void);
}STM32FXXXTIM1_SR, STM32FXXXTIM8_SR;
typedef struct{
	void (*bg)(void);
	void (*tg)(void);
	void (*comg)(void);
	void (*cc4g)(void);
	void (*cc3g)(void);
	void (*cc2g)(void);
	void (*cc1g)(void);
	void (*ug)(void);
}STM32FXXXTIM1_EGR, STM32FXXXTIM8_EGR;
typedef struct{
	void (*oc2ce)(uint8_t bool);
	void (*oc2m)(uint8_t value);
	void (*ic2f)(uint8_t value);
	void (*oc2pe)(uint8_t bool);
	void (*oc2fe)(uint8_t bool);
	void (*ic2psc)(uint8_t value);
	void (*cc2s)(uint8_t value);
	void (*oc1ce)(uint8_t bool);
	void (*oc1m)(uint8_t value);
	void (*ic1f)(uint8_t value);
	void (*oc1pe)(uint8_t bool);
	void (*oc1fe)(uint8_t bool);
	void (*ic1psc)(uint8_t value);
	void (*cc1s)(uint8_t value);
}STM32FXXXTIM1_CCMR1, STM32FXXXTIM8_CCMR1;
typedef struct{
	void (*oc4ce)(uint8_t bool);
	void (*oc4m)(uint8_t value);
	void (*ic4f)(uint8_t value);
	void (*oc4pe)(uint8_t bool);
	void (*oc4fe)(uint8_t bool);
	void (*ic4psc)(uint8_t value);
	void (*cc4s)(uint8_t value);
	void (*oc3ce)(uint8_t bool);
	void (*oc3m)(uint8_t value);
	void (*ic3f)(uint8_t value);
	void (*oc3pe)(uint8_t bool);
	void (*oc3fe)(uint8_t bool);
	void (*ic3psc)(uint8_t value);
	void (*cc3s)(uint8_t value);
}STM32FXXXTIM1_CCMR2, STM32FXXXTIM8_CCMR2;
typedef struct{
	void (*cc4p)(uint8_t bool);
	void (*cc4e)(uint8_t bool);
	void (*cc3np)(uint8_t bool);
	void (*cc3ne)(uint8_t bool);
	void (*cc3p)(uint8_t bool);
	void (*cc3e)(uint8_t bool);
	void (*cc2np)(uint8_t bool);
	void (*cc2ne)(uint8_t bool);
	void (*cc2p)(uint8_t bool);
	void (*cc2e)(uint8_t bool);
	void (*cc1np)(uint8_t bool);
	void (*cc1ne)(uint8_t bool);
	void (*cc1p)(uint8_t bool);
	void (*cc1e)(uint8_t bool);
}STM32FXXXTIM1_CCER, STM32FXXXTIM8_CCER;
typedef struct{
	void (*moe)(uint8_t bool);
	void (*aoe)(uint8_t bool);
	void (*bkp)(uint8_t bool);
	void (*bke)(uint8_t bool);
	void (*ossr)(uint8_t bool);
	void (*ossi)(uint8_t bool);
	void (*lock)(uint8_t value);
	void (*dtg)(uint8_t value);
}STM32FXXXTIM1_BDTR, STM32FXXXTIM8_BDTR;
typedef struct{
	void (*dbl)(uint8_t value);
	void (*dba)(uint8_t value);
}STM32FXXXTIM1_DCR, STM32FXXXTIM8_DCR;
/*** TIMER TypeDef***/
// ( 1 and 8 ) TIM 
typedef struct
{

	/*** Bit Mapping ***/
	STM32FXXXTIM1_CR1* cr1;
	STM32FXXXTIM1_CR2* cr2;
	STM32FXXXTIM1_SMCR* smcr;
	STM32FXXXTIM1_DIER* dier;
	STM32FXXXTIM1_SR* sr;
	STM32FXXXTIM1_EGR* egr;
	STM32FXXXTIM1_CCMR1* ccmr1;
	STM32FXXXTIM1_CCMR2* ccmr2;
	STM32FXXXTIM1_CCER* ccer;
	void (*cnt)(uint16_t value);
	uint16_t (*get_cnt)(void);
	void (*psc)(uint16_t value);
	void (*arr)(uint16_t value);
	void (*rep)(uint8_t value);
	void (*ccr1)(uint16_t value);
	void (*ccr2)(uint16_t value);
	void (*ccr3)(uint16_t value);
	void (*ccr4)(uint16_t value);
	STM32FXXXTIM1_BDTR* bdtr;
	STM32FXXXTIM1_DCR* dcr;
	void (*dmar)(uint16_t value);
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t value);
}STM32FXXXTIM1obj, STM32FXXXTIM8obj;
/*******************/
/*** INIC 1 and 8 ***/
/*******************/
STM32FXXXTIM1obj tim1_enable(void);
STM32FXXXTIM1obj* tim1(void);
STM32FXXXTIM8obj tim8_enable(void);
STM32FXXXTIM1obj* tim8(void);
/****************************************/
/*** TIM1 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim1Clock(uint8_t bool);
void STM32FXXXTim1Nvic(uint8_t value);
/*** TIM1 Bit Mapping Header ***/
// CR1
void STM32FXXXTim1_ckd(uint8_t value);
uint8_t STM32FXXXTim1_get_ckd(void);
void STM32FXXXTim1_set_apre(uint8_t bool);
void STM32FXXXTim1_set_cms(uint8_t value);
void STM32FXXXTim1_set_dir(uint8_t bool);
void STM32FXXXTim1_set_opm(uint8_t bool);
void STM32FXXXTim1_set_urs(uint8_t bool);
void STM32FXXXTim1_set_udis(uint8_t bool);
void STM32FXXXTim1_cen(uint8_t bool);
// CR2
void STM32FXXXTim1_ois4(uint8_t bool);
void STM32FXXXTim1_ois3n(uint8_t bool);
void STM32FXXXTim1_ois3(uint8_t bool);
void STM32FXXXTim1_ois2n(uint8_t bool);
void STM32FXXXTim1_ois2(uint8_t bool);
void STM32FXXXTim1_ois1n(uint8_t bool);
void STM32FXXXTim1_ois1(uint8_t bool);
void STM32FXXXTim1_ti1s(uint8_t bool);
void STM32FXXXTim1_mms(uint8_t value);
void STM32FXXXTim1_ccds(uint8_t bool);
void STM32FXXXTim1_ccus(uint8_t bool);
void STM32FXXXTim1_ccpc(uint8_t bool);
// SMCR
void STM32FXXXTim1_etp(uint8_t bool);
void STM32FXXXTim1_ece(uint8_t bool);
void STM32FXXXTim1_etps(uint8_t value);
void STM32FXXXTim1_etf(uint8_t value);
void STM32FXXXTim1_msm(uint8_t bool);
void STM32FXXXTim1_ts(uint8_t value);
void STM32FXXXTim1_sms(uint8_t value);
// DIER
void STM32FXXXTim1_tde(uint8_t bool);
void STM32FXXXTim1_cc4de(uint8_t bool);
void STM32FXXXTim1_cc3de(uint8_t bool);
void STM32FXXXTim1_cc2de(uint8_t bool);
void STM32FXXXTim1_cc1de(uint8_t bool);
void STM32FXXXTim1_ude(uint8_t bool);
void STM32FXXXTim1_bie(uint8_t bool);
void STM32FXXXTim1_comie(uint8_t bool);
void STM32FXXXTim1_tie(uint8_t bool);
void STM32FXXXTim1_cc4ie(uint8_t bool);
void STM32FXXXTim1_cc3ie(uint8_t bool);
void STM32FXXXTim1_cc2ie(uint8_t bool);
void STM32FXXXTim1_cc1ie(uint8_t bool);
void STM32FXXXTim1_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim1_cc4of(void);
void STM32FXXXTim1_clear_cc4of(void);
uint8_t STM32FXXXTim1_cc3of(void);
void STM32FXXXTim1_clear_cc3of(void);
uint8_t STM32FXXXTim1_cc2of(void);
void STM32FXXXTim1_clear_cc2of(void);
uint8_t STM32FXXXTim1_cc1of(void);
void STM32FXXXTim1_clear_cc1of(void);
uint8_t STM32FXXXTim1_bif(void);
void STM32FXXXTim1_clear_bif(void);
uint8_t STM32FXXXTim1_tif(void);
uint8_t STM32FXXXTim1_tif(void);
uint8_t STM32FXXXTim1_comif(void);
void STM32FXXXTim1_clear_comif(void);
void STM32FXXXTim1_clear_tif(void);
uint8_t STM32FXXXTim1_cc4if(void);
void STM32FXXXTim1_clear_cc4if(void);
uint8_t STM32FXXXTim1_cc3if(void);
void STM32FXXXTim1_clear_cc3if(void);
uint8_t STM32FXXXTim1_cc2if(void);
void STM32FXXXTim1_clear_cc2if(void);
uint8_t STM32FXXXTim1_cc1if(void);
void STM32FXXXTim1_clear_cc1if(void);
uint8_t STM32FXXXTim1_uif(void);
void STM32FXXXTim1_clear_uif(void);
// EGR
void STM32FXXXTim1_tg(void);
void STM32FXXXTim1_cc4g(void);
void STM32FXXXTim1_cc3g(void);
void STM32FXXXTim1_cc2g(void);
void STM32FXXXTim1_cc1g(void);
void STM32FXXXTim1_ug(void);
// CCMR1
void STM32FXXXTim1_oc2ce(uint8_t value);
void STM32FXXXTim1_oc2m(uint8_t value);
void STM32FXXXTim1_ic2f(uint8_t value);
void STM32FXXXTim1_oc2pe(uint8_t bool);
void STM32FXXXTim1_oc2fe(uint8_t bool);
void STM32FXXXTim1_ic2psc(uint8_t value);
void STM32FXXXTim1_cc2s(uint8_t value);
void STM32FXXXTim1_oc1ce(uint8_t value);
void STM32FXXXTim1_oc1m(uint8_t value);
void STM32FXXXTim1_ic1f(uint8_t value);
void STM32FXXXTim1_oc1pe(uint8_t bool);
void STM32FXXXTim1_oc1fe(uint8_t bool);
void STM32FXXXTim1_ic1psc(uint8_t value);
void STM32FXXXTim1_cc1s(uint8_t value);
// CCMR2
void STM32FXXXTim1_oc4ce(uint8_t value);
void STM32FXXXTim1_oc4m(uint8_t value);
void STM32FXXXTim1_ic4f(uint8_t value);
void STM32FXXXTim1_oc4pe(uint8_t bool);
void STM32FXXXTim1_oc4fe(uint8_t bool);
void STM32FXXXTim1_ic4psc(uint8_t value);
void STM32FXXXTim1_cc4s(uint8_t value);
void STM32FXXXTim1_oc3ce(uint8_t value);
void STM32FXXXTim1_oc3m(uint8_t value);
void STM32FXXXTim1_ic3f(uint8_t value);
void STM32FXXXTim1_oc3pe(uint8_t bool);
void STM32FXXXTim1_oc3fe(uint8_t bool);
void STM32FXXXTim1_ic3psc(uint8_t value);
void STM32FXXXTim1_cc3s(uint8_t value);
// CCER
void STM32FXXXTim1_cc4np(uint8_t bool);
void STM32FXXXTim1_cc4p(uint8_t bool);
void STM32FXXXTim1_cc4e(uint8_t bool);
void STM32FXXXTim1_cc3np(uint8_t bool);
void STM32FXXXTim1_cc3ne(uint8_t bool);
void STM32FXXXTim1_cc3p(uint8_t bool);
void STM32FXXXTim1_cc3e(uint8_t bool);
void STM32FXXXTim1_cc2np(uint8_t bool);
void STM32FXXXTim1_cc2ne(uint8_t bool);
void STM32FXXXTim1_cc2p(uint8_t bool);
void STM32FXXXTim1_cc2e(uint8_t bool);
void STM32FXXXTim1_cc1np(uint8_t bool);
void STM32FXXXTim1_cc1ne(uint8_t bool);
void STM32FXXXTim1_cc1p(uint8_t bool);
void STM32FXXXTim1_cc1e(uint8_t bool);
// CNT
void STM32FXXXTim1_cnt(uint16_t value);
uint16_t STM32FXXXTim1_get_cnt(void);
// PSC
void STM32FXXXTim1_psc(uint16_t value);
// ARR
void STM32FXXXTim1_arr(uint16_t value);
// RCR
void STM32FXXXTim1_rcr(uint8_t value);
// CCR1
void STM32FXXXTim1_ccr1(uint16_t value);
// CCR2
void STM32FXXXTim1_ccr2(uint16_t value);
// CCR3
void STM32FXXXTim1_ccr3(uint16_t value);
// CCR4
void STM32FXXXTim1_ccr4(uint16_t value);
// BDTR
void STM32FXXXTim1_moe(uint8_t bool);
void STM32FXXXTim1_aoe(uint8_t bool);
void STM32FXXXTim1_bkp(uint8_t bool);
void STM32FXXXTim1_bke(uint8_t bool);
void STM32FXXXTim1_ossr(uint8_t bool);
void STM32FXXXTim1_ossi(uint8_t bool);
void STM32FXXXTim1_lock(uint8_t value);
void STM32FXXXTim1_dtg(uint8_t value);
// DCR
void STM32FXXXTim1_dbl(uint8_t value);
void STM32FXXXTim1_dba(uint8_t value);
// DMAR
void STM32FXXXTim1_dmab(uint16_t value);
uint16_t STM32FXXXTim1_get_dmab(void);
// OR
void STM32FXXXTim1_itr1_rmp(uint8_t value);
/****************************************/
/*** TIM8 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim8Clock(uint8_t bool);
void STM32FXXXTim8Nvic(uint8_t value);
/*** TIM8 Bit Mapping Header ***/
// CR1
uint8_t STM32FXXXTim8_get_ckd(void);
void STM32FXXXTim8_set_apre(uint8_t bool);
void STM32FXXXTim8_set_cms(uint8_t value);
void STM32FXXXTim8_set_dir(uint8_t bool);
void STM32FXXXTim8_set_opm(uint8_t bool);
void STM32FXXXTim8_set_urs(uint8_t bool);
void STM32FXXXTim8_set_udis(uint8_t bool);
void STM32FXXXTim8_cen(uint8_t bool);
// CR2
void STM32FXXXTim8_ois4(uint8_t bool);
void STM32FXXXTim8_ois3n(uint8_t bool);
void STM32FXXXTim8_ois3(uint8_t bool);
void STM32FXXXTim8_ois2n(uint8_t bool);
void STM32FXXXTim8_ois2(uint8_t bool);
void STM32FXXXTim8_ois1n(uint8_t bool);
void STM32FXXXTim8_ois1(uint8_t bool);
void STM32FXXXTim8_ti1s(uint8_t bool);
void STM32FXXXTim8_mms(uint8_t value);
void STM32FXXXTim8_ccds(uint8_t bool);
void STM32FXXXTim8_ccus(uint8_t bool);
void STM32FXXXTim8_ccpc(uint8_t bool);
// SMCR
void STM32FXXXTim8_etp(uint8_t bool);
void STM32FXXXTim8_ece(uint8_t bool);
void STM32FXXXTim8_etps(uint8_t value);
void STM32FXXXTim8_etf(uint8_t value);
void STM32FXXXTim8_msm(uint8_t bool);
void STM32FXXXTim8_ts(uint8_t value);
void STM32FXXXTim8_sms(uint8_t value);
// DIER
void STM32FXXXTim8_tde(uint8_t bool);
void STM32FXXXTim8_comde(uint8_t bool);
void STM32FXXXTim8_cc4de(uint8_t bool);
void STM32FXXXTim8_cc3de(uint8_t bool);
void STM32FXXXTim8_cc2de(uint8_t bool);
void STM32FXXXTim8_cc1de(uint8_t bool);
void STM32FXXXTim8_ude(uint8_t bool);
void STM32FXXXTim8_bie(uint8_t bool);
void STM32FXXXTim8_tie(uint8_t bool);
void STM32FXXXTim8_comie(uint8_t bool);
void STM32FXXXTim8_cc4ie(uint8_t bool);
void STM32FXXXTim8_cc3ie(uint8_t bool);
void STM32FXXXTim8_cc2ie(uint8_t bool);
void STM32FXXXTim8_cc1ie(uint8_t bool);
void STM32FXXXTim8_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim8_cc4of(void);
void STM32FXXXTim8_clear_cc4of(void);
uint8_t STM32FXXXTim8_cc3of(void);
void STM32FXXXTim8_clear_cc3of(void);
uint8_t STM32FXXXTim8_cc2of(void);
void STM32FXXXTim8_clear_cc2of(void);
uint8_t STM32FXXXTim8_cc1of(void);
void STM32FXXXTim8_clear_cc1of(void);
uint8_t STM32FXXXTim8_bif(void);
void STM32FXXXTim8_clear_bif(void);
uint8_t STM32FXXXTim8_tif(void);
void STM32FXXXTim8_clear_tif(void);
uint8_t STM32FXXXTim8_comif(void);
void STM32FXXXTim8_clear_comif(void);
void STM32FXXXTim8_clear_tif(void);
uint8_t STM32FXXXTim8_cc4if(void);
void STM32FXXXTim8_clear_cc4if(void);
uint8_t STM32FXXXTim8_cc3if(void);
void STM32FXXXTim8_clear_cc3if(void);
uint8_t STM32FXXXTim8_cc2if(void);
void STM32FXXXTim8_clear_cc2if(void);
uint8_t STM32FXXXTim8_cc1if(void);
void STM32FXXXTim8_clear_cc1if(void);
uint8_t STM32FXXXTim8_uif(void);
void STM32FXXXTim8_clear_uif(void);
// EGR
void STM32FXXXTim8_bg(void);
void STM32FXXXTim8_tg(void);
void STM32FXXXTim8_comg(void);
void STM32FXXXTim8_cc4g(void);
void STM32FXXXTim8_cc3g(void);
void STM32FXXXTim8_cc2g(void);
void STM32FXXXTim8_cc1g(void);
void STM32FXXXTim8_ug(void);
// CCMR1
void STM32FXXXTim8_oc2ce(uint8_t value);
void STM32FXXXTim8_oc2m(uint8_t value);
void STM32FXXXTim8_ic2f(uint8_t value);
void STM32FXXXTim8_oc2pe(uint8_t bool);
void STM32FXXXTim8_oc2fe(uint8_t bool);
void STM32FXXXTim8_ic2psc(uint8_t value);
void STM32FXXXTim8_cc2s(uint8_t value);
void STM32FXXXTim8_oc1ce(uint8_t value);
void STM32FXXXTim8_oc1m(uint8_t value);
void STM32FXXXTim8_ic1f(uint8_t value);
void STM32FXXXTim8_oc1pe(uint8_t bool);
void STM32FXXXTim8_oc1fe(uint8_t bool);
void STM32FXXXTim8_ic1psc(uint8_t value);
void STM32FXXXTim8_cc1s(uint8_t value);
// CCMR2
void STM32FXXXTim8_oc4ce(uint8_t value);
void STM32FXXXTim8_oc4m(uint8_t value);
void STM32FXXXTim8_ic4f(uint8_t value);
void STM32FXXXTim8_oc4pe(uint8_t bool);
void STM32FXXXTim8_oc4fe(uint8_t bool);
void STM32FXXXTim8_ic4psc(uint8_t value);
void STM32FXXXTim8_cc4s(uint8_t value);
void STM32FXXXTim8_oc3ce(uint8_t value);
void STM32FXXXTim8_oc3m(uint8_t value);
void STM32FXXXTim8_ic3f(uint8_t value);
void STM32FXXXTim8_oc3pe(uint8_t bool);
void STM32FXXXTim8_oc3fe(uint8_t bool);
void STM32FXXXTim8_ic3psc(uint8_t value);
void STM32FXXXTim8_cc3s(uint8_t value);
// CCER
void STM32FXXXTim8_cc4np(uint8_t bool);
void STM32FXXXTim8_cc4p(uint8_t bool);
void STM32FXXXTim8_cc4e(uint8_t bool);
void STM32FXXXTim8_cc3np(uint8_t bool);
void STM32FXXXTim8_cc3ne(uint8_t bool);
void STM32FXXXTim8_cc3p(uint8_t bool);
void STM32FXXXTim8_cc3e(uint8_t bool);
void STM32FXXXTim8_cc2np(uint8_t bool);
void STM32FXXXTim8_cc2ne(uint8_t bool);
void STM32FXXXTim8_cc2p(uint8_t bool);
void STM32FXXXTim8_cc2e(uint8_t bool);
void STM32FXXXTim8_cc1np(uint8_t bool);
void STM32FXXXTim8_cc1ne(uint8_t bool);
void STM32FXXXTim8_cc1p(uint8_t bool);
void STM32FXXXTim8_cc1e(uint8_t bool);
// CNT
void STM32FXXXTim8_cnt(uint16_t value);
uint16_t STM32FXXXTim8_get_cnt(void);
// PSC
void STM32FXXXTim8_psc(uint16_t value);
// ARR
void STM32FXXXTim8_arr(uint16_t value);
// RCR
void STM32FXXXTim8_rcr(uint8_t value);
// CCR1
void STM32FXXXTim8_ccr1(uint16_t value);
// CCR2
void STM32FXXXTim8_ccr2(uint16_t value);
// CCR3
void STM32FXXXTim8_ccr3(uint16_t value);
// CCR4
void STM32FXXXTim8_ccr4(uint16_t value);
// BDTR
void STM32FXXXTim8_moe(uint8_t bool);
void STM32FXXXTim8_aoe(uint8_t bool);
void STM32FXXXTim8_bkp(uint8_t bool);
void STM32FXXXTim8_bke(uint8_t bool);
void STM32FXXXTim8_ossr(uint8_t bool);
void STM32FXXXTim8_ossi(uint8_t bool);
void STM32FXXXTim8_lock(uint8_t value);
void STM32FXXXTim8_dtg(uint8_t value);
// DCR
void STM32FXXXTim8_dbl(uint8_t value);
void STM32FXXXTim8_dba(uint8_t value);
// DMAR
void STM32FXXXTim8_dmab(uint16_t value);
uint16_t STM32FXXXTim8_get_dmab(void);
// OR
void STM32FXXXTim8_ti4_rmp(uint8_t value);
/****************************************/

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

