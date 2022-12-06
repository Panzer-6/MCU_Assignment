/*
 * traffic.c
 *
 *  Created on: Nov 30, 2022
 *      Author: PC
 */
/* NOTES */
//PLIGHT will turn on when PBUTTON is pressed
//Timeout for PLIGHT can be freely defined
//When will PBUZZER active is freely defined

#include "button.h"
#include "timer.h"
#include "traffic.h"

enum TRAFFIC_FSM_MODE {TRAFFIC_FSM_INIT, AUTOMATIC, MANUAL, TUNING};
enum TRAFFIC_FSM_MODE trafficFsmMode = TRAFFIC_FSM_INIT;

enum TRAFFIC_MODE {TRAFFIC_INIT, RED, GREEN, YELLOW};
enum TRAFFIC_MODE traffic1Mode = TRAFFIC_INIT;
enum TRAFFIC_MODE traffic2Mode = TRAFFIC_INIT;

enum TUNING_MODE {TUNE_INIT, TUNE_RED, TUNE_GREEN, TUNE_YELLOW};

int led_red_time = 5;
int led_green_time = 3;
int led_yellow_time = 2;
int tuning_mode = TUNE_INIT;

void traffic_fsm_auto()
{
	//-------------------------------------------------
	switch (traffic1Mode)
	{
	case TRAFFIC_INIT:
		//Initialze necessary variables
		//TODO

		break;
	case RED:
		//Implement case RED auto
		//If BUTTON2 is pressed, switch to MANUAL mode
		//TODO

		break;
	case YELLOW:
		//Implement case YELLOW auto
		//If BUTTON2 is pressed, switch to MANUAL mode
		//TODO

		break;
	case GREEN:
		//Implement case GREEN auto
		//If BUTTON2 is pressed, switch to MANUAL mode

		break;
	default:
		break;
	}
	//-------------------------------------------------
	switch (traffic2Mode)
	{
	case TRAFFIC_INIT:
		//Initialze necessary variables
		//TODO

		break;
	case RED:
		//Implement case RED auto
		//If BUTTON2 is pressed, switch to MANUAL mode
		//TODO

		break;
	case YELLOW:
		//Implement case YELLOW auto
		//If BUTTON2 is pressed, switch to MANUAL mode
		//TODO

		break;
	case GREEN:
		//Implement case GREEN auto
		//If BUTTON2 is pressed, switch to MANUAL mode

		break;
	default:
		break;
	}
	//-------------------------------------------------
}

void traffic_fsm_manual()
{
	//-------------------------------------------------
	switch (traffic1Mode)
	{
	case TRAFFIC_INIT:
		//Initialze necessary variables
		//TODO

		break;
	case RED:
		//Implement case RED manual
		//If timeout, switch to AUTO mode
		//TODO

		break;
	case YELLOW:
		//Implement case YELLOW manual
		//If timeout, switch to AUTO mode
		//TODO

		break;
	case GREEN:
		//Implement case GREEN manual
		//If timeout, switch to AUTO mode
		//TODO

		break;
	default:
		break;
	}
	//-------------------------------------------------
	switch (traffic2Mode)
	{
	case TRAFFIC_INIT:
		//Initialze necessary variables
		//TODO

		break;
	case RED:
		//Implement case RED manual
		//If timeout, switch to AUTO mode
		//TODO

		break;
	case YELLOW:
		//Implement case YELLOW manual
		//If timeout, switch to AUTO mode
		//TODO

		break;
	case GREEN:
		//Implement case GREEN manual
		//If timeout, switch to AUTO mode
		//TODO

		break;
	default:
		break;
	}
	//-------------------------------------------------
}
/*
 * tuning FSM
 * BUTTON1 to switch mode
 * BUTTOn2 to switch LED to adjust
 * BUTTON3 to increase, if > MAX_TIME then rollback to 1
 * PES_BUTTON to save and switch to auto mode
 * */
void tuning_fsm(){
	switch(tuning_mode){
		case TUNE_GREEN:
			if(isButtonPressed(1)) tuning_mode = TUNE_YELLOW;
			if(isButtonPressed(3)){
				led_red_time = led_yellow_time + led_green_time;
				trafficFsmMode = AUTOMATIC;
				return;
			}
			if(isButtonPressed(2)){
				led_green_time++;
				if(led_green_time > MAX_TIME) led_green_time = MIN_TIME;
			}
			break;
		case TUNE_YELLOW:
			if(isButtonPressed(1)) tuning_mode = TUNE_GREEN;
			if(isButtonPressed(3)){
				tuning_mode = TUNE_GREEN;
				led_red_time = led_yellow_time + led_green_time;
				trafficFsmMode = AUTOMATIC;
				return;
			}
			if(isButtonPressed(2)){
				led_yellow_time++;
				if(led_yellow_time > MAX_TIME) led_green_time = MIN_TIME;
			}
			break;
	}
}
/*
 * Mode switch function
 * switch to appopriate function
 */
void mode_switch(){
	switch(trafficFsmMode){
	case AUTOMATIC:
		trafficFsmMode = MANUAL;
		break;
	case MANUAL:
		trafficFsmMode = TUNING;
		break;
	case TUNING:
		trafficFsmMode = AUTOMATIC;
		break;
}

void main_fsm()
{
	switch (trafficFsmMode)
	{
	case TRAFFIC_FSM_INIT:
		//Initialize necessary variables
		//TODO

		break;
	case AUTOMATIC:
		//Default mode
		//Typical auto traffic light
		//Implement the function below
		//TODO
		traffic_fsm_auto();
		break;
	case MANUAL:
		//Pressing BUTTON1 while in AUTOMATIC mode will switch to MANUAL mode
		//In MANUAL mode, BUTTON2 will manually switch to another state of traffic light
		//BUTTON3 will switch to the previous state of the traffic light
		//Implement the function below
		traffic_fsm_manual();
		break;
	case TUNING:
		//Pressing BUTTON1 in MANUAL mode will switch to TUNING mode
		//In TUNING mode, BUTTON2 will choose the LED we want to tune
		//BUTTON3 will increase the duration by 1 per press, by 10 per long press
		//Implement TUNING mode
		//TODO

		break;
	default:
		break;
	}
}


