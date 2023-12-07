/************************************************************************
	ATMEGA 32U4 REGISTERS
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega32U4 by ETT ET-BASE
Date: 03122023
Comment: 
	Virtual Image Atmega 32U4.
************************************************************************/
#ifndef _ATMEGA32U4_H_
	#define _ATMEGA32U4_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#define Atmega32U4GPWR_Address 0x0000
#define Atmega32U4PORTB_Address 0x0023
#define Atmega32U4PORTC_Address 0x0026
#define Atmega32U4PORTD_Address 0x0029
#define Atmega32U4PORTE_Address 0x002C
#define Atmega32U4PORTF_Address 0x002F
#define Atmega32U4TimerInterruptFlag_Address 0x0035
#define Atmega32U4ExternalInterruptFlag_Address 0x003B
#define Atmega32U4ExternalInterruptMask_Address 0x003D
#define Atmega32U4CpuGeneralPurposeIoRegister_Address 0x003E;
#define Atmega32U4CpuGeneralPurposeIoRegister0_Address 0x003E;
#define Atmega32U4Eeprom_Address 0x003F
#define Atmega3U4TimerGeneralControlRegister_Address 0x0043
#define Atmega32U4TimerCounter0_Address 0x0044
#define Atmega32U4TimerCompareRegister0_Address 0x0047
#define Atmega32U4PhaseLockedLoopControlStatus_Address 0x0049
#define Atmega32U4CpuGeneralPurposeIoRegister1_Address 0x004A;
#define Atmega32U4CpuGeneralPurposeIoRegister2_Address 0x004B;
#define Atmega32U4SerialPeripherialInterface_Address 0x004C
#define Atmega32U4AnalogComparator_Address 0x0050
#define Atmega32U4JtagInterface_Address 0x0051
#define Atmega32U4PhaseLockedLoopFreq_Address 0x0052
#define Atmega32U4CPURegister_Address 0x0053
#define Atmega32U4CPURegisterSleep_Address 0x0053
#define Atmega32U4CPURegisterStatus_Address 0x0054
#define Atmega32U4CPURegisterControl_Address 0x0055
#define Atmega32U4Bootloader_Address 0x0057
#define Atmega32U4CPURegisterState_Address 0x005B
#define Atmega32U4WatchdogTimer_Address 0x0060
#define Atmega32U4CPURegisterPower_Address 0x0061
#define Atmega32U4ExternalInterrupt_Address 0x0068
#define Atmega32U4TimerInterruptMask_Address 0x006E;
#define Atmega32U4AnalogToDigitalConverter_Address 0x0078
#define Atmega32U4AnalogComparatorCs_Address 0x007B;
#define Atmega32U4AnalogComparatorDid_Address 0x007F;
#define Atmega32U4TimerCounter1_Address 0x0080
#define Atmega32U4TimerCompareRegister1_Address 0x0086
#define Atmega32U4TimerCounter3_Address 0x0090
#define Atmega32U4TimerCompareRegister3_Address 0x0096
#define Atmega32U4TwoWireSerialInterface_Address 0x00B8
#define Atmega32U4TimerCounter4_Address 0x00BE
#define Atmega32U4CpuClockSelect_Address 0x00C5
#define Atmega32U4Usart1_Address 0x00C8
#define Atmega32U4TimerCompareRegister4_Address 0x00CF
#define Atmega32U4UsbDeviceRegister_Address 0x00D7

/*** Global Variable ***/
// HLbyte
typedef struct {
	uint8_t L; // Lower address
	uint8_t H; // Higher address
} HighLowByte;

//		MAIN HARDWARE LAYER
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
} Atmega32U4GPWR_TypeDef;

// I/O Port (PORTB)
typedef struct {
	volatile uint8_t pin; // 0x23
	volatile uint8_t ddr; // 0x24
	volatile uint8_t port; //0x25
} Atmega32U4PORTB_TypeDef;

// I/O Port (PORTC)
typedef struct {
	volatile uint8_t pin; // 0x26
	volatile uint8_t ddr; // 0x27
	volatile uint8_t port; // 0x28
} Atmega32U4PORTC_TypeDef;

