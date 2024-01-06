/******************************************************************************
	STM32 446 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 22062023
Comment:
	-manual um1724, m0390, pm0056, pm0214, and other sources.
	-Virtual Image STM32-446, mapping.
	-Still in progress 15062023, increment has go along.
	-Dependent on CMSIS
	-Stable.
*******************************************************************************/
#ifndef _STM32446MAPPING_H_
	#define _STM32446MAPPING_H_
/*** Global Libraries ***/
#include <inttypes.h>
// SELECTION OF CHIP (CMSIS Access to its libraries)
#ifndef STM32F446xx
	#define STM32F446xx
#endif
#include "stm32f4xx.h"
/*** Define & Macros***/
#define HSI_RC 16000000UL
#define HSE_OSC 25000000UL
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
#ifndef IO_var
	#define IO_var uint32_t
#endif
#ifndef DATA_BITS
	#define DATA_BITS 31
#endif
#ifndef DATA_SIZE
	#define DATA_SIZE 32
#endif
/*** Module Library ***/
// Comment out modules not being used
//#include "stm32446flash.h"
//#include "stm32446crc.h"
//#include "stm32446pwr.h"
#include "stm32446rcc.h"
#include "stm32446nvic.h"
//#include "stm32446sram.h"
#include "stm32446gpio.h"
//#include "stm32446syscfg.h"
#include "stm32446dma.h"
#include "stm32446adc.h"
#include "stm32446rtc.h"
#include "stm32446usart.h"
//#include "stm32446tim1and8.h"
//#include "stm32446tim2to5.h"
//#include "stm32446tim6and7.h"
#include "stm32446tim9to14.h"
#include "function.h"
/************ STM32F446RE ************/
/********** Global TypeDef ***********/
typedef struct
{
	uint8_t L;
	uint8_t H;
} STM32HighLowByte;
/************** QUERY TypeDef ****************/
typedef struct
{
	uint16_t (*AHB)(void);
	uint8_t (*APB1)(void);
	uint8_t (*APB2)(void);
	uint8_t (*RTCclk)(void);
	uint8_t (*MCO1)(void);
	uint8_t (*MCO2)(void);
}STM32446CLOCK_prescaler;
typedef struct
{
	uint8_t (*M)(void);
	uint16_t (*N)(void);
	uint8_t (*P)(void);
	uint8_t (*Q)(void);
	uint8_t (*R)(void);
}STM32446PLL_parameter;
typedef struct
{
	STM32446CLOCK_prescaler CLOCK_prescaler;
	STM32446PLL_parameter PLL_parameter;
	uint32_t (*ClockSource)(void);
	uint32_t (*PllSource)(void);
	uint32_t (*SystemClock)(void);
}STM32446Query;
/******************* CORE TypeDef ********************/
// SCB
typedef struct
{
	SCB_Type* reg;
}STM32446SCBobj;
// SysTick
typedef struct
{
	SysTick_Type* reg;
	void (*delay_ms)(uint32_t ms); // It uses Systick
	void (*delay_10us)(uint32_t ten_us); // It uses Systick
	void (*delay_us)(uint32_t us);
}STM32446SysTickobj;
/******************** MCU TypeDef ********************/
/*** RTC TypeDef ***/
typedef struct
{
	RTC_TypeDef* reg;
	#if defined(_STM32446RTC_H_)
		void (*clock)(uint8_t bool);
		void (*nvic)(uint8_t value);
		void (*inic)(uint8_t clock);
		// Enable
		STM32446_RTC* (*run)(void);
		STM32446_RTC (*enable)(void);
	#endif
}STM32446RTCobj;
// CAN_TxMailBox
typedef struct
{
	CAN_TxMailBox_TypeDef* reg;
}STM32446CAN_TxMailBoxobj;
// CAN_FIFOMailBox
typedef struct
{
	CAN_FIFOMailBox_TypeDef* reg;
}STM32446CAN_FIFOMailBoxobj;
// CAN_FilterRegister
typedef struct
{
	CAN_FilterRegister_TypeDef* reg;
}STM32446CAN_FilterRegisterobj;
// CAN -> CAN1
typedef struct
{
	CAN_TypeDef* reg;
}STM32446CAN1obj;
// CAN -> CAN2
typedef struct
{
	CAN_TypeDef* reg;
}STM32446CAN2obj;
// CEC
typedef struct
{
	CEC_TypeDef* reg;
}STM32446CECobj;
// DAC
typedef struct
{
	DAC_TypeDef* reg;
}STM32446DACobj;
// DBGMCU
typedef struct
{
	DBGMCU_TypeDef* reg;
}STM32446DBGMCUobj;
// DCMI
typedef struct
{
	DCMI_TypeDef* reg;
}STM32446DCMIobj;
// EXTI
typedef struct
{
	EXTI_TypeDef* reg;
}STM32446EXTIobj;
// FMC_Bank1
typedef struct
{
	FMC_Bank1_TypeDef* reg;
}STM32446FMC_Bank1obj;
// FMC_Bank1E
typedef struct
{
	FMC_Bank1E_TypeDef* reg;
}STM32446FMC_Bank1Eobj;
// FMC_Bank3
typedef struct
{
	FMC_Bank3_TypeDef* reg;
}STM32446FMC_Bank3obj;
// FMC_Bank5_6
typedef struct
{
	FMC_Bank5_6_TypeDef* reg;
}STM32446FMC_Bank5_6obj;
// I2C -> I2C1
typedef struct
{
	I2C_TypeDef* reg;
}STM32446I2C1obj;
// I2C -> I2C2
typedef struct
{
	I2C_TypeDef* reg;
}STM32446I2C2obj;
// I2C -> I2C3
typedef struct
{
	I2C_TypeDef* reg;
}STM32446I2C3obj;
// FMPI2C
typedef struct
{
	FMPI2C_TypeDef* reg;
}STM32446FMPI2Cobj;
// IWDG
typedef struct
{
	IWDG_TypeDef* reg;
}STM32446IWDGobj;
// SAI -> SAI1
typedef struct
{
	SAI_TypeDef* reg;
}STM32446SAI1obj;
// SAI1_Block -> SAI1_BlockA
typedef struct
{
	SAI_Block_TypeDef* reg;
}STM32446SAI1_BlockAobj;
// SAI1_Block -> SAI1_BlockB
typedef struct
{
	SAI_Block_TypeDef* reg;
}STM32446SAI1_BlockBobj;
// SAI -> SAI2
typedef struct
{
	SAI_TypeDef* reg;
}STM32446SAI2obj;
// SAI2_Block -> SAI2_BlockA
typedef struct
{
	SAI_Block_TypeDef* reg;
}STM32446SAI2_BlockAobj;
// SAI2_Block -> SAI2_BlockB
typedef struct
{
	SAI_Block_TypeDef* reg;
}STM32446SAI2_BlockBobj;
// SDIO
typedef struct
{
	SDIO_TypeDef* reg;
}STM32446SDIOobj;
// SPI -> SPI1
typedef struct
{
	SPI_TypeDef* reg;
}STM32446SPI1obj;
// SPI -> SPI2
typedef struct
{
	SPI_TypeDef* reg;
}STM32446SPI2obj;
// SPI -> SPI3
typedef struct
{
	SPI_TypeDef* reg;
}STM32446SPI3obj;
// SPI -> SPI4
typedef struct
{
	SPI_TypeDef* reg;
}STM32446SPI4obj;
// QUADSPI
typedef struct
{
	QUADSPI_TypeDef* reg;
}STM32446QUADSPIobj;
// SPDIFRX
typedef struct
{
	SPDIFRX_TypeDef* reg;
}STM32446SPDIFRXobj;
// WWDG
typedef struct
{
	WWDG_TypeDef* reg;
}STM32446WWDGobj;
// USB_OTG_Global
typedef struct
{
	USB_OTG_GlobalTypeDef* reg;
}STM32446USB_OTG_Globalobj;
// USB_OTG_Device
typedef struct
{
	USB_OTG_DeviceTypeDef* reg;
}STM32446USB_OTG_Deviceobj;
// USB_OTG_INEndpoint
typedef struct
{
	USB_OTG_INEndpointTypeDef* reg;
}STM32446USB_OTG_INEndpointobj;
// USB_OTG_OUTEndpoint
typedef struct
{
	USB_OTG_OUTEndpointTypeDef* reg;
}STM32446USB_OTG_OUTEndpointobj;
// USB_OTG_Host
typedef struct
{
	USB_OTG_HostTypeDef* reg;
}STM32446USB_OTG_Hostobj;
// USB_OTG_HostChannel
typedef struct
{
	USB_OTG_HostChannelTypeDef* reg;
}STM32446USB_OTG_HostChannelobj;
/***************** STM32F446 TypeDef *****************/
typedef struct
{
	// PARAMETER
	STM32HighLowByte HLbyte;

	STM32446Query query;
	// CORE
	STM32446SCBobj scb;

	#if defined(_STM32446NVIC_H_)
		STM32446NVICobj nvic;
	#endif

	STM32446SysTickobj systick;
	// MCU
	#if defined(_STM32446ADC_H_)
		STM32446ADC1obj adc1;
		STM32446ADC2obj adc2;
		STM32446ADC3obj adc3;
	#endif

	#if defined(_STM32446CRC_H_)
		STM32446CRCobj crc;
	#endif


	#if defined(_STM32446DMA_H_)
		STM32446DMA1obj dma1;
		STM32446DMA2obj dma2;
	#endif

	#if defined(_STM32446FLASH_H_)
		STM32446FLASHobj flash;
	#endif

	#if defined(_STM32446GPIO_H_)
		STM32446GpioAobj gpioa;
		STM32446GpioBobj gpiob;
		STM32446GpioCobj gpioc;
		STM32446GpioDobj gpiod;
		STM32446GpioEobj gpioe;
		STM32446GpioHobj gpioh;
	#endif

	#if defined(_STM32446SYSCFG_H_)
		STM32446SYSCFGobj syscfg;
	#endif

	#if defined(_STM32446PWR_H_)
		STM32446PWRobj pwr;
	#endif

	#if defined(_STM32446RCC_H_)
		STM32446RCCobj rcc;
	#endif

	#if defined(_STM32446RTC_H_)
		STM32446RTCobj rtc;
	#endif

	#if defined(_STM32446SRAM_H_)
		STM32446SRAMobj sram;
	#endif

	#if defined(_STM32446TIM1AND8_H_)
		STM32446TIM1obj tim1;
		STM32446TIM8obj tim8;
	#endif
	#if defined(_STM32446TIM2TO5_H_)
		STM32446TIM2obj tim2;
		STM32446TIM3obj tim3;
		STM32446TIM4obj tim4;
		STM32446TIM5obj tim5;
	#endif
	#if defined(_STM32446TIM6AND7_H_)
		STM32446TIM6obj tim6;
		STM32446TIM7obj tim7;
	#endif
	#if defined(_STM32446TIM9TO14_H_)
		STM32446TIM9obj tim9;
		STM32446TIM10obj tim10;
		STM32446TIM11obj tim11;
		STM32446TIM12obj tim12;
		STM32446TIM13obj tim13;
		STM32446TIM14obj tim14;
	#endif

	#if defined(_STM32446USART_H_)
		STM32446USART1obj usart1;
		STM32446USART2obj usart2;
		STM32446USART3obj usart3;
		STM32446USART4obj uart4;
		STM32446USART5obj uart5;
		STM32446USART6obj usart6;
	#endif
	//PRIVATE
	#if defined(_FUNCTION_H_)
		FUNC func;
	#endif

}STM32446;

/*** Global ***/
STM32446* stm(void);
STM32446 STM32446enable(void);

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

