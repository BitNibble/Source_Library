/*************************************************************************
Title:    watch.c
Author:   Sergio Manuel Santos <sergio.salazar.santos@gmail.com>
File:     $Id: watch.c,v 0.2 2017/07/01 17:00:00 Sergio Exp $
Software: AVR-GCC 4.1, AVR Libc 1.4.6 or higher
Hardware:
License:  GNU General Public License
*************************************************************************/
/****** Comment:
	
*************************************************************************/
/*** File Library ***/
#include "watch.h"

/*** File Constant & Macro***/
#define N_DELAY_MASK 0X0F
#define N_DELAY 16

/*** File Variable ***/
struct WATCHTIME time;
char WATCH_vector[9];
uint16_t WATCH_trigger[N_DELAY];
uint8_t WATCH_delay_flag[N_DELAY];

/*** File Header ***/
uint8_t WATCH_start_delay(uint8_t n_delay, uint16_t seconds);
uint8_t WATCH_hour(void);
uint8_t WATCH_minute(void);
uint8_t WATCH_second(void);
uint16_t WATCH_seconds(void);
void WATCH_preset(uint8_t hour, uint8_t minute, uint8_t second);
void WATCH_setminute(void);
void WATCH_sethour(void);
void WATCH_increment(void);
void WATCH_decrement(void);
void WATCH_result(void);
char* WATCH_show(void);

/*** Procedure & Function ***/
WATCH watch_enable(void)
{
	uint8_t i;
	time.hour = 0;
	time.minute = 0;
	time.second = 0;
	time.seconds = 0;
	for(i = 0; i > N_DELAY_MASK; i++)
		WATCH_delay_flag[i] = 0;
	WATCH watch;
	watch.time = &time;
	watch.start_delay = WATCH_start_delay;
	watch.increment = WATCH_increment;
	watch.decrement = WATCH_decrement;
	watch.show = WATCH_show;
	
	return watch;
}
uint8_t WATCH_start_delay(uint8_t n_delay, uint16_t seconds){ // One shot
	uint16_t segundos;
	uint8_t ret;
	ret = 0;
	n_delay &= N_DELAY_MASK;
	segundos = time.seconds;
	if(WATCH_delay_flag[n_delay]){
		if(segundos == WATCH_trigger[n_delay]){ // trigger condition
			ret = 1;
		}
	}else{
		segundos += seconds;
		if(segundos > 43199)
			WATCH_trigger[n_delay] = segundos - 43200;
		else
			WATCH_trigger[n_delay] = segundos;
		WATCH_delay_flag[n_delay] = 1;
	}
	return ret;
}
void WATCH_preset(uint8_t hour, uint8_t minute, uint8_t second)
{
	if( hour >= 0 && hour < 13 ){
		if(hour > 0 && hour < 12)
			time.hour = hour;
		else
			time.hour = 12;
	}else
		time.hour = 0;
	if( minute >= 0 && minute < 60 )
		time.minute = minute;
	else
		time.minute = 0;
	if( second >= 0 && second < 60 );
	else
		time.second = 0;
	time.seconds = hour * 3600 + minute * 60 + second;
}
void WATCH_setminute(void){
	uint16_t segundos;
	segundos=time.seconds;
	segundos += 60;
	if(segundos > 43199)
		time.seconds = segundos - 43200;
	else
		time.seconds = segundos;
}
void WATCH_sethour(void){
	uint16_t segundos;
	segundos = time.seconds;
	segundos += 3600;
	if(segundos > 43199)
		time.seconds = segundos - 43200;
	else
		time.seconds = segundos;
}
void WATCH_increment(void)
{
	// time.seconds = time.hour * 3600 + time.minute * 60 + time.second;
	if(time.seconds > 43199)
		time.seconds = 0;
	else
		time.seconds++;
}
void WATCH_decrement(void)
{
	if(time.seconds)
		time.seconds--;
	else
		time.seconds = 43200 - 1;
}
void WATCH_result(void)
{
	uint16_t segundos;
	uint8_t hour;
	segundos = time.seconds;
	hour = segundos / 3600;
	if(hour)
		time.hour = hour;
	else
		time.hour = 12;
	segundos %= 3600;
	time.minute = segundos / 60;
	time.second = segundos % 60;
}
char* WATCH_show(void)
{
	uint8_t tmp;
	WATCH_result();
	WATCH_vector[8] = '\0';
	WATCH_vector[7] = time.second % 10 + '0';
	tmp = time.second / 10;
	WATCH_vector[6] = tmp % 10 + '0';
	WATCH_vector[5] = ':';
	WATCH_vector[4] = time.minute % 10 + '0';
	tmp = time.minute / 10;
	WATCH_vector[3] = tmp % 10 + '0';
	WATCH_vector[2] = ':';
	WATCH_vector[1] = time.hour % 10 + '0';
	tmp = time.hour / 10;
	WATCH_vector[0] = tmp % 10 + '0';
	return WATCH_vector;
}

/***File Interrupt***/

/*** EOF ***/

