/********************************************************************
	ATMEGA 88 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega88 by ETT ET-BASE
Date: 05122023
Comment:
	Virtual Image Atmega 88 mapping and linking.
*********************************************************************/
/*** File Library ***/
#include "atmega88mapping.h"

/*** File Define & Macro ***/
// STATIC RAM
#define Atmega88InterruptVectors_Address 0x0100

/*** File Variable ***/
//ATMEGA88 atmega88;

/***File Header***/
uint16_t Atmega88_ReadHLByte(HighLowByte reg);
uint16_t Atmega88_ReadLHByte(HighLowByte reg);
HighLowByte Atmega88_WriteHLByte(uint16_t val);
HighLowByte Atmega88_WriteLHByte(uint16_t val);
uint16_t Atmega88_SwapByte(uint16_t num);
uint8_t Atmega88_ByteMask(uint8_t target, uint8_t mask);
void Atmega88_ByteSet(uint8_t* target, uint8_t set);
void Atmega88_ByteClear(uint8_t* target, uint8_t clear);
uint8_t Atmega88_ByteShiftright(uint8_t target, uint8_t shift);
uint8_t Atmega88_ByteShiftleft(uint8_t target, uint8_t shift);

/*** File Procedure & Function ***/
ATMEGA88 ATMEGA88enable(void){
	// Assign
	// GPWR
	atmega88.gpwr.reg = (Atmega88GPWR_TypeDef*) Atmega88GPWR_Address;
	// AC
	atmega88.ac.reg = (Atmega88AnalogComparator_TypeDef*) Atmega88AnalogComparator_Address;
	atmega88.ac.didr1 = (Atmega88AnalogComparatorDid_TypeDef*) Atmega88AnalogComparatorDid_Address;
	// ADC
	atmega88.adc.reg = (Atmega88AnalogToDigitalConverter_TypeDef*) Atmega88AnalogToDigitalConverter_Address;
	#if defined(_ATMEGA88ANALOG_H_)
		atmega88.adc.enable = ANALOGenable;
	#endif
	// CPU
	atmega88.cpu.reg = (Atmega88CPURegister_TypeDef*) Atmega88CPURegister_Address;
	atmega88.cpu.gpio = (Atmega88CpuGeneralPurposeIoRegister_TypeDef*) Atmega88CpuGeneralPurposeIoRegister_Address;
	// EEPROM
	atmega88.eeprom.reg = (Atmega88Eeprom_TypeDef*) Atmega88Eeprom_Address;
	#if defined(_ATMEGAEEPROM_H_)
		atmega88.eeprom.enable = EEPROMenable;
	#endif
	// EXINT
	atmega88.exint.reg = (Atmega88ExternalInterrupt_TypeDef*) Atmega88ExternalInterrupt_Address;
	atmega88.exint.iflag = (Atmega88ExternalInterruptFlag_TypeDef*) Atmega88ExternalInterruptFlag_Address;
	atmega88.exint.imask = (Atmega88ExternalInterruptMask_TypeDef*) Atmega88ExternalInterruptMask_Address;
	#if defined(_ATMEGA88INTERRUPT_H_)
		atmega88.exint.enable = INTERRUPTenable;
	#endif
	// PORTB
	atmega88.portb.reg = (Atmega88PORTB_TypeDef*) Atmega88PORTB_Address;
	// PORTC
	atmega88.portc.reg = (Atmega88PORTC_TypeDef*) Atmega88PORTC_Address;
	// PORTD
	atmega88.portd.reg = (Atmega88PORTD_TypeDef*) Atmega88PORTD_Address;
	// SPI
	atmega88.spi.reg = (Atmega88SerialPeripherialInterface_TypeDef*) Atmega88SerialPeripherialInterface_Address;
	#if defined(_ATMEGA88SPI_H_)
		atmega88.spi.enable = SPIenable;
	#endif
	// TC1
	atmega88.tc1.reg = (Atmega88TimerCounter1_TypeDef*) Atmega88TimerCounter1_Address;
	atmega88.tc1.gcr = (Atmega88TimerGeneralControlRegister_TypeDef*) Atmega88TimerGeneralControlRegister_Address;
	atmega88.tc1.iflag = (Atmega88TimerInterruptFlag_TypeDef*) Atmega88TimerInterruptFlag_Address;
	atmega88.tc1.imask = (Atmega88TimerInterruptMask_TypeDef*) Atmega88TimerInterruptMask_Address;
	atmega88.tc1.comp = (Atmega88TimerCompareRegister1_TypeDef*) Atmega88TimerCompareRegister1_Address;
	#if defined(_ATMEGA88TIMER_H_)
		atmega88.tc1.enable = TIMER_COUNTER1enable;
	#endif
	// TC0
	atmega88.tc0.reg = (Atmega88TimerCounter0_TypeDef*) Atmega88TimerCounter0_Address;
	atmega88.tc0.gcr = (Atmega88TimerGeneralControlRegister_TypeDef*) Atmega88TimerGeneralControlRegister_Address;
	atmega88.tc0.iflag = (Atmega88TimerInterruptFlag_TypeDef*) Atmega88TimerInterruptFlag_Address;
	atmega88.tc0.imask = (Atmega88TimerInterruptMask_TypeDef*) Atmega88TimerInterruptMask_Address;
	atmega88.tc0.comp = (Atmega88TimerCompareRegister0_TypeDef*) Atmega88TimerCompareRegister0_Address;
	#if defined(_ATMEGA88TIMER_H_)
		atmega88.tc0.enable = TIMER_COUNTER0enable;
	#endif
	// TC2
	atmega88.tc2.reg = (Atmega88TimerCounter2_TypeDef*) Atmega88TimerCounter2_Address;
	atmega88.tc2.gcr = (Atmega88TimerGeneralControlRegister_TypeDef*) Atmega88TimerGeneralControlRegister_Address;
	atmega88.tc2.iflag = (Atmega88TimerInterruptFlag_TypeDef*) Atmega88TimerInterruptFlag_Address;
	atmega88.tc2.imask = (Atmega88TimerInterruptMask_TypeDef*) Atmega88TimerInterruptMask_Address;
	atmega88.tc2.comp = (Atmega88TimerCompareRegister2_TypeDef*) Atmega88TimerCompareRegister2_Address;
	#if defined(_ATMEGA88TIMER_H_)
		atmega88.tc2.enable = TIMER_COUNTER2enable;
	#endif
	// TWI
	atmega88.twi.reg = (Atmega88TwoWireSerialInterface_TypeDef*) Atmega88TwoWireSerialInterface_Address;
	#if defined(_ATMEGA88TWI_H_)
		atmega88.twi.enable = TWIenable;
	#endif
	// USART
	atmega88.usart.reg = (Atmega88Usart_TypeDef*) Atmega88Usart_Address;
	#if defined(_ATMEGA88UART_H_)
		atmega88.usart.enable = UARTenable;
	#endif
	// WDT
	atmega88.wdt.reg = (Atmega88WatchdogTimer_TypeDef*) Atmega88WatchdogTimer_Address;
	// General Func
	atmega88.readhlbyte = Atmega88_ReadHLByte;
	atmega88.readlhbyte = Atmega88_ReadLHByte;
	atmega88.writehlbyte = Atmega88_WriteHLByte;
	atmega88.writelhbyte = Atmega88_WriteLHByte;
	atmega88.swapbyte = Atmega88_SwapByte;
	atmega88.byte_mask = Atmega88_ByteMask;
	atmega88.byte_set = Atmega88_ByteSet;
	atmega88.byte_clear = Atmega88_ByteClear;
	atmega88.byte_shiftright = Atmega88_ByteShiftright;
	atmega88.byte_shiftleft = Atmega88_ByteShiftleft;
	
	return atmega88;
}

