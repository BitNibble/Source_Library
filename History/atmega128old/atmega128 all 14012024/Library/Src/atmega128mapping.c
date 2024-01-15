/*********************************************************
	ATMEGA 128 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega128 by ETT ET-BASE
Update: 07/01/2024
Comment:
	Virtual Image Atmega 128 mapping.
**********************************************************/
/*** File Library ***/
#include "atmega128mapping.h"

/*** File Variables ***/
static ATMEGA128 atmega;
/**********************/
/*** File Header ***/
uint16_t ReadHLByte(HighLowByte reg);
uint16_t ReadLHByte(HighLowByte reg);
HighLowByte WriteHLByte(uint16_t val);
HighLowByte WriteLHByte(uint16_t val);
uint16_t SwapByte(uint16_t num);
/******/
void ClockPrescalerSelect(volatile uint8_t prescaler);
void MoveInterruptsToBoot(void);

/*** Procedure & Function ***/
ATMEGA128 ATMEGA128enable(void){ 
	
	atmega.gpwr_reg = (Atmega128GPWR_TypeDef*) Atmega128GPWR_Address;
	atmega.ac_reg = (Atmega128AnalogComparator_TypeDef*) Atmega128AnalogComparator_Address;
	atmega.ac_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#ifdef _ANALOG_MODULE_
		atmega.adc_reg = (Atmega128AnalogToDigitalConverter_TypeDef*) Atmega128AnalogToDigitalConverter_Address;
		atmega.adc_enable = ANALOG_enable;
		atmega.adc = adc();
	#else
		atmega.adc_reg = (Atmega128AnalogToDigitalConverter_TypeDef*) Atmega128AnalogToDigitalConverter_Address;
	#endif
	atmega.boot_load_reg = (Atmega128BootLoader_TypeDef*) Atmega128BootLoader_Address;
	atmega.cpu_reg = (Atmega128CPURegister_TypeDef*) Atmega128CPURegister_Address;
	#ifdef _EEPROM_MODULE_
		atmega.eeprom_reg = (Atmega128Eeprom_TypeDef*) Atmega128Eeprom_Address;
		atmega.eeprom_enable = EEPROMenable;
		atmega.eeprom = eeprom();
	#else
		atmega.eeprom_reg = (Atmega128Eeprom_TypeDef*) Atmega128Eeprom_Address;
	#endif
	#ifdef _INTERRUPT_MODULE_
		atmega.exint_reg = (Atmega128ExternalInterrupts_TypeDef*) Atmega128ExternalInterrupts_Address;
		atmega.exint_enable = INTERRUPTenable;
		atmega.exint = exint();
	#else
		atmega.exint_reg = (Atmega128ExternalInterrupts_TypeDef*) Atmega128ExternalInterrupts_Address;
	#endif
	atmega.porta_reg = (Atmega128PORTA_TypeDef*) Atmega128PORTA_Address;
	atmega.portb_reg = (Atmega128PORTB_TypeDef*) Atmega128PORTB_Address;
	atmega.portc_reg = (Atmega128PORTC_TypeDef*) Atmega128PORTC_Address;
	atmega.portd_reg = (Atmega128PORTD_TypeDef*) Atmega128PORTD_Address;
	atmega.porte_reg = (Atmega128PORTE_TypeDef*) Atmega128PORTE_Address;
	atmega.portf_reg = (Atmega128PORTF_TypeDef*) Atmega128PORTF_Address;
	atmega.portg_reg = (Atmega128PORTG_TypeDef*) Atmega128PORTG_Address;
	atmega.jtag_reg = (Atmega128JtagInterface_TypeDef*) Atmega128JtagInterface_Address;
	atmega.misc_reg = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#ifdef _SPI_MODULE_
		atmega.spi_reg = (Atmega128SerialPeripherialInterface_TypeDef*) Atmega128SerialPeripherialInterface_Address;
		atmega.spi_enable = SPI_enable;
		atmega.spi = spi();
	#else
		atmega.spi_reg = (Atmega128SerialPeripherialInterface_TypeDef*) Atmega128SerialPeripherialInterface_Address;
	#endif
	#ifdef _TIMER1_MODULE_
		atmega.tc1_reg = (Atmega128TimerCounter1_TypeDef*) Atmega128TimerCounter1_Address;
		atmega.tc1_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
		atmega.tc1_enable = TIMER_COUNTER1enable;
		atmega.tc1 = tc1();
	#else
		atmega.tc1_reg = (Atmega128TimerCounter1_TypeDef*) Atmega128TimerCounter1_Address;
		atmega.tc1_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#endif
	#ifdef _TIMER3_MODULE_
		atmega.tc3_reg = (Atmega128TimerCounter3_TypeDef*) Atmega128TimerCounter3_Address;
		atmega.tc3_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
		atmega.tc3_enable = TIMER_COUNTER3enable;
		atmega.tc3 = tc3();
	#else
		atmega.tc3_reg = (Atmega128TimerCounter3_TypeDef*) Atmega128TimerCounter3_Address;
		atmega.tc3_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#endif
	#ifdef _TIMER2_MODULE_
		atmega.tc2_reg = (Atmega128TimerCounter2_TypeDef*) Atmega128TimerCounter2_Address;
		atmega.tc2_enable = TIMER_COUNTER2enable;
		atmega.tc2 = tc2();
	#else
		atmega.tc2_reg = (Atmega128TimerCounter2_TypeDef*) Atmega128TimerCounter2_Address;
	#endif
	#ifdef _TIMER0_MODULE_
		atmega.tc0_reg = (Atmega128TimerCounter0_TypeDef*) Atmega128TimerCounter0_Address;
		atmega.tc0_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
		atmega.tc0_enable = TIMER_COUNTER0enable;
		atmega.tc0 = tc0();
	#else
		atmega.tc0_reg = (Atmega128TimerCounter0_TypeDef*) Atmega128TimerCounter0_Address;
		atmega.tc0_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#endif
	#ifdef _TWI_MODULE_
		atmega.twi_reg = (Atmega128TwoWireSerialInterface_TypeDef*) Atmega128TwoWireSerialInterface_Address;
		atmega.twi_enable = TWIenable;
		atmega.twi = twi();
	#else
		atmega.twi_reg = (Atmega128TwoWireSerialInterface_TypeDef*) Atmega128TwoWireSerialInterface_Address;
	#endif
	#ifdef _USART0_MODULE_
		atmega.usart0_reg = (Atmega128Usart0_TypeDef*) Atmega128Usart0_Address;
		atmega.usart0_enable = USART0_enable;
		atmega.usart0 = usart0();
	#else
		atmega.usart0_reg = (Atmega128Usart0_TypeDef*) Atmega128Usart0_Address;
	#endif
		atmega.usart0_reg = (Atmega128Usart0_TypeDef*) Atmega128Usart0_Address;
	#ifdef _USART1_MODULE_
		atmega.usart1_reg = (Atmega128Usart1_TypeDef*) Atmega128Usart1_Address;
		atmega.usart1_enable = USART1_enable;
		atmega.usart1 = usart1();
	#else
		atmega.usart1_reg = (Atmega128Usart1_TypeDef*) Atmega128Usart1_Address;
	#endif
	atmega.wdt_reg = (Atmega128WatchdogTimer_TypeDef*) Atmega128WatchdogTimer_Address;
	// General Func
	atmega.readhlbyte = ReadHLByte;
	atmega.readlhbyte = ReadLHByte;
	atmega.writehlbyte = WriteHLByte;
	atmega.writelhbyte = WriteLHByte;
	atmega.swapbyte = SwapByte;
	atmega.readreg = readreg;
	atmega.writereg = writereg;
	atmega.setreg = setreg;
	atmega.setbit = setbit;
	atmega.getsetbit = getsetbit;
	/******/
	atmega.Clock_Prescaler_Select = ClockPrescalerSelect;
	atmega.Move_Interrupts_To_Boot = MoveInterruptsToBoot;
	
	return atmega;
}