// I/O Port (PORTD)
typedef struct {
	volatile uint8_t pin; // 0x29
	volatile uint8_t ddr; // 0x2A
	volatile uint8_t port; // 0x2B
} Atmega32U4PORTD_TypeDef;

// I/O Port (PORTE)
typedef struct {
	volatile uint8_t pin; // 0x2C
	volatile uint8_t ddr; // 0x2D
	volatile uint8_t port; // 0x2E
} Atmega32U4PORTE_TypeDef;

// I/O Port (PORTF)
typedef struct {
	volatile uint8_t pin; // 0x2F
	volatile uint8_t ddr; // 0x30
	volatile uint8_t port; // 0x31
} Atmega32U4PORTF_TypeDef;

// TIMER
typedef struct {
	volatile uint8_t tifr0; // 0x35
	volatile uint8_t tifr1; // 0x36
	uint8_t fill; // 0x37
	volatile uint8_t tifr3; // 0x38
	volatile uint8_t tifr4; // 0x39
} Atmega32U4TimerInterruptFlag_TypeDef;

// External Interrupts (EXINT)
typedef struct {
	volatile uint8_t pcifr; // 0x3B
	volatile uint8_t eifr; // 0x3C
} Atmega32U4ExternalInterruptFlag_TypeDef;

// External Interrupts (EXINT)
typedef struct {
	volatile uint8_t eimsk; // 0x3D [eimsk]
} Atmega32U4ExternalInterruptMask_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t r0; // 0x3E
	uint8_t fill[11]; // (0x4A - 0x3E) - 1
	volatile uint8_t r1; // 0x4A
	volatile uint8_t r2; // 0x4B
} Atmega328CpuGeneralPurposeIoRegister_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t par; // 0x3E [gpior0]
} Atmega32U4CpuGeneralPurposeIoRegister0_TypeDef;

// EEPROM (EEPROM)
typedef struct {
	volatile uint8_t eecr; // 0x3F
	volatile uint8_t eedr; // 0x40
	volatile uint16_t eear; // 0x41 0x42
} Atmega32U4Eeprom_TypeDef;

// TIMER
typedef struct {
	volatile uint8_t gtccr; // 0x43 [gtccr]
} Atmega3U4TimerGeneralControlRegister_TypeDef;

// Timer/Counter, 8-bit (TC0)
typedef struct {
	volatile uint8_t tccr0a; // 0x44
	volatile uint8_t tccr0b; // 0x45
	volatile uint8_t tcnt0; // 0x46
} Atmega32U4TimerCounter0_TypeDef;

// Timer/Counter, 8-bit (TC0)
typedef struct {
	volatile uint8_t ocr0a; // 0x47
	volatile uint8_t ocr0b; // 0x48
} Atmega32U4TimerCompareRegister0_TypeDef;

// Phase Locked Loop (PLL)
typedef struct {
	volatile uint8_t par; // 0x49 [pllcsr]
} Atmega32U4PhaseLockedLoopControlStatus_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t par; // 0x4A [gpior1]
} Atmega32U4CpuGeneralPurposeIoRegister1_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t par; // 0x4B [gpior2]
} Atmega32U4CpuGeneralPurposeIoRegister2_TypeDef;

// Serial Peripheral Interface (SPI)
typedef struct {
	volatile uint8_t spcr; // 0x4C
	volatile uint8_t spsr; // 0x4D
	volatile uint8_t spdr; // 0x4E
} Atmega32U4SerialPeripherialInterface_TypeDef;

// Analog Comparator (AC)
typedef struct {
	volatile uint8_t par; // 0x50 [acsr]
} Atmega32U4AnalogComparator_TypeDef;

// JTAG Interface (JTAG)
typedef struct {
	volatile uint8_t par; // 0x51 [ocdr]
} Atmega32U4JtagInterface_TypeDef;

