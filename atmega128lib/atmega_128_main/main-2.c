/************************************************************************
Title: SUNTRACK.c
Author: Sergio Manuel Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
File: $Id: MAIN,v 1.8.2.1 21/10/2020 Exp $
Software: Atmel Studio 7 (ver 7.0.129)
Hardware: Atmega128 by ETT ET-BASE
	-PORTA LCD 16X2
	-PORTE Keyboard 4X4
	-PF0 Sensor LDR
	-PB6 Servo Motor
	-PORTD RTC and UART1->FTDI chip->PC Putty or HC-05 115200kb 8 1 n.
	-PORTG HC595
Update: 01/01/2024
Comment:
	-AT+ROLE0\r\n
	-AT+TYPE1\r\n
	-AT+BAUD6\r\n
	-AT+ADVI3\r\n
	-AT+NAMEHome1\r\n
	-AT+PIN916919\r\n
	
	Nice
************************************************************************/
/*** Working Frequency ***/
#define F_CPU 16000000UL
/*** File library ***/
#include "atmega128mapping.h"
#include "function.h"
#include "lcd.h"
#include "pcf8563rtc.h"
#include "keypad.h"
#include "74hc595.h"
#include "hc05atcommands.h"
#include <util/delay.h>

/*** File Constant & Macro ***/
#define TRUE 1
#define ZERO 0
#define Min 500     // 450 PWM servo motor
#define Max 2350    // 2450 PWM servo motor
#define SMIN -200
#define SMAX +200

/*** File variable ***/
struct time tm; // time struct RTC
struct date dt; // date struct RTC

HC595 shift;
PCF8563RTC rtc;

uint8_t count=0; // 1Hz
uint8_t increment=0; // 1Hz
char* ptr = NULL; // pointing to analog reading string
char* uartreceive = NULL; // capture
unsigned int signal;
uint16_t counter1;

/*** File Header ***/
void PORTINIT(void);
ISR(TIMER0_COMP_vect);
ISR(TIMER2_COMP_vect);

