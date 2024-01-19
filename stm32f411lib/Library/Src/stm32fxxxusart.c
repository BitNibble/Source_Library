/******************************************************************************
	STM32 XXX USART
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 19062023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxusart.h"
#include <math.h>

/*** File Variable ***/
static STM32FXXXUSART_SR stm32fxxx_usart1_sr;
static STM32FXXXUSART_BRR stm32fxxx_usart1_brr;
static STM32FXXXUSART_CR1 stm32fxxx_usart1_cr1;
static STM32FXXXUSART_CR2 stm32fxxx_usart1_cr2;
static STM32FXXXUSART_CR3 stm32fxxx_usart1_cr3;
static STM32FXXXUSART_GTPR stm32fxxx_usart1_gtpr;
static STM32FXXX_USART1 stm32fxxx_usart1;
static STM32FXXXUSART_SR stm32fxxx_usart2_sr;
static STM32FXXXUSART_BRR stm32fxxx_usart2_brr;
static STM32FXXXUSART_CR1 stm32fxxx_usart2_cr1;
static STM32FXXXUSART_CR2 stm32fxxx_usart2_cr2;
static STM32FXXXUSART_CR3 stm32fxxx_usart2_cr3;
static STM32FXXXUSART_GTPR stm32fxxx_usart2_gtpr;
static STM32FXXX_USART2 stm32fxxx_usart2;
static STM32FXXXUSART_SR stm32fxxx_usart3_sr;
static STM32FXXXUSART_BRR stm32fxxx_usart3_brr;
static STM32FXXXUSART_CR1 stm32fxxx_usart3_cr1;
static STM32FXXXUSART_CR2 stm32fxxx_usart3_cr2;
static STM32FXXXUSART_CR3 stm32fxxx_usart3_cr3;
static STM32FXXXUSART_GTPR stm32fxxx_usart3_gtpr;
static STM32FXXX_USART3 stm32fxxx_usart3;
static STM32FXXXUSART_SR stm32fxxx_uart4_sr;
static STM32FXXXUSART_BRR stm32fxxx_uart4_brr;
static STM32FXXXUSART_CR1 stm32fxxx_uart4_cr1;
static STM32FXXXUSART_CR2 stm32fxxx_uart4_cr2;
static STM32FXXXUSART_CR3 stm32fxxx_uart4_cr3;
static STM32FXXXUSART_GTPR stm32fxxx_uart4_gtpr;
static STM32FXXX_UART4 stm32fxxx_uart4;
static STM32FXXXUSART_SR stm32fxxx_uart5_sr;
static STM32FXXXUSART_BRR stm32fxxx_uart5_brr;
static STM32FXXXUSART_CR1 stm32fxxx_uart5_cr1;
static STM32FXXXUSART_CR2 stm32fxxx_uart5_cr2;
static STM32FXXXUSART_CR3 stm32fxxx_uart5_cr3;
static STM32FXXXUSART_GTPR stm32fxxx_uart5_gtpr;
static STM32FXXX_UART5 stm32fxxx_uart5;
static STM32FXXXUSART_SR stm32fxxx_usart6_sr;
static STM32FXXXUSART_BRR stm32fxxx_usart6_brr;
static STM32FXXXUSART_CR1 stm32fxxx_usart6_cr1;
static STM32FXXXUSART_CR2 stm32fxxx_usart6_cr2;
static STM32FXXXUSART_CR3 stm32fxxx_usart6_cr3;
static STM32FXXXUSART_GTPR stm32fxxx_usart6_gtpr;
static STM32FXXX_USART6 stm32fxxx_usart6;
/*** File Procedure & Function Header ***/
/******/
STM32FXXXUSART_SR* stm32fxxx_usart1_sr_inic(void);
STM32FXXXUSART_BRR* stm32fxxx_usart1_brr_inic(void);
STM32FXXXUSART_CR1* stm32fxxx_usart1_cr1_inic(void);
STM32FXXXUSART_CR2* stm32fxxx_usart1_cr2_inic(void);
STM32FXXXUSART_CR3* stm32fxxx_usart1_cr3_inic(void);
STM32FXXXUSART_GTPR* stm32fxxx_usart1_gtpr_inic(void);
STM32FXXXUSART_SR* stm32fxxx_usart2_sr_inic(void);
STM32FXXXUSART_BRR* stm32fxxx_usart2_brr_inic(void);
STM32FXXXUSART_CR1* stm32fxxx_usart2_cr1_inic(void);
STM32FXXXUSART_CR2* stm32fxxx_usart2_cr2_inic(void);
STM32FXXXUSART_CR3* stm32fxxx_usart2_cr3_inic(void);
STM32FXXXUSART_GTPR* stm32fxxx_usart2_gtpr_inic(void);
STM32FXXXUSART_SR* stm32fxxx_usart3_sr_inic(void);
STM32FXXXUSART_BRR* stm32fxxx_usart3_brr_inic(void);
STM32FXXXUSART_CR1* stm32fxxx_usart3_cr1_inic(void);
STM32FXXXUSART_CR2* stm32fxxx_usart3_cr2_inic(void);
STM32FXXXUSART_CR3* stm32fxxx_usart3_cr3_inic(void);
STM32FXXXUSART_GTPR* stm32fxxx_usart3_gtpr_inic(void);
STM32FXXXUSART_SR* stm32fxxx_uart4_sr_inic(void);
STM32FXXXUSART_BRR* stm32fxxx_uart4_brr_inic(void);
STM32FXXXUSART_CR1* stm32fxxx_uart4_cr1_inic(void);
STM32FXXXUSART_CR2* stm32fxxx_uart4_cr2_inic(void);
STM32FXXXUSART_CR3* stm32fxxx_uart4_cr3_inic(void);
STM32FXXXUSART_GTPR* stm32fxxx_uart4_gtpr_inic(void);
STM32FXXXUSART_SR* stm32fxxx_uart5_sr_inic(void);
STM32FXXXUSART_BRR* stm32fxxx_uart5_brr_inic(void);
STM32FXXXUSART_CR1* stm32fxxx_uart5_cr1_inic(void);
STM32FXXXUSART_CR2* stm32fxxx_uart5_cr2_inic(void);
STM32FXXXUSART_CR3* stm32fxxx_uart5_cr3_inic(void);
STM32FXXXUSART_GTPR* stm32fxxx_uart5_gtpr_inic(void);
STM32FXXXUSART_SR* stm32fxxx_usart6_sr_inic(void);
STM32FXXXUSART_BRR* stm32fxxx_usart6_brr_inic(void);
STM32FXXXUSART_CR1* stm32fxxx_usart6_cr1_inic(void);
STM32FXXXUSART_CR2* stm32fxxx_usart6_cr2_inic(void);
STM32FXXXUSART_CR3* stm32fxxx_usart6_cr3_inic(void);
STM32FXXXUSART_GTPR* stm32fxxx_usart6_gtpr_inic(void);
/*** USART Procedure & Function Definition ***/
/*** USART1 ***/
void STM32FXXXUsart1Clock( uint8_t bool )
{
	if(bool){ RCC->APB2ENR |= (1 << 4); }else{ RCC->APB2ENR &= ~(1 << 4); }
}
void STM32FXXXUsart1Nvic( uint8_t bool )
{
	if(bool){ setbit(NVIC->ISER, 1, USART1_IRQn, 1); }else{ setbit(NVIC->ICER, 1, USART1_IRQn, 1); }
}
void STM32FXXXUsart1Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate )
// Sets the usart parameters, using real values.
{
	uint8_t sampling;
	double value, fracpart, intpart;
	if(wordlength == 9)
		USART1->CR1 |= (1 << 12); // M: Word length, 1 - 9bit.
	else if(wordlength == 8)
		USART1->CR1 &= (uint32_t) ~(1 << 12); // M: Word length, 0 - 8bit.
	else
		USART1->CR1 &= (uint32_t) ~(1 << 12); // M: Word length, 0 - 8bit, default.
	if(samplingmode == 8){
		sampling = 8;
		USART1->CR1 |= (1 << 15); // OVER8: Oversampling mode, 1 - 8.
	}else if(samplingmode == 16){
		sampling = 16;
		USART1->CR1 &= (uint32_t) ~(1 << 15); // OVER8: Oversampling mode, 0 - 16.
	}else{
		sampling = 16;
		USART1->CR1 &= (uint32_t) ~(1 << 15); // OVER8: Oversampling mode, 0 - 16, default.
	}
	USART1->CR2 &= (uint32_t) ~((1 << 13) | (1 << 12)); // STOP: STOP bits 00 - 1stopbit, default.
	if(fabs(stopbits - 0.5) < 0.00001) // STOP: STOP bits, 01: 0.5 Stop bit
		USART1->CR2 |= (1 << 12);
	else if(fabs(stopbits - 1) < 0.00001) // STOP: STOP bits, 00: 1 Stop bit.
		USART1->CR2 &= (uint32_t) ~((1 << 13) | (1 << 12));
	else if(fabs(stopbits - 1.5) < 0.00001) // STOP: STOP bits, 11: 1.5 Stop bit
		USART1->CR2 |= ((1 << 13) | (1 << 12));
	else if(fabs(stopbits - 2) < 0.00001) // STOP: STOP bits, 10: 2 Stop bits
		USART1->CR2 |= (1 << 13);
	value = (double) getsysclk() / ( gethpre() * sampling * baudrate );
	fracpart = modf(value, &intpart);
	USART1->BRR = 0; // clean slate, reset.
	if(samplingmode == 16){
		USART1->BRR = (uint32_t) (round(fracpart * 16)); // DIV_Fraction
		USART1->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0]
	}else if(samplingmode == 8){
		USART1->BRR = (uint32_t) (round(fracpart * 8)); // DIV_Fraction
		USART1->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0]
	}else{
		USART1->BRR = (uint32_t) (round(fracpart * 16)); // DIV_Fraction
		USART1->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0], default.
	}
}
/*** USART 1 Bit Mapping ***/
// SR
uint8_t STM32FXXXUsart1_cts(void)
{
	return readreg(USART1->SR, 1, 9);
}
void STM32FXXXUsart1_clear_cts(void)
{
	setreg(&USART1->SR, 1, 9, 0);
}
uint8_t STM32FXXXUsart1_lbd(void)
{
	return readreg(USART1->SR, 1, 8);
}
void STM32FXXXUsart1_clear_lbd(void)
{
	setreg(&USART1->SR, 1, 8, 0);
}
uint8_t STM32FXXXUsart1_txe(void)
{
	return readreg(USART1->SR, 1, 7);
}
uint8_t STM32FXXXUsart1_tc(void)
{
	return readreg(USART1->SR, 1, 6);
}
void STM32FXXXUsart1_clear_tc(void)
{
	setreg(&USART1->SR, 1, 6, 0);
}
uint8_t STM32FXXXUsart1_rxne(void)
{
	return readreg(USART1->SR, 1, 5);
}
void STM32FXXXUsart1_clear_rxne(void)
{
	setreg(&USART1->SR, 1, 5, 0);
}
uint8_t STM32FXXXUsart1_idle(void)
{
	return readreg(USART1->SR, 1, 4);
}
uint8_t STM32FXXXUsart1_ore(void)
{
	return readreg(USART1->SR, 1, 3);
}
uint8_t STM32FXXXUsart1_nf(void)
{
	return readreg(USART1->SR, 1, 2);
}
uint8_t STM32FXXXUsart1_fe(void)
{
	return readreg(USART1->SR, 1, 1);
}
uint8_t STM32FXXXUsart1_pe(void)
{
	return readreg(USART1->SR, 1, 0);
}
// DR
void STM32FXXXUsart1_dr(uint32_t data)
{
	writereg(&USART1->DR, 9, 0, data);
}
uint32_t STM32FXXXUsart1_get_dr(void)
{
	return readreg(USART1->DR, 9, 0);
}
// BRR
void STM32FXXXUsart1_div_mantissa(uint16_t value)
{
	setreg(&USART1->BRR, 12, 4, value);
}
void STM32FXXXUsart1_div_fraction(uint8_t value)
{
	setreg(&USART1->BRR, 4, 0, value);
}
// CR1
void STM32FXXXUsart1_over8(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 15, bool);
}
void STM32FXXXUsart1_ue(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 13, bool);
}
void STM32FXXXUsart1_m(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 12, bool);
}
void STM32FXXXUsart1_wake(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 11, bool);
}
void STM32FXXXUsart1_pce(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 10, bool);
}
void STM32FXXXUsart1_ps(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 9, bool);
}
void STM32FXXXUsart1_peie(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 8, bool);
}
void STM32FXXXUsart1_txeie(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 7, bool);
}
void STM32FXXXUsart1_tcie(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 6, bool);
}
void STM32FXXXUsart1_rxneie(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 5, bool);
}
void STM32FXXXUsart1_idleie(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 4, bool);
}
void STM32FXXXUsart1_te(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 3, bool);
}
void STM32FXXXUsart1_re(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 2, bool);
}
void STM32FXXXUsart1_rwu(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 1, bool);
}
void STM32FXXXUsart1_sbk(uint8_t bool)
{
	setreg(&USART1->CR1, 1, 0, bool);
}
// CR2
void STM32FXXXUsart1_linen(uint8_t bool)
{
	setreg(&USART1->CR2, 1, 14, bool);
}
void STM32FXXXUsart1_stop(uint8_t value)
{
	setreg(&USART1->CR2, 2, 12, value);
}

