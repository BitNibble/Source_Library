/*********************************************************************
Hardware: Atmega328.c
Author: Sergio Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Created: 20/04/2023 14:00:00
 ********************************************************************/
/****** Comment:
		LCD
-PB0 pin 14 cmd D4
-PB1 pin 15 cmd D5
-PB2 pin 16 cmd D6
-PB3 pin 17 cmd D7
-PC0 pin 23 data RS
-PC1 pin 24 data RW
-PC2 pin 25 data E
-PC3 pin 26 data Reboot
		RTC PCF8563 (twi)
-PC4 SDA
-PC5 SCL
********************************************************************/
/*** File library ***/
#include "atmega328mapping.h"
#include "function.h"
#include "lcd2p.h"
#include<util/delay.h>

#define TRUE 1
#define ZERO 0

#define pcf8575_addr 32

LCD02P lcd;

uint16_t count;

int main(void)
{
atmega328_enable();
func_enable();
lcd02p_enable(&DDRB, &PINB, &PORTB, &DDRC, &PINC, &PORTC);
twi_enable(85,16);

twi()->start();
twi()->connect(pcf8575_addr,TWI_WRITE);
twi()->master_write(0xFF);
twi()->master_write(0xFF);
twi()->stop();

uint8_t result_1 = 0xFF;
uint8_t result_2 = 0xFF;

for ( ; TRUE; ) // Looping
{
	lcd02p()->reboot();
	lcd02p()->gotoxy(0,0);
	lcd02p()->string_size("Welcome", 8); lcd02p()->string_size(func()->ui16toa(count), 6);
	count++;
	twi()->start();
	twi()->connect(pcf8575_addr,TWI_WRITE);
	twi()->master_write(0xFF);
	twi()->master_write(0xFF);
	twi()->stop();
	
	twi()->start();
	twi()->connect(pcf8575_addr, TWI_READ);
	result_1 = twi()->master_read(TWI_ACK);
	result_2 = twi()->master_read(TWI_NACK);
	twi()->stop();
	
	_delay_ms(500);
	twi()->start();
	twi()->connect(pcf8575_addr,TWI_WRITE);
	twi()->master_write(~4);
	twi()->master_write(0xff);
	twi()->stop();
	_delay_ms(500);
	
	lcd02p()->gotoxy(1,0);
	lcd02p()->string_size(func()->ui16toa(result_1), 6);lcd02p()->string_size(func()->ui16toa(result_2), 6);
	
	
	
}
} /*** MAIN ***/

/*** File Interrupt ***/

/***EOF***/

/******
1º Sequence
2º Scope
3º Pointer and Variable
4º Casting
******/

