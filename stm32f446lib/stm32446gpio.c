/******************************************************************************
	STM32 446 GPIO
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 19/06/2023
Update: 05/01/2024
Comment:
	File Vars, File Function Header, Library Function Definitions.
	
*******************************************************************************/
/*** File Library ***/
#include "stm32446mapping.h"
#include "stm32446gpio.h"
#include "math.h"
/*** File Procedure & Function Header ***/
IO_var gpio_readreg(IO_var reg, uint8_t size_block, uint8_t bit);
void gpio_writereg(volatile IO_var* reg, uint8_t size_block, uint8_t bit, IO_var data);
void gpio_setreg(volatile IO_var* reg, uint8_t size_block, uint8_t bit, IO_var data);
void gpio_setbit(volatile IO_var* reg, uint8_t size_block, uint8_t bit, IO_var data);
IO_var gpio_getsetbit(volatile IO_var* reg, uint8_t size_block, uint8_t bit);
STM32446GpioFunc stm32446_gpio_func_inic(void);
/*** GPIO Procedure & Function Definition ***/
/*** GPIOA ***/
void STM32446GpioAclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 0); }
	else{ RCC->AHB1ENR &= ~(1 << 0); }
}
void STM32446GpioAmoder( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOA->MODER &= ~(mask << (pin * blocksize));
	GPIOA->MODER |= (data << (pin * blocksize));
}
void STM32446GpioAotyper( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOA->OTYPER &= ~(1 << pin);
		GPIOA->OTYPER |= (bool << pin);
	}
}
void STM32446GpioAospeedr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOA->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOA->OSPEEDR |= (data << (pin * blocksize));
}
void STM32446GpioApupdr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOA->PUPDR &= ~(mask << (pin * blocksize));
	GPIOA->PUPDR |= (data << (pin * blocksize));
}
void STM32446GpioAreset( uint16_t data )
{
	GPIOA->BSRR = (unsigned int)(data << 16);
}
void STM32446GpioAset( uint16_t data )
{
	GPIOA->BSRR = (unsigned int)( data );
}
void STM32446GpioAlckr( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOA->LCKR &= ~(1 << pin);
		GPIOA->LCKR |= (bool << pin);
	}
}
void STM32446GpioAafr( uint8_t data, uint8_t pin )
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
void STM32446GpioBclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 1); }
	else{ RCC->AHB1ENR &= ~(1 << 1); }
}
void STM32446GpioBmoder( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOB->MODER &= ~(mask << (pin * blocksize));
	GPIOB->MODER |= (data << (pin * blocksize));
}
void STM32446GpioBotyper( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOB->OTYPER &= ~(1 << pin);
		GPIOB->OTYPER |= (bool << pin);
	}
}
void STM32446GpioBospeedr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOB->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOB->OSPEEDR |= (data << (pin * blocksize));
}
void STM32446GpioBpupdr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOB->PUPDR &= ~(mask << (pin * blocksize));
	GPIOB->PUPDR |= (data << (pin * blocksize));
}
void STM32446GpioBreset( uint16_t data )
{
	GPIOB->BSRR = (unsigned int)(data << 16);
}
void STM32446GpioBset( uint16_t data )
{
	GPIOB->BSRR = (unsigned int)( data );
}
void STM32446GpioBlckr( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOB->LCKR &= ~(1 << pin);
		GPIOB->LCKR |= (bool << pin);
	}
}
void STM32446GpioBafr( uint8_t data, uint8_t pin )
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
void STM32446GpioCclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 2); }
	else{ RCC->AHB1ENR &= ~(1 << 2); }
}
void STM32446GpioCmoder( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOC->MODER &= ~(mask << (pin * blocksize));
	GPIOC->MODER |= (data << (pin * blocksize));
}
void STM32446GpioCotyper( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOC->OTYPER &= ~(1 << pin);
		GPIOC->OTYPER |= (bool << pin);
	}
}
void STM32446GpioCospeedr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOC->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOC->OSPEEDR |= (data << (pin * blocksize));
}
void STM32446GpioCpupdr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOC->PUPDR &= ~(mask << (pin * blocksize));
	GPIOC->PUPDR |= (data << (pin * blocksize));
}
void STM32446GpioCreset( uint16_t data )
{
	GPIOC->BSRR = (unsigned int)(data << 16);
}
void STM32446GpioCset( uint16_t data )
{
	GPIOC->BSRR = (unsigned int)( data );
}
void STM32446GpioClckr( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOC->LCKR &= ~(1 << pin);
		GPIOC->LCKR |= (bool << pin);
	}
}
void STM32446GpioCafr( uint8_t data, uint8_t pin )
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
void STM32446GpioDclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 3); }
	else{ RCC->AHB1ENR &= ~(1 << 3); }
}
void STM32446GpioDmoder( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOD->MODER &= ~(mask << (pin * blocksize));
	GPIOD->MODER |= (data << (pin * blocksize));
}
void STM32446GpioDotyper( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOD->OTYPER &= ~(1 << pin);
		GPIOD->OTYPER |= (bool << pin);
	}
}
void STM32446GpioDospeedr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOD->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOD->OSPEEDR |= (data << (pin * blocksize));
}
void STM32446GpioDpupdr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOD->PUPDR &= ~(mask << (pin * blocksize));
	GPIOD->PUPDR |= (data << (pin * blocksize));
}
void STM32446GpioDreset( uint16_t data )
{
	GPIOD->BSRR = (unsigned int)(data << 16);
}
void STM32446GpioDset( uint16_t data )
{
	GPIOD->BSRR = (unsigned int)( data );
}
void STM32446GpioDlckr( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOD->LCKR &= ~(1 << pin);
		GPIOD->LCKR |= (bool << pin);
	}
}
void STM32446GpioDafr( uint8_t data, uint8_t pin )
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
void STM32446GpioEclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 4); }
	else{ RCC->AHB1ENR &= ~(1 << 4); }
}
void STM32446GpioEmoder( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOE->MODER &= ~(mask << (pin * blocksize));
	GPIOE->MODER |= (data << (pin * blocksize));
}
void STM32446GpioEotyper( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOE->OTYPER &= ~(1 << pin);
		GPIOE->OTYPER |= (bool << pin);
	}
}
void STM32446GpioEospeedr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOE->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOE->OSPEEDR |= (data << (pin * blocksize));
}
void STM32446GpioEpupdr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOE->PUPDR &= ~(mask << (pin * blocksize));
	GPIOE->PUPDR |= (data << (pin * blocksize));
}
void STM32446GpioEreset( uint16_t data )
{
	GPIOE->BSRR = (unsigned int)(data << 16);
}
void STM32446GpioEset( uint16_t data )
{
	GPIOE->BSRR = (unsigned int)( data );
}
void STM32446GpioElckr( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOE->LCKR &= ~(1 << pin);
		GPIOE->LCKR |= (bool << pin);
	}
}
void STM32446GpioEafr( uint8_t data, uint8_t pin )
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
/*** GPIOF ***/
void STM32446GpioFclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 5); }
	else{ RCC->AHB1ENR &= ~(1 << 5); }
}
void STM32446GpioFmoder( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOF->MODER &= ~(mask << (pin * blocksize));
	GPIOF->MODER |= (data << (pin * blocksize));
}
void STM32446GpioFotyper( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOF->OTYPER &= ~(1 << pin);
		GPIOF->OTYPER |= (bool << pin);
	}
}
void STM32446GpioFospeedr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOF->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOF->OSPEEDR |= (data << (pin * blocksize));
}
void STM32446GpioFpupdr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOF->PUPDR &= ~(mask << (pin * blocksize));
	GPIOF->PUPDR |= (data << (pin * blocksize));
}
void STM32446GpioFreset( uint16_t data )
{
	GPIOF->BSRR = (unsigned int)(data << 16);
}
void STM32446GpioFset( uint16_t data )
{
	GPIOF->BSRR = (unsigned int)( data );
}
void STM32446GpioFlckr( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOF->LCKR &= ~(1 << pin);
		GPIOF->LCKR |= (bool << pin);
	}
}
void STM32446GpioFafr( uint8_t data, uint8_t pin )
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
void STM32446GpioGclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 6); }
	else{ RCC->AHB1ENR &= ~(1 << 6); }
}
void STM32446GpioGmoder( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOG->MODER &= ~(mask << (pin * blocksize));
	GPIOG->MODER |= (data << (pin * blocksize));
}
void STM32446GpioGotyper( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOG->OTYPER &= ~(1 << pin);
		GPIOG->OTYPER |= (bool << pin);
	}
}
void STM32446GpioGospeedr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOG->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOG->OSPEEDR |= (data << (pin * blocksize));
}
void STM32446GpioGpupdr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOG->PUPDR &= ~(mask << (pin * blocksize));
	GPIOG->PUPDR |= (data << (pin * blocksize));
}
void STM32446GpioGreset( uint16_t data )
{
	GPIOG->BSRR = (unsigned int)(data << 16);
}
void STM32446GpioGset( uint16_t data )
{
	GPIOG->BSRR = (unsigned int)( data );
}
void STM32446GpioGlckr( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	if(pin < 16){
		GPIOG->LCKR &= ~(1 << pin);
		GPIOG->LCKR |= (bool << pin);
	}
}
void STM32446GpioGafr( uint8_t data, uint8_t pin )
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
/*** GPIOH ***/
void STM32446GpioHclock( uint8_t bool )
{
	if(bool){ RCC->AHB1ENR |= (1 << 7); }
	else{ RCC->AHB1ENR &= ~(1 << 7); }
}
void STM32446GpioHmoder( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOH->MODER &= ~(mask << (pin * blocksize));
	GPIOH->MODER |= (data << (pin * blocksize));
}
void STM32446GpioHotyper( uint8_t bool, uint8_t pin )
{
	bool &= 1;
	GPIOH->OTYPER &= ~(1 << pin);
	GPIOH->OTYPER |= (bool << pin);
}
void STM32446GpioHospeedr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOH->OSPEEDR &= ~(mask << (pin * blocksize));
	GPIOH->OSPEEDR |= (data << (pin * blocksize));
}
void STM32446GpioHpupdr( uint8_t data, uint8_t pin )
{
	const uint8_t blocksize = 2;
	uint8_t mask = (pow(2, blocksize) - 1);
	data &= mask;
	GPIOH->PUPDR &= ~(mask << (pin * blocksize));
	GPIOH->PUPDR |= (data << (pin * blocksize));
}
void STM32446GpioHreset( uint16_t data )
{
	GPIOH->BSRR = (unsigned int)(data << 16);
}
void STM32446GpioHset( uint16_t data )
{
	GPIOH->BSRR = (unsigned int)( data );
}
void STM32446GpioHafr( uint8_t data, uint8_t pin )
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
/*** COMMON Auxiliar ***/
STM32446GpioFunc stm32446_gpio_func_inic(void)
{
	STM32446GpioFunc stm32446_gpio_func;
	/*** Other ***/
	stm32446_gpio_func.readreg = gpio_readreg;
	stm32446_gpio_func.writereg = gpio_writereg;
	stm32446_gpio_func.setreg = gpio_setreg;
	stm32446_gpio_func.setbit = gpio_setbit;
	stm32446_gpio_func.getsetbit = gpio_getsetbit;
	return stm32446_gpio_func;
}
/*** INIC Procedure & Function Definition ***/
STM32446GpioAobj gpioa_inic(void)
{
	STM32446GpioAobj stm32446_gpioa;
	// GPIOA
	stm32446_gpioa.reg = GPIOA;
	/*** GPIOA RCC Clock Enable ***/
	stm32446_gpioa.clock = STM32446GpioAclock;
	/*** GPIOA Bit Mapping Link ***/
	stm32446_gpioa.moder = STM32446GpioAmoder;
	stm32446_gpioa.ospeedr = STM32446GpioAospeedr;
	stm32446_gpioa.pupdr = STM32446GpioApupdr;
	stm32446_gpioa.reset = STM32446GpioAreset;
	stm32446_gpioa.set = STM32446GpioAset;
	stm32446_gpioa.afr = STM32446GpioAafr;
	/*** Other ***/
	stm32446_gpioa.func = stm32446_gpio_func_inic();
	return stm32446_gpioa;
}
STM32446GpioBobj gpiob_inic(void)
{
	STM32446GpioBobj stm32446_gpiob;
	// GPIOB
	stm32446_gpiob.reg = GPIOB;
	/*** GPIOB RCC Clock Enable ***/
	stm32446_gpiob.clock = STM32446GpioBclock;
	/*** GPIOB Bit Mapping Link ***/
	stm32446_gpiob.moder = STM32446GpioBmoder;
	stm32446_gpiob.ospeedr = STM32446GpioBospeedr;
	stm32446_gpiob.pupdr = STM32446GpioBpupdr;
	stm32446_gpiob.reset = STM32446GpioBreset;
	stm32446_gpiob.set = STM32446GpioBset;
	stm32446_gpiob.afr = STM32446GpioBafr;
	/*** Other ***/
	stm32446_gpiob.func = stm32446_gpio_func_inic();
	return stm32446_gpiob;
}
STM32446GpioCobj gpioc_inic(void)
{
	STM32446GpioCobj stm32446_gpioc;
	// GPIOC
	stm32446_gpioc.reg = GPIOC;
	/*** GPIOC RCC Clock Enable ***/
	stm32446_gpioc.clock = STM32446GpioCclock;
	/*** GPIOC Bit Mapping Link ***/
	stm32446_gpioc.moder = STM32446GpioCmoder;
	stm32446_gpioc.ospeedr = STM32446GpioCospeedr;
	stm32446_gpioc.pupdr = STM32446GpioCpupdr;
	stm32446_gpioc.reset = STM32446GpioCreset;
	stm32446_gpioc.set = STM32446GpioCset;
	stm32446_gpioc.afr = STM32446GpioCafr;
	/*** Other ***/
	stm32446_gpioc.func = stm32446_gpio_func_inic();
	return stm32446_gpioc;
}
STM32446GpioDobj gpiod_inic(void)
{
	STM32446GpioDobj stm32446_gpiod;
	// GPIOD
	stm32446_gpiod.reg = GPIOD;
	/*** GPIOD RCC Clock Enable ***/
	stm32446_gpiod.clock = STM32446GpioDclock;
	/*** GPIOD Bit Mapping Link ***/
	stm32446_gpiod.moder = STM32446GpioDmoder;
	stm32446_gpiod.ospeedr = STM32446GpioDospeedr;
	stm32446_gpiod.pupdr = STM32446GpioDpupdr;
	stm32446_gpiod.reset = STM32446GpioDreset;
	stm32446_gpiod.set = STM32446GpioDset;
	stm32446_gpiod.afr = STM32446GpioDafr;
	/*** Other ***/
	stm32446_gpiod.func = stm32446_gpio_func_inic();
	return stm32446_gpiod;
}
STM32446GpioEobj gpioe_inic(void)
{
	STM32446GpioEobj stm32446_gpioe;
	// GPIOE
	stm32446_gpioe.reg = GPIOE;
	/*** GPIOE RCC Clock Enable ***/
	stm32446_gpioe.clock = STM32446GpioEclock;
	/*** GPIOE Bit Mapping Link ***/
	stm32446_gpioe.moder = STM32446GpioEmoder;
	stm32446_gpioe.ospeedr = STM32446GpioEospeedr;
	stm32446_gpioe.pupdr = STM32446GpioEpupdr;
	stm32446_gpioe.reset = STM32446GpioEreset;
	stm32446_gpioe.set = STM32446GpioEset;
	stm32446_gpioe.afr = STM32446GpioEafr;
	/*** Other ***/
	stm32446_gpioe.func = stm32446_gpio_func_inic();
	return stm32446_gpioe;
}
STM32446GpioHobj gpioh_inic(void)
{
	STM32446GpioHobj stm32446_gpioh;
	// GPIOH
	stm32446_gpioh.reg = GPIOH;
	/*** GPIOH RCC Clock Enable ***/
	stm32446_gpioh.clock = STM32446GpioHclock;
	/*** GPIOH Bit Mapping Link ***/
	stm32446_gpioh.moder = STM32446GpioHmoder;
	stm32446_gpioh.ospeedr = STM32446GpioHospeedr;
	stm32446_gpioh.pupdr = STM32446GpioHpupdr;
	stm32446_gpioh.reset = STM32446GpioHreset;
	stm32446_gpioh.set = STM32446GpioHset;
	stm32446_gpioh.afr = STM32446GpioHafr;
	/*** Other ***/
	stm32446_gpioh.func = stm32446_gpio_func_inic();
	return stm32446_gpioh;
}
/*** File Procedure & Function Definition ***/
IO_var gpio_readreg(IO_var reg, uint8_t size_block, uint8_t bit_n)
{
	if(bit_n > DATA_BITS){ bit_n = 0; } if(size_block > DATA_SIZE){ size_block = DATA_SIZE; }
	IO_var mask = (IO_var)((1 << size_block) - 1);
	reg &= (mask << bit_n);
	reg = (reg >> bit_n);
	return reg;
}
IO_var gpio_getsetbit(volatile IO_var* reg, uint8_t size_block, uint8_t bit_n)
{
	uint8_t n = 0;
	if(bit_n > DATA_BITS){ n = bit_n/DATA_SIZE; bit_n -= (n * DATA_SIZE); } if(size_block > DATA_SIZE){ size_block = DATA_SIZE; }
	IO_var value = *(reg + n );
	IO_var mask = (IO_var)((1 << size_block) - 1);
	value &= (mask << bit_n);
	value = (value >> bit_n);
	return value;
}
void gpio_setreg(volatile IO_var* reg, uint8_t size_block, uint8_t bit_n, IO_var data )
{
	if(bit_n > DATA_BITS){ bit_n = 0; } if(size_block > DATA_SIZE){ size_block = DATA_SIZE; }
	IO_var mask = (IO_var)((1 << size_block) - 1);
	data &= mask;
	*reg &= ~(mask << bit_n);
	*reg |= (data << bit_n);
}
void gpio_setbit(volatile IO_var* reg, uint8_t size_block, uint8_t bit_n, IO_var data)
{
	uint8_t n = 0;
	if(bit_n > DATA_BITS){ n = bit_n/DATA_SIZE; bit_n = bit_n - (n * DATA_SIZE); } if(size_block > DATA_SIZE){ size_block = DATA_SIZE; }
	IO_var mask = (IO_var)((1 << size_block) - 1);
	data &= mask;
	*(reg + n ) &= ~(mask << bit_n);
	*(reg + n ) |= (data << bit_n);
}
void gpio_writereg(volatile IO_var* reg, uint8_t size_block, uint8_t bit_n, IO_var data)
{
	if(bit_n > DATA_BITS){ bit_n = 0; } if(size_block > DATA_SIZE){ size_block = DATA_SIZE; }
	IO_var value = *reg;
	IO_var mask = (IO_var)((1 << size_block) - 1);
	data &= mask; value &= ~(mask << bit_n);
	data = (data << bit_n);
	value |= data;
	*reg = value;
}

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


