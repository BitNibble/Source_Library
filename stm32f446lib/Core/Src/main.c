/**
  ******************************************************************************
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
  * File: MAIN 12/01/2024
  *
  * Software: STM32CubeIDE Version: 1.14.0 Build: 19471_20231121_1200 (UTC)
  * Hardware: Nucleo-F446RE
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
#include "main.h"
/*** Library Switches ***/
#ifndef ARM_MATH_CM4
	#define ARM_MATH_CM4
#endif

#include "stm32446mapping.h"
#include <arm_math.h>
#include "armfunction.h"
#include "explode.h"
#include "74hc595.h"
#include "armlcd.h"
#include "circbuffer.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#ifndef ass
	#define ass (1)
#endif

static EXPLODE PINA;
static EXPLODE PINB;
static EXPLODE PINC;
static HC595 hc;
static ARMLCD0 lcd;
static circbuff circ1;
static circbuff circ2;
static char buffer1[32]; // for circular buffer
static char buffer2[32]; // for circular buffer

volatile unsigned int time_out;
static uint32_t index_var;
static uint8_t choice;
static uint8_t hour = 0;
static uint8_t minute = 0;
static uint8_t second = 0;
static uint8_t ano = 0;
static uint8_t mes = 1;
static uint8_t dia = 1;
static uint32_t value = 0;

uint16_t temperature[128];
uint32_t valuet;
double tempt;

static char transmit;
//static char toggle;
static char receive;
static char received[32]; // from circular buffer
static char message[64];

static int8_t count1;
static uint8_t count2;
static uint8_t dir;
uint16_t charcount;

uint8_t button_press;

void portinic(void);
void calendario(void);
void USART1_IRQHandler(void);

