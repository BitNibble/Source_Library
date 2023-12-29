/*********************************************************
	ATMEGA 128 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega128 by ETT ET-BASE
Date: 28112023
Comment: 
	Virtual Image Atmega 128 mapping.
**********************************************************/
#ifndef _ATMEGA128MAPPING_H_
	#define _ATMEGA128MAPPING_H_

/*** Global Library ***/
#include <avr/io.h>
#include <avr/fuse.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <inttypes.h>
// RAW IMAGE
#include "atmega128.h"

#ifndef DATA_SIZE
	#define DATA_SIZE 8
#endif
#ifndef DATA_BITS
	#define DATA_BITS 7
#endif

/*********************************************************/
/****************** Include Switches  ********************/
/*********************************************************/
// To be Selected by the User
// MODULES
#define _ANALOG_MODULE_
#define _TIMER_MODULE_
#define _EEPROM_MODULE_
#define _INTERRUPT_MODULE_
#define _SPI_MODULE_
#define _TWI_MODULE_
#define _UART_MODULE_

/*********************************************************/
/******************** USER Includes **********************/
/*********************************************************/
// MODULES
#ifdef _ANALOG_MODULE_
	#include "atmega128analog.h"
//#else
//	#warning "NO ANALOG MODULE"
#endif
#ifdef _TIMER_MODULE_
	#include "atmega128timer.h"
//#else
//	#warning "NO TIMER MODULE"
#endif
#ifdef _EEPROM_MODULE_
	#include "atmegaeeprom.h"
//#else
//	#warning "NO EEPROM MODULE"
#endif
#ifdef _INTERRUPT_MODULE_
	#include "atmega128interrupt.h"
//#else
//	#warning "NO INTERRUPT MODULE"
#endif
#ifdef _SPI_MODULE_
#include "atmega128spi.h"
//#else
//	#warning "NO SPI MODULE"
#endif
#ifdef _TWI_MODULE_
	#include "atmega128twi.h"
//#else
//	#warning "NO TWI MODULE"
#endif
#ifdef _UART_MODULE_
	#include "atmega128uart.h"
//#else
//	#warning "NO UART MODULE"
#endif

/*** Global Variable ***/
//		PARAMETER
typedef struct {
	HighLowByte HLbyte;
}Atmega128Parameter;

/*** SECOND LAYER ***/
// GPWR
typedef struct {
	Atmega128GPWR_TypeDef* reg;
}Atmega128GPWR;

// Analog Comparator (AC)
typedef struct {
	Atmega128AnalogComparator_TypeDef* reg;
	Atmega128OtherRegisters_TypeDef* misc;
}Atmega128AnalogComparator;

// Analog to Digital Converter (ADC)
typedef struct {
	Atmega128AnalogToDigitalConverter_TypeDef* reg;
	#if defined(_ANALOG_MODULE_)
		ANALOG (*enable)( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... );
	#endif
} Atmega128AnalogToDigitalConverter;

// Boot loader (BOOT_LOAD)
typedef struct {
	Atmega128BootLoader_TypeDef* reg;
} Atmega128BootLoader;

// CPU Register (CPU)
typedef struct {
	Atmega128CPURegister_TypeDef* reg;
} Atmega128CPURegister;

// EEPROM (EEPROM)
typedef struct {
	Atmega128Eeprom_TypeDef* reg;
	#if defined(_EEPROM_MODULE_)
		EEPROM (*enable)(void);
	#endif
} Atmega128Eeprom;

// External Interrupts (EXINT)
typedef struct {
	Atmega128ExternalInterrupts_TypeDef* reg;
	#if defined(_INTERRUPT_MODULE_)
		INTERRUPT (*enable)(void);
	#endif
} Atmega128ExternalInterrupts;

// I/O Port (PORTA)
typedef struct {
	Atmega128PORTA_TypeDef* reg;
}Atmega128PORTA;

// I/O Port (PORTB)
typedef struct {
	Atmega128PORTB_TypeDef* reg;
}Atmega128PORTB;

// I/O Port (PORTC)
typedef struct {
	Atmega128PORTC_TypeDef* reg;
}Atmega128PORTC;

// I/O Port (PORTD)
typedef struct {
	Atmega128PORTD_TypeDef* reg;
}Atmega128PORTD;

// I/O Port (PORTE)
typedef struct {
	Atmega128PORTE_TypeDef* reg;
}Atmega128PORTE;

// I/O Port (PORTF)
typedef struct {
	Atmega128PORTF_TypeDef* reg;
}Atmega128PORTF;

// I/O Port (PORTG)
typedef struct {
	Atmega128PORTG_TypeDef* reg;
} Atmega128PORTG;

// JTAG Interface (JTAG)
typedef struct {
	Atmega128JtagInterface_TypeDef* reg;
} Atmega128JtagInterface;

// Other Registers (MISC)
typedef struct {
	Atmega128OtherRegisters_TypeDef* reg;
} Atmega128OtherRegisters;

