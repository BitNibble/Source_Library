/********************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2024 STMicroelectronics.
  * All rights reserved.
  *
  * Author: Sergio Santos
  * <sergio.salazar.santos@gmail.com>
  * License: GNU General Public License
  * Hardware: STM32
  * Date: 28052023
  * Comment:
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
********************************************************************************/
/****** Comment
LCD
	PB3 - RS
	PB4 - RW
	PB5 - E
	PB6 - D4
	PB7 - D5
	PB8 - D6
	PB9 - D7
LED Blinking
	PB13 - LED blink
note:
test lcd and gpios.
********************************************************************************/
#include "main.h"
#include "stm32fxxxmapping.h"
#include "armlcd.h"
#include "armfunction.h"

char time[12];
//rtc()->BckWrite(0,65);

int main(void)
{
  STM32FXXX_enable();

  gpiob()->clock(on);
  rtc()->inic(0); // 1 - LSE 0 - LSI

  ARMLCD0_enable(stm()->gpiob_reg);
  FUNC_enable();

  gpiob()->moder(13,1);

  uint32_t count = 0;

  while (1)
  {
	  lcd0()->gotoxy(0,0);
	  lcd0()->string_size("Welcome",8);

	  _delay_ms(300);
	  setreg(&GPIOB->ODR,1,13,1);
	  lcd0()->gotoxy(2,0);
	  lcd0()->string_size(func()->ui32toa(count++),10);
	  _delay_ms(300);
	  setreg(&GPIOB->ODR,1,13,0);
  }
}


void Error_Handler(void)
{
  __disable_irq();
  while (1)
  {
  }
}
#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif

