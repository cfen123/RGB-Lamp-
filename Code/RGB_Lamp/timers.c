#include "timers.h"
#include <avr/io.h>
#include <iotn25.h>

void timer0_config() {
	// Fast PWM mode with 0xFF TOP
	TCCR0A |= (1 << WGM01)|(1 << WGM00); 
	TCCR0B &= ~(1 << WGM02); 
	
	// Set up OC0A non-inverting PWM
	TCCR0A &= ~(1 << COM0A0); 
	TCCR0A |= (1 << COM0A1); 
}

void timer1_config() {
	OCR1C = 0xFF; // Counter top value in the PWM should be 0xFF. 
	
	// Configure PWM for OC1A. 
	TCCR1 |= (1 << PWM1A); // Enable PWM
	TCCR1 |= (1 << COM1A1); // Non-inverting mode, inverted OC1A not connected
	TCCR1 &= ~(1 << COM1A0); 
	
	// Configure PWM for OC1B. 
	GTCCR |= (1 << PWM1B); // Enable PWM 
	GTCCR |= (1 << COM1B1); // Non-inverting mode, inverted OC1B not connected
	GTCCR &= ~(1 << COM1B0);
}

void LED_on() {
	ENABLE_TIMER0; 
	ENABLE_TIMER1; 
}

void LED_off() {
	DISABLE_TIMER0; 
	DISABLE_TIMER1; 
	TURN_LED_OFF; 
}

void change_color(Color c) {
	OCR0A = c.R; // Red
	OCR1A = c.G; // Green 
	OCR1B = c.B; // Blue
}