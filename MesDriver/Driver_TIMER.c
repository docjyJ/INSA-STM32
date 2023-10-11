#include "stm32f10x.h"
#include "Driver_TIMER.h"




void MyTimer_Base_Init (TIM_TypeDef * TIM, uint16_t ARR, uint16_t PSC){
	     if (TIM == TIM1) RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
	else if (TIM == TIM2) RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	else if (TIM == TIM3) RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	else if (TIM == TIM4) RCC->APB1ENR |= RCC_APB1ENR_TIM4EN;
	else return;
	
	TIM->ARR = ARR;
	TIM->PSC = PSC;
}


void (*TIM1_UP_IT_fun) (void);
void TIM1_UP_IRQHandler(){
	TIM1->SR &= ~TIM_SR_UIF;
	(*TIM1_UP_IT_fun)();
}


void (*TIM2_IT_fun) (void);
void TIM2_IRQHandler(){
	TIM2->SR &= ~TIM_SR_UIF;
	(*TIM2_IT_fun)();
}

void (*TIM3_IT_fun) (void);
void TIM3_IRQHandler(){
	TIM3->SR &= ~TIM_SR_UIF;
	(*TIM3_IT_fun)();
}

void (*TIM4_IT_fun) (void);
void TIM4_IRQHandler(){
	TIM4->SR &= ~TIM_SR_UIF;
	(*TIM4_IT_fun)();
}



void MyTimer_ActiveIT(TIM_TypeDef * TIM , uint32_t  priority, void (*IT_fun) (void)){
	IRQn_Type TIM_IRQn;
	     if (TIM == TIM1) { TIM_IRQn = TIM1_UP_IRQn; TIM1_UP_IT_fun = IT_fun; }
	else if (TIM == TIM2) { TIM_IRQn = TIM2_IRQn; TIM2_IT_fun = IT_fun; }
	else if (TIM == TIM3) { TIM_IRQn = TIM3_IRQn; TIM3_IT_fun = IT_fun; }
	else if (TIM == TIM4) { TIM_IRQn = TIM4_IRQn; TIM4_IT_fun = IT_fun; }
	else return;
	
	TIM->DIER |= TIM_DIER_UIE;
	NVIC_EnableIRQ(TIM_IRQn);
	NVIC_SetPriority(TIM_IRQn, priority);
}
