/***************************************************************************************************
	PCF8575
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: PCF8575
Date: 24012024
***************************************************************************************************/
/****** Comment:
	Allow to create up to four instances of pcf8575.
 **************************************************************************************************/
/*** File Library ***/
#include "pcf8575.h"
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
	#include "atmega128mapping.h"
#elif defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
	#include "atmega328mapping.h"
#else
	#error "MCU Lib not available"
#endif

/*** File Header ***/
void PCF8575_writehbits( pcf8575_parameter par, uint16_t hbits, uint8_t bool );
uint16_t PCF8575_readhbits( pcf8575_parameter par, uint16_t hbits );

#ifdef _TWI_MODULE_

/*** Procedure & Function ***/
PCF8575 pcf8575_enable(uint8_t pcf8575_id, uint8_t twi_prescaler)
{
	PCF8575 setup_pcf8575;
	static uint8_t N_pcf8575 = 0;
	twi_enable(85, twi_prescaler); // Initialize the I2c module.
	
	setup_pcf8575.par.pcf8575_id = pcf8575_id;
	setup_pcf8575.par.N_pcf8575 = N_pcf8575;
	
	if(++N_pcf8575 > 3) N_pcf8575 = 3;
	
	// Vtable
	setup_pcf8575.writehbits = PCF8575_writehbits;
	setup_pcf8575.readhbits = PCF8575_readhbits;
	
	return setup_pcf8575;
}

void PCF8575_writehbits(pcf8575_parameter par, uint16_t hbits, uint8_t bool)
{
	static uint16_t mask[N_Instance_PCF8575] = { 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF };
	if(bool) mask[par.N_pcf8575] |= hbits; else mask[par.N_pcf8575] &= ~hbits;
	twi()->start();
	twi()->connect(par.pcf8575_id,TWI_WRITE);
	twi()->master_write(writehlbyte(mask[par.N_pcf8575]).L);
	twi()->master_write(writehlbyte(mask[par.N_pcf8575]).H);
	twi()->stop();
}

uint16_t PCF8575_readhbits(pcf8575_parameter par, uint16_t hbits)
{
	HighLowByte data;
	twi()->start();
	twi()->connect(par.pcf8575_id, TWI_READ);
	data.L = twi()->master_read(TWI_ACK);
	data.H = twi()->master_read(TWI_NACK);
	twi()->stop();
	return (readhlbyte(data) & hbits);
}

#endif

/***File Interrupt***/

/***EOF***/

