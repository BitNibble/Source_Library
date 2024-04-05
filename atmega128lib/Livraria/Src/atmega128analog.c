/*************************************************************************
	ATMEGA128ANALOG
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Update: 07/01/2024
Comment:
	Stable
*************************************************************************/
/*** File Library ***/
#include "atmega128analog.h"
#include <stdarg.h>

/*** File Variable ***/
static ADC0 atmega128_adc;
static Atmega128AnalogToDigitalConverter_TypeDef* atmega128_adc_handle;

static volatile int ADC_VALUE[MAX_CHANNEL];
static volatile int ADC_CHANNEL_GAIN[MAX_CHANNEL];
int ADC_N_CHANNEL;
static volatile int ADC_SELECTOR;
static volatile int adc_sample;
uint16_t adc_tmp;
static volatile unsigned char adc_n_sample;

/*** File Header ***/
int ANALOG_read(int selection);

/*** Procedure & Function ***/
ADC0 adc_enable( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... )
// Interrupt running mode setup, and list of channels to be probed
{
	// ATMEGA128enable();
	atmega128_adc_handle = (Atmega128AnalogToDigitalConverter_TypeDef*) Atmega128AnalogToDigitalConverter_Address;

	// LOCAL VARIABLES
	va_list list;
	int i;
	// Initialize variables
	ADC_N_CHANNEL = (n_channel & MUX_MASK);
	ADC_SELECTOR = 0;
	adc_n_sample = 0;
	
	//atmega128_adc_handle->admux.reg &= ~(3 << REFS0);
	atmega128_adc_handle->admux.par.refs = 0;
	switch( Vreff ){
		case 0:
			atmega128_adc.par.VREFF = 0;
		break;
		case 1:
			//atmega128_adc_handle->admux.reg |= (1 << REFS0);
			atmega128_adc_handle->admux.par.refs = 1;
			atmega128_adc.par.VREFF = 1;
		break;
		case 3:
			//atmega128_adc_handle->admux.reg |= (3 << REFS0);
			atmega128_adc_handle->admux.par.refs = 3;
			atmega128_adc.par.VREFF = 3;
		break;
		default:
			atmega128_adc.par.VREFF = 0;
		break;
	}
		
	//atmega128_adc_handle->admux.reg &= ~(1 << ADLAR);
	atmega128_adc_handle->admux.par.adlar = 0;
	// atmega128.adc->admux |= (1 << ADLAR);
	
	va_start(list, n_channel);
	for(i = 0; i < n_channel; i++){
		ADC_CHANNEL_GAIN[i] = va_arg(list, int);
	}
	va_end(list);
	
	//atmega128_adc_handle->admux.reg &= ~MUX_MASK;
	atmega128_adc_handle->admux.par.mux = 0;
	//atmega128_adc_handle->admux.reg |= (MUX_MASK & ADC_CHANNEL_GAIN[ADC_SELECTOR]);
	atmega128_adc_handle->admux.par.mux = ADC_CHANNEL_GAIN[ADC_SELECTOR] & MUX_MASK;
	
	//atmega128_adc_handle->adcsra.reg |= (1 << ADSC);
	atmega128_adc_handle->adcsra.par.adsc = 1;
	//atmega128_adc_handle->adcsra.reg &= ~(1 << ADFR);
	atmega128_adc_handle->adcsra.par.adfr = 0;
	//atmega128_adc_handle->adcsra.reg |= (1 << ADIE);
	atmega128_adc_handle->adcsra.par.adie = 1;
	//atmega128_adc_handle->adcsra.reg &= ~(7 << ADPS0);
	atmega128_adc_handle->adcsra.par.adps = 0;
	
	switch( Divfactor ){
		case 2: // 1
			//atmega128_adc_handle->adcsra.reg |= (1 << ADPS0);
			atmega128_adc_handle->adcsra.par.adps = 1;
			atmega128_adc.par.DIVISION_FACTOR = 2;
		break;
		case 4: // 2
			//atmega128_adc_handle->adcsra.reg |= (1 << ADPS1);
			atmega128_adc_handle->adcsra.par.adps = 2;
			atmega128_adc.par.DIVISION_FACTOR = 4;
		break;
		case 8: // 3
			//atmega128_adc_handle->adcsra.reg |= (3 << ADPS0);
			atmega128_adc_handle->adcsra.par.adps = 3;
			atmega128_adc.par.DIVISION_FACTOR = 8;
		break;
		case 16: // 4
			//atmega128_adc_handle->adcsra.reg |= (1 << ADPS2);
			atmega128_adc_handle->adcsra.par.adps = 4;
			atmega128_adc.par.DIVISION_FACTOR = 16;
		break;
		case 32: // 5
			//atmega128_adc_handle->adcsra.reg |= (5 << ADPS0);
			atmega128_adc_handle->adcsra.par.adps = 5;
			atmega128_adc.par.DIVISION_FACTOR = 32;
		break;
		case 64: // 6
			//atmega128_adc_handle->adcsra.reg |= (6 << ADPS0);
			atmega128_adc_handle->adcsra.par.adps = 6;
			atmega128_adc.par.DIVISION_FACTOR = 64;
		break;
		case 128: // 7
			//atmega128_adc_handle->adcsra.reg |= (7 << ADPS0);
			atmega128_adc_handle->adcsra.par.adps = 7;
			atmega128_adc.par.DIVISION_FACTOR = 128;
		break;
		default:
			//atmega128_adc_handle->adcsra.reg |= (7 << ADPS0);
			atmega128_adc_handle->adcsra.par.adps = 7;
			atmega128_adc.par.DIVISION_FACTOR = 128;
		break;
	}
	
	//atmega128_adc_handle->adcsra.reg |= (1 << ADEN);
	atmega128_adc_handle->adcsra.par.aden = 1;
	
	atmega128_adc.handle = (Atmega128AnalogToDigitalConverter_TypeDef*) Atmega128AnalogToDigitalConverter_Address;
	atmega128_adc.read = ANALOG_read;
	cpu_handle()->sreg.reg |= (1 << GLOBAL_INTERRUPT_ENABLE);
	
	return atmega128_adc;
}

