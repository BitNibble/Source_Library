/*************************************************************************
	ANALOG
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328
Update: 01/01/2024
*************************************************************************/
/****** Comment:
	Very Stable
*************************************************************************/
/*** File Library ***/
#include "atmega328mapping.h"
#include "atmega328analog.h"
#include <stdarg.h>

/*** File Variable ***/
static ANALOG setup_analog;
static volatile int ADC_VALUE[MAX_CHANNEL];
static volatile int ADC_CHANNEL_GAIN[MAX_CHANNEL];
static volatile int ADC_N_CHANNEL;
static volatile int ADC_SELECTOR;
static volatile int adc_sample;
static volatile int adc_tmp;
static volatile unsigned char adc_n_sample;

/*** File Header ***/
int ANALOG_read(int selection);

/*** Procedure & Function ***/
ANALOG ANALOG_enable( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... )
// Interrupt running mode setup
// setup, and list of channels to be probed
{
	uint8_t tSREG;
	va_list list;
	int i;

	tSREG = atmega328()->cpu_reg->sreg;
	atmega328()->cpu_reg->sreg &= ~ (1 << GLOBAL_INTERRUPT_ENABLE);
	
	ADC_N_CHANNEL = n_channel;
	ADC_SELECTOR = 0;
	adc_n_sample = 0;

	//V table
	setup_analog.read = ANALOG_read;
	
	atmega328()->adc_reg->admux &= ~(3 << REFS0);
	switch( Vreff ){
		case 0:
			setup_analog.par.VREFF = 0;
		break;
		case 1:
			atmega328()->adc_reg->admux |=	(1 << REFS0);
			setup_analog.par.VREFF = 1;
		break;
		case 3:
			atmega328()->adc_reg->admux |=	(3 << REFS0);
			setup_analog.par.VREFF = 3;
		break;
		default:
			setup_analog.par.VREFF = 0;
		break;
	}
	
	atmega328()->adc_reg->admux &= ~(1 << ADLAR);
	
	va_start(list, n_channel);
	for( i = 0; i < n_channel; i++ ){
		ADC_CHANNEL_GAIN[i] = va_arg(list, int);
	}
	va_end(list);
	atmega328()->adc_reg->admux &= ~MUX_MASK;
	atmega328()->adc_reg->admux |= (MUX_MASK & ADC_CHANNEL_GAIN[ADC_SELECTOR]);
	
	atmega328()->adc_reg->adcsra |= (1 << ADEN);
	atmega328()->adc_reg->adcsra |= (1 << ADSC);
	atmega328()->adc_reg->adcsra &= ~(1 << ADATE);
	atmega328()->adc_reg->adcsrb &= ~(7 << ADTS0);
	atmega328()->adc_reg->adcsra |= (1 << ADIE);
	
	atmega328()->adc_reg->adcsra &= ~(7 << ADPS0);
	switch( Divfactor ){
		case 2: // 1
			setup_analog.par.DIVISION_FACTOR = 2;
		break;
		case 4: // 2
			atmega328()->adc_reg->adcsra |= (1 << ADPS1);
			setup_analog.par.DIVISION_FACTOR = 4;
		break;
		case 8: // 3
			atmega328()->adc_reg->adcsra |= (3 << ADPS0);
			setup_analog.par.DIVISION_FACTOR = 8;
		break;
		case 16: // 4
			atmega328()->adc_reg->adcsra |= (1 << ADPS2);
			setup_analog.par.DIVISION_FACTOR	=	16;
		break;
		case 32: // 5
			atmega328()->adc_reg->adcsra |= (5 << ADPS0);
			setup_analog.par.DIVISION_FACTOR = 32;
		break;
		case 64: // 6
			atmega328()->adc_reg->adcsra |= (6 << ADPS0);
			setup_analog.par.DIVISION_FACTOR = 64;
		break;
		case 128: // 7
			atmega328()->adc_reg->adcsra |= (7 << ADPS0);
			setup_analog.par.DIVISION_FACTOR = 128;
		break;
		default: // 7
			atmega328()->adc_reg->adcsra |= (7 << ADPS0);
			setup_analog.par.DIVISION_FACTOR = 128;
		break;
	}
	atmega328()->cpu_reg->sreg = tSREG;
	atmega328()->cpu_reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);

	return setup_analog;
}

ANALOG* adc(void){ return &setup_analog; }

int ANALOG_read(int selection)
// Returns selected Channel ADC_VALUE
{
	uint8_t ADSC_FLAG;
	ADSC_FLAG = (1 << ADSC);
	if( !(atmega328()->adc_reg->adcsra & ADSC_FLAG) ){
		//ADC_SELECT
		atmega328()->adc_reg->adcsra |= (1 << ADSC);
	}	
	return ADC_VALUE[selection];
}

/*** File Interrupt ***/
ISR(ANALOG_INTERRUPT)
// Function: ANALOG interrupt
// Purpose:  Read Analog Input
{
	adc_tmp = ADCL;
	adc_tmp |= (ADCH << 8);
	if(adc_n_sample < (1 << ADC_NUMBER_SAMPLE)){
		adc_n_sample++;
		adc_sample += adc_tmp;
	}else{
		ADC_VALUE[ADC_SELECTOR] = adc_sample >> ADC_NUMBER_SAMPLE;
		adc_n_sample=adc_sample = 0;
		/******/
		if(ADC_SELECTOR < ADC_N_CHANNEL)
			ADC_SELECTOR++;
		else
			ADC_SELECTOR = 0;
		atmega328()->adc_reg->admux &= ~MUX_MASK;
		atmega328()->adc_reg->admux |= (ADC_CHANNEL_GAIN[ADC_SELECTOR] & MUX_MASK);
	}		
}

/***EOF***/

