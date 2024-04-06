/************************************************************************
	LFSM
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmel
Date: 25102020
Comment:
	very stable
************************************************************************/
#ifndef _LFSM_H_
	#define _LFSM_H_

/*** Global Library ***/
#include "atmegaeeprom.h"
#include <inttypes.h>

/*** Constant & Macro ***/
#define NPAGES 255 // 1 to 254 possible pages
#define BYTEL 0
#define BYTEH 65535

/*** Global Variable ***/
struct lfsmdata{
	uint8_t page;
	uint16_t feedback;
	uint8_t inhl;
	uint8_t inlh;
	uint16_t mask;
	uint16_t outhl;
	uint16_t outlh;
};

struct model_lfsm{
	// Local Variables
	EEPROM0* eprom;
	uint16_t sizeeeprom;
	uint8_t sizeblock;
	uint8_t page;
	uint8_t input;
	uint16_t output;
	uint8_t status;
	// Function Pointers
	uint8_t (*read)(struct model_lfsm *r, uint8_t input);
	uint8_t (*learn)(struct model_lfsm *r, const uint8_t input, const uint16_t next, const uint16_t mask, const uint8_t page);
	uint16_t (*quant)(struct model_lfsm *r);
	uint8_t (*remove)(struct model_lfsm *r, uint8_t input);
	uint8_t (*premove)(struct model_lfsm *r, uint8_t input, uint8_t page);
	uint8_t (*deleteall)(struct model_lfsm *r);
	uint16_t (*getoutput)(struct model_lfsm *r);
	uint8_t (*getstatus)(struct model_lfsm *r);
	void (*setoutput)(struct model_lfsm *r,uint16_t output);
	uint8_t (*getpage)(struct model_lfsm *r);
	void (*setpage)(struct model_lfsm *r,uint8_t page);
};

typedef struct model_lfsm LFSM;

/*** Global Header ***/
LFSM lfsm_enable(EEPROM0* eeprom, const uint16_t sizeeeprom);

#endif

/***EOF***/


