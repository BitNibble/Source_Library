/*************************************************************************
	Atmega328Usart0
Author:	Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega328 by ETT ET-BASE
Update: 01/01/2024
*************************************************************************/
/****** Comment:
	stable
*************************************************************************/
/*** File Library ***/
#include "atmega328usart0.h"
#include "buffer.h"

/*** File Variable ***/
static USART0 setup_usart0;

BUFF rxbuff;
UARTvar UART_Rx;
UARTvar UART_RxBuf[UART_RX_BUFFER_SIZE+1];
uint8_t UART_LastRxError;
static uint8_t uart0flag;

/*** File Header ***/
UARTvar uart_read(void);
UARTvar uart_getch(void);
UARTvar* uart_gets(void);
void uart_rxflush(void);
void uart_write(UARTvar data);
void uart_putch(UARTvar c);
void uart_puts(UARTvar* s);
/*** Complimentary functions ***/
uint8_t USART0ReceiveComplete(void);
uint8_t USART0TransmitComplete(void);
uint8_t USART0DataRegisterEmpty(void);
uint8_t USART0FrameError(void);
uint8_t USART0DataOverRun(void);
uint8_t USART0ParityError(void);
uint8_t USART0ReadErrors(void);
void USART0ClearErrors(void);
void USART0DoubleTransmissionSpeed(void);

/*** Procedure & Function ***/
USART0 usart0_enable(uint32_t baud, unsigned int FDbits, unsigned int Stopbits, unsigned int Parity )
{
	uint8_t tSREG;
	tSREG = cpu_handle()->sreg;
	cpu_handle()->sreg &= ~(1 << GLOBAL_INTERRUPT_ENABLE);
	uart0flag = 1;
	uint16_t ubrr;
	rxbuff = buff_enable(UART_RX_BUFFER_SIZE, UART_RxBuf);
	ubrr = BAUDRATEnormal(baud);
	setup_usart0.par.ubrr = ubrr;
	// Vtable
	setup_usart0.read = uart_read;
	setup_usart0.getch = uart_getch;
	setup_usart0.gets = uart_gets;
	setup_usart0.rxflush = uart_rxflush;
	setup_usart0.write = uart_write;
	setup_usart0.putch = uart_putch;
	setup_usart0.puts = uart_puts;
	// Set baud rate
	if ( ubrr & 0x8000 ) 
	{
   		USART0DoubleTransmissionSpeed();  //Enable 2x speed
		ubrr = BAUDRATEdouble(baud);
   		setup_usart0.par.ubrr = ubrr;
   	}
	usart0_handle()->ubrr0 =  writehlbyte(ubrr);
	// Enable USART receiver and transmitter and receive complete interrupt
	usart0_handle()->ucsr0b = (1 << RXCIE0) | (1 << RXEN0) | (1 << TXEN0);
	
	#ifdef URSEL0 // Set frame format: asynchronous, 8data, no parity, 1stop bit
		usart0_handle()->ucsr0c = (1 << UMSEL0) | (3 << UCSZ00);
		setup_usart0.par.FDbits = 8;
		setup_usart0.par.Stopbits = 1;
		setup_usart0.par.Parity = 0;
	#else
		switch(FDbits){
			case 9:
				usart0_handle()->ucsr0b |= (1 << UCSZ02);
				usart0_handle()->ucsr0c |= (3 << UCSZ00);
				setup_usart0.par.FDbits = 9;
			break;
			case 8:
				usart0_handle()->ucsr0b &= ~(1 << UCSZ02);
				usart0_handle()->ucsr0c |= (3 << UCSZ00);
				setup_usart0.par.FDbits=8;
			break;
			case 7:
				usart0_handle()->ucsr0b &= ~(1 << UCSZ02);
				usart0_handle()->ucsr0c |= (1 << UCSZ01);
				usart0_handle()->ucsr0c &= ~(1 << UCSZ00);
				setup_usart0.par.FDbits=7;
			break;
			case 6:	
				usart0_handle()->ucsr0b &= ~(1 << UCSZ02);
				usart0_handle()->ucsr0c &= ~(1 << UCSZ01);
				usart0_handle()->ucsr0c |= (1 << UCSZ00);
				setup_usart0.par.FDbits = 6;
			break;
			case 5:	
				usart0_handle()->ucsr0b &= ~(1 << UCSZ02);
				usart0_handle()->ucsr0c &= ~(3 << UCSZ00);
				setup_usart0.par.FDbits=5;
			break;
			default:
				usart0_handle()->ucsr0b &= ~(1 << UCSZ02);
				usart0_handle()->ucsr0c |= (3 << UCSZ00);
				setup_usart0.par.FDbits = 8;
			break;
		}
		switch(Stopbits){
			case 1:
				usart0_handle()->ucsr0c &= ~(1 << USBS0);
				setup_usart0.par.Stopbits = 1;
			break;
			case 2:
				usart0_handle()->ucsr0c |= (1 << USBS0);
				setup_usart0.par.Stopbits=2;
			break;	
			default:
				usart0_handle()->ucsr0c &= ~(1 << USBS0);
				setup_usart0.par.Stopbits=1;
			break;
		}
		switch(Parity){
			case 0:
				usart0_handle()->ucsr0c &= ~(3 << UPM00);
				setup_usart0.par.Parity=0;
			break;
			case 2:
				usart0_handle()->ucsr0c |= (1 << UPM01);
				usart0_handle()->ucsr0c &= ~(1 << UPM00);
				setup_usart0.par.Parity=2;
			break;
			case 3:
				usart0_handle()->ucsr0c |= (3 << UPM00);
				setup_usart0.par.Parity=3;
			break;
			default:
				usart0_handle()->ucsr0c &= ~(3 << UPM00);
				setup_usart0.par.Parity=0;
			break;
		}
	#endif
	cpu_handle()->sreg = tSREG;
	cpu_handle()->sreg |= (1 << GLOBAL_INTERRUPT_ENABLE);

	return setup_usart0;
}

