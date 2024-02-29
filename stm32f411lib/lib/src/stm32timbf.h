/******************************************************************************
	STM32 XXX TIMBF
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 23022024
Comment:
	
*******************************************************************************/
#ifndef _STM32TIMBF_H_
	#define _STM32TIMBF_H_

#include <inttypes.h>

/*** TIMER BitField Mapping TypeDef ***/
/*** TIM -> CR1 ***/
volatile typedef union{
	struct TIM_CR1_1{
		uint32_t cen:1;
		uint32_t udis:1;
		uint32_t urs:1;
		uint32_t opm:1;
		uint32_t dir:1;
		uint32_t cms:2;
		uint32_t arpe:1;
		uint32_t ckd:2;
		uint32_t fill:22;
	}par,tim1and8_par,tim2to5_par;
	uint32_t reg;
}STM32FXXXTIM_CR1_TypeDef, STM32FXXXTIM1and8_CR1_TypeDef, STM32FXXXTIM2to5_CR1_TypeDef;
volatile typedef union{
	struct TIM_CR1_2{
		uint32_t cen:1;
		uint32_t udis:1;
		uint32_t urs:1;
		uint32_t opm:1;
		uint32_t fill1:3;
		uint32_t arpe:1;
		uint32_t ckd:2;
		uint32_t fill2:22;
	}tim9to11_par;
	uint32_t reg;
}STM32FXXXTIM9to11_CR1_TypeDef;
/*** TIM -> CR2 ***/
volatile typedef union{
	struct TIM_CR2_1{
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
	}par,tim1and8_par;
	uint32_t reg;
}STM32FXXXTIM_CR2_TypeDef, STM32FXXXTIM1and8_CR2_TypeDef;
volatile typedef union{
	struct TIM_CR2_2{
		uint32_t fill1:3;
		uint32_t ccds:1;
		uint32_t mms:3;
		uint32_t ti1s:1;
		uint32_t fill2:24;
	}tim2t05_par;
	uint32_t reg;
}STM32FXXXTIM2to5_CR2_TypeDef;
/*** TIM -> SMCR ***/
volatile typedef union{
	struct TIM_SMCR_1{
		uint32_t sms:3;
		uint32_t fill1:1;
		uint32_t ts:3;
		uint32_t msm:1;
		uint32_t etf:4;
		uint32_t etps:2;
		uint32_t ece:1;
		uint32_t etp:1;
		uint32_t fill2:16;
	}par,tim1and8_par,tim2to5_par;
	uint32_t reg;
}STM32FXXXTIM_SMCR_TypeDef, STM32FXXXTIM1and8_SMCR_TypeDef, STM32FXXXTIM2to5_SMCR_TypeDef;
volatile typedef union{
	struct TIM_SMCR_2{
		uint32_t sms:3;
		uint32_t fill1:1;
		uint32_t ts:3;
		uint32_t msm:1;
		uint32_t fill2:24;
	}tim9_par;
	uint32_t reg;
}STM32FXXXTIM9_SMCR_TypeDef;
/*** TIM -> DIEER ***/
volatile typedef union{
	struct TIM_DIER_1{
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
	}par,tim1and8_par;
	uint32_t reg;
}STM32FXXXTIM_DIER_TypeDef, STM32FXXXTIM1and8_DIER_TypeDef;
volatile typedef union{
	struct TIM_DIER_2{
		uint32_t uie:1;
		uint32_t cc1ie:1;
		uint32_t cc2ie:1;
		uint32_t cc3ie:1;
		uint32_t cc4ie:1;
		uint32_t fill1:1;
		uint32_t tie:1;
		uint32_t fill2:1;
		uint32_t ude:1;
		uint32_t cc1de:1;
		uint32_t cc2de:1;
		uint32_t cc3de:1;
		uint32_t cc4de:1;
		uint32_t comde:1;
		uint32_t tde:1;
		uint32_t fill3:17;
	}tim2to5_par;
	uint32_t reg;
}STM32FXXXTIM2to5_DIER_TypeDef;
volatile typedef union{
	struct TIM_DIER_3{
		uint32_t uie:1;
		uint32_t cc1ie:1;
		uint32_t cc2ie:1;
		uint32_t fill1:3;
		uint32_t tie:1;
		uint32_t fill:25;
	}tim9_par;
	uint32_t reg;
}STM32FXXXTIM9_DIER_TypeDef;
volatile typedef union{
	struct TIM_DIER_4{
		uint32_t uie:1;
		uint32_t cc1ie:1;
		uint32_t fill:30;
	}tim10and11_par;
	uint32_t reg;
}STM32FXXXTIM10and11_DIER_TypeDef;
/*** TIM -> SR ***/
volatile typedef union{
	struct TIM_SR_1{
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
	}par,tim1and8_par;
	struct TIM_SR_2{
		uint32_t iflag:8;
		uint32_t fill1:1;
		uint32_t oflag:4;
		uint32_t fill2:19;
	}iof_par,tim1and8_iof_par;
	struct TIM_SR_3{
		uint32_t fill1:1;
		uint32_t cciflag:4;
		uint32_t fill2:4;
		uint32_t ccoflag:4;
		uint32_t fill3:19;
	}iocc_par,tim1and8_iocc_par;
	uint32_t reg;
}STM32FXXXTIM_SR_TypeDef, STM32FXXXTIM1and8_SR_TypeDef;
volatile typedef union{
	struct TIM_SR_4{
		uint32_t uif:1;
		uint32_t cc1if:1;
		uint32_t cc2if:1;
		uint32_t cc3if:1;
		uint32_t cc4if:1;
		uint32_t fill1:1;
		uint32_t tif:1;
		uint32_t fill2:2;
		uint32_t cc1of:1;
		uint32_t cc2of:1;
		uint32_t cc3of:1;
		uint32_t cc4of:1;
		uint32_t fill3:19;
	}tim2to5_par;
	struct TIM_SR_5{
		uint32_t iflag:7;
		uint32_t fill1:2;
		uint32_t oflag:4;
		uint32_t fill2:19;
	}tim2to5_iof_par;
	struct TIM_SR_6{
		uint32_t fill1:1;
		uint32_t cciflag:4;
		uint32_t fill2:4;
		uint32_t ccoflag:4;
		uint32_t fill3:19;
	}tim2to5_iocc_par;
	uint32_t reg;
}STM32FXXXTIM2to5_SR_TypeDef;
volatile typedef union{
	struct TIM_SR_7{
		uint32_t uif:1;
		uint32_t cc1if:1;
		uint32_t cc2if:1;
		uint32_t fill1:3;
		uint32_t tif:1;
		uint32_t fill2:2;
		uint32_t cc1of:1;
		uint32_t cc2of:1;
		uint32_t fill3:21;
	}tim9_par;
	struct TIM_SR_8{
		uint32_t iflag:7;
		uint32_t fill1:2;
		uint32_t oflag:2;
		uint32_t fill2:21;
	}tim9_iof_par;
	struct TIM_SR_9{
		uint32_t fill1:1;
		uint32_t cciflag:2;
		uint32_t fill2:6;
		uint32_t ccoflag:2;
		uint32_t fill3:21;
	}tim9_iocc_par;
	uint32_t reg;
}STM32FXXXTIM9_SR_TypeDef;
volatile typedef union{
	struct TIM_SR_10{
		uint32_t uif:1;
		uint32_t cc1if:1;
		uint32_t fill1:7;
		uint32_t cc1of:1;
		uint32_t fill2:22;
	}tim10and11_par;
	struct TIM_SR_11{
		uint32_t iflag:2;
		uint32_t fill1:7;
		uint32_t oflag:1;
		uint32_t fill2:22;
	}tim10and11_iof_par;
	struct TIM_SR_12{
		uint32_t fill1:1;
		uint32_t cciflag:1;
		uint32_t fill2:7;
		uint32_t ccoflag:1;
		uint32_t fill3:22;
	}tim10and11_iocc_par;
	uint32_t reg;
}STM32FXXXTIM10and11_SR_TypeDef;
/*** TIM -> EGR ***/
volatile typedef union{
	struct TIM_EGR_1{
		uint32_t ug:1;
		uint32_t cc1g:1;
		uint32_t cc2g:1;
		uint32_t cc3g:1;
		uint32_t cc4g:1;
		uint32_t comg:1;
		uint32_t tg:1;
		uint32_t bg:1;
		uint32_t fill:24;
	}par,tim1and8_par;
	uint32_t reg;
}STM32FXXXTIM_EGR_TypeDef, STM32FXXXTIM1and8_EGR_TypeDef;
volatile typedef union{
	struct TIM_EGR_2{
		uint32_t ug:1;
		uint32_t cc1g:1;
		uint32_t cc2g:1;
		uint32_t cc3g:1;
		uint32_t cc4g:1;
		uint32_t fill1:1;
		uint32_t tg:1;
		uint32_t fill2:25;
	}tim2to5_par;
	uint32_t reg;
}STM32FXXXTIM2to5_EGR_TypeDef;
volatile typedef union{
	struct TIM_EGR_3{
		uint32_t ug:1;
		uint32_t cc1g:1;
		uint32_t cc2g:1;
		uint32_t fill1:3;
		uint32_t tg:1;
		uint32_t fill2:25;
	}tim9_par;
	uint32_t reg;
}STM32FXXXTIM9_EGR_TypeDef;
volatile typedef union{
	struct TIM_EGR_4{
		uint32_t ug:1;
		uint32_t cc1g:1;
		uint32_t fill:30;
	}tim10and11_par;
	uint32_t reg;
}STM32FXXXTIM10and11_EGR_TypeDef;
/*** TIM -> CCMR1 ***/
volatile typedef union{
	struct TIM_CCMR1_1{
		uint32_t cc1s:2;
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
	}ocm_par,tim1an8_ocm_par,tim2to5_ocm_par;
	struct TIM_CCMR1_2{
		uint32_t cc1s:2;
		uint32_t ic1psc:2;
		uint32_t ic1f:4;
		uint32_t cc2s:2;
		uint32_t ic2psc:2;
		uint32_t ic2f:4;
		uint32_t fill:16;
	}icm_par,tim1and8_icm_par,tim2to5_icm_par;
	uint32_t reg;
}STM32FXXXTIM_CCMR1_TypeDef, STM32FXXXTIM1and8_CCMR1_TypeDef, STM32FXXXTIM2to5_CCMR1_TypeDef;
volatile typedef union{
	struct TIM_CCMR1_3{
		uint32_t cc1s:2;
		uint32_t oc1fe:1;
		uint32_t oc1pe:1;
		uint32_t oc1m:3;
		uint32_t fill1:1;
		uint32_t cc2s:2;
		uint32_t oc2fe:1;
		uint32_t oc2pe:1;
		uint32_t oc2m:3;
		uint32_t fill2:17;
	}tim9_ocm_par;
	struct TIM_CCMR1_4{
		uint32_t cc1s:2;
		uint32_t ic1psc:2;
		uint32_t ic1f:4;
		uint32_t cc2s:2;
		uint32_t ic2psc:2;
		uint32_t ic2f:4;
		uint32_t fill:16;
	}tim9_icm_par;
	uint32_t reg;
}STM32FXXXTIM9_CCMR1_TypeDef;
volatile typedef union{
	struct TIM_CCMR1_5{
		uint32_t cc1s:2;
		uint32_t oc1fe:1;
		uint32_t oc1pe:1;
		uint32_t oc1m:3;
		uint32_t fill:25;
	}tim10and11_ocm_par;
	struct TIM_CCMR1_6{
		uint32_t cc1s:2;
		uint32_t ic1psc:2;
		uint32_t ic1f:4;
		uint32_t fill:24;
	}tim10and11_icm_par;
	uint32_t reg;
}STM32FXXXTIM10and11_CCMR1_TypeDef;
/*** TIM -> CCMR2 ***/
volatile typedef union{
	struct TIM_CCMR2_1{
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
	}ocm_par,tim1and8_ocm_par,tim2to5_ocm_par;
	struct TIM_CCMR2_2{
		uint32_t cc3s:2;
		uint32_t ic3psc:2;
		uint32_t ic3f:4;
		uint32_t cc4s:2;
		uint32_t ic4psc:2;
		uint32_t ic4f:4;
		uint32_t fill:16;
	}icm_par,tim1and8_icm_par,tim2to5_icm_par;
	uint32_t reg;
}STM32FXXXTIM_CCMR2_TypeDef, STM32FXXXTIM1and8_CCMR2_TypeDef, STM32FXXXTIM2to5_CCMR2_TypeDef;
/*** TIM -> CCER ***/
volatile typedef union{
	struct TIM_CCER_1{
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
		uint32_t fill1:1;
		uint32_t cc4np:1;
		uint32_t fill2:16;
	}par;
	uint32_t reg;
}STM32FXXXTIM_CCER_TypeDef;
volatile typedef union{
	struct TIM_CCER_2{
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
	}tim1and8_par;
	uint32_t reg;
}STM32FXXXTIM1and8_CCER_TypeDef;
volatile typedef union{
	struct TIM_CCER_3{
		uint32_t cc1e:1;
		uint32_t cc1p:1;
		uint32_t fill1:1;
		uint32_t cc1np:1;
		uint32_t cc2e:1;
		uint32_t cc2p:1;
		uint32_t fill2:1;
		uint32_t cc2np:1;
		uint32_t cc3e:1;
		uint32_t cc3p:1;
		uint32_t fill3:1;
		uint32_t cc3np:1;
		uint32_t cc4e:1;
		uint32_t cc4p:1;
		uint32_t fill4:1;
		uint32_t cc4np:1;
		uint32_t fill5:16;
	}tim2to5_par;
	uint32_t reg;
}STM32FXXXTIM2to5_CCER_TypeDef;
volatile typedef union{
	struct TIM_CCER_4{
		uint32_t cc1e:1;
		uint32_t cc1p:1;
		uint32_t fill1:1;
		uint32_t cc1np:1;
		uint32_t cc2e:1;
		uint32_t cc2p:1;
		uint32_t fill2:1;
		uint32_t cc2np:1;
		uint32_t fill4:24;
	}tim9_par;
	uint32_t reg;
}STM32FXXXTIM9_CCER_TypeDef;
volatile typedef union{
	struct TIM_CCER_5{
		uint32_t cc1e:1;
		uint32_t cc1p:1;
		uint32_t fill1:1;
		uint32_t cc1np:1;
		uint32_t fill4:28;
	}tim10and11_par;
	uint32_t reg;
}STM32FXXXTIM10and11_CCER_TypeDef;
/*** TIM -> CNT ***/
volatile typedef union{
	struct TIM_CNT_1{
		uint16_t w0;
		uint16_t w1;
	}par;
	uint32_t reg;
}STM32FXXXTIM_CNT_TypeDef, STM32FXXXTIM9to11_CNT_TypeDef, STM32FXXXTIM1and8_CNT_TypeDef, \
 STM32FXXXTIM2to5_CNT_TypeDef;
