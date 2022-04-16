#ifndef EEPROM_H 
#define EEPROM_H 

/* For writing to and reading from the EEPROM. Since RGB color codes will not change and only 
need to read, EEPROM is a great candidate for storing the colors. This will reserve the SRAM for 
other operations. */ 

#include <eeprom.h>
#include "colors.h"

#define EEPROM_STORAGE 128 // This uC has 128 bytes of EEPROM. 
#define MAX_COLORS 128/3 // Maximum number of colors which can be stored; each color is 3 bytes. 




#endif 