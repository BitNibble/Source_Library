/******************************************************************************
	STM32 XXX USART
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 24022024
Comment:
	
*******************************************************************************/
#ifndef _STM32FXXXUSART_H_
	#define _STM32FXXXUSART_H_
/*** Library ***/
#include "armquery.h"
/*** USART 1..6 BitField TypeDef ***/
/*** USART -> SR ***/
volatile typedef union{
	struct USART_SR_1{
		uint32_t pe:1;
		uint32_t fe:1;
		uint32_t nf:1;
		uint32_t ore:1;
		uint32_t idle:1;
		uint32_t rxne:1;
		uint32_t tc:1;
		uint32_t txe:1;
		uint32_t lbd:1;
		uint32_t cts:1;
		uint32_t fill:22;
	}par;
	struct USART_SR_2{
		uint32_t d:10;
		uint32_t fill:22;
	}data;
	uint32_t reg;
}STM32FXXXUSART_SR_TypeDef;
/*** USART -> DR ***/
volatile typedef union{
	struct USART_DR_1{
		uint32_t d:9;
		uint32_t fill:23;
	}data;
	struct USART_DR_2{
		uint32_t b:8;
		uint32_t fill:24;
	}byte;
	uint32_t reg;
}STM32FXXXUSART_DR_TypeDef;
/*** USART -> BRR ***/
volatile typedef union{
	struct USART_BRR_1{
		uint32_t div_fraction:4;
		uint32_t div_mantissa:12;
		uint32_t fill:16;
	}par;
	struct USART_BRR_2{
		uint32_t d:16;
		uint32_t fill:16;
	}data;
	uint32_t reg;
}STM32FXXXUSART_BRR_TypeDef;
/*** USART -> CR1 ***/
volatile typedef union{
	struct USART_CR1_1{
		uint32_t sbk:1;
		uint32_t rwu:1;
		uint32_t re:1;
		uint32_t te:1;
		uint32_t idleie:1;
		uint32_t rxneie:1;
		uint32_t tcie:1;
		uint32_t txeie:1;
		uint32_t peie:1;
		uint32_t ps:1;
		uint32_t pce:1;
		uint32_t wake:1;
		uint32_t m:1;
		uint32_t ue:1;
		uint32_t fill1:1;
		uint32_t over8:1;
		uint32_t fill2:16;
	}par;
	struct USART_CR1_2{
		uint32_t w:16;
		uint32_t fill:16;
	}data;
	uint32_t reg;
}STM32FXXXUSART_CR1_TypeDef;
/*** USART -> CR2 ***/
volatile typedef union{
	struct USART_CR2_1{
		uint32_t add:4;
		uint32_t fill1:1;
		uint32_t lbdl:1;
		uint32_t lbdie:1;
		uint32_t fill2:1;
		uint32_t lbcl:1;
		uint32_t cpha:1;
		uint32_t cpol:1;
		uint32_t clken:1;
		uint32_t stop:2;
		uint32_t linen:1;
		uint32_t fill3:17;
	}par;
	struct USART_CR2_2{
		uint32_t d:15;
		uint32_t fill:17;
	}data;
	uint32_t reg;
}STM32FXXXUSART_CR2_TypeDef;
/*** USART -> CR3 ***/
volatile typedef union{
	struct USART_CR3_1{
		uint32_t eie:1;
		uint32_t iren:1;
		uint32_t irlp:1;
		uint32_t hdsel:1;
		uint32_t nack:1;
		uint32_t scen:1;
		uint32_t dmar:1;
		uint32_t dmat:1;
		uint32_t rtse:1;
		uint32_t ctse:1;
		uint32_t ctsie:1;
		uint32_t onebit:1;
		uint32_t fill:20;
	}par;
struct USART_CR3_2{
		uint32_t d:12;
		uint32_t fill:20;
	}data;
	uint32_t reg;
}STM32FXXXUSART_CR3_TypeDef;
/*** USART -> GTPR ***/
volatile typedef union{
	struct USART_GTPR_1{
		uint32_t psc:8;
		uint32_t gt:8;
		uint32_t fill:16;
	}par;
	uint32_t reg;
}STM32FXXXUSART_GTPR_TypeDef;
/*** USART 1..6 Handler TypeDef ***/
// USART -> USART1,2,3,6
typedef struct
{

	/*** Bit Mapping ***/
	STM32FXXXUSART_SR_TypeDef* sr;
	STM32FXXXUSART_BRR_TypeDef* brr;
	STM32FXXXUSART_CR1_TypeDef* cr1;
	STM32FXXXUSART_CR2_TypeDef* cr2;
	STM32FXXXUSART_CR3_TypeDef* cr3;
	STM32FXXXUSART_GTPR_TypeDef* gtpr;
	STM32FXXXUSART_DR_TypeDef* dr;
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
	void (*parameter)( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
}STM32FXXX_USART1, STM32FXXX_USART2, STM32FXXX_USART3, STM32FXXX_USART6;
// USART -> UART4,5
typedef struct
{

	/*** Bit Mapping ***/
	STM32FXXXUSART_SR_TypeDef* sr;
	STM32FXXXUSART_BRR_TypeDef* brr;
	STM32FXXXUSART_CR1_TypeDef* cr1;
	STM32FXXXUSART_CR2_TypeDef* cr2;
	STM32FXXXUSART_CR3_TypeDef* cr3;
	STM32FXXXUSART_GTPR_TypeDef* gtpr;
	STM32FXXXUSART_DR_TypeDef* dr;
	/*** Other ***/
	void (*clock)(uint8_t bool);
	void (*nvic)(uint8_t bool);
	void (*parameter)( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
}STM32FXXX_UART4, STM32FXXX_UART5;

STM32FXXX_USART1* usart1_enable(void);
STM32FXXX_USART1*  usart1(void);

STM32FXXX_USART2* usart2_enable(void);
STM32FXXX_USART2*  usart2(void);

STM32FXXX_USART3* usart3_enable(void);
STM32FXXX_USART3*  usart3(void);

STM32FXXX_UART4* uart4_enable(void);
STM32FXXX_UART4*  uart4(void);

STM32FXXX_UART5* uart5_enable(void);
STM32FXXX_UART5*  uart5(void);

STM32FXXX_USART6* usart6_enable(void);
STM32FXXX_USART6*  usart6(void);
/*** USART1 Header ***/
void STM32FXXXUsart1Clock( uint8_t bool );
void STM32FXXXUsart1Nvic( uint8_t bool );
void STM32FXXXUsart1Inic( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
void STM32FXXXUsart1Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
/*** USART2 Header ***/
void STM32FXXXUsart2Clock( uint8_t bool );
void STM32FXXXUsart2Nvic( uint8_t bool );
void STM32FXXXUsart2Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
/*** USART3 Header ***/
void STM32FXXXUsart3Clock( uint8_t bool );
void STM32FXXXUsart3Nvic( uint8_t bool );
void STM32FXXXUsart3Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
/*** UART4 Header ***/
void STM32FXXXUart4Clock( uint8_t bool );
void STM32FXXXUart4Nvic( uint8_t bool );
void STM32FXXXUart4Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
/*** UART5 Header ***/
void STM32FXXXUart5Clock( uint8_t bool );
void STM32FXXXUart5Nvic( uint8_t bool );
void STM32FXXXUart5Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
/*** USART6 Header ***/
void STM32FXXXUsart6Clock( uint8_t bool );
void STM32FXXXUsart6Nvic( uint8_t bool );
void STM32FXXXUsart6Parameter( uint8_t wordlength, uint8_t samplingmode, double stopbits, uint32_t baudrate );
/*** INTERRUPT HEADER ***/
void USART1_IRQHandler(void);
void USART2_IRQHandler(void);
void USART3_IRQHandler(void);
void UART4_IRQHandler(void);
void UART5_IRQHandler(void);
void USART6_IRQHandler(void);

#endif
/*** EOF ***/

/******
1º Sequence
2º Scope
	- Library Scope
	- File Scope
	- Function Scope
	- Precedence Scope
3º Pointer and Variable
4º Casting
******/

