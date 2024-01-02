/************************************************************************
	ATMEGA128INTERRUPT
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Update: 01/01/2024
Comment:
	Stable
************************************************************************/
#ifndef _ATMEGA128INTERRUPT_H_
	#define _ATMEGA128INTERRUPT_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
	#ifndef GLOBAL_INTERRUPT_ENABLE
		#define GLOBAL_INTERRUPT_ENABLE 7
	#endif
#else
	#error "Not Atmega 128"
#endif

/*** Global Variable ***/
struct ntrrpt{
	void (*set)(uint8_t channel, uint8_t sense);
	void (*off)(uint8_t channel);
	void (*on)(uint8_t channel);
	uint8_t (*reset_status)(void);
};
typedef struct ntrrpt INTERRUPT;

INTERRUPT exint;
/*** Global Header ***/
INTERRUPT INTERRUPTenable(void);

#endif
/***EOF***/

