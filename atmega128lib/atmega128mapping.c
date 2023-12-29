/*********************************************************
	ATMEGA 128 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega128 by ETT ET-BASE
Update: 29/12/2023
Comment:
	Virtual Image Atmega 128 mapping.
**********************************************************/
/*** File Library ***/
#include "atmega128mapping.h"

/*** File Define & Macro ***/
// FLASH
#define Atmega128InterruptVectors_Address 0x0100 // ISVEL = 0

/*** File Header ***/
uint16_t ReadHLByte(HighLowByte reg);
uint16_t ReadLHByte(HighLowByte reg);
HighLowByte WriteHLByte(uint16_t val);
HighLowByte WriteLHByte(uint16_t val);
uint16_t SwapByte(uint16_t num);
uint8_t ByteMask(uint8_t target, uint8_t mask);
void ByteSet(uint8_t* target, uint8_t set);
void ByteClear(uint8_t* target, uint8_t clear);
uint8_t ByteShiftright(uint8_t target, uint8_t shift);
uint8_t ByteShiftleft(uint8_t target, uint8_t shift);
/*** File Procedure & Function Definition***/
uint8_t readreg(uint8_t reg, uint8_t size_block, uint8_t bit);
void writereg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
void setreg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
void setbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data);
uint8_t getsetbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit);
/******/
//void ClockPrescalerSelect(volatile uint8_t prescaler);
void MoveInterruptsToBoot(void);

