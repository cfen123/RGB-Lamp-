/*
 * RGB_Lamp.c
 *
 * Created: 4/14/2022 6:41:08 PM
 * Author : Charley
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <iotn25.h>
#include "common.h"
#include "timers.h"
#include "buttons.h"
#include "colors.h"

int main(void)
{
	buttons_init();
	timer0_config(); 
	timer1_config(); 
	init_colors();
	
	sei();
	change_color(get_color(0));
	TURN_LED_ON;
	
    while (1) {
		
    }
}