void STM32FXXXUsart1_clken(uint8_t bool)
{
	setreg(&USART1->CR2, 1, 11, bool);
}
void STM32FXXXUsart1_cpol(uint8_t bool)
{
	setreg(&USART1->CR2, 1, 10, bool);
}
void STM32FXXXUsart1_cpha(uint8_t bool)
{
	setreg(&USART1->CR2, 1, 9, bool);
}
void STM32FXXXUsart1_lbcl(uint8_t bool)
{
	setreg(&USART1->CR2, 1, 8, bool);
}
void STM32FXXXUsart1_lbdie(uint8_t bool)
{
	setreg(&USART1->CR2, 1, 6, bool);
}
void STM32FXXXUsart1_lbdl(uint8_t bool)
{
	setreg(&USART1->CR2, 1, 5, bool);
}
void STM32FXXXUsart1_add(uint8_t value)
{
	setreg(&USART1->CR2, 4, 0, value);
}
// CR3
void STM32FXXXUsart1_onebit(uint8_t bool)
{
	setreg(&USART1->CR3, 1, 11, bool);
}
void STM32FXXXUsart1_ctsie(uint8_t bool)
{
	setreg(&USART1->CR3, 1, 10, bool);
}
void STM32FXXXUsart1_ctse(uint8_t bool)
{
	setreg(&USART1->CR3, 1, 9, bool);
}
void STM32FXXXUsart1_rtse(uint8_t bool)
{
	setreg(&USART1->CR3, 1, 8, bool);
}
void STM32FXXXUsart1_dmat(uint8_t bool)
{
	setreg(&USART1->CR3, 1, 7, bool);
}
void STM32FXXXUsart1_dmar(uint8_t bool)
{
	setreg(&USART1->CR3, 1, 6, bool);
}
void STM32FXXXUsart1_scen(uint8_t bool)
{
	setreg(&USART1->CR3, 1, 5, bool);
}
void STM32FXXXUsart1_nack(uint8_t bool)
{
	setreg(&USART1->CR3, 1, 4, bool);
}
void STM32FXXXUsart1_hdsel(uint8_t bool)
{
	setreg(&USART1->CR3, 1, 3, bool);
}
void STM32FXXXUsart1_irlp(uint8_t bool)
{
	setreg(&USART1->CR3, 1, 2, bool);
}
void STM32FXXXUsart1_iren(uint8_t bool)
{
	setreg(&USART1->CR3, 1, 1, bool);
}
void STM32FXXXUsart1_eie(uint8_t bool)
{
	setreg(&USART1->CR3, 1, 0, bool);
}
// GTPR
void STM32FXXXUsart1_gt(uint8_t value)
{
	setreg(&USART1->GTPR, 8, 8, value);
}
void STM32FXXXUsart1_psc(uint8_t value)
{
	setreg(&USART1->GTPR, 8, 0, value);
}
/*** USART2 ***/
void STM32FXXXUsart2Clock( uint8_t bool )
{
	if(bool){ RCC->APB1ENR |= (1 << 17); }else{ RCC->APB1ENR &= ~(1 << 17); }
}
void STM32FXXXUsart2Nvic( uint8_t bool )
{
	if(bool){ setbit(NVIC->ISER, 1, USART2_IRQn, 1); }else{ setbit(NVIC->ICER, 1, USART2_IRQn, 1); }
}
void STM32FXXXUsart2Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate )
// Sets the usart parameters, using real values.
{
	uint8_t sampling;
	double value, fracpart, intpart;
	if(wordlength == 9)
		USART2->CR1 |= (1 << 12); // M: Word length, 1 - 9bit.
	else if(wordlength == 8)
		USART2->CR1 &= (uint32_t) ~(1 << 12); // M: Word length, 0 - 8bit.
	else
		USART2->CR1 &= (uint32_t) ~(1 << 12); // M: Word length, 0 - 8bit, default.
	if(samplingmode == 8){
		sampling = 8;
		USART2->CR1 |= (1 << 15); // OVER8: Oversampling mode, 1 - 8.
	}else if(samplingmode == 16){
		sampling = 16;
		USART2->CR1 &= (uint32_t) ~(1 << 15); // OVER8: Oversampling mode, 0 - 16.
	}else{
		sampling = 16;
		USART2->CR1 &= (uint32_t) ~(1 << 15); // OVER8: Oversampling mode, 0 - 16, default.
	}
	USART2->CR2 &= (uint32_t) ~((1 << 13) | (1 << 12)); // STOP: STOP bits 00 - 1stopbit, default.
	if(fabs(stopbits - 0.5) < 0.00001) // STOP: STOP bits, 01: 0.5 Stop bit
		USART2->CR2 |= (1 << 12);
	else if(fabs(stopbits - 1) < 0.00001) // STOP: STOP bits, 00: 1 Stop bit.
		USART2->CR2 &= (uint32_t) ~((1 << 13) | (1 << 12));
	else if(fabs(stopbits - 1.5) < 0.00001) // STOP: STOP bits, 11: 1.5 Stop bit
		USART2->CR2 |= ((1 << 13) | (1 << 12));
	else if(fabs(stopbits - 2) < 0.00001) // STOP: STOP bits, 10: 2 Stop bits
		USART2->CR2 |= (1 << 13);
	value = (double) getsysclk() / ( gethpre() * sampling * baudrate );
	fracpart = modf(value, &intpart);
	USART2->BRR = 0; // clean slate, reset.
	if(samplingmode == 16){
		USART2->BRR = (uint32_t) (round(fracpart * 16)); // DIV_Fraction
		USART2->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0]
	}else if(samplingmode == 8){
		USART2->BRR = (uint32_t) (round(fracpart * 8)); // DIV_Fraction
		USART2->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0]
	}else{
		USART2->BRR = (uint32_t) (round(fracpart * 16)); // DIV_Fraction
		USART2->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0], default.
	}
}
/*** USART 2 Bit Mapping ***/
// SR
uint8_t STM32FXXXUsart2_cts(void)
{
	return readreg(USART2->SR, 1, 9);
}
void STM32FXXXUsart2_clear_cts(void)
{
	setreg(&USART2->SR, 1, 9, 0);
}
uint8_t STM32FXXXUsart2_lbd(void)
{
	return readreg(USART2->SR, 1, 8);
}
void STM32FXXXUsart2_clear_lbd(void)
{
	setreg(&USART2->SR, 1, 8, 0);
}
uint8_t STM32FXXXUsart2_txe(void)
{
	return readreg(USART2->SR, 1, 7);
}
uint8_t STM32FXXXUsart2_tc(void)
{
	return readreg(USART2->SR, 1, 6);
}
void STM32FXXXUsart2_clear_tc(void)
{
	setreg(&USART2->SR, 1, 6, 0);
}
uint8_t STM32FXXXUsart2_rxne(void)
{
	return readreg(USART2->SR, 1, 5);
}
void STM32FXXXUsart2_clear_rxne(void)
{
	setreg(&USART2->SR, 1, 5, 0);
}
uint8_t STM32FXXXUsart2_idle(void)
{
	return readreg(USART2->SR, 1, 4);
}
uint8_t STM32FXXXUsart2_ore(void)
{
	return readreg(USART2->SR, 1, 3);
}
uint8_t STM32FXXXUsart2_nf(void)
{
	return readreg(USART2->SR, 1, 2);
}
uint8_t STM32FXXXUsart2_fe(void)
{
	return readreg(USART2->SR, 1, 1);
}
uint8_t STM32FXXXUsart2_pe(void)
{
	return readreg(USART2->SR, 1, 0);
}
// DR
void STM32FXXXUsart2_dr(uint32_t data)
{
	writereg(&USART2->DR, 9, 0, data);
}
uint32_t STM32FXXXUsart2_get_dr(void)
{
	return readreg(USART2->DR, 9, 0);
}
// BRR
void STM32FXXXUsart2_div_mantissa(uint16_t value)
{
	setreg(&USART2->BRR, 12, 4, value);
}
void STM32FXXXUsart2_div_fraction(uint8_t value)
{
	setreg(&USART2->BRR, 4, 0, value);
}
// CR1
void STM32FXXXUsart2_over8(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 15, bool);
}
void STM32FXXXUsart2_ue(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 13, bool);
}
void STM32FXXXUsart2_m(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 12, bool);
}
void STM32FXXXUsart2_wake(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 11, bool);
}
void STM32FXXXUsart2_pce(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 10, bool);
}
void STM32FXXXUsart2_ps(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 9, bool);
}
void STM32FXXXUsart2_peie(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 8, bool);
}
void STM32FXXXUsart2_txeie(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 7, bool);
}
void STM32FXXXUsart2_tcie(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 6, bool);
}
void STM32FXXXUsart2_rxneie(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 5, bool);
}
void STM32FXXXUsart2_idleie(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 4, bool);
}
void STM32FXXXUsart2_te(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 3, bool);
}
void STM32FXXXUsart2_re(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 2, bool);
}
void STM32FXXXUsart2_rwu(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 1, bool);
}
void STM32FXXXUsart2_sbk(uint8_t bool)
{
	setreg(&USART2->CR1, 1, 0, bool);
}
// CR2
void STM32FXXXUsart2_linen(uint8_t bool)
{
	setreg(&USART2->CR2, 1, 14, bool);
}
void STM32FXXXUsart2_stop(uint8_t value)
{
	setreg(&USART2->CR2, 2, 12, value);
}
void STM32FXXXUsart2_clken(uint8_t bool)
{
	setreg(&USART2->CR2, 1, 11, bool);
}
void STM32FXXXUsart2_cpol(uint8_t bool)
{
	setreg(&USART2->CR2, 1, 10, bool);
}
void STM32FXXXUsart2_cpha(uint8_t bool)
{
	setreg(&USART2->CR2, 1, 9, bool);
}
void STM32FXXXUsart2_lbcl(uint8_t bool)
{
	setreg(&USART2->CR2, 1, 8, bool);
}
void STM32FXXXUsart2_lbdie(uint8_t bool)
{
	setreg(&USART2->CR2, 1, 6, bool);
}
void STM32FXXXUsart2_lbdl(uint8_t bool)
{
	setreg(&USART2->CR2, 1, 5, bool);
}
void STM32FXXXUsart2_add(uint8_t value)
{
	setreg(&USART2->CR2, 4, 0, value);
}
// CR3
void STM32FXXXUsart2_onebit(uint8_t bool)
{
	setreg(&USART2->CR3, 1, 11, bool);
}
void STM32FXXXUsart2_ctsie(uint8_t bool)
{
	setreg(&USART2->CR3, 1, 10, bool);
}
void STM32FXXXUsart2_ctse(uint8_t bool)
{
	setreg(&USART2->CR3, 1, 9, bool);
}
void STM32FXXXUsart2_rtse(uint8_t bool)
{
	setreg(&USART2->CR3, 1, 8, bool);
}
void STM32FXXXUsart2_dmat(uint8_t bool)
{
	setreg(&USART2->CR3, 1, 7, bool);
}
void STM32FXXXUsart2_dmar(uint8_t bool)
{
	setreg(&USART2->CR3, 1, 6, bool);
}
void STM32FXXXUsart2_scen(uint8_t bool)
{
	setreg(&USART2->CR3, 1, 5, bool);
}
void STM32FXXXUsart2_nack(uint8_t bool)
{
	setreg(&USART2->CR3, 1, 4, bool);
}
void STM32FXXXUsart2_hdsel(uint8_t bool)
{
	setreg(&USART2->CR3, 1, 3, bool);
}
void STM32FXXXUsart2_irlp(uint8_t bool)
{
	setreg(&USART2->CR3, 1, 2, bool);
}
void STM32FXXXUsart2_iren(uint8_t bool)
{
	setreg(&USART2->CR3, 1, 1, bool);
}
void STM32FXXXUsart2_eie(uint8_t bool)
{
	setreg(&USART2->CR3, 1, 0, bool);
}
// GTPR
void STM32FXXXUsart2_gt(uint8_t value)
{
	setreg(&USART2->GTPR, 8, 8, value);
}
void STM32FXXXUsart2_psc(uint8_t value)
{
	setreg(&USART2->GTPR, 8, 0, value);
}
#ifdef STM32F446xx
/*** USART3 ***/
void STM32FXXXUsart3Clock( uint8_t bool )
{
	if(bool){ RCC->APB1ENR |= (1 << 18); }else{ RCC->APB1ENR &= ~(1 << 18); }
}
void STM32FXXXUsart3Nvic( uint8_t bool )
{
	if(bool){ setbit(NVIC->ISER, 1, USART3_IRQn, 1); }else{ setbit(NVIC->ICER, 1, USART3_IRQn, 1); }
}
void STM32FXXXUsart3Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate )
// Sets the usart parameters, using real values.
{
	uint8_t sampling;
	double value, fracpart, intpart;
	if(wordlength == 9)
		USART3->CR1 |= (1 << 12); // M: Word length, 1 - 9bit.
	else if(wordlength == 8)
		USART3->CR1 &= (uint32_t) ~(1 << 12); // M: Word length, 0 - 8bit.
	else
		USART3->CR1 &= (uint32_t) ~(1 << 12); // M: Word length, 0 - 8bit, default.
	if(samplingmode == 8){
		sampling = 8;
		USART3->CR1 |= (1 << 15); // OVER8: Oversampling mode, 1 - 8.
	}else if(samplingmode == 16){
		sampling = 16;
		USART3->CR1 &= (uint32_t) ~(1 << 15); // OVER8: Oversampling mode, 0 - 16.
	}else{
		sampling = 16;
		USART3->CR1 &= (uint32_t) ~(1 << 15); // OVER8: Oversampling mode, 0 - 16, default.
	}
	USART3->CR2 &= (uint32_t) ~((1 << 13) | (1 << 12)); // STOP: STOP bits 00 - 1stopbit, default.
	if(fabs(stopbits - 0.5) < 0.00001) // STOP: STOP bits, 01: 0.5 Stop bit
		USART3->CR2 |= (1 << 12);
	else if(fabs(stopbits - 1) < 0.00001) // STOP: STOP bits, 00: 1 Stop bit.
		USART3->CR2 &= (uint32_t) ~((1 << 13) | (1 << 12));
	else if(fabs(stopbits - 1.5) < 0.00001) // STOP: STOP bits, 11: 1.5 Stop bit
		USART3->CR2 |= ((1 << 13) | (1 << 12));
	else if(fabs(stopbits - 2) < 0.00001) // STOP: STOP bits, 10: 2 Stop bits
		USART3->CR2 |= (1 << 13);
	value = (double) getsysclk() / ( gethpre() * sampling * baudrate );
	fracpart = modf(value, &intpart);
	USART3->BRR = 0; // clean slate, reset.
	if(samplingmode == 16){
		USART3->BRR = (uint32_t) (round(fracpart * 16)); // DIV_Fraction
		USART3->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0]
	}else if(samplingmode == 8){
		USART3->BRR = (uint32_t) (round(fracpart * 8)); // DIV_Fraction
		USART3->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0]
	}else{
		USART3->BRR = (uint32_t) (round(fracpart * 16)); // DIV_Fraction
		USART3->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0], default.
	}
}
/*** USART 3 Bit Mapping ***/
// SR
uint8_t STM32FXXXUsart3_cts(void)
{
	return readreg(USART3->SR, 1, 9);
}
void STM32FXXXUsart3_clear_cts(void)
{
	setreg(&USART3->SR, 1, 9, 0);
}
uint8_t STM32FXXXUsart3_lbd(void)
{
	return readreg(USART3->SR, 1, 8);
}
void STM32FXXXUsart3_clear_lbd(void)
{
	setreg(&USART3->SR, 1, 8, 0);
}
uint8_t STM32FXXXUsart3_txe(void)
{
	return readreg(USART3->SR, 1, 7);
}
uint8_t STM32FXXXUsart3_tc(void)
{
	return readreg(USART3->SR, 1, 6);
}
void STM32FXXXUsart3_clear_tc(void)
{
	setreg(&USART3->SR, 1, 6, 0);
}
uint8_t STM32FXXXUsart3_rxne(void)
{
	return readreg(USART3->SR, 1, 5);
}
void STM32FXXXUsart3_clear_rxne(void)
{
	setreg(&USART3->SR, 1, 5, 0);
}
uint8_t STM32FXXXUsart3_idle(void)
{
	return readreg(USART3->SR, 1, 4);
}
uint8_t STM32FXXXUsart3_ore(void)
{
	return readreg(USART3->SR, 1, 3);
}
uint8_t STM32FXXXUsart3_nf(void)
{
	return readreg(USART3->SR, 1, 2);
}
uint8_t STM32FXXXUsart3_fe(void)
{
	return readreg(USART3->SR, 1, 1);
}
uint8_t STM32FXXXUsart3_pe(void)
{
	return readreg(USART3->SR, 1, 0);
}
// DR
void STM32FXXXUsart3_dr(uint32_t data)
{
	writereg(&USART3->DR, 9, 0, data);
}
uint32_t STM32FXXXUsart3_get_dr(void)
{
	return readreg(USART3->DR, 9, 0);
}
// BRR
void STM32FXXXUsart3_div_mantissa(uint16_t value)
{
	setreg(&USART3->BRR, 12, 4, value);
}
void STM32FXXXUsart3_div_fraction(uint8_t value)
{
	setreg(&USART3->BRR, 4, 0, value);
}
// CR1
void STM32FXXXUsart3_over8(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 15, bool);
}
void STM32FXXXUsart3_ue(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 13, bool);
}
void STM32FXXXUsart3_m(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 12, bool);
}
void STM32FXXXUsart3_wake(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 11, bool);
}
void STM32FXXXUsart3_pce(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 10, bool);
}
void STM32FXXXUsart3_ps(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 9, bool);
}
void STM32FXXXUsart3_peie(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 8, bool);
}
void STM32FXXXUsart3_txeie(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 7, bool);
}
void STM32FXXXUsart3_tcie(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 6, bool);
}
void STM32FXXXUsart3_rxneie(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 5, bool);
}
void STM32FXXXUsart3_idleie(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 4, bool);
}
void STM32FXXXUsart3_te(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 3, bool);
}
void STM32FXXXUsart3_re(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 2, bool);
}
void STM32FXXXUsart3_rwu(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 1, bool);
}
void STM32FXXXUsart3_sbk(uint8_t bool)
{
	setreg(&USART3->CR1, 1, 0, bool);
}
// CR2
void STM32FXXXUsart3_linen(uint8_t bool)
{
	setreg(&USART3->CR2, 1, 14, bool);
}
void STM32FXXXUsart3_stop(uint8_t value)
{
	setreg(&USART3->CR2, 2, 12, value);
}
void STM32FXXXUsart3_clken(uint8_t bool)
{
	setreg(&USART3->CR2, 1, 11, bool);
}
void STM32FXXXUsart3_cpol(uint8_t bool)
{
	setreg(&USART3->CR2, 1, 10, bool);
}
void STM32FXXXUsart3_cpha(uint8_t bool)
{
	setreg(&USART3->CR2, 1, 9, bool);
}
void STM32FXXXUsart3_lbcl(uint8_t bool)
{
	setreg(&USART3->CR2, 1, 8, bool);
}
void STM32FXXXUsart3_lbdie(uint8_t bool)
{
	setreg(&USART3->CR2, 1, 6, bool);
}
void STM32FXXXUsart3_lbdl(uint8_t bool)
{
	setreg(&USART3->CR2, 1, 5, bool);
}
void STM32FXXXUsart3_add(uint8_t value)
{
	setreg(&USART3->CR2, 4, 0, value);
}
// CR3
void STM32FXXXUsart3_onebit(uint8_t bool)
{
	setreg(&USART3->CR3, 1, 11, bool);
}
void STM32FXXXUsart3_ctsie(uint8_t bool)
{
	setreg(&USART3->CR3, 1, 10, bool);
}
void STM32FXXXUsart3_ctse(uint8_t bool)
{
	setreg(&USART3->CR3, 1, 9, bool);
}
void STM32FXXXUsart3_rtse(uint8_t bool)
{
	setreg(&USART3->CR3, 1, 8, bool);
}
void STM32FXXXUsart3_dmat(uint8_t bool)
{
	setreg(&USART3->CR3, 1, 7, bool);
}
void STM32FXXXUsart3_dmar(uint8_t bool)
{
	setreg(&USART3->CR3, 1, 6, bool);
}
void STM32FXXXUsart3_scen(uint8_t bool)
{
	setreg(&USART3->CR3, 1, 5, bool);
}
void STM32FXXXUsart3_nack(uint8_t bool)
{
	setreg(&USART3->CR3, 1, 4, bool);
}
void STM32FXXXUsart3_hdsel(uint8_t bool)
{
	setreg(&USART3->CR3, 1, 3, bool);
}
void STM32FXXXUsart3_irlp(uint8_t bool)
{
	setreg(&USART3->CR3, 1, 2, bool);
}
void STM32FXXXUsart3_iren(uint8_t bool)
{
	setreg(&USART3->CR3, 1, 1, bool);
}
void STM32FXXXUsart3_eie(uint8_t bool)
{
	setreg(&USART3->CR3, 1, 0, bool);
}
// GTPR
void STM32FXXXUsart3_gt(uint8_t value)
{
	setreg(&USART3->GTPR, 8, 8, value);
}
void STM32FXXXUsart3_psc(uint8_t value)
{
	setreg(&USART3->GTPR, 8, 0, value);
}
/*** UART4 ***/
void STM32FXXXUart4Clock( uint8_t bool )
{
	if(bool){ RCC->APB1ENR |= (1 << 19); }else{ RCC->APB1ENR &= ~(1 << 19); }

}
void STM32FXXXUart4Nvic( uint8_t bool )
{
	if(bool){ setbit(NVIC->ISER, 1, UART4_IRQn, 1); }else{ setbit(NVIC->ICER, 1, UART4_IRQn, 1); }
}
void STM32FXXXUart4Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate )
// Sets the uart parameters, using real values.
{
	uint8_t sampling;
	double value, fracpart, intpart;
	if(wordlength == 9)
		UART4->CR1 |= (1 << 12); // M: Word length, 1 - 9bit.
	else if(wordlength == 8)
		UART4->CR1 &= (uint32_t) ~(1 << 12); // M: Word length, 0 - 8bit.
	else
		UART4->CR1 &= (uint32_t) ~(1 << 12); // M: Word length, 0 - 8bit, default.
	if(samplingmode == 8){
		sampling = 8;
		UART4->CR1 |= (1 << 15); // OVER8: Oversampling mode, 1 - 8.
	}else if(samplingmode == 16){
		sampling = 16;
		UART4->CR1 &= (uint32_t) ~(1 << 15); // OVER8: Oversampling mode, 0 - 16.
	}else{
		sampling = 16;
		UART4->CR1 &= (uint32_t) ~(1 << 15); // OVER8: Oversampling mode, 0 - 16, default.
	}
	UART4->CR2 &= (uint32_t) ~((1 << 13) | (1 << 12)); // STOP: STOP bits 00 - 1stopbit, default.
	if(fabs(stopbits - 0.5) < 0.00001) // STOP: STOP bits, 01: 0.5 Stop bit
		UART4->CR2 |= (1 << 12);
	else if(fabs(stopbits - 1) < 0.00001) // STOP: STOP bits, 00: 1 Stop bit.
		UART4->CR2 &= (uint32_t) ~((1 << 13) | (1 << 12));
	else if(fabs(stopbits - 1.5) < 0.00001) // STOP: STOP bits, 11: 1.5 Stop bit
		UART4->CR2 |= ((1 << 13) | (1 << 12));
	else if(fabs(stopbits - 2) < 0.00001) // STOP: STOP bits, 10: 2 Stop bits
		UART4->CR2 |= (1 << 13);
	value = (double) getsysclk() / ( gethpre() * sampling * baudrate );
	fracpart = modf(value, &intpart);
	UART4->BRR = 0; // clean slate, reset.
	if(samplingmode == 16){
		UART4->BRR = (uint32_t) (round(fracpart * 16)); // DIV_Fraction
		UART4->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0]
	}else if(samplingmode == 8){
		UART4->BRR = (uint32_t) (round(fracpart * 8)); // DIV_Fraction
		UART4->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0]
	}else{
		UART4->BRR = (uint32_t) (round(fracpart * 16)); // DIV_Fraction
		UART4->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0], default.
	}
}
/*** UART 4 Bit Mapping ***/
// SR
uint8_t STM32FXXXUart4_cts(void)
{
	return readreg(UART4->SR, 1, 9);
}
void STM32FXXXUart4_clear_cts(void)
{
	setreg(&UART4->SR, 1, 9, 0);
}
uint8_t STM32FXXXUart4_lbd(void)
{
	return readreg(UART4->SR, 1, 8);
}
void STM32FXXXUart4_clear_lbd(void)
{
	setreg(&UART4->SR, 1, 8, 0);
}
uint8_t STM32FXXXUart4_txe(void)
{
	return readreg(UART4->SR, 1, 7);
}
uint8_t STM32FXXXUart4_tc(void)
{
	return readreg(UART4->SR, 1, 6);
}
void STM32FXXXUart4_clear_tc(void)
{
	setreg(&UART4->SR, 1, 6, 0);
}
uint8_t STM32FXXXUart4_rxne(void)
{
	return readreg(UART4->SR, 1, 5);
}
void STM32FXXXUart4_clear_rxne(void)
{
	setreg(&UART4->SR, 1, 5, 0);
}
uint8_t STM32FXXXUart4_idle(void)
{
	return readreg(UART4->SR, 1, 4);
}
uint8_t STM32FXXXUart4_ore(void)
{
	return readreg(UART4->SR, 1, 3);
}
uint8_t STM32FXXXUart4_nf(void)
{
	return readreg(UART4->SR, 1, 2);
}
uint8_t STM32FXXXUart4_fe(void)
{
	return readreg(UART4->SR, 1, 1);
}
uint8_t STM32FXXXUart4_pe(void)
{
	return readreg(UART4->SR, 1, 0);
}
// DR
void STM32FXXXUart4_dr(uint32_t data)
{
	writereg(&UART4->DR, 9, 0, data);
}
uint32_t STM32FXXXUart4_get_dr(void)
{
	return readreg(UART4->DR, 9, 0);
}
// BRR
void STM32FXXXUart4_div_mantissa(uint16_t value)
{
	setreg(&UART4->BRR, 12, 4, value);
}
void STM32FXXXUart4_div_fraction(uint8_t value)
{
	setreg(&UART4->BRR, 4, 0, value);
}
// CR1
void STM32FXXXUart4_over8(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 15, bool);
}
void STM32FXXXUart4_ue(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 13, bool);
}
void STM32FXXXUart4_m(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 12, bool);
}
void STM32FXXXUart4_wake(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 11, bool);
}
void STM32FXXXUart4_pce(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 10, bool);
}
void STM32FXXXUart4_ps(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 9, bool);
}
void STM32FXXXUart4_peie(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 8, bool);
}
void STM32FXXXUart4_txeie(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 7, bool);
}
void STM32FXXXUart4_tcie(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 6, bool);
}
void STM32FXXXUart4_rxneie(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 5, bool);
}
void STM32FXXXUart4_idleie(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 4, bool);
}
void STM32FXXXUart4_te(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 3, bool);
}
void STM32FXXXUart4_re(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 2, bool);
}
void STM32FXXXUart4_rwu(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 1, bool);
}
void STM32FXXXUart4_sbk(uint8_t bool)
{
	setreg(&UART4->CR1, 1, 0, bool);
}
// CR2
void STM32FXXXUart4_linen(uint8_t bool)
{
	setreg(&UART4->CR2, 1, 14, bool);
}
void STM32FXXXUart4_stop(uint8_t value)
{
	setreg(&UART4->CR2, 2, 12, value);
}
void STM32FXXXUart4_clken(uint8_t bool)
{
	setreg(&UART4->CR2, 1, 11, bool);
}
void STM32FXXXUart4_cpol(uint8_t bool)
{
	setreg(&UART4->CR2, 1, 10, bool);
}
void STM32FXXXUart4_cpha(uint8_t bool)
{
	setreg(&UART4->CR2, 1, 9, bool);
}
void STM32FXXXUart4_lbcl(uint8_t bool)
{
	setreg(&UART4->CR2, 1, 8, bool);
}
void STM32FXXXUart4_lbdie(uint8_t bool)
{
	setreg(&UART4->CR2, 1, 6, bool);
}
void STM32FXXXUart4_lbdl(uint8_t bool)
{
	setreg(&UART4->CR2, 1, 5, bool);
}
void STM32FXXXUart4_add(uint8_t value)
{
	setreg(&UART4->CR2, 4, 0, value);
}
// CR3
void STM32FXXXUart4_onebit(uint8_t bool)
{
	setreg(&UART4->CR3, 1, 11, bool);
}
void STM32FXXXUart4_ctsie(uint8_t bool)
{
	setreg(&UART4->CR3, 1, 10, bool);
}
void STM32FXXXUart4_ctse(uint8_t bool)
{
	setreg(&UART4->CR3, 1, 9, bool);
}
void STM32FXXXUart4_rtse(uint8_t bool)
{
	setreg(&UART4->CR3, 1, 8, bool);
}
void STM32FXXXUart4_dmat(uint8_t bool)
{
	setreg(&UART4->CR3, 1, 7, bool);
}
void STM32FXXXUart4_dmar(uint8_t bool)
{
	setreg(&UART4->CR3, 1, 6, bool);
}
void STM32FXXXUart4_scen(uint8_t bool)
{
	setreg(&UART4->CR3, 1, 5, bool);
}
void STM32FXXXUart4_nack(uint8_t bool)
{
	setreg(&UART4->CR3, 1, 4, bool);
}
void STM32FXXXUart4_hdsel(uint8_t bool)
{
	setreg(&UART4->CR3, 1, 3, bool);
}
void STM32FXXXUart4_irlp(uint8_t bool)
{
	setreg(&UART4->CR3, 1, 2, bool);
}
void STM32FXXXUart4_iren(uint8_t bool)
{
	setreg(&UART4->CR3, 1, 1, bool);
}
void STM32FXXXUart4_eie(uint8_t bool)
{
	setreg(&UART4->CR3, 1, 0, bool);
}
// GTPR
void STM32FXXXUart4_gt(uint8_t value)
{
	setreg(&UART4->GTPR, 8, 8, value);
}
void STM32FXXXUart4_psc(uint8_t value)
{
	setreg(&UART4->GTPR, 8, 0, value);
}
/*** UART5 ***/
void STM32FXXXUart5Clock( uint8_t bool )
{
	if(bool){ RCC->APB1ENR |= (1 << 20); } // UART5EN: USART5 clock enable
	else{ RCC->APB1ENR &= ~(1 << 20); } // UART5EN: USART5 clock disable
}
void STM32FXXXUart5Nvic( uint8_t bool )
{
	if(bool){ setbit(NVIC->ISER, 1, UART5_IRQn, 1); }else{ setbit(NVIC->ICER, 1, UART5_IRQn, 1); }
}
void STM32FXXXUart5Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate )
// Sets the uart parameters, using real values.
{
	uint8_t sampling;
	double value, fracpart, intpart;
	if(wordlength == 9)
		UART5->CR1 |= (1 << 12); // M: Word length, 1 - 9bit.
	else if(wordlength == 8)
		UART5->CR1 &= (uint32_t) ~(1 << 12); // M: Word length, 0 - 8bit.
	else
		UART5->CR1 &= (uint32_t) ~(1 << 12); // M: Word length, 0 - 8bit, default.
	if(samplingmode == 8){
		sampling = 8;
		UART5->CR1 |= (1 << 15); // OVER8: Oversampling mode, 1 - 8.
	}else if(samplingmode == 16){
		sampling = 16;
		UART5->CR1 &= (uint32_t) ~(1 << 15); // OVER8: Oversampling mode, 0 - 16.
	}else{
		sampling = 16;
		UART5->CR1 &= (uint32_t) ~(1 << 15); // OVER8: Oversampling mode, 0 - 16, default.
	}
	UART5->CR2 &= (uint32_t) ~((1 << 13) | (1 << 12)); // STOP: STOP bits 00 - 1stopbit, default.
	if(fabs(stopbits - 0.5) < 0.00001) // STOP: STOP bits, 01: 0.5 Stop bit
		UART5->CR2 |= (1 << 12);
	else if(fabs(stopbits - 1) < 0.00001) // STOP: STOP bits, 00: 1 Stop bit.
		UART5->CR2 &= (uint32_t) ~((1 << 13) | (1 << 12));
	else if(fabs(stopbits - 1.5) < 0.00001) // STOP: STOP bits, 11: 1.5 Stop bit
		UART5->CR2 |= ((1 << 13) | (1 << 12));
	else if(fabs(stopbits - 2) < 0.00001) // STOP: STOP bits, 10: 2 Stop bits
		UART5->CR2 |= (1 << 13);
	value = (double) getsysclk() / ( gethpre() * sampling * baudrate );
	fracpart = modf(value, &intpart);
	UART5->BRR = 0; // clean slate, reset.
	if(samplingmode == 16){
		UART5->BRR = (uint32_t) (round(fracpart * 16)); // DIV_Fraction
		UART5->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0]
	}else if(samplingmode == 8){
		UART5->BRR = (uint32_t) (round(fracpart * 8)); // DIV_Fraction
		UART5->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0]
	}else{
		UART5->BRR = (uint32_t) (round(fracpart * 16)); // DIV_Fraction
		UART5->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0], default.
	}
}
/*** UART 5 Bit Mapping ***/
// SR
uint8_t STM32FXXXUart5_cts(void)
{
	return readreg(UART5->SR, 1, 9);
}
void STM32FXXXUart5_clear_cts(void)
{
	setreg(&UART5->SR, 1, 9, 0);
}
uint8_t STM32FXXXUart5_lbd(void)
{
	return readreg(UART5->SR, 1, 8);
}
void STM32FXXXUart5_clear_lbd(void)
{
	setreg(&UART5->SR, 1, 8, 0);
}
uint8_t STM32FXXXUart5_txe(void)
{
	return readreg(UART5->SR, 1, 7);
}
uint8_t STM32FXXXUart5_tc(void)
{
	return readreg(UART5->SR, 1, 6);
}
void STM32FXXXUart5_clear_tc(void)
{
	setreg(&UART5->SR, 1, 6, 0);
}
uint8_t STM32FXXXUart5_rxne(void)
{
	return readreg(UART5->SR, 1, 5);
}
void STM32FXXXUart5_clear_rxne(void)
{
	setreg(&UART5->SR, 1, 5, 0);
}
uint8_t STM32FXXXUart5_idle(void)
{
	return readreg(UART5->SR, 1, 4);
}
uint8_t STM32FXXXUart5_ore(void)
{
	return readreg(UART5->SR, 1, 3);
}
uint8_t STM32FXXXUart5_nf(void)
{
	return readreg(UART5->SR, 1, 2);
}
uint8_t STM32FXXXUart5_fe(void)
{
	return readreg(UART5->SR, 1, 1);
}
uint8_t STM32FXXXUart5_pe(void)
{
	return readreg(UART5->SR, 1, 0);
}
// DR
void STM32FXXXUart5_dr(uint32_t data)
{
	writereg(&UART5->DR, 9, 0, data);
}
uint32_t STM32FXXXUart5_get_dr(void)
{
	return readreg(UART5->DR, 9, 0);
}
// BRR
void STM32FXXXUart5_div_mantissa(uint16_t value)
{
	setreg(&UART5->BRR, 12, 4, value);
}
void STM32FXXXUart5_div_fraction(uint8_t value)
{
	setreg(&UART5->BRR, 4, 0, value);
}
// CR1
void STM32FXXXUart5_over8(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 15, bool);
}
void STM32FXXXUart5_ue(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 13, bool);
}
void STM32FXXXUart5_m(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 12, bool);
}
void STM32FXXXUart5_wake(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 11, bool);
}
void STM32FXXXUart5_pce(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 10, bool);
}
void STM32FXXXUart5_ps(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 9, bool);
}
void STM32FXXXUart5_peie(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 8, bool);
}
void STM32FXXXUart5_txeie(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 7, bool);
}
void STM32FXXXUart5_tcie(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 6, bool);
}
void STM32FXXXUart5_rxneie(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 5, bool);
}
void STM32FXXXUart5_idleie(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 4, bool);
}
void STM32FXXXUart5_te(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 3, bool);
}
void STM32FXXXUart5_re(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 2, bool);
}
void STM32FXXXUart5_rwu(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 1, bool);
}
void STM32FXXXUart5_sbk(uint8_t bool)
{
	setreg(&UART5->CR1, 1, 0, bool);
}
// CR2
void STM32FXXXUart5_linen(uint8_t bool)
{
	setreg(&UART5->CR2, 1, 14, bool);
}
void STM32FXXXUart5_stop(uint8_t value)
{
	setreg(&UART5->CR2, 2, 12, value);
}
void STM32FXXXUart5_clken(uint8_t bool)
{
	setreg(&UART5->CR2, 1, 11, bool);
}
void STM32FXXXUart5_cpol(uint8_t bool)
{
	setreg(&UART5->CR2, 1, 10, bool);
}
void STM32FXXXUart5_cpha(uint8_t bool)
{
	setreg(&UART5->CR2, 1, 9, bool);
}
void STM32FXXXUart5_lbcl(uint8_t bool)
{
	setreg(&UART5->CR2, 1, 8, bool);
}
void STM32FXXXUart5_lbdie(uint8_t bool)
{
	setreg(&UART5->CR2, 1, 6, bool);
}
void STM32FXXXUart5_lbdl(uint8_t bool)
{
	setreg(&UART5->CR2, 1, 5, bool);
}
void STM32FXXXUart5_add(uint8_t value)
{
	setreg(&UART5->CR2, 4, 0, value);
}
// CR3
void STM32FXXXUart5_onebit(uint8_t bool)
{
	setreg(&UART5->CR3, 1, 11, bool);
}
void STM32FXXXUart5_ctsie(uint8_t bool)
{
	setreg(&UART5->CR3, 1, 10, bool);
}
void STM32FXXXUart5_ctse(uint8_t bool)
{
	setreg(&UART5->CR3, 1, 9, bool);
}
void STM32FXXXUart5_rtse(uint8_t bool)
{
	setreg(&UART5->CR3, 1, 8, bool);
}
void STM32FXXXUart5_dmat(uint8_t bool)
{
	setreg(&UART5->CR3, 1, 7, bool);
}
void STM32FXXXUart5_dmar(uint8_t bool)
{
	setreg(&UART5->CR3, 1, 6, bool);
}
void STM32FXXXUart5_scen(uint8_t bool)
{
	setreg(&UART5->CR3, 1, 5, bool);
}
void STM32FXXXUart5_nack(uint8_t bool)
{
	setreg(&UART5->CR3, 1, 4, bool);
}
void STM32FXXXUart5_hdsel(uint8_t bool)
{
	setreg(&UART5->CR3, 1, 3, bool);
}
void STM32FXXXUart5_irlp(uint8_t bool)
{
	setreg(&UART5->CR3, 1, 2, bool);
}
void STM32FXXXUart5_iren(uint8_t bool)
{
	setreg(&UART5->CR3, 1, 1, bool);
}
void STM32FXXXUart5_eie(uint8_t bool)
{
	setreg(&UART5->CR3, 1, 0, bool);
}
// GTPR
void STM32FXXXUart5_gt(uint8_t value)
{
	setreg(&UART5->GTPR, 8, 8, value);
}
void STM32FXXXUart5_psc(uint8_t value)
{
	setreg(&UART5->GTPR, 8, 0, value);
}
#endif
/*** USART6 ***/
void STM32FXXXUsart6Clock( uint8_t bool )
{
	if(bool){ RCC->APB2ENR |= (1 << 5); }else{ RCC->APB2ENR &= ~(1 << 5); }
}
void STM32FXXXUsart6Nvic( uint8_t bool )
{
	if(bool){ setbit(NVIC->ISER, 1, USART6_IRQn, 1); }else{ setbit(NVIC->ICER, 1, USART6_IRQn, 1); }
}
void STM32FXXXUsart6Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate )
// Sets the usart parameters, using real values.
{
	uint8_t sampling;
	double value, fracpart, intpart;
	if(wordlength == 9)
		USART6->CR1 |= (1 << 12); // M: Word length, 1 - 9bit.
	else if(wordlength == 8)
		USART6->CR1 &= (uint32_t) ~(1 << 12); // M: Word length, 0 - 8bit.
	else
		USART6->CR1 &= (uint32_t) ~(1 << 12); // M: Word length, 0 - 8bit, default.
	if(samplingmode == 8){
		sampling = 8;
		USART6->CR1 |= (1 << 15); // OVER8: Oversampling mode, 1 - 8.
	}else if(samplingmode == 16){
		sampling = 16;
		USART6->CR1 &= (uint32_t) ~(1 << 15); // OVER8: Oversampling mode, 0 - 16.
	}else{
		sampling = 16;
		USART6->CR1 &= (uint32_t) ~(1 << 15); // OVER8: Oversampling mode, 0 - 16, default.
	}
	USART6->CR2 &= (uint32_t) ~((1 << 13) | (1 << 12)); // STOP: STOP bits 00 - 1stopbit, default.
	if(fabs(stopbits - 0.5) < 0.00001) // STOP: STOP bits, 01: 0.5 Stop bit
		USART6->CR2 |= (1 << 12);
	else if(fabs(stopbits - 1) < 0.00001) // STOP: STOP bits, 00: 1 Stop bit.
		USART6->CR2 &= (uint32_t) ~((1 << 13) | (1 << 12));
	else if(fabs(stopbits - 1.5) < 0.00001) // STOP: STOP bits, 11: 1.5 Stop bit
		USART6->CR2 |= ((1 << 13) | (1 << 12));
	else if(fabs(stopbits - 2) < 0.00001) // STOP: STOP bits, 10: 2 Stop bits
		USART6->CR2 |= (1 << 13);
	value = (double) getsysclk() / ( gethpre() * sampling * baudrate );
	fracpart = modf(value, &intpart);
	USART6->BRR = 0; // clean slate, reset.
	if(samplingmode == 16){
		USART6->BRR = (uint32_t) (round(fracpart * 16)); // DIV_Fraction
		USART6->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0]
	}else if(samplingmode == 8){
		USART6->BRR = (uint32_t) (round(fracpart * 8)); // DIV_Fraction
		USART6->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0]
	}else{
		USART6->BRR = (uint32_t) (round(fracpart * 16)); // DIV_Fraction
		USART6->BRR |= ((uint32_t) intpart << 4); // DIV_Mantissa[11:0], default.
	}
}
/*** USART 6 Bit Mapping ***/
// SR
uint8_t STM32FXXXUsart6_cts(void)
{
	return readreg(USART6->SR, 1, 9);
}
void STM32FXXXUsart6_clear_cts(void)
{
	setreg(&USART6->SR, 1, 9, 0);
}
uint8_t STM32FXXXUsart6_lbd(void)
{
	return readreg(USART6->SR, 1, 8);
}
void STM32FXXXUsart6_clear_lbd(void)
{
	setreg(&USART6->SR, 1, 8, 0);
}
uint8_t STM32FXXXUsart6_txe(void)
{
	return readreg(USART6->SR, 1, 7);
}
uint8_t STM32FXXXUsart6_tc(void)
{
	return readreg(USART6->SR, 1, 6);
}
void STM32FXXXUsart6_clear_tc(void)
{
	setreg(&USART6->SR, 1, 6, 0);
}
uint8_t STM32FXXXUsart6_rxne(void)
{
	return readreg(USART6->SR, 1, 5);
}
void STM32FXXXUsart6_clear_rxne(void)
{
	setreg(&USART6->SR, 1, 5, 0);
}
uint8_t STM32FXXXUsart6_idle(void)
{
	return readreg(USART6->SR, 1, 4);
}
uint8_t STM32FXXXUsart6_ore(void)
{
	return readreg(USART6->SR, 1, 3);
}
uint8_t STM32FXXXUsart6_nf(void)
{
	return readreg(USART6->SR, 1, 2);
}
uint8_t STM32FXXXUsart6_fe(void)
{
	return readreg(USART6->SR, 1, 1);
}
uint8_t STM32FXXXUsart6_pe(void)
{
	return readreg(USART6->SR, 1, 0);
}
// DR
void STM32FXXXUsart6_dr(uint32_t data)
{
	writereg(&USART6->DR, 9, 0, data);
}
uint32_t STM32FXXXUsart6_get_dr(void)
{
	return readreg(USART6->DR, 9, 0);
}
// BRR
void STM32FXXXUsart6_div_mantissa(uint16_t value)
{
	setreg(&USART6->BRR, 12, 4, value);
}
void STM32FXXXUsart6_div_fraction(uint8_t value)
{
	setreg(&USART6->BRR, 4, 0, value);
}
// CR1
void STM32FXXXUsart6_over8(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 15, bool);
}
void STM32FXXXUsart6_ue(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 13, bool);
}
void STM32FXXXUsart6_m(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 12, bool);
}
void STM32FXXXUsart6_wake(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 11, bool);
}
void STM32FXXXUsart6_pce(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 10, bool);
}
void STM32FXXXUsart6_ps(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 9, bool);
}
void STM32FXXXUsart6_peie(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 8, bool);
}
void STM32FXXXUsart6_txeie(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 7, bool);
}
void STM32FXXXUsart6_tcie(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 6, bool);
}
void STM32FXXXUsart6_rxneie(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 5, bool);
}
void STM32FXXXUsart6_idleie(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 4, bool);
}
void STM32FXXXUsart6_te(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 3, bool);
}
void STM32FXXXUsart6_re(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 2, bool);
}
void STM32FXXXUsart6_rwu(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 1, bool);
}
void STM32FXXXUsart6_sbk(uint8_t bool)
{
	setreg(&USART6->CR1, 1, 0, bool);
}
// CR2
void STM32FXXXUsart6_linen(uint8_t bool)
{
	setreg(&USART6->CR2, 1, 14, bool);
}
void STM32FXXXUsart6_stop(uint8_t value)
{
	setreg(&USART6->CR2, 2, 12, value);
}
void STM32FXXXUsart6_clken(uint8_t bool)
{
	setreg(&USART6->CR2, 1, 11, bool);
}
void STM32FXXXUsart6_cpol(uint8_t bool)
{
	setreg(&USART6->CR2, 1, 10, bool);
}
void STM32FXXXUsart6_cpha(uint8_t bool)
{
	setreg(&USART6->CR2, 1, 9, bool);
}
void STM32FXXXUsart6_lbcl(uint8_t bool)
{
	setreg(&USART6->CR2, 1, 8, bool);
}
void STM32FXXXUsart6_lbdie(uint8_t bool)
{
	setreg(&USART6->CR2, 1, 6, bool);
}
void STM32FXXXUsart6_lbdl(uint8_t bool)
{
	setreg(&USART6->CR2, 1, 5, bool);
}
void STM32FXXXUsart6_add(uint8_t value)
{
	setreg(&USART6->CR2, 4, 0, value);
}
// CR3
void STM32FXXXUsart6_onebit(uint8_t bool)
{
	setreg(&USART6->CR3, 1, 11, bool);
}
void STM32FXXXUsart6_ctsie(uint8_t bool)
{
	setreg(&USART6->CR3, 1, 10, bool);
}
void STM32FXXXUsart6_ctse(uint8_t bool)
{
	setreg(&USART6->CR3, 1, 9, bool);
}
void STM32FXXXUsart6_rtse(uint8_t bool)
{
	setreg(&USART6->CR3, 1, 8, bool);
}
void STM32FXXXUsart6_dmat(uint8_t bool)
{
	setreg(&USART6->CR3, 1, 7, bool);
}
void STM32FXXXUsart6_dmar(uint8_t bool)
{
	setreg(&USART6->CR3, 1, 6, bool);
}
void STM32FXXXUsart6_scen(uint8_t bool)
{
	setreg(&USART6->CR3, 1, 5, bool);
}
void STM32FXXXUsart6_nack(uint8_t bool)
{
	setreg(&USART6->CR3, 1, 4, bool);
}
void STM32FXXXUsart6_hdsel(uint8_t bool)
{
	setreg(&USART6->CR3, 1, 3, bool);
}
void STM32FXXXUsart6_irlp(uint8_t bool)
{
	setreg(&USART6->CR3, 1, 2, bool);
}
void STM32FXXXUsart6_iren(uint8_t bool)
{
	setreg(&USART6->CR3, 1, 1, bool);
}
void STM32FXXXUsart6_eie(uint8_t bool)
{
	setreg(&USART6->CR3, 1, 0, bool);
}
// GTPR
void STM32FXXXUsart6_gt(uint8_t value)
{
	setreg(&USART6->GTPR, 8, 8, value);
}
void STM32FXXXUsart6_psc(uint8_t value)
{
	setreg(&USART6->GTPR, 8, 0, value);
}
/*** USART1 Auxiliar ***/
STM32FXXXUSART_SR* stm32fxxx_usart1_sr_inic(void)
{

	// SR
	stm32fxxx_usart1_sr.cts = STM32FXXXUsart1_cts;
	stm32fxxx_usart1_sr.clear_cts = STM32FXXXUsart1_clear_cts;
	stm32fxxx_usart1_sr.lbd = STM32FXXXUsart1_lbd;
	stm32fxxx_usart1_sr.clear_lbd = STM32FXXXUsart1_clear_lbd;
	stm32fxxx_usart1_sr.txe = STM32FXXXUsart1_txe;
	stm32fxxx_usart1_sr.tc = STM32FXXXUsart1_tc;
	stm32fxxx_usart1_sr.clear_tc = STM32FXXXUsart1_clear_tc;
	stm32fxxx_usart1_sr.rxne = STM32FXXXUsart1_rxne;
	stm32fxxx_usart1_sr.clear_rxne = STM32FXXXUsart1_clear_rxne;
	stm32fxxx_usart1_sr.idle = STM32FXXXUsart1_idle;
	stm32fxxx_usart1_sr.ore = STM32FXXXUsart1_ore;
	stm32fxxx_usart1_sr.nf = STM32FXXXUsart1_nf;
	stm32fxxx_usart1_sr.fe = STM32FXXXUsart1_fe;
	stm32fxxx_usart1_sr.pe = STM32FXXXUsart1_pe;
	return &stm32fxxx_usart1_sr;
}
STM32FXXXUSART_BRR* stm32fxxx_usart1_brr_inic(void)
{

	// BRR
	stm32fxxx_usart1_brr.div_mantissa = STM32FXXXUsart1_div_mantissa;
	stm32fxxx_usart1_brr.div_fraction = STM32FXXXUsart1_div_fraction;
	return &stm32fxxx_usart1_brr;
}
STM32FXXXUSART_CR1* stm32fxxx_usart1_cr1_inic(void)
{

	// CR1
	stm32fxxx_usart1_cr1.over8 = STM32FXXXUsart1_over8;
	stm32fxxx_usart1_cr1.ue = STM32FXXXUsart1_ue;
	stm32fxxx_usart1_cr1.m = STM32FXXXUsart1_m;
	stm32fxxx_usart1_cr1.wake = STM32FXXXUsart1_wake;
	stm32fxxx_usart1_cr1.pce = STM32FXXXUsart1_pce;
	stm32fxxx_usart1_cr1.ps = STM32FXXXUsart1_ps;
	stm32fxxx_usart1_cr1.peie = STM32FXXXUsart1_peie;
	stm32fxxx_usart1_cr1.txeie = STM32FXXXUsart1_txeie;
	stm32fxxx_usart1_cr1.tcie = STM32FXXXUsart1_tcie;
	stm32fxxx_usart1_cr1.rxneie = STM32FXXXUsart1_rxneie;
	stm32fxxx_usart1_cr1.idleie = STM32FXXXUsart1_idleie;
	stm32fxxx_usart1_cr1.te = STM32FXXXUsart1_te;
	stm32fxxx_usart1_cr1.re = STM32FXXXUsart1_re;
	stm32fxxx_usart1_cr1.rwu = STM32FXXXUsart1_rwu;
	stm32fxxx_usart1_cr1.sbk = STM32FXXXUsart1_sbk;
	return &stm32fxxx_usart1_cr1;
}
STM32FXXXUSART_CR2* stm32fxxx_usart1_cr2_inic(void)
{

	// CR2
	stm32fxxx_usart1_cr2.linen = STM32FXXXUsart1_linen;
	stm32fxxx_usart1_cr2.stop = STM32FXXXUsart1_stop;
	stm32fxxx_usart1_cr2.clken = STM32FXXXUsart1_clken;
	stm32fxxx_usart1_cr2.cpol = STM32FXXXUsart1_cpol;
	stm32fxxx_usart1_cr2.cpha = STM32FXXXUsart1_cpha;
	stm32fxxx_usart1_cr2.lbcl = STM32FXXXUsart1_lbcl;
	stm32fxxx_usart1_cr2.lbdie = STM32FXXXUsart1_lbdie;
	stm32fxxx_usart1_cr2.lbdl = STM32FXXXUsart1_lbdl;
	stm32fxxx_usart1_cr2.add = STM32FXXXUsart1_add;
	return &stm32fxxx_usart1_cr2;
}
STM32FXXXUSART_CR3* stm32fxxx_usart1_cr3_inic(void)
{

	// CR3
	stm32fxxx_usart1_cr3.onebit = STM32FXXXUsart1_onebit;
	stm32fxxx_usart1_cr3.ctsie = STM32FXXXUsart1_ctsie;
	stm32fxxx_usart1_cr3.ctse = STM32FXXXUsart1_ctse;
	stm32fxxx_usart1_cr3.rtse = STM32FXXXUsart1_rtse;
	stm32fxxx_usart1_cr3.dmat = STM32FXXXUsart1_dmat;
	stm32fxxx_usart1_cr3.dmar = STM32FXXXUsart1_dmar;
	stm32fxxx_usart1_cr3.scen = STM32FXXXUsart1_scen;
	stm32fxxx_usart1_cr3.nack = STM32FXXXUsart1_nack;
	stm32fxxx_usart1_cr3.hdsel = STM32FXXXUsart1_hdsel;
	stm32fxxx_usart1_cr3.irlp = STM32FXXXUsart1_irlp;
	stm32fxxx_usart1_cr3.iren = STM32FXXXUsart1_iren;
	stm32fxxx_usart1_cr3.eie = STM32FXXXUsart1_eie;
	return &stm32fxxx_usart1_cr3;
}
STM32FXXXUSART_GTPR* stm32fxxx_usart1_gtpr_inic(void)
{

	// GTPR
	stm32fxxx_usart1_gtpr.gt = STM32FXXXUsart1_gt;
	stm32fxxx_usart1_gtpr.psc = STM32FXXXUsart1_psc;
	return &stm32fxxx_usart1_gtpr;
}
/*** USART1 INIC Procedure & Function Definition ***/
STM32FXXX_USART1 usart1_enable(void)
{

	// STM32FXXXUSART1obj stm32fxxx_usart1;

	/*** USART1 Bit Mapping Link ***/
	stm32fxxx_usart1.sr = stm32fxxx_usart1_sr_inic();
	stm32fxxx_usart1.dr = STM32FXXXUsart1_dr;
	stm32fxxx_usart1.get_dr = STM32FXXXUsart1_get_dr;
	stm32fxxx_usart1.brr = stm32fxxx_usart1_brr_inic();
	stm32fxxx_usart1.cr1 = stm32fxxx_usart1_cr1_inic();
	stm32fxxx_usart1.cr2 = stm32fxxx_usart1_cr2_inic();
	stm32fxxx_usart1.cr3 = stm32fxxx_usart1_cr3_inic();
	stm32fxxx_usart1.gtpr = stm32fxxx_usart1_gtpr_inic();
	// Other
	stm32fxxx_usart1.clock = STM32FXXXUsart1Clock;
	stm32fxxx_usart1.nvic = STM32FXXXUsart1Nvic;
	stm32fxxx_usart1.parameter = STM32FXXXUsart1Parameter;

	return stm32fxxx_usart1;
}