/*** TIM -> PSC ***/
volatile typedef union{
	struct TIM_PSC_1{
		uint16_t w0;
		uint16_t w1;
	}par;
	uint32_t reg;
}STM32FXXXTIM_PSC_TypeDef, STM32FXXXTIM9to11_PSC_TypeDef, STM32FXXXTIM1and8_PSC_TypeDef, \
 STM32FXXXTIM2to5_PSC_TypeDef;
/*** TIM -> ARR ***/
volatile typedef union{
	struct TIM_ARR_1{
		uint16_t w0;
		uint16_t w1;
	}par;
	uint32_t reg;
}STM32FXXXTIM_ARR_TypeDef,STM32FXXXTIM9_ARR_TypeDef, STM32FXXXTIM1and8_ARR_TypeDef, \
 STM32FXXXTIM2to5_ARR_TypeDef;
/*** TIM -> RCR ***/
volatile typedef union{
	struct TIM_RCR_1{
		uint32_t byte:8;
		uint32_t fill:24;
	}par;
	uint32_t reg;
}STM32FXXXTIM_RCR_TypeDef, STM32FXXXTIM1and8_RCR_TypeDef;
/*** TIM -> CCR1 ***/
volatile typedef union{
	struct TIM_CCR1_1{
		uint16_t w0;
		uint16_t w1;
	}par;
	uint32_t reg;
}STM32FXXXTIM_CCR1_TypeDef, STM32FXXXTIM1and8_CCR1_TypeDef, STM32FXXXTIM2to5_CCR1_TypeDef;
/*** TIM -> CCR2 ***/
volatile typedef union{
	struct TIM_CCR2_1{
		uint16_t w0;
		uint16_t w1;
	}par;
	uint32_t reg;
}STM32FXXXTIM_CCR2_TypeDef, STM32FXXXTIM1and8_CCR2_TypeDef, STM32FXXXTIM2to5_CCR2_TypeDef;
/*** TIM -> CCR3 ***/
volatile typedef union{
	struct TIM_CCR3_1{
		uint16_t w0;
		uint16_t w1;
	}par;
	uint32_t reg;
}STM32FXXXTIM_CCR3_TypeDef, STM32FXXXTIM1and8_CCR3_TypeDef, STM32FXXXTIM2to5_CCR3_TypeDef;
/*** TIM -> CCR4 ***/
volatile typedef union{
	struct TIM_CCR4_1{
		uint16_t w0;
		uint16_t w1;
	}par;
	uint32_t reg;
}STM32FXXXTIM_CCR4_TypeDef, STM32FXXXTIM1and8_CCR4_TypeDef, STM32FXXXTIM2to5_CCR4_TypeDef;
/*** TIM -> BDTR ***/
volatile typedef union{
	struct TIM_BDTR_1{
		uint32_t dt:8;
		uint32_t lock:2;
		uint32_t ossi:1;
		uint32_t ossr:1;
		uint32_t bke:1;
		uint32_t bkp:1;
		uint32_t aoe:1;
		uint32_t moe:1;
		uint32_t fill:16;
	}par,tim1an8_par;
	uint32_t reg;
}STM32FXXXTIM_BDTR_TypeDef, STM32FXXXTIM1and8_BDTR_TypeDef;
/*** TIM -> DCR ***/
volatile typedef union{
	struct TIM_DCR_1{
		uint32_t dba:5;
		uint32_t fill1:3;
		uint32_t dbl:5;
		uint32_t fill2:19;
	}par,tim1an8_dcr_par,tim2to5_par;
	uint32_t reg;
}STM32FXXXTIM_DCR_TypeDef, STM32FXXXTIM1and8_DCR_TypeDef, STM32FXXXTIM2to5_DCR_TypeDef;
/*** TIM -> DMAR ***/
volatile typedef union{
	struct TIM_DMAR_1{
		uint16_t dmab;
		uint16_t fill;
	}par,tim2to5_par;
	uint32_t reg;
}STM32FXXXTIM_DMAR_TypeDef, STM32FXXXTIM2to5_DMAR_TypeDef;
volatile typedef union{
	struct TIM_DMAR_2{
		uint32_t dmab;
	}tim1and8_par;
	uint32_t reg;
}STM32FXXXTIM1and8_DMAR_TypeDef;
/*** TIM -> OR ***/
volatile typedef union{
	struct TIM_OR_6{
		uint32_t fill1:10;
		uint32_t itr1_rmp:2;
		uint32_t fill2:20;
	}tim2_par;
	struct TIM_OR_7{
		uint32_t fill1:6;
		uint32_t it4_rmp:2;
		uint32_t fill2:24;
	}tim5_par;
	uint32_t reg;
}STM32FXXXTIM2and5_OR_TypeDef;
volatile typedef union{
	struct TIM_OR_8{
		uint32_t ti1_rmp:2;
		uint32_t fill2:30;
	}tim10and11_par;
	uint32_t reg;
}STM32FXXXTIM10and11_OR_TypeDef;

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

