/******************************************************************************
	STM32 FXXX RCC
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-FXXX
Date: 19062023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxrcc.h"

/*** File Variables ***/
static STM32FXXXRCC_cr stm32fxxx_rcc_cr;
static STM32FXXXRCC_pllcfgr stm32fxxx_rcc_pllcfgr;
static STM32FXXXRCC_cfgr stm32fxxx_rcc_cfgr;
static STM32FXXXRCC_cir stm32fxxx_rcc_cir;
static STM32FXXXRCC_ahb1rstr stm32fxxx_rcc_ahb1rstr;
static STM32FXXXRCC_ahb2rstr stm32fxxx_rcc_ahb2rstr;
static STM32FXXXRCC_apb1rstr stm32fxxx_rcc_apb1rstr;
static STM32FXXXRCC_apb2rstr stm32fxxx_rcc_apb2rstr;
static STM32FXXXRCC_ahb1enr stm32fxxx_rcc_ahb1enr;
static STM32FXXXRCC_ahb2enr stm32fxxx_rcc_ahb2enr;
static STM32FXXXRCC_apb1enr stm32fxxx_rcc_apb1enr;
static STM32FXXXRCC_apb2enr stm32fxxx_rcc_apb2enr;
static STM32FXXXRCC_ahb1lpenr stm32fxxx_rcc_ahb1lpenr;
static STM32FXXXRCC_ahb2lpenr stm32fxxx_rcc_ahb2lpenr;
static STM32FXXXRCC_apb1lpenr stm32fxxx_rcc_apb1lpenr;
static STM32FXXXRCC_apb2lpenr stm32fxxx_rcc_apb2lpenr;
static STM32FXXXRCC_bdcr stm32fxxx_rcc_bdcr;
static STM32FXXXRCC_csr stm32fxxx_rcc_csr;
static STM32FXXXRCC_sscgr stm32fxxx_rcc_sscgr;
static STM32FXXXRCC_plli2scfgr stm32fxxx_rcc_plli2scfgr;
static STM32FXXXRCC_dckcfgr stm32fxxx_rcc_dckcfgr;
static STM32FXXXRCCPLL stm32fxxx_rcc_pll;
static STM32FXXXRCCPLLI2S stm32fxxx_rcc_plli2s;
static STM32FXXXRCCPLLSAI stm32fxxx_rcc_pllsai;
static STM32FXXXRCCobj stm32fxxx_rcc;

/*** File Procedure & Function Header ***/
STM32FXXXRCC_cr* stm32fxxx_rcc_cr_inic(void);
STM32FXXXRCC_pllcfgr* stm32fxxx_rcc_pllcfgr_inic(void);
STM32FXXXRCC_cfgr* stm32fxxx_rcc_cfgr_inic(void);
STM32FXXXRCC_cir* stm32fxxx_rcc_cir_inic(void);
STM32FXXXRCC_ahb1rstr* stm32fxxx_rcc_ahb1rstr_inic(void);
STM32FXXXRCC_ahb2rstr* stm32fxxx_rcc_ahb2rstr_inic(void);
STM32FXXXRCC_ahb3rstr* stm32fxxx_rcc_ahb3rstr_inic(void);
STM32FXXXRCC_apb1rstr* stm32fxxx_rcc_apb1rstr_inic(void);
STM32FXXXRCC_apb2rstr* stm32fxxx_rcc_apb2rstr_inic(void);
STM32FXXXRCC_ahb1enr* stm32fxxx_rcc_ahb1enr_inic(void);
STM32FXXXRCC_ahb2enr* stm32fxxx_rcc_ahb2enr_inic(void);
STM32FXXXRCC_apb1enr* stm32fxxx_rcc_apb1enr_inic(void);
STM32FXXXRCC_apb2enr* stm32fxxx_rcc_apb2enr_inic(void);
STM32FXXXRCC_ahb1lpenr* stm32fxxx_rcc_ahb1lpenr_inic(void);
STM32FXXXRCC_ahb2lpenr* stm32fxxx_rcc_ahb2lpenr_inic(void);
STM32FXXXRCC_ahb3lpenr* stm32fxxx_rcc_ahb3lpenr_inic(void);
STM32FXXXRCC_apb1lpenr* stm32fxxx_rcc_apb1lpenr_inic(void);
STM32FXXXRCC_apb2lpenr* stm32fxxx_rcc_apb2lpenr_inic(void);
STM32FXXXRCC_bdcr* stm32fxxx_rcc_bdcr_inic(void);
STM32FXXXRCC_csr* stm32fxxx_rcc_csr_inic(void);
STM32FXXXRCC_sscgr* stm32fxxx_rcc_sscgr_inic(void);
STM32FXXXRCC_plli2scfgr* stm32fxxx_rcc_plli2scfgr_inic(void);
STM32FXXXRCC_dckcfgr* stm32fxxx_rcc_dckcfgr_inic(void);
/*** Extended ***/
STM32FXXXRCCPLL* stm32fxxx_rcc_pll_inic(void);
STM32FXXXRCCPLLI2S* stm32fxxx_rcc_plli2s_inic(void);
STM32FXXXRCCPLLSAI* stm32fxxx_rcc_pllsai_inic(void);
/******/
void STM32FXXXRccPwrClock(uint8_t bool);
void STM32FXXXRccWriteEnable(void);
void STM32FXXXRccWriteDisable(void);
uint8_t STM32FXXXRccPLLSelect(uint8_t hclock);

/*****   0 -> HSI    1->HSE   *******/
#ifndef H_Clock_Source
	#define H_Clock_Source 0
#endif
/************************************/

