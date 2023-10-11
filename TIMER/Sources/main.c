#include "stm32f10x.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"


void changeLed() {
	MyGPIO_Toggle(GPIOA, 5);
}


int main() {
	MyTimer_Base_Init(TIM1, 1000-1, 36000-1);
	MyTimer_ActiveIT(TIM1, 2, changeLed);
	MyTimer_Base_Start(TIM1);
	MyGPIO_Init(GPIOA, 5, Out_Ppull);
	
	while(1);
}
