# RGB-Lamp-
A lamp which can display various colors, including a rainbow mode. Brightness can be varied. 

## Requirements 
- A switch which will turn on the lamp. 
- Powered from batteries (portable) or adapter. 
- Low power so that the batteries do not have to be replaced often. 
- Push button switch to toggle between colors. 
- Push button switch to change brightness. 
- On/off switch. 

## Implementation
- Use through hole components so that the components can be tested on breadboards easily. 
- RGB LED (possibly in a transparent/translucent casing). 
- The power source will be batteries (6AAA 1.5V batteries) as this allows it to be mobile and will hence be able to be used anywhere. AAA batteries are smaller than AA and have the same voltage but less charge. This is good for this application since it is low power and smaller is better. This will be good for when you don’t have a power outlet by your bed and can be used in a wider range of locations.
- As the batteries’ voltage decreases as they discharge, the voltage will need to be regulated to 5V to power the circuit. Their total voltage is 9V. This is because we want this to be quite a bit higher than 5V so that the regulator output does not drop even when the batteries have significantly discharged. 
- Switches could be debounced in software. 

## Components 
RGB LED: HV-5RGB25 (Cheapest through hole with 4 leads) 
Microcontroller: ATMEGA328P 
Regulator: 78L05 +5V 100mA Voltage Regulator | Jaycar Electronics New Zealand
