/******************************************************************************
	STM32 XXX TIM 2 to 5
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 22062023
Comment:
	
*******************************************************************************/
#ifndef _STM32FXXXTIM2TO5_H_
	#define _STM32FXXXTIM2TO5_H_
/*** Library ***/
#include "armquery.h"
/*** TIMER 2 to 5 Bit Mapping TypeDef ***/
// CR1
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
}STM32FXXXTIM2_CR1, STM32FXXXTIM3_CR1, STM32FXXXTIM4_CR1, STM32FXXXTIM5_CR1;
// CR2
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
}STM32FXXXTIM2_CR2, STM32FXXXTIM3_CR2, STM32FXXXTIM4_CR2, STM32FXXXTIM5_CR2;
// SMCR
typedef struct{
	void (*etp)(uint8_t bool);
	void (*ece)(uint8_t bool);
	void (*etps)(uint8_t value);
	void (*etf)(uint8_t value);
	void (*msm)(uint8_t bool);
	void (*ts)(uint8_t value);
	void (*sms)(uint8_t value);
}STM32FXXXTIM2_SMCR, STM32FXXXTIM3_SMCR, STM32FXXXTIM4_SMCR, STM32FXXXTIM5_SMCR;
// DIER
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
}STM32FXXXTIM2_DIER, STM32FXXXTIM3_DIER, STM32FXXXTIM4_DIER, STM32FXXXTIM5_DIER;
// SR
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
}STM32FXXXTIM2_SR, STM32FXXXTIM3_SR, STM32FXXXTIM4_SR, STM32FXXXTIM5_SR;
// EGR
typedef struct{
	void (*bg)(void);
	void (*tg)(void);
	void (*comg)(void);
	void (*cc4g)(void);
	void (*cc3g)(void);
	void (*cc2g)(void);
	void (*cc1g)(void);
	void (*ug)(void);
}STM32FXXXTIM2_EGR, STM32FXXXTIM3_EGR, STM32FXXXTIM4_EGR, STM32FXXXTIM5_EGR;
// CCMR1
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
}STM32FXXXTIM2_CCMR1, STM32FXXXTIM3_CCMR1, STM32FXXXTIM4_CCMR1, STM32FXXXTIM5_CCMR1;
// CCMR2
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
}STM32FXXXTIM2_CCMR2, STM32FXXXTIM3_CCMR2, STM32FXXXTIM4_CCMR2, STM32FXXXTIM5_CCMR2;
// CCER
typedef struct{
	void (*cc4np)(uint8_t bool);
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
}STM32FXXXTIM2_CCER, STM32FXXXTIM3_CCER, STM32FXXXTIM4_CCER, STM32FXXXTIM5_CCER;
// BDTR
typedef struct{
	void (*moe)(uint8_t bool);
	void (*aoe)(uint8_t bool);
	void (*bkp)(uint8_t bool);
	void (*bke)(uint8_t bool);
	void (*ossr)(uint8_t bool);
	void (*ossi)(uint8_t bool);
	void (*lock)(uint8_t value);
	void (*dtg)(uint8_t value);
}STM32FXXXTIM2_BDTR, STM32FXXXTIM3_BDTR, STM32FXXXTIM4_BDTR, STM32FXXXTIM5_BDTR;
// DCR
typedef struct{
	void (*dbl)(uint8_t value);
	void (*dba)(uint8_t value);
}STM32FXXXTIM2_DCR, STM32FXXXTIM3_DCR, STM32FXXXTIM4_DCR, STM32FXXXTIM5_DCR;
/*** TIMER 2 to 5 TypeDef ***/
// ( 2 and 5 ) TIM
typedef struct
{

	/*** Bit Mapping ***/
	STM32FXXXTIM2_CR1* cr1;
	STM32FXXXTIM2_CR2* cr2;
	STM32FXXXTIM2_SMCR* smcr;
	STM32FXXXTIM2_DIER* dier;
	STM32FXXXTIM2_SR* sr;
	STM32FXXXTIM2_EGR* egr;
	STM32FXXXTIM2_CCMR1* ccmr1;
	STM32FXXXTIM2_CCMR2* ccmr2;
	STM32FXXXTIM2_CCER* ccer;
	STM32FXXXTIM2_DCR* dcr;
	void (*cnt)(uint32_t value);
	uint32_t (*get_cnt)(void);
	void (*psc)(uint16_t value);
	void (*arr)(uint32_t value);
	void (*ccr1)(uint32_t value);
	void (*ccr2)(uint32_t value);
	void (*ccr3)(uint32_t value);
	void (*ccr4)(uint32_t value);
	void (*dmar)(uint16_t value);
	void (*or)(uint8_t value);
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
}STM32FXXXTIM2obj, STM32FXXXTIM5obj;
// ( 3 and 4 ) TIM
typedef struct
{

	/*** Bit Mapping ***/
	STM32FXXXTIM3_CR1* cr1;
	STM32FXXXTIM3_CR2* cr2;
	STM32FXXXTIM3_SMCR* smcr;
	STM32FXXXTIM3_DIER* dier;
	STM32FXXXTIM3_SR* sr;
	STM32FXXXTIM3_EGR* egr;
	STM32FXXXTIM3_CCMR1* ccmr1;
	STM32FXXXTIM3_CCMR2* ccmr2;
	STM32FXXXTIM3_CCER* ccer;
	STM32FXXXTIM3_DCR* dcr;
	void (*cnt)(uint16_t value);
	uint16_t (*get_cnt)(void);
	void (*psc)(uint16_t value);
	void (*arr)(uint16_t value);
	void (*ccr1)(uint16_t value);
	void (*ccr2)(uint16_t value);
	void (*ccr3)(uint16_t value);
	void (*ccr4)(uint16_t value);
	void (*dmar)(uint16_t value);
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
}STM32FXXXTIM3obj, STM32FXXXTIM4obj;
/***********************/
/*** INIC TIM 2 to 5 ***/
/***********************/
STM32FXXXTIM2obj tim2_enable(void);
STM32FXXXTIM2obj* tim2(void);
STM32FXXXTIM3obj tim3_enable(void);
STM32FXXXTIM3obj* tim3(void);
STM32FXXXTIM4obj tim4_enable(void);
STM32FXXXTIM4obj* tim4(void);
STM32FXXXTIM5obj tim5_enable(void);
STM32FXXXTIM5obj* tim5(void);
/****************************************/
/*** TIM2 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim2Clock(uint8_t bool);
void STM32FXXXTim2Nvic(uint8_t bool);
/*** TIM2 Bit Mapping Header ***/
// CR1
void STM32FXXXTim2_ckd(uint8_t value);
uint8_t STM32FXXXTim2_get_ckd(void);
void STM32FXXXTim2_set_apre(uint8_t bool);
void STM32FXXXTim2_set_cms(uint8_t value);
void STM32FXXXTim2_set_dir(uint8_t bool);
void STM32FXXXTim2_set_opm(uint8_t bool);
void STM32FXXXTim2_set_urs(uint8_t bool);
void STM32FXXXTim2_set_udis(uint8_t bool);
void STM32FXXXTim2_cen(uint8_t bool);
// CR2
void STM32FXXXTim2_ti1s(uint8_t bool);
void STM32FXXXTim2_mms(uint8_t value);
void STM32FXXXTim2_ccds(uint8_t bool);
// SMCR
void STM32FXXXTim2_etp(uint8_t bool);
void STM32FXXXTim2_ece(uint8_t bool);
void STM32FXXXTim2_etps(uint8_t value);
void STM32FXXXTim2_etf(uint8_t value);
void STM32FXXXTim2_msm(uint8_t bool);
void STM32FXXXTim2_ts(uint8_t value);
void STM32FXXXTim2_sms(uint8_t value);
// DIER
void STM32FXXXTim2_tde(uint8_t bool);
void STM32FXXXTim2_cc4de(uint8_t bool);
void STM32FXXXTim2_cc3de(uint8_t bool);
void STM32FXXXTim2_cc2de(uint8_t bool);
void STM32FXXXTim2_cc1de(uint8_t bool);
void STM32FXXXTim2_ude(uint8_t bool);
void STM32FXXXTim2_tie(uint8_t bool);
void STM32FXXXTim2_cc4ie(uint8_t bool);
void STM32FXXXTim2_cc3ie(uint8_t bool);
void STM32FXXXTim2_cc2ie(uint8_t bool);
void STM32FXXXTim2_cc1ie(uint8_t bool);
void STM32FXXXTim2_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim2_cc4of(void);
void STM32FXXXTim2_clear_cc4of(void);
uint8_t STM32FXXXTim2_cc3of(void);
void STM32FXXXTim2_clear_cc3of(void);
uint8_t STM32FXXXTim2_cc2of(void);
void STM32FXXXTim2_clear_cc2of(void);
uint8_t STM32FXXXTim2_cc1of(void);
void STM32FXXXTim2_clear_cc1of(void);
uint8_t STM32FXXXTim2_tif(void);
void STM32FXXXTim2_clear_tif(void);
uint8_t STM32FXXXTim2_cc4if(void);
void STM32FXXXTim2_clear_cc4if(void);
uint8_t STM32FXXXTim2_cc3if(void);
void STM32FXXXTim2_clear_cc3if(void);
uint8_t STM32FXXXTim2_cc2if(void);
void STM32FXXXTim2_clear_cc2if(void);
uint8_t STM32FXXXTim2_cc1if(void);
void STM32FXXXTim2_clear_cc1if(void);
uint8_t STM32FXXXTim2_uif(void);
void STM32FXXXTim2_clear_uif(void);
// EGR
void STM32FXXXTim2_tg(void);
void STM32FXXXTim2_cc4g(void);
void STM32FXXXTim2_cc3g(void);
void STM32FXXXTim2_cc2g(void);
void STM32FXXXTim2_cc1g(void);
void STM32FXXXTim2_ug(void);
// CCMR1
void STM32FXXXTim2_oc2ce(uint8_t value);
void STM32FXXXTim2_oc2m(uint8_t value);
void STM32FXXXTim2_ic2f(uint8_t value);
void STM32FXXXTim2_oc2pe(uint8_t bool);
void STM32FXXXTim2_oc2fe(uint8_t bool);
void STM32FXXXTim2_ic2psc(uint8_t value);
void STM32FXXXTim2_cc2s(uint8_t value);
void STM32FXXXTim2_oc1ce(uint8_t value);
void STM32FXXXTim2_oc1m(uint8_t value);
void STM32FXXXTim2_ic1f(uint8_t value);
void STM32FXXXTim2_oc1pe(uint8_t bool);
void STM32FXXXTim2_oc1fe(uint8_t bool);
void STM32FXXXTim2_ic1psc(uint8_t value);
void STM32FXXXTim2_cc1s(uint8_t value);
// CCMR2
void STM32FXXXTim2_oc4ce(uint8_t value);
void STM32FXXXTim2_oc4m(uint8_t value);
void STM32FXXXTim2_ic4f(uint8_t value);
void STM32FXXXTim2_oc4pe(uint8_t bool);
void STM32FXXXTim2_oc4fe(uint8_t bool);
void STM32FXXXTim2_ic4psc(uint8_t value);
void STM32FXXXTim2_cc4s(uint8_t value);
void STM32FXXXTim2_oc3ce(uint8_t value);
void STM32FXXXTim2_oc3m(uint8_t value);
void STM32FXXXTim2_ic3f(uint8_t value);
void STM32FXXXTim2_oc3pe(uint8_t bool);
void STM32FXXXTim2_oc3fe(uint8_t bool);
void STM32FXXXTim2_ic3psc(uint8_t value);
void STM32FXXXTim2_cc3s(uint8_t value);
// CCER
void STM32FXXXTim2_cc4np(uint8_t bool);
void STM32FXXXTim2_cc4p(uint8_t bool);
void STM32FXXXTim2_cc4e(uint8_t bool);
void STM32FXXXTim2_cc3np(uint8_t bool);
void STM32FXXXTim2_cc3p(uint8_t bool);
void STM32FXXXTim2_cc3e(uint8_t bool);
void STM32FXXXTim2_cc2np(uint8_t bool);
void STM32FXXXTim2_cc2p(uint8_t bool);
void STM32FXXXTim2_cc2e(uint8_t bool);
void STM32FXXXTim2_cc1np(uint8_t bool);
void STM32FXXXTim2_cc1p(uint8_t bool);
void STM32FXXXTim2_cc1e(uint8_t bool);
// CNT
void STM32FXXXTim2_cnt(uint32_t value);
uint32_t STM32FXXXTim2_get_cnt(void);
// PSC
void STM32FXXXTim2_psc(uint16_t value);
// ARR
void STM32FXXXTim2_arr(uint32_t value);
// CCR1
void STM32FXXXTim2_ccr1(uint32_t value);
// CCR2
void STM32FXXXTim2_ccr2(uint32_t value);
// CCR3
void STM32FXXXTim2_ccr3(uint32_t value);
// CCR4
void STM32FXXXTim2_ccr4(uint32_t value);
// DCR
void STM32FXXXTim2_dbl(uint8_t value);
void STM32FXXXTim2_dba(uint8_t value);
// DMAR
void STM32FXXXTim2_dmab(uint16_t value);
uint16_t STM32FXXXTim2_get_dmab(void);
// OR
void STM32FXXXTim2_itr1_rmp(uint8_t value);
/****************************************/
/*** TIM3 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim3Clock(uint8_t bool);
void STM32FXXXTim3Nvic(uint8_t bool);
/*** TIM3 Bit Mapping Header ***/
// CR1
void STM32FXXXTim3_ckd(uint8_t value);
uint8_t STM32FXXXTim3_get_ckd(void);
void STM32FXXXTim3_set_apre(uint8_t bool);
void STM32FXXXTim3_set_cms(uint8_t value);
void STM32FXXXTim3_set_dir(uint8_t bool);
void STM32FXXXTim3_set_opm(uint8_t bool);
void STM32FXXXTim3_set_urs(uint8_t bool);
void STM32FXXXTim3_set_udis(uint8_t bool);
void STM32FXXXTim3_cen(uint8_t bool);
// CR2
void STM32FXXXTim3_ti1s(uint8_t bool);
void STM32FXXXTim3_mms(uint8_t value);
void STM32FXXXTim3_ccds(uint8_t bool);
// SMCR
void STM32FXXXTim3_etp(uint8_t bool);
void STM32FXXXTim3_ece(uint8_t bool);
void STM32FXXXTim3_etps(uint8_t value);
void STM32FXXXTim5_etf(uint8_t value);
void STM32FXXXTim3_msm(uint8_t bool);
void STM32FXXXTim3_ts(uint8_t value);
void STM32FXXXTim3_sms(uint8_t value);
// DIER
void STM32FXXXTim3_tde(uint8_t bool);
void STM32FXXXTim3_cc4de(uint8_t bool);
void STM32FXXXTim3_cc3de(uint8_t bool);
void STM32FXXXTim3_cc2de(uint8_t bool);
void STM32FXXXTim3_cc1de(uint8_t bool);
void STM32FXXXTim3_ude(uint8_t bool);
void STM32FXXXTim3_tie(uint8_t bool);
void STM32FXXXTim3_cc4ie(uint8_t bool);
void STM32FXXXTim3_cc3ie(uint8_t bool);
void STM32FXXXTim3_cc2ie(uint8_t bool);
void STM32FXXXTim3_cc1ie(uint8_t bool);
void STM32FXXXTim3_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim3_cc4of(void);
void STM32FXXXTim3_clear_cc4of(void);
uint8_t STM32FXXXTim3_cc3of(void);
void STM32FXXXTim3_clear_cc3of(void);
uint8_t STM32FXXXTim3_cc2of(void);
void STM32FXXXTim3_clear_cc2of(void);
uint8_t STM32FXXXTim3_cc1of(void);
void STM32FXXXTim3_clear_cc1of(void);
uint8_t STM32FXXXTim3_tif(void);
void STM32FXXXTim3_clear_tif(void);
uint8_t STM32FXXXTim3_cc4if(void);
void STM32FXXXTim3_clear_cc4if(void);
uint8_t STM32FXXXTim3_cc3if(void);
void STM32FXXXTim3_clear_cc3if(void);
uint8_t STM32FXXXTim3_cc2if(void);
void STM32FXXXTim3_clear_cc2if(void);
uint8_t STM32FXXXTim3_cc1if(void);
void STM32FXXXTim3_clear_cc1if(void);
uint8_t STM32FXXXTim3_uif(void);
void STM32FXXXTim3_clear_uif(void);
// EGR
void STM32FXXXTim3_tg(void);
void STM32FXXXTim3_cc4g(void);
void STM32FXXXTim3_cc3g(void);
void STM32FXXXTim3_cc2g(void);
void STM32FXXXTim3_cc1g(void);
void STM32FXXXTim3_ug(void);
// CCMR1
void STM32FXXXTim3_oc2ce(uint8_t value);
void STM32FXXXTim3_oc2m(uint8_t value);
void STM32FXXXTim3_ic2f(uint8_t value);
void STM32FXXXTim3_oc2pe(uint8_t bool);
void STM32FXXXTim3_oc2fe(uint8_t bool);
void STM32FXXXTim3_ic2psc(uint8_t value);
void STM32FXXXTim3_cc2s(uint8_t value);
void STM32FXXXTim3_oc1ce(uint8_t value);
void STM32FXXXTim3_oc1m(uint8_t value);
void STM32FXXXTim3_ic1f(uint8_t value);
void STM32FXXXTim3_oc1pe(uint8_t bool);
void STM32FXXXTim3_oc1fe(uint8_t bool);
void STM32FXXXTim3_ic1psc(uint8_t value);
void STM32FXXXTim3_cc1s(uint8_t value);
// CCMR2
void STM32FXXXTim3_oc4ce(uint8_t value);
void STM32FXXXTim3_oc4m(uint8_t value);
void STM32FXXXTim3_ic4f(uint8_t value);
void STM32FXXXTim3_oc4pe(uint8_t bool);
void STM32FXXXTim3_oc4fe(uint8_t bool);
void STM32FXXXTim3_ic4psc(uint8_t value);
void STM32FXXXTim3_cc4s(uint8_t value);
void STM32FXXXTim3_oc3ce(uint8_t value);
void STM32FXXXTim3_oc3m(uint8_t value);
void STM32FXXXTim3_ic3f(uint8_t value);
void STM32FXXXTim3_oc3pe(uint8_t bool);
void STM32FXXXTim3_oc3fe(uint8_t bool);
void STM32FXXXTim3_ic3psc(uint8_t value);
void STM32FXXXTim3_cc3s(uint8_t value);
// CCER
void STM32FXXXTim3_cc4np(uint8_t bool);
void STM32FXXXTim3_cc4p(uint8_t bool);
void STM32FXXXTim3_cc4e(uint8_t bool);
void STM32FXXXTim3_cc3np(uint8_t bool);
void STM32FXXXTim3_cc3p(uint8_t bool);
void STM32FXXXTim3_cc3e(uint8_t bool);
void STM32FXXXTim3_cc2np(uint8_t bool);
void STM32FXXXTim3_cc2p(uint8_t bool);
void STM32FXXXTim3_cc2e(uint8_t bool);
void STM32FXXXTim3_cc1np(uint8_t bool);
void STM32FXXXTim3_cc1p(uint8_t bool);
void STM32FXXXTim3_cc1e(uint8_t bool);
// CNT
void STM32FXXXTim3_cnt(uint16_t value);
uint16_t STM32FXXXTim3_get_cnt(void);
// PSC
void STM32FXXXTim3_psc(uint16_t value);
// ARR
void STM32FXXXTim3_arr(uint16_t value);
// CCR1
void STM32FXXXTim3_ccr1(uint16_t value);
// CCR2
void STM32FXXXTim3_ccr2(uint16_t value);
// CCR3
void STM32FXXXTim3_ccr3(uint16_t value);
// CCR4
void STM32FXXXTim3_ccr4(uint16_t value);
// DCR
void STM32FXXXTim3_dbl(uint8_t value);
void STM32FXXXTim3_dba(uint8_t value);
// DMAR
void STM32FXXXTim3_dmab(uint16_t value);
uint16_t STM32FXXXTim3_get_dmab(void);
/****************************************/
/*** TIM4 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim4Clock(uint8_t bool);
void STM32FXXXTim4Nvic(uint8_t bool);
/*** TIM4 Bit Mapping Header ***/
// CR1
void STM32FXXXTim4_ckd(uint8_t value);
uint8_t STM32FXXXTim4_get_ckd(void);
void STM32FXXXTim4_set_apre(uint8_t bool);
void STM32FXXXTim4_set_cms(uint8_t value);
void STM32FXXXTim4_set_dir(uint8_t bool);
void STM32FXXXTim4_set_opm(uint8_t bool);
void STM32FXXXTim4_set_urs(uint8_t bool);
void STM32FXXXTim4_set_udis(uint8_t bool);
void STM32FXXXTim4_cen(uint8_t bool);
// CR2
void STM32FXXXTim4_ti1s(uint8_t bool);
void STM32FXXXTim4_mms(uint8_t value);
void STM32FXXXTim4_ccds(uint8_t bool);
// SMCR
void STM32FXXXTim4_etp(uint8_t bool);
void STM32FXXXTim4_ece(uint8_t bool);
void STM32FXXXTim4_etps(uint8_t value);
void STM32FXXXTim5_etf(uint8_t value);
void STM32FXXXTim4_msm(uint8_t bool);
void STM32FXXXTim4_ts(uint8_t value);
void STM32FXXXTim4_sms(uint8_t value);
// DIER
void STM32FXXXTim4_tde(uint8_t bool);
void STM32FXXXTim4_cc4de(uint8_t bool);
void STM32FXXXTim4_cc3de(uint8_t bool);
void STM32FXXXTim4_cc2de(uint8_t bool);
void STM32FXXXTim4_cc1de(uint8_t bool);
void STM32FXXXTim4_ude(uint8_t bool);
void STM32FXXXTim4_tie(uint8_t bool);
void STM32FXXXTim4_cc4ie(uint8_t bool);
void STM32FXXXTim4_cc3ie(uint8_t bool);
void STM32FXXXTim4_cc2ie(uint8_t bool);
void STM32FXXXTim4_cc1ie(uint8_t bool);
void STM32FXXXTim4_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim4_cc4of(void);
void STM32FXXXTim4_clear_cc4of(void);
uint8_t STM32FXXXTim4_cc3of(void);
void STM32FXXXTim4_clear_cc3of(void);
uint8_t STM32FXXXTim4_cc2of(void);
void STM32FXXXTim4_clear_cc2of(void);
uint8_t STM32FXXXTim4_cc1of(void);
void STM32FXXXTim4_clear_cc1of(void);
uint8_t STM32FXXXTim4_tif(void);
void STM32FXXXTim4_clear_tif(void);
uint8_t STM32FXXXTim4_cc4if(void);
void STM32FXXXTim4_clear_cc4if(void);
uint8_t STM32FXXXTim4_cc3if(void);
void STM32FXXXTim4_clear_cc3if(void);
uint8_t STM32FXXXTim4_cc2if(void);
void STM32FXXXTim4_clear_cc2if(void);
uint8_t STM32FXXXTim4_cc1if(void);
void STM32FXXXTim4_clear_cc1if(void);
uint8_t STM32FXXXTim4_uif(void);
void STM32FXXXTim4_clear_uif(void);
// EGR
void STM32FXXXTim4_tg(void);
void STM32FXXXTim4_cc4g(void);
void STM32FXXXTim4_cc3g(void);
void STM32FXXXTim4_cc2g(void);
void STM32FXXXTim4_cc1g(void);
void STM32FXXXTim4_ug(void);
// CCMR1
void STM32FXXXTim4_oc2ce(uint8_t value);
void STM32FXXXTim4_oc2m(uint8_t value);
void STM32FXXXTim4_ic2f(uint8_t value);
void STM32FXXXTim4_oc2pe(uint8_t bool);
void STM32FXXXTim4_oc2fe(uint8_t bool);
void STM32FXXXTim4_ic2psc(uint8_t value);
void STM32FXXXTim4_cc2s(uint8_t value);
void STM32FXXXTim4_oc1ce(uint8_t value);
void STM32FXXXTim4_oc1m(uint8_t value);
void STM32FXXXTim4_ic1f(uint8_t value);
void STM32FXXXTim4_oc1pe(uint8_t bool);
void STM32FXXXTim4_oc1fe(uint8_t bool);
void STM32FXXXTim4_ic1psc(uint8_t value);
void STM32FXXXTim4_cc1s(uint8_t value);
// CCMR2
void STM32FXXXTim4_oc4ce(uint8_t value);
void STM32FXXXTim4_oc4m(uint8_t value);
void STM32FXXXTim4_ic4f(uint8_t value);
void STM32FXXXTim4_oc4pe(uint8_t bool);
void STM32FXXXTim4_oc4fe(uint8_t bool);
void STM32FXXXTim4_ic4psc(uint8_t value);
void STM32FXXXTim4_cc4s(uint8_t value);
void STM32FXXXTim4_oc3ce(uint8_t value);
void STM32FXXXTim4_oc3m(uint8_t value);
void STM32FXXXTim4_ic3f(uint8_t value);
void STM32FXXXTim4_oc3pe(uint8_t bool);
void STM32FXXXTim4_oc3fe(uint8_t bool);
void STM32FXXXTim4_ic3psc(uint8_t value);
void STM32FXXXTim4_cc3s(uint8_t value);
// CCER
void STM32FXXXTim4_cc4np(uint8_t bool);
void STM32FXXXTim4_cc4p(uint8_t bool);
void STM32FXXXTim4_cc4e(uint8_t bool);
void STM32FXXXTim4_cc3np(uint8_t bool);
void STM32FXXXTim4_cc3p(uint8_t bool);
void STM32FXXXTim4_cc3e(uint8_t bool);
void STM32FXXXTim4_cc2np(uint8_t bool);
void STM32FXXXTim4_cc2p(uint8_t bool);
void STM32FXXXTim4_cc2e(uint8_t bool);
void STM32FXXXTim4_cc1np(uint8_t bool);
void STM32FXXXTim4_cc1p(uint8_t bool);
void STM32FXXXTim4_cc1e(uint8_t bool);
// CNT
void STM32FXXXTim4_cnt(uint16_t value);
uint16_t STM32FXXXTim4_get_cnt(void);
// PSC
void STM32FXXXTim4_psc(uint16_t value);
// ARR
void STM32FXXXTim4_arr(uint16_t value);
// CCR1
void STM32FXXXTim4_ccr1(uint16_t value);
// CCR2
void STM32FXXXTim4_ccr2(uint16_t value);
// CCR3
void STM32FXXXTim4_ccr3(uint16_t value);
// CCR4
void STM32FXXXTim4_ccr4(uint16_t value);
// DCR
void STM32FXXXTim4_dbl(uint8_t value);
void STM32FXXXTim4_dba(uint8_t value);
// DMAR
void STM32FXXXTim4_dmab(uint16_t value);
uint16_t STM32FXXXTim4_get_dmab(void);
/****************************************/
/*** TIM5 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim5Clock(uint8_t bool);
void STM32FXXXTim5Nvic(uint8_t bool);
/*** TIM5 Bit Mapping Header ***/
// CR1
void STM32FXXXTim5_ckd(uint8_t value);
uint8_t STM32FXXXTim5_get_ckd(void);
void STM32FXXXTim5_set_apre(uint8_t bool);
void STM32FXXXTim5_set_cms(uint8_t value);
void STM32FXXXTim5_set_dir(uint8_t bool);
void STM32FXXXTim5_set_opm(uint8_t bool);
void STM32FXXXTim5_set_urs(uint8_t bool);
void STM32FXXXTim5_set_udis(uint8_t bool);
void STM32FXXXTim5_cen(uint8_t bool);
// CR2
void STM32FXXXTim5_ti1s(uint8_t bool);
void STM32FXXXTim5_mms(uint8_t value);
void STM32FXXXTim5_ccds(uint8_t bool);
// SMCR
void STM32FXXXTim5_etp(uint8_t bool);
void STM32FXXXTim5_ece(uint8_t bool);
void STM32FXXXTim5_etps(uint8_t value);
void STM32FXXXTim5_etf(uint8_t value);
void STM32FXXXTim5_msm(uint8_t bool);
void STM32FXXXTim5_ts(uint8_t value);
void STM32FXXXTim5_sms(uint8_t value);
// DIER
void STM32FXXXTim5_tde(uint8_t bool);
void STM32FXXXTim5_cc4de(uint8_t bool);
void STM32FXXXTim5_cc3de(uint8_t bool);
void STM32FXXXTim5_cc2de(uint8_t bool);
void STM32FXXXTim5_cc1de(uint8_t bool);
void STM32FXXXTim5_ude(uint8_t bool);
void STM32FXXXTim5_tie(uint8_t bool);
void STM32FXXXTim5_cc4ie(uint8_t bool);
void STM32FXXXTim5_cc3ie(uint8_t bool);
void STM32FXXXTim5_cc2ie(uint8_t bool);
void STM32FXXXTim5_cc1ie(uint8_t bool);
void STM32FXXXTim5_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim5_cc4of(void);
void STM32FXXXTim5_clear_cc4of(void);
uint8_t STM32FXXXTim5_cc3of(void);
void STM32FXXXTim5_clear_cc3of(void);
uint8_t STM32FXXXTim5_cc2of(void);
void STM32FXXXTim5_clear_cc2of(void);
uint8_t STM32FXXXTim5_cc1of(void);
void STM32FXXXTim5_clear_cc1of(void);
uint8_t STM32FXXXTim5_tif(void);
void STM32FXXXTim5_clear_tif(void);
uint8_t STM32FXXXTim5_cc4if(void);
void STM32FXXXTim5_clear_cc4if(void);
uint8_t STM32FXXXTim5_cc3if(void);
void STM32FXXXTim5_clear_cc3if(void);
uint8_t STM32FXXXTim5_cc2if(void);
void STM32FXXXTim5_clear_cc2if(void);
uint8_t STM32FXXXTim5_cc1if(void);
void STM32FXXXTim5_clear_cc1if(void);
uint8_t STM32FXXXTim5_uif(void);
void STM32FXXXTim5_clear_uif(void);
// EGR
void STM32FXXXTim5_tg(void);
void STM32FXXXTim5_cc4g(void);
void STM32FXXXTim5_cc3g(void);
void STM32FXXXTim5_cc2g(void);
void STM32FXXXTim5_cc1g(void);
void STM32FXXXTim5_ug(void);
// CCMR1
void STM32FXXXTim5_oc2ce(uint8_t value);
void STM32FXXXTim5_oc2m(uint8_t value);
void STM32FXXXTim5_ic2f(uint8_t value);
void STM32FXXXTim5_oc2pe(uint8_t bool);
void STM32FXXXTim5_oc2fe(uint8_t bool);
void STM32FXXXTim5_ic2psc(uint8_t value);
void STM32FXXXTim5_cc2s(uint8_t value);
void STM32FXXXTim5_oc1ce(uint8_t value);
void STM32FXXXTim5_oc1m(uint8_t value);
void STM32FXXXTim5_ic1f(uint8_t value);
void STM32FXXXTim5_oc1pe(uint8_t bool);
void STM32FXXXTim5_oc1fe(uint8_t bool);
void STM32FXXXTim5_ic1psc(uint8_t value);
void STM32FXXXTim5_cc1s(uint8_t value);
// CCMR2
void STM32FXXXTim5_oc4ce(uint8_t value);
void STM32FXXXTim5_oc4m(uint8_t value);
void STM32FXXXTim5_ic4f(uint8_t value);
void STM32FXXXTim5_oc4pe(uint8_t bool);
void STM32FXXXTim5_oc4fe(uint8_t bool);
void STM32FXXXTim5_ic4psc(uint8_t value);
void STM32FXXXTim5_cc4s(uint8_t value);
void STM32FXXXTim5_oc3ce(uint8_t value);
void STM32FXXXTim5_oc3m(uint8_t value);
void STM32FXXXTim5_ic3f(uint8_t value);
void STM32FXXXTim5_oc3pe(uint8_t bool);
void STM32FXXXTim5_oc3fe(uint8_t bool);
void STM32FXXXTim5_ic3psc(uint8_t value);
void STM32FXXXTim5_cc3s(uint8_t value);
// CCER
void STM32FXXXTim5_cc4np(uint8_t bool);
void STM32FXXXTim5_cc4p(uint8_t bool);
void STM32FXXXTim5_cc4e(uint8_t bool);
void STM32FXXXTim5_cc3np(uint8_t bool);
void STM32FXXXTim5_cc3p(uint8_t bool);
void STM32FXXXTim5_cc3e(uint8_t bool);
void STM32FXXXTim5_cc2np(uint8_t bool);
void STM32FXXXTim5_cc2p(uint8_t bool);
void STM32FXXXTim5_cc2e(uint8_t bool);
void STM32FXXXTim5_cc1np(uint8_t bool);
void STM32FXXXTim5_cc1p(uint8_t bool);
void STM32FXXXTim5_cc1e(uint8_t bool);
// CNT
void STM32FXXXTim5_cnt(uint32_t value);
uint32_t STM32FXXXTim5_get_cnt(void);
// PSC
void STM32FXXXTim5_psc(uint16_t value);
// ARR
void STM32FXXXTim5_arr(uint32_t value);
// CCR1
void STM32FXXXTim5_ccr1(uint32_t value);
// CCR2
void STM32FXXXTim5_ccr2(uint32_t value);
// CCR3
void STM32FXXXTim5_ccr3(uint32_t value);
// CCR4
void STM32FXXXTim5_ccr4(uint32_t value);
// DCR
void STM32FXXXTim5_dbl(uint8_t value);
void STM32FXXXTim5_dba(uint8_t value);
// DMAR
void STM32FXXXTim5_dmab(uint16_t value);
uint16_t STM32FXXXTim5_get_dmab(void);
// OR
void STM32FXXXTim5_ti4_rmp(uint8_t value);

/*** INTERRUPT HEADER ***/
void TIM2_IRQHandler(void);
void TIM3_IRQHandler(void);
void TIM4_IRQHandler(void);
void TIM5_IRQHandler(void);

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

