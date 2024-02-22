/******************************************************************************
	STM32 XXX GPIO
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 19/06/2023
Update: 05/01/2024
Comment:
	TypeDef Pointer Structures, Library Function Headers.
*******************************************************************************/
#ifndef _STM32FXXXGPIO_H_
	#define _STM32FXXXGPIO_H_

/*** File Library ***/
#include "armquery.h"

/*** GPIO -> MODER ***/
typedef union{
	struct MODER_1{
	  uint32_t m0:2;
	  uint32_t m1:2;
	  uint32_t m2:2;
	  uint32_t m3:2;
	  uint32_t m4:2;
	  uint32_t m5:2;
	  uint32_t m6:2;
	  uint32_t m7:2;
	  uint32_t m8:2;
	  uint32_t m9:2;
	  uint32_t m10:2;
	  uint32_t m11:2;
	  uint32_t m12:2;
	  uint32_t m13:2;
	  uint32_t m14:2;
	  uint32_t m15:2;
	} bit;
	uint32_t m;
} GPIO_MODER_TypeDef;
/*** GPIO -> OTYPER ***/
typedef union{
	struct OTYPER_1{
	  uint32_t t0:1;
	  uint32_t t1:1;
	  uint32_t t2:1;
	  uint32_t t3:1;
	  uint32_t t4:1;
	  uint32_t t5:1;
	  uint32_t t6:1;
	  uint32_t t7:1;
	  uint32_t t8:1;
	  uint32_t t9:1;
	  uint32_t t10:1;
	  uint32_t t11:1;
	  uint32_t t12:1;
	  uint32_t t13:1;
	  uint32_t t14:1;
	  uint32_t t15:1;
	  uint32_t fill:16;
	} bit;
	struct OTYPER_2{
	  uint16_t t;
	  uint16_t fill;
	} word;
} GPIO_OTYPER_TypeDef;
/*** GPIO -> OSPEEDR ***/
typedef union{
	struct OSPEEDR_1{
	  uint32_t s0:2;
	  uint32_t s1:2;
	  uint32_t s2:2;
	  uint32_t s3:2;
	  uint32_t s4:2;
	  uint32_t s5:2;
	  uint32_t s6:2;
	  uint32_t s7:2;
	  uint32_t s8:2;
	  uint32_t s9:2;
	  uint32_t s10:2;
	  uint32_t s11:2;
	  uint32_t s12:2;
	  uint32_t s13:2;
	  uint32_t s14:2;
	  uint32_t s15:2;
	} bit;
	uint32_t s;
} GPIO_OSPEEDR_TypeDef;
/*** GPIO -> PUPDR ***/
typedef union{
	struct PUPDR_1{
	  uint32_t p0:2;
	  uint32_t p1:2;
	  uint32_t p2:2;
	  uint32_t p3:2;
	  uint32_t p4:2;
	  uint32_t p5:2;
	  uint32_t p6:2;
	  uint32_t p7:2;
	  uint32_t p8:2;
	  uint32_t p9:2;
	  uint32_t p10:2;
	  uint32_t p11:2;
	  uint32_t p12:2;
	  uint32_t p13:2;
	  uint32_t p14:2;
	  uint32_t p15:2;
	} bit;
	uint32_t p;
} GPIO_PUPDR_TypeDef;
/*** GPIO -> BSRR ***/
typedef union{
	struct BSRR_1{
	  uint32_t s0:1;
	  uint32_t s1:1;
	  uint32_t s2:1;
	  uint32_t s3:1;
	  uint32_t s4:1;
	  uint32_t s5:1;
	  uint32_t s6:1;
	  uint32_t s7:1;
	  uint32_t s8:1;
	  uint32_t s9:1;
	  uint32_t s10:1;
	  uint32_t s11:1;
	  uint32_t s12:1;
	  uint32_t s13:1;
	  uint32_t s14:1;
	  uint32_t s15:1;
	  uint32_t r0:1;
	  uint32_t r1:1;
	  uint32_t r2:1;
	  uint32_t r3:1;
	  uint32_t r4:1;
	  uint32_t r5:1;
	  uint32_t r6:1;
	  uint32_t r7:1;
	  uint32_t r8:1;
	  uint32_t r9:1;
	  uint32_t r10:1;
	  uint32_t r11:1;
	  uint32_t r12:1;
	  uint32_t r13:1;
	  uint32_t r14:1;
	  uint32_t r15:1;
	} bit;
	struct BSRR_2{
	 uint32_t s:16;
	 uint32_t r:16;
	} word;
} GPIO_BSRR_TypeDef;
/*** GPIO -> LCKR ***/
typedef union{
	struct LCKR_1{
	  uint32_t l0:1;
	  uint32_t l1:1;
	  uint32_t l2:1;
	  uint32_t l3:1;
	  uint32_t l4:1;
	  uint32_t l5:1;
	  uint32_t l6:1;
	  uint32_t l7:1;
	  uint32_t l8:1;
	  uint32_t l9:1;
	  uint32_t l10:1;
	  uint32_t l11:1;
	  uint32_t l12:1;
	  uint32_t l13:1;
	  uint32_t l14:1;
	  uint32_t l15:1;
	  uint32_t fill:16;
	} bit;
	struct LCKR_2{
	  uint16_t l;
	  uint16_t fill;
	} word;
} GPIO_LCKR_TypeDef;
/*** GPIO -> GPIO ***/
typedef struct
{

	/*** Bit Mapping ***/
	GPIO_MODER_TypeDef* moder;
	GPIO_OTYPER_TypeDef* otyper;
	GPIO_OSPEEDR_TypeDef* ospeedr;
	GPIO_PUPDR_TypeDef* pupdr;
	GPIO_BSRR_TypeDef* bsrr;
	GPIO_LCKR_TypeDef* lckr;
	void (*afr)( uint8_t pin, uint8_t data );
	/*** Other ***/
	void (*clock)( uint8_t bool );

}STM32FXXXGPIOA_HandleTypeDef, STM32FXXXGPIOB_HandleTypeDef, STM32FXXXGPIOC_HandleTypeDef, STM32FXXXGPIOD_HandleTypeDef, STM32FXXXGPIOE_HandleTypeDef, STM32FXXXGPIOF_HandleTypeDef, STM32FXXXGPIOG_HandleTypeDef, STM32FXXXGPIOH_HandleTypeDef;
// INIC
STM32FXXXGPIOA_HandleTypeDef gpioa_enable(void);
STM32FXXXGPIOA_HandleTypeDef* gpioa(void);

STM32FXXXGPIOB_HandleTypeDef gpiob_enable(void);
STM32FXXXGPIOB_HandleTypeDef* gpiob(void);

STM32FXXXGPIOC_HandleTypeDef gpioc_enable(void);
STM32FXXXGPIOC_HandleTypeDef* gpioc(void);

STM32FXXXGPIOD_HandleTypeDef gpiod_enable(void);
STM32FXXXGPIOD_HandleTypeDef* gpiod(void);

STM32FXXXGPIOE_HandleTypeDef gpioe_enable(void);
STM32FXXXGPIOE_HandleTypeDef* gpioe(void);

STM32FXXXGPIOF_HandleTypeDef gpiof_enable(void);
STM32FXXXGPIOF_HandleTypeDef* gpiof(void);

STM32FXXXGPIOG_HandleTypeDef gpiog_enable(void);
STM32FXXXGPIOG_HandleTypeDef* gpiog(void);

STM32FXXXGPIOH_HandleTypeDef gpioh_enable(void);
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

