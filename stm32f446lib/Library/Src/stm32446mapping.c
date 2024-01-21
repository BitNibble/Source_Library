/******************************************************************************
	STM32 446 MAPPING
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 19/06/2023
Update: 05/01/2024
Comment:
	-manual um1724, m0390, pm0056, pm0214, and other sources.
	-Virtual Image STM32-446, mapping.
	-Still in progress 15062023, increment has go along.
	-Dependent on CMSIS
	-Stable.
*******************************************************************************/
/*** File Library ***/
#include "stm32446mapping.h"

/*** File Variables ***/
static STM32446 stm32446;

/******* STM32F446RE Procedure & Function Definition *******/
STM32446 STM32446_enable(void){
	/************* CORE ************/
	// SCB
	stm32446.scb_reg = SCB;
	// SysTick
	stm32446.systick_reg = SysTick;
	// NVIC
	#if defined(_STM32446NVIC_H_)
		nvic_enable();
		stm32446.nvic_reg = NVIC;
		stm32446.nvic = nvic();
	#endif
	/************ MCU ************/
	// ADC
	#if defined(_STM32446ADC1_H_)
		adc1_enable();
		stm32446.adc1_common_reg = ADC123_COMMON;
		stm32446.adc1_reg = ADC1;
		stm32446.adc1 = adc1();
	#endif
	#if defined(_STM32446ADC2_H_)
		adc2_enable();
		stm32446.adc2_common_reg = ADC123_COMMON;
		stm32446.adc2_reg = ADC2;
		stm32446.adc2 = adc2();
	#endif
	#if defined(_STM32446ADC3_H_)
		adc3_enable();
		stm32446.adc3_common_reg = ADC123_COMMON;
		stm32446.adc3_reg = ADC3;
		stm32446.adc3 = adc3();
	#endif
	// CRC
	#if defined(_STM32446CRC_H_)
		crc_enable();
		stm32446.crc_reg = CRC;
		stm32446.crc = crc();
	#endif
	// DMA
	#if defined(_STM32446DMA_H_)
		dma1_enable();
		stm32446.dma1_reg = DMA1;
		stm32446.dma1_stream0_reg = DMA1_Stream0;
		stm32446.dma1_stream1_reg = DMA1_Stream1;
		stm32446.dma1_stream2_reg = DMA1_Stream2;
		stm32446.dma1_stream3_reg = DMA1_Stream3;
		stm32446.dma1_stream4_reg = DMA1_Stream4;
		stm32446.dma1_stream5_reg = DMA1_Stream5;
		stm32446.dma1_stream6_reg = DMA1_Stream6;
		stm32446.dma1_stream7_reg = DMA1_Stream7;
		stm32446.dma1 = dma1();
		dma2_enable();
		stm32446.dma2_reg = DMA2;
		stm32446.dma2_stream0_reg = DMA2_Stream0;
		stm32446.dma2_stream1_reg = DMA2_Stream1;
		stm32446.dma2_stream2_reg = DMA2_Stream2;
		stm32446.dma2_stream3_reg = DMA2_Stream3;
		stm32446.dma2_stream4_reg = DMA2_Stream4;
		stm32446.dma2_stream5_reg = DMA2_Stream5;
		stm32446.dma2_stream6_reg = DMA2_Stream6;
		stm32446.dma2_stream7_reg = DMA2_Stream7;
		stm32446.dma2 = dma2();
	#endif
	// FLASH
	#if defined(_STM32446FLASH_H_)
		flash_enable();
		stm32446.flash_reg = FLASH;
		stm32446.flash = flash();
	#endif
	// GPIO
	#if defined(_STM32446GPIO_H_)
		gpioa_enable();
		stm32446.gpioa_reg = GPIOA;
		stm32446.gpioa = gpioa();
		gpiob_enable();
		stm32446.gpiob_reg = GPIOB;
		stm32446.gpiob = gpiob();
		gpioc_enable();
		stm32446.gpioc_reg = GPIOC;
		stm32446.gpioc = gpioc();
		gpiod_enable();
		stm32446.gpiod_reg = GPIOD;
		stm32446.gpiod = gpiod();
		gpioe_enable();
		stm32446.gpioe_reg = GPIOE;
		stm32446.gpioe = gpioe();
		gpioh_enable();
		stm32446.gpioh_reg = GPIOH;
		stm32446.gpioh = gpioh();
	#endif
	// SYSCFG
	#if defined(_STM32446SYSCFG_H_)
		syscfg_enable();
		stm32446.syscfg_reg = SYSCFG;
		stm32446.syscfg = syscfg();
	#endif
	// PWR
	#if defined(_STM32446PWR_H_)
		pwr_enable();
		stm32446.pwr_reg = PWR;
		stm32446.pwr = pwr();
	#endif
	// RCC
	#if defined(_STM32FXXXRCC_H_)
		rcc_enable();
		stm32446.rcc_reg = RCC;
		stm32446.rcc = rcc();
	#endif
	// RTC
	#if defined(_STM32446RTC_H_)
		rtc_enable();
		stm32446.rtc_reg = RTC;
		stm32446.rtc = rtc();
	#endif
	// SRAM
	#if defined(_STM32446SRAM_H_)
		sram_enable();
		stm32446.sram = sram();
	#endif
	// TIM
	#if defined(_STM32446TIM1AND8_H_)
		tim1_enable();
		stm32446.tim1_reg = TIM1;
		stm32446.tim1 = tim1();
		tim8_enable();
		stm32446.tim8_reg = TIM8;
		stm32446.tim8 = tim8();
	#endif
	#if defined(_STM32446TIM2TO5_H_)
		tim2_enable();
		stm32446.tim2_reg = TIM2;
		stm32446.tim2 = tim2();
		tim3_enable();
		stm32446.tim3_reg = TIM3;
		stm32446.tim3 = tim3();
		tim4_enable();
		stm32446.tim4_reg = TIM4;
		stm32446.tim4 = tim4();
		tim5_enable();
		stm32446.tim5_reg = TIM5;
		stm32446.tim5 = tim5();
	#endif
	#if defined(_STM32446TIM6AND7_H_)
		tim6_enable();
		stm32446.tim6_reg = TIM6;
		stm32446.tim6 = tim6();
		tim7_enable();
		stm32446.tim7_reg = TIM7;
		stm32446.tim7 = tim7();
	#endif
	#if defined(_STM32446TIM9TO14_H_)
		tim9_enable();
		stm32446.tim9_reg = TIM9;
		stm32446.tim9 = tim9();
		tim10_enable();
		stm32446.tim10_reg = TIM10;
		stm32446.tim10 = tim10();
		tim11_enable();
		stm32446.tim11_reg = TIM11;
		stm32446.tim11 = tim11();
		tim12_enable();
		stm32446.tim12_reg = TIM12;
		stm32446.tim12 = tim12();
		tim13_enable();
		stm32446.tim13_reg = TIM13;
		stm32446.tim13 = tim13();
		tim14_enable();
		stm32446.tim14_reg = TIM14;
		stm32446.tim14 = tim14();
	#endif
	// USART
	#if defined(_STM32446USART_H_)
		usart1_enable();
		stm32446.usart1_reg = USART1;
		stm32446.usart1 = usart1();
		usart2_enable();
		stm32446.usart2_reg = USART2;
		stm32446.usart2 = usart2();
		usart3_enable();
		stm32446.usart3_reg = USART3;
		stm32446.usart3 = usart3();
		uart4_enable();
		stm32446.uart4_reg = UART4;
		stm32446.uart4 = uart4();
		uart5_enable();
		stm32446.uart5_reg = UART5;
		stm32446.uart5 = uart5();
		usart6_enable();
		stm32446.usart6_reg = USART6;
		stm32446.usart6 = usart6();
	#endif

	/*** System ***/
	query_enable();
	rcc_start();
	systick_start();

	return stm32446;
}

STM32446* stm(void){return (STM32446*) &stm32446;}

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

