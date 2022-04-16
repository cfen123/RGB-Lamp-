/*
 * RGB_Lamp.c
 *
 * Created: 4/14/2022 6:41:08 PM
 * Author : Charley
 */ 

#include <avr/io.h>
#include <avr/sleep.h>
#include <avr/interrupt.h>
#include <iotn25.h>
#include "common.h"
#include "timers.h"
#include "buttons.h"
#include "colors.h"

static uint8_t state = 0; // This variable controls the color/pattern displayed. 

int main(void)
{
	buttons_init(); 
	timer0_config(); 
	timer1_config(); 
	init_colors();
	
	DDRB |= (1 << PB0)|(1 << PB1)|(1 << PB4); // Make the PWM channels outputs. 
	MCUCR |= (1 << SM1); // Power down mode. 
	MCUCR &= ~(1 << SM0);
	
	sei();
	LED_on();
	change_color(get_color(0));
	//sleep(); // LED is initially off. 
	
    while (1) {
		
    }
}

void sleep() {
	LED_off();
	sleep_enable(); 
	sleep_cpu(); 
}

void wakeup() {
	sleep_disable(); 
	LED_on();
}

void update_state() {
	if (state < MAX_STATE) {
		state++;
	}
	else {
		state = 0;
	}
	
	// Make changes to reflect the new state. 
	if (state < NUMBER_OF_COLORS) {
		change_color(get_color(state)); 
	}
	// Once more functionality is added, there may be else if statements here. 
}

uint8_t get_state() {
	return state; 
}