// COMMON
uint16_t Atmega88_ReadHLByte(HighLowByte reg)
{
	return (reg.H << 8) | reg.L;
}

uint16_t Atmega88_ReadLHByte(HighLowByte reg)
{
	return (reg.L << 8) | reg.H;
}

HighLowByte Atmega88_WriteHLByte(uint16_t val) // AVR normal little endian
{
	HighLowByte reg; reg.H = (val >> 8); reg.L = val;
	return reg;
}

HighLowByte Atmega88_WriteLHByte(uint16_t val)
{
	HighLowByte reg; reg.L = (val >> 8); reg.H = val;
	return reg;
}

uint16_t Atmega88_SwapByte(uint16_t num)
{
	uint16_t tp;
	tp = (num << 8);
	return (num >> 8) | tp;
}

uint8_t Atmega88_ByteMask(uint8_t target, uint8_t mask)
{
	return target & mask;
}

void Atmega88_ByteSet(uint8_t* target, uint8_t set)
{
	*target |= set;
}

void Atmega88_ByteClear(uint8_t* target, uint8_t clear)
{
	*target &= ~clear;
}

uint8_t Atmega88_ByteShiftright(uint8_t target, uint8_t shift)
{
	return target >> shift;
}

uint8_t Atmega88_ByteShiftleft(uint8_t target, uint8_t shift)
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

