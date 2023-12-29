/*************************************************************************
	ATMEGA128TIMER
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Update: 29/12/2023
Comment:
	Stable
*************************************************************************/
/*** File Library ***/
#include "atmega128mapping.h"
#include "atmega128timer.h"

/*** File Constant & Macro ***/
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
	#define ATMEGA_128_TIMER_COUNTER
#else
	#error "Not Atmega 128"
#endif

/*** File Variable ***/
uint8_t timer0_state;
uint8_t timer1_state;
uint8_t timer2_state;
uint8_t timer3_state;

/*** File Header ***/
void TIMER_COUNTER0_compoutmode(unsigned char compoutmode);
void TIMER_COUNTER0_compoutmodeA(unsigned char compoutmode);
void TIMER_COUNTER0_compoutmodeB(unsigned char compoutmode);
void TIMER_COUNTER0_compare(unsigned char compare);
void TIMER_COUNTER0_compareA(unsigned char compare);
void TIMER_COUNTER0_compareB(unsigned char compare);
uint8_t TIMER_COUNTER0_start(unsigned int prescaler);
uint8_t TIMER_COUNTER0_stop(void);

void TIMER_COUNTER1_compoutmodeA(unsigned char compoutmode);
void TIMER_COUNTER1_compoutmodeB(unsigned char compoutmode);
void TIMER_COUNTER1_compoutmodeC(unsigned char compoutmode);
void TIMER_COUNTER1_compareA(uint16_t compare);
void TIMER_COUNTER1_compareB(uint16_t compare);
void TIMER_COUNTER1_compareC(uint16_t compare);
uint8_t TIMER_COUNTER1_start(unsigned int prescaler);
uint8_t TIMER_COUNTER1_stop(void);

void TIMER_COUNTER2_compoutmode(unsigned char compoutmode);
void TIMER_COUNTER2_compoutmodeA(unsigned char compoutmode);
void TIMER_COUNTER2_compoutmodeB(unsigned char compoutmode);
void TIMER_COUNTER2_compare(unsigned char compare);
void TIMER_COUNTER2_compareA(unsigned char compare);
void TIMER_COUNTER2_compareB(unsigned char compare);
uint8_t TIMER_COUNTER2_start(unsigned int prescaler);
uint8_t TIMER_COUNTER2_stop(void);

void TIMER_COUNTER3_compoutmodeA(unsigned char compoutmode);
void TIMER_COUNTER3_compoutmodeB(unsigned char compoutmode);
void TIMER_COUNTER3_compoutmodeC(unsigned char compoutmode);
void TIMER_COUNTER3_compareA(uint16_t compare);
void TIMER_COUNTER3_compareB(uint16_t compare);
void TIMER_COUNTER3_compareC(uint16_t compare);
uint8_t TIMER_COUNTER3_start(unsigned int prescaler);
uint8_t TIMER_COUNTER3_stop(void);

