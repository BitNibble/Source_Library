/*************************************************************************
	ARMQUERY
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License     
Hardware: STM32QUERY
Date: 10/01/2024
Update: 
Comment:
	Tested STM32F446RE and STM32F411CEU6
************************************************************************/
#ifndef _ARMQUERY_H_
	#define _ARMQUERY_H_

// SELECTION OF CHIP (CMSIS Access to its libraries)
#ifndef STM32F411xE
	#define STM32F411xE
#endif
#include "stm32f4xx.h"
#include <inttypes.h>

#ifndef HSI_RC
	#define HSI_RC 16000000UL
#endif
#ifndef HSE_OSC
	#define HSE_OSC 25000000UL
#endif

typedef struct{
uint16_t (*AHB)(void);
uint8_t (*APB1)(void);
uint8_t (*APB2)(void);
uint8_t (*RTCclk)(void);
uint8_t (*MCO1)(void);
uint8_t (*MCO2)(void);
}STM32FXXXCLOCK_prescaler;
typedef struct{
uint8_t (*M)(void);
uint16_t (*N)(void);
uint8_t (*P)(void);
uint8_t (*Q)(void);
uint8_t (*R)(void);
}STM32FXXXPLL_parameter;
typedef struct{
STM32FXXXCLOCK_prescaler* CLOCK_prescaler;
STM32FXXXPLL_parameter* PLL_parameter;
uint32_t (*ClockSource)(void);
uint32_t (*PllSource)(void);
uint32_t (*SystemClock)(void);
}STM32FXXXQuery;

uint32_t readreg(uint32_t reg, uint8_t size_block, uint8_t bit_n);
uint32_t getsetbit(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n);
void setreg(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data);
void setbit(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data);
void writereg(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data);
void setpin( GPIO_TypeDef* reg, int pin );
void resetpin( GPIO_TypeDef* reg, int pin );

uint32_t getclocksource(void);
uint32_t getpllsource(void);
uint16_t gethpre(void);
uint8_t gethppre1(void);
uint8_t gethppre2(void);
uint8_t getrtcpre(void);
uint8_t gethmco1pre(void);
uint8_t gethmco2pre(void);
uint8_t getpllm(void);
uint16_t getplln(void);
uint8_t getpllp(void);
uint8_t getpllq(void);
uint8_t getpllr(void);
uint32_t getsysclk(void);

STM32FXXXQuery query_enable(void);
STM32FXXXQuery* query(void);

#endif

/***EOF***/
