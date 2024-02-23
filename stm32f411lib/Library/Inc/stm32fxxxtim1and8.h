/******************************************************************************
	STM32 XXX TIM 1 and 8
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 22062023
Comment:
	
*******************************************************************************/
#ifndef _STM32FXXXTIM1AND8_H_
	#define _STM32FXXXTIM1AND8_H_
/*** Library ***/
#include "armquery.h"
/*** TIMER BitField Mapping TypeDef ***/
/*** TIM1and8 -> CR1 ***/
typedef struct{
	uint32_t cen:1;
	uint32_t udis:1;
	uint32_t urs:1;
	uint32_t opm:1;
	uint32_t dir:1;
	uint32_t cms:2;
	uint32_t apre:1;
	uint32_t ckd:2;
	uint32_t fill:22;
}STM32FXXXTIM1_CR1_TypeDef, STM32FXXXTIM8_CR1_TypeDef;
/*** TIM1and8 -> CR2 ***/
typedef struct{
	uint32_t ccpc:1;
	uint32_t fill1:1;
	uint32_t ccus:1;
	uint32_t ccds:1;
	uint32_t mms:3;
	uint32_t ti1s:1;
	uint32_t ois1:1;
	uint32_t ois1n:1;
	uint32_t ois2:1;
	uint32_t ois2n:1;
	uint32_t ois3:1;
	uint32_t ois3n:1;
	uint32_t ois4:1;
	uint32_t fill2:17;
}STM32FXXXTIM1_CR2_TypeDef, STM32FXXXTIM8_CR2_TypeDef;
/*** TIM1and8 -> SMCR ***/
typedef struct{
	uint32_t sms:3;
	uint32_t fill1:1;
	uint32_t ts:3;
	uint32_t msm:1;
	uint32_t etf:4;
	uint32_t etps:2;
	uint32_t ece:1;
	uint32_t etp:1;
	uint32_t fill2:16;
}STM32FXXXTIM1_SMCR_TypeDef, STM32FXXXTIM8_SMCR_TypeDef;
/*** TIM1and8 -> DIEER ***/
typedef struct{
	uint32_t uie:1;
	uint32_t cc1ie:1;
	uint32_t cc2ie:1;
	uint32_t cc3ie:1;
	uint32_t cc4ie:1;
	uint32_t comie:1;
	uint32_t tie:1;
	uint32_t bie:1;
	uint32_t ude:1;
	uint32_t cc1de:1;
	uint32_t cc2de:1;
	uint32_t cc3de:1;
	uint32_t cc4de:1;
	uint32_t comde:1;
	uint32_t tde:1;
	uint32_t fill:17;
}STM32FXXXTIM1_DIER_TypeDef, STM32FXXXTIM8_DIER_TypeDef;
/*** TIM1and8 -> SR ***/
typedef union{
	struct SR_1{
		uint32_t uif:1;
		uint32_t cc1if:1;
		uint32_t cc2if:1;
		uint32_t cc3if:1;
		uint32_t cc4if:1;
		uint32_t comif:1;
		uint32_t tif:1;
		uint32_t bif:1;
		uint32_t fill1:1;
		uint32_t cc1of:1;
		uint32_t cc2of:1;
		uint32_t cc3of:1;
		uint32_t cc4of:1;
		uint32_t fill2:19;
	} bit;
	struct SR_2{
		uint32_t iflag:8;
		uint32_t fill1:1;
		uint32_t oflag:4;
		uint32_t fill2:19;
	} iof;
}STM32FXXXTIM1_SR_TypeDef, STM32FXXXTIM8_SR_TypeDef;
/*** TIM1and8 -> EGR ***/
typedef struct{
	uint32_t ug:1;
	uint32_t cc1g:1;
	uint32_t cc2g:1;
	uint32_t cc3g:1;
	uint32_t cc4g:1;
	uint32_t comg:1;
	uint32_t tg:1;
	uint32_t bg:1;
	uint32_t fill:24;
}STM32FXXXTIM1_EGR_TypeDef, STM32FXXXTIM8_EGR_TypeDef;
/*** TIM1and8 -> CCMR1 ***/
typedef union{
	struct CCMR1_1{
		uint32_t ccls:2;
		uint32_t oc1fe:1;
		uint32_t oc1pe:1;
		uint32_t oc1m:3;
		uint32_t oc1ce:1;
		uint32_t cc2s:2;
		uint32_t oc2fe:1;
		uint32_t oc2pe:1;
		uint32_t oc2m:3;
		uint32_t oc2ce:1;
		uint32_t fill:16;
	} ocm;
	struct CCMR1_2{
		uint32_t ccls:2;
		uint32_t iclpsc:2;
		uint32_t ic1f:4;
		uint32_t cc2s:2;
		uint32_t ic2psc:2;
		uint32_t ic2f:4;
		uint32_t fill:16;
	} icm;
}STM32FXXXTIM1_CCMR1_TypeDef, STM32FXXXTIM8_CCMR1_TypeDef;
/*** TIM1and8 -> CCMR2 ***/
typedef union{
	struct CCMR2_1{
		uint32_t cc3s:2;
		uint32_t oc3fe:1;
		uint32_t oc3pe:1;
		uint32_t oc3m:3;
		uint32_t oc3ce:1;
		uint32_t cc4s:2;
		uint32_t oc4fe:1;
		uint32_t oc4pe:1;
		uint32_t oc4m:3;
		uint32_t oc4ce:1;
		uint32_t fill:16;
	} ocm;
	struct CCMR2_2{
		uint32_t cc3s:2;
		uint32_t ic3psc:2;
		uint32_t ic3f:4;
		uint32_t cc4s:2;
		uint32_t ic4psc:2;
		uint32_t ic4f:4;
		uint32_t fill:16;
	} icm;
}STM32FXXXTIM1_CCMR2_TypeDef, STM32FXXXTIM8_CCMR2_TypeDef;
/*** TIM1and8 -> CCER ***/
typedef struct{
	uint32_t cc1e:1;
	uint32_t cc1p:1;
	uint32_t cc1ne:1;
	uint32_t cc1np:1;
	uint32_t cc2e:1;
	uint32_t cc2p:1;
	uint32_t cc2ne:1;
	uint32_t cc2np:1;
	uint32_t cc3e:1;
	uint32_t cc3p:1;
	uint32_t cc3ne:1;
	uint32_t cc3np:1;
	uint32_t cc4e:1;
	uint32_t cc4p:1;
	uint32_t fill:18;
}STM32FXXXTIM1_CCER_TypeDef, STM32FXXXTIM8_CCER_TypeDef;
/*** TIM1and8 -> CNT ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM1_CNT_TypeDef, STM32FXXXTIM8_CNT_TypeDef;
/*** TIM1and8 -> PSC ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM1_PSC_TypeDef, STM32FXXXTIM8_PSC_TypeDef;
/*** TIM1and8 -> ARR ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM1_ARR_TypeDef, STM32FXXXTIM8_ARR_TypeDef;
/*** TIM1and8 -> RCR ***/
typedef struct{
	uint32_t byte:8;
	uint32_t fill:24;
}STM32FXXXTIM1_RCR_TypeDef, STM32FXXXTIM8_RCR_TypeDef;
/*** TIM1and8 -> CCR1 ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM1_CCR1_TypeDef, STM32FXXXTIM8_CCR1_TypeDef;
/*** TIM1and8 -> CCR2 ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM1_CCR2_TypeDef, STM32FXXXTIM8_CCR2_TypeDef;
/*** TIM1and8 -> CCR3 ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM1_CCR3_TypeDef, STM32FXXXTIM8_CCR3_TypeDef;
/*** TIM1and8 -> CCR4 ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM1_CCR4_TypeDef, STM32FXXXTIM8_CCR4_TypeDef;
/*** TIM1and8 -> BDTR ***/
typedef struct{
	uint32_t dtg:8;
	uint32_t lock:2;
	uint32_t ossi:1;
	uint32_t ossr:1;
	uint32_t bke:1;
	uint32_t bkp:1;
	uint32_t aoe:1;
	uint32_t moe:1;
	uint32_t fill:16;
}STM32FXXXTIM1_BDTR_TypeDef, STM32FXXXTIM8_BDTR_TypeDef;
/*** TIM1and8 -> DCR ***/
typedef struct{
	uint32_t dba:5;
	uint32_t fill1:3;
	uint32_t dbl:5;
	uint32_t fill2:19;
}STM32FXXXTIM1_DCR_TypeDef, STM32FXXXTIM8_DCR_TypeDef;
/*** TIM1and8 -> DMAR ***/
typedef struct{
	uint32_t dword;
}STM32FXXXTIM1_DMAR_TypeDef, STM32FXXXTIM8_DMAR_TypeDef;
/*************************/
/*** TIMER1and8 TypeDef***/
/*************************/
typedef struct
{
	/*** BitField Mapping ***/
	STM32FXXXTIM1_CR1_TypeDef* cr1;
	STM32FXXXTIM1_CR2_TypeDef* cr2;
	STM32FXXXTIM1_SMCR_TypeDef* smcr;
	STM32FXXXTIM1_DIER_TypeDef* dier;
	STM32FXXXTIM1_SR_TypeDef* sr;
	STM32FXXXTIM1_EGR_TypeDef* egr;
	STM32FXXXTIM1_CCMR1_TypeDef* ccmr1;
	STM32FXXXTIM1_CCMR2_TypeDef* ccmr2;
	STM32FXXXTIM1_CCER_TypeDef* ccer;
	STM32FXXXTIM1_CNT_TypeDef* cnt;
	STM32FXXXTIM1_PSC_TypeDef* psc;
	STM32FXXXTIM1_ARR_TypeDef* arr;
	STM32FXXXTIM1_RCR_TypeDef* rcr;
	STM32FXXXTIM1_CCR1_TypeDef* ccr1;
	STM32FXXXTIM1_CCR2_TypeDef* ccr2;
	STM32FXXXTIM1_CCR3_TypeDef* ccr3;
	STM32FXXXTIM1_CCR4_TypeDef* ccr4;
	STM32FXXXTIM1_BDTR_TypeDef* bdtr;
	STM32FXXXTIM1_DCR_TypeDef* dcr;
	STM32FXXXTIM1_DMAR_TypeDef* dmar;
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t value);
}STM32FXXXTIM1obj, STM32FXXXTIM8obj;
/*******************/
/*** INIC 1 and 8 ***/
/*******************/
STM32FXXXTIM1obj tim1_enable(void);
STM32FXXXTIM1obj* tim1(void);
STM32FXXXTIM8obj tim8_enable(void);
STM32FXXXTIM1obj* tim8(void);
/****************************************/
/*** TIM1 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim1Clock(uint8_t bool);
void STM32FXXXTim1Nvic(uint8_t value);
/****************************************/
/*** TIM8 Procedure & Function Header ***/
/****************************************/
void STM32FXXXTim8Clock(uint8_t bool);
void STM32FXXXTim8Nvic(uint8_t value);
/****************************************/
/*** INTERRUPT HEADER ***/
void TIM1_BRK_TIM9_IRQHandler(void);
void TIM1_UP_TIM10_IRQHandler(void);
void TIM1_TRG_COM_TIM11_IRQHandler(void);
void TIM1_CC_IRQHandler(void);
void TIM8_BRK_TIM12_IRQHandler(void);
void TIM8_UP_TIM13_IRQHandler(void);
void TIM8_TRG_COM_TIM14_IRQHandler(void);
void TIM8_CC_IRQHandler(void);

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

