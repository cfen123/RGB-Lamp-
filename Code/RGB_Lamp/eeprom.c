#include <avr/io.h>
#include <iotn25.h>
#include "eeprom.h"

/* Basic EEPROM functions */ 
uint8_t eeprom_read_byte(uint8_t address) {
	while (CURRENTLY_WRITING); // Cannot read until any writing is complete. 
	EEAR = address; // Set the address to read from. 
	START_READ; 
	return EEDR; 
}

void eeprom_write_byte(uint8_t address, uint8_t value) { 
	EEAR = address; 
	EEDR = value; 
	/* According to the datasheet (page 21-22), the master program must be enabled less than 4 clock cycles 
	before the writing is enabled, otherwise it is disabled automatically. Thus, it must be enabled immediately 
	before the writing is enabled, and does not need to be manually cleared afterwards. */
	ENABLE_MASTER_PROGRAM;
	START_WRITE; 
}

void eeprom_update_byte(uint8_t address, uint8_t value) { 
	if (eeprom_read_byte(address) != value) {
		eeprom_write_byte(address, value);
	}
}

/* Functions for the color */ 
Color eeprom_read_color(uint8_t index) {
	Color c; 
	// Addresses for each component. e.g. the first color has R at 0x00, G at 0x01, and B at 0x02.
	uint8_t red_address = 3 * index;
	uint8_t green_address = 3 * index + 1;
	uint8_t blue_address = 3 * index + 2;
	
	c.R = eeprom_read_byte(red_address);
	c.G = eeprom_read_byte(green_address); 
	c.B = eeprom_read_byte(blue_address); 
	
	return c;
}

void eeprom_update_color(Color c, uint8_t index) { 
	// Addresses for each component. e.g. the first color has R at 0x00, G at 0x01, and B at 0x02. 
	uint8_t red_address = 3 * index; 
	uint8_t green_address = 3 * index + 1; 
	uint8_t blue_address = 3 * index + 2;
	
	// Update the EEPROM. 
	eeprom_update_byte(red_address, c.R); 
	eeprom_update_byte(green_address, c.G); 
	eeprom_update_byte(blue_address, c.B); 
}

void eeprom_colors_init(Color* color_array, uint8_t n_colors) {
	for (uint8_t i = 0; i < n_colors; i++) {
		eeprom_update_color(color_array[i], i);
	}
}

/* Functions for updating the state */
void update_solid_mode() {
	// Make sure the flag is 0 for this mode. 
	eeprom_update_byte(FLAG_ADDRESS, SOLID_MODE);
	
	// Increment the state variable and overflow as required. 
	uint8_t current_state = SOLID_MODE_STATE;
	if (current_state < NUM_OF_SOLID_MODES) {
		// Can just use write because the value to store is always different to the current value. 
		eeprom_write_byte(SOLID_MODE_ADDRESS, current_state + 1); 
	}
	else {
		eeprom_write_byte(SOLID_MODE_ADDRESS, 0);
	}
}

void update_cycling_mode() {
	// Make sure the flag is 1 for this mode.
	eeprom_update_byte(FLAG_ADDRESS, CYCLING_MODE);
	
	// Increment the state variable and overflow as required.
	uint8_t current_state = CYCLING_MODE_STATE;
	if (current_state < NUM_OF_SOLID_MODES) {
		// Can just use write because the value to store is always different to the current value.
		eeprom_write_byte(CYCLING_MODE_ADDRESS, current_state + 1);
	}
	else {
		eeprom_write_byte(CYCLING_MODE_ADDRESS, 0);
	}
}