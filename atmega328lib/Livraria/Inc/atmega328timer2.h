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
#ifndef _ATMEGA328TIMER2_H_
	#define _ATMEGA328TIMER2_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#if defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
	#ifndef GLOBAL_INTERRUPT_ENABLE
		#define GLOBAL_INTERRUPT_ENABLE 7
	#endif
#else
	#error "Not Atmega 328"
#endif

/*** Global variable ***/
struct TIMER_COUNTER2{
	// prototype pointer
	void (*compoutmodeA)(unsigned char compoutmode);
	void (*compoutmodeB)(unsigned char compoutmode);
	void (*compareA)(unsigned char compare);
	void (*compareB)(unsigned char compare);
	void (*start)(unsigned int prescaler);
	void (*stop)(void);
};
typedef struct TIMER_COUNTER2 TIMER_COUNTER2;

TIMER_COUNTER2 TIMER_COUNTER2_enable(unsigned char wavegenmode, unsigned char interrupt);
TIMER_COUNTER2* tc2(void);

#endif

/***EOF***/


// ISR(TIMER2_COMPA_vect){}
// ISR(TIMER2_COMPB_vect){}
// ISR(TIMER2_OVF_vect){}
// ISR(TIMER1_CAPT_vect){}
// ISR(TIMER1_COMPA_vect){}
// ISR(TIMER1_COMPB_vect){}
// ISR(TIMER1_OVF_vect){}
// ISR(TIMER0_COMPA_vect){}
// ISR(TIMER0_COMPB_vect){}
// ISR(TIMER0_OVF_vect){}

