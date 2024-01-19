/*********************************************************
	ATMEGA 128 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega128 by ETT ET-BASE
Update: 07/01/2024
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
#ifndef DATA_SIZE
	#define DATA_SIZE 8
#endif
#ifndef DATA_BITS
	#define DATA_BITS 7
#endif
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
//	#warning "NO TIMER0 MODULE"
#endif
#ifdef _TIMER1_MODULE_
#include "atmega128timer1.h"
//#else
//	#warning "NO TIMER1 MODULE"
#endif
#ifdef _TIMER2_MODULE_
#include "atmega128timer2.h"
//#else
//	#warning "NO TIMER2 MODULE"
#endif
#ifdef _TIMER3_MODULE_
#include "atmega128timer3.h"
//#else
//	#warning "NO TIMER3 MODULE"
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
//	#warning "NO UART0 MODULE"
#endif
#ifdef _USART1_MODULE_
#include "atmega128usart1.h"
//#else
//	#warning "NO UART1 MODULE"
#endif
/*******************************************************************/
/************************* ATMEGA 128 IMAGE ************************/
/*************************** Third Layer ***************************/
/*******************************************************************/
typedef struct {
	Atmega128GPWR_TypeDef* gpwr_reg;
	Atmega128AnalogComparator_TypeDef* ac_reg;
	Atmega128OtherRegisters_TypeDef* ac_misc;
	#ifdef _ANALOG_MODULE_
		Atmega128AnalogToDigitalConverter_TypeDef* adc_reg;
		ANALOG (*adc_enable)( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... );
		ANALOG* adc;
	#else
		Atmega128AnalogToDigitalConverter_TypeDef* adc_reg;
	#endif
	Atmega128BootLoader_TypeDef* boot_load_reg;
	Atmega128CPURegister_TypeDef* cpu_reg;
	#ifdef _EEPROM_MODULE_
		Atmega128Eeprom_TypeDef* eeprom_reg;
		EEPROM (*eeprom_enable)( void );
		EEPROM* eeprom;
	#else
		Atmega128Eeprom_TypeDef* eeprom_reg;
	#endif
	#ifdef _INTERRUPT_MODULE_
		Atmega128ExternalInterrupts_TypeDef* exint_reg;
		INTERRUPT (*exint_enable)(void);
		INTERRUPT* exint;
	#else
		Atmega128ExternalInterrupts_TypeDef* exint_reg;
	#endif
	Atmega128PORTA_TypeDef* porta_reg;
	Atmega128PORTB_TypeDef* portb_reg;
	Atmega128PORTC_TypeDef* portc_reg;
	Atmega128PORTD_TypeDef* portd_reg;
	Atmega128PORTE_TypeDef* porte_reg;
	Atmega128PORTF_TypeDef* portf_reg;
	Atmega128PORTG_TypeDef* portg_reg;
	Atmega128JtagInterface_TypeDef* jtag_reg;
	Atmega128OtherRegisters_TypeDef* misc_reg;
	#ifdef _SPI_MODULE_
		Atmega128SerialPeripherialInterface_TypeDef* spi_reg;
		SPI (*spi_enable)(uint8_t master_slave_select, uint8_t data_order,  uint8_t data_modes, uint8_t prescaler);
		SPI* spi;
	#else
		Atmega128SerialPeripherialInterface_TypeDef* spi_reg;
	#endif
	#ifdef _TIMER1_MODULE_
		Atmega128TimerCounter1_TypeDef* tc1_reg;
		Atmega128OtherRegisters_TypeDef* tc1_misc;
		TIMER_COUNTER1 (*tc1_enable)(unsigned char wavegenmode, unsigned char interrupt);
		TIMER_COUNTER1* tc1;
	#else
		Atmega128TimerCounter1_TypeDef* tc1_reg;
		Atmega128OtherRegisters_TypeDef* tc1_misc;
	#endif
	#ifdef _TIMER3_MODULE_
		Atmega128TimerCounter3_TypeDef* tc3_reg;
		Atmega128OtherRegisters_TypeDef* tc3_misc;
		TIMER_COUNTER3 (*tc3_enable)(unsigned char wavegenmode, unsigned char interrupt);
		TIMER_COUNTER3* tc3;
	#else
		Atmega128TimerCounter3_TypeDef* tc3_reg;
		Atmega128OtherRegisters_TypeDef* tc3_misc;
	#endif
	#ifdef _TIMER2_MODULE_
		Atmega128TimerCounter2_TypeDef* tc2_reg;
		TIMER_COUNTER2 (*tc2_enable)(unsigned char wavegenmode, unsigned char interrupt);
		TIMER_COUNTER2* tc2;
	#else
		Atmega128TimerCounter2_TypeDef* tc2_reg;
	#endif
	#ifdef _TIMER0_MODULE_
		Atmega128TimerCounter0_TypeDef* tc0_reg;
		Atmega128OtherRegisters_TypeDef* tc0_misc;
		TIMER_COUNTER0 (*tc0_enable)(unsigned char wavegenmode, unsigned char interrupt);
		TIMER_COUNTER0* tc0;
	#else
		Atmega128TimerCounter0_TypeDef* tc0_reg;
		Atmega128OtherRegisters_TypeDef* tc0_misc;
	#endif
	#ifdef _TWI_MODULE_
		Atmega128TwoWireSerialInterface_TypeDef* twi_reg;
		TWI (*twi_enable)(uint8_t atmega_ID,  uint8_t prescaler);
		TWI* twi;
	#else
		Atmega128TwoWireSerialInterface_TypeDef* twi_reg;
	#endif
	#ifdef _USART0_MODULE_
		Atmega128Usart0_TypeDef* usart0_reg;
		USART0 (*usart0_enable)(uint32_t baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
		USART0* usart0;
	#else
		Atmega128Usart0_TypeDef* usart0_reg;
	#endif
	#ifdef _USART1_MODULE_
		Atmega128Usart1_TypeDef* usart1_reg;
		USART1 (*usart1_enable)( uint32_t baud, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
		USART1* usart1;
	#else
		Atmega128Usart1_TypeDef* usart1_reg;
	#endif
	Atmega128WatchdogTimer_TypeDef* wdt_reg;
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
uint8_t readreg(uint8_t reg, uint8_t size_block, uint8_t bit_n);
uint8_t getsetbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n);
void setreg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
void setbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
void writereg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
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