/**** Procedure & Function ****/
int main(void)
{
atmega128_enable();
PORTINIT();

atmega128()->adc_enable(1, 128, 1, 0); // Channel 0 for Position
atmega128()->tc0_enable(2,2); // 1Hz to HC595
atmega128()->tc1_enable(9,0); // PWM Positioning
atmega128()->tc2_enable(2,2);
atmega128()->usart1_enable(38400,8,1,NONE); // UART 103 para 9600 (ESP01), 68 para 14400, 25 para 38400 (HC05), 8 para 115200

func_enable(); // Function Library
lcd0_enable(&DDRA,&PINA,&PORTA); // LCD Display 4X20
keypad_enable(&DDRE,&PINE,&PORTE); // Keyboard
rtc = pcf8563rtc_enable(16); // RTC with I2C
shift = hc595_enable(&DDRG,&PORTG,2,0,1);

// local var
char Menu = '1'; // Main menu selector
int AT = 0;
uint16_t adcvalue; // analog reading
char str[6]="0"; // analog vector
int16_t mvalue=0; // manual position reading
int16_t m_value; // manual positioning
char mstr[6]="0"; // manual position vector
char tstr[6]; // time vector
char cal='0'; // Sub Menu for setting up date and time
uint16_t set;
ptr=str;
uint16_t positionhour = 12;
long mapping = 0;
signal = 0;
counter1 = 0;
char* ATmsg = NULL;
char uartmsg[UART1_RX_BUFFER_SIZE]; // Oneshot
char uartmsgprint[UART1_RX_BUFFER_SIZE]; // triggered
uint32_t number1 = 0;
uint8_t tnum = 170;
//uint8_t tnum1 = 0;
//uint16_t var = RAMEND;
// RAMSTART

// Parameters timers
tc0()->compare(249);
tc0()->start(64);
tc1()->compoutmodeB(2);
tc1()->compareA(20000);
tc1()->start(8);
tc2()->start(0);

// rtc setup pin
rtc.SetClkOut(1, 2); // oscillate pin at 1 sec

// TODO:: Please write your application code
while(TRUE){
	// Preamble [INPUT]
	lcd0()->reboot();
	keypad()->read();
		
	uartreceive = usart1_messageprint( atmega128()->usart1, uartmsg, uartmsgprint, "\n");
	// RTC
	tm=rtc.GetTime();
	dt=rtc.GetDate();
	// Reading analog
	adcvalue = adc()->read(0);
	strcpy(str,func()->i16toa(adcvalue));
	
	// catch message
	if(!strcmp(uartreceive,"Connect\r\n")){Menu='6';lcd0()->clear();}
	if(!strcmp(uartreceive,"Connected\r\n")){Menu='6';lcd0()->clear();}
	
	// MENU SELECTOR	
	switch(Menu){
		// MENU 1
		case '1': // Main Program Menu
			if(!strcmp(keypad()->data->string,"A")){Menu='8';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"B")){Menu='2';keypad()->flush();lcd0()->clear();break;}
			// Reading input
			lcd0()->gotoxy(1,0);
			lcd0()->putch(':');
			lcd0()->string_size(keypad()->data->print, 6);
			// ENTRY END
			// Set Position
			if(positionhour>5 && positionhour<21){
				mapping = func()->trimmer(positionhour,2,23,Min,Max);
				mapping += func()->trimmer(adcvalue,0,1023,SMIN,SMAX);
				tc1()->compareB((uint16_t) mapping);
			}else{
				mapping = func()->trimmer(6,2,23,Min,Max);
				tc1()->compareB((uint16_t) mapping);
			}
			lcd0()->gotoxy(0,0);
			lcd0()->string_size("S:",3);
			lcd0()->string_size(str,5);
			lcd0()->gotoxy(0,8);
			lcd0()->string_size(func()->ui16toa(rtc.bcd2dec(dt.days)),2);
			lcd0()->putch(':');
			lcd0()->string_size(func()->ui16toa(rtc.bcd2dec(dt.century_months)),2);
			lcd0()->putch(':');
			lcd0()->string_size(func()->ui16toa(rtc.bcd2dec(dt.years)),2);
			lcd0()->gotoxy(1,8);
			// set hour for positioning
			positionhour=rtc.bcd2dec(tm.hours);
			lcd0()->string_size(func()->ui16toa(positionhour),2);
			lcd0()->putch(':');
			lcd0()->string_size(func()->ui16toa(rtc.bcd2dec(tm.minutes)),2);
			lcd0()->putch(':');
			lcd0()->string_size(func()->ui16toa(rtc.bcd2dec(tm.VL_seconds)),2);
		break;
		// MENU 2
		case '2': // Manual position override 
			if(!strcmp(keypad()->data->string,"A")){Menu='1';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"B")){Menu='3';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"C")){Menu='1';keypad()->flush();lcd0()->clear();usart1()->puts("Manual exit\r\n");break;}
			// Reading input
			lcd0()->gotoxy(1,0);
			lcd0()->putch(':');
			lcd0()->string_size(keypad()->data->print, 6);
			// ENTRY END
			// Title
			lcd0()->gotoxy(0,0);
			lcd0()->string_size("Ang:",5);
			lcd0()->string_size(mstr,3);
			
			if(keypad()->data->character == KEYPADENTERKEY){
				strncpy(mstr,keypad()->data->string,6);
				mvalue=func()->strToInt(mstr);
				if(mvalue >=0 && mvalue <181){
					m_value=mvalue;
					tc1()->compareB(func()->trimmer(m_value,0,180,Min,Max));
					lcd0()->gotoxy(0,12);
					lcd0()->hspace(4);
				}else{
					lcd0()->gotoxy(0,12);
					lcd0()->string_size("err",4);
				}
				keypad()->flush();
			}
			// else
			// tc1.compareB(function.trimmer(m_value,0,180,Min,Max));
			lcd0()->gotoxy(1,12);
			lcd0()->string_size("C-Ex",4);
		break;
		// MENU 3
		case '3': //Set Date
			if(!strcmp(keypad()->data->string,"A")){Menu='2';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"B")){Menu='4';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"C")){Menu='1';cal='0';keypad()->flush();lcd0()->clear();usart1()->puts("Date exit\r\n");break;}
			// Reading input
			lcd0()->gotoxy(1,0);
			lcd0()->putch(':');
			lcd0()->string_size(keypad()->data->print, 6);
			// ENTRY END
			// Menu to set RTC Time and Date
			// Calibrate Menu
			switch(cal){
				case '0': // choice
					lcd0()->gotoxy(0,0);
					lcd0()->string_size("1-Yr",5);
					lcd0()->string_size("2-Mh",5);
					lcd0()->string_size("3-Dy",5);
					lcd0()->gotoxy(1,12);
					lcd0()->string_size("C-Ex",4);
					if(!strcmp(keypad()->data->string,"1")){cal='1';keypad()->flush();lcd0()->clear();}
					if(!strcmp(keypad()->data->string,"2")){cal='2';keypad()->flush();lcd0()->clear();}
					if(!strcmp(keypad()->data->string,"3")){cal='3';keypad()->flush();lcd0()->clear();}
					// if(keypad()->data->character=='1'){cal='1';keypad()->flush();lcd0()->clear();}
				break;
				
				case '1': // YEAR
					lcd0()->gotoxy(1,12);
					lcd0()->string_size("C-Ex",4);
					// YEAR
					if(keypad()->data->character == KEYPADENTERKEY){
						strcpy(tstr,keypad()->data->string);
						set = func()->strToInt(tstr);
						if(set <100){
							rtc.SetYear(rtc.bintobcd(set));
							cal='0';
						}else{
							strcpy(tstr,"err");
						}
						keypad()->flush();
					}
				break;
				
				case '2': // MONTH
					lcd0()->gotoxy(1,12);
					lcd0()->string_size("C-Ex",4);
					// MONTH
					if(keypad()->data->character == KEYPADENTERKEY){
						strcpy(tstr,keypad()->data->string);
						set = func()->strToInt(tstr);
						if(set <13){
							rtc.SetMonth(rtc.bintobcd(set));
							cal='0';
						}else{
							strcpy(tstr,"err");
						}
						keypad()->flush();
					}
				break;
				
				case '3': // DAY
					lcd0()->gotoxy(1,12);
					lcd0()->string_size("C-Ex",4);
					// DAY
					if(keypad()->data->character == KEYPADENTERKEY){
						strcpy(tstr,keypad()->data->string);
						set = func()->strToInt(tstr);
						if(set <32){
							rtc.SetDay(rtc.bintobcd(set));
							cal='0';
						}else{
							strcpy(tstr,"err");
						}
						keypad()->flush();
					}
				break;
				
				default:
					cal='0';
				break;
			};
		break;
		// MENU 4
		case '4': //Set Time
			if(!strcmp(keypad()->data->string,"A")){Menu='3';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"B")){Menu='5';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"C")){Menu='1';cal='0';keypad()->flush();lcd0()->clear();usart1()->puts("Time exit\r\n");break;}
			// Reading input
			lcd0()->gotoxy(1,0);
			lcd0()->putch(':');
			lcd0()->string_size(keypad()->data->print, 6);
			// ENTRY END
			// Menu to set RTC Time and Date
			// Calibrate Menu
			switch(cal){
				case '0': // choice
					lcd0()->gotoxy(0,0);
					lcd0()->string_size("1-Hr",5);
					lcd0()->string_size("2-Mn",5);
					lcd0()->string_size("3-Sc",5);
					lcd0()->gotoxy(1,12);
					lcd0()->string_size("C-Ex",4);
					if(!strcmp(keypad()->data->string,"1")){cal='1';keypad()->flush();lcd0()->clear();}
					if(!strcmp(keypad()->data->string,"2")){cal='2';keypad()->flush();lcd0()->clear();}
					if(!strcmp(keypad()->data->string,"3")){cal='3';keypad()->flush();lcd0()->clear();}
					// if(keypad()->data->character=='1'){cal='1';keypad()->flush();lcd0()->clear();}
				break;
				
				case '1': // HOUR
					lcd0()->gotoxy(1,12);
					lcd0()->string_size("C-Ex",4);
					// HOUR
					if(keypad()->data->character == KEYPADENTERKEY){
						strcpy(tstr,keypad()->data->string);
						set = func()->strToInt(tstr);
						if(set <24){
							rtc.SetHour(rtc.bintobcd(set));
							cal='0';
						}else{
							strcpy(tstr,"err");
						}
						keypad()->flush();
					}
				break;
				
				case '2': // MINUTE
					lcd0()->gotoxy(1,12);
					lcd0()->string_size("C-Ex",4);
					// MINUTE
					if(keypad()->data->character == KEYPADENTERKEY){
						strcpy(tstr,keypad()->data->string);
						set = func()->strToInt(tstr);
						if(set <60){
							rtc.SetMinute(rtc.bintobcd(set));
							cal='0';
						}else{
							strcpy(tstr,"err");
						}
						keypad()->flush();
					}
				break;
				
				case '3': // SECOND
					lcd0()->gotoxy(1,12);
					lcd0()->string_size("C-Ex",4);
					// SECOND
					if(keypad()->data->character == KEYPADENTERKEY){
						strcpy(tstr,keypad()->data->string);
						set = func()->strToInt(tstr);
						if(set <60){
							rtc.SetSecond(rtc.bintobcd(set));
							cal='0';
						}else{
							strcpy(tstr,"err");
						}
						keypad()->flush();
					}
				break;
				default:
					cal='0';
				break;
			};
		break;
		// MENU 5
		case '5': // Output
			if(!strcmp(keypad()->data->string,"A")){Menu='4';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"B")){Menu='6';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"C")){Menu='1';cal='0';keypad()->flush();lcd0()->clear();usart1()->puts("Output exit\r\n");break;}
			// Reading input
			lcd0()->gotoxy(1,0);
			lcd0()->putch(':');
			lcd0()->string_size(keypad()->data->print, 6);
			// ENTRY END
			// Title
			lcd0()->gotoxy(0,0);
			lcd0()->string_size("Out:",5);
			
			lcd0()->string_size(mstr,3);
			if(keypad()->data->character == KEYPADENTERKEY){
				strncpy(mstr,keypad()->data->string,6);
				mvalue=func()->strToInt(mstr);
				if(mvalue >=0 && mvalue <16){
					// PORTC = mvalue;
					atmega128()->portc_reg->port = mvalue;
					lcd0()->gotoxy(0,12);
					lcd0()->hspace(4);
				}else{
					lcd0()->gotoxy(0,12);
					lcd0()->string_size("err",4);
				}
				keypad()->flush();
			}
			lcd0()->gotoxy(1,12);
			lcd0()->string_size("C-Ex",4);
		break;
		// MENU 6
		case '6': // HC-05 Communication
			if(!strcmp(keypad()->data->string,"A")){Menu='5';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"B")){Menu='7';keypad()->flush();lcd0()->clear();break;}
			// if(!strcmp(keypad()->data->string,"C")){Menu='1';cal='0';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"C")){Menu='1';cal='0';keypad()->flush();lcd0()->clear();usart1()->puts("Communication exit\r\n");break;}
			// Reading input
			lcd0()->gotoxy(1,0);
			lcd0()->putch(':');
			lcd0()->string_size(keypad()->data->print, 6);
			// ENTRY END
			// Title
			lcd0()->gotoxy(0,0);
			lcd0()->string_size("HC:",3);
			
			if(!strcmp(uartmsg,"position\r\n")){
				usart1()->puts("> ");
				usart1()->puts("analog Reading: ");
				usart1()->puts(ptr);
				usart1()->puts("\r\n");
				usart1()->rxflush();
			}
			if(!strcmp(uartmsg,"time\r\n")){
				// usart1()->putc('>');usart1()->puts("analog Reading: ");usart1()->puts(ptr);usart()1->puts("\r\n");
				usart1()->puts(func()->ui16toa(rtc.bcd2dec(tm.hours)));
				usart1()->putch(':');
				usart1()->puts(func()->ui16toa(rtc.bcd2dec(tm.minutes)));
				usart1()->putch(':');
				usart1()->puts(func()->ui16toa(rtc.bcd2dec(tm.VL_seconds)));
				usart1()->puts("\r\n");
				usart1()->rxflush();
			}
			if(!strcmp(uartmsg,"s00.\r\n")){
				if(atmega128()->portc_reg->port & 1)
					atmega128()->portc_reg->port &= ~1;
				else
					atmega128()->portc_reg->port |= 1;
			}
			if(!strcmp(uartmsg,"s00 off.\r\n")){
				atmega128()->portc_reg->port &= ~1;
			}
			if(!strcmp(uartmsg,"s01.\r\n")){
				if(atmega128()->portc_reg->port & 2)
					atmega128()->portc_reg->port &= ~2;
				else
					atmega128()->portc_reg->port |= 2;
			}
			if(!strcmp(uartmsg,"s02.\r\n")){
				if(atmega128()->portc_reg->port & 4)
					atmega128()->portc_reg->port &= ~4;
				else
					atmega128()->portc_reg->port |= 4;
			}
			if(!strcmp(uartmsg,"s03.\r\n")){
				if(atmega128()->portc_reg->port & 8)
					atmega128()->portc_reg->port &= ~8;
				else
					atmega128()->portc_reg->port |= 8;
			}
			if(!strcmp(uartmsg,"all on.\r\n")){
				atmega128()->portc_reg->port |= 15;
			}
			if(!strcmp(uartmsg,"all off.\r\n")){
				atmega128()->portc_reg->port &= ~15;
			}
			if(!strcmp(uartmsg,"Disconnect\r\n")){
				Menu = '1';
			}
				
			lcd0()->gotoxy(0,3);
			lcd0()->string_size(uartmsgprint,13);

			lcd0()->gotoxy(1,12);
			lcd0()->string_size("C-Ex",4);
		break;			
		// MENU 7
		case '7': // HC-05 AT
			if(!strcmp(keypad()->data->string,"A")){Menu='6';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"B")){Menu='8';keypad()->flush();lcd0()->clear();break;}
			// if(!strcmp(keypad()->data().string,"C")){Menu='1';cal='0';keypad()->flush();lcd0()->clear();break;}
			if(!strcmp(keypad()->data->string,"C")){Menu='1';cal='0';keypad()->flush();lcd0()->clear();usart1()->puts("AT exit\r\n");break;}
			// Reading input
			lcd0()->gotoxy(1,0);
			lcd0()->putch(':');
			lcd0()->string_size(keypad()->data->print, 6);
			// ENTRY END
			// Title
			lcd0()->gotoxy(0,0);
			lcd0()->string_size("AT:",3);
			// COMMANDS
			if(keypad()->data->character == KEYPADENTERKEY){
				AT = func()->strToInt(keypad()->data->string);
				ATmsg = hc05at_cmd(AT);
				if(ATmsg)
					usart1()->puts(hc05at_cmd(AT));
				keypad()->flush();
			}
			AT = 0;
			
			lcd0()->gotoxy(0,3);
			lcd0()->string_size(uartmsgprint,13);
				
			lcd0()->gotoxy(1,12);
			lcd0()->string_size("C-Ex",4);
		break;
		// MENU 8
		case '8': // Testing Code
		if(!strcmp(keypad()->data->string,"A")){Menu='7';keypad()->flush();lcd0()->clear();break;}
		if(!strcmp(keypad()->data->string,"B")){Menu='1';keypad()->flush();lcd0()->clear();break;}
		if(!strcmp(keypad()->data->string,"C")){Menu='1';cal='0';keypad()->flush();lcd0()->clear();usart1()->puts("Testing exit\r\n");break;}
		// Title
		lcd0()->gotoxy(0,0);
		lcd0()->string_size("T:",2);
		
		/*** Test Area ***/
		lcd0()->gotoxy(0,2);
		number1 = F_CPU/16;
		//atmega128()->writereg(&tnum,2,4,0);
		//tnum1 = atmega128()->readreg(tnum,3,3); // read
		writereg(&tnum,3,3,6); // read
		//lcd0()->string_size( func()->ftoa((float)88/35,5) ,14); // binary
		lcd0()->string_size( func()->ftoa((float)8965/856, 5) ,14); // binary
		//lcd0()->string_size(func()->print_binary(8,tnum),14); // binary
		//lcd0()->string_size(func()->print_binary(8,tnum1),14); // binary
		//lcd0()->string_size(func()->ui16toa(tnum),14); // binary
		//lcd0()->string_size(func()->ui32toa(atmega128.cpu.reg->xdiv),14); // 32 bit max number
		//lcd0()->string_size(func()->ui32toa(4294967295),14); // 32 bit max number
		//lcd0()->string_size(func()->ui32toa(number1),14); // baud
		lcd0()->gotoxy(1,0);
		number1 /= 14400;
		lcd0()->string_size(func()->ui32toa(number1),4);
		lcd0()->gotoxy(1,4);
		number1 -= 1;
		lcd0()->string_size(func()->ui32toa(number1),4);
		
		
		
		
		
		/******/
		// Reading input
		lcd0()->gotoxy(1,9);
		lcd0()->putch(':');
		lcd0()->string_size(keypad()->data->print, 6);
		// ENTRY END
		break;
		//DEFAULT
		default:
			Menu='1';
		break;
	};
	
	switch(signal)
	{
		case 1:
			lcd0()->gotoxy(1,7);
			lcd0()->string_size("T",1);
			signal = 0;
		break;
		default:
		break;
	};
}// WHILE
}// MAIN

