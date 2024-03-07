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
	struct RCC_CR_1{
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
	struct RCC_PLLCFGR_1{
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
/*
volatile typedef union{
	struct RCC_CFGR_1{
		uint32_t sw:2;
		uint32_t sws:2;
		uint32_t hpre:4;
		uint32_t reserved1:2;
		uint32_t ppre1:3;
		uint32_t ppre2:3;
		uint32_t rtcpre:5;
		uint32_t mco1:2;
		uint32_t reserved2:1;
		uint32_t mco1pre:3;
		uint32_t mco2pre:3;
		uint32_t mco2:2;
	}par;
	uint32_t reg;
}STM32FXXXRCC_CFGR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_CIR_1{
		uint32_t lsirdyf:1;
		uint32_t lserdyf:1;
		uint32_t hsirdyf:1;
		uint32_t hserdyf:1;
		uint32_t pllrdyf:1;
		uint32_t plli2srdyf:1;
		uint32_t pllsairdyf:1;
		uint32_t cssf:1;
		uint32_t lsirdyie:1;
		uint32_t lserdyie:1;
		uint32_t hsirdyie:1;
		uint32_t hserdyie:1;
		uint32_t pllrdyie:1;
		uint32_t plli2srdyie:1;
		uint32_t pllsairdyie:1;
		uint32_t reserved1:1;
		uint32_t lsirdyc:1;
		uint32_t lserdyc:1;
		uint32_t hsirdyc:1;
		uint32_t hserdyc:1;
		uint32_t pllrdyc:1;
		uint32_t plli2srdyc:1;
		uint32_t pllsairdyc:1;
		uint32_t cssc:1;
		uint32_t reserved2:8;
	}par;
	uint32_t reg;
}STM32FXXXRCC_CIR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_AHB1RSTR_1{
		uint32_t gpioarst:1;
		uint32_t gpiobrst:1;
		uint32_t gpiocrst:1;
		uint32_t gpiodrst:1;
		uint32_t gpioerst:1;
		uint32_t gpiofrst:1;
		uint32_t gpiogrst:1;
		uint32_t gpiohrst:1;
		uint32_t reserved1:4;
		uint32_t crcrst:1;
		uint32_t reserved2:8;
		uint32_t dma1rst:1;
		uint32_t dma2rst:1;
		uint32_t reserved3:6;
		uint32_t otghsrst:1;
		uint32_t reserved4:2;
	}par;
	uint32_t reg;
}STM32FXXXRCC_AHB1RSTR_TypeDef;
*/
// AHB2RSTR
typedef struct
{
	void (*otgfsrst)(uint8_t bool);
	void (*dcmirst)(uint8_t bool);
}STM32FXXXRCC_ahb2rstr;
/*
volatile typedef union{
	struct RCC_AHB2RSTR_1{
		uint32_t dcmirst:1;
		uint32_t reserved1:6;
		uint32_t otgfsrs:1;
		uint32_t reserved2:24;
	}par;
	uint32_t reg;
}STM32FXXXRCC_AHB2RSTR_TypeDef;
*/
// AHB3RSTR
typedef struct
{
	void (*qspirst)(uint8_t bool);
	void (*fmcrst)(uint8_t bool);
}STM32FXXXRCC_ahb3rstr;
/*
volatile typedef union{
	struct RCC_AHB3RSTR_1{
		uint32_t fmcrst:1;
		uint32_t qspirst:1;
		uint32_t reserved2:30;
	}par;
	uint32_t reg;
}STM32FXXXRCC_AHB3RSTR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_APB1RSTR_1{
		uint32_t tim2rst:1;
		uint32_t tim3rst:1;
		uint32_t tim4rst:1;
		uint32_t tim5rst:1;
		uint32_t tim6rst:1;
		uint32_t tim7rst:1;
		uint32_t tim12rst:1;
		uint32_t tim13rst:1;
		uint32_t tim14rst:1;
		uint32_t reserved1:2;
		uint32_t wwdgrst:1;
		uint32_t reserved2:2;
		uint32_t spi2rst:1;
		uint32_t spi3rst:1;
		uint32_t spdifrxrst:1;
		uint32_t uart2rst:1;
		uint32_t uart3rst:1;
		uint32_t uart4rst:1;
		uint32_t uart5rst:1;
		uint32_t i2c1rst:1;
		uint32_t i2c2rst:1;
		uint32_t i2c3rst:1;
		uint32_t fmpi2c1rst:1;
		uint32_t can1rst:1;
		uint32_t can2rst:1;
		uint32_t cecrst:1;
		uint32_t pwrrst:1;
		uint32_t dacrst:1;
		uint32_t reserved3:2;
	}par;
	uint32_t reg;
}STM32FXXXRCC_APB1RSTR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_APB2RSTR_1{
		uint32_t tim1rst:1;
		uint32_t tim8rst:1;
		uint32_t reserved1:2;
		uint32_t usart1rst:1;
		uint32_t usart6rst:1;
		uint32_t reserved2:2;
		uint32_t adcrst:1;
		uint32_t reserved3:2;
		uint32_t sdiorst:1;
		uint32_t spi1rst:1;
		uint32_t sp45rst:1;
		uint32_t syscfgrst:1;
		uint32_t reserved4:1;
		uint32_t tim9rst:1;
		uint32_t tim10rst:1;
		uint32_t tim11rst:1;
		uint32_t reserved5:3;
		uint32_t sai1rst:1;
		uint32_t sai2rst:1;
		uint32_t reserved6:8;
	}par;
	uint32_t reg;
}STM32FXXXRCC_APB2RSTR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_AHB1ENR_1{
		uint32_t gpioaen:1;
		uint32_t gpioben:1;
		uint32_t gpiocen:1;
		uint32_t gpioden:1;
		uint32_t gpioeen:1;
		uint32_t gpiofen:1;
		uint32_t gpiogen:1;
		uint32_t gpiohen:1;
		uint32_t reserved1:4;
		uint32_t crcen:1;
		uint32_t reserved2:5;
		uint32_t bkpsramen:1;
		uint32_t reserved3:2;
		uint32_t dma1en:1;
		uint32_t dma2en:1;
		uint32_t reserved4:6;
		uint32_t otghsen:1;
		uint32_t otghsulpien:1;
		uint32_t reserved5:1;
	}par;
	uint32_t reg;
}STM32FXXXRCC_AHB1ENR_TypeDef;
*/
// AHB2ENR
typedef struct
{
	void (*otgfsen)(uint8_t bool);
	void (*dcmien)(uint8_t bool);
}STM32FXXXRCC_ahb2enr;
/*
volatile typedef union{
	struct RCC_AHB2ENR_1{
		uint32_t dcmien:1;
		uint32_t reserved1:6;
		uint32_t otgfsen:1;
		uint32_t reserved1:24;
	}par;
	uint32_t reg;
}STM32FXXXRCC_AHB2ENR_TypeDef;
*/
/*
volatile typedef union{
	struct RCC_AHB3ENR_1{
		uint32_t fmcen:1;
		uint32_t qspien:1;
		uint32_t reserved1:30;
	}par;
	uint32_t reg;
}STM32FXXXRCC_AHB3ENR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_APB1ENR_1{
		uint32_t tim2en:1;
		uint32_t tim3en:1;
		uint32_t tim4en:1;
		uint32_t tim5en:1;
		uint32_t tim6en:1;
		uint32_t tim7en:1;
		uint32_t tim12en:1;
		uint32_t tim13en:1;
		uint32_t tim14en:1;
		uint32_t reserved1:2;
		uint32_t wwdgen:1;
		uint32_t reserved2:2;
		uint32_t spi2en:1;
		uint32_t spi3en:1;
		uint32_t spdifrxen:1;
		uint32_t usart2en:1;
		uint32_t usart3en:1;
		uint32_t uart4en:1;
		uint32_t uart5en:1;
		uint32_t i2c1en:1;
		uint32_t i2c2en:1;
		uint32_t i2c3en:1;
		uint32_t fmpi2c1en:1;
		uint32_t can1en:1;
		uint32_t can2en:1;
		uint32_t cecen:1;
		uint32_t pwren:1;
		uint32_t dacen:1;
		uint32_t reserved3:2;
	}par;
	uint32_t reg;
}STM32FXXXRCC_APB1ENR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_APB2ENR_1{
		uint32_t tim1en:1;
		uint32_t tim8en:1;
		uint32_t reserved1:2;
		uint32_t usart1en:1;
		uint32_t usart6en:1;
		uint32_t reserved2:2;
		uint32_t adc1en:1;
		uint32_t adc2en:1;
		uint32_t adc3en:1;
		uint32_t sdioen:1;
		uint32_t spi1en:1;
		uint32_t spi4en:1;
		uint32_t syscfgen:1;
		uint32_t reserved3:1;
		uint32_t tim9en:1;
		uint32_t tim10en:1;
		uint32_t tim11en:1;
		uint32_t reserved4:3;
		uint32_t sai1en:1;
		uint32_t sai2en:1;
		uint32_t reserved5:8;
	}par;
	uint32_t reg;
}STM32FXXXRCC_APB2ENR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_AHB1LPENR_1{
		uint32_t gpioalpen:1;
		uint32_t gpioblpen:1;
		uint32_t gpioclpen:1;
		uint32_t gpiodlpen:1;
		uint32_t gpioelpen:1;
		uint32_t gpioflpen:1;
		uint32_t gpioglpen:1;
		uint32_t gpiohlpen:1;
		uint32_t reserved1:4;
		uint32_t crclpen:1;
		uint32_t reserved2:2;
		uint32_t flitflpen:1;
		uint32_t sram1lpen:1;
		uint32_t sram2lpen:1;
		uint32_t bkpsramlpen:1;
		uint32_t reserved3:2;
		uint32_t dma1lpen:1;
		uint32_t dma2lpen:1;
		uint32_t reserved4:6;
		uint32_t otghslpen:1;
		uint32_t otghsulpilpen:1;
		uint32_t reserved5:1;
	}par;
	uint32_t reg;
}STM32FXXXRCC_AHB1LPENR_TypeDef;
*/
// AHB2LPENR
typedef struct
{
	void (*otgfslpen)(uint8_t bool);
	void (*dcmilpen)(uint8_t bool);
}STM32FXXXRCC_ahb2lpenr;
/*
volatile typedef union{
	struct RCC_AHB2LPENR_1{
		uint32_t dcmilpen:1;
		uint32_t reserved1:6;
		uint32_t otgfslpen;1;
		uint32_t reserved2:24;
	}par;
	uint32_t reg;
}STM32FXXXRCC_AHB2LPENR_TypeDef;
*/
// AHB3LPENR
typedef struct
{
	void (*qspilpen)(uint8_t bool);
	void (*fmclpen)(uint8_t bool);
}STM32FXXXRCC_ahb3lpenr;
/*
volatile typedef union{
	struct RCC_AHB3LPENR_1{
		uint32_t fmclpen:1;
		uint32_t qspilpen:1;
		uint32_t reserved1:30;
	}par;
	uint32_t reg;
}STM32FXXXRCC_AHB3LPENR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_APB1LPENR_1{
		uint32_t tim2lpen:1;
		uint32_t tim3lpen:1;
		uint32_t tim4lpen:1;
		uint32_t tim5lpen:1;
		uint32_t tim6lpen:1;
		uint32_t tim7lpen:1;
		uint32_t tim12lpen:1;
		uint32_t tim13lpen:1;
		uint32_t tim14lpen:1;
		uint32_t reserved1:2;
		uint32_t wwdglpen:1;
		uint32_t reserved2:2;
		uint32_t spi2lpen:1;
		uint32_t spi3lpen:1;
		uint32_t spdifrxlpen:1;
		uint32_t usart2lpen:1;
		uint32_t usart3lpen:1;
		uint32_t uart4lpen:1;
		uint32_t uart5lpen:1;
		uint32_t i2c1lpen:1;
		uint32_t i2c2lpen:1;
		uint32_t i2c3lpen:1;
		uint32_t fmpi2c1lpen:1;
		uint32_t can1lpen:1;
		uint32_t can2lpen:1;
		uint32_t ceclpen:1;
		uint32_t pwrlpen:1;
		uint32_t daclpen:1;
		uint32_t reserved3:2;
	}par;
	uint32_t reg;
}STM32FXXXRCC_APB1LPENR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_APB2LPENR_1{
		uint32_t tim1lpen:1;
		uint32_t tim8lpen:1;
		uint32_t reserved1:2;
		uint32_t usart1lpen:1;
		uint32_t usart6lpen:1;
		uint32_t reserved2:2;
		uint32_t adc1lpen:1;
		uint32_t adc2lpen:1;
		uint32_t adc3lpen:1;
		uint32_t sdiolpen:1;
		uint32_t spi1lpen:1;
		uint32_t spi4lpen:1;
		uint32_t syscfglpen:1;
		uint32_t reserved3:1;
		uint32_t tim9lpen:1;
		uint32_t tim10lpen:1;
		uint32_t tim11lpen:1;
		uint32_t reserved4:3;
		uint32_t sai1lpen:1;
		uint32_t sai2lpen:1;
		uint32_t reserved5:8;
	}par;
	uint32_t reg;
}STM32FXXXRCC_APB2LPENR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_BDCR_1{
		uint32_t lseon:1;
		uint32_t lserdy:1;
		uint32_t lsebyp:1;
		uint32_t lsemod:1;
		uint32_t reserved1:4;
		uint32_t rtcsel:2;
		uint32_t reserved2:5;
		uint32_t rtcen:1;
		uint32_t bdrst:1;
		uint32_t reserved3:15;
	}par;
	uint32_t reg;
}STM32FXXXRCC_BDCR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_CSR_1{
		uint32_t lsion:1;
		uint32_t lsirdy:1;
		uint32_t reserved1:22;
		uint32_t rmvf:1;
		uint32_t borrstf:1;
		uint32_t padrstf:1;
		uint32_t porrstf:1;
		uint32_t sftrstf:1;
		uint32_t wdgrstf:1;
		uint32_t wwgrstf:1;
		uint32_t lpwrrstf:1;
	}par;
	uint32_t reg;
}STM32FXXXRCC_CSR_TypeDef;
*/
// SSCGR
typedef struct
{
	void (*sscgen)(uint8_t bool);
	void (*spreadsel)(uint8_t bool);
	void (*incstep)(uint8_t value);
	void (*modper)(uint8_t value);
}STM32FXXXRCC_sscgr;
/*
volatile typedef union{
	struct RCC_SSCGR_1{
		uint32_t modper:13;
		uint32_t incstep:15;
		uint32_t reserved1:2;
		uint32_t spreadsel:1;
		uint32_t sscgen:1;
	}par;
	uint32_t reg;
}STM32FXXXRCC_SSCGR_TypeDef;
*/
// PLLI2SCFGR
typedef struct
{
	void (*plli2sr)(uint8_t value);
	void (*plli2sq)(uint8_t value);
	void (*plli2sp)(uint8_t value);
	void (*plli2sn)(uint16_t value);
	void (*plli2sm)(uint8_t value);
}STM32FXXXRCC_plli2scfgr;
/*
volatile typedef union{
	struct RCC_PLLI2SCFGR_1{
		uint32_t plli2sm:6;
		uint32_t plli2sn:9;
		uint32_t reserved1:1;
		uint32_t plli2sp:2;
		uint32_t reserved2:6;
		uint32_t plli2sq:4;
		uint32_t plli2sr:3;
		uint32_t reserved3:1;
	}par;
	uint32_t reg;
}STM32FXXXRCC_PLLI2SCFGR_TypeDef;
*/
/*
volatile typedef union{
	struct RCC_PLLSAICFGR_1{
		uint32_t pllsaim:6;
		uint32_t pllsain:9;
		uint32_t reserved1:1;
		uint32_t pllsaip:2;
		uint32_t reserved2:6;
		uint32_t pllsaiq:4;
		uint32_t pllsair:3;
		uint32_t reserved3:1;
	}par;
	uint32_t reg;
}STM32FXXXRCC_PLLSAICFGR_TypeDef;
*/
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
/*
volatile typedef union{
	struct RCC_DCKCFGR_1{
		uint32_t plli2sdivq:5;
		uint32_t reserved1:3;
		uint32_t pllsaidivq:5;
		uint32_t reserved2:7;
		uint32_tcr:2;
		uint32_t sai2scr:2;
		uint32_t timpre:1;
		uint32_t i2s1src:2;
		uint32_t i2s2src:2;
		uint32_t reserved3:3;
	}par;
	uint32_t reg;
}STM32FXXXRCC_DCKCFGR_TypeDef;
*/
/*
volatile typedef union{
	struct RCC_CKGATENR_1{
		uint32_t ahb2apb1_cken:1;
		uint32_t ahb2apb2_cken:1;
		uint32_t cm4dbg_cken:1;
		uint32_t spare_cken:1;
		uint32_t sram_cken:1;
		uint32_t flitf_cken:1;
		uint32_t rcc_cken:1;
		uint32_t reserved1:25;
	}par;
	uint32_t reg;
}STM32FXXXRCC_CKGATENR_TypeDef;
*/
/*
volatile typedef union{
	struct RCC_DCKCFGR2_1{
		uint32_t reserved1:22;
		uint32_t fmpi2c1sel:2;
		uint32_t reserved2:2;
		uint32_t cecsel:1;
		uint32_t ck48msel:1;
		uint32_t sdiosel:1;
		uint32_t spdifrxsel:1;
		uint32_t reserved3:2;
	}par;
	uint32_t reg;
}STM32FXXXRCC_DCKCFGR2_TypeDef;
*/

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

