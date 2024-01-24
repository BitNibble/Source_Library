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
#include "pcf8563rtc.h"

#define TRUE 1
#define ZERO 0

LCD02P lcd;
PCF8563RTC rtc;
struct time tm; // time struct RTC
struct date dt; // date struct RTC

uint16_t count;

int main(void)
{
atmega328_enable();
func_enable();
lcd = lcd02p_enable(&DDRB, &PINB, &PORTB, &DDRC, &PINC, &PORTC);
rtc = pcf8563rtc_enable(16); // RTC with I2C

for ( ; TRUE; ) // Looping
{
	lcd.reboot();
	
	tm=rtc.GetTime();
	dt=rtc.GetDate();
	lcd.gotoxy(0,0);
	lcd.string_size("S:",3);
	lcd.gotoxy(0,8);
	lcd.string_size(func()->ui16toa(rtc.bcd2dec(dt.days)),2);
	lcd.putch(':');
	lcd.string_size(func()->ui16toa(rtc.bcd2dec(dt.century_months)),2);
	lcd.putch(':');
	lcd.string_size(func()->ui16toa(rtc.bcd2dec(dt.years)),2);
	lcd.gotoxy(1,8);
	lcd.string_size(func()->ui16toa(rtc.bcd2dec(tm.hours)),2);
	lcd.putch(':');
	lcd.string_size(func()->ui16toa(rtc.bcd2dec(tm.minutes)),2);
	lcd.putch(':');
	lcd.string_size(func()->ui16toa(rtc.bcd2dec(tm.VL_seconds)),2);
	
	
	//lcd.gotoxy(0,0);
	//lcd.string_size("Welcome", 15);
	//lcd.gotoxy(1,0);
	//lcd.string_size( func()->ui16toa(count), 6 );
	
	
}
} /*** MAIN ***/

/*** File Interrupt ***/

/***EOF***/

/******
1� Sequence
2� Scope
3� Pointer and Variable
4� Casting
******/

