/********************************************************************
	ATMEGA 32U4 MAPPING
Author: Sergio Manuel Santos
	<sergio.salazar.santos@gmail.com>
License: GNU General Public License
Hardware: Atmega32U4 by ETT ET-BASE
Date: 03122023
Comment:
	Virtual Image Atmega 32U4 mapping and linking.
*********************************************************************/
/*** File Library ***/
#include "atmega32u4mapping.h"

/*** File Define & Macro ***/

/***File Variable***/
//ATMEGA32U4 atmega32u4;

/***File Header***/
uint16_t ATMEGA32U4_ReadHLByte(HighLowByte reg);
uint16_t ATMEGA32U4_ReadLHByte(HighLowByte reg);
HighLowByte ATMEGA32U4_WriteHLByte(uint16_t val);
HighLowByte ATMEGA32U4_WriteLHByte(uint16_t val);
uint16_t ATMEGA32U4_SwapByte(uint16_t num);
uint8_t Atmega32U4_ByteMask(uint8_t target, uint8_t mask);
void Atmega32U4_ByteSet(uint8_t* target, uint8_t set);
void Atmega32U4_ByteClear(uint8_t* target, uint8_t clear);
uint8_t Atmega32U4_ByteShiftright(uint8_t target, uint8_t shift);
uint8_t Atmega32U4_ByteShiftleft(uint8_t target, uint8_t shift);
/******/
void Atmega32U4ClockPrescalerSelect(volatile uint8_t prescaler);
void Atmega32U4MoveInterruptsToBoot(void);
void Atmega32U4MoveInterruptsToSram(void);

