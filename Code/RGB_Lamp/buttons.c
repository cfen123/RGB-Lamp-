#define F_CPU 16000000
#include "buttons.h"
#include "rgb_led.h"
#include "colors.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

// State variables 
uint8_t cycling = 0; // Flag 
static uint8_t solid_mode = 0; 
uint8_t cycling_mode = 0; 

// Solid 
ISR(INT0_vect) {
	cycling = 0;
	update_LED_color();
	_delay_ms(500);
	EIFR |= (1 << INTF0); // Clear flag
}

// Cycling 
ISR(INT1_vect) {
	if (cycling) {
		update_cycling_mode();
	}
	else {
		cycling = 1;
	}
	_delay_ms(500);
	EIFR |= (1 << INTF1); // Clear flag
}

void buttons_init() {
	// Pins are inputs so no need to change DDRD
	PORTD |= (1 << PORTD2)|(1 << PORTD3); // Enable internal pullup resistors. 
	EIMSK |= (1 << INT0)|(1 << INT1); // Enable interrupts 
	EICRA |= (1 << ISC01)|(1 << ISC11); // Falling edge 
}

void update_LED_color() {
	if (solid_mode < NUMBER_OF_COLORS) {
		solid_mode++;
	}
	else {
		solid_mode = 0;
	}
	change_LED_color(get_color(solid_mode));
}

void update_cycling_mode() {
	if (cycling_mode < NUMBER_OF_CYCLING_MODES) {
		cycling_mode++;
	}
	else {
		cycling_mode = 0;
	}
}