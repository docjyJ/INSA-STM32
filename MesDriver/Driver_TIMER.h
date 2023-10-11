#ifndef MYTIMER_H
#define MYTIMER_H
#include "stm32f10x.h"

//TIM2_IRQHandler

void MyTimer_Base_Init (TIM_TypeDef * TIM, uint16_t ARR, uint16_t PSC);
void MyTimer_ActiveIT(TIM_TypeDef * TIM , uint32_t priority, void (*IT_fun) (void));

#define MyTimer_Base_Start(TIM) TIM->CR1 |= TIM_CR1_CEN
#define MyTimer_Base_Stop(TIM) TIM->CR1 &= ~TIM_CR1_CEN

#endif
