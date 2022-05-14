#define F_CPU 16000000
#include <util/delay.h>
#include "rgb_led.h"
#include <avr/io.h>

// Changed pins for easier breadboarding. 
void change_LED_color(Color c) {
	OCR1A = c.B; // Blue
	OCR1B = c.G; // Green
	OCR2A = c.R; // Red
}

void grayscale_cycling() {
	OCR1A = 0; 
	OCR1B = 0;
	OCR2A = 0;
	while (OCR1A < 255) {
		OCR1A++; 
		OCR1B++;
		OCR2A++; 
		_delay_ms(20);
	}
	while (OCR1A > 0) {
		OCR1A--; 
		OCR1B--;
		OCR2A--;
		_delay_ms(20);
	}
}

void cycling_1() {
	OCR1A = 0;
	OCR1B = 128;
	OCR2A = 255;
	while (OCR1A < 255) {
		OCR1A++;
		OCR1B++;
		OCR2A++;
		_delay_ms(20);
	}
	while (OCR1A > 0) {
		OCR1A--;
		OCR1B--;
		OCR2A--;
		_delay_ms(20);
	}
}