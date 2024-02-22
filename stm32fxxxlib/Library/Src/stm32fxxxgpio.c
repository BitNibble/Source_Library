/******************************************************************************
	STM32 xxx GPIO
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-xxx
Date: 19/06/2023
Update: 05/01/2024
Comment:
	File Vars, File Function Header, Library Function Definitions.
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxgpio.h"
#include <math.h>

/*** File Variables ***/
static STM32FXXXGPIOA_HandleTypeDef stm32fxxx_gpioa;
static STM32FXXXGPIOB_HandleTypeDef stm32fxxx_gpiob;
static STM32FXXXGPIOC_HandleTypeDef stm32fxxx_gpioc;
static STM32FXXXGPIOD_HandleTypeDef stm32fxxx_gpiod;
static STM32FXXXGPIOE_HandleTypeDef stm32fxxx_gpioe;
#ifdef STM32F446xx
	static STM32FXXXGPIOF_HandleTypeDef stm32fxxx_gpiof;
	static STM32FXXXGPIOG_HandleTypeDef stm32fxxx_gpiog;
#endif
static STM32FXXXGPIOH_HandleTypeDef stm32fxxx_gpioh;

/*** GPIO Procedure & Function Definition ***/
/*** GPIOA ***/
void STM32FXXXGpioAclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 0); } else{ RCC->AHB1ENR &= ~(1 << 0); }
}
void STM32FXXXGpioAafr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 4;
	const uint8_t n_bits = sizeof(unsigned int) * 8;
	const uint8_t mask = (pow(2, blocksize) - 1);
	unsigned int index = (pin * blocksize) / n_bits;
	data &= mask;
	if(index < 2){
		GPIOA->AFR[index] &= ~( mask << ((pin * blocksize) - (index * n_bits)) );
		GPIOA->AFR[index] |= ( data << ((pin * blocksize) - (index * n_bits)) );
	}
}
/*** GPIOB ***/
void STM32FXXXGpioBclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 1); } else{ RCC->AHB1ENR &= ~(1 << 1); }
}
void STM32FXXXGpioBafr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 4;
	const uint8_t n_bits = sizeof(unsigned int) * 8;
	const uint8_t mask = (pow(2, blocksize) - 1);
	unsigned int index = (pin * blocksize) / n_bits;
	data &= mask;
	if(index < 2){
		GPIOB->AFR[index] &= ~( mask << ((pin * blocksize) - (index * n_bits)) );
		GPIOB->AFR[index] |= ( data << ((pin * blocksize) - (index * n_bits)) );
	}
}
/*** GPIOC ***/
void STM32FXXXGpioCclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 2); } else{ RCC->AHB1ENR &= ~(1 << 2); }
}
void STM32FXXXGpioCafr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 4;
	const uint8_t n_bits = sizeof(unsigned int) * 8;
	const uint8_t mask = (pow(2, blocksize) - 1);
	unsigned int index = (pin * blocksize) / n_bits;
	data &= mask;
	if(index < 2){
		GPIOC->AFR[index] &= ~( mask << ((pin * blocksize) - (index * n_bits)) );
		GPIOC->AFR[index] |= ( data << ((pin * blocksize) - (index * n_bits)) );
	}
}
/*** GPIOD ***/
void STM32FXXXGpioDclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 3); } else{ RCC->AHB1ENR &= ~(1 << 3); }
}
void STM32FXXXGpioDafr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 4;
	const uint8_t n_bits = sizeof(unsigned int) * 8;
	const uint8_t mask = (pow(2, blocksize) - 1);
	unsigned int index = (pin * blocksize) / n_bits;
	data &= mask;
	if(index < 2){
		GPIOD->AFR[index] &= ~( mask << ((pin * blocksize) - (index * n_bits)) );
		GPIOD->AFR[index] |= ( data << ((pin * blocksize) - (index * n_bits)) );
	}
}
/*** GPIOE ***/
void STM32FXXXGpioEclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 4); } else{ RCC->AHB1ENR &= ~(1 << 4); }
}
void STM32FXXXGpioEafr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 4;
	const uint8_t n_bits = sizeof(unsigned int) * 8;
	const uint8_t mask = (pow(2, blocksize) - 1);
	unsigned int index = (pin * blocksize) / n_bits;
	data &= mask;
	if(index < 2){
		GPIOE->AFR[index] &= ~( mask << ((pin * blocksize) - (index * n_bits)) );
		GPIOE->AFR[index] |= ( data << ((pin * blocksize) - (index * n_bits)) );
	}
}
#ifdef STM32F446xx
/*** GPIOF ***/
void STM32FXXXGpioFclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 5); } else{ RCC->AHB1ENR &= ~(1 << 5); }
}
void STM32FXXXGpioFafr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 4;
	const uint8_t n_bits = sizeof(unsigned int) * 8;
	const uint8_t mask = (pow(2, blocksize) - 1);
	unsigned int index = (pin * blocksize) / n_bits;
	data &= mask;
	if(index < 2){
		GPIOF->AFR[index] &= ~( mask << ((pin * blocksize) - (index * n_bits)) );
		GPIOF->AFR[index] |= ( data << ((pin * blocksize) - (index * n_bits)) );
	}
}
/*** GPIOG ***/
void STM32FXXXGpioGclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 6); } else{ RCC->AHB1ENR &= ~(1 << 6); }
}
void STM32FXXXGpioGafr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 4;
	const uint8_t n_bits = sizeof(unsigned int) * 8;
	const uint8_t mask = (pow(2, blocksize) - 1);
	unsigned int index = (pin * blocksize) / n_bits;
	data &= mask;
	if(index < 2){
		GPIOG->AFR[index] &= ~( mask << ((pin * blocksize) - (index * n_bits)) );
		GPIOG->AFR[index] |= ( data << ((pin * blocksize) - (index * n_bits)) );
	}
}
#endif
/*** GPIOH ***/
void STM32FXXXGpioHclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 7); } else{ RCC->AHB1ENR &= ~(1 << 7); }
}
void STM32FXXXGpioHafr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 4;
	const unsigned int n_bits = sizeof(unsigned int) * 8;
	uint8_t mask = (pow(2, blocksize) - 1);
	unsigned int index = (pin * blocksize) / n_bits;
	data &= mask;
	if(index < 2){
		GPIOH->AFR[index] &= ~( mask << ((pin * blocksize) - (index * n_bits)) );
		GPIOH->AFR[index] |= ( data << ((pin * blocksize) - (index * n_bits)) );
	}
}
/*** INIC Procedure & Function Definition ***/
STM32FXXXGPIOA_HandleTypeDef gpioa_enable(void)
{

	// GPIOA

	/*** GPIOA RCC Clock Enable ***/
	stm32fxxx_gpioa.clock = STM32FXXXGpioAclock;
	/*** GPIOA Bit Mapping Link ***/
	stm32fxxx_gpioa.moder = (GPIO_MODER_TypeDef*) &GPIOA->MODER;
	stm32fxxx_gpioa.otyper = (GPIO_OTYPER_TypeDef*) &GPIOA->OTYPER;
	stm32fxxx_gpioa.ospeedr = (GPIO_OSPEEDR_TypeDef*) &GPIOA->OSPEEDR;
	stm32fxxx_gpioa.pupdr = (GPIO_PUPDR_TypeDef*) &GPIOA->PUPDR;
	stm32fxxx_gpioa.bsrr = (GPIO_BSRR_TypeDef*) &GPIOA->BSRR;
	stm32fxxx_gpioa.lckr = (GPIO_LCKR_TypeDef*) &GPIOA->LCKR;
	stm32fxxx_gpioa.afr = STM32FXXXGpioAafr;
	/*** Other ***/
	return stm32fxxx_gpioa;
}

