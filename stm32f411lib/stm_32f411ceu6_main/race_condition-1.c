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
uint8_t callback;

uint8_t tim1_cc1f_callback(void);
uint8_t tim1_cc2f_callback(void);

int main(void)
{
  STM32FXXX_enable();

  uint16_t counter = 0;

  gpiob()->clock(on); // lcd0
  gpioc()->clock(on); // gpio13
  rtc()->inic(0); // 1 - LSE 0 - LSI

  ARMLCD0_enable(stm()->gpiob_reg);
  FUNC_enable();

  gpioc()->moder->par.m13 = 1;

  stm()->tim1->nvic(on);
  stm()->tim1->clock(on);
  //tim1()->ccmr1->tim1an8_ocm_par.oc1m = 6;
  tim1()->arr->par.w0 = 0xFFFF;
  //tim1()->rcr->par.byte = 0;
  // Compare
  tim1()->ccr1->par.w0 = 1000;
  tim1()->ccr2->par.w0 = 60000;
  // pre-scaler
  tim1()->psc->par.w0 = 4;
  // interrupt
  //tim1()->dier->tim1and8_par.uie = 0;
  tim1()->dier->tim1and8_par.cc1ie = 1;
  tim1()->dier->tim1and8_par.cc2ie = 1;
  // other
  //tim1()->dier->tim1and8_par.comie = 0;
  //tim1()->dier->tim1and8_par.tie = 0;
  //tim1()->dier->tim1and8_par.bie = 0;
  //
  //tim1()->dier->tim1and8_par.ude = 0;
  //tim1()->dier->tim1and8_par.cc1de = 0;

  // Enable (Start/Stop)
  tim1()->cr1->tim1and8_par.arpe = 1;
  tim1()->cr1->tim1and8_par.cen = 1;

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
	  if(tim1_cc1f_callback()==1){counter++;}

	  lcd0()->gotoxy(0,0);
	  lcd0()->string_size(func()->ui32toa(TIM1->ARR),6); lcd0()->string_size(func()->ui32toa(tim1()->ccr1->par.w0),6); lcd0()->string_size(func()->ui32toa(TIM1->CCR2),6);

	  lcd0()->gotoxy(1,0);
	  lcd0()->string_size(func()->ui32toa(count1),6); lcd0()->string_size(func()->i32toa(count2),6); lcd0()->string_size(func()->i32toa(count3),6);

	  lcd0()->gotoxy(2,0);
	  //lcd0()->string_size(func()->ui32toa(count4),6); lcd0()->string_size(func()->i32toa(count5),6); lcd0()->string_size(func()->i32toa(count6),6);
	  //lcd0()->string_size(func()->print_binary(16,tim1()->dier->reg),17);
	  rtc()->tr2vec(vecT);
	  lcd0()->string_size(func()->print_v2("hora: %d%d:%d%d:%d%d", vecT[0],vecT[1],vecT[2],vecT[3],vecT[4],vecT[5]),14);

	  lcd0()->gotoxy(3,0);
	  lcd0()->string_size(func()->ui32toa(count7),6); lcd0()->string_size(func()->ui32toa(count0),6); lcd0()->string_size(func()->ui32toa(counter),6);
  }
}
/*** END MAIN ***/
/***
uint8_t tim1_cc1f_callback(void){
	count2++;
	//count8=tim1()->cnt->par.w0;
	gpioc()->bsrr->bit.r13 = 1;
	return 1;
}
uint8_t tim1_cc2f_callback(void){
	count3++;
	tim1()->ccr1->par.w0 += (cdir * 295);
	if(tim1()->ccr1->par.w0 > (tim1()->ccr2->par.w0 - 100)){ cdir = -1; }
	if(tim1()->ccr1->par.w0 < (1000 + 100)){ cdir = 1; }
	//count8=tim1()->cnt->par.w0;
	gpioc()->bsrr->bit.s13 = 1;
	return 1;
}
***/

uint8_t tim1_cc1f_callback(void){
	uint8_t oneshot = callback;
	callback = 0;
	return oneshot;
}
uint8_t tim1_cc2f_callback(void){
	uint8_t oneshot = callback;
	callback = 0;
	return oneshot;
}

void TIM1_CC_IRQHandler(void){

	count0++;
	if(tim1()->sr->tim1and8_par.uif){
		count1++;
		count8=tim1()->cnt->par.w0;
		//gpioc()->odr->bit.o13 = 0;
		tim1()->sr->tim1and8_par.uif = 0;
	}
	if(tim1()->sr->tim1and8_par.cc1if){
		count2++;
		//count8=tim1()->cnt->par.w0;
		gpioc()->bsrr->bit.r13 = 1;
		callback = 1;
		tim1()->sr->tim1and8_par.cc1if = 0;
	}
	if(tim1()->sr->tim1and8_par.cc2if){
		count3++;
		tim1()->ccr1->par.w0 += (cdir * 295);
		if(tim1()->ccr1->par.w0 > (tim1()->ccr2->par.w0 - 100)){ cdir = -1; }
		if(tim1()->ccr1->par.w0 < (1000 + 100)){ cdir = 1; }
		//count8=tim1()->cnt->par.w0;
		gpioc()->bsrr->bit.s13 = 1;
		callback = 2;
		tim1()->sr->tim1and8_par.cc2if = 0;
	}
	if(tim1()->sr->tim1and8_par.tif){
		count4++;
		//count8=tim1()->cnt->par.w0;
		tim1()->sr->tim1and8_par.tif = 0;
	}
	if(tim1()->sr->tim1and8_par.comif){
		count5++;
		//count8=tim1()->cnt->par.w0;
		tim1()->sr->tim1and8_par.comif = 0;
	}
	if(tim1()->sr->tim1and8_par.bif){
		count6++;
		//count8=tim1()->cnt->par.w0;
		tim1()->sr->tim1and8_par.bif = 0;
	}
	if(tim1()->sr->tim1and8_par.cc1of){
		count7++;
		//count8=tim1()->cnt->par.w0;
		tim1()->sr->tim1and8_par.cc1of = 0;
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

/*** EOF ***/
/*** Comment
struct->register->par

***/