// Phase Locked Loop (PLL)
typedef struct {
	volatile uint8_t par; // 0x52 [pllfrq]
} Atmega32U4PhaseLockedLoopFreq_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t smcr; // 0x53
	volatile uint8_t mcusr; // 0x54
	volatile uint8_t mcucr; // 0x55
	uint8_t fill1[5]; // (0x5B - 0x55) - 1
	volatile uint8_t rampz; // 0x5B
	volatile uint8_t eind; // 0x5C
	volatile HighLowByte sp; // 0x5D 0x5E
	volatile uint8_t sreg; // 0x5F
	uint8_t fill2; // (0x61 - 0x5F) - 1
	volatile uint8_t clkpr; // 0x61
	uint8_t fill3[2]; // (0x64 - 0x61) - 1
	volatile uint8_t prr0; // 0x64
	volatile uint8_t prr1; // 0x65
	volatile uint8_t osccal; // 0x66
	volatile uint8_t rcctrl; // 0x67
} Atmega32U4CPURegister_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t par; // 0x53 [smcr]
} Atmega32U4CPURegisterSleep_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t par; // 0x54 [mcusr]
} Atmega32U4CPURegisterStatus_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t par; // 0x55 [mcucr]
} Atmega32U4CPURegisterControl_TypeDef;

// Boot loader (BOOT_LOAD)
typedef struct {
	volatile HighLowByte par; // 0x57 [spmcsr]
} Atmega32U4Bootloader_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t rampz; // 0x5B
	volatile uint8_t eind; // 0x5C
	volatile HighLowByte sp; // 0x5D 0x5E
	volatile uint8_t sreg; // 0x5F
} Atmega32U4CPURegisterState_TypeDef;

// Watchdog Timer (WDT)
typedef struct {
	volatile uint8_t par; // 0x60 [wdtcr]
} Atmega32U4WatchdogTimer_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t clkpr; // 0x61
	uint8_t fill[2]; // (0x64 - 0x61) - 1
	volatile uint8_t prr0; // 0x64
	volatile uint8_t prr1; // 0x65
	volatile uint8_t osccal; // 0x66
	volatile uint8_t rcctrl; // 0x67
} Atmega32U4CPURegisterPower_TypeDef;

// External Interrupts (EXINT)
typedef struct {
	volatile uint8_t pcicr; // 0x68
	volatile uint8_t eicra; // 0x69
	volatile uint8_t eicrb; // 0x6A
	volatile uint8_t pcmsk0; // 0x6B
} Atmega32U4ExternalInterrupt_TypeDef;

// TIMER
typedef struct {
	volatile uint8_t timsk0; // 0x6E
	volatile uint8_t timsk1; // 0x6F
	uint8_t fill; // 0x70
	volatile uint8_t timsk3; // 0x71
	volatile uint8_t timsk4; // 0x72
} Atmega32U4TimerInterruptMask_TypeDef;

// Analog to Digital Converter (ADC)
typedef struct {
	volatile HighLowByte adc; // 0x78 0x79
	volatile uint8_t adcsra; // 0x7A
	volatile uint8_t adcsrb; // 0x7B
	volatile uint8_t admux; // 0x7C
	volatile uint8_t didr2; // 0x7D
	volatile uint8_t didr0; // 0x7E
} Atmega32U4AnalogToDigitalConverter_TypeDef;

// Analog Comparator (AC)
typedef struct {
	volatile uint8_t par; // 0x7B [adcsrb]
} Atmega32U4AnalogComparatorCs_TypeDef;

// Analog Comparator (AC)
typedef struct {
	volatile uint8_t par; // 0x7F [didr1]
} Atmega32U4AnalogComparatorDid_TypeDef;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	volatile uint8_t tccr1a; // 0x80
	volatile uint8_t tccr1b; // 0x81
	volatile uint8_t tccr1c; // 0x82
	uint8_t fill; // (0x84 - 0x82) - 1
	volatile HighLowByte tcnt1; // 0x84 0x85
} Atmega32U4TimerCounter1_TypeDef;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	volatile HighLowByte icr1; // 0x86 0x87
	volatile HighLowByte ocr1a; // 0x88 0x89
	volatile HighLowByte ocr1b; // 0x8A 0x8B
	volatile HighLowByte ocr1c; // 0x8C 0x8D
} Atmega32U4TimerCompareRegister1_TypeDef;

// Timer/Counter, 16-bit (TC3)
typedef struct {
	volatile uint8_t tccr3a; // 0x90
	volatile uint8_t tccr3b; // 0x91
	volatile uint8_t tccr3c; // 0x92
	uint8_t fill; // (0x94 - 0x92) - 1
	volatile HighLowByte tcnt3; // 0x94 0x95
} Atmega32U4TimerCounter3_TypeDef;

