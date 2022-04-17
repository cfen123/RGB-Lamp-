#include "rgb_led.h"
#include <avr/io.h>
#include <iotn25.h>

void change_color(Color c) {
	OCR0A = c.R; // Red
	OCR1A = c.G; // Green
	OCR1B = c.B; // Blue
}