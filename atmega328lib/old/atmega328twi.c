/***************************************************************************************************
	TWI API
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update: 01/01/2024
Comment:
	Stable
***************************************************************************************************/
/*** File Library ***/
#include "atmega328mapping.h"
#include "atmega328twi.h"
#include <util/delay.h>

/*** File Define and Macro ***/

/*** File Variable ***/

/*** File Header ***/
void TWI_init(uint8_t device_id, uint8_t prescaler);
void TWI_start(void);
void TWI_connect(uint8_t address, uint8_t rw);
void TWI_master_write(uint8_t var_twiData_u8);
uint8_t TWI_master_read(uint8_t ack_nack);
void TWI_stop(void);
// auxiliary
uint8_t TWI_status(void);
void TWI_wait_twint( uint16_t nticks );

/*** Procedure and Function ***/
TWI TWIenable(uint8_t atmega_ID,  uint8_t prescaler)
{
	//local var
	uint8_t tSREG;
	TWI ic;
	//inic file var
	ATMEGA328enable();
	//inic local var
	tSREG = atmega328.cpu.reg->sreg;
	atmega328.cpu.reg->sreg &= ~(1<<GLOBAL_INTERRUPT_ENABLE);
	// Vtable
	ic.start = TWI_start;
	ic.connect = TWI_connect;
	ic.stop = TWI_stop;
	ic.master_write = TWI_master_write;
	ic.master_read = TWI_master_read;
	ic.status = TWI_status;
	
	TWI_init(atmega_ID, prescaler);
	atmega328.cpu.reg->sreg = tSREG;

	return ic;
}
// void TWI_Init(uint8_t device_id, uint8_t prescaler)
void TWI_init(uint8_t device_id, uint8_t prescaler)
{
	uint8_t cmd = 0x00;
	if(device_id > 0 && device_id < 128)
		cmd = (device_id << 1) | (1 << TWGCE);
	else
		cmd = (1 << TWGCE); // no address, but accept general call
	atmega328.twi.reg->twar = cmd;
	atmega328.portd.reg->ddr |= TWI_IO_MASK;
	atmega328.portd.reg->port |= TWI_IO_MASK;
	switch(prescaler){
		case 1:
			atmega328.twi.reg->twsr &= ~TWI_PRESCALER_MASK;
		break;
		case 4:
			atmega328.twi.reg->twsr |= (1 << TWPS0);
		break;
		case 16:
			atmega328.twi.reg->twsr |= (2 << TWPS0);
		break;
		case 64:
			atmega328.twi.reg->twsr |= (3 << TWPS0);
		break;
		default:
			prescaler = 1;
			atmega328.twi.reg->twsr &= ~TWI_PRESCALER_MASK;
		break;
	}
	atmega328.twi.reg->twbr = ((F_CPU / TWI_SCL_CLOCK) - 16) / (2 * prescaler);
	// Standard Config begin
	//atmega328.twi->twsr = 0x00; //set presca1er bits to zero
	//atmega328.twi->twbr = 0x46; //SCL frequency is 50K for 16Mhz
	//atmega328.twi->twcr = 0x04; //enab1e TWI module
	// Standard Config end
}
// void TWI_Start(void)
void TWI_start(void) // $08
{
	uint8_t cmd = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);
	atmega328.twi.reg->twcr = cmd;
	
	TWI_wait_twint( Nticks );
	
	switch( TWI_status( ) ){
		case TWI_T_START:
			// Do nothing
		break;
		default:
			TWI_stop( ); // error
		break;
	}
}
// void TWI_Connect(uint8_t address, uint8_t rw)
void TWI_connect( uint8_t address, uint8_t rw )
{
	uint8_t cmd = 0;
	if( rw )
		cmd = (address << 1) | (1 << 0);
	else
		cmd = (address << 1) | (0 << 0);
	atmega328.twi.reg->twdr = cmd;
	
	cmd = (1 << TWINT) | (1 << TWEN);
	atmega328.twi.reg->twcr = cmd;
	
	TWI_wait_twint( Nticks );
	
	switch( TWI_status( ) ){
		case TWI_M_SLAW_R_ACK:
			// Do nothing
		break;
		case TWI_M_SLAR_R_ACK:
			// Do nothing
		break;
		default:
			TWI_stop( ); // error
		break;
	}
}
// void TWI_Write(uint8_t var_twiData_u8)
void TWI_master_write( uint8_t var_twiData_u8 )
{
	uint8_t cmd = var_twiData_u8;
	atmega328.twi.reg->twdr = cmd;
	
	cmd = (1 << TWINT) | (1 << TWEN);
	atmega328.twi.reg->twcr = cmd;
	
	TWI_wait_twint( Nticks );
	
	switch( TWI_status( ) ){
		case TWI_M_DATABYTE_R_ACK:
			// Do nothing
		break;
		default:
			TWI_stop( ); // error
		break;
	}
}
// uint8_t TWI_Read(uint8_t ack_nack)
uint8_t TWI_master_read( uint8_t ack_nack )
{
	uint8_t cmd = 0x00;
	if( ack_nack )
		cmd |= ( 1 << TWEA );
	cmd |= ( 1 << TWINT ) | ( 1 << TWEN );
	atmega328.twi.reg->twcr = cmd;
	
	TWI_wait_twint( Nticks );
	
	switch( TWI_status( ) ){
		case TWI_ARBLSLARNACK:
			TWI_stop( );
		break;
		default:
		break;
	}
	
	cmd = atmega328.twi.reg->twdr;
	return cmd;
}
// void TWI_stop(void)
void TWI_stop(void)
{
	uint8_t cmd = (1 << TWINT) | (1 << TWEN) | (1 << TWSTO);
	atmega328.twi.reg->twcr = cmd;
	
	_delay_us(100); //wait for a short time
}
// auxiliary
uint8_t TWI_status( void )
{
	uint8_t cmd = atmega328.twi.reg->twsr & TWI_STATUS_MASK;
	return cmd;
}

void TWI_wait_twint( uint16_t nticks ) // hardware triggered
{
	unsigned int i;
	for(i = 0; !( atmega328.twi.reg->twcr & (1 << TWINT)); i++ ){ // wait for acknowledgment confirmation bit.
		if( i > nticks ) // timeout
			break;
	}
}

/*** File Interrupt ***/
// ISR(TWI_vect){}
	
/***EOF***/

