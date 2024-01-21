/******************************************************************************
	STM32 XXX MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 22062023
Comment:
	-manual um1724, m0390, pm0056, pm0214, and other sources.
	-Virtual Image STM32-446, mapping.
	-Still in progress 15062023, increment has go along.
	-Dependent on CMSIS
	-Stable.
*******************************************************************************/
#ifndef _STM32FXXXMAPPING_H_
	#define _STM32FXXXMAPPING_H_
/***** Global Libraries *****/
#include "armquery.h"
#include "armsystick.h"
/****** Define & Macros******/
#ifndef on
	#define on 1
#endif
#ifndef off
	#define off 0
#endif
#ifndef yes
	#define yes 1
#endif
#ifndef no
	#define no 0
#endif
/*** Module Library ***/
// May comment out modules not being used
#include "stm32fxxxflash.h"
#include "stm32fxxxcrc.h"
#include "stm32fxxxpwr.h"
#include "stm32fxxxrcc.h"
#include "stm32fxxxnvic.h"
#include "stm32fxxxsram.h"
#include "stm32fxxxgpio.h"
#include "stm32fxxxsyscfg.h"
#include "stm32fxxxdma.h"
#include "stm32fxxxadc1.h"
#include "stm32fxxxadc2.h"
#include "stm32fxxxadc3.h"
#include "stm32fxxxrtc.h"
#include "stm32fxxxusart.h"
#include "stm32fxxxtim1and8.h"
#include "stm32fxxxtim2to5.h"
#include "stm32fxxxtim6and7.h"
#include "stm32fxxxtim9to14.h"
/***************** STM32F446 TypeDef *****************/
typedef struct
{
	// SCB
		SCB_Type* scb_reg;
	// SysTick
		SysTick_Type* systick_reg;
	// NVIC
	#if defined(_STM32FXXXNVIC_H_)
		NVIC_Type* nvic_reg;
		STM32FXXXNVICobj* nvic;
	#endif
	// ADC
	#if defined(_STM32FXXXADC1_H_)
		ADC_TypeDef* adc1_reg;
		ADC_Common_TypeDef* adc1_common_reg;
		STM32FXXXADC1obj* adc1;
	#endif
	#if defined(_STM32FXXXADC2_H_)
		ADC_TypeDef* adc2_reg;
		ADC_Common_TypeDef* adc2_common_reg;
		STM32FXXXADC2obj* adc2;
	#endif
	#if defined(_STM32FXXXADC3_H_)
		ADC_TypeDef* adc3_reg;
		ADC_Common_TypeDef* adc3_common_reg;
		STM32FXXXADC3obj* adc3;
	#endif
	// CRC
	#if defined(_STM32FXXXCRC_H_)
		CRC_TypeDef* crc_reg;
		STM32FXXXCRCobj* crc;
	#endif
	// DMA
	#if defined(_STM32FXXXDMA_H_)
		DMA_TypeDef* dma1_reg;
		DMA_Stream_TypeDef* dma1_stream0_reg;
		DMA_Stream_TypeDef* dma1_stream1_reg;
		DMA_Stream_TypeDef* dma1_stream2_reg;
		DMA_Stream_TypeDef* dma1_stream3_reg;
		DMA_Stream_TypeDef* dma1_stream4_reg;
		DMA_Stream_TypeDef* dma1_stream5_reg;
		DMA_Stream_TypeDef* dma1_stream6_reg;
		DMA_Stream_TypeDef* dma1_stream7_reg;
		STM32FXXXDMA1obj* dma1;
		DMA_TypeDef* dma2_reg;
		DMA_Stream_TypeDef* dma2_stream0_reg;
		DMA_Stream_TypeDef* dma2_stream1_reg;
		DMA_Stream_TypeDef* dma2_stream2_reg;
		DMA_Stream_TypeDef* dma2_stream3_reg;
		DMA_Stream_TypeDef* dma2_stream4_reg;
		DMA_Stream_TypeDef* dma2_stream5_reg;
		DMA_Stream_TypeDef* dma2_stream6_reg;
		DMA_Stream_TypeDef* dma2_stream7_reg;
		DMA_Stream_TypeDef* dma2_stream8_reg;
		STM32FXXXDMA2obj* dma2;
	#endif
	// FLASH
	#if defined(_STM32FXXXFLASH_H_)
		FLASH_TypeDef* flash_reg;
		STM32FXXXFLASHobj* flash;
	#endif
	// GPIO
	#if defined(_STM32FXXXGPIO_H_)
		GPIO_TypeDef* gpioa_reg;
		STM32FXXXGpioAobj* gpioa;
		GPIO_TypeDef* gpiob_reg;
		STM32FXXXGpioBobj* gpiob;
		GPIO_TypeDef* gpioc_reg;
		STM32FXXXGpioCobj* gpioc;
		GPIO_TypeDef* gpiod_reg;
		STM32FXXXGpioDobj* gpiod;
		GPIO_TypeDef* gpioe_reg;
		STM32FXXXGpioEobj* gpioe;
		GPIO_TypeDef* gpioh_reg;
		STM32FXXXGpioHobj* gpioh;
	#endif
	// SYSCFG
	#if defined(_STM32FXXXSYSCFG_H_)
		SYSCFG_TypeDef* syscfg_reg;
		STM32FXXXSYSCFGobj* syscfg;
	#endif
	// PWR
	#if defined(_STM32FXXXPWR_H_)
		PWR_TypeDef* pwr_reg;
		STM32FXXXPWRobj* pwr;
	#endif
	// RCC
	#if defined(_STM32FXXXRCC_H_)
		RCC_TypeDef* rcc_reg;
		STM32FXXXRCCobj* rcc;
	#endif
	// RTC
	#if defined(_STM32FXXXRTC_H_)
		RTC_TypeDef* rtc_reg;
		STM32FXXX_RTC* rtc;
	#endif
	// SRAM
	#if defined(_STM32FXXXSRAM_H_)
		STM32FXXXSRAMobj* sram;
	#endif
	// TIM
	#if defined(_STM32FXXXTIM1AND8_H_)
		TIM_TypeDef* tim1_reg;
		STM32FXXXTIM1obj* tim1;
		TIM_TypeDef* tim8_reg;
		STM32FXXXTIM8obj* tim8;
	#endif
	#if defined(_STM32FXXXTIM2TO5_H_)
		TIM_TypeDef* tim2_reg;
		STM32FXXXTIM2obj* tim2;
		TIM_TypeDef* tim3_reg;
		STM32FXXXTIM3obj* tim3;
		TIM_TypeDef* tim4_reg;
		STM32FXXXTIM4obj* tim4;
		TIM_TypeDef* tim5_reg;
		STM32FXXXTIM5obj* tim5;
	#endif
	#if defined(_STM32FXXXTIM6AND7_H_)
		TIM_TypeDef* tim6_reg;
		STM32FXXXTIM6obj* tim6;
		TIM_TypeDef* tim7_reg;
		STM32FXXXTIM7obj* tim7;
	#endif
	#if defined(_STM32FXXXTIM9TO14_H_)
		TIM_TypeDef* tim9_reg;
		STM32FXXXTIM9obj* tim9;
		TIM_TypeDef* tim10_reg;
		STM32FXXXTIM10obj* tim10;
		TIM_TypeDef* tim11_reg;
		STM32FXXXTIM11obj* tim11;
		TIM_TypeDef* tim12_reg;
		STM32FXXXTIM12obj* tim12;
		TIM_TypeDef* tim13_reg;
		STM32FXXXTIM13obj* tim13;
		TIM_TypeDef* tim14_reg;
		STM32FXXXTIM14obj* tim14;
	#endif
	// USART
	#if defined(_STM32FXXXUSART_H_)
		USART_TypeDef* usart1_reg;
		STM32FXXX_USART1* usart1;
		USART_TypeDef* usart2_reg;
		STM32FXXX_USART2* usart2;
		USART_TypeDef* usart3_reg;
		STM32FXXX_USART3* usart3;
		USART_TypeDef* uart4_reg;
		STM32FXXX_UART4* uart4;
		USART_TypeDef* uart5_reg;
		STM32FXXX_UART5* uart5;
		USART_TypeDef* usart6_reg;
		STM32FXXX_USART6* usart6;
	#endif

}STM32FXXX;

/*** Global ***/
STM32FXXX STM32FXXX_enable(void);
STM32FXXX* stm(void);

/*** INTERRUPT HEADER ***/
void Reset_IRQHandler(void);
void NMI_IRQHandler(void);
void HardFault_IRQHandler(void);
void MemManage_IRQHandler(void);
void BusFault_IRQHandler(void);
void UsageFault_IRQHandler(void);
void SVCall_IRQHandler(void);
void PendSV_IRQHandler(void);
void Systick_IRQHandler(void);
void FPU_IRQHandler(void);
void SysTick_Handler(void);

#endif

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

