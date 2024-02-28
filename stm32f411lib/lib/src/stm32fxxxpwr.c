/******************************************************************************
	STM32 XXX PWR
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 19062023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32fxxxpwr.h"

/*** File Variable ***/
static STM32FXXXPWR_cr stm32fxxx_pwr_cr;
static STM32FXXXPWR_csr stm32fxxx_pwr_csr;
static STM32FXXXPWRobj stm32fxxx_pwr;

/*** File Procedure & Function Header ***/
STM32FXXXPWR_cr* stm32fxxx_pwr_cr_inic(void);
STM32FXXXPWR_csr* stm32fxxx_pwr_csr_inic(void);
/*** PWR Bit Mapping ***/
// CR
void STM32FXXXPWR_cr_fissr(uint8_t bool)
{
	setreg(&PWR->CR, 1, 21, bool);
}
void STM32FXXXPWR_cr_fmssr(uint8_t bool)
{
	setreg(&PWR->CR, 1, 20, bool);
}
void STM32FXXXPWR_cr_uden(uint8_t value)
{
	setreg(&PWR->CR, 2, 18, value);
}
void STM32FXXXPWR_cr_odswen(uint8_t bool)
{
	setreg(&PWR->CR, 1, 17, bool);
}
void STM32FXXXPWR_cr_oden(uint8_t bool)
{
	setreg(&PWR->CR, 1, 16, bool);
}
void STM32FXXXPWR_cr_vos(uint8_t value)
{
	setreg(&PWR->CR, 2, 14, value);
}
void STM32FXXXPWR_cr_adcdc1(uint8_t bool)
{
	setreg(&PWR->CR, 1, 13, bool);
}
void STM32FXXXPWR_cr_mruds(uint8_t bool)
{
	setreg(&PWR->CR, 1, 11, bool);
}
void STM32FXXXPWR_cr_lpuds(uint8_t bool)
{
	setreg(&PWR->CR, 1, 10, bool);
}
void STM32FXXXPWR_cr_fpds(uint8_t bool)
{
	setreg(&PWR->CR, 1, 9, bool);
}
void STM32FXXXPWR_cr_dbp(uint8_t bool)
{
	setreg(&PWR->CR, 1, 8, bool);
}
void STM32FXXXPWR_cr_pls(uint8_t value)
{
	setreg(&PWR->CR, 3, 5, value);
}
uint8_t STM32FXXXPWR_cr_get_pls(void)
{
	return readreg(PWR->CR, 3, 5);
}
void STM32FXXXPWR_cr_pvde(uint8_t bool)
{
	setreg(&PWR->CR, 1, 4, bool);
}
void STM32FXXXPWR_cr_clear_csbf(void)
{
	setreg(&PWR->CR, 1, 3, 1);
}
void STM32FXXXPWR_cr_clear_cwuf(void)
{
	setreg(&PWR->CR, 1, 2, 1);
}
void STM32FXXXPWR_cr_pdds(uint8_t bool)
{
	setreg(&PWR->CR, 1, 1, bool);
}
void STM32FXXXPWR_cr_lpds(uint8_t bool)
{
	setreg(&PWR->CR, 1, 0, bool);
}
// CSR
uint8_t STM32FXXXPWR_udrdy(void)
{
	return readreg(PWR->CSR, 2, 18);
}
void STM32FXXXPWR_csr_clear_udrdy(void)
{
	setreg(&PWR->CSR, 2, 18, 3);
}
uint8_t STM32FXXXPWR_csr_odswrdy(void)
{
	return readreg(PWR->CSR, 1, 17);
}
uint8_t STM32FXXXPWR_csr_odrdy(void)
{
	return readreg(PWR->CSR, 1, 16);
}
uint8_t STM32FXXXPWR_csr_vosrdy(void)
{
	return readreg(PWR->CSR, 1, 14);
}
void STM32FXXXPWR_csr_bre(uint8_t bool)
{
	setreg(&PWR->CSR, 1, 9, bool);
}
void STM32FXXXPWR_csr_ewup1(uint8_t bool)
{
	setreg(&PWR->CSR, 1, 8, bool);
}
void STM32FXXXPWR_csr_ewup2(uint8_t bool)
{
	setreg(&PWR->CSR, 1, 7, bool);
}
uint8_t STM32FXXXPWR_csr_brr(void)
{
	return readreg(PWR->CSR, 1, 3);
}
uint8_t STM32FXXXPWR_csr_pvdo(void)
{
	return readreg(PWR->CSR, 1, 2);
}
uint8_t STM32FXXXPWR_csr_sbf(void)
{
	return readreg(PWR->CSR, 1, 1);
}
uint8_t STM32FXXXPWR_csr_wuf(void)
{
	return readreg(PWR->CSR, 1, 0);
}
/*** Other ***/
void STM32FXXXPWR_clock(uint8_t bool)
{
	if(bool){ RCC->APB1ENR |= (1 << 28); }
	else{ RCC->APB1ENR &= ~(1 << 28); }
}
/*** Auxiliar ***/
STM32FXXXPWR_cr* stm32fxxx_pwr_cr_inic(void)
{

	// CR
	stm32fxxx_pwr_cr.fissr = STM32FXXXPWR_cr_fissr;
	stm32fxxx_pwr_cr.fmssr = STM32FXXXPWR_cr_fmssr;
	stm32fxxx_pwr_cr.uden = STM32FXXXPWR_cr_uden;
	stm32fxxx_pwr_cr.odswen = STM32FXXXPWR_cr_odswen;
	stm32fxxx_pwr_cr.oden = STM32FXXXPWR_cr_oden;
	stm32fxxx_pwr_cr.vos = STM32FXXXPWR_cr_vos;
	stm32fxxx_pwr_cr.adcdc1 = STM32FXXXPWR_cr_adcdc1;
	stm32fxxx_pwr_cr.mruds = STM32FXXXPWR_cr_mruds;
	stm32fxxx_pwr_cr.lpuds = STM32FXXXPWR_cr_lpuds;
	stm32fxxx_pwr_cr.fpds = STM32FXXXPWR_cr_fpds;
	stm32fxxx_pwr_cr.dbp = STM32FXXXPWR_cr_dbp;
	stm32fxxx_pwr_cr.pls = STM32FXXXPWR_cr_pls;
	stm32fxxx_pwr_cr.get_pls = STM32FXXXPWR_cr_get_pls;
	stm32fxxx_pwr_cr.pvde = STM32FXXXPWR_cr_pvde;
	stm32fxxx_pwr_cr.clear_csbf = STM32FXXXPWR_cr_clear_csbf;
	stm32fxxx_pwr_cr.clear_cwuf = STM32FXXXPWR_cr_clear_cwuf;
	stm32fxxx_pwr_cr.pdds =STM32FXXXPWR_cr_pdds;
	stm32fxxx_pwr_cr.lpds = STM32FXXXPWR_cr_lpds;
	return &stm32fxxx_pwr_cr;
}
STM32FXXXPWR_csr* stm32fxxx_pwr_csr_inic(void)
{

	// CSR
	stm32fxxx_pwr_csr.udrdy = STM32FXXXPWR_udrdy;
	stm32fxxx_pwr_csr.clear_udrdy = STM32FXXXPWR_csr_clear_udrdy;
	stm32fxxx_pwr_csr.odswrdy = STM32FXXXPWR_csr_odswrdy;
	stm32fxxx_pwr_csr.odrdy = STM32FXXXPWR_csr_odrdy;
	stm32fxxx_pwr_csr.vosrdy = STM32FXXXPWR_csr_vosrdy;
	stm32fxxx_pwr_csr.bre = STM32FXXXPWR_csr_bre;
	stm32fxxx_pwr_csr.ewup1 = STM32FXXXPWR_csr_ewup1;
	stm32fxxx_pwr_csr.ewup2 = STM32FXXXPWR_csr_ewup2;
	stm32fxxx_pwr_csr.brr = STM32FXXXPWR_csr_brr;
	stm32fxxx_pwr_csr.pvdo = STM32FXXXPWR_csr_pvdo;
	stm32fxxx_pwr_csr.sbf = STM32FXXXPWR_csr_sbf;
	stm32fxxx_pwr_csr.wuf = STM32FXXXPWR_csr_wuf;
	return &stm32fxxx_pwr_csr;
}
/*** INIC Procedure & Function Definition ***/
STM32FXXXPWRobj* pwr_enable(void)
{


	stm32fxxx_pwr.clock = STM32FXXXPWR_clock;
	/*** PWR Bit Mapping Link ***/
	stm32fxxx_pwr.cr = stm32fxxx_pwr_cr_inic();
	stm32fxxx_pwr.csr = stm32fxxx_pwr_csr_inic();
	return &stm32fxxx_pwr;
}

STM32FXXXPWRobj* pwr(void){ return (STM32FXXXPWRobj*) &stm32fxxx_pwr; }

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

