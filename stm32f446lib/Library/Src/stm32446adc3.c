/******************************************************************************
	STM32 446 ADC3
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 19062023
Update: 10012024
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32446adc3.h"

/*** File Variables ***/

/*** Auxiliar ***/
STM32446ADC_SR stm32446_adc3_sr_inic(void);
STM32446ADC_CR1 stm32446_adc3_cr1_inic(void);
STM32446ADC_CR2 stm32446_adc3_cr2_inic(void);
STM32446ADC_SMPR1 stm32446_adc3_smpr1_inic(void);
STM32446ADC_SMPR2 stm32446_adc3_smpr2_inic(void);
STM32446ADC_SQR1 stm32446_adc3_sqr1_inic(void);
STM32446ADC_SQR2 stm32446_adc3_sqr2_inic(void);
STM32446ADC_SQR3 stm32446_adc3_sqr3_inic(void);
STM32446ADC_JSQR stm32446_adc3_jsqr_inic(void);
STM32446ADC3single stm32446_adc3_single_inic(void);
/*** ADC3 Bit Mapping ***/
// SR
uint8_t STM32446ADC3_sr_ovr(void)
{
	return readreg(ADC3->SR, 1, 5);
}
void STM32446ADC3_sr_clear_ovr(void)
{
	setreg(&ADC3->SR, 1, 5, 0);
}
uint8_t STM32446ADC3_sr_strt(void)
{
	return readreg(ADC3->SR, 1, 4);
}
void STM32446ADC3_sr_clear_strt(void)
{
	setreg(&ADC3->SR, 1, 4, 0);
}
uint8_t STM32446ADC3_sr_jstrt(void)
{
	return readreg(ADC3->SR, 1, 3);
}
void STM32446ADC3_sr_clear_jstrt(void)
{
	setreg(&ADC3->SR, 1, 3, 0);
}
uint8_t STM32446ADC3_sr_jeoc(void)
{
	return readreg(ADC3->SR, 1, 2);
}
void STM32446ADC3_sr_clear_jeoc(void)
{
	setreg(&ADC3->SR, 1, 2, 0);
}
uint8_t STM32446ADC3_sr_eoc(void)
{
	return readreg(ADC3->SR, 1, 1);
}
void STM32446ADC3_sr_clear_eoc(void)
{
	setreg(&ADC3->SR, 1, 1, 0);
}
uint8_t STM32446ADC3_sr_awd(void)
{
	return readreg(ADC3->SR, 1, 0);
}
void STM32446ADC3_sr_clear_awd(void)
{
	setreg(&ADC3->SR, 1, 0, 0);
}
// CR1
void STM32446ADC3_cr1_ovrie(uint8_t bool)
{
	setreg(&ADC3->CR1, 1, 26, bool);
}
void STM32446ADC3_cr1_res(uint8_t value)
{
	setreg(&ADC3->CR1, 2, 24, value);
}
void STM32446ADC3_cr1_awden(uint8_t bool)
{
	setreg(&ADC3->CR1, 1, 23, bool);
}
void STM32446ADC3_cr1_jawden(uint8_t bool)
{
	setreg(&ADC3->CR1, 1, 22, bool);
}
void STM32446ADC3_cr1_discnum(uint8_t value)
{
	setreg(&ADC3->CR1, 3, 13, value);
}
void STM32446ADC3_cr1_jdiscen(uint8_t bool)
{
	setreg(&ADC3->CR1, 1, 12, bool);
}
void STM32446ADC3_cr1_discen(uint8_t bool)
{
	setreg(&ADC3->CR1, 1, 11, bool);
}
void STM32446ADC3_cr1_jauto(uint8_t bool)
{
	setreg(&ADC3->CR1, 1, 10, bool);
}
void STM32446ADC3_cr1_awdsgl(uint8_t bool)
{
	setreg(&ADC3->CR1, 1, 9, bool);
}
void STM32446ADC3_cr1_scan(uint8_t bool)
{
	setreg(&ADC3->CR1, 1, 8, bool);
}
void STM32446ADC3_cr1_jeocie(uint8_t bool)
{
	setreg(&ADC3->CR1, 1, 7, bool);
}
void STM32446ADC3_cr1_awdie(uint8_t bool)
{
	setreg(&ADC3->CR1, 1, 6, bool);
}
void STM32446ADC3_cr1_eocie(uint8_t bool)
{
	setreg(&ADC3->CR1, 1, 5, bool);
}
void STM32446ADC3_cr1_awdch(uint8_t value)
{
	setreg(&ADC3->CR1, 5, 0, value);
}
// CR2
void STM32446ADC3_cr2_swstart(uint8_t bool)
{
	setreg(&ADC3->CR2, 1, 30, bool);
}
uint8_t STM32446ADC3_cr2_read_swstart(void)
{
	return readreg(ADC3->CR2, 1, 30);
}
void STM32446ADC3_cr2_exten(uint8_t value)
{
	setreg(&ADC3->CR2, 2, 28, value);
}
void STM32446ADC3_cr2_extsel(uint8_t value)
{
	setreg(&ADC3->CR2, 4, 24, value);
}
void STM32446ADC3_cr2_jswstart(uint8_t bool)
{
	setreg(&ADC3->CR2, 1, 22, bool);
}
void STM32446ADC3_cr2_jexten(uint8_t value)
{
	setreg(&ADC3->CR2, 2, 20, value);
}
void STM32446ADC3_cr2_jextsel(uint8_t value)
{
	setreg(&ADC3->CR2, 4, 16, value);
}
void STM32446ADC3_cr2_align(uint8_t bool)
{
	setreg(&ADC3->CR2, 1, 11, bool);
}
void STM32446ADC3_cr2_eocs(uint8_t bool)
{
	setreg(&ADC3->CR2, 1, 10, bool);
}
void STM32446ADC3_cr2_dds(uint8_t bool)
{
	setreg(&ADC3->CR2, 1, 9, bool);
}
void STM32446ADC3_cr2_dma(uint8_t bool)
{
	setreg(&ADC3->CR2, 1, 8, bool);
}
void STM32446ADC3_cr2_cont(uint8_t bool)
{
	setreg(&ADC3->CR2, 1, 1, bool);
}
void STM32446ADC3_cr2_adon(uint8_t bool)
{
	setreg(&ADC3->CR2, 1, 0, bool);
}
// SMPR1
void STM32446ADC3_smpr1_smp18(uint8_t value)
{
	setreg(&ADC3->SMPR1, 3, 24, value);
}
void STM32446ADC3_smpr1_smp17(uint8_t value)
{
	setreg(&ADC3->SMPR1, 3, 21, value);
}
void STM32446ADC3_smpr1_smp16(uint8_t value)
{
	setreg(&ADC3->SMPR1, 3, 18, value);
}
void STM32446ADC3_smpr1_smp15(uint8_t value)
{
	setreg(&ADC3->SMPR1, 3, 15, value);
}
void STM32446ADC3_smpr1_smp14(uint8_t value)
{
	setreg(&ADC3->SMPR1, 3, 12, value);
}
void STM32446ADC3_smpr1_smp13(uint8_t value)
{
	setreg(&ADC3->SMPR1, 3, 9, value);
}
void STM32446ADC3_smpr1_smp12(uint8_t value)
{
	setreg(&ADC3->SMPR1, 3, 6, value);
}
void STM32446ADC3_smpr1_smp11(uint8_t value)
{
	setreg(&ADC3->SMPR1, 3, 3, value);
}
void STM32446ADC3_smpr1_smp10(uint8_t value)
{
	setreg(&ADC3->SMPR1, 3, 0, value);
}
// SMPR2
void STM32446ADC3_smpr2_smp9(uint8_t value)
{
	setreg(&ADC3->SMPR2, 3, 27, value);
}
void STM32446ADC3_smpr2_smp8(uint8_t value)
{
	setreg(&ADC3->SMPR2, 3, 24, value);
}
void STM32446ADC3_smpr2_smp7(uint8_t value)
{
	setreg(&ADC3->SMPR2, 3, 21, value);
}
void STM32446ADC3_smpr2_smp6(uint8_t value)
{
	setreg(&ADC3->SMPR2, 3, 18, value);
}
void STM32446ADC3_smpr2_smp5(uint8_t bool)
{
	setreg(&ADC3->SMPR2, 3, 15, bool);
}
void STM32446ADC3_smpr2_smp4(uint8_t value)
{
	setreg(&ADC3->SMPR2, 3, 12, value);
}
void STM32446ADC3_smpr2_smp3(uint8_t value)
{
	setreg(&ADC3->SMPR2, 3, 9, value);
}
void STM32446ADC3_smpr2_smp2(uint8_t value)
{
	setreg(&ADC3->SMPR2, 3, 6, value);
}
void STM32446ADC3_smpr2_smp1(uint8_t value)
{
	setreg(&ADC3->SMPR2, 3, 3, value);
}
void STM32446ADC3_smpr2_smp0(uint8_t value)
{
	setreg(&ADC3->SMPR2, 3, 0, value);
}
void STM32446ADC3_jofr1(uint16_t value)
{
	setreg(&ADC3->JOFR1, 12, 0, value);
}
void STM32446ADC3_jofr2(uint16_t value)
{
	setreg(&ADC3->JOFR2, 12, 0, value);
}
void STM32446ADC3_jofr3(uint16_t value)
{
	setreg(&ADC3->JOFR3, 12, 0, value);
}
void STM32446ADC3_jofr4(uint16_t value)
{
	setreg(&ADC3->JOFR4, 12, 0, value);
}
void STM32446ADC3_htr(uint16_t value)
{
	setreg(&ADC3->HTR, 12, 0, value);
}
void STM32446ADC3_ltr(uint16_t value)
{
	setreg(&ADC3->LTR, 12, 0, value);
}
// SQR1
void STM32446ADC3_sqr1_l(uint8_t value)
{
	setreg(&ADC3->SQR1, 4, 20, value);
}
void STM32446ADC3_sqr1_sq16(uint8_t value)
{
	setreg(&ADC3->SQR1, 5, 15, value);
}
void STM32446ADC3_sqr1_sq15(uint8_t value)
{
	setreg(&ADC3->SQR1, 5, 10, value);
}
void STM32446ADC3_sqr1_sq14(uint8_t value)
{
	setreg(&ADC3->SQR1, 5, 5, value);
}
void STM32446ADC3_sqr1_sq13(uint8_t value)
{
	setreg(&ADC3->SQR1, 5, 0, value);
}
// SQR2
void STM32446ADC3_sqr2_sq12(uint8_t value)
{
	setreg(&ADC3->SQR2, 5, 25, value);
}
void STM32446ADC3_sqr2_sq11(uint8_t value)
{
	setreg(&ADC3->SQR2, 5, 20, value);
}
void STM32446ADC3_sqr2_sq10(uint8_t value)
{
	setreg(&ADC3->SQR2, 5, 15, value);
}
void STM32446ADC3_sqr2_sq9(uint8_t value)
{
	setreg(&ADC3->SQR2, 5, 10, value);
}
void STM32446ADC3_sqr2_sq8(uint8_t value)
{
	setreg(&ADC3->SQR2, 5, 5, value);
}
void STM32446ADC3_sqr2_sq7(uint8_t value)
{
	setreg(&ADC3->SQR2, 5, 0, value);
}
// SQR3
void STM32446ADC3_sqr3_sq6(uint8_t value)
{
	setreg(&ADC3->SQR3, 5, 25, value);
}
void STM32446ADC3_sqr3_sq5(uint8_t value)
{
	setreg(&ADC3->SQR3, 5, 20, value);
}
void STM32446ADC3_sqr3_sq4(uint8_t value)
{
	setreg(&ADC3->SQR3, 5, 15, value);
}
void STM32446ADC3_sqr3_sq3(uint8_t value)
{
	setreg(&ADC3->SQR3, 5, 10, value);
}
void STM32446ADC3_sqr3_sq2(uint8_t value)
{
	setreg(&ADC3->SQR3, 5, 5, value);
}
void STM32446ADC3_sqr3_sq1(uint8_t value)
{
	setreg(&ADC3->SQR3, 5, 0, value);
}
// JSQR
void STM32446ADC3_jsqr_jl(uint8_t value)
{
	setreg(&ADC3->JSQR, 2, 20, value);
}
void STM32446ADC3_jsqr_jsq4(uint8_t value)
{
	setreg(&ADC3->JSQR, 5, 15, value);
}
void STM32446ADC3_jsqr_jsq3(uint8_t value)
{
	setreg(&ADC3->JSQR, 5, 10, value);
}
void STM32446ADC3_jsqr_jsq2(uint8_t value)
{
	setreg(&ADC3->JSQR, 5, 5, value);
}
void STM32446ADC3_jsqr_jsq1(uint8_t value)
{
	setreg(&ADC3->JSQR, 5, 0, value);
}
uint16_t STM32446ADC3_jdr1(void)
{
	return readreg(ADC3->JDR1, 16, 0);
}
uint16_t STM32446ADC3_jdr2(void)
{
	return readreg(ADC3->JDR2, 16, 0);
}
uint16_t STM32446ADC3_jdr3(void)
{
	return readreg(ADC3->JDR3, 16, 0);
}
uint16_t STM32446ADC3_jdr4(void)
{
	return readreg(ADC3->JDR4, 16, 0);
}
uint16_t STM32446ADC3_dr(void)
{
	return readreg(ADC3->DR, 16, 0);
}
/*** ADC3 Auxiliar ***/
STM32446ADC_SR stm32446_adc3_sr_inic(void)
{
	STM32446ADC_SR stm32446_adc3_sr;
	// SR
	stm32446_adc3_sr.ovr = STM32446ADC3_sr_ovr;
	stm32446_adc3_sr.clear_ovr = STM32446ADC3_sr_clear_ovr;
	stm32446_adc3_sr.strt = STM32446ADC3_sr_strt;
	stm32446_adc3_sr.clear_strt = STM32446ADC3_sr_clear_strt;
	stm32446_adc3_sr.jstrt = STM32446ADC3_sr_jstrt;
	stm32446_adc3_sr.clear_jstrt = STM32446ADC3_sr_clear_jstrt;
	stm32446_adc3_sr.jeoc = STM32446ADC3_sr_jeoc;
	stm32446_adc3_sr.clear_jeoc = STM32446ADC3_sr_clear_jeoc;
	stm32446_adc3_sr.eoc = STM32446ADC3_sr_eoc;
	stm32446_adc3_sr.clear_eoc = STM32446ADC3_sr_clear_eoc;
	stm32446_adc3_sr.awd =  STM32446ADC3_sr_awd;
	stm32446_adc3_sr.clear_awd = STM32446ADC3_sr_clear_awd;
	return stm32446_adc3_sr;
}
STM32446ADC_CR1 stm32446_adc3_cr1_inic(void)
{
	STM32446ADC_CR1 stm32446_adc3_cr1;
	// CR1
	stm32446_adc3_cr1.ovrie = STM32446ADC3_cr1_ovrie;
	stm32446_adc3_cr1.res = STM32446ADC3_cr1_res;
	stm32446_adc3_cr1.awden = STM32446ADC3_cr1_awden;
	stm32446_adc3_cr1.jawden = STM32446ADC3_cr1_jawden;
	stm32446_adc3_cr1.discnum = STM32446ADC3_cr1_discnum;
	stm32446_adc3_cr1.jdiscen = STM32446ADC3_cr1_jdiscen;
	stm32446_adc3_cr1.discen = STM32446ADC3_cr1_discen;
	stm32446_adc3_cr1.jauto = STM32446ADC3_cr1_jauto;
	stm32446_adc3_cr1.awdsgl = STM32446ADC3_cr1_awdsgl;
	stm32446_adc3_cr1.scan = STM32446ADC3_cr1_scan;
	stm32446_adc3_cr1.jeocie = STM32446ADC3_cr1_jeocie;
	stm32446_adc3_cr1.awdie = STM32446ADC3_cr1_awdie;
	stm32446_adc3_cr1.eocie = STM32446ADC3_cr1_eocie;
	stm32446_adc3_cr1.awdch = STM32446ADC3_cr1_awdch;
	return stm32446_adc3_cr1;
}
STM32446ADC_CR2 stm32446_adc3_cr2_inic(void)
{
	STM32446ADC_CR2 stm32446_adc3_cr2;
	// CR2
	stm32446_adc3_cr2.swstart = STM32446ADC3_cr2_swstart;
	stm32446_adc3_cr2.read_swstart = STM32446ADC3_cr2_read_swstart;
	stm32446_adc3_cr2.exten = STM32446ADC3_cr2_exten;
	stm32446_adc3_cr2.extsel = STM32446ADC3_cr2_extsel;
	stm32446_adc3_cr2.jswstart = STM32446ADC3_cr2_jswstart;
	stm32446_adc3_cr2.jexten = STM32446ADC3_cr2_jexten;
	stm32446_adc3_cr2.jextsel = STM32446ADC3_cr2_jextsel;
	stm32446_adc3_cr2.align = STM32446ADC3_cr2_align;
	stm32446_adc3_cr2.eocs = STM32446ADC3_cr2_eocs;
	stm32446_adc3_cr2.dds = STM32446ADC3_cr2_dds;
	stm32446_adc3_cr2.dma = STM32446ADC3_cr2_dma;
	stm32446_adc3_cr2.cont = STM32446ADC3_cr2_cont;
	stm32446_adc3_cr2.adon = STM32446ADC3_cr2_adon;
	return stm32446_adc3_cr2;
}
STM32446ADC_SMPR1 stm32446_adc3_smpr1_inic(void)
{
	STM32446ADC_SMPR1 stm32446_adc3_smpr1;
	// SMPR1
	stm32446_adc3_smpr1.smp18 = STM32446ADC3_smpr1_smp18;
	stm32446_adc3_smpr1.smp17 = STM32446ADC3_smpr1_smp17;
	stm32446_adc3_smpr1.smp16 = STM32446ADC3_smpr1_smp16;
	stm32446_adc3_smpr1.smp15 = STM32446ADC3_smpr1_smp15;
	stm32446_adc3_smpr1.smp14 = STM32446ADC3_smpr1_smp14;
	stm32446_adc3_smpr1.smp13 = STM32446ADC3_smpr1_smp13;
	stm32446_adc3_smpr1.smp12 = STM32446ADC3_smpr1_smp12;
	stm32446_adc3_smpr1.smp11 = STM32446ADC3_smpr1_smp11;
	stm32446_adc3_smpr1.smp10 = STM32446ADC3_smpr1_smp10;
	return stm32446_adc3_smpr1;
}
STM32446ADC_SMPR2 stm32446_adc3_smpr2_inic(void)
{
	STM32446ADC_SMPR2 stm32446_adc3_smpr2;
	// SMPR2
	stm32446_adc3_smpr2.smp9 = STM32446ADC3_smpr2_smp9;
	stm32446_adc3_smpr2.smp8 = STM32446ADC3_smpr2_smp8;
	stm32446_adc3_smpr2.smp7 = STM32446ADC3_smpr2_smp7;
	stm32446_adc3_smpr2.smp6 = STM32446ADC3_smpr2_smp6;
	stm32446_adc3_smpr2.smp5 = STM32446ADC3_smpr2_smp5;
	stm32446_adc3_smpr2.smp4 = STM32446ADC3_smpr2_smp4;
	stm32446_adc3_smpr2.smp3 = STM32446ADC3_smpr2_smp3;
	stm32446_adc3_smpr2.smp2 = STM32446ADC3_smpr2_smp2;
	stm32446_adc3_smpr2.smp1 = STM32446ADC3_smpr2_smp1;
	stm32446_adc3_smpr2.smp0 = STM32446ADC3_smpr2_smp0;
	return stm32446_adc3_smpr2;
}
STM32446ADC_SQR1 stm32446_adc3_sqr1_inic(void)
{
	STM32446ADC_SQR1 stm32446_adc3_sqr1;
	// SQR1
	stm32446_adc3_sqr1.l = STM32446ADC3_sqr1_l;
	stm32446_adc3_sqr1.sq16 = STM32446ADC3_sqr1_sq16;
	stm32446_adc3_sqr1.sq15 = STM32446ADC3_sqr1_sq15;
	stm32446_adc3_sqr1.sq14 = STM32446ADC3_sqr1_sq14;
	stm32446_adc3_sqr1.sq13 = STM32446ADC3_sqr1_sq13;
	return stm32446_adc3_sqr1;
}
STM32446ADC_SQR2 stm32446_adc3_sqr2_inic(void)
{
	STM32446ADC_SQR2 stm32446_adc3_sqr2;
	// SQR2
	stm32446_adc3_sqr2.sq12 = STM32446ADC3_sqr2_sq12;
	stm32446_adc3_sqr2.sq11 = STM32446ADC3_sqr2_sq11;
	stm32446_adc3_sqr2.sq10 = STM32446ADC3_sqr2_sq10;
	stm32446_adc3_sqr2.sq9 = STM32446ADC3_sqr2_sq9;
	stm32446_adc3_sqr2.sq8 = STM32446ADC3_sqr2_sq8;
	stm32446_adc3_sqr2.sq7 = STM32446ADC3_sqr2_sq7;
	return stm32446_adc3_sqr2;
}
STM32446ADC_SQR3 stm32446_adc3_sqr3_inic(void)
{
	STM32446ADC_SQR3 stm32446_adc3_sqr3;
	// SQ3
	stm32446_adc3_sqr3.sq6 = STM32446ADC3_sqr3_sq6;
	stm32446_adc3_sqr3.sq5 = STM32446ADC3_sqr3_sq5;
	stm32446_adc3_sqr3.sq4 = STM32446ADC3_sqr3_sq4;
	stm32446_adc3_sqr3.sq3 = STM32446ADC3_sqr3_sq3;
	stm32446_adc3_sqr3.sq2 = STM32446ADC3_sqr3_sq2;
	stm32446_adc3_sqr3.sq1 = STM32446ADC3_sqr3_sq1;
	return stm32446_adc3_sqr3;
}
STM32446ADC_JSQR stm32446_adc3_jsqr_inic(void)
{
	STM32446ADC_JSQR stm32446_adc3_jsqr;
	// JSQR
	stm32446_adc3_jsqr.jl = STM32446ADC3_jsqr_jl;
	stm32446_adc3_jsqr.jsq4 = STM32446ADC3_jsqr_jsq4;
	stm32446_adc3_jsqr.jsq3 = STM32446ADC3_jsqr_jsq3;
	stm32446_adc3_jsqr.jsq2 = STM32446ADC3_jsqr_jsq2;
	stm32446_adc3_jsqr.jsq1 = STM32446ADC3_jsqr_jsq1;
	return stm32446_adc3_jsqr;
}
/*** ADC3 ***/
void STM32446Adc3IClock(uint8_t bool)
{
	if(bool){ RCC->APB1ENR |= (1 << 29); } // DACEN: DAC interface clock enable
	else{ RCC->APB1ENR &= ~(1 << 29); } // DACEN: DAC interface clock disable
}
void STM32446Adc3Clock(uint8_t bool)
{
	if(bool){ RCC->APB2ENR |= (1 << 10); } // ADC3EN: ADC3 clock enable
	else{ RCC->APB2ENR &= ~(1 << 10); } // ADC3EN: ADC3 clock disable
}
void STM32446Adc3Nvic(uint8_t bool)
{
	if(bool){ setbit(NVIC->ISER, 1, 18, 1); } else{ setbit(NVIC->ICER, 1, 18, 1); }
}
void STM32446Adc3Inic(void)
{
	// ADC Clock
	// void STM32446Adc3IClock(1); // DACEN: DAC interface clock enable
	// STM32446Adc3Clock(1) // ADC3EN: ADC3 clock enable
	// ADC CONFIG
	STM32446ADC3_cr2_eocs(1); // EOCS: End of conversion selection
	STM32446ADC_ccr_adcpre(3); // ADCPRE: ADC prescaler, 11: PCLK2 divided by 8
	STM32446ADC3_smpr1_smp15(7); // SMPx[2:0]: Channel x sampling time selection
	STM32446ADC3_cr1_discen(1); // DISCEN: Discontinuous mode on regular channels
	STM32446ADC3_sqr3_sq1(15); // SQ1[4:0]: 1st conversion in regular sequence
}
void STM32446Adc3Start()
{
	// turn on select source and start reading
	STM32446ADC3_cr2_adon(1); // ADON: A/D Converter ON / OFF
	//
	STM32446ADC3_cr2_swstart(1); // SWSTART: Start conversion of regular channels
}
STM32446ADC3single stm32446_adc3_single_inic(void)
{
	STM32446ADC3single stm32446_adc3_single;
	stm32446_adc3_single.inic = STM32446Adc3Inic;
	stm32446_adc3_single.start = STM32446Adc3Start;
	return stm32446_adc3_single;
}
/*** ADC3 INIC Procedure & Function Definition ***/
STM32446ADC3obj adc3_inic(void)
{
	STM32446ADC3obj stm32446_adc3;
	stm32446_adc3.reg = ADC3;
	/*** ADC3 Bit Mapping Link ***/
	stm32446_adc3.sr = stm32446_adc3_sr_inic();
	stm32446_adc3.cr1 = stm32446_adc3_cr1_inic();
	stm32446_adc3.cr2 = stm32446_adc3_cr2_inic();
	stm32446_adc3.smpr1 = stm32446_adc3_smpr1_inic();
	stm32446_adc3.smpr2 = stm32446_adc3_smpr2_inic();
	stm32446_adc3.jofr1 = STM32446ADC3_jofr1;
	stm32446_adc3.jofr2 = STM32446ADC3_jofr2;
	stm32446_adc3.jofr3 = STM32446ADC3_jofr3;
	stm32446_adc3.jofr4 = STM32446ADC3_jofr4;
	stm32446_adc3.htr = STM32446ADC3_htr;
	stm32446_adc3.ltr = STM32446ADC3_ltr;
	stm32446_adc3.sqr1 = stm32446_adc3_sqr1_inic();
	stm32446_adc3.sqr2 = stm32446_adc3_sqr2_inic();
	stm32446_adc3.sqr3 = stm32446_adc3_sqr3_inic();
	stm32446_adc3.jsqr = stm32446_adc3_jsqr_inic();
	stm32446_adc3.jdr1 = STM32446ADC3_jdr1;
	stm32446_adc3.jdr2 = STM32446ADC3_jdr2;
	stm32446_adc3.jdr3 = STM32446ADC3_jdr3;
	stm32446_adc3.jdr4 = STM32446ADC3_jdr4;
	stm32446_adc3.dr = STM32446ADC3_dr;
	stm32446_adc3.common = stm32446_adc_common_inic();
	// Other
	stm32446_adc3.single = stm32446_adc3_single_inic();
	stm32446_adc3.iclock = STM32446Adc3IClock;
	stm32446_adc3.clock = STM32446Adc3Clock;
	stm32446_adc3.nvic = STM32446Adc3Nvic;
	return stm32446_adc3;
}

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

