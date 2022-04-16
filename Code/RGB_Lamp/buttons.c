#include "buttons.h"
#include "common.h"
#include <avr/io.h>
#include <iotn25.h>
#include <avr/interrupt.h>
#include <avr/sleep.h>

// ISR for color button. 
ISR(INT0_vect) {
	update_state();
}

// ISR for ON/OFF button. 
ISR(PCINT0_vect) {
	// Check if the pin is low; a low to high change also triggers this ISR. 
	if (ON_OFF_BTN_LOW) {
		if (SLEEP_ENABLED) {
			wakeup();
		}
		else {
			sleep();
		}
	}
}

void on_off_btn_init() {
	GIMSK |= (1 << PCIE); // Enable pin change interrupts.
	PCMSK |= (1 << PCINT3); // BUtton is on PCINT3. 
}

void color_btn_init() {
	GIMSK |= (1 << INT0); // Enable INT0 interrupts. 
	MCUCR |= (1 << ISC01); // Interrupt on falling edge
	MCUCR &= ~(1 << ISC00); 
}

void buttons_init() {
	color_btn_init();
	on_off_btn_init();
}