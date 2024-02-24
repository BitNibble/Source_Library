/******************************************************************************
	STM32 XXX USARTBF
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 23022024
Comment:
	
*******************************************************************************/
#ifndef _STM32USARTBF_H_
	#define _STM32USARTBF_H_

/*** USART BitField Mapping TypeDef ***/
/*** USART -> SR ***/
typedef union{
	struct SR_1{
		uint32_t pe:1;
		uint32_t fe:1;
		uint32_t nf:1;
		uint32_t ore:1;
		uint32_t idle:1;
		uint32_t rxne:1;
		uint32_t tc:1;
		uint32_t txe:1;
		uint32_t lbd:1;
		uint32_t cts:1;
		uint32_t fill2:22;
	}bit;
	struct SR_2{
		uint32_t d:10;
		uint32_t fill:22;
	}data;
	uint32_t dword;
}STM32FXXXUSART_SR_TypeDef;
/*** USART -> DR ***/
typedef union{
	struct DR_2{
		uint32_t d:9;
		uint32_t fill:23;
	}data;
	uint32_t dword;
}STM32FXXXUSART_DR_TypeDef;
/*** USART -> BRR ***/
typedef union{
	struct BRR_1{
		uint32_t div_fraction:4;
		uint32_t div_mantissa:12;
		uint32_t fill:16;
	}bit;
	uint32_t dword;
}STM32FXXXUSART_BRR_TypeDef;
/*** USART -> CR1 ***/
typedef union{
	struct CR1_1{
		uint32_t cen:1;
		uint32_t udis:1;
		uint32_t urs:1;
		uint32_t opm:1;
		uint32_t dir:1;
		uint32_t cms:2;
		uint32_t arpe:1;
		uint32_t ckd:2;
		uint32_t fill:22;
	}bit;
	uint32_t dword;
}STM32FXXXUSART_CR1_TypeDef;
/*** USART -> CR2 ***/
typedef union{
	struct CR2_1{
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
	}bit;
	uint32_t dword;
}STM32FXXXUSART_CR2_TypeDef, STM32FXXXUSART1and8_CR2_TypeDef;
typedef union{
	struct CR2_2{
		uint32_t fill1:3;
		uint32_t ccds:1;
		uint32_t mms:3;
		uint32_t ti1s:1;
		uint32_t fill2:24;
	}bit;
	uint32_t dword;
}STM32FXXXUSART2to5_CR2_TypeDef;
/*** USART -> DIEER ***/
typedef union{
	struct DIER_1{
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
	}bit;
	uint32_t dword;
}STM32FXXXUSART_DIER_TypeDef, STM32FXXXUSART1and8_DIER_TypeDef;
typedef union{
	struct DIER_2{
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
	}bit;
	uint32_t dword;
}STM32FXXXUSART2to5_DIER_TypeDef;
typedef union{
	struct DIER_3{
		uint32_t uie:1;
		uint32_t cc1ie:1;
		uint32_t cc2ie:1;
		uint32_t fill1:3;
		uint32_t tie:1;
		uint32_t fill:25;
	}bit;
	uint32_t dword;
}STM32FXXXUSART9_DIER_TypeDef;
typedef union{
	struct DIER_4{
		uint32_t uie:1;
		uint32_t cc1ie:1;
		uint32_t fill:30;
	}bit;
	uint32_t dword;
}STM32FXXXUSART10and11_DIER_TypeDef;
/*** USART -> EGR ***/
typedef union{
	struct EGR_1{
		uint32_t ug:1;
		uint32_t cc1g:1;
		uint32_t cc2g:1;
		uint32_t cc3g:1;
		uint32_t cc4g:1;
		uint32_t comg:1;
		uint32_t tg:1;
		uint32_t bg:1;
		uint32_t fill:24;
	}bit;
	uint32_t dword;
}STM32FXXXUSART_EGR_TypeDef, STM32FXXXUSART1and8_EGR_TypeDef;
typedef union{
	struct EGR_2{
		uint32_t ug:1;
		uint32_t cc1g:1;
		uint32_t cc2g:1;
		uint32_t cc3g:1;
		uint32_t cc4g:1;
		uint32_t fill1:1;
		uint32_t tg:1;
		uint32_t fill2:25;
	}bit;
	uint32_t dword;
}STM32FXXXUSART2to5_EGR_TypeDef;
typedef union{
	struct EGR_3{
		uint32_t ug:1;
		uint32_t cc1g:1;
		uint32_t cc2g:1;
		uint32_t fill1:3;
		uint32_t tg:1;
		uint32_t fill2:25;
	}bit;
	uint32_t dword;
}STM32FXXXUSART9_EGR_TypeDef;
typedef union{
	struct EGR_4{
		uint32_t ug:1;
		uint32_t cc1g:1;
		uint32_t fill:30;
	}bit;
	uint32_t dword;
}STM32FXXXUSART10and11_EGR_TypeDef;
/*** USART -> CCMR1 ***/
typedef union{
	struct CCMR1_1{
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
	}ocm;
	struct CCMR1_2{
		uint32_t cc1s:2;
		uint32_t ic1psc:2;
		uint32_t ic1f:4;
		uint32_t cc2s:2;
		uint32_t ic2psc:2;
		uint32_t ic2f:4;
		uint32_t fill:16;
	}icm;
	uint32_t dword;
}STM32FXXXUSART_CCMR1_TypeDef, STM32FXXXUSART1and8_CCMR1_TypeDef, STM32FXXXUSART2to5_CCMR1_TypeDef;
typedef union{
	struct CCMR1_3{
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
	}ocm;
	struct CCMR1_4{
		uint32_t cc1s:2;
		uint32_t ic1psc:2;
		uint32_t ic1f:4;
		uint32_t cc2s:2;
		uint32_t ic2psc:2;
		uint32_t ic2f:4;
		uint32_t fill:16;
	}icm;
	uint32_t dword;
}STM32FXXXUSART9_CCMR1_TypeDef;
typedef union{
	struct CCMR1_5{
		uint32_t cc1s:2;
		uint32_t oc1fe:1;
		uint32_t oc1pe:1;
		uint32_t oc1m:3;
		uint32_t fill:25;
	}ocm;
	struct CCMR1_6{
		uint32_t cc1s:2;
		uint32_t ic1psc:2;
		uint32_t ic1f:4;
		uint32_t fill:24;
	}icm;
	uint32_t dword;
}STM32FXXXUSART10and11_CCMR1_TypeDef;
/*** USART -> CCMR2 ***/
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
	}ocm;
	struct CCMR2_2{
		uint32_t cc3s:2;
		uint32_t ic3psc:2;
		uint32_t ic3f:4;
		uint32_t cc4s:2;
		uint32_t ic4psc:2;
		uint32_t ic4f:4;
		uint32_t fill:16;
	}icm;
	uint32_t dword;
}STM32FXXXUSART_CCMR2_TypeDef, STM32FXXXUSART1and8_CCMR2_TypeDef, STM32FXXXUSART2to5_CCMR2_TypeDef;
/*** USART -> CCER ***/
typedef union{
	struct CCER_1{
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
	}bit;
	uint32_t dword;
}STM32FXXXUSART_CCER_TypeDef;
typedef union{
	struct CCER_2{
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
	}bit;
	uint32_t dword;
}STM32FXXXUSART1and8_CCER_TypeDef;
typedef union{
	struct CCER_3{
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
	}bit;
	uint32_t dword;
}STM32FXXXUSART2to5_CCER_TypeDef;
typedef union{
	struct CCER_4{
		uint32_t cc1e:1;
		uint32_t cc1p:1;
		uint32_t fill1:1;
		uint32_t cc1np:1;
		uint32_t cc2e:1;
		uint32_t cc2p:1;
		uint32_t fill2:1;
		uint32_t cc2np:1;
		uint32_t fill4:24;
	}bit;
	uint32_t dword;
}STM32FXXXUSART9_CCER_TypeDef;
typedef union{
	struct CCER_5{
		uint32_t cc1e:1;
		uint32_t cc1p:1;
		uint32_t fill1:1;
		uint32_t cc1np:1;
		uint32_t fill4:28;
	}bit;
	uint32_t dword;
}STM32FXXXUSART10and11_CCER_TypeDef;
/*** TIM -> PSC ***/
typedef union{
	struct PSC_1{
		uint32_t w0:16;
		uint32_t w1:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART_PSC_TypeDef;
typedef union{
	struct PSC_2{
		uint32_t w:16;
		uint32_t fill:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART9to11_PSC_TypeDef, STM32FXXXUSART1and8_PSC_TypeDef, STM32FXXXUSART2to5_PSC_TypeDef;
/*** USART -> ARR ***/
typedef union{
	struct ARR_1{
		uint32_t w0:16;
		uint32_t w1:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART_ARR_TypeDef, STM32FXXXUSART2and5_ARR_TypeDef;
typedef union{
	struct ARR_2{
		uint32_t w:16;
		uint32_t fill:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART9_ARR_TypeDef, STM32FXXXUSART1and8_ARR_TypeDef, STM32FXXXUSART3and4_ARR_TypeDef;
/*** USART -> RCR ***/
typedef union{
	struct RCR_1{
		uint32_t b:8;
		uint32_t fill:24;
	}byte;
	uint32_t dword;
}STM32FXXXUSART_RCR_TypeDef, STM32FXXXUSART1and8_RCR_TypeDef;
/*** USART -> CCR1 ***/
typedef union{
	struct CCR1_1{
		uint32_t w0:16;
		uint32_t w1:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART_CCR1_TypeDef, STM32FXXXUSART2and5_CCR1_TypeDef;
typedef union{
	struct CCR1_2{
		uint32_t w:16;
		uint32_t fill:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART9to11_CCR1_TypeDef, STM32FXXXUSART1and8_CCR1_TypeDef, STM32FXXXUSART3and4_CCR1_TypeDef;
/*** USART -> CCR2 ***/
typedef union{
	struct CCR2_1{
		uint32_t w0:16;
		uint32_t w1:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART_CCR2_TypeDef, STM32FXXXUSART2and5_CCR2_TypeDef;
typedef union{
	struct CCR2_2{
		uint32_t w:16;
		uint32_t fill:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART9_CCR2_TypeDef, STM32FXXXUSART1and8_CCR2_TypeDef, STM32FXXXUSART3and4_CCR2_TypeDef;
/*** USART -> CCR3 ***/
typedef union{
	struct CCR3_1{
		uint32_t w0:16;
		uint32_t w1:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART_CCR3_TypeDef, STM32FXXXUSART2and5_CCR3_TypeDef;
typedef union{
	struct CCR3_2{
		uint32_t w:16;
		uint32_t fill:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART1and8_CCR3_TypeDef, STM32FXXXUSART3and4_CCR3_TypeDef;
/*** USART -> CCR4 ***/
typedef union{
	struct CCR4_1{
		uint32_t w0:16;
		uint32_t w1:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART_CCR4_TypeDef, STM32FXXXUSART2and5_CCR4_TypeDef;
typedef union{
	struct CCR4_2{
		uint32_t w:16;
		uint32_t fill:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART1and8_CCR4_TypeDef, STM32FXXXUSART3and4_CCR4_TypeDef;
/*** USART -> BDTR ***/
typedef union{
	struct BDTR_1{
		uint32_t dt:8;
		uint32_t lock:2;
		uint32_t ossi:1;
		uint32_t ossr:1;
		uint32_t bke:1;
		uint32_t bkp:1;
		uint32_t aoe:1;
		uint32_t moe:1;
		uint32_t fill:16;
	}bit;
	uint32_t dword;
}STM32FXXXUSART_BDTR_TypeDef, STM32FXXXUSART1and8_BDTR_TypeDef;
/*** USART -> DCR ***/
typedef union{
	struct DCR_1{
		uint32_t dba:5;
		uint32_t fill1:3;
		uint32_t dbl:5;
		uint32_t fill2:19;
	}bit;
	uint32_t dword;
}STM32FXXXUSART_DCR_TypeDef, STM32FXXXUSART1and8_DCR_TypeDef, STM32FXXXUSART2to5_DCR_TypeDef;
/*** USART -> DMAR ***/
typedef union{
	struct DMAR_1{
		uint16_t dmab;
		uint16_t fill;
	}word;
	uint32_t dword;
}STM32FXXXUSART_DMAR_TypeDef, STM32FXXXUSART2to5_DMAR_TypeDef;
typedef union{
	struct DMAR_2{
		uint32_t d;
	}dword;
	uint32_t d;
}STM32FXXXUSART1and8_DMAR_TypeDef;
/*** USART -> OR ***/
typedef union{
	struct OR_1{
		uint32_t fill1:10;
		uint32_t itr1_rmp:2;
		uint32_t fill2:20;
	}t2;
	struct OR_2{
		uint32_t fill1:6;
		uint32_t it4_rmp:2;
		uint32_t fill2:24;
	}t5;
	struct OR_3{
		uint32_t ti1_rmp:2;
		uint32_t fill2:30;
	}t10_11;
	uint32_t dword;
}STM32FXXXUSART_OR_TypeDef;
typedef union{
	struct OR_6{
		uint32_t fill1:10;
		uint32_t itr1_rmp:2;
		uint32_t fill2:20;
	}t2;
	struct OR_7{
		uint32_t fill1:6;
		uint32_t it4_rmp:2;
		uint32_t fill2:24;
	}t5;
	uint32_t dword;
}STM32FXXXUSART2and5_OR_TypeDef;
typedef union{
	struct OR_8{
		uint32_t ti1_rmp:2;
		uint32_t fill2:30;
	}t10_11;
	uint32_t dword;
}STM32FXXXUSART10and11_OR_TypeDef;

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

