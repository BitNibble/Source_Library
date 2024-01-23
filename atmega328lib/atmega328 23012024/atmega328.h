/************************************************************************
	ATMEGA 328 REGISTERS
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update: 01/01/2024
Comment:
	Virtual Image Atmega 328.
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
#define Atmega328ExternalInterruptPinChangeMask_Address 0x006B;
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

/***************************/
/*** MAIN HARDWARE LAYER ***/
/***************************/
// GPWR
typedef struct {
	volatile uint8_t r0; // 0x00
	volatile uint8_t r1; // 0x01
	volatile uint8_t r2; // 0x02
	volatile uint8_t r3; // 0x03
	volatile uint8_t r4; // 0x04
	volatile uint8_t r5; // 0x05
	volatile uint8_t r6; // 0x06
	volatile uint8_t r7; // 0x07
	volatile uint8_t r8; // 0x08
	volatile uint8_t r9; // 0x09
	volatile uint8_t r10; // 0x0A
	volatile uint8_t r11; // 0x0B
	volatile uint8_t r12; // 0x0C
	volatile uint8_t r13; // 0x0D
	volatile uint8_t r14; // 0x0E
	volatile uint8_t r15; // 0x0F
	volatile uint8_t r16; // 0x10
	volatile uint8_t r17; // 0x11
	volatile uint8_t r18; // 0x12
	volatile uint8_t r19; // 0x13
	volatile uint8_t r20; // 0x14
	volatile uint8_t r21; // 0x15
	volatile uint8_t r22; // 0x16
	volatile uint8_t r23; // 0x17
	volatile uint8_t r24; // 0x18
	volatile uint8_t r25; // 0x19
	volatile HighLowByte X; // 0x1A 0x1B
	volatile HighLowByte Y; // 0x1C 0x1D
	volatile HighLowByte Z; // 0x1E 0x1F
} Atmega328GPWR_TypeDef;

// I/O Port (PORTB)
typedef struct {
	volatile uint8_t pin; // 0x23
	volatile uint8_t ddr; // 0x24
	volatile uint8_t port; //0x25
} Atmega328PORTB_TypeDef;

// I/O Port (PORTC)
typedef struct {
	volatile uint8_t pin; // 0x26
	volatile uint8_t ddr; // 0x27
	volatile uint8_t port; // 0x28
} Atmega328PORTC_TypeDef;

// I/O Port (PORTD)
typedef struct {
	volatile uint8_t pin; // 0x29
	volatile uint8_t ddr; // 0x2A
	volatile uint8_t port; // 0x2B
} Atmega328PORTD_TypeDef;

// TIMER
typedef struct {
	volatile uint8_t tifr0; // 0x35
	volatile uint8_t tifr1; // 0x36
	volatile uint8_t tifr2; // 0x37
} Atmega328TimerInterruptFlag_TypeDef;

// External Interrupts (EXINT)
typedef struct {
	volatile uint8_t pcifr; // 0x3B
	volatile uint8_t eifr; // 0x3C
} Atmega328ExternalInterruptFlag_TypeDef;

// External Interrupts (EXINT)
typedef struct {
	volatile uint8_t eimsk; // 0x3D [eimsk]
} Atmega328ExternalInterruptMask_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t par; // 0x3E [gpior0]
} Atmega328CpuGeneralPurposeIoRegister0_TypeDef;

// EEPROM (EEPROM)
typedef struct {
	volatile uint8_t eecr; // 0x3F
	volatile uint8_t eedr; // 0x40
	volatile uint16_t eear; // 0x41
} Atmega328Eeprom_TypeDef;

// TIMER
typedef struct {
	volatile uint8_t gtccr; // 0x43 [gtccr]
} Atmega328TimerGeneralControlRegister_TypeDef;

// Timer/Counter, 8-bit A sync (TC0)
typedef struct {
	volatile uint8_t tccr0a; // 0x44
	volatile uint8_t tccr0b; // 0x45
	volatile uint8_t tcnt0; // 0x46
} Atmega328TimerCounter0_TypeDef;

// Timer/Counter, 8-bit A sync (TC0)
typedef struct {
	volatile uint8_t ocr0a; // 0x47
	volatile uint8_t ocr0b; // 0x48
} Atmega328TimerCompareRegister0_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t par; // 0x4A [gpior1]
} Atmega328CpuGeneralPurposeIoRegister1_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t r0; // 0x3E
	uint8_t fill[11]; // (0x4A - 0x3E) - 1
	volatile uint8_t r1; // 0x4A
	volatile uint8_t r2; // 0x4B
} Atmega328CpuGeneralPurposeIoRegister_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t par; // 0x4B [gpior2]
} Atmega328CpuGeneralPurposeIoRegister2_TypeDef;

// Serial Peripheral Interface (SPI)
typedef struct {
	volatile uint8_t spcr; // 0x4C
	volatile uint8_t spsr; // 0x4D
	volatile uint8_t spdr; // 0x4E
} Atmega328SerialPeripherialInterface_TypeDef;

