#include "timers.h"
#include <avr/io.h>

void timer1_config() {
	TCCR1B |= (1 << CS11); // Set prescaler to /8
	
	// Fast PWM mode with 0xFF TOP
	TCCR1A |= (1 << WGM10); 
	TCCR1B |= (1 << WGM12);
	
	// Set up OC0A non-inverting PWM
	TCCR1A |= (1 << COM1A1)|(1 << COM1B1);
}

void timer2_config() {
	TCCR2B |= (1 << CS21); // prescaler of 8
	TCCR2A |= (1 << WGM20)|(1 << WGM21); // Fast PWM with 0xFF TOP
	TCCR2A |= (1 << COM2A1); // Non-inverting mode.		
}