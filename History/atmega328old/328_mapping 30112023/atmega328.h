/************************************************************************
	ATMEGA 328 REGISTERS
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Date: 30112023
Comment:
	Virtual Image Atmega 328.
	In Search of Perfection
************************************************************************/
#ifndef _ATMEGA328_H_
	#define _ATMEGA328_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#define Atmega328GPWR_Address 0x0000
#define Atmega328PORTB_Address 0x0023
#define Atmega328PORTC_Address 0x0026
#define Atmega328PORTD_Address 0x0029
#define Atmega328Eeprom_Address 0x003F
#define Atmega328TimerCounter0_Address 0x0044
#define Atmega328SerialPeripherialInterface_Address 0x004C
#define Atmega328AnalogComparator_Address 0x0050
#define Atmega328CPURegister_Address 0x0053
#define Atmega328WatchdogTimer_Address 0x0060
#define Atmega328ExternalInterrupt_Address 0x0068
#define Atmega328AnalogToDigitalConverter_Address 0x0078
#define Atmega328TimerCounter1_Address 0x0080
#define Atmega328TimerCounter2_Address 0x00B0
#define Atmega328TwoWireSerialInterface_Address 0x00B8
#define Atmega328Usart_Address 0x00C0
// AUXILIAR
#define Atmega328TimerInterruptFlag_Address 0x0035
#define Atmega328ExternalInterruptFlag_Address 0x003B
#define Atmega328ExternalInterruptMask_Address 0x003D
#define Atmega328CpuGeneralPurposeIoRegister_Address 0x003E
#define Atmega328CpuGeneralPurposeIoRegister0_Address 0x003E
#define Atmega328TimerGeneralControlRegister_Address 0x0043
#define Atmega328TimerCompareRegister0_Address 0x0047
#define Atmega328CpuGeneralPurposeIoRegister1_Address 0x004A
#define Atmega328CpuGeneralPurposeIoRegister2_Address 0x004B
#define Atmega328TimerInterruptMask_Address 0x006E;
#define Atmega328AnalogComparatorDid_Address 0x007F
#define Atmega328TimerCompareRegister1_Address 0x0086
#define Atmega328TimerCompareRegister2_Address 0x00B3

/*** Global Variable ***/
// HLbyte
typedef struct {
	uint8_t L; // Lower address
	uint8_t H; // Higher address
} HighLowByte;

//		MAIN HARDWARE LAYER
// GPWR
typedef struct {
	uint8_t r0; // 0x00
	uint8_t r1; // 0x01
	uint8_t r2; // 0x02
	uint8_t r3; // 0x03
	uint8_t r4; // 0x04
	uint8_t r5; // 0x05
	uint8_t r6; // 0x06
	uint8_t r7; // 0x07
	uint8_t r8; // 0x08
	uint8_t r9; // 0x09
	uint8_t r10; // 0x0A
	uint8_t r11; // 0x0B
	uint8_t r12; // 0x0C
	uint8_t r13; // 0x0D
	uint8_t r14; // 0x0E
	uint8_t r15; // 0x0F
	uint8_t r16; // 0x10
	uint8_t r17; // 0x11
	uint8_t r18; // 0x12
	uint8_t r19; // 0x13
	uint8_t r20; // 0x14
	uint8_t r21; // 0x15
	uint8_t r22; // 0x16
	uint8_t r23; // 0x17
	uint8_t r24; // 0x18
	uint8_t r25; // 0x19
	HighLowByte X; // 0x1A 0x1B
	HighLowByte Y; // 0x1C 0x1D
	HighLowByte Z; // 0x1E 0x1F
} Atmega328GPWR_TypeDef;

// I/O Port (PORTB)
typedef struct {
	uint8_t pin; // 0x23
	uint8_t ddr; // 0x24
	uint8_t port; //0x25
} Atmega328PORTB_TypeDef;

// I/O Port (PORTC)
typedef struct {
	uint8_t pin; // 0x26
	uint8_t ddr; // 0x27
	uint8_t port; // 0x28
} Atmega328PORTC_TypeDef;

// I/O Port (PORTD)
typedef struct {
	uint8_t pin; // 0x29
	uint8_t ddr; // 0x2A
	uint8_t port; // 0x2B
} Atmega328PORTD_TypeDef;

// TIMER
typedef struct {
	uint8_t tifr0; // 0x35
	uint8_t tifr1; // 0x36
	uint8_t tifr2; // 0x37
} Atmega328TimerInterruptFlag_TypeDef;

