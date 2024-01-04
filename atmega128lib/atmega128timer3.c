/*************************************************************************
	ATMEGA128TIMER3
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Update: 01/01/2024
Comment:
	Stable
*************************************************************************/
/*** File Library ***/
#include "atmega128mapping.h"
#include "atmega128timer3.h"

/*** File Variable ***/
static TIMER_COUNTER3 atmega128_tc3;
uint8_t timer3_state;

/*** File Header ***/
void TIMER_COUNTER3_compoutmodeA(unsigned char compoutmode);
void TIMER_COUNTER3_compoutmodeB(unsigned char compoutmode);
void TIMER_COUNTER3_compoutmodeC(unsigned char compoutmode);
void TIMER_COUNTER3_compareA(uint16_t compare);
void TIMER_COUNTER3_compareB(uint16_t compare);
void TIMER_COUNTER3_compareC(uint16_t compare);
uint8_t TIMER_COUNTER3_start(unsigned int prescaler);
uint8_t TIMER_COUNTER3_stop(void);

/*** Procedure & Function ***/
TIMER_COUNTER3 TIMER_COUNTER3enable(unsigned char wavegenmode, unsigned char interrupt)
// PARAMETER SETTING
// wavegen mode: Normal; PWM, Phase Correct, 8-bit; PWM, Phase Correct, 9-bit; PWM, Phase Correct, 10-bit;
// CTC; Fast PWM, 8-bit; Fast PWM, 9-bit; Fast PWM, 10-bit; PWM, Phase and Frequency Correct; PWM, Phase and Frequency Correct;
// PWM, Phase Correct; PWM, Phase Correct; CTC; (Reserved); Fast PWM; Fast PWM.
// interrupt: off; overflow; output compare; both; default - non.
// for more information read data sheet.
{
	// ATMEGA128enable(); // Dependency
	
	timer3_state = 0;
	atmega128()->tc3.reg->tccr3a &= ~((1 << WGM31) | (1 << WGM30));
	atmega128()->tc3.reg->tccr3b &= ~((1 << WGM33) | (1 << WGM32));
	switch(wavegenmode){ // TOP -- Update of OCRnX -- TOV Flag Set on
		case 0: // Normal, 0xFFFF -- Immediate -- MAX
		break;
		case 1: // PWM Phase Correct 8-bit, 0x00FF -- TOP -- BOTTOM
			atmega128()->tc3.reg->tccr3a |= (1 << WGM30);
		break;
		case 2:	// PWM Phase Correct 9-bit, 0x01FF -- TOP -- BOTTOM
			atmega128()->tc3.reg->tccr3a |= (1 << WGM31);
		break;
		case 3:	// PWM Phase Correct 10-bit, 0x03FF -- TOP -- BOTTOM
			atmega128()->tc3.reg->tccr3a |= (1 << WGM31) | (1 << WGM30);
		break;
		case 4:	// CTC, OCRnA Immediate MAX
			atmega128()->tc3.reg->tccr3b |= (1 << WGM32);
		break;
		case 5:	// Fast PWM 8-bit, 0x00FF -- BOTTOM -- TOP
			atmega128()->tc3.reg->tccr3a |=(1 << WGM30);
			atmega128()->tc3.reg->tccr3b |= (1 << WGM32);
		break;
		case 6:	// Fast PWM 9-bit, 0x01FF -- BOTTOM -- TOP
			atmega128()->tc3.reg->tccr3a |= (1 << WGM31);
			atmega128()->tc3.reg->tccr3b |= (1 << WGM32);
		break;
		case 7:	// Fast PWM 10-bit, 0x03FF -- BOTTOM -- TOP
			atmega128()->tc3.reg->tccr3a |=(1 << WGM31) | (1 << WGM30);
			atmega128()->tc3.reg->tccr3b |= (1 << WGM32);
		break;
		case 8:	// PWM Phase and Frequency Correct, ICRnA -- BOTTOM -- BOTTOM
			atmega128()->tc3.reg->tccr3b |= (1 << WGM33);
		break;
		case 9:	// PWM Phase and Frequency Correct, OCRnA -- BOTTOM -- BOTTOM
			atmega128()->tc3.reg->tccr3a |= (1 << WGM30);
			atmega128()->tc3.reg->tccr3b |= (1 << WGM33);
		break;
		case 10: // PWM Phase Correct, ICRn -- TOP -- BOTTOM
			atmega128()->tc3.reg->tccr3a |=(1 << WGM31);
			atmega128()->tc3.reg->tccr3b |= (1 << WGM33);
		break;
		case 11: // PWM Phase Correct, OCRnA -- TOP -- BOTTOM
			atmega128()->tc3.reg->tccr3a |= (1 << WGM31) | (1 << WGM30);
			atmega128()->tc3.reg->tccr3b |= (1 << WGM33);
		break;
		case 12: // CTC, ICRn -- Immediate -- MAX
			atmega128()->tc3.reg->tccr3b |= (1 << WGM33) | (1 << WGM32);
		break;
		case 13: // (Reserved), -- -- --
			atmega128()->tc3.reg->tccr3a |= (1 << WGM30);
			atmega128()->tc3.reg->tccr3b |= (1 << WGM33) | (1 << WGM32);
		break;
		case 14: // Fast PWM, ICRn -- BOTTOM -- TOP
			atmega128()->tc3.reg->tccr3a |= (1 << WGM31);
			atmega128()->tc3.reg->tccr3b |= (1 << WGM33) | (1 << WGM32);
		break;
		case 15: // Fast PWM, OCRnA -- BOTTOM -- TOP
			atmega128()->tc3.reg->tccr3a |= (1 << WGM31) | (1 << WGM30);
			atmega128()->tc3.reg->tccr3b |= (1 << WGM33) | (1 << WGM32);
		break;
		default:
		break;
	}
	atmega128()->tc3.reg->tccr3a &= ~((3 << COM3A0) | (3 << COM3B0)| (3 << COM3C0));
	atmega128()->tc3.reg->etimsk &= ~((1 << TICIE3) | (1 << OCIE3A) | (1 << OCIE3B) | (1 << TOIE3) | (1 << OCIE3C));
	switch(interrupt){ // ICP3  -->  PE7
		case 0:
		break;
		case 1:
			atmega128()->tc3.reg->etimsk |= (1 << TOIE3);
			atmega128()->cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 2:
			atmega128()->tc3.reg->etimsk |= (1 << OCIE3A);
			atmega128()->cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 3:
			atmega128()->tc3.reg->etimsk |= (1 << OCIE3B);
			atmega128()->cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 4:
			atmega128()->tc3.reg->etimsk |= (1 << OCIE3C);
			atmega128()->cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 5:
			atmega128()->tc3.reg->etimsk |= (1 << TICIE3);
			atmega128()->cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 6:
			atmega128()->tc3.reg->etimsk |= (1 << OCIE3A) | (1 << TOIE3);
			atmega128()->cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 7:
			atmega128()->tc3.reg->etimsk |= (1 << OCIE3B) | (1 << TOIE3);
			atmega128()->cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 8:
			atmega128()->tc3.reg->etimsk |= (1 << TOIE3) | (1 << OCIE3C);
			atmega128()->cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 9:
			atmega128()->tc3.reg->etimsk |= (1 << TICIE3) | (1 << TOIE3);
			atmega128()->cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 10:
			atmega128()->tc3.reg->etimsk |= (1 << OCIE3A) | (1 << OCIE3B) | (1 << TOIE3);
			atmega128()->cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 11:
			atmega128()->tc3.reg->etimsk |= (1 << OCIE3A) | (1 << OCIE3B) | (1 << TOIE3) | (1 << OCIE3C);
			atmega128()->cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		case 12:
			atmega128()->tc3.reg->etimsk |= (1 << OCIE3A) | (1 << OCIE3B) | (1 << OCIE3C);
			atmega128()->cpu.reg->sreg |= 1 << GLOBAL_INTERRUPT_ENABLE;
		break;
		default:
		break;
	}
	atmega128()->tc3.reg->ocr3a = atmega128()->writehlbyte(~0);
	atmega128()->tc3.reg->ocr3b = atmega128()->writehlbyte(~0);
	atmega128()->tc3.reg->ocr3c = atmega128()->writehlbyte(~0);
	
	atmega128_tc3.compoutmodeA = TIMER_COUNTER3_compoutmodeA;
	atmega128_tc3.compoutmodeB = TIMER_COUNTER3_compoutmodeB;
	atmega128_tc3.compoutmodeC = TIMER_COUNTER3_compoutmodeC;
	atmega128_tc3.compareA = TIMER_COUNTER3_compareA;
	atmega128_tc3.compareB = TIMER_COUNTER3_compareB;
	atmega128_tc3.compareC = TIMER_COUNTER3_compareC;
	atmega128_tc3.start = TIMER_COUNTER3_start;
	atmega128_tc3.stop = TIMER_COUNTER3_stop;
	
	return atmega128_tc3;
}

