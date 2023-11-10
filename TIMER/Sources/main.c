#include "stm32f10x.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"


void changeLed() {
	MyGPIO_Toggle(GPIOA, 5);
}


int main() {
	MyGPIO_Init(GPIOA, 0, AltOut_Ppull);
	MyTimer_Base_Init(TIM2, 10-1, 72-1);
	MyTimer_PWM(TIM2, 1);
	MyTimer_PWM_Cycle(TIM2, 1, 2);
	MyTimer_Base_Start(TIM2);
	
	while(1){
		__asm__ ("nop");
	}
}
