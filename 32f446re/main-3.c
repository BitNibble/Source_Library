/********************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * Author: Sergio Manuel Santos
  * <sergio.salazar.santos@gmail.com>
  *
  * License: GNU General Public License
  * File: MAIN 13/01/2024
  *
  * Software: STM32CubeIDE Version: 1.14.0 Build: 19471_20231121_1200 (UTC)
  * Hardware: Nucleo-F446RE
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
*******************************************************************************/
/**** Comment
PC 0,1,2 		---> 74HC595
PB 0...7 		---> LCD 4x20
PA 5     		---> Led indicator
PC 13    		---> user button
PA9 and PA10 	---> USART1
*******************************************************************************/
#include "main.h"
/*** Library Switches ***/
#ifndef ARM_MATH_CM4
	#define ARM_MATH_CM4
#endif

#include "stm32446mapping.h"
#include "armfunction.h"
#include "armlcd.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static ARMLCD0 lcd;
/*************************************/
void portinic(void);
/*************************************/
int main(void)
{
STM32446_enable();
FUNC_enable();
portinic();
lcd = ARMLCD0_enable(stm()->gpiob_reg);
/*************************************/
unsigned int zone;
/*************************************/
for ( zone = 1 ; 0xFF ; zone++)
{// COMMON

if(zone < 2){ // Preamble
	lcd.reboot();
	lcd.gotoxy(0,0);
	lcd.string_size("Welcome",7);
}
/******************************************************************************/
if(zone < 3){ // workspace 1
	lcd.gotoxy(1,0);
	lcd.string_size(func()->ui32toa(getsysclk()),7);
	lcd.gotoxy(2,0);
	lcd.string_size(func()->ui32toa(getsysclk()/gethpre()),7);


} // if
/******************************************************************************/
if(zone < 4){ // workspace 2 ADC1 TEMPERATURE

	stm()->gpioa->set(1 << 5);
	//_delay_5us(1);
	stm()->gpioa->reset(1 << 5); // max 1us to 1.5 us half duty cycle, therefore us delay function is un-necessary. This at 21Mhz.
	//_delay_5us(1);
	stm()->gpioa->set(1 << 5);
	//_delay_5us(1);
	stm()->gpioa->reset(1 << 5);
	//_delay_5us(1);
	stm()->gpioa->set(1 << 5);
	//_delay_5us(1);
	stm()->gpioa->reset(1 << 5);
	//_delay_5us(1);
	stm()->gpioa->set(1 << 5);
	//_delay_5us(1);
	stm()->gpioa->reset(1 << 5);
	//_delay_5us(1);
	stm()->gpioa->set(1 << 5);
	//_delay_5us(1);
	stm()->gpioa->reset(1 << 5);
	//_delay_5us(1);
	stm()->gpioa->set(1 << 5);
	//_delay_5us(1);
	stm()->gpioa->reset(1 << 5);
	//_delay_5us(1);
	//zone = 2;
	//continue;
} // if
/******************************************************************************/
if(zone < 5){




zone = 0;
} // if
/******************************************************************************/
/******************************************************************************/
} // for
} // main
/******************************************************************************/
/******************************************************************************/
void portinic(void)
{
	// GPIO
	gpioa()->clock(on);
	gpiob()->clock(on);
  	// PA5 or PB13 is green user led
	gpioa()->moder(5,1); // 0-input 1-output 2-Af 3-Analog
	gpioa()->pupdr(5,0); // 2-pull down 1-pull up 0-non
	gpioa()->ospeedr(5,3); // 3-100Mhz 2-50Mhz 1-25Mhz 0-2Mhz
	// PC13 is user button
	gpioc()->moder(13,0);
	gpioc()->pupdr(13,1);
}
/******************************************************************************/
/******************************************************************************/







/******************************************************************************/
/******************************************************************************/
void Error_Handler(void)
{
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