// External Interrupts (EXINT)
typedef struct {
	uint8_t pcifr; // 0x3B
	uint8_t eifr; // 0x3C
} Atmega328ExternalInterruptFlag_TypeDef;

// External Interrupts (EXINT)
typedef struct {
	uint8_t eimsk; // 0x3D [eimsk]
} Atmega328ExternalInterruptMask_TypeDef;

// CPU Register (CPU)
typedef struct {
	uint8_t r0; // 0x3E
	uint8_t fill[11]; // (0x4A - 0x3E) - 1
	uint8_t r1; // 0x4A
	uint8_t r2; // 0x4B
} Atmega328CpuGeneralPurposeIoRegister_TypeDef;

// CPU Register (CPU)
typedef struct {
	uint8_t par; // 0x3E [gpior0]
} Atmega32U4CpuGeneralPurposeIoRegister0_TypeDef;

// EEPROM (EEPROM)
typedef struct {
	uint8_t eecr; // 0x3F
	uint8_t eedr; // 0x40
	uint16_t eear; // 0x41
} Atmega328Eeprom_TypeDef;

// TIMER
typedef struct {
	uint8_t gtccr; // 0x43 [gtccr]
} Atmega328TimerGeneralControlRegister_TypeDef;

// Timer/Counter, 8-bit A sync (TC0)
typedef struct {
	uint8_t tccr0a; // 0x44
	uint8_t tccr0b; // 0x45
	uint8_t tcnt0; // 0x46
} Atmega328TimerCounter0_TypeDef;

// Timer/Counter, 8-bit A sync (TC0)
typedef struct {
	uint8_t ocr0a; // 0x47
	uint8_t ocr0b; // 0x48
} Atmega328TimerCompareRegister0_TypeDef;

// CPU Register (CPU)
typedef struct {
	uint8_t par; // 0x4A [gpior1]
} Atmega32U4CpuGeneralPurposeIoRegister1_TypeDef;

// CPU Register (CPU)
typedef struct {
	uint8_t par; // 0x4B [gpior2]
} Atmega32U4CpuGeneralPurposeIoRegister2_TypeDef;

// Serial Peripheral Interface (SPI)
typedef struct {
	uint8_t spcr; // 0x4C
	uint8_t spsr; // 0x4D
	uint8_t spdr; // 0x4E
} Atmega328SerialPeripherialInterface_TypeDef;

// Analog Comparator (AC)
typedef struct {
	uint8_t acsr; // 0x50 [acsr]
} Atmega328AnalogComparator_TypeDef;

// CPU Register (CPU)
typedef struct {
	uint8_t smcr; // 0x53
	uint8_t mcusr; // 0x54
	uint8_t mcucr; // 0x55
	uint8_t fill1; // (0x57 - 0x55) - 1
	uint8_t spmcsr; // 0x57
	uint8_t fill2[5]; // (0x5D - 0x57) - 1
	HighLowByte sp; // 0x5D 0x5E
	uint8_t sreg; // 0x5F
	uint8_t fill3; // (0x61 - 0x5F) - 1
	uint8_t clkpr; // 0x61
	uint8_t fill4[2]; // (0x64 - 0x61) - 1
	uint8_t prr; // 0x64
	uint8_t fill5; // (0x66 - 0x64) - 1
	uint8_t osccal; // 0x66
} Atmega328CPURegister_TypeDef;

// Watchdog Timer (WDT)
typedef struct {
	uint8_t wdtcsr; // 0x60 [wdtcsr]
} Atmega328WatchdogTimer_TypeDef;

// External Interrupts (EXINT)
typedef struct {
	uint8_t pcicr; // 0x68
	uint8_t eicra; // 0x69
	uint8_t fill; // (0x6B - 0x69) - 1
	uint8_t pcmsk0; // 0x6B
	uint8_t pcmsk1; // 0x6C
	uint8_t pcmsk2; // 0x6D
} Atmega328ExternalInterrupt_TypeDef;

// TIMER
typedef struct {
	uint8_t timsk0; // 0x6E
	uint8_t timsk1; // 0x6F
	uint8_t timsk2; // 0x70
} Atmega328TimerInterruptMask_TypeDef;

