#include "stm32f4xx.h"                  // Device header
int main(){
	volatile int i;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIODEN; // Activate clock signal
	GPIOD->MODER |= GPIO_MODER_MODE15_0; // Set pin 15 of D port to digital output mode
	GPIOA->MODER &= ~GPIO_MODER_MODER0; // Set pin 0 of A port to digital input mode
	while(1){
		if ( GPIOA->IDR & GPIO_IDR_ID0 ){ // If button changes
			GPIOD->ODR |= GPIO_ODR_OD15; // Light on blue LED
			for(i=0;i<1000000;i++); // Wait
			GPIOD->ODR &= ~GPIO_ODR_OD15; // Light off blue LED
		}
	}
}
