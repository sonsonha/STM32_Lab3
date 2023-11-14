/*
 * button.h
 *
 *  Created on: Nov 4, 2023
 *      Author: sonha
 */

#ifndef INC_BUTTON_H_
#define INC_BUTTON_H_

#define NORMAL_STATE GPIO_PIN_SET
#define PRESSED_SATE GPIO_PIN_RESET

void getKeyInput();

int isButton1_pressed();
int isButton2_pressed();
int isButton3_pressed();

#endif /* INC_BUTTON_H_ */
