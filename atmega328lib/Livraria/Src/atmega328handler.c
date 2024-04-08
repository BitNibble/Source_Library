/*********************************************************
	ATMEGA 328 Handler
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega 328
Update:	07/04/2024
Comment: 
	
**********************************************************/
#include "Atmega328handler.h"

/**************************/
/**** HARDWARE HANDLER ****/
/**************************/
// GPWR
Atmega328GPWR_TypeDef* gpwr_handle(void)
{
	return (Atmega328GPWR_TypeDef*) Atmega328GPWR_Address;
}
// I/O Port (PORTB)
Atmega328PORTB_TypeDef* portb_handle(void)
{
	return (Atmega328PORTB_TypeDef*) Atmega328PORTB_Address;
}
// I/O Port (PORTC)
Atmega328PORTC_TypeDef* portc_handle(void)
{
	return (Atmega328PORTC_TypeDef*) Atmega328PORTC_Address;
}
// I/O Port (PORTD)
Atmega328PORTD_TypeDef* portd_handle(void)
{
	return (Atmega328PORTD_TypeDef*) Atmega328PORTD_Address;
}
// Timer/Counter 0, 1 and 2 Interrupt Flag
Atmega328TimerInterruptFlag_TypeDef* tc_iflag_handle(void)
{
	return (Atmega328TimerInterruptFlag_TypeDef*) Atmega328TimerInterruptFlag_Address;
}
// External Interrupts Flag (EXINT)
Atmega328ExternalInterruptFlag_TypeDef* exint_flag_handle(void)
{
	return (Atmega328ExternalInterruptFlag_TypeDef*) Atmega328ExternalInterruptFlag_Address;
}
// External Interrupts Mask (EXINT)
Atmega328ExternalInterruptMask_TypeDef* exint_mask_handle(void)
{
	return (Atmega328ExternalInterruptMask_TypeDef*) Atmega328ExternalInterruptMask_Address;
}
// CPU Register Gpio0 (CPU)
Atmega328CpuGeneralPurposeIoRegister0_TypeDef* cpu_gpio0_handle(void)
{
	return (Atmega328CpuGeneralPurposeIoRegister0_TypeDef*) Atmega328CpuGeneralPurposeIoRegister0_Address;
}
// EEPROM (EEPROM)
Atmega328Eeprom_TypeDef* eeprom_handle(void)
{
	return (Atmega328Eeprom_TypeDef*) Atmega328Eeprom_Address;
}
// TIMER General Control
Atmega328TimerGeneralControlRegister_TypeDef* tc_gcontrol_handle(void)
{
	return (Atmega328TimerGeneralControlRegister_TypeDef*) Atmega328TimerGeneralControlRegister_Address;
}
// Timer/Counter, 8-bit A sync (TC0)
Atmega328TimerCounter0_TypeDef* tc0_handle(void)
{
	return (Atmega328TimerCounter0_TypeDef*) Atmega328TimerCounter0_Address;
}
// Timer/Counter, 8-bit A sync Compare (TC0)
Atmega328TimerCompareRegister0_TypeDef* tc0_compare_handle(void)
{
	return (Atmega328TimerCompareRegister0_TypeDef*) Atmega328TimerCompareRegister0_Address;
}
// CPU Register Gpio1 (CPU)
Atmega328CpuGeneralPurposeIoRegister1_TypeDef* cpu_gpio1_handle(void)
{
	return (Atmega328CpuGeneralPurposeIoRegister1_TypeDef*) Atmega328CpuGeneralPurposeIoRegister1_Address;
}
// CPU Register Gpio012 (CPU)
Atmega328CpuGeneralPurposeIoRegister_TypeDef* cpu_gpio012_handle(void)
{
	return (Atmega328CpuGeneralPurposeIoRegister_TypeDef*) Atmega328CpuGeneralPurposeIoRegister_Address;
}
// CPU Register Gpio2 (CPU)
Atmega328CpuGeneralPurposeIoRegister2_TypeDef* cpu_gpio2_handle(void)
{
	return (Atmega328CpuGeneralPurposeIoRegister2_TypeDef*) Atmega328CpuGeneralPurposeIoRegister2_Address;
}
// Serial Peripheral Interface (SPI)
Atmega328SerialPeripherialInterface_TypeDef* spi_handle(void)
{
	return (Atmega328SerialPeripherialInterface_TypeDef*) Atmega328SerialPeripherialInterface_Address;
}
// Analog Comparator (AC)
Atmega328AnalogComparator_TypeDef* ac_handle(void)
{
	return (Atmega328AnalogComparator_TypeDef*) Atmega328AnalogComparator_Address;
}
// Watchdog Timer (WDT)
Atmega328WatchdogTimer_TypeDef* wdt_handle(void)
{
	return (Atmega328WatchdogTimer_TypeDef*) Atmega328WatchdogTimer_Address;
}
// CPU Register (CPU)
Atmega328CPURegister_TypeDef* cpu_handle(void)
{
	return (Atmega328CPURegister_TypeDef*) Atmega328CPURegister_Address;
}
// External Interrupts Pin Change Mask (EXINT)
Atmega328ExternalInterruptPinChangeMask_TypeDef* exint_pcmask_handle(void)
{
	return (Atmega328ExternalInterruptPinChangeMask_TypeDef*) Atmega328ExternalInterruptPinChangeMask_Address;
}
// External Interrupts (EXINT)
Atmega328ExternalInterrupt_TypeDef* exint_handle(void)
{
	return (Atmega328ExternalInterrupt_TypeDef*) Atmega328ExternalInterrupt_Address;
}
// Timer/Counter 0, 1 and 2 Interrupt Mask
Atmega328TimerInterruptMask_TypeDef* tc_imask_handle(void)
{
	return (Atmega328TimerInterruptMask_TypeDef*) Atmega328TimerInterruptMask_Address;
}
// Analog to Digital Converter (ADC)
Atmega328AnalogToDigitalConverter_TypeDef* adc_handle(void)
{
	return (Atmega328AnalogToDigitalConverter_TypeDef*) Atmega328AnalogToDigitalConverter_Address;
}
// Analog Comparator Did (AC)
Atmega328AnalogComparatorDid_TypeDef* ac_did_handle(void)
{
	return (Atmega328AnalogComparatorDid_TypeDef*) Atmega328AnalogComparatorDid_Address;
}
// Timer/Counter, 16-bit (TC1)
Atmega328TimerCounter1_TypeDef* tc1_handle(void)
{
	return (Atmega328TimerCounter1_TypeDef*) Atmega328TimerCounter1_Address;
}
// Timer/Counter, 16-bit Compare (TC1)
Atmega328TimerCompareRegister1_TypeDef* tc1_compare_handle(void)
{
	return (Atmega328TimerCompareRegister1_TypeDef*) Atmega328TimerCompareRegister1_Address;
}
// Timer/Counter, 8-bit (TC2)
Atmega328TimerCounter2_TypeDef* tc2_handle(void)
{
	return (Atmega328TimerCounter2_TypeDef*) Atmega328TimerCounter2_Address;
}
// Timer/Counter, 8-bit Compare (TC2)
Atmega328TimerCompareRegister2_TypeDef* tc2_compare_handle(void)
{
	return (Atmega328TimerCompareRegister2_TypeDef*) Atmega328TimerCompareRegister2_Address;
}
// Two Wire Serial Interface (TWI)
Atmega328TwoWireSerialInterface_TypeDef* twi_handle(void)
{
	return (Atmega328TwoWireSerialInterface_TypeDef*) Atmega328TwoWireSerialInterface_Address;
}
// USART (USART0)
Atmega328Usart0_TypeDef* usart0_handle(void)
{
	return (Atmega328Usart0_TypeDef*) Atmega328Usart0_Address;
}
/*** Atmega 128 Procedure and Function ***/
uint16_t readhlbyte(HighLowByte reg)
{
	return (reg.par.H << 8) | reg.par.L;
}
uint16_t readlhbyte(HighLowByte reg)
{
	return (reg.par.L << 8) | reg.par.H;
}
HighLowByte writehlbyte(uint16_t val)
{
	HighLowByte reg; reg.par.H = (val >> 8); reg.par.L = val;
	return reg;
}
HighLowByte writelhbyte(uint16_t val)
{
	HighLowByte reg; reg.par.L = (val >> 8); reg.par.H = val;
	return reg;
}
uint16_t SwapByte(uint16_t num)
{
	uint16_t tp;
	tp = (num << 8);
	return (num >> 8) | tp;
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
/****** System ******/
void Atmega328ClockPrescalerSelect(volatile uint8_t prescaler)
{
	volatile uint8_t sreg;
	volatile uint8_t* clkpr = &CLKPR;
	prescaler &= 0x0F;
	sreg = cpu_handle()->sreg;
	cpu_handle()->sreg &= ~(1 << 7);
	
	*clkpr = (1 << CLKPCE);
	*clkpr = prescaler;
	
	cpu_handle()->sreg = sreg;
}
void Atmega328MoveInterruptsToBoot(void)
{
	volatile uint8_t sreg;
	sreg = cpu_handle()->sreg;
	cpu_handle()->sreg &= ~(1 << 7);
	
	MCUCR = (1<<IVCE);
	MCUCR = (1<<IVSEL);
	
	cpu_handle()->sreg = sreg;
}

/*** EOF ***/

