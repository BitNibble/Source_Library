/********************************************************************
	ATMEGA 328 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update: 01/01/2024
*********************************************************************/
/****** Comment: 
	Virtual Image Atmega 328 mapping.
	NB:
	- This Header file should be the first to be placed
*********************************************************************/
#ifndef _ATMEGA328MAPPING_H_
	#define _ATMEGA328MAPPING_H_
	
#include "query.h"

/*********************************************************/
/****************** Include Switches  ********************/
/*********************************************************/
// User may Comment out if not in use
// MODULES
//#define _ANALOG_MODULE_
//#define _EEPROM_MODULE_
//#define _INTERRUPT_MODULE_
//#define _TIMER0_MODULE_
#define _TIMER1_MODULE_
//#define _TIMER2_MODULE_
//#define _TWI_MODULE_
//#define _SPI_MODULE_
#define _USART0_MODULE_
/*********************************************************/
/******************* Hardware Includes *******************/
/*********************************************************/
// MODULES
#ifdef _ANALOG_MODULE_
	#include "atmega328analog.h"
//#else
//	#warning "NO ANALOG MODULE"
#endif
#ifdef _EEPROM_MODULE_
	#include "atmegaeeprom.h"
//#else
//	#warning "NO EEPROM MODULE"
#endif
#ifdef _INTERRUPT_MODULE_
	#include "atmega328interrupt.h"
//#else
//	#warning "NO INTERRUPT MODULE"
#endif
#ifdef _TIMER0_MODULE_
	#include "atmega328timer0.h"
//#else
//	#warning "NO TIMER MODULE"
#endif
#ifdef _TIMER1_MODULE_
	#include "atmega328timer1.h"
//#else
//	#warning "NO TIMER MODULE"
#endif
#ifdef _TIMER2_MODULE_
	#include "atmega328timer2.h"
//#else
//	#warning "NO TIMER MODULE"
#endif
#ifdef _TWI_MODULE_
	#include "atmega328twi.h"
//#else
//	#warning "NO TWI MODULE"
#endif
#ifdef _SPI_MODULE_
	#include "atmega328spi.h"
//#else
//	#warning "NO SPI MODULE"
#endif
#ifdef _USART0_MODULE_
	#include "atmega328usart0.h"
//#else
//	#warning "NO UART MODULE"
#endif
/*******************************************************************/
/************************* ATMEGA 328 IMAGE ************************/
/*************************** Third Layer ***************************/
/*******************************************************************/
typedef struct {
	//		Second Layer
	Atmega328GPWR_TypeDef* gpwr_reg;
	/************************************/
	Atmega328AnalogComparator_TypeDef* ac_reg;
	Atmega328AnalogComparatorDid_TypeDef* ac_didr1;
	/************************************/
	Atmega328AnalogToDigitalConverter_TypeDef* adc_reg;
	#ifdef _ANALOG_MODULE_
		ANALOG (*adc_enable)( uint8_t Vreff, uint8_t Divfactor, int n_channel, ... );
		ANALOG* adc;
	#endif
	/************************************/
	Atmega328CPURegister_TypeDef* cpu_reg;
	Atmega328CpuGeneralPurposeIoRegister_TypeDef* cpu_gpio;
	/************************************/
	Atmega328Eeprom_TypeDef* eeprom_reg;
	#ifdef _EEPROM_MODULE_
		EEPROM (*eeprom_enable)(void);
		EEPROM* eeprom;
	#endif
	/************************************/
	Atmega328ExternalInterrupt_TypeDef* exint_reg;
	Atmega328ExternalInterruptFlag_TypeDef* exint_iflag;
	Atmega328ExternalInterruptMask_TypeDef* exint_imask;
	#ifdef _INTERRUPT_MODULE_
		INTERRUPT (*exint_enable)(void);
		INTERRUPT* exint;
	#endif
	/************************************/
	Atmega328PORTB_TypeDef* portb_reg;
	/************************************/
	Atmega328PORTC_TypeDef* portc_reg;
	/************************************/
	Atmega328PORTD_TypeDef* portd_reg;
	/************************************/
	Atmega328SerialPeripherialInterface_TypeDef* spi_reg;
	#ifdef _SPI_MODULE_
		SPI (*spi_enable)(uint8_t master_slave_select, uint8_t data_order,  uint8_t data_modes, uint8_t prescaler);
		SPI* spi;
	#endif
	/************************************/
	Atmega328TwoWireSerialInterface_TypeDef* twi_reg;
	#ifdef _TWI_MODULE_
		TWI (*twi_enable)(uint8_t atmega_ID, uint8_t prescaler);
		TWI* twi;
	#endif
	/************************************/
	Atmega328Usart_TypeDef* usart0_reg;
	#ifdef _USART0_MODULE_
		USART0 (*usart0_enable)(uint32_t baudrate, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity );
		USART0* usart0;
	#endif
	/************************************/
	Atmega328WatchdogTimer_TypeDef* wdt_reg;
	/************************************/
	Atmega328TimerCounter2_TypeDef* tc2_reg;
	Atmega328TimerGeneralControlRegister_TypeDef* tc2_gcr;
	Atmega328TimerInterruptFlag_TypeDef* tc2_iflag;
	Atmega328TimerInterruptMask_TypeDef* tc2_imask;
	Atmega328TimerCompareRegister2_TypeDef* tc2_comp;
	#ifdef _TIMER2_MODULE_
		TIMER_COUNTER2 (*tc2_enable)(unsigned char wavegenmode, unsigned char interrupt);
		TIMER_COUNTER2* tc2;
	#endif
	/************************************/
	Atmega328TimerCounter1_TypeDef* tc1_reg;
	Atmega328TimerGeneralControlRegister_TypeDef* tc1_gcr;
	Atmega328TimerInterruptFlag_TypeDef* tc1_iflag;
	Atmega328TimerInterruptMask_TypeDef* tc1_imask;
	Atmega328TimerCompareRegister1_TypeDef* tc1_comp;
	#ifdef _TIMER1_MODULE_
		TIMER_COUNTER1 (*tc1_enable)(unsigned char wavegenmode, unsigned char interrupt);
		TIMER_COUNTER1* tc1;
	#endif
	/************************************/
	Atmega328TimerCounter0_TypeDef* tc0_reg;
	Atmega328TimerGeneralControlRegister_TypeDef* tc0_gcr;
	Atmega328TimerInterruptFlag_TypeDef* tc0_iflag;
	Atmega328TimerInterruptMask_TypeDef* tc0_imask;
	Atmega328TimerCompareRegister0_TypeDef* tc0_comp;
	#ifdef _TIMER0_MODULE_
		TIMER_COUNTER0 (*tc0_enable)( unsigned char wavegenmode, unsigned char interrupt );
		TIMER_COUNTER0* tc0;
	#endif
	/***********************************/
	void (*Clock_Prescaler_Select)(volatile uint8_t prescaler);
	void (*Move_Interrupts_To_Boot)(void);
}ATMEGA328;

ATMEGA328 ATMEGA328_enable(void);
ATMEGA328* atmega328(void);

#endif

/***EOF***/

/*** Interrupt List ***/
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
// ISR(ADC_vect)
// ISR(ANALOG_COMP_vect){}
// ISR(TWI_vect){}
// ISR(SPM_READY_vect){}
// ISR(USART_RX_vect){}
// ISR(USART_UDRE_vect){}
// ISR(USART_TX_vect){}

