/******************************************************************************
	STM32 XXX GPIO
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 19/06/2023
Update: 28/02/2024
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
STM32FXXXGPIOA_HandleTypeDef* gpioa_enable(void)
{
	/*** GPIOA Bit Mapping Link ***/
	stm32fxxx_gpioa.handle = (STM32FXXXGPIOX_TypeDef*) GPIOA;
	/*** GPIOA RCC Clock Enable ***/
	stm32fxxx_gpioa.clock = STM32FXXXGpioAclock;
	/*** Other ***/
	return &stm32fxxx_gpioa;
}

STM32FXXXGPIOA_HandleTypeDef* gpioa(void){ return &stm32fxxx_gpioa; }

STM32FXXXGPIOB_HandleTypeDef* gpiob_enable(void)
{
	/*** GPIOB Bit Mapping Link ***/
	stm32fxxx_gpiob.handle = (STM32FXXXGPIOX_TypeDef*) GPIOB;
	/*** GPIOB RCC Clock Enable ***/
	stm32fxxx_gpiob.clock = STM32FXXXGpioBclock;
	/*** Other ***/
	return &stm32fxxx_gpiob;
}

STM32FXXXGPIOB_HandleTypeDef* gpiob(void){ return &stm32fxxx_gpiob; }

STM32FXXXGPIOC_HandleTypeDef* gpioc_enable(void)
{
	/*** GPIOC Bit Mapping Link ***/
	stm32fxxx_gpioc.handle = (STM32FXXXGPIOX_TypeDef*) GPIOC;
	/*** GPIOC RCC Clock Enable ***/
	stm32fxxx_gpioc.clock = STM32FXXXGpioCclock;
	/*** Other ***/
	return &stm32fxxx_gpioc;
}

STM32FXXXGPIOC_HandleTypeDef* gpioc(void){ return &stm32fxxx_gpioc; }

STM32FXXXGPIOD_HandleTypeDef* gpiod_enable(void)
{
	/*** GPIOD Bit Mapping Link ***/
	stm32fxxx_gpiod.handle = (STM32FXXXGPIOX_TypeDef*) GPIOD;
	/*** GPIOD RCC Clock Enable ***/
	stm32fxxx_gpiod.clock = STM32FXXXGpioDclock;
	/*** Other ***/
	return &stm32fxxx_gpiod;
}

STM32FXXXGPIOD_HandleTypeDef* gpiod(void){ return &stm32fxxx_gpiod; }

STM32FXXXGPIOE_HandleTypeDef* gpioe_enable(void)
{
	/*** GPIOE Bit Mapping Link ***/
	stm32fxxx_gpioe.handle = (STM32FXXXGPIOX_TypeDef*) GPIOE;
	/*** GPIOE RCC Clock Enable ***/
	stm32fxxx_gpioe.clock = STM32FXXXGpioEclock;
	/*** Other ***/
	return &stm32fxxx_gpioe;
}

STM32FXXXGPIOE_HandleTypeDef* gpioe(void){ return &stm32fxxx_gpioe; }

#ifdef STM32F446xx
STM32FXXXGPIOF_HandleTypeDef* gpiof_enable(void)
{
	/*** GPIOF Bit Mapping Link ***/
	stm32fxxx_gpiof.handle = (STM32FXXXGPIOX_TypeDef*) GPIOF;
	/*** GPIOF RCC Clock Enable ***/
	stm32fxxx_gpiof.clock = STM32FXXXGpioFclock;
	/*** Other ***/
	return &stm32fxxx_gpiof;
}

STM32FXXXGPIOF_HandleTypeDef* gpiof(void){ return &stm32fxxx_gpiof; }

STM32FXXXGPIOG_HandleTypeDef* gpiog_enable(void)
{
	/*** GPIOG Bit Mapping Link ***/
	stm32fxxx_gpiog.handle = (STM32FXXXGPIOX_TypeDef*) GPIOG;
	/*** GPIOG RCC Clock Enable ***/
	stm32fxxx_gpiog.clock = STM32FXXXGpioGclock;
	/*** Other ***/
	return &stm32fxxx_gpiog;
}

STM32FXXXGPIOA_HandleTypeDef* gpiog(void){ return &stm32fxxx_gpiog; }
#endif

STM32FXXXGPIOH_HandleTypeDef* gpioh_enable(void)
{
	/*** GPIOH Bit Mapping Link ***/
	stm32fxxx_gpioh.handle = (STM32FXXXGPIOX_TypeDef*) GPIOH;
	/*** GPIOH RCC Clock Enable ***/
	stm32fxxx_gpioh.clock = STM32FXXXGpioHclock;
	/*** Other ***/
	return &stm32fxxx_gpioh;
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

