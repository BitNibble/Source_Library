/************************************************************************
	ATMEGA 128 REGISTERS
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega128 by ETT ET-BASE
Update: 07/01/2024
Comment:
	Virtual Image Atmega 128.
************************************************************************/
#ifndef _ATMEGA128_H_
	#define _ATMEGA128_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#define Atmega128GPWR_Address 0x0000
#define Atmega128AnalogComparator_Address 0x0028
#define Atmega128AnalogToDigitalConverter_Address 0x0024
#define Atmega128BootLoader_Address 0x0068
#define Atmega128CPURegister_Address 0x0054
#define Atmega128Eeprom_Address 0x003C
#define Atmega128ExternalInterrupts_Address 0x0058
#define Atmega128PORTA_Address 0x0039
#define Atmega128PORTB_Address 0x0036
#define Atmega128PORTC_Address 0x0033
#define Atmega128PORTD_Address 0x0030
#define Atmega128PORTE_Address 0x0021
#define Atmega128PORTF_Address 0x0020
#define Atmega128PORTG_Address 0x0063
#define Atmega128JtagInterface_Address 0x0042
#define Atmega128OtherRegisters_Address 0x0040
#define Atmega128SerialPeripherialInterface_Address 0x002D
#define Atmega128TimerCounter1_Address 0x0046
#define Atmega128TimerCounter3_Address 0x007C
#define Atmega128TimerCounter2_Address 0x0043
#define Atmega128TimerCounter0_Address 0X0050
#define Atmega128TwoWireSerialInterface_Address 0x0070
#define Atmega128Usart0_Address 0x0029
#define Atmega128Usart1_Address 0x0098
#define Atmega128WatchdogTimer_Address 0x0041
#define Atmega128JtagInterfaceControlStatus_Address 0x0054
#define Atmega128TimerInterruptFlag_Address 0x0056
#define Atmega128TimerInterruptMask_Address 0x0057
#define Atmega128TimerExternalInterruptFlag_Address 0x007C
#define Atmega128TimerExternalInterruptMask_Address 0x007D

/*** Global Variable ***/
// Low Byte High Byte
typedef struct {
	uint8_t L; // Lower Address
	uint8_t H; // Higher Address
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
} Atmega128GPWR_TypeDef;

// Analog Comparator (AC)
typedef volatile struct {
	union{
		struct{
			uint8_t acis:2;
			uint8_t acic:1;
			uint8_t acie:1;
			uint8_t aci:1;
			uint8_t aco:1;
			uint8_t acbg:1;
			uint8_t acd:1;
		}par;
		uint8_t reg;
	}acsr; // 0x28
} Atmega128AnalogComparator_TypeDef;

// Analog to Digital Converter (ADC)
typedef volatile struct {
	union{
		HighLowByte data;
		uint16_t reg;
	}adc; // 0x24 0x25
	union{
		struct{
			uint8_t adps:3;
			uint8_t adie:1;
			uint8_t adif:1;
			uint8_t adfr:1;
			uint8_t adsc:1;
			uint8_t aden:1;
		}par;
		uint8_t reg;
	}adcsra; // 0x26
	union{
		struct{
			uint8_t mux:5;
			uint8_t adlar:1;
			uint8_t refs:2;
		}par;
		uint8_t reg;
	}admux; // 0x27
} Atmega128AnalogToDigitalConverter_TypeDef;

// Boot loader (BOOT_LOAD)
typedef volatile struct {
	union{
		struct{
				uint8_t spmem:1;
				uint8_t pgers:1;
				uint8_t pgwrt:1;
				uint8_t blbset;
				uint8_t rwwsre:1;
				uint8_t reserved:1;
				uint8_t rwwsb:1;
				uint8_t spmie:1;
		}par;
		uint8_t reg;
	}spmcsr; // 0x68
} Atmega128BootLoader_TypeDef;

