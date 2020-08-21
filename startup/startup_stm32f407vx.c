/*
* STM32F4 Startup Code for STM32F407 devices
* Copyright (C) 2017 Mario Hüttel <mario.huettel@gmx.net>
*
* This file is part of 'STM32F4 code template'.
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
void MemManage_Handler(void) ALIAS(__int_default_handler);
void BusFault_Handler(void) ALIAS(__int_default_handler);
void UsageFault_Handler(void) ALIAS(__int_default_handler);
void SVC_Handler(void) ALIAS(__int_default_handler);
void DebugMon_Handler(void) ALIAS(__int_default_handler);
void PendSV_Handler(void) ALIAS(__int_default_handler);
void SysTick_Handler(void) ALIAS(__int_default_handler);

/* Peripheral Interrupts (by default mapped onto Default Handler) */
void WWDG_IRQHandler(void) ALIAS(__int_default_handler);
void PVD_IRQHandler(void) ALIAS(__int_default_handler);
void TAMP_STAMP_IRQHandler(void) ALIAS(__int_default_handler);
void RTC_WKUP_IRQHandler(void) ALIAS(__int_default_handler);
void FLASH_IRQHandler(void) ALIAS(__int_default_handler);
void RCC_IRQHandler(void) ALIAS(__int_default_handler);
void EXTI0_IRQHandler(void) ALIAS(__int_default_handler);
void EXTI1_IRQHandler(void) ALIAS(__int_default_handler);
void EXTI2_IRQHandler(void) ALIAS(__int_default_handler);
void EXTI3_IRQHandler(void) ALIAS(__int_default_handler);
void EXTI4_IRQHandler(void) ALIAS(__int_default_handler);
void DMA1_Stream0_IRQHandler(void) ALIAS(__int_default_handler);
void DMA1_Stream1_IRQHandler(void) ALIAS(__int_default_handler);
void DMA1_Stream2_IRQHandler(void) ALIAS(__int_default_handler);
void DMA1_Stream3_IRQHandler(void) ALIAS(__int_default_handler);
void DMA1_Stream4_IRQHandler(void) ALIAS(__int_default_handler);
void DMA1_Stream5_IRQHandler(void) ALIAS(__int_default_handler);
void DMA1_Stream6_IRQHandler(void) ALIAS(__int_default_handler);
void ADC_IRQHandler(void) ALIAS(__int_default_handler);
void CAN1_TX_IRQHandler(void) ALIAS(__int_default_handler);
void CAN1_RX0_IRQHandler(void) ALIAS(__int_default_handler);
void CAN1_RX1_IRQHandler(void) ALIAS(__int_default_handler);
void CAN1_SCE_IRQHandler(void) ALIAS(__int_default_handler);
void EXTI9_5_IRQHandler(void) ALIAS(__int_default_handler);
void TIM1_BRK_TIM9_IRQHandler(void) ALIAS(__int_default_handler);
void TIM1_UP_TIM10_IRQHandler(void) ALIAS(__int_default_handler);
void TIM1_TRG_COM_TIM11_IRQHandler(void) ALIAS(__int_default_handler);
void TIM1_CC_IRQHandler(void) ALIAS(__int_default_handler);
void TIM2_IRQHandler(void) ALIAS(__int_default_handler);
void TIM3_IRQHandler(void) ALIAS(__int_default_handler);
void TIM4_IRQHandler(void) ALIAS(__int_default_handler);
void I2C1_EV_IRQHandler(void) ALIAS(__int_default_handler);
void I2C1_ER_IRQHandler(void) ALIAS(__int_default_handler);
void I2C2_EV_IRQHandler(void) ALIAS(__int_default_handler);
void I2C2_ER_IRQHandler(void) ALIAS(__int_default_handler);
void SPI1_IRQHandler(void) ALIAS(__int_default_handler);
void SPI2_IRQHandler(void) ALIAS(__int_default_handler);
void USART1_IRQHandler(void) ALIAS(__int_default_handler);
void USART2_IRQHandler(void) ALIAS(__int_default_handler);
void USART3_IRQHandler(void) ALIAS(__int_default_handler);
void EXTI15_10_IRQHandler(void) ALIAS(__int_default_handler);
void RTC_Alarm_IRQHandler(void) ALIAS(__int_default_handler);
void OTG_FS_WKUP_IRQHandler(void) ALIAS(__int_default_handler);
void TIM8_BRK_TIM12_IRQHandler(void) ALIAS(__int_default_handler);
void TIM8_UP_TIM13_IRQHandler(void) ALIAS(__int_default_handler);
void TIM8_TRG_COM_TIM14_IRQHandler(void) ALIAS(__int_default_handler);
void TIM8_CC_IRQHandler(void) ALIAS(__int_default_handler);
void DMA1_Stream7_IRQHandler(void) ALIAS(__int_default_handler);
void FSMC_IRQHandler(void) ALIAS(__int_default_handler);
void SDIO_IRQHandler(void) ALIAS(__int_default_handler);
void TIM5_IRQHandler(void) ALIAS(__int_default_handler);
void SPI3_IRQHandler(void) ALIAS(__int_default_handler);
void UART4_IRQHandler(void) ALIAS(__int_default_handler);
void UART5_IRQHandler(void) ALIAS(__int_default_handler);
void TIM6_DAC_IRQHandler(void) ALIAS(__int_default_handler);
void TIM7_IRQHandler(void) ALIAS(__int_default_handler);
void DMA2_Stream0_IRQHandler(void) ALIAS(__int_default_handler);
void DMA2_Stream1_IRQHandler(void) ALIAS(__int_default_handler);
void DMA2_Stream2_IRQHandler(void) ALIAS(__int_default_handler);
void DMA2_Stream3_IRQHandler(void) ALIAS(__int_default_handler);
void DMA2_Stream4_IRQHandler(void) ALIAS(__int_default_handler);
void ETH_IRQHandler(void) ALIAS(__int_default_handler);
void ETH_WKUP_IRQHandler(void) ALIAS(__int_default_handler);
void CAN2_TX_IRQHandler(void) ALIAS(__int_default_handler);
void CAN2_RX0_IRQHandler(void) ALIAS(__int_default_handler);
void CAN2_RX1_IRQHandler(void) ALIAS(__int_default_handler);
void CAN2_SCE_IRQHandler(void) ALIAS(__int_default_handler);
void OTG_FS_IRQHandler(void) ALIAS(__int_default_handler);
void DMA2_Stream5_IRQHandler(void) ALIAS(__int_default_handler);
void DMA2_Stream6_IRQHandler(void) ALIAS(__int_default_handler);
void DMA2_Stream7_IRQHandler(void) ALIAS(__int_default_handler);
void USART6_IRQHandler(void) ALIAS(__int_default_handler);
void I2C3_EV_IRQHandler(void) ALIAS(__int_default_handler);
void I2C3_ER_IRQHandler(void) ALIAS(__int_default_handler);
void OTG_HS_EP1_OUT_IRQHandler(void) ALIAS(__int_default_handler);
void OTG_HS_EP1_IN_IRQHandler(void) ALIAS(__int_default_handler);
void OTG_HS_WKUP_IRQHandler(void) ALIAS(__int_default_handler);
void OTG_HS_IRQHandler(void) ALIAS(__int_default_handler);
void DCMI_IRQHandler(void) ALIAS(__int_default_handler);
void CRYP_IRQHandler(void) ALIAS(__int_default_handler);
void HASH_RNG_IRQHandler(void) ALIAS(__int_default_handler);
void FPU_IRQHandler(void) ALIAS(__int_default_handler);    

