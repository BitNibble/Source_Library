/************************************************************************
	Atmega328Usart0
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 ETT ET-BASE
Update: 01/01/2024
************************************************************************/
/****** Comment:
	stable
************************************************************************/
#ifndef _ATMEGA328USART0_H_
	#define _ATMEGA328USART0_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#ifndef GLOBAL_INTERRUPT_ENABLE
	#define GLOBAL_INTERRUPT_ENABLE 7
#endif
#ifndef UART_RX_BUFFER_SIZE
	#define UART_RX_BUFFER_SIZE 32
#endif
#define UARTvar char
// test if the size of the circular buffers fits into SRAM
#if ( ( UART_RX_BUFFER_SIZE ) >= ( RAMEND - 0x60 ) )
	#error "size of UART_RX_BUFFER_SIZE + UART_TX_BUFFER_SIZE larger than size of SRAM"
#endif
// Parity choices
#define NONE 0
#define EVEN 2
#define ODD 3
#define UART_FRAME_ERROR      0x0800	/* Framing Error by UART       */
#define UART_OVERRUN_ERROR    0x0400	/* Overrun condition by UART   */
#define UART_BUFFER_OVERFLOW  0x0200	/* receive ringbuffer overflow */
#define UART_NO_DATA          0x0100	/* no receive data available   */
// USART, RX Complete Handler
#define UART_RX_COMPLETE		USART_RX_vect
// USART, UDR Empty Handler
#define UART_UDR_EMPTY			USART_UDRE_vect
//USART, TX Complete Handler
#define UART_TX_COMPLETE		USART_TX_vect

/*** Global Variable ***/
typedef struct{
	unsigned int ubrr;
	unsigned int FDbits;
	unsigned int Stopbits;
	unsigned int Parity;
}uart_parameter;

typedef struct{
	// Parameters
	uart_parameter par;
	// prototype pointers
	UARTvar (*read)(void);
	UARTvar (*getch)(void);
	UARTvar* (*gets)(void);
	void (*rxflush)(void);
	void (*write)(UARTvar data);
	void (*putch)(UARTvar c);
	void (*puts)(UARTvar* s);
}USART0;

USART0 usart0_enable( uint32_t baud, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
USART0* usart0(void);

char* usart0_messageprint(USART0* uart, char* oneshot, char* msg, const char* endl);

#endif

/***EOF***/

