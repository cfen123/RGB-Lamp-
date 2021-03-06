#include "colors.h"
#include "eeprom.h"

static Color colors[NUMBER_OF_COLORS]; 

Color color(uint8_t R, uint8_t G, uint8_t B) {
	Color new_color; 
	new_color.R = R;
	new_color.G = G;
	new_color.B = B; 
	return new_color;
}

Color get_color(uint8_t num) {
	return eeprom_read_color(num);
}

void init_colors() {
	colors[0] = WHITE; 
	colors[1] = RED; 
	colors[2] = GREEN; 
	colors[3] = BLUE; 
	colors[4] = PURPLE;
	eeprom_colors_init(colors, NUMBER_OF_COLORS);
}