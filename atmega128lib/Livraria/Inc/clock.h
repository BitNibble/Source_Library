/************************************************************************
	CLOCK
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
Hardware: all
Date: 25102020
Comment:
	Stable
************************************************************************/
#ifndef _CLOCK_H_
	#define _CLOCK_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#define HORA 24

/*** Global Variable ***/
struct CLOCKTIME{
	int8_t hour;
	int8_t minute;
	int8_t second;
};
typedef struct{
	void (*set)(uint8_t hour, uint8_t minute, uint8_t second);
	void (*increment)(void);
	void (*decrement)(void);
	uint8_t (*alarm)(uint8_t hour, uint8_t minute, uint8_t second);
	uint8_t (*second_count)(uint16_t second);
	void (*second_count_reset)(void);
	void (*second_count_stop)(void);
	void (*alarm_reset)(void);
	void (*alarm_stop)(void);
	char* (*show)(void);
}CLOCK;

/*** Global Header ***/
CLOCK clock_enable(uint8_t hour, uint8_t minute, uint8_t second);

#endif

/***EOF***/