// CPU Register (CPU)
typedef volatile struct {
	union{
		struct{
			uint8_t porf:1;
			uint8_t extrf:1;
			uint8_t borf:1;
			uint8_t wdrf:1;
			uint8_t jtrf:1;
			uint8_t reserved:2;
			uint8_t jtd:1;
		}par;
		uint8_t reg;
	}mcucsr; // 0x54
	union{
		struct{
			uint8_t ivce:1;
			uint8_t ivsel:1;
			uint8_t sm2:1;
			uint8_t sm0:1;
			uint8_t sm1:1;
			uint8_t se:1;
			uint8_t srw10:1;
			uint8_t sre:1;
		}par;
		uint8_t reg;
	}mcucr; // 0x55
	uint8_t fill1[5]; // (5B - 55) - 1
	union{
		struct{
			uint8_t rampz0:1;
			uint8_t reserved:7;
		}par;
		uint8_t reg;
	}rampz; // 0x5B
	union{
		struct{
			uint8_t xdiv:7;
			uint8_t xdiven:1;
		}par;
		uint8_t reg;
	}xdiv; // 0x5C
	HighLowByte sp; // 0x5D 0x5E
	union{
		struct{
			uint8_t C:1;
			uint8_t Z:1;
			uint8_t N:1;
			uint8_t V:1;
			uint8_t S:1;
			uint8_t H:1;
			uint8_t T:1;
			uint8_t I:1;
		}par;
		uint8_t reg;
	}sreg; // 0x5F
	uint8_t fill2[12]; // (6C - 5F) - 1
	union{
		struct{
			uint8_t xmm0:1;
			uint8_t xmm1:1;
			uint8_t xmm2:1;
			uint8_t reserved:4;
			uint8_t xmbk:1;
		}par;
		uint8_t reg;
	}xmcrb; // 0x6C
	union{
		struct{
			uint8_t reserved1:1;
			uint8_t srw11:1;
			uint8_t srw00:1;
			uint8_t srw01:1;
			uint8_t srl0:1;
			uint8_t srl1:1;
			uint8_t srl2:1;
			uint8_t reserved2:1;
		}par;
		uint8_t reg;
	}xmcra; // 0x6D
	uint8_t fill3; // (6F - 6D) - 1
	union{
		struct{
			uint8_t b0:1;
			uint8_t b1:1;
			uint8_t b2:1;
			uint8_t b3:1;
			uint8_t b4:1;
			uint8_t b5:1;
			uint8_t b6:1;
			uint8_t b7:1;
		}par;
		uint8_t reg;
	}osccal; // 0x6F
} Atmega128CPURegister_TypeDef;

// EEPROM (EEPROM)
typedef volatile struct {
	union{
		struct{
			uint8_t eere:1;
			uint8_t eewe:1;
			uint8_t eemwe:1;
			uint8_t eerie:1;
			uint8_t reserved:4;
		}par;
		uint8_t reg;
	}eecr; // 0x3C
	union{
		struct{
			uint8_t bit0:1;
			uint8_t bit1:1;
			uint8_t bit2:1;
			uint8_t bit3:1;
			uint8_t bit4:1;
			uint8_t bit5:1;
			uint8_t bit6:1;
			uint8_t bit7:1;
		}par;
		uint8_t reg;
	}eedr; // 0x3D
	HighLowByte eear; // 0x3E 0x3F
} Atmega128Eeprom_TypeDef;

// External Interrupts (EXINT)
typedef volatile struct {
	union{
		struct{
			uint8_t intf0:1;
			uint8_t intf1:1;
			uint8_t intf2:1;
			uint8_t intf3:1;
			uint8_t intf4:1;
			uint8_t intf5:1;
			uint8_t intf6:1;
			uint8_t intf7:1;
		}par;
		uint8_t reg;
	}eifr; // 0x58
	union{
		struct{
			uint8_t int0:1;
			uint8_t int1:1;
			uint8_t int2:1;
			uint8_t int3:1;
			uint8_t int4:1;
			uint8_t int5:1;
			uint8_t int6:1;
			uint8_t int7:1;
		}par;
		uint8_t reg;
	}eimsk; // 0x59
	union{
		struct{
			uint8_t isc40:1;
			uint8_t isc41:1;
			uint8_t isc50:1;
			uint8_t isc51:1;
			uint8_t isc60:1;
			uint8_t isc61:1;
			uint8_t isc70:1;
			uint8_t isc71:1;
		}par;
		uint8_t reg;
	}eicrb; // 0x5A
	uint8_t fill[15]; // (6A - 5A) - 1
	union{
		struct{
			uint8_t isc00:1;
			uint8_t isc01:1;
			uint8_t isc10:1;
			uint8_t isc11:1;
			uint8_t isc20:1;
			uint8_t isc21:1;
			uint8_t isc30:1;
			uint8_t isc31:1;
		}par;
		uint8_t reg;
	}eicra; // 0x6A
} Atmega128ExternalInterrupts_TypeDef;

