/******************************************************************************
	STM32 XXX USARTBF
Author: Sergio Santos 
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32-XXX
Date: 23022024
Comment:
	
*******************************************************************************/
#ifndef _STM32USARTBF_H_
	#define _STM32USARTBF_H_

/*** USART BitField Mapping TypeDef ***/
/*** USART -> SR ***/
typedef union{
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
	}bit;
	struct USART_SR_2{
		uint32_t d:10;
		uint32_t fill:22;
	}data;
	uint32_t dword;
}STM32FXXXUSART_SR_TypeDef;
/*** USART -> DR ***/
typedef union{
	struct USART_DR_1{
		uint32_t d:9;
		uint32_t fill:23;
	}data;
	struct USART_DR_2{
		uint32_t b:8;
		uint32_t fill:24;
	}byte;
	uint32_t dword;
}STM32FXXXUSART_DR_TypeDef;
/*** USART -> BRR ***/
typedef union{
	struct USART_BRR_1{
		uint32_t div_fraction:4;
		uint32_t div_mantissa:12;
		uint32_t fill:16;
	}bit;
	struct USART_BRR_2{
		uint32_t d:16;
		uint32_t fill:16;
	}data;
	uint32_t dword;
}STM32FXXXUSART_BRR_TypeDef;
/*** USART -> CR1 ***/
typedef union{
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
	}bit;
struct USART_CR1_2{
		uint32_t w:16;
		uint32_t fill:16;
	}word;
	uint32_t dword;
}STM32FXXXUSART_CR1_TypeDef;
/*** USART -> CR2 ***/
typedef union{
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
	}bit;
struct USART_CR2_2{
		uint32_t d:15;
		uint32_t fill:17;
	}data;
	uint32_t dword;
}STM32FXXXUSART_CR2_TypeDef;
/*** USART -> CR3 ***/
typedef union{
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
	}bit;
struct USART_CR3_2{
		uint32_t d:12;
		uint32_t fill:20;
	}data;
	uint32_t dword;
}STM32FXXXUSART_CR3_TypeDef;
/*** USART -> GTPR ***/
typedef union{
	struct USART_GTPR_1{
		uint32_t psc:8;
		uint32_t gt:8;
		uint32_t fill:16;
	}byte;
	uint32_t dword;
}STM32FXXXUSART_GTPR_TypeDef;

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

