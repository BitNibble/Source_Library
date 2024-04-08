/***************************************************************************************************
	PCF8575
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: PCF8575
Date: 24012024
Comment:
	
***************************************************************************************************/
/*** File Library ***/
#include "pcf8575.h"

#if defined(__AVR_ATmega64__) || defined(__AVR_Atmega328__)
	#include "Atmega328mapping.h"
#elif defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
	#include "atmega328mapping.h"
#else
	#error "MCU Lib not available"
#endif

/*** File Header ***/
void PCF8575_writehbits( pcf8575_parameter *par, uint16_t hbits, uint8_t bool );
uint16_t PCF8575_readhbits( pcf8575_parameter *par, uint16_t hbits );

#ifdef _TWI_MODULE_

/*** Procedure & Function ***/
PCF8575 pcf8575_enable(uint8_t pcf8575_id, uint8_t twi_prescaler)
{
	PCF8575 setup_pcf8575;
	twi_enable(85, twi_prescaler); // Initialize the I2c module.
	
	setup_pcf8575.par.pcf8575_id = pcf8575_id;
	setup_pcf8575.par.state = 0xFFFF;
	
	// Vtable
	setup_pcf8575.writehbits = PCF8575_writehbits;
	setup_pcf8575.readhbits = PCF8575_readhbits;
	
	return setup_pcf8575;
}

void PCF8575_writehbits(pcf8575_parameter *par, uint16_t hbits, uint8_t bool)
{
	if(bool) par->state |= hbits; else par->state &= ~hbits;
	twi()->start();
	twi()->connect(par->pcf8575_id,TWI_WRITE);
	twi()->master_write(writehlbyte(par->state).par.L);
	twi()->master_write(writehlbyte(par->state).par.H);
	twi()->stop();
}

uint16_t PCF8575_readhbits(pcf8575_parameter *par, uint16_t hbits)
{
	HighLowByte data;
	twi()->start();
	twi()->connect(par->pcf8575_id, TWI_READ);
	data.par.L = twi()->master_read(TWI_ACK);
	data.par.H = twi()->master_read(TWI_NACK);
	twi()->stop();
	return (readhlbyte(data) & hbits);
}

#endif

/***File Interrupt***/

/*** EOF ***/