// I/O Port (PORTA)
typedef struct {
	volatile uint8_t pin; // 0x39
	volatile uint8_t ddr; // 0x3A
	volatile uint8_t port; // 0x3B
} Atmega128PORTA_TypeDef;

// I/O Port (PORTB)
typedef struct {
	volatile uint8_t pin; // 0x36
	volatile uint8_t ddr; // 0x37
	volatile uint8_t port; // 0x38
} Atmega128PORTB_TypeDef;

// I/O Port (PORTC)
typedef struct {
	volatile uint8_t pin; // 0x33
	volatile uint8_t ddr; // 0x34
	volatile uint8_t port; // 0x35
} Atmega128PORTC_TypeDef;

// I/O Port (PORTD)
typedef struct {
	volatile uint8_t pin; // 0x30
	volatile uint8_t ddr; // 0x31
	volatile uint8_t port; // 0x32
} Atmega128PORTD_TypeDef;

// I/O Port (PORTE)
typedef struct {
	volatile uint8_t pin; // 0x21
	volatile uint8_t ddr; // 0x22
	volatile uint8_t port; // 0x23
} Atmega128PORTE_TypeDef;

// I/O Port (PORTF)
typedef struct {
	volatile uint8_t pin; // 0x20
	uint8_t fill[64]; // (0x61 - 0x20) - 1
	volatile uint8_t ddr; // 0x61
	volatile uint8_t port; // 0x62
} Atmega128PORTF_TypeDef;

// I/O Port (PORTG)
typedef struct {
	volatile uint8_t pin; // 0x63
	volatile uint8_t ddr; // 0x64
	volatile uint8_t port; // 0x65
} Atmega128PORTG_TypeDef;

// JTAG Interface (JTAG)
typedef struct {
	volatile uint8_t ocdr; // 0x42
	uint8_t fill[17]; // (54 - 42) - 1
	volatile uint8_t mcucsr; // 0x54
} Atmega128JtagInterface_TypeDef;

// JTAG Interface (JTAG)
typedef struct {
	volatile uint8_t reg; // 0x54 mcucsr
} Atmega128JtagInterfaceControlStatus_TypeDef;

// Other Registers (MISC)
typedef struct {
	volatile uint8_t sfior; // 0x40
} Atmega128OtherRegisters_TypeDef;

// Serial Peripheral Interface (SPI)
typedef struct {
	volatile uint8_t spcr; // 0x2D
	volatile uint8_t spsr; // 0x2E
	volatile uint8_t spdr; // 0x2F
} Atmega128SerialPeripherialInterface_TypeDef;

// Timer/Counter, 16-bit (TC1)
typedef struct {
	volatile HighLowByte icr1; // 0x46 0x47
	volatile HighLowByte ocr1b; // 0x48 0x49
	volatile HighLowByte ocr1a; // 0x4A 0x4B
	volatile HighLowByte tcnt1; // 0x4C 0x4D
	volatile uint8_t tccr1b; // 0x4E
	volatile uint8_t tccr1a; // 0x4F
	uint8_t fill1[6]; // (56 - 4F) - 1
	volatile uint8_t tifr; // 0x56
	volatile uint8_t timsk; // 0x57
	uint8_t fill2[32]; // (78 - 57) - 1
	volatile HighLowByte ocr1c; // 0x78 0x79
	volatile uint8_t tccr1c; // 0x7A
	uint8_t fill3; // (7C - 7A) - 1
	volatile uint8_t etifr; // 0x7C
	volatile uint8_t etimsk; // 0x7D
} Atmega128TimerCounter1_TypeDef;

