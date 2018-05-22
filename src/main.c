

#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include <stdio.h>
#include "delay.h"
#include "servo_motor.h"
#include "stepper_motor.h"
#include "letters.h"

int main(void) {
	/* GPIOD Periph clock enable */
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOE, ENABLE);

	// zasilanie sysemu przerwan
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_SYSCFG, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);

	GPIO_InitTypeDef  sterownik1;
	sterownik1.GPIO_Pin = GPIO_Pin_1 | GPIO_Pin_2| GPIO_Pin_3| GPIO_Pin_4;
	sterownik1.GPIO_Mode = GPIO_Mode_OUT;
	sterownik1.GPIO_OType = GPIO_OType_PP;
	sterownik1.GPIO_Speed = GPIO_Speed_100MHz;
	sterownik1.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &sterownik1);

	GPIO_InitTypeDef  sterownik2;
	sterownik2.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2| GPIO_Pin_3;
	sterownik2.GPIO_Mode = GPIO_Mode_OUT;
	sterownik2.GPIO_OType = GPIO_OType_PP;
	sterownik2.GPIO_Speed = GPIO_Speed_100MHz;
	sterownik2.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOE, &sterownik2);

	setSysTick();
	config_PWM();

	init_motor(&motor1, GPIOD, GPIO_Pin_1, GPIO_Pin_2, GPIO_Pin_3, GPIO_Pin_4);
	init_motor(&motor2, GPIOE, GPIO_Pin_0, GPIO_Pin_1, GPIO_Pin_2, GPIO_Pin_3);

	setSpeed(300);
	Delay(2000);

//	char* text = "ABCDEFGHIJKLMNOPRSTUVWXYZ0123456789!?.,-";
	char* text = "ABCDEFGHIJKLMNOPRSTUVWXYZ";
//	char* text = "ABCDEFGHI";



//	draw_text(text);
//	draw_e();


	while(1) {
		horizontal(-50);
//		vertical(-50);
		Delay(500);
		horizontal(50);
	//	vertical(50);
		Delay(500);

	}
	return 0;
}

