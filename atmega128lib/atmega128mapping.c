/*********************************************************
	ATMEGA 128 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega128 by ETT ET-BASE
Update: 01/01/2024
Comment:
	Virtual Image Atmega 128 mapping.
**********************************************************/
/*** File Library ***/
#include "atmega128mapping.h"

/*** File Variables ***/

/*** File Header ***/
uint16_t ReadHLByte(HighLowByte reg);
uint16_t ReadLHByte(HighLowByte reg);
HighLowByte WriteHLByte(uint16_t val);
HighLowByte WriteLHByte(uint16_t val);
uint16_t SwapByte(uint16_t num);
uint8_t readreg(uint8_t reg, uint8_t size_block, uint8_t bit_n);
uint8_t getsetbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n);
void setreg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
void setbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
void writereg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
/******/
void ClockPrescalerSelect(volatile uint8_t prescaler);
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
		atmega128.spi.run = &spi;
		atmega128.spi.enable = SPIenable;
	#endif
	// TC1
	atmega128.tc1.reg = (Atmega128TimerCounter1_TypeDef*) Atmega128TimerCounter1_Address;
	atmega128.tc1.misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#if defined(_TIMER1_MODULE_)
		atmega128.tc1.enable = TIMER_COUNTER1enable;
	#endif
	// TC3
	atmega128.tc3.reg = (Atmega128TimerCounter3_TypeDef*) Atmega128TimerCounter3_Address;
	atmega128.tc3.misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#if defined(_TIMER3_MODULE_)
		atmega128.tc3.enable = TIMER_COUNTER3enable;
	#endif
	// TC2
	atmega128.tc2.reg = (Atmega128TimerCounter2_TypeDef*) Atmega128TimerCounter2_Address;
	#if defined(_TIMER2_MODULE_)
		atmega128.tc2.enable = TIMER_COUNTER2enable;
	#endif
	// TC0
	atmega128.tc0.reg = (Atmega128TimerCounter0_TypeDef*) Atmega128TimerCounter0_Address;
	atmega128.tc0.misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#if defined(_TIMER0_MODULE_)
		atmega128.tc0.enable = TIMER_COUNTER0enable;
	#endif
	// TWI
	atmega128.twi.reg = (Atmega128TwoWireSerialInterface_TypeDef*) Atmega128TwoWireSerialInterface_Address;
	#if defined(_TWI_MODULE_)
		atmega128.twi.run = &twi;
		atmega128.twi.enable = TWIenable;
	#endif
	// USART0
	atmega128.usart0.reg = (Atmega128Usart0_TypeDef*) Atmega128Usart0_Address;
	#if defined(_USART0_MODULE_)
		atmega128.usart0.run = &usart0;
		atmega128.usart0.enable = USART0enable;
	#endif
	// USART1
	atmega128.usart1.reg = (Atmega128Usart1_TypeDef*) Atmega128Usart1_Address;
	#if defined(_USART1_MODULE_)
		atmega128.usart1.run = &usart1;
		atmega128.usart1.enable = USART1enable;
	#endif
	atmega128.wdt.reg = (Atmega128WatchdogTimer_TypeDef*) Atmega128WatchdogTimer_Address;
	// General Func
	atmega128.readhlbyte = ReadHLByte;
	atmega128.readlhbyte = ReadLHByte;
	atmega128.writehlbyte = WriteHLByte;
	atmega128.writelhbyte = WriteLHByte;
	atmega128.swapbyte = SwapByte;
	atmega128.readreg = readreg;
	atmega128.writereg = writereg;
	atmega128.setreg = setreg;
	atmega128.setbit = setbit;
	atmega128.getsetbit = getsetbit;
	/******/
	atmega128.Clock_Prescaler_Select = ClockPrescalerSelect;
	atmega128.Move_Interrupts_To_Boot = MoveInterruptsToBoot;
	
	return atmega128;
}

/*** Global Procedure & Function Definition***/
uint16_t BAUDRATEnormal(uint32_t BAUD)
{
	uint32_t baudrate = F_CPU/16;
	baudrate /= BAUD;
	baudrate -= 1;
	return (uint16_t) baudrate;
}
uint16_t BAUDRATEdouble(uint32_t BAUD)
{
	uint32_t baudrate = F_CPU/8;
	baudrate /= BAUD;
	baudrate -= 1;
	return (uint16_t) baudrate;
}
uint16_t BAUDRATEsynchronous(uint32_t BAUD)
{
	uint32_t baudrate = F_CPU/2;
	baudrate /= BAUD;
	baudrate -= 1;
	return (uint16_t) baudrate;
}
/*** File Procedure & Function Definition***/
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
uint8_t readreg(uint8_t reg, uint8_t size_block, uint8_t bit_n)
{
	if(bit_n > DATA_BITS){ bit_n = 0;} if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	reg &= (mask << bit_n);
	reg = (reg >> bit_n);
	return reg;
}
uint8_t getsetbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n)
{
	uint8_t n = 0;
	if(bit_n > DATA_BITS){ n = bit_n/DATA_SIZE; bit_n = bit_n - (n * DATA_SIZE); } if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t value = *(reg + n );
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	value &= (mask << bit_n);
	value = (value >> bit_n);
	return value;
}
void setreg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data)
{
	if(bit_n > DATA_BITS){ bit_n = 0;} if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask;
	*reg &= ~(mask << bit_n);
	*reg |= (data << bit_n);
}
void setbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data)
{
	uint8_t n = 0;
	if(bit_n > DATA_BITS){ n = bit_n/DATA_SIZE; bit_n = bit_n - (n * DATA_SIZE); } if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask;
	*(reg + n ) &= ~(mask << bit_n);
	*(reg + n ) |= (data << bit_n);
}
void writereg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data)
{
	if(bit_n > DATA_BITS){ bit_n = 0;} if(size_block > DATA_SIZE){ size_block = DATA_SIZE;}
	uint8_t value = *reg;
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask; value &= ~(mask << bit_n);
	data = (data << bit_n);
	value |= data;
	*reg = value;
}
/****** System ******/
void ClockPrescalerSelect(volatile uint8_t prescaler)
{
	volatile uint8_t sreg;
	volatile uint8_t* clkpr = &XDIV;
	prescaler &= 0x7F;
	sreg = atmega128.cpu.reg->sreg;
	atmega128.cpu.reg->sreg &= ~(1 << 7);
	
	*clkpr = prescaler;
	*clkpr = (1 << XDIVEN) | prescaler;
	
	atmega128.cpu.reg->sreg = sreg;
}
void MoveInterruptsToBoot(void)
{
	volatile uint8_t sreg;
	sreg = atmega128.cpu.reg->sreg;
	atmega128.cpu.reg->sreg &= ~(1 << 7);
	
	MCUCR = (1<<IVCE);
	MCUCR = (1<<IVSEL);
	
	atmega128.cpu.reg->sreg = sreg;
}

/***EOF***/