// Serial Peripheral Interface (SPI)
typedef struct {
	Atmega128SerialPeripherialInterface_TypeDef* reg;
	#if defined(_SPI_MODULE_)
		SPI (*enable)(uint8_t master_slave_select, uint8_t data_order,  uint8_t data_modes, uint8_t prescaler);
	#endif
} Atmega128SerialPeripherialInterface;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	Atmega128TimerCounter1_TypeDef* reg;
	Atmega128OtherRegisters_TypeDef* misc;
	#if defined(_TIMER_MODULE_)
		TIMER_COUNTER1 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega128TimerCounter1;

// Timer/Counter, 16-bit (TC3)
typedef struct {
	Atmega128TimerCounter3_TypeDef* reg;
	Atmega128OtherRegisters_TypeDef* misc;
	#if defined(_TIMER_MODULE_)
		TIMER_COUNTER3 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega128TimerCounter3;

// Timer/Counter, 8-bit (TC2)
typedef struct {
	Atmega128TimerCounter2_TypeDef* reg;
	#if defined(_TIMER_MODULE_)
		TIMER_COUNTER2 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega128TimerCounter2;

// Timer/Counter, 8-bit A sync (TC0)
typedef struct {
	Atmega128TimerCounter0_TypeDef* reg;
	Atmega128OtherRegisters_TypeDef* misc;
	#if defined(_TIMER_MODULE_)
		TIMER_COUNTER0 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega128TimerCounter0;

// Two Wire Serial Interface (TWI)
typedef struct {
	Atmega128TwoWireSerialInterface_TypeDef* reg;
	#if defined(_TWI_MODULE_)
		TWI (*enable)(uint8_t atmega_ID,  uint8_t prescaler);
	#endif
} Atmega128TwoWireSerialInterface;

// USART (USART0)
typedef struct {
	Atmega128Usart0_TypeDef* reg;
	#if defined(_UART_MODULE_)
		UART0 (*enable)(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
	#endif
} Atmega128Usart0;

// USART (USART1)
typedef struct {
	Atmega128Usart1_TypeDef* reg;
	#if defined(_UART_MODULE_)
		UART1 (*enable)(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
	#endif
} Atmega128Usart1;

// Watchdog Timer (WDT)
typedef struct {
	Atmega128WatchdogTimer_TypeDef* reg;
} Atmega128WatchdogTimer;

/*******************************************************************/
/************************* ATMEGA 128 IMAGE ************************/
/*******************************************************************/

typedef struct {
	//		PARAMETER
	Atmega128Parameter par;
	//		SECOND LAYER
	Atmega128GPWR gpwr;
	Atmega128AnalogComparator ac;
	Atmega128AnalogToDigitalConverter adc;
	Atmega128BootLoader boot_load;
	Atmega128CPURegister cpu;
	Atmega128Eeprom eeprom;
	Atmega128ExternalInterrupts exint;
	Atmega128PORTA porta;
	Atmega128PORTB portb;
	Atmega128PORTC portc;
	Atmega128PORTD portd;
	Atmega128PORTE porte;
	Atmega128PORTF portf;
	Atmega128PORTG portg;
	Atmega128JtagInterface jtag;
	Atmega128OtherRegisters misc;
	Atmega128SerialPeripherialInterface spi;
	Atmega128TimerCounter1 tc1;
	Atmega128TimerCounter3 tc3;
	Atmega128TimerCounter2 tc2;
	Atmega128TimerCounter0 tc0;
	Atmega128TwoWireSerialInterface twi;
	Atmega128Usart0 usart0;
	Atmega128Usart1 usart1;
	Atmega128WatchdogTimer wdt;
	//		Pointer Function
	uint16_t (*readhlbyte)(HighLowByte reg);
	uint16_t (*readlhbyte)(HighLowByte reg);
	HighLowByte (*writehlbyte)(uint16_t val);
	HighLowByte (*writelhbyte)(uint16_t val);
	uint16_t (*swapbyte)(uint16_t num);
	uint8_t (*byte_mask)(uint8_t target, uint8_t mask);
	void (*byte_set)(uint8_t* target, uint8_t set);
	void (*byte_clear)(uint8_t* target, uint8_t clear);
	uint8_t (*byte_shiftright)(uint8_t target, uint8_t shift);
	uint8_t (*byte_shiftleft)(uint8_t target, uint8_t shift);
	uint8_t (*readreg)(uint8_t reg, uint8_t size_block, uint8_t bit);
	void (*writereg)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
	void (*setreg)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
	void (*setbit)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
	uint8_t (*getsetbit)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit);
	/******/
	//void (*Clock_Prescaler_Select)(volatile uint8_t prescaler);
	void (*Move_Interrupts_To_Boot)(void);
}ATMEGA128;

/*** Global Variable ***/
ATMEGA128 atmega128;
/*** Global Header ***/
ATMEGA128 ATMEGA128enable(void);

#endif
/***EOF***/