void PORTINIT(void)
{
	// INPUT
	atmega128()->portf_reg->ddr = 0x00;
	atmega128()->portf_reg->port = 0x0F;
	// OUTPUT
	atmega128()->portb_reg->ddr |= (1<<5) | (1<<6) | (1<<7);
	// OUTPUT PULLUP
	atmega128()->portc_reg->ddr = 0xFF;
	atmega128()->portc_reg->port = 0x00;
}

/*** File Interrupt ***/
ISR(TIMER0_COMP_vect) // 1Hz and usart Tx
{
	uint8_t Sreg;
	Sreg = atmega128()->cpu_reg->sreg;
	atmega128()->cpu_reg->sreg &= ~(1<<7);
	if(count>59){ //59 -> 1Hz
		increment++;
		if((increment & 0x0F) < 8){
			shift.bit(&shift.par, 0);
			shift.out(&shift.par);
		}else{
			shift.bit(&shift.par, 1);
			shift.out(&shift.par);
		}
		count=0;
	}else
		count++;
	atmega128()->cpu_reg->sreg = Sreg;
}

ISR(TIMER2_COMP_vect)
{
	uint8_t Sreg;
	Sreg = atmega128()->cpu_reg->sreg;
	atmega128()->cpu_reg->sreg &= ~(1<<7);
	
	if(counter1 > 1000){
		// signal = 1;
		counter1=0;
	}
	counter1++;
	
	atmega128()->cpu_reg->sreg = Sreg;
}

/***EOF***/

/**************************** Comment: ******************************
1º Sequence
2º Scope
- Library Scope
- File Scope
- Function Scope
- Precedence Scope
3º Pointers and Variables
4º Casting
A/(b*c*d*e*f) = A/b/c/d/e/f
functions should never return to one of its own parameters, it leads to zero.
********************************************************************/


