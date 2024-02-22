/******************************************************************************
	STM32 xxx GPIO
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-xxx
Date: 19/06/2023
Update: 05/01/2024
Comment:
	TypeDef Pointer Structures, Library Function Headers.
*******************************************************************************/
#ifndef _STM32FXXXGPIO_H_
	#define _STM32FXXXGPIO_H_

/*** File Library ***/
#include "armquery.h"

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

}STM32FXXXGpioAobj, STM32FXXXGpioBobj, STM32FXXXGpioCobj, STM32FXXXGpioDobj, STM32FXXXGpioEobj, STM32FXXXGpioFobj, STM32FXXXGpioGobj, STM32FXXXGpioHobj;
// INIC
STM32FXXXGpioAobj gpioa_enable(void);
STM32FXXXGpioAobj* gpioa(void);

STM32FXXXGpioBobj gpiob_enable(void);
STM32FXXXGpioBobj* gpiob(void);

STM32FXXXGpioCobj gpioc_enable(void);
STM32FXXXGpioCobj* gpioc(void);

STM32FXXXGpioDobj gpiod_enable(void);
STM32FXXXGpioDobj* gpiod(void);

STM32FXXXGpioEobj gpioe_enable(void);
STM32FXXXGpioEobj* gpioe(void);

STM32FXXXGpioHobj gpioh_enable(void);
STM32FXXXGpioHobj* gpioh(void);

/***** GPIO Procedure & Funtion Header ******/
void STM32FXXXGpioAclock( uint8_t bool );
void STM32FXXXGpioAmoder( uint8_t pin, uint8_t data );
void STM32FXXXGpioAotyper( uint8_t pin, uint8_t bool );
void STM32FXXXGpioAospeedr( uint8_t pin, uint8_t data );
void STM32FXXXGpioApupdr( uint8_t pin, uint8_t data );
void STM32FXXXGpioAreset( uint16_t data );
void STM32FXXXGpioAset( uint16_t data );
void STM32FXXXGpioAlckr( uint8_t pin, uint8_t bool );
void STM32FXXXGpioAafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioBclock( uint8_t bool );
void STM32FXXXGpioBmoder( uint8_t pin, uint8_t data );
void STM32FXXXGpioBotyper( uint8_t pin, uint8_t bool );
void STM32FXXXGpioBospeedr( uint8_t pin, uint8_t data );
void STM32FXXXGpioBpupdr( uint8_t pin, uint8_t data );
void STM32FXXXGpioBreset( uint16_t data );
void STM32FXXXGpioBset( uint16_t data );
void STM32FXXXGpioBlckr( uint8_t pin, uint8_t bool );
void STM32FXXXGpioBafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioCclock( uint8_t bool );
void STM32FXXXGpioCmoder( uint8_t pin, uint8_t data );
void STM32FXXXGpioCotyper( uint8_t pin, uint8_t bool );
void STM32FXXXGpioCospeedr( uint8_t pin, uint8_t data );
void STM32FXXXGpioCpupdr( uint8_t pin, uint8_t data );
void STM32FXXXGpioCreset( uint16_t data );
void STM32FXXXGpioCset( uint16_t data );
void STM32FXXXGpioClckr( uint8_t pin, uint8_t bool );
void STM32FXXXGpioCafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioDclock( uint8_t bool );
void STM32FXXXGpioDmoder( uint8_t pin, uint8_t data );
void STM32FXXXGpioDotyper( uint8_t pin, uint8_t bool );
void STM32FXXXGpioDospeedr( uint8_t pin, uint8_t data );
void STM32FXXXGpioDpupdr( uint8_t pin, uint8_t data );
void STM32FXXXGpioDreset( uint16_t data );
void STM32FXXXGpioDset( uint16_t data );
void STM32FXXXGpioDlckr( uint8_t pin, uint8_t bool );
void STM32FXXXGpioDafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioEclock( uint8_t bool );
void STM32FXXXGpioEmoder( uint8_t pin, uint8_t data );
void STM32FXXXGpioEotyper( uint8_t pin, uint8_t bool );
void STM32FXXXGpioEospeedr( uint8_t pin, uint8_t data );
void STM32FXXXGpioEpupdr( uint8_t pin, uint8_t data );
void STM32FXXXGpioEreset( uint16_t data );
void STM32FXXXGpioEset( uint16_t data );
void STM32FXXXGpioElckr( uint8_t pin, uint8_t bool );
void STM32FXXXGpioEafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioFclock( uint8_t bool );
void STM32FXXXGpioFmoder( uint8_t pin, uint8_t data );
void STM32FXXXGpioFotyper( uint8_t pin, uint8_t bool );
void STM32FXXXGpioFospeedr( uint8_t pin, uint8_t data );
void STM32FXXXGpioFpupdr( uint8_t pin, uint8_t data );
void STM32FXXXGpioFreset( uint16_t data );
void STM32FXXXGpioFset( uint16_t data );
void STM32FXXXGpioFlckr( uint8_t pin, uint8_t bool );
void STM32FXXXGpioFafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioGclock( uint8_t bool );
void STM32FXXXGpioGmoder( uint8_t pin, uint8_t data );
void STM32FXXXGpioGotyper( uint8_t pin, uint8_t bool );
void STM32FXXXGpioGospeedr( uint8_t pin, uint8_t data );
void STM32FXXXGpioGpupdr( uint8_t pin, uint8_t data );
void STM32FXXXGpioGreset( uint16_t data );
void STM32FXXXGpioGset( uint16_t data );
void STM32FXXXGpioGlckr( uint8_t pin, uint8_t bool );
void STM32FXXXGpioGafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioHclock( uint8_t bool );
void STM32FXXXGpioHmoder( uint8_t pin, uint8_t data );
void STM32FXXXGpioHotyper( uint8_t pin, uint8_t bool );
void STM32FXXXGpioHospeedr( uint8_t pin, uint8_t data );
void STM32FXXXGpioHpupdr( uint8_t pin, uint8_t data );
void STM32FXXXGpioHreset( uint16_t data );
void STM32FXXXGpioHset( uint16_t data );
void STM32FXXXGpioHlckr( uint8_t pin, uint8_t bool );
void STM32FXXXGpioHafr( uint8_t pin, uint8_t data );

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

