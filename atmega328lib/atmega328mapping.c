/********************************************************************
	ATMEGA 328 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Date: 01122023
Comment:
	Virtual Image Atmega 328 mapping and linking.
*********************************************************************/
/*** File Library ***/
#include "atmega328mapping.h"

/*** File Define & Macro ***/
// STATIC RAM
#define Atmega328InterruptVectors_Address 0x0100

/*** File Variable ***/
//ATMEGA328 atmega328;

/***File Header***/
uint16_t Atmega328_ReadHLByte(HighLowByte reg);
uint16_t Atmega328_ReadLHByte(HighLowByte reg);
HighLowByte Atmega328_WriteHLByte(uint16_t val);
HighLowByte Atmega328_WriteLHByte(uint16_t val);
uint16_t Atmega328_SwapByte(uint16_t num);
uint8_t Atmega328_ByteMask(uint8_t target, uint8_t mask);
void Atmega328_ByteSet(uint8_t* target, uint8_t set);
void Atmega328_ByteClear(uint8_t* target, uint8_t clear);
uint8_t Atmega328_ByteShiftright(uint8_t target, uint8_t shift);
uint8_t Atmega328_ByteShiftleft(uint8_t target, uint8_t shift);

/*** File Procedure & Function ***/
ATMEGA328 ATMEGA328enable(void){
	// Assign
	// GPWR
	atmega328.gpwr.reg = (Atmega328GPWR_TypeDef*) Atmega328GPWR_Address;
	// AC
	atmega328.ac.reg = (Atmega328AnalogComparator_TypeDef*) Atmega328AnalogComparator_Address;
	atmega328.ac.didr1 = (Atmega328AnalogComparatorDid_TypeDef*) Atmega328AnalogComparatorDid_Address;
	// ADC
	atmega328.adc.reg = (Atmega328AnalogToDigitalConverter_TypeDef*) Atmega328AnalogToDigitalConverter_Address;
	#if defined(_ATMEGA328ANALOG_H_)
		atmega328.adc.enable = ANALOGenable;
	#endif
	// CPU
	atmega328.cpu.reg = (Atmega328CPURegister_TypeDef*) Atmega328CPURegister_Address;
	atmega328.cpu.gpio = (Atmega328CpuGeneralPurposeIoRegister_TypeDef*) Atmega328CpuGeneralPurposeIoRegister_Address;
	// EEPROM
	atmega328.eeprom.reg = (Atmega328Eeprom_TypeDef*) Atmega328Eeprom_Address;
	#if defined(_ATMEGAEEPROM_H_)
		atmega328.eeprom.enable = EEPROMenable;
	#endif
	// EXINT
	atmega328.exint.reg = (Atmega328ExternalInterrupt_TypeDef*) Atmega328ExternalInterrupt_Address;
	atmega328.exint.iflag = (Atmega328ExternalInterruptFlag_TypeDef*) Atmega328ExternalInterruptFlag_Address;
	atmega328.exint.imask = (Atmega328ExternalInterruptMask_TypeDef*) Atmega328ExternalInterruptMask_Address;
	#if defined(_ATMEGA328INTERRUPT_H_)
		atmega328.exint.enable = INTERRUPTenable;
	#endif
	// PORTB
	atmega328.portb.reg = (Atmega328PORTB_TypeDef*) Atmega328PORTB_Address;
	// PORTC
	atmega328.portc.reg = (Atmega328PORTC_TypeDef*) Atmega328PORTC_Address;
	// PORTD
	atmega328.portd.reg = (Atmega328PORTD_TypeDef*) Atmega328PORTD_Address;
	// SPI
	atmega328.spi.reg = (Atmega328SerialPeripherialInterface_TypeDef*) Atmega328SerialPeripherialInterface_Address;
	#if defined(_ATMEGA328SPI_H_)
		atmega328.spi.enable = SPIenable;
	#endif
	// TC1
	atmega328.tc1.reg = (Atmega328TimerCounter1_TypeDef*) Atmega328TimerCounter1_Address;
	atmega328.tc1.gcr = (Atmega328TimerGeneralControlRegister_TypeDef*) Atmega328TimerGeneralControlRegister_Address;
	atmega328.tc1.iflag = (Atmega328TimerInterruptFlag_TypeDef*) Atmega328TimerInterruptFlag_Address;
	atmega328.tc1.imask = (Atmega328TimerInterruptMask_TypeDef*) Atmega328TimerInterruptMask_Address;
	atmega328.tc1.comp = (Atmega328TimerCompareRegister1_TypeDef*) Atmega328TimerCompareRegister1_Address;
	#if defined(_ATMEGA328TIMER_H_)
		atmega328.tc1.enable = TIMER_COUNTER1enable;
	#endif
	// TC0
	atmega328.tc0.reg = (Atmega328TimerCounter0_TypeDef*) Atmega328TimerCounter0_Address;
	atmega328.tc0.gcr = (Atmega328TimerGeneralControlRegister_TypeDef*) Atmega328TimerGeneralControlRegister_Address;
	atmega328.tc0.iflag = (Atmega328TimerInterruptFlag_TypeDef*) Atmega328TimerInterruptFlag_Address;
	atmega328.tc0.imask = (Atmega328TimerInterruptMask_TypeDef*) Atmega328TimerInterruptMask_Address;
	atmega328.tc0.comp = (Atmega328TimerCompareRegister0_TypeDef*) Atmega328TimerCompareRegister0_Address;
	#if defined(_ATMEGA328TIMER_H_)
		atmega328.tc0.enable = TIMER_COUNTER0enable;
	#endif
	// TC2
	atmega328.tc2.reg = (Atmega328TimerCounter2_TypeDef*) Atmega328TimerCounter2_Address;
	atmega328.tc2.gcr = (Atmega328TimerGeneralControlRegister_TypeDef*) Atmega328TimerGeneralControlRegister_Address;
	atmega328.tc2.iflag = (Atmega328TimerInterruptFlag_TypeDef*) Atmega328TimerInterruptFlag_Address;
	atmega328.tc2.imask = (Atmega328TimerInterruptMask_TypeDef*) Atmega328TimerInterruptMask_Address;
	atmega328.tc2.comp = (Atmega328TimerCompareRegister2_TypeDef*) Atmega328TimerCompareRegister2_Address;
	#if defined(_ATMEGA328TIMER_H_)
		atmega328.tc2.enable = TIMER_COUNTER2enable;
	#endif
	// TWI
	atmega328.twi.reg = (Atmega328TwoWireSerialInterface_TypeDef*) Atmega328TwoWireSerialInterface_Address;
	#if defined(_ATMEGA328TWI_H_)
		atmega328.twi.enable = TWIenable;
	#endif
	// USART
	atmega328.usart.reg = (Atmega328Usart_TypeDef*) Atmega328Usart_Address;
	#if defined(_ATMEGA328UART_H_)
		atmega328.usart.enable = UARTenable;
	#endif
	// WDT
	atmega328.wdt.reg = (Atmega328WatchdogTimer_TypeDef*) Atmega328WatchdogTimer_Address;
	// General Func
	atmega328.readhlbyte = Atmega328_ReadHLByte;
	atmega328.readlhbyte = Atmega328_ReadLHByte;
	atmega328.writehlbyte = Atmega328_WriteHLByte;
	atmega328.writelhbyte = Atmega328_WriteLHByte;
	atmega328.swapbyte = Atmega328_SwapByte;
	atmega328.byte_mask = Atmega328_ByteMask;
	atmega328.byte_set = Atmega328_ByteSet;
	atmega328.byte_clear = Atmega328_ByteClear;
	atmega328.byte_shiftright = Atmega328_ByteShiftright;
	atmega328.byte_shiftleft = Atmega328_ByteShiftleft;
	
	return atmega328;
}

