# Overview

This is a template file for bare metal applications for the STM32F407xx controller.

Currently, the template is for the STM32F407VEx controllers which have 512k of Flash and 128k of RAM + 64k of core-coupled memory (in sum 192k of RAM), but can easily be changed for other F407 controllers by adapting the Flash and RAM sizes in the linkerscript.


# Structure


-  the whole project is built by a single ``Makefile``. This is rather comfortable, but can become quite a pain for larger projects.
- The ``obj`` folder contains all build derived files.
- The ``startup`` folder contains my own startup code written in C. Most projects for STM32 controllers use Assembly for their startup codes, which is unnecessary. A downside of the C startup code, is its slighly bigger memory footprint.
- The ``stm32f407ve.ld`` is the linkerscript.
- The ``setup`` folder contains ST's generated clock setup file. It contains the ``SystemInit()`` function which configures the system clocks and flash waitcycles. It is currently set up for a system frequency of 168 MHz. The Code is automatically called by the startup code right before jumping into the ``main()`` function
- The ``mathlib`` folder contains CMSIS's math and DSP library in form of a precompiled static library and the corresponding header file. I never use it. No clue, if it works. A quick function check showed that the functions work, but no guarantee here. (Btw. there is no guarantee anywhere in this code, according to my GPLv2 license).

# Compiler

The Makefile expects a ``arm-none-eabi-gcc`` which has to be available in the PATH. For most linux users this should work fine.

# Adaptations

* Memory regions (Flash and RAM sizes and locations) can be adapted in the linker script.
* Stack and Heap reserved areas are also defined in the linkerscript.
* The compiler flags force newlib to rely on external system calls. When using malloc(), printf() etc. you will get errors regarding missing syscalls like ``_sbrk()`` etc. I will add a basic systemcll file in future. But for now you have to implement them yourself.
