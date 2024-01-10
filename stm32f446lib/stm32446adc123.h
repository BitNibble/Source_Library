/******************************************************************************
	STM32 446 ADC123
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 19062023
Comment:
	
*******************************************************************************/
#ifndef _STM32446ADC123_H_
	#define _STM32446ADC123_H_
/*** Library ***/
#include "stm32446adc.h"
/*** ADC TypeDef ***/
// ADC -> ADC1
typedef struct
{
	ADC_TypeDef* reg;
	STM32446ADCCOMMONobj* common;
	/*** Bit Mapping ***/
	STM32446ADC_SR* sr;
	STM32446ADC_CR1* cr1;
	STM32446ADC_CR2* cr2;
	STM32446ADC_SMPR1* smpr1;
	STM32446ADC_SMPR2* smpr2;
	void (*jofr1)(uint16_t value);
	void (*jofr2)(uint16_t value);
	void (*jofr3)(uint16_t value);
	void (*jofr4)(uint16_t value);
	void (*htr)(uint16_t value);
	void (*ltr)(uint16_t value);
	STM32446ADC_SQR1* sqr1;
	STM32446ADC_SQR2* sqr2;
	STM32446ADC_SQR3* sqr3;
	STM32446ADC_JSQR* jsqr;
	uint16_t (*jdr1)(void);
	uint16_t (*jdr2)(void);
	uint16_t (*jdr3)(void);
	uint16_t (*jdr4)(void);
	uint16_t (*dr)(void);
	/*** Other ***/
	STM32446ADC1single* single;
	void (*iclock)(uint8_t bool);
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
}STM32446ADC1obj;
// ADC -> ADC2
typedef struct
{
	ADC_TypeDef* reg;
	STM32446ADCCOMMONobj* common;
	#if defined(_STM32446ADC123_H_)
		STM32446ADC_SR sr;
		STM32446ADC_CR1 cr1;
		STM32446ADC_CR2 cr2;
		STM32446ADC_SMPR1 smpr1;
		STM32446ADC_SMPR2 smpr2;
		void (*jofr1)(uint16_t value);
		void (*jofr2)(uint16_t value);
		void (*jofr3)(uint16_t value);
		void (*jofr4)(uint16_t value);
		void (*htr)(uint16_t value);
		void (*ltr)(uint16_t value);
		STM32446ADC_SQR1 sqr1;
		STM32446ADC_SQR2 sqr2;
		STM32446ADC_SQR3 sqr3;
		STM32446ADC_JSQR jsqr;
		uint16_t (*jdr1)(void);
		uint16_t (*jdr2)(void);
		uint16_t (*jdr3)(void);
		uint16_t (*jdr4)(void);
		uint16_t (*dr)(void);
		STM32446ADC2single single;
		void (*iclock)(uint8_t bool);
		void (*clock)(uint8_t bool);
		void (*nvic)(uint8_t bool);
	#endif
}STM32446ADC2obj;
// ADC -> ADC3
typedef struct
{
	ADC_TypeDef* reg;
	STM32446ADCCOMMONobj* common;
	#if defined(_STM32446ADC123_H_)
		STM32446ADC_SR sr;
		STM32446ADC_CR1 cr1;
		STM32446ADC_CR2 cr2;
		STM32446ADC_SMPR1 smpr1;
		STM32446ADC_SMPR2 smpr2;
		void (*jofr1)(uint16_t value);
		void (*jofr2)(uint16_t value);
		void (*jofr3)(uint16_t value);
		void (*jofr4)(uint16_t value);
		void (*htr)(uint16_t value);
		void (*ltr)(uint16_t value);
		STM32446ADC_SQR1 sqr1;
		STM32446ADC_SQR2 sqr2;
		STM32446ADC_SQR3 sqr3;
		STM32446ADC_JSQR jsqr;
		uint16_t (*jdr1)(void);
		uint16_t (*jdr2)(void);
		uint16_t (*jdr3)(void);
		uint16_t (*jdr4)(void);
		uint16_t (*dr)(void);
		STM32446ADC3single single;
		void (*iclock)(uint8_t bool);
		void (*clock)(uint8_t bool);
		void (*nvic)(uint8_t bool);
	#endif
}STM32446ADC3obj;
// INIC
STM32446ADC1obj adc1_inic(void);
STM32446ADC1obj* adc1(void);
STM32446ADC2obj adc2_inic(void);
STM32446ADC3obj adc3_inic(void);
/***** ADC1 Procedure & Function Header ******/
/*** ADC1 ***/
void STM32446Adc1IClock(uint8_t bool);
void STM32446Adc1Clock(uint8_t bool);
void STM32446Adc1Nvic(uint8_t bool);
void STM32446Adc1Inic(void);
void STM32446Adc1VBAT(void);
void STM32446Adc1TEMP(void);
void STM32446Adc1Start(void);
/*** ADC1 Bit Mapping Header ***/
// SR
uint8_t STM32446ADC1_sr_ovr(void);
void STM32446ADC1_sr_clear_ovr(void);
uint8_t STM32446ADC1_sr_strt(void);
void STM32446ADC1_sr_clear_strt(void);
uint8_t STM32446ADC1_sr_jstrt(void);
void STM32446ADC1_sr_clear_jstrt(void);
uint8_t STM32446ADC1_sr_jeoc(void);
void STM32446ADC1_sr_clear_jeoc(void);
uint8_t STM32446ADC1_sr_eoc(void);
void STM32446ADC1_sr_clear_eoc(void);
uint8_t STM32446ADC1_sr_awd(void);
void STM32446ADC1_sr_clear_awd(void);
// CR1
void STM32446ADC1_cr1_ovrie(uint8_t bool);
void STM32446ADC1_cr1_res(uint8_t value);
void STM32446ADC1_cr1_awden(uint8_t bool);
void STM32446ADC1_cr1_jawden(uint8_t bool);
void STM32446ADC1_cr1_discnum(uint8_t value);
void STM32446ADC1_cr1_jdiscen(uint8_t bool);
void STM32446ADC1_cr1_discen(uint8_t bool);
void STM32446ADC1_cr1_jauto(uint8_t bool);
void STM32446ADC1_cr1_awdsgl(uint8_t bool);
void STM32446ADC1_cr1_scan(uint8_t bool);
void STM32446ADC1_cr1_jeocie(uint8_t bool);
void STM32446ADC1_cr1_awdie(uint8_t bool);
void STM32446ADC1_cr1_eocie(uint8_t bool);
void STM32446ADC1_cr1_awdch(uint8_t value);
// CR2
void STM32446ADC1_cr2_swstart(uint8_t bool);
uint8_t STM32446ADC1_cr2_read_swstart(void);
void STM32446ADC1_cr2_exten(uint8_t value);
void STM32446ADC1_cr2_extsel(uint8_t value);
void STM32446ADC1_cr2_jswstart(uint8_t bool);
void STM32446ADC1_cr2_jexten(uint8_t value);
void STM32446ADC1_cr2_jextsel(uint8_t value);
void STM32446ADC1_cr2_align(uint8_t bool);
void STM32446ADC1_cr2_eocs(uint8_t bool);
void STM32446ADC1_cr2_dds(uint8_t bool);
void STM32446ADC1_cr2_dma(uint8_t bool);
void STM32446ADC1_cr2_cont(uint8_t bool);
void STM32446ADC1_cr2_adon(uint8_t bool);
// SMPR1
void STM32446ADC1_smpr1_smp18(uint8_t value);
void STM32446ADC1_smpr1_smp17(uint8_t value);
void STM32446ADC1_smpr1_smp16(uint8_t value);
void STM32446ADC1_smpr1_smp15(uint8_t value);
void STM32446ADC1_smpr1_smp14(uint8_t value);
void STM32446ADC1_smpr1_smp13(uint8_t value);
void STM32446ADC1_smpr1_smp12(uint8_t value);
void STM32446ADC1_smpr1_smp11(uint8_t value);
void STM32446ADC1_smpr1_smp10(uint8_t value);
// SMPR2
void STM32446ADC1_smpr2_smp9(uint8_t value);
void STM32446ADC1_smpr2_smp8(uint8_t value);
void STM32446ADC1_smpr2_smp7(uint8_t value);
void STM32446ADC1_smpr2_smp6(uint8_t value);
void STM32446ADC1_smpr2_smp5(uint8_t bool);
void STM32446ADC1_smpr2_smp4(uint8_t value);
void STM32446ADC1_smpr2_smp3(uint8_t value);
void STM32446ADC1_smpr2_smp2(uint8_t value);
void STM32446ADC1_smpr2_smp1(uint8_t value);
void STM32446ADC1_smpr2_smp0(uint8_t value);
// Other
void STM32446ADC1_jofr1(uint16_t value);
void STM32446ADC1_jofr2(uint16_t value);
void STM32446ADC1_jofr3(uint16_t value);
void STM32446ADC1_jofr4(uint16_t value);
void STM32446ADC1_htr(uint16_t value);
void STM32446ADC1_ltr(uint16_t value);
// SQR1
void STM32446ADC1_sqr1_l(uint8_t value);
void STM32446ADC1_sqr1_sq16(uint8_t value);
void STM32446ADC1_sqr1_sq15(uint8_t value);
void STM32446ADC1_sqr1_sq14(uint8_t value);
void STM32446ADC1_sqr1_sq13(uint8_t value);
// SQR2
void STM32446ADC1_sqr2_sq12(uint8_t value);
void STM32446ADC1_sqr2_sq11(uint8_t value);
void STM32446ADC1_sqr2_sq10(uint8_t value);
void STM32446ADC1_sqr2_sq9(uint8_t value);
void STM32446ADC1_sqr2_sq8(uint8_t value);
void STM32446ADC1_sqr2_sq7(uint8_t value);
// SQR3
void STM32446ADC1_sqr3_sq6(uint8_t value);
void STM32446ADC1_sqr3_sq5(uint8_t value);
void STM32446ADC1_sqr3_sq4(uint8_t value);
void STM32446ADC1_sqr3_sq3(uint8_t value);
void STM32446ADC1_sqr3_sq2(uint8_t value);
void STM32446ADC1_sqr3_sq1(uint8_t value);
// JSQR
void STM32446ADC1_jsqr_jl(uint8_t value);
void STM32446ADC1_jsqr_jsq4(uint8_t value);
void STM32446ADC1_jsqr_jsq3(uint8_t value);
void STM32446ADC1_jsqr_jsq2(uint8_t value);
void STM32446ADC1_jsqr_jsq1(uint8_t value);
// Other
uint16_t STM32446ADC1_jdr1(void);
uint16_t STM32446ADC1_jdr2(void);
uint16_t STM32446ADC1_jdr3(void);
uint16_t STM32446ADC1_jdr4(void);
uint16_t STM32446ADC1_dr(void);
/*** ADC2 ***/
void STM32446Adc2IClock(uint8_t bool);
void STM32446Adc2Clock(uint8_t bool);
void STM32446Adc2Nvic(uint8_t bool);
void STM32446Adc2Inic(void);
void STM32446Adc2Start(void);
/*** ADC2 Bit Mapping Header ***/
// SR
uint8_t STM32446ADC2_sr_ovr(void);
void STM32446ADC2_sr_clear_ovr(void);
uint8_t STM32446ADC2_sr_strt(void);
void STM32446ADC2_sr_clear_strt(void);
uint8_t STM32446ADC2_sr_jstrt(void);
void STM32446ADC2_sr_clear_jstrt(void);
uint8_t STM32446ADC2_sr_jeoc(void);
void STM32446ADC2_sr_clear_jeoc(void);
uint8_t STM32446ADC2_sr_eoc(void);
void STM32446ADC2_sr_clear_eoc(void);
uint8_t STM32446ADC2_sr_awd(void);
void STM32446ADC2_sr_clear_awd(void);
// CR1
void STM32446ADC2_cr1_ovrie(uint8_t bool);
void STM32446ADC2_cr1_res(uint8_t value);
void STM32446ADC2_cr1_awden(uint8_t bool);
void STM32446ADC2_cr1_jawden(uint8_t bool);
void STM32446ADC2_cr1_discnum(uint8_t value);
void STM32446ADC2_cr1_jdiscen(uint8_t bool);
void STM32446ADC2_cr1_discen(uint8_t bool);
void STM32446ADC2_cr1_jauto(uint8_t bool);
void STM32446ADC2_cr1_awdsgl(uint8_t bool);
void STM32446ADC2_cr1_scan(uint8_t bool);
void STM32446ADC2_cr1_jeocie(uint8_t bool);
void STM32446ADC2_cr1_awdie(uint8_t bool);
void STM32446ADC2_cr1_eocie(uint8_t bool);
void STM32446ADC2_cr1_awdch(uint8_t value);
// CR2
void STM32446ADC2_cr2_swstart(uint8_t bool);
uint8_t STM32446ADC2_cr2_read_swstart(void);
void STM32446ADC2_cr2_exten(uint8_t value);
void STM32446ADC2_cr2_extsel(uint8_t value);
void STM32446ADC2_cr2_jswstart(uint8_t bool);
void STM32446ADC2_cr2_jexten(uint8_t value);
void STM32446ADC2_cr2_jextsel(uint8_t value);
void STM32446ADC2_cr2_align(uint8_t bool);
void STM32446ADC2_cr2_eocs(uint8_t bool);
void STM32446ADC2_cr2_dds(uint8_t bool);
void STM32446ADC2_cr2_dma(uint8_t bool);
void STM32446ADC2_cr2_cont(uint8_t bool);
void STM32446ADC2_cr2_adon(uint8_t bool);
// SMPR1
void STM32446ADC2_smpr1_smp18(uint8_t value);
void STM32446ADC2_smpr1_smp17(uint8_t value);
void STM32446ADC2_smpr1_smp16(uint8_t value);
void STM32446ADC2_smpr1_smp15(uint8_t value);
void STM32446ADC2_smpr1_smp14(uint8_t value);
void STM32446ADC2_smpr1_smp13(uint8_t value);
void STM32446ADC2_smpr1_smp12(uint8_t value);
void STM32446ADC2_smpr1_smp11(uint8_t value);
void STM32446ADC2_smpr1_smp10(uint8_t value);
// SMPR2
void STM32446ADC2_smpr2_smp9(uint8_t value);
void STM32446ADC2_smpr2_smp8(uint8_t value);
void STM32446ADC2_smpr2_smp7(uint8_t value);
void STM32446ADC2_smpr2_smp6(uint8_t value);
void STM32446ADC2_smpr2_smp5(uint8_t bool);
void STM32446ADC2_smpr2_smp4(uint8_t value);
void STM32446ADC2_smpr2_smp3(uint8_t value);
void STM32446ADC2_smpr2_smp2(uint8_t value);
void STM32446ADC2_smpr2_smp1(uint8_t value);
void STM32446ADC2_smpr2_smp0(uint8_t value);
// Other
void STM32446ADC2_jofr1(uint16_t value);
void STM32446ADC2_jofr2(uint16_t value);
void STM32446ADC2_jofr3(uint16_t value);
void STM32446ADC2_jofr4(uint16_t value);
void STM32446ADC2_htr(uint16_t value);
void STM32446ADC2_ltr(uint16_t value);
// SQR1
void STM32446ADC2_sqr1_l(uint8_t value);
void STM32446ADC2_sqr1_sq16(uint8_t value);
void STM32446ADC2_sqr1_sq15(uint8_t value);
void STM32446ADC2_sqr1_sq14(uint8_t value);
void STM32446ADC2_sqr1_sq13(uint8_t value);
// SQR2
void STM32446ADC2_sqr2_sq12(uint8_t value);
void STM32446ADC2_sqr2_sq11(uint8_t value);
void STM32446ADC2_sqr2_sq10(uint8_t value);
void STM32446ADC2_sqr2_sq9(uint8_t value);
void STM32446ADC2_sqr2_sq8(uint8_t value);
void STM32446ADC2_sqr2_sq7(uint8_t value);
// SQR3
void STM32446ADC2_sqr3_sq6(uint8_t value);
void STM32446ADC2_sqr3_sq5(uint8_t value);
void STM32446ADC2_sqr3_sq4(uint8_t value);
void STM32446ADC2_sqr3_sq3(uint8_t value);
void STM32446ADC2_sqr3_sq2(uint8_t value);
void STM32446ADC2_sqr3_sq1(uint8_t value);
// JSQR
void STM32446ADC2_jsqr_jl(uint8_t value);
void STM32446ADC2_jsqr_jsq4(uint8_t value);
void STM32446ADC2_jsqr_jsq3(uint8_t value);
void STM32446ADC2_jsqr_jsq2(uint8_t value);
void STM32446ADC2_jsqr_jsq1(uint8_t value);
// Other
uint16_t STM32446ADC2_jdr1(void);
uint16_t STM32446ADC2_jdr2(void);
uint16_t STM32446ADC2_jdr3(void);
uint16_t STM32446ADC2_jdr4(void);
uint16_t STM32446ADC2_dr(void);
/*** ADC3 ***/
void STM32446Adc3IClock(uint8_t bool);
void STM32446Adc3Clock(uint8_t bool);
void STM32446Adc3Nvic(uint8_t bool);
void STM32446Adc3Inic(void);
void STM32446Adc3Start(void);
/*** ADC3 Bit Mapping Header ***/
// SR
uint8_t STM32446ADC3_sr_ovr(void);
void STM32446ADC3_sr_clear_ovr(void);
uint8_t STM32446ADC3_sr_strt(void);
void STM32446ADC3_sr_clear_strt(void);
uint8_t STM32446ADC3_sr_jstrt(void);
void STM32446ADC3_sr_clear_jstrt(void);
uint8_t STM32446ADC3_sr_jeoc(void);
void STM32446ADC3_sr_clear_jeoc(void);
uint8_t STM32446ADC3_sr_eoc(void);
void STM32446ADC3_sr_clear_eoc(void);
uint8_t STM32446ADC3_sr_awd(void);
void STM32446ADC3_sr_clear_awd(void);
// CR1
void STM32446ADC3_cr1_ovrie(uint8_t bool);
void STM32446ADC3_cr1_res(uint8_t value);
void STM32446ADC3_cr1_awden(uint8_t bool);
void STM32446ADC3_cr1_jawden(uint8_t bool);
void STM32446ADC3_cr1_discnum(uint8_t value);
void STM32446ADC3_cr1_jdiscen(uint8_t bool);
void STM32446ADC3_cr1_discen(uint8_t bool);
void STM32446ADC3_cr1_jauto(uint8_t bool);
void STM32446ADC3_cr1_awdsgl(uint8_t bool);
void STM32446ADC3_cr1_scan(uint8_t bool);
void STM32446ADC3_cr1_jeocie(uint8_t bool);
void STM32446ADC3_cr1_awdie(uint8_t bool);
void STM32446ADC3_cr1_eocie(uint8_t bool);
void STM32446ADC3_cr1_awdch(uint8_t value);
// CR2
void STM32446ADC3_cr2_swstart(uint8_t bool);
uint8_t STM32446ADC3_cr2_read_swstart(void);
void STM32446ADC3_cr2_exten(uint8_t value);
void STM32446ADC3_cr2_extsel(uint8_t value);
void STM32446ADC3_cr2_jswstart(uint8_t bool);
void STM32446ADC3_cr2_jexten(uint8_t value);
void STM32446ADC3_cr2_jextsel(uint8_t value);
void STM32446ADC3_cr2_align(uint8_t bool);
void STM32446ADC3_cr2_eocs(uint8_t bool);
void STM32446ADC3_cr2_dds(uint8_t bool);
void STM32446ADC3_cr2_dma(uint8_t bool);
void STM32446ADC3_cr2_cont(uint8_t bool);
void STM32446ADC3_cr2_adon(uint8_t bool);
// SMPR1
void STM32446ADC3_smpr1_smp18(uint8_t value);
void STM32446ADC3_smpr1_smp17(uint8_t value);
void STM32446ADC3_smpr1_smp16(uint8_t value);
void STM32446ADC3_smpr1_smp15(uint8_t value);
void STM32446ADC3_smpr1_smp14(uint8_t value);
void STM32446ADC3_smpr1_smp13(uint8_t value);
void STM32446ADC3_smpr1_smp12(uint8_t value);
void STM32446ADC3_smpr1_smp11(uint8_t value);
void STM32446ADC3_smpr1_smp10(uint8_t value);
// SMPR2
void STM32446ADC3_smpr2_smp9(uint8_t value);
void STM32446ADC3_smpr2_smp8(uint8_t value);
void STM32446ADC3_smpr2_smp7(uint8_t value);
void STM32446ADC3_smpr2_smp6(uint8_t value);
void STM32446ADC3_smpr2_smp5(uint8_t bool);
void STM32446ADC3_smpr2_smp4(uint8_t value);
void STM32446ADC3_smpr2_smp3(uint8_t value);
void STM32446ADC3_smpr2_smp2(uint8_t value);
void STM32446ADC3_smpr2_smp1(uint8_t value);
void STM32446ADC3_smpr2_smp0(uint8_t value);
// Other
void STM32446ADC3_jofr1(uint16_t value);
void STM32446ADC3_jofr2(uint16_t value);
void STM32446ADC3_jofr3(uint16_t value);
void STM32446ADC3_jofr4(uint16_t value);
void STM32446ADC3_htr(uint16_t value);
void STM32446ADC3_ltr(uint16_t value);
// SQR1
void STM32446ADC3_sqr1_l(uint8_t value);
void STM32446ADC3_sqr1_sq16(uint8_t value);
void STM32446ADC3_sqr1_sq15(uint8_t value);
void STM32446ADC3_sqr1_sq14(uint8_t value);
void STM32446ADC3_sqr1_sq13(uint8_t value);
// SQR2
void STM32446ADC3_sqr2_sq12(uint8_t value);
void STM32446ADC3_sqr2_sq11(uint8_t value);
void STM32446ADC3_sqr2_sq10(uint8_t value);
void STM32446ADC3_sqr2_sq9(uint8_t value);
void STM32446ADC3_sqr2_sq8(uint8_t value);
void STM32446ADC3_sqr2_sq7(uint8_t value);
// SQR3
void STM32446ADC3_sqr3_sq6(uint8_t value);
void STM32446ADC3_sqr3_sq5(uint8_t value);
void STM32446ADC3_sqr3_sq4(uint8_t value);
void STM32446ADC3_sqr3_sq3(uint8_t value);
void STM32446ADC3_sqr3_sq2(uint8_t value);
void STM32446ADC3_sqr3_sq1(uint8_t value);
// JSQR
void STM32446ADC3_jsqr_jl(uint8_t value);
void STM32446ADC3_jsqr_jsq4(uint8_t value);
void STM32446ADC3_jsqr_jsq3(uint8_t value);
void STM32446ADC3_jsqr_jsq2(uint8_t value);
void STM32446ADC3_jsqr_jsq1(uint8_t value);
// Other
uint16_t STM32446ADC3_jdr1(void);
uint16_t STM32446ADC3_jdr2(void);
uint16_t STM32446ADC3_jdr3(void);
uint16_t STM32446ADC3_jdr4(void);
uint16_t STM32446ADC3_dr(void);

/*** INTERRUPT HEADER ***/
void ADC_IRQHandler(void);

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

