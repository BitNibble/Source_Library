/*************************************************************************
	TIMER2
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
#include "atmega328timer2.h"

/*** File Variable ***/
TC2 setup_tc2;
static unsigned char timer2_state;

/*** File Header ***/
void TIMER_COUNTER2_compoutmodeA(unsigned char compoutmode);
void TIMER_COUNTER2_compoutmodeB(unsigned char compoutmode);
void TIMER_COUNTER2_compareA(unsigned char compare);
void TIMER_COUNTER2_compareB(unsigned char compare);
void TIMER_COUNTER2_start(unsigned int prescaler);
void TIMER_COUNTER2_stop(void);

/*** Procedure & Function ***/
TC2 tc2_enable(unsigned char wavegenmode, unsigned char interrupt)
//	PARAMETER SETTING
//	wavegen mode: Normal; PWM phase correct; Fast PWM; default-Normasl;
//	interrupt: off; overflow; output compare; both; default - non.
{
	timer2_state = 0;
	tc2_handle()->tccr2a &= ~((1 << WGM21) | (1 << WGM20));
	tc2_handle()->tccr2b &= ~(1<<WGM22);
	switch(wavegenmode){
		case 0: // Normal
		break;
		case 1: // PWM, Phase Correct
			tc2_handle()->tccr2a |=(1 << WGM20);
		break;
		case 2: // CTC
			tc2_handle()->tccr2a |= (1 << WGM21);
		break;
		case 3: // Fast PWM
			tc2_handle()->tccr2a |= (1 << WGM20) | (1 << WGM21);
		break;
		case 5: // PWM, Phase Correct
			tc2_handle()->tccr2a |= (1 << WGM20);
			tc2_handle()->tccr2b |= (1 << WGM22);
		break;
		case 7: // Fast PWM
			tc2_handle()->tccr2a |= (1 << WGM20) | (1 << WGM21);
			tc2_handle()->tccr2b |= (1 << WGM22);
		break;
		default: // Normal
		break;
	}
	tc_imask_handle()->timsk2 &= ~((1 << OCIE2B) | (1 << OCIE2A) | (1 << TOIE2));
	switch(interrupt){
		case 0: 
		break;
		case 1:
			tc_imask_handle()->timsk2 |= (1 << TOIE2);
			cpu_handle()->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 2:
			tc_imask_handle()->timsk2 |= (1 << OCIE2A);
			cpu_handle()->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 3:
			tc_imask_handle()->timsk2 |= (1 << TOIE2) | (1 << OCIE2A);
			cpu_handle()->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 4:
			tc_imask_handle()->timsk2 |= (1 << TOIE2) | (1 << OCIE2B);
			cpu_handle()->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 5:
			tc_imask_handle()->timsk2 |= (1 << OCIE2B) | (1 << OCIE2A);
			cpu_handle()->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 6:
			tc_imask_handle()->timsk2 |= (1 << OCIE2B) | (1 << OCIE2A) | (1 << TOIE2);
			cpu_handle()->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		default:
		break;
	}
	setup_tc2.compoutmodeA = TIMER_COUNTER2_compoutmodeA;
	setup_tc2.compoutmodeB = TIMER_COUNTER2_compoutmodeB;
	setup_tc2.compareA = TIMER_COUNTER2_compareA;
	setup_tc2.compareB = TIMER_COUNTER2_compareB;
	setup_tc2.start = TIMER_COUNTER2_start;
	setup_tc2.stop = TIMER_COUNTER2_stop;
	
	return setup_tc2;
}

TC2* tc2(void){ return &setup_tc2; }

