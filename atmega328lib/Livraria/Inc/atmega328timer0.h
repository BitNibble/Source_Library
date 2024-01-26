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
#ifndef _ATMEGA328TIMER0_H_
	#define _ATMEGA328TIMER0_H_

/*** Global Library ***/
#include <inttypes.h>

#ifndef GLOBAL_INTERRUPT_ENABLE
	#define GLOBAL_INTERRUPT_ENABLE 7
#endif

/*** Global variable ***/
typedef struct{
	// prototype pointer
	void (*compoutmodeA)(unsigned char compoutmode);
	void (*compoutmodeB)(unsigned char compoutmode);
	void (*compareA)(unsigned char compare);
	void (*compareB)(unsigned char compare);
	void (*start)(unsigned int prescaler);
	void (*stop)(void);
}TC0;

TC0 tc0_enable(unsigned char wavegenmode, unsigned char interrupt);
TC0* tc0(void);

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

