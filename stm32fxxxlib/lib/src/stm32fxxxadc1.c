/******************************************************************************
	STM32 XXX ADC1
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 28022024
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxadc1.h"

/*** File Variables ***/
// ADC1
static STM32FXXXADC1obj stm32fxxx_adc1;
static STM32FXXXADC1single stm32fxxx_adc1_single;
/*** File Procedure & Function Header ***/
STM32FXXXADC1single* stm32fxxx_adc1_single_inic(void);
/*** ADC1 ***/
void STM32FXXXAdc1IClock(uint8_t bool)
{
	if(bool){ RCC->APB1ENR |= (1 << 29); }else{ RCC->APB1ENR &= ~(1 << 29); }
}
void STM32FXXXAdc1Clock(uint8_t bool)
{
	if(bool){ RCC->APB2ENR |= (1 << 8); }else{ RCC->APB2ENR &= ~(1 << 8); }
}
void STM32FXXXAdc1Nvic(uint8_t bool)
{
	if(bool){ setbit(NVIC->ISER, 1, ADC_IRQn, 1); } else{ setbit(NVIC->ICER, 1, ADC_IRQn, 1); }
}
void STM32FXXXAdc1Inic(void)
{
	STM32FXXXADC1obj* adc1_config = adc1_enable();
	//STM32FXXXADCCOMMONobj* adc_common = stm32fxxx_adc_common_inic( );
	// ADC Clock
	 STM32FXXXAdc1IClock(1); // DACEN: DAC interface clock enable
	 STM32FXXXAdc1Clock(1); // ADC1EN: ADC1 clock enable
	 adc1_config->cr2->par.adon = 0; // ADON: A/D Converter ON / OFF
	// ADC CONFIG
	//STM32FXXXADC1_cr1_discnum(1);
	//STM32FXXXADC1_cr1_scan(1);
	//STM32FXXXADC1_cr2_eocs(1); // EOCS: End of conversion selection

	 adc1_config->common->ccr->par.adcpre = 3; // ADCPRE: ADC prescaler, 11: PCLK2 divided by 8
	 //adc_common->ccr->par.adcpre = 3; // ADCPRE: ADC prescaler, 11: PCLK2 divided by 8

	adc1_config->smpr1->par.smp18 = 7; // SMPx[2:0]: Channel x sampling time selection
	adc1_config->smpr2->par.smp0 = 7; // SMPx[2:0]: Channel x sampling time selection
	adc1_config->sqr1->par.l = 1; // 0 -> read one channel, 1 -> read two channels
	adc1_config->sqr3->par.sq1 = 18; // SQ1[4:0]: 1st conversion in regular sequence
	adc1_config->sqr3->par.sq2 = 0; // SQ2[4:0]: 2st conversion in regular sequence

	//STM32FXXXADC1_cr1_discen(1); // DISCEN: Discontinuous mode on regular channels
}
void STM32FXXXAdc1VBAT(void) // vbat overrides temperature
{
	STM32FXXXADC1obj* adc1_config = adc1_enable();
	adc1_config->common->ccr->par.vbate = 1; // VBATE: VBAT enable
}
void STM32FXXXAdc1TEMP(void)
{
	STM32FXXXADC1obj* adc1_config = adc1_enable();
	// Temperature (in degrees) = {(VSENSE V25) / Avg_Slope} + 25
	adc1_config->common->ccr->par.tsvrefe = 1; // TSVREFE: Temperature sensor and VREFINT enable
}
void STM32FXXXAdc1Start(void)
{
	uint32_t time_out;
	STM32FXXXADC1obj* adc1_config = adc1_enable();
	// turn on select source and start reading
	adc1_config->cr2->par.adon = 1; // ADON: A/D Converter ON / OFF
	adc1_config->cr2->par.swstart = 1; // SWSTART: Start conversion of regular channels
	for(time_out = 200; adc1_config->cr2->par.swstart && time_out; time_out-- );
}
STM32FXXXADC1single* stm32fxxx_adc1_single_inic(void)
{
	stm32fxxx_adc1_single.inic = STM32FXXXAdc1Inic;
	stm32fxxx_adc1_single.vbat = STM32FXXXAdc1VBAT;
	stm32fxxx_adc1_single.temp = STM32FXXXAdc1TEMP;
	stm32fxxx_adc1_single.start = STM32FXXXAdc1Start;
	return &stm32fxxx_adc1_single;
}
/*** ADC1 INIC Procedure & Function Definition ***/
STM32FXXXADC1obj* adc1_enable(void)
{

	/*** ADC1 Bit Mapping Link ***/
	stm32fxxx_adc1.sr = (STM32FXXXADC_SR_TypeDef*) &ADC1->SR;
	stm32fxxx_adc1.cr1 = (STM32FXXXADC_CR1_TypeDef*) &ADC1->CR1;
	stm32fxxx_adc1.cr2 = (STM32FXXXADC_CR2_TypeDef*) &ADC1->CR2;
	stm32fxxx_adc1.smpr1 = (STM32FXXXADC_SMPR1_TypeDef*) &ADC1->SMPR1;
	stm32fxxx_adc1.smpr2 = (STM32FXXXADC_SMPR2_TypeDef*) &ADC1->SMPR2;
	stm32fxxx_adc1.jofr1 = (STM32FXXXADC_JOFRx_TypeDef*) &ADC1->JOFR1;
	stm32fxxx_adc1.jofr2 = (STM32FXXXADC_JOFRx_TypeDef*) &ADC1->JOFR2;
	stm32fxxx_adc1.jofr3 = (STM32FXXXADC_JOFRx_TypeDef*) &ADC1->JOFR3;
	stm32fxxx_adc1.jofr4 = (STM32FXXXADC_JOFRx_TypeDef*) &ADC1->JOFR4;
	stm32fxxx_adc1.htr = (STM32FXXXADC_HTR_TypeDef*) &ADC1->HTR;
	stm32fxxx_adc1.ltr = (STM32FXXXADC_LTR_TypeDef*) &ADC1->LTR;
	stm32fxxx_adc1.sqr1 = (STM32FXXXADC_SQR1_TypeDef*) &ADC1->SQR1;
	stm32fxxx_adc1.sqr2 = (STM32FXXXADC_SQR2_TypeDef*) &ADC1->SQR2;
	stm32fxxx_adc1.sqr3 = (STM32FXXXADC_SQR3_TypeDef*) &ADC1->SQR3;
	stm32fxxx_adc1.jsqr = (STM32FXXXADC_JSQR_TypeDef*) &ADC1->JSQR;
	stm32fxxx_adc1.jdr1 = (STM32FXXXADC_JDRx_TypeDef*) &ADC1->JDR1;
	stm32fxxx_adc1.jdr2 = (STM32FXXXADC_JDRx_TypeDef*) &ADC1->JDR2;
	stm32fxxx_adc1.jdr3 = (STM32FXXXADC_JDRx_TypeDef*) &ADC1->JDR3;
	stm32fxxx_adc1.jdr4 = (STM32FXXXADC_JDRx_TypeDef*) &ADC1->JDR4;
	stm32fxxx_adc1.dr = (STM32FXXXADC_DR_TypeDef*) &ADC1->DR;
	stm32fxxx_adc1.common = stm32fxxx_adc_common_inic();
	/*** Other ***/
	stm32fxxx_adc1.single = stm32fxxx_adc1_single_inic();
	stm32fxxx_adc1.start = STM32FXXXAdc1Start;
	stm32fxxx_adc1.iclock = STM32FXXXAdc1IClock;
	stm32fxxx_adc1.clock = STM32FXXXAdc1Clock;
	stm32fxxx_adc1.nvic = STM32FXXXAdc1Nvic;
	return &stm32fxxx_adc1;
}

STM32FXXXADC1obj* adc1(void){ return (STM32FXXXADC1obj*) &stm32fxxx_adc1; }

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

/*** EOF ***/



