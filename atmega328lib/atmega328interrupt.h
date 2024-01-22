/************************************************************************
	Atmega 328 Interrupt
Author: Sergio Manuel Santos
		<sergio.salazar.santos@gmail.com>
Hardware: ATmega328
License: GNU General Public License 
Update: 01/01/2024
Comment:

************************************************************************/
#ifndef _ATMEGA328INTERRUPT_H_
	#define _ATMEGA328INTERRUPT_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macros ***/
//#define External_Interrupt_Flag_Register EIFR
//#define Pin_Change_Interrrupt_Control_Register PCICR
//#define Pin_Change_Interrupt_Flag_Register PCIFR
//#define Pin_Change_Mask_Register_2 PCMSK2
//#define Pin_Change_Mask_Register_1 PCMSK1
//#define Pin_Change_Mask_Register_0 PCMSK0
//#define MCU_Control_Status_Register MCUSR
#define MCU_Control_Status_Register_Mask 0X0F

/*** Global Variable ***/
struct intrpt{
	void (*set)(uint8_t channel, uint8_t sense);
	void (*off)(uint8_t channel);
	uint8_t (*reset_status)(void);
};
typedef struct intrpt INTERRUPT;

INTERRUPT INTERRUPT_enable(void);
INTERRUPT* exint(void);

#endif

/***EOF***/


/*** File Interrupt ***/
// ISR(INT0_vect){}
// ISR(INT1_vect){}

