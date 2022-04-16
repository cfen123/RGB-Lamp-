#ifndef TIMERS_H 
#define TIMERS_H 

#include "colors.h"

/* 
	Timer/Counter 0 and Timer/Counter 1 will be used to generate PWM signals on 
	PB0 (red), PB1 (green) and PB4 (blue). Since the LED is common cathode, non-inverting PWM 
	will be used. OC0A on PB1, OC0B/OC1A on PB1 and OC1B on PB4 will be the PWM outputs. 
	
	A prescaler of 8 will be used, resulting in a PWM frequency of approximately 500Hz (488.2Hz).
	
	The timers should overflow at OxFF since the colors go from 0 to 255. 
	
*/ 

#define ENABLE_TIMER0 TCCR0B |= (1 << CS01) // Enables the timer with prescaler of 8 
#define DISABLE_TIMER0 TCCR0B &= ~(1 << CS01) 
#define ENABLE_TIMER1 TCCR1 |= (1 << CS12) // Enables the timer with prescaler of 8
#define DISABLE_TIMER1 TCCR1 &= ~(1 << CS12)

#define TURN_LED_OFF PORTB &= ~((1 << PB0)|(1 << PB1)|(1 << PB4))

void timer0_config(); // Initializes Timer/Counter 0
void timer1_config(); // Initializes Timer/Counter 1
void LED_on(); // Activates the PWM. 
void LED_off(); // Deactivates and turns off the LED. 
void change_color(Color c); // Changes the color displayed by altering the OCRxx registers. 


#endif