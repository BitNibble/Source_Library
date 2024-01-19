/******************************************************************************
	STM32 XXX ADC2
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 19062023
Update: 10012024
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxadc2.h"

/*** File Variables ***/
// ADC1
static STM32FXXXADC_SR stm32fxxx_adc2_sr;
static STM32FXXXADC_CR1 stm32fxxx_adc2_cr1;
static STM32FXXXADC_CR2 stm32fxxx_adc2_cr2;
static STM32FXXXADC_SMPR1 stm32fxxx_adc2_smpr1;
static STM32FXXXADC_SMPR2 stm32fxxx_adc2_smpr2;
static STM32FXXXADC_SQR1 stm32fxxx_adc2_sqr1;
static STM32FXXXADC_SQR2 stm32fxxx_adc2_sqr2;
static STM32FXXXADC_SQR3 stm32fxxx_adc2_sqr3;
static STM32FXXXADC_JSQR stm32fxxx_adc2_jsqr;
static STM32FXXXADC2obj stm32fxxx_adc2;
static STM32FXXXADC2single stm32fxxx_adc2_single;

/*** File Procedure & Function Header ***/
/*** Auxiliar ***/
STM32FXXXADC_SR* stm32fxxx_adc2_sr_inic(void);
STM32FXXXADC_CR1* stm32fxxx_adc2_cr1_inic(void);
STM32FXXXADC_CR2* stm32fxxx_adc2_cr2_inic(void);
STM32FXXXADC_SMPR1* stm32fxxx_adc2_smpr1_inic(void);
STM32FXXXADC_SMPR2* stm32fxxx_adc2_smpr2_inic(void);
STM32FXXXADC_SQR1* stm32fxxx_adc2_sqr1_inic(void);
STM32FXXXADC_SQR2* stm32fxxx_adc2_sqr2_inic(void);
STM32FXXXADC_SQR3* stm32fxxx_adc2_sqr3_inic(void);
STM32FXXXADC_JSQR* stm32fxxx_adc2_jsqr_inic(void);
STM32FXXXADC2single* stm32fxxx_adc2_single_inic(void);
#ifdef STM32F446xx
/*** ADC2 Bit Mapping ***/
// SR
uint8_t STM32FXXXADC2_sr_ovr(void)
{
	return readreg(ADC2->SR, 1, 5);
}
void STM32FXXXADC2_sr_clear_ovr(void)
{
	setreg(&ADC2->SR, 1, 5, 0);
}
uint8_t STM32FXXXADC2_sr_strt(void)
{
	return readreg(ADC2->SR, 1, 4);
}
void STM32FXXXADC2_sr_clear_strt(void)
{
	setreg(&ADC2->SR, 1, 4, 0);
}
uint8_t STM32FXXXADC2_sr_jstrt(void)
{
	return readreg(ADC2->SR, 1, 3);
}
void STM32FXXXADC2_sr_clear_jstrt(void)
{
	setreg(&ADC2->SR, 1, 3, 0);
}
uint8_t STM32FXXXADC2_sr_jeoc(void)
{
	return readreg(ADC2->SR, 1, 2);
}
void STM32FXXXADC2_sr_clear_jeoc(void)
{
	setreg(&ADC2->SR, 1, 2, 0);
}
uint8_t STM32FXXXADC2_sr_eoc(void)
{
	return readreg(ADC2->SR, 1, 1);
}
void STM32FXXXADC2_sr_clear_eoc(void)
{
	setreg(&ADC2->SR, 1, 1, 0);
}
uint8_t STM32FXXXADC2_sr_awd(void)
{
	return readreg(ADC2->SR, 1, 0);
}
void STM32FXXXADC2_sr_clear_awd(void)
{
	setreg(&ADC2->SR, 1, 0, 0);
}
// CR1
void STM32FXXXADC2_cr1_ovrie(uint8_t bool)
{
	setreg(&ADC2->CR1, 1, 26, bool);
}
void STM32FXXXADC2_cr1_res(uint8_t value)
{
	setreg(&ADC2->CR1, 2, 24, value);
}
void STM32FXXXADC2_cr1_awden(uint8_t bool)
{
	setreg(&ADC2->CR1, 1, 23, bool);
}
void STM32FXXXADC2_cr1_jawden(uint8_t bool)
{
	setreg(&ADC2->CR1, 1, 22, bool);
}
void STM32FXXXADC2_cr1_discnum(uint8_t value)
{
	setreg(&ADC2->CR1, 3, 13, value);
}
void STM32FXXXADC2_cr1_jdiscen(uint8_t bool)
{
	setreg(&ADC2->CR1, 1, 12, bool);
}
void STM32FXXXADC2_cr1_discen(uint8_t bool)
{
	setreg(&ADC2->CR1, 1, 11, bool);
}
void STM32FXXXADC2_cr1_jauto(uint8_t bool)
{
	setreg(&ADC2->CR1, 1, 10, bool);
}
void STM32FXXXADC2_cr1_awdsgl(uint8_t bool)
{
	setreg(&ADC2->CR1, 1, 9, bool);
}
void STM32FXXXADC2_cr1_scan(uint8_t bool)
{
	setreg(&ADC2->CR1, 1, 8, bool);
}
void STM32FXXXADC2_cr1_jeocie(uint8_t bool)
{
	setreg(&ADC2->CR1, 1, 7, bool);
}
void STM32FXXXADC2_cr1_awdie(uint8_t bool)
{
	setreg(&ADC2->CR1, 1, 6, bool);
}
void STM32FXXXADC2_cr1_eocie(uint8_t bool)
{
	setreg(&ADC2->CR1, 1, 5, bool);
}
void STM32FXXXADC2_cr1_awdch(uint8_t value)
{
	setreg(&ADC2->CR1, 5, 0, value);
}
// CR2
void STM32FXXXADC2_cr2_swstart(uint8_t bool)
{
	setreg(&ADC2->CR2, 1, 30, bool);
}
uint8_t STM32FXXXADC2_cr2_read_swstart(void)
{
	return readreg(ADC2->CR2, 1, 30);
}
void STM32FXXXADC2_cr2_exten(uint8_t value)
{
	setreg(&ADC2->CR2, 2, 28, value);
}
void STM32FXXXADC2_cr2_extsel(uint8_t value)
{
	setreg(&ADC2->CR2, 4, 24, value);
}
void STM32FXXXADC2_cr2_jswstart(uint8_t bool)
{
	setreg(&ADC2->CR2, 1, 22, bool);
}
void STM32FXXXADC2_cr2_jexten(uint8_t value)
{
	setreg(&ADC2->CR2, 2, 20, value);
}
void STM32FXXXADC2_cr2_jextsel(uint8_t value)
{
	setreg(&ADC2->CR2, 4, 16, value);
}
void STM32FXXXADC2_cr2_align(uint8_t bool)
{
	setreg(&ADC2->CR2, 1, 11, bool);
}
void STM32FXXXADC2_cr2_eocs(uint8_t bool)
{
	setreg(&ADC2->CR2, 1, 10, bool);
}
void STM32FXXXADC2_cr2_dds(uint8_t bool)
{
	setreg(&ADC2->CR2, 1, 9, bool);
}
void STM32FXXXADC2_cr2_dma(uint8_t bool)
{
	setreg(&ADC2->CR2, 1, 8, bool);
}
void STM32FXXXADC2_cr2_cont(uint8_t bool)
{
	setreg(&ADC2->CR2, 1, 1, bool);
}
void STM32FXXXADC2_cr2_adon(uint8_t bool)
{
	setreg(&ADC2->CR2, 1, 0, bool);
}
// SMPR1
void STM32FXXXADC2_smpr1_smp18(uint8_t value)
{
	setreg(&ADC2->SMPR1, 3, 24, value);
}
void STM32FXXXADC2_smpr1_smp17(uint8_t value)
{
	setreg(&ADC2->SMPR1, 3, 21, value);
}
void STM32FXXXADC2_smpr1_smp16(uint8_t value)
{
	setreg(&ADC2->SMPR1, 3, 18, value);
}
void STM32FXXXADC2_smpr1_smp15(uint8_t value)
{
	setreg(&ADC2->SMPR1, 3, 15, value);
}
void STM32FXXXADC2_smpr1_smp14(uint8_t value)
{
	setreg(&ADC2->SMPR1, 3, 12, value);
}
void STM32FXXXADC2_smpr1_smp13(uint8_t value)
{
	setreg(&ADC2->SMPR1, 3, 9, value);
}
void STM32FXXXADC2_smpr1_smp12(uint8_t value)
{
	setreg(&ADC2->SMPR1, 3, 6, value);
}
void STM32FXXXADC2_smpr1_smp11(uint8_t value)
{
	setreg(&ADC2->SMPR1, 3, 3, value);
}
void STM32FXXXADC2_smpr1_smp10(uint8_t value)
{
	setreg(&ADC2->SMPR1, 3, 0, value);
}
// SMPR2
void STM32FXXXADC2_smpr2_smp9(uint8_t value)
{
	setreg(&ADC2->SMPR2, 3, 27, value);
}
void STM32FXXXADC2_smpr2_smp8(uint8_t value)
{
	setreg(&ADC2->SMPR2, 3, 24, value);
}
void STM32FXXXADC2_smpr2_smp7(uint8_t value)
{
	setreg(&ADC2->SMPR2, 3, 21, value);
}
void STM32FXXXADC2_smpr2_smp6(uint8_t value)
{
	setreg(&ADC2->SMPR2, 3, 18, value);
}
void STM32FXXXADC2_smpr2_smp5(uint8_t bool)
{
	setreg(&ADC2->SMPR2, 3, 15, bool);
}
void STM32FXXXADC2_smpr2_smp4(uint8_t value)
{
	setreg(&ADC2->SMPR2, 3, 12, value);
}
void STM32FXXXADC2_smpr2_smp3(uint8_t value)
{
	setreg(&ADC2->SMPR2, 3, 9, value);
}
void STM32FXXXADC2_smpr2_smp2(uint8_t value)
{
	setreg(&ADC2->SMPR2, 3, 6, value);
}
void STM32FXXXADC2_smpr2_smp1(uint8_t value)
{
	setreg(&ADC2->SMPR2, 3, 3, value);
}
void STM32FXXXADC2_smpr2_smp0(uint8_t value)
{
	setreg(&ADC2->SMPR2, 3, 0, value);
}
// Other
void STM32FXXXADC2_jofr1(uint16_t value)
{
	setreg(&ADC2->JOFR1, 12, 0, value);
}
void STM32FXXXADC2_jofr2(uint16_t value)
{
	setreg(&ADC2->JOFR2, 12, 0, value);
}
void STM32FXXXADC2_jofr3(uint16_t value)
{
	setreg(&ADC2->JOFR3, 12, 0, value);
}
void STM32FXXXADC2_jofr4(uint16_t value)
{
	setreg(&ADC2->JOFR4, 12, 0, value);
}
void STM32FXXXADC2_htr(uint16_t value)
{
	setreg(&ADC2->HTR, 12, 0, value);
}
void STM32FXXXADC2_ltr(uint16_t value)
{
	setreg(&ADC2->LTR, 12, 0, value);
}
// SQR1
void STM32FXXXADC2_sqr1_l(uint8_t value)
{
	setreg(&ADC2->SQR1, 4, 20, value);
}
void STM32FXXXADC2_sqr1_sq16(uint8_t value)
{
	setreg(&ADC2->SQR1, 5, 15, value);
}
void STM32FXXXADC2_sqr1_sq15(uint8_t value)
{
	setreg(&ADC2->SQR1, 5, 10, value);
}
void STM32FXXXADC2_sqr1_sq14(uint8_t value)
{
	setreg(&ADC2->SQR1, 5, 5, value);
}
void STM32FXXXADC2_sqr1_sq13(uint8_t value)
{
	setreg(&ADC2->SQR1, 5, 0, value);
}
// SQR2
void STM32FXXXADC2_sqr2_sq12(uint8_t value)
{
	setreg(&ADC2->SQR2, 5, 25, value);
}
void STM32FXXXADC2_sqr2_sq11(uint8_t value)
{
	setreg(&ADC2->SQR2, 5, 20, value);
}
void STM32FXXXADC2_sqr2_sq10(uint8_t value)
{
	setreg(&ADC2->SQR2, 5, 15, value);
}
void STM32FXXXADC2_sqr2_sq9(uint8_t value)
{
	setreg(&ADC2->SQR2, 5, 10, value);
}
void STM32FXXXADC2_sqr2_sq8(uint8_t value)
{
	setreg(&ADC2->SQR2, 5, 5, value);
}
void STM32FXXXADC2_sqr2_sq7(uint8_t value)
{
	setreg(&ADC2->SQR2, 5, 0, value);
}
// SQR3
void STM32FXXXADC2_sqr3_sq6(uint8_t value)
{
	setreg(&ADC2->SQR3, 5, 25, value);
}
void STM32FXXXADC2_sqr3_sq5(uint8_t value)
{
	setreg(&ADC2->SQR3, 5, 20, value);
}
void STM32FXXXADC2_sqr3_sq4(uint8_t value)
{
	setreg(&ADC2->SQR3, 5, 15, value);
}
void STM32FXXXADC2_sqr3_sq3(uint8_t value)
{
	setreg(&ADC2->SQR3, 5, 10, value);
}
void STM32FXXXADC2_sqr3_sq2(uint8_t value)
{
	setreg(&ADC2->SQR3, 5, 5, value);
}
void STM32FXXXADC2_sqr3_sq1(uint8_t value)
{
	setreg(&ADC2->SQR3, 5, 0, value);
}
// JSQR
void STM32FXXXADC2_jsqr_jl(uint8_t value)
{
	setreg(&ADC2->JSQR, 2, 20, value);
}
void STM32FXXXADC2_jsqr_jsq4(uint8_t value)
{
	setreg(&ADC2->JSQR, 5, 15, value);
}
void STM32FXXXADC2_jsqr_jsq3(uint8_t value)
{
	setreg(&ADC2->JSQR, 5, 10, value);
}
void STM32FXXXADC2_jsqr_jsq2(uint8_t value)
{
	setreg(&ADC2->JSQR, 5, 5, value);
}
void STM32FXXXADC2_jsqr_jsq1(uint8_t value)
{
	setreg(&ADC2->JSQR, 5, 0, value);
}
uint16_t STM32FXXXADC2_jdr1(void)
{
	return readreg(ADC2->JDR1, 16, 0);
}
uint16_t STM32FXXXADC2_jdr2(void)
{
	return readreg(ADC2->JDR2, 16, 0);
}
uint16_t STM32FXXXADC2_jdr3(void)
{
	return readreg(ADC2->JDR3, 16, 0);
}
uint16_t STM32FXXXADC2_jdr4(void)
{
	return readreg(ADC2->JDR4, 16, 0);
}
uint16_t STM32FXXXADC2_dr(void)
{
	return readreg(ADC2->DR, 16, 0);
}
#endif
/*** ADC2 Auxiliar ***/
STM32FXXXADC_SR* stm32fxxx_adc2_sr_inic(void)
{

	// SR
	stm32fxxx_adc2_sr.ovr = STM32FXXXADC2_sr_ovr;
	stm32fxxx_adc2_sr.clear_ovr = STM32FXXXADC2_sr_clear_ovr;
	stm32fxxx_adc2_sr.strt = STM32FXXXADC2_sr_strt;
	stm32fxxx_adc2_sr.clear_strt = STM32FXXXADC2_sr_clear_strt;
	stm32fxxx_adc2_sr.jstrt = STM32FXXXADC2_sr_jstrt;
	stm32fxxx_adc2_sr.clear_jstrt = STM32FXXXADC2_sr_clear_jstrt;
	stm32fxxx_adc2_sr.jeoc = STM32FXXXADC2_sr_jeoc;
	stm32fxxx_adc2_sr.clear_jeoc = STM32FXXXADC2_sr_clear_jeoc;
	stm32fxxx_adc2_sr.eoc = STM32FXXXADC2_sr_eoc;
	stm32fxxx_adc2_sr.clear_eoc = STM32FXXXADC2_sr_clear_eoc;
	stm32fxxx_adc2_sr.awd =  STM32FXXXADC2_sr_awd;
	stm32fxxx_adc2_sr.clear_awd = STM32FXXXADC2_sr_clear_awd;
	return &stm32fxxx_adc2_sr;
}
STM32FXXXADC_CR1* stm32fxxx_adc2_cr1_inic(void)
{

	// CR1
	stm32fxxx_adc2_cr1.ovrie = STM32FXXXADC2_cr1_ovrie;
	stm32fxxx_adc2_cr1.res = STM32FXXXADC2_cr1_res;
	stm32fxxx_adc2_cr1.awden = STM32FXXXADC2_cr1_awden;
	stm32fxxx_adc2_cr1.jawden = STM32FXXXADC2_cr1_jawden;
	stm32fxxx_adc2_cr1.discnum = STM32FXXXADC2_cr1_discnum;
	stm32fxxx_adc2_cr1.jdiscen = STM32FXXXADC2_cr1_jdiscen;
	stm32fxxx_adc2_cr1.discen = STM32FXXXADC2_cr1_discen;
	stm32fxxx_adc2_cr1.jauto = STM32FXXXADC2_cr1_jauto;
	stm32fxxx_adc2_cr1.awdsgl = STM32FXXXADC2_cr1_awdsgl;
	stm32fxxx_adc2_cr1.scan = STM32FXXXADC2_cr1_scan;
	stm32fxxx_adc2_cr1.jeocie = STM32FXXXADC2_cr1_jeocie;
	stm32fxxx_adc2_cr1.awdie = STM32FXXXADC2_cr1_awdie;
	stm32fxxx_adc2_cr1.eocie = STM32FXXXADC2_cr1_eocie;
	stm32fxxx_adc2_cr1.awdch = STM32FXXXADC2_cr1_awdch;
	return &stm32fxxx_adc2_cr1;
}
STM32FXXXADC_CR2* stm32fxxx_adc2_cr2_inic(void)
{

	// CR2
	stm32fxxx_adc2_cr2.swstart = STM32FXXXADC2_cr2_swstart;
	stm32fxxx_adc2_cr2.read_swstart = STM32FXXXADC2_cr2_read_swstart;
	stm32fxxx_adc2_cr2.exten = STM32FXXXADC2_cr2_exten;
	stm32fxxx_adc2_cr2.extsel = STM32FXXXADC2_cr2_extsel;
	stm32fxxx_adc2_cr2.jswstart = STM32FXXXADC2_cr2_jswstart;
	stm32fxxx_adc2_cr2.jexten = STM32FXXXADC2_cr2_jexten;
	stm32fxxx_adc2_cr2.jextsel = STM32FXXXADC2_cr2_jextsel;
	stm32fxxx_adc2_cr2.align = STM32FXXXADC2_cr2_align;
	stm32fxxx_adc2_cr2.eocs = STM32FXXXADC2_cr2_eocs;
	stm32fxxx_adc2_cr2.dds = STM32FXXXADC2_cr2_dds;
	stm32fxxx_adc2_cr2.dma = STM32FXXXADC2_cr2_dma;
	stm32fxxx_adc2_cr2.cont = STM32FXXXADC2_cr2_cont;
	stm32fxxx_adc2_cr2.adon = STM32FXXXADC2_cr2_adon;
	return &stm32fxxx_adc2_cr2;
}
STM32FXXXADC_SMPR1* stm32fxxx_adc2_smpr1_inic(void)
{

	// SMPR1
	stm32fxxx_adc2_smpr1.smp18 = STM32FXXXADC2_smpr1_smp18;
	stm32fxxx_adc2_smpr1.smp17 = STM32FXXXADC2_smpr1_smp17;
	stm32fxxx_adc2_smpr1.smp16 = STM32FXXXADC2_smpr1_smp16;
	stm32fxxx_adc2_smpr1.smp15 = STM32FXXXADC2_smpr1_smp15;
	stm32fxxx_adc2_smpr1.smp14 = STM32FXXXADC2_smpr1_smp14;
	stm32fxxx_adc2_smpr1.smp13 = STM32FXXXADC2_smpr1_smp13;
	stm32fxxx_adc2_smpr1.smp12 = STM32FXXXADC2_smpr1_smp12;
	stm32fxxx_adc2_smpr1.smp11 = STM32FXXXADC2_smpr1_smp11;
	stm32fxxx_adc2_smpr1.smp10 = STM32FXXXADC2_smpr1_smp10;
	return &stm32fxxx_adc2_smpr1;
}
STM32FXXXADC_SMPR2* stm32fxxx_adc2_smpr2_inic(void)
{

	// SMPR2
	stm32fxxx_adc2_smpr2.smp9 = STM32FXXXADC2_smpr2_smp9;
	stm32fxxx_adc2_smpr2.smp8 = STM32FXXXADC2_smpr2_smp8;
	stm32fxxx_adc2_smpr2.smp7 = STM32FXXXADC2_smpr2_smp7;
	stm32fxxx_adc2_smpr2.smp6 = STM32FXXXADC2_smpr2_smp6;
	stm32fxxx_adc2_smpr2.smp5 = STM32FXXXADC2_smpr2_smp5;
	stm32fxxx_adc2_smpr2.smp4 = STM32FXXXADC2_smpr2_smp4;
	stm32fxxx_adc2_smpr2.smp3 = STM32FXXXADC2_smpr2_smp3;
	stm32fxxx_adc2_smpr2.smp2 = STM32FXXXADC2_smpr2_smp2;
	stm32fxxx_adc2_smpr2.smp1 = STM32FXXXADC2_smpr2_smp1;
	stm32fxxx_adc2_smpr2.smp0 = STM32FXXXADC2_smpr2_smp0;
	return &stm32fxxx_adc2_smpr2;
}
STM32FXXXADC_SQR1* stm32fxxx_adc2_sqr1_inic(void)
{

	// SQR1
	stm32fxxx_adc2_sqr1.l = STM32FXXXADC2_sqr1_l;
	stm32fxxx_adc2_sqr1.sq16 = STM32FXXXADC2_sqr1_sq16;
	stm32fxxx_adc2_sqr1.sq15 = STM32FXXXADC2_sqr1_sq15;
	stm32fxxx_adc2_sqr1.sq14 = STM32FXXXADC2_sqr1_sq14;
	stm32fxxx_adc2_sqr1.sq13 = STM32FXXXADC2_sqr1_sq13;
	return &stm32fxxx_adc2_sqr1;
}
STM32FXXXADC_SQR2* stm32fxxx_adc2_sqr2_inic(void)
{

	// SQR2
	stm32fxxx_adc2_sqr2.sq12 = STM32FXXXADC2_sqr2_sq12;
	stm32fxxx_adc2_sqr2.sq11 = STM32FXXXADC2_sqr2_sq11;
	stm32fxxx_adc2_sqr2.sq10 = STM32FXXXADC2_sqr2_sq10;
	stm32fxxx_adc2_sqr2.sq9 = STM32FXXXADC2_sqr2_sq9;
	stm32fxxx_adc2_sqr2.sq8 = STM32FXXXADC2_sqr2_sq8;
	stm32fxxx_adc2_sqr2.sq7 = STM32FXXXADC2_sqr2_sq7;
	return &stm32fxxx_adc2_sqr2;
}
STM32FXXXADC_SQR3* stm32fxxx_adc2_sqr3_inic(void)
{

	// SQ3
	stm32fxxx_adc2_sqr3.sq6 = STM32FXXXADC2_sqr3_sq6;
	stm32fxxx_adc2_sqr3.sq5 = STM32FXXXADC2_sqr3_sq5;
	stm32fxxx_adc2_sqr3.sq4 = STM32FXXXADC2_sqr3_sq4;
	stm32fxxx_adc2_sqr3.sq3 = STM32FXXXADC2_sqr3_sq3;
	stm32fxxx_adc2_sqr3.sq2 = STM32FXXXADC2_sqr3_sq2;
	stm32fxxx_adc2_sqr3.sq1 = STM32FXXXADC2_sqr3_sq1;
	return &stm32fxxx_adc2_sqr3;
}
STM32FXXXADC_JSQR* stm32fxxx_adc2_jsqr_inic(void)
{

	// JSQR
	stm32fxxx_adc2_jsqr.jl = STM32FXXXADC2_jsqr_jl;
	stm32fxxx_adc2_jsqr.jsq4 = STM32FXXXADC2_jsqr_jsq4;
	stm32fxxx_adc2_jsqr.jsq3 = STM32FXXXADC2_jsqr_jsq3;
	stm32fxxx_adc2_jsqr.jsq2 = STM32FXXXADC2_jsqr_jsq2;
	stm32fxxx_adc2_jsqr.jsq1 = STM32FXXXADC2_jsqr_jsq1;
	return &stm32fxxx_adc2_jsqr;
}
/*** ADC2 ***/
void STM32FXXXAdc2IClock(uint8_t bool)
{
	if(bool){ RCC->APB1ENR |= (1 << 29); }else{ RCC->APB1ENR &= ~(1 << 29); }
}
void STM32FXXXAdc2Clock(uint8_t bool)
{
	if(bool){ RCC->APB2ENR |= (1 << 9); }else{ RCC->APB2ENR &= ~(1 << 9); }
}
void STM32FXXXAdc2Nvic(uint8_t bool)
{
	if(bool){ setbit(NVIC->ISER, 1, ADC_IRQn, 1); } else{ setbit(NVIC->ICER, 1, ADC_IRQn, 1); }
}
void STM32FXXXAdc2Inic(void)
{
	// ADC Clock
	// void STM32FXXXAdc2IClock(1); // DACEN: DAC interface clock enable
	// STM32FXXXAdc2Clock(1) // ADC2EN: ADC2 clock enable
	// ADC CONFIG
	STM32FXXXADC2_cr2_eocs(1); // EOCS: End of conversion selection
	STM32FXXXADC_ccr_adcpre(3); // ADCPRE: ADC prescaler, 11: PCLK2 divided by 8
	STM32FXXXADC2_smpr1_smp10(7); // SMPx[2:0]: Channel x sampling time selection
	STM32FXXXADC2_cr1_discen(1); // DISCEN: Discontinuous mode on regular channels
	STM32FXXXADC2_sqr3_sq1(10); // SQ1[4:0]: 1st conversion in regular sequence
}
void STM32FXXXAdc2Start()
{
	// turn on select source and start reading
	STM32FXXXADC2_cr2_adon(1); // ADON: A/D Converter ON / OFF
	//
	STM32FXXXADC2_cr2_swstart(1); // SWSTART: Start conversion of regular channels
}
STM32FXXXADC2single* stm32fxxx_adc2_single_inic(void)
{

	stm32fxxx_adc2_single.inic = STM32FXXXAdc2Inic;
	stm32fxxx_adc2_single.start = STM32FXXXAdc2Start;
	return &stm32fxxx_adc2_single;
}

