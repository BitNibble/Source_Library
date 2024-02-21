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
note:
test bit access
********************************************************************************/
#include "main.h"
#include "stm32fxxxmapping.h"
#include "armlcd.h"
#include "armfunction.h"

char time[12];
//rtc()->BckWrite(0,65);

int main(void)
{
	_UN32var num;

	STM32FXXX_enable();

	gpiob()->clock(on);
	rtc()->inic(0); // 0 - LSI, 1 - LSE, 2 - LSECLK

	ARMLCD0_enable(stm()->gpiob_reg);
	FUNC_enable();

	num.n = 4294967295;
	//num.n = 257;
	lcd0()->gotoxy(0,0);
	lcd0()->string_size(func()->print_v2("n: %u",num.n) ,20);
	lcd0()->gotoxy(1,0);
	lcd0()->string_size(func()->print_v2("%u",num.byte.b3) ,4);lcd0()->string_size(func()->print_v2("%u",num.byte.b2) ,4);
	lcd0()->string_size(func()->print_v2("%u",num.byte.b1) ,4);lcd0()->string_size(func()->print_v2("%u",num.byte.b0) ,4);
	lcd0()->gotoxy(2,0);
	lcd0()->string_size(func()->print_v2("%u",num.word.w1) ,6);lcd0()->string_size(func()->print_v2("%u",num.word.w0) ,6);
	lcd0()->string_size(func()->print_v2("%u",sizeof(uint64_t)) ,6);
	//num.nibble.n3=15;
	//num.nibble.n3=9;
	lcd0()->gotoxy(3,0);
	lcd0()->string_size(func()->print_v2("%u",num.nibble.n5) ,3);lcd0()->string_size(func()->print_v2("%u",num.nibble.n4) ,3);
	lcd0()->string_size(func()->print_v2("%u",num.nibble.n3) ,3);lcd0()->string_size(func()->print_v2("%u",num.nibble.n2) ,3);
	lcd0()->string_size(func()->print_v2("%u",num.nibble.n1) ,3);lcd0()->string_size(func()->print_v2("%u",num.nibble.n0) ,3);
	while (1)
	{
		//func()->arm->dispar4x20(lcd0());
	}
}
/*******************************************************************************/
/*******************************************************************************/





/*******************************************************************************/
/*******************************************************************************/
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

