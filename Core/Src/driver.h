/*
 * driver.h
 *
 *  Created on: Nov 30, 2022
 *      Author: PC
 */

#ifndef SRC_DRIVER_H_
#define SRC_DRIVER_H_
#include "main.h"
enum PINOUT {TRAFFIC1A, TRAFFIC1B, TRAFFIC2A, TRAFFIC2B, PLIGHTR, PLIGHTG};
enum PININ {PBUTTON, BUTTON1, BUTTON2, BUTTON3};
//enum PINOUT pinOutType;
//enum PININ pinInType;

void writePin(int index, int value);
void readPin(int index);
void writePWM(TIM_HandleTypeDef* htim3, int value);
void togglePin(int index);


#endif /* SRC_DRIVER_H_ */
