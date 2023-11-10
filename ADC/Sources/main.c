#include "stm32f10x.h"
#include "Driver_TIMER.h"
#include "Driver_GPIO.h"
#include "Driver_ADC.h"



int main() {
	MyADC_Init(ADC1, 0);
	MyADC_On(ADC1);
	
	

	while(1){
		__asm__ ("nop");
	}
}