// Timer/Counter, 16-bit (TC3)
typedef struct {
	volatile uint8_t etifr; // 0x7C
	volatile uint8_t etimsk; // 0x7D
	uint8_t fill[2]; // (80 - 7D) - 1
	volatile HighLowByte icr3; // 0x80 0x81
	volatile HighLowByte ocr3c; // 0x82 0x83
	volatile HighLowByte ocr3b; // 0x84 0x85
	volatile HighLowByte ocr3a; // 0x86 0x87
	volatile HighLowByte tcnt3; // 0x88 0x89
	volatile uint8_t tccr3b; // 0x8A
	volatile uint8_t tccr3a; // 0x8B
	volatile uint8_t tccr3c; // 0x8C
} Atmega128TimerCounter3_TypeDef;

// Timer/Counter 1 and 3
typedef struct {
	volatile uint8_t reg; // 0x7C etifr
} Atmega128TimerExternalInterruptFlag_TypeDef;

// Timer/Counter 1 and 3
typedef struct {
	volatile uint8_t reg; // 0x7D etimsk
} Atmega128TimerExternalInterruptMask_TypeDef;

// Timer/Counter, 8-bit (TC2)
typedef struct {
	volatile uint8_t ocr2; // 0x43
	volatile uint8_t tcnt2; // 0x44
	volatile uint8_t tccr2; // 0x45
	uint8_t fill[16]; // (56 - 45) - 1
	volatile uint8_t tifr; // 0x56
	volatile uint8_t timsk; // 0x57
} Atmega128TimerCounter2_TypeDef;

// Timer/Counter, 8-bit A sync (TC0)
typedef struct {
	volatile uint8_t assr; // 0x50
	volatile uint8_t ocr0; // 0x51
	volatile uint8_t tcnt0; // 0x52
	volatile uint8_t tccr0; // 0x53
	uint8_t fill[2]; // (56 - 53) - 1
	volatile uint8_t tifr; // 0x56
	volatile uint8_t timsk; // 0x57
} Atmega128TimerCounter0_TypeDef;

// Timer/Counter 0, 1 and 2
typedef struct {
	volatile uint8_t reg; // 0x56 tifr
} Atmega128TimerInterruptFlag_TypeDef;

// Timer/Counter 0, 1 and 2
typedef struct {
	volatile uint8_t reg; // 0x57 timsk
} Atmega128TimerInterruptMask_TypeDef;

// Two Wire Serial Interface (TWI)
typedef volatile struct {
	union{
		struct{
			uint8_t bit0:1;
			uint8_t bit1:1;
			uint8_t bit2:1;
			uint8_t bit3:1;
			uint8_t bit4:1;
			uint8_t bit5:1;
			uint8_t bit6:1;
			uint8_t bit7:1;
		}par;
		uint8_t reg;
	}twbr; // 0x70
	union{
		struct{
			uint8_t twps:2;
			uint8_t reserved:1;
			uint8_t tws:5;
		}par;
		uint8_t reg;
	}twsr; // 0x71
	union{
		struct{
			uint8_t twgce:1;
			uint8_t twa:7;
		}par;
		uint8_t reg;
	}twar; // 0x72
	union{
		struct{
			uint8_t bit0:1;
			uint8_t bit1:1;
			uint8_t bit2:1;
			uint8_t bit3:1;
			uint8_t bit4:1;
			uint8_t bit5:1;
			uint8_t bit6:1;
			uint8_t bit7:1;
		}par;
		uint8_t reg;
	}twdr; // 0x73
	union{
		struct{
			uint8_t twie:1;
			uint8_t reserved:1;
			uint8_t twen:1;
			uint8_t twwc:1;
			uint8_t twsto:1;
			uint8_t twsta:1;
			uint8_t twea:1;
			uint8_t twint:1;
		}par;
		uint8_t reg;
	}twcr; // 0x74
} Atmega128TwoWireSerialInterface_TypeDef;

