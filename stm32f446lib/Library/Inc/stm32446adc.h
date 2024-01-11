/******************************************************************************
	STM32 446 ADC
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 19062023
Update 10012024
Comment:
	
*******************************************************************************/
#ifndef _STM32446ADC_H_
	#define _STM32446ADC_H_

/*** Library ***/
#include "stm32query.h"

/*** ADC Bit Mapping TypeDef ***/
// SR
typedef struct
{
	uint8_t (*ovr)(void);
	void (*clear_ovr)(void);
	uint8_t (*strt)(void);
	void (*clear_strt)(void);
	uint8_t (*jstrt)(void);
	void (*clear_jstrt)(void);
	uint8_t (*jeoc)(void);
	void (*clear_jeoc)(void);
	uint8_t (*eoc)(void);
	void (*clear_eoc)(void);
	uint8_t (*awd)(void);
	void (*clear_awd)(void);
}STM32446ADC_SR;
// CR1
typedef struct
{
	void (*ovrie)(uint8_t bool);
	void (*res)(uint8_t value);
	void (*awden)(uint8_t bool);
	void (*jawden)(uint8_t bool);
	void (*discnum)(uint8_t value);
	void (*jdiscen)(uint8_t bool);
	void (*discen)(uint8_t bool);
	void (*jauto)(uint8_t bool);
	void (*awdsgl)(uint8_t bool);
	void (*scan)(uint8_t bool);
	void (*jeocie)(uint8_t bool);
	void (*awdie)(uint8_t bool);
	void (*eocie)(uint8_t bool);
	void (*awdch)(uint8_t value);
}STM32446ADC_CR1;
// CR2
typedef struct
{
	void (*swstart)(uint8_t bool);
	uint8_t (*read_swstart)(void);
	void (*exten)(uint8_t value);
	void (*extsel)(uint8_t value);
	void (*jswstart)(uint8_t bool);
	void (*jexten)(uint8_t value);
	void (*jextsel)(uint8_t value);
	void (*align)(uint8_t bool);
	void (*eocs)(uint8_t bool);
	void (*dds)(uint8_t bool);
	void (*dma)(uint8_t bool);
	void (*cont)(uint8_t bool);
	void (*adon)(uint8_t bool);
}STM32446ADC_CR2;
// SMPR1
typedef struct
{
	void (*smp18)(uint8_t value);
	void (*smp17)(uint8_t value);
	void (*smp16)(uint8_t value);
	void (*smp15)(uint8_t value);
	void (*smp15_0)(uint8_t bool);
	void (*smp14)(uint8_t value);
	void (*smp13)(uint8_t value);
	void (*smp12)(uint8_t value);
	void (*smp11)(uint8_t value);
	void (*smp10)(uint8_t value);
}STM32446ADC_SMPR1;
// SMPR2
typedef struct
{
	void (*smp9)(uint8_t value);
	void (*smp8)(uint8_t value);
	void (*smp7)(uint8_t value);
	void (*smp6)(uint8_t value);
	void (*smp5)(uint8_t bool);
	void (*smp5_0)(uint8_t bool);
	void (*smp4)(uint8_t value);
	void (*smp3)(uint8_t value);
	void (*smp2)(uint8_t value);
	void (*smp1)(uint8_t value);
	void (*smp0)(uint8_t value);
}STM32446ADC_SMPR2;
// SQR1
typedef struct
{
	void (*l)(uint8_t value);
	void (*sq16)(uint8_t value);
	void (*sq16_0)(uint8_t bool);
	void (*sq15)(uint8_t value);
	void (*sq14)(uint8_t value);
	void (*sq13)(uint8_t value);
}STM32446ADC_SQR1;
// SQR2
typedef struct
{
	void (*sq12)(uint8_t value);
	void (*sq11)(uint8_t value);
	void (*sq10)(uint8_t value);
	void (*sq10_0)(uint8_t bool);
	void (*sq9)(uint8_t value);
	void (*sq8)(uint8_t value);
	void (*sq7)(uint8_t value);
}STM32446ADC_SQR2;
// SQR3
typedef struct
{
	void (*sq6)(uint8_t value);
	void (*sq5)(uint8_t value);
	void (*sq4)(uint8_t value);
	void (*sq4_0)(uint8_t bool);
	void (*sq3)(uint8_t value);
	void (*sq2)(uint8_t value);
	void (*sq1)(uint8_t value);
}STM32446ADC_SQR3;
// JSQR
typedef struct
{
	void (*jl)(uint8_t value);
	void (*jsq4)(uint8_t value);
	void (*jsq4_0)(uint8_t bool);
	void (*jsq3)(uint8_t value);
	void (*jsq2)(uint8_t value);
	void (*jsq1)(uint8_t value);
}STM32446ADC_JSQR;
// CSR
typedef struct
{
	uint8_t (*ovr3)(void);
	uint8_t (*strt3)(void);
	uint8_t (*jstrt3)(void);
	uint8_t (*jeoc3)(void);
	uint8_t (*eoc3)(void);
	uint8_t (*awd3)(void);
	uint8_t (*ovr2)(void);
	uint8_t (*strt2)(void);
	uint8_t (*jstrt2)(void);
	uint8_t (*jeoc2)(void);
	uint8_t (*eoc2)(void);
	uint8_t (*awd2)(void);
	uint8_t (*ovr1)(void);
	uint8_t (*strt1)(void);
	uint8_t (*jstrt1)(void);
	uint8_t (*jeoc1)(void);
	uint8_t (*eoc1)(void);
	uint8_t (*awd1)(void);
}STM32446ADC_CSR;
// CCR
typedef struct
{
	void (*tsvrefe)(uint8_t bool);
	void (*vbate)(uint8_t bool);
	void (*adcpre)(uint8_t value);
	void (*dma)(uint8_t value);
	void (*dds)(uint8_t bool);
	void (*delay)(uint8_t value);
	void (*multi)(uint8_t value);
}STM32446ADC_CCR;
/*** ADC_Common TypeDef ***/
typedef struct
{
	ADC_Common_TypeDef* reg;
	#if defined(_STM32446ADC_H_)
		STM32446ADC_CSR csr;
		STM32446ADC_CCR ccr;
		uint32_t (*cdr)(void);
	#endif
}STM32446ADCCOMMONobj;
/*** ADC1 Procedure & Function TypeDef ***/
typedef struct
{
	void (*inic)(void);
	void (*vbat)(void);
	void (*temp)(void);
	void (*start)(void);
}STM32446ADC1single, STM32446ADC2single, STM32446ADC3single;
/*** ADC Common Header ***/
// CSR
uint8_t STM32446ADC_csr_ovr3(void);
uint8_t STM32446ADC_csr_strt3(void);
uint8_t STM32446ADC_csr_jstrt3(void);
uint8_t STM32446ADC_csr_jeoc3(void);
uint8_t STM32446ADC_csr_eoc3(void);
uint8_t STM32446ADC_csr_awd3(void);
uint8_t STM32446ADC_csr_ovr2(void);
uint8_t STM32446ADC_csr_strt2(void);
uint8_t STM32446ADC_csr_jstrt2(void);
uint8_t STM32446ADC_csr_jeoc2(void);
uint8_t STM32446ADC_csr_eoc2(void);
uint8_t STM32446ADC_csr_awd2(void);
uint8_t STM32446ADC_csr_ovr1(void);
uint8_t STM32446ADC_csr_strt1(void);
uint8_t STM32446ADC_csr_jstrt1(void);
uint8_t STM32446ADC_csr_jeoc1(void);
uint8_t STM32446ADC_csr_eoc1(void);
uint8_t STM32446ADC_csr_awd1(void);
// CCR
void STM32446ADC_ccr_tsvrefe(uint8_t bool);
void STM32446ADC_ccr_vbate(uint8_t bool);
void STM32446ADC_ccr_adcpre(uint8_t value);
void STM32446ADC_ccr_dma(uint8_t value);
void STM32446ADC_ccr_dds(uint8_t bool);
void STM32446ADC_ccr_delay(uint8_t value);
void STM32446ADC_ccr_multi(uint8_t value);
// CDR
uint32_t STM32446ADC_cdr(void);

STM32446ADC_CSR stm32446_adc_common_csr_inic(void);
STM32446ADC_CCR stm32446_adc_common_ccr_inic(void);
STM32446ADCCOMMONobj* stm32446_adc_common_inic(void);

/*** INTERRUPT HEADER ***/
void ADC_IRQHandler(void);

#endif

/***EOF***/

