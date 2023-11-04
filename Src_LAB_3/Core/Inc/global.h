/*
 * globla.h
 *
 *  Created on: Nov 4, 2023
 *      Author: sonha
 */

#ifndef INC_GLOBAL_H_
#define INC_GLOBAL_H_

#define INIT 1
#define RED1_GREEN2 2
#define RED1_AMBER2 3
#define GREEN1_RED2 4
#define AMBER1_RED2 5

extern int status;

extern int time_light1;
extern int time_light2;

extern const int MAX_LED;
extern int index_led;
extern int led_buffer[4];

void display_7SEG(int num);
void clearALL_7SEG();
void update7SEG( int index);
void updateClockBuffer();
void clearALL_light();

#endif /* INC_GLOBAL_H_ */
