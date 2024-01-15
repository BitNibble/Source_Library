/************************************************************************
	ATMEGA128TIMER1
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Update: 07/01/2024
Comment:
	Stable
************************************************************************/
/*** Preamble Inic ***/
#ifndef _ATMEGA128TIMER1_H_
	#define _ATMEGA128TIMER1_H_

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
struct tmr_cntr1{
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
typedef struct tmr_cntr1 TIMER_COUNTER1;

/*** Global Header ***/
TIMER_COUNTER1* tc1(void);
TIMER_COUNTER1 TIMER_COUNTER1_enable(unsigned char wavegenmode, unsigned char interrupt);

#endif
/***EOF***/

