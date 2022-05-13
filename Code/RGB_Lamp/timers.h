#ifndef TIMERS_H 
#define TIMERS_H 

/* 
	Timer/Counter 1 and Timer/Counter 2 will be used to generate PWM signals on 
	PB1 (red), PB2 (green) and PB3 (blue). Since the LED is common cathode, non-inverting PWM 
	will be used. OC1A on PB1, OC1B on PB2 and OC2A on PB3 will be the PWM outputs. 
	
	A prescaler of 8 will be used, resulting in a PWM frequency of approximately 1kHz.
	
*/ 

void timer1_config(); // Initializes Timer/Counter 0
void timer2_config(); // Initializes Timer/Counter 1

#endif