// COMMON
uint16_t Atmega328_ReadHLByte(HighLowByte reg)
{
	return (reg.H << 8) | reg.L;
}

uint16_t Atmega328_ReadLHByte(HighLowByte reg)
{
	return (reg.L << 8) | reg.H;
}

HighLowByte Atmega328_WriteHLByte(uint16_t val) // AVR normal little endian
{
	HighLowByte reg; reg.H = (val >> 8); reg.L = val;
	return reg;
}

HighLowByte Atmega328_WriteLHByte(uint16_t val)
{
	HighLowByte reg; reg.L = (val >> 8); reg.H = val;
	return reg;
}

uint16_t Atmega328_SwapByte(uint16_t num)
{
	uint16_t tp;
	tp = (num << 8);
	return (num >> 8) | tp;
}

uint8_t Atmega328_ByteMask(uint8_t target, uint8_t mask)
{
	return target & mask;
}

void Atmega328_ByteSet(uint8_t* target, uint8_t set)
{
	*target |= set;
}

void Atmega328_ByteClear(uint8_t* target, uint8_t clear)
{
	*target &= ~clear;
}

uint8_t Atmega328_ByteShiftright(uint8_t target, uint8_t shift)
{
	return target >> shift;
}

uint8_t Atmega328_ByteShiftleft(uint8_t target, uint8_t shift)
{
	return target << shift;
}

/*** File Interrupt ***/
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
// ISR(ANALOG_INTERRUPT)
// ISR(ANALOG_COMP_vect){}
// ISR(TWI_vect){}
// ISR(SPM_READY_vect){}

/***EOF***/

/******
1º Sequence
2º Scope
3º Pointer and Variable
4º Casting
******/

