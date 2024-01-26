/************************************************************************
	ATMEGA128TIMER2
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Update: 07/01/2024
Comment:
	Stable
************************************************************************/
/*** Preamble Inic ***/
#ifndef _ATMEGA128TIMER2_H_
	#define _ATMEGA128TIMER2_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Constant & Macro ***/
#ifndef ATMEGA_128_TIMER_COUNTER
	#define ATMEGA_128_TIMER_COUNTER

#ifndef GLOBAL_INTERRUPT_ENABLE
	#define GLOBAL_INTERRUPT_ENABLE 7
#endif

#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
#else
	#error "Not Atmega 128"
#endif

#endif


/*** Global Variable ***/
typedef struct{
	// prototype pointers
	void (*compoutmode)(unsigned char compoutmode);
	void (*compare)(unsigned char compare);
	uint8_t (*start)(unsigned int prescaler);
	uint8_t (*stop)(void);
}TC2;

/*** Global Header ***/
TC2* tc2(void);
TC2 tc2_enable(unsigned char wavegenmode, unsigned char interrupt);

#endif
/***EOF***/

