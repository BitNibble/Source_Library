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
#include "atmega128mapping.h"
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
	
	atmega128_spi.transfer_sync = spi_transfer_sync;
	atmega128_spi.transmit_sync = spi_transmit_sync;
	atmega128_spi.fast_shift = spi_fast_shift;
	
	atmega128()->portb_reg->ddr &= ~((1 << DD_MOSI) | (1 << DD_MISO) | (1 << DD_SS) | (1 << DD_SCK));
	switch(master_slave_select){
		case SPI_MASTER_MODE:
			atmega128()->spi_reg->spcr |= (1 << MSTR);
			atmega128()->portb_reg->ddr |= (1 << DD_SS) | (1 << DD_MOSI) | (1 << DD_SCK);
			atmega128()->portb_reg->port |= (1 << DD_SS);
		break;
		case SPI_SLAVE_MODE:
			atmega128()->spi_reg->spcr |= (1 << MSTR);
			atmega128()->portb_reg->ddr |= (1 << DD_MISO);
		break;
		default:
			atmega128()->spi_reg->spcr |= (1 << MSTR);
			atmega128()->portb_reg->ddr |= (1 << DD_SS) | (1 << DD_MOSI) | (1 << DD_SCK);
		break;
	}
	switch(data_order){
		case SPI_LSB_DATA_ORDER:
			atmega128()->spi_reg->spcr |= (1 << DORD);
		break;
		case SPI_MSB_DATA_ORDER:
			atmega128()->spi_reg->spcr &= ~(1 << DORD);
		break;
		default:
			atmega128()->spi_reg->spcr &= ~(1 << DORD);
		break;
	}
	switch(data_modes){
		case 0:
			atmega128()->spi_reg->spcr &= ~((1 << CPOL) | (1 << CPHA));
		break;
		case 1:
			atmega128()->spi_reg->spcr |= (1 << CPHA);
		break;
		case 2:
			atmega128()->spi_reg->spcr |= (1 << CPOL);
		break;
		case 3:
			atmega128()->spi_reg->spcr |= (1 << CPOL) | (1 << CPHA);
		break;
		default:
			atmega128()->spi_reg->spcr &= ~((1 << CPOL) | (1 << CPHA));
		break;
	}
	switch(prescaler){
		case 2:
			atmega128()->spi_reg->spsr |= (1 << SPI2X);
			atmega128()->spi_reg->spcr &= ~((1 << SPR1) | (1 << SPR0));
		break;
		case 4:
			atmega128()->spi_reg->spsr &= ~(1 << SPI2X);
			atmega128()->spi_reg->spcr &= ~((1 << SPR1) | (1 << SPR0));
		break;
		case 8:
			atmega128()->spi_reg->spsr |= (1 << SPI2X);
			atmega128()->spi_reg->spcr |= (1 << SPR0);
		break;
		case 16:
			atmega128()->spi_reg->spsr &= ~(1 << SPI2X);
			atmega128()->spi_reg->spcr |= (1 << SPR0);
		break;
		case 32:
			atmega128()->spi_reg->spsr |= (1 << SPI2X);
			atmega128()->spi_reg->spcr |= (1 << SPR1);
		break;
		case 64:
			atmega128()->spi_reg->spsr &= ~(1 << SPI2X);
			atmega128()->spi_reg->spcr |= (1 << SPR1);
		break;
		case 128:
			atmega128()->spi_reg->spsr &= (1 << SPI2X);
			atmega128()->spi_reg->spcr |= (1 << SPR1) | (1 << SPR0);
		break;
		default:
			atmega128()->spi_reg->spsr |= (1 << SPI2X);
			atmega128()->spi_reg->spcr |= (1 << SPR0);
		break;
	}
	atmega128()->spi_reg->spcr |= (1 << SPE);
	
	return atmega128_spi;
}

SPI0* spi(void){ return &atmega128_spi; }

void spi_default()
// Initialize pins for spi communication
{
	atmega128()->portb_reg->ddr &= ~((1 << DD_MOSI) | (1 << DD_MISO) | (1 << DD_SS) | (1 << DD_SCK));
	// Define the following pins as output
	atmega128()->portb_reg->ddr |= ((1 << DD_MOSI) | (1 << DD_SS) | (1 << DD_SCK)); 
	atmega128()->spi_reg->spcr	=	((1 << SPE) |				// SPI Enable
						(0 << SPIE) |				// SPI Interrupt Enable
						(0 << DORD) |				// Data Order (0:MSB first / 1:LSB first)
						(1 << MSTR) |				// Master/Slave select   
						(0 << SPR1) | (1 << SPR0) |	// SPI Clock Rate
						(0 << CPOL) |				// Clock Polarity (0:SCK low / 1:SCK hi when idle)
						(0 << CPHA));				// Clock Phase (0:leading / 1:trailing edge sampling)
    atmega128()->spi_reg->spsr	=	(1 << SPI2X);				// Double Clock Rate  
}
void spi_transfer_sync (uint8_t * dataout, uint8_t * datain, uint8_t len)
// Shift full array through target device
{
	uint8_t i;      
	for (i = 0; i < len; i++) {
		atmega128()->spi_reg->spdr = dataout[i];
		while((atmega128()->spi_reg->spsr & (1 << SPIF)) == 0) ; // polling, serial transfer is complete interrupt.
		datain[i] = atmega128()->spi_reg->spdr;
	}
}
void spi_transmit_sync (uint8_t * dataout, uint8_t len)
// Shift full array to target device without receiving any byte
{
	uint8_t i;
	for (i = 0; i < len; i++) {
		atmega128()->spi_reg->spdr = dataout[i];
		while((atmega128()->spi_reg->spsr & (1 << SPIF)) == 0) ; // polling, serial transfer is complete interrupt.
	}
}
uint8_t spi_fast_shift (uint8_t data)
// Clocks only one byte to target device and returns the received one
{
	atmega128()->spi_reg->spdr = data;
	while((atmega128()->spi_reg->spsr & (1 << SPIF)) == 0) ; // polling, serial transfer is complete interrupt.
	return atmega128()->spi_reg->spdr;
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