void TIMER_COUNTER2_start(unsigned int prescaler)
//	PARAMETER SETTING
//	Frequency oscillator devision factor or prescaler.
//	prescaler: clk T0S /(No prescaling); clk T0S /8 (From prescaler); clk T0S /64 (From prescaler);
//	clk T0S /256 (From prescaler); clk T0S /1024 (From prescaler); External clock source on Tn pin. Clock on falling edge;
//	External clock source on Tn pin. Clock on rising edge; default - clk T 0 S /1024 (From prescaler).
{
	if(timer2_state == 0){ // one shot
		tc2_compare_handle()->ocr2a = 0XFF;
		tc2_handle()->tccr2b &= ~(7 << CS20); // No clock source. (Timer/Counter stopped)
		switch(prescaler){
			case 1: // clkI/O/(No prescaler)
				tc2_handle()->tccr2b |= (1 << CS20);
			break;
			case 8: // clkI/O/8 (From prescaler)
				tc2_handle()->tccr2b |= (1 << CS21);
			break;
			case 32: // clkI/O/32 (From prescaler)
				tc2_handle()->tccr2b |= (1 << CS21) | (1 << CS20);
			break;
			case 64: // clkI/O/64 (From prescaler)
				tc2_handle()->tccr2b |= (1 << CS22);
			break;
			case 128: // clkI/O/128 (From prescaler)
				tc2_handle()->tccr2b |= (1 << CS22) | (1 << CS20);
			break;
			case 256: // clkI/O/256 (From prescaler)
				tc2_handle()->tccr2b |= (1 << CS22) | (1 << CS21);
			break;
			case 1024: // clkI/O/1024 (From prescaler)
				tc2_handle()->tccr2b |= (7 << CS20);
			break;
			default: // clkI/O/1024 (From prescaler)
				tc2_handle()->tccr2b |= (7 << CS20);
			break;
		}
		timer2_state = 1;
	}	
}
void TIMER_COUNTER2_compoutmodeA(unsigned char compoutmode)
//	compoutmode: Normal port operation, OC2 disconnected; Toggle OC2 on compare match; 
//	Clear OC2 on compare match when up-counting. Set OC2 on compare match when downcounting. Clear OC2 on compare match;
//	Set OC2 on compare match when up-counting. Clear OC2 on compare match when downcounting. Set OC2 on compare match ;
//	default-Normal port operation, OC2 disconnected.
{
	tc2_handle()->tccr2a &= ~((1 << COM2A0) | (1 << COM2A1));
	switch(compoutmode){ // see table 53, 54, 55 in data sheet for more information
		case 0: // Normal port operation, OC2 disconnected.
		break;
		case 1: // Reserved
				// Toggle OC2 on compare match
			portb_handle()->ddr |= (1 << 3);
			tc2_handle()->tccr2a |= (1 << COM2A0);
		break;
		case 2: // Clear OC2 on compare match when up-counting. 
				// Set OC2 on compare
				// match when down counting.
				// Clear OC2 on compare match
			portb_handle()->ddr |= (1 << 3);
			tc2_handle()->tccr2a |= (1 << COM2A1);
		break;
		case 3: // Set OC2 on compare match when up-counting.
				// Clear OC2 on compare
				// match when down counting.
				// Set OC2 on compare match
			portb_handle()->ddr |= (1 << 3);
			tc2_handle()->tccr2a |= (1 << COM2A0) | (1 << COM2A1);
		break;
		default: // Normal port operation, OC2 disconnected.
		break;
	}
}
void TIMER_COUNTER2_compoutmodeB(unsigned char compoutmode)
//	compoutmode: Normal port operation, OC2 disconnected; Toggle OC2 on compare match; 
//	Clear OC2 on compare match when up-counting. Set OC2 on compare match when downcounting. Clear OC2 on compare match;
//	Set OC2 on compare match when up-counting. Clear OC2 on compare match when downcounting. Set OC2 on compare match ;
//	default-Normal port operation, OC2 disconnected.
{
	tc2_handle()->tccr2a &= ~((1 << COM2B0) | (1 << COM2B1));
	switch(compoutmode){ // see table 53, 54, 55 in data sheet for more information
		case 0: // Normal port operation, OC2 disconnected.
		break;
		case 1: // Reserved
				// Toggle OC2 on compare match
			portd_handle()->ddr |= (1 << 3);
			tc2_handle()->tccr2a |= (1 << COM2B0);
		break;
		case 2: // Clear OC2 on compare match when up-counting.
				// Set OC2 on compare
				// match when down counting.
				// Clear OC2 on compare match
			portd_handle()->ddr |= (1 << 3);
			tc2_handle()->tccr2a |= (1 << COM2B1);
		break;
		case 3: // Set OC2 on compare match when up-counting.
				// Clear OC2 on compare
				// match when down counting.
				// Set OC2 on compare match
			portd_handle()->ddr |= (1 << 3);
			tc2_handle()->tccr2a |= (1 << COM2B0) | (1 << COM2B1);
		break;
		default: // Normal port operation, OC2 disconnected.
		break;
	}
}
void TIMER_COUNTER2_compareA(unsigned char compare)
{
	tc2_compare_handle()->ocr2a = compare;
}
	void TIMER_COUNTER2_compareB(unsigned char compare)
{
	tc2_compare_handle()->ocr2b = compare;
}
void TIMER_COUNTER2_stop(void)
// stops timer by setting prescaler to zero
{
	tc2_handle()->tccr2b &= ~(7 << CS20); // No clock source. (Timer/Counter stopped)
	tc2_handle()->tcnt2 = 0X00;
	timer2_state = 0;
}

/*** EOF ***/

