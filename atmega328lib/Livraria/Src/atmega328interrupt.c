/*************************************************************************
	Atmega 328 Interrupt
Author: Sergio Manuel Santos
		<sergio.salazar.santos@gmail.com>
Hardware: ATmega328
License: GNU General Public License        
Update: 01/01/2024
*************************************************************************/
/****** Comment:

*************************************************************************/
/*** File Library ***/
#include "atmega328mapping.h"
#include "atmega328interrupt.h"
#include <stdarg.h>

/*** File Constant & Macro ***/

/*** File Variable ***/
static struct intrpt setup_interrupt;
/*** File Header ***/
void INTERRUPT_set(uint8_t channel, uint8_t sense);
void INTERRUPT_off(uint8_t channel);
uint8_t INTERRUPT_reset_status(void);

/*** Procedure and Function ***/
INTERRUPT INTERRUPT_enable(void)
// setup blank
{
	// Pre-Processor Case 1
	atmega328()->exint_imask->eimsk = 0X00;
	
	setup_interrupt.set = INTERRUPT_set;
	setup_interrupt.off = INTERRUPT_off;
	setup_interrupt.reset_status = INTERRUPT_reset_status;

	return setup_interrupt;
}

INTERRUPT* exint(void){ return &setup_interrupt; };

uint8_t INTERRUPT_reset_status(void)
{
	uint8_t reset, ret = 0;
	reset = (atmega328()->cpu_reg->mcusr & MCU_Control_Status_Register_Mask);
	switch(reset){
		case 1: // Power-On Reset Flag
			ret = 0;
			atmega328()->cpu_reg->mcusr &= ~(1 << PORF);
			break;
		case 2: // External Reset Flag
			atmega328()->cpu_reg->mcusr &= ~(1 << EXTRF);
			ret = 1;
			break;
		case 4: // Brown-out Reset Flag
			atmega328()->cpu_reg->mcusr &= ~(1 << BORF);
			ret = 2;
			break;
		case 8: // Watchdog Reset Flag
			atmega328()->cpu_reg->mcusr &= ~(1 << WDRF);
			ret = 3;
			break;
		default: // clear all status
			atmega328()->cpu_reg->mcusr &= ~(MCU_Control_Status_Register_Mask);
			break;
	}
	
	return ret;
}
void INTERRUPT_set(uint8_t channel, uint8_t sense)
{
	switch( channel ){
		case 0: 
			atmega328()->exint_imask->eimsk &= ~(1 << INT0);
			atmega328()->exint_reg->eicra &= ~((1 << ISC01) | (1 << ISC00));
			switch(sense){
				case 0: // The low level of INT0 generates an interrupt request.
				case 1: // Any logical change on INT0 generates an interrupt request.
					break;
				case 2: // The falling edge of INT0 generates an interrupt request.
					atmega328()->exint_reg->eicra |= (1 << ISC01);
					break;
				case 3: // The rising edge of INT0 generates an interrupt request.
					atmega328()->exint_reg->eicra |= ((1 << ISC01) | (1 << ISC00));
					break;
				default: // The low level of INT0 generates an interrupt request.
					break;
			}
			atmega328()->exint_imask->eimsk |= (1 << INT0);
			break;
		case 1:
			atmega328()->exint_imask->eimsk &= ~(1 << INT1);
			atmega328()->exint_reg->eicra &= ~((1 << ISC11) | (1 << ISC10));
			switch(sense){
				case 0: // The low level of INT1 generates an interrupt request.
				case 1: // Any logical change on INT1 generates an interrupt request.
					break;
				case 2: // The falling edge of INT1 generates an interrupt request.
					atmega328()->exint_reg->eicra |= (1 << ISC11);
					break;
				case 3: // The rising edge of INT1 generates an interrupt request.
					atmega328()->exint_reg->eicra |= ((1 << ISC11) | (1 << ISC10));
					break;
				default: // The low level of INT1 generates an interrupt request.
					break;
			}
			atmega328()->exint_imask->eimsk |= (1 << INT1);
			break;
		default:
			atmega328()->exint_imask->eimsk = 0X00;
			break;
	}
}
void INTERRUPT_off(uint8_t channel)
{
	switch( channel ){
		case 0: // disable
			atmega328()->exint_imask->eimsk &= ~(1 << INT0);
			break;
		case 1: // disable
			atmega328()->exint_imask->eimsk &= ~(1 << INT1);
			break;
		default: // all disable
			atmega328()->exint_imask->eimsk = 0X00;
			break;
	}
}

/***EOF***/

