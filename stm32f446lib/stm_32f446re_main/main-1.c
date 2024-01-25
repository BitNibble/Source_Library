/******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
*******************************************************************************
  * @attention
  *
  * Copyright (c) 2022 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  * Author: Sergio Santos
  *	<sergio.salazar.santos@gmail.com>
  *	License: GNU General Public License
  *	Hardware: STM32-446
  *
  * Date:
  * 25/06/2023
*******************************************************************************/
/**** Comment
PC 0,1,2 		---> 74HC595
PB 0...7 		---> LCD 4x20
PA 5     		---> Led indicator
PC 13    		---> user button
PA9 and PA10 	---> USART1
*******************************************************************************/
#include "main.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#include "stm32446mapping.h"
#include "armfunction.h"
#include "explode.h"
#include "74hc595.h"
#include "armlcd.h"
#include "circbuffer.h"

#include "stm32f4xx_hal.h"

static EXPLODE PINA;
static EXPLODE PINB;
static EXPLODE PINC;
static HC595 hc;
static ARMLCD0 lcd;
static circbuff circ;
static circbuff circ2;

static int8_t count1;
static uint16_t count2;
static uint8_t dir;
uint32_t time_out;

void portinic(void);

void TIM1_BRK_TIM9_IRQHandler(void);
/******************************************************************************/
int main(void)
{
STM32446_enable();
portinic();

unsigned int workspace;
unsigned int zone;
uint8_t transmit;
uint8_t receive;
uint32_t value;

double temperature = 0;
unsigned int samples = 0;
const int n_samples = 60;

char buffer[64]; // for circular buffer
char buffer2[64]; // for circular buffer
char received[64]; // for circular buffer
char message[64]; // for circular buffer

FUNC_enable();
PINA = EXPLODE_enable();
PINB = EXPLODE_enable();
PINC = EXPLODE_enable();
circ = CIRCBUFF_enable(32, buffer);
circ2 = CIRCBUFF_enable(32, buffer2);

count1 = 0;
count2 = 0;
dir = 0;

// Initialise objects after portinic()
hc = HC595_enable(&stm()->gpioc_reg->MODER, &stm()->gpioc_reg->ODR, 2, 1, 0);
lcd = ARMLCD0_enable(stm()->gpiob_reg);

usart1()->parameter(8, 16, 1, 9600);

/***************************** TEST STUFF START *******************************/


/*****************************  TEST STUFF END  *******************************/

for ( zone = 0, workspace = 0 ; (1) ; workspace++)
{// COMMON
zone = workspace & 7;

if(zone == 0)
{// PREAMBLE PREAMBLE COMMON

	PINA.update(&PINA.par, stm()->gpioa_reg->IDR);
	PINB.update(&PINB.par, stm()->gpiob_reg->IDR);
	PINC.update(&PINC.par, stm()->gpioc_reg->IDR);
	lcd.reboot();
	// Detect for all workspaces only once

	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 1)
{// workspace 1
	value = func()->triggerB(PINC.par.HL,PINC.par.LH,13,count2);
	if( value > 5 && value < 11 ){
		circ.putstr(&circ.par, "5 to 10 pulse press\r\n" );
	}
	if( value > 10 && value < 30 ){
		circ.putstr(&circ.par, "10 to 30 pulse press\r\n");
	}
	if( value > 40 ){
		circ.putstr(&circ.par, "More than 40 pulse press\r\n");
	}

	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 2)
{// workspace 2 ADC1 TEMPERATURE

	lcd.gotoxy(1,0);

	if(samples < n_samples){
		temperature += ADC1->DR;
		stm()->adc1->cr2->swstart(1); for(time_out = 200; time_out; time_out--);
		samples++;
	}else{
		temperature /= n_samples;
		temperature = (temperature/3.1 - 943/3.1) + 25;
		lcd.string_size( func()->print_v1(message, 6, "%d %cC", (unsigned int)temperature, (char) 0xDF ), 6);
		//lcd.string_size( stm.func.ftoa( stm.rcc.systemclock(), message, 0) , 14);
		samples=0;
	}

	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 3)
{// workspace 3 USART1 TX RX

	if( stm()->usart1_reg->SR & (1 << 6) ){ // TC: Transmission complete

		transmit = circ.get(&circ.par);
		if(transmit)
			stm()->usart1_reg->DR = transmit;

	}

	if(stm()->usart1_reg->SR & (1 << 5)){ // RXNE: Read data register not empty
		receive = stm()->usart1_reg->DR;
		if(receive){
			circ2.put(&circ2.par, receive);

			if(receive == 13 ){
				circ2.getstr(&circ2.par, received);
				lcd.gotoxy(1,6);
				received[strlen(received)-1] = '\0'; //remove enter key [13]
				lcd.string_size(received, 14);
			}

		}
		stm()->usart1_reg->SR &=  ~(1 << 5);
	}

	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 4)
{// workspace 4
	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 5)
{// workspace 5
	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 6)
{// workspace 6
	continue;
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 7)
{// workspace 7
	continue;
} // if
/******************************************************************************/
/******************************************************************************/
} // for
} // main

