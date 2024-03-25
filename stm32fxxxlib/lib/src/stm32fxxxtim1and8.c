/******************************************************************************
	STM32 XXX TIM 1 and 8
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 2262023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxtim1and8.h"
#include "stm32fxxxnvic.h"
#include "stm32fxxxrcc.h"

/*** File Variables ***/
static STM32FXXXTIM1obj stm32fxxx_tim1;
#ifdef STM32F446xx
	static STM32FXXXTIM8obj stm32fxxx_tim8;
#endif
/************/
/*** TIM1 ***/
/************/
void STM32FXXXTim1Clock(uint8_t bool)
{
	//if(bool){RCC->APB2ENR |= (1 << 0);}else{RCC->APB2ENR &= ~(1 << 0);}
	if(bool){rcc()->handle->apb2enr.par.tim1en = 1;}else{rcc()->handle->apb2enr.par.tim1en = 0;}
}
void STM32FXXXTim1Nvic(uint8_t value)
{ // 24, 25, 26, 27
	switch(value){
		case 0b1000:
			//setbit(NVIC->ISER, 1, TIM1_BRK_TIM9_IRQn, 1);
			nvic()->set_enable(TIM1_BRK_TIM9_IRQn);
		break;
		case 0b0100:
			//setbit(NVIC->ISER, 1, TIM1_UP_TIM10_IRQn, 1);
			nvic()->set_enable(TIM1_UP_TIM10_IRQn);
		break;
		case 0b0010:
			//setbit(NVIC->ISER, 1, TIM1_TRG_COM_TIM11_IRQn, 1);
			nvic()->set_enable(TIM1_TRG_COM_TIM11_IRQn);
		break;
		case 0b0001:
			//setbit(NVIC->ISER, 1, TIM1_CC_IRQn, 1);
			nvic()->set_enable(TIM1_CC_IRQn);
		break;
		case 0b11000:
			//setbit(NVIC->ICER, 1, TIM1_BRK_TIM9_IRQn, 1);
			nvic()->clear_enable(TIM1_BRK_TIM9_IRQn);
		break;
		case 0b10100:
			//setbit(NVIC->ICER, 1, TIM1_UP_TIM10_IRQn, 1);
			nvic()->clear_enable(TIM1_UP_TIM10_IRQn);
		break;
		case 0b10010:
			//setbit(NVIC->ICER, 1, TIM1_TRG_COM_TIM11_IRQn, 1);
			nvic()->clear_enable(TIM1_TRG_COM_TIM11_IRQn);
		break;
		case 0b10001:
			//setbit(NVIC->ICER, 1, TIM1_CC_IRQn, 1);
			nvic()->clear_enable(TIM1_CC_IRQn);
		break;
	default:
	break;
	}
}
#ifdef STM32F446xx
/************/
/*** TIM8 ***/
/************/
void STM32FXXXTim8Clock(uint8_t bool)
{
	if(bool){RCC->APB2ENR |= (1 << 1);}else{RCC->APB2ENR &= ~(1 << 1);}
}
void STM32FXXXTim8Nvic(uint8_t value)
{ // 43, 44, 45, 46
	switch(value){
		case 0b1000:
			setbit(NVIC->ISER, 1, TIM8_BRK_TIM12_IRQn, 1);
		break;
		case 0b0100:
			setbit(NVIC->ISER, 1, TIM8_UP_TIM13_IRQn, 1);
		break;
		case 0b0010:
			setbit(NVIC->ISER, 1, TIM8_TRG_COM_TIM14_IRQn, 1);
		break;
		case 0b0001:
			setbit(NVIC->ISER, 1, TIM8_CC_IRQn, 1);
		break;
		case 0b11000:
			setbit(NVIC->ICER, 1, TIM8_BRK_TIM12_IRQn, 1);
		break;
		case 0b10100:
			setbit(NVIC->ICER, 1, TIM8_UP_TIM13_IRQn, 1);
		break;
		case 0b10010:
			setbit(NVIC->ICER, 1, TIM8_TRG_COM_TIM14_IRQn, 1);
		break;
		case 0b10001:
			setbit(NVIC->ICER, 1, TIM8_CC_IRQn, 1);
		break;
	default:
	break;
	}
}

#endif

/*** TIM1 INIC Procedure & Function Definition ***/
STM32FXXXTIM1obj* tim1_enable(void)
{
	// CLOCK
	stm32fxxx_tim1.clock = STM32FXXXTim1Clock;
	// NVIC
	stm32fxxx_tim1.nvic = STM32FXXXTim1Nvic;
	/*** TIM1 Bit Field ***/
	stm32fxxx_tim1.handle = (STM32FXXXTIMXX_TypeDef*) TIM1;
	return &stm32fxxx_tim1;
}

STM32FXXXTIM1obj* tim1(void){ return (STM32FXXXTIM1obj*) &stm32fxxx_tim1;}

#ifdef STM32F446xx
/*** TIM8 INIC Procedure & Function Definition ***/
STM32FXXXTIM8obj* tim8_enable(void)
{
	// CLOCK
	stm32fxxx_tim8.clock = STM32FXXXTim8Clock;
	// NVIC
	stm32fxxx_tim8.nvic = STM32FXXXTim8Nvic;
	/*** TIM8 Bit Field ***/
	stm32fxxx_tim8.handle = (STM32FXXXTIMXX_TypeDef*) TIM8;
	return &stm32fxxx_tim8;
}

STM32FXXXTIM8obj* tim8(void){ return (STM32FXXXTIM8obj*) &stm32fxxx_tim8; }

#endif

/*** TIM1 CC IRQ Request ***/
void TIM1_CC_IRQHandler(void){

	if(tim1()->handle->sr.tim1and8_par.uif){
		tim1_u_callback();
		tim1()->handle->sr.tim1and8_par.uif = 0;
	}
	if(tim1()->handle->sr.tim1and8_par.cc1if){
		tim1_cc1_callback();
		tim1()->handle->sr.tim1and8_par.cc1if = 0;
	}
	if(tim1()->handle->sr.tim1and8_par.cc2if){
		tim1_cc2_callback();
		tim1()->handle->sr.tim1and8_par.cc2if = 0;
	}
	if(tim1()->handle->sr.tim1and8_par.tif){
		tim1_t_callback();
		tim1()->handle->sr.tim1and8_par.tif = 0;
	}
	if(tim1()->handle->sr.tim1and8_par.comif){
		tim1_com_callback();
		tim1()->handle->sr.tim1and8_par.comif = 0;
	}
	if(tim1()->handle->sr.tim1and8_par.bif){
		tim1_b_callback();
		tim1()->handle->sr.tim1and8_par.bif = 0;
	}
}
/***/

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
Instance->Reg->Par
******/