/*** Procedure & Function ***/
TIMER_COUNTER0 TIMER_COUNTER0enable(unsigned char wavegenmode, unsigned char interrupt)
// PARAMETER SETTING
// wavegen mode: Normal; PWM phase correct; Fast PWM; default-Normasl;
// interrupt: off; overflow; output compare; both; default - non.
{
	TIMER_COUNTER0 tc0;
	ATMEGA128enable(); // Dependency
	
	timer0_state = 0;
	atmega128.tc0.reg->tccr0 &= ~((1 << WGM00) | (1 << WGM01));
	switch(wavegenmode){ // TOP -- Update of OCR0 at -- TOV0 Flag Set on
		case 0: // Normal, 0xFF -- Immediate -- MAX
		break;
		case 1: // PWM Phase Correct, 0xFF -- TOP -- BOTTOM
			atmega128.tc0.reg->tccr0 |= (1 << WGM00);
		break;
		case 2: // CTC, OCR0 -- Immediate -- MAX
			atmega128.tc0.reg->tccr0 |= (1 << WGM01);
		break;
		case 3: // Fast PWM, 0xFF -- BOTTOM -- MAX
			atmega128.tc0.reg->tccr0 |= (1 << WGM00) | (1 << WGM01);
		break;
		default:
		break;
	}
	atmega128.tc0.reg->timsk &= ~(1 << TOIE0);
	atmega128.tc0.reg->timsk &= ~(1 << OCIE0);
	switch(interrupt){
		case 0:
		break;
		case 1:
			atmega128.tc0.reg->timsk |= (1 << TOIE0);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 2:
			atmega128.tc0.reg->timsk |= (1 << OCIE0);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 3:
			atmega128.tc0.reg->timsk |= ((1 << TOIE0) | (1 << OCIE0));
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		default:
		break;
	}
	atmega128.tc0.reg->ocr0 = ~0;
	
	tc0.compoutmode = TIMER_COUNTER0_compoutmode;
	tc0.compare = TIMER_COUNTER0_compare;
	tc0.start = TIMER_COUNTER0_start;
	tc0.stop = TIMER_COUNTER0_stop;
	return tc0;
}
uint8_t TIMER_COUNTER0_start(unsigned int prescaler)
// PARAMETER SETTING
// Frequency oscillator devision factor or prescaler.
// prescaler: clk T0S /(No prescaling); clk T0S /8 (From prescaler); clk T0S /32 (From prescaler);
// clk T0S /64 (From prescaler); clk T0S /128 (From prescaler); clk T 0 S /256 (From prescaler);
// clk T 0 S /1024 (From prescaler); default - clk T 0 S /1024 (From prescaler).
{
	if(!timer0_state){ // one shot
		atmega128.tc0.reg->tccr0 &= ~(7 << CS00); // No clock source. (Timer/Counter stopped)
		switch(prescaler){
			//case 0: // No clock source. (Timer/Counter stopped)
			//break;
			case 1: // clk T0S /(No prescaler)
				atmega128.tc0.reg->tccr0 |= (1 << CS00);
			break;
			case 8: // clk T0S /8 (From prescaler)
				atmega128.tc0.reg->tccr0 |= (1 << CS01);
			break;
			case 32: // clk T0S /32 (From prescaler)
				atmega128.tc0.reg->tccr0 |=(3 << CS00);
			break;
			case 64: // clk T0S /64 (From prescaler)
				atmega128.tc0.reg->tccr0 |= (4 << CS00);
			break;
			case 128: // clk T0S /128 (From prescaler)
				atmega128.tc0.reg->tccr0 |= (5 << CS00);
			break;
			case 256: // clk T 0 S /256 (From prescaler)
				atmega128.tc0.reg->tccr0 |= (6 << CS00);
			break;
			case 1024: // clk T 0 S /1024 (From prescaler)
				atmega128.tc0.reg->tccr0 |= (7 << CS00);
			break;
			default:
				atmega128.tc0.reg->tccr0 |= (7 << CS00);
			break;
		}
		timer0_state = 85;
	}
	return timer0_state;
}
void TIMER_COUNTER0_compoutmode(unsigned char compoutmode)
// compoutmode: Normal port operation, OC0 disconnected; Toggle OC0 on compare match;
// Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting. Clear OC0 on compare match;
// Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting. Set OC0 on compare match ;
// default-Normal port operation, OC0 disconnected.
{
	atmega128.tc0.reg->tccr0 &= ~((1 << COM00) | (1 << COM01));
	switch(compoutmode){ // OC0  -->  PB4
		case 0: // Normal port operation, OC0 disconnected.
		break;
		case 1: // Reserved
			// Toggle OC0 on compare match
			atmega128.portb.reg->ddr = 0x10;
			atmega128.tc0.reg->tccr0 |= (1 << COM00);
		break;
		case 2: // Clear OC0 on compare match when up-counting. Set OC0 on compare
			// match when down counting.
			atmega128.portb.reg->ddr = 0x10;
			atmega128.tc0.reg->tccr0 |= (1 << COM01);
		break;
		case 3: // Set OC0 on compare match when up-counting. Clear OC0 on compare
			// match when down counting.
			atmega128.portb.reg->ddr = 0x10;
			atmega128.tc0.reg->tccr0 |= (1 << COM00) | (1 << COM01);
		break;
		default:
		break;
	}
}
void TIMER_COUNTER0_compare(unsigned char compare)
{
	atmega128.tc0.reg->ocr0 = compare;
}
uint8_t TIMER_COUNTER0_stop(void)
// stops timer by setting prescaler to zero
{
	atmega128.tc0.reg->tccr0 &= ~(7 << CS00); // No clock source. (Timer/Counter stopped)
	timer0_state = 0;
	return timer0_state;
}

