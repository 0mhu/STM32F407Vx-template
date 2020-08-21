#include <stm32/stm32f4xx.h>

int main(void)
{
	int stack_init = 124;
	int stack_var;
	static volatile int data_var = 0x5557;
	static volatile int bss_var;
	static volatile int __attribute__((section(".ccm.data"))) ccm_data_var = 0x1224;
	static volatile int __attribute__((section(".ccm.bss"))) ccm_bss_var;

	stack_var = 100;
	bss_var = 200;
	ccm_bss_var = 300;
	ccm_bss_var = stack_init + stack_var + bss_var + data_var + ccm_data_var + ccm_bss_var;

	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN;
	
	while (1);
}
