/*
 * software_timer.h
 *
 *  Created on: Nov 4, 2023
 *      Author: sonha
 */

#ifndef INC_SOFTWARE_TIMER_H_
#define INC_SOFTWARE_TIMER_H_

extern int timer1_flag;
extern int timer2_flag;
extern int timer3_flag;

void setTimer1(int duration);
void setTimer2(int duration);
void setTimer3(int duration);

void timerRun();


#endif /* INC_SOFTWARE_TIMER_H_ */