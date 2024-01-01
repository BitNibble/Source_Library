/*************************************************************************
	TIMER
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update: 29/12/2023
Comment:
	Very Stable
*************************************************************************/
/*** File library ***/
#include "atmega328mapping.h"
#include "atmega328timer.h"

/*** File Constant & Macro ***/
#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
#else
	#error "Not Atmega 328"
#endif

/*** File Variable ***/
static unsigned char timer0_state;
static unsigned char timer1_state;
static unsigned char timer2_state;

/*** File Header ***/
void TIMER_COUNTER0_compoutmodeA(unsigned char compoutmode);
void TIMER_COUNTER0_compoutmodeB(unsigned char compoutmode);
void TIMER_COUNTER0_compareA(unsigned char compare);
void TIMER_COUNTER0_compareB(unsigned char compare);
void TIMER_COUNTER0_start(unsigned int prescaler);
void TIMER_COUNTER0_stop(void);

void TIMER_COUNTER1_compoutmodeA(unsigned char compoutmode);
void TIMER_COUNTER1_compoutmodeB(unsigned char compoutmode);
void TIMER_COUNTER1_compareA(uint16_t compare);
void TIMER_COUNTER1_compareB(uint16_t compare);
void TIMER_COUNTER1_start(unsigned int prescaler);
void TIMER_COUNTER1_stop(void);

void TIMER_COUNTER2_compoutmodeA(unsigned char compoutmode);
void TIMER_COUNTER2_compoutmodeB(unsigned char compoutmode);
void TIMER_COUNTER2_compareA(unsigned char compare);
void TIMER_COUNTER2_compareB(unsigned char compare);
void TIMER_COUNTER2_start(unsigned int prescaler);
void TIMER_COUNTER2_stop(void);

