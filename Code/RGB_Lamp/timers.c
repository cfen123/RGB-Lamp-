#include "timers.h"
#include <avr/io.h>

void timer1_config() {
	TCCR1B |= (1 << CS11)|(1 << CS10); // Set prescaler to /64
	
	// Fast PWM mode with 0xFF TOP
	TCCR1A |= (1 << WGM10); 
	TCCR1B |= (1 << WGM12);
	
	// Set up OC0A non-inverting PWM
	TCCR1A |= (1 << COM1A1)|(1 << COM1B1);
}

void timer2_config() {
	TCCR2B |= (1 << CS22); // prescaler of 64
	TCCR2A |= (1 << WGM20)|(1 << WGM21); // Fast PWM with 0xFF TOP
	TCCR2A |= (1 << COM2A1); // Non-inverting mode.		
}