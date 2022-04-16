#ifndef COLORS_H 
#define COLORS_H 

#include <stdint.h>

#define NUMBER_OF_COLORS 4 // Should be the same number of colors defined. Target is about 30 (90 bytes). 

// RGB color struct 
typedef struct RGB_color {
	uint8_t R;
	uint8_t G; 
	uint8_t B;	
} Color;

// Creates a color variable based on the red, green and blue values. 
Color color(uint8_t R, uint8_t G, uint8_t B); 

// Initializes the colors array. 
void init_colors(); 

// Retrieves the red component of a color. 
uint8_t get_red(Color c);
// Retrieves the green component of a color.
uint8_t get_green(Color c);
// Retrieves the blue component of a color.
uint8_t get_blue(Color c);

// Returns the color with index num in the color array. 
Color get_color(uint8_t num); 

// Colors to have. 
#define WHITE color(255, 255, 255)
#define RED color(255, 0, 0)
#define GREEN color(0, 255, 0)
#define BLUE color(0, 0, 255)


#endif