STM32FXXX_USART1*  usart1(void){ return (STM32FXXX_USART1*) &stm32fxxx_usart1; }

/*** USART2 Auxiliar ***/
STM32FXXXUSART_SR* stm32fxxx_usart2_sr_inic(void)
{

	// SR
	stm32fxxx_usart2_sr.cts = STM32FXXXUsart2_cts;
	stm32fxxx_usart2_sr.clear_cts = STM32FXXXUsart2_clear_cts;
	stm32fxxx_usart2_sr.lbd = STM32FXXXUsart2_lbd;
	stm32fxxx_usart2_sr.clear_lbd = STM32FXXXUsart2_clear_lbd;
	stm32fxxx_usart2_sr.txe = STM32FXXXUsart2_txe;
	stm32fxxx_usart2_sr.tc = STM32FXXXUsart2_tc;
	stm32fxxx_usart2_sr.clear_tc = STM32FXXXUsart2_clear_tc;
	stm32fxxx_usart2_sr.rxne = STM32FXXXUsart2_rxne;
	stm32fxxx_usart2_sr.clear_rxne = STM32FXXXUsart2_clear_rxne;
	stm32fxxx_usart2_sr.idle = STM32FXXXUsart2_idle;
	stm32fxxx_usart2_sr.ore = STM32FXXXUsart2_ore;
	stm32fxxx_usart2_sr.nf = STM32FXXXUsart2_nf;
	stm32fxxx_usart2_sr.fe = STM32FXXXUsart2_fe;
	stm32fxxx_usart2_sr.pe = STM32FXXXUsart2_pe;
	return &stm32fxxx_usart2_sr;
}
STM32FXXXUSART_BRR* stm32fxxx_usart2_brr_inic(void)
{

	// BRR
	stm32fxxx_usart2_brr.div_mantissa = STM32FXXXUsart2_div_mantissa;
	stm32fxxx_usart2_brr.div_fraction = STM32FXXXUsart2_div_fraction;
	return &stm32fxxx_usart2_brr;
}
STM32FXXXUSART_CR1* stm32fxxx_usart2_cr1_inic(void)
{

	// CR1
	stm32fxxx_usart2_cr1.over8 = STM32FXXXUsart2_over8;
	stm32fxxx_usart2_cr1.ue = STM32FXXXUsart2_ue;
	stm32fxxx_usart2_cr1.m = STM32FXXXUsart2_m;
	stm32fxxx_usart2_cr1.wake = STM32FXXXUsart2_wake;
	stm32fxxx_usart2_cr1.pce = STM32FXXXUsart2_pce;
	stm32fxxx_usart2_cr1.ps = STM32FXXXUsart2_ps;
	stm32fxxx_usart2_cr1.peie = STM32FXXXUsart2_peie;
	stm32fxxx_usart2_cr1.txeie = STM32FXXXUsart2_txeie;
	stm32fxxx_usart2_cr1.tcie = STM32FXXXUsart2_tcie;
	stm32fxxx_usart2_cr1.rxneie = STM32FXXXUsart2_rxneie;
	stm32fxxx_usart2_cr1.idleie = STM32FXXXUsart2_idleie;
	stm32fxxx_usart2_cr1.te = STM32FXXXUsart2_te;
	stm32fxxx_usart2_cr1.re = STM32FXXXUsart2_re;
	stm32fxxx_usart2_cr1.rwu = STM32FXXXUsart2_rwu;
	stm32fxxx_usart2_cr1.sbk = STM32FXXXUsart2_sbk;
	return &stm32fxxx_usart2_cr1;
}
STM32FXXXUSART_CR2* stm32fxxx_usart2_cr2_inic(void)
{

	// CR2
	stm32fxxx_usart2_cr2.linen = STM32FXXXUsart2_linen;
	stm32fxxx_usart2_cr2.stop = STM32FXXXUsart2_stop;
	stm32fxxx_usart2_cr2.clken = STM32FXXXUsart2_clken;
	stm32fxxx_usart2_cr2.cpol = STM32FXXXUsart2_cpol;
	stm32fxxx_usart2_cr2.cpha = STM32FXXXUsart2_cpha;
	stm32fxxx_usart2_cr2.lbcl = STM32FXXXUsart2_lbcl;
	stm32fxxx_usart2_cr2.lbdie = STM32FXXXUsart2_lbdie;
	stm32fxxx_usart2_cr2.lbdl = STM32FXXXUsart2_lbdl;
	stm32fxxx_usart2_cr2.add = STM32FXXXUsart2_add;
	return &stm32fxxx_usart2_cr2;
}
STM32FXXXUSART_CR3* stm32fxxx_usart2_cr3_inic(void)
{

	// CR3
	stm32fxxx_usart2_cr3.onebit = STM32FXXXUsart2_onebit;
	stm32fxxx_usart2_cr3.ctsie = STM32FXXXUsart2_ctsie;
	stm32fxxx_usart2_cr3.ctse = STM32FXXXUsart2_ctse;
	stm32fxxx_usart2_cr3.rtse = STM32FXXXUsart2_rtse;
	stm32fxxx_usart2_cr3.dmat = STM32FXXXUsart2_dmat;
	stm32fxxx_usart2_cr3.dmar = STM32FXXXUsart2_dmar;
	stm32fxxx_usart2_cr3.scen = STM32FXXXUsart2_scen;
	stm32fxxx_usart2_cr3.nack = STM32FXXXUsart2_nack;
	stm32fxxx_usart2_cr3.hdsel = STM32FXXXUsart2_hdsel;
	stm32fxxx_usart2_cr3.irlp = STM32FXXXUsart2_irlp;
	stm32fxxx_usart2_cr3.iren = STM32FXXXUsart2_iren;
	stm32fxxx_usart2_cr3.eie = STM32FXXXUsart2_eie;
	return &stm32fxxx_usart2_cr3;
}
STM32FXXXUSART_GTPR* stm32fxxx_usart2_gtpr_inic(void)
{

	// GTPR
	stm32fxxx_usart2_gtpr.gt = STM32FXXXUsart2_gt;
	stm32fxxx_usart2_gtpr.psc = STM32FXXXUsart2_psc;
	return &stm32fxxx_usart2_gtpr;
}
/*** USART2 INIC Procedure & Function Definition ***/
STM32FXXX_USART2 usart2_enable(void)
{


	/*** USART2 Bit Mapping Link ***/
	stm32fxxx_usart2.sr = stm32fxxx_usart2_sr_inic();
	stm32fxxx_usart2.dr = STM32FXXXUsart2_dr;
	stm32fxxx_usart2.get_dr = STM32FXXXUsart2_get_dr;
	stm32fxxx_usart2.brr = stm32fxxx_usart2_brr_inic();
	stm32fxxx_usart2.cr1 = stm32fxxx_usart2_cr1_inic();
	stm32fxxx_usart2.cr2 = stm32fxxx_usart2_cr2_inic();
	stm32fxxx_usart2.cr3 = stm32fxxx_usart2_cr3_inic();
	stm32fxxx_usart2.gtpr = stm32fxxx_usart2_gtpr_inic();
	// Other
	stm32fxxx_usart2.clock = STM32FXXXUsart2Clock;
	stm32fxxx_usart2.nvic = STM32FXXXUsart2Nvic;
	stm32fxxx_usart2.parameter = STM32FXXXUsart2Parameter;
	return stm32fxxx_usart2;
}

