/******************************************************************************
	STM32 FXXX RCC
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-FXXX
Date: 07032024
Comment:
	
*******************************************************************************/
#ifndef _STM32FXXXRCC_H_
	#define _STM32FXXXRCC_H_
/*** Library ***/
#include "stm32fxxxhandler.h"
#include "armquery.h"
/*** Define & Macros***/
#ifndef on
	#define on 1
#endif
#ifndef off
	#define off 0
#endif
#ifndef yes
	#define yes 1
#endif
#ifndef no
	#define no 0
#endif
/*** RCC_Common TypeDef ***/
// RCC -> PLL
typedef struct
{
	void (*division)(uint8_t pllm, uint16_t plln, uint8_t pllp, uint8_t pllq);
	void (*enable)(void);
}STM32FXXXRCCPLL;
// RCC -> PLLI2S
typedef struct
{
	void (*enable)(void);
}STM32FXXXRCCPLLI2S;
// RCC -> PLLSAI
typedef struct
{
	void (*enable)(void);
}STM32FXXXRCCPLLSAI;
/*** RCC TypeDef ***/
typedef struct
{

	/*** Bit Mapping ***/
	STM32FXXXRCC_TypeDef* handle;
	void (*prescaler)(uint16_t ahbpre, uint8_t ppre1, uint8_t ppre2, uint8_t rtcpre);
	/*** Extended ***/
	STM32FXXXRCCPLL* pll;
	STM32FXXXRCCPLLI2S* plli2s;
	STM32FXXXRCCPLLSAI* pllsai;
	/*** Other ***/
	void (*inic)(void);
	void (*henable)(uint8_t hclock);
	uint8_t (*hselect)(uint8_t sysclk);
	void (*lenable)(uint8_t lclock);
	void (*lselect)(uint8_t lclock);

	void (*nvic)(uint8_t bool);
}STM32FXXX_RCC;

STM32FXXX_RCC* rcc_enable(void);
STM32FXXX_RCC* rcc(void);

/*** Procedure & Function Header ***/
void STM32FXXXRCC_nvic(uint8_t bool);
/*** RCC Procedure & Function Header ***/
// PLL
void STM32FXXXPLLDivision(uint8_t pllm, uint16_t plln, uint8_t pllp, uint8_t pllq);
void STM32FXXXRccPLLCLKEnable(void);
void STM32FXXXRccPLLI2SEnable(void);
void STM32FXXXRccPLLSAIEnable(void);
// RCC
void rcc_start(void);
void STM32FXXXRccHEnable(uint8_t hclock);
uint8_t STM32FXXXRccHSelect(uint8_t hclock);
void STM32FXXXRccLEnable(uint8_t lclock);
void STM32FXXXRccLSelect(uint8_t lclock);
void STM32FXXXPrescaler(uint16_t ahbpre, uint8_t ppre1, uint8_t ppre2, uint8_t rtcpre);

/*** INTERRUPT HEADER ***/
void RCC_IRQHandler(void);

#endif

/*** EOF ***/

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

