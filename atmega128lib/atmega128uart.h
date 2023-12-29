/************************************************************************
	ATMEGA128UART
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega128
Update: 29/12/2023
Comment:
	Stable
************************************************************************/
#ifndef _ATMEGA128UART_H_
	#define _ATMEGA128UART_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#ifndef F_CPU
	#define F_CPU 16000000UL
#endif
#ifndef TWI_SCL_CLOCK
	#define TWI_SCL_CLOCK 100000UL
#endif

#ifndef GLOBAL_INTERRUPT_ENABLE
	#define GLOBAL_INTERRUPT_ENABLE 7
#endif
#ifndef UART0_RX_BUFFER_SIZE
	#define UART0_RX_BUFFER_SIZE 32
#endif
#ifndef UART1_RX_BUFFER_SIZE
	#define UART1_RX_BUFFER_SIZE 32
#endif
#define UARTvar char
// Parity choices
#define NONE 0
#define EVEN 2
#define ODD 3

/*** Global Variable ***/
typedef struct {
	// Parameters
	uint8_t ubrr;
	uint8_t FDbits;
	uint8_t Stopbits;
	uint8_t Parity;
}uart0parameter;

struct uart0{
	uart0parameter par;
	// prototype pointers
	UARTvar (*read)(void);
	UARTvar (*getch)(void);
	UARTvar* (*gets)(void);
	void (*rxflush)(void);
	void (*write)(UARTvar data);
	void (*putch)(UARTvar c);
	void (*puts)(UARTvar* s);
};
typedef struct uart0 UART0;

typedef struct {
	// Parameters
	uint8_t ubrr;
	uint8_t FDbits;
	uint8_t Stopbits;
	uint8_t Parity;
}uart1parameter;

struct uart1{
	uart0parameter par;
	// prototype pointers
	UARTvar (*read)(void);
	UARTvar (*getch)(void);
	UARTvar* (*gets)(void);
	void (*rxflush)(void);
	void (*write)(UARTvar data);
	void (*putch)(UARTvar c);
	void (*puts)(UARTvar* s);
};
typedef struct uart1 UART1;

/*** Global Header ***/
UART0 UART0enable(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
UART1 UART1enable(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );

#endif
/***EOF***/

