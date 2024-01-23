/*************************************************************************
	TIMER0
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update: 01/01/2024
*************************************************************************/
/****** Comment:
	Very Stable
*************************************************************************/
/*** File library ***/
#include "atmega328mapping.h"
#include "atmega328timer0.h"

/*** File Constant & Macro ***/

/*** File Variable ***/
static TIMER_COUNTER0 setup_tc0;
static unsigned char timer0_state;

/*** File Header ***/
void TIMER_COUNTER0_compoutmodeA(unsigned char compoutmode);
void TIMER_COUNTER0_compoutmodeB(unsigned char compoutmode);
void TIMER_COUNTER0_compareA(unsigned char compare);
void TIMER_COUNTER0_compareB(unsigned char compare);
void TIMER_COUNTER0_start(unsigned int prescaler);
void TIMER_COUNTER0_stop(void);

/*** Procedure & Function ***/
TIMER_COUNTER0 tc0_enable(unsigned char wavegenmode, unsigned char interrupt)
//	PARAMETER SETTING
//	wavegen mode: Normal; PWM phase correct; Fast PWM; default-Normasl;
//	interrupt: off; overflow; output compare; both; default - non.
{
	timer0_state = 0;
	atmega328()->tc0_reg->tccr0a &= ~((1 << WGM01) | (1 << WGM00));
	atmega328()->tc0_reg->tccr0b &= ~(1 << WGM02);
	switch(wavegenmode){
		case 0: // Normal
		break;
		case 1: // PWM, Phase Correct, 8-bit
			atmega328()->tc0_reg->tccr0a |= (1 << WGM00);
		break;
		case 2: // PWM, Phase Correct, 9-bit
			atmega328()->tc0_reg->tccr0a |= (1 << WGM01);
		break;
		case 3: // Fast PWM
			atmega328()->tc0_reg->tccr0a |= (1 << WGM00) | (1 << WGM01);
		break;
		case 5: // PWM, Phase Correct
			atmega328()->tc0_reg->tccr0a |= (1 << WGM00);
			atmega328()->tc0_reg->tccr0b |= (1 << WGM02);
		break;
		case 7: // Fast PWM
			atmega328()->tc0_reg->tccr0a |= (1 << WGM00) | (1 << WGM01);
			atmega328()->tc0_reg->tccr0b |= (1 << WGM02);
		break;
		default: // Normal
		break;
	}
	atmega328()->tc0_imask->timsk0 &= ~((1 << OCIE0B) | (1 << OCIE0A) | (1 << TOIE0));
	switch(interrupt){
		case 0: 
		break;
		case 1:
			atmega328()->tc0_imask->timsk0 |= (1 << TOIE0);
			atmega328()->cpu_reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 2:
			atmega328()->tc0_imask->timsk0 |= (1 << OCIE0A);
			atmega328()->cpu_reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 3:
			atmega328()->tc0_imask->timsk0 |= (1 << OCIE0B);
			atmega328()->cpu_reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 4:
			atmega328()->tc0_imask->timsk0 |= (1 << TOIE0) | (1 << OCIE0A);
			atmega328()->cpu_reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 5:
			atmega328()->tc0_imask->timsk0 |= (1 << TOIE0) | (1 << OCIE0B);
			atmega328()->cpu_reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 6:
			atmega328()->tc0_imask->timsk0 |= (1 << TOIE0) | (1 << OCIE0A) | (1 << OCIE0B);
			atmega328()->cpu_reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 7:
			atmega328()->tc0_imask->timsk0 |= (1 << OCIE0A) | (1 << OCIE0B);
			atmega328()->cpu_reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		default:
		break;
	}
	setup_tc0.compoutmodeA = TIMER_COUNTER0_compoutmodeA;
	setup_tc0.compoutmodeB = TIMER_COUNTER0_compoutmodeB;
	setup_tc0.compareA = TIMER_COUNTER0_compareA;
	setup_tc0.compareB = TIMER_COUNTER0_compareB;
	setup_tc0.start = TIMER_COUNTER0_start;
	setup_tc0.stop = TIMER_COUNTER0_stop;

	return setup_tc0;
}

TIMER_COUNTER0* tc0(void){ return &setup_tc0; };

