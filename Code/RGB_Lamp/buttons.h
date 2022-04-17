#ifndef BUTTONS_H
#define BUTTONS_H 

/* 
	Configuring the external interrupts for the push buttons on PB2 (PCINT2/INT0) and PB3 (PCINT3), 
	which are the solid and cycling color buttons respectively. 
	
	These are active low switches so the input pins are low when the button is pressed. 
	
*/ 

#define SOLID_BTN_PRESSED (~PINB & (1 << PCINT2))
#define CYCLING_BTN_PRESSED (~PINB & (1 << PCINT3)) 

void buttons_init(); // Configure buttons 

#endif