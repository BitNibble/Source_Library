/*************************************************************************
	STM32QUERY
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License     
Hardware: STM32QUERY
Date: 10/01/2024
Update: 
Comment:
	Tested STM32F446RE and STM32F411CEU6
************************************************************************/
#include "armquery.h"
#include <stdarg.h>
#include <math.h>

static STM32FXXXQuery stm32fxxx_query;
static STM32FXXXCLOCK_prescaler stm32fxxx_CLOCK_prescaler;
static STM32FXXXPLL_parameter stm32fxxx_PLL_parameter;


STM32FXXXCLOCK_prescaler* CLOCK_prescaler_inic(void);
STM32FXXXPLL_parameter* PLL_parameter_inic(void);

uint32_t getclocksource(void)
{
	uint32_t reg = RCC->CR;
	uint32_t source;
	if(reg & (1 << 1)){source = HSI_RC;} else if(reg & (1 << 17)){source = HSE_OSC;}
	return source;
}
uint32_t getpllsource(void)
{
	uint32_t reg = RCC->CFGR;
	uint32_t source;
	if(reg & (1 << 22)) source = HSE_OSC; else source = HSI_RC;
	return source;
}
uint16_t gethpre(void)
{
	uint32_t value = readreg(RCC->CFGR, 4, 4);
	switch(value)
	{
		case 0b1000:
			value = 2;
		break;
		case 0b1001:
			value = 4;
		break;
		case 0b1010:
			value = 8;
		break;
		case 0b1011:
			value = 16;
		break;
		case 0b1100:
			value = 64;
		break;
		case 0b1101:
			value = 128;
		break;
		case 0b1110:
			value = 256;
		break;
		case 0b1111:
			value = 512;
		break;
		default:
			value = 1;
		break;
	}
	return value;
}
uint8_t gethppre1(void)
{
	uint32_t value = readreg(RCC->CFGR, 3, 10);
	switch(value)
	{
		case 0b100:
			value = 2;
		break;
		case 0b101:
			value = 4;
		break;
		case 0b110:
			value = 8;
		break;
		case 0b111:
			value = 16;
		break;
		default:
			value = 1;
		break;
	}
	return value;
}
uint8_t gethppre2(void)
{
	uint32_t value = readreg(RCC->CFGR, 3, 13);
	switch(value)
	{
		case 0b100:
			value = 2;
		break;
		case 0b101:
			value = 4;
		break;
		case 0b110:
			value = 8;
		break;
		case 0b111:
			value = 16;
		break;
		default:
			value = 1;
		break;
	}
	return value;
}
uint8_t getrtcpre(void)
{
	return readreg(RCC->CFGR, 5, 16);
}
uint8_t gethmco1pre(void)
{
	uint32_t value = readreg(RCC->CFGR, 3, 24);
	switch(value)
	{
		case 0b100:
			value = 2;
		break;
		case 0b101:
			value = 3;
		break;
		case 0b110:
			value = 4;
		break;
		case 0b111:
			value = 5;
		break;
		default:
			value = 1;
		break;
	}
	return value;
}
uint8_t gethmco2pre(void)
{
	uint32_t value = readreg(RCC->CFGR, 3, 27);
	switch(value)
	{
		case 0b100:
			value = 2;
		break;
		case 0b101:
			value = 3;
		break;
		case 0b110:
			value = 4;
		break;
		case 0b111:
			value = 5;
		break;
		default:
			value = 1;
		break;
		}
	return value;
}
uint8_t getpllm(void)
{
	return readreg(RCC->PLLCFGR, 6, 0);
}
uint16_t getplln(void)
{
	return readreg(RCC->PLLCFGR, 9, 6);
}
uint8_t getpllp(void)
{
	uint32_t value = readreg(RCC->PLLCFGR, 2, 16);
	switch(value)
	{
		case 0b00:
			value = 2;
		break;
		case 0b01:
			value = 4;
		break;
		case 0b10:
			value = 6;
		break;
		case 0b11:
			value = 8;
		break;
		default:
		break;
	}
	return value;
}
uint8_t getpllq(void)
{
	return readreg(RCC->PLLCFGR, 4, 24);
}
uint8_t getpllr(void)
{
	return readreg(RCC->PLLCFGR, 3, 28);
}
uint32_t getsysclk(void)
{
	long value = readreg(RCC->CFGR, 2, 2);
	switch(value) // SWS[2]: System clock switch status
	{
		case 1: // 01: HSE oscillator used as the system clock
			value = HSE_OSC;
		break;
		case 2: // 10: PLL used as the system clock
			value = getclocksource() / getpllm();
			value /= getpllp();
			value *= getplln();
		break;
		case 3: // 11: PLL_R used as the system clock
			value = getclocksource() / getpllm();
			value /= getpllr();
			value *= getplln();
		break;
		default: // 00: HSI oscillator used as the system clock
			value = HSI_RC;
		break;
	}
	return (uint32_t)value;
}
STM32FXXXCLOCK_prescaler* CLOCK_prescaler_inic(void)
{
	stm32fxxx_CLOCK_prescaler.AHB = gethpre;
	stm32fxxx_CLOCK_prescaler.APB1 = gethppre1;
	stm32fxxx_CLOCK_prescaler.APB2 = gethppre2;
	stm32fxxx_CLOCK_prescaler.RTCclk = getrtcpre;
	stm32fxxx_CLOCK_prescaler.MCO1 = gethmco1pre;
	stm32fxxx_CLOCK_prescaler.MCO2 = gethmco2pre;
	return &stm32fxxx_CLOCK_prescaler;
}
STM32FXXXPLL_parameter* PLL_parameter_inic(void)
{
	stm32fxxx_PLL_parameter.M = getpllm;
	stm32fxxx_PLL_parameter.N = getplln;
	stm32fxxx_PLL_parameter.P = getpllp;
	stm32fxxx_PLL_parameter.Q = getpllq;
	stm32fxxx_PLL_parameter.R = getpllr;
	return &stm32fxxx_PLL_parameter;
}
STM32FXXXQuery query_enable(void)
{
	stm32fxxx_query.CLOCK_prescaler = CLOCK_prescaler_inic();
	stm32fxxx_query.PLL_parameter = PLL_parameter_inic();
	stm32fxxx_query.ClockSource = getclocksource;
	stm32fxxx_query.PllSource = getpllsource;
	stm32fxxx_query.SystemClock = getsysclk;
	return stm32fxxx_query;
}

