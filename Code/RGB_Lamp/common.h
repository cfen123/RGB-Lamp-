#ifndef COMMON_H
#define COMMON_H 

#include "colors.h"

#define F_CPU 1000000

#define MAX_STATE NUMBER_OF_COLORS // Will be different once more functionality is added. 

// The LED can be turned on and off by making the pins outputs and inputs respectively.
#define TURN_LED_ON DDRB |= (1 << PB0)|(1 << PB1)|(1 << PB4)
#define TURN_LED_OFF DDRB &= ~((1 << PB0)|(1 << PB1)|(1 << PB4))

void sleep(); 
void wakeup(); 

void update_state(); // Updates the state variable. 
uint8_t get_state();

#endif