/******************************************************************************
	STM32 446 ADC1
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 19062023
Update: 10012024
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32446adc1.h"

/*** File Variables ***/
// ADC1
static STM32446ADC_SR stm32446_adc1_sr;
static STM32446ADC_CR1 stm32446_adc1_cr1;
static STM32446ADC_CR2 stm32446_adc1_cr2;
static STM32446ADC_SMPR1 stm32446_adc1_smpr1;
static STM32446ADC_SMPR2 stm32446_adc1_smpr2;
static STM32446ADC_SQR1 stm32446_adc1_sqr1;
static STM32446ADC_SQR2 stm32446_adc1_sqr2;
static STM32446ADC_SQR3 stm32446_adc1_sqr3;
static STM32446ADC_JSQR stm32446_adc1_jsqr;
static STM32446ADC1obj stm32446_adc1;
static STM32446ADC1single stm32446_adc1_single;

/*** File Procedure & Function Header ***/
/*** Auxiliar ***/
STM32446ADC_SR* stm32446_adc1_sr_inic(void);
STM32446ADC_CR1* stm32446_adc1_cr1_inic(void);
STM32446ADC_CR2* stm32446_adc1_cr2_inic(void);
STM32446ADC_SMPR1* stm32446_adc1_smpr1_inic(void);
STM32446ADC_SMPR2* stm32446_adc1_smpr2_inic(void);
STM32446ADC_SQR1* stm32446_adc1_sqr1_inic(void);
STM32446ADC_SQR2* stm32446_adc1_sqr2_inic(void);
STM32446ADC_SQR3* stm32446_adc1_sqr3_inic(void);
STM32446ADC_JSQR* stm32446_adc1_jsqr_inic(void);
STM32446ADC1single* stm32446_adc1_single_inic(void);
/*** ADC1 Bit Mapping ***/
// SR
uint8_t STM32446ADC1_sr_ovr(void)
{
	return readreg(ADC1->SR, 1, 5);
}
void STM32446ADC1_sr_clear_ovr(void)
{
	setreg(&ADC1->SR, 1, 5, 0);
}
uint8_t STM32446ADC1_sr_strt(void)
{
	return readreg(ADC1->SR, 1, 4);
}
void STM32446ADC1_sr_clear_strt(void)
{
	setreg(&ADC1->SR, 1, 4, 0);
}
uint8_t STM32446ADC1_sr_jstrt(void)
{
	return readreg(ADC1->SR, 1, 3);
}
void STM32446ADC1_sr_clear_jstrt(void)
{
	setreg(&ADC1->SR, 1, 3, 0);
}
uint8_t STM32446ADC1_sr_jeoc(void)
{
	return readreg(ADC1->SR, 1, 2);
}
void STM32446ADC1_sr_clear_jeoc(void)
{
	setreg(&ADC1->SR, 1, 2, 0);
}
uint8_t STM32446ADC1_sr_eoc(void)
{
	return readreg(ADC1->SR, 1, 1);
}
void STM32446ADC1_sr_clear_eoc(void)
{
	setreg(&ADC1->SR, 1, 1, 0);
}
uint8_t STM32446ADC1_sr_awd(void)
{
	return readreg(ADC1->SR, 1, 0);
}
void STM32446ADC1_sr_clear_awd(void)
{
	setreg(&ADC1->SR, 1, 0, 0);
}
// CR1
void STM32446ADC1_cr1_ovrie(uint8_t bool)
{
	setreg(&ADC1->CR1, 1, 26, bool);
}
void STM32446ADC1_cr1_res(uint8_t value)
{
	setreg(&ADC1->CR1, 2, 24, value);
}
void STM32446ADC1_cr1_awden(uint8_t bool)
{
	setreg(&ADC1->CR1, 1, 23, bool);
}
void STM32446ADC1_cr1_jawden(uint8_t bool)
{
	setreg(&ADC1->CR1, 1, 22, bool);
}
void STM32446ADC1_cr1_discnum(uint8_t value)
{
	setreg(&ADC1->CR1, 3, 13, value);
}
void STM32446ADC1_cr1_jdiscen(uint8_t bool)
{
	setreg(&ADC1->CR1, 1, 12, bool);
}
void STM32446ADC1_cr1_discen(uint8_t bool)
{
	setreg(&ADC1->CR1, 1, 11, bool);
}
void STM32446ADC1_cr1_jauto(uint8_t bool)
{
	setreg(&ADC1->CR1, 1, 10, bool);
}
void STM32446ADC1_cr1_awdsgl(uint8_t bool)
{
	setreg(&ADC1->CR1, 1, 9, bool);
}
void STM32446ADC1_cr1_scan(uint8_t bool)
{
	setreg(&ADC1->CR1, 1, 8, bool);
}
void STM32446ADC1_cr1_jeocie(uint8_t bool)
{
	setreg(&ADC1->CR1, 1, 7, bool);
}
void STM32446ADC1_cr1_awdie(uint8_t bool)
{
	setreg(&ADC1->CR1, 1, 6, bool);
}
void STM32446ADC1_cr1_eocie(uint8_t bool)
{
	setreg(&ADC1->CR1, 1, 5, bool);
}
void STM32446ADC1_cr1_awdch(uint8_t value)
{
	setreg(&ADC1->CR1, 5, 0, value);
}
// CR2
void STM32446ADC1_cr2_swstart(uint8_t bool)
{
	setreg(&ADC1->CR2, 1, 30, bool);
}
uint8_t STM32446ADC1_cr2_read_swstart(void)
{
	return readreg(ADC1->CR2, 1, 30);
}
void STM32446ADC1_cr2_exten(uint8_t value)
{
	setreg(&ADC1->CR2, 2, 28, value);
}
void STM32446ADC1_cr2_extsel(uint8_t value)
{
	setreg(&ADC1->CR2, 4, 24, value);
}
void STM32446ADC1_cr2_jswstart(uint8_t bool)
{
	setreg(&ADC1->CR2, 1, 22, bool);
}
void STM32446ADC1_cr2_jexten(uint8_t value)
{
	setreg(&ADC1->CR2, 2, 20, value);
}
void STM32446ADC1_cr2_jextsel(uint8_t value)
{
	setreg(&ADC1->CR2, 4, 16, value);
}
void STM32446ADC1_cr2_align(uint8_t bool)
{
	setreg(&ADC1->CR2, 1, 11, bool);
}
void STM32446ADC1_cr2_eocs(uint8_t bool)
{
	setreg(&ADC1->CR2, 1, 10, bool);
}
void STM32446ADC1_cr2_dds(uint8_t bool)
{
	setreg(&ADC1->CR2, 1, 9, bool);
}
void STM32446ADC1_cr2_dma(uint8_t bool)
{
	setreg(&ADC1->CR2, 1, 8, bool);
}
void STM32446ADC1_cr2_cont(uint8_t bool)
{
	setreg(&ADC1->CR2, 1, 1, bool);
}
void STM32446ADC1_cr2_adon(uint8_t bool)
{
	setreg(&ADC1->CR2, 1, 0, bool);
}
// SMPR1
void STM32446ADC1_smpr1_smp18(uint8_t value)
{
	setreg(&ADC1->SMPR1, 3, 24, value);
}
void STM32446ADC1_smpr1_smp17(uint8_t value)
{
	setreg(&ADC1->SMPR1, 3, 21, value);
}
void STM32446ADC1_smpr1_smp16(uint8_t value)
{
	setreg(&ADC1->SMPR1, 3, 18, value);
}
void STM32446ADC1_smpr1_smp15(uint8_t value)
{
	setreg(&ADC1->SMPR1, 3, 15, value);
}
void STM32446ADC1_smpr1_smp14(uint8_t value)
{
	setreg(&ADC1->SMPR1, 3, 12, value);
}
void STM32446ADC1_smpr1_smp13(uint8_t value)
{
	setreg(&ADC1->SMPR1, 3, 9, value);
}
void STM32446ADC1_smpr1_smp12(uint8_t value)
{
	setreg(&ADC1->SMPR1, 3, 6, value);
}
void STM32446ADC1_smpr1_smp11(uint8_t value)
{
	setreg(&ADC1->SMPR1, 3, 3, value);
}
void STM32446ADC1_smpr1_smp10(uint8_t value)
{
	setreg(&ADC1->SMPR1, 3, 0, value);
}
// SMPR2
void STM32446ADC1_smpr2_smp9(uint8_t value)
{
	setreg(&ADC1->SMPR2, 3, 27, value);
}
void STM32446ADC1_smpr2_smp8(uint8_t value)
{
	setreg(&ADC1->SMPR2, 3, 24, value);
}
void STM32446ADC1_smpr2_smp7(uint8_t value)
{
	setreg(&ADC1->SMPR2, 3, 21, value);
}
void STM32446ADC1_smpr2_smp6(uint8_t value)
{
	setreg(&ADC1->SMPR2, 3, 18, value);
}
void STM32446ADC1_smpr2_smp5(uint8_t bool)
{
	setreg(&ADC1->SMPR2, 3, 15, bool);
}
void STM32446ADC1_smpr2_smp4(uint8_t value)
{
	setreg(&ADC1->SMPR2, 3, 12, value);
}
void STM32446ADC1_smpr2_smp3(uint8_t value)
{
	setreg(&ADC1->SMPR2, 3, 9, value);
}
void STM32446ADC1_smpr2_smp2(uint8_t value)
{
	setreg(&ADC1->SMPR2, 3, 6, value);
}
void STM32446ADC1_smpr2_smp1(uint8_t value)
{
	setreg(&ADC1->SMPR2, 3, 3, value);
}
void STM32446ADC1_smpr2_smp0(uint8_t value)
{
	setreg(&ADC1->SMPR2, 3, 0, value);
}
void STM32446ADC1_jofr1(uint16_t value)
{
	setreg(&ADC1->JOFR1, 12, 0, value);
}
void STM32446ADC1_jofr2(uint16_t value)
{
	setreg(&ADC1->JOFR2, 12, 0, value);
}
void STM32446ADC1_jofr3(uint16_t value)
{
	setreg(&ADC1->JOFR3, 12, 0, value);
}
void STM32446ADC1_jofr4(uint16_t value)
{
	setreg(&ADC1->JOFR4, 12, 0, value);
}
void STM32446ADC1_htr(uint16_t value)
{
	setreg(&ADC1->HTR, 12, 0, value);
}
void STM32446ADC1_ltr(uint16_t value)
{
	setreg(&ADC1->LTR, 12, 0, value);
}
// SQR1
void STM32446ADC1_sqr1_l(uint8_t value)
{
	setreg(&ADC1->SQR1, 4, 20, value);
}
void STM32446ADC1_sqr1_sq16(uint8_t value)
{
	setreg(&ADC1->SQR1, 5, 15, value);
}
void STM32446ADC1_sqr1_sq15(uint8_t value)
{
	setreg(&ADC1->SQR1, 5, 10, value);
}
void STM32446ADC1_sqr1_sq14(uint8_t value)
{
	setreg(&ADC1->SQR1, 5, 5, value);
}
void STM32446ADC1_sqr1_sq13(uint8_t value)
{
	setreg(&ADC1->SQR1, 5, 0, value);
}
// SQR2
void STM32446ADC1_sqr2_sq12(uint8_t value)
{
	setreg(&ADC1->SQR2, 5, 25, value);
}
void STM32446ADC1_sqr2_sq11(uint8_t value)
{
	setreg(&ADC1->SQR2, 5, 20, value);
}
void STM32446ADC1_sqr2_sq10(uint8_t value)
{
	setreg(&ADC1->SQR2, 5, 15, value);
}
void STM32446ADC1_sqr2_sq9(uint8_t value)
{
	setreg(&ADC1->SQR2, 5, 10, value);
}
void STM32446ADC1_sqr2_sq8(uint8_t value)
{
	setreg(&ADC1->SQR2, 5, 5, value);
}
void STM32446ADC1_sqr2_sq7(uint8_t value)
{
	setreg(&ADC1->SQR2, 5, 0, value);
}
// SQR3
void STM32446ADC1_sqr3_sq6(uint8_t value)
{
	setreg(&ADC1->SQR3, 5, 25, value);
}
void STM32446ADC1_sqr3_sq5(uint8_t value)
{
	setreg(&ADC1->SQR3, 5, 20, value);
}
void STM32446ADC1_sqr3_sq4(uint8_t value)
{
	setreg(&ADC1->SQR3, 5, 15, value);
}
void STM32446ADC1_sqr3_sq3(uint8_t value)
{
	setreg(&ADC1->SQR3, 5, 10, value);
}
void STM32446ADC1_sqr3_sq2(uint8_t value)
{
	setreg(&ADC1->SQR3, 5, 5, value);
}
void STM32446ADC1_sqr3_sq1(uint8_t value)
{
	setreg(&ADC1->SQR3, 5, 0, value);
}
// JSQR
void STM32446ADC1_jsqr_jl(uint8_t value)
{
	setreg(&ADC1->JSQR, 2, 20, value);
}
void STM32446ADC1_jsqr_jsq4(uint8_t value)
{
	setreg(&ADC1->JSQR, 5, 15, value);
}
void STM32446ADC1_jsqr_jsq3(uint8_t value)
{
	setreg(&ADC1->JSQR, 5, 10, value);
}
void STM32446ADC1_jsqr_jsq2(uint8_t value)
{
	setreg(&ADC1->JSQR, 5, 5, value);
}
void STM32446ADC1_jsqr_jsq1(uint8_t value)
{
	setreg(&ADC1->JSQR, 5, 0, value);
}
uint16_t STM32446ADC1_jdr1(void)
{
	return readreg(ADC1->JDR1, 16, 0);
}
uint16_t STM32446ADC1_jdr2(void)
{
	return readreg(ADC1->JDR2, 16, 0);
}
uint16_t STM32446ADC1_jdr3(void)
{
	return readreg(ADC1->JDR3, 16, 0);
}
uint16_t STM32446ADC1_jdr4(void)
{
	return readreg(ADC1->JDR4, 16, 0);
}
uint16_t STM32446ADC1_dr(void)
{
	return readreg(ADC1->DR, 16, 0);
}
/*** ADC1 Auxiliar ***/
STM32446ADC_SR* stm32446_adc1_sr_inic(void)
{
	// SR
	stm32446_adc1_sr.ovr = STM32446ADC1_sr_ovr;
	stm32446_adc1_sr.clear_ovr = STM32446ADC1_sr_clear_ovr;
	stm32446_adc1_sr.strt = STM32446ADC1_sr_strt;
	stm32446_adc1_sr.clear_strt = STM32446ADC1_sr_clear_strt;
	stm32446_adc1_sr.jstrt = STM32446ADC1_sr_jstrt;
	stm32446_adc1_sr.clear_jstrt = STM32446ADC1_sr_clear_jstrt;
	stm32446_adc1_sr.jeoc = STM32446ADC1_sr_jeoc;
	stm32446_adc1_sr.clear_jeoc = STM32446ADC1_sr_clear_jeoc;
	stm32446_adc1_sr.eoc = STM32446ADC1_sr_eoc;
	stm32446_adc1_sr.clear_eoc = STM32446ADC1_sr_clear_eoc;
	stm32446_adc1_sr.awd =  STM32446ADC1_sr_awd;
	stm32446_adc1_sr.clear_awd = STM32446ADC1_sr_clear_awd;
	return &stm32446_adc1_sr;
}
STM32446ADC_CR1* stm32446_adc1_cr1_inic(void)
{
	// CR1
	stm32446_adc1_cr1.ovrie = STM32446ADC1_cr1_ovrie;
	stm32446_adc1_cr1.res = STM32446ADC1_cr1_res;
	stm32446_adc1_cr1.awden = STM32446ADC1_cr1_awden;
	stm32446_adc1_cr1.jawden = STM32446ADC1_cr1_jawden;
	stm32446_adc1_cr1.discnum = STM32446ADC1_cr1_discnum;
	stm32446_adc1_cr1.jdiscen = STM32446ADC1_cr1_jdiscen;
	stm32446_adc1_cr1.discen = STM32446ADC1_cr1_discen;
	stm32446_adc1_cr1.jauto = STM32446ADC1_cr1_jauto;
	stm32446_adc1_cr1.awdsgl = STM32446ADC1_cr1_awdsgl;
	stm32446_adc1_cr1.scan = STM32446ADC1_cr1_scan;
	stm32446_adc1_cr1.jeocie = STM32446ADC1_cr1_jeocie;
	stm32446_adc1_cr1.awdie = STM32446ADC1_cr1_awdie;
	stm32446_adc1_cr1.eocie = STM32446ADC1_cr1_eocie;
	stm32446_adc1_cr1.awdch = STM32446ADC1_cr1_awdch;
	return &stm32446_adc1_cr1;
}
STM32446ADC_CR2* stm32446_adc1_cr2_inic(void)
{
	// CR2
	stm32446_adc1_cr2.swstart = STM32446ADC1_cr2_swstart;
	stm32446_adc1_cr2.read_swstart = STM32446ADC1_cr2_read_swstart;
	stm32446_adc1_cr2.exten = STM32446ADC1_cr2_exten;
	stm32446_adc1_cr2.extsel = STM32446ADC1_cr2_extsel;
	stm32446_adc1_cr2.jswstart = STM32446ADC1_cr2_jswstart;
	stm32446_adc1_cr2.jexten = STM32446ADC1_cr2_jexten;
	stm32446_adc1_cr2.jextsel = STM32446ADC1_cr2_jextsel;
	stm32446_adc1_cr2.align = STM32446ADC1_cr2_align;
	stm32446_adc1_cr2.eocs = STM32446ADC1_cr2_eocs;
	stm32446_adc1_cr2.dds = STM32446ADC1_cr2_dds;
	stm32446_adc1_cr2.dma = STM32446ADC1_cr2_dma;
	stm32446_adc1_cr2.cont = STM32446ADC1_cr2_cont;
	stm32446_adc1_cr2.adon = STM32446ADC1_cr2_adon;
	return &stm32446_adc1_cr2;
}
STM32446ADC_SMPR1* stm32446_adc1_smpr1_inic(void)
{
	// SMPR1
	stm32446_adc1_smpr1.smp18 = STM32446ADC1_smpr1_smp18;
	stm32446_adc1_smpr1.smp17 = STM32446ADC1_smpr1_smp17;
	stm32446_adc1_smpr1.smp16 = STM32446ADC1_smpr1_smp16;
	stm32446_adc1_smpr1.smp15 = STM32446ADC1_smpr1_smp15;
	stm32446_adc1_smpr1.smp14 = STM32446ADC1_smpr1_smp14;
	stm32446_adc1_smpr1.smp13 = STM32446ADC1_smpr1_smp13;
	stm32446_adc1_smpr1.smp12 = STM32446ADC1_smpr1_smp12;
	stm32446_adc1_smpr1.smp11 = STM32446ADC1_smpr1_smp11;
	stm32446_adc1_smpr1.smp10 = STM32446ADC1_smpr1_smp10;
	return &stm32446_adc1_smpr1;
}
STM32446ADC_SMPR2* stm32446_adc1_smpr2_inic(void)
{
	// SMPR2
	stm32446_adc1_smpr2.smp9 = STM32446ADC1_smpr2_smp9;
	stm32446_adc1_smpr2.smp8 = STM32446ADC1_smpr2_smp8;
	stm32446_adc1_smpr2.smp7 = STM32446ADC1_smpr2_smp7;
	stm32446_adc1_smpr2.smp6 = STM32446ADC1_smpr2_smp6;
	stm32446_adc1_smpr2.smp5 = STM32446ADC1_smpr2_smp5;
	stm32446_adc1_smpr2.smp4 = STM32446ADC1_smpr2_smp4;
	stm32446_adc1_smpr2.smp3 = STM32446ADC1_smpr2_smp3;
	stm32446_adc1_smpr2.smp2 = STM32446ADC1_smpr2_smp2;
	stm32446_adc1_smpr2.smp1 = STM32446ADC1_smpr2_smp1;
	stm32446_adc1_smpr2.smp0 = STM32446ADC1_smpr2_smp0;
	return &stm32446_adc1_smpr2;
}
STM32446ADC_SQR1* stm32446_adc1_sqr1_inic(void)
{
	// SQR1
	stm32446_adc1_sqr1.l = STM32446ADC1_sqr1_l;
	stm32446_adc1_sqr1.sq16 = STM32446ADC1_sqr1_sq16;
	stm32446_adc1_sqr1.sq15 = STM32446ADC1_sqr1_sq15;
	stm32446_adc1_sqr1.sq14 = STM32446ADC1_sqr1_sq14;
	stm32446_adc1_sqr1.sq13 = STM32446ADC1_sqr1_sq13;
	return &stm32446_adc1_sqr1;
}
STM32446ADC_SQR2* stm32446_adc1_sqr2_inic(void)
{
	// SQR2
	stm32446_adc1_sqr2.sq12 = STM32446ADC1_sqr2_sq12;
	stm32446_adc1_sqr2.sq11 = STM32446ADC1_sqr2_sq11;
	stm32446_adc1_sqr2.sq10 = STM32446ADC1_sqr2_sq10;
	stm32446_adc1_sqr2.sq9 = STM32446ADC1_sqr2_sq9;
	stm32446_adc1_sqr2.sq8 = STM32446ADC1_sqr2_sq8;
	stm32446_adc1_sqr2.sq7 = STM32446ADC1_sqr2_sq7;
	return &stm32446_adc1_sqr2;
}
STM32446ADC_SQR3* stm32446_adc1_sqr3_inic(void)
{
	// SQ3
	stm32446_adc1_sqr3.sq6 = STM32446ADC1_sqr3_sq6;
	stm32446_adc1_sqr3.sq5 = STM32446ADC1_sqr3_sq5;
	stm32446_adc1_sqr3.sq4 = STM32446ADC1_sqr3_sq4;
	stm32446_adc1_sqr3.sq3 = STM32446ADC1_sqr3_sq3;
	stm32446_adc1_sqr3.sq2 = STM32446ADC1_sqr3_sq2;
	stm32446_adc1_sqr3.sq1 = STM32446ADC1_sqr3_sq1;
	return &stm32446_adc1_sqr3;
}
STM32446ADC_JSQR* stm32446_adc1_jsqr_inic(void)
{

	// JSQR
	stm32446_adc1_jsqr.jl = STM32446ADC1_jsqr_jl;
	stm32446_adc1_jsqr.jsq4 = STM32446ADC1_jsqr_jsq4;
	stm32446_adc1_jsqr.jsq3 = STM32446ADC1_jsqr_jsq3;
	stm32446_adc1_jsqr.jsq2 = STM32446ADC1_jsqr_jsq2;
	stm32446_adc1_jsqr.jsq1 = STM32446ADC1_jsqr_jsq1;
	return &stm32446_adc1_jsqr;
}
/*** ADC1 ***/
void STM32446Adc1IClock(uint8_t bool)
{
	if(bool){ RCC->APB1ENR |= (1 << 29); } // DACEN: DAC interface clock enable
	else{ RCC->APB1ENR &= ~(1 << 29); } // DACEN: DAC interface clock disable
}
void STM32446Adc1Clock(uint8_t bool)
{
	if(bool){ RCC->APB2ENR |= (1 << 8); } // ADC1EN: ADC1 clock enable
	else{ RCC->APB2ENR &= ~(1 << 8); } // ADC1EN: ADC1 clock disable
}
void STM32446Adc1Nvic(uint8_t bool)
{
	if(bool){ setbit(NVIC->ISER, 1, 18, 1); } else{ setbit(NVIC->ICER, 1, 18, 1); }
}
void STM32446Adc1Inic(void)
{
	// ADC Clock
	 STM32446Adc1IClock(1); // DACEN: DAC interface clock enable
	 STM32446Adc1Clock(1); // ADC1EN: ADC1 clock enable
	 STM32446ADC1_cr2_adon(0); // ADON: A/D Converter ON / OFF
	// ADC CONFIG
	//STM32446ADC1_cr1_discnum(1);
	//STM32446ADC1_cr1_scan(1);
	//STM32446ADC1_cr2_eocs(1); // EOCS: End of conversion selection

	 STM32446ADC_ccr_adcpre(3); // ADCPRE: ADC prescaler, 11: PCLK2 divided by 8

	STM32446ADC1_smpr1_smp18(7); // SMPx[2:0]: Channel x sampling time selection
	STM32446ADC1_smpr2_smp0(7); // SMPx[2:0]: Channel x sampling time selection

	STM32446ADC1_sqr1_l(1); // 0 -> read one channel, 1 -> read two channels
	STM32446ADC1_sqr3_sq1(18); // SQ1[4:0]: 1st conversion in regular sequence
	STM32446ADC1_sqr3_sq2(0); // SQ2[4:0]: 2st conversion in regular sequence

	//STM32446ADC1_cr1_discen(1); // DISCEN: Discontinuous mode on regular channels
}
void STM32446Adc1VBAT(void) // vbat overrides temperature
{
	STM32446ADC_ccr_vbate(1); // VBATE: VBAT enable
}
void STM32446Adc1TEMP(void)
{
	// Temperature (in degrees) = {(VSENSE V25) / Avg_Slope} + 25
	STM32446ADC_ccr_tsvrefe(1); // TSVREFE: Temperature sensor and VREFINT enable
}
void STM32446Adc1Start()
{
	uint32_t time_out;
	// turn on select source and start reading
	STM32446ADC1_cr2_adon(1); // ADON: A/D Converter ON / OFF
	//
	STM32446ADC1_cr2_swstart(1); // SWSTART: Start conversion of regular channels
	for(time_out = 200; STM32446ADC1_cr2_read_swstart() && time_out; time_out-- );
}
STM32446ADC1single* stm32446_adc1_single_inic(void)
{
	stm32446_adc1_single.inic = STM32446Adc1Inic;
	stm32446_adc1_single.vbat = STM32446Adc1VBAT;
	stm32446_adc1_single.temp = STM32446Adc1TEMP;
	stm32446_adc1_single.start = STM32446Adc1Start;
	return &stm32446_adc1_single;
}
/*** ADC1 INIC Procedure & Function Definition ***/
STM32446ADC1obj adc1_inic(void)
{
	stm32446_adc1.reg = ADC1;
	/*** ADC1 Bit Mapping Link ***/
	stm32446_adc1.sr = stm32446_adc1_sr_inic();
	stm32446_adc1.cr1 = stm32446_adc1_cr1_inic();
	stm32446_adc1.cr2 = stm32446_adc1_cr2_inic();
	stm32446_adc1.smpr1 = stm32446_adc1_smpr1_inic();
	stm32446_adc1.smpr2 = stm32446_adc1_smpr2_inic();
	stm32446_adc1.jofr1 = STM32446ADC1_jofr1;
	stm32446_adc1.jofr2 = STM32446ADC1_jofr2;
	stm32446_adc1.jofr3 = STM32446ADC1_jofr3;
	stm32446_adc1.jofr4 = STM32446ADC1_jofr4;
	stm32446_adc1.htr = STM32446ADC1_htr;
	stm32446_adc1.ltr = STM32446ADC1_ltr;
	stm32446_adc1.sqr1 = stm32446_adc1_sqr1_inic();
	stm32446_adc1.sqr2 = stm32446_adc1_sqr2_inic();
	stm32446_adc1.sqr3 = stm32446_adc1_sqr3_inic();
	stm32446_adc1.jsqr = stm32446_adc1_jsqr_inic();
	stm32446_adc1.jdr1 = STM32446ADC1_jdr1;
	stm32446_adc1.jdr2 = STM32446ADC1_jdr2;
	stm32446_adc1.jdr3 = STM32446ADC1_jdr3;
	stm32446_adc1.jdr4 = STM32446ADC1_jdr4;
	stm32446_adc1.dr = STM32446ADC1_dr;
	stm32446_adc1.common = stm32446_adc_common_inic();
	/*** Other ***/
	stm32446_adc1.single = stm32446_adc1_single_inic();
	stm32446_adc1.iclock = STM32446Adc1IClock;
	stm32446_adc1.clock = STM32446Adc1Clock;
	stm32446_adc1.nvic = STM32446Adc1Nvic;
	return stm32446_adc1;
}

STM32446ADC1obj* adc1(void){ return (STM32446ADC1obj*) &stm32446_adc1; }

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


