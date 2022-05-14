#ifndef RGB_LED_H 
#define RGB_LED_H 

#include "colors.h"

#define NUMBER_OF_CYCLING_MODES 2

/* All functions directly related to the RGB LED's color, which include changing the color and 
   the color cycling. */ 

// The LED can be turned on by making the PWM pins outputs.
// Red: PB1 (OC1A), Green: PB2 (OC1B), Blue: PB3 (OC2A)
#define TURN_LED_ON DDRB |= (1 << PB1)|(1 << PB2)|(1 << PB3)

void change_LED_color(Color c); // Changes the color displayed by altering the OCRxx registers.
void grayscale_cycling(); // First cycling mode 
void cycling_1();

#endif