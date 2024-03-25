/******************************************************************************
	STM32 XXX GPIO
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 19/06/2023
Update: 28/02/2024
Comment:
	TypeDef Pointer Structures, Library Function Headers.
*******************************************************************************/
#ifndef _STM32FXXXGPIO_H_
	#define _STM32FXXXGPIO_H_

/*** File Library ***/
#include "armquery.h"
#include "stm32gpiobf.h"

/*** GPIO -> GPIO ***/
typedef struct
{

	/*** BitField Mapping ***/
	GPIOX_TypeDef* handle;
	/*** Other ***/
	void (*clock)( uint8_t bool );

}STM32FXXXGPIOA_HandleTypeDef, STM32FXXXGPIOB_HandleTypeDef, STM32FXXXGPIOC_HandleTypeDef, \
 STM32FXXXGPIOD_HandleTypeDef, STM32FXXXGPIOE_HandleTypeDef, STM32FXXXGPIOF_HandleTypeDef, \
 STM32FXXXGPIOG_HandleTypeDef, STM32FXXXGPIOH_HandleTypeDef;
// INIC
STM32FXXXGPIOA_HandleTypeDef* gpioa_enable(void);
STM32FXXXGPIOA_HandleTypeDef* gpioa(void);

STM32FXXXGPIOB_HandleTypeDef* gpiob_enable(void);
STM32FXXXGPIOB_HandleTypeDef* gpiob(void);

STM32FXXXGPIOC_HandleTypeDef* gpioc_enable(void);
STM32FXXXGPIOC_HandleTypeDef* gpioc(void);

STM32FXXXGPIOD_HandleTypeDef* gpiod_enable(void);
STM32FXXXGPIOD_HandleTypeDef* gpiod(void);

STM32FXXXGPIOE_HandleTypeDef* gpioe_enable(void);
STM32FXXXGPIOE_HandleTypeDef* gpioe(void);

STM32FXXXGPIOF_HandleTypeDef* gpiof_enable(void);
STM32FXXXGPIOF_HandleTypeDef* gpiof(void);

STM32FXXXGPIOG_HandleTypeDef* gpiog_enable(void);
STM32FXXXGPIOG_HandleTypeDef* gpiog(void);

STM32FXXXGPIOH_HandleTypeDef* gpioh_enable(void);
STM32FXXXGPIOH_HandleTypeDef* gpioh(void);

/***** GPIO Procedure & Funtion Header ******/
void STM32FXXXGpioAclock( uint8_t bool );
void STM32FXXXGpioAafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioBclock( uint8_t bool );
void STM32FXXXGpioBafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioCclock( uint8_t bool );
void STM32FXXXGpioCafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioDclock( uint8_t bool );
void STM32FXXXGpioDafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioEclock( uint8_t bool );
void STM32FXXXGpioEafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioFclock( uint8_t bool );
void STM32FXXXGpioFafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioGclock( uint8_t bool );
void STM32FXXXGpioGafr( uint8_t pin, uint8_t data );
void STM32FXXXGpioHclock( uint8_t bool );
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

