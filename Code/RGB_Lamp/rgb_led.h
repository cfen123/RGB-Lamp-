#ifndef RGB_LED_H 
#define RGB_LED_H 

#include "colors.h"

/* All functions directly related to the RGB LED's color, which include changing the color and 
   the color cycling. */ 

// The LED can be turned on by making the PWM pins outputs.
#define TURN_LED_ON DDRB |= (1 << PB0)|(1 << PB1)|(1 << PB4)

void change_color(Color c); // Changes the color displayed by altering the OCRxx registers.

#endif