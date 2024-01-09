/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.c
  * @brief   Interrupt Service Routines.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "main.h"
#include "stm32f4xx_it.h"
/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN TD */

/* USER CODE END TD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN PV */
static uint32_t DelayCounter;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
uint32_t it_readreg(uint32_t reg, uint8_t size_block, uint8_t bit_n);
uint32_t it_getsetbit(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n);
void it_setreg(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data);
void it_setbit(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data);
void it_writereg(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data);
STM32446CLOCK_prescaler CLOCK_prescaler_inic(void);
STM32446PLL_parameter PLL_parameter_inic(void);
uint32_t STM32446_getclocksource(void);
uint32_t STM32446_getpllsource(void);
uint16_t STM32446_gethpre(void);
uint8_t STM32446_gethppre1(void);
uint8_t STM32446_gethppre2(void);
uint8_t STM32446_getrtcpre(void);
uint8_t STM32446_gethmco1pre(void);
uint8_t STM32446_gethmco2pre(void);
uint8_t STM32446_getpllm(void);
uint16_t STM32446_getplln(void);
uint8_t STM32446_getpllp(void);
uint8_t STM32446_getpllq(void);
uint8_t STM32446_getpllr(void);
uint32_t STM32446_getsysclk(void);
// SysTick
void STM32446delay_ms(uint32_t ms);
void STM32446delay_10us(uint32_t ten_us);
void STM32446delay_us(uint32_t us);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
/*** Query ***/
STM32446CLOCK_prescaler CLOCK_prescaler_inic(void)
{
	STM32446CLOCK_prescaler stm32446_CLOCK_prescaler;
	stm32446_CLOCK_prescaler.AHB = STM32446_gethpre;
	stm32446_CLOCK_prescaler.APB1 = STM32446_gethppre1;
	stm32446_CLOCK_prescaler.APB2 = STM32446_gethppre2;
	stm32446_CLOCK_prescaler.RTCclk = STM32446_getrtcpre;
	stm32446_CLOCK_prescaler.MCO1 = STM32446_gethmco1pre;
	stm32446_CLOCK_prescaler.MCO2 = STM32446_gethmco2pre;
	return stm32446_CLOCK_prescaler;
}
STM32446PLL_parameter PLL_parameter_inic(void)
{
	STM32446PLL_parameter stm32446_PLL_parameter;
	stm32446_PLL_parameter.M = STM32446_getpllm;
	stm32446_PLL_parameter.N = STM32446_getplln;
	stm32446_PLL_parameter.P = STM32446_getpllp;
	stm32446_PLL_parameter.Q = STM32446_getpllq;
	stm32446_PLL_parameter.R = STM32446_getpllr;
	return stm32446_PLL_parameter;
}
STM32446Query query_inic(void)
{
	STM32446Query stm32446_query;
	stm32446_query.CLOCK_prescaler = CLOCK_prescaler_inic();
	stm32446_query.PLL_parameter = PLL_parameter_inic();
	stm32446_query.ClockSource = STM32446_getclocksource;
	stm32446_query.PllSource = STM32446_getpllsource;
	stm32446_query.SystemClock = STM32446_getsysclk;
	return stm32446_query;
}
uint32_t STM32446_getclocksource(void)
{
	uint32_t reg = RCC->CR;
	uint32_t source;
	if(reg & (1 << 1)){source = HSI_RC;}else if(reg & (1 << 17)){source = HSE_OSC;}
	return source;
}
uint32_t STM32446_getpllsource(void)
{
	uint32_t reg = RCC->CFGR;
	uint32_t source;
	if(reg & (1 << 22)) source = HSE_OSC; else source = HSI_RC;
	return source;
}
uint16_t STM32446_gethpre(void)
{
	uint32_t value = it_readreg(RCC->CFGR, 4, 4);
	switch(value)
	{
		case 0b1000:
			value = 2;
		break;
		case 0b1001:
			value = 4;
		break;
		case 0b1010:
			value = 8;
		break;
		case 0b1011:
			value = 16;
		break;
		case 0b1100:
			value = 64;
		break;
		case 0b1101:
			value = 128;
		break;
		case 0b1110:
			value = 256;
		break;
		case 0b1111:
			value = 512;
		break;
		default:
			value = 1;
		break;
	}
	return value;
}
uint8_t STM32446_gethppre1(void)
{
	uint32_t value = it_readreg(RCC->CFGR, 3, 10);
	switch(value)
	{
		case 0b100:
			value = 2;
		break;
		case 0b101:
			value = 4;
		break;
		case 0b110:
			value = 8;
		break;
		case 0b111:
			value = 16;
		break;
		default:
			value = 1;
		break;
	}
	return value;
}
uint8_t STM32446_gethppre2(void)
{
	uint32_t value = it_readreg(RCC->CFGR, 3, 13);
	switch(value)
	{
		case 0b100:
			value = 2;
		break;
		case 0b101:
			value = 4;
		break;
		case 0b110:
			value = 8;
		break;
		case 0b111:
			value = 16;
		break;
		default:
			value = 1;
		break;
	}
	return value;
}
uint8_t STM32446_getrtcpre(void)
{
	return it_readreg(RCC->CFGR, 5, 16);
}
uint8_t STM32446_gethmco1pre(void)
{
	uint32_t value = it_readreg(RCC->CFGR, 3, 24);
	switch(value)
	{
		case 0b100:
			value = 2;
		break;
		case 0b101:
			value = 3;
		break;
		case 0b110:
			value = 4;
		break;
		case 0b111:
			value = 5;
		break;
		default:
			value = 1;
		break;
	}
	return value;
}
uint8_t STM32446_gethmco2pre(void)
{
	uint32_t value = it_readreg(RCC->CFGR, 3, 27);
	switch(value)
	{
		case 0b100:
			value = 2;
		break;
		case 0b101:
			value = 3;
		break;
		case 0b110:
			value = 4;
		break;
		case 0b111:
			value = 5;
		break;
		default:
			value = 1;
		break;
		}
	return value;
}
uint8_t STM32446_getpllm(void)
{
	return it_readreg(RCC->PLLCFGR, 6, 0);
}
uint16_t STM32446_getplln(void)
{
	return it_readreg(RCC->PLLCFGR, 9, 6);
}
uint8_t STM32446_getpllp(void)
{
	uint32_t value = it_readreg(RCC->PLLCFGR, 2, 16);
	switch(value)
	{
		case 0b00:
			value = 2;
		break;
		case 0b01:
			value = 4;
		break;
		case 0b10:
			value = 6;
		break;
		case 0b11:
			value = 8;
		break;
		default:
		break;
	}
	return value;
}
uint8_t STM32446_getpllq(void)
{
	return it_readreg(RCC->PLLCFGR, 4, 24);
}
uint8_t STM32446_getpllr(void)
{
	return it_readreg(RCC->PLLCFGR, 3, 28);
}
uint32_t STM32446_getsysclk(void)
{
	uint32_t value = it_readreg(RCC->CFGR, 2, 2);
	switch(value) // SWS[2]: System clock switch status
	{
		case 1: // 01: HSE oscillator used as the system clock
			value = HSE_OSC;
		break;
		case 2: // 10: PLL used as the system clock
			value = ( STM32446_getclocksource() / STM32446_getpllm() ) * ( STM32446_getplln() / STM32446_getpllp() );
		break;
		case 3: // 11: PLL_R used as the system clock
			value = ( STM32446_getclocksource() / STM32446_getpllm() ) * ( STM32446_getplln() / STM32446_getpllr() );
		break;
		default: // 00: HSI oscillator used as the system clock
			value = HSI_RC;
		break;
	}
	return value;
}
STM32446SysTickobj systick_inic(void)
{
	STM32446SysTickobj stm32446_systick;
	stm32446_systick.reg = (SysTick_Type*) SysTick_BASE;
	stm32446_systick.delay_ms = STM32446delay_ms;
	stm32446_systick.delay_10us = STM32446delay_10us;
	stm32446_systick.delay_us = STM32446delay_us;
	return stm32446_systick;
}
void SystickInic(void)
{
	SysTick->LOAD = (uint32_t)( STM32446_getsysclk() - 1);
	SysTick->VAL = 0UL;
	SysTick->CTRL |= ((1 << 1) | (1 << 2));
}
void STM32446delay_ms(uint32_t ms)
{
	SysTick->LOAD = (uint32_t)(( STM32446_getsysclk() / 1000 ) - 1);
	// Enable the SysTick timer
	SysTick->CTRL |= (1 << 0);
	// Wait for a specified number of milliseconds
	DelayCounter = 0;
	while (DelayCounter < ms);
	// Disable the SysTick timer
	SysTick->CTRL &= (uint32_t) ~(1 << 0);
}
void STM32446delay_10us(uint32_t ten_us)
{
	SysTick->LOAD = (uint32_t)(( STM32446_getsysclk() / 100000) - 1);
	// Enable the SysTick timer
	SysTick->CTRL |= (1 << 0);
	// Wait for a specified number of milliseconds
	DelayCounter = 0;
	while (DelayCounter < ten_us);
	// Disable the SysTick timer
	SysTick->CTRL &= (uint32_t) ~(1 << 0);
}
void STM32446delay_us(uint32_t us)
{
	SysTick->LOAD = (uint32_t)(( STM32446_getsysclk() / 1000000) - 1);
	// Enable the SysTick timer
	SysTick->CTRL |= (1 << 0);
	// Wait for a specified number of milliseconds
	DelayCounter = 0;
	while (DelayCounter < us);
	// Disable the SysTick timer
	SysTick->CTRL &= (uint32_t) ~(1 << 0);
}
uint32_t it_readreg(uint32_t reg, uint8_t size_block, uint8_t bit_n)
{
	if(bit_n > 31){ bit_n = 0;} if(size_block > 32){ size_block = 32;}
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	reg &= (mask << bit_n);
	reg = (reg >> bit_n);
	return reg;
}
uint32_t it_getsetbit(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n)
{
	uint32_t n = 0;
	if(bit_n > 31){ n = bit_n/32; bit_n = bit_n - (n * 32); } if(size_block > 32){ size_block = 32;}
	uint32_t value = *(reg + n );
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	value &= (mask << bit_n);
	value = (value >> bit_n);
	return value;
}
void it_setreg(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data)
{
	if(bit_n > 31){ bit_n = 0;} if(size_block > 32){ size_block = 32;}
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask;
	*reg &= ~(mask << bit_n);
	*reg |= (data << bit_n);
}
void it_setbit(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data)
{
	uint32_t n = 0;
	if(bit_n > 31){ n = bit_n/32; bit_n = bit_n - (n * 32); } if(size_block > 32){ size_block = 32;}
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask;
	*(reg + n ) &= ~(mask << bit_n);
	*(reg + n ) |= (data << bit_n);
}
void it_writereg(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data)
{
	if(bit_n > 31){ bit_n = 0;} if(size_block > 32){ size_block = 32;}
	uint32_t value = *reg;
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask; value &= ~(mask << bit_n);
	data = (data << bit_n);
	value |= data;
	*reg = value;
}
/* USER CODE END 0 */

