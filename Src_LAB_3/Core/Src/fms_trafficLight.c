/*
 * fms_trafficLight.c
 *
 *  Created on: Nov 4, 2023
 *      Author: sonha
 */

#include "fms_trafficLight.h"
#include "main.h"
#include "global.h"
#include "update_led.h"

void fmsRun(){
	switch(status){
	case INIT:
		status = RED1_GREEN2;
		break;
	case RED1_GREEN2:

		status = RED1_AMBER2;
		break;
	case RED1_AMBER2:
		break;
	case GREEN1_RED2:
		break;
	case AMBER1_RED2:
		break;
	default:
		break;
	}
}