STM32FXXX_USART2*  usart2(void){ return (STM32FXXX_USART2*) &stm32fxxx_usart2; }

/*** USART3 Auxiliar ***/
STM32FXXXUSART_SR* stm32fxxx_usart3_sr_inic(void)
{

	// SR
	stm32fxxx_usart3_sr.cts = STM32FXXXUsart3_cts;
	stm32fxxx_usart3_sr.clear_cts = STM32FXXXUsart3_clear_cts;
	stm32fxxx_usart3_sr.lbd = STM32FXXXUsart3_lbd;
	stm32fxxx_usart3_sr.clear_lbd = STM32FXXXUsart3_clear_lbd;
	stm32fxxx_usart3_sr.txe = STM32FXXXUsart3_txe;
	stm32fxxx_usart3_sr.tc = STM32FXXXUsart3_tc;
	stm32fxxx_usart3_sr.clear_tc = STM32FXXXUsart3_clear_tc;
	stm32fxxx_usart3_sr.rxne = STM32FXXXUsart3_rxne;
	stm32fxxx_usart3_sr.clear_rxne = STM32FXXXUsart3_clear_rxne;
	stm32fxxx_usart3_sr.idle = STM32FXXXUsart3_idle;
	stm32fxxx_usart3_sr.ore = STM32FXXXUsart3_ore;
	stm32fxxx_usart3_sr.nf = STM32FXXXUsart3_nf;
	stm32fxxx_usart3_sr.fe = STM32FXXXUsart3_fe;
	stm32fxxx_usart3_sr.pe = STM32FXXXUsart3_pe;
	return &stm32fxxx_usart3_sr;
}
STM32FXXXUSART_BRR* stm32fxxx_usart3_brr_inic(void)
{

	// BRR
	stm32fxxx_usart3_brr.div_mantissa = STM32FXXXUsart3_div_mantissa;
	stm32fxxx_usart3_brr.div_fraction = STM32FXXXUsart3_div_fraction;
	return &stm32fxxx_usart3_brr;
}
STM32FXXXUSART_CR1* stm32fxxx_usart3_cr1_inic(void)
{

	// CR1
	stm32fxxx_usart3_cr1.over8 = STM32FXXXUsart3_over8;
	stm32fxxx_usart3_cr1.ue = STM32FXXXUsart3_ue;
	stm32fxxx_usart3_cr1.m = STM32FXXXUsart3_m;
	stm32fxxx_usart3_cr1.wake = STM32FXXXUsart3_wake;
	stm32fxxx_usart3_cr1.pce = STM32FXXXUsart3_pce;
	stm32fxxx_usart3_cr1.ps = STM32FXXXUsart3_ps;
	stm32fxxx_usart3_cr1.peie = STM32FXXXUsart3_peie;
	stm32fxxx_usart3_cr1.txeie = STM32FXXXUsart3_txeie;
	stm32fxxx_usart3_cr1.tcie = STM32FXXXUsart3_tcie;
	stm32fxxx_usart3_cr1.rxneie = STM32FXXXUsart3_rxneie;
	stm32fxxx_usart3_cr1.idleie = STM32FXXXUsart3_idleie;
	stm32fxxx_usart3_cr1.te = STM32FXXXUsart3_te;
	stm32fxxx_usart3_cr1.re = STM32FXXXUsart3_re;
	stm32fxxx_usart3_cr1.rwu = STM32FXXXUsart3_rwu;
	stm32fxxx_usart3_cr1.sbk = STM32FXXXUsart3_sbk;
	return &stm32fxxx_usart3_cr1;
}
STM32FXXXUSART_CR2* stm32fxxx_usart3_cr2_inic(void)
{

	// CR2
	stm32fxxx_usart3_cr2.linen = STM32FXXXUsart3_linen;
	stm32fxxx_usart3_cr2.stop = STM32FXXXUsart3_stop;
	stm32fxxx_usart3_cr2.clken = STM32FXXXUsart3_clken;
	stm32fxxx_usart3_cr2.cpol = STM32FXXXUsart3_cpol;
	stm32fxxx_usart3_cr2.cpha = STM32FXXXUsart3_cpha;
	stm32fxxx_usart3_cr2.lbcl = STM32FXXXUsart3_lbcl;
	stm32fxxx_usart3_cr2.lbdie = STM32FXXXUsart3_lbdie;
	stm32fxxx_usart3_cr2.lbdl = STM32FXXXUsart3_lbdl;
	stm32fxxx_usart3_cr2.add = STM32FXXXUsart3_add;
	return &stm32fxxx_usart3_cr2;
}
STM32FXXXUSART_CR3* stm32fxxx_usart3_cr3_inic(void)
{

	// CR3
	stm32fxxx_usart3_cr3.onebit = STM32FXXXUsart3_onebit;
	stm32fxxx_usart3_cr3.ctsie = STM32FXXXUsart3_ctsie;
	stm32fxxx_usart3_cr3.ctse = STM32FXXXUsart3_ctse;
	stm32fxxx_usart3_cr3.rtse = STM32FXXXUsart3_rtse;
	stm32fxxx_usart3_cr3.dmat = STM32FXXXUsart3_dmat;
	stm32fxxx_usart3_cr3.dmar = STM32FXXXUsart3_dmar;
	stm32fxxx_usart3_cr3.scen = STM32FXXXUsart3_scen;
	stm32fxxx_usart3_cr3.nack = STM32FXXXUsart3_nack;
	stm32fxxx_usart3_cr3.hdsel = STM32FXXXUsart3_hdsel;
	stm32fxxx_usart3_cr3.irlp = STM32FXXXUsart3_irlp;
	stm32fxxx_usart3_cr3.iren = STM32FXXXUsart3_iren;
	stm32fxxx_usart3_cr3.eie = STM32FXXXUsart3_eie;
	return &stm32fxxx_usart3_cr3;
}
STM32FXXXUSART_GTPR* stm32fxxx_usart3_gtpr_inic(void)
{

	// GTPR
	stm32fxxx_usart3_gtpr.gt = STM32FXXXUsart3_gt;
	stm32fxxx_usart3_gtpr.psc = STM32FXXXUsart3_psc;
	return &stm32fxxx_usart3_gtpr;
}
/*** USART3 INIC Procedure & Function Definition ***/
STM32FXXX_USART3 usart3_enable(void)
{


	/*** USART3 Bit Mapping Link ***/
	stm32fxxx_usart3.sr = stm32fxxx_usart3_sr_inic();
	stm32fxxx_usart3.dr = STM32FXXXUsart3_dr;
	stm32fxxx_usart3.get_dr = STM32FXXXUsart3_get_dr;
	stm32fxxx_usart3.brr = stm32fxxx_usart3_brr_inic();
	stm32fxxx_usart3.cr1 = stm32fxxx_usart3_cr1_inic();
	stm32fxxx_usart3.cr2 = stm32fxxx_usart3_cr2_inic();
	stm32fxxx_usart3.cr3 = stm32fxxx_usart3_cr3_inic();
	stm32fxxx_usart3.gtpr = stm32fxxx_usart3_gtpr_inic();
	// Other
	stm32fxxx_usart3.clock = STM32FXXXUsart3Clock;
	stm32fxxx_usart3.nvic = STM32FXXXUsart3Nvic;
	stm32fxxx_usart3.parameter = STM32FXXXUsart3Parameter;
	return stm32fxxx_usart3;
}

