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
		// If the MCU just woke up (sleep enabled), perform the wakeup routine. Or else, sleep. 
		if (SLEEP_ENABLED) { 
			wakeup();
		}
		else {
			/* As the CPU is put to sleep inside an interrupt, the MCU does not exit this 
			ISR before going to sleep. As a result, the interrupt flag is not cleared and the 
			MCU is still inside the ISR in sleep mode so it cannot be woken up without 
			manually clearing the interrupt flag prior to putting it to sleep. 
			
			Furthermore, global interrupts are disabled inside an interrupt so we need to 
			enable global interrupts before putting it to sleep in order for interrupts to wake it up.
			*/ 
			CLEAR_PCINT_FLAG; 
			sei();
			sleep();
		}
	}
}

void on_off_btn_init() {
	GIMSK |= (1 << PCIE); // Enable pin change interrupts.
	PCMSK |= (1 << PCINT3); // Button is on PCINT3. 
}

void color_btn_init() {
	GIMSK |= (1 << INT0); // Enable INT0 interrupts. 
	MCUCR |= (1 << ISC01); // Interrupt on falling edge
	MCUCR &= ~(1 << ISC00); 
}