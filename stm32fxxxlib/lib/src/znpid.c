/*************************************************************************
	ZNPID
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License     
Hardware: Atmega 128
Date: 17022021_start
Comment:

************************************************************************/
/*** File Library ***/
#include "znpid.h"

/*** File Constant & Macro ***/
#define ZNPID_outMAX 1023
#define ZNPID_outMIN -1023

/*** File Variable ***/
double ZNPID_tmp;

/*** File Header ***/
void ZNPID_set_kc(znpidparameter* par, double kc);
void ZNPID_set_ki(znpidparameter* par, double ki);
void ZNPID_set_kd(znpidparameter* par, double kp);
void ZNPID_set_SP(znpidparameter* par, double setpoint);
double ZNPID_output(znpidparameter* par, double PV, double timelapse);
double ZNPID_integral(znpidparameter* par, double PV, double timelapse);
double ZNPID_derivative(znpidparameter* par, double PV, double timelapse);
double ZNPID_delta(double present_value, double past_value);
double ZNPID_sum(double value_1, double value_2);
double ZNPID_product(double value_1, double value_2);
uint32_t znpid_readreg(uint32_t reg, uint32_t size_block, uint32_t bit);
void znpid_writereg(volatile uint32_t* reg, uint32_t size_block, uint32_t bit, uint32_t data);
void znpid_setreg(volatile uint32_t* reg, uint32_t size_block, uint32_t bit, uint32_t data);
void znpid_setbit(volatile uint32_t* reg, uint32_t size_block, uint32_t bit, uint32_t data);
uint32_t znpid_getbit(volatile uint32_t* reg, uint32_t size_block, uint32_t bit);
znpidparameter znpid_par_inic(void);

/*** ZNPID Auxiliar  ***/
znpidparameter znpid_par_inic(void)
{
	znpidparameter znpid_par;
	// initialize variables
	znpid_par.k.c = 1;
	znpid_par.k.i = 0;
	znpid_par.k.d = 0;
	znpid_par.SetPoint = 0;
	znpid_par.aux.Err_past = 0;
	znpid_par.aux.dy = 0;
	znpid_par.aux.dx = 0;
	znpid_par.aux.integral = 0;
	znpid_par.aux.derivative = 0;
	znpid_par.PV = 0;
	znpid_par.OP = 0;
	return znpid_par;
}
/*** ZNPID Procedure & Function Definition ***/
ZNPID ZNPIDenable(void)
{
	// LOCAL VARIABLES
	ZNPID znpid;
	// initialize variables
	znpid.par = znpid_par_inic();
	// Direccionar apontadores para PROTOTIPOS
	znpid.set_kc = ZNPID_set_kc;
	znpid.set_ki = ZNPID_set_ki;
	znpid.set_kd = ZNPID_set_kd;
	znpid.set_SP = ZNPID_set_SP;
	znpid.output = ZNPID_output;
	
	return znpid;
}

void ZNPID_set_kc(znpidparameter* par, double kc)
{
	par->k.c = kc;
}

void ZNPID_set_ki(znpidparameter* par, double ki)
{
	par->k.i = ki;
}

void ZNPID_set_kd(znpidparameter* par, double kd)
{	
	par->k.d = kd;
}

void ZNPID_set_SP(znpidparameter* par, double setpoint)
{
	par->SetPoint = setpoint;
}

double ZNPID_output(znpidparameter* par, double PV, double timelapse)
{
	double result;
	par->PV = PV;
	par->aux.dy = ZNPID_delta(par->SetPoint, PV);
	par->aux.dx = timelapse;
	result = ZNPID_product(par->k.c, par->aux.dy);
	ZNPID_tmp = ZNPID_product(par->k.i, ZNPID_integral(par, PV, timelapse));
	result = ZNPID_sum(result, ZNPID_tmp);
	ZNPID_tmp = ZNPID_product(par->k.d, ZNPID_derivative(par, PV, timelapse));
	result = ZNPID_sum(result, ZNPID_tmp);
	par->aux.Err_past = par->aux.dy;
	par->OP = result;
	if(result > ZNPID_outMAX)
		par->aux.integral = ZNPID_outMAX - (par->aux.dy * par->aux.dx) - (par->aux.derivative * par->aux.dx * par->aux.dx);
	else if(result < ZNPID_outMIN)
		par->aux.integral = ZNPID_outMIN + (par->aux.dy * par->aux.dx) + (par->aux.derivative * par->aux.dx * par->aux.dx);
	return result;
}

double ZNPID_integral(znpidparameter* par, double PV, double timelapse)
{
	ZNPID_tmp = ZNPID_product(ZNPID_sum(ZNPID_delta(par->SetPoint, PV), par->aux.Err_past), timelapse);
	ZNPID_tmp /= 2;
	return (par->aux.integral += ZNPID_tmp);
}

double ZNPID_derivative(znpidparameter* par, double PV, double timelapse)
{
	ZNPID_tmp = ZNPID_delta(ZNPID_delta(par->SetPoint, PV), par->aux.Err_past);
	return (par->aux.derivative = (ZNPID_tmp / timelapse));
}

double ZNPID_delta(double present_value, double past_value)
{
	return (present_value - past_value);
}

double ZNPID_sum(double value_1, double value_2)
{
	return (value_1 + value_2);
}

double ZNPID_product(double value_1, double value_2)
{
	return (value_1 * value_2);
}

/*** File Procedure & Function Definition ***/
uint32_t znpid_readreg(uint32_t reg, uint32_t size_block, uint32_t bit)
{
	if(bit > 31){ bit = 0;} if(size_block > 32){ size_block = 32;}
	uint32_t value = reg;
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	value &= (mask << bit);
	value = (value >> bit);
	return value;
}

void znpid_writereg(volatile uint32_t* reg, uint32_t size_block, uint32_t bit, uint32_t data)
{
	if(bit > 31){ bit = 0;} if(size_block > 32){ size_block = 32;}
	uint32_t value = data;
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	value &= mask;
	value = (value << bit);
	*reg = value;
}

void znpid_setreg(volatile uint32_t* reg, uint32_t size_block, uint32_t bit, uint32_t data)
{
	if(bit > 31){ bit = 0;} if(size_block > 32){ size_block = 32;}
	uint32_t value = data;
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	value &= mask;
	*reg &= ~(mask << bit);
	*reg |= (value << bit);
}

void znpid_setbit(volatile uint32_t* reg, uint32_t size_block, uint32_t bit, uint32_t data)
{
	uint32_t n = 0;
	if(bit > 31){ n = bit/32; bit = bit - (n * 32); } if(size_block > 32){ size_block = 32;}
	uint32_t value = data;
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	value &= mask;
	*(reg + n ) &= ~(mask << bit);
	*(reg + n ) |= (value << bit);
}

uint32_t znpid_getbit(volatile uint32_t* reg, uint32_t size_block, uint32_t bit)
{
	uint32_t n = 0;
	if(bit > 31){ n = bit/32; bit = bit - (n * 32); } if(size_block > 32){ size_block = 32;}
	uint32_t value = *(reg + n );
	uint32_t mask = (unsigned int)((1 << size_block) - 1);
	value &= (mask << bit);
	value = (value >> bit);
	return value;
}

/***File Interrupt***/

/***EOF***/


