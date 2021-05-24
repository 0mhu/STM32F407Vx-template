/*
* STM32F407VE Linkerscript for FLASH normal flash code execution
* Copyright (C) 2017 Mario Hüttel <mario.huettel@gmx.net>
*
* This file is part of 'STM32F407 code template'.
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
* --------------------------------------------------------------------
* FLASH: 512K
* RAM: 128K
* CCM RAM: 64L
* FPU: fpv4-sp-d16
*/ 

/* USER PARAMETERS */
__ld_stack_size = 0x1000;
__ld_heap_size  = 0x0500;

/* END OF USER PARAMETERS */
ENTRY(Reset_Handler)
__ld_top_of_stack = 0x20020000; /* One byte above the end of the SRAM. Stack is pre-decrewmenting, so this is okay */


/* Available memory areas */
MEMORY
{
	FLASH (xr)	: ORIGIN = 0x08000000, LENGTH = 512K
	RAM (xrw)	: ORIGIN = 0x20000000, LENGTH = 128K
	CCM (rw)	: ORIGIN = 0x10000000, LENGTH = 64K
}

SECTIONS
{
	.vectors : ALIGN(4)
	{
		KEEP(*(.vectors))
		. = ALIGN(4);
	} >FLASH
	
	.text : ALIGN(4)
	{
		*(.text)           /* .text sections (code) */
    		*(.text*)          /* .text* sections (code) */
    		*(.rodata)         /* .rodata sections (constants, strings, etc.) */
    		*(.rodata*)        /* .rodata* sections (constants, strings, etc.) */
    		*(.glue_7)         /* glue arm to thumb code */
    		*(.glue_7t)        /* glue thumb to arm code */
		*(.eh_frame)
		KEEP(*(.init))	   /* Constructors */
		KEEP(*(.fini))     /* Destructors  */
		. = ALIGN(4);
	} >FLASH =0xFF
	
	.ARM.extab : ALIGN(4)
	{ 
		*(.ARM.extab* .gnu.linkonce.armextab.*) 
	} >FLASH =0xFF
	
	.ARM : ALIGN(4)
	{
    		__exidx_start = .;
      		*(.ARM.exidx*)
      		__exidx_end = .;
   	} >FLASH =0xFF
	
	/* Constructor/Destructor tables */
 	.preinit_array : ALIGN(4)
	{
    		PROVIDE_HIDDEN (__preinit_array_start = .);
    		KEEP (*(.preinit_array*))
    		PROVIDE_HIDDEN (__preinit_array_end = .);
  	} >FLASH =0xFF
  	
	.init_array :
  	{
    		PROVIDE_HIDDEN (__init_array_start = .);
    		KEEP (*(SORT(.init_array.*)))
    		KEEP (*(.init_array*))
    		PROVIDE_HIDDEN (__init_array_end = .);
  	} >FLASH =0xFF
  
	.fini_array :
	{
    		PROVIDE_HIDDEN (__fini_array_start = .);
    		KEEP (*(.fini_array*))
    		KEEP (*(SORT(.fini_array.*)))
    		PROVIDE_HIDDEN (__fini_array_end = .);
    		/* Ensure the flash is aligned at a 32 bit word boundary */
    		. = ALIGN(4);
  	} >FLASH =0xFF

	/* Initialized CCM data */
	__ld_load_ccm_data = LOADADDR(.ccmdata);
	.ccmdata : ALIGN(4)
	{
		__ld_sdata_ccm = .;	
		*(.ccm.data)
		*(.ccm.data*)
		. = ALIGN(4);
		__ld_edata_ccm = .;
	} >CCM AT> FLASH
	
	.ccmbss (NOLOAD) : ALIGN(4)
	{
		__ld_sbss_ccm = .;	
		*(.ccm.bss)
		*(.ccm.bss*)
		. = ALIGN(4);
		__ld_ebss_ccm = .;
	} >CCM

	/* Initialized Data */
	__ld_load_data = LOADADDR(.data);
	.data : ALIGN(4)
	{
		__ld_sdata = .;
		*(.data)
		*(.data*)
		. = ALIGN(4);
		__ld_edata = .;
	} >RAM AT> FLASH
	
	/* Uninitialized static data */
	.bss (NOLOAD) : ALIGN(4)
	{
		__ld_sbss = .;
		*(.bss)
		*(.bss*)
		*(COMMON)
		. = ALIGN(4);
		__ld_ebss = .;
	} >RAM

	.heap_stack (NOLOAD) : ALIGN(4)
	{
		__ld_sheap = .;
		. = . + __ld_heap_size;
		__ld_eheap = .;
		. = . + __ld_stack_size;
		. = ALIGN(4);
	} >RAM
}