STM32FXXXGPIOA_HandleTypeDef* gpioa(void){ return &stm32fxxx_gpioa; }

STM32FXXXGPIOB_HandleTypeDef gpiob_enable(void)
{

	// GPIOB

	/*** GPIOB RCC Clock Enable ***/
	stm32fxxx_gpiob.clock = STM32FXXXGpioBclock;
	/*** GPIOB Bit Mapping Link ***/
	stm32fxxx_gpiob.moder = (GPIO_MODER_TypeDef*) &GPIOB->MODER;
	stm32fxxx_gpiob.otyper = (GPIO_OTYPER_TypeDef*) &GPIOB->OTYPER;
	stm32fxxx_gpiob.ospeedr = (GPIO_OSPEEDR_TypeDef*) &GPIOB->OSPEEDR;
	stm32fxxx_gpiob.pupdr = (GPIO_PUPDR_TypeDef*) &GPIOB->PUPDR;
	stm32fxxx_gpiob.bsrr = (GPIO_BSRR_TypeDef*) &GPIOB->BSRR;
	stm32fxxx_gpiob.lckr = (GPIO_LCKR_TypeDef*) &GPIOB->LCKR;
	stm32fxxx_gpiob.afr = STM32FXXXGpioBafr;
	/*** Other ***/
	return stm32fxxx_gpiob;
}

