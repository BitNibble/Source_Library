/******************************************************************************
	STM32 446 PWR
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-446
Date: 19062023
Comment:
	
*******************************************************************************/
/*** File Library ***/
#include "stm32446pwr.h"

/*** File Variable ***/
static STM32446PWR_cr stm32446_pwr_cr;
static STM32446PWR_csr stm32446_pwr_csr;
static STM32446PWRobj stm32446_pwr;

/*** File Procedure & Function Header ***/
STM32446PWR_cr* stm32446_pwr_cr_inic(void);
STM32446PWR_csr* stm32446_pwr_csr_inic(void);
/*** PWR Bit Mapping ***/
// CR
void STM32446PWR_cr_fissr(uint8_t bool)
{
	setreg(&PWR->CR, 1, 21, bool);
}
void STM32446PWR_cr_fmssr(uint8_t bool)
{
	setreg(&PWR->CR, 1, 20, bool);
}
void STM32446PWR_cr_uden(uint8_t value)
{
	setreg(&PWR->CR, 2, 18, value);
}
void STM32446PWR_cr_odswen(uint8_t bool)
{
	setreg(&PWR->CR, 1, 17, bool);
}
void STM32446PWR_cr_oden(uint8_t bool)
{
	setreg(&PWR->CR, 1, 16, bool);
}
void STM32446PWR_cr_vos(uint8_t value)
{
	setreg(&PWR->CR, 2, 14, value);
}
void STM32446PWR_cr_adcdc1(uint8_t bool)
{
	setreg(&PWR->CR, 1, 13, bool);
}
void STM32446PWR_cr_mruds(uint8_t bool)
{
	setreg(&PWR->CR, 1, 11, bool);
}
void STM32446PWR_cr_lpuds(uint8_t bool)
{
	setreg(&PWR->CR, 1, 10, bool);
}
void STM32446PWR_cr_fpds(uint8_t bool)
{
	setreg(&PWR->CR, 1, 9, bool);
}
void STM32446PWR_cr_dbp(uint8_t bool)
{
	setreg(&PWR->CR, 1, 8, bool);
}
void STM32446PWR_cr_pls(uint8_t value)
{
	setreg(&PWR->CR, 3, 5, value);
}
uint8_t STM32446PWR_cr_get_pls(void)
{
	return readreg(PWR->CR, 3, 5);
}
void STM32446PWR_cr_pvde(uint8_t bool)
{
	setreg(&PWR->CR, 1, 4, bool);
}
void STM32446PWR_cr_clear_csbf(void)
{
	setreg(&PWR->CR, 1, 3, 1);
}
void STM32446PWR_cr_clear_cwuf(void)
{
	setreg(&PWR->CR, 1, 2, 1);
}
void STM32446PWR_cr_pdds(uint8_t bool)
{
	setreg(&PWR->CR, 1, 1, bool);
}
void STM32446PWR_cr_lpds(uint8_t bool)
{
	setreg(&PWR->CR, 1, 0, bool);
}
// CSR
uint8_t STM32446PWR_udrdy(void)
{
	return readreg(PWR->CSR, 2, 18);
}
void STM32446PWR_csr_clear_udrdy(void)
{
	setreg(&PWR->CSR, 2, 18, 3);
}
uint8_t STM32446PWR_csr_odswrdy(void)
{
	return readreg(PWR->CSR, 1, 17);
}
uint8_t STM32446PWR_csr_odrdy(void)
{
	return readreg(PWR->CSR, 1, 16);
}
uint8_t STM32446PWR_csr_vosrdy(void)
{
	return readreg(PWR->CSR, 1, 14);
}
void STM32446PWR_csr_bre(uint8_t bool)
{
	setreg(&PWR->CSR, 1, 9, bool);
}
void STM32446PWR_csr_ewup1(uint8_t bool)
{
	setreg(&PWR->CSR, 1, 8, bool);
}
void STM32446PWR_csr_ewup2(uint8_t bool)
{
	setreg(&PWR->CSR, 1, 7, bool);
}
uint8_t STM32446PWR_csr_brr(void)
{
	return readreg(PWR->CSR, 1, 3);
}
uint8_t STM32446PWR_csr_pvdo(void)
{
	return readreg(PWR->CSR, 1, 2);
}
uint8_t STM32446PWR_csr_sbf(void)
{
	return readreg(PWR->CSR, 1, 1);
}
uint8_t STM32446PWR_csr_wuf(void)
{
	return readreg(PWR->CSR, 1, 0);
}
/*** Other ***/
void STM32446PWR_clock(uint8_t bool)
{
	if(bool){ RCC->APB1ENR |= (1 << 28); }
	else{ RCC->APB1ENR &= ~(1 << 28); }
}
/*** Auxiliar ***/
STM32446PWR_cr* stm32446_pwr_cr_inic(void)
{

	// CR
	stm32446_pwr_cr.fissr = STM32446PWR_cr_fissr;
	stm32446_pwr_cr.fmssr = STM32446PWR_cr_fmssr;
	stm32446_pwr_cr.uden = STM32446PWR_cr_uden;
	stm32446_pwr_cr.odswen = STM32446PWR_cr_odswen;
	stm32446_pwr_cr.oden = STM32446PWR_cr_oden;
	stm32446_pwr_cr.vos = STM32446PWR_cr_vos;
	stm32446_pwr_cr.adcdc1 = STM32446PWR_cr_adcdc1;
	stm32446_pwr_cr.mruds = STM32446PWR_cr_mruds;
	stm32446_pwr_cr.lpuds = STM32446PWR_cr_lpuds;
	stm32446_pwr_cr.fpds = STM32446PWR_cr_fpds;
	stm32446_pwr_cr.dbp = STM32446PWR_cr_dbp;
	stm32446_pwr_cr.pls = STM32446PWR_cr_pls;
	stm32446_pwr_cr.get_pls = STM32446PWR_cr_get_pls;
	stm32446_pwr_cr.pvde = STM32446PWR_cr_pvde;
	stm32446_pwr_cr.clear_csbf = STM32446PWR_cr_clear_csbf;
	stm32446_pwr_cr.clear_cwuf = STM32446PWR_cr_clear_cwuf;
	stm32446_pwr_cr.pdds =STM32446PWR_cr_pdds;
	stm32446_pwr_cr.lpds = STM32446PWR_cr_lpds;
	return &stm32446_pwr_cr;
}
STM32446PWR_csr* stm32446_pwr_csr_inic(void)
{

	// CSR
	stm32446_pwr_csr.udrdy = STM32446PWR_udrdy;
	stm32446_pwr_csr.clear_udrdy = STM32446PWR_csr_clear_udrdy;
	stm32446_pwr_csr.odswrdy = STM32446PWR_csr_odswrdy;
	stm32446_pwr_csr.odrdy = STM32446PWR_csr_odrdy;
	stm32446_pwr_csr.vosrdy = STM32446PWR_csr_vosrdy;
	stm32446_pwr_csr.bre = STM32446PWR_csr_bre;
	stm32446_pwr_csr.ewup1 = STM32446PWR_csr_ewup1;
	stm32446_pwr_csr.ewup2 = STM32446PWR_csr_ewup2;
	stm32446_pwr_csr.brr = STM32446PWR_csr_brr;
	stm32446_pwr_csr.pvdo = STM32446PWR_csr_pvdo;
	stm32446_pwr_csr.sbf = STM32446PWR_csr_sbf;
	stm32446_pwr_csr.wuf = STM32446PWR_csr_wuf;
	return &stm32446_pwr_csr;
}
/*** INIC Procedure & Function Definition ***/
STM32446PWRobj pwr_enable(void)
{

	stm32446_pwr.reg = PWR;
	stm32446_pwr.clock = STM32446PWR_clock;
	/*** PWR Bit Mapping Link ***/
	stm32446_pwr.cr = stm32446_pwr_cr_inic();
	stm32446_pwr.csr = stm32446_pwr_csr_inic();
	return stm32446_pwr;
}

STM32446PWRobj* pwr(void){ return (STM32446PWRobj*) &stm32446_pwr; }

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


