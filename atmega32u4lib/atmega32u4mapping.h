/********************************************************************
	ATMEGA 32U4 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega32U4 by ETT ET-BASE
Date: 03122023
Comment: 
	Virtual Image Atmega 32U4 mapping.
*********************************************************************/
#ifndef _ATMEGA32U4MAPPING_H_
	#define _ATMEGA32U4MAPPING_H_

/*** Global Library ***/
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <stdlib.h>
#include <inttypes.h>
// RAW IMAGE
#include "atmega32U4.h"

/*********************************************************/
/******************** User includes **********************/
/*********************************************************/
// MODULES
// Comment out modules not being used
//#include "atmega32U4analog.h"
#include "atmegaeeprom.h"
//#include "atmega32U4interrupt.h"
//#include "atmega32U4timer.h"
//#include "atmega32U4twi.h"
//#include "atmega32U4spi.h"
//#include "atmega32U4uart.h"
/*********************************************************/

/*** Global Variable ***/
//		PARAMETER
typedef struct {
	HighLowByte HLbyte;
} Atmega32U4Parameter;
//		SECOND LAYER
// GPWR
typedef struct {
	Atmega32U4GPWR_TypeDef* reg;
} Atmega32U4GPWR;

// I/O Port (PORTB)
typedef struct {
	Atmega32U4PORTB_TypeDef* reg;
} Atmega32U4PORTB;

// I/O Port (PORTC)
typedef struct {
	Atmega32U4PORTC_TypeDef* reg;
} Atmega32U4PORTC;

// I/O Port (PORTD)
typedef struct {
	Atmega32U4PORTD_TypeDef* reg;
} Atmega32U4PORTD;

// I/O Port (PORTE)
typedef struct {
	Atmega32U4PORTE_TypeDef* reg;
} Atmega32U4PORTE;

// I/O Port (PORTF)
typedef struct {
	Atmega32U4PORTF_TypeDef* reg;
} Atmega32U4PORTF;

// External Interrupts (EXINT)
typedef struct {
	Atmega32U4ExternalInterruptFlag_TypeDef* iflag;
	Atmega32U4ExternalInterruptMask_TypeDef* imask;
	Atmega32U4ExternalInterrupt_TypeDef* reg;
	#if defined(_ATMEGA32U4INTERRUPT_H_)
		INTERRUPT run;
		INTERRUPT (*enable)(void);
	#endif
} Atmega32U4ExternalInterrupt;

// CPU Register (CPU)
typedef struct {
	Atmega32U4CpuGeneralPurposeIoRegister0_TypeDef* gpior0;
	Atmega32U4CpuGeneralPurposeIoRegister1_TypeDef* gpior1;
	Atmega32U4CpuGeneralPurposeIoRegister2_TypeDef* gpior2;
	Atmega32U4CPURegister_TypeDef* reg;
	//Atmega32U4CPURegisterSleep_TypeDef* smcr;
	//Atmega32U4CPURegisterStatus_TypeDef* mcusr;
	//Atmega32U4CPURegisterControl_TypeDef* mcucr;
	//Atmega32U4CPURegisterState_TypeDef* state;
	//Atmega32U4CPURegisterPower_TypeDef* power;
	Atmega32U4CpuClockSelect_TypeDef* clk;
} Atmega32U4CPURegister;

// EEPROM (EEPROM)
typedef struct {
	Atmega32U4Eeprom_TypeDef* reg;
	#if defined(_ATMEGAEEPROM_H_)
		EEPROM run;
		EEPROM (*enable)(void);
	#endif
} Atmega32U4Eeprom;

