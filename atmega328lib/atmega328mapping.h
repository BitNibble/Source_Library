/********************************************************************
	ATMEGA 328 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Date: 07122023
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
// RAW IMAGE
#include "atmega328.h"

/*********************************************************/
/****************** Include Switches  ********************/
/*********************************************************/
// To be Selected by the User
// MODULES
#define _TIMER_MODULE_
#define _UART_MODULE_

/*********************************************************/
/******************** USER Includes **********************/
/*********************************************************/
// MODULES
#ifdef _ANALOG_MODULE_
	#include "atmega328analog.h"
//#else
//	#warning "NO ANALOG MODULE"
#endif
#ifdef _EEPROM_MODULE_
	#include "atmegaeeprom.h"
//#else
//	#warning "NO EEPROM MODULE"
#endif
#ifdef _INTERRUPT_MODULE_
	#include "atmega328interrupt.h"
//#else
//	#warning "NO INTERRUPT MODULE"
#endif
#ifdef _TIMER_MODULE_
	#include "atmega328timer.h"
//#else
//	#warning "NO TIMER MODULE"
#endif
#ifdef _TWI_MODULE_
	#include "atmega328twi.h"
//#else
//	#warning "NO TWI MODULE"
#endif
#ifdef _SPI_MODULE_
	#include "atmega328spi.h"
//#else
//	#warning "NO SPI MODULE"
#endif
#ifdef _UART_MODULE_
	#include "atmega328uart.h"
//#else
//	#warning "NO UART MODULE"
#endif
/*********************************************************/

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
	Atmega328AnalogComparatorDid_TypeDef* didr1;
}Atmega328AnalogComparator;

// Analog to Digital Converter (ADC)
typedef struct {
	Atmega328AnalogToDigitalConverter_TypeDef* reg;
	#if defined(_ANALOG_MODULE_)
		ANALOG run;
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
	#if defined(_EEPROM_MODULE_)
		EEPROM run;
		EEPROM (*enable)(void);
	#endif
} Atmega328Eeprom;

// External Interrupts (EXINT)
typedef struct {
	Atmega328ExternalInterrupt_TypeDef* reg;
	Atmega328ExternalInterruptFlag_TypeDef* iflag;
	Atmega328ExternalInterruptMask_TypeDef* imask;
	#if defined(_INTERRUPT_MODULE_)
		INTERRUPT run;
		INTERRUPT (*enable)(void);
	#endif
} Atmega328ExternalInterrupt;

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
	#if defined(_SPI_MODULE_)
		SPI run;
		SPI (*enable)(uint8_t master_slave_select, uint8_t data_order,  uint8_t data_modes, uint8_t prescaler);
	#endif
} Atmega328SerialPeripherialInterface;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	Atmega328TimerCounter1_TypeDef* reg;
	Atmega328TimerGeneralControlRegister_TypeDef* gcr;
	Atmega328TimerInterruptFlag_TypeDef* iflag;
	Atmega328TimerInterruptMask_TypeDef* imask;
	Atmega328TimerCompareRegister1_TypeDef* comp;
	#if defined(_TIMER_MODULE_)
		TIMER_COUNTER1 run;
		TIMER_COUNTER1 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega328TimerCounter1;

// Timer/Counter, 8-bit (TC0)
typedef struct {
	Atmega328TimerCounter0_TypeDef* reg;
	Atmega328TimerGeneralControlRegister_TypeDef* gcr;
	Atmega328TimerInterruptFlag_TypeDef* iflag;
	Atmega328TimerInterruptMask_TypeDef* imask;
	Atmega328TimerCompareRegister0_TypeDef* comp;
	#if defined(_TIMER_MODULE_)
		TIMER_COUNTER0 run;
		TIMER_COUNTER0 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega328TimerCounter0;

// Timer/Counter, 8-bit A sync (TC2)
typedef struct {
	Atmega328TimerCounter2_TypeDef* reg;
	Atmega328TimerGeneralControlRegister_TypeDef* gcr;
	Atmega328TimerInterruptFlag_TypeDef* iflag;
	Atmega328TimerInterruptMask_TypeDef* imask;
	Atmega328TimerCompareRegister2_TypeDef* comp;
	#if defined(_TIMER_MODULE_)
		TIMER_COUNTER2 run;
		TIMER_COUNTER2 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega328TimerCounter2;

// Two Wire Serial Interface (TWI)
typedef struct {
	Atmega328TwoWireSerialInterface_TypeDef* reg;
	#if defined(_TWI_MODULE_)
		TWI run;
		TWI (*enable)(uint8_t atmega_ID, uint8_t prescaler);
	#endif
} Atmega328TwoWireSerialInterface;

// USART (USART)
typedef struct {
	Atmega328Usart_TypeDef* reg;
	#if defined(_UART_MODULE_)
		UART run;
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

/*******************************************************************/
/*******************************************************************/
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
	Atmega328ExternalInterrupt exint;
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
	uint8_t (*readreg)(uint8_t reg, uint8_t size_block, uint8_t bit);
	void (*writereg)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
	void (*setreg)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
	void (*setbit)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
	uint8_t (*getsetbit)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit);
	/******/
	void (*Clock_Prescaler_Select)(volatile uint8_t prescaler);
	void (*Move_Interrupts_To_Boot)(void);
}ATMEGA328;

/*** Global Header ***/
ATMEGA328 ATMEGA328enable(void);

/*** Global Variable ***/
ATMEGA328 atmega328;

#endif

/***EOF***/