STM32FXXX_USART3*  usart3(void){ return (STM32FXXX_USART3*) &stm32fxxx_usart3; }

/*** UART4 Auxiliar ***/
STM32FXXXUSART_SR* stm32fxxx_uart4_sr_inic(void)
{

	// SR
	stm32fxxx_uart4_sr.cts = STM32FXXXUart4_cts;
	stm32fxxx_uart4_sr.clear_cts = STM32FXXXUart4_clear_cts;
	stm32fxxx_uart4_sr.lbd = STM32FXXXUart4_lbd;
	stm32fxxx_uart4_sr.clear_lbd = STM32FXXXUart4_clear_lbd;
	stm32fxxx_uart4_sr.txe = STM32FXXXUart4_txe;
	stm32fxxx_uart4_sr.tc = STM32FXXXUart4_tc;
	stm32fxxx_uart4_sr.clear_tc = STM32FXXXUart4_clear_tc;
	stm32fxxx_uart4_sr.rxne = STM32FXXXUart4_rxne;
	stm32fxxx_uart4_sr.clear_rxne = STM32FXXXUart4_clear_rxne;
	stm32fxxx_uart4_sr.idle = STM32FXXXUart4_idle;
	stm32fxxx_uart4_sr.ore = STM32FXXXUart4_ore;
	stm32fxxx_uart4_sr.nf = STM32FXXXUart4_nf;
	stm32fxxx_uart4_sr.fe = STM32FXXXUart4_fe;
	stm32fxxx_uart4_sr.pe = STM32FXXXUart4_pe;
	return &stm32fxxx_uart4_sr;
}
STM32FXXXUSART_BRR* stm32fxxx_uart4_brr_inic(void)
{

	// BRR
	stm32fxxx_uart4_brr.div_mantissa = STM32FXXXUart4_div_mantissa;
	stm32fxxx_uart4_brr.div_fraction = STM32FXXXUart4_div_fraction;
	return &stm32fxxx_uart4_brr;
}
STM32FXXXUSART_CR1* stm32fxxx_uart4_cr1_inic(void)
{

	// CR1
	stm32fxxx_uart4_cr1.over8 = STM32FXXXUart4_over8;
	stm32fxxx_uart4_cr1.ue = STM32FXXXUart4_ue;
	stm32fxxx_uart4_cr1.m = STM32FXXXUart4_m;
	stm32fxxx_uart4_cr1.wake = STM32FXXXUart4_wake;
	stm32fxxx_uart4_cr1.pce = STM32FXXXUart4_pce;
	stm32fxxx_uart4_cr1.ps = STM32FXXXUart4_ps;
	stm32fxxx_uart4_cr1.peie = STM32FXXXUart4_peie;
	stm32fxxx_uart4_cr1.txeie = STM32FXXXUart4_txeie;
	stm32fxxx_uart4_cr1.tcie = STM32FXXXUart4_tcie;
	stm32fxxx_uart4_cr1.rxneie = STM32FXXXUart4_rxneie;
	stm32fxxx_uart4_cr1.idleie = STM32FXXXUart4_idleie;
	stm32fxxx_uart4_cr1.te = STM32FXXXUart4_te;
	stm32fxxx_uart4_cr1.re = STM32FXXXUart4_re;
	stm32fxxx_uart4_cr1.rwu = STM32FXXXUart4_rwu;
	stm32fxxx_uart4_cr1.sbk = STM32FXXXUart4_sbk;
	return &stm32fxxx_uart4_cr1;
}
STM32FXXXUSART_CR2* stm32fxxx_uart4_cr2_inic(void)
{

	// CR2
	stm32fxxx_uart4_cr2.linen = STM32FXXXUart4_linen;
	stm32fxxx_uart4_cr2.stop = STM32FXXXUart4_stop;
	stm32fxxx_uart4_cr2.clken = STM32FXXXUart4_clken;
	stm32fxxx_uart4_cr2.cpol = STM32FXXXUart4_cpol;
	stm32fxxx_uart4_cr2.cpha = STM32FXXXUart4_cpha;
	stm32fxxx_uart4_cr2.lbcl = STM32FXXXUart4_lbcl;
	stm32fxxx_uart4_cr2.lbdie = STM32FXXXUart4_lbdie;
	stm32fxxx_uart4_cr2.lbdl = STM32FXXXUart4_lbdl;
	stm32fxxx_uart4_cr2.add = STM32FXXXUart4_add;
	return &stm32fxxx_uart4_cr2;
}
STM32FXXXUSART_CR3* stm32fxxx_uart4_cr3_inic(void)
{

	// CR3
	stm32fxxx_uart4_cr3.onebit = STM32FXXXUart4_onebit;
	stm32fxxx_uart4_cr3.ctsie = STM32FXXXUart4_ctsie;
	stm32fxxx_uart4_cr3.ctse = STM32FXXXUart4_ctse;
	stm32fxxx_uart4_cr3.rtse = STM32FXXXUart4_rtse;
	stm32fxxx_uart4_cr3.dmat = STM32FXXXUart4_dmat;
	stm32fxxx_uart4_cr3.dmar = STM32FXXXUart4_dmar;
	stm32fxxx_uart4_cr3.scen = STM32FXXXUart4_scen;
	stm32fxxx_uart4_cr3.nack = STM32FXXXUart4_nack;
	stm32fxxx_uart4_cr3.hdsel = STM32FXXXUart4_hdsel;
	stm32fxxx_uart4_cr3.irlp = STM32FXXXUart4_irlp;
	stm32fxxx_uart4_cr3.iren = STM32FXXXUart4_iren;
	stm32fxxx_uart4_cr3.eie = STM32FXXXUart4_eie;
	return &stm32fxxx_uart4_cr3;
}
STM32FXXXUSART_GTPR* stm32fxxx_uart4_gtpr_inic(void)
{

	// GTPR
	stm32fxxx_uart4_gtpr.gt = STM32FXXXUart4_gt;
	stm32fxxx_uart4_gtpr.psc = STM32FXXXUart4_psc;
	return &stm32fxxx_uart4_gtpr;
}
/*** UART4 INIC Procedure & Function Definition ***/
STM32FXXX_UART4 uart4_enable(void)
{


	/*** UART4 Bit Mapping Link ***/
	stm32fxxx_uart4.sr = stm32fxxx_uart4_sr_inic();
	stm32fxxx_uart4.dr = STM32FXXXUart4_dr;
	stm32fxxx_uart4.get_dr = STM32FXXXUart4_get_dr;
	stm32fxxx_uart4.brr = stm32fxxx_uart4_brr_inic();
	stm32fxxx_uart4.cr1 = stm32fxxx_uart4_cr1_inic();
	stm32fxxx_uart4.cr2 = stm32fxxx_uart4_cr2_inic();
	stm32fxxx_uart4.cr3 = stm32fxxx_uart4_cr3_inic();
	stm32fxxx_uart4.gtpr = stm32fxxx_uart4_gtpr_inic();
	// Other
	stm32fxxx_uart4.clock = STM32FXXXUart4Clock;
	stm32fxxx_uart4.nvic = STM32FXXXUart4Nvic;
	stm32fxxx_uart4.parameter = STM32FXXXUart4Parameter;
	return stm32fxxx_uart4;
}

