/*************************************************************************
	Atmega328Uart
Author:	Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Date: 01122023
Comment:
	stable
*************************************************************************/
/*** File Library ***/
#include "atmega328mapping.h"
#include "buffer.h"
#include <util/delay.h>

/*** File Constant & Macro ***/
// test if the size of the circular buffers fits into SRAM
#if ( ( UART_RX_BUFFER_SIZE ) >= ( RAMEND - 0x60 ) )
	#error "size of UART_RX_BUFFER_SIZE + UART_TX_BUFFER_SIZE larger than size of SRAM"
#endif
#define BAUD_RATE_ASYNCHRONOUS_NORMAL_MODE(baudRate, xtalCpu) ((xtalCpu) / ((baudRate) * 16l) -1)
#define BAUD_RATE_ASYNCHRONOUS_DOUBLE_SPEED(baudRate, xtalCpu) (((xtalCpu) / ((baudRate) * 8l) -1) | 0x8000)
#define BAUD_RATE_SYNCHRONOUS_MASTER_MODE(baudRate, xtalCpu) (((xtalCpu) / ((baudRate) * 2l) -1)))
#define UART_FRAME_ERROR      0x0800	/* Framing Error by UART       */
#define UART_OVERRUN_ERROR    0x0400	/* Overrun condition by UART   */
#define UART_BUFFER_OVERFLOW  0x0200	/* receive ringbuffer overflow */
#define UART_NO_DATA          0x0100	/* no receive data available   */
#if defined(__AVR_ATmega48__) ||defined(__AVR_ATmega88__) || defined(__AVR_ATmega168__) || \
      defined(__AVR_ATmega48P__) ||defined(__AVR_ATmega88P__) || defined(__AVR_ATmega168P__) || \
      defined(__AVR_ATmega328__) || defined(__AVR_ATmega328P__)
	 // USART, RX Complete Handler
	 #define UART_RX_COMPLETE		USART_RX_vect
	 // USART, UDR Empty Handler
	 #define UART_UDR_EMPTY			USART_UDRE_vect
	 //USART, TX Complete Handler
	 #define UART_TX_COMPLETE		USART_TX_vect
#else
	#error "Not Atmega 328"
#endif

/*** File Variable ***/
//ATMEGA328 atmega328;
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
UART UARTenable(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity )
{
	uint8_t tSREG;
	tSREG = atmega328.cpu.reg->sreg;
	atmega328.cpu.reg->sreg &= ~(1 << GLOBAL_INTERRUPT_ENABLE);
	UART uart;
	atmega328 = ATMEGA328enable();
	rxbuff = BUFFenable(UART_RX_BUFFER_SIZE, UART_RxBuf);
	uart.par.ubrr = baudrate;
	// Vtable
	uart.read = uart_read;
	uart.getch = uart_getch;
	uart.gets = uart_gets;
	uart.rxflush = uart_rxflush;
	uart.write = uart_write;
	uart.putch = uart_putch;
	uart.puts = uart_puts;
	// Set baud rate
	if ( baudrate & 0x8000 ) 
	{
   		atmega328.usart.reg->ucsr0a = (1 << U2X0);  //Enable 2x speed 
   		baudrate &= ~0x8000;
   	}
	atmega328.usart.reg->ubrr0 =  atmega328.writehlbyte(baudrate);
	// Enable USART receiver and transmitter and receive complete interrupt
	atmega328.usart.reg->ucsr0b = _BV(RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	// Set frame format: asynchronous, 8data, no parity, 1stop bit
	#ifdef URSEL0
		atmega328.usart.reg->ucsr0c = (1 << URSEL0) | (3 << UCSZ00);
		uart.par.FDbits = 8;
		uart.par.Stopbits = 1;
		uart.par.Parity = 0;
	#else
		switch(FDbits){
			case 9:
				atmega328.usart.reg->ucsr0b |= (1 << UCSZ02);
				atmega328.usart.reg->ucsr0c |= (3 << UCSZ00);
				uart.par.FDbits = 9;
			break;
			case 8:
				atmega328.usart.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega328.usart.reg->ucsr0c |= (3 << UCSZ00);
				uart.par.FDbits=8;
			break;
			case 7:
				atmega328.usart.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega328.usart.reg->ucsr0c |= (1 << UCSZ01);
				atmega328.usart.reg->ucsr0c &= ~(1 << UCSZ00);
				uart.par.FDbits=7;
			break;
			case 6:	
				atmega328.usart.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega328.usart.reg->ucsr0c &= ~(1 << UCSZ01);
				atmega328.usart.reg->ucsr0c |= (1 << UCSZ00);
				uart.par.FDbits = 6;
			break;
			case 5:	
				atmega328.usart.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega328.usart.reg->ucsr0c &= ~(3 << UCSZ00);
				uart.par.FDbits=5;
			break;
			default:
				atmega328.usart.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega328.usart.reg->ucsr0c |= (3 << UCSZ00);
				uart.par.FDbits = 8;
			break;
		}
		switch(Stopbits){
			case 1:
				atmega328.usart.reg->ucsr0c &= ~(1 << USBS0);
				uart.par.Stopbits = 1;
			break;
			case 2:
				atmega328.usart.reg->ucsr0c |= (1 << USBS0);
				uart.par.Stopbits=2;
			break;	
			default:
				atmega328.usart.reg->ucsr0c &= ~(1 << USBS0);
				uart.par.Stopbits=1;
			break;
		}
		switch(Parity){
			case 0:
				atmega328.usart.reg->ucsr0c &= ~(3 << UPM00);
				uart.par.Parity=0;
			break;
			case 2:
				atmega328.usart.reg->ucsr0c |= (1 << UPM01);
				atmega328.usart.reg->ucsr0c &= ~(1 << UPM00);
				uart.par.Parity=2;
			break;
			case 3:
				atmega328.usart.reg->ucsr0c |= (3 << UPM00);
				uart.par.Parity=3;
			break;
			default:
				atmega328.usart.reg->ucsr0c &= ~(3 << UPM00);
				uart.par.Parity=0;
			break;
		}
	#endif
	atmega328.cpu.reg->sreg = tSREG;
	atmega328.cpu.reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
	
	atmega328.usart.run = uart;
	return uart;
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
	atmega328.usart.reg->udr0 = data;
	atmega328.usart.reg->ucsr0b |= _BV(UDRIE0);
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
	
	usr  = atmega328.usart.reg->ucsr0a;
    bit9 = atmega328.usart.reg->ucsr0b;
    bit9 = 0x01 & (bit9 >> 1);
	
    UART_LastRxError = (usr & (_BV(FE0) | _BV(DOR0)));
	
	UART_Rx = atmega328.usart.reg->udr0;
	rxbuff.push(&rxbuff.par, UART_Rx);
}

ISR(UART_UDR_EMPTY)
{ // USART, UDR Empty Handler
	atmega328.usart.reg->ucsr0b &= ~_BV( UDRIE0 );
}

// ISR(USART_TX_vect){}

/***EOF***/

