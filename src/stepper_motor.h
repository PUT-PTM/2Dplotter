/*
 * stepper_motor.h
 *
 *  Created on: 15.05.2018
 *      Author: ngier
 */

#ifndef STEPPER_MOTOR_H_
#define STEPPER_MOTOR_H_

int number_of_steps = 48;
long step_delay;
uint32_t now;
int vertical_moves, horizontal_moves;
int pin_count;

struct Motor
{
	GPIO_TypeDef * GPIO;
	uint32_t pin1, pin2, pin3, pin4;
	int direction, step_number, last_step_time;

} motor1, motor2;

void init_motor(struct Motor* motor, GPIO_TypeDef * port, uint32_t pin1, uint32_t pin2, uint32_t pin3, uint32_t pin4) {
	motor->GPIO = port;
	motor->pin1 = pin1;
	motor->pin2 = pin2;
	motor->pin3 = pin3;
	motor->pin4 = pin4;
}

void setSpeed(long whatSpeed) {
//	step_delay = 60L * 1000L * 1000L / number_of_steps / whatSpeed;
	step_delay = 60L * 1000L / number_of_steps / whatSpeed;
}

void stepMotor(struct Motor motor, int thisStep) {
	switch (thisStep) {
	      case 0:  // 1010
	        GPIO_SetBits(motor.GPIO, motor.pin1);
	        GPIO_ResetBits(motor.GPIO, motor.pin2);
	        GPIO_SetBits(motor.GPIO, motor.pin3);
	        GPIO_ResetBits(motor.GPIO, motor.pin4);
	      break;
	      case 1:  // 0110
		    GPIO_ResetBits(motor.GPIO, motor.pin1);
	        GPIO_SetBits(motor.GPIO, motor.pin2);
	        GPIO_SetBits(motor.GPIO, motor.pin3);
	        GPIO_ResetBits(motor.GPIO, motor.pin4);
	      break;
	      case 2:  //0101
		    GPIO_ResetBits(motor.GPIO, motor.pin1);
	        GPIO_SetBits(motor.GPIO, motor.pin2);
	        GPIO_ResetBits(motor.GPIO, motor.pin3);
	        GPIO_SetBits(motor.GPIO, motor.pin4);
	      break;
	      case 3:  //1001
		    GPIO_SetBits(motor.GPIO, motor.pin1);
	        GPIO_ResetBits(motor.GPIO, motor.pin2);
	        GPIO_ResetBits(motor.GPIO, motor.pin3);
	        GPIO_SetBits(motor.GPIO, motor.pin4);
	      break;
	    }
}

void vertical(int steps_to_move) {
	step(motor1, steps_to_move);
}

void horizontal(int steps_to_move) {
	step(motor2, steps_to_move);
}

void step(struct Motor motor, int steps_to_move) {
	int steps_left = abs(steps_to_move);
	if (steps_to_move > 0) { motor.direction = 1; horizontal_moves += steps_left; }
	if (steps_to_move < 0) { motor.direction = 0; }
	while (steps_left > 0) {
		  now = getTime();

	     // move only if the appropriate delay has passed:
	     if (now - motor.last_step_time >= step_delay) {
	       // get the timeStamp of when you stepped:
	       motor.last_step_time = now;
	       // increment or decrement the step number,
	       // depending on direction:
	       if (motor.direction == 1) {
	         motor.step_number++;
	         if (motor.step_number == number_of_steps) {
	        	 motor.step_number = 0;
	         }
	       }
	       else {
	         if (motor.step_number == 0) {
	        	 motor.step_number = number_of_steps;
	         }
	         motor.step_number--;
	       }
	       // decrement the steps left:
	       steps_left--;
	       // step the motor to step number 0, 1, ..., {3 or 10}
	       if (pin_count == 5)
	         stepMotor(motor, motor.step_number % 10);
	       else
	         stepMotor(motor, motor.step_number % 4);
	     }
	   }
}




#endif /* STEPPER_MOTOR_H_ */
