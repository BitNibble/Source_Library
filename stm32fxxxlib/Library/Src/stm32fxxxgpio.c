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
static STM32FXXXGpioAobj stm32fxxx_gpioa;
static STM32FXXXGpioBobj stm32fxxx_gpiob;
static STM32FXXXGpioCobj stm32fxxx_gpioc;
static STM32FXXXGpioDobj stm32fxxx_gpiod;
static STM32FXXXGpioEobj stm32fxxx_gpioe;
static STM32FXXXGpioHobj stm32fxxx_gpioh;

/*** GPIO Procedure & Function Definition ***/
/*** GPIOA ***/
void STM32FXXXGpioAclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 0); } else{ RCC->AHB1ENR &= ~(1 << 0); }
}
void STM32FXXXGpioAmoder( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOA->MODER &= ~(mask << (pin * blocksize));
	GPIOA->MODER |= (data << (pin * blocksize));
}
void STM32FXXXGpioAotyper( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOA->OTYPER &= ~(1 << pin);
		GPIOA->OTYPER |= (bool << pin);
	}
}
void STM32FXXXGpioAospeedr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOA->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOA->OSPEEDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioApupdr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOA->PUPDR &= ~(mask << (pin * blocksize));
	GPIOA->PUPDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioAreset( uint16_t data )
{
	GPIOA->BSRR = (unsigned int)(data << 16);
}
void STM32FXXXGpioAset( uint16_t data )
{
	GPIOA->BSRR = (unsigned int)( data );
}
void STM32FXXXGpioAlckr( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOA->LCKR &= ~(1 << pin);
		GPIOA->LCKR |= (bool << pin);
	}
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
void STM32FXXXGpioBmoder( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOB->MODER &= ~(mask << (pin * blocksize));
	GPIOB->MODER |= (data << (pin * blocksize));
}
void STM32FXXXGpioBotyper( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOB->OTYPER &= ~(1 << pin);
		GPIOB->OTYPER |= (bool << pin);
	}
}
void STM32FXXXGpioBospeedr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOB->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOB->OSPEEDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioBpupdr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOB->PUPDR &= ~(mask << (pin * blocksize));
	GPIOB->PUPDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioBreset( uint16_t data )
{
	GPIOB->BSRR = (unsigned int)(data << 16);
}
void STM32FXXXGpioBset( uint16_t data )
{
	GPIOB->BSRR = (unsigned int)( data );
}
void STM32FXXXGpioBlckr( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOB->LCKR &= ~(1 << pin);
		GPIOB->LCKR |= (bool << pin);
	}
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
void STM32FXXXGpioCmoder( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOC->MODER &= ~(mask << (pin * blocksize));
	GPIOC->MODER |= (data << (pin * blocksize));
}
void STM32FXXXGpioCotyper( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOC->OTYPER &= ~(1 << pin);
		GPIOC->OTYPER |= (bool << pin);
	}
}
void STM32FXXXGpioCospeedr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOC->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOC->OSPEEDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioCpupdr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOC->PUPDR &= ~(mask << (pin * blocksize));
	GPIOC->PUPDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioCreset( uint16_t data )
{
	GPIOC->BSRR = (unsigned int)(data << 16);
}
void STM32FXXXGpioCset( uint16_t data )
{
	GPIOC->BSRR = (unsigned int)( data );
}
void STM32FXXXGpioClckr( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOC->LCKR &= ~(1 << pin);
		GPIOC->LCKR |= (bool << pin);
	}
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
void STM32FXXXGpioDmoder( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOD->MODER &= ~(mask << (pin * blocksize));
	GPIOD->MODER |= (data << (pin * blocksize));
}
void STM32FXXXGpioDotyper( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOD->OTYPER &= ~(1 << pin);
		GPIOD->OTYPER |= (bool << pin);
	}
}
void STM32FXXXGpioDospeedr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOD->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOD->OSPEEDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioDpupdr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOD->PUPDR &= ~(mask << (pin * blocksize));
	GPIOD->PUPDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioDreset( uint16_t data )
{
	GPIOD->BSRR = (unsigned int)(data << 16);
}
void STM32FXXXGpioDset( uint16_t data )
{
	GPIOD->BSRR = (unsigned int)( data );
}
void STM32FXXXGpioDlckr( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOD->LCKR &= ~(1 << pin);
		GPIOD->LCKR |= (bool << pin);
	}
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
void STM32FXXXGpioEmoder( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOE->MODER &= ~(mask << (pin * blocksize));
	GPIOE->MODER |= (data << (pin * blocksize));
}
void STM32FXXXGpioEotyper( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOE->OTYPER &= ~(1 << pin);
		GPIOE->OTYPER |= (bool << pin);
	}
}
void STM32FXXXGpioEospeedr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOE->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOE->OSPEEDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioEpupdr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOE->PUPDR &= ~(mask << (pin * blocksize));
	GPIOE->PUPDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioEreset( uint16_t data )
{
	GPIOE->BSRR = (unsigned int)(data << 16);
}
void STM32FXXXGpioEset( uint16_t data )
{
	GPIOE->BSRR = (unsigned int)( data );
}
void STM32FXXXGpioElckr( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOE->LCKR &= ~(1 << pin);
		GPIOE->LCKR |= (bool << pin);
	}
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
void STM32FXXXGpioFmoder( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOF->MODER &= ~(mask << (pin * blocksize));
	GPIOF->MODER |= (data << (pin * blocksize));
}
void STM32FXXXGpioFotyper( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOF->OTYPER &= ~(1 << pin);
		GPIOF->OTYPER |= (bool << pin);
	}
}
void STM32FXXXGpioFospeedr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOF->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOF->OSPEEDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioFpupdr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOF->PUPDR &= ~(mask << (pin * blocksize));
	GPIOF->PUPDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioFreset( uint16_t data )
{
	GPIOF->BSRR = (unsigned int)(data << 16);
}
void STM32FXXXGpioFset( uint16_t data )
{
	GPIOF->BSRR = (unsigned int)( data );
}
void STM32FXXXGpioFlckr( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOF->LCKR &= ~(1 << pin);
		GPIOF->LCKR |= (bool << pin);
	}
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
void STM32FXXXGpioGmoder( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOG->MODER &= ~(mask << (pin * blocksize));
	GPIOG->MODER |= (data << (pin * blocksize));
}
void STM32FXXXGpioGotyper( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOG->OTYPER &= ~(1 << pin);
		GPIOG->OTYPER |= (bool << pin);
	}
}
void STM32FXXXGpioGospeedr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOG->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOG->OSPEEDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioGpupdr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOG->PUPDR &= ~(mask << (pin * blocksize));
	GPIOG->PUPDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioGreset( uint16_t data )
{
	GPIOG->BSRR = (unsigned int)(data << 16);
}
void STM32FXXXGpioGset( uint16_t data )
{
	GPIOG->BSRR = (unsigned int)( data );
}
void STM32FXXXGpioGlckr( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOG->LCKR &= ~(1 << pin);
		GPIOG->LCKR |= (bool << pin);
	}
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
void STM32FXXXGpioHmoder( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOH->MODER &= ~(mask << (pin * blocksize));
	GPIOH->MODER |= (data << (pin * blocksize));
}
void STM32FXXXGpioHotyper( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	GPIOH->OTYPER &= ~(1 << pin);
	GPIOH->OTYPER |= (bool << pin);
}
void STM32FXXXGpioHospeedr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOH->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOH->OSPEEDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioHpupdr( uint8_t pin, uint8_t data )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOH->PUPDR &= ~(mask << (pin * blocksize));
	GPIOH->PUPDR |= (data << (pin * blocksize));
}
void STM32FXXXGpioHreset( uint16_t data )
{
	GPIOH->BSRR = (unsigned int)(data << 16);
}
void STM32FXXXGpioHset( uint16_t data )
{
	GPIOH->BSRR = (unsigned int)( data );
}
void STM32FXXXGpioHlckr( uint8_t pin, uint8_t bool )
{
	bool &= 1;
	if(pin < 16){
		GPIOH->LCKR &= ~(1 << pin);
		GPIOH->LCKR |= (bool << pin);
	}
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
STM32FXXXGpioAobj gpioa_enable(void)
{

	// GPIOA

	/*** GPIOA RCC Clock Enable ***/
	stm32fxxx_gpioa.clock = STM32FXXXGpioAclock;
	/*** GPIOA Bit Mapping Link ***/
	stm32fxxx_gpioa.moder = STM32FXXXGpioAmoder;
	stm32fxxx_gpioa.otyper = STM32FXXXGpioAotyper;
	stm32fxxx_gpioa.ospeedr = STM32FXXXGpioAospeedr;
	stm32fxxx_gpioa.pupdr = STM32FXXXGpioApupdr;
	stm32fxxx_gpioa.reset = STM32FXXXGpioAreset;
	stm32fxxx_gpioa.set = STM32FXXXGpioAset;
	stm32fxxx_gpioa.lckr = STM32FXXXGpioAlckr;
	stm32fxxx_gpioa.afr = STM32FXXXGpioAafr;
	/*** Other ***/
	return stm32fxxx_gpioa;
}

STM32FXXXGpioAobj* gpioa(void){ return &stm32fxxx_gpioa; }

STM32FXXXGpioBobj gpiob_enable(void)
{

	// GPIOB

	/*** GPIOB RCC Clock Enable ***/
	stm32fxxx_gpiob.clock = STM32FXXXGpioBclock;
	/*** GPIOB Bit Mapping Link ***/
	stm32fxxx_gpiob.moder = STM32FXXXGpioBmoder;
	stm32fxxx_gpiob.otyper = STM32FXXXGpioBotyper;
	stm32fxxx_gpiob.ospeedr = STM32FXXXGpioBospeedr;
	stm32fxxx_gpiob.pupdr = STM32FXXXGpioBpupdr;
	stm32fxxx_gpiob.reset = STM32FXXXGpioBreset;
	stm32fxxx_gpiob.set = STM32FXXXGpioBset;
	stm32fxxx_gpiob.lckr = STM32FXXXGpioBlckr;
	stm32fxxx_gpiob.afr = STM32FXXXGpioBafr;
	/*** Other ***/
	return stm32fxxx_gpiob;
}

STM32FXXXGpioBobj* gpiob(void){ return &stm32fxxx_gpiob; }

STM32FXXXGpioCobj gpioc_enable(void)
{

	// GPIOC

	/*** GPIOC RCC Clock Enable ***/
	stm32fxxx_gpioc.clock = STM32FXXXGpioCclock;
	/*** GPIOC Bit Mapping Link ***/
	stm32fxxx_gpioc.moder = STM32FXXXGpioCmoder;
	stm32fxxx_gpioc.otyper = STM32FXXXGpioCotyper;
	stm32fxxx_gpioc.ospeedr = STM32FXXXGpioCospeedr;
	stm32fxxx_gpioc.pupdr = STM32FXXXGpioCpupdr;
	stm32fxxx_gpioc.reset = STM32FXXXGpioCreset;
	stm32fxxx_gpioc.set = STM32FXXXGpioCset;
	stm32fxxx_gpioc.lckr = STM32FXXXGpioClckr;
	stm32fxxx_gpioc.afr = STM32FXXXGpioCafr;
	/*** Other ***/
	return stm32fxxx_gpioc;
}

STM32FXXXGpioCobj* gpioc(void){ return &stm32fxxx_gpioc; }

STM32FXXXGpioDobj gpiod_enable(void)
{

	// GPIOD

	/*** GPIOD RCC Clock Enable ***/
	stm32fxxx_gpiod.clock = STM32FXXXGpioDclock;
	/*** GPIOD Bit Mapping Link ***/
	stm32fxxx_gpiod.moder = STM32FXXXGpioDmoder;
	stm32fxxx_gpiod.otyper = STM32FXXXGpioDotyper;
	stm32fxxx_gpiod.ospeedr = STM32FXXXGpioDospeedr;
	stm32fxxx_gpiod.pupdr = STM32FXXXGpioDpupdr;
	stm32fxxx_gpiod.reset = STM32FXXXGpioDreset;
	stm32fxxx_gpiod.set = STM32FXXXGpioDset;
	stm32fxxx_gpiod.lckr = STM32FXXXGpioDlckr;
	stm32fxxx_gpiod.afr = STM32FXXXGpioDafr;
	/*** Other ***/
	return stm32fxxx_gpiod;
}

STM32FXXXGpioDobj* gpiod(void){ return &stm32fxxx_gpiod; }

STM32FXXXGpioEobj gpioe_enable(void)
{

	// GPIOE

	/*** GPIOE RCC Clock Enable ***/
	stm32fxxx_gpioe.clock = STM32FXXXGpioEclock;
	/*** GPIOE Bit Mapping Link ***/
	stm32fxxx_gpioe.moder = STM32FXXXGpioEmoder;
	stm32fxxx_gpioe.otyper = STM32FXXXGpioEotyper;
	stm32fxxx_gpioe.ospeedr = STM32FXXXGpioEospeedr;
	stm32fxxx_gpioe.pupdr = STM32FXXXGpioEpupdr;
	stm32fxxx_gpioe.reset = STM32FXXXGpioEreset;
	stm32fxxx_gpioe.set = STM32FXXXGpioEset;
	stm32fxxx_gpioe.lckr = STM32FXXXGpioElckr;
	stm32fxxx_gpioe.afr = STM32FXXXGpioEafr;
	/*** Other ***/
	return stm32fxxx_gpioe;
}

STM32FXXXGpioEobj* gpioe(void){ return &stm32fxxx_gpioe; }

STM32FXXXGpioHobj gpioh_enable(void)
{

	// GPIOH

	/*** GPIOH RCC Clock Enable ***/
	stm32fxxx_gpioh.clock = STM32FXXXGpioHclock;
	/*** GPIOH Bit Mapping Link ***/
	stm32fxxx_gpioh.moder = STM32FXXXGpioHmoder;
	stm32fxxx_gpioh.otyper = STM32FXXXGpioHotyper;
	stm32fxxx_gpioh.ospeedr = STM32FXXXGpioHospeedr;
	stm32fxxx_gpioh.pupdr = STM32FXXXGpioHpupdr;
	stm32fxxx_gpioh.reset = STM32FXXXGpioHreset;
	stm32fxxx_gpioh.set = STM32FXXXGpioHset;
	stm32fxxx_gpioh.lckr = STM32FXXXGpioHlckr;
	stm32fxxx_gpioh.afr = STM32FXXXGpioHafr;
	/*** Other ***/
	return stm32fxxx_gpioh;
}

STM32FXXXGpioHobj* gpioh(void){ return &stm32fxxx_gpioh; }


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

