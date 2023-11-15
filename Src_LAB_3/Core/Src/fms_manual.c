/*
 * fms_manual.c
 *
 *  Created on: Nov 14, 2023
 *      Author: sonha
 */

#include "fms_manual.h"
#include "fms_trafficLight.h"

int duration_buffer[3] = {5000, 2000, 3000};

void clear_light_buffer(){
	duration_buffer[0] = 0;
	duration_buffer[1] = 0;
	duration_buffer[2] = 0;
}

void update_time_light_changed(){
	    duration_red = duration_buffer[0];
	    duration_amber = duration_buffer[1] ;
	    duration_green = duration_buffer[2];
}

void fms_manual_run() {
	switch(status) {
	case NORMAL_MODE:
		HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED1_GPIO_Port, AMBER_LED1_Pin, SET);
		HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED2_GPIO_Port,  AMBER_LED2_Pin, SET);

		if(!check_valid_duration()){
			clear_light_buffer();
		}

		display_led1 = duration_red/1000;
		display_led2 = duration_green/1000;



		if(timer1_flag == 1) {
			status = RED1_GREEN2;
			setTimer1(3000);
		}
		if(isButton1_pressed() == 1) {
			status = MODE_2;
			setTimer1(10000); // Wait 10s, all route is stopped, if button 1 is not pressed, turn to normal MODE
		}
		break;
	case MODE_2:
		num_MODE = 2;
		display_led2 = 2; // Display mode in 2
		updateClockBuffer();
		blink_red_led_2hz();
		if(timer1_flag == 1) {
			status = RED1_GREEN2;
			setTimer1(3000);
		}

		if(isButton1_pressed() == 1) {
			status = MODE_3;
			setTimer1(10000); // if button not pressed in 10s, status = auto
		}

		if(isButton2_pressed() == 1){
			temp_duration_red = temp_duration_red + 1000;
			if(temp_duration_red/1000 > 99){
				temp_duration_red = 99000;
			}
		}

		if(isButton3_pressed()){
			duration_buffer[0] = temp_duration_red;
		}

		break;
	case MODE_3:
		num_MODE = 3;
		display_led2 = 3; // Display mode 3
		updateClockBuffer();
		blink_amber_led_2hz();
		if(timer1_flag == 1) {
			status = RED1_GREEN2;
			setTimer1(3000);
		}

		if(isButton1_pressed() == 1) {
			status = MODE_4;
			setTimer1(10000); // if button not pressed in 10s, status = auto
		}

		if(isButton2_pressed() == 1){
			temp_duration_amber = temp_duration_amber + 1000;
			if(temp_duration_amber/1000 > 99){
				temp_duration_amber = 99000;
			}
		}

		if(isButton3_pressed()){
			duration_buffer[1] = temp_duration_amber;
		}

		break;
	case MODE_4:
		num_MODE = 4;
		display_led2 = 4; // Display mode 4
		updateClockBuffer();
		blink_green_led_2hz();
		if(timer1_flag == 1) {
			status = RED1_GREEN2;
			setTimer1(3000);
		}
		if(isButton1_pressed() == 1) {
			status = NORMAL_MODE;
			setTimer1(10000); // if button not pressed in 10s, status = auto
		}

		if(isButton2_pressed() == 1){
			temp_duration_green = temp_duration_green + 1000;
			if(temp_duration_green/1000 > 99){
				temp_duration_green = 99000;
			}
		}

		if(isButton3_pressed()){
			duration_buffer[2] = temp_duration_green;
		}

		if(check_valid_duration()){
			update_time_light_changed();
		}

		break;
	default:
		break;
	}
}

