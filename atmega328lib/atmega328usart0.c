/*************************************************************************
	Atmega328Usart0
Author:	Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update: 01/01/2024
Comment:
	stable
*************************************************************************/
/*** File Library ***/
#include "atmega328mapping.h"
#include "atmega328usart0.h"
#include "buffer.h"
#include <util/delay.h>
#include <math.h>

/*** File Constant & Macro ***/

/*** File Variable ***/
BUFF rxbuff;
UARTvar UART_Rx;
UARTvar UART_RxBuf[UART_RX_BUFFER_SIZE+1];
uint8_t UART_LastRxError;

/*** File Header ***/
UARTvar uart_read(void);
UARTvar uart_getch(void);
UARTvar* uart_gets(void);
void uart_rxflush(void);
void uart_write(UARTvar data);
void uart_putch(UARTvar c);
void uart_puts(UARTvar* s);

/*** Procedure & Function ***/
USART0 USART0enable(uint32_t baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity )
{
	uint8_t tSREG;
	tSREG = atmega328.cpu.reg->sreg;
	atmega328.cpu.reg->sreg &= ~(1 << GLOBAL_INTERRUPT_ENABLE);
	uint32_t ubrr;
	ATMEGA328enable();
	rxbuff = BUFFenable(UART_RX_BUFFER_SIZE, UART_RxBuf);
	ubrr = F_CPU/16; ubrr /= baudrate; ubrr -= 1;
	usart0.par.ubrr = ubrr;
	// Vtable
	usart0.read = uart_read;
	usart0.getch = uart_getch;
	usart0.gets = uart_gets;
	usart0.rxflush = uart_rxflush;
	usart0.write = uart_write;
	usart0.putch = uart_putch;
	usart0.puts = uart_puts;
	// Set baud rate
	if ( ubrr & 0x8000 ) 
	{
   		atmega328.usart0.reg->ucsr0a = (1 << U2X0);  //Enable 2x speed
		ubrr = F_CPU/8; ubrr /= baudrate; ubrr -= 1;
   		usart0.par.ubrr = ubrr;
   	}
	atmega328.usart0.reg->ubrr0 =  atmega328.writehlbyte(ubrr);
	// Enable USART receiver and transmitter and receive complete interrupt
	atmega328.usart0.reg->ucsr0b = _BV(RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	// Set frame format: asynchronous, 8data, no parity, 1stop bit
	#ifdef URSEL0
		atmega328.usart0.reg->ucsr0c = (1 << UMSEL0) | (3 << UCSZ00);
		usart0.par.FDbits = 8;
		usart0.par.Stopbits = 1;
		usart0.par.Parity = 0;
	#else
		switch(FDbits){
			case 9:
				atmega328.usart0.reg->ucsr0b |= (1 << UCSZ02);
				atmega328.usart0.reg->ucsr0c |= (3 << UCSZ00);
				usart0.par.FDbits = 9;
			break;
			case 8:
				atmega328.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega328.usart0.reg->ucsr0c |= (3 << UCSZ00);
				usart0.par.FDbits=8;
			break;
			case 7:
				atmega328.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega328.usart0.reg->ucsr0c |= (1 << UCSZ01);
				atmega328.usart0.reg->ucsr0c &= ~(1 << UCSZ00);
				usart0.par.FDbits=7;
			break;
			case 6:	
				atmega328.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega328.usart0.reg->ucsr0c &= ~(1 << UCSZ01);
				atmega328.usart0.reg->ucsr0c |= (1 << UCSZ00);
				usart0.par.FDbits = 6;
			break;
			case 5:	
				atmega328.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega328.usart0.reg->ucsr0c &= ~(3 << UCSZ00);
				usart0.par.FDbits=5;
			break;
			default:
				atmega328.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega328.usart0.reg->ucsr0c |= (3 << UCSZ00);
				usart0.par.FDbits = 8;
			break;
		}
		switch(Stopbits){
			case 1:
				atmega328.usart0.reg->ucsr0c &= ~(1 << USBS0);
				usart0.par.Stopbits = 1;
			break;
			case 2:
				atmega328.usart0.reg->ucsr0c |= (1 << USBS0);
				usart0.par.Stopbits=2;
			break;	
			default:
				atmega328.usart0.reg->ucsr0c &= ~(1 << USBS0);
				usart0.par.Stopbits=1;
			break;
		}
		switch(Parity){
			case 0:
				atmega328.usart0.reg->ucsr0c &= ~(3 << UPM00);
				usart0.par.Parity=0;
			break;
			case 2:
				atmega328.usart0.reg->ucsr0c |= (1 << UPM01);
				atmega328.usart0.reg->ucsr0c &= ~(1 << UPM00);
				usart0.par.Parity=2;
			break;
			case 3:
				atmega328.usart0.reg->ucsr0c |= (3 << UPM00);
				usart0.par.Parity=3;
			break;
			default:
				atmega328.usart0.reg->ucsr0c &= ~(3 << UPM00);
				usart0.par.Parity=0;
			break;
		}
	#endif
	atmega328.cpu.reg->sreg = tSREG;
	atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);

	return usart0;
}

UARTvar uart_read(void)
{
	UARTvar c;
	c = UART_Rx;
	UART_Rx = 0;
	_delay_ms(1);
	return c;
}
UARTvar uart_getch(void)
{
	return uart_read();
}
UARTvar* uart_gets(void)
{
	return rxbuff.raw(&rxbuff.par);
}
void uart_rxflush(void)
{
	rxbuff.flush(&rxbuff.par);
}
void uart_write(UARTvar data)
{
	atmega328.usart0.reg->udr0 = data;
	atmega328.usart0.reg->ucsr0b |= _BV(UDRIE0);
	_delay_ms(1);
}
void uart_putch(UARTvar c)
{
	uart_write(c);
}
void uart_puts(UARTvar* s)
{
	char tmp;
	while(*s){
		tmp = *(s++);
		uart_putch(tmp);
	}
}

/*** File Interrupt ***/
ISR(UART_RX_COMPLETE)
{ // USART, RX Complete Handler
	unsigned char bit9;
    unsigned char usr;
	
	usr  = atmega328.usart0.reg->ucsr0a;
    bit9 = atmega328.usart0.reg->ucsr0b;
    bit9 = 0x01 & (bit9 >> 1);
	
    UART_LastRxError = (usr & (_BV(FE0) | _BV(DOR0)));
	
	UART_Rx = atmega328.usart0.reg->udr0;
	rxbuff.push(&rxbuff.par, UART_Rx);
}

ISR(UART_UDR_EMPTY)
{ // USART, UDR Empty Handler
	atmega328.usart0.reg->ucsr0b &= ~_BV( UDRIE0 );
}

// ISR(USART_TX_vect){}

/***EOF***/