TIMER_COUNTER1 TIMER_COUNTER1enable(unsigned char wavegenmode, unsigned char interrupt)
// PARAMETER SETTING
// wavegen mode: Normal; PWM, Phase Correct, 8-bit; PWM, Phase Correct, 9-bit; PWM, Phase Correct, 10-bit;
// CTC; Fast PWM, 8-bit; Fast PWM, 9-bit; Fast PWM, 10-bit; PWM, Phase and Frequency Correct; PWM, Phase and Frequency Correct;
// PWM, Phase Correct; PWM, Phase Correct; CTC; (Reserved); Fast PWM; Fast PWM.
// interrupt: off; overflow; output compare; both; default - non.
// for more information read data sheet.
{
	TIMER_COUNTER1 tc1;
	ATMEGA128enable(); // Dependency

	timer1_state = 0;
	atmega128.tc1.reg->tccr1a &= ~((1 << WGM11) | (1 << WGM10));
	atmega128.tc1.reg->tccr1b &= ~((1 << WGM13) | (1 << WGM12));
	switch(wavegenmode){ // TOP -- Update of OCRnX at -- TOV Flag Set on
		case 0: // Normal, 0xFFFF -- Immediate -- MAX
		break;
		case 1: // PWM Phase Correct 8-bit, 0x00FF -- TOP -- BOTTOM
			atmega128.tc1.reg->tccr1a |= (1 << WGM10);
		break;
		case 2:	// PWM Phase Correct 9-bit, 0x01FF -- TOP -- BOTTOM
			atmega128.tc1.reg->tccr1a |= (1 << WGM11);
		break;
		case 3:	// PWM Phase Correct 10-bit, 0x03FF -- TOP -- BOTTOM
			atmega128.tc1.reg->tccr1a |= (1 << WGM11) | (1 << WGM10);
		break;
		case 4:	// CTC, OCRnA Immediate MAX
			atmega128.tc1.reg->tccr1b |= (1 << WGM12);
		break;
		case 5:	// Fast PWM 8-bit, 0x00FF -- BOTTOM -- TOP
			atmega128.tc1.reg->tccr1a |= (1 << WGM10);
			atmega128.tc1.reg->tccr1b |= (1 << WGM12);
		break;
		case 6:	// Fast PWM 9-bit, 0x01FF -- BOTTOM -- TOP
			atmega128.tc1.reg->tccr1a |= (1 << WGM11);
			atmega128.tc1.reg->tccr1b |= (1 << WGM12);
		break;
		case 7:	// Fast PWM 10-bit, 0x03FF -- BOTTOM -- TOP
			atmega128.tc1.reg->tccr1a |= (1 << WGM11) | (1 << WGM10);
			atmega128.tc1.reg->tccr1b |=(1 << WGM12);
		break;
		case 8:	// PWM Phase and Frequency Correct, ICRnA -- BOTTOM -- BOTTOM
			atmega128.tc1.reg->tccr1b |= (1 << WGM13);
		break;
		case 9:	// PWM Phase and Frequency Correct, OCRnA -- BOTTOM -- BOTTOM
			atmega128.tc1.reg->tccr1a |= (1 << WGM10);
			atmega128.tc1.reg->tccr1b |= (1 << WGM13);
		break;
		case 10: // PWM Phase Correct, ICRn -- TOP -- BOTTOM
			atmega128.tc1.reg->tccr1a |= (1 << WGM11);
			atmega128.tc1.reg->tccr1b |= (1 << WGM13);
		break;
		case 11: // PWM Phase Correct, OCRnA -- TOP -- BOTTOM
			atmega128.tc1.reg->tccr1a |= (1 << WGM11) | (1 << WGM10);
			atmega128.tc1.reg->tccr1b |= (1 << WGM13);
		break;
		case 12: // CTC, ICRn -- Immediate -- MAX
			atmega128.tc1.reg->tccr1b |= (1 << WGM13) | (1 << WGM12);
		break;
		case 13: // (Reserved), -- -- --
			atmega128.tc1.reg->tccr1a |= (1 << WGM10);
			atmega128.tc1.reg->tccr1b |= (1 << WGM13) | (1 << WGM12);
		break;
		case 14: // Fast PWM, ICRn -- BOTTOM -- TOP
			atmega128.tc1.reg->tccr1a |= (1 << WGM11);
			atmega128.tc1.reg->tccr1b |= (1 << WGM13) | (1 << WGM12);
		break;
		case 15: // Fast PWM, OCRnA -- BOTTOM -- TOP
			atmega128.tc1.reg->tccr1a |= (1 << WGM11) | (1 << WGM10);
			atmega128.tc1.reg->tccr1b |= (1 << WGM13) | (1 << WGM12);
		break;
		default:
		break;
	}
	atmega128.tc1.reg->tccr1a &= ~((3 << COM1A0) | (3 << COM1B0) | (3 << COM1C0));
	atmega128.tc1.reg->timsk &= ~((1 << TICIE1) | (1 << OCIE1A) | (1 << OCIE1B) | (1 << TOIE1));
	atmega128.tc1.reg->etimsk &= ~(1 << OCIE1C);
	switch(interrupt){ // ICP1  -->  PD4
		case 0:
		break;
		case 1:
			atmega128.tc1.reg->timsk |= (1 << TOIE1);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 2:
			atmega128.tc1.reg->timsk |= (1 << OCIE1A);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 3:
			atmega128.tc1.reg->timsk |= (1 << OCIE1B);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 4:
			atmega128.tc1.reg->etimsk |= (1 << OCIE1C);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 5:
			atmega128.tc1.reg->timsk |= (1 << TICIE1);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 6:
			atmega128.tc1.reg->timsk |= (1 << OCIE1A) | (1 << TOIE1);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 7:
			atmega128.tc1.reg->timsk |= (1 << OCIE1B) | (1 << TOIE1);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 8:
			atmega128.tc1.reg->timsk |= (1 << TOIE1);
			atmega128.tc1.reg->etimsk |= (1 << OCIE1C);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 9:
			atmega128.tc1.reg->timsk |= (1 << TICIE1) | (1 << TOIE1);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 10:
			atmega128.tc1.reg->timsk |= (1 << OCIE1A) | (1 << OCIE1B) | (1 << TOIE1);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 11:
			atmega128.tc1.reg->timsk |= (1 << OCIE1A) | (1 << OCIE1B) | (1 << TOIE1);
			atmega128.tc1.reg->etimsk |= (1 << OCIE1C);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 12:
			atmega128.tc1.reg->timsk |= (1 << OCIE1A) | (1 << OCIE1B);
			atmega128.tc1.reg->etimsk |= (1 << OCIE1C);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		default:
		break;
	}
	atmega128.tc1.reg->ocr1a = atmega128.writehlbyte(~0);
	atmega128.tc1.reg->ocr1b = atmega128.writehlbyte(~0);
	atmega128.tc1.reg->ocr1c = atmega128.writehlbyte(~0);
	
	tc1.compoutmodeA = TIMER_COUNTER1_compoutmodeA;
	tc1.compoutmodeB = TIMER_COUNTER1_compoutmodeB;
	tc1.compoutmodeC = TIMER_COUNTER1_compoutmodeC;
	tc1.compareA = TIMER_COUNTER1_compareA;
	tc1.compareB = TIMER_COUNTER1_compareB;
	tc1.compareC = TIMER_COUNTER1_compareC;
	tc1.start = TIMER_COUNTER1_start;
	tc1.stop = TIMER_COUNTER1_stop;
	return tc1;
}
uint8_t TIMER_COUNTER1_start(unsigned int prescaler)
// PARAMETER SETTING
// Frequency oscillator devision factor or prescaler.
// prescaler: clk T0S /(No prescaling); clk T0S /8 (From prescaler); clk T0S /64 (From prescaler);
// clk T0S /256 (From prescaler); clk T0S /1024 (From prescaler); External clock source on Tn pin. Clock on falling edge;
// External clock source on Tn pin. Clock on rising edge; default - clk T 0 S /1024 (From prescaler).
{
	if(!timer1_state){ // one shot
		atmega128.tc1.reg->tccr1b &= ~(7 << CS10); // No clock source. (Timer/Counter stopped)
		switch(prescaler){
			//case 0: // No clock source. (Timer/Counter stopped)
			//break;
			case 1: // clkI/O/1 (No prescaler
				atmega128.tc1.reg->tccr1b |= (1 << CS10);
			break;
			case 8: // clkI/O/8 (From prescaler)
				atmega128.tc1.reg->tccr1b |= (1 << CS11);
			break;
			case 64: // clkI/O/64 (From prescaler)
				atmega128.tc1.reg->tccr1b |= (3 << CS10);
			break;
			case 256: // clkI/O/256 (From prescaler)
				atmega128.tc1.reg->tccr1b |= (1 << CS12);
			break;
			case 1024: // clkI/O/1024 (From prescaler)
				atmega128.tc1.reg->tccr1b |= (5 << CS10);
			break;
			case 6: // External clock source on Tn pin. Clock on falling edge [PD6]
				atmega128.tc1.reg->tccr1b |= (6 << CS10);
			break;
			case 7: // External clock source on Tn pin. Clock on rising edge [PD6]
				atmega128.tc1.reg->tccr1b |= (7 << CS10);
			break;
			default: // clkI/O/1024 (From prescaler)
				atmega128.tc1.reg->tccr1b |= (5 << CS10);
			break;
		}
		timer1_state = 85;
	}
	return timer1_state;
}
void TIMER_COUNTER1_compoutmodeA(unsigned char compoutmode)
{
	atmega128.tc1.reg->tccr1a &= ~(3 << COM1A0);
	switch(compoutmode){ // OC1A  -->  PB5
		case 0: // Normal port operation, OC1A disconnected.
		break;
		case 1: // Reserved
			// Toggle OC1A on compare match
			atmega128.portb.reg->ddr |= 0x20;
			atmega128.tc1.reg->tccr1a |= (1 << COM1A0);
		break;
		case 2: // Clear OC1A on compare match when up-counting. Set OC1A on compare
			// match when down counting.
			atmega128.portb.reg->ddr |= 0x20;
			atmega128.tc1.reg->tccr1a |= (1 << COM1A1);
		break;
		case 3: // Set OC1A on compare match when up-counting. Clear OC1A on compare
			// match when down counting.
			atmega128.portb.reg->ddr |= 0x20;
			atmega128.tc1.reg->tccr1a |= (1 << COM1A0) | (1 << COM1A1);
		break;
		default:
		break;
	}
}
void TIMER_COUNTER1_compoutmodeB(unsigned char compoutmode)
{
	atmega128.tc1.reg->tccr1a &= ~(3 << COM1B0);
	switch(compoutmode){ // OC1B  -->  PB6
		case 0: // Normal port operation, OC1B disconnected.
		break;
		case 1: // Reserved
			// Toggle OC1A or OC1B on compare match
			atmega128.portb.reg->ddr |= 0x40;
			atmega128.tc1.reg->tccr1a |= (1 << COM1B0);
		break;
		case 2: // Clear OC1B on compare match when up-counting. Set OC1B on compare
			// match when down counting.
			atmega128.portb.reg->ddr |= 0x40;
			atmega128.tc1.reg->tccr1a |= (1 << COM1B1);
		break;
		case 3: // Set OC1B on compare match when up-counting. Clear OC1B on compare
			// match when down counting.
			atmega128.portb.reg->ddr |= 0x40;
			atmega128.tc1.reg->tccr1a |= (1 << COM1B0) | (1 << COM1B1);
		break;
		default:
		break;
	}
}
void TIMER_COUNTER1_compoutmodeC(unsigned char compoutmode)
{
	atmega128.tc1.reg->tccr1a &= ~(3 << COM1C0);
	switch(compoutmode){ // OC1C  -->  PB7
		case 0: // Normal port operation, OC1C disconnected.
		break;
		case 1: // Reserved
			// Toggle OC1A or OC1C on compare match
			atmega128.portb.reg->ddr |= 0x80;
			atmega128.tc1.reg->tccr1a |= (1 << COM1C0);
		break;
		case 2: // Clear OC1C on compare match when up-counting. Set OC1C on compare
			// match when down counting.
			atmega128.portb.reg->ddr |= 0x80;
			atmega128.tc1.reg->tccr1a |= (1 << COM1C1);
		break;
		case 3: // Set OC1C on compare match when up-counting. Clear OC1C on compare
			// match when down counting.
			atmega128.portb.reg->ddr |= 0x80;
			atmega128.tc1.reg->tccr1a |= (1 << COM1C0) | (1 << COM1C1);
		break;
		default:
		break;
	}
}
void TIMER_COUNTER1_compareA(uint16_t compare)
{
	atmega128.tc1.reg->ocr1a = atmega128.writehlbyte(compare);
}
void TIMER_COUNTER1_compareB(uint16_t compare)
{
	atmega128.tc1.reg->ocr1b = atmega128.writehlbyte(compare);
}
void TIMER_COUNTER1_compareC(uint16_t compare)
{
	atmega128.tc1.reg->ocr1c = atmega128.writehlbyte(compare);
}
uint8_t TIMER_COUNTER1_stop(void)
// stops timer by setting prescaler to zero
{
	atmega128.tc1.reg->tccr1b &= ~(7 << CS10); // No clock source. (Timer/Counter stopped)
	timer1_state = 0;
	return timer1_state;
}

