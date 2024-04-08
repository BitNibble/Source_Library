/*********************************************************
	ATMEGA 328 Handler
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega 328
Update:	07/04/2024
Comment: 
	Simple tools
**********************************************************/
#ifndef _ATMEGA328HANDLER_H_
	#define _ATMEGA328HANDLER_H_
	
/*** Working Frequency ***/
// User may change to conform to use
#ifndef F_CPU
	#define F_CPU 16000000UL
#endif
	
#include <avr/io.h>
#include <avr/fuse.h>
#include <avr/eeprom.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "atmega328.h"

/****************************/
/***** HARDWARE HANDLER *****/
/****************************/
// GPWR
Atmega328GPWR_TypeDef* gpwr_handle(void);
// I/O Port (PORTB)
Atmega328PORTB_TypeDef* portb_handle(void);
// I/O Port (PORTC)
Atmega328PORTC_TypeDef* portc_handle(void);
// I/O Port (PORTD)
Atmega328PORTD_TypeDef* portd_handle(void);
// Timer/Counter 0, 1 and 2 Interrupt Flag
Atmega328TimerInterruptFlag_TypeDef* tc_iflag_handle(void);
// External Interrupts Flag (EXINT)
Atmega328ExternalInterruptFlag_TypeDef* exint_flag_handle(void);
// External Interrupts Mask (EXINT)
Atmega328ExternalInterruptMask_TypeDef* exint_mask_handle(void);
// CPU Register Gpio0 (CPU)
Atmega328CpuGeneralPurposeIoRegister0_TypeDef* cpu_gpio0_handle(void);
// EEPROM (EEPROM)
Atmega328Eeprom_TypeDef* eeprom_handle(void);
// TIMER General Control
Atmega328TimerGeneralControlRegister_TypeDef* tc_gcontrol_handle(void);
// Timer/Counter, 8-bit A sync (TC0)
Atmega328TimerCounter0_TypeDef* tc0_handle(void);
// Timer/Counter, 8-bit A sync Compare (TC0)
Atmega328TimerCompareRegister0_TypeDef* tc0_compare_handle(void);
// CPU Register Gpio1 (CPU)
Atmega328CpuGeneralPurposeIoRegister1_TypeDef* cpu_gpio1_handle(void);
// CPU Register Gpio012 (CPU)
Atmega328CpuGeneralPurposeIoRegister_TypeDef* cpu_gpio012_handle(void);
// CPU Register Gpio2 (CPU)
Atmega328CpuGeneralPurposeIoRegister2_TypeDef* cpu_gpio2_handle(void);
// Serial Peripheral Interface (SPI)
Atmega328SerialPeripherialInterface_TypeDef* spi_handle(void);
// Analog Comparator (AC)
Atmega328AnalogComparator_TypeDef* ac_handle(void);
// Watchdog Timer (WDT)
Atmega328WatchdogTimer_TypeDef* wdt_handle(void);
// CPU Register (CPU)
Atmega328CPURegister_TypeDef* cpu_handle(void);
// External Interrupts Pin Change Mask (EXINT)
Atmega328ExternalInterruptPinChangeMask_TypeDef* exint_pcmask_handle(void);
// External Interrupts (EXINT)
Atmega328ExternalInterrupt_TypeDef* exint_handle(void);
// Timer/Counter 0, 1 and 2 Interrupt Mask
Atmega328TimerInterruptMask_TypeDef* tc_imask_handle(void);
// Analog to Digital Converter (ADC)
Atmega328AnalogToDigitalConverter_TypeDef* adc_handle(void);
// Analog Comparator Did (AC)
Atmega328AnalogComparatorDid_TypeDef* ac_did_handle(void);
// Timer/Counter, 16-bit (TC1)
Atmega328TimerCounter1_TypeDef* tc1_handle(void);
// Timer/Counter, 16-bit Compare (TC1)
Atmega328TimerCompareRegister1_TypeDef* tc1_compare_handle(void);
// Timer/Counter, 8-bit (TC2)
Atmega328TimerCounter2_TypeDef* tc2_handle(void);
// Timer/Counter, 8-bit Compare (TC2)
Atmega328TimerCompareRegister2_TypeDef* tc2_compare_handle(void);
// Two Wire Serial Interface (TWI)
Atmega328TwoWireSerialInterface_TypeDef* twi_handle(void);
// USART (USART0)
Atmega328Usart0_TypeDef* usart0_handle(void);

/*** Atmega 328 Procedure and Function ***/
uint16_t readhlbyte(HighLowByte reg);
uint16_t readlhbyte(HighLowByte reg);
HighLowByte writehlbyte(uint16_t val);
HighLowByte writelhbyte(uint16_t val);
uint16_t swapbyte(uint16_t num);
uint16_t BAUDRATEnormal(uint32_t BAUD);
uint16_t BAUDRATEdouble(uint32_t BAUD);
uint16_t BAUDRATEsynchronous(uint32_t BAUD);
void Atmega328ClockPrescalerSelect(volatile uint8_t prescaler);
void Atmega328MoveInterruptsToBoot(void);

#endif

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

/*** EOF ***/