USART0* usart0(void){ return &setup_usart0; }

UARTvar uart_read(void)
{
	UARTvar c;
	c = UART_Rx;
	UART_Rx = 0;
	return c;
}
UARTvar uart_getch(void)
{
	return uart_read();
}
UARTvar* uart_gets(void)
{
	return rxbuff.raw(&rxbuff.par);
}
void uart_rxflush(void)
{
	rxbuff.flush(&rxbuff.par);
	UART_LastRxError = 0;
}
void uart_write(UARTvar data)
{
	uint16_t timeout;
	usart0_handle()->ucsr0b |= 1 << UDRIE0;
	usart0_handle()->udr0 = data;
	for( timeout = 600; !USART0DataRegisterEmpty() && timeout; timeout-- ); // minimum -> +/- 450
	//for( ; !USART0DataRegisterEmpty(); ); // without timeout
}
void uart_putch(UARTvar c)
{
	uart_write(c);
}
void uart_puts(UARTvar* s)
{
	char tmp;
	while(*s){
		tmp = *(s++);
		uart_putch(tmp);
	}
}

/*** File Interrupt ***/
ISR(UART_RX_COMPLETE)
{ // USART, RX Complete Handler
	unsigned char bit_8;
    unsigned char usr;
	
	usr = USART0ReadErrors();
    bit_8 = usart0_handle()->ucsr0b;
    bit_8 = 0x01 & (bit_8 >> 1);
	
	if(usr){ UART_LastRxError = usr; }
	
	UART_Rx = usart0_handle()->udr0;
	rxbuff.push(&rxbuff.par, UART_Rx);
}

ISR(UART_UDR_EMPTY)
{ // USART, UDR Empty Handler
	usart0_handle()->ucsr0b &= ~( 1 << UDRIE0 );
}

/*** Complimentary functions ***/
char* usart0_messageprint(USART0* uart, char* oneshot, char* msg, const char* endl)
{
	char* ptr;
	uint8_t length;
	uint8_t endlength = strlen(endl);
	if(uart0flag){ *oneshot = 0; uart0flag = 0; uart->rxflush();} // the matrix
	ptr = uart->gets();
	length = strlen(ptr);
	if(length >= endlength){
		if( !strcmp( ptr+(length-endlength), endl ) ){ strcpy(oneshot, ptr); strcpy(msg, ptr); uart0flag = 0xFF; }
		// default
		//else if( !strcmp( ptr+(length-endlength), "\r" ) ){ strcpy(oneshot, ptr); strcpy(msg, ptr); uart0flag = 0xFF; }
		//else if( !strcmp( ptr+(length-endlength), "\n" ) ){ strcpy(oneshot, ptr); strcpy(msg, ptr); uart0flag = 0xFF; }
	}
	return ptr;
}

/*** Auxiliar ***/
uint8_t USART0ReceiveComplete(void)
{
	return (UCSR0A & (1 << RXC0));
}
uint8_t USART0TransmitComplete(void)
{
	return (UCSR0A & (1 << TXC0));
}
uint8_t USART0DataRegisterEmpty(void)
{
	return (UCSR0A & (1 << UDRE0));
}
uint8_t USART0FrameError(void)
{
	return (UCSR0A & (1 << FE0));
}
uint8_t USART0DataOverRun(void)
{
	return (UCSR0A & (1 << DOR0));
}
uint8_t USART0ParityError(void)
{
	return (UCSR0A & (1 << FE0));
}
uint8_t USART0ReadErrors(void)
{
	return getreg(UCSR0A,3,2);
}
void USART0ClearErrors(void)
{
	setreg(&UCSR0A,3,2,0);
}
void USART0DoubleTransmissionSpeed(void)
{
	setreg(&UCSR0A,4,1,1);
}

/*** EOF ***/