STM32FXXXGPIOB_HandleTypeDef* gpiob(void){ return &stm32fxxx_gpiob; }

STM32FXXXGPIOC_HandleTypeDef gpioc_enable(void)
{

	// GPIOC

	/*** GPIOC RCC Clock Enable ***/
	stm32fxxx_gpioc.clock = STM32FXXXGpioCclock;
	/*** GPIOC Bit Mapping Link ***/
	stm32fxxx_gpioc.moder = (GPIO_MODER_TypeDef*) &GPIOC->MODER;
	stm32fxxx_gpioc.otyper = (GPIO_OTYPER_TypeDef*) &GPIOC->OTYPER;
	stm32fxxx_gpioc.ospeedr = (GPIO_OSPEEDR_TypeDef*) &GPIOC->OSPEEDR;
	stm32fxxx_gpioc.pupdr = (GPIO_PUPDR_TypeDef*) &GPIOC->PUPDR;
	stm32fxxx_gpioc.bsrr = (GPIO_BSRR_TypeDef*) &GPIOC->BSRR;
	stm32fxxx_gpioc.lckr = (GPIO_LCKR_TypeDef*) &GPIOC->LCKR;
	stm32fxxx_gpioc.afr = STM32FXXXGpioCafr;
	/*** Other ***/
	return stm32fxxx_gpioc;
}

STM32FXXXGPIOC_HandleTypeDef* gpioc(void){ return &stm32fxxx_gpioc; }

STM32FXXXGPIOD_HandleTypeDef gpiod_enable(void)
{

	// GPIOD

	/*** GPIOD RCC Clock Enable ***/
	stm32fxxx_gpiod.clock = STM32FXXXGpioDclock;
	/*** GPIOD Bit Mapping Link ***/
	stm32fxxx_gpiod.moder = (GPIO_MODER_TypeDef*) &GPIOD->MODER;
	stm32fxxx_gpiod.otyper = (GPIO_OTYPER_TypeDef*) &GPIOD->OTYPER;
	stm32fxxx_gpiod.ospeedr = (GPIO_OSPEEDR_TypeDef*) &GPIOD->OSPEEDR;
	stm32fxxx_gpiod.pupdr = (GPIO_PUPDR_TypeDef*) &GPIOD->PUPDR;
	stm32fxxx_gpiod.bsrr = (GPIO_BSRR_TypeDef*) &GPIOD->BSRR;
	stm32fxxx_gpiod.lckr = (GPIO_LCKR_TypeDef*) &GPIOD->LCKR;
	stm32fxxx_gpiod.afr = STM32FXXXGpioDafr;
	/*** Other ***/
	return stm32fxxx_gpiod;
}

STM32FXXXGPIOD_HandleTypeDef* gpiod(void){ return &stm32fxxx_gpiod; }

STM32FXXXGPIOE_HandleTypeDef gpioe_enable(void)
{

	// GPIOE

	/*** GPIOE RCC Clock Enable ***/
	stm32fxxx_gpioe.clock = STM32FXXXGpioEclock;
	/*** GPIOE Bit Mapping Link ***/
	stm32fxxx_gpioe.moder = (GPIO_MODER_TypeDef*) &GPIOE->MODER;
	stm32fxxx_gpioe.otyper = (GPIO_OTYPER_TypeDef*) &GPIOE->OTYPER;
	stm32fxxx_gpioe.ospeedr = (GPIO_OSPEEDR_TypeDef*) &GPIOE->OSPEEDR;
	stm32fxxx_gpioe.pupdr = (GPIO_PUPDR_TypeDef*) &GPIOE->PUPDR;
	stm32fxxx_gpioe.bsrr = (GPIO_BSRR_TypeDef*) &GPIOE->BSRR;
	stm32fxxx_gpioe.lckr = (GPIO_LCKR_TypeDef*) &GPIOE->LCKR;
	stm32fxxx_gpioe.afr = STM32FXXXGpioEafr;
	/*** Other ***/
	return stm32fxxx_gpioe;
}