ADC0* adc(void){ return &atmega128_adc; }

int ANALOG_read(int selection)
// Returns selected Channel ADC_VALUE
{
	//uint8_t ADSC_FLAG;
	//ADSC_FLAG = (1 << ADSC);
	//if( !(atmega128_adc_handle->adcsra.reg & ADSC_FLAG) ){
	if( !atmega128_adc_handle->adcsra.par.adsc ){
		// ADC_SELECT
		//atmega128_adc_handle->adcsra.reg |= (1 << ADSC);
		atmega128_adc_handle->adcsra.par.adsc = 1;
	}	
	return ADC_VALUE[selection];
}

/*** File Interrupt ***/
ISR(ADC_vect)
// Function: ANALOG interrupt
// Purpose:  Read Analog Input
{
	// adc_tmp = atmega128.adc->adc.L; // ADCL
	// adc_tmp |= (atmega128.adc->adc.H << 8); // (ADCH << 8);
	// adc_tmp = *((uint16_t*)&m.adc->adc); // more then one way to skin a rabbit.
	adc_tmp = readhlbyte(atmega128_adc_handle->adc);
	if(adc_n_sample < (1 << ADC_NUMBER_SAMPLE)){
		adc_n_sample++;
		adc_sample += adc_tmp;
	}else{
		ADC_VALUE[ADC_SELECTOR] = adc_sample >> ADC_NUMBER_SAMPLE;
		adc_n_sample = adc_sample = 0;
		
		if(ADC_SELECTOR < ADC_N_CHANNEL)
			ADC_SELECTOR++;
		else
			ADC_SELECTOR = 0;
		//atmega128_adc_handle->admux.reg &= ~MUX_MASK;
		atmega128_adc_handle->admux.par.mux = 0;
		//atmega128_adc_handle->admux.reg |= (ADC_CHANNEL_GAIN[ADC_SELECTOR] & MUX_MASK);
		atmega128_adc_handle->admux.par.mux = ADC_CHANNEL_GAIN[ADC_SELECTOR] & MUX_MASK;
	}
}

/***EOF***/

