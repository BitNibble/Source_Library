/*************************************************************************
	eeprom wrapper
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: ATmega
Update: 01/01/
*************************************************************************/
/****** Comment:
   Very Stable
*************************************************************************/
/*** File Library ***/
#include "atmegaeeprom.h"

/*** File Variable ***/
static EEPROM setup_eeprom;
/*** File Header ***/

/*** Procedure & Function ***/
EEPROM EEPROM_enable(void){
	setup_eeprom.read_byte = eeprom_read_byte;
	setup_eeprom.write_byte = eeprom_write_byte;
	setup_eeprom.update_byte = eeprom_update_byte;
	setup_eeprom.read_word = eeprom_read_word;
	setup_eeprom.write_word = eeprom_write_word;
	setup_eeprom.update_word = eeprom_update_word;
	//setup_eeprom.read_dword = eeprom_read_dword;
	setup_eeprom.write_dword = eeprom_write_dword;
	setup_eeprom.write_dword = eeprom_write_dword;
	//setup_eeprom.read_float = eeprom_read_float;
	setup_eeprom.write_float = eeprom_write_float;
	setup_eeprom.update_float = eeprom_update_float;
	setup_eeprom.read_block = eeprom_read_block;
	setup_eeprom.write_block = eeprom_write_block;
	setup_eeprom.update_block = eeprom_update_block;
	
	return setup_eeprom;
}

EEPROM* eeprom(void){ return &setup_eeprom; };

/***EOF***/

