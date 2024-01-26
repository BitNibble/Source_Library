/************************************************************************
	EXPLODE
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: all
Date: 16032021
Comment:
	Tested Atemga128 16Mhz and Atmega328 8Mhz and STM32F446RE
************************************************************************/
#ifndef _EXPLODE_H_
	#define _EXPLODE_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#if defined (STM32F446xx)
	#ifndef IO_var
		#define IO_var uint32_t
	#endif
#else
	#ifndef IO_var
		#define IO_var uint8_t
	#endif
#endif

/*** Global TypeDef ***/
typedef struct {
	IO_var XI;
	IO_var XF;
	IO_var HH;
	IO_var LL;
	IO_var LH;
	IO_var HL;
}explode_parameter;

/*** EXPLODE ***/
typedef struct {
	/***Variable***/
	explode_parameter par;
	// PROTOTYPES VTABLE
	void (*update)(explode_parameter* par, IO_var x);
}EXPLODE;

EXPLODE explode_enable(void);

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


