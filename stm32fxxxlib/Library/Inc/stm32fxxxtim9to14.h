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
/*** TIMER 9 to 14 Bit Mapping TypeDef ***/
// CR1 9/12
typedef struct{
	void (*ckd)(uint8_t value);
	uint8_t (*get_ckd)(void);
	void (*apre)(uint8_t bool);
	void (*opm)(uint8_t bool);
	void (*urs)(uint8_t bool);
	void (*udis)(uint8_t bool);
	void (*cen)(uint8_t bool);
}STM32FXXXTIM9_CR1, STM32FXXXTIM12_CR1;
// CR1 10/11/13/14
typedef struct{
	void (*ckd)(uint8_t value);
	uint8_t (*get_ckd)(void);
	void (*apre)(uint8_t bool);
	void (*urs)(uint8_t bool);
	void (*udis)(uint8_t bool);
	void (*cen)(uint8_t bool);
}STM32FXXXTIM10_CR1, STM32FXXXTIM11_CR1, STM32FXXXTIM13_CR1, STM32FXXXTIM14_CR1;
// SMCR 9/12
typedef struct{
	void (*msm)(uint8_t bool);
	void (*ts)(uint8_t value);
	void (*sms)(uint8_t value);
}STM32FXXXTIM9_SMCR, STM32FXXXTIM12_SMCR;
// DIER 9/12
typedef struct{
	void (*tie)(uint8_t bool);
	void (*cc2ie)(uint8_t bool);
	void (*cc1ie)(uint8_t bool);
	void (*uie)(uint8_t bool);
}STM32FXXXTIM9_DIER, STM32FXXXTIM12_DIER;
// DIER 10/11/13/14
typedef struct{
	void (*cc1ie)(uint8_t bool);
	void (*uie)(uint8_t bool);
}STM32FXXXTIM10_DIER, STM32FXXXTIM11_DIER, STM32FXXXTIM13_DIER, STM32FXXXTIM14_DIER;
// SR 9/12
typedef struct{
	uint8_t (*cc2of)(void);
	void (*clear_cc2of)(void);
	uint8_t (*cc1of)(void);
	void (*clear_cc1of)(void);
	uint8_t (*tif)(void);
	void (*clear_tif)(void);
	uint8_t (*cc2if)(void);
	void (*clear_cc2if)(void);
	uint8_t (*cc1if)(void);
	void (*clear_cc1if)(void);
	uint8_t (*uif)(void);
	void (*clear_uif)(void);
}STM32FXXXTIM9_SR, STM32FXXXTIM12_SR;
// SR 10/11/13/14
typedef struct{
	uint8_t (*cc1of)(void);
	void (*clear_cc1of)(void);
	uint8_t (*cc1if)(void);
	void (*clear_cc1if)(void);
	uint8_t (*uif)(void);
	void (*clear_uif)(void);
}STM32FXXXTIM10_SR, STM32FXXXTIM11_SR, STM32FXXXTIM13_SR, STM32FXXXTIM14_SR;
// EGR 9/12
typedef struct{
	void (*tg)(void);
	void (*cc2g)(void);
	void (*cc1g)(void);
	void (*ug)(void);
}STM32FXXXTIM9_EGR, STM32FXXXTIM12_EGR;
// EGR 10/11/13/14
typedef struct{
	void (*cc1g)(void);
	void (*ug)(void);
}STM32FXXXTIM10_EGR, STM32FXXXTIM11_EGR, STM32FXXXTIM13_EGR, STM32FXXXTIM14_EGR;
// CCMR1 9/12
typedef struct{
	void (*oc2m)(uint8_t value);
	void (*ic2f)(uint8_t value);
	void (*oc2pe)(uint8_t bool);
	void (*oc2fe)(uint8_t bool);
	void (*ic2psc)(uint8_t value);
	void (*cc2s)(uint8_t value);
	void (*oc1m)(uint8_t value);
	void (*ic1f)(uint8_t value);
	void (*oc1pe)(uint8_t bool);
	void (*oc1fe)(uint8_t bool);
	void (*ic1psc)(uint8_t value);
	void (*cc1s)(uint8_t value);
}STM32FXXXTIM9_CCMR1, STM32FXXXTIM12_CCMR1;
// CCMR1 10/11/13/14
typedef struct{
	void (*oc1m)(uint8_t value);
	void (*ic1f)(uint8_t value);
	void (*oc1pe)(uint8_t bool);
	void (*oc1fe)(uint8_t bool);
	void (*ic1psc)(uint8_t value);
	void (*cc1s)(uint8_t value);
}STM32FXXXTIM10_CCMR1, STM32FXXXTIM11_CCMR1, STM32FXXXTIM13_CCMR1, STM32FXXXTIM14_CCMR1;
// CCER 9/12
typedef struct{
	void (*cc2np)(uint8_t bool);
	void (*cc2p)(uint8_t bool);
	void (*cc2e)(uint8_t bool);
	void (*cc1np)(uint8_t bool);
	void (*cc1p)(uint8_t bool);
	void (*cc1e)(uint8_t bool);
}STM32FXXXTIM9_CCER, STM32FXXXTIM12_CCER;
// CCER 10/11/13/14
typedef struct{
	void (*cc1np)(uint8_t bool);
	void (*cc1p)(uint8_t bool);
	void (*cc1e)(uint8_t bool);
}STM32FXXXTIM10_CCER, STM32FXXXTIM11_CCER, STM32FXXXTIM13_CCER, STM32FXXXTIM14_CCER;
/*** TIMER 9 TO 14 TypeDef***/
// ( 9/12 ) TIM
typedef struct
{

	/*** Bit Mapping ***/
	STM32FXXXTIM9_CR1* cr1;
	STM32FXXXTIM9_SMCR* smcr;
	STM32FXXXTIM9_DIER* dier;
	STM32FXXXTIM9_SR* sr;
	STM32FXXXTIM9_EGR* egr;
	STM32FXXXTIM9_CCMR1* ccmr1;
	STM32FXXXTIM9_CCER* ccer;
	void (*cnt)(uint16_t value);
	uint16_t (*get_cnt)(void);
	void (*psc)(uint16_t value);
	void (*arr)(uint16_t value);
	void (*ccr1)(uint16_t value);
	void (*ccr2)(uint16_t value);
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
}STM32FXXXTIM9obj, STM32FXXXTIM12obj;
// ( 10/11/13/14 ) TIM
typedef struct
{

	/*** Bit Mapping ***/
	STM32FXXXTIM10_CR1* cr1;
	STM32FXXXTIM10_DIER* dier;
	STM32FXXXTIM10_SR* sr;
	STM32FXXXTIM10_EGR* egr;
	STM32FXXXTIM10_CCMR1* ccmr1;
	STM32FXXXTIM10_CCER* ccer;
	void (*cnt)(uint16_t value);
	uint16_t (*get_cnt)(void);
	void (*psc)(uint16_t value);
	void (*arr)(uint16_t value);
	void (*ccr1)(uint16_t value);
	void (*or)(uint8_t value);
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
}STM32FXXXTIM10obj, STM32FXXXTIM11obj, STM32FXXXTIM13obj, STM32FXXXTIM14obj;
/************************/
/*** INIC TIM 9 to 14 ***/
/************************/
STM32FXXXTIM9obj tim9_enable(void);
STM32FXXXTIM9obj* tim9(void);
STM32FXXXTIM10obj tim10_enable(void);
STM32FXXXTIM10obj* tim10(void);
STM32FXXXTIM11obj tim11_enable(void);
STM32FXXXTIM11obj* tim11(void);
STM32FXXXTIM12obj tim12_enable(void);
STM32FXXXTIM12obj* tim12(void);
STM32FXXXTIM13obj tim13_enable(void);
STM32FXXXTIM13obj* tim13(void);
STM32FXXXTIM14obj tim14_enable(void);
STM32FXXXTIM14obj* tim14(void);
/****************************************/
/*** TIM9 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim9Clock(uint8_t bool);
void STM32FXXXTim9Nvic(uint8_t bool);
/*** TIM9 Bit Mapping Header ***/
// CR1
void STM32FXXXTim9_ckd(uint8_t value);
uint8_t STM32FXXXTim9_get_ckd(void);
void STM32FXXXTim9_set_apre(uint8_t bool);
void STM32FXXXTim9_set_opm(uint8_t bool);
void STM32FXXXTim9_set_urs(uint8_t bool);
void STM32FXXXTim9_set_udis(uint8_t bool);
void STM32FXXXTim9_cen(uint8_t bool);
// SMCR
void STM32FXXXTim9_msm(uint8_t bool);
void STM32FXXXTim9_ts(uint8_t value);
void STM32FXXXTim9_sms(uint8_t value);
// DIER
void STM32FXXXTim9_tie(uint8_t bool);
void STM32FXXXTim9_cc2ie(uint8_t bool);
void STM32FXXXTim9_cc1ie(uint8_t bool);
void STM32FXXXTim9_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim9_cc2of(void);
void STM32FXXXTim9_clear_cc2of(void);
uint8_t STM32FXXXTim9_cc1of(void);
void STM32FXXXTim9_clear_cc1of(void);
uint8_t STM32FXXXTim9_tif(void);
void STM32FXXXTim9_clear_tif(void);
uint8_t STM32FXXXTim9_cc2if(void);
void STM32FXXXTim9_clear_cc2if(void);
uint8_t STM32FXXXTim9_cc1if(void);
void STM32FXXXTim9_clear_cc1if(void);
uint8_t STM32FXXXTim9_uif(void);
void STM32FXXXTim9_clear_uif(void);
// EGR
void STM32FXXXTim9_tg(void);
void STM32FXXXTim9_cc2g(void);
void STM32FXXXTim9_cc1g(void);
void STM32FXXXTim9_ug(void);
// CCMR1
void STM32FXXXTim9_oc2m(uint8_t value);
void STM32FXXXTim9_ic2f(uint8_t value);
void STM32FXXXTim9_oc2pe(uint8_t bool);
void STM32FXXXTim9_oc2fe(uint8_t bool);
void STM32FXXXTim9_ic2psc(uint8_t value);
void STM32FXXXTim9_cc2s(uint8_t value);
void STM32FXXXTim9_oc1m(uint8_t value);
void STM32FXXXTim9_ic1f(uint8_t value);
void STM32FXXXTim9_oc1pe(uint8_t bool);
void STM32FXXXTim9_oc1fe(uint8_t bool);
void STM32FXXXTim9_ic1psc(uint8_t value);
void STM32FXXXTim9_cc1s(uint8_t value);
// CCER
void STM32FXXXTim9_cc2np(uint8_t bool);
void STM32FXXXTim9_cc2p(uint8_t bool);
void STM32FXXXTim9_cc2e(uint8_t bool);
void STM32FXXXTim9_cc1np(uint8_t bool);
void STM32FXXXTim9_cc1p(uint8_t bool);
void STM32FXXXTim9_cc1e(uint8_t bool);
// CNT
void STM32FXXXTim9_cnt(uint16_t value);
uint16_t STM32FXXXTim9_get_cnt(void);
// PSC
void STM32FXXXTim9_psc(uint16_t value);
// ARR
void STM32FXXXTim9_arr(uint16_t value);
// CCR1
void STM32FXXXTim9_ccr1(uint16_t value);
// CCR2
void STM32FXXXTim9_ccr2(uint16_t value);
/*****************************************/
/*** TIM10 Procedure & Function Header ***/
/*****************************************/
void STM32FXXXTim10Clock(uint8_t bool);
void STM32FXXXTim10Nvic(uint8_t bool);
/*** TIM10 Bit Mapping Header ***/
// CR1
void STM32FXXXTim10_ckd(uint8_t value);
uint8_t STM32FXXXTim10_get_ckd(void);
void STM32FXXXTim10_set_apre(uint8_t bool);
void STM32FXXXTim10_set_opm(uint8_t bool);
void STM32FXXXTim10_set_urs(uint8_t bool);
void STM32FXXXTim10_set_udis(uint8_t bool);
void STM32FXXXTim10_cen(uint8_t bool);
// DIER
void STM32FXXXTim10_tie(uint8_t bool);
void STM32FXXXTim10_cc2ie(uint8_t bool);
void STM32FXXXTim10_cc1ie(uint8_t bool);
void STM32FXXXTim10_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim10_cc2of(void);
void STM32FXXXTim10_clear_cc2of(void);
uint8_t STM32FXXXTim10_cc1of(void);
void STM32FXXXTim10_clear_cc1of(void);
uint8_t STM32FXXXTim10_tif(void);
void STM32FXXXTim10_clear_tif(void);
uint8_t STM32FXXXTim10_cc2if(void);
void STM32FXXXTim10_clear_cc2if(void);
uint8_t STM32FXXXTim10_cc1if(void);
void STM32FXXXTim10_clear_cc1if(void);
uint8_t STM32FXXXTim10_uif(void);
void STM32FXXXTim10_clear_uif(void);
// EGR
void STM32FXXXTim10_tg(void);
void STM32FXXXTim10_cc2g(void);
void STM32FXXXTim10_cc1g(void);
void STM32FXXXTim10_ug(void);
// CCMR1
void STM32FXXXTim10_oc2m(uint8_t value);
void STM32FXXXTim10_ic2f(uint8_t value);
void STM32FXXXTim10_oc2pe(uint8_t bool);
void STM32FXXXTim10_oc2fe(uint8_t bool);
void STM32FXXXTim10_ic2psc(uint8_t value);
void STM32FXXXTim10_cc2s(uint8_t value);
void STM32FXXXTim10_oc1m(uint8_t value);
void STM32FXXXTim10_ic1f(uint8_t value);
void STM32FXXXTim10_oc1pe(uint8_t bool);
void STM32FXXXTim10_oc1fe(uint8_t bool);
void STM32FXXXTim10_ic1psc(uint8_t value);
void STM32FXXXTim10_cc1s(uint8_t value);
// CCER
void STM32FXXXTim10_cc2np(uint8_t bool);
void STM32FXXXTim10_cc2p(uint8_t bool);
void STM32FXXXTim10_cc2e(uint8_t bool);
void STM32FXXXTim10_cc1np(uint8_t bool);
void STM32FXXXTim10_cc1p(uint8_t bool);
void STM32FXXXTim10_cc1e(uint8_t bool);
// CNT
void STM32FXXXTim10_cnt(uint16_t value);
uint16_t STM32FXXXTim10_get_cnt(void);
// PSC
void STM32FXXXTim10_psc(uint16_t value);
// ARR
void STM32FXXXTim10_arr(uint16_t value);
// CCR1
void STM32FXXXTim10_ccr1(uint16_t value);
// OR
void STM32FXXXTim10_or(uint8_t value);
/*****************************************/
/*** TIM11 Procedure & Function Header ***/
/*****************************************/
void STM32FXXXTim11Clock(uint8_t bool);
void STM32FXXXTim11Nvic(uint8_t bool);
/*** TIM11 Bit Mapping Header ***/
// CR1
void STM32FXXXTim11_ckd(uint8_t value);
uint8_t STM32FXXXTim11_get_ckd(void);
void STM32FXXXTim11_set_apre(uint8_t bool);
void STM32FXXXTim11_set_opm(uint8_t bool);
void STM32FXXXTim11_set_urs(uint8_t bool);
void STM32FXXXTim11_set_udis(uint8_t bool);
void STM32FXXXTim11_cen(uint8_t bool);
// DIER
void STM32FXXXTim11_tie(uint8_t bool);
void STM32FXXXTim11_cc2ie(uint8_t bool);
void STM32FXXXTim11_cc1ie(uint8_t bool);
void STM32FXXXTim11_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim11_cc2of(void);
void STM32FXXXTim11_clear_cc2of(void);
uint8_t STM32FXXXTim11_cc1of(void);
void STM32FXXXTim11_clear_cc1of(void);
uint8_t STM32FXXXTim11_tif(void);
void STM32FXXXTim11_clear_tif(void);
uint8_t STM32FXXXTim11_cc2if(void);
void STM32FXXXTim11_clear_cc2if(void);
uint8_t STM32FXXXTim11_cc1if(void);
void STM32FXXXTim11_clear_cc1if(void);
uint8_t STM32FXXXTim11_uif(void);
void STM32FXXXTim11_clear_uif(void);
// EGR
void STM32FXXXTim11_tg(void);
void STM32FXXXTim11_cc2g(void);
void STM32FXXXTim11_cc1g(void);
void STM32FXXXTim11_ug(void);
// CCMR1
void STM32FXXXTim11_oc2m(uint8_t value);
void STM32FXXXTim11_ic2f(uint8_t value);
void STM32FXXXTim11_oc2pe(uint8_t bool);
void STM32FXXXTim11_oc2fe(uint8_t bool);
void STM32FXXXTim11_ic2psc(uint8_t value);
void STM32FXXXTim11_cc2s(uint8_t value);
void STM32FXXXTim11_oc1m(uint8_t value);
void STM32FXXXTim11_ic1f(uint8_t value);
void STM32FXXXTim11_oc1pe(uint8_t bool);
void STM32FXXXTim11_oc1fe(uint8_t bool);
void STM32FXXXTim11_ic1psc(uint8_t value);
void STM32FXXXTim11_cc1s(uint8_t value);
// CCER
void STM32FXXXTim11_cc2np(uint8_t bool);
void STM32FXXXTim11_cc2p(uint8_t bool);
void STM32FXXXTim11_cc2e(uint8_t bool);
void STM32FXXXTim11_cc1np(uint8_t bool);
void STM32FXXXTim11_cc1p(uint8_t bool);
void STM32FXXXTim11_cc1e(uint8_t bool);
// CNT
void STM32FXXXTim11_cnt(uint16_t value);
uint16_t STM32FXXXTim11_get_cnt(void);
// PSC
void STM32FXXXTim11_psc(uint16_t value);
// ARR
void STM32FXXXTim11_arr(uint16_t value);
// CCR1
void STM32FXXXTim11_ccr1(uint16_t value);
// OR
void STM32FXXXTim11_or(uint8_t value);
/*****************************************/
/*** TIM12 Procedure & Function Header ***/
/*****************************************/
void STM32FXXXTim12Clock(uint8_t bool);
void STM32FXXXTim12Nvic(uint8_t bool);
/*** TIM12 Bit Mapping Header ***/
// CR1
void STM32FXXXTim12_ckd(uint8_t value);
uint8_t STM32FXXXTim12_get_ckd(void);
void STM32FXXXTim12_set_apre(uint8_t bool);
void STM32FXXXTim12_set_opm(uint8_t bool);
void STM32FXXXTim12_set_urs(uint8_t bool);
void STM32FXXXTim12_set_udis(uint8_t bool);
void STM32FXXXTim12_cen(uint8_t bool);
// SMCR
void STM32FXXXTim12_msm(uint8_t bool);
void STM32FXXXTim12_ts(uint8_t value);
void STM32FXXXTim12_sms(uint8_t value);
// DIER
void STM32FXXXTim12_tie(uint8_t bool);
void STM32FXXXTim12_cc2ie(uint8_t bool);
void STM32FXXXTim12_cc1ie(uint8_t bool);
void STM32FXXXTim12_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim12_cc2of(void);
void STM32FXXXTim12_clear_cc2of(void);
uint8_t STM32FXXXTim12_cc1of(void);
void STM32FXXXTim12_clear_cc1of(void);
uint8_t STM32FXXXTim12_tif(void);
void STM32FXXXTim12_clear_tif(void);
uint8_t STM32FXXXTim12_cc2if(void);
void STM32FXXXTim12_clear_cc2if(void);
uint8_t STM32FXXXTim12_cc1if(void);
void STM32FXXXTim12_clear_cc1if(void);
uint8_t STM32FXXXTim12_uif(void);
void STM32FXXXTim12_clear_uif(void);
// EGR
void STM32FXXXTim12_tg(void);
void STM32FXXXTim12_cc2g(void);
void STM32FXXXTim12_cc1g(void);
void STM32FXXXTim12_ug(void);
// CCMR1
void STM32FXXXTim12_oc2m(uint8_t value);
void STM32FXXXTim12_ic2f(uint8_t value);
void STM32FXXXTim12_oc2pe(uint8_t bool);
void STM32FXXXTim12_oc2fe(uint8_t bool);
void STM32FXXXTim12_ic2psc(uint8_t value);
void STM32FXXXTim12_cc2s(uint8_t value);
void STM32FXXXTim12_oc1m(uint8_t value);
void STM32FXXXTim12_ic1f(uint8_t value);
void STM32FXXXTim12_oc1pe(uint8_t bool);
void STM32FXXXTim12_oc1fe(uint8_t bool);
void STM32FXXXTim12_ic1psc(uint8_t value);
void STM32FXXXTim12_cc1s(uint8_t value);
// CCER
void STM32FXXXTim12_cc2np(uint8_t bool);
void STM32FXXXTim12_cc2p(uint8_t bool);
void STM32FXXXTim12_cc2e(uint8_t bool);
void STM32FXXXTim12_cc1np(uint8_t bool);
void STM32FXXXTim12_cc1p(uint8_t bool);
void STM32FXXXTim12_cc1e(uint8_t bool);
// CNT
void STM32FXXXTim12_cnt(uint16_t value);
uint16_t STM32FXXXTim12_get_cnt(void);
// PSC
void STM32FXXXTim12_psc(uint16_t value);
// ARR
void STM32FXXXTim12_arr(uint16_t value);
// CCR1
void STM32FXXXTim12_ccr1(uint16_t value);
// CCR2
void STM32FXXXTim12_ccr2(uint16_t value);
/*****************************************/
/*** TIM13 Procedure & Function Header ***/
/*****************************************/
void STM32FXXXTim13Clock(uint8_t bool);
void STM32FXXXTim13Nvic(uint8_t bool);
/*** TIM13 Bit Mapping Header ***/
// CR1
void STM32FXXXTim13_ckd(uint8_t value);
uint8_t STM32FXXXTim13_get_ckd(void);
void STM32FXXXTim13_set_apre(uint8_t bool);
void STM32FXXXTim13_set_opm(uint8_t bool);
void STM32FXXXTim13_set_urs(uint8_t bool);
void STM32FXXXTim13_set_udis(uint8_t bool);
void STM32FXXXTim13_cen(uint8_t bool);
// DIER
void STM32FXXXTim13_tie(uint8_t bool);
void STM32FXXXTim13_cc2ie(uint8_t bool);
void STM32FXXXTim13_cc1ie(uint8_t bool);
void STM32FXXXTim13_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim13_cc2of(void);
void STM32FXXXTim13_clear_cc2of(void);
uint8_t STM32FXXXTim13_cc1of(void);
void STM32FXXXTim13_clear_cc1of(void);
uint8_t STM32FXXXTim13_tif(void);
void STM32FXXXTim13_clear_tif(void);
uint8_t STM32FXXXTim13_cc2if(void);
void STM32FXXXTim13_clear_cc2if(void);
uint8_t STM32FXXXTim13_cc1if(void);
void STM32FXXXTim13_clear_cc1if(void);
uint8_t STM32FXXXTim13_uif(void);
void STM32FXXXTim13_clear_uif(void);
// EGR
void STM32FXXXTim13_tg(void);
void STM32FXXXTim13_cc2g(void);
void STM32FXXXTim13_cc1g(void);
void STM32FXXXTim13_ug(void);
// CCMR1
void STM32FXXXTim13_oc2m(uint8_t value);
void STM32FXXXTim13_ic2f(uint8_t value);
void STM32FXXXTim13_oc2pe(uint8_t bool);
void STM32FXXXTim13_oc2fe(uint8_t bool);
void STM32FXXXTim13_ic2psc(uint8_t value);
void STM32FXXXTim13_cc2s(uint8_t value);
void STM32FXXXTim13_oc1m(uint8_t value);
void STM32FXXXTim13_ic1f(uint8_t value);
void STM32FXXXTim13_oc1pe(uint8_t bool);
void STM32FXXXTim13_oc1fe(uint8_t bool);
void STM32FXXXTim13_ic1psc(uint8_t value);
void STM32FXXXTim13_cc1s(uint8_t value);
// CCER
void STM32FXXXTim13_cc2np(uint8_t bool);
void STM32FXXXTim13_cc2p(uint8_t bool);
void STM32FXXXTim13_cc2e(uint8_t bool);
void STM32FXXXTim13_cc1np(uint8_t bool);
void STM32FXXXTim13_cc1p(uint8_t bool);
void STM32FXXXTim13_cc1e(uint8_t bool);
// CNT
void STM32FXXXTim13_cnt(uint16_t value);
uint16_t STM32FXXXTim13_get_cnt(void);
// PSC
void STM32FXXXTim13_psc(uint16_t value);
// ARR
void STM32FXXXTim13_arr(uint16_t value);
// CCR1
void STM32FXXXTim13_ccr1(uint16_t value);
// OR
void STM32FXXXTim13_or(uint8_t value);
/*****************************************/
/*** TIM14 Procedure & Function Header ***/
/*****************************************/
void STM32FXXXTim14Clock(uint8_t bool);
void STM32FXXXTim14Nvic(uint8_t bool);
/*** TIM14 Bit Mapping Header ***/
// CR1
void STM32FXXXTim14_ckd(uint8_t value);
uint8_t STM32FXXXTim14_get_ckd(void);
void STM32FXXXTim14_set_apre(uint8_t bool);
void STM32FXXXTim14_set_opm(uint8_t bool);
void STM32FXXXTim14_set_urs(uint8_t bool);
void STM32FXXXTim14_set_udis(uint8_t bool);
void STM32FXXXTim14_cen(uint8_t bool);
// DIER
void STM32FXXXTim14_tie(uint8_t bool);
void STM32FXXXTim14_cc2ie(uint8_t bool);
void STM32FXXXTim14_cc1ie(uint8_t bool);
void STM32FXXXTim14_uie(uint8_t bool);
// SR
uint8_t STM32FXXXTim14_cc2of(void);
void STM32FXXXTim14_clear_cc2of(void);
uint8_t STM32FXXXTim14_cc1of(void);
void STM32FXXXTim14_clear_cc1of(void);
uint8_t STM32FXXXTim14_tif(void);
void STM32FXXXTim14_clear_tif(void);
uint8_t STM32FXXXTim14_cc2if(void);
void STM32FXXXTim14_clear_cc2if(void);
uint8_t STM32FXXXTim14_cc1if(void);
void STM32FXXXTim14_clear_cc1if(void);
uint8_t STM32FXXXTim14_uif(void);
void STM32FXXXTim14_clear_uif(void);
// EGR
void STM32FXXXTim14_tg(void);
void STM32FXXXTim14_cc2g(void);
void STM32FXXXTim14_cc1g(void);
void STM32FXXXTim14_ug(void);
// CCMR1
void STM32FXXXTim14_oc2m(uint8_t value);
void STM32FXXXTim14_ic2f(uint8_t value);
void STM32FXXXTim14_oc2pe(uint8_t bool);
void STM32FXXXTim14_oc2fe(uint8_t bool);
void STM32FXXXTim14_ic2psc(uint8_t value);
void STM32FXXXTim14_cc2s(uint8_t value);
void STM32FXXXTim14_oc1m(uint8_t value);
void STM32FXXXTim14_ic1f(uint8_t value);
void STM32FXXXTim14_oc1pe(uint8_t bool);
void STM32FXXXTim14_oc1fe(uint8_t bool);
void STM32FXXXTim14_ic1psc(uint8_t value);
void STM32FXXXTim14_cc1s(uint8_t value);
// CCER
void STM32FXXXTim14_cc2np(uint8_t bool);
void STM32FXXXTim14_cc2p(uint8_t bool);
void STM32FXXXTim14_cc2e(uint8_t bool);
void STM32FXXXTim14_cc1np(uint8_t bool);
void STM32FXXXTim14_cc1p(uint8_t bool);
void STM32FXXXTim14_cc1e(uint8_t bool);
// CNT
void STM32FXXXTim14_cnt(uint16_t value);
uint16_t STM32FXXXTim14_get_cnt(void);
// PSC
void STM32FXXXTim14_psc(uint16_t value);
// ARR
void STM32FXXXTim14_arr(uint16_t value);
// CCR1
void STM32FXXXTim14_ccr1(uint16_t value);
// OR
void STM32FXXXTim14_or(uint8_t value);

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

