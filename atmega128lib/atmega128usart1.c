/*************************************************************************
	ATMEGA128USART1
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Update: 01/01/2024
Comment:
	Stable
*************************************************************************/
/*** File Library ***/
#include "atmega128mapping.h"
#include "atmega128usart1.h"
#include "buffer.h"
#include <util/delay.h>
#include <math.h>

/*** File Variable ***/
BUFF rx1buff;

UARTvar UART1_Rx;
UARTvar UART1_RxBuf[UART1_RX_BUFFER_SIZE + 1];
uint8_t UART1_LastRxError;

/*** File Header ***/
UARTvar uart1_read(void);
UARTvar uart1_getch(void);
UARTvar* uart1_gets(void);
void uart1_rxflush(void);
void uart1_write(UARTvar data);
void uart1_putch(UARTvar c);
void uart1_puts(UARTvar* s);

/*** Procedure & Function ***/
USART1 USART1enable(uint32_t baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity )
{
	uint32_t ubrr = 0;
	ATMEGA128enable();
	rx1buff = BUFFenable( UART1_RX_BUFFER_SIZE, UART1_RxBuf );
	ubrr = F_CPU/16; ubrr /= baudrate; ubrr -= 1;
	usart1.par.ubrr = (uint16_t) ubrr;
	// FUNCTION POINTER
	usart1.read = uart1_read;
	usart1.getch = uart1_getch;
	usart1.gets = uart1_gets;
	usart1.rxflush = uart1_rxflush;
	usart1.write = uart1_write;
	usart1.putch = uart1_putch;
	usart1.puts = uart1_puts;
	// Set baud rate
	if ( ubrr & 0x8000 ) {
		atmega128.usart1.reg->ucsr1a = (1 << U2X1);  // Enable 2x speed 
		ubrr = F_CPU/8; ubrr /= baudrate; ubrr -= 1;
		usart1.par.ubrr = (uint16_t) ubrr;
	}
	atmega128.usart1.reg->ubrr1h = atmega128.writehlbyte(ubrr).H;
	atmega128.usart1.reg->ubrr1l = atmega128.writehlbyte(ubrr).L;
	// Enable USART receiver and transmitter and receive complete interrupt
	atmega128.usart1.reg->ucsr1b = _BV(RXCIE1) | (1 << RXEN1)|(1 << TXEN1);
	// Set frame format: asynchronous, 8data, no parity, 1stop bit
	#ifdef URSEL1
		UCSR1C = (1 << UMSEL1) | (3 << UCSZ10);
		usart1.par.FDbits = 8;
		usart1.par.Stopbits = 1;
		usart1.par.Parity = 0;
	#else
		// Parameters
		switch(FDbits){
			case 9:
				atmega128.usart1.reg->ucsr1b |= (1 << UCSZ12);
				atmega128.usart1.reg->ucsr1c |= (3 << UCSZ10);
				usart1.par.FDbits = 9;
			break;
			case 8:
				atmega128.usart1.reg->ucsr1b &= ~(1 << UCSZ12);
				atmega128.usart1.reg->ucsr1c |= (3 << UCSZ10);
				usart1.par.FDbits = 8;
			break;
			case 7:
				atmega128.usart1.reg->ucsr1b &= ~(1 << UCSZ12);
				atmega128.usart1.reg->ucsr1c |= (1 << UCSZ11);
				atmega128.usart1.reg->ucsr1c &= ~(1 << UCSZ10);
				usart1.par.FDbits = 7;
			break;
			case 6:
				atmega128.usart1.reg->ucsr1b &= ~(1 << UCSZ12);
				atmega128.usart1.reg->ucsr1c &= ~(1 << UCSZ11);
				atmega128.usart1.reg->ucsr1c |= (1 << UCSZ10);
				usart1.par.FDbits = 6;
			break;
			case 5:
				atmega128.usart1.reg->ucsr1b &= ~(1 << UCSZ12);
				atmega128.usart1.reg->ucsr1c &= ~(3 << UCSZ10);
				usart1.par.FDbits = 5;
			break;
			default:
				atmega128.usart1.reg->ucsr1b &= ~(1 << UCSZ12);
				atmega128.usart1.reg->ucsr1c |= (3 << UCSZ10);
				usart1.par.FDbits = 8;
			break;
		}
		switch(Stopbits){
			case 1:
				atmega128.usart1.reg->ucsr1c &= ~(1 << USBS1);
				usart1.par.Stopbits = 1;
			break;
			case 2:
				atmega128.usart1.reg->ucsr1c |= (1 << USBS1);
				usart1.par.Stopbits = 2;
			break;
			default:
				atmega128.usart1.reg->ucsr1c &= ~(1 << USBS1);
				usart1.par.Stopbits = 1;
			break;
		}
		switch(Parity){
			case 0: // NONE
				atmega128.usart1.reg->ucsr1c &= ~(3 << UPM10);
				usart1.par.Parity = 0;
			break;
			case 2: // EVEN
				atmega128.usart1.reg->ucsr1c |= (1 << UPM11);
				atmega128.usart1.reg->ucsr1c &= ~(1 << UPM10);
				usart1.par.Parity = 2;
			break;
			case 3: // ODD
				atmega128.usart1.reg->ucsr1c |= (3 << UPM10);
				usart1.par.Parity = 3;
			break;
			default:
				atmega128.usart1.reg->ucsr1c &= ~(3 << UPM10);
				usart1.par.Parity = 0;
			break;
		}
	#endif
	atmega128.cpu.reg->sreg |= _BV(GLOBAL_INTERRUPT_ENABLE);
	return usart1;
}
UARTvar uart1_read(void)
{
	UARTvar c;
	c = UART1_Rx;
	UART1_Rx = 0;
	_delay_ms(1);
	return c;
}
UARTvar uart1_getch(void)
{
	return uart1_read();
}
UARTvar* uart1_gets(void)
{
	return rx1buff.raw(&rx1buff.par);
}
void uart1_rxflush(void)
{
	rx1buff.flush(&rx1buff.par);
}
void uart1_write(UARTvar data)
{
	atmega128.usart1.reg->udr1 = data;
	atmega128.usart1.reg->ucsr1b |= _BV(UDRIE1);
	_delay_ms(1);
}
void uart1_putch(UARTvar c)
{
	uart1_write(c);
}
void uart1_puts(UARTvar* s)
{
	char tmp;
	while(*s){
		tmp = *(s++);
		uart1_putch(tmp);
	}
}

/*** File Interrupt ***/
SIGNAL(UART1_RECEIVE_INTERRUPT)
{
	unsigned char bit9;
	unsigned char usr;
	
	usr  = atmega128.usart1.reg->ucsr1a;
	bit9 = atmega128.usart1.reg->ucsr1b;
	bit9 = 0x01 & (bit9 >> 1);
 	   
	UART1_LastRxError = (usr & (_BV(FE1) | _BV(DOR1)));
	
	UART1_Rx = atmega128.usart1.reg->udr1;
	rx1buff.push(&rx1buff.par, UART1_Rx);
}

SIGNAL(UART1_TRANSMIT_INTERRUPT)
{
	atmega128.usart1.reg->ucsr1b &= ~_BV(UDRIE1);
}

/***EOF***/

