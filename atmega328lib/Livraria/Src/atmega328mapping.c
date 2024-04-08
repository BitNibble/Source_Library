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

/*** File Procedure & Function ***/
ATMEGA328 atmega328_enable(void){
	// GPWR
	setup_atmega328.gpwr_handle = gpwr_handle();
	// AC
	setup_atmega328.ac_handle = ac_handle();
	setup_atmega328.ac_did_handle = ac_did_handle();
	// ADC
	setup_atmega328.adc_handle = adc_handle();
	#if defined(_ANALOG_MODULE_)
		setup_atmega328.adc_enable = adc_enable;
		setup_atmega328.adc = adc();
	#endif
	// CPU
	setup_atmega328.cpu_handle = cpu_handle();
	setup_atmega328.cpu_gpio012_handle = cpu_gpio012_handle();
	// EEPROM
	setup_atmega328.eeprom_handle = eeprom_handle();
	#if defined(_EEPROM_MODULE_)
		setup_atmega328.eeprom_enable = eeprom_enable;
		setup_atmega328.eeprom = eeprom();
	#endif
	// EXINT
	setup_atmega328.exint_handle = exint_handle();
	setup_atmega328.exint_flag_handle = exint_flag_handle();
	setup_atmega328.exint_mask_handle = exint_mask_handle();
	setup_atmega328.exint_pcmask_handle = exint_pcmask_handle();
	#if defined(_INTERRUPT_MODULE_)
		setup_atmega328.exint_enable = exint_enable;
		setup_atmega328.exint = exint();
	#endif
	// PORTB
	setup_atmega328.portb_handle = portb_handle();
	// PORTC
	setup_atmega328.portc_handle = portc_handle();
	// PORTD
	setup_atmega328.portd_handle = portd_handle();
	// SPI
	setup_atmega328.spi_handle = spi_handle();
	#if defined(_SPI_MODULE_)
		setup_atmega328.spi_enable = spi_enable;
		setup_atmega328.spi = spi();
	#endif
	// TC1
	setup_atmega328.tc1_handle = tc1_handle();
	setup_atmega328.tc1_gcontrol_handle = tc_gcontrol_handle();
	setup_atmega328.tc1_iflag_handle = tc_iflag_handle();
	setup_atmega328.tc1_imask_handle = tc_imask_handle();
	setup_atmega328.tc1_compare_handle = tc1_compare_handle();
	#if defined(_TIMER1_MODULE_)
		setup_atmega328.tc1_enable = tc1_enable;
		setup_atmega328.tc1 = tc1();
	#endif
	// TC0
	setup_atmega328.tc0_handle = tc0_handle();
	setup_atmega328.tc0_gcontrol_handle = tc_gcontrol_handle();
	setup_atmega328.tc0_iflag_handle = tc_iflag_handle();
	setup_atmega328.tc0_imask_handle = tc_imask_handle();
	setup_atmega328.tc0_compare_handle = tc0_compare_handle();
	#if defined(_TIMER0_MODULE_)
		setup_atmega328.tc0_enable = tc0_enable;
		setup_atmega328.tc0 = tc0();	
	#endif
	// TC2
	setup_atmega328.tc2_handle = tc2_handle();
	setup_atmega328.tc2_gcontrol_handle = tc_gcontrol_handle();
	setup_atmega328.tc2_iflag_handle = tc_iflag_handle();
	setup_atmega328.tc2_imask_handle = tc_imask_handle();
	setup_atmega328.tc2_compare_handle = tc2_compare_handle();
	#if defined(_TIMER2_MODULE_)
		setup_atmega328.tc2_enable = tc2_enable;
		setup_atmega328.tc2 = tc2();
	#endif
	// TWI
	setup_atmega328.twi_handle = twi_handle();
	#if defined(_TWI_MODULE_)
		setup_atmega328.twi_enable = twi_enable;
		setup_atmega328.twi = twi();
	#endif
	// USART
	setup_atmega328.usart0_handle = usart0_handle();
	#if defined(_USART0_MODULE_)
		setup_atmega328.usart0_enable = usart0_enable;
	#endif
	// WDT
	setup_atmega328.wdt_handle = wdt_handle();
	/******/
	setup_atmega328.Clock_Prescaler_Select = Atmega328ClockPrescalerSelect;
	setup_atmega328.Move_Interrupts_To_Boot = Atmega328MoveInterruptsToBoot;
	
	return setup_atmega328;
}

ATMEGA328* atmega328(void){ return &setup_atmega328; }

/******
1º Sequence
2º Scope
3º Pointer and Variable
4º Casting
******/

/*** EOF ***/

