/******************************************************************************
	STM32 446 GPIO
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 19/06/2023
Update: 05/01/2024
Comment:
	TypeDef Pointer Structures, Library Function Headers.
*******************************************************************************/
#ifndef _STM32446GPIO_H_
	#define _STM32446GPIO_H_

/*** File Library ***/
#include "stm32query.h"

/*** GPIO TypeDef ***/
// GPIO -> GPIO
typedef struct
{

	/*** Bit Mapping ***/
	void (*moder)( uint8_t pin, uint8_t data );
	void (*otyper)( uint8_t pin, uint8_t bool );
	void (*ospeedr)( uint8_t pin, uint8_t data );
	void (*pupdr)( uint8_t pin, uint8_t data );
	void (*afr)( uint8_t pin, uint8_t data );
	void (*reset)( uint16_t data );
	void (*set)( uint16_t data );
	void (*lckr)( uint8_t pin, uint8_t bool );
	/*** Other ***/
	void (*clock)( uint8_t bool );

}STM32446GpioAobj, STM32446GpioBobj, STM32446GpioCobj, STM32446GpioDobj, STM32446GpioEobj, STM32446GpioFobj, STM32446GpioGobj, STM32446GpioHobj;
// INIC
STM32446GpioAobj gpioa_enable(void);
STM32446GpioAobj* gpioa(void);

STM32446GpioBobj gpiob_enable(void);
STM32446GpioBobj* gpiob(void);

STM32446GpioCobj gpioc_enable(void);
STM32446GpioCobj* gpioc(void);

STM32446GpioDobj gpiod_enable(void);
STM32446GpioDobj* gpiod(void);

STM32446GpioEobj gpioe_enable(void);
STM32446GpioEobj* gpioe(void);

STM32446GpioHobj gpioh_enable(void);
STM32446GpioHobj* gpioh(void);

/***** GPIO Procedure & Funtion Header ******/
void STM32446GpioAclock( uint8_t bool );
void STM32446GpioAmoder( uint8_t pin, uint8_t data );
void STM32446GpioAotyper( uint8_t pin, uint8_t bool );
void STM32446GpioAospeedr( uint8_t pin, uint8_t data );
void STM32446GpioApupdr( uint8_t pin, uint8_t data );
void STM32446GpioAreset( uint16_t data );
void STM32446GpioAset( uint16_t data );
void STM32446GpioAlckr( uint8_t pin, uint8_t bool );
void STM32446GpioAafr( uint8_t pin, uint8_t data );
void STM32446GpioBclock( uint8_t bool );
void STM32446GpioBmoder( uint8_t pin, uint8_t data );
void STM32446GpioBotyper( uint8_t pin, uint8_t bool );
void STM32446GpioBospeedr( uint8_t pin, uint8_t data );
void STM32446GpioBpupdr( uint8_t pin, uint8_t data );
void STM32446GpioBreset( uint16_t data );
void STM32446GpioBset( uint16_t data );
void STM32446GpioBlckr( uint8_t pin, uint8_t bool );
void STM32446GpioBafr( uint8_t pin, uint8_t data );
void STM32446GpioCclock( uint8_t bool );
void STM32446GpioCmoder( uint8_t pin, uint8_t data );
void STM32446GpioCotyper( uint8_t pin, uint8_t bool );
void STM32446GpioCospeedr( uint8_t pin, uint8_t data );
void STM32446GpioCpupdr( uint8_t pin, uint8_t data );
void STM32446GpioCreset( uint16_t data );
void STM32446GpioCset( uint16_t data );
void STM32446GpioClckr( uint8_t pin, uint8_t bool );
void STM32446GpioCafr( uint8_t pin, uint8_t data );
void STM32446GpioDclock( uint8_t bool );
void STM32446GpioDmoder( uint8_t pin, uint8_t data );
void STM32446GpioDotyper( uint8_t pin, uint8_t bool );
void STM32446GpioDospeedr( uint8_t pin, uint8_t data );
void STM32446GpioDpupdr( uint8_t pin, uint8_t data );
void STM32446GpioDreset( uint16_t data );
void STM32446GpioDset( uint16_t data );
void STM32446GpioDlckr( uint8_t pin, uint8_t bool );
void STM32446GpioDafr( uint8_t pin, uint8_t data );
void STM32446GpioEclock( uint8_t bool );
void STM32446GpioEmoder( uint8_t pin, uint8_t data );
void STM32446GpioEotyper( uint8_t pin, uint8_t bool );
void STM32446GpioEospeedr( uint8_t pin, uint8_t data );
void STM32446GpioEpupdr( uint8_t pin, uint8_t data );
void STM32446GpioEreset( uint16_t data );
void STM32446GpioEset( uint16_t data );
void STM32446GpioElckr( uint8_t pin, uint8_t bool );
void STM32446GpioEafr( uint8_t pin, uint8_t data );
void STM32446GpioFclock( uint8_t bool );
void STM32446GpioFmoder( uint8_t pin, uint8_t data );
void STM32446GpioFotyper( uint8_t pin, uint8_t bool );
void STM32446GpioFospeedr( uint8_t pin, uint8_t data );
void STM32446GpioFpupdr( uint8_t pin, uint8_t data );
void STM32446GpioFreset( uint16_t data );
void STM32446GpioFset( uint16_t data );
void STM32446GpioFlckr( uint8_t pin, uint8_t bool );
void STM32446GpioFafr( uint8_t pin, uint8_t data );
void STM32446GpioGclock( uint8_t bool );
void STM32446GpioGmoder( uint8_t pin, uint8_t data );
void STM32446GpioGotyper( uint8_t pin, uint8_t bool );
void STM32446GpioGospeedr( uint8_t pin, uint8_t data );
void STM32446GpioGpupdr( uint8_t pin, uint8_t data );
void STM32446GpioGreset( uint16_t data );
void STM32446GpioGset( uint16_t data );
void STM32446GpioGlckr( uint8_t pin, uint8_t bool );
void STM32446GpioGafr( uint8_t pin, uint8_t data );
void STM32446GpioHclock( uint8_t bool );
void STM32446GpioHmoder( uint8_t pin, uint8_t data );
void STM32446GpioHotyper( uint8_t pin, uint8_t bool );
void STM32446GpioHospeedr( uint8_t pin, uint8_t data );
void STM32446GpioHpupdr( uint8_t pin, uint8_t data );
void STM32446GpioHreset( uint16_t data );
void STM32446GpioHset( uint16_t data );
void STM32446GpioHlckr( uint8_t pin, uint8_t bool );
void STM32446GpioHafr( uint8_t pin, uint8_t data );

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

