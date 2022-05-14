#ifndef COLORS_H 
#define COLORS_H 

#include <stdint.h>

#define NUMBER_OF_COLORS 10 // Should be the same number of colors defined. Target is about 30 (90 bytes). 

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

// Returns the color with index num in the color array. 
Color get_color(uint8_t num); 

// Colors to have. 
#define WHITE color(255, 255, 255)
#define RED color(255, 0, 0)
#define GREEN color(0, 255, 0)
#define BLUE color(0, 0, 255)
#define PURPLE color(128, 0, 128)
#define YELLOW color(255, 255, 0)
#define SILVER color(192, 192, 192)
#define OLIVE color(128, 128, 0)
#define TEAL color(0, 128, 128)
#define CRIMSON color(220, 20, 60)


#endif