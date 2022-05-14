/*
 * RGB_Lamp.c
 *
 * Created: 4/14/2022 6:41:08 PM
 * Author : Charley
 */ 
#define F_CPU 16000000

#include <avr/io.h>
#include <avr/interrupt.h>
#include "rgb_led.h"
#include "timers.h"
#include "buttons.h"
#include "colors.h"
#include <util/delay.h>

int main(void)
{
	buttons_init();
	timer1_config(); 
	timer2_config(); 
	init_colors();
	change_LED_color(get_color(0)); // Initialize to default. 
	TURN_LED_ON;
	sei();
	
    while (1) {
		if (cycling) {
			switch (cycling_mode) {
				case 0: 
					grayscale_cycling();
					break; 
				case 1: 
					cycling_1(); 
					break; 
			}
		}
    }
}


