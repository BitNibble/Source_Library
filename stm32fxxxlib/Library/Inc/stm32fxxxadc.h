/******************************************************************************
	STM32 XXX ADC
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 19062023
Update 10012024
Comment:
	
*******************************************************************************/
#ifndef _STM32FXXXADC_H_
	#define _STM32FXXXADC_H_

/*** Library ***/
#include "armquery.h"

/*** ADC Bit Mapping TypeDef ***/
// SR
typedef struct
{
	uint8_t (*ovr)(void);
	void (*clear_ovr)(void);
	uint8_t (*strt)(void);
	void (*clear_strt)(void);
	uint8_t (*jstrt)(void);
	void (*clear_jstrt)(void);
	uint8_t (*jeoc)(void);
	void (*clear_jeoc)(void);
	uint8_t (*eoc)(void);
	void (*clear_eoc)(void);
	uint8_t (*awd)(void);
	void (*clear_awd)(void);
}STM32FXXXADC_SR;
/***
volatile typedef union {
	struct SR_1{
		uint32_t awd:1;
		uint32_t eoc:1;
		uint32_t jeoc:1;
		uint32_t jstrt:1;
		uint32_t strt:1;
		uint32_t ovr:1;
		uint32_t fill:26;
	}par;
	uint32_t reg;
}STM32FXXXADC_SR_TypeDef;
***/
// CR1
typedef struct
{
	void (*ovrie)(uint8_t bool);
	void (*res)(uint8_t value);
	void (*awden)(uint8_t bool);
	void (*jawden)(uint8_t bool);
	void (*discnum)(uint8_t value);
	void (*jdiscen)(uint8_t bool);
	void (*discen)(uint8_t bool);
	void (*jauto)(uint8_t bool);
	void (*awdsgl)(uint8_t bool);
	void (*scan)(uint8_t bool);
	void (*jeocie)(uint8_t bool);
	void (*awdie)(uint8_t bool);
	void (*eocie)(uint8_t bool);
	void (*awdch)(uint8_t value);
}STM32FXXXADC_CR1;
/***
volatile typedef union {
	struct CR1_1{
		uint32_t awdch:5;
		uint32_t eocie:1;
		uint32_t awdie:1;
		uint32_t jeocie:1;
		uint32_t scan:1;
		uint32_t awd_sgl:1;
		uint32_t jauto:1;
		uint32_t discen:1;
		uint32_t jdiscen:1;
		uint32_t discnum:3;
		uint32_t reserved1:6;
		uint32_t jawden:1;
		uint32_t awden:1;
		uint32_t res:2;
		uint32_t ovrie:1;
		uint32_t reserved2:5;
	}par;
	uint32_t reg;
}STM32FXXXADC_CR1_TypeDef;
***/
// CR2
typedef struct
{
	void (*swstart)(uint8_t bool);
	uint8_t (*read_swstart)(void);
	void (*exten)(uint8_t value);
	void (*extsel)(uint8_t value);
	void (*jswstart)(uint8_t bool);
	void (*jexten)(uint8_t value);
	void (*jextsel)(uint8_t value);
	void (*align)(uint8_t bool);
	void (*eocs)(uint8_t bool);
	void (*dds)(uint8_t bool);
	void (*dma)(uint8_t bool);
	void (*cont)(uint8_t bool);
	void (*adon)(uint8_t bool);
}STM32FXXXADC_CR2;
/***
volatile typedef union {
	struct CR2_1{
		uint32_t adon:1;
		uint32_t cont:1;
		uint32_t reserved1:6;
		uint32_t dma:1;
		uint32_t dds:1;
		uint32_t eocs:1;
		uint32_t align:1;
		uint32_t reserved2:4;
		uint32_t jextsel:4;
		uint32_t jexten:2;
		uint32_t jswstart:1;
		uint32_t reserved3:1;
		uint32_t extsel:4;
		uint32_t exten:2;
		uint32_t swstart:1;
		uint32_t reserved4:1;
	}par;
	uint32_t reg;
}STM32FXXXADC_CR2_TypeDef;
***/
// SMPR1
typedef struct
{
	void (*smp18)(uint8_t value);
	void (*smp17)(uint8_t value);
	void (*smp16)(uint8_t value);
	void (*smp15)(uint8_t value);
	void (*smp15_0)(uint8_t bool);
	void (*smp14)(uint8_t value);
	void (*smp13)(uint8_t value);
	void (*smp12)(uint8_t value);
	void (*smp11)(uint8_t value);
	void (*smp10)(uint8_t value);
}STM32FXXXADC_SMPR1;
/***
volatile typedef union {
	struct SMPR1_1{
		uint32_t smp10:3;
		uint32_t smp11:3;
		uint32_t smp12:3;
		uint32_t smp13:3;
		uint32_t smp14:3;
		uint32_t smp15:3;
		uint32_t smp16:3;
		uint32_t smp17:3;
		uint32_t smp18:3;
		uint32_t reserved:5;
	}par;
	uint32_t reg;
}STM32FXXXADC_SMPR1_TypeDef;
***/
// SMPR2
typedef struct
{
	void (*smp9)(uint8_t value);
	void (*smp8)(uint8_t value);
	void (*smp7)(uint8_t value);
	void (*smp6)(uint8_t value);
	void (*smp5)(uint8_t bool);
	void (*smp5_0)(uint8_t bool);
	void (*smp4)(uint8_t value);
	void (*smp3)(uint8_t value);
	void (*smp2)(uint8_t value);
	void (*smp1)(uint8_t value);
	void (*smp0)(uint8_t value);
}STM32FXXXADC_SMPR2;
/***
volatile typedef union {
	struct SMPR2_1{
		uint32_t smp0:3;
		uint32_t smp1:3;
		uint32_t smp2:3;
		uint32_t smp3:3;
		uint32_t smp4:3;
		uint32_t smp5:3;
		uint32_t smp6:3;
		uint32_t smp7:3;
		uint32_t smp8:3;
		uint32_t smp9:3;
		uint32_t reserved:2;
	}par;
	uint32_t reg;
}STM32FXXXADC_SMPR2_TypeDef;
***/
// JOFRx
/***
volatile typedef union {
	struct JOFRx_1{
		uint32_t joffset:12;
		uint32_t reserved:20;
	}par;
	uint32_t reg;
}STM32FXXXADC_JOFRx_TypeDef;
***/
// HTR
/***
volatile typedef union {
	struct HTR_1{
		uint32_t ht:12;
		uint32_t reserved:20;
	}par;
	uint32_t reg;
}STM32FXXXADC_HTR_TypeDef;
***/
// LTR
/***
volatile typedef union {
	struct LTR_1{
		uint32_t lt:12;
		uint32_t reserved:20;
	}par;
	uint32_t reg;
}STM32FXXXADC_LTR_TypeDef;
***/
// SQR1
typedef struct
{
	void (*l)(uint8_t value);
	void (*sq16)(uint8_t value);
	void (*sq16_0)(uint8_t bool);
	void (*sq15)(uint8_t value);
	void (*sq14)(uint8_t value);
	void (*sq13)(uint8_t value);
}STM32FXXXADC_SQR1;
/***
volatile typedef union {
	struct SQR1_1{
		uint32_t sq13:5;
		uint32_t sq14:5;
		uint32_t sq15:5;
		uint32_t sq16:5;
		uint32_t l:4;
		uint32_t reserved:8;
	}par;
	uint32_t reg;
}STM32FXXXADC_SQR1_TypeDef;
***/
// SQR2
typedef struct
{
	void (*sq12)(uint8_t value);
	void (*sq11)(uint8_t value);
	void (*sq10)(uint8_t value);
	void (*sq10_0)(uint8_t bool);
	void (*sq9)(uint8_t value);
	void (*sq8)(uint8_t value);
	void (*sq7)(uint8_t value);
}STM32FXXXADC_SQR2;
/***
volatile typedef union {
	struct SQR2_1{
		uint32_t sq7:5;
		uint32_t sq8:5;
		uint32_t sq9:5;
		uint32_t sq10:5;
		uint32_t sq11:5;
		uint32_t sq12:5;
		uint32_t reserved:2;
	}par;
	uint32_t reg;
}STM32FXXXADC_SQR2_TypeDef;
***/
// SQR3
typedef struct
{
	void (*sq6)(uint8_t value);
	void (*sq5)(uint8_t value);
	void (*sq4)(uint8_t value);
	void (*sq4_0)(uint8_t bool);
	void (*sq3)(uint8_t value);
	void (*sq2)(uint8_t value);
	void (*sq1)(uint8_t value);
}STM32FXXXADC_SQR3;
/***
volatile typedef union {
	struct SQR3_1{
		uint32_t sq1:5;
		uint32_t sq2:5;
		uint32_t sq3:5;
		uint32_t sq4:5;
		uint32_t sq5:5;
		uint32_t sq6:5;
		uint32_t reserved:2;
	}par;
	uint32_t reg;
}STM32FXXXADC_SQR3_TypeDef;
***/
// JSQR
typedef struct
{
	void (*jl)(uint8_t value);
	void (*jsq4)(uint8_t value);
	void (*jsq4_0)(uint8_t bool);
	void (*jsq3)(uint8_t value);
	void (*jsq2)(uint8_t value);
	void (*jsq1)(uint8_t value);
}STM32FXXXADC_JSQR;
/***
volatile typedef union {
	struct JSQR_1{
		uint32_t jsq1:5;
		uint32_t jsq2:5;
		uint32_t jsq3:5;
		uint32_t jsq4:5;
		uint32_t jl:2;
		uint32_t reserved:10;
	}par;
	uint32_t reg;
}STM32FXXXADC_JSQR_TypeDef;
***/
// JDRx
/***
volatile typedef union {
	struct JDRx_1{
		uint16_t jdata;
		uint16_t reserved;
	}par;
	uint32_t reg;
}STM32FXXXADC_JDRx_TypeDef;
***/
// DR
/***
volatile typedef union {
	struct DR_1{
		uint16_t data;
		uint16_t reserved;
	}par;
	uint32_t reg;
}STM32FXXXADC_DR_TypeDef;
***/
// CSR
volatile typedef union {
	struct CSR_1{
		uint32_t awd1:1;
		uint32_t eoc1:1;
		uint32_t jeoc1:1;
		uint32_t jstrt1:1;
		uint32_t strt1:1;
		uint32_t ovr1:1;
		uint32_t reserved1:2;
		uint32_t awd2:1;
		uint32_t eoc2:1;
		uint32_t jeoc2:1;
		uint32_t jstrt2:1;
		uint32_t strt2:1;
		uint32_t ovr2:1;
		uint32_t reserved2:2;
		uint32_t awd3:1;
		uint32_t eoc3:1;
		uint32_t jeoc3:1;
		uint32_t jstrt3:1;
		uint32_t strt3:1;
		uint32_t ovr3:1;
		uint32_t reserved3:10;
	}par;
	struct CSR_2{
		uint32_t awd1:1;
		uint32_t eoc1:1;
		uint32_t jeoc1:1;
		uint32_t jstrt1:1;
		uint32_t strt1:1;
		uint32_t ovr1:1;
		uint32_t reserved:26;
	}adc1_par;
	struct CSR_3{
		uint32_t reserved1:8;
		uint32_t awd2:1;
		uint32_t eoc2:1;
		uint32_t jeoc2:1;
		uint32_t jstrt2:1;
		uint32_t strt2:1;
		uint32_t ovr2:1;
		uint32_t reserved2:18;
	}adc2_par;
	struct CSR_4{
		uint32_t reserved1:16;
		uint32_t awd3:1;
		uint32_t eoc3:1;
		uint32_t jeoc3:1;
		uint32_t jstrt3:1;
		uint32_t strt3:1;
		uint32_t ovr3:1;
		uint32_t reserved2:10;
	}adc3_par;
	uint32_t reg;
}STM32FXXXADC_CSR_TypeDef;
// CCR
volatile typedef union {
	struct CCR_1{
		uint16_t reserved1;
		uint16_t adcpre:2;
		uint16_t reserved2:4;
		uint16_t vbate:1;
		uint16_t tsvrefe:1;
		uint16_t reserved3:8;
	}par;
	uint32_t reg;
}STM32FXXXADC_CCR_TypeDef;
/*** ADC_Common TypeDef ***/
typedef struct
{

	STM32FXXXADC_CSR_TypeDef* csr;
	STM32FXXXADC_CCR_TypeDef* ccr;
	uint32_t (*cdr)(void);
}STM32FXXXADCCOMMONobj;
/*** ADC1 Procedure & Function TypeDef ***/
typedef struct
{
	void (*inic)(void);
	void (*vbat)(void);
	void (*temp)(void);
	void (*start)(void);
}STM32FXXXADC1single, STM32FXXXADC2single, STM32FXXXADC3single;
/*** ADC Common Header ***/
// CDR
uint32_t STM32FXXXADC_cdr(void);

STM32FXXXADCCOMMONobj* stm32fxxx_adc_common_inic(void);

/*** INTERRUPT HEADER ***/
void ADC_IRQHandler(void);

#endif

/***EOF***/

