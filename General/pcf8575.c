/***************************************************************************************************
	PCF8575
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: PCF8575
Date: 24012024
***************************************************************************************************/
/****** Comment:
	Stable
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
void PCF8575_writehbits(uint16_t hbits, uint8_t bool);
uint16_t PCF8575_readhbits(uint16_t hbits);

#ifdef _TWI_MODULE_

/*** Procedure & Function ***/
PCF8575 pcf8575_enable(uint8_t prescaler)
{
	PCF8575 setup_pcf8575;
	twi_enable('A', prescaler); // Initialize the I2c module.
	// Vtable
	setup_pcf8575.writehbits = PCF8575_writehbits;
	setup_pcf8575.readhbits = PCF8575_readhbits;
	
	return setup_pcf8575;
}

void PCF8575_writehbits(uint16_t hbits, uint8_t bool)
{
	static uint16_t mask = 0xFFFF;
	if(bool) mask |= hbits; else mask &= ~hbits;
	twi()->start();
	twi()->connect(PCF8575_ADDR,TWI_WRITE);
	twi()->master_write(writelhbyte(mask).L);
	twi()->master_write(writelhbyte(mask).H);
	twi()->stop();
}

uint16_t PCF8575_readhbits(uint16_t hbits)
{
	HighLowByte data;
	twi()->start();
	twi()->connect(PCF8575_ADDR, TWI_READ);
	data.L = twi()->master_read(TWI_ACK);
	data.H = twi()->master_read(TWI_NACK);
	twi()->stop();
	return (readlhbyte(data) & hbits);
}

#endif

/***File Interrupt***/

/***EOF***/