// Timer/Counter, 16-bit (TC3)
typedef struct {
	volatile HighLowByte icr3; // 0x96 0x97
	volatile HighLowByte ocr3a; // 0x98 0x99
	volatile HighLowByte ocr3b; // 0x9A 0x9B
	volatile HighLowByte ocr3c; // 0x9C 0x9D
} Atmega32U4TimerCompareRegister3_TypeDef;

// Two Wire Serial Interface (TWI)
typedef struct {
	volatile uint8_t twbr; // 0xB8
	volatile uint8_t twsr; // 0xB9
	volatile uint8_t twar; // 0xBA
	volatile uint8_t twdr; // 0xBB
	volatile uint8_t twcr; // 0xBC
	volatile uint8_t twamr; // 0xBD
} Atmega32U4TwoWireSerialInterface_TypeDef;

// Timer/Counter, 10-bit (TC4)
typedef struct {
	volatile uint8_t tcnt4; // 0xBE
	volatile uint8_t tc4h; // 0xBF
	volatile uint8_t tccr4a; // 0xC0
	volatile uint8_t tccr4b; // 0xC1
	volatile uint8_t tccr4c; // 0xC2
	volatile uint8_t tccr4d; // 0xC3
	volatile uint8_t tccr4e; // 0xC4
} Atmega32U4TimerCounter4_TypeDef;

// CPU Register (CPU)
typedef struct {
	volatile uint8_t clksel0; // 0xC5
	volatile uint8_t clksel1; // 0xC6
	volatile uint8_t clksta; // 0xC7
} Atmega32U4CpuClockSelect_TypeDef;

// USART (USART1)
typedef struct {
	volatile uint8_t ucsr1a; // 0xC8
	volatile uint8_t ucsr1b; // 0xC9
	volatile uint8_t ucsr1c; // 0xCA
	volatile uint8_t ucsr1d; // 0xCB
	volatile HighLowByte ubrr1; // 0xCC 0xCD
	volatile uint8_t udr1; // 0xCE
} Atmega32U4Usart1_TypeDef;

// Timer/Counter, 10-bit (TC4)
typedef struct {
	volatile uint8_t ocr4a; // 0xCF
	volatile uint8_t ocr4b; // 0xD0
	volatile uint8_t ocr4c; // 0xD1
	volatile uint8_t ocr4d; // 0xD2
	uint8_t fill; // (0xD4 - 0xD2) - 1
	volatile uint8_t dt4; // 0xD4
} Atmega32U4TimerCompareRegister4_TypeDef;

// USB Device Register (USB_DEVICE)
typedef struct {
	volatile uint8_t uhwcon; // 0xD7
	volatile uint8_t usbcon; // 0xD8
	volatile uint8_t usbsta; // 0xD9
	volatile uint8_t usbint; // 0xDA
	uint8_t fill1[5]; // (0xE0 - 0xDA) - 1
	volatile uint8_t udcon; //0xE0
	volatile uint8_t udint; // 0xE1
	volatile uint8_t udien; // 0xE2
	volatile uint8_t udaddr; // 0xE3
	volatile HighLowByte udfnum; // 0xE4 0xE5
	volatile uint8_t udmfn; // 0xE6
	uint8_t fill2; // (0xE8 - 0xE6) - 1
	volatile uint8_t ueintx; // 0xE8
	volatile uint8_t uenum; // 0xE9
	volatile uint8_t uerst; // 0xEA
	volatile uint8_t ueconx; // 0xEB
	volatile uint8_t uecfg0x; // 0xEC
	volatile uint8_t uecfg1x; // 0xED
	volatile uint8_t uesta0x; // 0xEE
	volatile uint8_t uesta1x; // 0xEF
	volatile uint8_t ueienx; // 0xF0
	volatile uint8_t uedatx; // 0xF1
	volatile uint8_t uebclx; // 0xF2
	volatile uint8_t uebchx; // 0xF3
	volatile uint8_t ueint; // 0xF4
} Atmega32U4UsbDeviceRegister_TypeDef;

#endif

/***
MASK FLAG CONTROL STATUS
***/

/***EOF***/