extern int main(void);
extern void SystemInit(void);

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
	MemManage_Handler,
	BusFault_Handler,
	UsageFault_Handler,
	0,
	0,
	0,
	0,
	SVC_Handler,
	DebugMon_Handler,
	0,
	PendSV_Handler,
	SysTick_Handler,
	/* Peripheral Interrupts */
	WWDG_IRQHandler,
	PVD_IRQHandler,
	TAMP_STAMP_IRQHandler,
	RTC_WKUP_IRQHandler,
	FLASH_IRQHandler,
	RCC_IRQHandler,
	EXTI0_IRQHandler,
	EXTI1_IRQHandler,
	EXTI2_IRQHandler,
	EXTI3_IRQHandler,
	EXTI4_IRQHandler,
	DMA1_Stream0_IRQHandler,
	DMA1_Stream1_IRQHandler,
	DMA1_Stream2_IRQHandler,
	DMA1_Stream3_IRQHandler,
	DMA1_Stream4_IRQHandler,
	DMA1_Stream5_IRQHandler,
	DMA1_Stream6_IRQHandler,
	ADC_IRQHandler,
	CAN1_TX_IRQHandler,
	CAN1_RX0_IRQHandler,
	CAN1_RX1_IRQHandler,
	CAN1_SCE_IRQHandler,
	EXTI9_5_IRQHandler,
	TIM1_BRK_TIM9_IRQHandler,
	TIM1_UP_TIM10_IRQHandler,
	TIM1_TRG_COM_TIM11_IRQHandler,
	TIM1_CC_IRQHandler,
	TIM2_IRQHandler,
	TIM3_IRQHandler,
	TIM4_IRQHandler,
	I2C1_EV_IRQHandler,
	I2C1_ER_IRQHandler,
	I2C2_EV_IRQHandler,
	I2C2_ER_IRQHandler,
	SPI1_IRQHandler,
	SPI2_IRQHandler,
	USART1_IRQHandler,
	USART2_IRQHandler,
	USART3_IRQHandler,
	EXTI15_10_IRQHandler,
	RTC_Alarm_IRQHandler,
	OTG_FS_WKUP_IRQHandler,
	TIM8_BRK_TIM12_IRQHandler,
	TIM8_UP_TIM13_IRQHandler,
	TIM8_TRG_COM_TIM14_IRQHandler,
	TIM8_CC_IRQHandler,
	DMA1_Stream7_IRQHandler,
	FSMC_IRQHandler,
	SDIO_IRQHandler,
	TIM5_IRQHandler,
	SPI3_IRQHandler,
	UART4_IRQHandler,
	UART5_IRQHandler,
	TIM6_DAC_IRQHandler,
	TIM7_IRQHandler,
	DMA2_Stream0_IRQHandler,
	DMA2_Stream1_IRQHandler,
	DMA2_Stream2_IRQHandler,
	DMA2_Stream3_IRQHandler,
	DMA2_Stream4_IRQHandler,
	ETH_IRQHandler,
	ETH_WKUP_IRQHandler,
	CAN2_TX_IRQHandler,
	CAN2_RX0_IRQHandler,
	CAN2_RX1_IRQHandler,
	CAN2_SCE_IRQHandler,
	OTG_FS_IRQHandler,
	DMA2_Stream5_IRQHandler,
	DMA2_Stream6_IRQHandler,
	DMA2_Stream7_IRQHandler,
	USART6_IRQHandler,
	I2C3_EV_IRQHandler,
	I2C3_ER_IRQHandler,
	OTG_HS_EP1_OUT_IRQHandler,
	OTG_HS_EP1_IN_IRQHandler,
	OTG_HS_WKUP_IRQHandler,
	OTG_HS_IRQHandler,
	DCMI_IRQHandler,
	CRYP_IRQHandler,
	HASH_RNG_IRQHandler,
	FPU_IRQHandler
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
extern unsigned int __ld_sdata_ccm;
extern unsigned int __ld_edata_ccm;
extern unsigned int __ld_load_ccm_data;
extern unsigned int __ld_sdata_ccm;
extern unsigned int __ld_edata_ccm;
extern unsigned int __ld_sbss_ccm;
extern unsigned int __ld_ebss_ccm;
extern unsigned int __ld_sdata;
extern unsigned int __ld_edata;
extern unsigned int __ld_sbss;
extern unsigned int __ld_ebss;
extern unsigned int __ld_sheap;
extern unsigned int __ld_eheap;

void Reset_Handler(void) {
	/* Stack is already initialized by hardware */

	/* Copy .data section */
	__init_section(&__ld_load_data, &__ld_sdata, &__ld_edata);
	/* Fill bss with zero */
	__fill_zero(&__ld_sbss, &__ld_ebss);
	/* Fill Heap with zero */
	__fill_zero(&__ld_sheap, &__ld_eheap);
	/* Fill static CCM memory with zeroes */
	__fill_zero(&__ld_sbss_ccm, &__ld_ebss_ccm);
	/* Init CCM RAM data section */
	__init_section(&__ld_load_ccm_data, &__ld_sdata_ccm, &__ld_edata_ccm);

	/* Set clocks, waitstates, ART operation etc. */
	SystemInit();
	
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
