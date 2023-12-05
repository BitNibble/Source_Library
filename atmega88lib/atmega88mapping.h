/********************************************************************
	ATMEGA 88 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega88 by ETT ET-BASE
Date: 05122023
Comment: 
	Virtual Image Atmega 88 mapping.
*********************************************************************/
#ifndef _ATMEGA88MAPPING_H_
	#define _ATMEGA88MAPPING_H_

/*** Global Library ***/
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <inttypes.h>
// RAW IMAGE
#include "atmega88.h"

/*********************************************************/
/******************** USER Includes **********************/
/*********************************************************/
// MODULES
// Comment out modules not being used
//#include "atmega88analog.h"
//#include "atmegaeeprom.h"
//#include "atmega88interrupt.h"
//#include "atmega88timer.h"
//#include "atmega88twi.h"
//#include "atmega88spi.h"
//#include "atmega88uart.h"
/*********************************************************/

/*** Global Variable ***/
//		PARAMETER
typedef struct {
	HighLowByte HLbyte;
}Atmega88Parameter;
//		SECOND LAYER
// GPWR
typedef struct {
	Atmega88GPWR_TypeDef* reg;
}Atmega88GPWR;

// Analog Comparator (AC)
typedef struct {
	Atmega88AnalogComparator_TypeDef* reg;
	Atmega88AnalogComparatorDid_TypeDef* didr1;
}Atmega88AnalogComparator;

// Analog to Digital Converter (ADC)
typedef struct {
	Atmega88AnalogToDigitalConverter_TypeDef* reg;
	#if defined(_ATMEGA88ANALOG_H_)
		ANALOG run;
		ANALOG (*enable)( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... );
	#endif
} Atmega88AnalogToDigitalConverter;

// CPU Register (CPU)
typedef struct {
	Atmega88CPURegister_TypeDef* reg;
	Atmega88CpuGeneralPurposeIoRegister_TypeDef* gpio;
} Atmega88CPURegister;

// EEPROM (EEPROM)
typedef struct {
	Atmega88Eeprom_TypeDef* reg;
	#if defined(_ATMEGAEEPROM_H_)
		EEPROM run;
		EEPROM (*enable)(void);
	#endif
} Atmega88Eeprom;

// External Interrupts (EXINT)
typedef struct {
	Atmega88ExternalInterrupt_TypeDef* reg;
	Atmega88ExternalInterruptFlag_TypeDef* iflag;
	Atmega88ExternalInterruptMask_TypeDef* imask;
	#if defined(_ATMEGA88INTERRUPT_H_)
		INTERRUPT run;
		INTERRUPT (*enable)(void);
	#endif
} Atmega88ExternalInterrupt;

// I/O Port (PORTB)
typedef struct {
	Atmega88PORTB_TypeDef* reg;
}Atmega88PORTB;

// I/O Port (PORTC)
typedef struct {
	Atmega88PORTC_TypeDef* reg;
}Atmega88PORTC;

// I/O Port (PORTD)
typedef struct {
	Atmega88PORTD_TypeDef* reg;
}Atmega88PORTD;

// Serial Peripheral Interface (SPI)
typedef struct {
	Atmega88SerialPeripherialInterface_TypeDef* reg;
	#if defined(_ATMEGA88SPI_H_)
		SPI run;
		SPI (*enable)(uint8_t master_slave_select, uint8_t data_order,  uint8_t data_modes, uint8_t prescaler);
	#endif
} Atmega88SerialPeripherialInterface;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	Atmega88TimerCounter1_TypeDef* reg;
	Atmega88TimerGeneralControlRegister_TypeDef* gcr;
	Atmega88TimerInterruptFlag_TypeDef* iflag;
	Atmega88TimerInterruptMask_TypeDef* imask;
	Atmega88TimerCompareRegister1_TypeDef* comp;
	#if defined(_ATMEGA88TIMER_H_)
		TIMER_COUNTER1 run;
		TIMER_COUNTER1 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega88TimerCounter1;

// Timer/Counter, 8-bit (TC0)
typedef struct {
	Atmega88TimerCounter0_TypeDef* reg;
	Atmega88TimerGeneralControlRegister_TypeDef* gcr;
	Atmega88TimerInterruptFlag_TypeDef* iflag;
	Atmega88TimerInterruptMask_TypeDef* imask;
	Atmega88TimerCompareRegister0_TypeDef* comp;
	#if defined(_ATMEGA88TIMER_H_)
		TIMER_COUNTER0 run;
		TIMER_COUNTER0 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega88TimerCounter0;

// Timer/Counter, 8-bit A sync (TC2)
typedef struct {
	Atmega88TimerCounter2_TypeDef* reg;
	Atmega88TimerGeneralControlRegister_TypeDef* gcr;
	Atmega88TimerInterruptFlag_TypeDef* iflag;
	Atmega88TimerInterruptMask_TypeDef* imask;
	Atmega88TimerCompareRegister2_TypeDef* comp;
	#if defined(_ATMEGA88TIMER_H_)
		TIMER_COUNTER2 run;
		TIMER_COUNTER2 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega88TimerCounter2;

// Two Wire Serial Interface (TWI)
typedef struct {
	Atmega88TwoWireSerialInterface_TypeDef* reg;
	#if defined(_ATMEGA88TWI_H_)
		TWI run;
		TWI (*enable)(uint8_t atmega_ID, uint8_t prescaler);
	#endif
} Atmega88TwoWireSerialInterface;

// USART (USART)
typedef struct {
	Atmega88Usart_TypeDef* reg;
	#if defined(_ATMEGA88UART_H_)
		UART run;
		UART (*enable)(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
	#endif
} Atmega88Usart;

// Watchdog Timer (WDT)
typedef struct {
	Atmega88WatchdogTimer_TypeDef* reg;
} Atmega88WatchdogTimer;

//		STATIC RAM
// Interrupt Vectors (ISR)
typedef struct {
	Atmega88InterruptVectors_TypeDef* reg;
} Atmega88InterruptVectors;

/*******************************************************************/
/*******************************************************************/
// ATMEGA 88 IMAGE
typedef struct {
	//		Parameter
	Atmega88Parameter par;
	//		Second Layer
	Atmega88GPWR gpwr;
	Atmega88AnalogComparator ac;
	Atmega88AnalogToDigitalConverter adc;
	Atmega88CPURegister cpu;
	Atmega88Eeprom eeprom;
	Atmega88ExternalInterrupt exint;
	Atmega88PORTB portb;
	Atmega88PORTC portc;
	Atmega88PORTD portd;
	Atmega88SerialPeripherialInterface spi;
	Atmega88TimerCounter1 tc1;
	Atmega88TimerCounter0 tc0;
	Atmega88TimerCounter2 tc2;
	Atmega88TwoWireSerialInterface twi;
	Atmega88Usart usart;
	Atmega88WatchdogTimer wdt;
	//		General Function Pointer
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
}ATMEGA88;

/*** Global Header ***/
ATMEGA88 ATMEGA88enable(void);

/*** Global Variable ***/
ATMEGA88 atmega88;

#endif

/***EOF***/

