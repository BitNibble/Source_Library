/*************************************************************************
	TIMER
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Date: 01122023
Comment:
	Very Stable
*************************************************************************/
#ifndef _ATMEGA328TIMER_H_
	#define _ATMEGA328TIMER_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#ifndef GLOBAL_INTERRUPT_ENABLE
	#define GLOBAL_INTERRUPT_ENABLE 7
#endif

/*** Global variable ***/
struct TIMER_COUNTER0{
	// prototype pointer
	void (*compoutmodeA)(unsigned char compoutmode);
	void (*compoutmodeB)(unsigned char compoutmode);
	void (*compareA)(unsigned char compare);
	void (*compareB)(unsigned char compare);
	void (*start)(unsigned int prescaler);
	void (*stop)(void);
};
typedef struct TIMER_COUNTER0 TIMER_COUNTER0;

struct TIMER_COUNTER1{
	// prototype pointers
	void (*compoutmodeA)(unsigned char compoutmode);
	void (*compoutmodeB)(unsigned char compoutmode);
	void (*compareA)(uint16_t compareA);
	void (*compareB)(uint16_t compareB);
	void (*start)(unsigned int prescaler);
	void (*stop)(void);
};
typedef struct TIMER_COUNTER1 TIMER_COUNTER1;

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

/*** Global header ***/
//TIMER_COUNTER0 tc0;
//TIMER_COUNTER1 tc1;
//TIMER_COUNTER2 tc2;

TIMER_COUNTER0 TIMER_COUNTER0enable(unsigned char wavegenmode, unsigned char interrupt);
TIMER_COUNTER1 TIMER_COUNTER1enable(unsigned char wavegenmode, unsigned char interrupt);
TIMER_COUNTER2 TIMER_COUNTER2enable(unsigned char wavegenmode, unsigned char interrupt);

/*** File Header ***/
//void TIMER_COUNTER0_compoutmodeA(unsigned char compoutmode);
//void TIMER_COUNTER0_compoutmodeB(unsigned char compoutmode);
//void TIMER_COUNTER0_compareA(unsigned char compare);
//void TIMER_COUNTER0_compareB(unsigned char compare);
//void TIMER_COUNTER0_start(unsigned int prescaler);
//void TIMER_COUNTER0_stop(void);

//void TIMER_COUNTER1_compoutmodeA(unsigned char compoutmode);
//void TIMER_COUNTER1_compoutmodeB(unsigned char compoutmode);
//void TIMER_COUNTER1_compareA(uint16_t compare);
//void TIMER_COUNTER1_compareB(uint16_t compare);
//void TIMER_COUNTER1_start(unsigned int prescaler);
//void TIMER_COUNTER1_stop(void);

//void TIMER_COUNTER2_compoutmodeA(unsigned char compoutmode);
//void TIMER_COUNTER2_compoutmodeB(unsigned char compoutmode);
//void TIMER_COUNTER2_compareA(unsigned char compare);
//void TIMER_COUNTER2_compareB(unsigned char compare);
//void TIMER_COUNTER2_start(unsigned int prescaler);
//void TIMER_COUNTER2_stop(void);

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

