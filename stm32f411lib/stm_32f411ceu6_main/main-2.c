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

uint32_t count = 0;
int32_t cpos;

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
  //tim1()->arr->reg.w0 = 0xFFFF;
  // Compare
  //tim1()->ccr1->tim_ccr1_par.w0 = 0x0CFF;
  tim1()->ccr2->tim_ccr2_par.w0 = 0xFFFF;
  // pre-scaler
  tim1()->psc->tim_psc_par.w0 = 100;
  // interrupt
  tim1()->dier->tim1and8_dier_par.cc1ie = 1;
  tim1()->dier->tim1and8_dier_par.cc2ie = 1;
  // Enable (Start/Stop)
  tim1()->cr1->tim1and8_cr1_par.arpe = 1;
  tim1()->cr1->tim1and8_cr1_par.cen = 1;


  while (1)
  {
	  lcd0()->gotoxy(0,0);
	  lcd0()->string_size("Welcome",8);

	  _delay_ms(1000);
	  lcd0()->gotoxy(2,0);
	  lcd0()->string_size(func()->ui32toa(count++),10);

	  lcd0()->gotoxy(3,0);
	  lcd0()->string_size(func()->i32toa(cpos),10);
  }
}

void TIM1_CC_IRQHandler(void){

	if(tim1()->sr->tim1and8_sr_par.cc1if || tim1()->sr->tim1and8_sr_par.cc2if){
		cpos = (tim1()->ccr2->tim_ccr2_par.w0 - tim1()->ccr1->tim_ccr1_par.w0);
		gpioc()->odr->bit.o13 ^= 1;
	}
	if(tim1()->sr->tim1and8_sr_par.cc2if){
		tim1()->ccr1->tim_ccr1_par.w0 += 1000;
		if(cpos < 1){tim1()->ccr1->tim_ccr1_par.w0 = 0;}
	}

	tim1()->sr->tim1and8_sr_par.cc1if = 0;
	tim1()->sr->tim1and8_sr_par.cc2if = 0;
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

