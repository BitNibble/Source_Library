/******************************************************************************
	STM32 XXX ADC3
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 19062023
Update: 10012024
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxadc3.h"

/*** File Variables ***/
#ifdef STM32F446xx
// ADC3
static STM32FXXXADC3obj stm32fxxx_adc3;
static STM32FXXXADC3single stm32fxxx_adc3_single;
/*** File Procedure & Function Header ***/
STM32FXXXADC3single* stm32fxxx_adc3_single_inic(void);
/*** ADC3 ***/
void STM32FXXXAdc3IClock(uint8_t bool)
{
	if(bool){ RCC->APB1ENR |= (1 << 29); }else{ RCC->APB1ENR &= ~(1 << 29); }
}
void STM32FXXXAdc3Clock(uint8_t bool)
{
	if(bool){ RCC->APB2ENR |= (1 << 10); }else{ RCC->APB2ENR &= ~(1 << 10); }
}
void STM32FXXXAdc3Nvic(uint8_t bool)
{
	if(bool){ setbit(NVIC->ISER, 1, ADC_IRQn, 1); } else{ setbit(NVIC->ICER, 1, ADC_IRQn, 1); }
}
void STM32FXXXAdc3Inic(void)
{
	STM32FXXXADC3obj* adc3_config = adc3_enable();
	// ADC Clock
	// void STM32FXXXAdc3IClock(1); // DACEN: DAC interface clock enable
	// STM32FXXXAdc3Clock(1) // ADC3EN: ADC3 clock enable
	// ADC CONFIG
	STM32FXXXADC3_cr2_eocs(1); // EOCS: End of conversion selection
	adc3_config->common->ccr->par.adcpre = 3; // ADCPRE: ADC prescaler, 11: PCLK2 divided by 8
	STM32FXXXADC3_smpr1_smp15(7); // SMPx[2:0]: Channel x sampling time selection
	STM32FXXXADC3_cr1_discen(1); // DISCEN: Discontinuous mode on regular channels
	STM32FXXXADC3_sqr3_sq1(15); // SQ1[4:0]: 1st conversion in regular sequence
}
void STM32FXXXAdc3Start()
{
	// turn on select source and start reading
	STM32FXXXADC3_cr2_adon(1); // ADON: A/D Converter ON / OFF
	//
	STM32FXXXADC3_cr2_swstart(1); // SWSTART: Start conversion of regular channels
}
STM32FXXXADC3single* stm32fxxx_adc3_single_inic(void)
{

	stm32fxxx_adc3_single.inic = STM32FXXXAdc3Inic;
	stm32fxxx_adc3_single.start = STM32FXXXAdc3Start;
	return &stm32fxxx_adc3_single;
}
/*** ADC3 INIC Procedure & Function Definition ***/
STM32FXXXADC3obj adc3_enable(void)
{

	/*** ADC3 Bit Mapping Link ***/
	stm32fxxx_adc3.sr = (STM32FXXXADC_SR_TypeDef*) &ADC3->SR;
	stm32fxxx_adc3.cr1 = (STM32FXXXADC_CR1_TypeDef*) &ADC3->CR1;
	stm32fxxx_adc3.cr2 = (STM32FXXXADC_CR2_TypeDef*) &ADC3->CR2;
	stm32fxxx_adc3.smpr1 = (STM32FXXXADC_SMPR1_TypeDef*) &ADC3->SMPR1;
	stm32fxxx_adc3.smpr2 = (STM32FXXXADC_SMPR2_TypeDef*) &ADC3->SMPR2;
	stm32fxxx_adc3.jofr1 = (STM32FXXXADC_JOFRx_TypeDef*) &ADC3->JOFR1;
	stm32fxxx_adc3.jofr2 = (STM32FXXXADC_JOFRx_TypeDef*) &ADC3->JOFR2;
	stm32fxxx_adc3.jofr3 = (STM32FXXXADC_JOFRx_TypeDef*) &ADC3->JOFR3;
	stm32fxxx_adc3.jofr4 = (STM32FXXXADC_JOFRx_TypeDef*) &ADC3->JOFR4;
	stm32fxxx_adc3.htr = (STM32FXXXADC_HTR_TypeDef*) &ADC3->HTR;
	stm32fxxx_adc3.ltr = (STM32FXXXADC_LTR_TypeDef*) &ADC3->LTR;
	stm32fxxx_adc3.sqr1 = (STM32FXXXADC_SQR1_TypeDef*) &ADC3->SQR1;
	stm32fxxx_adc3.sqr2 = (STM32FXXXADC_SQR2_TypeDef*) &ADC3->SQR2;
	stm32fxxx_adc3.sqr3 = (STM32FXXXADC_SQR3_TypeDef*) &ADC3->SQR3;
	stm32fxxx_adc3.jsqr = (STM32FXXXADC_JSQR_TypeDef*) &ADC3->JSQR;
	stm32fxxx_adc3.jdr1 = (STM32FXXXADC_JDRx_TypeDef*) &ADC3->JDR1;
	stm32fxxx_adc3.jdr2 = (STM32FXXXADC_JDRx_TypeDef*) &ADC3->JDR2;
	stm32fxxx_adc3.jdr3 = (STM32FXXXADC_JDRx_TypeDef*) &ADC3->JDR3;
	stm32fxxx_adc3.jdr4 = (STM32FXXXADC_JDRx_TypeDef*) &ADC3->JDR4;
	stm32fxxx_adc3.dr = (STM32FXXXADC_DR_TypeDef*) &ADC3->DR;
	stm32fxxx_adc3.common = stm32fxxx_adc_common_inic();
	// Other
	stm32fxxx_adc3.single = stm32fxxx_adc3_single_inic();
	stm32fxxx_adc3.iclock = STM32FXXXAdc3IClock;
	stm32fxxx_adc3.clock = STM32FXXXAdc3Clock;
	stm32fxxx_adc3.nvic = STM32FXXXAdc3Nvic;
	return &stm32fxxx_adc3;
}

STM32FXXXADC3obj* adc3(void){ return (STM32FXXXADC3obj*) &stm32fxxx_adc3; }

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