STM32FXXX_UART4*  uart4(void){ return (STM32FXXX_UART4*) &stm32fxxx_uart4; }

/*** UART5 Auxiliar ***/
STM32FXXXUSART_SR* stm32fxxx_uart5_sr_inic(void)
{

	// SR
	stm32fxxx_uart5_sr.cts = STM32FXXXUart5_cts;
	stm32fxxx_uart5_sr.clear_cts = STM32FXXXUart5_clear_cts;
	stm32fxxx_uart5_sr.lbd = STM32FXXXUart5_lbd;
	stm32fxxx_uart5_sr.clear_lbd = STM32FXXXUart5_clear_lbd;
	stm32fxxx_uart5_sr.txe = STM32FXXXUart5_txe;
	stm32fxxx_uart5_sr.tc = STM32FXXXUart5_tc;
	stm32fxxx_uart5_sr.clear_tc = STM32FXXXUart5_clear_tc;
	stm32fxxx_uart5_sr.rxne = STM32FXXXUart5_rxne;
	stm32fxxx_uart5_sr.clear_rxne = STM32FXXXUart5_clear_rxne;
	stm32fxxx_uart5_sr.idle = STM32FXXXUart5_idle;
	stm32fxxx_uart5_sr.ore = STM32FXXXUart5_ore;
	stm32fxxx_uart5_sr.nf = STM32FXXXUart5_nf;
	stm32fxxx_uart5_sr.fe = STM32FXXXUart5_fe;
	stm32fxxx_uart5_sr.pe = STM32FXXXUart5_pe;
	return &stm32fxxx_uart5_sr;
}
STM32FXXXUSART_BRR* stm32fxxx_uart5_brr_inic(void)
{

	// BRR
	stm32fxxx_uart5_brr.div_mantissa = STM32FXXXUart5_div_mantissa;
	stm32fxxx_uart5_brr.div_fraction = STM32FXXXUart5_div_fraction;
	return &stm32fxxx_uart5_brr;
}
STM32FXXXUSART_CR1* stm32fxxx_uart5_cr1_inic(void)
{

	// CR1
	stm32fxxx_uart5_cr1.over8 = STM32FXXXUart5_over8;
	stm32fxxx_uart5_cr1.ue = STM32FXXXUart5_ue;
	stm32fxxx_uart5_cr1.m = STM32FXXXUart5_m;
	stm32fxxx_uart5_cr1.wake = STM32FXXXUart5_wake;
	stm32fxxx_uart5_cr1.pce = STM32FXXXUart5_pce;
	stm32fxxx_uart5_cr1.ps = STM32FXXXUart5_ps;
	stm32fxxx_uart5_cr1.peie = STM32FXXXUart5_peie;
	stm32fxxx_uart5_cr1.txeie = STM32FXXXUart5_txeie;
	stm32fxxx_uart5_cr1.tcie = STM32FXXXUart5_tcie;
	stm32fxxx_uart5_cr1.rxneie = STM32FXXXUart5_rxneie;
	stm32fxxx_uart5_cr1.idleie = STM32FXXXUart5_idleie;
	stm32fxxx_uart5_cr1.te = STM32FXXXUart5_te;
	stm32fxxx_uart5_cr1.re = STM32FXXXUart5_re;
	stm32fxxx_uart5_cr1.rwu = STM32FXXXUart5_rwu;
	stm32fxxx_uart5_cr1.sbk = STM32FXXXUart5_sbk;
	return &stm32fxxx_uart5_cr1;
}
STM32FXXXUSART_CR2* stm32fxxx_uart5_cr2_inic(void)
{

	// CR2
	stm32fxxx_uart5_cr2.linen = STM32FXXXUart5_linen;
	stm32fxxx_uart5_cr2.stop = STM32FXXXUart5_stop;
	stm32fxxx_uart5_cr2.clken = STM32FXXXUart5_clken;
	stm32fxxx_uart5_cr2.cpol = STM32FXXXUart5_cpol;
	stm32fxxx_uart5_cr2.cpha = STM32FXXXUart5_cpha;
	stm32fxxx_uart5_cr2.lbcl = STM32FXXXUart5_lbcl;
	stm32fxxx_uart5_cr2.lbdie = STM32FXXXUart5_lbdie;
	stm32fxxx_uart5_cr2.lbdl = STM32FXXXUart5_lbdl;
	stm32fxxx_uart5_cr2.add = STM32FXXXUart5_add;
	return &stm32fxxx_uart5_cr2;
}
STM32FXXXUSART_CR3* stm32fxxx_uart5_cr3_inic(void)
{

	// CR3
	stm32fxxx_uart5_cr3.onebit = STM32FXXXUart5_onebit;
	stm32fxxx_uart5_cr3.ctsie = STM32FXXXUart5_ctsie;
	stm32fxxx_uart5_cr3.ctse = STM32FXXXUart5_ctse;
	stm32fxxx_uart5_cr3.rtse = STM32FXXXUart5_rtse;
	stm32fxxx_uart5_cr3.dmat = STM32FXXXUart5_dmat;
	stm32fxxx_uart5_cr3.dmar = STM32FXXXUart5_dmar;
	stm32fxxx_uart5_cr3.scen = STM32FXXXUart5_scen;
	stm32fxxx_uart5_cr3.nack = STM32FXXXUart5_nack;
	stm32fxxx_uart5_cr3.hdsel = STM32FXXXUart5_hdsel;
	stm32fxxx_uart5_cr3.irlp = STM32FXXXUart5_irlp;
	stm32fxxx_uart5_cr3.iren = STM32FXXXUart5_iren;
	stm32fxxx_uart5_cr3.eie = STM32FXXXUart5_eie;
	return &stm32fxxx_uart5_cr3;
}
STM32FXXXUSART_GTPR* stm32fxxx_uart5_gtpr_inic(void)
{

	// GTPR
	stm32fxxx_uart5_gtpr.gt = STM32FXXXUart5_gt;
	stm32fxxx_uart5_gtpr.psc = STM32FXXXUart5_psc;
	return &stm32fxxx_uart5_gtpr;
}
/*** UART5 INIC Procedure & Function Definition ***/
STM32FXXX_UART5 uart5_enable(void)
{


	/*** UART5 Bit Mapping Link ***/
	stm32fxxx_uart5.sr = stm32fxxx_uart5_sr_inic();
	stm32fxxx_uart5.dr = STM32FXXXUart5_dr;
	stm32fxxx_uart5.get_dr = STM32FXXXUart5_get_dr;
	stm32fxxx_uart5.brr = stm32fxxx_uart5_brr_inic();
	stm32fxxx_uart5.cr1 = stm32fxxx_uart5_cr1_inic();
	stm32fxxx_uart5.cr2 = stm32fxxx_uart5_cr2_inic();
	stm32fxxx_uart5.cr3 = stm32fxxx_uart5_cr3_inic();
	stm32fxxx_uart5.gtpr = stm32fxxx_uart5_gtpr_inic();
	// Other
	stm32fxxx_uart5.clock = STM32FXXXUart5Clock;
	stm32fxxx_uart5.nvic = STM32FXXXUart5Nvic;
	stm32fxxx_uart5.parameter = STM32FXXXUart5Parameter;
	return stm32fxxx_uart5;
}

