#include "rgb_led.h"
#include <avr/io.h>

void change_LED_color(Color c) {
	OCR1A = c.R; // Red
	OCR1B = c.G; // Green
	OCR2A = c.B; // Blue
}