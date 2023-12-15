/************************************************************************
	Atmega32u4Uart
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega32u4 ETT ET-BASE
Date: 03122023
Comment:
	stable
************************************************************************/
#ifndef _ATMEGA32U4UART_H_
	#define _ATMEGA32U4UART_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#ifndef F_CPU
	#define F_CPU 8000000UL
#endif
#ifndef GLOBAL_INTERRUPT_ENABLE
	#define GLOBAL_INTERRUPT_ENABLE 7
#endif
#ifndef UART_RX_BUFFER_SIZE
	#define UART_RX_BUFFER_SIZE 32
#endif
#define UARTvar char
// Parity choices
#define NONE 0
#define EVEN 2
#define ODD 1

/*** Global Variable ***/
typedef struct {
	unsigned int ubrr;
	unsigned int FDbits;
	unsigned int Stopbits;
	unsigned int Parity;
}uartparameter;

struct uart {
	// Parameters
	uartparameter par;
	// prototype pointers
	UARTvar (*read)(void);
	UARTvar (*getch)(void);
	UARTvar* (*gets)(void);
	void (*rxflush)(void);
	void (*write)(UARTvar data);
	void (*putch)(UARTvar c);
	void (*puts)(UARTvar* s);
};
typedef struct uart UART;

/*** Global Header ****/
UART UARTenable( unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );

#endif

/***EOF***/

