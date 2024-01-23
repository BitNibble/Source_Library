/*********************************************************
	ATMEGA Query
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega
Update:	14/01/2024
**********************************************************/
/****** Comment: 
	Simple tools
**********************************************************/
#ifndef _QUERY_H_
	#define _QUERY_H_

/*** Working Frequency ***/
#ifndef F_CPU
	#define F_CPU 16000000UL
#endif

#define __AVR_ATmega328p__

#include <avr/io.h>
#include <avr/fuse.h>
#include <avr/pgmspace.h>
#include <avr/interrupt.h>
#include <inttypes.h>
#include <string.h>
#include <math.h>

#include "atmega328.h"

/*** Procedure and Function Prototypes ***/
uint8_t readreg(uint8_t reg, uint8_t size_block, uint8_t bit_n);
uint8_t getsetbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n);
void setreg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
void setbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
void writereg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data);
uint16_t readhlbyte(HighLowByte reg);
uint16_t readlhbyte(HighLowByte reg);
HighLowByte writehlbyte(uint16_t val);
HighLowByte writelhbyte(uint16_t val);
uint16_t swapbyte(uint16_t num);
uint16_t BAUDRATEnormal(uint32_t BAUD);
uint16_t BAUDRATEdouble(uint32_t BAUD);
uint16_t BAUDRATEsynchronous(uint32_t BAUD);

#endif

/*** EOF ***/

