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


//void led_7SEG_Run(){
//	  if(timer3_flag == 1){
//		  time_light1--;
//		  time_light2--;
////		  (status == RED1_AMBER2)
//		  if(status == RED1_AMBER2){
//			  time_light2 = 2;
//		  }
//		  if((status == GREEN1_RED2)){
//			  time_light1 = 3;
//			  time_light2 = 5;
//		  }
//		  if((status == AMBER1_RED2)){
//			  time_light1 = 2;
//		  }
//		  if((status == RED1_GREEN2)){
//			  time_light1 = 5;
//			  time_light2 = 3;
//		  }
//
//		  updateClockBuffer();
//		  setTimer3(1000);
//	  }
//}


void fmsRun(){
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

	  if(timer3_flag == 1){
		  time_light1--;
		  time_light2--;
//		  (status == RED1_AMBER2)
		  if((time_light2 <= 0) && (time_light1 > 0)){
			  time_light2 = 2;
		  }
		  if((time_light1 <= 0) && (time_light2 <= 0) && (flag == 0)){
			  flag = 1;
			  time_light1 = 3;
			  time_light2 = 5;
		  }
		  if((time_light1 <= 0) && (time_light2 > 0)){
			  time_light1 = 2;
		  }
		  if((time_light1 <= 0) && (time_light2 <= 0) && (flag == 1)){
			  flag = 0;
			  time_light1 = 5;
			  time_light2 = 3;
		  }

		  updateClockBuffer();
		  setTimer3(1000);
	  }

	switch(status){
	case INIT:
		clearALL_light();
		status = RED1_GREEN2;
		setTimer1(duration_green);
		break;
	case RED1_GREEN2:
		HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED1_GPIO_Port, AMBER_LED1_Pin, SET);
		HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, RESET);
		HAL_GPIO_WritePin(AMBER_LED2_GPIO_Port,  AMBER_LED2_Pin, SET);


//		if(timer1_flag == 1)
		if(timer1_flag == 1){
			setTimer1(duration_amber);
			status = RED1_AMBER2;
//			updateClockBuffer();
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
//			updateClockBuffer();
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
//			updateClockBuffer();
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
//			updateClockBuffer();
		}
		break;
	default:
		break;
	}
}