/*** Procedure & Function ***/
ATMEGA128 ATMEGA128enable(void){ 
	// Assign
	// GPWR
	atmega128.gpwr.reg = (Atmega128GPWR_TypeDef*) Atmega128GPWR_Address;
	// AC
	atmega128.ac.reg = (Atmega128AnalogComparator_TypeDef*) Atmega128AnalogComparator_Address;
	atmega128.ac.misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	// ADC
	atmega128.adc.reg = (Atmega128AnalogToDigitalConverter_TypeDef*) Atmega128AnalogToDigitalConverter_Address;
	#if defined(_ANALOG_MODULE_)
		atmega128.adc.enable = ANALOGenable;
	#endif
	atmega128.boot_load.reg = (Atmega128BootLoader_TypeDef*) Atmega128BootLoader_Address;
	atmega128.cpu.reg = (Atmega128CPURegister_TypeDef*) Atmega128CPURegister_Address;
	// EEPROM
	atmega128.eeprom.reg = (Atmega128Eeprom_TypeDef*) Atmega128Eeprom_Address;
	#if defined(_EEPROM_MODULE_)
		atmega128.eeprom.enable = EEPROMenable;
	#endif
	// EXINT
	atmega128.exint.reg = (Atmega128ExternalInterrupts_TypeDef*) Atmega128ExternalInterrupts_Address;
	#if defined(_INTERRUPT_MODULE_)
		atmega128.exint.enable = INTERRUPTenable;
	#endif
	// PORTA
	atmega128.porta.reg = (Atmega128PORTA_TypeDef*) Atmega128PORTA_Address;
	// PORTB
	atmega128.portb.reg = (Atmega128PORTB_TypeDef*) Atmega128PORTB_Address;
	// PORTC
	atmega128.portc.reg = (Atmega128PORTC_TypeDef*) Atmega128PORTC_Address;
	// PORTD
	atmega128.portd.reg = (Atmega128PORTD_TypeDef*) Atmega128PORTD_Address;
	// PORTE
	atmega128.porte.reg = (Atmega128PORTE_TypeDef*) Atmega128PORTE_Address;
	// PORTF
	atmega128.portf.reg = (Atmega128PORTF_TypeDef*) Atmega128PORTF_Address;
	// PORTG
	atmega128.portg.reg = (Atmega128PORTG_TypeDef*) Atmega128PORTG_Address;
	// JTAG
	atmega128.jtag.reg = (Atmega128JtagInterface_TypeDef*) Atmega128JtagInterface_Address;
	// MISC
	atmega128.misc.reg = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	// SPI
	atmega128.spi.reg = (Atmega128SerialPeripherialInterface_TypeDef*) Atmega128SerialPeripherialInterface_Address;
	#if defined(_SPI_MODULE_)
		atmega128.spi.enable = SPIenable;
	#endif
	// TC1
	atmega128.tc1.reg = (Atmega128TimerCounter1_TypeDef*) Atmega128TimerCounter1_Address;
	atmega128.tc1.misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#if defined(_TIMER_MODULE_)
		atmega128.tc1.enable = TIMER_COUNTER1enable;
	#endif
	// TC3
	atmega128.tc3.reg = (Atmega128TimerCounter3_TypeDef*) Atmega128TimerCounter3_Address;
	atmega128.tc3.misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#if defined(_TIMER_MODULE_)
		atmega128.tc3.enable = TIMER_COUNTER3enable;
	#endif
	// TC2
	atmega128.tc2.reg = (Atmega128TimerCounter2_TypeDef*) Atmega128TimerCounter2_Address;
	#if defined(_TIMER_MODULE_)
		atmega128.tc2.enable = TIMER_COUNTER2enable;
	#endif
	// TC0
	atmega128.tc0.reg = (Atmega128TimerCounter0_TypeDef*) Atmega128TimerCounter0_Address;
	atmega128.tc0.misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#if defined(_TIMER_MODULE_)
		atmega128.tc0.enable = TIMER_COUNTER0enable;
	#endif
	// TWI
	atmega128.twi.reg = (Atmega128TwoWireSerialInterface_TypeDef*) Atmega128TwoWireSerialInterface_Address;
	#if defined(_TWI_MODULE_)
		atmega128.twi.enable = TWIenable;
	#endif
	// USART0
	atmega128.usart0.reg = (Atmega128Usart0_TypeDef*) Atmega128Usart0_Address;
	#if defined(_UART_MODULE_)
		atmega128.usart0.enable = UART0enable;
	#endif
	// USART1
	atmega128.usart1.reg = (Atmega128Usart1_TypeDef*) Atmega128Usart1_Address;
	#if defined(_UART_MODULE_)
		atmega128.usart1.enable = UART1enable;
	#endif
	atmega128.wdt.reg = (Atmega128WatchdogTimer_TypeDef*) Atmega128WatchdogTimer_Address;
	// General Func
	atmega128.readhlbyte = ReadHLByte;
	atmega128.readlhbyte = ReadLHByte;
	atmega128.writehlbyte = WriteHLByte;
	atmega128.writelhbyte = WriteLHByte;
	atmega128.swapbyte = SwapByte;
	atmega128.byte_mask = ByteMask;
	atmega128.byte_set = ByteSet;
	atmega128.byte_clear = ByteClear;
	atmega128.byte_shiftright = ByteShiftright;
	atmega128.byte_shiftleft = ByteShiftleft;
	atmega128.readreg = readreg;
	atmega128.writereg = writereg;
	atmega128.setreg = setreg;
	atmega128.setbit = setbit;
	atmega128.getsetbit = getsetbit;
	/******/
	//atmega128.Clock_Prescaler_Select = ClockPrescalerSelect;
	atmega128.Move_Interrupts_To_Boot = MoveInterruptsToBoot;
	
	return atmega128;
}

// COMMON
uint16_t ReadHLByte(HighLowByte reg)
{
	return (reg.H << 8) | reg.L;
}

uint16_t ReadLHByte(HighLowByte reg)
{
	return (reg.L << 8) | reg.H;
}

HighLowByte WriteHLByte(uint16_t val)
{
	HighLowByte reg; reg.H = (val >> 8); reg.L = val;
	return reg;
}

HighLowByte WriteLHByte(uint16_t val)
{
	HighLowByte reg; reg.L = (val >> 8); reg.H = val;
	return reg;
}

uint16_t SwapByte(uint16_t num)
{
	uint16_t tp;
	tp = (num << 8);
	return (num >> 8) | tp;
}

uint8_t ByteMask(uint8_t target, uint8_t mask)
{
	return target & mask;
}

