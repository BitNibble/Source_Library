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

LCD02P lcd;
PCF8575 pcf8575;
PCF8575 pcf85;

char* uart_receive = NULL; // pointing to Rx Buffer raw
char uart_oneshot[UART_RX_BUFFER_SIZE];
char uart_msg[UART_RX_BUFFER_SIZE];

uint16_t count;

int main(void)
{
atmega328_enable();
func_enable();
lcd02p_enable(&DDRB, &PINB, &PORTB, &DDRC, &PINC, &PORTC);
twi_enable(85,16);
usart0_enable(38400,8,1,NONE);
pcf85 = pcf8575_enable(30, 16);
pcf8575 = pcf8575_enable(32, 16);

uint8_t menu;
for (menu = 1; TRUE; ) // Looping
{
	lcd02p()->reboot();
	count++;
	uart_receive = usart0messageprint( usart0(), uart_oneshot, uart_msg, '.');
	
	switch(menu){ // MENU
		case 1: // Main Program Menu 1
			lcd02p()->gotoxy(0,0);
			lcd02p()->string_size("Welcome", 8); lcd02p()->string_size(func()->ui16toa(count), 6);
			lcd02p()->gotoxy(1,0);
			lcd02p()->putch(':'); lcd02p()->string_size(uart_msg,19);
		break;
		case 2: // Main Program Menu 2
				
		break;
		default:
		break;
	}
	
	//OUT 1
	if(!strcmp( uart_oneshot, "s00." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 0) ) ){
			pcf8575.writehbits( pcf8575.par, 1, (0 << 0) );
			}else{
			pcf8575.writehbits( pcf8575.par, 1, 1);
		}
	}
	//OUT 2
	if(!strcmp( uart_oneshot, "s01." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 1) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 1), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 1), 1 );
		}
	}
	//OUT 3
	if(!strcmp( uart_oneshot, "s02." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 2) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 2), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 2), 1 );
		}
	}
	//OUT 4
	if(!strcmp( uart_oneshot, "s03." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 3) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 3), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 3), 1 );
		}
	}
	//OUT 5
	if(!strcmp( uart_oneshot, "s04." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 4) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 4), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 4), 1 );
		}
	}
	//OUT 6
	if(!strcmp( uart_oneshot, "s05." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 5) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 5), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 5), 1 );
		}
	}
	//OUT 7
	if(!strcmp( uart_oneshot, "s06." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 6) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 6), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 6), 1 );
		}
	}
	//OUT 8
	if(!strcmp( uart_oneshot, "s07." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 7) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 7), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 7), 1 );
		}
	}
	//OUT 9
	if(!strcmp( uart_oneshot, "s08." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 8) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 8), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 8), 1 );
		}
	}
	//OUT 10
	if(!strcmp( uart_oneshot, "s09." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 9) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 9), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 9), 1 );
		}
	}
	//OUT 11
	if(!strcmp( uart_oneshot, "s10." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 10) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 10), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 10), 1 );
		}
	}
	//OUT 12
	if(!strcmp( uart_oneshot, "s11." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 11) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 11), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 11), 1 );
		}
	}
	//OUT 13
	if(!strcmp( uart_oneshot, "s12." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 12) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 12), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 12), 1 );
		}
	}
	//OUT 14
	if(!strcmp( uart_oneshot, "s13." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 13) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 13), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 13), 1 );
		}
	}
	//OUT 15
	if(!strcmp( uart_oneshot, "s14." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 14) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 14), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 14), 1 );
		}
	}
	//OUT 16
	if(!strcmp( uart_oneshot, "s15." )){
		if( pcf8575.readhbits( pcf8575.par, (1 << 15) ) ){
			pcf8575.writehbits( pcf8575.par, (1 << 15), 0 );
			}else{
			pcf8575.writehbits( pcf8575.par, (1 << 15), 1 );
		}
	}
	//
	if(!strcmp( uart_oneshot, "all off." )){
		pcf8575.writehbits( pcf8575.par, 65535, 1 );
	}
	//
	if(!strcmp( uart_oneshot, "all on." )){
		pcf8575.writehbits( pcf8575.par, 65535, 0 );
	}
	
	//STATUS FEEDBACK
	if(!strcmp(uart_oneshot, "status.")){
		usart0()->puts( func()->ui16toa( pcf8575.readhbits( pcf8575.par, 0xFFFF ) ) );
		usart0()->putch('\n');
	}
	
	//_delay_ms(500);
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