/*** File Procedure & Function ***/
ATMEGA32U4 ATMEGA32U4enable(void){
	// Assign
	// GPWR
	atmega32u4.gpwr.reg = (Atmega32U4GPWR_TypeDef*) Atmega32U4GPWR_Address;
	// PORTB
	atmega32u4.portb.reg = (Atmega32U4PORTB_TypeDef*) Atmega32U4PORTB_Address;
	// PORTC
	atmega32u4.portc.reg = (Atmega32U4PORTC_TypeDef*) Atmega32U4PORTC_Address;
	// PORTD
	atmega32u4.portd.reg = (Atmega32U4PORTD_TypeDef*) Atmega32U4PORTD_Address;
	// PORTE
	atmega32u4.porte.reg = (Atmega32U4PORTE_TypeDef*) Atmega32U4PORTE_Address;
	// PORTF
	atmega32u4.portf.reg = (Atmega32U4PORTF_TypeDef*) Atmega32U4PORTF_Address;
	// EXINT
	atmega32u4.exint.reg = (Atmega32U4ExternalInterrupt_TypeDef*) Atmega32U4ExternalInterrupt_Address;
	atmega32u4.exint.iflag = (Atmega32U4ExternalInterruptFlag_TypeDef*) Atmega32U4ExternalInterruptFlag_Address;
	atmega32u4.exint.imask = (Atmega32U4ExternalInterruptMask_TypeDef*) Atmega32U4ExternalInterruptMask_Address;
	#if defined(_INTERRUPT_MODULE_)
		atmega32u4.exint.enable = INTERRUPTenable;
	#endif
	// CPU
	atmega32u4.cpu.gpior0 = (Atmega32U4CpuGeneralPurposeIoRegister0_TypeDef*) Atmega32U4CpuGeneralPurposeIoRegister0_Address;
	atmega32u4.cpu.gpior1 = (Atmega32U4CpuGeneralPurposeIoRegister1_TypeDef*) Atmega32U4CpuGeneralPurposeIoRegister1_Address;
	atmega32u4.cpu.gpior2 = (Atmega32U4CpuGeneralPurposeIoRegister2_TypeDef*) Atmega32U4CpuGeneralPurposeIoRegister2_Address;
	atmega32u4.cpu.reg = (Atmega32U4CPURegister_TypeDef*) Atmega32U4CPURegister_Address;
	//atmega32u4.cpu.smcr = (Atmega32U4CPURegisterSleep_TypeDef*) Atmega32U4CPURegisterSleep_Address;
	//atmega32u4.cpu.mcusr = (Atmega32U4CPURegisterStatus_TypeDef*) Atmega32U4CPURegisterStatus_Address;
	//atmega32u4.cpu.mcucr = (Atmega32U4CPURegisterControl_TypeDef*) Atmega32U4CPURegisterControl_Address;
	//atmega32u4.cpu.state = (Atmega32U4CPURegisterState_TypeDef*) Atmega32U4CPURegisterState_Address;
	//atmega32u4.cpu.power = (Atmega32U4CPURegisterPower_TypeDef*) Atmega32U4CPURegisterPower_Address;
	atmega32u4.cpu.clk = (Atmega32U4CpuClockSelect_TypeDef*) Atmega32U4CpuClockSelect_Address;
	// EEPROM
	atmega32u4.eeprom.reg = (Atmega32U4Eeprom_TypeDef*) Atmega32U4Eeprom_Address;
	#if defined(_EEPROM_MODULE_)
		atmega32u4.eeprom.enable = EEPROMenable;
	#endif
	// TC0
	atmega32u4.tc0.iflag = (Atmega32U4TimerInterruptFlag_TypeDef*) Atmega32U4TimerInterruptFlag_Address;
	atmega32u4.tc0.gcr = (Atmega3U4TimerGeneralControlRegister_TypeDef*) Atmega3U4TimerGeneralControlRegister_Address;
	atmega32u4.tc0.reg = (Atmega32U4TimerCounter0_TypeDef*) Atmega32U4TimerCounter0_Address;
	atmega32u4.tc0.comp = (Atmega32U4TimerCompareRegister0_TypeDef*) Atmega32U4TimerCompareRegister0_Address;
	atmega32u4.tc0.imask = (Atmega32U4TimerInterruptMask_TypeDef*) Atmega32U4TimerInterruptMask_Address;
	#if defined(_TIMER_MODULE_)
		atmega32u4.tc0.enable = TIMER_COUNTER0enable;
	#endif
	// PLL
	atmega32u4.pll.pllcsr = (Atmega32U4PhaseLockedLoopControlStatus_TypeDef*) Atmega32U4PhaseLockedLoopControlStatus_Address;
	atmega32u4.pll.pllfrq = (Atmega32U4PhaseLockedLoopFreq_TypeDef*) Atmega32U4PhaseLockedLoopFreq_Address;
	// SPI
	atmega32u4.spi.reg = (Atmega32U4SerialPeripherialInterface_TypeDef*) Atmega32U4SerialPeripherialInterface_Address;
	#if defined(_SPI_MODULE_)
		atmega32u4.spi.enable = SPIenable;
	#endif
	// AC
	atmega32u4.ac.acsr = (Atmega32U4AnalogComparator_TypeDef*) Atmega32U4AnalogComparator_Address;
	atmega32u4.ac.adcsrb = (Atmega32U4AnalogComparatorCs_TypeDef*) Atmega32U4AnalogComparatorCs_Address;
	atmega32u4.ac.didr1 = (Atmega32U4AnalogComparatorDid_TypeDef*) Atmega32U4AnalogComparatorDid_Address;
	// JTAG
	atmega32u4.jtag.ocdr = (Atmega32U4JtagInterface_TypeDef*) Atmega32U4JtagInterface_Address;
	atmega32u4.jtag.mcusr = (Atmega32U4CPURegisterStatus_TypeDef*) Atmega32U4CPURegisterStatus_Address;
	atmega32u4.jtag.mcucr = (Atmega32U4CPURegisterControl_TypeDef*) Atmega32U4CPURegisterControl_Address;
	// BOOT_LOAD
	atmega32u4.boot_load.spmcsr = (Atmega32U4Bootloader_TypeDef*) Atmega32U4Bootloader_Address;
	// WDT
	atmega32u4.wdt.wdtcsr = (Atmega32U4WatchdogTimer_TypeDef*) Atmega32U4WatchdogTimer_Address;
	// ADC
	atmega32u4.adc.reg = (Atmega32U4AnalogToDigitalConverter_TypeDef*) Atmega32U4AnalogToDigitalConverter_Address;
	#if defined(_ANALOG_MODULE_)
		atmega32u4.adc.enable = ANALOGenable;
	#endif
	// TC1
	atmega32u4.tc1.iflag = (Atmega32U4TimerInterruptFlag_TypeDef*) Atmega32U4TimerInterruptFlag_Address;
	atmega32u4.tc1.gcr = (Atmega3U4TimerGeneralControlRegister_TypeDef*) Atmega3U4TimerGeneralControlRegister_Address;
	atmega32u4.tc1.imask = (Atmega32U4TimerInterruptMask_TypeDef*) Atmega32U4TimerInterruptMask_Address;
	atmega32u4.tc1.reg = (Atmega32U4TimerCounter1_TypeDef*) Atmega32U4TimerCounter1_Address;
	atmega32u4.tc1.comp = (Atmega32U4TimerCompareRegister1_TypeDef*) Atmega32U4TimerCompareRegister1_Address;
	#if defined(_TIMER_MODULE_)
		atmega32u4.tc1.enable = TIMER_COUNTER1enable;
	#endif
	// TC3
	atmega32u4.tc3.iflag = (Atmega32U4TimerInterruptFlag_TypeDef*) Atmega32U4TimerInterruptFlag_Address;
	atmega32u4.tc3.gcr = (Atmega3U4TimerGeneralControlRegister_TypeDef*) Atmega3U4TimerGeneralControlRegister_Address;
	atmega32u4.tc3.imask = (Atmega32U4TimerInterruptMask_TypeDef*) Atmega32U4TimerInterruptMask_Address;
	atmega32u4.tc3.reg = (Atmega32U4TimerCounter3_TypeDef*) Atmega32U4TimerCounter3_Address;
	atmega32u4.tc3.comp = (Atmega32U4TimerCompareRegister3_TypeDef*) Atmega32U4TimerCompareRegister3_Address;
	#if defined(_TIMER_MODULE_)
		atmega32u4.tc3.enable = TIMER_COUNTER3enable;
	#endif
	// TWI
	atmega32u4.twi.reg = (Atmega32U4TwoWireSerialInterface_TypeDef*) Atmega32U4TwoWireSerialInterface_Address;
	#if defined(_TWI_MODULE_)
		atmega32u4.twi.enable = TWIenable;
	#endif
	// TC4
	atmega32u4.tc4.iflag = (Atmega32U4TimerInterruptFlag_TypeDef*) Atmega32U4TimerInterruptFlag_Address;
	atmega32u4.tc4.gcr = (Atmega3U4TimerGeneralControlRegister_TypeDef*) Atmega3U4TimerGeneralControlRegister_Address;
	atmega32u4.tc4.imask = (Atmega32U4TimerInterruptMask_TypeDef*) Atmega32U4TimerInterruptMask_Address;
	atmega32u4.tc4.reg = (Atmega32U4TimerCounter4_TypeDef*) Atmega32U4TimerCounter4_Address;
	atmega32u4.tc4.comp = (Atmega32U4TimerCompareRegister4_TypeDef*) Atmega32U4TimerCompareRegister4_Address;
	#if defined(_TIMER_MODULE_)
		atmega32u4.tc4.enable = TIMER_COUNTER4enable;
	#endif
	// USART1
	atmega32u4.usart1.reg = (Atmega32U4Usart1_TypeDef*) Atmega32U4Usart1_Address;
	#if defined(_USART1_MODULE_)
		atmega32u4.usart1.enable = UARTenable;
	#endif
	// USB_DEVICE
	atmega32u4.usb_device.reg = (Atmega32U4UsbDeviceRegister_TypeDef*) Atmega32U4UsbDeviceRegister_Address;
	// General Func
	atmega32u4.readhlbyte = ATMEGA32U4_ReadHLByte;
	atmega32u4.readlhbyte = ATMEGA32U4_ReadLHByte;
	atmega32u4.writehlbyte = ATMEGA32U4_WriteHLByte;
	atmega32u4.writelhbyte = ATMEGA32U4_WriteLHByte;
	atmega32u4.swapbyte = ATMEGA32U4_SwapByte;
	atmega32u4.byte_mask = Atmega32U4_ByteMask;
	atmega32u4.byte_set = Atmega32U4_ByteSet;
	atmega32u4.byte_clear = Atmega32U4_ByteClear;
	atmega32u4.byte_shiftright = Atmega32U4_ByteShiftright;
	atmega32u4.byte_shiftleft = Atmega32U4_ByteShiftleft;
	/******/
	atmega32u4.Clock_Prescaler_Select = Atmega32U4ClockPrescalerSelect;
	atmega32u4.Move_Interrupts_To_Boot = Atmega32U4MoveInterruptsToBoot;
	atmega32u4.Move_Interrupts_To_Sram = Atmega32U4MoveInterruptsToSram;
	return atmega32u4;
}

