#ifndef BUTTONS_H
#define BUTTONS_H 

/* 
	Configuring the external interrupts for the push buttons on PB2 (PCINT2/INT0) and PB3 (PCINT3), 
	which are the color changing and ON/OFF buttons respectively. 
	
	These are active low switches so the input pins are low when the button is pressed. 
	
	As the color button is on INT0 with a falling edge interrupt, it will be disabled in power-down sleep mode 
	as desired. 
*/ 

#define ON_OFF_BTN_LOW (~PINB & (1 << PCINT3)) 

#define SLEEP_ENABLED (MCUCR & (1 << SE))

void color_btn_init(); // Configure color changing button on PCINT2/INT0. 
void on_off_btn_init(); // Configure on/off button on PCINT3. 
void buttons_init(); // Initialize buttons. Combines the above two functions. 

#endif