/******************************************************************************
	STM32 XXX TIM
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 23022024
Comment:
	
*******************************************************************************/
#ifndef _STM32TIM_H_
	#define _STM32TIM_H_
/*** Library ***/
#include "armquery.h"
/*** TIMER BitField Mapping TypeDef ***/
/*** TIM -> CR1 ***/
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
}STM32FXXXTIM_CR1_TypeDef, STM32FXXXTIM1_CR1_TypeDef, STM32FXXXTIM8_CR1_TypeDef;
/*** TIM -> CR2 ***/
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
}STM32FXXXTIM_CR2_TypeDef, STM32FXXXTIM1_CR2_TypeDef, STM32FXXXTIM8_CR2_TypeDef;
/*** TIM -> SMCR ***/
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
}STM32FXXXTIM_SMCR_TypeDef, STM32FXXXTIM1_SMCR_TypeDef, STM32FXXXTIM8_SMCR_TypeDef;
/*** TIM -> DIEER ***/
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
}STM32FXXXTIM_DIER_TypeDef, STM32FXXXTIM1_DIER_TypeDef, STM32FXXXTIM8_DIER_TypeDef;
/*** TIM -> SR ***/
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
}STM32FXXXTIM_SR_TypeDef, STM32FXXXTIM1_SR_TypeDef, STM32FXXXTIM8_SR_TypeDef;
/*** TIM -> EGR ***/
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
}STM32FXXXTIM_EGR_TypeDef, STM32FXXXTIM1_EGR_TypeDef, STM32FXXXTIM8_EGR_TypeDef;
/*** TIM -> CCMR1 ***/
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
}STM32FXXXTIM_CCMR1_TypeDef, STM32FXXXTIM1_CCMR1_TypeDef, STM32FXXXTIM8_CCMR1_TypeDef;
/*** TIM -> CCMR2 ***/
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
}STM32FXXXTIM_CCMR2_TypeDef, STM32FXXXTIM1_CCMR2_TypeDef, STM32FXXXTIM8_CCMR2_TypeDef;
/*** TIM -> CCER ***/
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
}STM32FXXXTIM_CCER_TypeDef, STM32FXXXTIM1_CCER_TypeDef, STM32FXXXTIM8_CCER_TypeDef;
/*** TIM -> CNT ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM_CNT_TypeDef, STM32FXXXTIM1_CNT_TypeDef, STM32FXXXTIM8_CNT_TypeDef;
/*** TIM -> PSC ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM_PSC_TypeDef, STM32FXXXTIM1_PSC_TypeDef, STM32FXXXTIM8_PSC_TypeDef;
/*** TIM -> ARR ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM_ARR_TypeDef, STM32FXXXTIM1_ARR_TypeDef, STM32FXXXTIM8_ARR_TypeDef;
/*** TIM -> RCR ***/
typedef struct{
	uint32_t byte:8;
	uint32_t fill:24;
}STM32FXXXTIM_RCR_TypeDef, STM32FXXXTIM1_RCR_TypeDef, STM32FXXXTIM8_RCR_TypeDef;
/*** TIM -> CCR1 ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM_CCR1_TypeDef, STM32FXXXTIM1_CCR1_TypeDef, STM32FXXXTIM8_CCR1_TypeDef;
/*** TIM -> CCR2 ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM_CCR2_TypeDef, STM32FXXXTIM1_CCR2_TypeDef, STM32FXXXTIM8_CCR2_TypeDef;
/*** TIM -> CCR3 ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM_CCR3_TypeDef, STM32FXXXTIM1_CCR3_TypeDef, STM32FXXXTIM8_CCR3_TypeDef;
/*** TIM -> CCR4 ***/
typedef struct{
	uint32_t word:16;
	uint32_t fill:16;
}STM32FXXXTIM_CCR4_TypeDef, STM32FXXXTIM1_CCR4_TypeDef, STM32FXXXTIM8_CCR4_TypeDef;
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
}STM32FXXXTIM_BDTR_TypeDef, STM32FXXXTIM1_BDTR_TypeDef, STM32FXXXTIM8_BDTR_TypeDef;
/*** TIM -> DCR ***/
typedef struct{
	uint32_t dba:5;
	uint32_t fill1:3;
	uint32_t dbl:5;
	uint32_t fill2:19;
}STM32FXXXTIM_DCR_TypeDef, STM32FXXXTIM1_DCR_TypeDef, STM32FXXXTIM8_DCR_TypeDef;
/*** TIM -> DMAR ***/
typedef struct{
	uint32_t dword;
}STM32FXXXTIM_DMAR_TypeDef, STM32FXXXTIM1_DMAR_TypeDef, STM32FXXXTIM8_DMAR_TypeDef;

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