void ByteSet(uint8_t* target, uint8_t set)
{
	*target |= set;
}

void ByteClear(uint8_t* target, uint8_t clear)
{
	*target &= ~clear;
}

uint8_t ByteShiftright(uint8_t target, uint8_t shift)
{
	return target >> shift;
}

uint8_t ByteShiftleft(uint8_t target, uint8_t shift)
{
	return target << shift;
}

/*** File Procedure & Function Definition***/
uint8_t readreg(uint8_t reg, uint8_t size_block, uint8_t bit)
{
	if(bit > DATA_BITS){ bit = 0;} if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t value = reg;
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	value &= (mask << bit);
	value = (value >> bit);
	return value;
}
void writereg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data)
{
	if(bit > DATA_BITS){ bit = 0;} if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t value = *reg;
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask; value &= ~(mask << bit);
	data = (data << bit);
	value |= data;
	*reg = value;
}
void setreg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data)
{
	if(bit > DATA_BITS){ bit = 0;} if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t value = data;
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	value &= mask;
	*reg &= ~(mask << bit);
	*reg |= (value << bit);
}
void setbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit, uint8_t data)
{
	uint8_t n = 0;
	if(bit > DATA_BITS){ n = bit/DATA_SIZE; bit = bit - (n * DATA_SIZE); } if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t value = data;
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	value &= mask;
	*(reg + n ) &= ~(mask << bit);
	*(reg + n ) |= (value << bit);
}
uint8_t getsetbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit)
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
/***
void ClockPrescalerSelect(volatile uint8_t prescaler)
{
	volatile uint8_t sreg;
	volatile uint8_t* clkpr = &CLKPR;
	prescaler &= 0x0F;
	sreg = atmega128.cpu.reg->sreg;
	atmega128.cpu.reg->sreg &= ~(1 << 7);
	
	*clkpr = (1 << CLKPCE);
	*clkpr = prescaler;
	
	atmega128.cpu.reg->sreg = sreg;
}
***/
void MoveInterruptsToBoot(void)
{
	volatile uint8_t sreg;
	sreg = atmega128.cpu.reg->sreg;
	atmega128.cpu.reg->sreg &= ~(1 << 7);
	
	MCUCR = (1<<IVCE);
	MCUCR = (1<<IVSEL);
	
	atmega128.cpu.reg->sreg = sreg;
}

/*** File Interrupt ***/
// ISR(RESET_vect){}
// ISR(EXT_INT0_vect){}
// ISR(EXT_INT1_vect){}
// ISR(EXT_INT2_vect){}
// ISR(EXT_INT3_vect){}
// ISR(EXT_INT4_vect){}
// ISR(EXT_INT5_vect){}
// ISR(EXT_INT6_vect){}
// ISR(EXT_INT7_vect){}
// ISR(TIM2_COMP_vect){}
// ISR(TIM2_OVF_vect){}
// ISR(TIM1_CAPT_vect){}
// ISR(TIM1_COMPA_vect){}
// ISR(TIM1_COMPB_vect){}
// ISR(TIM1_OVF_vect){}
// ISR(TIM0_COMP_vect){}
// ISR(TIM0_OVF_vect){}
// ISR(SPI_STC_vect){}
// ISR(USART0_RXC_vect){}
// ISR(USART0_DRE_vect){}
// ISR(USART0_TXC_vect){}
// ISR(ADC_vect){}
// ISR(EE_RDY_vect){}
// ISR(ANA_COMP_vect){}
// ISR(TIM1_COMPC_vect){}
// ISR(TIM3_CAPT_vect){}
// ISR(TIM3_COMPA_vect){}
// ISR(TIM3_COMPB_vect){}
// ISR(TIM3_COMPC_vect){}
// ISR(TIM3_OVF_vect){}
// ISR(USART1_RXC_vect){}
// ISR(USART1_DRE_vect){}
// ISR(USART1_TXC_vect){}
// ISR(TWI_vect){}
// ISR(SPM_RDY_vect){}

/***EOF***/

