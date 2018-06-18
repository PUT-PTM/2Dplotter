/**
 * @author ngiersz, LiLatee, jakubhamer
 * @version 1.01 18/06/2018
 */
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include <stdio.h>
#include "delay.h"
#include "servo_motor.h"
#include "stepper_motor.h"
#include "letters.h"

int timeToWrite = 0;
int counter = 0;
char tab[30];
void memoryClear();
int main(void) {

	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_USART3, ENABLE);
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef driver1;
	driver1.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	driver1.GPIO_Mode = GPIO_Mode_OUT;
	driver1.GPIO_OType = GPIO_OType_PP;
	driver1.GPIO_Speed = GPIO_Speed_100MHz;
	driver1.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOA, &driver1);

	GPIO_InitTypeDef driver2;
	driver2.GPIO_Pin = GPIO_Pin_8 | GPIO_Pin_9 | GPIO_Pin_10 | GPIO_Pin_11;
	driver2.GPIO_Mode = GPIO_Mode_OUT;
	driver2.GPIO_OType = GPIO_OType_PP;
	driver2.GPIO_Speed = GPIO_Speed_100MHz;
	driver2.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &driver2);

	GPIO_InitTypeDef GPIO_InitStructure;
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;
	GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_UP;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOC, &GPIO_InitStructure);

	GPIO_PinAFConfig(GPIOC, GPIO_PinSource10, GPIO_AF_USART3);
	GPIO_PinAFConfig(GPIOC, GPIO_PinSource11, GPIO_AF_USART3);

	NVIC_InitTypeDef NVIC_InitStructure;
	USART_ITConfig(USART3, USART_IT_RXNE, ENABLE);
	NVIC_InitStructure.NVIC_IRQChannel = USART3_IRQn;
	NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelSubPriority = 0;
	NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
	NVIC_Init(&NVIC_InitStructure);
	NVIC_EnableIRQ(USART3_IRQn);

	USART_InitTypeDef USART_InitStructure;
	USART_InitStructure.USART_BaudRate = 9600;
	USART_InitStructure.USART_WordLength = USART_WordLength_8b;
	USART_InitStructure.USART_StopBits = USART_StopBits_1;
	USART_InitStructure.USART_Parity = USART_Parity_No;
	USART_InitStructure.USART_HardwareFlowControl =
	USART_HardwareFlowControl_None;
	USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

	USART_Init(USART3, &USART_InitStructure);
	USART_Cmd(USART3, ENABLE);

	setSysTick();
	config_PWM();
	setSpeed(300);
	pen_up();
	pen_down();
	pen_up();

	while (1) {
		if (timeToWrite) {
			draw_text(tab);
			timeToWrite = 0;
			memoryClear();
		}
	}
	return 0;
}

memoryClear() {
	for (int i = 0; i < 30; i++) {
		tab[i] = '\0';
	}
}

uint8_t usartGetChar(void) {
	while (USART_GetFlagStatus(USART3, USART_FLAG_RXNE) == RESET)
		;
	return USART_ReceiveData(USART3);
}
void USART3_IRQHandler(void) {
	if (USART_GetITStatus(USART3, USART_IT_RXNE) != RESET) {
		counter = 0;
		tab[0] = usartGetChar();
		while (tab[counter] != '@') {
			counter++;
			tab[counter] = usartGetChar();
		}
		tab[counter] = '\0';
		timeToWrite = 1;
	}
}