/* External variables --------------------------------------------------------*/

/* USER CODE BEGIN EV */

/* USER CODE END EV */

/******************************************************************************/
/*           Cortex-M4 Processor Interruption and Exception Handlers          */
/******************************************************************************/
/**
  * @brief This function handles Non maskable interrupt.
  */
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */
   while (1)
  {
  }
  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
  * @brief This function handles Hard fault interrupt.
  */
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Memory management fault.
  */
void MemManage_Handler(void)
{
  /* USER CODE BEGIN MemoryManagement_IRQn 0 */

  /* USER CODE END MemoryManagement_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_MemoryManagement_IRQn 0 */
    /* USER CODE END W1_MemoryManagement_IRQn 0 */
  }
}

/**
  * @brief This function handles Pre-fetch fault, memory access fault.
  */
void BusFault_Handler(void)
{
  /* USER CODE BEGIN BusFault_IRQn 0 */

  /* USER CODE END BusFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_BusFault_IRQn 0 */
    /* USER CODE END W1_BusFault_IRQn 0 */
  }
}

/**
  * @brief This function handles Undefined instruction or illegal state.
  */
void UsageFault_Handler(void)
{
  /* USER CODE BEGIN UsageFault_IRQn 0 */

  /* USER CODE END UsageFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_UsageFault_IRQn 0 */
    /* USER CODE END W1_UsageFault_IRQn 0 */
  }
}

/**
  * @brief This function handles System service call via SWI instruction.
  */
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVCall_IRQn 0 */

  /* USER CODE END SVCall_IRQn 0 */
  /* USER CODE BEGIN SVCall_IRQn 1 */

  /* USER CODE END SVCall_IRQn 1 */
}

/**
  * @brief This function handles Debug monitor.
  */
void DebugMon_Handler(void)
{
  /* USER CODE BEGIN DebugMonitor_IRQn 0 */

  /* USER CODE END DebugMonitor_IRQn 0 */
  /* USER CODE BEGIN DebugMonitor_IRQn 1 */

  /* USER CODE END DebugMonitor_IRQn 1 */
}

/**
  * @brief This function handles Pendable request for system service.
  */
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
  * @brief This function handles System tick timer.
  */
void SysTick_Handler(void)
{
  /* USER CODE BEGIN SysTick_IRQn 0 */
	DelayCounter++;
  /* USER CODE END SysTick_IRQn 0 */

  /* USER CODE BEGIN SysTick_IRQn 1 */

  /* USER CODE END SysTick_IRQn 1 */
}

/******************************************************************************/
/* STM32F4xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f4xx.s).                    */
/******************************************************************************/

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
