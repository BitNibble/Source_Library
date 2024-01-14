/******************************************************************************
	STM32 446 ADC
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 19062023
Update: 10012024
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32446adc.h"

/*** ADC Common Header ***/
STM32446ADC_CSR stm32446_adc_common_csr;
STM32446ADC_CCR stm32446_adc_common_ccr;
STM32446ADCCOMMONobj stm32446_adc_common;

/*** COMMON ***/
// CSR
uint8_t STM32446ADC_csr_ovr3(void)
{
	return readreg(ADC->CSR, 1, 21);
}
uint8_t STM32446ADC_csr_strt3(void)
{
	return readreg(ADC->CSR, 1, 20);
}
uint8_t STM32446ADC_csr_jstrt3(void)
{
	return readreg(ADC->CSR, 1, 19);
}
uint8_t STM32446ADC_csr_jeoc3(void)
{
	return readreg(ADC->CSR, 1, 18);
}
uint8_t STM32446ADC_csr_eoc3(void)
{
	return readreg(ADC->CSR, 1, 17);
}
uint8_t STM32446ADC_csr_awd3(void)
{
	return readreg(ADC->CSR, 1, 16);
}
uint8_t STM32446ADC_csr_ovr2(void)
{
	return readreg(ADC->CSR, 1, 13);
}
uint8_t STM32446ADC_csr_strt2(void)
{
	return readreg(ADC->CSR, 1, 12);
}
uint8_t STM32446ADC_csr_jstrt2(void)
{
	return readreg(ADC->CSR, 1, 11);
}
uint8_t STM32446ADC_csr_jeoc2(void)
{
	return readreg(ADC->CSR, 1, 10);
}
uint8_t STM32446ADC_csr_eoc2(void)
{
	return readreg(ADC->CSR, 1, 9);
}
uint8_t STM32446ADC_csr_awd2(void)
{
	return readreg(ADC->CSR, 1, 8);
}
uint8_t STM32446ADC_csr_ovr1(void)
{
	return readreg(ADC->CSR, 1, 5);
}
uint8_t STM32446ADC_csr_strt1(void)
{
	return readreg(ADC->CSR, 1, 4);
}
uint8_t STM32446ADC_csr_jstrt1(void)
{
	return readreg(ADC->CSR, 1, 3);
}
uint8_t STM32446ADC_csr_jeoc1(void)
{
	return readreg(ADC->CSR, 1, 2);
}
uint8_t STM32446ADC_csr_eoc1(void)
{
	return readreg(ADC->CSR, 1, 1);
}
uint8_t STM32446ADC_csr_awd1(void)
{
	return readreg(ADC->CSR, 1, 0);
}
// CCR
void STM32446ADC_ccr_tsvrefe(uint8_t bool)
{
	setreg(&ADC->CCR, 1, 23, bool);
}
void STM32446ADC_ccr_vbate(uint8_t bool)
{
	setreg(&ADC->CCR, 2, 22, bool);
}
void STM32446ADC_ccr_adcpre(uint8_t value)
{
	setreg(&ADC->CCR, 2, 16, value);
}
void STM32446ADC_ccr_dma(uint8_t value)
{
	setreg(&ADC->CCR, 2, 14, value);
}
void STM32446ADC_ccr_dds(uint8_t bool)
{
	setreg(&ADC->CCR, 1, 13, bool);
}
void STM32446ADC_ccr_delay(uint8_t value)
{
	setreg(&ADC->CCR, 4, 8, value);
}
void STM32446ADC_ccr_multi(uint8_t value)
{
	setreg(&ADC->CCR, 5, 0, value);
}
// CDR
uint32_t STM32446ADC_cdr(void)
{
	return readreg(ADC->CDR, 32, 0);
}
/*** Auxiliar ***/
STM32446ADC_CSR* stm32446_adc_common_csr_inic(void)
{
	// CSR
	stm32446_adc_common_csr.ovr3 = STM32446ADC_csr_ovr3;
	stm32446_adc_common_csr.strt3 = STM32446ADC_csr_strt3;
	stm32446_adc_common_csr.jstrt3 = STM32446ADC_csr_jstrt3;
	stm32446_adc_common_csr.jeoc3 = STM32446ADC_csr_jeoc3;
	stm32446_adc_common_csr.eoc3 = STM32446ADC_csr_eoc3;
	stm32446_adc_common_csr.awd3 = STM32446ADC_csr_awd3;
	stm32446_adc_common_csr.ovr2 = STM32446ADC_csr_ovr2;
	stm32446_adc_common_csr.strt2 = STM32446ADC_csr_strt2;
	stm32446_adc_common_csr.jstrt2 = STM32446ADC_csr_jstrt2;
	stm32446_adc_common_csr.jeoc2 = STM32446ADC_csr_jeoc2;
	stm32446_adc_common_csr.eoc2 = STM32446ADC_csr_eoc2;
	stm32446_adc_common_csr.awd2 = STM32446ADC_csr_awd2;
	stm32446_adc_common_csr.ovr1 = STM32446ADC_csr_ovr1;
	stm32446_adc_common_csr.strt1 = STM32446ADC_csr_strt1;
	stm32446_adc_common_csr.jstrt1 = STM32446ADC_csr_jstrt1;
	stm32446_adc_common_csr.jeoc1 = STM32446ADC_csr_jeoc1;
	stm32446_adc_common_csr.eoc1 = STM32446ADC_csr_eoc1;
	stm32446_adc_common_csr.awd1 = STM32446ADC_csr_awd1;
	return &stm32446_adc_common_csr;
}
STM32446ADC_CCR* stm32446_adc_common_ccr_inic(void)
{
	// CCR
	stm32446_adc_common_ccr.tsvrefe = STM32446ADC_ccr_tsvrefe;
	stm32446_adc_common_ccr.vbate = STM32446ADC_ccr_vbate;
	stm32446_adc_common_ccr.adcpre = STM32446ADC_ccr_adcpre;
	stm32446_adc_common_ccr.dma = STM32446ADC_ccr_dma;
	stm32446_adc_common_ccr.dds = STM32446ADC_ccr_dds;
	stm32446_adc_common_ccr.delay = STM32446ADC_ccr_delay;
	stm32446_adc_common_ccr.multi = STM32446ADC_ccr_multi;
	return &stm32446_adc_common_ccr;
}
STM32446ADCCOMMONobj* stm32446_adc_common_inic(void)
{
	stm32446_adc_common.reg = ADC123_COMMON;
	// CSR
	stm32446_adc_common.csr = stm32446_adc_common_csr_inic();
	// CCR
	stm32446_adc_common.ccr = stm32446_adc_common_ccr_inic();
	// CDR
	stm32446_adc_common.cdr = STM32446ADC_cdr;
	return &stm32446_adc_common;
}

/*** EOF ***/

