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
  * Date: 28022024
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
timer testing. At 25Mhz and STM32FXXXPrescaler(1, 1, 1, 0);
- uie is always enabled wonder why the option exists.
- dimmer
- testing race conditions
- Callback function for timer 1 CC
********************************************************************************/
#include "main.h"
#include "stm32fxxxmapping.h"
#include "armlcd.h"
#include "armfunction.h"

uint16_t count0 = 0;
uint16_t count1 = 0;
uint16_t count2 = 0;
uint16_t count3 = 0;
uint16_t count4 = 0;
uint16_t count5 = 0;
uint16_t count6 = 0;
uint16_t count7 = 0;
uint16_t count8 = 0;
int8_t cdir;

/** TIM1 CC IRQn CallBack ***/
/**
void tim1_u_callback(void){
	count1++;
}
**/
void tim1_cc1_callback(void){
	//count2++;
	//count8=tim1()->cnt->par.w0;
	gpioc()->handle->bsrr.bit.r13 = 1;
}
/**/
/**/
void tim1_cc2_callback(void){
	//count3++;
	tim1()->handle->ccr1.par.w0 += (cdir * 295);
	if(tim1()->handle->ccr1.par.w0 > (tim1()->handle->ccr2.par.w0 - 100)){ cdir = -1; }
	if(tim1()->handle->ccr1.par.w0 < (1000 + 100)){ cdir = 1; }
	//count8=tim1()->cnt->par.w0;
	gpioc()->handle->bsrr.bit.s13 = 1;
}
/**/

int main(void)
{
  STM32FXXX_enable();

  gpiob()->clock(on); // lcd0
  gpioc()->clock(on); // gpio13
  gpioa()->clock(on); // timer 1 pwm af channel 1
  rtc()->inic(0); // 1 - LSE 0 - LSI

  ARMLCD0_enable(stm()->gpiob_reg);
  FUNC_enable();

  gpioc()->handle->moder.par.m13 = 1;

  stm()->tim1->nvic(1);
  //stm()->tim1->nvic(17);
  stm()->tim1->clock(on);
  gpioa()->handle->afr.par.pin7 = 1; // pin 7 af tim1ch1n
  gpioa()->handle->afr.par.pin8 = 1; // pin 8 af tim1ch1
  gpioa()->handle->moder.par.m7 = 2; // AF enable
  gpioa()->handle->moder.par.m8 = 2; // AF enable
  tim1()->handle->ccmr1.tim1and8_ocm_par.oc1m = 6;
  //tim1()->handle->ccmr1.ocm_par.oc1m = 6;
  tim1()->handle->ccer.tim1and8_par.cc1ne = 1;
  tim1()->handle->ccer.tim1and8_par.cc1e = 1;
  tim1()->handle->bdtr.tim1and8_par.moe = 1;
  tim1()->handle->arr.par.w0 = 0xFFFF;
  // Compare
  tim1()->handle->ccr1.par.w0 = 1000;
  tim1()->handle->ccr2.par.w0 = 60000;
  // pre-scaler
  tim1()->handle->psc.par.w0 = 1;
  // interrupt
  tim1()->handle->dier.tim1and8_par.cc1ie = 1;
  tim1()->handle->dier.tim1and8_par.cc2ie = 1;
  // other
  //tim1()->handle->dier.tim1and8_par.comie = 1;
  //tim1()->handle->dier.tim1and8_par.tie = 0;
  //tim1()->handle->dier.tim1and8_par.bie = 0;
  //
  //tim1()->handle->dier.tim1and8_par.ude = 1;
  //tim1()->handle->dier.tim1and8_par.cc1de = 1;

  // Enable (Start/Stop)
  tim1()->handle->cr1.tim1and8_par.arpe = 1;
  tim1()->handle->cr1.tim1and8_par.cen = 1;

  char vecT[8]; // for calendar
  //char vecD[8]; // for calendar
  rtc()->Year(24);
  rtc()->Month(1);
  rtc()->Day(1);
  rtc()->Hour(12);
  rtc()->Minute(0);
  rtc()->Second(0);
  cdir = 1;

  while (1)
  {
	  lcd0()->gotoxy(0,0);
	  lcd0()->string_size(func()->ui32toa(TIM1->ARR),6); lcd0()->string_size(func()->ui32toa(tim1()->handle->ccr1.par.w0),6); lcd0()->string_size(func()->ui32toa(TIM1->CCR2),6);

	  //lcd0()->gotoxy(1,0);
	  //lcd0()->string_size(func()->ui32toa(count1),6); lcd0()->string_size(func()->i32toa(count2),6); lcd0()->string_size(func()->i32toa(count3),6);

	  lcd0()->gotoxy(2,0);
	  //lcd0()->string_size(func()->ui32toa(count4),6); lcd0()->string_size(func()->i32toa(count5),6); lcd0()->string_size(func()->i32toa(count6),6);
	  //lcd0()->string_size(func()->print_binary(16,tim1()->cr1->reg),17);
	  rtc()->tr2vec(vecT);
	  lcd0()->string_size(func()->print_v2("hora: %d%d:%d%d:%d%d", vecT[0],vecT[1],vecT[2],vecT[3],vecT[4],vecT[5]),14);

	  //lcd0()->gotoxy(3,0);
	  //lcd0()->string_size(func()->ui32toa(count4),6); lcd0()->string_size(func()->ui32toa(count5),6); lcd0()->string_size(func()->ui32toa(count7),6);
  }
}
/*** END MAIN ***/

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

/*** EOF ***/
/*** Comment
struct->register->par

***/