/*** Procedure & Function ***/
TIMER_COUNTER0 TIMER_COUNTER0enable(unsigned char wavegenmode, unsigned char interrupt)
//	PARAMETER SETTING
//	wavegen mode: Normal; PWM phase correct; Fast PWM; default-Normasl;
//	interrupt: off; overflow; output compare; both; default - non.
{
	ATMEGA328enable();
	TIMER_COUNTER0 tc0;
	
	timer0_state = 0;
	atmega328.tc0.reg->tccr0a &= ~((1 << WGM01) | (1 << WGM00));
	atmega328.tc0.reg->tccr0b &= ~(1 << WGM02);
	switch(wavegenmode){
		case 0: // Normal
		break;
		case 1: // PWM, Phase Correct, 8-bit
			atmega328.tc0.reg->tccr0a |= (1 << WGM00);
		break;
		case 2: // PWM, Phase Correct, 9-bit
			atmega328.tc0.reg->tccr0a |= (1 << WGM01);
		break;
		case 3: // Fast PWM
			atmega328.tc0.reg->tccr0a |= (1 << WGM00) | (1 << WGM01);
		break;
		case 5: // PWM, Phase Correct
			atmega328.tc0.reg->tccr0a |= (1 << WGM00);
			atmega328.tc0.reg->tccr0b |= (1 << WGM02);
		break;
		case 7: // Fast PWM
			atmega328.tc0.reg->tccr0a |= (1 << WGM00) | (1 << WGM01);
			atmega328.tc0.reg->tccr0b |= (1 << WGM02);
		break;
		default: // Normal
		break;
	}
	atmega328.tc0.imask->timsk0 &= ~((1 << OCIE0B) | (1 << OCIE0A) | (1 << TOIE0));
	switch(interrupt){
		case 0: 
		break;
		case 1:
			atmega328.tc0.imask->timsk0 |= (1 << TOIE0);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 2:
			atmega328.tc0.imask->timsk0 |= (1 << OCIE0A);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 3:
			atmega328.tc0.imask->timsk0 |= (1 << OCIE0B);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 4:
			atmega328.tc0.imask->timsk0 |= (1 << TOIE0) | (1 << OCIE0A);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 5:
			atmega328.tc0.imask->timsk0 |= (1 << TOIE0) | (1 << OCIE0B);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 6:
			atmega328.tc0.imask->timsk0 |= (1 << TOIE0) | (1 << OCIE0A) | (1 << OCIE0B);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 7:
			atmega328.tc0.imask->timsk0 |= (1 << OCIE0A) | (1 << OCIE0B);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		default:
		break;
	}
	tc0.compoutmodeA = TIMER_COUNTER0_compoutmodeA;
	tc0.compoutmodeB = TIMER_COUNTER0_compoutmodeB;
	tc0.compareA = TIMER_COUNTER0_compareA;
	tc0.compareB = TIMER_COUNTER0_compareB;
	tc0.start = TIMER_COUNTER0_start;
	tc0.stop = TIMER_COUNTER0_stop;
	
#ifdef _TIMER_MODULE_
	//atmega328.tc0.run = timer0;
#endif

	return tc0;
}
void TIMER_COUNTER0_start(unsigned int prescaler)
//	PARAMETER SETTING
//	Frequency oscillator devision factor or prescaler.
//	prescaler: clk T0S /(No prescaling); clk T0S /8 (From prescaler); clk T0S /32 (From prescaler);
//	clk T0S /64 (From prescaler); clk T0S /128 (From prescaler); clk T 0 S /256 (From prescaler);
//	clk T 0 S /1024 (From prescaler); default - clk T 0 S /1024 (From prescaler).
{
	if(timer0_state == 0){ // one shot
		atmega328.tc0.comp->ocr0a = 0XFF;
		atmega328.tc0.reg->tccr0b &= ~(7 << CS00); // No clock source. (Timer/Counter stopped)
		switch(prescaler){
			case 1: // clk T0S /(No prescaler)
				atmega328.tc0.reg->tccr0b |= (1 << CS00);
			break;
			case 8: // clk T0S /8 (From prescaler)
				atmega328.tc0.reg->tccr0b |= (1 << CS01);
			break;
			case 64: // clk T0S /64 (From prescaler)
				atmega328.tc0.reg->tccr0b |= (3 << CS00);
			break;
			case 256: // clk T 0 S /256 (From prescaler)
				atmega328.tc0.reg->tccr0b |= (4 << CS00);
			break;
			case 1024: // clk T 0 S /1024 (From prescaler)
				atmega328.tc0.reg->tccr0b |= (5 << CS00);
			break;
			case 3: // External clock source on T0 pin. Clock on falling edge.
				atmega328.tc0.reg->tccr0b |= (6 << CS00);
			break;
			case 5: // External clock source on T0 pin. Clock on rising edge.
				atmega328.tc0.reg->tccr0b |= (7 << CS00);
			break;
			default: // clk T 0 S /1024 (From prescaler)
				atmega328.tc0.reg->tccr0b |= (5 << CS00);
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
	atmega328.tc0.reg->tccr0a &= ~((1 << COM0A0) | (1 << COM0A1));
	switch(compoutmode){
		case 0: // Normal port operation, OC0 disconnected.
		break;
		case 1: // Reserved
				// Toggle OC0 on compare match
			atmega328.portd.reg->ddr |= (1 << 6);
			atmega328.tc0.reg->tccr0a |= (1 << COM0A0);
			
		break;
		case 2: // Clear OC0 on compare match when up-counting.
				// Set OC0 on compare
				// match when down counting.
				// Clear OC0 on compare match
			atmega328.portd.reg->ddr |= (1 << 6);
			atmega328.tc0.reg->tccr0a |= (1 << COM0A1);
		break;
		case 3: // Set OC0 on compare match when up-counting.
				// Clear OC0 on compare
				// match when down counting.
				// Set OC0 on compare match
			atmega328.portd.reg->ddr |= (1 << 6);
			atmega328.tc0.reg->tccr0a |= (1 << COM0A0) | (1 << COM0A1);
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
	atmega328.tc0.reg->tccr0a &= ~((1 << COM0B0) | (1 << COM0B1));
	switch(compoutmode){ // see table 53, 54, 55 in data sheet for more information
		case 0: // Normal port operation, OC0 disconnected.
		break;
		case 1: // Reserved
				// Toggle OC0 on compare match
			atmega328.portd.reg->ddr |= (1 << 5);
			atmega328.tc0.reg->tccr0a |= (1 << COM0B0);
		break;
		case 2: // Clear OC0 on compare match when up-counting.
				// Set OC0 on compare
				// match when down counting.
				// Clear OC0 on compare match
			atmega328.portd.reg->ddr |= (1 << 5);
			atmega328.tc0.reg->tccr0a |= (1 << COM0B1);
		break;
		case 3: // Set OC0 on compare match when up-counting.
				// Clear OC0 on compare
				// match when down counting.
				// Set OC0 on compare match
			atmega328.portd.reg->ddr |= (1 << 5);
			atmega328.tc0.reg->tccr0a |= (1 << COM0B0) | (1 << COM0B1);
		break;
		default: // Normal port operation, OC0 disconnected.
		break;
	}
}
void TIMER_COUNTER0_compareA(unsigned char compare)
{
	atmega328.tc0.comp->ocr0a = compare;
}
void TIMER_COUNTER0_compareB(unsigned char compare)
{
	atmega328.tc0.comp->ocr0b = compare;
}
void TIMER_COUNTER0_stop(void)
// stops timer by setting prescaler to zero
{
	atmega328.tc0.reg->tccr0b &= ~(7 << CS00); // No clock source. (Timer/Counter stopped)
	atmega328.tc0.reg->tcnt0 = 0X00;
	timer0_state = 0;
}

TIMER_COUNTER1 TIMER_COUNTER1enable(unsigned char wavegenmode, unsigned char interrupt)
//	PARAMETER SETTING
//	wavegen mode: Normal; PWM, Phase Correct, 8-bit; PWM, Phase Correct, 9-bit; PWM, Phase Correct, 10-bit;
//	CTC; Fast PWM, 8-bit; Fast PWM, 9-bit; Fast PWM, 10-bit; PWM, Phase and Frequency Correct; PWM, Phase and Frequency Correct;
//	PWM, Phase Correct; PWM, Phase Correct; CTC; (Reserved); Fast PWM; Fast PWM.
//	interrupt: off; overflow; output compare; both; default - non.
//	for more information read data sheet.
{
	TIMER_COUNTER1 tc1;
	ATMEGA328enable();
	
	timer1_state = 0;
	atmega328.tc1.reg->tccr1a &= ~((1 << WGM11) | (1 << WGM10));
	atmega328.tc1.reg->tccr1b &= ~((1 << WGM13) | (1 << WGM12));
	switch(wavegenmode){
		case 0: // Normal
		break;
		case 1: // PWM, Phase Correct, 8-bit
			atmega328.tc1.reg->tccr1a |= (1 << WGM10);
		break;
		case 2:	// PWM, Phase Correct, 9-bit
			atmega328.tc1.reg->tccr1a |= (1 << WGM11);
		break;
		case 3:	// PWM, Phase Correct, 10-bit
			atmega328.tc1.reg->tccr1a |= (1 << WGM11) | (1 << WGM10);
		break;
		case 4:	// CTC
			atmega328.tc1.reg->tccr1b |= (1 << WGM12);
		break;
		case 5:	// Fast PWM, 8-bit
			atmega328.tc1.reg->tccr1a |= (1 << WGM10);
			atmega328.tc1.reg->tccr1b |= (1 << WGM12);
		break;
		case 6:	// Fast PWM, 9-bit
			atmega328.tc1.reg->tccr1a |= (1 << WGM11);
			atmega328.tc1.reg->tccr1b |= (1 << WGM12);
		break;
		case 7:	// Fast PWM, 10-bit
			atmega328.tc1.reg->tccr1a |= (1 << WGM11) | (1 << WGM10);
			atmega328.tc1.reg->tccr1b |= (1 << WGM12);
		break;
		case 8:	// PWM, Phase and Frequency Correct
			atmega328.tc1.reg->tccr1b |= (1 << WGM13);
		break;
		case 9:	// PWM, Phase and Frequency Correct
			atmega328.tc1.reg->tccr1a |= (1 << WGM10);
			atmega328.tc1.reg->tccr1b |= (1 << WGM13);
		break;
		case 10: // PWM, Phase Correct
			atmega328.tc1.reg->tccr1a |= (1 << WGM11);
			atmega328.tc1.reg->tccr1b |= (1 << WGM13);
		break;
		case 11: // PWM, Phase Correct
			atmega328.tc1.reg->tccr1a |= (1 << WGM11) | (1 << WGM10);
			atmega328.tc1.reg->tccr1b |= (1 << WGM13);
		break;
		case 12: // CTC
			atmega328.tc1.reg->tccr1b |= (1 << WGM13) | (1 << WGM12);
		break;
		case 13: // (Reserved)
			atmega328.tc1.reg->tccr1a |= (1 << WGM10);
			atmega328.tc1.reg->tccr1b |= (1 << WGM13) | (1 << WGM12);
		break;
		case 14: // Fast PWM
			atmega328.tc1.reg->tccr1a |= (1 << WGM11);
			atmega328.tc1.reg->tccr1b |= (1 << WGM13) | (1 << WGM12);
		break;
		case 15: // Fast PWM
			atmega328.tc1.reg->tccr1a |= (1 << WGM11) | (1 << WGM10);
			atmega328.tc1.reg->tccr1b |= (1 << WGM13) | (1 << WGM12);
		break;
		default: // Normal
		break;
	}
	atmega328.tc1.reg->tccr1a &= ~((3 << COM1A0) | (3 << COM1B0));
	atmega328.tc1.imask->timsk1 &= ~((1 << ICIE1)  | (1 << OCIE1B) | (1 << OCIE1A) | (1 << TOIE1));
	switch(interrupt){
		case 0:
		break;
		case 1:
			atmega328.tc1.imask->timsk1 |= (1 << TOIE1);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 2:
			atmega328.tc1.imask->timsk1 |= (1 << OCIE1A);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 3:
			atmega328.tc1.imask->timsk1 |= (1 << OCIE1B);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 4:
			atmega328.tc1.imask->timsk1 |= (1 << ICIE1);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 5:
			atmega328.tc1.imask->timsk1 |= (1 << OCIE1A) | (1 << OCIE1B);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 6:
			atmega328.tc1.imask->timsk1 |= (1 << OCIE1A) | (1 << TOIE1);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 7:
			atmega328.tc1.imask->timsk1 |= (1 << OCIE1B) | (1 << TOIE1);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 8:
			atmega328.tc1.imask->timsk1 |= (1 << ICIE1) | (1 << TOIE1);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 9:
			atmega328.tc1.imask->timsk1 |= (1 << OCIE1A) | (1 << OCIE1B) | (1 << TOIE1);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 10:
			atmega328.tc1.imask->timsk1 |= (1 << ICIE1) | (1 << OCIE1A) | (1 << OCIE1B) | (1 << TOIE1);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 11:
			atmega328.tc1.imask->timsk1 |= (1 << OCIE1A) | (1 << OCIE1B);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		default:
		break;
	}
	//
	tc1.compoutmodeA = TIMER_COUNTER1_compoutmodeA;
	tc1.compoutmodeB = TIMER_COUNTER1_compoutmodeB;
	tc1.compareA = TIMER_COUNTER1_compareA;
	tc1.compareB = TIMER_COUNTER1_compareB;
	tc1.start = TIMER_COUNTER1_start;
	tc1.stop = TIMER_COUNTER1_stop;
	
#ifdef _TIMER_MODULE_
	//atmega328.tc1.run = timer1;
#endif

	return tc1;
}
void TIMER_COUNTER1_start(unsigned int prescaler)
//	PARAMETER SETTING
//	Frequency oscillator devision factor or prescaler.
//	prescaler: clk T0S /(No prescaling); clk T0S /8 (From prescaler); clk T0S /64 (From prescaler);
//	clk T0S /256 (From prescaler); clk T0S /1024 (From prescaler); External clock source on Tn pin. Clock on falling edge;
//	External clock source on Tn pin. Clock on rising edge; default - clk T 0 S /1024 (From prescaler).
{
	if(timer1_state == 0){ // one shot
		TIMER_COUNTER1_compareA(0xFFFF); // preset as max
		TIMER_COUNTER1_compareB(0xFFFF); // preset as max
		atmega328.tc1.reg->tccr1b &= ~(7 << CS10); // No clock source. (Timer/Counter stopped)
		switch(prescaler){
			case 1: // clkI/O/1 (No prescaler)
				atmega328.tc1.reg->tccr1b |= (1 << CS10);
			break;
			case 8: // clkI/O/8 (From prescaler)
				atmega328.tc1.reg->tccr1b |= (1 << CS11);
			break;
			case 64: // clkI/O/64 (From prescaler)
				atmega328.tc1.reg->tccr1b |= (3 << CS10);
			break;
			case 256: // clkI/O/256 (From prescaler)
				atmega328.tc1.reg->tccr1b |= (1 << CS12);
			break;
			case 1024: // clkI/O/1024 (From prescaler)
				atmega328.tc1.reg->tccr1b |= (5 << CS10);
			break;
			case 3: // External clock source on Tn pin. Clock on falling edge
				atmega328.tc1.reg->tccr1b |= (6 << CS10);
			break;
			case 5: // External clock source on Tn pin. Clock on rising edge
				atmega328.tc1.reg->tccr1b |= (7 << CS10);
			break;
			default: // clkI/O/1024 (From prescaler)
				atmega328.tc1.reg->tccr1b |= (5 << CS10);
			break;
		}
		timer1_state = 1;
	}	
}
void TIMER_COUNTER1_compoutmodeA(unsigned char compoutmode)
{
	atmega328.tc1.reg->tccr1a &= ~(3 << COM1A0);
	switch(compoutmode){ // see table 53, 54, 55 in data sheet for more information
		case 0: // Normal port operation, OC1 disconnected.
		break;
		case 1: // Reserved
				// Toggle OC1 on compare match
			atmega328.portb.reg->ddr |= (1 << 1);
			atmega328.tc1.reg->tccr1a |= (1 << COM1A0);
		break;
		case 2: // Clear OC1 on compare match when up-counting.
				// Set OC1 on compare
				// match when down counting.
				// Clear OC1 on compare match
			atmega328.portb.reg->ddr |= (1 << 1);
			atmega328.tc1.reg->tccr1a |= (1 << COM1A1);
		break;
		case 3: // Set OC1 on compare match when up-counting.
				// Clear OC1 on compare
				// match when down counting.
				// Set OC1 on compare match
			atmega328.portb.reg->ddr |= (1 << 1);
			atmega328.tc1.reg->tccr1a |= (1 << COM1A0) | (1 << COM1A1);
		break;
		default: // Normal port operation, OC1 disconnected.
		break;
	}
}
void TIMER_COUNTER1_compoutmodeB(unsigned char compoutmode)
{
	atmega328.tc1.reg->tccr1a &= ~(3 << COM1B0);
	switch(compoutmode){ // see table 53, 54, 55 in data sheet for more information
		case 0: // Normal port operation, OC1 disconnected.
		break;
		case 1: // Reserved
				// Toggle OC1 on compare match
			atmega328.portb.reg->ddr |= (1 << 2);
			atmega328.tc1.reg->tccr1a |= (1 << COM1B0);
		break;
		case 2: // Clear OC1 on compare match when up-counting.
				// Set OC1 on compare
				// match when down counting.
				// Clear OC1 on compare match
			atmega328.portb.reg->ddr |= (1 << 2);
			atmega328.tc1.reg->tccr1a |= (1 << COM1B1);
		break;
		case 3: // Set OC1 on compare match when up-counting.
				// Clear OC1 on compare
				// match when down counting.
				// Set OC1 on compare match
			atmega328.portb.reg->ddr |= (1 << 2);
			atmega328.tc1.reg->tccr1a |= (1 << COM1B0) | (1 << COM1B1);
		break;
		default: // Normal port operation, OC1 disconnected.
		break;
	}
}
void TIMER_COUNTER1_compareA(uint16_t compare)
{
	atmega328.tc1.comp->ocr1a = atmega328.writehlbyte(compare);
}
void TIMER_COUNTER1_compareB(uint16_t compare)
{
	atmega328.tc1.comp->ocr1b = atmega328.writehlbyte(compare);
}
void TIMER_COUNTER1_stop(void)
// stops timer by setting prescaler to zero
{
	atmega328.tc1.reg->tccr1b &= ~(7 << CS10); // No clock source. (Timer/Counter stopped)
	atmega328.tc1.reg->tcnt1 = atmega328.writehlbyte(0X0000);
	timer1_state = 0;
}

TIMER_COUNTER2 TIMER_COUNTER2enable(unsigned char wavegenmode, unsigned char interrupt)
//	PARAMETER SETTING
//	wavegen mode: Normal; PWM phase correct; Fast PWM; default-Normasl;
//	interrupt: off; overflow; output compare; both; default - non.
{
	TIMER_COUNTER2 tc2;
	ATMEGA328enable();
	
	timer2_state = 0;
	atmega328.tc2.reg->tccr2a &= ~((1 << WGM21) | (1 << WGM20));
	atmega328.tc2.reg->tccr2b &= ~(1<<WGM22);
	switch(wavegenmode){
		case 0: // Normal
		break;
		case 1: // PWM, Phase Correct
			atmega328.tc2.reg->tccr2a |=(1 << WGM20);
		break;
		case 2: // CTC
			atmega328.tc2.reg->tccr2a |= (1 << WGM21);
		break;
		case 3: // Fast PWM
			atmega328.tc2.reg->tccr2a |= (1 << WGM20) | (1 << WGM21);
		break;
		case 5: // PWM, Phase Correct
			atmega328.tc2.reg->tccr2a |= (1 << WGM20);
			atmega328.tc2.reg->tccr2b |= (1 << WGM22);
		break;
		case 7: // Fast PWM
			atmega328.tc2.reg->tccr2a |= (1 << WGM20) | (1 << WGM21);
			atmega328.tc2.reg->tccr2b |= (1 << WGM22);
		break;
		default: // Normal
		break;
	}
	atmega328.tc2.imask->timsk2 &= ~((1 << OCIE2B) | (1 << OCIE2A) | (1 << TOIE2));
	switch(interrupt){
		case 0: 
		break;
		case 1:
			atmega328.tc2.imask->timsk2 |= (1 << TOIE2);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 2:
			atmega328.tc2.imask->timsk2 |= (1 << OCIE2A);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 3:
			atmega328.tc2.imask->timsk2 |= (1 << TOIE2) | (1 << OCIE2A);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 4:
			atmega328.tc2.imask->timsk2 |= (1 << TOIE2) | (1 << OCIE2B);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 5:
			atmega328.tc2.imask->timsk2 |= (1 << OCIE2B) | (1 << OCIE2A);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		case 6:
			atmega328.tc2.imask->timsk2 |= (1 << OCIE2B) | (1 << OCIE2A) | (1 << TOIE2);
			atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
		break;
		default:
		break;
	}
	tc2.compoutmodeA = TIMER_COUNTER2_compoutmodeA;
	tc2.compoutmodeB = TIMER_COUNTER2_compoutmodeB;
	tc2.compareA = TIMER_COUNTER2_compareA;
	tc2.compareB = TIMER_COUNTER2_compareB;
	tc2.start = TIMER_COUNTER2_start;
	tc2.stop = TIMER_COUNTER2_stop;
	
#ifdef _TIMER_MODULE_
	//atmega328.tc2.run = timer2;
#endif

	return tc2;
}
void TIMER_COUNTER2_start(unsigned int prescaler)
//	PARAMETER SETTING
//	Frequency oscillator devision factor or prescaler.
//	prescaler: clk T0S /(No prescaling); clk T0S /8 (From prescaler); clk T0S /64 (From prescaler);
//	clk T0S /256 (From prescaler); clk T0S /1024 (From prescaler); External clock source on Tn pin. Clock on falling edge;
//	External clock source on Tn pin. Clock on rising edge; default - clk T 0 S /1024 (From prescaler).
{
	if(timer2_state == 0){ // one shot
		atmega328.tc2.comp->ocr2a = 0XFF;
		atmega328.tc2.reg->tccr2b &= ~(7 << CS20); // No clock source. (Timer/Counter stopped)
		switch(prescaler){
			case 1: // clkI/O/(No prescaler)
				atmega328.tc2.reg->tccr2b |= (1 << CS20);
			break;
			case 8: // clkI/O/8 (From prescaler)
				atmega328.tc2.reg->tccr2b |= (1 << CS21);
			break;
			case 32: // clkI/O/32 (From prescaler)
				atmega328.tc2.reg->tccr2b |= (1 << CS21) | (1 << CS20);
			break;
			case 64: // clkI/O/64 (From prescaler)
				atmega328.tc2.reg->tccr2b |= (1 << CS22);
			break;
			case 128: // clkI/O/128 (From prescaler)
				atmega328.tc2.reg->tccr2b |= (1 << CS22) | (1 << CS20);
			break;
			case 256: // clkI/O/256 (From prescaler)
				atmega328.tc2.reg->tccr2b |= (1 << CS22) | (1 << CS21);
			break;
			case 1024: // clkI/O/1024 (From prescaler)
				atmega328.tc2.reg->tccr2b |= (7 << CS20);
			break;
			default: // clkI/O/1024 (From prescaler)
				atmega328.tc2.reg->tccr2b |= (7 << CS20);
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
	atmega328.tc2.reg->tccr2a &= ~((1 << COM2A0) | (1 << COM2A1));
	switch(compoutmode){ // see table 53, 54, 55 in data sheet for more information
		case 0: // Normal port operation, OC2 disconnected.
		break;
		case 1: // Reserved
				// Toggle OC2 on compare match
			atmega328.portb.reg->ddr |= (1 << 3);
			atmega328.tc2.reg->tccr2a |= (1 << COM2A0);
		break;
		case 2: // Clear OC2 on compare match when up-counting. 
				// Set OC2 on compare
				// match when down counting.
				// Clear OC2 on compare match
			atmega328.portb.reg->ddr |= (1 << 3);
			atmega328.tc2.reg->tccr2a |= (1 << COM2A1);
		break;
		case 3: // Set OC2 on compare match when up-counting.
				// Clear OC2 on compare
				// match when down counting.
				// Set OC2 on compare match
			atmega328.portb.reg->ddr |= (1 << 3);
			atmega328.tc2.reg->tccr2a |= (1 << COM2A0) | (1 << COM2A1);
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
	atmega328.tc2.reg->tccr2a &= ~((1 << COM2B0) | (1 << COM2B1));
	switch(compoutmode){ // see table 53, 54, 55 in data sheet for more information
		case 0: // Normal port operation, OC2 disconnected.
		break;
		case 1: // Reserved
				// Toggle OC2 on compare match
			atmega328.portd.reg->ddr |= (1 << 3);
			atmega328.tc2.reg->tccr2a |= (1 << COM2B0);
		break;
		case 2: // Clear OC2 on compare match when up-counting.
				// Set OC2 on compare
				// match when down counting.
				// Clear OC2 on compare match
			atmega328.portd.reg->ddr |= (1 << 3);
			atmega328.tc2.reg->tccr2a |= (1 << COM2B1);
		break;
		case 3: // Set OC2 on compare match when up-counting.
				// Clear OC2 on compare
				// match when down counting.
				// Set OC2 on compare match
			atmega328.portd.reg->ddr |= (1 << 3);
			atmega328.tc2.reg->tccr2a |= (1 << COM2B0) | (1 << COM2B1);
		break;
		default: // Normal port operation, OC2 disconnected.
		break;
	}
}
void TIMER_COUNTER2_compareA(unsigned char compare)
{
	atmega328.tc2.comp->ocr2a = compare;
}
	void TIMER_COUNTER2_compareB(unsigned char compare)
{
	atmega328.tc2.comp->ocr2b = compare;
}
void TIMER_COUNTER2_stop(void)
// stops timer by setting prescaler to zero
{
	atmega328.tc2.reg->tccr2b &= ~(7 << CS20); // No clock source. (Timer/Counter stopped)
	atmega328.tc2.reg->tcnt2 = 0X00;
	timer2_state = 0;
}

/***EOF***/


// ISR(TIMER2_COMPA_vect){}
// ISR(TIMER2_COMPB_vect){}
// ISR(TIMER2_OVF_vect){}
// ISR(TIMER1_CAPT_vect){}
// ISR(TIMER1_COMPA_vect){}
// ISR(TIMER1_COMPB_vect){}
// ISR(TIMER1_COMPC_vect){}
// ISR(TIMER1_OVF_vect){}
// ISR(TIMER0_COMPA_vect){}
// ISR(TIMER0_COMPB_vect){}
// ISR(TIMER0_OVF_vect){}

