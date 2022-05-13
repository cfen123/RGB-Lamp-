#include "buttons.h"
#include "rgb_led.h"
#include "colors.h"
#include <avr/io.h>
#include <avr/interrupt.h>

// State variables 
static uint8_t solid_mode = 0; 
static uint8_t cycling_mode = 0; 

// Solid 
ISR(INT0_vect) {
	if (solid_mode < NUMBER_OF_COLORS) {
		solid_mode++;
	}
	else {
		solid_mode = 0; 
	}
	change_LED_color(get_color(solid_mode)); 
}

// Cycling 
ISR(INT1_vect) {
	update_cycling_mode();
}

void buttons_init() {
	EIMSK |= (1 << INT0)|(1 << INT1); // Enable interrupts 
	EICRA |= (1 << ISC01)|(1 << ISC11); // Falling edge 
}