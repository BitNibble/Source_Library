/************************************************************************
	ATMEGA Query
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega
Update:	14/01/2024
************************************************************************/
/****** Comment: 
	Simple tools
************************************************************************/
#include "query.h"

/*** Procedure & Function Definition***/
uint8_t readreg(uint8_t reg, uint8_t size_block, uint8_t bit_n)
{
	if(bit_n > 7){ bit_n = 0;} if(size_block > 8){ size_block = 8;}
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	reg &= (mask << bit_n);
	reg = (reg >> bit_n);
	return reg;
}
uint8_t getsetbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n)
{
	uint8_t n = 0;
	if(bit_n > 7){ n = bit_n/8; bit_n = bit_n - (n * 8); } if(size_block > 8){ size_block = 8;}
	uint8_t value = *(reg + n ); uint8_t mask = (unsigned int)((1 << size_block) - 1);
	value &= (mask << bit_n);
	value = (value >> bit_n);
	return value;
}
void setreg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data)
{
	if(bit_n > 7){ bit_n = 0;} if(size_block > 8){ size_block = 8;}
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask;
	*reg &= ~(mask << bit_n);
	*reg |= (data << bit_n);
}
void setbit(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data)
{
	uint8_t n = 0;
	if(bit_n > 7){ n = bit_n/8; bit_n = bit_n - (n * 8); } if(size_block > 8){ size_block = 8;}
	uint8_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask;
	*(reg + n ) &= ~(mask << bit_n);
	*(reg + n ) |= (data << bit_n);
}
void writereg(volatile uint8_t* reg, uint8_t size_block, uint8_t bit_n, uint8_t data)
{
	if(bit_n > 7){ bit_n = 0;} if(size_block > 8){ size_block = 8;}
	uint8_t value = *reg; uint8_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask; value &= ~(mask << bit_n);
	data = (data << bit_n);
	value |= data;
	*reg = value;
}
uint16_t readhlbyte(HighLowByte reg)
{
	return (reg.H << 8) | reg.L;
}
uint16_t readlhbyte(HighLowByte reg)
{
	return (reg.L << 8) | reg.H;
}
HighLowByte writehlbyte(uint16_t val)
{
	HighLowByte reg; reg.H = (val >> 8); reg.L = val;
	return reg;
}
HighLowByte writelhbyte(uint16_t val)
{
	HighLowByte reg; reg.L = (val >> 8); reg.H = val;
	return reg;
}
uint16_t swapbyte(uint16_t num)
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

/*** EOF ***/

