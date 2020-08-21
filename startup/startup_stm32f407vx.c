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
void SVCall_Handler(void) ALIAS(__int_default_handler);
void PendSV_Handler(void) ALIAS(__int_default_handler);
void SysTick_Handler(void) ALIAS(__int_default_handler);

/* Peripheral Interrupts (by default mapped onto Default Handler) */

    

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
extern unsigned int __ld_sbss_ccm;
extern unsigned int __ld_ebss_ccm;
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

	/* Fill static CCM memory with zeroes */
	__fill_zero(&__ld_sbss_ccm, &__ld_ebss_ccm);

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
