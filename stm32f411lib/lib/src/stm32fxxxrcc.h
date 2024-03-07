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
#include "armquery.h"
#include "stm32rccbf.h"
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
	STM32FXXXRCC_CR_TypeDef* cr;
	STM32FXXXRCC_PLLCFGR_TypeDef* pllcfgr;
	STM32FXXXRCC_CFGR_TypeDef* cfgr;
	STM32FXXXRCC_CIR_TypeDef* cir;
	STM32FXXXRCC_AHB1RSTR_TypeDef* ahb1rstr;
	STM32FXXXRCC_AHB2RSTR_TypeDef* ahb2rstr;
	STM32FXXXRCC_AHB3RSTR_TypeDef* ahb3rstr;
	STM32FXXXRCC_APB1RSTR_TypeDef* apb1rstr;
	STM32FXXXRCC_APB2RSTR_TypeDef* apb2rstr;
	STM32FXXXRCC_AHB1ENR_TypeDef* ahb1enr;
	STM32FXXXRCC_AHB2ENR_TypeDef* ahb2enr;
	STM32FXXXRCC_AHB3ENR_TypeDef* ahb3enr;
	STM32FXXXRCC_APB1ENR_TypeDef* apb1enr;
	STM32FXXXRCC_APB2ENR_TypeDef* apb2enr;
	STM32FXXXRCC_AHB1LPENR_TypeDef* ahb1lpenr;
	STM32FXXXRCC_AHB2LPENR_TypeDef* ahb2lpenr;
	STM32FXXXRCC_AHB3LPENR_TypeDef* ahb3lpenr;
	STM32FXXXRCC_APB1LPENR_TypeDef* apb1lpenr;
	STM32FXXXRCC_APB2LPENR_TypeDef* apb2lpenr;
	STM32FXXXRCC_BDCR_TypeDef* bdcr;
	STM32FXXXRCC_CSR_TypeDef* csr;
	STM32FXXXRCC_SSCGR_TypeDef* sscgr;
	STM32FXXXRCC_PLLI2SCFGR_TypeDef* plli2scfgr;
	STM32FXXXRCC_PLLSAICFGR_TypeDef* pllsaicfgr;
	STM32FXXXRCC_DCKCFGR_TypeDef* dckcfgr;
	STM32FXXXRCC_CKGATENR_TypeDef* ckgatenr;
	STM32FXXXRCC_DCKCFGR2_TypeDef* dckcfgr2;
	/*** Extended ***/
	STM32FXXXRCCPLL* pll;
	STM32FXXXRCCPLLI2S* plli2s;
	STM32FXXXRCCPLLSAI* pllsai;
	/*** Other ***/
	void (*pll_division)(uint8_t pllm, uint16_t plln, uint8_t pllp, uint8_t pllq);
	void (*pllclk_enable)(void);
	void (*plli2s_enable)(void);
	void (*pllsai_enable)(void);
	void (*inic)(void);
	void (*henable)(uint8_t hclock);
	uint8_t (*hselect)(uint8_t sysclk);
	void (*lenable)(uint8_t lclock);
	void (*lselect)(uint8_t lclock);
	void (*prescaler)(uint16_t ahbpre, uint8_t ppre1, uint8_t ppre2, uint8_t rtcpre);
	void (*nvic)(uint8_t bool);
}STM32FXXXRCCobj;

STM32FXXXRCCobj* rcc_enable(void);
STM32FXXXRCCobj* rcc(void);

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

