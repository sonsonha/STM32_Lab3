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

//int index_led = 0;

void fmsRun(){
//	if(index_led < MAX_LED){
//	display_7SEG(led_buffer[index_led]);
//	index_led++;
//	}
//	else {
//		index_led = 0;
//	}
	switch(status){
	case INIT:
		clearALL_light();
			time_light1 = 5;
			time_light2 = 3;
			status = RED1_GREEN2;
			updateClockBuffer();
			setTimer1(500);
		break;
	case RED1_GREEN2:
//		clearALL_light();
		HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED1_GPIO_Port, AMBER_LED1_Pin, SET);
		HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, RESET);
		time_light1--;
		time_light2--;
		if(timer1_flag == 1){
			setTimer1(300);
			time_light2 = 2;
			status = RED1_AMBER2;
			updateClockBuffer();
		}
		break;
	case RED1_AMBER2:
//		clearALL_light();
//		HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, RESET);
		HAL_GPIO_WritePin(GREEN_LED2_GPIO_Port, GREEN_LED2_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED2_GPIO_Port,  AMBER_LED2_Pin, RESET);
		time_light1--;
		time_light2--;
		if(timer1_flag == 1){
			setTimer1(200);
			time_light1 = 3;
			time_light2 = 5;
			status = GREEN1_RED2;
			updateClockBuffer();
		}
		break;
	case GREEN1_RED2:
//		clearALL_light();
		HAL_GPIO_WritePin(RED_LED1_GPIO_Port, RED_LED1_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED2_GPIO_Port,  AMBER_LED2_Pin, SET);
		HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, RESET);
		HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, RESET);
		time_light1--;
		time_light2--;
		if(timer1_flag == 1){
			setTimer1(300);
			time_light1 = 2;
			status = AMBER1_RED2;
			updateClockBuffer();
		}
		break;
	case AMBER1_RED2:
//		clearALL_light();
		HAL_GPIO_WritePin(GREEN_LED1_GPIO_Port, GREEN_LED1_Pin, SET);
		HAL_GPIO_WritePin(AMBER_LED1_GPIO_Port, AMBER_LED1_Pin, RESET);
//		HAL_GPIO_WritePin(RED_LED2_GPIO_Port, RED_LED2_Pin, RESET);
		time_light1--;
		time_light2--;
		if(timer1_flag == 1){
			setTimer1(200);
			time_light1 = 5;
			time_light2 = 3;
			status = RED1_GREEN2;
			updateClockBuffer();
		}
		break;
	default:
		break;
	}
//	updateClockBuffer();
//	if(index_led < MAX_LED){
//		update7SEG(index_led);
//		display_7SEG(led_buffer[index_led]);
//		index_led++;
//	}
//	if(index_led >= MAX_LED){
//		index_led = 0;
//	}
}


