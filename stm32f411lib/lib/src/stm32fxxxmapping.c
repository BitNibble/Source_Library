/******************************************************************************
	STM32 XXX MAPPING
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 19/06/2023
Update: 05/01/2024
Comment:
	-manual um1724, m0390, pm0056, pm0214, and other sources.
	-Virtual Image STM32-XXX, mapping.
	-Still in progress 15062023, increment has go along.
	-Dependent on CMSIS
	-Stable.
*******************************************************************************/
/*** File Library ***/
#include <stm32fxxxmapping.h>

/*** File Variables ***/
static STM32FXXX stm32fxxx;

/******* STM32F446RE Procedure & Function Definition *******/
STM32FXXX* STM32FXXX_enable(void){
	/************* CORE ************/
	// SCB
	stm32fxxx.scb_reg = SCB;
	// SysTick
	stm32fxxx.systick_reg = SysTick;
	// NVIC
	stm32fxxx.nvic_reg = NVIC;
	#if defined(_STM32FXXXNVIC_H_)
		stm32fxxx.nvic = nvic_enable();
	#endif
	/************ MCU ************/
	// ADC
	stm32fxxx.adc1_reg = ADC1;
	#ifdef STM32F446xx
		stm32fxxx.adc1_common_reg = ADC123_COMMON;
	#endif
	#ifdef STM32F411xE
		stm32fxxx.adc1_common_reg = ADC1_COMMON;
	#endif
	#if defined(_STM32FXXXADC1_H_)
		stm32fxxx.adc1 = adc1_enable();
	#endif
	#ifdef STM32F446xx
		stm32fxxx.adc2_reg = ADC2;
		stm32fxxx.adc2_common_reg = ADC123_COMMON;
	#endif
	#if defined(_STM32FXXXADC2_H_)
		#ifdef STM32F446xx
			stm32fxxx.adc2 = adc2_enable();
		#endif
	#endif
	#ifdef STM32F446xx
		stm32fxxx.adc3_reg = ADC3;
		stm32fxxx.adc3_common_reg = ADC123_COMMON;
	#endif
	#if defined(_STM32FXXXADC3_H_)
		#ifdef STM32F446xx
			stm32fxxx.adc3 = adc3_enable();
		#endif
	#endif
	// CRC
	stm32fxxx.crc_reg = CRC;
	#if defined(_STM32FXXXCRC_H_)
		stm32fxxx.crc = crc_enable();
	#endif
	// DMA
	stm32fxxx.dma1_reg = DMA1;
	stm32fxxx.dma1_stream0_reg = DMA1_Stream0;
	stm32fxxx.dma1_stream1_reg = DMA1_Stream1;
	stm32fxxx.dma1_stream2_reg = DMA1_Stream2;
	stm32fxxx.dma1_stream3_reg = DMA1_Stream3;
	stm32fxxx.dma1_stream4_reg = DMA1_Stream4;
	stm32fxxx.dma1_stream5_reg = DMA1_Stream5;
	stm32fxxx.dma1_stream6_reg = DMA1_Stream6;
	stm32fxxx.dma1_stream7_reg = DMA1_Stream7;
	stm32fxxx.dma2_reg = DMA2;
	stm32fxxx.dma2_stream0_reg = DMA2_Stream0;
	stm32fxxx.dma2_stream1_reg = DMA2_Stream1;
	stm32fxxx.dma2_stream2_reg = DMA2_Stream2;
	stm32fxxx.dma2_stream3_reg = DMA2_Stream3;
	stm32fxxx.dma2_stream4_reg = DMA2_Stream4;
	stm32fxxx.dma2_stream5_reg = DMA2_Stream5;
	stm32fxxx.dma2_stream6_reg = DMA2_Stream6;
	stm32fxxx.dma2_stream7_reg = DMA2_Stream7;
	#if defined(_STM32FXXXDMA_H_)
		stm32fxxx.dma1 = dma1_enable();
		stm32fxxx.dma2 = dma2_enable();
	#endif
	// FLASH
	stm32fxxx.flash_reg = FLASH;
	#if defined(_STM32FXXXFLASH_H_)
		stm32fxxx.flash = flash_enable();
	#endif
	// GPIO
	stm32fxxx.gpioa_reg = GPIOA;
	stm32fxxx.gpiob_reg = GPIOB;
	stm32fxxx.gpioc_reg = GPIOC;
	stm32fxxx.gpiod_reg = GPIOD;
	stm32fxxx.gpioe_reg = GPIOE;
	#ifdef STM32F446xx
		stm32fxxx.gpiof_reg = GPIOF;
		stm32fxxx.gpiog_reg = GPIOG;
	#endif
	stm32fxxx.gpioh_reg = GPIOH;
	#if defined(_STM32FXXXGPIO_H_)
		stm32fxxx.gpioa = gpioa_enable();
		stm32fxxx.gpiob = gpiob_enable();
		stm32fxxx.gpioc = gpioc_enable();
		stm32fxxx.gpiod = gpiod_enable();
		stm32fxxx.gpioe = gpioe_enable();
		stm32fxxx.gpioh = gpioh_enable();
	#endif
	// SYSCFG
	stm32fxxx.syscfg_reg = SYSCFG;
	#if defined(_STM32FXXXSYSCFG_H_)
		stm32fxxx.syscfg = syscfg_enable();
	#endif
	// PWR
	stm32fxxx.pwr_reg = PWR;
	#if defined(_STM32FXXXPWR_H_)
		stm32fxxx.pwr = pwr_enable();
	#endif
	// RCC
	stm32fxxx.rcc_reg = RCC;
	#if defined(_STM32FXXXRCC_H_)
		stm32fxxx.rcc = rcc_enable();
	#endif
	// RTC
	stm32fxxx.rtc_reg = RTC;
	#if defined(_STM32FXXXRTC_H_)
		stm32fxxx.rtc = rtc_enable();
	#endif
	// SRAM
	#if defined(_STM32FXXXSRAM_H_)
		stm32fxxx.sram = sram_enable();
	#endif
	// TIM
	stm32fxxx.tim1_reg = TIM1;
	#ifdef STM32F446xx
		stm32fxxx.tim8_reg = TIM8;
	#endif
	#if defined(_STM32FXXXTIM1AND8_H_)
		stm32fxxx.tim1 = tim1_enable();
		#ifdef STM32F446xx
			stm32fxxx.tim8 = tim8_enable();
		#endif
	#endif
	stm32fxxx.tim2_reg = TIM2;
	stm32fxxx.tim3_reg = TIM3;
	stm32fxxx.tim4_reg = TIM4;
	stm32fxxx.tim5_reg = TIM5;
	#if defined(_STM32FXXXTIM2TO5_H_)
		stm32fxxx.tim2 = tim2_enable();
		stm32fxxx.tim3 = tim3_enable();
		stm32fxxx.tim4 = tim4_enable();
		stm32fxxx.tim5 = tim5_enable();
	#endif
	#ifdef STM32F446xx
		stm32fxxx.tim6_reg = TIM6;
		stm32fxxx.tim7_reg = TIM7;
	#endif
	#if defined(_STM32FXXXTIM6AND7_H_)
		#ifdef STM32F446xx
			stm32fxxx.tim6 = tim6_enable();
			stm32fxxx.tim7 = tim7_enable();
		#endif
	#endif
	stm32fxxx.tim9_reg = TIM9;
	stm32fxxx.tim10_reg = TIM10;
	stm32fxxx.tim11_reg = TIM11;
	#ifdef STM32F446xx
		stm32fxxx.tim12_reg = TIM12;
		stm32fxxx.tim13_reg = TIM13;
		stm32fxxx.tim14_reg = TIM14;
	#endif
	#if defined(_STM32FXXXTIM9TO14_H_)
		stm32fxxx.tim9 = tim9_enable();
		stm32fxxx.tim10 = tim10_enable();
		stm32fxxx.tim11 = tim11_enable();
		#ifdef STM32F446xx
			stm32fxxx.tim12 = tim12_enable();
			stm32fxxx.tim13 = tim13_enable();
			stm32fxxx.tim14 = tim14_enable();
		#endif
	#endif
	// USART
	stm32fxxx.usart1_reg = USART1;
	stm32fxxx.usart2_reg = USART2;
	#ifdef STM32F446xx
		stm32fxxx.usart3_reg = USART3;
		stm32fxxx.uart4_reg = UART4;
		stm32fxxx.uart5_reg = UART5;
	#endif
	stm32fxxx.usart6_reg = USART6;
	#if defined(_STM32FXXXUSART_H_)
		stm32fxxx.usart1 = usart1_enable();
		stm32fxxx.usart2 = usart2_enable();
		#ifdef STM32F446xx
			stm32fxxx.usart3 = usart3_enable();
			stm32fxxx.uart4 = uart4_enable();
			stm32fxxx.uart5 = uart5_enable();
		#endif
		stm32fxxx.usart6 = usart6_enable();
	#endif

	/*** System ***/
	rcc_start();
	query_enable();
	systick_start();

	return &stm32fxxx;
}

STM32FXXX* stm(void){return (STM32FXXX*) &stm32fxxx;}

/***EOF***/

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

