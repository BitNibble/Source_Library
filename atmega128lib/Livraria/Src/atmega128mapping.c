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
void ClockPrescalerSelect(volatile uint8_t prescaler);
void MoveInterruptsToBoot(void);

/*** Procedure & Function ***/
ATMEGA128 atmega128_enable(void){ 
	
	atmega.gpwr_reg = (Atmega128GPWR_TypeDef*) Atmega128GPWR_Address;
	atmega.ac_reg = (Atmega128AnalogComparator_TypeDef*) Atmega128AnalogComparator_Address;
	atmega.ac_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#ifdef _ANALOG_MODULE_
		atmega.adc_reg = (Atmega128AnalogToDigitalConverter_TypeDef*) Atmega128AnalogToDigitalConverter_Address;
		atmega.adc_enable = adc_enable;
		atmega.adc = adc();
	#else
		atmega.adc_reg = (Atmega128AnalogToDigitalConverter_TypeDef*) Atmega128AnalogToDigitalConverter_Address;
	#endif
	atmega.boot_load_reg = (Atmega128BootLoader_TypeDef*) Atmega128BootLoader_Address;
	atmega.cpu_reg = (Atmega128CPURegister_TypeDef*) Atmega128CPURegister_Address;
	#ifdef _EEPROM_MODULE_
		atmega.eeprom_reg = (Atmega128Eeprom_TypeDef*) Atmega128Eeprom_Address;
		atmega.eeprom_enable = eeprom_enable;
		atmega.eeprom = eeprom();
	#else
		atmega.eeprom_reg = (Atmega128Eeprom_TypeDef*) Atmega128Eeprom_Address;
	#endif
	#ifdef _INTERRUPT_MODULE_
		atmega.exint_reg = (Atmega128ExternalInterrupts_TypeDef*) Atmega128ExternalInterrupts_Address;
		atmega.exint_enable = exint_enable;
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
		atmega.spi_enable = spi_enable;
		atmega.spi = spi();
	#else
		atmega.spi_reg = (Atmega128SerialPeripherialInterface_TypeDef*) Atmega128SerialPeripherialInterface_Address;
	#endif
	#ifdef _TIMER1_MODULE_
		atmega.tc1_reg = (Atmega128TimerCounter1_TypeDef*) Atmega128TimerCounter1_Address;
		atmega.tc1_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
		atmega.tc1_enable = tc1_enable;
		atmega.tc1 = tc1();
	#else
		atmega.tc1_reg = (Atmega128TimerCounter1_TypeDef*) Atmega128TimerCounter1_Address;
		atmega.tc1_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#endif
	#ifdef _TIMER3_MODULE_
		atmega.tc3_reg = (Atmega128TimerCounter3_TypeDef*) Atmega128TimerCounter3_Address;
		atmega.tc3_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
		atmega.tc3_enable = tc3_enable;
		atmega.tc3 = tc3();
	#else
		atmega.tc3_reg = (Atmega128TimerCounter3_TypeDef*) Atmega128TimerCounter3_Address;
		atmega.tc3_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#endif
	#ifdef _TIMER2_MODULE_
		atmega.tc2_reg = (Atmega128TimerCounter2_TypeDef*) Atmega128TimerCounter2_Address;
		atmega.tc2_enable = tc2_enable;
		atmega.tc2 = tc2();
	#else
		atmega.tc2_reg = (Atmega128TimerCounter2_TypeDef*) Atmega128TimerCounter2_Address;
	#endif
	#ifdef _TIMER0_MODULE_
		atmega.tc0_reg = (Atmega128TimerCounter0_TypeDef*) Atmega128TimerCounter0_Address;
		atmega.tc0_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
		atmega.tc0_enable = tc0_enable;
		atmega.tc0 = tc0();
	#else
		atmega.tc0_reg = (Atmega128TimerCounter0_TypeDef*) Atmega128TimerCounter0_Address;
		atmega.tc0_misc = (Atmega128OtherRegisters_TypeDef*) Atmega128OtherRegisters_Address;
	#endif
	#ifdef _TWI_MODULE_
		atmega.twi_reg = (Atmega128TwoWireSerialInterface_TypeDef*) Atmega128TwoWireSerialInterface_Address;
		atmega.twi_enable = twi_enable;
		atmega.twi = twi();
	#else
		atmega.twi_reg = (Atmega128TwoWireSerialInterface_TypeDef*) Atmega128TwoWireSerialInterface_Address;
	#endif
	#ifdef _USART0_MODULE_
		atmega.usart0_reg = (Atmega128Usart0_TypeDef*) Atmega128Usart0_Address;
		atmega.usart0_enable = usart0_enable;
		atmega.usart0 = usart0();
	#else
		atmega.usart0_reg = (Atmega128Usart0_TypeDef*) Atmega128Usart0_Address;
	#endif
		atmega.usart0_reg = (Atmega128Usart0_TypeDef*) Atmega128Usart0_Address;
	#ifdef _USART1_MODULE_
		atmega.usart1_reg = (Atmega128Usart1_TypeDef*) Atmega128Usart1_Address;
		atmega.usart1_enable = usart1_enable;
		atmega.usart1 = usart1();
	#else
		atmega.usart1_reg = (Atmega128Usart1_TypeDef*) Atmega128Usart1_Address;
	#endif
	atmega.wdt_reg = (Atmega128WatchdogTimer_TypeDef*) Atmega128WatchdogTimer_Address;
	/******/
	atmega.Clock_Prescaler_Select = ClockPrescalerSelect;
	atmega.Move_Interrupts_To_Boot = MoveInterruptsToBoot;
	
	return atmega;
}

ATMEGA128* atmega128(void){ return &atmega; }

/****** System ******/
void ClockPrescalerSelect(volatile uint8_t prescaler)
{
	volatile uint8_t sreg;
	volatile uint8_t* clkpr = &XDIV;
	prescaler &= 0x7F;
	sreg = atmega.cpu_reg->sreg.reg;
	atmega.cpu_reg->sreg.reg &= ~(1 << 7);
	
	*clkpr = prescaler;
	*clkpr = (1 << XDIVEN) | prescaler;
	
	atmega.cpu_reg->sreg.reg = sreg;
}
void MoveInterruptsToBoot(void)
{
	volatile uint8_t sreg;
	sreg = atmega.cpu_reg->sreg.reg;
	atmega.cpu_reg->sreg.reg &= ~(1 << 7);
	
	MCUCR = (1<<IVCE);
	MCUCR = (1<<IVSEL);
	
	atmega.cpu_reg->sreg.reg = sreg;
}

/***EOF***/