/*************************************/
int main(void)
{
STM32446_enable();
//tim9_inic();
FUNC_enable();
portinic();

unsigned int zone;

button_press = 0;
charcount=0;
time_out = 0;

//func = FUNCenable();
PINA = EXPLODE_enable();
PINB = EXPLODE_enable();
PINC = EXPLODE_enable();
circ1 = CIRCBUFF_enable(32, buffer1);
circ2 = CIRCBUFF_enable(32, buffer2);

// FPU full access
setreg(&stm()->scb_reg->CPACR, 2, 20, 3);
setreg(&stm()->scb_reg->CPACR, 2, 22, 3);

choice = 3;
count1 = 0;
count2 = 0;
dir = 0;

hc = HC595_enable(&stm()->gpioc_reg->MODER, &stm()->gpioc_reg->ODR, 2, 1, 0);
lcd = ARMLCD0_enable(stm()->gpiob_reg);


circ1.putstr(&circ1.par, "Welcome\r\n");
//stm()->rtc.run->BckWrite(2,33);
//stm.func.setreg(&test_var,2,30,3);
/*************************************/
for ( zone = 1 ; ass ; zone++)
{// COMMON

if(zone == 1){ // Preamble
	/*** PREAMBLE PREAMBLE COMMON IO ***/
	PINA.update(&PINA.par, stm()->gpioa_reg->IDR);
	PINB.update(&PINB.par, stm()->gpiob_reg->IDR);
	PINC.update(&PINC.par, stm()->gpioc_reg->IDR);
	lcd.reboot();
	lcd.gotoxy(0,4);
	//lcd.string_size(func()->ui32toa( getsysclk()/gethpre()/1000000 - 1 ),15 );
	lcd.string_size(func()->ui32toa( USART1_IRQn ),15 );
	//lcd.string_size(func()->ftoa( (double) getsysclk()/gethpre(), 4 ),15 );
	//lcd.string_size(func()->ftoa( (double) 75/12 ,4 ),15);
	//_delay_5us(2000000);
}
/******************************************************************************/
/******************************************************************************/
if(zone == 2){ // workspace 1 RTC CALENDAR

	//if(PINC.par.LH & (1 << 13)){lcd.gotoxy(0,11); lcd.string(func.i32toa(stm.query.PLL_parameter.Source));}
	if(PINC.par.LH & (1 << 13)){
		//lcd0()->gotoxy(0,11); lcd0()->string_size(stm()->func->i16toa(button_press++),9);
		//lcd.gotoxy(0,11); lcd.string_size(stm.func.i16toa(button_press++),4);
		circ1.putstr(&circ1.par, "Welcome\r\n");
		//transmit = 'Z';
	}
	//lcd.gotoxy(0,4); lcd.string_size(func()->i32toa(tim8()->get_cnt()),5);
	//lcd.gotoxy(0,4); lcd.string(func()->i32toa(query()->SystemClock()));
	//lcd.gotoxy(0,15); lcd.string(func()->i32toa(stm()->rtc->BckRead(2)));
	//if(PINC.par.LL & (1 << 13)){setbit(&stm()->gpioa_reg->ODR, 1, 5, 3);}

	calendario();

} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 3){ // workspace 2 ADC1 TEMPERATURE
	for(tempt=0, index_var = 0; index_var < 32; index_var += 2 ){
		tempt += temperature[index_var];
	}
	valuet = tempt / 16;
	valuet = (valuet/3.1 - 943/3.1) + 25; // (valuet/3.1 - 943/3.1) + 25;

	lcd.gotoxy(1,0);
	lcd.string_size( func()->print_v1(message, 10, "%d %cC", (unsigned int)valuet, (char) 0xDF ), 6);
	lcd.gotoxy(1,6);
	lcd.string_size( func()->print_v1(message, 10, "%d", (unsigned int)temperature[3], (char) 0xDF ), 4);
} // if
/******************************************************************************/
/******************************************************************************/
if(zone == 4){ // workspace 3 USART1 TX RX

	lcd.gotoxy(1,11);
	lcd.string_size(received, 9);
	if( stm()->usart1->sr->tc() ){ // TC: Transmission complete
		transmit = circ1.get(&circ1.par);
		if(transmit){ stm()->usart1->dr(transmit); for(time_out = 20; (!stm()->usart1->sr->tc()) && time_out; time_out--);}
		}
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
	//Enable clock for IO peripherals
	gpioa()->clock(on);
	gpiob()->clock(on);
	gpioc()->clock(on);
  	// PA5 or PB13 is green user led
	stm()->gpioa->moder(5,1);
	stm()->gpioa->pupdr(5,0); // 2-pull down 1-pull up 0-non
	gpioa()->ospeedr(5,3); // 3-100Mhz 2-50Mhz 1-25Mhz 0-2Mhz
	// PC13 is user button
	stm()->gpioc->moder(13,0);
	stm()->gpioc->pupdr(13,1);
	/********** USART1 *********/
	stm()->usart1->clock(on);
	usart1()->nvic(on);
	usart1()->cr1->ue(on);
	stm()->gpioa->moder(9,2);
	stm()->gpioa->moder(10,2); // 0-input 1-output 2-Af 3-Analog
	stm()->gpioa->afr(9,7);
	stm()->gpioa->afr(10,7);
	stm()->usart1->parameter(8, 16, 1, 38400);
	stm()->usart1->cr3->dmat(off);
	stm()->usart1->cr1->te(on);
	stm()->usart1->cr3->dmar(off);
	stm()->usart1->cr1->re(on);
	stm()->usart1->cr1->rxneie(on);
	/******* TIMER9 SETUP ******/
	tim9()->clock(on);
	// NVIC
	tim9()->nvic(on);
	// Frequency
	tim9()->arr(4535);
	// Compare
	tim9()->ccr1(1400);
	// pre-scaler
	tim9()->psc(300);
	// interrupt
	tim9()->dier->cc1ie(on);
	// Enable (Start/Stop)
	tim9()->cr1->apre(on);
	tim9()->cr1->cen(on);
	/********** ADC1 ***********/
	gpioa()->pupdr(0,1);
	gpioa()->moder(0,3);
	// ADC Clock
	adc1()->clock(on); // ADC1EN: ADC1 clock enable
	adc1()->cr2->adon(off); // ADON: A/D Converter ON / OFF
	adc1()->common->ccr->adcpre(3); // ADCPRE: ADC prescaler, 11: PCLK2 divided by 8
	adc1()->smpr1->smp18(7); // SMPx[2:0]: Channel x sampling time selection
	adc1()->smpr2->smp0(7); // SMPx[2:0]: Channel x sampling time selection
	adc1()->sqr1->l(1); // 0 -> read one channel, 1 -> read two channels
	adc1()->sqr3->sq1(18); // SQ1[4:0]: 1st conversion in regular sequence
	adc1()->sqr3->sq2(0); // SQ2[4:0]: 2st conversion in regular sequence
	adc1()->single->temp();
	adc1()->cr2->eocs(1);
	adc1()->cr2->dma(1);
	stm()->adc1->cr2->dds(1);
	adc1()->start();
	adc1()->cr2->cont(1);
	adc1()->cr1->scan(1);

	dma2()->clock(on);
	dma2()->func->circ_cfg(&ADC1->DR, (volatile long unsigned int*)temperature, 0, 0, 32, 1, 1, 0, 0);
	/*********** RTC ***********/
	rtc()->clock(on);
	rtc()->inic(1); // 2 - LSI, 1 - LSE
	/***************************/
}
/******************************************************************************/
void calendario(void)
{
	char vecT[8]; // for calendar
	char vecD[8]; // for calendar
	const uint16_t min1 = 0;
	const uint16_t max1 = 50;
	const uint16_t min2 = 50;
	const uint16_t max2 = 120;
	const uint16_t min3 = 120;
	const uint16_t max3 = 500;

	const uint16_t minp1 = 0;
	const uint16_t maxp1 = 50;
	const uint16_t minp2 = 50;
	const uint16_t maxp2 = 120;
	const uint16_t minp3 = 120;
	//const uint16_t maxp3 = 100;

	/******MENU*****/
	switch(choice){
		case 1: // show time
			lcd.gotoxy(0,0);
			lcd.string_size("Rel",4);
			rtc()->tr2vec(vecT);
			lcd.gotoxy(3,0);
			lcd.string_size(func()->print_v2("hora: %d%d:%d%d:%d%d", vecT[0],vecT[1],vecT[2],vecT[3],vecT[4],vecT[5]),14);
			value = func()->triggerA(PINC.par.LL,13,rtc()->get_ss());
			if( value > min1 && value < max1 ){
				rtc()->dr2vec(vecD);
				circ1.putstr(&circ1.par, func()->print_v2("data: %d%d:%d%d:20%d%d\r\n", vecD[5],vecD[6],vecD[3],vecD[4],vecD[0],vecD[1]));
				lcd.clear();
				choice = 2;
			}
			if( value > min2 && value < max2 ){
				circ1.putstr(&circ1.par, "acertar hora\r\n");
				lcd.clear();
				choice = 4;
			}
			if( value > min3 && value < max3 ){
				circ1.putstr(&circ1.par, "Calendario\r\n");
				lcd.clear();
				choice = 3;
			}
			break;

		case 2: // show date
			lcd.gotoxy(0,0);
			lcd.string_size("Dat",4);
			rtc()->dr2vec(vecD);
			lcd.gotoxy(3,0);
			lcd.string_size(func()->print_v2("data: %d%d:%d%d:20%d%d", vecD[5],vecD[6],vecD[3],vecD[4],vecD[0],vecD[1]),16);
			value = func()->triggerA(PINC.par.LL,13,rtc()->get_ss());
			if( value > min1 && value < max1 ){
				rtc()->tr2vec(vecT);
				circ1.putstr(&circ1.par, func()->print_v2("hora: %d%d:%d%d:%d%d\r\n", vecT[0],vecT[1],vecT[2],vecT[3],vecT[4],vecT[5]) );
				lcd.clear();
				choice = 1;
			}
			if( value > min2 && value < max2 ){
				circ1.putstr(&circ1.par, "acertar ano\r\n");
				lcd.clear();
				choice = 7;
			}
			if( value > min3 && value < max3 ){
				circ1.putstr(&circ1.par, "Calendario\r\n");
				lcd.clear();
				choice = 3;
			}
			break;

		case 3: // message
			lcd.gotoxy(0,0);
			lcd.string_size("Cal",4);

			rtc()->dr2vec(vecD);
			lcd.gotoxy(2,0);
			lcd.string_size(func()->print_v2("data: %d%d:%d%d:20%d%d", vecD[5],vecD[6],vecD[3],vecD[4],vecD[0],vecD[1]), 16);

			rtc()->tr2vec(vecT);
			lcd.gotoxy(3,0);
			lcd.string_size(func()->print_v2("hora: %d%d:%d%d:%d%d", vecT[0],vecT[1],vecT[2],vecT[3],vecT[4],vecT[5]), 14);

			value = func()->triggerA(PINC.par.LL,13,rtc()->get_ss());
			if( value > min3 && value < max3 ){
				circ1.putstr(&circ1.par, "Relogio\r\n");
				lcd.clear();
				choice = 1;
			}
			break;

		// Relogio
		case 4: // Set Hour
			lcd.gotoxy(0,0);
			lcd.string_size("Hr",4);
			value = func()->triggerA(PINC.par.LL,13,rtc()->get_ss());
			if( value > minp1 && value < maxp1 ){
				hour ++;
				if(hour > 23)
					hour = 0;
				lcd.gotoxy(2,0);
				lcd.string_size(func()->print_v2("hora: %d", hour),8);
			}
			if( value > minp2 && value < maxp2 ){
				circ1.putstr(&circ1.par, "acertar minutos\r\n");
				lcd.clear();
				choice = 5;
			}
			if( value > minp3 ){
				circ1.putstr(&circ1.par, "Relogio\r\n");
				choice = 1;
				rtc()->Hour(hour);
				lcd.clear();
			}
			break;

		case 5: // Set Minute
			lcd.gotoxy(0,0);
			lcd.string_size("Min",4);
			value = func()->triggerA(PINC.par.LL,13,rtc()->get_ss());
			if( value > minp1 && value < maxp1 ){
				minute ++;
				if(minute > 59)
					minute = 0;
				lcd.gotoxy(2,0);
				lcd.string_size(func()->print_v2("minuto: %d", minute),10);
			}
			if( value > minp2 && value < maxp2 ){
				circ1.putstr(&circ1.par, "acertar segundos\r\n");
				lcd.clear();
				choice = 6;
			}
			if( value > minp3 ){
				circ1.putstr(&circ1.par, "Relogio\r\n");
				choice = 1;
				rtc()->Minute(minute);
				lcd.clear();
			}
			break;

		case 6: // Set Second
			lcd.gotoxy(0,0);
			lcd.string_size("Seg",4);
			value = func()->triggerA(PINC.par.LL,13,rtc()->get_ss());
			if( value > minp1 && value < maxp1 ){
				second ++;
				if(second > 59)
					second = 0;
				lcd.gotoxy(2,0);
				lcd.string_size(func()->print_v2("segundo: %d", second),11);
			}
			if( value > minp2 && value < maxp2 ){
				circ1.putstr(&circ1.par, "Relogio\r\n");
				lcd.clear();
				choice = 1;
			}
			if( value > minp3 ){
				circ1.putstr(&circ1.par, "Relogio\r\n");
				choice = 1;
				rtc()->Second(second);
				lcd.clear();
			}
			break;

			// Calendario
		case 7: // Set Year
			lcd.gotoxy(0,0);
			lcd.string_size("Ano",4);
			value = func()->triggerA(PINC.par.LL,13,rtc()->get_ss());
			if( value > minp1 && value < maxp1 ){
				ano ++;
				if(ano > 99)
					ano = 0;
				lcd.gotoxy(2,0);
				lcd.string_size(func()->print_v2("Ano: %d", ano),7);
			}
			if( value > minp2 && value < maxp2 ){
				lcd.clear();
				circ1.putstr(&circ1.par, "acertar mes\r\n");
				choice = 8;
			}
			if( value > minp3 ){
				lcd.clear();
				circ1.putstr(&circ1.par, "Data\r\n");
				choice = 2;
				rtc()->Year(ano);
			}
			break;

		case 8: // Set Month
			lcd.gotoxy(0,0);
			lcd.string_size("Mes",4);
			value = func()->triggerA(PINC.par.LL,13,rtc()->get_ss());
			if( value > minp1 && value < maxp1 ){
				mes ++;
				if(mes > 12)
					mes = 1;
				lcd.gotoxy(2,0);
				lcd.string_size(func()->print_v2("mes: %d", mes),7);
			}
			if( value > minp2 && value < maxp2 ){
				lcd.clear();
				circ1.putstr(&circ1.par, "acertar dia\r\n");
				choice = 9;
			}
			if( value > minp3 ){
				lcd.clear();
				circ1.putstr(&circ1.par, "Data\r\n");
				choice = 2;
				rtc()->Month(mes);
			}
			break;

		case 9: // Set Day
			lcd.gotoxy(0,0);
			lcd.string_size("Dia",4);
			value = func()->triggerA(PINC.par.LL,13,rtc()->get_ss());
			if( value > minp1 && value < maxp1 ){
				dia ++;
				if(dia > 31)
					dia = 1;
				lcd.gotoxy(2,0);
				lcd.string_size(func()->print_v2("dia: %d", dia),7);
			}
			if( value > minp2 && value < maxp2 ){
				lcd.clear();
				circ1.putstr(&circ1.par, "Data\r\n");
				choice = 2;
			}
			if( value > minp3 ){
				lcd.clear();
				circ1.putstr(&circ1.par, "Data\r\n");
				choice = 2;
				rtc()->Day(dia);
			}
			break;

		default:
			break;
	}

}
/******************************************************************************/
/*** TIM9 Interrupt Definition ***/
void TIM1_BRK_TIM9_IRQHandler(void)
{
	if(tim9()->sr->uif()){ // status register (view interrupt flags)
		tim9()->sr->clear_uif();

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
	if(tim9()->sr->cc1if()){tim9()->sr->clear_cc1if();}
	//stm()->tim9_reg->SR &=  (uint32_t) ~1;
	//stm()->tim9_reg->SR &=  (uint32_t) ~2;
}
/******************************************************************************/
void USART1_IRQHandler(void)
{
	charcount++;
	if( stm()->usart1->sr->rxne() ){ // RXNE: Read data register not empty
		receive = stm()->usart1->get_dr();
		if(receive){
			circ2.put(&circ2.par, receive);

			if(receive == 13 ){
				circ2.getstr(&circ2.par, received);
				received[strlen(received)-1] = '\0'; //remove enter key [13]
			}
		}
	}
	if( stm()->usart1->sr->ore() ){ receive = usart1()->get_dr(); }

}
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