STM32FXXXGPIOE_HandleTypeDef* gpioe(void){ return &stm32fxxx_gpioe; }

#ifdef STM32F446xx
STM32FXXXGPIOF_HandleTypeDef gpiof_enable(void)
{

	// GPIOF

	/*** GPIOF RCC Clock Enable ***/
	stm32fxxx_gpiof.clock = STM32FXXXGpioFclock;
	/*** GPIOF Bit Mapping Link ***/
	stm32fxxx_gpiof.moder = (GPIO_MODER_TypeDef*) &GPIOF->MODER;
	stm32fxxx_gpiof.otyper = (GPIO_OTYPER_TypeDef*) &GPIOF->OTYPER;
	stm32fxxx_gpiof.ospeedr = (GPIO_OSPEEDR_TypeDef*) &GPIOF->OSPEEDR;
	stm32fxxx_gpiof.pupdr = (GPIO_PUPDR_TypeDef*) &GPIOF->PUPDR;
	stm32fxxx_gpiof.bsrr = (GPIO_BSRR_TypeDef*) &GPIOF->BSRR;
	stm32fxxx_gpiof.lckr = (GPIO_LCKR_TypeDef*) &GPIOF->LCKR;
	stm32fxxx_gpiof.afr = STM32FXXXGpioFafr;
	/*** Other ***/
	return stm32fxxx_gpiof;
}

STM32FXXXGPIOF_HandleTypeDef* gpiof(void){ return &stm32fxxx_gpiof; }

STM32FXXXGPIOG_HandleTypeDef gpiog_enable(void)
{

	// GPIOG

	/*** GPIOG RCC Clock Enable ***/
	stm32fxxx_gpiog.clock = STM32FXXXGpioGclock;
	/*** GPIOG Bit Mapping Link ***/
	stm32fxxx_gpiog.moder = (GPIO_MODER_TypeDef*) &GPIOG->MODER;
	stm32fxxx_gpiog.otyper = (GPIO_OTYPER_TypeDef*) &GPIOG->OTYPER;
	stm32fxxx_gpiog.ospeedr = (GPIO_OSPEEDR_TypeDef*) &GPIOG->OSPEEDR;
	stm32fxxx_gpiog.pupdr = (GPIO_PUPDR_TypeDef*) &GPIOG->PUPDR;
	stm32fxxx_gpiog.bsrr = (GPIO_BSRR_TypeDef*) &GPIOG->BSRR;
	stm32fxxx_gpiog.lckr = (GPIO_LCKR_TypeDef*) &GPIOG->LCKR;
	stm32fxxx_gpiog.afr = STM32FXXXGpioGafr;
	/*** Other ***/
	return stm32fxxx_gpiog;
}

STM32FXXXGPIOA_HandleTypeDef* gpiog(void){ return &stm32fxxx_gpiog; }
#endif

STM32FXXXGPIOH_HandleTypeDef gpioh_enable(void)
{

	// GPIOH

	/*** GPIOH RCC Clock Enable ***/
	stm32fxxx_gpioh.clock = STM32FXXXGpioHclock;
	/*** GPIOH Bit Mapping Link ***/
	stm32fxxx_gpioh.moder = (GPIO_MODER_TypeDef*) &GPIOH->MODER;
	stm32fxxx_gpioh.otyper = (GPIO_OTYPER_TypeDef*) &GPIOH->OTYPER;
	stm32fxxx_gpioh.ospeedr = (GPIO_OSPEEDR_TypeDef*) &GPIOH->OSPEEDR;
	stm32fxxx_gpioh.pupdr = (GPIO_PUPDR_TypeDef*) &GPIOH->PUPDR;
	stm32fxxx_gpioh.bsrr = (GPIO_BSRR_TypeDef*) &GPIOH->BSRR;
	stm32fxxx_gpioh.lckr = (GPIO_LCKR_TypeDef*) &GPIOH->LCKR;
	stm32fxxx_gpioh.afr = STM32FXXXGpioHafr;
	/*** Other ***/
	return stm32fxxx_gpioh;
}

STM32FXXXGPIOH_HandleTypeDef* gpioh(void){ return &stm32fxxx_gpioh; }


/**** EOF ****/

/*
 * More Interested in finding the best work flow, then coding itself. Because that will become redundant after
 * achieving the objective.
 *
 * **/

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

