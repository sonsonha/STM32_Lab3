/*
 * global.c
 *
 *  Created on: Nov 4, 2023
 *      Author: sonha
 */

#include "global.h"
#include "main.h"

int status = 1;


const int MAX_LED = 4;
int index_led = 0;

int duration_red = 5000;
int duration_green = 3000;
int duration_amber = 2000;

int temp_duration_red = 5000;
int temp_duration_green = 3000;
int temp_duration_amber = 2000;

int time_light1 = 5;
int time_light2 = 3;
int led_buffer[4] = {0, 5, 0, 3};

	void display_7SEG(int num){
			switch (num) {
				case 0:
							HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
							HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
							HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
							HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
							HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
							HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
							HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
							break;
						case 1:
							HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
							HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
							HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
							HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
							HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
							HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
							HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
							break;
						case 2:
							HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
							HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
							HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, SET);
							HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
							HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
							HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
							HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
							break;
						case 3:
							HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
							HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
							HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
							HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
							HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
							HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
							HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
							break;
						case 4:
							HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, SET);
							HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
							HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
							HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
							HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
							HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
							HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
							break;
						case 5:
							HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
							HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
							HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
							HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
							HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
							HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
							HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
							break;
						case 6:
							HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
							HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, SET);
							HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
							HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
							HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
							HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
							HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
							break;
						case 7:
							HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
							HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
							HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
							HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, SET);
							HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
							HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, SET);
							HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, SET);
							break;
						case 8:
							HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
							HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
							HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
							HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
							HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, RESET);
							HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
							HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
							break;
						case 9:
							HAL_GPIO_WritePin(SEG0_GPIO_Port, SEG0_Pin, RESET);
							HAL_GPIO_WritePin(SEG1_GPIO_Port, SEG1_Pin, RESET);
							HAL_GPIO_WritePin(SEG2_GPIO_Port, SEG2_Pin, RESET);
							HAL_GPIO_WritePin(SEG3_GPIO_Port, SEG3_Pin, RESET);
							HAL_GPIO_WritePin(SEG4_GPIO_Port, SEG4_Pin, SET);
							HAL_GPIO_WritePin(SEG5_GPIO_Port, SEG5_Pin, RESET);
							HAL_GPIO_WritePin(SEG6_GPIO_Port, SEG6_Pin, RESET);
							break;
			}
		}

	void update7SEG( int index) {
		switch (index) {
		case 0:
			clearAll_7SEG();
			HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, RESET);
			break;
		case 1:
			clearAll_7SEG();
			HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, RESET);
			break;
		case 2:
			clearAll_7SEG();
			HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, RESET);
			break;
		case 3:
			clearAll_7SEG();
			HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, RESET);
			break;
		}
	}

	void updateClockBuffer() {
		led_buffer[0] = time_light1/10;
		led_buffer[1] = time_light1%10;
		led_buffer[2] = time_light2/10;
		led_buffer[3] = time_light2%10;

		// Display value 0 on the 1st led 7 segment if time light has 1 digit
		if (time_light1 <= 9) {
			led_buffer[0] = 0;
			led_buffer[1] = time_light1;
		}

		// Display value 0 on the 3rd led 7 segment if time light has 1 digit
		if (time_light2 <= 9) {
			led_buffer[2] = 0;
			led_buffer[3] = time_light2;
		}
	}

	void clearALL_light(){
		HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED1_GPIO_Port, AMBER_LED1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, SET);
		HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED2_GPIO_Port, AMBER_LED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, SET);
	}

	void clearAll_7SEG(){
		HAL_GPIO_WritePin(EN0_GPIO_Port, EN0_Pin, SET);
		HAL_GPIO_WritePin(EN1_GPIO_Port, EN1_Pin, SET);
		HAL_GPIO_WritePin(EN2_GPIO_Port, EN2_Pin, SET);
		HAL_GPIO_WritePin(EN3_GPIO_Port, EN3_Pin, SET);
	}

	void blink_red_led_2hz(){
		if(timer2_flag == 1){
			HAL_GPIO_TogglePin(RED_LED1_GPIO_Port, RED_LED1_Pin);
			HAL_GPIO_TogglePin(RED_LED2_GPIO_Port, RED_LED2_Pin);
			setTimer2(50);
		}
	}

	void blink_green_led_2hz(){
		if(timer2_flag == 1){
			HAL_GPIO_TogglePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin);
			HAL_GPIO_TogglePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin);
			setTimer2(50);
		}
	}

	void blink_amber_led_2hz(){
		if(timer2_flag == 1){
			HAL_GPIO_TogglePin(AMBER_LED1_GPIO_Port, AMBER_LED1_Pin);
			HAL_GPIO_TogglePin(AMBER_LED2_GPIO_Port, AMBER_LED2_Pin);
			setTimer2(50);
		}
	}

	void check_button3(){
		if(isButton3_pressed()){
			duration_red = temp_duration_red;
			duration_green = temp_duration_green;
			duration_amber = temp_duration_amber;
		}
	}

	int check_valid_duration(){
		int total = duration_amber + duration_green;
		if(!(duration_red = total)){
			return 0;
		}
		return 1;
	}