// Analog Comparator (AC)
typedef struct {
	volatile uint8_t acsr; // 0x50 [acsr]
} Atmega328AnalogComparator_TypeDef;

// Watchdog Timer (WDT)
typedef struct {
	volatile uint8_t wdtcsr; // 0x60 [wdtcsr]
} Atmega328WatchdogTimer_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t smcr; // 0x53
	volatile uint8_t mcusr; // 0x54
	volatile uint8_t mcucr; // 0x55
	uint8_t fill1; // (0x57 - 0x55) - 1
	volatile uint8_t spmcsr; // 0x57
	uint8_t fill2[5]; // (0x5D - 0x57) - 1
	volatile HighLowByte sp; // 0x5D 0x5E
	volatile uint8_t sreg; // 0x5F
	uint8_t fill3; // (0x61 - 0x5F) - 1
	volatile uint8_t clkpr; // 0x61
	uint8_t fill4[2]; // (0x64 - 0x61) - 1
	volatile uint8_t prr; // 0x64
	uint8_t fill5; // (0x66 - 0x64) - 1
	volatile uint8_t osccal; // 0x66
} Atmega328CPURegister_TypeDef;

// External Interrupts (EXINT)
typedef struct {
	volatile uint8_t pcmsk0; // 0x6B
	volatile uint8_t pcmsk1; // 0x6C
	volatile uint8_t pcmsk2; // 0x6D
} Atmega328ExternalInterruptPinChangeMask_TypeDef;

// External Interrupts (EXINT)
typedef struct {
	volatile uint8_t pcicr; // 0x68
	volatile uint8_t eicra; // 0x69
	uint8_t fill; // (0x6B - 0x69) - 1
	volatile uint8_t pcmsk0; // 0x6B
	volatile uint8_t pcmsk1; // 0x6C
	volatile uint8_t pcmsk2; // 0x6D
} Atmega328ExternalInterrupt_TypeDef;

// TIMER
typedef struct {
	volatile uint8_t timsk0; // 0x6E
	volatile uint8_t timsk1; // 0x6F
	volatile uint8_t timsk2; // 0x70
} Atmega328TimerInterruptMask_TypeDef;

// Analog to Digital Converter (ADC)
typedef struct {
	volatile HighLowByte adc; // 0x78 0x79
	volatile uint8_t adcsra; // 0x7A
	volatile uint8_t adcsrb; // 0x7B
	volatile uint8_t admux; // 0x7C
	uint8_t fill; // (0x7E - 0x7C) - 1
	volatile uint8_t didr0; // 0x7E
} Atmega328AnalogToDigitalConverter_TypeDef;

// Analog Comparator (AC)
typedef struct {
	volatile uint8_t par; // 0x7F [didr1]
} Atmega328AnalogComparatorDid_TypeDef;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	volatile uint8_t tccr1a; // 0x80
	volatile uint8_t tccr1b; // 0x81
	volatile uint8_t tccr1c; // 0x82
	uint8_t fill; // (0x84 - 0x82) - 1
	volatile HighLowByte tcnt1; // 0x84 0x85
} Atmega328TimerCounter1_TypeDef;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	volatile HighLowByte icr1; // 0x86 0x87
	volatile HighLowByte ocr1a; // 0x88 0x89
	volatile HighLowByte ocr1b; // 0x8A 0x8B
} Atmega328TimerCompareRegister1_TypeDef;

// Timer/Counter, 8-bit (TC2)
typedef struct {
	volatile uint8_t tccr2a; // 0xB0
	volatile uint8_t tccr2b; // 0xB1
	volatile uint8_t tcnt2; // 0xB2
} Atmega328TimerCounter2_TypeDef;

// Timer/Counter, 8-bit (TC2)
typedef struct {
	volatile uint8_t ocr2a; // 0xB3
	volatile uint8_t ocr2b; // 0xB4
	uint8_t fill; // (0xB6 - 0xB4) - 1
	volatile uint8_t assr; // 0xB6
} Atmega328TimerCompareRegister2_TypeDef;

// Two Wire Serial Interface (TWI)
typedef struct {
	volatile uint8_t twbr; // 0xB8
	volatile uint8_t twsr; // 0xB9
	volatile uint8_t twar; // 0xBA
	volatile uint8_t twdr; // 0xBB
	volatile uint8_t twcr; // 0xBC
	volatile uint8_t twamr; // 0xBD
} Atmega328TwoWireSerialInterface_TypeDef;

// USART (USART0)
typedef struct {
	volatile uint8_t ucsr0a; // 0xC0
	volatile uint8_t ucsr0b; // 0xC1
	volatile uint8_t ucsr0c; // 0xC2
	uint8_t fill; // (0xC4 - 0xC2) - 1
	volatile HighLowByte ubrr0; // 0xC4 0xC5
	volatile uint8_t udr0; // 0xC6
} Atmega328Usart_TypeDef;

/*** FLASH ***/
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