// COMMON
uint16_t ATMEGA32U4_ReadHLByte(HighLowByte reg)
{
	return (reg.H << 8) | reg.L;
}

uint16_t ATMEGA32U4_ReadLHByte(HighLowByte reg)
{
	return (reg.L << 8) | reg.H;
}

HighLowByte ATMEGA32U4_WriteHLByte(uint16_t val) // AVR normal little endian
{
	HighLowByte reg; reg.H = (val >> 8); reg.L = val;
	return reg;
}

HighLowByte ATMEGA32U4_WriteLHByte(uint16_t val)
{
	HighLowByte reg; reg.L = (val >> 8); reg.H = val;
	return reg;
}

uint16_t ATMEGA32U4_SwapByte(uint16_t num)
{
	uint16_t tp;
	tp = (num << 8);
	return (num >> 8) | tp;
}

uint8_t Atmega32U4_ByteMask(uint8_t target, uint8_t mask)
{
	return target & mask;
}

void Atmega32U4_ByteSet(uint8_t* target, uint8_t set)
{
	*target |= set;
}

void Atmega32U4_ByteClear(uint8_t* target, uint8_t clear)
{
	*target &= ~clear;
}

uint8_t Atmega32U4_ByteShiftright(uint8_t target, uint8_t shift)
{
	return target >> shift;
}