/*** RCC Procedure & Function Definition ***/
void rcc_start(void)
{
	// M 2 to 63  N 50 to 432  P 2,4,6,8  Q 2 to 15  R 2 to 7  (2Mhz ideal, N/m  *  clkx)
	STM32FXXXPLLDivision(16, 192, 2, 4);
    // AHB 1,2,4,8,16,64,128,256,512  APB1 1,2,4,8,16  APB2 1,2,4,8,16  RTC 2 to 31
	STM32FXXXPrescaler(8, 1, 1, 0);
	// Selection
	STM32FXXXRccHEnable(H_Clock_Source); // 0 - HSI 1 - HSE 2 - HSEBYP
	STM32FXXXRccPLLCLKEnable();
	STM32FXXXRccPLLSelect(H_Clock_Source); // 0 - HSI, 1 - HSE
	STM32FXXXRccHSelect(2); // SW[1:0]: System clock switch 00 - HSI, 01 - HSE, 02 - PLL_P, 03 - PLL_R pg133 (manual 2)
}
// RCC
void STM32FXXXRccHEnable(uint8_t hclock)
{
	uint8_t set;
	uint8_t rdy;
	setreg(&RCC->CR, 1, 19, 1); // CSSON
	for( set = 1, rdy = 1; rdy ; ){
		if(hclock == 0){ // HSION: Internal high-speed clock enable
			if( set ){ STM32FXXXRccWriteEnable(); RCC->CR |= ( 1 << 0); STM32FXXXRccWriteDisable(); set = 0; }else if( RCC->CR & ( 1 << 1) ) rdy = 0;
		}
		else if(hclock == 1){ // HSEON: HSE clock enable
			if( set ){ STM32FXXXRccWriteEnable(); RCC->CR |= ( 1 << 16); STM32FXXXRccWriteDisable(); set = 0; }else if( RCC->CR & ( 1 << 17) ) rdy = 0;
		}
		else if(hclock == 2){ // HSEBYP: HSE clock bypass
			if( set ){ STM32FXXXRccWriteEnable(); RCC->CR |= ( 1 << 18 ); STM32FXXXRccWriteDisable(); }
			hclock = 1;
		}
		else hclock = 0; // default
	}
}
uint8_t STM32FXXXRccHSelect(uint8_t hclock)
{ // SW[1:0]: System clock switch 00 - HSI, 01 - HSE pg133
	STM32FXXXRccWriteEnable();
	RCC->CFGR &= (uint32_t) ~(3);
	STM32FXXXRccWriteDisable();
	switch(hclock){
		case 1: // HSE oscillator selected as system clock
			STM32FXXXRccWriteEnable();
			RCC->CFGR |= 1;
			STM32FXXXRccWriteDisable();
		break;
		case 2: // PLL_P selected as system clock
			STM32FXXXRccWriteEnable();
			RCC->CFGR |= 2;
			STM32FXXXRccWriteDisable();
		break;
		case 3: // PLL_R selected as system clock
			#ifdef STM32F446xx
				STM32FXXXRccWriteEnable();
				RCC->CFGR |= 3;
				STM32FXXXRccWriteDisable();
			#endif
		break;
		default: // 00: HSI oscillator selected as system clock
		break;
	}
	return (RCC->CFGR >> 2) & 3;
}
uint8_t STM32FXXXRccPLLSelect(uint8_t hclock)
{ // This bit can be written only when PLL and PLLI2S are disabled
	setreg(&RCC->CR, 1, 24, 0); setreg(&RCC->CR, 1, 26, 0); setreg(&RCC->CR, 1, 28, 0);
	switch(hclock){
		case 0: // HSI
			setreg(&RCC->PLLCFGR, 1, 22, 0);
		break;
		case 1: // HSE
			setreg(&RCC->PLLCFGR, 1, 22, 1);
		break;
		default: // HSI
			setreg(&RCC->PLLCFGR, 1, 22, 0);
		break;
	}
	setreg(&RCC->CR, 1, 24, 1); setreg(&RCC->CR, 1, 26, 1); setreg(&RCC->CR, 1, 28, 1);
	return readreg(RCC->PLLCFGR, 1, 22);
}
void STM32FXXXRccLEnable(uint8_t lclock)
{
	uint8_t set;
	uint8_t rdy;
	for( set = 1, rdy = 1; rdy ; ){
		if(lclock == 2){ // LSION: Internal low-speed oscillator enable
			if( set ){ STM32FXXXRccWriteEnable(); RCC->CSR |= ( 1 << 0); STM32FXXXRccWriteDisable(); set = 0; }else if( RCC->CSR & ( 1 << 1) ) rdy = 0;
		}
		else if(lclock == 1){ // LSEON: External low-speed oscillator enable
			if( set ){ STM32FXXXRccWriteEnable(); RCC->BDCR |= ( 1 << 0); STM32FXXXRccWriteDisable(); set = 0; }else if( RCC->BDCR & ( 1 << 1) ) rdy = 0;
		}
		else if(lclock == 4){ // LSEBYP: External low-speed oscillator bypass
			if( set ){ STM32FXXXRccWriteEnable(); RCC->BDCR |= ( 1 << 2 ); STM32FXXXRccWriteDisable(); }
			lclock = 1;
		}
		else lclock = 2; // default
	}
}
void STM32FXXXRccLSelect(uint8_t lclock)
{
	STM32FXXXRccWriteEnable();
	RCC->BDCR &= (uint32_t) ~((1 << 9) | (1 << 8)); // Clear
	STM32FXXXRccWriteDisable();
	switch(lclock){
		case 2: // LSI oscillator clock used as the RTC clock
			STM32FXXXRccWriteEnable();
			RCC->BDCR |= (1 << 9);
			STM32FXXXRccWriteDisable();
		break;
		case 1: // LSE oscillator clock used as the RTC clock
			STM32FXXXRccWriteEnable();
			RCC->BDCR |= (1 << 8);
			STM32FXXXRccWriteDisable();
		break;
		case 3: // HSE oscillator clock divided by a programmable prescaler
			STM32FXXXRccWriteEnable();
			RCC->BDCR |= ((1 << 8) | (1 << 9));
			STM32FXXXRccWriteDisable();
		break;
		default: // LSE oscillator clock used as the RTC clock
			STM32FXXXRccWriteEnable();
			RCC->BDCR |= (1 << 8);
			STM32FXXXRccWriteDisable();
		break;
	}
}
void STM32FXXXPrescaler(uint16_t ahbpre, uint8_t ppre1, uint8_t ppre2, uint8_t rtcpre)
{
	const unsigned int mask = 0x001FFCF0;
	RCC->CFGR &= (unsigned int) ~mask; // clear args
	if(rtcpre > 1 && rtcpre < 32) // 16
		RCC->CFGR |= (rtcpre << 16);
	switch(ppre2){ // 13
		case 2:
			RCC->CFGR |= (4 << 13);
		break;
		case 4:
			RCC->CFGR |= (5 << 13);
		break;
		case 8:
			RCC->CFGR |= (6 << 13);
		break;
		case 16:
			RCC->CFGR |= (7 << 13);
		break;
		default:
		break;
	}
	switch(ppre1){ // 10
		case 2:
			RCC->CFGR |= (4 << 10);
		break;
		case 4:
			RCC->CFGR |= (5 << 10);
		break;
		case 8:
			RCC->CFGR |= (6 << 10);
		break;
		case 16:
			RCC->CFGR |= (7 << 10);
		break;
		default:
		break;
	}
	switch(ahbpre){ // 4
		case 2:
			RCC->CFGR |= (8 << 4);
		break;
		case 4:
			RCC->CFGR |= (9 << 4);
		break;
		case 8:
			RCC->CFGR |= (10 << 4);
		break;
		case 16:
			RCC->CFGR |= (11 << 4);
		break;
		case 64:
			RCC->CFGR |= (12 << 4);
		break;
		case 128:
			RCC->CFGR |= (13 << 4);
		break;
		case 256:
			RCC->CFGR |= (14 << 4);
			break;
		case 512:
			RCC->CFGR |= (15 << 4);
			break;
		default:
		break;
	}
}
// PLL
void STM32FXXXPLLDivision(uint8_t pllm, uint16_t plln, uint8_t pllp, uint8_t pllq)
{
	const unsigned int mask = 0x0FC37FFF;
	RCC->PLLCFGR &= (unsigned int) ~mask; // clear args

	if(pllq > 1 && pllq < 16){ // PLLQ[24]: Main PLL (PLL) division factor for USB OTG FS, SDIOclocks
		RCC->PLLCFGR |= (pllq << 24);
	}

	switch(pllp){ // PLLP[16]: Main PLL (PLL) division factor for main system clock
		case 4:
			RCC->PLLCFGR |= (1 << 16);
		break;
		case 6:
			RCC->PLLCFGR |= (2 << 16);
		break;
		case 8:
			RCC->PLLCFGR |= (3 << 16);
		break;
		default: // 2
			RCC->PLLCFGR &= ~(3 << 16);
		break;
	}

	if(plln > 49 && plln < 433){ // PLLN[6]: Main PLL (PLL) multiplication factor for VCO
		RCC->PLLCFGR |= (plln << 6);
	}

	if(pllm > 1 && pllm < 64){ // PLLM[0]: Division factor for the main PLL (PLL) input clock [2Mhz]
		RCC->PLLCFGR |= pllm;
	}
}
void STM32FXXXRccPLLCLKEnable(void)
{
	uint32_t rcc_time_out;
	//if(onoff){
		for( rcc_time_out = 0xFFFFFF, RCC->CR |= (1 << 24) ; !(RCC->CR & (1 << 25)) && rcc_time_out; rcc_time_out-- ); // PLLON: Main PLL (PLL) enable
	//}else{
		//RCC->CR &= (unsigned int) ~(1 << 24);
	//}
}
void STM32FXXXRccPLLI2SEnable(void)
{
	uint32_t rcc_time_out;
	//if(onoff)
		for( rcc_time_out = 0xFFFFFF, RCC->CR |= (1 << 26) ; !(RCC->CR & (1 << 27)) && rcc_time_out; rcc_time_out-- ); // PLLI2SON: PLLI2S enable
	//else
		//RCC->CR &= (unsigned int) ~(1 << 26);
}
void STM32FXXXRccPLLSAIEnable(void)
{
	uint32_t rcc_time_out;
	//if(onoff)
		for( rcc_time_out = 0xFFFFFF, RCC->CR |= (1 << 28) ; !(RCC->CR & (1 << 29)) && rcc_time_out; rcc_time_out-- ); // PLLSAION: PLLSAI enable
	//else
		//RCC->CR &= (unsigned int) ~(1 << 28);
}
void STM32FXXXRccPwrClock(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 28, bool); // Power interface clock enable
}
void STM32FXXXRccWriteEnable(void)
{
	PWR->CR |= (1 << 8); // Disable protection
}
void STM32FXXXRccWriteDisable(void)
{
	PWR->CR &= (uint32_t) ~(1 << 8); // Enable protection
}
/*** RCC Bit Mapping Definition ***/
// CR
uint8_t STM32FXXXRCC_CR_get_pllsairdy(void)
{
	return readreg(RCC->CR, 1, 29);
}
void STM32FXXXRCC_CR_pllsaion(uint8_t bool)
{
	setreg(&RCC->CR, 1, 28, bool);
}
uint8_t STM32FXXXRCC_CR_get_plli2srdy(void)
{
	return readreg(RCC->CR, 1, 27);
}
void STM32FXXXRCC_CR_plli2son(uint8_t bool)
{
	setreg(&RCC->CR, 1, 26, bool);
}
uint8_t STM32FXXXRCC_CR_get_pllrdy(void)
{
	return readreg(RCC->CR, 1, 25);
}
void STM32FXXXRCC_CR_pllon(uint8_t bool)
{
	setreg(&RCC->CR, 1, 24, bool);
}
void STM32FXXXRCC_CR_csson(uint8_t bool)
{
	setreg(&RCC->CR, 1, 19, bool);
}
void STM32FXXXRCC_CR_hsebyp(uint8_t bool)
{
	setreg(&RCC->CR, 1, 18, bool);
}
uint8_t STM32FXXXRCC_CR_get_hserdy(void)
{
	return readreg(RCC->CR, 1, 17);
}
void STM32FXXXRCC_CR_hseon(uint8_t bool)
{
	setreg(&RCC->CR, 1, 16, bool);
}
uint8_t STM32FXXXRCC_CR_get_hsical(void)
{
	return readreg(RCC->CR, 8, 8);
}
void STM32FXXXRCC_CR_hsitrim(uint8_t value)
{
	setreg(&RCC->CR, 5, 3, value);
}
uint8_t STM32FXXXRCC_CR_get_hsirdy(void)
{
	return readreg(RCC->CR, 1, 1);
}
void STM32FXXXRCC_CR_hsion(uint8_t bool)
{
	setreg(&RCC->CR, 1, 0, bool);
}
// PLLCFGR
void STM32FXXXRCC_PLLCFGR_pllr(uint8_t value)
{
	setreg(&RCC->CR, 3, 28, value);
}
void STM32FXXXRCC_PLLCFGR_pllq(uint8_t value)
{
	setreg(&RCC->CR, 4, 24, value);
}
void STM32FXXXRCC_PLLCFGR_pllsrc(uint8_t bool)
{
	setreg(&RCC->CR, 1, 22, bool);
}
void STM32FXXXRCC_PLLCFGR_pllp(uint8_t value)
{
	setreg(&RCC->CR, 2, 16, value);
}
void STM32FXXXRCC_PLLCFGR_plln(uint16_t value)
{
	setreg(&RCC->CR, 9, 6, value);
}
void STM32FXXXRCC_PLLCFGR_pllm(uint8_t value)
{
	setreg(&RCC->CR, 6, 0, value);
}
// CFGR
void STM32FXXXRCC_CFGR_mco2(uint8_t value)
{
	setreg(&RCC->CFGR, 2, 30, value);
}
void STM32FXXXRCC_CFGR_mco2pre(uint8_t value)
{
	setreg(&RCC->CFGR, 3, 27, value);
}
void STM32FXXXRCC_CFGR_mco1pre(uint8_t value)
{
	setreg(&RCC->CFGR, 3, 24, value);
}
void STM32FXXXRCC_CFGR_mco1(uint8_t value)
{
	setreg(&RCC->CFGR, 2, 21, value);
}
void STM32FXXXRCC_CFGR_rtcpre(uint8_t value)
{
	setreg(&RCC->CFGR, 5, 16, value);
}
void STM32FXXXRCC_CFGR_ppre2(uint8_t value)
{
	setreg(&RCC->CFGR, 3, 13, value);
}
void STM32FXXXRCC_CFGR_ppre1(uint8_t value)
{
	setreg(&RCC->CFGR, 3, 10, value);
}
void STM32FXXXRCC_CFGR_hpre(uint8_t value)
{
	setreg(&RCC->CFGR, 4, 4, value);
}
uint8_t STM32FXXXRCC_CFGR_get_sws(void)
{
	return readreg(RCC->CFGR, 2, 2);
}
void STM32FXXXRCC_CFGR_sw(uint8_t value)
{
	setreg(&RCC->CFGR, 2, 0, value);
}
// CIR
void STM32FXXXRCC_CIR_clear_cssc(void)
{
	setreg(&RCC->CIR, 1, 23, 1);
}
void STM32FXXXRCC_CIR_clear_pllsairdyc(void)
{
	setreg(&RCC->CIR, 1, 22, 1);
}
void STM32FXXXRCC_CIR_clear_plli2srdyc(void)
{
	setreg(&RCC->CIR, 1, 21, 1);
}
void STM32FXXXRCC_CIR_clear_pllrdyc(void)
{
	setreg(&RCC->CIR, 1, 20, 1);
}
void STM32FXXXRCC_CIR_clear_hserdyc(void)
{
	setreg(&RCC->CIR, 1, 19, 1);
}
void STM32FXXXRCC_CIR_clear_hsirdyc(void)
{
	setreg(&RCC->CIR, 1, 18, 1);
}
void STM32FXXXRCC_CIR_clear_lserdyc(void)
{
	setreg(&RCC->CIR, 1, 17, 1);
}
void STM32FXXXRCC_CIR_clear_lsirdyc(void)
{
	setreg(&RCC->CIR, 1, 16, 1);
}
void STM32FXXXRCC_CIR_pllsairdyie(uint8_t bool)
{
	setreg(&RCC->CIR, 1, 14, bool);
}
void STM32FXXXRCC_CIR_plli2srdyie(uint8_t bool)
{
	setreg(&RCC->CIR, 1, 13, bool);
}
void STM32FXXXRCC_CIR_pllrdyie(uint8_t bool)
{
	setreg(&RCC->CIR, 1, 12, bool);
}
void STM32FXXXRCC_CIR_hserdyie(uint8_t bool)
{
	setreg(&RCC->CIR, 1, 11, bool);
}
void STM32FXXXRCC_CIR_hsirdyie(uint8_t bool)
{
	setreg(&RCC->CIR, 1, 10, bool);
}
void STM32FXXXRCC_CIR_lserdyie(uint8_t bool)
{
	setreg(&RCC->CIR, 1, 9, bool);
}
void STM32FXXXRCC_CIR_lsirdyie(uint8_t bool)
{
	setreg(&RCC->CIR, 1, 8, bool);
}
uint8_t STM32FXXXRCC_CIR_get_cssf(void)
{
	return readreg(RCC->CIR, 1, 7);
}
uint8_t STM32FXXXRCC_CIR_get_pllsairdyf(void)
{
	return readreg(RCC->CIR, 1, 6);
}
uint8_t STM32FXXXRCC_CIR_get_plli2srdyf(void)
{
	return readreg(RCC->CIR, 1, 5);
}
uint8_t STM32FXXXRCC_CIR_get_pllrdyf(void)
{
	return readreg(RCC->CIR, 1, 4);
}
uint8_t STM32FXXXRCC_CIR_get_hserdyf(void)
{
	return readreg(RCC->CIR, 1, 3);
}
uint8_t STM32FXXXRCC_CIR_get_hsirdyf(void)
{
	return readreg(RCC->CIR, 1, 2);
}
uint8_t STM32FXXXRCC_CIR_get_lserdyf(void)
{
	return readreg(RCC->CIR, 1, 1);
}
uint8_t STM32FXXXRCC_CIR_get_lsirdyf(void)
{
	return readreg(RCC->CIR, 1, 0);
}
// AHB1RSTR
void STM32FXXXRCC_AHB1RSTR_otghsrst(uint8_t bool)
{
	setreg(&RCC->AHB1RSTR, 1, 29, bool);
}
void STM32FXXXRCC_AHB1RSTR_dma2rst(uint8_t bool)
{
	setreg(&RCC->AHB1RSTR, 1, 22, bool);
}
void STM32FXXXRCC_AHB1RSTR_dma1rst(uint8_t bool)
{
	setreg(&RCC->AHB1RSTR, 1, 21, bool);
}
void STM32FXXXRCC_AHB1RSTR_crcrst(uint8_t bool)
{
	setreg(&RCC->AHB1RSTR, 1, 12, bool);
}
void STM32FXXXRCC_AHB1RSTR_gpiohrst(uint8_t bool)
{
	setreg(&RCC->AHB1RSTR, 1, 7, bool);
}
void STM32FXXXRCC_AHB1RSTR_gpiogrst(uint8_t bool)
{
	setreg(&RCC->AHB1RSTR, 1, 6, bool);
}
void STM32FXXXRCC_AHB1RSTR_gpiofrst(uint8_t bool)
{
	setreg(&RCC->AHB1RSTR, 1, 5, bool);
}
void STM32FXXXRCC_AHB1RSTR_gpioerst(uint8_t bool)
{
	setreg(&RCC->AHB1RSTR, 1, 4, bool);
}
void STM32FXXXRCC_AHB1RSTR_gpiodrst(uint8_t bool)
{
	setreg(&RCC->AHB1RSTR, 1, 3, bool);
}
void STM32FXXXRCC_AHB1RSTR_gpiocrst(uint8_t bool)
{
	setreg(&RCC->AHB1RSTR, 1, 2, bool);
}
void STM32FXXXRCC_AHB1RSTR_gpiobrst(uint8_t bool)
{
	setreg(&RCC->AHB1RSTR, 1, 1, bool);
}
void STM32FXXXRCC_AHB1RSTR_gpioarst(uint8_t bool)
{
	setreg(&RCC->AHB1RSTR, 1, 0, bool);
}
// AHB2RSTR
void STM32FXXXRCC_AHB2RSTR_otgfsrst(uint8_t bool)
{
	setreg(&RCC->AHB2RSTR, 1, 7, bool);
}
void STM32FXXXRCC_AHB2RSTR_dcmirst(uint8_t bool)
{
	setreg(&RCC->AHB2RSTR, 1, 0, bool);
}
// AHB3RSTR
void STM32FXXXRCC_AHB3RSTR_qspirst(uint8_t bool)
{
	setreg(&RCC->AHB3RSTR, 1, 1, bool);
}
void STM32FXXXRCC_AHB3RSTR_fmcrst(uint8_t bool)
{
	setreg(&RCC->AHB3RSTR, 1, 0, bool);
}
// APB1RSTR
void STM32FXXXRCC_APB1RSTR_dacrst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 29, bool);
}
void STM32FXXXRCC_APB1RSTR_pwrrst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 28, bool);
}
void STM32FXXXRCC_APB1RSTR_cecrst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 27, bool);
}
void STM32FXXXRCC_APB1RSTR_can2rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 26, bool);
}
void STM32FXXXRCC_APB1RSTR_can1rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 25, bool);
}
void STM32FXXXRCC_APB1RSTR_fmpi2c1rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 24, bool);
}
void STM32FXXXRCC_APB1RSTR_i2c3rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 23, bool);
}
void STM32FXXXRCC_APB1RSTR_i2c2rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 22, bool);
}
void STM32FXXXRCC_APB1RSTR_i2c1rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 21, bool);
}
void STM32FXXXRCC_APB1RSTR_uart5rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 20, bool);
}
void STM32FXXXRCC_APB1RSTR_uart4rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 19, bool);
}
void STM32FXXXRCC_APB1RSTR_usart3rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 18, bool);
}
void STM32FXXXRCC_APB1RSTR_usart2rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 17, bool);
}
void STM32FXXXRCC_APB1RSTR_spdifrxrst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 16, bool);
}
void STM32FXXXRCC_APB1RSTR_spi3rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 15, bool);
}
void STM32FXXXRCC_APB1RSTR_spi2rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 14, bool);
}
void STM32FXXXRCC_APB1RSTR_wwdgrst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 11, bool);
}
void STM32FXXXRCC_APB1RSTR_tim14rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 8, bool);
}
void STM32FXXXRCC_APB1RSTR_tim13rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 7, bool);
}
void STM32FXXXRCC_APB1RSTR_tim12rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 6, bool);
}
void STM32FXXXRCC_APB1RSTR_tim7rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 5, bool);
}
void STM32FXXXRCC_APB1RSTR_tim6rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 4, bool);
}
void STM32FXXXRCC_APB1RSTR_tim5rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 3, bool);
}
void STM32FXXXRCC_APB1RSTR_tim4rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 2, bool);
}
void STM32FXXXRCC_APB1RSTR_tim3rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 1, bool);
}
void STM32FXXXRCC_APB1RSTR_tim2rst(uint8_t bool)
{
	setreg(&RCC->APB1RSTR, 1, 0, bool);
}
// APB2RSTR
void STM32FXXXRCC_APB2RSTR_sai2rst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 23, bool);
}
void STM32FXXXRCC_APB2RSTR_sai1rst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 22, bool);
}
void STM32FXXXRCC_APB2RSTR_tim11rst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 18, bool);
}
void STM32FXXXRCC_APB2RSTR_tim10rst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 17, bool);
}
void STM32FXXXRCC_APB2RSTR_tim9rst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 16, bool);
}
void STM32FXXXRCC_APB2RSTR_syscfgrst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 14, bool);
}
void STM32FXXXRCC_APB2RSTR_spi4rst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 13, bool);
}
void STM32FXXXRCC_APB2RSTR_spi1rst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 12, bool);
}
void STM32FXXXRCC_APB2RSTR_sdiorst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 11, bool);
}
void STM32FXXXRCC_APB2RSTR_adcrst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 8, bool);
}
void STM32FXXXRCC_APB2RSTR_usart6rst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 5, bool);
}
void STM32FXXXRCC_APB2RSTR_usart1rst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 4, bool);
}
void STM32FXXXRCC_APB2RSTR_tim8rst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 1, bool);
}
void STM32FXXXRCC_APB2RSTR_tim1rst(uint8_t bool)
{
	setreg(&RCC->APB2RSTR, 1, 0, bool);
}
// AHB1ENR
void STM32FXXXRCC_AHB1ENR_otghsulpien(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 30, bool);
}
void STM32FXXXRCC_AHB1ENR_otghsen(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 29, bool);
}
void STM32FXXXRCC_AHB1ENR_dma2en(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 22, bool);
}
void STM32FXXXRCC_AHB1ENR_dma1en(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 21, bool);
}
void STM32FXXXRCC_AHB1ENR_bkpsramen(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 18, bool);
}
void STM32FXXXRCC_AHB1ENR_crcen(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 12, bool);
}
void STM32FXXXRCC_AHB1ENR_gpiohen(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 7, bool);
}
void STM32FXXXRCC_AHB1ENR_gpiogen(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 6, bool);
}
void STM32FXXXRCC_AHB1ENR_gpiofen(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 5, bool);
}
void STM32FXXXRCC_AHB1ENR_gpioeen(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 4, bool);
}
void STM32FXXXRCC_AHB1ENR_gpioden(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 3, bool);
}
void STM32FXXXRCC_AHB1ENR_gpiocen(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 2, bool);
}
void STM32FXXXRCC_AHB1ENR_gpioben(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 1, bool);
}
void STM32FXXXRCC_AHB1ENR_gpioaen(uint8_t bool)
{
	setreg(&RCC->AHB1ENR, 1, 0, bool);
}
// AHB2ENR
void STM32FXXXRCC_AHB2ENR_otgfsen(uint8_t bool)
{
	setreg(&RCC->AHB2ENR, 1, 7, bool);
}
void STM32FXXXRCC_AHB2ENR_dcmien(uint8_t bool)
{
	setreg(&RCC->AHB2ENR, 1, 0, bool);
}
// AHB3ENR
void STM32FXXXRCC_AHB3ENR_qspien(uint8_t bool)
{
	setreg(&RCC->AHB3ENR, 1, 1, bool);
}
void STM32FXXXRCC_AHB3ENR_fmcen(uint8_t bool)
{
	setreg(&RCC->AHB3ENR, 1, 0, bool);
}
// APB1ENR
void STM32FXXXRCC_APB1ENR_dacen(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 29, bool);
}
void STM32FXXXRCC_APB1ENR_pwren(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 28, bool);
}
void STM32FXXXRCC_APB1ENR_cecen(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 27, bool);
}
void STM32FXXXRCC_APB1ENR_can2en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 26, bool);
}
void STM32FXXXRCC_APB1ENR_can1en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 25, bool);
}
void STM32FXXXRCC_APB1ENR_fmpi2c1en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 24, bool);
}
void STM32FXXXRCC_APB1ENR_i2c3en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 23, bool);
}
void STM32FXXXRCC_APB1ENR_i2c2en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 22, bool);
}
void STM32FXXXRCC_APB1ENR_i2c1en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 21, bool);
}
void STM32FXXXRCC_APB1ENR_uart5en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 20, bool);
}
void STM32FXXXRCC_APB1ENR_uart4en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 19, bool);
}
void STM32FXXXRCC_APB1ENR_usart3en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 18, bool);
}
void STM32FXXXRCC_APB1ENR_usart2en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 17, bool);
}
void STM32FXXXRCC_APB1ENR_spdifrxen(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 16, bool);
}
void STM32FXXXRCC_APB1ENR_spi3en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 15, bool);
}
void STM32FXXXRCC_APB1ENR_spi2en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 14, bool);
}
void STM32FXXXRCC_APB1ENR_wwdgen(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 11, bool);
}
void STM32FXXXRCC_APB1ENR_tim14en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 8, bool);
}
void STM32FXXXRCC_APB1ENR_tim13en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 7, bool);
}
void STM32FXXXRCC_APB1ENR_tim12en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 6, bool);
}
void STM32FXXXRCC_APB1ENR_tim7en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 5, bool);
}
void STM32FXXXRCC_APB1ENR_tim6en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 4, bool);
}
void STM32FXXXRCC_APB1ENR_tim5en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 3, bool);
}
void STM32FXXXRCC_APB1ENR_tim4en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 2, bool);
}
void STM32FXXXRCC_APB1ENR_tim3en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 1, bool);
}
void STM32FXXXRCC_APB1ENR_tim2en(uint8_t bool)
{
	setreg(&RCC->APB1ENR, 1, 0, bool);
}
// APB2ENR
void STM32FXXXRCC_APB2ENR_sai2en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 23, bool);
}
void STM32FXXXRCC_APB2ENR_sai1en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 22, bool);
}
void STM32FXXXRCC_APB2ENR_tim11en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 18, bool);
}
void STM32FXXXRCC_APB2ENR_tim10en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 17, bool);
}
void STM32FXXXRCC_APB2ENR_tim9en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 16, bool);
}
void STM32FXXXRCC_APB2ENR_syscfgen(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 14, bool);
}
void STM32FXXXRCC_APB2ENR_spi4en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 13, bool);
}
void STM32FXXXRCC_APB2ENR_spi1en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 12, bool);
}
void STM32FXXXRCC_APB2ENR_sdioen(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 11, bool);
}
void STM32FXXXRCC_APB2ENR_adc3en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 10, bool);
}
void STM32FXXXRCC_APB2ENR_adc2en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 9, bool);
}
void STM32FXXXRCC_APB2ENR_adc1en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 8, bool);
}
void STM32FXXXRCC_APB2ENR_usart6en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 5, bool);
}
void STM32FXXXRCC_APB2ENR_usart1en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 4, bool);
}
void STM32FXXXRCC_APB2ENR_tim8en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 1, bool);
}
void STM32FXXXRCC_APB2ENR_tim1en(uint8_t bool)
{
	setreg(&RCC->APB2ENR, 1, 0, bool);
}
//AHB1LPENR
void STM32FXXXRCC_AHB1LPENR_otghsulpilpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 30, bool);
}
void STM32FXXXRCC_AHB1LPENR_otghslpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 29, bool);
}
void STM32FXXXRCC_AHB1LPENR_dma2lpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 22, bool);
}
void STM32FXXXRCC_AHB1LPENR_dma1lpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 21, bool);
}
void STM32FXXXRCC_AHB1LPENR_bkpsramlpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 18, bool);
}
void STM32FXXXRCC_AHB1LPENR_sram2lpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 17, bool);
}
void STM32FXXXRCC_AHB1LPENR_sram1lpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 16, bool);
}
void STM32FXXXRCC_AHB1LPENR_flitflpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 15, bool);
}
void STM32FXXXRCC_AHB1LPENR_crclpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 12, bool);
}
void STM32FXXXRCC_AHB1LPENR_gpiohlpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 7, bool);
}
void STM32FXXXRCC_AHB1LPENR_gpioglpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 6, bool);
}
void STM32FXXXRCC_AHB1LPENR_gpioflpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 5, bool);
}
void STM32FXXXRCC_AHB1LPENR_gpioelpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 4, bool);
}
void STM32FXXXRCC_AHB1LPENR_gpiodlpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 3, bool);
}
void STM32FXXXRCC_AHB1LPENR_gpioclpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 2, bool);
}
void STM32FXXXRCC_AHB1LPENR_gpioblpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 1, bool);
}
void STM32FXXXRCC_AHB1LPENR_gpioalpen(uint8_t bool)
{
	setreg(&RCC->AHB1LPENR, 1, 0, bool);
}
// AHB2LPENR
void STM32FXXXRCC_AHB2LPENR_otgfslpen(uint8_t bool)
{
	setreg(&RCC->AHB2LPENR, 1, 7, bool);
}
void STM32FXXXRCC_AHB2LPENR_dcmilpen(uint8_t bool)
{
	setreg(&RCC->AHB2LPENR, 1, 0, bool);
}
// AHB3LPENR
void STM32FXXXRCC_AHB3LPENR_qspilpen(uint8_t bool)
{
	setreg(&RCC->AHB3LPENR, 1, 1, bool);
}
void STM32FXXXRCC_AHB3LPENR_fmclpen(uint8_t bool)
{
	setreg(&RCC->AHB3LPENR, 1, 0, bool);
}
// APB1LPENR
void STM32FXXXRCC_APB1LPENR_daclpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 29, bool);
}
void STM32FXXXRCC_APB1LPENR_pwrlpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 28, bool);
}
void STM32FXXXRCC_APB1LPENR_ceclpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 27, bool);
}
void STM32FXXXRCC_APB1LPENR_can2lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 26, bool);
}
void STM32FXXXRCC_APB1LPENR_can1lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 25, bool);
}
void STM32FXXXRCC_APB1LPENR_fmpi2c1lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 24, bool);
}
void STM32FXXXRCC_APB1LPENR_i2c3lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 23, bool);
}
void STM32FXXXRCC_APB1LPENR_i2c2lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 22, bool);
}
void STM32FXXXRCC_APB1LPENR_i2c1lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 21, bool);
}
void STM32FXXXRCC_APB1LPENR_uart5lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 20, bool);
}
void STM32FXXXRCC_APB1LPENR_uart4lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 19, bool);
}
void STM32FXXXRCC_APB1LPENR_usart3lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 18, bool);
}
void STM32FXXXRCC_APB1LPENR_usart2lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 17, bool);
}
void STM32FXXXRCC_APB1LPENR_spdifrxlpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 16, bool);
}
void STM32FXXXRCC_APB1LPENR_spi3lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 15, bool);
}
void STM32FXXXRCC_APB1LPENR_spi2lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 14, bool);
}
void STM32FXXXRCC_APB1LPENR_wwdglpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 11, bool);
}
void STM32FXXXRCC_APB1LPENR_tim14lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 8, bool);
}
void STM32FXXXRCC_APB1LPENR_tim13lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 7, bool);
}
void STM32FXXXRCC_APB1LPENR_tim12lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 6, bool);
}
void STM32FXXXRCC_APB1LPENR_tim7lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 5, bool);
}
void STM32FXXXRCC_APB1LPENR_tim6lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 4, bool);
}
void STM32FXXXRCC_APB1LPENR_tim5lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 3, bool);
}
void STM32FXXXRCC_APB1LPENR_tim4lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 2, bool);
}
void STM32FXXXRCC_APB1LPENR_tim3lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 1, bool);
}
void STM32FXXXRCC_APB1LPENR_tim2lpen(uint8_t bool)
{
	setreg(&RCC->APB1LPENR, 1, 0, bool);
}
// APB2LPENR
void STM32FXXXRCC_APB2LPENR_sai2lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 23, bool);
}
void STM32FXXXRCC_APB2LPENR_sai1lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 22, bool);
}
void STM32FXXXRCC_APB2LPENR_tim11lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 18, bool);
}
void STM32FXXXRCC_APB2LPENR_tim10lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 17, bool);
}
void STM32FXXXRCC_APB2LPENR_tim9lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 16, bool);
}
void STM32FXXXRCC_APB2LPENR_syscfglpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 14, bool);
}
void STM32FXXXRCC_APB2LPENR_spi4lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 13, bool);
}
void STM32FXXXRCC_APB2LPENR_spi1lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 12, bool);
}
void STM32FXXXRCC_APB2LPENR_sdiolpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 11, bool);
}
void STM32FXXXRCC_APB2LPENR_adc3lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 10, bool);
}
void STM32FXXXRCC_APB2LPENR_adc2lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 9, bool);
}
void STM32FXXXRCC_APB2LPENR_adc1lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 8, bool);
}
void STM32FXXXRCC_APB2LPENR_usart6lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 5, bool);
}
void STM32FXXXRCC_APB2LPENR_usart1lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 4, bool);
}
void STM32FXXXRCC_APB2LPENR_tim8lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 1, bool);
}
void STM32FXXXRCC_APB2LPENR_tim1lpen(uint8_t bool)
{
	setreg(&RCC->APB2LPENR, 1, 0, bool);
}
// BDCR
void STM32FXXXRCC_BDCR_bdrst(uint8_t bool)
{
	setreg(&RCC->BDCR, 1, 16, bool);
}
void STM32FXXXRCC_BDCR_rtcen(uint8_t bool)
{
	setreg(&RCC->BDCR, 1, 15, bool);
}
uint8_t STM32FXXXRCC_BDCR_get_rtcen(void)
{
	return readreg(RCC->BDCR, 1, 15);
}
void STM32FXXXRCC_BDCR_rtcsel(uint8_t value)
{
	setreg(&RCC->BDCR, 2, 8, value);
}
uint8_t STM32FXXXRCC_BDCR_get_rtcsel(void)
{
	return readreg(RCC->BDCR, 2, 8);
}
void STM32FXXXRCC_BDCR_lsemod(uint8_t bool)
{
	setreg(&RCC->BDCR, 1, 3, bool);
}
void STM32FXXXRCC_BDCR_lsebyp(uint8_t bool)
{
	setreg(&RCC->BDCR, 1, 2, bool);
}
uint8_t STM32FXXXRCC_BDCR_get_lserdy(void)
{
	return readreg(RCC->BDCR, 1, 1);
}
void STM32FXXXRCC_BDCR_lseon(uint8_t bool)
{
	setreg(&RCC->BDCR, 1, 0, bool);
}
// CSR
uint8_t STM32FXXXRCC_CSR_get_lpwrrstf(void)
{
	return readreg(RCC->CSR, 1, 31);
}
uint8_t STM32FXXXRCC_CSR_get_wwdgrstf(void)
{
	return readreg(RCC->CSR, 1, 30);
}
uint8_t STM32FXXXRCC_CSR_get_iwdqrstf(void)
{
	return readreg(RCC->CSR, 1, 29);
}
uint8_t STM32FXXXRCC_CSR_get_sftrstf(void)
{
	return readreg(RCC->CSR, 1, 28);
}
uint8_t STM32FXXXRCC_CSR_get_porrstf(void)
{
	return readreg(RCC->CSR, 1, 27);
}
uint8_t STM32FXXXRCC_CSR_get_pinrstf(void)
{
	return readreg(RCC->CSR, 1, 26);
}
uint8_t STM32FXXXRCC_CSR_get_borrstf(void)
{
	return readreg(RCC->CSR, 1, 25);
}
void STM32FXXXRCC_CSR_clear_rmvf(void)
{
	setreg(&RCC->CSR, 1, 24, 1);
}
uint8_t STM32FXXXRCC_CSR_get_lsirdy(void)
{
	return readreg(RCC->CSR, 1, 1);
}
void STM32FXXXRCC_CSR_lsion(uint8_t bool)
{
	setreg(&RCC->CSR, 1, 0, bool);
}
// SSCGR
void STM32FXXXRCC_SSCGR_sscgen(uint8_t bool)
{
	setreg(&RCC->SSCGR, 1, 31, bool);
}
void STM32FXXXRCC_SSCGR_spreadsel(uint8_t bool)
{
	setreg(&RCC->SSCGR, 1, 30, bool);
}
void STM32FXXXRCC_SSCGR_incstep(uint8_t value)
{
	setreg(&RCC->SSCGR, 15, 13, value);
}
void STM32FXXXRCC_SSCGR_modper(uint8_t value)
{
	setreg(&RCC->SSCGR, 13, 0, value);
}
// PLLI2SCFGR
void STM32FXXXRCC_PLLI2SCFGR_plli2sr(uint8_t value)
{
	setreg(&RCC->PLLI2SCFGR, 3, 28, value);
}
void STM32FXXXRCC_PLLI2SCFGR_plli2sq(uint8_t value)
{
	setreg(&RCC->PLLI2SCFGR, 4, 24, value);
}
void STM32FXXXRCC_PLLI2SCFGR_plli2sp(uint8_t value)
{
	setreg(&RCC->PLLI2SCFGR, 2, 16, value);
}
void STM32FXXXRCC_PLLI2SCFGR_plli2sn(uint16_t value)
{
	setreg(&RCC->PLLI2SCFGR, 9, 6, value);
}
void STM32FXXXRCC_PLLI2SCFGR_plli2sm(uint8_t value)
{
	setreg(&RCC->PLLI2SCFGR, 6, 0, value);
}
// DCKCFGR
void STM32FXXXRCC_DCKCFGR_i2s2src(uint8_t value)
{
	setreg(&RCC->DCKCFGR, 2, 27, value);
}
void STM32FXXXRCC_DCKCFGR_i2s1src(uint8_t value)
{
	setreg(&RCC->DCKCFGR, 2, 25, value);
}
void STM32FXXXRCC_DCKCFGR_timpre(uint8_t bool)
{
	setreg(&RCC->DCKCFGR, 1, 24, bool);
}
void STM32FXXXRCC_DCKCFGR_sai2src(uint8_t value)
{
	setreg(&RCC->DCKCFGR, 2, 22, value);
}
void STM32FXXXRCC_DCKCFGR_sai1src(uint8_t value)
{
	setreg(&RCC->DCKCFGR, 2, 20, value);
}
void STM32FXXXRCC_DCKCFGR_pllsaidivq(uint8_t value)
{
	setreg(&RCC->DCKCFGR, 5, 8, value);
}
void STM32FXXXRCC_DCKCFGR_plli2sdivq(uint8_t value)
{
	setreg(&RCC->DCKCFGR, 5, 0, value);
}
/*** Other ***/
void STM32FXXXRCC_nvic(uint8_t bool)
{
	if(bool){ setbit(NVIC->ISER, 1, RCC_IRQn, 1); } else{ setbit(NVIC->ICER, 1, RCC_IRQn, 1); }
}
/*** Auxiliar ***/
STM32FXXXRCC_cr* stm32fxxx_rcc_cr_inic(void)
{

	// CR
	stm32fxxx_rcc_cr.get_pllsairdy = STM32FXXXRCC_CR_get_pllsairdy;
	stm32fxxx_rcc_cr.pllsaion = STM32FXXXRCC_CR_pllsaion;
	stm32fxxx_rcc_cr.get_plli2srdy = STM32FXXXRCC_CR_get_plli2srdy;
	stm32fxxx_rcc_cr.plli2son = STM32FXXXRCC_CR_plli2son;
	stm32fxxx_rcc_cr.get_pllrdy = STM32FXXXRCC_CR_get_pllrdy;
	stm32fxxx_rcc_cr.pllon = STM32FXXXRCC_CR_pllon;
	stm32fxxx_rcc_cr.csson = STM32FXXXRCC_CR_csson;
	stm32fxxx_rcc_cr.hsebyp = STM32FXXXRCC_CR_hsebyp;
	stm32fxxx_rcc_cr.get_hserdy = STM32FXXXRCC_CR_get_hserdy;
	stm32fxxx_rcc_cr.hseon = STM32FXXXRCC_CR_hseon;
	stm32fxxx_rcc_cr.get_hsical = STM32FXXXRCC_CR_get_hsical;
	stm32fxxx_rcc_cr.hsitrim = STM32FXXXRCC_CR_hsitrim;
	stm32fxxx_rcc_cr.get_hsirdy = STM32FXXXRCC_CR_get_hsirdy;
	stm32fxxx_rcc_cr.hsion = STM32FXXXRCC_CR_hsion;
	return &stm32fxxx_rcc_cr;
}
STM32FXXXRCC_pllcfgr* stm32fxxx_rcc_pllcfgr_inic(void)
{

	// PLLCFGR
	stm32fxxx_rcc_pllcfgr.pllr = STM32FXXXRCC_PLLCFGR_pllr;
	stm32fxxx_rcc_pllcfgr.pllq = STM32FXXXRCC_PLLCFGR_pllq;
	stm32fxxx_rcc_pllcfgr.pllsrc = STM32FXXXRCC_PLLCFGR_pllsrc;
	stm32fxxx_rcc_pllcfgr.pllp = STM32FXXXRCC_PLLCFGR_pllp;
	stm32fxxx_rcc_pllcfgr.plln = STM32FXXXRCC_PLLCFGR_plln;
	stm32fxxx_rcc_pllcfgr.pllm = STM32FXXXRCC_PLLCFGR_pllm;
	return &stm32fxxx_rcc_pllcfgr;
}
STM32FXXXRCC_cfgr* stm32fxxx_rcc_cfgr_inic(void)
{

	// CFGR
	stm32fxxx_rcc_cfgr.mco2 = STM32FXXXRCC_CFGR_mco2;
	stm32fxxx_rcc_cfgr.mco2pre = STM32FXXXRCC_CFGR_mco2pre;
	stm32fxxx_rcc_cfgr.mco1pre = STM32FXXXRCC_CFGR_mco1pre;
	stm32fxxx_rcc_cfgr.mco1 = STM32FXXXRCC_CFGR_mco1;
	stm32fxxx_rcc_cfgr.rtcpre = STM32FXXXRCC_CFGR_rtcpre;
	stm32fxxx_rcc_cfgr.ppre2 = STM32FXXXRCC_CFGR_ppre2;
	stm32fxxx_rcc_cfgr.ppre1 = STM32FXXXRCC_CFGR_ppre1;
	stm32fxxx_rcc_cfgr.hpre = STM32FXXXRCC_CFGR_hpre;
	stm32fxxx_rcc_cfgr.get_sws = STM32FXXXRCC_CFGR_get_sws;
	stm32fxxx_rcc_cfgr.sw = STM32FXXXRCC_CFGR_sw;
	return &stm32fxxx_rcc_cfgr;
}
STM32FXXXRCC_cir* stm32fxxx_rcc_cir_inic(void)
{

	// CIR
	stm32fxxx_rcc_cir.clear_cssc = STM32FXXXRCC_CIR_clear_cssc;
	stm32fxxx_rcc_cir.clear_pllsairdyc = STM32FXXXRCC_CIR_clear_pllsairdyc;
	stm32fxxx_rcc_cir.clear_plli2srdyc = STM32FXXXRCC_CIR_clear_plli2srdyc;
	stm32fxxx_rcc_cir.clear_pllrdyc = STM32FXXXRCC_CIR_clear_pllrdyc;
	stm32fxxx_rcc_cir.clear_hserdyc = STM32FXXXRCC_CIR_clear_hserdyc;
	stm32fxxx_rcc_cir.clear_hsirdyc = STM32FXXXRCC_CIR_clear_hsirdyc;
	stm32fxxx_rcc_cir.clear_lserdyc = STM32FXXXRCC_CIR_clear_lserdyc;
	stm32fxxx_rcc_cir.clear_lsirdyc = STM32FXXXRCC_CIR_clear_lsirdyc;
	stm32fxxx_rcc_cir.pllsairdyie = STM32FXXXRCC_CIR_pllsairdyie;
	stm32fxxx_rcc_cir.plli2srdyie = STM32FXXXRCC_CIR_plli2srdyie;
	stm32fxxx_rcc_cir.pllrdyie = STM32FXXXRCC_CIR_pllrdyie;
	stm32fxxx_rcc_cir.hserdyie = STM32FXXXRCC_CIR_hserdyie;
	stm32fxxx_rcc_cir.hsirdyie = STM32FXXXRCC_CIR_hsirdyie;
	stm32fxxx_rcc_cir.lserdyie = STM32FXXXRCC_CIR_lserdyie;
	stm32fxxx_rcc_cir.lsirdyie = STM32FXXXRCC_CIR_lsirdyie;
	stm32fxxx_rcc_cir.get_cssf = STM32FXXXRCC_CIR_get_cssf;
	stm32fxxx_rcc_cir.get_pllsairdyf = STM32FXXXRCC_CIR_get_pllsairdyf;
	stm32fxxx_rcc_cir.get_plli2srdyf = STM32FXXXRCC_CIR_get_plli2srdyf;
	stm32fxxx_rcc_cir.get_pllrdyf = STM32FXXXRCC_CIR_get_pllrdyf;
	stm32fxxx_rcc_cir.get_hserdyf = STM32FXXXRCC_CIR_get_hserdyf;
	stm32fxxx_rcc_cir.get_hsirdyf = STM32FXXXRCC_CIR_get_hsirdyf;
	stm32fxxx_rcc_cir.get_lserdyf = STM32FXXXRCC_CIR_get_lserdyf;
	stm32fxxx_rcc_cir.get_lsirdyf = STM32FXXXRCC_CIR_get_lsirdyf;
	return &stm32fxxx_rcc_cir;
}
STM32FXXXRCC_ahb1rstr* stm32fxxx_rcc_ahb1rstr_inic(void)
{

	// AHB1RSTR
	stm32fxxx_rcc_ahb1rstr.otghsrst = STM32FXXXRCC_AHB1RSTR_otghsrst;
	stm32fxxx_rcc_ahb1rstr.dma2rst = STM32FXXXRCC_AHB1RSTR_dma2rst;
	stm32fxxx_rcc_ahb1rstr.dma1rst = STM32FXXXRCC_AHB1RSTR_dma1rst;
	stm32fxxx_rcc_ahb1rstr.crcrst = STM32FXXXRCC_AHB1RSTR_crcrst;
	stm32fxxx_rcc_ahb1rstr.gpiohrst = STM32FXXXRCC_AHB1RSTR_gpiohrst;
	stm32fxxx_rcc_ahb1rstr.gpiogrst = STM32FXXXRCC_AHB1RSTR_gpiogrst;
	stm32fxxx_rcc_ahb1rstr.gpiofrst = STM32FXXXRCC_AHB1RSTR_gpiofrst;
	stm32fxxx_rcc_ahb1rstr.gpioerst = STM32FXXXRCC_AHB1RSTR_gpioerst;
	stm32fxxx_rcc_ahb1rstr.gpiodrst = STM32FXXXRCC_AHB1RSTR_gpiodrst;
	stm32fxxx_rcc_ahb1rstr.gpiocrst = STM32FXXXRCC_AHB1RSTR_gpiocrst;
	stm32fxxx_rcc_ahb1rstr.gpiobrst = STM32FXXXRCC_AHB1RSTR_gpiobrst;
	stm32fxxx_rcc_ahb1rstr.gpioarst = STM32FXXXRCC_AHB1RSTR_gpioarst;
	return &stm32fxxx_rcc_ahb1rstr;
}
STM32FXXXRCC_ahb2rstr* stm32fxxx_rcc_ahb2rstr_inic(void)
{

	// AHB2RSTR
	stm32fxxx_rcc_ahb2rstr.otgfsrst = STM32FXXXRCC_AHB2RSTR_otgfsrst;
	stm32fxxx_rcc_ahb2rstr.dcmirst = STM32FXXXRCC_AHB2RSTR_dcmirst;
	return &stm32fxxx_rcc_ahb2rstr;
}
STM32FXXXRCC_apb1rstr* stm32fxxx_rcc_apb1rstr_inic(void)
{

	// APB1RSTR
	stm32fxxx_rcc_apb1rstr.dacrst = STM32FXXXRCC_APB1RSTR_dacrst;
	stm32fxxx_rcc_apb1rstr.pwrrst = STM32FXXXRCC_APB1RSTR_pwrrst;
	stm32fxxx_rcc_apb1rstr.cecrst = STM32FXXXRCC_APB1RSTR_cecrst;
	stm32fxxx_rcc_apb1rstr.can2rst = STM32FXXXRCC_APB1RSTR_can2rst;
	stm32fxxx_rcc_apb1rstr.can1rst = STM32FXXXRCC_APB1RSTR_can1rst;
	stm32fxxx_rcc_apb1rstr.fmpi2c1rst = STM32FXXXRCC_APB1RSTR_fmpi2c1rst;
	stm32fxxx_rcc_apb1rstr.i2c3rst = STM32FXXXRCC_APB1RSTR_i2c3rst;
	stm32fxxx_rcc_apb1rstr.i2c2rst = STM32FXXXRCC_APB1RSTR_i2c2rst;
	stm32fxxx_rcc_apb1rstr.i2c1rst = STM32FXXXRCC_APB1RSTR_i2c1rst;
	stm32fxxx_rcc_apb1rstr.uart5rst = STM32FXXXRCC_APB1RSTR_uart5rst;
	stm32fxxx_rcc_apb1rstr.uart4rst = STM32FXXXRCC_APB1RSTR_uart4rst;
	stm32fxxx_rcc_apb1rstr.usart3rst = STM32FXXXRCC_APB1RSTR_usart3rst;
	stm32fxxx_rcc_apb1rstr.usart2rst = STM32FXXXRCC_APB1RSTR_usart2rst;
	stm32fxxx_rcc_apb1rstr.spdifrxrst = STM32FXXXRCC_APB1RSTR_spdifrxrst;
	stm32fxxx_rcc_apb1rstr.spi3rst = STM32FXXXRCC_APB1RSTR_spi3rst;
	stm32fxxx_rcc_apb1rstr.spi2rst = STM32FXXXRCC_APB1RSTR_spi2rst;
	stm32fxxx_rcc_apb1rstr.wwdgrst = STM32FXXXRCC_APB1RSTR_wwdgrst;
	stm32fxxx_rcc_apb1rstr.tim14rst = STM32FXXXRCC_APB1RSTR_tim14rst;
	stm32fxxx_rcc_apb1rstr.tim13rst = STM32FXXXRCC_APB1RSTR_tim13rst;
	stm32fxxx_rcc_apb1rstr.tim12rst = STM32FXXXRCC_APB1RSTR_tim12rst;
	stm32fxxx_rcc_apb1rstr.tim7rst = STM32FXXXRCC_APB1RSTR_tim7rst;
	stm32fxxx_rcc_apb1rstr.tim6rst = STM32FXXXRCC_APB1RSTR_tim6rst;
	stm32fxxx_rcc_apb1rstr.tim5rst = STM32FXXXRCC_APB1RSTR_tim5rst;
	stm32fxxx_rcc_apb1rstr.tim4rst = STM32FXXXRCC_APB1RSTR_tim4rst;
	stm32fxxx_rcc_apb1rstr.tim3rst = STM32FXXXRCC_APB1RSTR_tim3rst;
	stm32fxxx_rcc_apb1rstr.tim2rst = STM32FXXXRCC_APB1RSTR_tim2rst;
	return &stm32fxxx_rcc_apb1rstr;
}
STM32FXXXRCC_apb2rstr* stm32fxxx_rcc_apb2rstr_inic(void)
{

	// APB2RSTR
	stm32fxxx_rcc_apb2rstr.sai2rst = STM32FXXXRCC_APB2RSTR_sai2rst;
	stm32fxxx_rcc_apb2rstr.sai1rst = STM32FXXXRCC_APB2RSTR_sai1rst;
	stm32fxxx_rcc_apb2rstr.tim11rst = STM32FXXXRCC_APB2RSTR_tim11rst;
	stm32fxxx_rcc_apb2rstr.tim10rst = STM32FXXXRCC_APB2RSTR_tim10rst;
	stm32fxxx_rcc_apb2rstr.tim9rst = STM32FXXXRCC_APB2RSTR_tim9rst;
	stm32fxxx_rcc_apb2rstr.syscfgrst = STM32FXXXRCC_APB2RSTR_syscfgrst;
	stm32fxxx_rcc_apb2rstr.spi4rst = STM32FXXXRCC_APB2RSTR_spi4rst;
	stm32fxxx_rcc_apb2rstr.spi1rst = STM32FXXXRCC_APB2RSTR_spi1rst;
	stm32fxxx_rcc_apb2rstr.sdiorst = STM32FXXXRCC_APB2RSTR_sdiorst;
	stm32fxxx_rcc_apb2rstr.adcrst = STM32FXXXRCC_APB2RSTR_adcrst;
	stm32fxxx_rcc_apb2rstr.usart6rst = STM32FXXXRCC_APB2RSTR_usart6rst;
	stm32fxxx_rcc_apb2rstr.usart1rst = STM32FXXXRCC_APB2RSTR_usart1rst;
	stm32fxxx_rcc_apb2rstr.tim8rst = STM32FXXXRCC_APB2RSTR_tim8rst;
	stm32fxxx_rcc_apb2rstr.tim1rst = STM32FXXXRCC_APB2RSTR_tim1rst;
	return &stm32fxxx_rcc_apb2rstr;
}
STM32FXXXRCC_ahb1enr* stm32fxxx_rcc_ahb1enr_inic(void)
{

	// AHB1ENR
	stm32fxxx_rcc_ahb1enr.otghsulpien = STM32FXXXRCC_AHB1ENR_otghsulpien;
	stm32fxxx_rcc_ahb1enr.otghsen = STM32FXXXRCC_AHB1ENR_otghsen;
	stm32fxxx_rcc_ahb1enr.dma2en = STM32FXXXRCC_AHB1ENR_dma2en;
	stm32fxxx_rcc_ahb1enr.dma1en = STM32FXXXRCC_AHB1ENR_dma1en;
	stm32fxxx_rcc_ahb1enr.bkpsramen = STM32FXXXRCC_AHB1ENR_bkpsramen;
	stm32fxxx_rcc_ahb1enr.crcen = STM32FXXXRCC_AHB1ENR_crcen;
	stm32fxxx_rcc_ahb1enr.gpiohen = STM32FXXXRCC_AHB1ENR_gpiohen;
	stm32fxxx_rcc_ahb1enr.gpiogen = STM32FXXXRCC_AHB1ENR_gpiogen;
	stm32fxxx_rcc_ahb1enr.gpiofen = STM32FXXXRCC_AHB1ENR_gpiofen;
	stm32fxxx_rcc_ahb1enr.gpioeen = STM32FXXXRCC_AHB1ENR_gpioeen;
	stm32fxxx_rcc_ahb1enr.gpioden = STM32FXXXRCC_AHB1ENR_gpioden;
	stm32fxxx_rcc_ahb1enr.gpiocen = STM32FXXXRCC_AHB1ENR_gpiocen;
	stm32fxxx_rcc_ahb1enr.gpioben = STM32FXXXRCC_AHB1ENR_gpioben;
	stm32fxxx_rcc_ahb1enr.gpioaen = STM32FXXXRCC_AHB1ENR_gpioaen;
	return &stm32fxxx_rcc_ahb1enr;
}
STM32FXXXRCC_ahb2enr* stm32fxxx_rcc_ahb2enr_inic(void)
{

	// AHB2ENR
	stm32fxxx_rcc_ahb2enr.otgfsen = STM32FXXXRCC_AHB2ENR_otgfsen;
	stm32fxxx_rcc_ahb2enr.dcmien = STM32FXXXRCC_AHB2ENR_dcmien;
	return &stm32fxxx_rcc_ahb2enr;
}
STM32FXXXRCC_apb1enr* stm32fxxx_rcc_apb1enr_inic(void)
{

	// APB1ENR
	stm32fxxx_rcc_apb1enr.dacen = STM32FXXXRCC_APB1ENR_dacen;
	stm32fxxx_rcc_apb1enr.pwren = STM32FXXXRCC_APB1ENR_pwren;
	stm32fxxx_rcc_apb1enr.cecen = STM32FXXXRCC_APB1ENR_cecen;
	stm32fxxx_rcc_apb1enr.can2en = STM32FXXXRCC_APB1ENR_can2en;
	stm32fxxx_rcc_apb1enr.can1en = STM32FXXXRCC_APB1ENR_can1en;
	stm32fxxx_rcc_apb1enr.fmpi2c1en = STM32FXXXRCC_APB1ENR_fmpi2c1en;
	stm32fxxx_rcc_apb1enr.i2c3en = STM32FXXXRCC_APB1ENR_i2c3en;
	stm32fxxx_rcc_apb1enr.i2c2en = STM32FXXXRCC_APB1ENR_i2c2en;
	stm32fxxx_rcc_apb1enr.i2c1en = STM32FXXXRCC_APB1ENR_i2c1en;
	stm32fxxx_rcc_apb1enr.uart5en = STM32FXXXRCC_APB1ENR_uart5en;
	stm32fxxx_rcc_apb1enr.uart4en = STM32FXXXRCC_APB1ENR_uart4en;
	stm32fxxx_rcc_apb1enr.usart3en = STM32FXXXRCC_APB1ENR_usart3en;
	stm32fxxx_rcc_apb1enr.usart2en = STM32FXXXRCC_APB1ENR_usart2en;
	stm32fxxx_rcc_apb1enr.spdifrxen = STM32FXXXRCC_APB1ENR_spdifrxen;
	stm32fxxx_rcc_apb1enr.spi3en = STM32FXXXRCC_APB1ENR_spi3en;
	stm32fxxx_rcc_apb1enr.spi2en = STM32FXXXRCC_APB1ENR_spi2en;
	stm32fxxx_rcc_apb1enr.wwdgen = STM32FXXXRCC_APB1ENR_wwdgen;
	stm32fxxx_rcc_apb1enr.tim14en = STM32FXXXRCC_APB1ENR_tim14en;
	stm32fxxx_rcc_apb1enr.tim13en = STM32FXXXRCC_APB1ENR_tim13en;
	stm32fxxx_rcc_apb1enr.tim12en = STM32FXXXRCC_APB1ENR_tim12en;
	stm32fxxx_rcc_apb1enr.tim7en = STM32FXXXRCC_APB1ENR_tim7en;
	stm32fxxx_rcc_apb1enr.tim6en = STM32FXXXRCC_APB1ENR_tim6en;
	stm32fxxx_rcc_apb1enr.tim5en = STM32FXXXRCC_APB1ENR_tim5en;
	stm32fxxx_rcc_apb1enr.tim4en = STM32FXXXRCC_APB1ENR_tim4en;
	stm32fxxx_rcc_apb1enr.tim3en = STM32FXXXRCC_APB1ENR_tim3en;
	stm32fxxx_rcc_apb1enr.tim2en = STM32FXXXRCC_APB1ENR_tim2en;
	return &stm32fxxx_rcc_apb1enr;
}
STM32FXXXRCC_apb2enr* stm32fxxx_rcc_apb2enr_inic(void)
{

	// APB2ENR
	stm32fxxx_rcc_apb2enr.sai2en = STM32FXXXRCC_APB2ENR_sai2en;
	stm32fxxx_rcc_apb2enr.sai1en = STM32FXXXRCC_APB2ENR_sai1en;
	stm32fxxx_rcc_apb2enr.tim11en = STM32FXXXRCC_APB2ENR_tim11en;
	stm32fxxx_rcc_apb2enr.tim10en = STM32FXXXRCC_APB2ENR_tim10en;
	stm32fxxx_rcc_apb2enr.tim9en = STM32FXXXRCC_APB2ENR_tim9en;
	stm32fxxx_rcc_apb2enr.syscfgen = STM32FXXXRCC_APB2ENR_syscfgen;
	stm32fxxx_rcc_apb2enr.spi4en = STM32FXXXRCC_APB2ENR_spi4en;
	stm32fxxx_rcc_apb2enr.spi1en = STM32FXXXRCC_APB2ENR_spi1en;
	stm32fxxx_rcc_apb2enr.sdioen = STM32FXXXRCC_APB2ENR_sdioen;
	stm32fxxx_rcc_apb2enr.adc3en = STM32FXXXRCC_APB2ENR_adc3en;
	stm32fxxx_rcc_apb2enr.adc2en = STM32FXXXRCC_APB2ENR_adc2en;
	stm32fxxx_rcc_apb2enr.adc1en = STM32FXXXRCC_APB2ENR_adc1en;
	stm32fxxx_rcc_apb2enr.usart6en = STM32FXXXRCC_APB2ENR_usart6en;
	stm32fxxx_rcc_apb2enr.usart1en = STM32FXXXRCC_APB2ENR_usart1en;
	stm32fxxx_rcc_apb2enr.tim8en = STM32FXXXRCC_APB2ENR_tim8en;
	stm32fxxx_rcc_apb2enr.tim1en = STM32FXXXRCC_APB2ENR_tim1en;
	return &stm32fxxx_rcc_apb2enr;
}
STM32FXXXRCC_ahb1lpenr* stm32fxxx_rcc_ahb1lpenr_inic(void)
{

	//AHB1LPENR
	stm32fxxx_rcc_ahb1lpenr.otghsulpilpen = STM32FXXXRCC_AHB1LPENR_otghsulpilpen;
	stm32fxxx_rcc_ahb1lpenr.otghslpen = STM32FXXXRCC_AHB1LPENR_otghslpen;
	stm32fxxx_rcc_ahb1lpenr.dma2lpen = STM32FXXXRCC_AHB1LPENR_dma2lpen;
	stm32fxxx_rcc_ahb1lpenr.dma1lpen = STM32FXXXRCC_AHB1LPENR_dma1lpen;
	stm32fxxx_rcc_ahb1lpenr.bkpsramlpen = STM32FXXXRCC_AHB1LPENR_bkpsramlpen;
	stm32fxxx_rcc_ahb1lpenr.sram2lpen = STM32FXXXRCC_AHB1LPENR_sram2lpen;
	stm32fxxx_rcc_ahb1lpenr.sram1lpen = STM32FXXXRCC_AHB1LPENR_sram1lpen;
	stm32fxxx_rcc_ahb1lpenr.flitflpen = STM32FXXXRCC_AHB1LPENR_flitflpen;
	stm32fxxx_rcc_ahb1lpenr.crclpen = STM32FXXXRCC_AHB1LPENR_crclpen;
	stm32fxxx_rcc_ahb1lpenr.gpiohlpen = STM32FXXXRCC_AHB1LPENR_gpiohlpen;
	stm32fxxx_rcc_ahb1lpenr.gpioglpen = STM32FXXXRCC_AHB1LPENR_gpioglpen;
	stm32fxxx_rcc_ahb1lpenr.gpioflpen = STM32FXXXRCC_AHB1LPENR_gpioflpen;
	stm32fxxx_rcc_ahb1lpenr.gpioelpen = STM32FXXXRCC_AHB1LPENR_gpioelpen;
	stm32fxxx_rcc_ahb1lpenr.gpiodlpen = STM32FXXXRCC_AHB1LPENR_gpiodlpen;
	stm32fxxx_rcc_ahb1lpenr.gpioclpen = STM32FXXXRCC_AHB1LPENR_gpioclpen;
	stm32fxxx_rcc_ahb1lpenr.gpioblpen = STM32FXXXRCC_AHB1LPENR_gpioblpen;
	stm32fxxx_rcc_ahb1lpenr.gpioalpen = STM32FXXXRCC_AHB1LPENR_gpioalpen;
	return &stm32fxxx_rcc_ahb1lpenr;
}
STM32FXXXRCC_ahb2lpenr* stm32fxxx_rcc_ahb2lpenr_inic(void)
{

	// AHB2LPENR
	stm32fxxx_rcc_ahb2lpenr.otgfslpen = STM32FXXXRCC_AHB2LPENR_otgfslpen;
	stm32fxxx_rcc_ahb2lpenr.dcmilpen = STM32FXXXRCC_AHB2LPENR_dcmilpen;
	return &stm32fxxx_rcc_ahb2lpenr;
}
STM32FXXXRCC_apb1lpenr* stm32fxxx_rcc_apb1lpenr_inic(void)
{

	// APB1LPENR
	stm32fxxx_rcc_apb1lpenr.daclpen = STM32FXXXRCC_APB1LPENR_daclpen;
	stm32fxxx_rcc_apb1lpenr.pwrlpen = STM32FXXXRCC_APB1LPENR_pwrlpen;
	stm32fxxx_rcc_apb1lpenr.ceclpen = STM32FXXXRCC_APB1LPENR_ceclpen;
	stm32fxxx_rcc_apb1lpenr.can2lpen = STM32FXXXRCC_APB1LPENR_can2lpen;
	stm32fxxx_rcc_apb1lpenr.can1lpen = STM32FXXXRCC_APB1LPENR_can1lpen;
	stm32fxxx_rcc_apb1lpenr.fmpi2c1lpen = STM32FXXXRCC_APB1LPENR_fmpi2c1lpen;
	stm32fxxx_rcc_apb1lpenr.i2c3lpen = STM32FXXXRCC_APB1LPENR_i2c3lpen;
	stm32fxxx_rcc_apb1lpenr.i2c2lpen = STM32FXXXRCC_APB1LPENR_i2c2lpen;
	stm32fxxx_rcc_apb1lpenr.i2c1lpen = STM32FXXXRCC_APB1LPENR_i2c1lpen;
	stm32fxxx_rcc_apb1lpenr.uart5lpen = STM32FXXXRCC_APB1LPENR_uart5lpen;
	stm32fxxx_rcc_apb1lpenr.uart4lpen = STM32FXXXRCC_APB1LPENR_uart4lpen;
	stm32fxxx_rcc_apb1lpenr.usart3lpen = STM32FXXXRCC_APB1LPENR_usart3lpen;
	stm32fxxx_rcc_apb1lpenr.usart2lpen = STM32FXXXRCC_APB1LPENR_usart2lpen;
	stm32fxxx_rcc_apb1lpenr.spdifrxlpen = STM32FXXXRCC_APB1LPENR_spdifrxlpen;
	stm32fxxx_rcc_apb1lpenr.spi3lpen = STM32FXXXRCC_APB1LPENR_spi3lpen;
	stm32fxxx_rcc_apb1lpenr.spi2lpen = STM32FXXXRCC_APB1LPENR_spi2lpen;
	stm32fxxx_rcc_apb1lpenr.wwdglpen = STM32FXXXRCC_APB1LPENR_wwdglpen;
	stm32fxxx_rcc_apb1lpenr.tim14lpen = STM32FXXXRCC_APB1LPENR_tim14lpen;
	stm32fxxx_rcc_apb1lpenr.tim13lpen = STM32FXXXRCC_APB1LPENR_tim13lpen;
	stm32fxxx_rcc_apb1lpenr.tim12lpen = STM32FXXXRCC_APB1LPENR_tim12lpen;
	stm32fxxx_rcc_apb1lpenr.tim7lpen = STM32FXXXRCC_APB1LPENR_tim7lpen;
	stm32fxxx_rcc_apb1lpenr.tim6lpen = STM32FXXXRCC_APB1LPENR_tim6lpen;
	stm32fxxx_rcc_apb1lpenr.tim5lpen = STM32FXXXRCC_APB1LPENR_tim5lpen;
	stm32fxxx_rcc_apb1lpenr.tim4lpen = STM32FXXXRCC_APB1LPENR_tim4lpen;
	stm32fxxx_rcc_apb1lpenr.tim3lpen = STM32FXXXRCC_APB1LPENR_tim3lpen;
	stm32fxxx_rcc_apb1lpenr.tim2lpen = STM32FXXXRCC_APB1LPENR_tim2lpen;
	return &stm32fxxx_rcc_apb1lpenr;
}
STM32FXXXRCC_apb2lpenr* stm32fxxx_rcc_apb2lpenr_inic(void)
{

	// APB2LPENR
	stm32fxxx_rcc_apb2lpenr.sai2lpen = STM32FXXXRCC_APB2LPENR_sai2lpen;
	stm32fxxx_rcc_apb2lpenr.sai1lpen = STM32FXXXRCC_APB2LPENR_sai1lpen;
	stm32fxxx_rcc_apb2lpenr.tim11lpen = STM32FXXXRCC_APB2LPENR_tim11lpen;
	stm32fxxx_rcc_apb2lpenr.tim10lpen = STM32FXXXRCC_APB2LPENR_tim10lpen;
	stm32fxxx_rcc_apb2lpenr.tim9lpen = STM32FXXXRCC_APB2LPENR_tim9lpen;
	stm32fxxx_rcc_apb2lpenr.syscfglpen = STM32FXXXRCC_APB2LPENR_syscfglpen;
	stm32fxxx_rcc_apb2lpenr.spi4lpen = STM32FXXXRCC_APB2LPENR_spi4lpen;
	stm32fxxx_rcc_apb2lpenr.sai1lpen = STM32FXXXRCC_APB2LPENR_spi1lpen;
	stm32fxxx_rcc_apb2lpenr.sdiolpen = STM32FXXXRCC_APB2LPENR_sdiolpen;
	stm32fxxx_rcc_apb2lpenr.adc3lpen = STM32FXXXRCC_APB2LPENR_adc3lpen;
	stm32fxxx_rcc_apb2lpenr.adc2lpen = STM32FXXXRCC_APB2LPENR_adc2lpen;
	stm32fxxx_rcc_apb2lpenr.adc1lpen = STM32FXXXRCC_APB2LPENR_adc1lpen;
	stm32fxxx_rcc_apb2lpenr.usart6lpen = STM32FXXXRCC_APB2LPENR_usart6lpen;
	stm32fxxx_rcc_apb2lpenr.usart1lpen = STM32FXXXRCC_APB2LPENR_usart1lpen;
	stm32fxxx_rcc_apb2lpenr.tim8lpen = STM32FXXXRCC_APB2LPENR_tim8lpen;
	stm32fxxx_rcc_apb2lpenr.tim1lpen = STM32FXXXRCC_APB2LPENR_tim1lpen;
	return &stm32fxxx_rcc_apb2lpenr;
}
STM32FXXXRCC_bdcr* stm32fxxx_rcc_bdcr_inic(void)
{

	// BDCR
	stm32fxxx_rcc_bdcr.bdrst = STM32FXXXRCC_BDCR_bdrst;
	stm32fxxx_rcc_bdcr.rtcen = STM32FXXXRCC_BDCR_rtcen;
	stm32fxxx_rcc_bdcr.get_rtcen = STM32FXXXRCC_BDCR_get_rtcen;
	stm32fxxx_rcc_bdcr.rtcsel = STM32FXXXRCC_BDCR_rtcsel;
	stm32fxxx_rcc_bdcr.get_rtcsel = STM32FXXXRCC_BDCR_get_rtcsel;
	stm32fxxx_rcc_bdcr.lsemod = STM32FXXXRCC_BDCR_lsemod;
	stm32fxxx_rcc_bdcr.lsebyp = STM32FXXXRCC_BDCR_lsebyp;
	stm32fxxx_rcc_bdcr.get_lserdy = STM32FXXXRCC_BDCR_get_lserdy;
	stm32fxxx_rcc_bdcr.lseon = STM32FXXXRCC_BDCR_lseon;
	return &stm32fxxx_rcc_bdcr;
}
STM32FXXXRCC_csr* stm32fxxx_rcc_csr_inic(void)
{

	// CSR
	stm32fxxx_rcc_csr.get_lpwrrstf = STM32FXXXRCC_CSR_get_lpwrrstf;
	stm32fxxx_rcc_csr.get_wwdgrstf = STM32FXXXRCC_CSR_get_wwdgrstf;
	stm32fxxx_rcc_csr.get_iwdqrstf = STM32FXXXRCC_CSR_get_iwdqrstf;
	stm32fxxx_rcc_csr.get_sftrstf = STM32FXXXRCC_CSR_get_sftrstf;
	stm32fxxx_rcc_csr.get_porrstf = STM32FXXXRCC_CSR_get_porrstf;
	stm32fxxx_rcc_csr.get_pinrstf = STM32FXXXRCC_CSR_get_pinrstf;
	stm32fxxx_rcc_csr.get_borrstf = STM32FXXXRCC_CSR_get_borrstf;
	stm32fxxx_rcc_csr.clear_rmvf = STM32FXXXRCC_CSR_clear_rmvf;
	stm32fxxx_rcc_csr.get_lsirdy = STM32FXXXRCC_CSR_get_lsirdy;
	stm32fxxx_rcc_csr.lsion = STM32FXXXRCC_CSR_lsion;
	return &stm32fxxx_rcc_csr;
}
STM32FXXXRCC_sscgr* stm32fxxx_rcc_sscgr_inic(void)
{

	// SSCGR
	stm32fxxx_rcc_sscgr.sscgen = STM32FXXXRCC_SSCGR_sscgen;
	stm32fxxx_rcc_sscgr.spreadsel = STM32FXXXRCC_SSCGR_spreadsel;
	stm32fxxx_rcc_sscgr.incstep = STM32FXXXRCC_SSCGR_incstep;
	stm32fxxx_rcc_sscgr.modper = STM32FXXXRCC_SSCGR_modper;
	return &stm32fxxx_rcc_sscgr;
}
STM32FXXXRCC_plli2scfgr* stm32fxxx_rcc_plli2scfgr_inic(void)
{

	// PLLI2SCFGR
	stm32fxxx_rcc_plli2scfgr.plli2sr = STM32FXXXRCC_PLLI2SCFGR_plli2sr;
	stm32fxxx_rcc_plli2scfgr.plli2sq = STM32FXXXRCC_PLLI2SCFGR_plli2sq;
	stm32fxxx_rcc_plli2scfgr.plli2sp = STM32FXXXRCC_PLLI2SCFGR_plli2sp;
	stm32fxxx_rcc_plli2scfgr.plli2sn = STM32FXXXRCC_PLLI2SCFGR_plli2sn;
	stm32fxxx_rcc_plli2scfgr.plli2sm = STM32FXXXRCC_PLLI2SCFGR_plli2sm;
	return &stm32fxxx_rcc_plli2scfgr;
}
STM32FXXXRCC_dckcfgr* stm32fxxx_rcc_dckcfgr_inic(void)
{

	// DCKCFGR
	stm32fxxx_rcc_dckcfgr.i2s2src = STM32FXXXRCC_DCKCFGR_i2s2src;
	stm32fxxx_rcc_dckcfgr.i2s1src = STM32FXXXRCC_DCKCFGR_i2s1src;
	stm32fxxx_rcc_dckcfgr.timpre = STM32FXXXRCC_DCKCFGR_timpre;
	stm32fxxx_rcc_dckcfgr.sai2src = STM32FXXXRCC_DCKCFGR_sai2src;
	stm32fxxx_rcc_dckcfgr.sai1src = STM32FXXXRCC_DCKCFGR_sai1src;
	stm32fxxx_rcc_dckcfgr.pllsaidivq = STM32FXXXRCC_DCKCFGR_pllsaidivq;
	stm32fxxx_rcc_dckcfgr.plli2sdivq = STM32FXXXRCC_DCKCFGR_plli2sdivq;
	return &stm32fxxx_rcc_dckcfgr;
}
/*** Extended ***/
STM32FXXXRCCPLL* stm32fxxx_rcc_pll_inic(void)
{

	stm32fxxx_rcc_pll.division = STM32FXXXPLLDivision;
	stm32fxxx_rcc_pll.enable = STM32FXXXRccPLLCLKEnable;
	return &stm32fxxx_rcc_pll;
}
STM32FXXXRCCPLLI2S* stm32fxxx_rcc_plli2s_inic(void)
{

	stm32fxxx_rcc_plli2s.enable = STM32FXXXRccPLLI2SEnable;
	return &stm32fxxx_rcc_plli2s;
}
STM32FXXXRCCPLLSAI* stm32fxxx_rcc_pllsai_inic(void)
{

	stm32fxxx_rcc_pllsai.enable = STM32FXXXRccPLLSAIEnable;
	return &stm32fxxx_rcc_pllsai;
}
/*** INIC Procedure & Function Definition ***/
STM32FXXXRCCobj rcc_enable(void)
{


	/*** RCC Bit Mapping Link ***/
	stm32fxxx_rcc.cr = stm32fxxx_rcc_cr_inic();
	stm32fxxx_rcc.pllcfgr = stm32fxxx_rcc_pllcfgr_inic();
	stm32fxxx_rcc.cfgr = stm32fxxx_rcc_cfgr_inic();
	stm32fxxx_rcc.cir = stm32fxxx_rcc_cir_inic();
	stm32fxxx_rcc.ahb1rstr = stm32fxxx_rcc_ahb1rstr_inic();
	stm32fxxx_rcc.ahb2rstr = stm32fxxx_rcc_ahb2rstr_inic();
	stm32fxxx_rcc.apb1rstr = stm32fxxx_rcc_apb1rstr_inic();
	stm32fxxx_rcc.apb2rstr = stm32fxxx_rcc_apb2rstr_inic();
	stm32fxxx_rcc.ahb1enr = stm32fxxx_rcc_ahb1enr_inic();
	stm32fxxx_rcc.ahb2enr = stm32fxxx_rcc_ahb2enr_inic();
	stm32fxxx_rcc.apb1enr = stm32fxxx_rcc_apb1enr_inic();
	stm32fxxx_rcc.apb2enr = stm32fxxx_rcc_apb2enr_inic();
	stm32fxxx_rcc.ahb1lpenr = stm32fxxx_rcc_ahb1lpenr_inic();
	stm32fxxx_rcc.ahb2lpenr = stm32fxxx_rcc_ahb2lpenr_inic();
	stm32fxxx_rcc.apb1lpenr = stm32fxxx_rcc_apb1lpenr_inic();
	stm32fxxx_rcc.apb2lpenr = stm32fxxx_rcc_apb2lpenr_inic();
	stm32fxxx_rcc.bdcr = stm32fxxx_rcc_bdcr_inic();
	stm32fxxx_rcc.csr = stm32fxxx_rcc_csr_inic();
	stm32fxxx_rcc.sscgr = stm32fxxx_rcc_sscgr_inic();
	stm32fxxx_rcc.plli2scfgr = stm32fxxx_rcc_plli2scfgr_inic();
	stm32fxxx_rcc.dckcfgr = stm32fxxx_rcc_dckcfgr_inic();
	/*** PLL ***/
	stm32fxxx_rcc.pll = stm32fxxx_rcc_pll_inic();
	stm32fxxx_rcc.plli2s = stm32fxxx_rcc_plli2s_inic();
	stm32fxxx_rcc.pllsai = stm32fxxx_rcc_pllsai_inic();
	stm32fxxx_rcc.prescaler = STM32FXXXPrescaler;
	/*** Other ***/
	stm32fxxx_rcc.pll_division = STM32FXXXPLLDivision;
	stm32fxxx_rcc.pllclk_enable = STM32FXXXRccPLLCLKEnable;
	stm32fxxx_rcc.plli2s_enable = STM32FXXXRccPLLI2SEnable;
	stm32fxxx_rcc.pllsai_enable = STM32FXXXRccPLLSAIEnable;
	stm32fxxx_rcc.inic = rcc_start;
	stm32fxxx_rcc.henable = STM32FXXXRccHEnable;
	stm32fxxx_rcc.hselect = STM32FXXXRccHSelect;
	stm32fxxx_rcc.lenable = STM32FXXXRccLEnable;
	stm32fxxx_rcc.lselect = STM32FXXXRccLSelect;
	/*** Nvic ***/
	stm32fxxx_rcc.nvic = STM32FXXXRCC_nvic;
	return stm32fxxx_rcc;
}

STM32FXXXRCCobj* rcc(void){ return &stm32fxxx_rcc; };

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