void TIMER_COUNTER0_start(unsigned int prescaler)
//	PARAMETER SETTING
//	Frequency oscillator devision factor or prescaler.
//	prescaler: clk T0S /(No prescaling); clk T0S /8 (From prescaler); clk T0S /32 (From prescaler);
//	clk T0S /64 (From prescaler); clk T0S /128 (From prescaler); clk T 0 S /256 (From prescaler);
//	clk T 0 S /1024 (From prescaler); default - clk T 0 S /1024 (From prescaler).
{
	if(timer0_state == 0){ // one shot
		atmega328()->tc0_comp->ocr0a = 0XFF;
		atmega328()->tc0_reg->tccr0b &= ~(7 << CS00); // No clock source. (Timer/Counter stopped)
		switch(prescaler){
			case 1: // clk T0S /(No prescaler)
				atmega328()->tc0_reg->tccr0b |= (1 << CS00);
			break;
			case 8: // clk T0S /8 (From prescaler)
				atmega328()->tc0_reg->tccr0b |= (1 << CS01);
			break;
			case 64: // clk T0S /64 (From prescaler)
				atmega328()->tc0_reg->tccr0b |= (3 << CS00);
			break;
			case 256: // clk T 0 S /256 (From prescaler)
				atmega328()->tc0_reg->tccr0b |= (4 << CS00);
			break;
			case 1024: // clk T 0 S /1024 (From prescaler)
				atmega328()->tc0_reg->tccr0b |= (5 << CS00);
			break;
			case 3: // External clock source on T0 pin. Clock on falling edge.
				atmega328()->tc0_reg->tccr0b |= (6 << CS00);
			break;
			case 5: // External clock source on T0 pin. Clock on rising edge.
				atmega328()->tc0_reg->tccr0b |= (7 << CS00);
			break;
			default: // clk T 0 S /1024 (From prescaler)
				atmega328()->tc0_reg->tccr0b |= (5 << CS00);
			break;
		}
		timer0_state = 1;
	}	
}
void TIMER_COUNTER0_compoutmodeA(unsigned char compoutmode)
//	compoutmode: Normal port operation, OC0 disconnected; Toggle OC0 on compare match; 
//	Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting. Clear OC0 on compare match;
//	Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting. Set OC0 on compare match ;
//	default-Normal port operation, OC0 disconnected.
{
	atmega328()->tc0_reg->tccr0a &= ~((1 << COM0A0) | (1 << COM0A1));
	switch(compoutmode){
		case 0: // Normal port operation, OC0 disconnected.
		break;
		case 1: // Reserved
				// Toggle OC0 on compare match
			atmega328()->portd_reg->ddr |= (1 << 6);
			atmega328()->tc0_reg->tccr0a |= (1 << COM0A0);
			
		break;
		case 2: // Clear OC0 on compare match when up-counting.
				// Set OC0 on compare
				// match when down counting.
				// Clear OC0 on compare match
			atmega328()->portd_reg->ddr |= (1 << 6);
			atmega328()->tc0_reg->tccr0a |= (1 << COM0A1);
		break;
		case 3: // Set OC0 on compare match when up-counting.
				// Clear OC0 on compare
				// match when down counting.
				// Set OC0 on compare match
			atmega328()->portd_reg->ddr |= (1 << 6);
			atmega328()->tc0_reg->tccr0a |= (1 << COM0A0) | (1 << COM0A1);
		break;
		default: // Normal port operation, OC0 disconnected.
		break;
	}
}
void TIMER_COUNTER0_compoutmodeB(unsigned char compoutmode)
//	compoutmode: Normal port operation, OC0 disconnected; Toggle OC0 on compare match; 
//	Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting. Clear OC0 on compare match;
//	Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting. Set OC0 on compare match ;
//	default-Normal port operation, OC0 disconnected.
{
	atmega328()->tc0_reg->tccr0a &= ~((1 << COM0B0) | (1 << COM0B1));
	switch(compoutmode){ // see table 53, 54, 55 in data sheet for more information
		case 0: // Normal port operation, OC0 disconnected.
		break;
		case 1: // Reserved
				// Toggle OC0 on compare match
			atmega328()->portd_reg->ddr |= (1 << 5);
			atmega328()->tc0_reg->tccr0a |= (1 << COM0B0);
		break;
		case 2: // Clear OC0 on compare match when up-counting.
				// Set OC0 on compare
				// match when down counting.
				// Clear OC0 on compare match
			atmega328()->portd_reg->ddr |= (1 << 5);
			atmega328()->tc0_reg->tccr0a |= (1 << COM0B1);
		break;
		case 3: // Set OC0 on compare match when up-counting.
				// Clear OC0 on compare
				// match when down counting.
				// Set OC0 on compare match
			atmega328()->portd_reg->ddr |= (1 << 5);
			atmega328()->tc0_reg->tccr0a |= (1 << COM0B0) | (1 << COM0B1);
		break;
		default: // Normal port operation, OC0 disconnected.
		break;
	}
}
void TIMER_COUNTER0_compareA(unsigned char compare)
{
	atmega328()->tc0_comp->ocr0a = compare;
}
void TIMER_COUNTER0_compareB(unsigned char compare)
{
	atmega328()->tc0_comp->ocr0b = compare;
}
void TIMER_COUNTER0_stop(void)
// stops timer by setting prescaler to zero
{
	atmega328()->tc0_reg->tccr0b &= ~(7 << CS00); // No clock source. (Timer/Counter stopped)
	atmega328()->tc0_reg->tcnt0 = 0X00;
	timer0_state = 0;
}

/***EOF***/

