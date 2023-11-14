/*
 * globla.h
 *
 *  Created on: Nov 4, 2023
 *      Author: sonha
 */

#include "main.h"
#include "software_timer.h"
#include "fms_manual.h"
#include "fms_trafficLight.h"
#include "button.h"

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 1
#define RED1_GREEN2 2
#define RED1_AMBER2 3
#define GREEN1_RED2 4
#define AMBER1_RED2 5

#define NORMAL_MODE 22
#define MODE_2 23
#define MAN_AMBER 24

extern int status;

extern int time_light1;
extern int time_light2;

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

void display_7SEG(int num);
void clearAll_7SEG();
void update7SEG( int index);
void updateClockBuffer();
void clearALL_light();

#endif /* INC_GLOBAL_H_ */