TIMER_COUNTER2 TIMER_COUNTER2enable(unsigned char wavegenmode, unsigned char interrupt)
// PARAMETER SETTING
// wavegen mode: Normal; PWM phase correct; Fast PWM; default-Normasl;
// interrupt: off; overflow; output compare; both; default - non.
{
	TIMER_COUNTER2 tc2;
	ATMEGA128enable(); // Dependency
	
	timer2_state = 0;
	atmega128.tc2.reg->tccr2 &= ~((1 << WGM20) | (1 << WGM21));
	switch(wavegenmode){ // TOP -- Update of OCR2 at -- TOV0 Flag Set on
		case 0: // Normal, 0xFF -- Immediate -- MAX
		break;
		case 1: // PWM Phase Correct, 0xFF -- TOP -- BOTTOM
			atmega128.tc2.reg->tccr2 |= (1 << WGM20);
		break;
		case 2: // CTC, OCR2 -- Immediate -- MAX
			atmega128.tc2.reg->tccr2 |= (1 << WGM21);
		break;
		case 3: // Fast PWM, 0xFF -- BOTTOM -- MAX
			atmega128.tc2.reg->tccr2 |= (1 << WGM20) | (1 << WGM21);
		break;
		default:
		break;
	}
	atmega128.tc2.reg->timsk &= ~((1 << TOIE2) | (1 << OCIE2));
	switch(interrupt){
		case 0:
		break;
		case 1:
			atmega128.tc2.reg->timsk |= (1 << TOIE2);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 2:
			atmega128.tc2.reg->timsk |= (1 << OCIE2);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 3:
			atmega128.tc2.reg->timsk |= (1 << TOIE2);
			atmega128.tc2.reg->timsk |= (1 << OCIE2);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		default:
		break;
	}
	atmega128.tc2.reg->ocr2 = ~0;
	
	tc2.compoutmode = TIMER_COUNTER2_compoutmode;
	tc2.compare = TIMER_COUNTER2_compare;
	tc2.start = TIMER_COUNTER2_start;
	tc2.stop = TIMER_COUNTER2_stop;
	return tc2;
}
uint8_t TIMER_COUNTER2_start(unsigned int prescaler)
// PARAMETER SETTING
// Frequency oscillator devision factor or prescaler.
// prescaler: clk T0S /(No prescaling); clk T0S /8 (From prescaler); clk T0S /64 (From prescaler);
// clk T0S /256 (From prescaler); clk T0S /1024 (From prescaler); External clock source on Tn pin. Clock on falling edge;
// External clock source on Tn pin. Clock on rising edge; default - clk T 0 S /1024 (From prescaler).
{
	if(!timer2_state){ // one shot
		atmega128.tc2.reg->tccr2 &= ~(7 << CS20); // No clock source. (Timer/Counter stopped)
		switch(prescaler){
			//case 0: // No clock source. (Timer/Counter stopped)
			//break;
			case 1: // clkI/O/(No prescaler)
				atmega128.tc2.reg->tccr2 |= (1 << CS20);
			break;
			case 8: // clkI/O/8 (From prescaler)
				atmega128.tc2.reg->tccr2 |= (1 << CS21);
			break;
			case 64: // clkI/O/64 (From prescaler)
				atmega128.tc2.reg->tccr2 |= (3 << CS20);
			break;
			case 256: // clkI/O/256 (From prescaler)
				atmega128.tc2.reg->tccr2 |= (1 << CS22);
			break;
			case 1024: // clkI/O/1024 (From prescaler)
				atmega128.tc2.reg->tccr2 |= (5 << CS20);
			break;
			case 6: // External clock source on T2 pin. Clock on falling edge [PD7]
				atmega128.tc2.reg->tccr2 |= (6 << CS20);
			break;
			case 7: // External clock source on T2 pin. Clock on rising edge [PD7]
				atmega128.tc2.reg->tccr2 |= (7 << CS20);
			break;
			default:
				atmega128.tc2.reg->tccr2 |= (5 << CS20);
			break;
		}
		timer2_state = 85;
	}
	return timer2_state;
}
void TIMER_COUNTER2_compoutmode(unsigned char compoutmode)
// compoutmode: Normal port operation, OC0 disconnected; Toggle OC0 on compare match; 
// Clear OC0 on compare match when up-counting. Set OC0 on compare match when downcounting. Clear OC0 on compare match;
// Set OC0 on compare match when up-counting. Clear OC0 on compare match when downcounting. Set OC0 on compare match ;
// default-Normal port operation, OC0 disconnected.
{
	atmega128.tc2.reg->tccr2 &= ~((1 << COM20) | (1 << COM21));
	switch(compoutmode){ // OC2  -->  PB7
		case 0: // Normal port operation, OC2 disconnected.
		break;
		case 1: // Reserved
			// Toggle OC2 on compare match
			atmega128.portb.reg->ddr |= 0x80;
			atmega128.tc2.reg->tccr2 |= (1 << COM20);
		break;
		case 2: // Clear OC2 on compare match when up-counting. Set OC0 on compare
			// match when down counting.
			atmega128.portb.reg->ddr |= 0x80;
			atmega128.tc2.reg->tccr2 |= (1 << COM21);
		break;
		case 3: // Set OC2 on compare match when up-counting. Clear OC0 on compare
			// match when down counting.
			atmega128.portb.reg->ddr |= 0x80;
			atmega128.tc2.reg->tccr2 |= (1 << COM20) | (1 << COM21);
		break;
		default:
		break;
	}
}
void TIMER_COUNTER2_compare(unsigned char compare)
{
	atmega128.tc2.reg->ocr2 = compare;
}
uint8_t TIMER_COUNTER2_stop(void)
// stops timer by setting prescaler to zero
{
	atmega128.tc2.reg->tccr2 &= ~(7 << CS20); // No clock source. (Timer/Counter stopped)
	timer2_state = 0;
	return timer2_state;
}

