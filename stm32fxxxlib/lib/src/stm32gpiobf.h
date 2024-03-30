/******************************************************************************
	STM32 XXX GPIOBF
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 25032024
Comment:
	wrapper
*******************************************************************************/
#ifndef _STM32GPIOBF_H_
	#define _STM32GPIOBF_H_

#include <inttypes.h>

volatile typedef struct{
	/*** GPIO -> MODER ***/
	union{
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
		} par;
		uint32_t reg;
	} moder; //0x00
	/*** GPIO -> OTYPER ***/
	union{
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
		uint32_t reg;
	} otyper; //0x04
	/*** GPIO -> OSPEEDR ***/
	union{
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
		} par;
		uint32_t reg;
	} ospeedr; //0x08
	/*** GPIO -> PUPDR ***/
	union{
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
		} par;
		uint32_t reg;
	} pupdr; //0x0C
	/*** GPIO -> IDR ***/
	union{
		struct IDR_1{
		  uint32_t i0:1;
		  uint32_t i1:1;
		  uint32_t i2:1;
		  uint32_t i3:1;
		  uint32_t i4:1;
		  uint32_t i5:1;
		  uint32_t i6:1;
		  uint32_t i7:1;
		  uint32_t i8:1;
		  uint32_t i9:1;
		  uint32_t i10:1;
		  uint32_t i11:1;
		  uint32_t i12:1;
		  uint32_t i13:1;
		  uint32_t i14:1;
		  uint32_t i15:1;
		  uint32_t fill:16;
		} bit;
		struct IDR_2{
		  uint16_t i;
		  uint16_t fill;
		} word;
		uint32_t reg;
	} idr; //0x10
	/*** GPIO -> ODR ***/
	union{
		struct ODR_1{
		  uint32_t o0:1;
		  uint32_t o1:1;
		  uint32_t o2:1;
		  uint32_t o3:1;
		  uint32_t o4:1;
		  uint32_t o5:1;
		  uint32_t o6:1;
		  uint32_t o7:1;
		  uint32_t o8:1;
		  uint32_t o9:1;
		  uint32_t o10:1;
		  uint32_t o11:1;
		  uint32_t o12:1;
		  uint32_t o13:1;
		  uint32_t o14:1;
		  uint32_t o15:1;
		  uint32_t fill:16;
		} bit;
		struct ODR_2{
		  uint16_t o;
		  uint16_t fill;
		} word;
		uint32_t reg;
	} odr; //0x14
	/*** GPIO -> BSRR ***/
	union{
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
		uint32_t reg;
	} bsrr; //0x18
	/*** GPIO -> LCKR ***/
	union{
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
		uint32_t reg;
	} lckr; //0x1C
	/*** GPIO -> AFR ***/
	union{
		struct AFR_1{
		  uint32_t pin0:4;
		  uint32_t pin1:4;
		  uint32_t pin2:4;
		  uint32_t pin3:4;
		  uint32_t pin4:4;
		  uint32_t pin5:4;
		  uint32_t pin6:4;
		  uint32_t pin7:4;
		  uint32_t pin8:4;
		  uint32_t pin9:4;
		  uint32_t pin10:4;
		  uint32_t pin11:4;
		  uint32_t pin12:4;
		  uint32_t pin13:4;
		  uint32_t pin14:4;
		  uint32_t pin15:4;
		} par;
		uint32_t regl; //0x20
		uint32_t regh; //0x24
	} afr;
} STM32FXXXGPIOX_TypeDef;

#endif

/*** EOF ***/

