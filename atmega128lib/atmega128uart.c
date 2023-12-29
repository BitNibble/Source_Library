/*************************************************************************
	ATMEGA128UART
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Date: 24042023
Comment:
	Stable
*************************************************************************/
/*** File Library ***/
#include "atmega128mapping.h"
#include "atmega128uart.h"
#include "buffer.h"
//#include <stdarg.h>
#include <util/delay.h>

/*** File Constant & Macro ***/
#if ( ( UART_RX_BUFFER_SIZE ) >= ( RAMEND-0x60 ) )
	#error "size of UART_RX_BUFFER_SIZE + UART_TX_BUFFER_SIZE larger than size of SRAM"
#endif
#define BAUD_RATE_ASYNCHRONOUS_NORMAL_MODE(baudRate, xtalCpu) ((xtalCpu) / ((baudRate) * 16l) - 1)
#define BAUD_RATE_ASYNCHRONOUS_DOUBLE_SPEED(baudRate, xtalCpu) (((xtalCpu) / ((baudRate) * 8l) -1) | 0x8000)
#define BAUD_RATE_SYNCHRONOUS_MASTER_MODE(baudRate, xtalCpu) (((xtalCpu) / ((baudRate) * 2l) -1)))
#if defined(__AVR_ATmega64__) || defined(__AVR_ATmega128__) 
	// ATmega with two USART
	#define ATMEGA_128_USART
	#define UART_FRAME_ERROR		0x0800              /* Framing Error by UART        */
	#define UART_OVERRUN_ERROR		0x0400              /* Overrun condition by UART    */
	#define UART_BUFFER_OVERFLOW	0x0200              /* receive ring buffer overflow */
	#define UART_NO_DATA			0x0100              /* no receive data available    */
	#define UART0_RECEIVE_INTERRUPT   USART0_RX_vect
	#define UART1_RECEIVE_INTERRUPT   USART1_RX_vect
	#define UART0_TRANSMIT_INTERRUPT  USART0_UDRE_vect
	#define UART1_TRANSMIT_INTERRUPT  USART1_UDRE_vect
#else
	#error "Not Atmega 128"
#endif

/*** File Variable ***/
BUFF rx0buff;
BUFF rx1buff;

UARTvar UART0_Rx;
UARTvar UART0_RxBuf[UART0_RX_BUFFER_SIZE + 1];
uint8_t UART0_LastRxError;
UARTvar UART1_Rx;
UARTvar UART1_RxBuf[UART1_RX_BUFFER_SIZE + 1];
uint8_t UART1_LastRxError;

/*** File Header ***/
UARTvar uart0_read(void);
UARTvar uart0_getch(void);
UARTvar* uart0_gets(void);
void uart0_rxflush(void);
void uart0_write(UARTvar data);
void uart0_putch(UARTvar c);
void uart0_puts(UARTvar* s);

UARTvar uart1_read(void);
UARTvar uart1_getch(void);
UARTvar* uart1_gets(void);
void uart1_rxflush(void);
void uart1_write(UARTvar data);
void uart1_putch(UARTvar c);
void uart1_puts(UARTvar* s);

