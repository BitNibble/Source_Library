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

I2C_HandleTypeDef i2c;

/** TIM1 CC IRQn CallBack ***/
/**
void tim1_u_callback(void){
	count1++;
}
**/
void tim1_cc1_callback(void){
	//count2++;
	//count8=tim1()->cnt->par.w0;
	gpioc()->handle->bsrr.par.resetpin_13 = 1;
}
/**/
/**/
void tim1_cc2_callback(void){
	//count3++;
	tim1()->handle->ccr1.par.w0 += (cdir * 295);
	if(tim1()->handle->ccr1.par.w0 > (tim1()->handle->ccr2.par.w0 - 100)){ cdir = -1; }
	if(tim1()->handle->ccr1.par.w0 < (1000 + 100)){ cdir = 1; }
	//count8=tim1()->cnt->par.w0;
	gpioc()->handle->bsrr.par.setpin_13 = 1;
}
/**/

int main(void)
{
  STM32FXXX_enable();

  gpiob()->clock(on); // lcd0
  gpioc()->clock(on); // gpio13
  gpioa()->clock(on); // timer 1 pwm af channel 1
  rtc()->inic(0); // 1 - LSE 0 - LSI

  i2c.Instance = (I2C_TypeDef*) i2c1_handle();

  //setup i2c io
  rcc()->handle->apb1enr.par.i2c1en = 1;
  //PB5 I2C1_SMBA
  //gpiob()->handle->afr.par.pin_6 = 4; // PB6 AF4 (I2C1..3) I2C1_SCL
  //gpiob()->handle->afr.par.pin_7 = 4; // PB7 AF4 (I2C1..3) I2C1_SDA
  //gpiob()->handle->moder.par.pin_6 = 1;
  //gpiob()->handle->moder.par.pin_7 = 1;
  //gpiob()->handle->pupdr.par.pin_6 = 1;
  //gpiob()->handle->pupdr.par.pin_7 = 1;

  //setup i2c parameters
  //i2c1_handle()->cr2.par.freq = query()->pclk1 / 1000000;
  //i2c1_handle()->trise.par.trise = (query()->pclk1 / 1000000) + 1;
  i2c.Init.ClockSpeed = 100000;
  i2c.Init.DutyCycle = I2C_DUTYCYCLE_2;
  i2c.Init.OwnAddress1 = 'A';
  i2c.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  i2c.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  i2c.Init.OwnAddress2 = 'A';
  i2c.Init.GeneralCallMode = I2C_GENERALCALL_ENABLE;
  i2c.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

  //Initialise parameters
  if (HAL_I2C_Init(&i2c) != HAL_OK)
  {
	  Error_Handler();
  }

  ARMLCD0_enable((GPIO_TypeDef*)gpiob()->handle);
  FUNC_enable();

  //gpioc()->handle->moder.par.pin_1 = 1;
  gpioc()->handle->moder.par.pin_13 = 1;

  stm()->tim1->nvic(1);
  //stm()->tim1->nvic(17);
  stm()->tim1->clock(on);

  gpioa()->handle->afr.par.pin_7 = 1; // pin 7 af tim1ch1n
  gpioa()->handle->afr.par.pin_8 = 1; // pin 8 af tim1ch1
  gpioa()->handle->moder.par.pin_7 = 2; // AF enable
  gpioa()->handle->moder.par.pin_8 = 2; // AF enable

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
  //((STM32FXXXTIMXX_TypeDef*) tim1_handle())->cr1.tim1and8_par.cen = 1;

  char vecT[8]; // for calendar
  //char vecD[8]; // for calendar
  rtc()->Year(24);
  rtc()->Month(1);
  rtc()->Day(1);
  rtc()->Hour(12);
  rtc()->Minute(0);
  rtc()->Second(0);
  cdir = 1;

  //HAL_I2C_Master_Transmit( &i2c, devaddr, pdata, size, timeout );

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
	  //lcd0()->string_size(func()->print_v2("pclk1: %d", query()->pclk1()),14);

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
struct->x_union->register
               ->parameter

STM32 seems to be the only brand that gives a most complete working set and environment,
the style could be improved, but as is, is easy to work with.
Why do not other brands give a CMSIS and HAL layer for the user to work with do not know.
Maybe they are lazy, but also STM could take a step further and give driver library for all
external components. But that may be asking to much for then anybody could play around.

***/

