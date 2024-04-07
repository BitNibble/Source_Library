/*************************************************************************
	ATMEGA128SPI
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Update: 07/01/2024
Comment:
   Stable
*************************************************************************/
/*** File Library ***/
#include "atmega128spi.h"

/*** File Variable ***/
static SPI0 atmega128_spi;

/*** File Header ***/
void spi_default(void);
void spi_transfer_sync (uint8_t * dataout, uint8_t * datain, uint8_t len);
void spi_transmit_sync (uint8_t * dataout, uint8_t len);
uint8_t spi_fast_shift (uint8_t data);

/*** Procedure & Function ***/
SPI0 spi_enable(uint8_t master_slave_select, uint8_t data_order,  uint8_t data_modes, uint8_t prescaler)
{
	// ATMEGA128enable();
	
	atmega128_spi.handle = spi_handle();
	atmega128_spi.transfer_sync = spi_transfer_sync;
	atmega128_spi.transmit_sync = spi_transmit_sync;
	atmega128_spi.fast_shift = spi_fast_shift;
	
	portb_handle()->ddr.reg &= ~((1 << DD_MOSI) | (1 << DD_MISO) | (1 << DD_SS) | (1 << DD_SCK));
	switch(master_slave_select){
		case SPI_MASTER_MODE:
			spi_handle()->spcr.reg |= (1 << MSTR);
			portb_handle()->ddr.reg |= (1 << DD_SS) | (1 << DD_MOSI) | (1 << DD_SCK);
			portb_handle()->port.reg |= (1 << DD_SS);
		break;
		case SPI_SLAVE_MODE:
			spi_handle()->spcr.reg |= (1 << MSTR);
			portb_handle()->ddr.reg |= (1 << DD_MISO);
		break;
		default:
			spi_handle()->spcr.reg |= (1 << MSTR);
			portb_handle()->ddr.reg |= (1 << DD_SS) | (1 << DD_MOSI) | (1 << DD_SCK);
		break;
	}
	switch(data_order){
		case SPI_LSB_DATA_ORDER:
			spi_handle()->spcr.reg |= (1 << DORD);
		break;
		case SPI_MSB_DATA_ORDER:
			spi_handle()->spcr.reg &= ~(1 << DORD);
		break;
		default:
			spi_handle()->spcr.reg &= ~(1 << DORD);
		break;
	}
	switch(data_modes){
		case 0:
			spi_handle()->spcr.reg &= ~((1 << CPOL) | (1 << CPHA));
		break;
		case 1:
			spi_handle()->spcr.reg |= (1 << CPHA);
		break;
		case 2:
			spi_handle()->spcr.reg |= (1 << CPOL);
		break;
		case 3:
			spi_handle()->spcr.reg |= (1 << CPOL) | (1 << CPHA);
		break;
		default:
			spi_handle()->spcr.reg &= ~((1 << CPOL) | (1 << CPHA));
		break;
	}
	switch(prescaler){
		case 2:
			spi_handle()->spsr.reg |= (1 << SPI2X);
			spi_handle()->spcr.reg &= ~((1 << SPR1) | (1 << SPR0));
		break;
		case 4:
			spi_handle()->spsr.reg &= ~(1 << SPI2X);
			spi_handle()->spcr.reg &= ~((1 << SPR1) | (1 << SPR0));
		break;
		case 8:
			spi_handle()->spsr.reg |= (1 << SPI2X);
			spi_handle()->spcr.reg |= (1 << SPR0);
		break;
		case 16:
			spi_handle()->spsr.reg &= ~(1 << SPI2X);
			spi_handle()->spcr.reg |= (1 << SPR0);
		break;
		case 32:
			spi_handle()->spsr.reg |= (1 << SPI2X);
			spi_handle()->spcr.reg |= (1 << SPR1);
		break;
		case 64:
			spi_handle()->spsr.reg &= ~(1 << SPI2X);
			spi_handle()->spcr.reg |= (1 << SPR1);
		break;
		case 128:
			spi_handle()->spsr.reg &= (1 << SPI2X);
			spi_handle()->spcr.reg |= (1 << SPR1) | (1 << SPR0);
		break;
		default:
			spi_handle()->spsr.reg |= (1 << SPI2X);
			spi_handle()->spcr.reg |= (1 << SPR0);
		break;
	}
	spi_handle()->spcr.reg |= (1 << SPE);
	
	return atmega128_spi;
}

SPI0* spi(void){ return &atmega128_spi; }

void spi_default()
// Initialize pins for spi communication
{
	portb_handle()->ddr.reg &= ~((1 << DD_MOSI) | (1 << DD_MISO) | (1 << DD_SS) | (1 << DD_SCK));
	// Define the following pins as output
	portb_handle()->ddr.reg |= ((1 << DD_MOSI) | (1 << DD_SS) | (1 << DD_SCK)); 
	spi_handle()->spcr.reg	=	((1 << SPE) |				// SPI Enable
						(0 << SPIE) |				// SPI Interrupt Enable
						(0 << DORD) |				// Data Order (0:MSB first / 1:LSB first)
						(1 << MSTR) |				// Master/Slave select   
						(0 << SPR1) | (1 << SPR0) |	// SPI Clock Rate
						(0 << CPOL) |				// Clock Polarity (0:SCK low / 1:SCK hi when idle)
						(0 << CPHA));				// Clock Phase (0:leading / 1:trailing edge sampling)
    spi_handle()->spsr.reg	=	(1 << SPI2X);				// Double Clock Rate  
}
void spi_transfer_sync (uint8_t * dataout, uint8_t * datain, uint8_t len)
// Shift full array through target device
{
	uint8_t i;      
	for (i = 0; i < len; i++) {
		spi_handle()->spdr.reg = dataout[i];
		while((spi_handle()->spsr.reg & (1 << SPIF)) == 0) ; // polling, serial transfer is complete interrupt.
		datain[i] = spi_handle()->spdr.reg;
	}
}
void spi_transmit_sync (uint8_t * dataout, uint8_t len)
// Shift full array to target device without receiving any byte
{
	uint8_t i;
	for (i = 0; i < len; i++) {
		spi_handle()->spdr.reg = dataout[i];
		while((spi_handle()->spsr.reg & (1 << SPIF)) == 0) ; // polling, serial transfer is complete interrupt.
	}
}
uint8_t spi_fast_shift (uint8_t data)
// Clocks only one byte to target device and returns the received one
{
	spi_handle()->spdr.reg = data;
	while((spi_handle()->spsr.reg & (1 << SPIF)) == 0) ; // polling, serial transfer is complete interrupt.
	return spi_handle()->spdr.reg;
}

/***EOF***/


/**************************** Comment *******************************
// From data sheet:
void SPI_MasterInit(void)
{
// Set MOSI and SCK output, all others input
DDR_SPI = (1 << DD_MOSI) | (1 << DD_SCK);
// Enable SPI, Master, set clock rate fck/16
SPCR = (1 << SPE) | (1 << MSTR) | (1 << SPR0);
}
void SPI_MasterTransmit(char cData)
{
// Start transmission
SPDR = cData;
// Wait for transmission complete
while(!(SPSR & (1 << SPIF))) ;
}
void SPI_SlaveInit(void)
{
// Set MISO output, all others input
DDR_SPI = (1 << DD_MISO);
// Enable SPI
SPCR = (1 << SPE);
}
char SPI_SlaveReceive(void)
{
// Wait for reception complete
while(!(SPSR & (1 << SPIF))) ;
// Return data register
return SPDR;
}
********************************************************************/

