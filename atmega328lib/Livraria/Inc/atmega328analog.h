/************************************************************************
	ANALOG
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328
Update: 01/01/2024
************************************************************************/
/****** Comment:
	Very Stable
************************************************************************/
#ifndef _ATMEGA328ANALOG_H_
	#define _ATMEGA328ANALOG_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#ifndef GLOBAL_INTERRUPT_ENABLE
	#define GLOBAL_INTERRUPT_ENABLE 7
#endif
#define MAX_CHANNEL 8 // if using differential channels this value has to be greater than one
#define ADC_NUMBER_SAMPLE 2 // ADC_NUMBER_SAMPLE^2 gives number of samples, note values can only range from 0 to 4.
#define MUX_MASK 15
#define ANALOG_INTERRUPT ADC_vect
/*** Global Variable ***/
typedef struct {
	uint8_t VREFF;
	uint8_t DIVISION_FACTOR;
}analog_parameter;

typedef struct{
	analog_parameter par;
	int (*read)(int selection);
}ADC0;

ADC0 adc_enable( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... );
ADC0* adc(void);

#endif

/***EOF***/

