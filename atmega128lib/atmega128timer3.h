/************************************************************************
	ATMEGA128TIMER3
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Update: 01/01/2024
Comment:
	Stable
************************************************************************/
/*** Preamble Inic ***/
#ifndef _ATMEGA128TIMER3_H_
	#define _ATMEGA128TIMER3_H_

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
struct tmr_cntr3{
	// prototype pointers
	void (*compoutmodeA)(unsigned char compoutmode);
	void (*compoutmodeB)(unsigned char compoutmode);
	void (*compoutmodeC)(unsigned char compoutmode);
	void (*compareA)(uint16_t compareA);
	void (*compareB)(uint16_t compareB);
	void (*compareC)(uint16_t compareC);
	uint8_t (*start)(unsigned int prescaler);
	uint8_t (*stop)(void);
};
typedef struct tmr_cntr3 TIMER_COUNTER3;

TIMER_COUNTER3 tc3;
/*** Global Header ***/
TIMER_COUNTER3 TIMER_COUNTER3enable(unsigned char wavegenmode, unsigned char interrupt);

#endif
/***EOF***/

