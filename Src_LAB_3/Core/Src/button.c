/*
 * button.c
 *
 *  Created on: Nov 4, 2023
 *      Author: sonha
 */

#include "button.h"
#include "main.h"

int keyReg0 = NORMAL_STATE;
int keyReg1 = NORMAL_STATE;
int keyReg2 = NORMAL_STATE;

int keyReg_pre = NORMAL_STATE;
int counterForButtonPress1s = 200;

int button1_flag = 0;
int button2_flag = 0;
int button3_flag = 0;

int isButton1_pressed(){
	if(button1_flag == 1){
		button1_flag = 0; // Reset flag
		return 1;
	}
	else return 0;
}

int isButton2_pressed(){
	if(button2_flag == 1){
		button2_flag = 0;
		return 1;
	}
	else return 0;
}

int isButton3_pressed(){
	if(button3_flag == 1){
		button3_flag = 0;
		return 1;
	}
	else return 0;
}


void TODOfunc(){
	button1_flag = 1;
}

void getKeyInput(){
	// variable for debouncing
	keyReg0 = keyReg1;
	keyReg1 = keyReg2;
	keyReg2 = HAL_GPIO_ReadPin(BUTTON_1_GPIO_Port, BUTTON_1_Pin);
	if((keyReg0 == keyReg1) && (keyReg1 == keyReg2)){
		if(keyReg2 != keyReg_pre){  // When the button normally pressed if current state is different from previous state
			keyReg_pre = keyReg2;   // To set previous state  with current state and the current state (keyReg2) move to the next state
			if(keyReg2 == PRESSED_SATE){
				//TODO
				TODOfunc();
			}
		}
		else{ // If current state equal to previous state, that mean the button is being pressed hold (more than 1 second)
			counterForButtonPress1s--;
			if(counterForButtonPress1s <= 0){
				if(keyReg2 == PRESSED_SATE){  // If don't have this condition, TODO still occur when button not be pressed cause pre-condition still satisfied
					//TODO
					TODOfunc();
				}
				counterForButtonPress1s = 200;
			}
		}
	}
}


