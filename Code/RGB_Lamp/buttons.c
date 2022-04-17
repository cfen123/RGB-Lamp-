#include "buttons.h"
#include "eeprom.h"
#include <avr/io.h>
#include <iotn25.h>
#include <avr/interrupt.h>

// ISR for changing the state of the LED.  
ISR(PCINT0_vect) {
	// Check which button is pressed and change the state accordingly. 
	if (SOLID_BTN_PRESSED) {
		update_solid_mode(); 
	}
	else if (CYCLING_BTN_PRESSED) {
		update_cycling_mode();
	}
}

void buttons_init() {
	GIMSK |= (1 << PCIE); // Enable pin change interrupts.
	PCMSK |= (1 << PCINT2)|(1 << PCINT3); // Enable both buttons. 
}