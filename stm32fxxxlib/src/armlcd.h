/************************************************************************
	ARMLCD
Author: Sergio Santos 
   <sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32
Date: 12112022
Comment:
	STM32F446RE
	- Make sure the delay are working in the inic function.
************************************************************************/
#ifndef _ARMLCD_H_
	#define _ARMLCD_H_

/*** Global Library ***/
//#include <util/delay.h> // if use AVR ATMEL
#include "armquery.h"
#include "armsystick.h"
#include <inttypes.h>

/*** Global Constant & Macro ***/
// ASIGN PORT PINS TO LCD (can be setup in any way)
#define ARMLCD0_RS 3
#define ARMLCD0_RW 4
#define ARMLCD0_EN 5
#define ARMLCD0_NC 10
#define ARMLCD0_DB4 6
#define ARMLCD0_DB5 7
#define ARMLCD0_DB6 8
#define ARMLCD0_DB7 9

/*** ARM LCD ***/
typedef struct
{
	void (*write)(char c, unsigned short D_I);
	char (*read)(unsigned short D_I);
	void (*BF)(void);
	void (*putch)(char c);
	char (*getch)(void);
	void (*string)(const char *s); // RAW
	void (*string_size)(const char* s, uint32_t size); // RAW
	void (*hspace)(uint32_t n);
	void (*clear)(void);
	void (*gotoxy)(unsigned int y, unsigned int x);
	void (*reboot)(void);
}ARMLCD0;

ARMLCD0 ARMLCD0_enable(GPIO_TypeDef* reg);
ARMLCD0* lcd0(void);

#endif

/***EOF***/

/******
1º Sequence
2º Scope
	- Library Scope
	- File Scope
	- Function Scope
	- Precedence Scope
3º Pointer and Variable
4º Casting
******/