STM32FXXXQuery* query(void){ return &stm32fxxx_query; }

uint32_t readreg(uint32_t reg, uint8_t size_block, uint8_t bit_n)
{
	if(bit_n > 31){ bit_n = 0;} if(size_block > 32){ size_block = 32;}
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	reg &= (mask << bit_n);
	reg = (reg >> bit_n);
	return reg;
}
uint32_t getsetbit(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n)
{
	uint32_t n = 0;
	if(bit_n > 31){ n = bit_n/32; bit_n = bit_n - (n * 32); } if(size_block > 32){ size_block = 32;}
	uint32_t value = *(reg + n );
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	value &= (mask << bit_n);
	value = (value >> bit_n);
	return value;
}
void setreg(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data)
{
	if(bit_n > 31){ bit_n = 0;} if(size_block > 32){ size_block = 32;}
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask;
	*reg &= ~(mask << bit_n);
	*reg |= (data << bit_n);
}
void setbit(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data)
{
	uint32_t n = 0;
	if(bit_n > 31){ n = bit_n/32; bit_n = bit_n - (n * 32); } if(size_block > 32){ size_block = 32;}
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask;
	*(reg + n ) &= ~(mask << bit_n);
	*(reg + n ) |= (data << bit_n);
}
void writereg(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data)
{
	if(bit_n > 31){ bit_n = 0;} if(size_block > 32){ size_block = 32;}
	uint32_t value = *reg;
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	data &= mask; value &= ~(mask << bit_n);
	data = (data << bit_n);
	value |= data;
	*reg = value;
}
void STM32446RegSetBits( unsigned int* reg, int n_bits, ... )
{
	uint8_t i;
	if(n_bits > 0 && n_bits < 33){ // Filter input
		va_list list;
		va_start(list, n_bits);
		for(i = 0; i < n_bits; i++){
			*reg |= (unsigned int)(1 << va_arg(list, int));
		}
		va_end(list);
	}
}
void STM32446RegResetBits( unsigned int* reg, int n_bits, ... )
{
	uint8_t i;
	if(n_bits > 0 && n_bits < 33){ // Filter input
		va_list list;
		va_start(list, n_bits);
		for(i = 0; i < n_bits; i++){
			*reg &= (unsigned int)~((1 << va_arg(list, int)) << 16);
		}
		va_end(list);
	}
}
void STM32446VecSetup( volatile uint32_t vec[], const unsigned int size_block, unsigned int data, unsigned int block_n )
{
	const unsigned int n_bits = sizeof(data) * 8;
	const unsigned int mask = (unsigned int) (pow(2, size_block) - 1);
	unsigned int index = (block_n * size_block) / n_bits;
	data &= mask;
	vec[index] &= ~( mask << ((block_n * size_block) - (index * n_bits)) );
	vec[index] |= ( data << ((block_n * size_block) - (index * n_bits)) );
}
void setpin( GPIO_TypeDef* reg, int pin )
{
	reg->BSRR = (1 << pin);
}
void resetpin( GPIO_TypeDef* reg, int pin )
{
	reg->BSRR = (unsigned int)((1 << pin) << 16);
}

/***EOF***/