// USART (USART0)
typedef struct {
	volatile uint8_t ubrr0l; // 0x29
	volatile uint8_t ucsr0b; // 0x2A
	volatile uint8_t ucsr0a; // 0x2B
	volatile uint8_t udr0; // 0x2C
	uint8_t fill1[99]; // (90 - 2C) - 1
	volatile uint8_t ubrr0h; // 0x90
	uint8_t fill2[4]; // (95 - 90) - 1
	volatile uint8_t ucsr0c; // 0x95
} Atmega128Usart0_TypeDef;

// USART (USART1)
typedef struct {
	volatile uint8_t ubrr1h; // 0x98
	volatile uint8_t ubrr1l; // 0x99
	volatile uint8_t ucsr1b; // 0x9A
	volatile uint8_t ucsr1a; // 0x9B
	volatile uint8_t udr1; // 0x9C
	volatile uint8_t ucsr1c; // 0x9D
} Atmega128Usart1_TypeDef;

// Watchdog Timer (WDT)
typedef struct {
	volatile uint8_t wdtcr; // 0x41
} Atmega128WatchdogTimer_TypeDef;

/*** Interrupt Vectors FLASH ***/
typedef struct { // IVSEL = 0
	HighLowByte RESET_vect; // 0x0000
	HighLowByte EXT_INT0_vect; // 0x0002
	HighLowByte EXT_INT1_vect; // 0x0004
	HighLowByte EXT_INT2_vect; // 0x0006
	HighLowByte EXT_INT3_vect; // 0x0008
	HighLowByte EXT_INT4_vect; // 0x000A
	HighLowByte EXT_INT5_vect; // 0x000C
	HighLowByte EXT_INT6_vect; // 0x000E
	HighLowByte EXT_INT7_vect; // 0x0010
	HighLowByte TIM2_COMP_vect; // 0x0012
	HighLowByte TIM2_OVF_vect; // 0x0014
	HighLowByte TIM1_CAPT_vect; // 0x0016
	HighLowByte TIM1_COMPA_vect; // 0x0018
	HighLowByte TIM1_COMPB_vect; // 0x001A
	HighLowByte TIM1_OVF_vect; // 0x001C
	HighLowByte TIM0_COMP_vect; // 0x001E
	HighLowByte TIM0_OVF_vect; // 0x0020
	HighLowByte SPI_STC_vect; // 0x0022
	HighLowByte USART0_RXC_vect; // 0x0024
	HighLowByte USART0_DRE_vect; // 0x0026
	HighLowByte USART0_TXC_vect; // 0x0028
	HighLowByte ADC_vect; // 0x002A
	HighLowByte EE_RDY_vect; // 0x002C
	HighLowByte ANA_COMP_vect; // 0x002E
	HighLowByte TIM1_COMPC_vect; // 0x0030
	HighLowByte TIM3_CAPT_vect; // 0x0032
	HighLowByte TIM3_COMPA_vect; // 0x0034
	HighLowByte TIM3_COMPB_vect; // 0x0036
	HighLowByte TIM3_COMPC_vect; // 0x0038
	HighLowByte TIM3_OVF_vect; // 0x003A
	HighLowByte USART1_RXC_vect; // 0x003C
	HighLowByte USART1_DRE_vect; // 0x003E
	HighLowByte USART1_TXC_vect; // 0x0040
	HighLowByte TWI_vect; // 0x0042
	HighLowByte SPM_RDY_vect; // 0x0044
} Atmega128InterruptVectors_TypeDef;

#endif

/***EOF***/

/***
MASK FLAG CONTROL STATUS
*** BIT FIELD CONFIG ***
union{
	struct{
		uint8_t bit0:1;
		uint8_t bit1:1;
		uint8_t bit2:1;
		uint8_t bit3:1;
		uint8_t bit4:1;
		uint8_t bit5:1;
		uint8_t bit6:1;
		uint8_t bit7:1;
	}par;
	uint8_t reg;
}<regname>;
***/

