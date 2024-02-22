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
  * Hardware: STM32F4x1 mini_F4x1 Ver. V20 SN: 202005 DevEBox
  * Board Site: mcudev.taobao.com
  * Date: 22022024
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
	PC13 - LED blink
note:
timer 1 test.
********************************************************************************/
#include "main.h"
#include "stm32fxxxmapping.h"
#include "armlcd.h"
#include "armfunction.h"

int main(void)
{

  STM32FXXX_enable();

  gpiob()->clock(on);
  gpioc()->clock(on);
  rtc()->inic(0); // 1 - LSE 0 - LSI

  ARMLCD0_enable(stm()->gpiob_reg);
  FUNC_enable();

  gpioc()->moder->bit.m13 = 1;

  stm()->tim1->nvic(1);
  stm()->tim1->clock(on);
  tim1()->arr(0xFFFF);
  // Compare
  tim1()->ccr1(1400);
  // pre-scaler
  tim1()->psc(100);
  // interrupt
  tim1()->dier->cc1ie = 1;
  // Enable (Start/Stop)
  tim1()->cr1->apre = 1;
  tim1()->cr1->cen = 1;

  uint32_t count = 0;

  while (1)
  {
	  lcd0()->gotoxy(0,0);
	  lcd0()->string_size("Welcome",8);

	  _delay_ms(300);
	  //gpioc()->bsrr->bit.s13 = 1;
	  lcd0()->gotoxy(2,0);
	  lcd0()->string_size(func()->ui32toa(count++),10);
	  _delay_ms(300);
	  //gpioc()->bsrr->bit.r13 = 1;
  }
}

void TIM1_CC_IRQHandler(void){
	tim1()->sr->iof.iflag = 0;
	gpioc()->odr->bit.o13 ^= 1;
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

