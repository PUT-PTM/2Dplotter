#ifndef DELAY_H_
#define DELAY_H_
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include <stdio.h>

volatile uint32_t msTicks;      //counts 1ms timeTicks

void SysTick_Handler(void) {
	msTicks++;
}

void setSysTick(void){
	if (SysTick_Config(SystemCoreClock / 1000)) {
		// Capture error
		while (1){};
	}
}

static void Delay(__IO uint32_t dlyTicks){
  uint32_t curTicks = msTicks;
  while ((msTicks - curTicks) < dlyTicks);
}

uint32_t getTime() {
	return msTicks;
}

#endif /* DELAY_H_ */
