/*
 * fms_trafficLight.c
 *
 *  Created on: Nov 4, 2023
 *      Author: sonha
 */

#include "fms_trafficLight.h"
#include "main.h"
#include "global.h"
#include "software_timer.h"



int flag = 0;
int led_buffer[4] = {0, 5, 0, 3};

int display_led1, display_led2;
int duration_amber = 2000;
int duration_red = 5000;
int duration_green = 3000;
int display_led1 = 5;
int display_led2 = 3;


// Hàm mới để cập nhật display_led1 và display_led2
//void updateDisplayValues() {
//    display_led1 = duration_red / 1000;
//    display_led2 = duration_green / 1000;
//
//}

void led_7SEG_Run(){
	  if(timer3_flag == 1){
		  if(!isButton1_pressed()){
			  display_led1--;
			  display_led2--;
		  }
		  else{
			  display_led1--;
			  display_led2 = num_MODE;
		  }
//		  (status == RED1_AMBER2)
		  if((display_led2 <= 0) && (display_led1 > 0)){
			  display_led2 = duration_amber/1000;
		  }
		  if((display_led1 <= 0) && (display_led2 <= 0) && (flag == 0)){
			  flag = 1;
			  display_led1 = duration_green/1000;
			  display_led2 = duration_red/1000;
		  }
		  if((display_led1 <= 0) && (display_led2 > 0)){
			  display_led1 = duration_amber/1000;
		  }
		  if((display_led1 <= 0) && (display_led2 <= 0) && (flag == 1)){
			  flag = 0;
			  display_led1 = duration_red/1000;
			  display_led2 = duration_green/1000;
		  }

		  updateClockBuffer();
		  setTimer3(1000);
	  }
}

void time_light_run(){
	if(timer2_flag == 1){
		if(index_led < MAX_LED){
			setTimer2(250);
			display_7SEG(led_buffer[index_led]);
			update7SEG(index_led);
			updateClockBuffer();
			index_led++;
			}
		else {
			index_led = 0;
		}
	}
}


void updateClockBuffer() {
	led_buffer[0] = display_led1/10;
	led_buffer[1] = display_led1%10;
	led_buffer[2] = display_led2/10;
	led_buffer[3] = display_led2%10;

	// Display value 0 on the 1st led 7 segment if time light has 1 digit
	if (display_led1 <= 9) {
		led_buffer[0] = 0;
		led_buffer[1] = display_led1;
	}

	// Display value 0 on the 3rd led 7 segment if time light has 1 digit
	if (display_led2 <= 9) {
		led_buffer[2] = 0;
		led_buffer[3] = display_led2;
	}
}


void fmsRun(){
	time_light_run();
	led_7SEG_Run();
	switch(status){
	case INIT:
		clearALL_light();
		status = RED1_GREEN2;
		setTimer1(duration_green);
		isButton1_pressed(); // Clear flag button 1 if it is being pressed, just allowing button 1 is being pressed in state status = RED1_GREEN2
		break;
	case RED1_GREEN2:
		HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED1_GPIO_Port, AMBER_LED1_Pin, SET);
		HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, RESET);
		HAL_GPIO_WritePin(AMBER_LED2_GPIO_Port,  AMBER_LED2_Pin, SET);

		if(timer1_flag == 1){
			setTimer1(duration_amber);
			status = RED1_AMBER2;
		}

		if(isButton1_pressed() == 1) {
			status = NORMAL_MODE;
			setTimer1(10000); // if button not pressed in 10s, status = auto
		}
		break;
	case RED1_AMBER2:
		HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED1_GPIO_Port, AMBER_LED1_Pin, SET);
		HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED2_GPIO_Port,  AMBER_LED2_Pin, RESET);

		if(timer1_flag == 1){
			setTimer1(duration_green);
			status = GREEN1_RED2;
			isButton1_pressed();
		}
		break;
	case GREEN1_RED2:
		HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, RESET);
		HAL_GPIO_WritePin(AMBER_LED1_GPIO_Port, AMBER_LED1_Pin, SET);
		HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED2_GPIO_Port,  AMBER_LED2_Pin, SET);

		if(timer1_flag == 1){
			setTimer1(duration_amber);
			status = AMBER1_RED2;
			isButton1_pressed();
		}
		break;
	case AMBER1_RED2:
		HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED1_GPIO_Port, AMBER_LED1_Pin, RESET);
		HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED2_GPIO_Port,  AMBER_LED2_Pin, SET);
		if(timer1_flag == 1){
			setTimer1(duration_green);
			status = RED1_GREEN2;
			isButton1_pressed();
		}
		break;
	default:
		break;
	}
}


