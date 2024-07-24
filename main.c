#include "stm32f4xx.h"                  // Device header
int main(){
	volatile int i;
	RCC->AHB1ENR |= RCC_AHB1ENR_GPIOAEN | RCC_AHB1ENR_GPIODEN;
	GPIOD->MODER |= GPIO_MODER_MODE15_0;
	GPIOA->MODER &= ~GPIO_MODER_MODER0;
	while(1){
		if ( GPIOA->IDR & GPIO_IDR_ID0 ){
			GPIOD->ODR |= GPIO_ODR_OD15;
			for(i=0;i<1000000;i++);
			GPIOD->ODR &= ~GPIO_ODR_OD15;
			for(i=0;i<1000000;i++);
		}
	}
}
