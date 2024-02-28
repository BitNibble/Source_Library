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
#ifdef STM32F446xx
// ADC2
static STM32FXXXADC2obj stm32fxxx_adc2;
static STM32FXXXADC2single stm32fxxx_adc2_single;
/*** File Procedure & Function Header ***/
STM32FXXXADC2single* stm32fxxx_adc2_single_inic(void);
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
	STM32FXXXADC2obj* adc2_config = adc2_enable();
	// ADC Clock
	// void STM32FXXXAdc2IClock(1); // DACEN: DAC interface clock enable
	// STM32FXXXAdc2Clock(1) // ADC2EN: ADC2 clock enable
	// ADC CONFIG
	STM32FXXXADC2_cr2_eocs(1); // EOCS: End of conversion selection
	adc2_config->common->ccr->par.adcpre = 3; // ADCPRE: ADC prescaler, 11: PCLK2 divided by 8
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
	stm32fxxx_adc2.sr = (STM32FXXXADC_SR_TypeDef*) &ADC2->SR;
	stm32fxxx_adc2.cr1 = (STM32FXXXADC_CR1_TypeDef*) &ADC2->CR1;
	stm32fxxx_adc2.cr2 = (STM32FXXXADC_CR2_TypeDef*) &ADC2->CR2;
	stm32fxxx_adc2.smpr1 = (STM32FXXXADC_SMPR1_TypeDef*) &ADC2->SMPR1;
	stm32fxxx_adc2.smpr2 = (STM32FXXXADC_SMPR2_TypeDef*) &ADC2->SMPR2;
	stm32fxxx_adc2.jofr1 = (STM32FXXXADC_JOFRx_TypeDef*) &ADC2->JOFR1;
	stm32fxxx_adc2.jofr2 = (STM32FXXXADC_JOFRx_TypeDef*) &ADC2->JOFR2;
	stm32fxxx_adc2.jofr3 = (STM32FXXXADC_JOFRx_TypeDef*) &ADC2->JOFR3;
	stm32fxxx_adc2.jofr4 = (STM32FXXXADC_JOFRx_TypeDef*) &ADC2->JOFR4;
	stm32fxxx_adc2.htr = (STM32FXXXADC_HTR_TypeDef*) &ADC2->HTR;
	stm32fxxx_adc2.ltr = (STM32FXXXADC_LTR_TypeDef*) &ADC2->LTR;
	stm32fxxx_adc2.sqr1 = (STM32FXXXADC_SQR1_TypeDef*) &ADC2->SQR1;
	stm32fxxx_adc2.sqr2 = (STM32FXXXADC_SQR2_TypeDef*) &ADC2->SQR2;
	stm32fxxx_adc2.sqr3 = (STM32FXXXADC_SQR3_TypeDef*) &ADC2->SQR3;
	stm32fxxx_adc2.jsqr = (STM32FXXXADC_JSQR_TypeDef*) &ADC2->JSQR;
	stm32fxxx_adc2.jdr1 = (STM32FXXXADC_JDRx_TypeDef*) &ADC2->JDR1;
	stm32fxxx_adc2.jdr2 = (STM32FXXXADC_JDRx_TypeDef*) &ADC2->JDR2;
	stm32fxxx_adc2.jdr3 = (STM32FXXXADC_JDRx_TypeDef*) &ADC2->JDR3;
	stm32fxxx_adc2.jdr4 = (STM32FXXXADC_JDRx_TypeDef*) &ADC2->JDR4;
	stm32fxxx_adc2.dr = (STM32FXXXADC_DR_TypeDef*) &ADC2->DR;
	stm32fxxx_adc2.common = stm32fxxx_adc_common_inic();
	// Other
	stm32fxxx_adc2.single = stm32fxxx_adc2_single_inic();
	stm32fxxx_adc2.iclock = STM32FXXXAdc2IClock;
	stm32fxxx_adc2.clock = STM32FXXXAdc2Clock;
	stm32fxxx_adc2.nvic = STM32FXXXAdc2Nvic;
	return &stm32fxxx_adc2;
}

STM32FXXXADC2obj* adc2(void){ return (STM32FXXXADC2obj*) &stm32fxxx_adc2; }

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

