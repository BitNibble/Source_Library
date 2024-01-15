/*************************************************************************
	ATMEGA128USART0
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
#include "atmega128usart0.h"
#include "buffer.h"
#include <util/delay.h>
#include <math.h>

/*** File Variable ***/
static USART0 atmega128_usart0;
BUFF rx0buff;
UARTvar UART0_Rx;
UARTvar UART0_RxBuf[UART0_RX_BUFFER_SIZE + 1];
uint8_t UART0_LastRxError;
static uint8_t uart0flag;

/*** File Header ***/
UARTvar uart0_read(void);
UARTvar uart0_getch(void);
UARTvar* uart0_gets(void);
void uart0_rxflush(void);
void uart0_write(UARTvar data);
void uart0_putch(UARTvar c);
void uart0_puts(UARTvar* s);
/*** Complimentary functions ***/
uint8_t USART0ReceiveComplete(void);
uint8_t USART0TransmitComplete(void);
uint8_t USART0DataRegisterEmpty(void);
uint8_t USART0FrameError(void);
uint8_t USART0DataOverRun(void);
uint8_t USART0ParityError(void);
uint8_t USART0ReadErrors(void);
void USART0ClearErrors(void);
void USART0DoubleTransmissionSpeed(void);

/*** Procedure & Function ***/
USART0 USART0_enable(uint32_t baud, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity )
{
	// ATMEGA128enable();
	
	uint16_t ubrr = 0;
	rx0buff = BUFFenable( UART0_RX_BUFFER_SIZE, UART0_RxBuf );
	ubrr = BAUDRATEnormal(baud);
	atmega128_usart0.par.ubrr = ubrr;
	// Vtable
	atmega128_usart0.read = uart0_read;
	atmega128_usart0.getch = uart0_getch;
	atmega128_usart0.gets = uart0_gets;
	atmega128_usart0.rxflush = uart0_rxflush;
	atmega128_usart0.write = uart0_write;
	atmega128_usart0.putch = uart0_putch;
	atmega128_usart0.puts = uart0_puts;
	// Set baud rate
	if ( ubrr & 0x8000 ) // The transfer rate can be doubled by setting the U2X bit in UCSRA.
	{
   		USART0DoubleTransmissionSpeed(); // Enable 2x speed 
   		ubrr = BAUDRATEdouble(baud);
		atmega128_usart0.par.ubrr = ubrr;
   	}
	atmega128()->usart0_reg->ubrr0h = atmega128()->writehlbyte(ubrr).H;
	atmega128()->usart0_reg->ubrr0l = atmega128()->writehlbyte(ubrr).L;
	// Enable USART receiver and transmitter and receive complete interrupt
	atmega128()->usart0_reg->ucsr0b = (1 << RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	
	#ifdef URSEL0 // Set frame format: asynchronous, 8 data, no parity, 1 stop bit
		atmega128()->usart0_reg->ucsr0c = (1 << UMSEL0) | (3 << UCSZ00);
		atmega128_usart0.par.FDbits = 8;
		atmega128_usart0.par.Stopbits = 1;
		atmega128_usart0.par.Parity = 0;
	#else
		switch(FDbits){
			case 9:
				atmega128()->usart0_reg->ucsr0b |= (1 << UCSZ02);
				atmega128()->usart0_reg->ucsr0c |= (3 << UCSZ00);
				atmega128_usart0.par.FDbits = 9;
			break;
			case 8:
				atmega128()->usart0_reg->ucsr0b &= ~(1 << UCSZ02);
				atmega128()->usart0_reg->ucsr0c |= (3 << UCSZ00);
				atmega128_usart0.par.FDbits = 8;
			break;
			case 7:
				atmega128()->usart0_reg->ucsr0b &= ~(1 << UCSZ02);
				atmega128()->usart0_reg->ucsr0c |= (1 << UCSZ01);
				atmega128()->usart0_reg->ucsr0c &= ~(1 << UCSZ00);
				atmega128_usart0.par.FDbits = 7;
			break;
			case 6:
				atmega128()->usart0_reg->ucsr0b &= ~(1 << UCSZ02);
				atmega128()->usart0_reg->ucsr0c &= ~(1 << UCSZ01);
				atmega128()->usart0_reg->ucsr0c |= (1 << UCSZ00);
				atmega128_usart0.par.FDbits = 6;
			break;
			case 5:
				atmega128()->usart0_reg->ucsr0b &= ~(1 << UCSZ02);
				atmega128()->usart0_reg->ucsr0c &= ~(3 << UCSZ00);
				atmega128_usart0.par.FDbits = 5;
			break;
			default:
				atmega128()->usart0_reg->ucsr0b &= ~(1 << UCSZ02);
				atmega128()->usart0_reg->ucsr0c |= (3 << UCSZ00);
				atmega128_usart0.par.FDbits = 8;
			break;
		}
		switch(Stopbits){
			case 1:
				atmega128()->usart0_reg->ucsr0c &= ~(1 << USBS0);
				atmega128_usart0.par.Stopbits = 1;
			break;
			case 2:
				atmega128()->usart0_reg->ucsr0c |= (1 << USBS0);
				atmega128_usart0.par.Stopbits = 2;
			break;	
			default:
				atmega128()->usart0_reg->ucsr0c &= ~(1 << USBS0);
				atmega128_usart0.par.Stopbits = 1;
			break;
		}
		switch(Parity){
			case 0:
				atmega128()->usart0_reg->ucsr0c &= ~(3 << UPM00);
				atmega128_usart0.par.Parity = 0;
			break;
			case 2:
				atmega128()->usart0_reg->ucsr0c |= (1 << UPM01);
				atmega128()->usart0_reg->ucsr0c &= ~(1 << UPM00);
				atmega128_usart0.par.Parity = 2;
			break;
			case 3:
				atmega128()->usart0_reg->ucsr0c |= (3 << UPM00);
				atmega128_usart0.par.Parity = 3;
			break;	
			default:
				atmega128()->usart0_reg->ucsr0c &= ~(3 << UPM00);
				atmega128_usart0.par.Parity = 0;
			break;
		}
	#endif
	atmega128()->cpu_reg->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);
	
	return atmega128_usart0;
}

