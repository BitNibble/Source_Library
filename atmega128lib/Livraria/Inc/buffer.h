/******************************************************************************
	BUFFER
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: all
Date: 17112022
Comment:
	Circular Buffer
*******************************************************************************/
#ifndef _BUFFER_H_
	#define _BUFFER_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#define BUFFvar char

/*** Global Variable ***/
typedef struct{
	BUFFvar* orig;
	BUFFvar* head;
	BUFFvar* end;
}buffer_parameter;

typedef struct{
	buffer_parameter par;
	void (*push)(buffer_parameter* par, BUFFvar data);
	BUFFvar* (*raw)(buffer_parameter* par);
	void (*flush)(buffer_parameter* par);
}BUFF;

/*** Global Header ***/
BUFF buff_enable(uint8_t size_buff, BUFFvar* buff);

#endif

/***EOF***/

