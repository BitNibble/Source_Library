/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file    stm32f4xx_it.h
  * @brief   This file contains the headers of the interrupt handlers.
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

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM32F4xx_IT_H
#define __STM32F4xx_IT_H

#ifdef __cplusplus
 extern "C" {
#endif

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#ifndef STM32F446xx
	#define STM32F446xx
#endif
#include "stm32f4xx.h"
/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */
/***/
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
typedef struct
{
SysTick_Type* reg;
void (*delay_ms)(uint32_t ms); // It uses Systick
void (*delay_10us)(uint32_t ten_us); // It uses Systick
void (*delay_us)(uint32_t us);
}STM32446SysTickobj;
 /***/
/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */
#ifndef HSI_RC
	#define HSI_RC 16000000UL
#endif
#ifndef HSE_OSC
	#define HSE_OSC 25000000UL
#endif
/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

/* Exported functions prototypes ---------------------------------------------*/
void NMI_Handler(void);
void HardFault_Handler(void);
void MemManage_Handler(void);
void BusFault_Handler(void);
void UsageFault_Handler(void);
void SVC_Handler(void);
void DebugMon_Handler(void);
void PendSV_Handler(void);
void SysTick_Handler(void);
/* USER CODE BEGIN EFP */
STM32446Query query_inic(void);
void SystickInic(void);
STM32446SysTickobj systick_inic(void);
/* USER CODE END EFP */

#ifdef __cplusplus
}
#endif

#endif /* __STM32F4xx_IT_H */
