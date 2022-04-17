#ifndef EEPROM_H 
#define EEPROM_H 

/*  For writing to and reading from the EEPROM. Since RGB color codes will not change and only 
	need to read, EEPROM is a great candidate for storing the colors. This will reserve the SRAM for 
	other operations. These colors will be stored in addresses starting from 0x00, emulating an array. 
	(Up to) 40 colors (120 bytes) will be stored. If needed, extra colors can be stored in the SRAM. 

	The state variables which control the mode of the LED can also be stored here so that 
	the state is maintained after power-off. These are stored at the highest addresses
	of the EEPROM so that they do not collide with the colors. 
	
	State variables: 
	Solid or cycling mode flag: 125 (0 for solid, 1 for cycling) 
	Solid mode: 126
	Cycling mode: 127
	
	The programming mode is atomic operation (erase and write in one operation) since 
	there are no time critical operations. This has EEPM0 and EEPM1 as zero so 
	these bits do not need to be modified. 
*/ 

#include <stdint.h>
#include "colors.h"

/* Macros for general EEPROM */ 
#define ENABLE_MASTER_PROGRAM EECR |= (1 << EEMPE) 
#define START_WRITE EECR |= (1 << EEPE)
#define CURRENTLY_WRITING (EECR & (1 << EEPE)) 
#define START_READ EECR |= (1 << EERE)

#define NUM_COLORS_EEPROM 40 // Total number of colors stored in the EEPROM

/* For the state variables */ 
#define SOLID_MODE 0
#define CYCLING_MODE 1
#define NUM_OF_SOLID_MODES 5
#define NUM_OF_CYCLING_MODES 0
#define FLAG_ADDRESS 125
#define SOLID_MODE_ADDRESS 126
#define CYCLING_MODE_ADDRESS 127
#define MODE eeprom_read_byte(FLAG_ADDRESS) 
#define SOLID_MODE_STATE eeprom_read_byte(SOLID_MODE_ADDRESS)
#define CYCLING_MODE_STATE eeprom_read_byte(CYCLING_MODE_ADDRESS)

/* Basic EEPROM functions */ 
uint8_t eeprom_read_byte(uint8_t address); // Reads a byte from a specific address. 
void eeprom_write_byte(uint8_t address, uint8_t value); // Writes a byte to a specific address. 
void eeprom_update_byte(uint8_t address, uint8_t value); // Updates a byte, avoiding rewriting it if the byte is unchanged. 

/* Functions for the color. */ 
Color eeprom_read_color(uint8_t index); 
void eeprom_update_color(Color c, uint8_t index); 
void eeprom_colors_init(Color* color_array, uint8_t n_colors); // Copies the colors in an array into the EEPROM.  

/* Functions for updating the state */ 
void update_solid_mode(); 
void update_cycling_mode();

#endif 