ATMEGA128* atmega128(void){ return &atmega; }

/*** Global Procedure & Function Definition***/
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
	uint8_t value = *(reg + n ); uint8_t mask = (unsigned int)((1 << size_block) - 1);
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
	uint8_t value = *reg; uint8_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask; value &= ~(mask << bit_n);
	data = (data << bit_n);
	value |= data;
	*reg = value;
}
uint16_t BAUDRATEnormal(uint32_t BAUD)
{
	uint32_t baudrate = F_CPU/16;
	baudrate /= BAUD; baudrate -= 1;
	return (uint16_t) baudrate;
}
uint16_t BAUDRATEdouble(uint32_t BAUD)
{
	uint32_t baudrate = F_CPU/8;
	baudrate /= BAUD; baudrate -= 1;
	return (uint16_t) baudrate;
}
uint16_t BAUDRATEsynchronous(uint32_t BAUD)
{
	uint32_t baudrate = F_CPU/2;
	baudrate /= BAUD; baudrate -= 1;
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

/****** System ******/
void ClockPrescalerSelect(volatile uint8_t prescaler)
{
	volatile uint8_t sreg;
	volatile uint8_t* clkpr = &XDIV;
	prescaler &= 0x7F;
	sreg = atmega.cpu_reg->sreg;
	atmega.cpu_reg->sreg &= ~(1 << 7);
	
	*clkpr = prescaler;
	*clkpr = (1 << XDIVEN) | prescaler;
	
	atmega.cpu_reg->sreg = sreg;
}
void MoveInterruptsToBoot(void)
{
	volatile uint8_t sreg;
	sreg = atmega.cpu_reg->sreg;
	atmega.cpu_reg->sreg &= ~(1 << 7);
	
	MCUCR = (1<<IVCE);
	MCUCR = (1<<IVSEL);
	
	atmega.cpu_reg->sreg = sreg;
}

/***EOF***/

