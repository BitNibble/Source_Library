/********************************************************************
	ATMEGA 328 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Date: 07122023
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
/*** File Procedure & Function Definition***/
uint8_t Atmega328_readreg(uint8_t reg, uint8_t size_block, uint8_t bit);
void Atmega328_writereg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
void Atmega328_setreg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
void Atmega328_setbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
uint8_t Atmega328_getsetbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit);
/******/
void Atmega328ClockPrescalerSelect(volatile uint8_t prescaler);
void Atmega328MoveInterruptsToBoot(void);

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
	#if defined(_ANALOG_MODULE_)
		atmega328.adc.enable = ANALOGenable;
	#endif
	// CPU
	atmega328.cpu.reg = (Atmega328CPURegister_TypeDef*) Atmega328CPURegister_Address;
	atmega328.cpu.gpio = (Atmega328CpuGeneralPurposeIoRegister_TypeDef*) Atmega328CpuGeneralPurposeIoRegister_Address;
	// EEPROM
	atmega328.eeprom.reg = (Atmega328Eeprom_TypeDef*) Atmega328Eeprom_Address;
	#if defined(_EEPROM_MODULE_)
		atmega328.eeprom.enable = EEPROMenable;
	#endif
	// EXINT
	atmega328.exint.reg = (Atmega328ExternalInterrupt_TypeDef*) Atmega328ExternalInterrupt_Address;
	atmega328.exint.iflag = (Atmega328ExternalInterruptFlag_TypeDef*) Atmega328ExternalInterruptFlag_Address;
	atmega328.exint.imask = (Atmega328ExternalInterruptMask_TypeDef*) Atmega328ExternalInterruptMask_Address;
	#if defined(_INTERRUPT_MODULE_)
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
	#if defined(_SPI_MODULE_)
		atmega328.spi.enable = SPIenable;
	#endif
	// TC1
	atmega328.tc1.reg = (Atmega328TimerCounter1_TypeDef*) Atmega328TimerCounter1_Address;
	atmega328.tc1.gcr = (Atmega328TimerGeneralControlRegister_TypeDef*) Atmega328TimerGeneralControlRegister_Address;
	atmega328.tc1.iflag = (Atmega328TimerInterruptFlag_TypeDef*) Atmega328TimerInterruptFlag_Address;
	atmega328.tc1.imask = (Atmega328TimerInterruptMask_TypeDef*) Atmega328TimerInterruptMask_Address;
	atmega328.tc1.comp = (Atmega328TimerCompareRegister1_TypeDef*) Atmega328TimerCompareRegister1_Address;
	#if defined(_TIMER_MODULE_)
		atmega328.tc1.enable = TIMER_COUNTER1enable;
	#endif
	// TC0
	atmega328.tc0.reg = (Atmega328TimerCounter0_TypeDef*) Atmega328TimerCounter0_Address;
	atmega328.tc0.gcr = (Atmega328TimerGeneralControlRegister_TypeDef*) Atmega328TimerGeneralControlRegister_Address;
	atmega328.tc0.iflag = (Atmega328TimerInterruptFlag_TypeDef*) Atmega328TimerInterruptFlag_Address;
	atmega328.tc0.imask = (Atmega328TimerInterruptMask_TypeDef*) Atmega328TimerInterruptMask_Address;
	atmega328.tc0.comp = (Atmega328TimerCompareRegister0_TypeDef*) Atmega328TimerCompareRegister0_Address;
	#if defined(_TIMER_MODULE_)
		atmega328.tc0.enable = TIMER_COUNTER0enable;
	#endif
	// TC2
	atmega328.tc2.reg = (Atmega328TimerCounter2_TypeDef*) Atmega328TimerCounter2_Address;
	atmega328.tc2.gcr = (Atmega328TimerGeneralControlRegister_TypeDef*) Atmega328TimerGeneralControlRegister_Address;
	atmega328.tc2.iflag = (Atmega328TimerInterruptFlag_TypeDef*) Atmega328TimerInterruptFlag_Address;
	atmega328.tc2.imask = (Atmega328TimerInterruptMask_TypeDef*) Atmega328TimerInterruptMask_Address;
	atmega328.tc2.comp = (Atmega328TimerCompareRegister2_TypeDef*) Atmega328TimerCompareRegister2_Address;
	#if defined(_TIMER_MODULE_)
		atmega328.tc2.enable = TIMER_COUNTER2enable;
	#endif
	// TWI
	atmega328.twi.reg = (Atmega328TwoWireSerialInterface_TypeDef*) Atmega328TwoWireSerialInterface_Address;
	#if defined(_TWI_MODULE_)
		atmega328.twi.enable = TWIenable;
	#endif
	// USART
	atmega328.usart.reg = (Atmega328Usart_TypeDef*) Atmega328Usart_Address;
	#if defined(_UART_MODULE_)
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
	atmega328.readreg = Atmega328_readreg;
	atmega328.writereg = Atmega328_writereg;
	atmega328.setreg = Atmega328_setreg;
	atmega328.setbit = Atmega328_setbit;
	atmega328.getsetbit = Atmega328_getsetbit;
	/******/
	atmega328.Clock_Prescaler_Select = Atmega328ClockPrescalerSelect;
	atmega328.Move_Interrupts_To_Boot = Atmega328MoveInterruptsToBoot;
	
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

/*** File Procedure & Function Definition***/
uint8_t Atmega328_readreg(uint8_t reg, uint8_t size_block, uint8_t bit)
{
	if(bit > DATA_BITS){ bit = 0;} if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t value = reg;
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	value &= (mask << bit);
	value = (value >> bit);
	return value;
}
void Atmega328_writereg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data)
{
	if(bit > DATA_BITS){ bit = 0;} if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t value = *reg;
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask; value &= ~(mask << bit);
	data = (data << bit);
	value |= data;
	*reg = value;
}
void Atmega328_setreg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data)
{
	if(bit > DATA_BITS){ bit = 0;} if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t value = data;
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	value &= mask;
	*reg &= ~(mask << bit);
	*reg |= (value << bit);
}
void Atmega328_setbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data)
{
	uint8_t n = 0;
	if(bit > DATA_BITS){ n = bit/DATA_SIZE; bit = bit - (n * DATA_SIZE); } if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t value = data;
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	value &= mask;
	*(reg + n ) &= ~(mask << bit);
	*(reg + n ) |= (value << bit);
}
uint8_t Atmega328_getsetbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit)
{
	uint8_t n = 0;
	if(bit > DATA_BITS){ n = bit/DATA_SIZE; bit = bit - (n * DATA_SIZE); } if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t value = *(reg + n );
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	value &= (mask << bit);
	value = (value >> bit);
	return value;
}

/******/
void Atmega328ClockPrescalerSelect(volatile uint8_t prescaler)
{
	volatile uint8_t sreg;
	volatile uint8_t* clkpr = &CLKPR;
	prescaler &= 0x0F;
	sreg = atmega328.cpu.reg->sreg;
	atmega328.cpu.reg->sreg &= ~(1 << 7);
	
	*clkpr = (1 << CLKPCE);
	*clkpr = prescaler;
	
	atmega328.cpu.reg->sreg = sreg;
}
void Atmega328MoveInterruptsToBoot(void)
{
	volatile uint8_t sreg;
	sreg = atmega328.cpu.reg->sreg;
	atmega328.cpu.reg->sreg &= ~(1 << 7);
	
	MCUCR = (1<<IVCE);
	MCUCR = (1<<IVSEL);
	
	atmega328.cpu.reg->sreg = sreg;
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

