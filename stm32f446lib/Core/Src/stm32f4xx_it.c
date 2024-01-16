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
#include "stm32query.h"
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
volatile uint32_t DelayCounter;
static uint32_t DelayCounter_top;
uint32_t systick_sysclk_calc_xs;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN PFP */
uint32_t systick_sysclk_us(void);
uint32_t systick_sysclk_5us(void);
uint32_t systick_sysclk_10us(void);
uint32_t systick_sysclk_ms(void);
uint32_t systick_sysclk_xs(void);
/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
// 1/(getsysclock/gethpre), seconds per tick
/* USER CODE BEGIN 0 */
uint32_t systick_sysclk_us(void)
{
	return systick_sysclk_calc_xs = DelayCounter_top / 1000000 - 1;
}
uint32_t systick_sysclk_5us(void)
{
	return systick_sysclk_calc_xs = DelayCounter_top / 200000 - 1;
}
uint32_t systick_sysclk_10us(void)
{
	return systick_sysclk_calc_xs = DelayCounter_top / 100000 - 1;
}
uint32_t systick_sysclk_ms(void)
{
	return systick_sysclk_calc_xs = DelayCounter_top / 1000 - 1;
}
uint32_t systick_sysclk_xs(void)
{
	return systick_sysclk_calc_xs = DelayCounter_top / 100000 - 1;
}
/******/
void _delay_us(uint32_t us)
{
	uint32_t trigger = systick_sysclk_us();
	SysTick->LOAD = trigger;
	trigger *= us;
	for( DelayCounter = 0, SysTick->CTRL |= (1 << 0); DelayCounter < trigger; );
	SysTick->CTRL &= (uint32_t) ~(1 << 0);
}
void _delay_5us(uint32_t cinco_us)
{
	uint32_t trigger = systick_sysclk_5us();
	SysTick->LOAD = trigger;
	trigger *= cinco_us;
	for( DelayCounter = 0, SysTick->CTRL |= (1 << 0); DelayCounter < trigger; );
	SysTick->CTRL &= (uint32_t) ~(1 << 0);
}
void _delay_10us(uint32_t dez_us)
{
	uint32_t trigger = systick_sysclk_10us();
	SysTick->LOAD = trigger;
	trigger *= dez_us;
	for( DelayCounter = 0, SysTick->CTRL |= (1 << 0); DelayCounter < trigger; );
	SysTick->CTRL &= (uint32_t) ~(1 << 0);
}
void _delay_ms(uint32_t ms)
{
	uint32_t trigger = systick_sysclk_ms();
	SysTick->LOAD = trigger;
	trigger *= ms;
	for( DelayCounter = 0, SysTick->CTRL |= (1 << 0); DelayCounter < trigger; );
	SysTick->CTRL &= (uint32_t) ~(1 << 0);
}
void _delay_xs(uint32_t xs)
{
	uint32_t trigger = systick_sysclk_xs();
	SysTick->LOAD = trigger;
	trigger *= xs;
	for( DelayCounter = 0, SysTick->CTRL |= (1 << 0); DelayCounter < trigger; );
	SysTick->CTRL &= (uint32_t) ~(1 << 0);
}
void systick_start(void)
{
	DelayCounter_top = getsysclk()/gethpre();
	SysTick->LOAD = 0xffffffff;
	SysTick->VAL = 0UL;
	SysTick->CTRL |= ((1 << 1) | (1 << 2));
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
	DelayCounter += systick_sysclk_calc_xs;
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
