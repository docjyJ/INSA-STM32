#include "stm32f10x.h"
#include "Driver_TIMER.h"

void MyTimer_Base_Init (TIM_TypeDef * TIM, uint16_t ARR, uint16_t PSC){
	if (TIM == TIM2)
		RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	
	else if (TIM == TIM3)
		RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	
	#if defined (RCC_APB1ENR_TIM4EN)
	else if (TIM == TIM4)
		RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	#endif
	
	#if defined (RCC_APB1ENR_TIM5EN)
	else if (Timer == TIM5)
		RCC->APB1ENR |= RCC_APB1ENR_TIM5EN;
	#endif
	
	TIM->ARR = ARR;
	TIM->PSC = PSC;
}

void MyTimer_ActiveIT(TIM_TypeDef * Timer , char Prio){

}