STM32FXXX_UART5*  uart5(void){ return (STM32FXXX_UART5*) &stm32fxxx_uart5; }

/*** USART6 Auxiliar ***/
STM32FXXXUSART_SR* stm32fxxx_usart6_sr_inic(void)
{

	// SR
	stm32fxxx_usart6_sr.cts = STM32FXXXUsart6_cts;
	stm32fxxx_usart6_sr.clear_cts = STM32FXXXUsart6_clear_cts;
	stm32fxxx_usart6_sr.lbd = STM32FXXXUsart6_lbd;
	stm32fxxx_usart6_sr.clear_lbd = STM32FXXXUsart6_clear_lbd;
	stm32fxxx_usart6_sr.txe = STM32FXXXUsart6_txe;
	stm32fxxx_usart6_sr.tc = STM32FXXXUsart6_tc;
	stm32fxxx_usart6_sr.clear_tc = STM32FXXXUsart6_clear_tc;
	stm32fxxx_usart6_sr.rxne = STM32FXXXUsart6_rxne;
	stm32fxxx_usart6_sr.clear_rxne = STM32FXXXUsart6_clear_rxne;
	stm32fxxx_usart6_sr.idle = STM32FXXXUsart6_idle;
	stm32fxxx_usart6_sr.ore = STM32FXXXUsart6_ore;
	stm32fxxx_usart6_sr.nf = STM32FXXXUsart6_nf;
	stm32fxxx_usart6_sr.fe = STM32FXXXUsart6_fe;
	stm32fxxx_usart6_sr.pe = STM32FXXXUsart6_pe;
	return &stm32fxxx_usart6_sr;
}
STM32FXXXUSART_BRR* stm32fxxx_usart6_brr_inic(void)
{

	// BRR
	stm32fxxx_usart6_brr.div_mantissa = STM32FXXXUsart6_div_mantissa;
	stm32fxxx_usart6_brr.div_fraction = STM32FXXXUsart6_div_fraction;
	return &stm32fxxx_usart6_brr;
}
STM32FXXXUSART_CR1* stm32fxxx_usart6_cr1_inic(void)
{

	// CR1
	stm32fxxx_usart6_cr1.over8 = STM32FXXXUsart6_over8;
	stm32fxxx_usart6_cr1.ue = STM32FXXXUsart6_ue;
	stm32fxxx_usart6_cr1.m = STM32FXXXUsart6_m;
	stm32fxxx_usart6_cr1.wake = STM32FXXXUsart6_wake;
	stm32fxxx_usart6_cr1.pce = STM32FXXXUsart6_pce;
	stm32fxxx_usart6_cr1.ps = STM32FXXXUsart6_ps;
	stm32fxxx_usart6_cr1.peie = STM32FXXXUsart6_peie;
	stm32fxxx_usart6_cr1.txeie = STM32FXXXUsart6_txeie;
	stm32fxxx_usart6_cr1.tcie = STM32FXXXUsart6_tcie;
	stm32fxxx_usart6_cr1.rxneie = STM32FXXXUsart6_rxneie;
	stm32fxxx_usart6_cr1.idleie = STM32FXXXUsart6_idleie;
	stm32fxxx_usart6_cr1.te = STM32FXXXUsart6_te;
	stm32fxxx_usart6_cr1.re = STM32FXXXUsart6_re;
	stm32fxxx_usart6_cr1.rwu = STM32FXXXUsart6_rwu;
	stm32fxxx_usart6_cr1.sbk = STM32FXXXUsart6_sbk;
	return &stm32fxxx_usart6_cr1;
}
STM32FXXXUSART_CR2* stm32fxxx_usart6_cr2_inic(void)
{

	// CR2
	stm32fxxx_usart6_cr2.linen = STM32FXXXUsart6_linen;
	stm32fxxx_usart6_cr2.stop = STM32FXXXUsart6_stop;
	stm32fxxx_usart6_cr2.clken = STM32FXXXUsart6_clken;
	stm32fxxx_usart6_cr2.cpol = STM32FXXXUsart6_cpol;
	stm32fxxx_usart6_cr2.cpha = STM32FXXXUsart6_cpha;
	stm32fxxx_usart6_cr2.lbcl = STM32FXXXUsart6_lbcl;
	stm32fxxx_usart6_cr2.lbdie = STM32FXXXUsart6_lbdie;
	stm32fxxx_usart6_cr2.lbdl = STM32FXXXUsart6_lbdl;
	stm32fxxx_usart6_cr2.add = STM32FXXXUsart6_add;
	return &stm32fxxx_usart6_cr2;
}
STM32FXXXUSART_CR3* stm32fxxx_usart6_cr3_inic(void)
{

	// CR3
	stm32fxxx_usart6_cr3.onebit = STM32FXXXUsart6_onebit;
	stm32fxxx_usart6_cr3.ctsie = STM32FXXXUsart6_ctsie;
	stm32fxxx_usart6_cr3.ctse = STM32FXXXUsart6_ctse;
	stm32fxxx_usart6_cr3.rtse = STM32FXXXUsart6_rtse;
	stm32fxxx_usart6_cr3.dmat = STM32FXXXUsart6_dmat;
	stm32fxxx_usart6_cr3.dmar = STM32FXXXUsart6_dmar;
	stm32fxxx_usart6_cr3.scen = STM32FXXXUsart6_scen;
	stm32fxxx_usart6_cr3.nack = STM32FXXXUsart6_nack;
	stm32fxxx_usart6_cr3.hdsel = STM32FXXXUsart6_hdsel;
	stm32fxxx_usart6_cr3.irlp = STM32FXXXUsart6_irlp;
	stm32fxxx_usart6_cr3.iren = STM32FXXXUsart6_iren;
	stm32fxxx_usart6_cr3.eie = STM32FXXXUsart6_eie;
	return &stm32fxxx_usart6_cr3;
}
STM32FXXXUSART_GTPR* stm32fxxx_usart6_gtpr_inic(void)
{

	// GTPR
	stm32fxxx_usart6_gtpr.gt = STM32FXXXUsart6_gt;
	stm32fxxx_usart6_gtpr.psc = STM32FXXXUsart6_psc;
	return &stm32fxxx_usart6_gtpr;
}
/*** USART6 INIC Procedure & Function Definition ***/
STM32FXXX_USART6 usart6_enable(void)
{


	/*** USART6 Bit Mapping Link ***/
	stm32fxxx_usart6.sr = stm32fxxx_usart6_sr_inic();
	stm32fxxx_usart6.dr = STM32FXXXUsart6_dr;
	stm32fxxx_usart6.get_dr = STM32FXXXUsart6_get_dr;
	stm32fxxx_usart6.brr = stm32fxxx_usart6_brr_inic();
	stm32fxxx_usart6.cr1 = stm32fxxx_usart6_cr1_inic();
	stm32fxxx_usart6.cr2 = stm32fxxx_usart6_cr2_inic();
	stm32fxxx_usart6.cr3 = stm32fxxx_usart6_cr3_inic();
	stm32fxxx_usart6.gtpr = stm32fxxx_usart6_gtpr_inic();
	// Other
	stm32fxxx_usart6.clock = STM32FXXXUsart6Clock;
	stm32fxxx_usart6.nvic = STM32FXXXUsart6Nvic;
	stm32fxxx_usart6.parameter = STM32FXXXUsart6Parameter;
	return stm32fxxx_usart6;
}

STM32FXXX_USART6*  usart6(void){ return (STM32FXXX_USART6*) &stm32fxxx_usart6; }

/*** EOF ***/

