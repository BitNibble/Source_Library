/********************************************************************
	ATMEGA 328 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update: 01/01/2024
Comment: 
	Virtual Image Atmega 328 mapping.
	NB:
	- This Header file should be the first to be placed
*********************************************************************/
#ifndef _ATMEGA328MAPPING_H_
	#define _ATMEGA328MAPPING_H_
	
/*** Working Frequency ***/
// User May change to conform to use
#ifndef F_CPU
	#define F_CPU 8000000UL
#endif

/*** Global Library ***/
#include <avr/io.h>
#include <avr/fuse.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include <math.h>
/*** RAW IMAGE ***/
#include "atmega328.h"
/****************/
#ifndef DATA_SIZE
	#define DATA_SIZE 8
#endif
#ifndef DATA_BITS
	#define DATA_BITS 7
#endif
/****************/
/*********************************************************/
/****************** Include Switches  ********************/
/*********************************************************/
// User may Comment out if not in use
// MODULES
#define _TIMER0_MODULE_
#define _TIMER1_MODULE_
#define _TIMER2_MODULE_
#define _USART0_MODULE_

/*********************************************************/
/******************* Hardware Includes *******************/
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
#ifdef _TIMER0_MODULE_
	#include "atmega328timer0.h"
//#else
//	#warning "NO TIMER MODULE"
#endif
#ifdef _TIMER1_MODULE_
	#include "atmega328timer1.h"
//#else
//	#warning "NO TIMER MODULE"
#endif
#ifdef _TIMER2_MODULE_
	#include "atmega328timer2.h"
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
#ifdef _USART0_MODULE_
	#include "atmega328usart0.h"
//#else
//	#warning "NO UART MODULE"
#endif
/*********************************************************/

/*** Global Variable ***/
//		PARAMETER
typedef struct {
	HighLowByte HLbyte;
}Atmega328Parameter;

/********************/
/*** Second Layer ***/
/********************/
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
		EEPROM (*enable)(void);
	#endif
} Atmega328Eeprom;

// External Interrupts (EXINT)
typedef struct {
	Atmega328ExternalInterrupt_TypeDef* reg;
	Atmega328ExternalInterruptFlag_TypeDef* iflag;
	Atmega328ExternalInterruptMask_TypeDef* imask;
	#if defined(_INTERRUPT_MODULE_)
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
	#if defined(_TIMER1_MODULE_)
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
	#if defined(_TIMER0_MODULE_)
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
	#if defined(_TIMER2_MODULE_)
		TIMER_COUNTER2 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega328TimerCounter2;

// Two Wire Serial Interface (TWI)
typedef struct {
	Atmega328TwoWireSerialInterface_TypeDef* reg;
	#if defined(_TWI_MODULE_)
		TWI (*enable)(uint8_t atmega_ID, uint8_t prescaler);
	#endif
} Atmega328TwoWireSerialInterface;

// USART (USART0)
typedef struct {
	Atmega328Usart_TypeDef* reg;
	#if defined(_USART0_MODULE_)
		USART0 (*enable)(uint32_t baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
	#endif
} Atmega328Usart;

// Watchdog Timer (WDT)
typedef struct {
	Atmega328WatchdogTimer_TypeDef* reg;
} Atmega328WatchdogTimer;

/*******************************************************************/
/************************* ATMEGA 328 IMAGE ************************/
/*************************** Third Layer ***************************/
/*******************************************************************/
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
	Atmega328Usart usart0;
	Atmega328WatchdogTimer wdt;
	//		Function Pointer
	uint16_t (*readhlbyte)(HighLowByte reg);
	uint16_t (*readlhbyte)(HighLowByte reg);
	HighLowByte (*writehlbyte)(uint16_t val);
	HighLowByte (*writelhbyte)(uint16_t val);
	uint16_t (*swapbyte)(uint16_t num);
	uint8_t (*readreg)(uint8_t reg, uint8_t size_block, uint8_t bit);
	void (*writereg)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
	void (*setreg)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
	void (*setbit)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
	uint8_t (*getsetbit)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit);
	/******/
	void (*Clock_Prescaler_Select)(volatile uint8_t prescaler);
	void (*Move_Interrupts_To_Boot)(void);
}ATMEGA328;

/*** Global Variable ***/
ATMEGA328 atmega328;
/*** Global Header ***/
ATMEGA328 ATMEGA328enable(void);

/*** General ***/
uint16_t BAUDRATEnormal(uint32_t BAUD);
uint16_t BAUDRATEdouble(uint32_t BAUD);
uint16_t BAUDRATEsynchronous(uint32_t BAUD);

#endif

/***EOF***/

/*** Interrupt List ***/
// ISR(RESET_vect){}
// ISR(INT0_vect){}
// ISR(INT1_vect){}
// ISR(PCINT0_vect){}
// ISR(PCINT1_vect){}
// ISR(PCINT2_vect){}
// ISR(WDT_vect){}
// ISR(TIMER2_COMPA_vect){}
// ISR(TIMER2_COMPB_vect){}
// ISR(TIMER2_OVF_vect){}
// ISR(TIMER1_CAPT_vect){}
// ISR(TIMER1_COMPA_vect){}
// ISR(TIMER1_COMPB_vect){}
// ISR(TIMER1_OVF_vect){}
// ISR(TIMER0_COMPA_vect){}
// ISR(TIMER0_COMPB_vect){}
// ISR(TIMER0_OVF_vect){}
// ISR(SPI_STC_vect){}
// ISR(USART_RX_vect){}
// ISR(USART_UDRE_vect){}
// ISR(USART_TX_vect){}
// ISR(ADC_vect){}
// ISR(EE_READY_vect){}
// ISR(ADC_vect)
// ISR(ANALOG_COMP_vect){}
// ISR(TWI_vect){}
// ISR(SPM_READY_vect){}
// ISR(USART_RX_vect){}
// ISR(USART_UDRE_vect){}
// ISR(USART_TX_vect){}
