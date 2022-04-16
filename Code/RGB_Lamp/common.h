#ifndef COMMON_H
#define COMMON_H 

#include "colors.h"

#define F_CPU 1000000

#define MAX_STATE 3

void sleep(); 
void wakeup(); 

void update_state(); // Updates the state variable. 
uint8_t get_state();

#endif