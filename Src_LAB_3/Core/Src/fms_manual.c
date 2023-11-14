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
		time_light2 = 2; // Display mode in 2
		blink_red_led_2hz();
		if(timer1_flag == 1) {
			status = RED1_GREEN2;
			setTimer1(3000);
		}
		if(isButton1_pressed() == 1) {
			status = MODE_3;
			setTimer1(10000); // if button not pressed in 10s, status = auto
			if(isButton2_pressed() == 1){
				temp_duration_red = temp_duration_red - 1000;
			}
			if(check_valid_duration()){
			   check_button3();
			}
		}
		break;
	case MODE_3:
		time_light2 = 3; // Display mode 3
		blink_amber_led_2hz();
		if(timer1_flag == 1) {
			status = RED1_GREEN2;
			setTimer1(3000);
		}
		if(isButton1_pressed() == 1) {
			status = MODE_4;
			setTimer1(10000); // if button not pressed in 10s, status = auto
			if(isButton2_pressed() == 1){
				temp_duration_amber = temp_duration_amber - 1000;
			}
			if(check_valid_duration()){
			   check_button3();
			}
		}
		break;
	case MODE_4:
		time_light2 = 4; // Display mode 4
		blink_green_led_2hz();
		if(timer1_flag == 1) {
			status = RED1_GREEN2;
			setTimer1(3000);
		}
		if(isButton1_pressed() == 1) {
			status = NORMAL_MODE;
			setTimer1(10000); // if button not pressed in 10s, status = auto
			if(isButton2_pressed() == 1){
				temp_duration_green = temp_duration_green - 1000;
			}
			if(check_valid_duration()){
			   check_button3();
			}
		}
		break;
	default:
		break;
	}
}

