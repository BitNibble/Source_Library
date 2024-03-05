/******************************************************************************
	STM32 XXX RCCBF
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 05032024
Comment:
	RCC BIT FIELD TypeDef for STM32F411CEU6 and STM32F446RE
*******************************************************************************/
#ifndef _STM32RCCBF_H_
	#define _STM32RCCBF_H_

#include <inttypes.h>

/*** RCC Bit Field TypeDef ***/
// CR
typedef struct
{
	uint8_t (*get_pllsairdy)(void);
	void (*pllsaion)(uint8_t bool);
	uint8_t (*get_plli2srdy)(void);
	void (*plli2son)(uint8_t bool);
	uint8_t (*get_pllrdy)(void);
	void (*pllon)(uint8_t bool);
	void (*csson)(uint8_t bool);
	void (*hsebyp)(uint8_t bool);
	uint8_t (*get_hserdy)(void);
	void (*hseon)(uint8_t bool);
	uint8_t (*get_hsical)(void);
	void (*hsitrim)(uint8_t value);
	uint8_t (*get_hsirdy)(void);
	void (*hsion)(uint8_t bool);
}STM32FXXXRCC_cr;
/*
volatile typedef union{
	struct TIM_CR_1{
		uint32_t hsion:1;
		uint32_t hsirdy:1;
		uint32_t reserved1:1;
		uint32_t hsitrim:5;
		uint32_t hsical:8;
		uint32_t hseon:1;
		uint32_t hserdy:1;
		uint32_t hsebyp:1;
		uint32_t csson:1;
		uint32_t reserved2:4;
		uint32_t pllon:1;
		uint32_t pllrdy:1;
		uint32_t plli2son:1;
		uint32_t plli2srdy:1;
		uint32_t pllsaion:1;
		uint32_t pllsairdy:1;
		uint32_t reserved3:2;
	}par;
	uint32_t reg;
}STM32FXXXRCC_CR_TypeDef;
*/
// PLLCFGR
typedef struct
{
	void (*pllr)(uint8_t value);
	void (*pllq)(uint8_t value);
	void (*pllsrc)(uint8_t bool);
	void (*pllp)(uint8_t value);
	void (*plln)(uint16_t value);
	void (*pllm)(uint8_t value);
}STM32FXXXRCC_pllcfgr;
/*
volatile typedef union{
	struct TIM_PLLCFGR_1{
		uint32_t pllm:6;
		uint32_t plln:9;
		uint32_t reserved1:1;
		uint32_t pllp:2;
		uint32_t reserved2:4;
		uint32_t pllsrc:1;
		uint32_t reserved3:1;
		uint32_t pllq:4;
		uint32_t pllr:3;
		uint32_t reserved4:1;
	}par;
	uint32_t reg;
}STM32FXXXRCC_PLLCFGR_TypeDef;
*/
// CFGR
typedef struct
{
	void (*mco2)(uint8_t value);
	void (*mco2pre)(uint8_t value);
	void (*mco1pre)(uint8_t value);
	void (*mco1)(uint8_t value);
	void (*rtcpre)(uint8_t value);
	void (*ppre2)(uint8_t value);
	void (*ppre1)(uint8_t value);
	void (*hpre)(uint8_t value);
	uint8_t (*get_sws)(void);
	void (*sw)(uint8_t value);
}STM32FXXXRCC_cfgr;
// CIR
typedef struct
{
	void (*clear_cssc)(void);
	void (*clear_pllsairdyc)(void);
	void (*clear_plli2srdyc)(void);
	void (*clear_pllrdyc)(void);
	void (*clear_hserdyc)(void);
	void (*clear_hsirdyc)(void);
	void (*clear_lserdyc)(void);
	void (*clear_lsirdyc)(void);
	void (*pllsairdyie)(uint8_t bool);
	void (*plli2srdyie)(uint8_t bool);
	void (*pllrdyie)(uint8_t bool);
	void (*hserdyie)(uint8_t bool);
	void (*hsirdyie)(uint8_t bool);
	void (*lserdyie)(uint8_t bool);
	void (*lsirdyie)(uint8_t bool);
	uint8_t (*get_cssf)(void);
	uint8_t (*get_pllsairdyf)(void);
	uint8_t (*get_plli2srdyf)(void);
	uint8_t (*get_pllrdyf)(void);
	uint8_t (*get_hserdyf)(void);
	uint8_t (*get_hsirdyf)(void);
	uint8_t (*get_lserdyf)(void);
	uint8_t (*get_lsirdyf)(void);
}STM32FXXXRCC_cir;
// AHB1RSTR
typedef struct
{
	void (*otghsrst)(uint8_t bool);
	void (*dma2rst)(uint8_t bool);
	void (*dma1rst)(uint8_t bool);
	void (*crcrst)(uint8_t bool);
	void (*gpiohrst)(uint8_t bool);
	void (*gpiogrst)(uint8_t bool);
	void (*gpiofrst)(uint8_t bool);
	void (*gpioerst)(uint8_t bool);
	void (*gpiodrst)(uint8_t bool);
	void (*gpiocrst)(uint8_t bool);
	void (*gpiobrst)(uint8_t bool);
	void (*gpioarst)(uint8_t bool);
}STM32FXXXRCC_ahb1rstr;
// AHB2RSTR
typedef struct
{
	void (*otgfsrst)(uint8_t bool);
	void (*dcmirst)(uint8_t bool);
}STM32FXXXRCC_ahb2rstr;
// AHB3RSTR
typedef struct
{
	void (*qspirst)(uint8_t bool);
	void (*fmcrst)(uint8_t bool);
}STM32FXXXRCC_ahb3rstr;
// APB1RSTR
typedef struct
{
	void (*dacrst)(uint8_t bool);
	void (*pwrrst)(uint8_t bool);
	void (*cecrst)(uint8_t bool);
	void (*can2rst)(uint8_t bool);
	void (*can1rst)(uint8_t bool);
	void (*fmpi2c1rst)(uint8_t bool);
	void (*i2c3rst)(uint8_t bool);
	void (*i2c2rst)(uint8_t bool);
	void (*i2c1rst)(uint8_t bool);
	void (*uart5rst)(uint8_t bool);
	void (*uart4rst)(uint8_t bool);
	void (*usart3rst)(uint8_t bool);
	void (*usart2rst)(uint8_t bool);
	void (*spdifrxrst)(uint8_t bool);
	void (*spi3rst)(uint8_t bool);
	void (*spi2rst)(uint8_t bool);
	void (*wwdgrst)(uint8_t bool);
	void (*tim14rst)(uint8_t bool);
	void (*tim13rst)(uint8_t bool);
	void (*tim12rst)(uint8_t bool);
	void (*tim7rst)(uint8_t bool);
	void (*tim6rst)(uint8_t bool);
	void (*tim5rst)(uint8_t bool);
	void (*tim4rst)(uint8_t bool);
	void (*tim3rst)(uint8_t bool);
	void (*tim2rst)(uint8_t bool);
}STM32FXXXRCC_apb1rstr;
// APB2RSTR
typedef struct
{
	void (*sai2rst)(uint8_t bool);
	void (*sai1rst)(uint8_t bool);
	void (*tim11rst)(uint8_t bool);
	void (*tim10rst)(uint8_t bool);
	void (*tim9rst)(uint8_t bool);
	void (*syscfgrst)(uint8_t bool);
	void (*spi4rst)(uint8_t bool);
	void (*spi1rst)(uint8_t bool);
	void (*sdiorst)(uint8_t bool);
	void (*adcrst)(uint8_t bool);
	void (*usart6rst)(uint8_t bool);
	void (*usart1rst)(uint8_t bool);
	void (*tim8rst)(uint8_t bool);
	void (*tim1rst)(uint8_t bool);
}STM32FXXXRCC_apb2rstr;
// AHB1ENR
typedef struct
{
	void (*otghsulpien)(uint8_t bool);
	void (*otghsen)(uint8_t bool);
	void (*dma2en)(uint8_t bool);
	void (*dma1en)(uint8_t bool);
	void (*bkpsramen)(uint8_t bool);
	void (*crcen)(uint8_t bool);
	void (*gpiohen)(uint8_t bool);
	void (*gpiogen)(uint8_t bool);
	void (*gpiofen)(uint8_t bool);
	void (*gpioeen)(uint8_t bool);
	void (*gpioden)(uint8_t bool);
	void (*gpiocen)(uint8_t bool);
	void (*gpioben)(uint8_t bool);
	void (*gpioaen)(uint8_t bool);
}STM32FXXXRCC_ahb1enr;
// AHB2ENR
typedef struct
{
	void (*otgfsen)(uint8_t bool);
	void (*dcmien)(uint8_t bool);
}STM32FXXXRCC_ahb2enr;
// APB1ENR
typedef struct
{
	void (*dacen)(uint8_t bool);
	void (*pwren)(uint8_t bool);
	void (*cecen)(uint8_t bool);
	void (*can2en)(uint8_t bool);
	void (*can1en)(uint8_t bool);
	void (*fmpi2c1en)(uint8_t bool);
	void (*i2c3en)(uint8_t bool);
	void (*i2c2en)(uint8_t bool);
	void (*i2c1en)(uint8_t bool);
	void (*uart5en)(uint8_t bool);
	void (*uart4en)(uint8_t bool);
	void (*usart3en)(uint8_t bool);
	void (*usart2en)(uint8_t bool);
	void (*spdifrxen)(uint8_t bool);
	void (*spi3en)(uint8_t bool);
	void (*spi2en)(uint8_t bool);
	void (*wwdgen)(uint8_t bool);
	void (*tim14en)(uint8_t bool);
	void (*tim13en)(uint8_t bool);
	void (*tim12en)(uint8_t bool);
	void (*tim7en)(uint8_t bool);
	void (*tim6en)(uint8_t bool);
	void (*tim5en)(uint8_t bool);
	void (*tim4en)(uint8_t bool);
	void (*tim3en)(uint8_t bool);
	void (*tim2en)(uint8_t bool);
}STM32FXXXRCC_apb1enr;
// APB2ENR
typedef struct
{
	void (*sai2en)(uint8_t bool);
	void (*sai1en)(uint8_t bool);
	void (*tim11en)(uint8_t bool);
	void (*tim10en)(uint8_t bool);
	void (*tim9en)(uint8_t bool);
	void (*syscfgen)(uint8_t bool);
	void (*spi4en)(uint8_t bool);
	void (*spi1en)(uint8_t bool);
	void (*sdioen)(uint8_t bool);
	void (*adc3en)(uint8_t bool);
	void (*adc2en)(uint8_t bool);
	void (*adc1en)(uint8_t bool);
	void (*usart6en)(uint8_t bool);
	void (*usart1en)(uint8_t bool);
	void (*tim8en)(uint8_t bool);
	void (*tim1en)(uint8_t bool);
}STM32FXXXRCC_apb2enr;
// AHB1LPENR
typedef struct
{
	void (*otghsulpilpen)(uint8_t bool);
	void (*otghslpen)(uint8_t bool);
	void (*dma2lpen)(uint8_t bool);
	void (*dma1lpen)(uint8_t bool);
	void (*bkpsramlpen)(uint8_t bool);
	void (*sram2lpen)(uint8_t bool);
	void (*sram1lpen)(uint8_t bool);
	void (*flitflpen)(uint8_t bool);
	void (*crclpen)(uint8_t bool);
	void (*gpiohlpen)(uint8_t bool);
	void (*gpioglpen)(uint8_t bool);
	void (*gpioflpen)(uint8_t bool);
	void (*gpioelpen)(uint8_t bool);
	void (*gpiodlpen)(uint8_t bool);
	void (*gpioclpen)(uint8_t bool);
	void (*gpioblpen)(uint8_t bool);
	void (*gpioalpen)(uint8_t bool);
}STM32FXXXRCC_ahb1lpenr;
// AHB2LPENR
typedef struct
{
	void (*otgfslpen)(uint8_t bool);
	void (*dcmilpen)(uint8_t bool);
}STM32FXXXRCC_ahb2lpenr;
// AHB3LPENR
typedef struct
{
	void (*qspilpen)(uint8_t bool);
	void (*fmclpen)(uint8_t bool);
}STM32FXXXRCC_ahb3lpenr;
// APB1LPENR
typedef struct
{
	void (*daclpen)(uint8_t bool);
	void (*pwrlpen)(uint8_t bool);
	void (*ceclpen)(uint8_t bool);
	void (*can2lpen)(uint8_t bool);
	void (*can1lpen)(uint8_t bool);
	void (*fmpi2c1lpen)(uint8_t bool);
	void (*i2c3lpen)(uint8_t bool);
	void (*i2c2lpen)(uint8_t bool);
	void (*i2c1lpen)(uint8_t bool);
	void (*uart5lpen)(uint8_t bool);
	void (*uart4lpen)(uint8_t bool);
	void (*usart3lpen)(uint8_t bool);
	void (*usart2lpen)(uint8_t bool);
	void (*spdifrxlpen)(uint8_t bool);
	void (*spi3lpen)(uint8_t bool);
	void (*spi2lpen)(uint8_t bool);
	void (*wwdglpen)(uint8_t bool);
	void (*tim14lpen)(uint8_t bool);
	void (*tim13lpen)(uint8_t bool);
	void (*tim12lpen)(uint8_t bool);
	void (*tim7lpen)(uint8_t bool);
	void (*tim6lpen)(uint8_t bool);
	void (*tim5lpen)(uint8_t bool);
	void (*tim4lpen)(uint8_t bool);
	void (*tim3lpen)(uint8_t bool);
	void (*tim2lpen)(uint8_t bool);
}STM32FXXXRCC_apb1lpenr;
// APB2LPENR
typedef struct
{
	void (*sai2lpen)(uint8_t bool);
	void (*sai1lpen)(uint8_t bool);
	void (*tim11lpen)(uint8_t bool);
	void (*tim10lpen)(uint8_t bool);
	void (*tim9lpen)(uint8_t bool);
	void (*syscfglpen)(uint8_t bool);
	void (*spi4lpen)(uint8_t bool);
	void (*spi1lpen)(uint8_t bool);
	void (*sdiolpen)(uint8_t bool);
	void (*adc3lpen)(uint8_t bool);
	void (*adc2lpen)(uint8_t bool);
	void (*adc1lpen)(uint8_t bool);
	void (*usart6lpen)(uint8_t bool);
	void (*usart1lpen)(uint8_t bool);
	void (*tim8lpen)(uint8_t bool);
	void (*tim1lpen)(uint8_t bool);
}STM32FXXXRCC_apb2lpenr;
// BDCR
typedef struct
{
	void (*bdrst)(uint8_t bool);
	void (*rtcen)(uint8_t bool);
	uint8_t (*get_rtcen)(void);
	void (*rtcsel)(uint8_t value);
	uint8_t (*get_rtcsel)(void);
	void (*lsemod)(uint8_t bool);
	void (*lsebyp)(uint8_t bool);
	uint8_t (*get_lserdy)(void);
	void (*lseon)(uint8_t bool);
}STM32FXXXRCC_bdcr;
// CSR
typedef struct
{
	uint8_t (*get_lpwrrstf)(void);
	uint8_t (*get_wwdgrstf)(void);
	uint8_t (*get_iwdqrstf)(void);
	uint8_t (*get_sftrstf)(void);
	uint8_t (*get_porrstf)(void);
	uint8_t (*get_pinrstf)(void);
	uint8_t (*get_borrstf)(void);
	void (*clear_rmvf)(void);
	uint8_t (*get_lsirdy)(void);
	void (*lsion)(uint8_t bool);
}STM32FXXXRCC_csr;
// SSCGR
typedef struct
{
	void (*sscgen)(uint8_t bool);
	void (*spreadsel)(uint8_t bool);
	void (*incstep)(uint8_t value);
	void (*modper)(uint8_t value);
}STM32FXXXRCC_sscgr;
// PLLI2SCFGR
typedef struct
{
	void (*plli2sr)(uint8_t value);
	void (*plli2sq)(uint8_t value);
	void (*plli2sp)(uint8_t value);
	void (*plli2sn)(uint16_t value);
	void (*plli2sm)(uint8_t value);
}STM32FXXXRCC_plli2scfgr;
// DCKCFGR
typedef struct
{
	void (*i2s2src)(uint8_t value);
	void (*i2s1src)(uint8_t value);
	void (*timpre)(uint8_t bool);
	void (*sai2src)(uint8_t value);
	void (*sai1src)(uint8_t value);
	void (*pllsaidivq)(uint8_t value);
	void (*plli2sdivq)(uint8_t value);
}STM32FXXXRCC_dckcfgr;

#endif

/*** EOF ***/

/******
1� Sequence
2� Scope
	- Library Scope
	- File Scope
	- Function Scope
	- Precedence Scope
3� Pointer and Variable
4� Casting
******/