TIMER_COUNTER3 TIMER_COUNTER3enable(unsigned char wavegenmode, unsigned char interrupt)
// PARAMETER SETTING
// wavegen mode: Normal; PWM, Phase Correct, 8-bit; PWM, Phase Correct, 9-bit; PWM, Phase Correct, 10-bit;
// CTC; Fast PWM, 8-bit; Fast PWM, 9-bit; Fast PWM, 10-bit; PWM, Phase and Frequency Correct; PWM, Phase and Frequency Correct;
// PWM, Phase Correct; PWM, Phase Correct; CTC; (Reserved); Fast PWM; Fast PWM.
// interrupt: off; overflow; output compare; both; default - non.
// for more information read data sheet.
{
	TIMER_COUNTER3 tc3;
	ATMEGA128enable(); // Dependency
	
	timer3_state = 0;
	atmega128.tc3.reg->tccr3a &= ~((1 << WGM31) | (1 << WGM30));
	atmega128.tc3.reg->tccr3b &= ~((1 << WGM33) | (1 << WGM32));
	switch(wavegenmode){ // TOP -- Update of OCRnX -- TOV Flag Set on
		case 0: // Normal, 0xFFFF -- Immediate -- MAX
		break;
		case 1: // PWM Phase Correct 8-bit, 0x00FF -- TOP -- BOTTOM
			atmega128.tc3.reg->tccr3a |= (1 << WGM30);
		break;
		case 2:	// PWM Phase Correct 9-bit, 0x01FF -- TOP -- BOTTOM
			atmega128.tc3.reg->tccr3a |= (1 << WGM31);
		break;
		case 3:	// PWM Phase Correct 10-bit, 0x03FF -- TOP -- BOTTOM
			atmega128.tc3.reg->tccr3a |= (1 << WGM31) | (1 << WGM30);
		break;
		case 4:	// CTC, OCRnA Immediate MAX
			atmega128.tc3.reg->tccr3b |= (1 << WGM32);
		break;
		case 5:	// Fast PWM 8-bit, 0x00FF -- BOTTOM -- TOP
			atmega128.tc3.reg->tccr3a |=(1 << WGM30);
			atmega128.tc3.reg->tccr3b |= (1 << WGM32);
		break;
		case 6:	// Fast PWM 9-bit, 0x01FF -- BOTTOM -- TOP
			atmega128.tc3.reg->tccr3a |= (1 << WGM31);
			atmega128.tc3.reg->tccr3b |= (1 << WGM32);
		break;
		case 7:	// Fast PWM 10-bit, 0x03FF -- BOTTOM -- TOP
			atmega128.tc3.reg->tccr3a |=(1 << WGM31) | (1 << WGM30);
			atmega128.tc3.reg->tccr3b |= (1 << WGM32);
		break;
		case 8:	// PWM Phase and Frequency Correct, ICRnA -- BOTTOM -- BOTTOM
			atmega128.tc3.reg->tccr3b |= (1 << WGM33);
		break;
		case 9:	// PWM Phase and Frequency Correct, OCRnA -- BOTTOM -- BOTTOM
			atmega128.tc3.reg->tccr3a |= (1 << WGM30);
			atmega128.tc3.reg->tccr3b |= (1 << WGM33);
		break;
		case 10: // PWM Phase Correct, ICRn -- TOP -- BOTTOM
			atmega128.tc3.reg->tccr3a |=(1 << WGM31);
			atmega128.tc3.reg->tccr3b |= (1 << WGM33);
		break;
		case 11: // PWM Phase Correct, OCRnA -- TOP -- BOTTOM
			atmega128.tc3.reg->tccr3a |= (1 << WGM31) | (1 << WGM30);
			atmega128.tc3.reg->tccr3b |= (1 << WGM33);
		break;
		case 12: // CTC, ICRn -- Immediate -- MAX
			atmega128.tc3.reg->tccr3b |= (1 << WGM33) | (1 << WGM32);
		break;
		case 13: // (Reserved), -- -- --
			atmega128.tc3.reg->tccr3a |= (1 << WGM30);
			atmega128.tc3.reg->tccr3b |= (1 << WGM33) | (1 << WGM32);
		break;
		case 14: // Fast PWM, ICRn -- BOTTOM -- TOP
			atmega128.tc3.reg->tccr3a |= (1 << WGM31);
			atmega128.tc3.reg->tccr3b |= (1 << WGM33) | (1 << WGM32);
		break;
		case 15: // Fast PWM, OCRnA -- BOTTOM -- TOP
			atmega128.tc3.reg->tccr3a |= (1 << WGM31) | (1 << WGM30);
			atmega128.tc3.reg->tccr3b |= (1 << WGM33) | (1 << WGM32);
		break;
		default:
		break;
	}
	atmega128.tc3.reg->tccr3a &= ~((3 << COM3A0) | (3 << COM3B0)| (3 << COM3C0));
	atmega128.tc3.reg->etimsk &= ~((1 << TICIE3) | (1 << OCIE3A) | (1 << OCIE3B) | (1 << TOIE3) | (1 << OCIE3C));
	switch(interrupt){ // ICP3  -->  PE7
		case 0:
		break;
		case 1:
			atmega128.tc3.reg->etimsk |= (1 << TOIE3);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 2:
			atmega128.tc3.reg->etimsk |= (1 << OCIE3A);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 3:
			atmega128.tc3.reg->etimsk |= (1 << OCIE3B);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 4:
			atmega128.tc3.reg->etimsk |= (1 << OCIE3C);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 5:
			atmega128.tc3.reg->etimsk |= (1 << TICIE3);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 6:
			atmega128.tc3.reg->etimsk |= (1 << OCIE3A) | (1 << TOIE3);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 7:
			atmega128.tc3.reg->etimsk |= (1 << OCIE3B) | (1 << TOIE3);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 8:
			atmega128.tc3.reg->etimsk |= (1 << TOIE3) | (1 << OCIE3C);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 9:
			atmega128.tc3.reg->etimsk |= (1 << TICIE3) | (1 << TOIE3);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 10:
			atmega128.tc3.reg->etimsk |= (1 << OCIE3A) | (1 << OCIE3B) | (1 << TOIE3);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 11:
			atmega128.tc3.reg->etimsk |= (1 << OCIE3A) | (1 << OCIE3B) | (1 << TOIE3) | (1 << OCIE3C);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 12:
			atmega128.tc3.reg->etimsk |= (1 << OCIE3A) | (1 << OCIE3B) | (1 << OCIE3C);
			atmega128.cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		default:
		break;
	}
	atmega128.tc3.reg->ocr3a = atmega128.writehlbyte(~0);
	atmega128.tc3.reg->ocr3b = atmega128.writehlbyte(~0);
	atmega128.tc3.reg->ocr3c = atmega128.writehlbyte(~0);
	
	tc3.compoutmodeA = TIMER_COUNTER3_compoutmodeA;
	tc3.compoutmodeB = TIMER_COUNTER3_compoutmodeB;
	tc3.compoutmodeC = TIMER_COUNTER3_compoutmodeC;
	tc3.compareA = TIMER_COUNTER3_compareA;
	tc3.compareB = TIMER_COUNTER3_compareB;
	tc3.compareC = TIMER_COUNTER3_compareC;
	tc3.start = TIMER_COUNTER3_start;
	tc3.stop = TIMER_COUNTER3_stop;
	return tc3;
}
uint8_t TIMER_COUNTER3_start(unsigned int prescaler)
// PARAMETER SETTING
// Frequency oscillator devision factor or prescaler.
// prescaler: clk T0S /(No prescaling); clk T0S /8 (From prescaler); clk T0S /64 (From prescaler);
// clk T0S /256 (From prescaler); clk T0S /1024 (From prescaler); External clock source on Tn pin. Clock on falling edge;
// External clock source on Tn pin. Clock on rising edge; default - clk T 0 S /1024 (From prescaler).
{
	if(!timer3_state){ // one shot
		atmega128.tc3.reg->tccr3b &= ~(7 << CS30); // No clock source. (Timer/Counter stopped)
		switch(prescaler){
			//case 0: // No clock source. (Timer/Counter stopped)
			//break;
			case 1: // clkI/O/1 (No prescaler)
				atmega128.tc3.reg->tccr3b |= (1 << CS30);
			break;
			case 8: // clkI/O/8 (From prescaler)
				atmega128.tc3.reg->tccr3b |= (1 << CS31);
			break;
			case 64: // clkI/O/64 (From prescaler)
				atmega128.tc3.reg->tccr3b |= (3 << CS30);
			break;
			case 256: // clkI/O/256 (From prescaler)
				atmega128.tc3.reg->tccr3b |= (1 << CS32);
			break;
			case 1024: // clkI/O/1024 (From prescaler)
				atmega128.tc3.reg->tccr3b |= (5 << CS30);
			break;
			case 6: // External clock source on Tn pin. Clock on falling edge [PE6]
				atmega128.tc3.reg->tccr3b |= (6 << CS30);
			break;
			case 7: // External clock source on Tn pin. Clock on rising edge [PE6]
				atmega128.tc3.reg->tccr3b |= (7 << CS30);
			break;
			default:
				atmega128.tc3.reg->tccr3b |= (5 << CS30);
			break;
		}
		timer3_state = 85;
	}	
	return timer3_state;
}
void TIMER_COUNTER3_compoutmodeA(unsigned char compoutmode)
{
	atmega128.tc3.reg->tccr3a &= ~(3 << COM3A0);
	switch(compoutmode){ // OC3A  -->  PE3
		case 0: // Normal port operation, OC3A disconnected.
		break;
		case 1: // Reserved
			// Toggle OC3A on compare match
			atmega128.porte.reg->ddr |= 0x08;
			atmega128.tc3.reg->tccr3a |= (1 << COM3A0);
		break;
		case 2: // Clear OC3A on compare match when up-counting. Set OC0 on compare
			// match when down counting.
			atmega128.porte.reg->ddr |= 0x08;
			atmega128.tc3.reg->tccr3a |= (1 << COM3A1);
		break;
		case 3: // Set OC3A on compare match when up-counting. Clear OC0 on compare
			// match when down counting.
			atmega128.porte.reg->ddr |= 0x08;
			atmega128.tc3.reg->tccr3a |= (1 << COM3A0) | (1 << COM3A1);
		break;
		default:
		break;
	}
}
void TIMER_COUNTER3_compoutmodeB(unsigned char compoutmode)
{
	atmega128.tc3.reg->tccr3a &= ~(3 << COM3B0);
	switch(compoutmode){ // OC3B  -->  PE4
		case 0: // Normal port operation, OC3B disconnected.
		break;
		case 1: // Reserved
			// Toggle OC3A or OC3B on compare match
			atmega128.porte.reg->ddr |= 0x10;
			atmega128.tc3.reg->tccr3a |= (1 << COM3B0);
		break;
		case 2: // Clear OC3B on compare match when up-counting. Set OC3B on compare
			// match when down counting.
			atmega128.porte.reg->ddr |= 0x10;
			atmega128.tc3.reg->tccr3a |= (1 << COM3B1);
		break;
		case 3: // Set OC3B on compare match when up-counting. Clear OC3B on compare
			// match when down counting.
			atmega128.porte.reg->ddr |= 0x10;
			atmega128.tc3.reg->tccr3a |= (1 << COM3B0) | (1 << COM3B1);
		break;
		default:
		break;
	}
}
void TIMER_COUNTER3_compoutmodeC(unsigned char compoutmode)
{
	atmega128.tc3.reg->tccr3a &= ~(3 << COM3C0);
	switch(compoutmode){ // OC3C  -->  PE5
		case 0: // Normal port operation, OC3C disconnected.
		break;
		case 1: // Reserved
			// Toggle OC3A or OC3C on compare match
			atmega128.porte.reg->ddr |= 0x20;
			atmega128.tc3.reg->tccr3a |= (1 << COM3C0);
		break;
		case 2: // Clear OC3C on compare match when up-counting. Set OC3C on compare
			// match when down counting.
			atmega128.porte.reg->ddr |= 0x20;
			atmega128.tc3.reg->tccr3a |= (1 << COM3C1);
		break;
		case 3: // Set OC3C on compare match when up-counting. Clear OC3C on compare
			// match when down counting.
			atmega128.porte.reg->ddr |= 0x20;
			atmega128.tc3.reg->tccr3a |= (1 << COM3C0) | (1 << COM3C1);
		break;
		default:
		break;
	}
}
void TIMER_COUNTER3_compareA(uint16_t compare)
{
	atmega128.tc3.reg->ocr3a = atmega128.writehlbyte(compare);
}
void TIMER_COUNTER3_compareB(uint16_t compare)
{
	atmega128.tc3.reg->ocr3b = atmega128.writehlbyte(compare);
}
void TIMER_COUNTER3_compareC(uint16_t compare)
{
	atmega128.tc3.reg->ocr3c = atmega128.writehlbyte(compare);
}
uint8_t TIMER_COUNTER3_stop(void)
// stops timer by setting prescaler to zero
{
	atmega128.tc3.reg->tccr3b &= ~(7 << CS30); // No clock source. (Timer/Counter stopped)
	timer3_state = 0;
	return timer3_state;
}

/*** File Interrupt ***/
// ISR(TIMER0_COMP_vect){};
// ISR(TIMER0_OVF_vect){};
// ISR(TIMER1_CAPT_vect){};
// ISR(TIMER1_COMPA_vect){};
// ISR(TIMER1_COMPB_vect){};
// ISR(TIMER1_COMPC_vect){};
// ISR(TIMER1_OVF_vect){};
// ISR(TIMER2_COMP_vect){};
// ISR(TIMER2_OVF_vect){};
// ISR(TIMER3_CAPT_vect){};
// ISR(TIMER3_COMPA_vect){};
// ISR(TIMER3_COMPB_vect){};
// ISR(TIMER3_COMPC_vect){};
// ISR(TIMER3_OVF_vect){};

/***EOF***/

