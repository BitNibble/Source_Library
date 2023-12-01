/************************************************************************
	ANALOG
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328
Date: 01122023
Comment:
	Very Stable
************************************************************************/
#ifndef _ATMEGA328ANALOG_H_
	#define _ATMEGA328ANALOG_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#define ADC_NUMBER_SAMPLE 2 // ADC_NUMBER_SAMPLE^2 gives number of samples, note values can only range from 0 to 4.

/*** Global Variable ***/
typedef struct {
	uint8_t VREFF;
	uint8_t DIVISION_FACTOR;
}analogparameter;

struct analog {
	analogparameter par;
	int (*read)(int selection);
};
typedef struct analog ANALOG;

/***Global Header***/
ANALOG ANALOGenable( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... );

#endif

/***EOF***/