// Timer/Counter, 8-bit (TC0)
typedef struct {
	Atmega32U4TimerInterruptFlag_TypeDef* iflag;
	Atmega3U4TimerGeneralControlRegister_TypeDef* gcr;
	Atmega32U4TimerCounter0_TypeDef* reg;
	Atmega32U4TimerCompareRegister0_TypeDef* comp;
	Atmega32U4TimerInterruptMask_TypeDef* imask;
	#if defined(_ATMEGA32U4TIMER_H_)
		TIMER_COUNTER0 run;
		TIMER_COUNTER0 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega32U4TimerCounter0;

// Phase Locked Loop (PLL)
typedef struct {
	Atmega32U4PhaseLockedLoopControlStatus_TypeDef* pllcsr;
	Atmega32U4PhaseLockedLoopFreq_TypeDef* pllfrq;
} Atmega32U4PhaseLockedLoop;

// Serial Peripheral Interface (SPI)
typedef struct {
	Atmega32U4SerialPeripherialInterface_TypeDef* reg;
	#if defined(_ATMEGA32U4SPI_H_)
		SPI run;
		SPI (*enable)(uint8_t master_slave_select, uint8_t data_order,  uint8_t data_modes, uint8_t prescaler);
	#endif
} Atmega32U4SerialPeripherialInterface;

// Analog Comparator (AC)
typedef struct {
	Atmega32U4AnalogComparator_TypeDef* acsr;
	Atmega32U4AnalogComparatorCs_TypeDef* adcsrb;
	Atmega32U4AnalogComparatorDid_TypeDef* didr1;
} Atmega32U4AnalogComparator;

// JTAG Interface (JTAG)
typedef struct {
	Atmega32U4JtagInterface_TypeDef* ocdr;
	Atmega32U4CPURegisterStatus_TypeDef* mcusr;
	Atmega32U4CPURegisterControl_TypeDef* mcucr;
} Atmega32U4JtagInterface;

// Boot loader (BOOT_LOAD)
typedef struct {
	Atmega32U4Bootloader_TypeDef* spmcsr;
} Atmega32U4Bootloader;

// Watchdog Timer (WDT)
typedef struct {
	Atmega32U4WatchdogTimer_TypeDef* wdtcsr;
} Atmega32U4WatchdogTimer;

// Analog to Digital Converter (ADC)
typedef struct {
	Atmega32U4AnalogToDigitalConverter_TypeDef* reg;
	#if defined(_ATMEGA32U4ANALOG_H_)
		ANALOG run;
		ANALOG (*enable)( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... );
	#endif
} Atmega32U4AnalogToDigitalConverter;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	Atmega32U4TimerInterruptFlag_TypeDef* iflag;
	Atmega3U4TimerGeneralControlRegister_TypeDef* gcr;
	Atmega32U4TimerInterruptMask_TypeDef* imask;
	Atmega32U4TimerCounter1_TypeDef* reg;
	Atmega32U4TimerCompareRegister1_TypeDef* comp;
	#if defined(_ATMEGA32U4TIMER_H_)
		TIMER_COUNTER1 run;
		TIMER_COUNTER1 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega32U4TimerCounter1;

// Timer/Counter, 16-bit (TC3)
typedef struct {
	Atmega32U4TimerInterruptFlag_TypeDef* iflag;
	Atmega3U4TimerGeneralControlRegister_TypeDef* gcr;
	Atmega32U4TimerInterruptMask_TypeDef* imask;
	Atmega32U4TimerCounter3_TypeDef* reg;
	Atmega32U4TimerCompareRegister3_TypeDef* comp;
	#if defined(_ATMEGA32U4TIMER_H_)
		TIMER_COUNTER3 run;
		TIMER_COUNTER3 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega32U4TimerCounter3;

// Two Wire Serial Interface (TWI)
typedef struct {
	Atmega32U4TwoWireSerialInterface_TypeDef* reg;
	#if defined(_ATMEGA32U4TWI_H_)
		TWI run;
		TWI (*enable)(uint8_t atmega_ID, uint8_t prescaler);
	#endif
} Atmega32U4TwoWireSerialInterface;

// Timer/Counter, 10-bit (TC4)
typedef struct {
	Atmega32U4TimerInterruptFlag_TypeDef* iflag;
	Atmega3U4TimerGeneralControlRegister_TypeDef* gcr;
	Atmega32U4TimerInterruptMask_TypeDef* imask;
	Atmega32U4TimerCounter4_TypeDef* reg;
	Atmega32U4TimerCompareRegister4_TypeDef* comp;
	#if defined(_ATMEGA32U4TIMER_H_)
		TIMER_COUNTER4 run;
		TIMER_COUNTER4 (*enable)(unsigned char wavegenmode, unsigned char interrupt);
	#endif
} Atmega32U4TimerCounter4;

// USART (USART1)
typedef struct {
	Atmega32U4Usart1_TypeDef* reg;
	#if defined(_ATMEGA32U4UART_H_)
		UART run;
		UART (*enable)(unsigned int baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
	#endif
} Atmega32U4Usart1;

// USB Device Register (USB_DEVICE)
typedef struct {
	Atmega32U4UsbDeviceRegister_TypeDef* reg;
} Atmega32U4UsbDeviceRegister;

/*******************************************************************/
/*******************************************************************/
// ATMEGA 32U4 IMAGE
typedef struct {
	//		Parameter
	Atmega32U4Parameter par;
	//		Second Layer
	Atmega32U4GPWR gpwr;
	Atmega32U4PORTB portb;
	Atmega32U4PORTC portc;
	Atmega32U4PORTD portd;
	Atmega32U4PORTE porte;
	Atmega32U4PORTF portf;
	Atmega32U4ExternalInterrupt exint;
	Atmega32U4CPURegister cpu;
	Atmega32U4Eeprom eeprom;
	Atmega32U4TimerCounter0 tc0;
	Atmega32U4PhaseLockedLoop pll;
	Atmega32U4SerialPeripherialInterface spi;
	Atmega32U4AnalogComparator ac;
	Atmega32U4JtagInterface jtag;
	Atmega32U4Bootloader boot_load;
	Atmega32U4WatchdogTimer wdt;
	Atmega32U4AnalogToDigitalConverter adc;
	Atmega32U4TimerCounter1 tc1;
	Atmega32U4TimerCounter3 tc3;
	Atmega32U4TwoWireSerialInterface twi;
	Atmega32U4TimerCounter4 tc4;
	Atmega32U4Usart1 usart1;
	Atmega32U4UsbDeviceRegister usb_device;
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
	/******/
	void (*Clock_Prescaler_Select)(volatile uint8_t prescaler);
	void (*Move_Interrupts_To_Boot)(void);
	void (*Move_Interrupts_To_Sram)(void);
}ATMEGA32U4;

/*** Global Header ***/
ATMEGA32U4 ATMEGA32U4enable(void);

/***Global Variable***/
ATMEGA32U4 atmega32u4;

#endif

/***EOF***/

