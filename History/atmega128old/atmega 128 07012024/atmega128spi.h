/************************************************************************
	ATMEGA128SPI
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
Hardware: ATmega128
Update: 01/01/2024
Comment:
	Stable
************************************************************************/
#ifndef _ATMEGA128SPI_H_
	#define _ATMEGA128SPI_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__)
	#define SPI_LSB_DATA_ORDER 1
	#define SPI_MSB_DATA_ORDER 0
	#define SPI_MASTER_MODE 1
	#define SPI_SLAVE_MODE 0
	#define SPI_PIN_MASK 15
	#define DD_SS 0
	#define DD_SCK 1
	#define DD_MOSI 2
	#define DD_MISO 3
#else
	#error "Not Atmega 128"
#endif

/*** Global Variable ***/
struct sp{
	void (*transfer_sync) (uint8_t * dataout, uint8_t * datain, uint8_t len);
	void (*transmit_sync) (uint8_t * dataout, uint8_t len);
	uint8_t (*fast_shift) (uint8_t data);
};
typedef struct sp SPI;

/*** Global ***/
SPI* spi(void);
SPI SPIenable(uint8_t master_slave_select, uint8_t data_order,  uint8_t data_modes, uint8_t prescaler);

#endif
/***EOF***/

