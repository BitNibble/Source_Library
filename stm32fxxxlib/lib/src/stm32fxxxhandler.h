/************************************************************************
	STM32FXXX
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: STM32FXXX
Update: 07/01/2024
Comment:
	
************************************************************************/
#ifndef _STM32FXXXHANDLER_H_
	#define _STM32FXXXHANDLER_H_

/************ CMSIS BASE *************/
// SELECTION OF CHIP (CMSIS Access to its libraries)
// Options: __STM32F446xx_H    __STM32F411xE_H
#include "stm32f4xx.h"
#include <inttypes.h>
/*** General Purpose Bit field ***/
typedef union{
	struct UN32nibble{
		uint32_t n0:4;
		uint32_t n1:4;
		uint32_t n2:4;
		uint32_t n3:4;
		uint32_t n4:4;
		uint32_t n5:4;
		uint32_t n6:4;
		uint32_t n7:4;
	}nibble;
	struct UN32byte{
		uint8_t b0;
		uint8_t b1;
		uint8_t b2;
		uint8_t b3;
	}byte;
	struct UN32word{
		uint16_t w0;
		uint16_t w1;
	}word;
	uint32_t n;
}_UN32var;
typedef union{
	struct UN64nibble{
		uint32_t n0:4;
		uint32_t n1:4;
		uint32_t n2:4;
		uint32_t n3:4;
		uint32_t n4:4;
		uint32_t n5:4;
		uint32_t n6:4;
		uint32_t n7:4;
		uint32_t n8:4;
		uint32_t n9:4;
		uint32_t n10:4;
		uint32_t n11:4;
		uint32_t n12:4;
		uint32_t n13:4;
		uint32_t n14:4;
		uint32_t n15:4;
	}nibble;
	struct UN64byte{
		uint8_t b0;
		uint8_t b1;
		uint8_t b2;
		uint8_t b3;
		uint8_t b4;
		uint8_t b5;
		uint8_t b6;
		uint8_t b7;
	}byte;
	struct UN64word{
		uint16_t w0;
		uint16_t w1;
		uint16_t w2;
		uint16_t w3;
	}word;
	struct UN64dword{
		uint32_t d0;
		uint32_t d1;
	}dword;
	uint64_t n;
}_UN64var;
/*** Alternative CMSIS replacement ***/
#include "stm32gpiobf.h"
#include "stm32rccbf.h"
#include "stm32timbf.h"
#include "stm32usartbf.h"
#include "stm32adcbf.h"
#include "stm32i2cbf.h"
/*************************************/
/********* HARDWARE HANDLER **********/
/*************************************/
/*** ADC ***/
//ADC_TypeDef* adc1_handle(void);
//STM32FXXXADC_TypeDef* adc1_handle(void);
volatile void* adc1_handle(void);
//ADC_TypeDef* adc2_handle(void);
//ADC_TypeDef* adc3_handle(void);
volatile void* adc2_handle(void);
volatile void* adc3_handle(void);
//ADC_Common_TypeDef* adc_common_handle(void);
//STM32FXXXADC_COMMON_TypeDef* adc_common_handle(void);
volatile void* adc_common_handle(void);
#ifdef __STM32F446xx_H
/*** CAN ***/
CAN_TypeDef* can1_handle(void);
CAN_TypeDef* can2_handle(void);
/*** CEC ***/
CEC_TypeDef* cec_handle(void);
#endif
/*** CRC ***/
CRC_TypeDef* crc_handle(void);
#ifdef __STM32F446xx_H_H
/*** DAC ***/
DAC_TypeDef* dac_handle(void);
#endif
/*** DBGMCU ***/
DBGMCU_TypeDef* dbgmcu_handle(void);
#ifdef __STM32F446xx_H_H
/*** DCMI ***/
DCMI_TypeDef* dcmi_handle(void);
#endif
/*** DMA ***/
DMA_TypeDef* dma1_handle(void);
DMA_Stream_TypeDef* dma1_stream0_handle(void);
DMA_Stream_TypeDef* dma1_stream1_handle(void);
DMA_Stream_TypeDef* dma1_stream2_handle(void);
DMA_Stream_TypeDef* dma1_stream3_handle(void);
DMA_Stream_TypeDef* dma1_stream4_handle(void);
DMA_Stream_TypeDef* dma1_stream5_handle(void);
DMA_Stream_TypeDef* dma1_stream6_handle(void);
DMA_Stream_TypeDef* dma1_stream7_handle(void);
DMA_TypeDef* dma2_handle(void);
DMA_Stream_TypeDef* dma2_stream0_handle(void);
DMA_Stream_TypeDef* dma2_stream1_handle(void);
DMA_Stream_TypeDef* dma2_stream2_handle(void);
DMA_Stream_TypeDef* dma2_stream3_handle(void);
DMA_Stream_TypeDef* dma2_stream4_handle(void);
DMA_Stream_TypeDef* dma2_stream5_handle(void);
DMA_Stream_TypeDef* dma2_stream6_handle(void);
DMA_Stream_TypeDef* dma2_stream7_handle(void);
/*** EXTI ***/
EXTI_TypeDef* exti_handle(void);
/*** FLASH ***/
FLASH_TypeDef* flash_handle(void);
#ifdef __STM32F446xx_H_H
/*** FMC ***/
FMC_Bank1_TypeDef* fmc_bank1_handle(void);
FMC_Bank1E_TypeDef* fmc_bank1e_handle(void);
FMC_Bank3_TypeDef* fmc_bank3_handle(void);
FMC_Bank5_6_TypeDef* fmc_bank5_6_handle(void);
#endif
/*** GPIO ***/
//GPIO_TypeDef* gpioa_handle(void);
//GPIO_TypeDef* gpiob_handle(void);
//GPIO_TypeDef* gpioc_handle(void);
//GPIO_TypeDef* gpiod_handle(void);
//GPIO_TypeDef* gpioe_handle(void);
//GPIO_TypeDef* gpiof_handle(void);
//GPIO_TypeDef* gpiog_handle(void);
//GPIO_TypeDef* gpioh_handle(void);
//STM32FXXXGPIOX_TypeDef* gpioa_handle(void);
//STM32FXXXGPIOX_TypeDef* gpiob_handle(void);
//STM32FXXXGPIOX_TypeDef* gpioc_handle(void);
//STM32FXXXGPIOX_TypeDef* gpiod_handle(void);
//STM32FXXXGPIOX_TypeDef* gpioe_handle(void);
//STM32FXXXGPIOX_TypeDef* gpiof_handle(void);
//STM32FXXXGPIOX_TypeDef* gpiog_handle(void);
//STM32FXXXGPIOX_TypeDef* gpioh_handle(void);
volatile void* gpioa_handle(void);
volatile void* gpiob_handle(void);
volatile void* gpioc_handle(void);
volatile void* gpiod_handle(void);
volatile void* gpioe_handle(void);
volatile void* gpiof_handle(void);
volatile void* gpiog_handle(void);
volatile void* gpioh_handle(void);
/*** SYSCFG ***/
SYSCFG_TypeDef* syscfg_handle(void);
/*** I2C ***/
I2C_TypeDef* i2c1_handle(void);
//I2C_TypeDef* i2c2_handle(void);
//I2C_TypeDef* i2c3_handle(void);
//volatile void* i2c1_handle(void);
volatile void* i2c2_handle(void);
volatile void* i2c3_handle(void);
#ifdef __STM32F446xx_H_H
/*** FMPI2C ***/
FMPI2C_TypeDef* fmpi2c1_handle(void);
#endif
/*** IWDG ***/
IWDG_TypeDef* iwdg_handle(void);
/*** PWR ***/
PWR_TypeDef* pwr_handle(void);
/*** RCC ***/
//RCC_TypeDef* rcc_handle(void);
//STM32FXXXRCC_TypeDef* rcc_handle(void);
volatile void* rcc_handle(void);
/*** RTC ***/
RTC_TypeDef* rtc_handle(void);
/*** SAI ***/
#ifdef __STM32F446xx_H_H
SAI_TypeDef* sai1_handle(void){return (SAI_TypeDef*) SAI1_BASE;}
SAI_Block_TypeDef* sai1_block_a_handle(void);
SAI_Block_TypeDef* sai1_block_b_handle(void);
SAI_TypeDef* sai2_handle(void);
SAI_Block_TypeDef* sai2_block_a_handle(void);
SAI_Block_TypeDef* sai2_block_b_handle(void);
#endif
/*** SDIO ***/
SDIO_TypeDef* sdio_handle(void);
/*** SPI ***/
SPI_TypeDef* spi1_handle(void);
SPI_TypeDef* spi2_handle(void);
SPI_TypeDef* spi3_handle(void);
SPI_TypeDef* spi4_handle(void);
#ifdef __STM32F446xx_H_H
/*** QUADSPI ***/
QUADSPI_TypeDef* quadspi_handle(void);
/*** SPDIFRX ***/
SPDIFRX_TypeDef* spdifrx_handle(void);
#endif
/*** TIM ***/
//TIM_TypeDef* tim1_handle(void);
//TIM_TypeDef* tim2_handle(void);
//TIM_TypeDef* tim3_handle(void);
//TIM_TypeDef* tim4_handle(void);
//TIM_TypeDef* tim5_handle(void);
//TIM_TypeDef* tim6_handle(void);
//TIM_TypeDef* tim7_handle(void);
//TIM_TypeDef* tim8_handle(void);
//TIM_TypeDef* tim9_handle(void);
//TIM_TypeDef* tim10_handle(void);
//TIM_TypeDef* tim11_handle(void);
//TIM_TypeDef* tim12_handle(void);
//TIM_TypeDef* tim13_handle(void);
//TIM_TypeDef* tim14_handle(void);
//STM32FXXXTIMXX_TypeDef* tim1_handle(void);
//STM32FXXXTIMXX_TypeDef* tim2_handle(void);
//STM32FXXXTIMXX_TypeDef* tim3_handle(void);
//STM32FXXXTIMXX_TypeDef* tim4_handle(void);
//STM32FXXXTIMXX_TypeDef* tim5_handle(void);
//STM32FXXXTIMXX_TypeDef* tim6_handle(void);
//STM32FXXXTIMXX_TypeDef* tim7_handle(void);
//STM32FXXXTIMXX_TypeDef* tim8_handle(void);
//STM32FXXXTIMXX_TypeDef* tim9_handle(void);
//STM32FXXXTIMXX_TypeDef* tim10_handle(void);
//STM32FXXXTIMXX_TypeDef* tim11_handle(void);
//STM32FXXXTIMXX_TypeDef* tim12_handle(void);
//STM32FXXXTIMXX_TypeDef* tim13_handle(void);
//STM32FXXXTIMXX_TypeDef* tim14_handle(void);
volatile void* tim1_handle(void);
volatile void* tim2_handle(void);
volatile void* tim3_handle(void);
volatile void* tim4_handle(void);
volatile void* tim5_handle(void);
volatile void* tim6_handle(void);
volatile void* tim7_handle(void);
volatile void* tim8_handle(void);
volatile void* tim9_handle(void);
volatile void* tim10_handle(void);
volatile void* tim11_handle(void);
volatile void* tim12_handle(void);
volatile void* tim13_handle(void);
volatile void* tim14_handle(void);
/*** USART ***/
//USART_TypeDef* usart1_handle(void);
//USART_TypeDef* usart2_handle(void);
//USART_TypeDef* usart3_handle(void);
//USART_TypeDef* uart4_handle(void);
//USART_TypeDef* uart5_handle(void);
//USART_TypeDef* usart6_handle(void);
//TM32FXXXUSARTX_TypeDef* usart1_handle(void);
//TM32FXXXUSARTX_TypeDef* usart2_handle(void);
//TM32FXXXUSARTX_TypeDef* usart3_handle(void);
//TM32FXXXUSARTX_TypeDef* uart4_handle(void);
//TM32FXXXUSARTX_TypeDef* uart5_handle(void);
//TM32FXXXUSARTX_TypeDef* usart6_handle(void);
volatile void* usart1_handle(void);
volatile void* usart2_handle(void);
volatile void* usart3_handle(void);
volatile void* uart4_handle(void);
volatile void* uart5_handle(void);
volatile void* usart6_handle(void);
/*** WWDG ***/
WWDG_TypeDef* wwdg_handle(void);
/*** USB ***/
USB_OTG_GlobalTypeDef* usb_otg_global_handle(void);
USB_OTG_DeviceTypeDef* usb_otg_device_handle(void);
USB_OTG_INEndpointTypeDef* usb_otg_inendpoint_handle(void);
USB_OTG_OUTEndpointTypeDef* usb_otg_outendpoint_handle(void);
USB_OTG_HostTypeDef* usb_otg_host_handle(void);
USB_OTG_HostChannelTypeDef* usb_otg_hotchannel_handle(void);

#endif

/***
Use volatile void*, so it will be copied to its type or needs to be casted to a type.
***/

/*** EOF ***/

