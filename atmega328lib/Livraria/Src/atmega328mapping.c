/********************************************************************
	ATMEGA 328 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update: 01/01/2024
*********************************************************************/
/****** Comment:
	Virtual Image Atmega 328 mapping and linking.
*********************************************************************/
/*** File Library ***/
#include "atmega328mapping.h"

static ATMEGA328 setup_atmega328;

void Atmega328ClockPrescalerSelect(volatile uint8_t prescaler);
void Atmega328MoveInterruptsToBoot(void);

/*** File Procedure & Function ***/
ATMEGA328 atmega328_enable(void){
	// GPWR
	setup_atmega328.gpwr_reg = (Atmega328GPWR_TypeDef*) Atmega328GPWR_Address;
	// AC
	setup_atmega328.ac_reg = (Atmega328AnalogComparator_TypeDef*) Atmega328AnalogComparator_Address;
	setup_atmega328.ac_didr1 = (Atmega328AnalogComparatorDid_TypeDef*) Atmega328AnalogComparatorDid_Address;
	// ADC
	setup_atmega328.adc_reg = (Atmega328AnalogToDigitalConverter_TypeDef*) Atmega328AnalogToDigitalConverter_Address;
	#if defined(_ANALOG_MODULE_)
		setup_atmega328.adc_enable = adc_enable;
		setup_atmega328.adc = adc();
	#endif
	// CPU
	setup_atmega328.cpu_reg = (Atmega328CPURegister_TypeDef*) Atmega328CPURegister_Address;
	setup_atmega328.cpu_gpio = (Atmega328CpuGeneralPurposeIoRegister_TypeDef*) Atmega328CpuGeneralPurposeIoRegister_Address;
	// EEPROM
	setup_atmega328.eeprom_reg = (Atmega328Eeprom_TypeDef*) Atmega328Eeprom_Address;
	#if defined(_EEPROM_MODULE_)
		setup_atmega328.eeprom_enable = eeprom_enable;
		setup_atmega328.eeprom = eeprom();
	#endif
	// EXINT
	setup_atmega328.exint_reg = (Atmega328ExternalInterrupt_TypeDef*) Atmega328ExternalInterrupt_Address;
	setup_atmega328.exint_iflag = (Atmega328ExternalInterruptFlag_TypeDef*) Atmega328ExternalInterruptFlag_Address;
	setup_atmega328.exint_imask = (Atmega328ExternalInterruptMask_TypeDef*) Atmega328ExternalInterruptMask_Address;
	#if defined(_INTERRUPT_MODULE_)
		setup_atmega328.exint_enable = exint_enable;
		setup_atmega328.exint = exint();
	#endif
	// PORTB
	setup_atmega328.portb_reg = (Atmega328PORTB_TypeDef*) Atmega328PORTB_Address;
	// PORTC
	setup_atmega328.portc_reg = (Atmega328PORTC_TypeDef*) Atmega328PORTC_Address;
	// PORTD
	setup_atmega328.portd_reg = (Atmega328PORTD_TypeDef*) Atmega328PORTD_Address;
	// SPI
	setup_atmega328.spi_reg = (Atmega328SerialPeripherialInterface_TypeDef*) Atmega328SerialPeripherialInterface_Address;
	#if defined(_SPI_MODULE_)
		setup_atmega328.spi_enable = spi_enable;
		setup_atmega328.spi = spi();
	#endif
	// TC1
	setup_atmega328.tc1_reg = (Atmega328TimerCounter1_TypeDef*) Atmega328TimerCounter1_Address;
	setup_atmega328.tc1_gcr = (Atmega328TimerGeneralControlRegister_TypeDef*) Atmega328TimerGeneralControlRegister_Address;
	setup_atmega328.tc1_iflag = (Atmega328TimerInterruptFlag_TypeDef*) Atmega328TimerInterruptFlag_Address;
	setup_atmega328.tc1_imask = (Atmega328TimerInterruptMask_TypeDef*) Atmega328TimerInterruptMask_Address;
	setup_atmega328.tc1_comp = (Atmega328TimerCompareRegister1_TypeDef*) Atmega328TimerCompareRegister1_Address;
	#if defined(_TIMER1_MODULE_)
		setup_atmega328.tc1_enable = tc1_enable;
		setup_atmega328.tc1 = tc1();
	#endif
	// TC0
	setup_atmega328.tc0_reg = (Atmega328TimerCounter0_TypeDef*) Atmega328TimerCounter0_Address;
	setup_atmega328.tc0_gcr = (Atmega328TimerGeneralControlRegister_TypeDef*) Atmega328TimerGeneralControlRegister_Address;
	setup_atmega328.tc0_iflag = (Atmega328TimerInterruptFlag_TypeDef*) Atmega328TimerInterruptFlag_Address;
	setup_atmega328.tc0_imask = (Atmega328TimerInterruptMask_TypeDef*) Atmega328TimerInterruptMask_Address;
	setup_atmega328.tc0_comp = (Atmega328TimerCompareRegister0_TypeDef*) Atmega328TimerCompareRegister0_Address;
	#if defined(_TIMER0_MODULE_)
		setup_atmega328.tc0_enable = tc0_enable;
		setup_atmega328.tc0 = tc0();	
	#endif
	// TC2
	setup_atmega328.tc2_reg = (Atmega328TimerCounter2_TypeDef*) Atmega328TimerCounter2_Address;
	setup_atmega328.tc2_gcr = (Atmega328TimerGeneralControlRegister_TypeDef*) Atmega328TimerGeneralControlRegister_Address;
	setup_atmega328.tc2_iflag = (Atmega328TimerInterruptFlag_TypeDef*) Atmega328TimerInterruptFlag_Address;
	setup_atmega328.tc2_imask = (Atmega328TimerInterruptMask_TypeDef*) Atmega328TimerInterruptMask_Address;
	setup_atmega328.tc2_comp = (Atmega328TimerCompareRegister2_TypeDef*) Atmega328TimerCompareRegister2_Address;
	#if defined(_TIMER2_MODULE_)
		setup_atmega328.tc2_enable = tc2_enable;
		setup_atmega328.tc2 = tc2();
	#endif
	// TWI
	setup_atmega328.twi_reg = (Atmega328TwoWireSerialInterface_TypeDef*) Atmega328TwoWireSerialInterface_Address;
	#if defined(_TWI_MODULE_)
		setup_atmega328.twi_enable = twi_enable;
		setup_atmega328.twi = twi();
	#endif
	// USART
	setup_atmega328.usart0_reg = (Atmega328Usart_TypeDef*) Atmega328Usart_Address;
	#if defined(_USART0_MODULE_)
		setup_atmega328.usart0_enable = usart0_enable;
	#endif
	// WDT
	setup_atmega328.wdt_reg = (Atmega328WatchdogTimer_TypeDef*) Atmega328WatchdogTimer_Address;
	/******/
	setup_atmega328.Clock_Prescaler_Select = Atmega328ClockPrescalerSelect;
	setup_atmega328.Move_Interrupts_To_Boot = Atmega328MoveInterruptsToBoot;
	
	return setup_atmega328;
}

ATMEGA328* atmega328(void){ return &setup_atmega328; }

/****** System ******/
void Atmega328ClockPrescalerSelect(volatile uint8_t prescaler)
{
	volatile uint8_t sreg;
	volatile uint8_t* clkpr = &CLKPR;
	prescaler &= 0x0F;
	sreg = setup_atmega328.cpu_reg->sreg;
	setup_atmega328.cpu_reg->sreg &= ~(1 << 7);
	
	*clkpr = (1 << CLKPCE);
	*clkpr = prescaler;
	
	setup_atmega328.cpu_reg->sreg = sreg;
}
void Atmega328MoveInterruptsToBoot(void)
{
	volatile uint8_t sreg;
	sreg = setup_atmega328.cpu_reg->sreg;
	setup_atmega328.cpu_reg->sreg &= ~(1 << 7);
	
	MCUCR = (1<<IVCE);
	MCUCR = (1<<IVSEL);
	
	setup_atmega328.cpu_reg->sreg = sreg;
}

/***EOF***/

/******
1º Sequence
2º Scope
3º Pointer and Variable
4º Casting
******/

