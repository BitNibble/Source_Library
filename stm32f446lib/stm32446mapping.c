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
#include <stdarg.h>
#include <math.h>
/*** File Constant & Macros ***/
// CPACR is located at address 0xE000ED88
#define STM32446_SCB_BASE ((0xE000E000UL) + 0x0D00UL))
/*** File Variable ***/
static STM32446 stm32446;

/*** File Header ***/

/******* STM32F446RE Procedure & Function Definition *******/
STM32446 STM32446enable(void){
	/************* CORE ************/
	// SCB
	stm32446.scb.reg = ((SCB_Type*) STM32446_SCB_BASE;
	// NVIC
	#if defined(_STM32446NVIC_H_)
		stm32446.nvic = nvic_inic();
	#endif
	/************ MCU ************/
	// ADC -> ADC1
	#if defined(_STM32446ADC_H_)
		stm32446.adc1 = adc1_inic();
		stm32446.adc2 = adc2_inic();
		stm32446.adc3 = adc3_inic();
	#endif
	// CRC
	#if defined(_STM32446CRC_H_)
		stm32446.crc = crc_inic();
	#endif
	#if defined(_STM32446DMA_H_)
	// DMA1
		stm32446.dma1 = dma1_inic();
	// DMA2
		stm32446.dma2 = dma2_inic();
	#endif
	// FLASH
	#if defined(_STM32446FLASH_H_)
		stm32446.flash = flash_inic();
	#endif
	// GPIO
	#if defined(_STM32446GPIO_H_)
		stm32446.gpioa = gpioa_inic();
		stm32446.gpiob = gpiob_inic();
		stm32446.gpioc = gpioc_inic();
		stm32446.gpiod = gpiod_inic();
		stm32446.gpioe = gpioe_inic();
		stm32446.gpioh = gpioh_inic();
	#endif
	// SYSCFG
	#if defined(_STM32446SYSCFG_H_)
		stm32446.syscfg.reg = SYSCFG;
	#endif
	// PWR
	#if defined(_STM32446PWR_H_)
		stm32446.pwr = pwr_inic();
	#endif
	// RCC
	#if defined(_STM32446RCC_H_)
		stm32446.rcc = rcc_inic();
	#endif
	// RTC
	#if defined(_STM32446RTC_H_)
		RTCenable();
		stm32446.rtc = rtc();
	#endif
	// SRAM
	#if defined(_STM32446SRAM_H_)
		stm32446.sram = sram_inic();
	#endif
	// TIM
	#if defined(_STM32446TIM1AND8_H_)
		stm32446.tim1 = tim1_inic();
		stm32446.tim8 = tim8_inic();
	#endif
	#if defined(_STM32446TIM2TO5_H_)
		stm32446.tim2 = tim2_inic();
		stm32446.tim3 = tim3_inic();
		stm32446.tim4 = tim4_inic();
		stm32446.tim5 = tim5_inic();
	#endif
	#if defined(_STM32446TIM6AND7_H_)
		stm32446.tim6 = tim6_inic();
		stm32446.tim7 = tim7_inic();
	#endif
	#if defined(_STM32446TIM9TO14_H_)
		stm32446.tim9 = tim9_inic();
		stm32446.tim10 = tim10_inic();
		stm32446.tim11 = tim11_inic();
		stm32446.tim12 = tim12_inic();
		stm32446.tim13 = tim13_inic();
		stm32446.tim14 = tim14_inic();
	#endif
	// USART
	#if defined(_STM32446USART_H_)
		USART1enable();
		stm32446.usart1 = (STM32446_USART1*) usart1();
		USART2enable();
		stm32446.usart2 = (STM32446_USART2*) usart2();
		USART3enable();
		stm32446.usart3 = (STM32446_USART3*) usart3();
		UART4enable();
		stm32446.uart4 = (STM32446_UART4*) uart4();
		UART5enable();
		stm32446.uart5 = (STM32446_UART5*) uart5();
		USART6enable();
		stm32446.usart6 = (STM32446_USART6*) usart6();
	#endif

	query_inic();
	systick_start();

	return stm32446;
}

STM32446* stm(void){return (STM32446*) &stm32446;}

/*** File Procedure & Function Definition ***/
/***/
void STM32446RegSetBits( unsigned int* reg, int n_bits, ... )
{
	uint8_t i;
	if(n_bits > 0 && n_bits < 33){ // Filter input
		va_list list;
		va_start(list, n_bits);
		for(i = 0; i < n_bits; i++){
			*reg |= (unsigned int)(1 << va_arg(list, int));
		}
		va_end(list);
	}
}
void STM32446RegResetBits( unsigned int* reg, int n_bits, ... )
{
	uint8_t i;
	if(n_bits > 0 && n_bits < 33){ // Filter input
		va_list list;
		va_start(list, n_bits);
		for(i = 0; i < n_bits; i++){
			*reg &= (unsigned int)~((1 << va_arg(list, int)) << 16);
		}
		va_end(list);
	}
}
void STM32446VecSetup( volatile uint32_t vec[], const unsigned int size_block, unsigned int data, unsigned int block_n )
{
	const unsigned int n_bits = sizeof(data) * 8;
	const unsigned int mask = (unsigned int) (pow(2, size_block) - 1);
	unsigned int index = (block_n * size_block) / n_bits;
	data &= mask;
	vec[index] &= ~( mask << ((block_n * size_block) - (index * n_bits)) );
	vec[index] |= ( data << ((block_n * size_block) - (index * n_bits)) );
}

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

/*********
1º Make struct
2º Make SUB struct with vars
3º Make Function pointers
4º Make Function that returns SUB struct with initialised vars
5º Make Functions that initialises SUB struct links
6º Make Function that returns the struct with the above functions
*********/

