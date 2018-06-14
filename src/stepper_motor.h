#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

#include "delay.h"

int number_of_steps = 48;
uint8_t motor_pin_1, motor_pin_2, motor_pin_3, motor_pin_4;
int direction1, direction2;
int step_number1, step_number2;
long step_delay;
uint32_t last_step_time1, last_step_time2;
int pin_count;
uint32_t now;

int vertical_moves, horizontal_moves;

void setSpeed(long whatSpeed) {
	step_delay = 60L * 1000L / number_of_steps / whatSpeed;
}

void vertical(int steps_to_move) {
	int steps_left = abs(steps_to_move);
	if (steps_to_move > 0) {
		direction1 = 1;
	}
	if (steps_to_move < 0) {
		direction1 = 0;
		vertical_moves += steps_left;
	}
	while (steps_left > 0) {
		now = getTime();

		// move only if the appropriate delay has passed:
		if (now - last_step_time1 >= step_delay) {
			// get the timeStamp of when you stepped:
			last_step_time1 = now;
			// increment or decrement the step number,
			// depending on direction:
			if (direction1 == 1) {
				step_number1++;
				if (step_number1 == number_of_steps) {
					step_number1 = 0;
				}
			} else {
				if (step_number1 == 0) {
					step_number1 = number_of_steps;
				}
				step_number1--;
			}
			// decrement the steps left:
			steps_left--;
			// step the motor to step number 0, 1, ..., {3 or 10}
			if (pin_count == 5)
				stepMotor1(step_number1 % 10);
			else
				stepMotor1(step_number1 % 4);
		}
	}
}
void horizontal(int steps_to_move) {
	int steps_left = abs(steps_to_move);
	if (steps_to_move > 0) {
		direction2 = 1;
		horizontal_moves += steps_left;
	}
	if (steps_to_move < 0) {
		direction2 = 0;
	}
	while (steps_left > 0) {
		now = getTime();

		// move only if the appropriate delay has passed:
		if (now - last_step_time2 >= step_delay) {
			// get the timeStamp of when you stepped:
			last_step_time2 = now;
			// increment or decrement the step number,
			// depending on direction:
			if (direction2 == 1) {
				step_number2++;
				if (step_number2 == number_of_steps) {
					step_number2 = 0;
				}
			} else {
				if (step_number2 == 0) {
					step_number2 = number_of_steps;
				}
				step_number2--;
			}
			// decrement the steps left:
			steps_left--;

			stepMotor2(step_number2 % 4);
		}
	}
}

void stepMotor1(int thisStep) {
	switch (thisStep) {
	case 0:  // 1010
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		GPIO_ResetBits(GPIOA, GPIO_Pin_3);
		break;
	case 1:  // 0110
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
		GPIO_SetBits(GPIOA, GPIO_Pin_2);
		GPIO_ResetBits(GPIOA, GPIO_Pin_3);
		break;
	case 2:  //0101
		GPIO_ResetBits(GPIOA, GPIO_Pin_0);
		GPIO_SetBits(GPIOA, GPIO_Pin_1);
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
		GPIO_SetBits(GPIOA, GPIO_Pin_3);
		break;
	case 3:  //1001
		GPIO_SetBits(GPIOA, GPIO_Pin_0);
		GPIO_ResetBits(GPIOA, GPIO_Pin_1);
		GPIO_ResetBits(GPIOA, GPIO_Pin_2);
		GPIO_SetBits(GPIOA, GPIO_Pin_3);
		break;
	}
}
void stepMotor2(int thisStep) {
	switch (thisStep) {
	case 0:  // 1010
		GPIO_SetBits(GPIOD, GPIO_Pin_8);
		GPIO_ResetBits(GPIOD, GPIO_Pin_9);
		GPIO_SetBits(GPIOD, GPIO_Pin_10);
		GPIO_ResetBits(GPIOD, GPIO_Pin_11);
		break;
	case 1:  // 0110
		GPIO_ResetBits(GPIOD, GPIO_Pin_8);
		GPIO_SetBits(GPIOD, GPIO_Pin_9);
		GPIO_SetBits(GPIOD, GPIO_Pin_10);
		GPIO_ResetBits(GPIOD, GPIO_Pin_11);
		break;
	case 2:  //0101
		GPIO_ResetBits(GPIOD, GPIO_Pin_8);
		GPIO_SetBits(GPIOD, GPIO_Pin_9);
		GPIO_ResetBits(GPIOD, GPIO_Pin_10);
		GPIO_SetBits(GPIOD, GPIO_Pin_11);
		break;
	case 3:  //1001
		GPIO_SetBits(GPIOD, GPIO_Pin_8);
		GPIO_ResetBits(GPIOD, GPIO_Pin_9);
		GPIO_ResetBits(GPIOD, GPIO_Pin_10);
		GPIO_SetBits(GPIOD, GPIO_Pin_11);
		break;
	}
}

void back_to_beginning() {
	pen_up();
	vertical(-vertical_moves);
	horizontal(-horizontal_moves);
	vertical_moves = 0;
	horizontal_moves = 0;
}

struct motor {
	uint32_t pin1, pin2, pin3, pin4;
	int direction, step_number, last_step_time;

};

void init_motors() {
	number_of_steps = 48;
	pin_count = 4;
	step_delay = 0;
// motor1
	direction1 = 0;
	step_number1 = 0;
	last_step_time1 = 0;
// motor2
	direction2 = 0;
	step_number2 = 0;
	last_step_time2 = 0;
}

#endif /* STEPPER_MOTOR_H_ */