// Analog to Digital Converter (ADC)
typedef struct {
	HighLowByte adc; // 0x78 0x79
	uint8_t adcsra; // 0x7A
	uint8_t adcsrb; // 0x7B
	uint8_t admux; // 0x7C
	uint8_t fill; // (0x7E - 0x7C) - 1
	uint8_t didr0; // 0x7E
} Atmega328AnalogToDigitalConverter_TypeDef;

// Analog Comparator (AC)
typedef struct {
	uint8_t par; // 0x7F [didr1]
} Atmega328AnalogComparatorDid_TypeDef;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	uint8_t tccr1a; // 0x80
	uint8_t tccr1b; // 0x81
	uint8_t tccr1c; // 0x82
	uint8_t fill; // (0x84 - 0x82) - 1
	HighLowByte tcnt1; // 0x84 0x85
} Atmega328TimerCounter1_TypeDef;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	HighLowByte icr1; // 0x86 0x87
	HighLowByte ocr1a; // 0x88 0x89
	HighLowByte ocr1b; // 0x8A 0x8B
} Atmega328TimerCompareRegister1_TypeDef;

// Timer/Counter, 8-bit (TC2)
typedef struct {
	uint8_t tccr2a; // 0xB0
	uint8_t tccr2b; // 0xB1
	uint8_t tcnt2; // 0xB2
} Atmega328TimerCounter2_TypeDef;

// Timer/Counter, 8-bit (TC2)
typedef struct {
	uint8_t ocr2a; // 0xB3
	uint8_t ocr2b; // 0xB4
	uint8_t fill; // (0xB6 - 0xB4) - 1
	uint8_t assr; // 0xB6
} Atmega328TimerCompareRegister2_TypeDef;

// Two Wire Serial Interface (TWI)
typedef struct {
	uint8_t twbr; // 0xB8
	uint8_t twsr; // 0xB9
	uint8_t twar; // 0xBA
	uint8_t twdr; // 0xBB
	uint8_t twcr; // 0xBC
	uint8_t twamr; // 0xBD
} Atmega328TwoWireSerialInterface_TypeDef;

// USART (USART0)
typedef struct {
	uint8_t ucsr0a; // 0xC0
	uint8_t ucsr0b; // 0xC1
	uint8_t ucsr0c; // 0xC2
	uint8_t fill; // (0xC4 - 0xC2) - 1
	HighLowByte ubrr0; // 0xC4 0xC5
	uint8_t udr0; // 0xC6
} Atmega328Usart_TypeDef;

/*** STATIC RAM ***/
// Interrupt Vectors (ISR)
typedef struct { // SRAM START = 0x0100 END = 0x0877 atmega328
	HighLowByte RESET_vect; // 0x0000
	HighLowByte INT0_vect; // 0x0002
	HighLowByte INT1_vect; // 0x0004
	HighLowByte PCINT0_vect; // 0x0006
	HighLowByte PCINT1_vect; // 0x0008
	HighLowByte PCINT2_vect; // 0x000A
	HighLowByte WDT_vect; // 0x000C
	HighLowByte TIMER2_COMPA_vect; // 0x000E
	HighLowByte TIMER2_COMPB_vect; // 0x0010
	HighLowByte TIMER2_OVF_vect; // 0x0012
	HighLowByte TIMER1_CAPT_vect; // 0x0014
	HighLowByte TIMER1_COMPA_vect; // 0x0016
	HighLowByte TIMER1_COMPB_vect; // 0x0018
	HighLowByte TIMER1_OVF_vect; // 0x0001A
	HighLowByte TIMER0_COMPA_vect; // 0x001C
	HighLowByte TIMER0_COMPB_vect; // 0x001E
	HighLowByte TIMER0_OVF_vect; // 0x0020
	HighLowByte SPI_STC_vect; // 0x0022
	HighLowByte USART_RX_vect; // 0x0024
	HighLowByte USART_UDRE_vect; // 0x0026
	HighLowByte USART_TX_vect; // 0x0028
	HighLowByte ADC_vect; // 0x002A
	HighLowByte EE_READY_vect; // 0x002C
	HighLowByte ANALOG_COMP_vect; // 0x002E
	HighLowByte TWI_vect; // 0x0030
	HighLowByte SPM_READY_vect; // 0x0032
} Atmega328InterruptVectors_TypeDef;

#endif

/***EOF***/

/***
Notes:
The Reset button is an interrupt [address 0 rjump] that jumps to the main() location.

MASK FLAG CONTROL STATUS
***/
