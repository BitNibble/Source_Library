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
/*** wrapper ***/
#include "stm32gpiobf.h"
#include "stm32rccbf.h"
#include "stm32timbf.h"
/******/
#include <inttypes.h>

#ifndef HSI_RC
	#define HSI_RC 16000000UL
#endif
#ifndef HSE_OSC
	#define HSE_OSC 25000000UL
#endif

/*******   0 -> HSI    1->HSE   *********/
#define H_Clock_Source 1
/****************************************/
/****   PLL ON -> 1    PLL OFF = 0   ****/
#define PLL_ON_OFF 0
/****************************************/
volatile typedef union{
	struct UN32nibble{
		uint32_t n0:4;
		uint32_t n1:4;
		uint32_t n2:4;
		uint32_t n3:4;
		uint32_t n4:4;
		uint32_t n5:4;
		uint32_t n6:4;
		uint32_t n7:4;
		}nibble;
	struct UN32byte{
		uint8_t b0;
		uint8_t b1;
		uint8_t b2;
		uint8_t b3;
	}byte;
	struct UN32word{
		uint16_t w0;
		uint16_t w1;
	}word;
	uint32_t n;
}_UN32var;
volatile typedef union{
	struct UN64nibble{
		uint32_t n0:4;
		uint32_t n1:4;
		uint32_t n2:4;
		uint32_t n3:4;
		uint32_t n4:4;
		uint32_t n5:4;
		uint32_t n6:4;
		uint32_t n7:4;
		uint32_t n8:4;
		uint32_t n9:4;
		uint32_t n10:4;
		uint32_t n11:4;
		uint32_t n12:4;
		uint32_t n13:4;
		uint32_t n14:4;
		uint32_t n15:4;
	}nibble;
	struct UN64byte{
		uint8_t b0;
		uint8_t b1;
		uint8_t b2;
		uint8_t b3;
		uint8_t b4;
		uint8_t b5;
		uint8_t b6;
		uint8_t b7;
	}byte;
	struct UN64word{
		uint16_t w0;
		uint16_t w1;
		uint16_t w2;
		uint16_t w3;
	}word;
	struct UN64dword{
		uint32_t d0;
		uint32_t d1;
	}dword;
	uint64_t n;
}_UN64var;

typedef struct{
uint16_t (*AHB)(void);
uint8_t (*APB1)(void);
uint8_t (*APB2)(void);
uint8_t (*RTCclk)(void);
uint8_t (*MCO1)(void);
uint8_t (*MCO2)(void);
}STM32FXXXSYSTEM_prescaler;
typedef struct{
uint8_t (*M)(void);
uint16_t (*N)(void);
uint8_t (*P)(void);
uint8_t (*Q)(void);
uint8_t (*R)(void);
}STM32FXXXPLL_prescaler;
typedef struct{
STM32FXXXSYSTEM_prescaler* System_prescaler;
STM32FXXXPLL_prescaler* Pll_prescaler;
uint32_t (*PllClock)(void);
uint32_t (*SystemClock)(void);
}STM32FXXXQuery;

uint32_t readreg(uint32_t reg, uint8_t size_block, uint8_t bit_n);
void writereg(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data);
void setreg(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data);
uint32_t getreg(uint32_t reg, uint8_t size_block, uint8_t bit_n);
uint32_t getsetbit(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n);
void setbit(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n, uint32_t data);
uint32_t getbit(volatile uint32_t* reg, uint8_t size_block, uint8_t bit_n);
void setregposmsk(volatile uint32_t* reg, uint32_t msk, uint8_t pos, uint32_t data);
uint32_t getregposmsk(uint32_t reg, uint32_t msk, uint8_t pos);
void sethpins( GPIO_TypeDef* reg, uint16_t hpins );
void resethpins( GPIO_TypeDef* reg, uint16_t hpins );
void setpin( GPIO_TypeDef* reg, uint8_t pin );
void resetpin( GPIO_TypeDef* reg, uint8_t pin );

uint32_t getpllclk(void);
uint32_t getsysclk(void);

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

STM32FXXXGPIOX_TypeDef* gpioa_handle(void);
STM32FXXXRCC_TypeDef* rcc_handle(void);
STM32FXXXTIMXX_TypeDef* tim1_handle(void);

STM32FXXXQuery query_enable(void);
STM32FXXXQuery* query(void);

#endif

/***EOF***/

