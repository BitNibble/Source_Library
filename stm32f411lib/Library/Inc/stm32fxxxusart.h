/******************************************************************************
	STM32 XXX USART
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 19062023
Comment:
	
*******************************************************************************/
#ifndef _STM32FXXXUSART_H_
	#define _STM32FXXXUSART_H_
/*** Library ***/
#include "armquery.h"
/*** Define & Macro ***/

/*** USART Bit Mapping Common TypeDef ***/
typedef struct{
	uint8_t (*cts)(void);
	void (*clear_cts)(void);
	uint8_t (*lbd)(void);
	void (*clear_lbd)(void);
	uint8_t (*txe)(void);
	uint8_t (*tc)(void);
	void (*clear_tc)(void);
	uint8_t (*rxne)(void);
	void (*clear_rxne)(void);
	uint8_t (*idle)(void);
	uint8_t (*ore)(void);
	uint8_t (*nf)(void);
	uint8_t (*fe)(void);
	uint8_t (*pe)(void);
}STM32FXXXUSART_SR;
typedef struct{
	void (*div_mantissa)(uint16_t value);
	void (*div_fraction)(uint8_t value);
}STM32FXXXUSART_BRR;
typedef struct{
	void (*over8)(uint8_t bool);
	void (*ue)(uint8_t bool);
	void (*m)(uint8_t bool);
	void (*wake)(uint8_t bool);
	void (*pce)(uint8_t bool);
	void (*ps)(uint8_t bool);
	void (*peie)(uint8_t bool);
	void (*txeie)(uint8_t bool);
	void (*tcie)(uint8_t bool);
	void (*rxneie)(uint8_t bool);
	void (*idleie)(uint8_t bool);
	void (*te)(uint8_t bool);
	void (*re)(uint8_t bool);
	void (*rwu)(uint8_t bool);
	void (*sbk)(uint8_t bool);
}STM32FXXXUSART_CR1;
typedef struct{
	void (*linen)(uint8_t bool);
	void (*stop)(uint8_t value);
	void (*clken)(uint8_t bool);
	void (*cpol)(uint8_t bool);
	void (*cpha)(uint8_t bool);
	void (*lbcl)(uint8_t bool);
	void (*lbdie)(uint8_t bool);
	void (*lbdl)(uint8_t bool);
	void (*add)(uint8_t value);
}STM32FXXXUSART_CR2;
typedef struct{
	void (*onebit)(uint8_t bool);
	void (*ctsie)(uint8_t bool);
	void (*ctse)(uint8_t bool);
	void (*rtse)(uint8_t bool);
	void (*dmat)(uint8_t bool);
	void (*dmar)(uint8_t bool);
	void (*scen)(uint8_t bool);
	void (*nack)(uint8_t bool);
	void (*hdsel)(uint8_t bool);
	void (*irlp)(uint8_t bool);
	void (*iren)(uint8_t bool);
	void (*eie)(uint8_t bool);
}STM32FXXXUSART_CR3;
typedef struct{
	void (*gt)(uint8_t value);
	void (*psc)(uint8_t value);
}STM32FXXXUSART_GTPR;
// USART -> USART1,2,3,6
typedef struct
{

	/*** Bit Mapping ***/
	STM32FXXXUSART_SR* sr;
	STM32FXXXUSART_BRR* brr;
	STM32FXXXUSART_CR1* cr1;
	STM32FXXXUSART_CR2* cr2;
	STM32FXXXUSART_CR3* cr3;
	STM32FXXXUSART_GTPR* gtpr;
	void (*dr)(uint32_t data);
	uint32_t (*get_dr)(void);
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
	void (*enable)(void);

	void (*parameter)( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
}STM32FXXX_USART1, STM32FXXX_USART2, STM32FXXX_USART3, STM32FXXX_USART6;
// USART -> UART4,5
typedef struct
{

	/*** Bit Mapping ***/
	STM32FXXXUSART_SR* sr;
	STM32FXXXUSART_BRR* brr;
	STM32FXXXUSART_CR1* cr1;
	STM32FXXXUSART_CR2* cr2;
	STM32FXXXUSART_CR3* cr3;
	STM32FXXXUSART_GTPR* gtpr;
	void (*dr)(uint32_t data);
	uint32_t (*get_dr)(void);
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
	void (*parameter)( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
}STM32FXXX_UART4, STM32FXXX_UART5;

STM32FXXX_USART1 usart1_enable(void);
STM32FXXX_USART1*  usart1(void);

STM32FXXX_USART2 usart2_enable(void);
STM32FXXX_USART2*  usart2(void);

STM32FXXX_USART3 usart3_enable(void);
STM32FXXX_USART3*  usart3(void);

STM32FXXX_UART4 uart4_enable(void);
STM32FXXX_UART4*  uart4(void);

STM32FXXX_UART5 uart5_enable(void);
STM32FXXX_UART5*  uart5(void);

STM32FXXX_USART6 usart6_enable(void);
STM32FXXX_USART6*  usart6(void);

/*** USART1 Bit Mapping Header ***/
// SR
uint8_t STM32FXXXUsart1_cts(void);
void STM32FXXXUsart1_clear_cts(void);
uint8_t STM32FXXXUsart1_lbd(void);
void STM32FXXXUsart1_clear_lbd(void);
uint8_t STM32FXXXUsart1_txe(void);
uint8_t STM32FXXXUsart1_tc(void);
void STM32FXXXUsart1_clear_tc(void);
uint8_t STM32FXXXUsart1_rxne(void);
void STM32FXXXUsart1_clear_rxne(void);
uint8_t STM32FXXXUsart1_idle(void);
uint8_t STM32FXXXUsart1_ore(void);
uint8_t STM32FXXXUsart1_nf(void);
uint8_t STM32FXXXUsart1_fe(void);
uint8_t STM32FXXXUsart1_pe(void);
// DR
void STM32FXXXUsart1_dr(uint32_t data);
uint32_t STM32FXXXUsart1_get_dr(void);
// BRR
void STM32FXXXUsart1_div_mantissa(uint16_t value);
void STM32FXXXUsart1_div_fraction(uint8_t value);
// CR1
void STM32FXXXUsart1_over8(uint8_t bool);
void STM32FXXXUsart1_ue(uint8_t bool);
void STM32FXXXUsart1_m(uint8_t bool);
void STM32FXXXUsart1_wake(uint8_t bool);
void STM32FXXXUsart1_pce(uint8_t bool);
void STM32FXXXUsart1_ps(uint8_t bool);
void STM32FXXXUsart1_peie(uint8_t bool);
void STM32FXXXUsart1_txeie(uint8_t bool);
void STM32FXXXUsart1_tcie(uint8_t bool);
void STM32FXXXUsart1_rxneie(uint8_t bool);
void STM32FXXXUsart1_idleie(uint8_t bool);
void STM32FXXXUsart1_te(uint8_t bool);
void STM32FXXXUsart1_re(uint8_t bool);
void STM32FXXXUsart1_rwu(uint8_t bool);
void STM32FXXXUsart1_sbk(uint8_t bool);
// CR2
void STM32FXXXUsart1_linen(uint8_t bool);
void STM32FXXXUsart1_stop(uint8_t value);
void STM32FXXXUsart1_clken(uint8_t bool);
void STM32FXXXUsart1_cpol(uint8_t bool);
void STM32FXXXUsart1_cpha(uint8_t bool);
void STM32FXXXUsart1_lbcl(uint8_t bool);
void STM32FXXXUsart1_lbdie(uint8_t bool);
void STM32FXXXUsart1_lbdl(uint8_t bool);
void STM32FXXXUsart1_add(uint8_t value);
// CR3
void STM32FXXXUsart1_onebit(uint8_t bool);
void STM32FXXXUsart1_ctsie(uint8_t bool);
void STM32FXXXUsart1_ctse(uint8_t bool);
void STM32FXXXUsart1_rtse(uint8_t bool);
void STM32FXXXUsart1_dmat(uint8_t bool);
void STM32FXXXUsart1_dmar(uint8_t bool);
void STM32FXXXUsart1_scen(uint8_t bool);
void STM32FXXXUsart1_nack(uint8_t bool);
void STM32FXXXUsart1_hdsel(uint8_t bool);
void STM32FXXXUsart1_irlp(uint8_t bool);
void STM32FXXXUsart1_iren(uint8_t bool);
void STM32FXXXUsart1_eie(uint8_t bool);
// GTPR
void STM32FXXXUsart1_gt(uint8_t value);
void STM32FXXXUsart1_psc(uint8_t value);
// Other
void STM32FXXXUsart1Clock( uint8_t bool );
void STM32FXXXUsart1Nvic( uint8_t bool );
void STM32FXXXUsart1Inic( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
void STM32FXXXUsart1Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
/*** USART2 Bit Mapping Header ***/
// SR
uint8_t STM32FXXXUsart2_cts(void);
void STM32FXXXUsart2_clear_cts(void);
uint8_t STM32FXXXUsart2_lbd(void);
void STM32FXXXUsart2_clear_lbd(void);
uint8_t STM32FXXXUsart2_txe(void);
uint8_t STM32FXXXUsart2_tc(void);
void STM32FXXXUsart2_clear_tc(void);
uint8_t STM32FXXXUsart2_rxne(void);
void STM32FXXXUsart2_clear_rxne(void);
uint8_t STM32FXXXUsart2_idle(void);
uint8_t STM32FXXXUsart2_ore(void);
uint8_t STM32FXXXUsart2_nf(void);
uint8_t STM32FXXXUsart2_fe(void);
uint8_t STM32FXXXUsart2_pe(void);
// DR
void STM32FXXXUsart2_dr(uint32_t data);
uint32_t STM32FXXXUsart2_get_dr(void);
// BRR
void STM32FXXXUsart2_div_mantissa(uint16_t value);
void STM32FXXXUsart2_div_fraction(uint8_t value);
// CR1
void STM32FXXXUsart2_over8(uint8_t bool);
void STM32FXXXUsart2_ue(uint8_t bool);
void STM32FXXXUsart2_m(uint8_t bool);
void STM32FXXXUsart2_wake(uint8_t bool);
void STM32FXXXUsart2_pce(uint8_t bool);
void STM32FXXXUsart2_ps(uint8_t bool);
void STM32FXXXUsart2_peie(uint8_t bool);
void STM32FXXXUsart2_txeie(uint8_t bool);
void STM32FXXXUsart2_tcie(uint8_t bool);
void STM32FXXXUsart2_rxneie(uint8_t bool);
void STM32FXXXUsart2_idleie(uint8_t bool);
void STM32FXXXUsart2_te(uint8_t bool);
void STM32FXXXUsart2_re(uint8_t bool);
void STM32FXXXUsart2_rwu(uint8_t bool);
void STM32FXXXUsart2_sbk(uint8_t bool);
// CR2
void STM32FXXXUsart2_linen(uint8_t bool);
void STM32FXXXUsart2_stop(uint8_t value);
void STM32FXXXUsart2_clken(uint8_t bool);
void STM32FXXXUsart2_cpol(uint8_t bool);
void STM32FXXXUsart2_cpha(uint8_t bool);
void STM32FXXXUsart2_lbcl(uint8_t bool);
void STM32FXXXUsart2_lbdie(uint8_t bool);
void STM32FXXXUsart2_lbdl(uint8_t bool);
void STM32FXXXUsart2_add(uint8_t value);
// CR3
void STM32FXXXUsart2_onebit(uint8_t bool);
void STM32FXXXUsart2_ctsie(uint8_t bool);
void STM32FXXXUsart2_ctse(uint8_t bool);
void STM32FXXXUsart2_rtse(uint8_t bool);
void STM32FXXXUsart2_dmat(uint8_t bool);
void STM32FXXXUsart2_dmar(uint8_t bool);
void STM32FXXXUsart2_scen(uint8_t bool);
void STM32FXXXUsart2_nack(uint8_t bool);
void STM32FXXXUsart2_hdsel(uint8_t bool);
void STM32FXXXUsart2_irlp(uint8_t bool);
void STM32FXXXUsart2_iren(uint8_t bool);
void STM32FXXXUsart2_eie(uint8_t bool);
// GTPR
void STM32FXXXUsart2_gt(uint8_t value);
void STM32FXXXUsart2_psc(uint8_t value);
// Other
void STM32FXXXUsart2Clock( uint8_t bool );
void STM32FXXXUsart2Nvic( uint8_t bool );
void STM32FXXXUsart2Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
/*** USART3 Bit Mapping Header ***/
// SR
uint8_t STM32FXXXUsart3_cts(void);
void STM32FXXXUsart3_clear_cts(void);
uint8_t STM32FXXXUsart3_lbd(void);
void STM32FXXXUsart3_clear_lbd(void);
uint8_t STM32FXXXUsart3_txe(void);
uint8_t STM32FXXXUsart3_tc(void);
void STM32FXXXUsart3_clear_tc(void);
uint8_t STM32FXXXUsart3_rxne(void);
void STM32FXXXUsart3_clear_rxne(void);
uint8_t STM32FXXXUsart3_idle(void);
uint8_t STM32FXXXUsart3_ore(void);
uint8_t STM32FXXXUsart3_nf(void);
uint8_t STM32FXXXUsart3_fe(void);
uint8_t STM32FXXXUsart3_pe(void);
// DR
void STM32FXXXUsart3_dr(uint32_t data);
uint32_t STM32FXXXUsart3_get_dr(void);
// BRR
void STM32FXXXUsart3_div_mantissa(uint16_t value);
void STM32FXXXUsart3_div_fraction(uint8_t value);
// CR1
void STM32FXXXUsart3_over8(uint8_t bool);
void STM32FXXXUsart3_ue(uint8_t bool);
void STM32FXXXUsart3_m(uint8_t bool);
void STM32FXXXUsart3_wake(uint8_t bool);
void STM32FXXXUsart3_pce(uint8_t bool);
void STM32FXXXUsart3_ps(uint8_t bool);
void STM32FXXXUsart3_peie(uint8_t bool);
void STM32FXXXUsart3_txeie(uint8_t bool);
void STM32FXXXUsart3_tcie(uint8_t bool);
void STM32FXXXUsart3_rxneie(uint8_t bool);
void STM32FXXXUsart3_idleie(uint8_t bool);
void STM32FXXXUsart3_te(uint8_t bool);
void STM32FXXXUsart3_re(uint8_t bool);
void STM32FXXXUsart3_rwu(uint8_t bool);
void STM32FXXXUsart3_sbk(uint8_t bool);
// CR2
void STM32FXXXUsart3_linen(uint8_t bool);
void STM32FXXXUsart3_stop(uint8_t value);
void STM32FXXXUsart3_clken(uint8_t bool);
void STM32FXXXUsart3_cpol(uint8_t bool);
void STM32FXXXUsart3_cpha(uint8_t bool);
void STM32FXXXUsart3_lbcl(uint8_t bool);
void STM32FXXXUsart3_lbdie(uint8_t bool);
void STM32FXXXUsart3_lbdl(uint8_t bool);
void STM32FXXXUsart3_add(uint8_t value);
// CR3
void STM32FXXXUsart3_onebit(uint8_t bool);
void STM32FXXXUsart3_ctsie(uint8_t bool);
void STM32FXXXUsart3_ctse(uint8_t bool);
void STM32FXXXUsart3_rtse(uint8_t bool);
void STM32FXXXUsart3_dmat(uint8_t bool);
void STM32FXXXUsart3_dmar(uint8_t bool);
void STM32FXXXUsart3_scen(uint8_t bool);
void STM32FXXXUsart3_nack(uint8_t bool);
void STM32FXXXUsart3_hdsel(uint8_t bool);
void STM32FXXXUsart3_irlp(uint8_t bool);
void STM32FXXXUsart3_iren(uint8_t bool);
void STM32FXXXUsart3_eie(uint8_t bool);
// GTPR
void STM32FXXXUsart3_gt(uint8_t value);
void STM32FXXXUsart3_psc(uint8_t value);
// Other
void STM32FXXXUsart3Clock( uint8_t bool );
void STM32FXXXUsart3Nvic( uint8_t bool );
void STM32FXXXUsart3Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
/*** UART4 Bit Mapping Header ***/
// SR
uint8_t STM32FXXXUart4_cts(void);
void STM32FXXXUart4_clear_cts(void);
uint8_t STM32FXXXUart4_lbd(void);
void STM32FXXXUart4_clear_lbd(void);
uint8_t STM32FXXXUart4_txe(void);
uint8_t STM32FXXXUart4_tc(void);
void STM32FXXXUart4_clear_tc(void);
uint8_t STM32FXXXUart4_rxne(void);
void STM32FXXXUart4_clear_rxne(void);
uint8_t STM32FXXXUart4_idle(void);
uint8_t STM32FXXXUart4_ore(void);
uint8_t STM32FXXXUart4_nf(void);
uint8_t STM32FXXXUart4_fe(void);
uint8_t STM32FXXXUart4_pe(void);
// DR
void STM32FXXXUart4_dr(uint32_t data);
uint32_t STM32FXXXUart4_get_dr(void);
// BRR
void STM32FXXXUart4_div_mantissa(uint16_t value);
void STM32FXXXUart4_div_fraction(uint8_t value);
// CR1
void STM32FXXXUart4_over8(uint8_t bool);
void STM32FXXXUart4_ue(uint8_t bool);
void STM32FXXXUart4_m(uint8_t bool);
void STM32FXXXUart4_wake(uint8_t bool);
void STM32FXXXUart4_pce(uint8_t bool);
void STM32FXXXUart4_ps(uint8_t bool);
void STM32FXXXUart4_peie(uint8_t bool);
void STM32FXXXUart4_txeie(uint8_t bool);
void STM32FXXXUart4_tcie(uint8_t bool);
void STM32FXXXUart4_rxneie(uint8_t bool);
void STM32FXXXUart4_idleie(uint8_t bool);
void STM32FXXXUart4_te(uint8_t bool);
void STM32FXXXUart4_re(uint8_t bool);
void STM32FXXXUart4_rwu(uint8_t bool);
void STM32FXXXUart4_sbk(uint8_t bool);
// CR2
void STM32FXXXUart4_linen(uint8_t bool);
void STM32FXXXUart4_stop(uint8_t value);
void STM32FXXXUart4_clken(uint8_t bool);
void STM32FXXXUart4_cpol(uint8_t bool);
void STM32FXXXUart4_cpha(uint8_t bool);
void STM32FXXXUart4_lbcl(uint8_t bool);
void STM32FXXXUart4_lbdie(uint8_t bool);
void STM32FXXXUart4_lbdl(uint8_t bool);
void STM32FXXXUart4_add(uint8_t value);
// CR3
void STM32FXXXUart4_onebit(uint8_t bool);
void STM32FXXXUart4_ctsie(uint8_t bool);
void STM32FXXXUart4_ctse(uint8_t bool);
void STM32FXXXUart4_rtse(uint8_t bool);
void STM32FXXXUart4_dmat(uint8_t bool);
void STM32FXXXUart4_dmar(uint8_t bool);
void STM32FXXXUart4_scen(uint8_t bool);
void STM32FXXXUart4_nack(uint8_t bool);
void STM32FXXXUart4_hdsel(uint8_t bool);
void STM32FXXXUart4_irlp(uint8_t bool);
void STM32FXXXUart4_iren(uint8_t bool);
void STM32FXXXUart4_eie(uint8_t bool);
// GTPR
void STM32FXXXUart4_gt(uint8_t value);
void STM32FXXXUart4_psc(uint8_t value);
// Other
void STM32FXXXUart4Clock( uint8_t bool );
void STM32FXXXUart4Nvic( uint8_t bool );
void STM32FXXXUart4Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
/*** UART5 Bit Mapping Header ***/
// SR
uint8_t STM32FXXXUart5_cts(void);
void STM32FXXXUart5_clear_cts(void);
uint8_t STM32FXXXUart5_lbd(void);
void STM32FXXXUart5_clear_lbd(void);
uint8_t STM32FXXXUart5_txe(void);
uint8_t STM32FXXXUart5_tc(void);
void STM32FXXXUart5_clear_tc(void);
uint8_t STM32FXXXUart5_rxne(void);
void STM32FXXXUart5_clear_rxne(void);
uint8_t STM32FXXXUart5_idle(void);
uint8_t STM32FXXXUart5_ore(void);
uint8_t STM32FXXXUart5_nf(void);
uint8_t STM32FXXXUart5_fe(void);
uint8_t STM32FXXXUart5_pe(void);
// DR
void STM32FXXXUart5_dr(uint32_t data);
uint32_t STM32FXXXUart5_get_dr(void);
// BRR
void STM32FXXXUart5_div_mantissa(uint16_t value);
void STM32FXXXUart5_div_fraction(uint8_t value);
// CR1
void STM32FXXXUart5_over8(uint8_t bool);
void STM32FXXXUart5_ue(uint8_t bool);
void STM32FXXXUart5_m(uint8_t bool);
void STM32FXXXUart5_wake(uint8_t bool);
void STM32FXXXUart5_pce(uint8_t bool);
void STM32FXXXUart5_ps(uint8_t bool);
void STM32FXXXUart5_peie(uint8_t bool);
void STM32FXXXUart5_txeie(uint8_t bool);
void STM32FXXXUart5_tcie(uint8_t bool);
void STM32FXXXUart5_rxneie(uint8_t bool);
void STM32FXXXUart5_idleie(uint8_t bool);
void STM32FXXXUart5_te(uint8_t bool);
void STM32FXXXUart5_re(uint8_t bool);
void STM32FXXXUart5_rwu(uint8_t bool);
void STM32FXXXUart5_sbk(uint8_t bool);
// CR2
void STM32FXXXUart5_linen(uint8_t bool);
void STM32FXXXUart5_stop(uint8_t value);
void STM32FXXXUart5_clken(uint8_t bool);
void STM32FXXXUart5_cpol(uint8_t bool);
void STM32FXXXUart5_cpha(uint8_t bool);
void STM32FXXXUart5_lbcl(uint8_t bool);
void STM32FXXXUart5_lbdie(uint8_t bool);
void STM32FXXXUart5_lbdl(uint8_t bool);
void STM32FXXXUart5_add(uint8_t value);
// CR3
void STM32FXXXUart5_onebit(uint8_t bool);
void STM32FXXXUart5_ctsie(uint8_t bool);
void STM32FXXXUart5_ctse(uint8_t bool);
void STM32FXXXUart5_rtse(uint8_t bool);
void STM32FXXXUart5_dmat(uint8_t bool);
void STM32FXXXUart5_dmar(uint8_t bool);
void STM32FXXXUart5_scen(uint8_t bool);
void STM32FXXXUart5_nack(uint8_t bool);
void STM32FXXXUart5_hdsel(uint8_t bool);
void STM32FXXXUart5_irlp(uint8_t bool);
void STM32FXXXUart5_iren(uint8_t bool);
void STM32FXXXUart5_eie(uint8_t bool);
// GTPR
void STM32FXXXUart5_gt(uint8_t value);
void STM32FXXXUart5_psc(uint8_t value);
// Other
void STM32FXXXUart5Clock( uint8_t bool );
void STM32FXXXUart5Nvic( uint8_t bool );
void STM32FXXXUart5Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
/*** USART6 Bit Mapping Header ***/
// SR
uint8_t STM32FXXXUsart6_cts(void);
void STM32FXXXUsart6_clear_cts(void);
uint8_t STM32FXXXUsart6_lbd(void);
void STM32FXXXUsart6_clear_lbd(void);
uint8_t STM32FXXXUsart6_txe(void);
uint8_t STM32FXXXUsart6_tc(void);
void STM32FXXXUsart6_clear_tc(void);
uint8_t STM32FXXXUsart6_rxne(void);
void STM32FXXXUsart6_clear_rxne(void);
uint8_t STM32FXXXUsart6_idle(void);
uint8_t STM32FXXXUsart6_ore(void);
uint8_t STM32FXXXUsart6_nf(void);
uint8_t STM32FXXXUsart6_fe(void);
uint8_t STM32FXXXUsart6_pe(void);
// DR
void STM32FXXXUsart6_dr(uint32_t data);
uint32_t STM32FXXXUsart6_get_dr(void);
// BRR
void STM32FXXXUsart6_div_mantissa(uint16_t value);
void STM32FXXXUsart6_div_fraction(uint8_t value);
// CR1
void STM32FXXXUsart6_over8(uint8_t bool);
void STM32FXXXUsart6_ue(uint8_t bool);
void STM32FXXXUsart6_m(uint8_t bool);
void STM32FXXXUsart6_wake(uint8_t bool);
void STM32FXXXUsart6_pce(uint8_t bool);
void STM32FXXXUsart6_ps(uint8_t bool);
void STM32FXXXUsart6_peie(uint8_t bool);
void STM32FXXXUsart6_txeie(uint8_t bool);
void STM32FXXXUsart6_tcie(uint8_t bool);
void STM32FXXXUsart6_rxneie(uint8_t bool);
void STM32FXXXUsart6_idleie(uint8_t bool);
void STM32FXXXUsart6_te(uint8_t bool);
void STM32FXXXUsart6_re(uint8_t bool);
void STM32FXXXUsart6_rwu(uint8_t bool);
void STM32FXXXUsart6_sbk(uint8_t bool);
// CR2
void STM32FXXXUsart6_linen(uint8_t bool);
void STM32FXXXUsart6_stop(uint8_t value);
void STM32FXXXUsart6_clken(uint8_t bool);
void STM32FXXXUsart6_cpol(uint8_t bool);
void STM32FXXXUsart6_cpha(uint8_t bool);
void STM32FXXXUsart6_lbcl(uint8_t bool);
void STM32FXXXUsart6_lbdie(uint8_t bool);
void STM32FXXXUsart6_lbdl(uint8_t bool);
void STM32FXXXUsart6_add(uint8_t value);
// CR3
void STM32FXXXUsart6_onebit(uint8_t bool);
void STM32FXXXUsart6_ctsie(uint8_t bool);
void STM32FXXXUsart6_ctse(uint8_t bool);
void STM32FXXXUsart6_rtse(uint8_t bool);
void STM32FXXXUsart6_dmat(uint8_t bool);
void STM32FXXXUsart6_dmar(uint8_t bool);
void STM32FXXXUsart6_scen(uint8_t bool);
void STM32FXXXUsart6_nack(uint8_t bool);
void STM32FXXXUsart6_hdsel(uint8_t bool);
void STM32FXXXUsart6_irlp(uint8_t bool);
void STM32FXXXUsart6_iren(uint8_t bool);
void STM32FXXXUsart6_eie(uint8_t bool);
// GTPR
void STM32FXXXUsart6_gt(uint8_t value);
void STM32FXXXUsart6_psc(uint8_t value);
// Other
void STM32FXXXUsart6Clock( uint8_t bool );
void STM32FXXXUsart6Nvic( uint8_t bool );
void STM32FXXXUsart6Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );

/*** INTERRUPT HEADER ***/
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
void UART4_IRQHandler(void);
void UART5_IRQHandler(void);
void USART6_IRQHandler(void);

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

