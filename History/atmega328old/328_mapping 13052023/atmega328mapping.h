/********************************************************************
	ATMEGA 328 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Date: 13052023
Comment: 
	Virtual Image Atmega 328 mapping.
*********************************************************************/
#ifndef _ATMEGA328MAPPING_H_
	#define _ATMEGA328MAPPING_H_

/*** Global Library ***/
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <inttypes.h>
// Comment out modules not being used
// RAW IMAGE
#include "atmega328.h"
// MODULES
#include "atmega328analog.h"
#include "atmegaeeprom.h"
#include "atmega328interrupt.h"
#include "atmega328timer.h"
#include "atmega328twi.h"
//#include "atmega328spi.h"
#include "atmega328uart.h"

/*** Global Variable ***/
//		PARAMETER
typedef struct {
	HighLowByte HLbyte;
}Atmega328Parameter;
//		SECOND LAYER
// GPWR
typedef struct {
	Atmega328GPWR_TypeDef* reg;
}Atmega328GPWR;

// Analog Comparator (AC)
typedef struct {
	Atmega328AnalogComparator_TypeDef* reg;
}Atmega328AnalogComparator;

// Analog to Digital Converter (ADC)
typedef struct {
	Atmega328AnalogToDigitalConverter_TypeDef* reg;
	#if defined(_ATMEGA328ANALOG_H_)
		ANALOG (*enable)( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... );
	#endif
} Atmega328AnalogToDigitalConverter;

// CPU Register (CPU)
typedef struct {
	Atmega328CPURegister_TypeDef* reg;
	Atmega328CpuGeneralPurposeIoRegister_TypeDef* gpio;
} Atmega328CPURegister;

// EEPROM (EEPROM)
typedef struct {
	Atmega328Eeprom_TypeDef* reg;
	#if defined(_ATMEGAEEPROM_H_)
		EEPROM (*enable)(void);
	#endif
} Atmega328Eeprom;

// External Interrupts (EXINT)
typedef struct {
	Atmega328ExternalInterrupts_TypeDef* reg;
	#if defined(_ATMEGA328INTERRUPT_H_)
		INTERRUPT (*enable)(void);
	#endif
} Atmega328ExternalInterrupts;

// I/O Port (PORTB)
typedef struct {
	Atmega328PORTB_TypeDef* reg;
}Atmega328PORTB;

// I/O Port (PORTC)
typedef struct {
	Atmega328PORTC_TypeDef* reg;
}Atmega328PORTC;

// I/O Port (PORTD)
typedef struct {
	Atmega328PORTD_TypeDef* reg;
}Atmega328PORTD;

// Serial Peripheral Interface (SPI)
typedef struct {
	Atmega328SerialPeripherialInterface_TypeDef* reg;
	#if defined(_ATMEGA328SPI_H_)
		SPI (*enable)(uint8_t master_slave_select, uint8_t data_order,  uint8_t data_modes, uint8_t prescaler);
	#endif
} Atmega328SerialPeripherialInterface;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	Atmega328TimerCounter1_TypeDef* reg;
	Atmega328TimerGeneralControlRegister_TypeDef* gcr;
	Atmega328TimerInterruptFlag_TypeDef* iflag;
	Atmega328TimerMask_TypeDef* imask;
	Atmega328TimerCompareRegister1_TypeDef* comp;
	#if defined(_ATMEGA328TIMER_H_)
		TIMER_COUNTER1 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega328TimerCounter1;

// Timer/Counter, 8-bit (TC0)
typedef struct {
	Atmega328TimerCounter0_TypeDef* reg;
	Atmega328TimerGeneralControlRegister_TypeDef* gcr;
	Atmega328TimerInterruptFlag_TypeDef* iflag;
	Atmega328TimerMask_TypeDef* imask;
	Atmega328TimerCompareRegister0_TypeDef* comp;
	#if defined(_ATMEGA328TIMER_H_)
		TIMER_COUNTER0 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega328TimerCounter0;

// Timer/Counter, 8-bit A sync (TC2)
typedef struct {
	Atmega328TimerCounter2_TypeDef* reg;
	Atmega328TimerGeneralControlRegister_TypeDef* gcr;
	Atmega328TimerInterruptFlag_TypeDef* iflag;
	Atmega328TimerMask_TypeDef* imask;
	Atmega328TimerCompareRegister2_TypeDef* comp;
	#if defined(_ATMEGA328TIMER_H_)
		TIMER_COUNTER2 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega328TimerCounter2;

// Two Wire Serial Interface (TWI)
typedef struct {
	Atmega328TwoWireSerialInterface_TypeDef* reg;
	#if defined(_ATMEGA328TWI_H_)
		TWI (*enable)(uint8_t atmega_ID, uint8_t prescaler);
	#endif
} Atmega328TwoWireSerialInterface;

// USART (USART)
typedef struct {
	Atmega328Usart_TypeDef* reg;
	#if defined(_ATMEGA328UART_H_)
		UART (*enable)(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
	#endif
} Atmega328Usart;

// Watchdog Timer (WDT)
typedef struct {
	Atmega328WatchdogTimer_TypeDef* reg;
} Atmega328WatchdogTimer;

//		STATIC RAM
// Interrupt Vectors (ISR)
typedef struct {
	Atmega328InterruptVectors_TypeDef* reg;
} Atmega328InterruptVectors;

// ATMEGA 328 IMAGE
typedef struct {
	//		Parameter
	Atmega328Parameter par;
	//		Second Layer
	Atmega328GPWR gpwr;
	Atmega328AnalogComparator ac;
	Atmega328AnalogToDigitalConverter adc;
	Atmega328CPURegister cpu;
	Atmega328Eeprom eeprom;
	Atmega328ExternalInterrupts exint;
	Atmega328PORTB portb;
	Atmega328PORTC portc;
	Atmega328PORTD portd;
	Atmega328SerialPeripherialInterface spi;
	Atmega328TimerCounter1 tc1;
	Atmega328TimerCounter0 tc0;
	Atmega328TimerCounter2 tc2;
	Atmega328TwoWireSerialInterface twi;
	Atmega328Usart usart;
	Atmega328WatchdogTimer wdt;
	//		Function Pointer
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
}ATMEGA328;

/*** Global Header ***/
ATMEGA328 ATMEGA328enable(void);

// Experiment A
//void (*timer2_compa)(void);
//void (*timer2_compb)(void);
//void (*timer2_ovf)(void);
//void (*timer1_capt)(void);
//void (*timer1_compa)(void);
//void (*timer1_compb)(void);
//void (*timer1_ovf)(void);
//void (*timer0_compa)(void);
//void (*timer0_compb)(void);
//void (*timer0_ovf)(void);

#endif

/***EOF***/

