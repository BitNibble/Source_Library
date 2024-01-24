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
#include "pcf8575.h"
#include<util/delay.h>

#define TRUE 1
#define ZERO 0

#define pcf8575_addr 32

LCD02P lcd;
PCF8575 pcf8575;
PCF8575 pcf85;

uint16_t count;

int main(void)
{
atmega328_enable();
func_enable();
lcd02p_enable(&DDRB, &PINB, &PORTB, &DDRC, &PINC, &PORTC);
twi_enable(85,16);

pcf85 = pcf8575_enable(30, 16);
pcf8575 = pcf8575_enable(32, 16);


uint16_t result_1 = 0xFF;
uint8_t updown = 1;
for ( ; TRUE; ) // Looping
{
	lcd02p()->reboot();
	lcd02p()->gotoxy(0,0);
	lcd02p()->string_size("Welcome", 8); lcd02p()->string_size(func()->ui16toa(count), 6);
	count++;
	_delay_ms(500);
	if(updown){
		pcf8575.writehbits(pcf8575.par, 1 << count,0);
		result_1 = pcf8575.readhbits(pcf8575.par, 0xFFFF);
		lcd02p()->gotoxy(1,0);
		lcd02p()->string_size(func()->ui16toa(result_1), 6);
		if(count > 14){ count = 0; updown = 0;}
	}else{
		pcf8575.writehbits(pcf8575.par, 1 << count,1);
		result_1 = pcf8575.readhbits(pcf8575.par, 0xFFFF);
		lcd02p()->gotoxy(1,0);
		lcd02p()->string_size(func()->ui16toa(result_1), 6);
		if( count > 14){ count = 0; updown = 1;}
	}
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