uint8_t Atmega32U4_ByteShiftleft(uint8_t target, uint8_t shift)
{
	return target << shift;
}

/******/
void Atmega32U4ClockPrescalerSelect(volatile uint8_t prescaler)
{
	volatile uint8_t sreg;
	prescaler &= 0x0F;
	sreg = atmega32u4.cpu.reg->sreg;
	atmega32u4.cpu.reg->sreg &= ~(1 << 7);
	
	CLKPR = (1 << CLKPCE);
	CLKPR = prescaler;
	
	atmega32u4.cpu.reg->sreg = sreg;
}
void Atmega32U4MoveInterruptsToBoot(void)
{
	volatile uint8_t sreg;
	sreg = atmega32u4.cpu.reg->sreg;
	atmega32u4.cpu.reg->sreg &= ~(1 << 7);
	
	/* Enable change of Interrupt Vectors */
	MCUCR = (1<<IVCE);
	/* Move interrupts to Boot Flash section */
	MCUCR = (1<<IVSEL);
	
	atmega32u4.cpu.reg->sreg = sreg;
}
void Atmega32U4MoveInterruptsToSram(void)
{
	volatile uint8_t sreg;
	sreg = atmega32u4.cpu.reg->sreg;
	atmega32u4.cpu.reg->sreg &= ~(1 << 7);
	
	/* Enable change of Interrupt Vectors */
	MCUCR = (1<<IVCE);
	/* Move interrupts to Boot Flash section */
	MCUCR = (0<<IVSEL);
	
	atmega32u4.cpu.reg->sreg = sreg;
}

/*** File Interrupt ***/
// ISR(RESET_vect){}
// ISR(INT0_vect){}
// ISR(INT1_vect){}
// ISR(PCINT0_vect){}
// ISR(PCINT1_vect){}
// ISR(PCINT2_vect){}
// ISR(WDT_vect){}
// ISR(TIMER2_COMPA_vect){}
// ISR(TIMER2_COMPB_vect){}
// ISR(TIMER2_OVF_vect){}
// ISR(TIMER1_CAPT_vect){}
// ISR(TIMER1_COMPA_vect){}
// ISR(TIMER1_COMPB_vect){}
// ISR(TIMER1_OVF_vect){}
// ISR(TIMER0_COMPA_vect){}
// ISR(TIMER0_COMPB_vect){}
// ISR(TIMER0_OVF_vect){}
// ISR(SPI_STC_vect){}
// ISR(USART_RX_vect){}
// ISR(USART_UDRE_vect){}
// ISR(USART_TX_vect){}
// ISR(ADC_vect){}
// ISR(EE_READY_vect){}
// ISR(ANALOG_INTERRUPT)
// ISR(ANALOG_COMP_vect){}
// ISR(TWI_vect){}
// ISR(SPM_READY_vect){}

/***EOF***/

/******
1º Sequence
2º Scope
3º Pointer and Variable
4º Casting
******/