TIMER_COUNTER3* tc3(void){ return &atmega128_tc3;}

uint8_t TIMER_COUNTER3_start(unsigned int prescaler)
// PARAMETER SETTING
// Frequency oscillator devision factor or prescaler.
// prescaler: clk T0S /(No prescaling); clk T0S /8 (From prescaler); clk T0S /64 (From prescaler);
// clk T0S /256 (From prescaler); clk T0S /1024 (From prescaler); External clock source on Tn pin. Clock on falling edge;
// External clock source on Tn pin. Clock on rising edge; default - clk T 0 S /1024 (From prescaler).
{
	if(!timer3_state){ // one shot
		atmega128()->tc3.reg->tccr3b &= ~(7 << CS30); // No clock source. (Timer/Counter stopped)
		switch(prescaler){
			//case 0: // No clock source. (Timer/Counter stopped)
			//break;
			case 1: // clkI/O/1 (No prescaler)
				atmega128()->tc3.reg->tccr3b |= (1 << CS30);
			break;
			case 8: // clkI/O/8 (From prescaler)
				atmega128()->tc3.reg->tccr3b |= (1 << CS31);
			break;
			case 64: // clkI/O/64 (From prescaler)
				atmega128()->tc3.reg->tccr3b |= (3 << CS30);
			break;
			case 256: // clkI/O/256 (From prescaler)
				atmega128()->tc3.reg->tccr3b |= (1 << CS32);
			break;
			case 1024: // clkI/O/1024 (From prescaler)
				atmega128()->tc3.reg->tccr3b |= (5 << CS30);
			break;
			case 6: // External clock source on Tn pin. Clock on falling edge [PE6]
				atmega128()->tc3.reg->tccr3b |= (6 << CS30);
			break;
			case 7: // External clock source on Tn pin. Clock on rising edge [PE6]
				atmega128()->tc3.reg->tccr3b |= (7 << CS30);
			break;
			default:
				atmega128()->tc3.reg->tccr3b |= (5 << CS30);
			break;
		}
		timer3_state = 85;
	}	
	return timer3_state;
}
void TIMER_COUNTER3_compoutmodeA(unsigned char compoutmode)
{
	atmega128()->tc3.reg->tccr3a &= ~(3 << COM3A0);
	switch(compoutmode){ // OC3A  -->  PE3
		case 0: // Normal port operation, OC3A disconnected.
		break;
		case 1: // Reserved
			// Toggle OC3A on compare match
			atmega128()->porte.reg->ddr |= 0x08;
			atmega128()->tc3.reg->tccr3a |= (1 << COM3A0);
		break;
		case 2: // Clear OC3A on compare match when up-counting. Set OC0 on compare
			// match when down counting.
			atmega128()->porte.reg->ddr |= 0x08;
			atmega128()->tc3.reg->tccr3a |= (1 << COM3A1);
		break;
		case 3: // Set OC3A on compare match when up-counting. Clear OC0 on compare
			// match when down counting.
			atmega128()->porte.reg->ddr |= 0x08;
			atmega128()->tc3.reg->tccr3a |= (1 << COM3A0) | (1 << COM3A1);
		break;
		default:
		break;
	}
}
void TIMER_COUNTER3_compoutmodeB(unsigned char compoutmode)
{
	atmega128()->tc3.reg->tccr3a &= ~(3 << COM3B0);
	switch(compoutmode){ // OC3B  -->  PE4
		case 0: // Normal port operation, OC3B disconnected.
		break;
		case 1: // Reserved
			// Toggle OC3A or OC3B on compare match
			atmega128()->porte.reg->ddr |= 0x10;
			atmega128()->tc3.reg->tccr3a |= (1 << COM3B0);
		break;
		case 2: // Clear OC3B on compare match when up-counting. Set OC3B on compare
			// match when down counting.
			atmega128()->porte.reg->ddr |= 0x10;
			atmega128()->tc3.reg->tccr3a |= (1 << COM3B1);
		break;
		case 3: // Set OC3B on compare match when up-counting. Clear OC3B on compare
			// match when down counting.
			atmega128()->porte.reg->ddr |= 0x10;
			atmega128()->tc3.reg->tccr3a |= (1 << COM3B0) | (1 << COM3B1);
		break;
		default:
		break;
	}
}
void TIMER_COUNTER3_compoutmodeC(unsigned char compoutmode)
{
	atmega128()->tc3.reg->tccr3a &= ~(3 << COM3C0);
	switch(compoutmode){ // OC3C  -->  PE5
		case 0: // Normal port operation, OC3C disconnected.
		break;
		case 1: // Reserved
			// Toggle OC3A or OC3C on compare match
			atmega128()->porte.reg->ddr |= 0x20;
			atmega128()->tc3.reg->tccr3a |= (1 << COM3C0);
		break;
		case 2: // Clear OC3C on compare match when up-counting. Set OC3C on compare
			// match when down counting.
			atmega128()->porte.reg->ddr |= 0x20;
			atmega128()->tc3.reg->tccr3a |= (1 << COM3C1);
		break;
		case 3: // Set OC3C on compare match when up-counting. Clear OC3C on compare
			// match when down counting.
			atmega128()->porte.reg->ddr |= 0x20;
			atmega128()->tc3.reg->tccr3a |= (1 << COM3C0) | (1 << COM3C1);
		break;
		default:
		break;
	}
}
void TIMER_COUNTER3_compareA(uint16_t compare)
{
	atmega128()->tc3.reg->ocr3a = atmega128()->writehlbyte(compare);
}
void TIMER_COUNTER3_compareB(uint16_t compare)
{
	atmega128()->tc3.reg->ocr3b = atmega128()->writehlbyte(compare);
}
void TIMER_COUNTER3_compareC(uint16_t compare)
{
	atmega128()->tc3.reg->ocr3c = atmega128()->writehlbyte(compare);
}
uint8_t TIMER_COUNTER3_stop(void)
// stops timer by setting prescaler to zero
{
	atmega128()->tc3.reg->tccr3b &= ~(7 << CS30); // No clock source. (Timer/Counter stopped)
	timer3_state = 0;
	return timer3_state;
}

/***EOF***/

