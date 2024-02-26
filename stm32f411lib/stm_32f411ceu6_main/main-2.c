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
timer testing.
********************************************************************************/
#include "main.h"
#include "stm32fxxxmapping.h"
#include "armlcd.h"
#include "armfunction.h"

uint32_t count0 = 0;
uint32_t count1 = 0;
uint32_t count2 = 0;
uint32_t count3 = 0;
uint32_t count4 = 0;
uint32_t count5 = 0;
uint32_t count6 = 0;
uint32_t count7 = 0;
uint32_t count8 = 0;
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

  stm()->tim1->nvic(on);
  stm()->tim1->clock(on);
  //tim1()->ccmr1->tim1an8_ccmr1_ocm_par.oc1m = 6;
  tim1()->arr->tim_arr_par.w0 = 0xFFFF;
  //tim1()->rcr->tim_rcr_par.byte = 0;
  // Compare
  tim1()->ccr1->tim_ccr1_par.w0 = 16375;
  tim1()->ccr2->tim_ccr2_par.w0 = 32767;
  // pre-scaler
  tim1()->psc->tim_psc_par.w0 = 12;
  // interrupt
  tim1()->dier->tim1and8_dier_par.uie = 1;
  tim1()->dier->tim1and8_dier_par.cc1ie = 1;
  tim1()->dier->tim1and8_dier_par.cc2ie = 1;
  // other
  tim1()->dier->tim1and8_dier_par.comie = 1;
  tim1()->dier->tim1and8_dier_par.tie = 1;
  tim1()->dier->tim1and8_dier_par.bie = 1;
  //
  //tim1()->dier->tim1and8_dier_par.cc1de = 1;

  // Enable (Start/Stop)
  tim1()->cr1->tim1and8_cr1_par.arpe = 1;
  tim1()->cr1->tim1and8_cr1_par.cen = 1;


  while (1)
  {
	  lcd0()->gotoxy(0,0);
	  lcd0()->string_size(func()->ui32toa(TIM1->ARR),6); lcd0()->string_size(func()->ui32toa(TIM1->CCR1),6); lcd0()->string_size(func()->ui32toa(TIM1->CCR2),6);
	  lcd0()->gotoxy(1,0);
	  lcd0()->string_size(func()->ui32toa(count1),6); lcd0()->string_size(func()->i32toa(count2),6); lcd0()->string_size(func()->i32toa(count3),6);
	  lcd0()->gotoxy(2,0);
	  lcd0()->string_size(func()->ui32toa(count4),6); lcd0()->string_size(func()->i32toa(count5),6); lcd0()->string_size(func()->i32toa(count6),6);
	  lcd0()->gotoxy(3,0);
	  lcd0()->string_size(func()->ui32toa(count7),6); lcd0()->string_size(func()->ui32toa(count0),6); lcd0()->string_size(func()->ui32toa(count8),6);
  }
}

void TIM1_CC_IRQHandler(void){
	count0++;
	if(tim1()->sr->tim1and8_sr_par.uif){
		count1++;
		//count8=tim1()->cnt->tim_cnt_par.w0;
		//gpioc()->odr->bit.o13 = 0;
		tim1()->sr->tim1and8_sr_par.uif = 0;
	}
	if(tim1()->sr->tim1and8_sr_par.cc1if){
		count2++;
		//count8=tim1()->cnt->tim_cnt_par.w0;
		gpioc()->odr->bit.o13 = 1;
		tim1()->sr->tim1and8_sr_par.cc1if = 0;
	}
	if(tim1()->sr->tim1and8_sr_par.cc2if){
		count3++;
		//count8=tim1()->cnt->tim_cnt_par.w0;
		gpioc()->odr->bit.o13 = 0;
		tim1()->sr->tim1and8_sr_par.cc2if = 0;
	}
	if(tim1()->sr->tim1and8_sr_par.tif){
		count4++;
		//count8=tim1()->cnt->tim_cnt_par.w0;
		tim1()->sr->tim1and8_sr_par.tif = 0;
	}
	if(tim1()->sr->tim1and8_sr_par.comif){
		count5++;
		//count8=tim1()->cnt->tim_cnt_par.w0;
		tim1()->sr->tim1and8_sr_par.comif = 0;
	}
	if(tim1()->sr->tim1and8_sr_par.bif){
		count6++;
		//count8=tim1()->cnt->tim_cnt_par.w0;
		tim1()->sr->tim1and8_sr_par.bif = 0;
	}
	if(tim1()->sr->tim1and8_sr_par.cc1of){
		count7++;
		//count8=tim1()->cnt->tim_cnt_par.w0;
		tim1()->sr->tim1and8_sr_par.cc1of = 0;
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

