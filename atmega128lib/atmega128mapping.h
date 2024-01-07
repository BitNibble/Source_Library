/*********************************************************
	ATMEGA 128 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega128 by ETT ET-BASE
Update: 01/01/2024
Comment: 
	Virtual Image Atmega 128 mapping.
	NB:
	- This Header file should be the first to be placed
**********************************************************/
#ifndef _ATMEGA128MAPPING_H_
	#define _ATMEGA128MAPPING_H_
	
/*** Working Frequency ***/
// User May change to conform to use
#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

/*** Global Library ***/
#include <avr/io.h>
#include <avr/fuse.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>
/*** RAW IMAGE ***/
#include "atmega128.h"
/****************/
#ifndef IO_var
	#define IO_var uint8_t
#endif
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
#define _ANALOG_MODULE_
#define _TIMER0_MODULE_
#define _TIMER1_MODULE_
#define _TIMER2_MODULE_
#define _TIMER3_MODULE_
#define _EEPROM_MODULE_
#define _INTERRUPT_MODULE_
#define _SPI_MODULE_
#define _TWI_MODULE_
#define _USART0_MODULE_
#define _USART1_MODULE_
/*********************************************************/
/****************** Hardware Includes ********************/
/*********************************************************/
// MODULES
#ifdef _ANALOG_MODULE_
	#include "atmega128analog.h"
//#else
//	#warning "NO ANALOG MODULE"
#endif
#ifdef _TIMER0_MODULE_
	#include "atmega128timer0.h"
//#else
//	#warning "NO TIMER MODULE"
#endif
#ifdef _TIMER1_MODULE_
#include "atmega128timer1.h"
//#else
//	#warning "NO TIMER MODULE"
#endif
#ifdef _TIMER2_MODULE_
#include "atmega128timer2.h"
//#else
//	#warning "NO TIMER MODULE"
#endif
#ifdef _TIMER3_MODULE_
#include "atmega128timer3.h"
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
#ifdef _USART0_MODULE_
#include "atmega128usart0.h"
//#else
//	#warning "NO UART MODULE"
#endif
#ifdef _USART1_MODULE_
#include "atmega128usart1.h"
//#else
//	#warning "NO UART MODULE"
#endif
/*** Global Variable ***/
//		PARAMETER
typedef struct {
	HighLowByte HLbyte;
}Atmega128Parameter;
/********************/
/*** Second Layer ***/
/********************/
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
		SPI* (*run)(void);
		SPI (*enable)(uint8_t master_slave_select, uint8_t data_order,  uint8_t data_modes, uint8_t prescaler);
	#endif
} Atmega128SerialPeripherialInterface;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	Atmega128TimerCounter1_TypeDef* reg;
	Atmega128OtherRegisters_TypeDef* misc;
	#if defined(_TIMER1_MODULE_)
		TIMER_COUNTER1 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega128TimerCounter1;

// Timer/Counter, 16-bit (TC3)
typedef struct {
	Atmega128TimerCounter3_TypeDef* reg;
	Atmega128OtherRegisters_TypeDef* misc;
	#if defined(_TIMER3_MODULE_)
		TIMER_COUNTER3 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega128TimerCounter3;

// Timer/Counter, 8-bit (TC2)
typedef struct {
	Atmega128TimerCounter2_TypeDef* reg;
	#if defined(_TIMER2_MODULE_)
		TIMER_COUNTER2 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega128TimerCounter2;

// Timer/Counter, 8-bit A sync (TC0)
typedef struct {
	Atmega128TimerCounter0_TypeDef* reg;
	Atmega128OtherRegisters_TypeDef* misc;
	#if defined(_TIMER0_MODULE_)
		TIMER_COUNTER0 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega128TimerCounter0;

// Two Wire Serial Interface (TWI)
typedef struct {
	Atmega128TwoWireSerialInterface_TypeDef* reg;
	#if defined(_TWI_MODULE_)
		TWI* (*run)(void);
		TWI (*enable)(uint8_t atmega_ID,  uint8_t prescaler);
	#endif
} Atmega128TwoWireSerialInterface;

// USART (USART0)
typedef struct {
	Atmega128Usart0_TypeDef* reg;
	#if defined(_USART0_MODULE_)
		USART0* (*run)(void);
		USART0 (*enable)(uint32_t baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
	#endif
} Atmega128Usart0;

// USART (USART1)
typedef struct {
	Atmega128Usart1_TypeDef* reg;
	#if defined(_USART1_MODULE_)
		USART1* (*run)(void);
		USART1 (*enable)(uint32_t baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
	#endif
} Atmega128Usart1;

// Watchdog Timer (WDT)
typedef struct {
	Atmega128WatchdogTimer_TypeDef* reg;
} Atmega128WatchdogTimer;
/*******************************************************************/
/************************* ATMEGA 128 IMAGE ************************/
/*************************** Third Layer ***************************/
/*******************************************************************/
typedef struct {
	//		Second Layer
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
	uint8_t (*readreg)(uint8_t reg, uint8_t size_block, uint8_t bit_n);
	uint8_t (*getsetbit)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n);
	void (*setreg)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
	void (*setbit)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
	void (*writereg)(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
	/******/
	void (*Clock_Prescaler_Select)(volatile uint8_t prescaler);
	void (*Move_Interrupts_To_Boot)(void);
}ATMEGA128;

/*** Global ***/
ATMEGA128* atmega128(void);
ATMEGA128 ATMEGA128enable(void);

/*** General ***/
uint16_t BAUDRATEnormal(uint32_t BAUD);
uint16_t BAUDRATEdouble(uint32_t BAUD);
uint16_t BAUDRATEsynchronous(uint32_t BAUD);

#endif

/***EOF***/

/*** Interrupt List ***/
// ISR(RESET_vect){}
// ISR(EXT_INT0_vect){}
// ISR(EXT_INT1_vect){}
// ISR(EXT_INT2_vect){}
// ISR(EXT_INT3_vect){}
// ISR(EXT_INT4_vect){}
// ISR(EXT_INT5_vect){}
// ISR(EXT_INT6_vect){}
// ISR(EXT_INT7_vect){}
// ISR(SPI_STC_vect){}
// ISR(USART0_RXC_vect){}
// ISR(USART0_DRE_vect){}
// ISR(USART0_TXC_vect){}
// ISR(ADC_vect){}
// ISR(EE_RDY_vect){}
// ISR(ANA_COMP_vect){}
// ISR(USART1_RXC_vect){}
// ISR(USART1_DRE_vect){}
// ISR(USART1_TXC_vect){}
// ISR(TWI_vect){}
// ISR(SPM_RDY_vect){}
// ISR(INT0_vect){ }
// ISR(INT1_vect){ }
// ISR(INT2_vect){ }
// ISR(INT3_vect){ }
// ISR(INT4_vect){ }
// ISR(INT5_vect){ }
// ISR(INT6_vect){ }
// ISR(INT7_vect){ }
// ISR(TIMER0_COMP_vect){};
// ISR(TIMER0_OVF_vect){};
// ISR(TIMER1_CAPT_vect){};
// ISR(TIMER1_COMPA_vect){};
// ISR(TIMER1_COMPB_vect){};
// ISR(TIMER1_COMPC_vect){};
// ISR(TIMER1_OVF_vect){};
// ISR(TIMER2_COMP_vect){};
// ISR(TIMER2_OVF_vect){};
// ISR(TIMER3_CAPT_vect){};
// ISR(TIMER3_COMPA_vect){};
// ISR(TIMER3_COMPB_vect){};
// ISR(TIMER3_COMPC_vect){};
// ISR(TIMER3_OVF_vect){};