/******************************************************************************/
		/*************************************************************/
/******************************************************************************/

void portinic(void)
{
	//Enable clock for IO peripherals
	stm()->rcc->apb1enr->pwren(yes);
	stm()->rcc->apb2enr->usart1en(yes);
	stm()->rcc->bdcr->rtcen(yes);
	stm()->rcc->apb2enr->adc1en(yes);
	stm()->rcc->ahb1enr->gpioaen(yes);
	stm()->rcc->ahb1enr->gpioben(yes);
	stm()->rcc->ahb1enr->gpiocen(yes);
	stm()->rcc->apb2enr->tim9en(yes);
	/**************************/
  	// PA5 or PB13 is green user led
	stm()->gpioa->moder(5,1); // 0-input 1-output 2-Af 3-Analog
	stm()->gpioa->pupdr(5,0);
	gpioa()->ospeedr(5,3); // 3-100Mhz 2-50Mhz 1-25Mhz 0-2Mhz
	// PC13 is user button
	stm()->gpioc->moder(13,0);
	stm()->gpioc->pupdr(13,1); // 2-pull down 1-pull up 0-non
	/********* USART1 *********/
	stm()->usart1->cr1->ue(on);
	stm()->gpioa->moder(9,2);
	stm()->gpioa->moder(10,2);
	stm()->gpioa->afr(9,7);
	stm()->gpioa->afr(10,7);
	stm()->usart1->parameter(8, 16, 1, 38400);
	stm()->usart1->cr3->dmat(off);
	stm()->usart1->cr1->te(on);
	stm()->usart1->cr3->dmar(off);
	stm()->usart1->cr1->re(on);
	/****** TIMER9 SETUP ******/
	// NVIC
	//stm()->nvic->set_enable(24);
	tim9()->nvic(on);
	// Frequency
	stm()->tim9->arr(45535);
	// Compare
	stm()->tim9->ccr1(7530);
	// pre-scaler
	stm()->tim9->psc(10);
	// interrupt
	stm()->tim9->dier->cc1ie(on);
	// Enable (Start/Stop)
	stm()->tim9->cr1->apre(on);
	stm()->tim9->cr1->cen(on);
	/********** ADC1 **********/
	stm()->adc1->single->inic();
	stm()->adc1->single->temp();
	//stm.adc1.single.vbat();
	stm()->adc1->single->start();
}

/***Interrupt Definition***/

void TIM1_BRK_TIM9_IRQHandler(void)
{
	/***/
	if(stm()->tim9_reg->SR & 1){ // status register (view interrupt flags)
		stm()->tim9_reg->SR &=  (uint32_t) ~1;

		if(dir){
			stm()->gpioa->reset(1 << 5);

			hc.byte(&hc.par, (uint8_t)~(1 << count1--));
			if(count1 < 0)
				dir = 0;
		}else{
			stm()->gpioa->set(1 << 5);

			hc.byte(&hc.par, (uint8_t)~(1 << count1++));
			if(count1 > 7)
				dir = 1;
		}
		count2++;
	}
	if(stm()->tim9_reg->SR & 2){
		stm()->tim9_reg->SR &=  (uint32_t) ~2;
	}
	/***/
	//tim9.reg->SR &=  (uint32_t) ~1;
	//tim9.reg->SR &=  (uint32_t) ~2;
}

/******************************************************************************/
void Error_Handler(void)
{
  __disable_irq();

  perror("error\n");
  //while (1)
  //{

  //}
}
/******************************************************************************/
/******************************************************************************
#ifdef  USE_FULL_ASSERT
void assert_failed(uint8_t *file, uint32_t line)
{

}
#endif
*******************************************************************************/
/******************************** COMMENT *************************************

*******************************************************************************/
/***EOF***/

