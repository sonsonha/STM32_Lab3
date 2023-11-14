/*
 * fms_manual.c
 *
 *  Created on: Nov 14, 2023
 *      Author: sonha
 */

#include "fms_manual.h"

void fms_manual_run() {
	switch(status) {
	case NORMAL_MODE:
		HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED1_GPIO_Port, AMBER_LED1_Pin, SET);
		HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, RESET);

		if(timer1_flag == 1) {
			status = RED1_GREEN2;
			setTimer1(3000);
		}
		if(isButton1_pressed() == 1) {
			status = MODE_2;
			setTimer1(10000); // if button not pressed in 10s, status = auto
		}
		break;
	case MODE_2:
		time_light1 = 2;
		break;
	case MAN_AMBER:
		break;
	default:
		break;
	}
}

