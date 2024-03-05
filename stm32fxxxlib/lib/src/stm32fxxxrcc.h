/******************************************************************************
	STM32 FXXX RCC
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-FXXX
Date: 19062023
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
	STM32FXXXRCC_cr* cr;
	STM32FXXXRCC_pllcfgr* pllcfgr;
	STM32FXXXRCC_cfgr* cfgr;
	STM32FXXXRCC_cir* cir;
	STM32FXXXRCC_ahb1rstr* ahb1rstr;
	STM32FXXXRCC_ahb2rstr* ahb2rstr;
	STM32FXXXRCC_ahb3rstr* ahb3rstr;
	STM32FXXXRCC_apb1rstr* apb1rstr;
	STM32FXXXRCC_apb2rstr* apb2rstr;
	STM32FXXXRCC_ahb1enr* ahb1enr;
	STM32FXXXRCC_ahb2enr* ahb2enr;
	STM32FXXXRCC_apb1enr* apb1enr;
	STM32FXXXRCC_apb2enr* apb2enr;
	STM32FXXXRCC_ahb1lpenr* ahb1lpenr;
	STM32FXXXRCC_ahb2lpenr* ahb2lpenr;
	STM32FXXXRCC_ahb3lpenr* ahb3lpenr;
	STM32FXXXRCC_apb1lpenr* apb1lpenr;
	STM32FXXXRCC_apb2lpenr* apb2lpenr;
	STM32FXXXRCC_bdcr* bdcr;
	STM32FXXXRCC_csr* csr;
	STM32FXXXRCC_sscgr* sscgr;
	STM32FXXXRCC_plli2scfgr* plli2scfgr;
	STM32FXXXRCC_dckcfgr* dckcfgr;
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
/*** RCC Bit Mapping Header ***/
// CR
uint8_t STM32FXXXRCC_CR_get_pllsairdy(void);
void STM32FXXXRCC_CR_pllsaion(uint8_t bool);
uint8_t STM32FXXXRCC_CR_get_plli2srdy(void);
void STM32FXXXRCC_CR_plli2son(uint8_t bool);
uint8_t STM32FXXXRCC_CR_get_pllrdy(void);
void STM32FXXXRCC_CR_pllon(uint8_t bool);
void STM32FXXXRCC_CR_csson(uint8_t bool);
void STM32FXXXRCC_CR_hsebyp(uint8_t bool);
uint8_t STM32FXXXRCC_CR_get_hserdy(void);
void STM32FXXXRCC_CR_hseon(uint8_t bool);
uint8_t STM32FXXXRCC_CR_get_hsical(void);
void STM32FXXXRCC_CR_hsitrim(uint8_t value);
uint8_t STM32FXXXRCC_CR_get_hsirdy(void);
void STM32FXXXRCC_CR_hsion(uint8_t bool);
// PLLCFGR
void STM32FXXXRCC_PLLCFGR_pllr(uint8_t value);
void STM32FXXXRCC_PLLCFGR_pllq(uint8_t value);
void STM32FXXXRCC_PLLCFGR_pllsrc(uint8_t bool);
void STM32FXXXRCC_PLLCFGR_pllp(uint8_t value);
void STM32FXXXRCC_PLLCFGR_plln(uint16_t value);
void STM32FXXXRCC_PLLCFGR_pllm(uint8_t value);
// CFGR
void STM32FXXXRCC_CFGR_mco2(uint8_t value);
void STM32FXXXRCC_CFGR_mco2pre(uint8_t value);
void STM32FXXXRCC_CFGR_mco1pre(uint8_t value);
void STM32FXXXRCC_CFGR_mco1(uint8_t value);
void STM32FXXXRCC_CFGR_rtcpre(uint8_t value);
void STM32FXXXRCC_CFGR_ppre2(uint8_t value);
void STM32FXXXRCC_CFGR_ppre1(uint8_t value);
void STM32FXXXRCC_CFGR_hpre(uint8_t value);
uint8_t STM32FXXXRCC_CFGR_get_sws(void);
void STM32FXXXRCC_CFGR_sw(uint8_t value);
// CIR
void STM32FXXXRCC_CIR_clear_cssc(void);
void STM32FXXXRCC_CIR_clear_pllsairdyc(void);
void STM32FXXXRCC_CIR_clear_plli2srdyc(void);
void STM32FXXXRCC_CIR_clear_pllrdyc(void);
void STM32FXXXRCC_CIR_clear_hserdyc(void);
void STM32FXXXRCC_CIR_clear_hsirdyc(void);
void STM32FXXXRCC_CIR_clear_lserdyc(void);
void STM32FXXXRCC_CIR_clear_lsirdyc(void);
void STM32FXXXRCC_CIR_pllsairdyie(uint8_t bool);
void STM32FXXXRCC_CIR_plli2srdyie(uint8_t bool);
void STM32FXXXRCC_CIR_pllrdyie(uint8_t bool);
void STM32FXXXRCC_CIR_hserdyie(uint8_t bool);
void STM32FXXXRCC_CIR_hsirdyie(uint8_t bool);
void STM32FXXXRCC_CIR_lserdyie(uint8_t bool);
void STM32FXXXRCC_CIR_lsirdyie(uint8_t bool);
uint8_t STM32FXXXRCC_CIR_get_cssf(void);
uint8_t STM32FXXXRCC_CIR_get_pllsairdyf(void);
uint8_t STM32FXXXRCC_CIR_get_plli2srdyf(void);
uint8_t STM32FXXXRCC_CIR_get_pllrdyf(void);
uint8_t STM32FXXXRCC_CIR_get_hserdyf(void);
uint8_t STM32FXXXRCC_CIR_get_hsirdyf(void);
uint8_t STM32FXXXRCC_CIR_get_lserdyf(void);
uint8_t STM32FXXXRCC_CIR_get_lsirdyf(void);
// AHB1RSTR
void STM32FXXXRCC_AHB1RSTR_otghsrst(uint8_t bool);
void STM32FXXXRCC_AHB1RSTR_dma2rst(uint8_t bool);
void STM32FXXXRCC_AHB1RSTR_dma1rst(uint8_t bool);
void STM32FXXXRCC_AHB1RSTR_crcrst(uint8_t bool);
void STM32FXXXRCC_AHB1RSTR_gpiohrst(uint8_t bool);
void STM32FXXXRCC_AHB1RSTR_gpiogrst(uint8_t bool);
void STM32FXXXRCC_AHB1RSTR_gpiofrst(uint8_t bool);
void STM32FXXXRCC_AHB1RSTR_gpioerst(uint8_t bool);
void STM32FXXXRCC_AHB1RSTR_gpiodrst(uint8_t bool);
void STM32FXXXRCC_AHB1RSTR_gpiocrst(uint8_t bool);
void STM32FXXXRCC_AHB1RSTR_gpiobrst(uint8_t bool);
void STM32FXXXRCC_AHB1RSTR_gpioarst(uint8_t bool);
// AHB2RSTR
void STM32FXXXRCC_AHB2RSTR_otgfsrst(uint8_t bool);
void STM32FXXXRCC_AHB2RSTR_dcmirst(uint8_t bool);
// AHB3RSTR
void STM32FXXXRCC_AHB3RSTR_qspirst(uint8_t bool);
void STM32FXXXRCC_AHB3RSTR_fmcrst(uint8_t bool);
// APB1RSTR
void STM32FXXXRCC_APB1RSTR_dacrst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_pwrrst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_cecrst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_can2rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_can1rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_fmpi2c1rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_i2c3rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_i2c2rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_i2c1rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_uart5rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_uart4rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_usart3rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_usart2rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_spdifrxrst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_spi3rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_spi2rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_wwdgrst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_tim14rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_tim13rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_tim12rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_tim7rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_tim6rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_tim5rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_tim4rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_tim3rst(uint8_t bool);
void STM32FXXXRCC_APB1RSTR_tim2rst(uint8_t bool);
// APB2RSTR
void STM32FXXXRCC_APB2RSTR_sai2rst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_sai1rst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_tim11rst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_tim10rst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_tim9rst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_syscfgrst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_spi4rst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_spi1rst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_sdiorst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_adcrst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_usart6rst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_usart1rst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_tim8rst(uint8_t bool);
void STM32FXXXRCC_APB2RSTR_tim1rst(uint8_t bool);
// AHB1ENR
void STM32FXXXRCC_AHB1ENR_otghsulpien(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_otghsen(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_dma2en(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_dma1en(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_bkpsramen(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_crcen(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_gpiohen(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_gpiogen(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_gpiofen(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_gpioeen(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_gpioden(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_gpiocen(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_gpioben(uint8_t bool);
void STM32FXXXRCC_AHB1ENR_gpioaen(uint8_t bool);
// AHB2ENR
void STM32FXXXRCC_AHB2ENR_otgfsen(uint8_t bool);
void STM32FXXXRCC_AHB2ENR_dcmien(uint8_t bool);
// AHB3ENR
void STM32FXXXRCC_AHB3ENR_qspien(uint8_t bool);
void STM32FXXXRCC_AHB3ENR_fmcen(uint8_t bool);
// APB1ENR
void STM32FXXXRCC_APB1ENR_dacen(uint8_t bool);
void STM32FXXXRCC_APB1ENR_pwren(uint8_t bool);
void STM32FXXXRCC_APB1ENR_cecen(uint8_t bool);
void STM32FXXXRCC_APB1ENR_can2en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_can1en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_fmpi2c1en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_i2c3en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_i2c2en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_i2c1en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_uart5en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_uart4en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_usart3en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_usart2en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_spdifrxen(uint8_t bool);
void STM32FXXXRCC_APB1ENR_spi3en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_spi2en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_wwdgen(uint8_t bool);
void STM32FXXXRCC_APB1ENR_tim14en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_tim13en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_tim12en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_tim7en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_tim6en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_tim5en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_tim4en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_tim3en(uint8_t bool);
void STM32FXXXRCC_APB1ENR_tim2en(uint8_t bool);
// APB2ENR
void STM32FXXXRCC_APB2ENR_sai2en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_sai1en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_tim11en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_tim10en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_tim9en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_syscfgen(uint8_t bool);
void STM32FXXXRCC_APB2ENR_spi4en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_spi1en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_sdioen(uint8_t bool);
void STM32FXXXRCC_APB2ENR_adc3en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_adc2en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_adc1en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_usart6en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_usart1en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_tim8en(uint8_t bool);
void STM32FXXXRCC_APB2ENR_tim1en(uint8_t bool);
//AHB1LPENR
void STM32FXXXRCC_AHB1LPENR_otghsulpilpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_otghslpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_dma2lpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_dma1lpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_bkpsramlpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_sram2lpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_sram1lpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_flitflpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_crclpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_gpiohlpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_gpioglpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_gpioflpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_gpioelpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_gpiodlpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_gpioclpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_gpioblpen(uint8_t bool);
void STM32FXXXRCC_AHB1LPENR_gpioalpen(uint8_t bool);
// AHB2LPENR
void STM32FXXXRCC_AHB2LPENR_otgfslpen(uint8_t bool);
void STM32FXXXRCC_AHB2LPENR_dcmilpen(uint8_t bool);
// AHB3LPENR
void STM32FXXXRCC_AHB3LPENR_qspilpen(uint8_t bool);
void STM32FXXXRCC_AHB3LPENR_fmclpen(uint8_t bool);
// APB1LPENR
void STM32FXXXRCC_APB1LPENR_daclpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_pwrlpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_ceclpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_can2lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_can1lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_fmpi2c1lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_i2c3lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_i2c2lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_i2c1lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_uart5lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_uart4lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_usart3lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_usart2lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_spdifrxlpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_spi3lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_spi2lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_wwdglpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_tim14lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_tim13lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_tim12lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_tim7lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_tim6lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_tim5lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_tim4lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_tim3lpen(uint8_t bool);
void STM32FXXXRCC_APB1LPENR_tim2lpen(uint8_t bool);
// APB2LPENR
void STM32FXXXRCC_APB2LPENR_sai2lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_sai1lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_tim11lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_tim10lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_tim9lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_syscfglpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_spi4lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_spi1lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_sdiolpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_adc3lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_adc2lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_adc1lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_usart6lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_usart1lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_tim8lpen(uint8_t bool);
void STM32FXXXRCC_APB2LPENR_tim1lpen(uint8_t bool);
// BDCR
void STM32FXXXRCC_BDCR_bdrst(uint8_t bool);
void STM32FXXXRCC_BDCR_rtcen(uint8_t bool);
void STM32FXXXRCC_BDCR_rtcsel(uint8_t value);
void STM32FXXXRCC_BDCR_lsemod(uint8_t bool);
void STM32FXXXRCC_BDCR_lsebyp(uint8_t bool);
uint8_t STM32FXXXRCC_BDCR_get_lserdy(void);
void STM32FXXXRCC_BDCR_lseon(uint8_t bool);
// CSR
uint8_t STM32FXXXRCC_CSR_get_lpwrrstf(void);
uint8_t STM32FXXXRCC_CSR_get_wwdgrstf(void);
uint8_t STM32FXXXRCC_CSR_get_iwdqrstf(void);
uint8_t STM32FXXXRCC_CSR_get_sftrstf(void);
uint8_t STM32FXXXRCC_CSR_get_porrstf(void);
uint8_t STM32FXXXRCC_CSR_get_pinrstf(void);
uint8_t STM32FXXXRCC_CSR_get_borrstf(void);
void STM32FXXXRCC_CSR_clear_rmvf(void);
uint8_t STM32FXXXRCC_CSR_get_lsirdy(void);
void STM32FXXXRCC_CSR_lsion(uint8_t bool);
// SSCGR
void STM32FXXXRCC_SSCGR_sscgen(uint8_t bool);
void STM32FXXXRCC_SSCGR_spreadsel(uint8_t bool);
void STM32FXXXRCC_SSCGR_incstep(uint8_t value);
void STM32FXXXRCC_SSCGR_modper(uint8_t value);
// PLLI2SCFGR
void STM32FXXXRCC_PLLI2SCFGR_plli2sr(uint8_t value);
void STM32FXXXRCC_PLLI2SCFGR_plli2sq(uint8_t value);
void STM32FXXXRCC_PLLI2SCFGR_plli2sp(uint8_t value);
void STM32FXXXRCC_PLLI2SCFGR_plli2sn(uint16_t value);
void STM32FXXXRCC_PLLI2SCFGR_plli2sm(uint8_t value);
// DCKCFGR
void STM32FXXXRCC_DCKCFGR_i2s2src(uint8_t value);
void STM32FXXXRCC_DCKCFGR_i2s1src(uint8_t value);
void STM32FXXXRCC_DCKCFGR_timpre(uint8_t bool);
void STM32FXXXRCC_DCKCFGR_sai2src(uint8_t value);
void STM32FXXXRCC_DCKCFGR_sai1src(uint8_t value);
void STM32FXXXRCC_DCKCFGR_pllsaidivq(uint8_t value);
void STM32FXXXRCC_DCKCFGR_plli2sdivq(uint8_t value);

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