/*** ADC2 INIC Procedure & Function Definition ***/
STM32FXXXADC2obj adc2_enable(void)
{


	/*** ADC2 Bit Mapping Link ***/
	stm32fxxx_adc2.sr = stm32fxxx_adc2_sr_inic();
	stm32fxxx_adc2.cr1 = stm32fxxx_adc2_cr1_inic();
	stm32fxxx_adc2.cr2 = stm32fxxx_adc2_cr2_inic();
	stm32fxxx_adc2.smpr1 = stm32fxxx_adc2_smpr1_inic();
	stm32fxxx_adc2.smpr2 = stm32fxxx_adc2_smpr2_inic();
	stm32fxxx_adc2.jofr1 = STM32FXXXADC2_jofr1;
	stm32fxxx_adc2.jofr2 = STM32FXXXADC2_jofr2;
	stm32fxxx_adc2.jofr3 = STM32FXXXADC2_jofr3;
	stm32fxxx_adc2.jofr4 = STM32FXXXADC2_jofr4;
	stm32fxxx_adc2.htr = STM32FXXXADC2_htr;
	stm32fxxx_adc2.ltr = STM32FXXXADC2_ltr;
	stm32fxxx_adc2.sqr1 = stm32fxxx_adc2_sqr1_inic();
	stm32fxxx_adc2.sqr2 = stm32fxxx_adc2_sqr2_inic();
	stm32fxxx_adc2.sqr3 = stm32fxxx_adc2_sqr3_inic();
	stm32fxxx_adc2.jsqr = stm32fxxx_adc2_jsqr_inic();
	stm32fxxx_adc2.jdr1 = STM32FXXXADC2_jdr1;
	stm32fxxx_adc2.jdr2 = STM32FXXXADC2_jdr2;
	stm32fxxx_adc2.jdr3 = STM32FXXXADC2_jdr3;
	stm32fxxx_adc2.jdr4 = STM32FXXXADC2_jdr4;
	stm32fxxx_adc2.dr = STM32FXXXADC2_dr;
	stm32fxxx_adc2.common = stm32fxxx_adc_common_inic();
	// Other
	stm32fxxx_adc2.single = stm32fxxx_adc2_single_inic();
	stm32fxxx_adc2.iclock = STM32FXXXAdc2IClock;
	stm32fxxx_adc2.clock = STM32FXXXAdc2Clock;
	stm32fxxx_adc2.nvic = STM32FXXXAdc2Nvic;
	return stm32fxxx_adc2;
}

STM32FXXXADC2obj* adc2(void){ return (STM32FXXXADC2obj*) &stm32fxxx_adc2; }

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

