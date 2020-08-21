/*
* STM32F030 Linkerscript
* Copyright (C) 2019 Stefan Strobel <stefan.strobel@shimatta.net>
*
* This file is part of 'STM32F0 code template'.
*
* It is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, version 2 of the License.
*
* This code is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this template.  If not, see <http://www.gnu.org/licenses/>.
* ------------------------------------------------------------------------
*/

/* C++ library init */
# if defined(__cplusplus)
extern "C" {
	extern void __libc_init_array(void);
}
#endif

/* Defines for weak default handlers */
#define WEAK __attribute__((weak))
#define ALIAS(func) __attribute__ ((weak, alias (#func)))

/* Define for section mapping */
#define SECTION(sec) __attribute__((section(sec)))

/* Handler prototypes */
#if defined(_cplusplus)
extern "C" {
#endif


/* Interrupt Defualt handler */
WEAK void __int_default_handler(void);

/* Core Interrupts */
void Reset_Handler(void);
void NMI_Handler(void) ALIAS(__int_default_handler);
void HardFault_Handler(void) ALIAS(__int_default_handler);
void SVCall_Handler(void) ALIAS(__int_default_handler);
void PendSV_Handler(void) ALIAS(__int_default_handler);
void SysTick_Handler(void) ALIAS(__int_default_handler);

/* Peripheral Interrupts (by default mapped onto Default Handler) */
void WWDG_IRQHandler(void) ALIAS(__int_default_handler);
void PVD_VDDIO2_IRQHandler(void) ALIAS(__int_default_handler);
void RTC_IRQHandler(void) ALIAS(__int_default_handler);
void FLASH_IRQHandler(void) ALIAS(__int_default_handler);
void RCC_CRS_IRQHandler(void) ALIAS(__int_default_handler);
void EXTI0_1_IRQHandler(void) ALIAS(__int_default_handler);
void EXTI2_3_IRQHandler(void) ALIAS(__int_default_handler);
void EXTI4_15_IRQHandler(void) ALIAS(__int_default_handler);
void TSC_IRWHandler(void) ALIAS(__int_default_handler);
void DMA_CH1_IRQHandler(void) ALIAS(__int_default_handler);
void DMA_CH2_3_DMA2_CH1_2_IRQHandler(void) ALIAS(__int_default_handler);
void DMA_CH4_5_6_7_DMA2_CH3_4_5_IRQHandler(void) ALIAS(__int_default_handler);
void ADC_COMP_IRQHandler(void) ALIAS(__int_default_handler);
void TIM1_BRK_UP_TRG_COM_IRQHandler(void) ALIAS(__int_default_handler);
void TIM1_CC_IRQHandler(void) ALIAS(__int_default_handler);
void TIM2_IRQHandler(void) ALIAS(__int_default_handler);
void TIM3_IRQHandler(void) ALIAS(__int_default_handler);
void TIM6_DAC_IRQHandler(void) ALIAS(__int_default_handler);
void TIM7_IRQHandler(void) ALIAS(__int_default_handler);
void TIM14_IRQHandler(void) ALIAS(__int_default_handler);
void TIM15_IRQHandler(void) ALIAS(__int_default_handler);
void TIM16_IRQHandler(void) ALIAS(__int_default_handler);
void TIM17_IRQHandler(void) ALIAS(__int_default_handler);
void I2C1_IRQHandler(void) ALIAS(__int_default_handler);
void I2C2_IRQHandler(void) ALIAS(__int_default_handler);
void SPI1_IRQHandler(void) ALIAS(__int_default_handler);
void SPI2_IRQHandler(void) ALIAS(__int_default_handler);
void USART1_IRQHandler(void) ALIAS(__int_default_handler);
void USART2_IRQHandler(void) ALIAS(__int_default_handler);
void USART3_4_5_6_7_8_IRQHandler(void) ALIAS(__int_default_handler);
void CEC_CAN_IRQHandler(void) ALIAS(__int_default_handler);
void USB_IRQHandler(void) ALIAS(__int_default_handler);
    

extern int main(void);
extern void __system_init(void);

extern void __ld_top_of_stack(void);
#if defined(_cplusplus)
extern "C" }
#endif

void (* const vector_table[])(void) SECTION(".vectors") = {
	&__ld_top_of_stack,
	/* Core Interrupts */
	Reset_Handler,
	NMI_Handler,
	HardFault_Handler,
	0,
	0,
	0,
	0,
	0,
	0,
	0,
	SVCall_Handler,
	0,
	0,
	PendSV_Handler,
	SysTick_Handler,
	/* Peripheral Interrupts */
	WWDG_IRQHandler,
	PVD_VDDIO2_IRQHandler,
	RTC_IRQHandler,
	FLASH_IRQHandler,
	RCC_CRS_IRQHandler,
	EXTI0_1_IRQHandler,
	EXTI2_3_IRQHandler,
	EXTI4_15_IRQHandler,
	TSC_IRWHandler,
	DMA_CH1_IRQHandler,
	DMA_CH2_3_DMA2_CH1_2_IRQHandler,
	DMA_CH4_5_6_7_DMA2_CH3_4_5_IRQHandler,
	ADC_COMP_IRQHandler,
	TIM1_BRK_UP_TRG_COM_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM6_DAC_IRQHandler,
	TIM7_IRQHandler,
	TIM14_IRQHandler,
	TIM15_IRQHandler,
	TIM16_IRQHandler,
	TIM17_IRQHandler,
	I2C1_IRQHandler,
	I2C2_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_4_5_6_7_8_IRQHandler,
	CEC_CAN_IRQHandler,
	USB_IRQHandler,
};

static void __init_section(unsigned int *src_start, unsigned int *dest_start, unsigned int *dest_end) {
	unsigned int *get, *put;
	
	put = dest_start;
	get = src_start;
	
	while ((unsigned int)put < (unsigned int)dest_end) {
		*(put++) = *(get++);	
	}
}

static void __fill_zero(unsigned int *start, unsigned int *end) {
	while ((unsigned int) start < (unsigned int)end) {
		*(start++) = 0x00000000;	
	}
}

extern unsigned int __ld_load_data;
extern unsigned int __ld_sitcm;
extern unsigned int __ld_eitcm;
extern unsigned int __ld_sdtcm;
extern unsigned int __ld_edtcm;
extern unsigned int __ld_sdata;
extern unsigned int __ld_edata;
extern unsigned int __ld_sbss;
extern unsigned int __ld_ebss;
extern unsigned int __ld_sheap;
extern unsigned int __ld_eheap;

void Reset_Handler(void) {
	/* Stack is already initilized by hardware */

	/* Copy .data section */
	__init_section(&__ld_load_data, &__ld_sdata, &__ld_edata);
	/* Fill bss with zero */
	__fill_zero(&__ld_sbss, &__ld_ebss);
	/* Fill Heap with zero */
	__fill_zero(&__ld_sheap, &__ld_eheap);
	/* Set clocks, waitstates, ART operation etc. */
	__system_init();
	
	/* C++ init function */
#if defined(__cplusplus)
	__libc_init_array();
#endif
	/* Call main */
	main();	
	
	/* Catch return from main() */
	while(1);
}

WEAK void __int_default_handler(void)
{
	while(1);
}
