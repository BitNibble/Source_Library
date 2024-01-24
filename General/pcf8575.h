/***************************************************************************************************
	PCF8575
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: PCF8575
Date: 24012024
***************************************************************************************************/
/****** Comment:
	Stable
 **************************************************************************************************/
#ifndef _PCF8575_H_
	#define _PCF8575_H_

/*** Global Library ***/
#include <inttypes.h>

/*** Global Constant & Macro ***/
#define PCF8575_ADDR   32

typedef struct{
	void (*writehbits)(uint16_t hbits, uint8_t bool);
	uint16_t (*readhbits)(uint16_t hbits);
}PCF8575;

/*** Global Header ***/
PCF8575 pcf8575_enable(uint8_t prescaler);

#endif

/***EOF***/

