#ifndef BUTTONS_H
#define BUTTONS_H 

/* 
	Configuring the external interrupts for the push buttons on PD2 (INT0) and PD3 (PCINT3), 
	which are the solid and cycling color buttons respectively. 
	
	These are active low switches so the input pins are low when the button is pressed. 
	
*/ 

void buttons_init(); // Configure buttons 

#endif