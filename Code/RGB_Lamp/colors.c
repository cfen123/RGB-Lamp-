#include "colors.h"

static Color colors[NUMBER_OF_COLORS]; 

Color color(uint8_t R, uint8_t G, uint8_t B) {
	Color new_color; 
	new_color.R = R;
	new_color.G = G;
	new_color.B = B; 
	return new_color;
}

uint8_t get_red(Color c) {
	return c.R;
}

uint8_t get_green(Color c) {
	return c.G;
}

uint8_t get_blue(Color c) {
	return c.B;
}

Color get_color(uint8_t num) {
	return colors[num]; 
}

void init_colors() {
	colors[0] = WHITE; 
	colors[1] = RED; 
	colors[2] = GREEN; 
	colors[3] = BLUE; 
}