USART0* usart0(void){ return &atmega128_usart0; }

UARTvar uart0_read(void)
{
	UARTvar c;
	c = UART0_Rx;
	UART0_Rx = 0;
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
	UART0_LastRxError = 0;
}
void uart0_write(UARTvar data)
{
	uint16_t timeout;
	atmega128()->usart0_reg->ucsr0b |= 1 << UDRIE0;
	atmega128()->usart0_reg->udr0 = data;
	for( timeout = 600; !USART0DataRegisterEmpty() && timeout; timeout-- ); // minimum -> +/- 450
	//for( ; !USART0DataRegisterEmpty(); ); // without timeout
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

/*** Interrupts ***/
ISR(UART0_RECEIVE_INTERRUPT)
{
	unsigned char bit9;
	unsigned char usr;
	
	usr  = USART0ReadErrors();
	bit9 = atmega128()->usart0_reg->ucsr0b;
	bit9 = 0x01 & (bit9 >> 1);
	
	if(usr){ UART0_LastRxError = usr; }
	
	UART0_Rx = atmega128()->usart0_reg->udr0;
	rx0buff.push(&rx0buff.par, UART0_Rx);
}

ISR(UART0_TRANSMIT_INTERRUPT)
{
	atmega128()->usart0_reg->ucsr0b &= ~(1 << UDRIE0);
}

/*** Complimentary functions ***/
char* usart0messageprint(USART0* uart, char* oneshot, char* msg, char endl)
{
	char* ptr;
	if(uart0flag){ *oneshot = 0; uart0flag = 0; uart->rxflush();} // the matrix
	ptr = uart->gets();
	if(uart->getch() == endl){ strcpy(oneshot, ptr); strcpy(msg, ptr); uart0flag = 0xFF;}
	return ptr;
}

/*** Auxiliar ***/
uint8_t USART0ReceiveComplete(void)
{
	return (UCSR0A & (1 << RXC0));
}
uint8_t USART0TransmitComplete(void)
{
	return (UCSR0A & (1 << TXC0));
}
uint8_t USART0DataRegisterEmpty(void)
{
	return (UCSR0A & (1 << UDRE0));
}
uint8_t USART0FrameError(void)
{
	return (UCSR0A & (1 << FE0));
}
uint8_t USART0DataOverRun(void)
{
	return (UCSR0A & (1 << DOR0));
}
uint8_t USART0ParityError(void)
{
	return (UCSR0A & (1 << FE0));
}
uint8_t USART0ReadErrors(void)
{
	return atmega128()->readreg(UCSR0A,3,2);
}
void USART0ClearErrors(void)
{
	atmega128()->setreg(&UCSR0A,3,2,0);
}
void USART0DoubleTransmissionSpeed(void)
{
	atmega128()->setreg(&UCSR0A,4,1,1);
}

/***EOF***/

