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
#include <inttypes.h>
/*** Constant & Maco ***/
#ifndef IO_var
	#define IO_var uint32_t
#endif
#ifndef DATA_BITS
	#define DATA_BITS 31
#endif
#ifndef DATA_SIZE
	#define DATA_SIZE 32
#endif
/*** GPIO TypeDef ***/
typedef struct
{
	IO_var (*readreg)(IO_var reg, uint8_t size_block, uint8_t bit);
	void (*writereg)(volatile IO_var* reg, uint8_t size_block, uint8_t bit, IO_var data);
	void (*setreg)(volatile IO_var* reg, uint8_t size_block, uint8_t bit, IO_var data);
	void (*setbit)(volatile IO_var* reg, uint8_t size_block, uint8_t bit, IO_var data);
	IO_var (*getsetbit)(volatile IO_var* reg, uint8_t size_block, uint8_t bit);
}STM32446GpioFunc;
// GPIO -> GPIOA
typedef struct
{
	GPIO_TypeDef* reg;
	/*** Bit Mapping ***/
	void (*moder)( uint8_t data, uint8_t pin );
	void (*ospeedr)( uint8_t data, uint8_t pin );
	void (*pupdr)( uint8_t data, uint8_t pin );
	void (*afr)( uint8_t data, uint8_t pin );
	void (*reset)( uint16_t data );
	void (*set)( uint16_t data );
	/*** Other ***/
	void (*clock)(uint8_t bool);
	STM32446GpioFunc func;

}STM32446GpioAobj;
// GPIO -> GPIOB
typedef struct
{
	GPIO_TypeDef* reg;
	#if defined(_STM32446GPIO_H_)
		/*** Bit Mapping ***/
		void (*moder)( uint8_t data, uint8_t pin );
		void (*ospeedr)( uint8_t data, uint8_t pin );
		void (*pupdr)( uint8_t data, uint8_t pin );
		void (*afr)( uint8_t data, uint8_t pin );
		void (*reset)( uint16_t data );
		void (*set)( uint16_t data );
		/*** Other ***/
		void (*clock)(uint8_t bool);
		STM32446GpioFunc func;
	#endif
}STM32446GpioBobj;
// GPIO -> GPIOC
typedef struct
{
	GPIO_TypeDef* reg;
	#if defined(_STM32446GPIO_H_)
		/*** Bit Mapping ***/
		void (*moder)( uint8_t data, uint8_t pin );
		void (*ospeedr)( uint8_t data, uint8_t pin );
		void (*pupdr)( uint8_t data, uint8_t pin );
		void (*afr)( uint8_t data, uint8_t pin );
		void (*reset)( uint16_t data );
		void (*set)( uint16_t data );
		/*** Other ***/
		void (*clock)(uint8_t bool);
		STM32446GpioFunc func;
	#endif
}STM32446GpioCobj;
// GPIO -> GPIOD
typedef struct
{
	GPIO_TypeDef* reg;
	#if defined(_STM32446GPIO_H_)
		/*** Bit Mapping ***/
		void (*moder)( uint8_t data, uint8_t pin );
		void (*ospeedr)( uint8_t data, uint8_t pin );
		void (*pupdr)( uint8_t data, uint8_t pin );
		void (*afr)( uint8_t data, uint8_t pin );
		void (*reset)( uint16_t data );
		void (*set)( uint16_t data );
		/*** Other ***/
		void (*clock)(uint8_t bool);
		STM32446GpioFunc func;
	#endif
}STM32446GpioDobj;
// GPIO -> GPIOE
typedef struct
{
	GPIO_TypeDef* reg;
	#if defined(_STM32446GPIO_H_)
		/*** Bit Mapping ***/
		void (*moder)( uint8_t data, uint8_t pin );
		void (*ospeedr)( uint8_t data, uint8_t pin );
		void (*pupdr)( uint8_t data, uint8_t pin );
		void (*afr)( uint8_t data, uint8_t pin );
		void (*reset)( uint16_t data );
		void (*set)( uint16_t data );
		/*** Other ***/
		void (*clock)(uint8_t bool);
		STM32446GpioFunc func;
	#endif
}STM32446GpioEobj;
// GPIO -> GPIOF
typedef struct
{
	GPIO_TypeDef* reg;
	#if defined(_STM32446GPIO_H_)
		/*** Bit Mapping ***/
		void (*moder)( uint8_t data, uint8_t pin );
		void (*ospeedr)( uint8_t data, uint8_t pin );
		void (*pupdr)( uint8_t data, uint8_t pin );
		void (*afr)( uint8_t data, uint8_t pin );
		void (*reset)( uint16_t data );
		void (*set)( uint16_t data );
		/*** Other ***/
		void (*clock)(uint8_t bool);
		STM32446GpioFunc func;
	#endif
}STM32446GpioFobj;
// GPIO -> GPIOG
typedef struct
{
	GPIO_TypeDef* reg;
	#if defined(_STM32446GPIO_H_)
		/*** Bit Mapping ***/
		void (*moder)( uint8_t data, uint8_t pin );
		void (*ospeedr)( uint8_t data, uint8_t pin );
		void (*pupdr)( uint8_t data, uint8_t pin );
		void (*afr)( uint8_t data, uint8_t pin );
		void (*reset)( uint16_t data );
		void (*set)( uint16_t data );
		/*** Other ***/
		void (*clock)(uint8_t bool);
		STM32446GpioFunc func;
	#endif
}STM32446GpioGobj;
// GPIO -> GPIOH
typedef struct
{
	GPIO_TypeDef* reg;
	#if defined(_STM32446GPIO_H_)
		/*** Bit Mapping ***/
		void (*moder)( uint8_t data, uint8_t pin );
		void (*ospeedr)( uint8_t data, uint8_t pin );
		void (*pupdr)( uint8_t data, uint8_t pin );
		void (*afr)( uint8_t data, uint8_t pin );
		void (*reset)( uint16_t data );
		void (*set)( uint16_t data );
		/*** Other ***/
		void (*clock)(uint8_t bool);
		STM32446GpioFunc func;
	#endif
}STM32446GpioHobj;
// INIC
STM32446GpioAobj gpioa_inic(void);
STM32446GpioBobj gpiob_inic(void);
STM32446GpioCobj gpioc_inic(void);
STM32446GpioDobj gpiod_inic(void);
STM32446GpioEobj gpioe_inic(void);
STM32446GpioHobj gpioh_inic(void);
/***** GPIO Procedure & Funtion Header ******/
void STM32446GpioAclock( uint8_t bool );
void STM32446GpioAmoder( uint8_t data, uint8_t pin );
void STM32446GpioAospeedr( uint8_t data, uint8_t pin );
void STM32446GpioApupdr( uint8_t data, uint8_t pin );
void STM32446GpioAreset( uint16_t data );
void STM32446GpioAset( uint16_t data );
void STM32446GpioAafr( uint8_t data, uint8_t pin );
void STM32446GpioBclock( uint8_t bool );
void STM32446GpioBmoder( uint8_t data, uint8_t pin );
void STM32446GpioBospeedr( uint8_t data, uint8_t pin );
void STM32446GpioBpupdr( uint8_t data, uint8_t pin );
void STM32446GpioBreset( uint16_t data );
void STM32446GpioBset( uint16_t data );
void STM32446GpioBafr( uint8_t data, uint8_t pin );
void STM32446GpioCclock( uint8_t bool );
void STM32446GpioCmoder( uint8_t data, uint8_t pin );
void STM32446GpioCospeedr( uint8_t data, uint8_t pin );
void STM32446GpioCpupdr( uint8_t data, uint8_t pin );
void STM32446GpioCreset( uint16_t data );
void STM32446GpioCset( uint16_t data );
void STM32446GpioCafr( uint8_t data, uint8_t pin );
void STM32446GpioDclock( uint8_t bool );
void STM32446GpioDmoder( uint8_t data, uint8_t pin );
void STM32446GpioDospeedr( uint8_t data, uint8_t pin );
void STM32446GpioDpupdr( uint8_t data, uint8_t pin );
void STM32446GpioDreset( uint16_t data );
void STM32446GpioDset( uint16_t data );
void STM32446GpioDafr( uint8_t data, uint8_t pin );
void STM32446GpioEclock( uint8_t bool );
void STM32446GpioEmoder( uint8_t data, uint8_t pin );
void STM32446GpioEospeedr( uint8_t data, uint8_t pin );
void STM32446GpioEpupdr( uint8_t data, uint8_t pin );
void STM32446GpioEreset( uint16_t data );
void STM32446GpioEset( uint16_t data );
void STM32446GpioEafr( uint8_t data, uint8_t pin );
void STM32446GpioFclock( uint8_t bool );
void STM32446GpioFmoder( uint8_t data, uint8_t pin );
void STM32446GpioFospeedr( uint8_t data, uint8_t pin );
void STM32446GpioFpupdr( uint8_t data, uint8_t pin );
void STM32446GpioFreset( uint16_t data );
void STM32446GpioFset( uint16_t data );
void STM32446GpioFafr( uint8_t data, uint8_t pin );
void STM32446GpioGclock( uint8_t bool );
void STM32446GpioGmoder( uint8_t data, uint8_t pin );
void STM32446GpioGospeedr( uint8_t data, uint8_t pin );
void STM32446GpioGpupdr( uint8_t data, uint8_t pin );
void STM32446GpioGreset( uint16_t data );
void STM32446GpioGset( uint16_t data );
void STM32446GpioGafr( uint8_t data, uint8_t pin );
void STM32446GpioHclock( uint8_t bool );
void STM32446GpioHmoder( uint8_t data, uint8_t pin );
void STM32446GpioHospeedr( uint8_t data, uint8_t pin );
void STM32446GpioHpupdr( uint8_t data, uint8_t pin );
void STM32446GpioHreset( uint16_t data );
void STM32446GpioHset( uint16_t data );
void STM32446GpioHafr( uint8_t data, uint8_t pin );

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