/*** Procedure & Function ***/
UART0 UART0enable(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity )
{
	UART0 usart0;
	ATMEGA128enable();
	rx0buff = BUFFenable( UART0_RX_BUFFER_SIZE, UART0_RxBuf );
	usart0.par.ubrr = baudrate;
	// Vtable
	usart0.read = uart0_read;
	usart0.getch = uart0_getch;
	usart0.gets = uart0_gets;
	usart0.rxflush = uart0_rxflush;
	usart0.write = uart0_write;
	usart0.putch = uart0_putch;
	usart0.puts = uart0_puts;
	// Set baud rate
	if ( baudrate & 0x8000 ) 
	{
   		atmega128.usart0.reg->ucsr0a = (1 << U2X0);  // Enable 2x speed 
   		baudrate &= ~0x8000;
   	}
	atmega128.usart0.reg->ubrr0h = (unsigned char)(baudrate >> 8);
	atmega128.usart0.reg->ubrr0l = (unsigned char) baudrate;
	// Enable USART receiver and transmitter and receive complete interrupt
	atmega128.usart0.reg->ucsr0b = _BV(RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	// Set frame format: asynchronous, 8 data, no parity, 1 stop bit
	#ifdef URSEL0
		atmega128.usart0->ucsr0c = (1 << URSEL0) | (3 << UCSZ00);
		usart0.par.FDbits = 8;
		usart0.par.Stopbits = 1;
		usart0.par.Parity = 0;
	#else
		switch(FDbits){
			case 9:
				atmega128.usart0.reg->ucsr0b |= (1 << UCSZ02);
				atmega128.usart0.reg->ucsr0c |= (3 << UCSZ00);
				usart0.par.FDbits = 9;
			break;
			case 8:
				atmega128.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega128.usart0.reg->ucsr0c |= (3 << UCSZ00);
				usart0.par.FDbits = 8;
			break;
			case 7:
				atmega128.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega128.usart0.reg->ucsr0c |= (1 << UCSZ01);
				atmega128.usart0.reg->ucsr0c &= ~(1 << UCSZ00);
				usart0.par.FDbits = 7;
			break;
			case 6:
				atmega128.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega128.usart0.reg->ucsr0c &= ~(1 << UCSZ01);
				atmega128.usart0.reg->ucsr0c |= (1 << UCSZ00);
				usart0.par.FDbits = 6;
			break;
			case 5:
				atmega128.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega128.usart0.reg->ucsr0c &= ~(3 << UCSZ00);
				usart0.par.FDbits = 5;
			break;
			default:
				atmega128.usart0.reg->ucsr0b &= ~(1 << UCSZ02);
				atmega128.usart0.reg->ucsr0c |= (3 << UCSZ00);
				usart0.par.FDbits = 8;
			break;
		}
		switch(Stopbits){
			case 1:
				atmega128.usart0.reg->ucsr0c &= ~(1 << USBS0);
				usart0.par.Stopbits = 1;
			break;
			case 2:
				atmega128.usart0.reg->ucsr0c |= (1 << USBS0);
				usart0.par.Stopbits = 2;
			break;	
			default:
				atmega128.usart0.reg->ucsr0c &= ~(1 << USBS0);
				usart0.par.Stopbits = 1;
			break;
		}
		switch(Parity){
			case 0:
				atmega128.usart0.reg->ucsr0c &= ~(3 << UPM00);
				usart0.par.Parity = 0;
			break;
			case 2:
				atmega128.usart0.reg->ucsr0c |= (1 << UPM01);
				atmega128.usart0.reg->ucsr0c &= ~(1 << UPM00);
				usart0.par.Parity = 2;
			break;
			case 3:
				atmega128.usart0.reg->ucsr0c |= (3 << UPM00);
				usart0.par.Parity = 3;
			break;	
			default:
				atmega128.usart0.reg->ucsr0c &= ~(3 << UPM00);
				usart0.par.Parity = 0;
			break;
		}
	#endif
	atmega128.cpu.reg->sreg |= _BV(GLOBAL_INTERRUPT_ENABLE);
	return usart0;
}
UARTvar uart0_read(void)
{
	UARTvar c;
	c = UART0_Rx;
	UART0_Rx = 0;
	_delay_ms(1);
	return c;
}
UARTvar uart0_getch(void)
{
	return uart0_read();
}
UARTvar* uart0_gets(void)
{
	return rx0buff.raw(&rx0buff.par);
}
void uart0_rxflush(void)
{
	rx0buff.flush(&rx0buff.par);
}
void uart0_write(UARTvar data)
{
	atmega128.usart0.reg->udr0 = data;
	atmega128.usart0.reg->ucsr0b |= _BV(UDRIE0);
	_delay_ms(1);
}
void uart0_putch(UARTvar c)
{
	uart0_write(c);
}
void uart0_puts(UARTvar* s)
{
	char tmp;
	while(*s){
		tmp = *(s++);
		uart0_putch(tmp);
	}
}

// these functions are only for ATmegas with two USART
UART1 UART1enable(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity )
{
	UART1 usart1;
	ATMEGA128enable();
	rx1buff = BUFFenable( UART1_RX_BUFFER_SIZE, UART1_RxBuf );
	usart1.par.ubrr = baudrate;
	// FUNCTION POINTER
	usart1.read = uart1_read;
	usart1.getch = uart1_getch;
	usart1.gets = uart1_gets;
	usart1.rxflush = uart1_rxflush;
	usart1.write = uart1_write;
	usart1.putch = uart1_putch;
	usart1.puts = uart1_puts;
	// Set baud rate
	if ( baudrate & 0x8000 ) {
		atmega128.usart1.reg->ucsr1a = (1 << U2X1);  // Enable 2x speed 
		baudrate &= ~0x8000;
	}
	atmega128.usart1.reg->ubrr1h = (unsigned char)(baudrate >> 8);
	atmega128.usart1.reg->ubrr1l = (unsigned char) baudrate;
	// Enable USART receiver and transmitter and receive complete interrupt
	atmega128.usart1.reg->ucsr1b = _BV(RXCIE1) | (1 << RXEN1)|(1 << TXEN1);
	// Set frame format: asynchronous, 8data, no parity, 1stop bit
	#ifdef URSEL1
		UCSR1C = (1 << URSEL1) | (3 << UCSZ10);
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
ISR(UART0_RECEIVE_INTERRUPT)
{
	unsigned char bit9;
	unsigned char usr;
	
	usr  = atmega128.usart0.reg->ucsr0a;
	bit9 = atmega128.usart0.reg->ucsr0b;
	bit9 = 0x01 & (bit9 >> 1);
	
	UART0_LastRxError = (usr & (_BV(FE0) | _BV(DOR0)));
	
	UART0_Rx = atmega128.usart0.reg->udr0;
	rx0buff.push(&rx0buff.par, UART0_Rx);
}

ISR(UART0_TRANSMIT_INTERRUPT)
{
	atmega128.usart0.reg->ucsr0b &= ~_BV(UDRIE0);
}

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

