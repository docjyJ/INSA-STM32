#include "stm32f10x.h"
#include "Driver_TIMER.h"




int main() {
	MyTimer_Base_Init(TIM2, 1000-1, 36000-1);
	MyTimer_Base_Start(TIM2);
	
	while(1);
}
