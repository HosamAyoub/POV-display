# POV-display
POV display anlaog clock. Display based on the persistence of vision concept shows a clock has 3 axes for hours, minutes and seconds. The display has a refresh rate of 1 second.



## Hardware
* Atmega32
* LEDs
* DC Motor withe more than 1000 RPM
* Hall effect sensor
* Magnet

<img src="https://github.com/HosamAyoub/Photos/blob/main/POV-display/1.png?raw=true" title = "Hardware" width="350" height="600"> &emsp; &emsp; &emsp; &emsp; <img src="https://github.com/HosamAyoub/Photos/blob/main/POV-display/2.png?raw=true" title = "Hardware" width="350" height="600">

## Drivers

### MCAL
* **DIO (Digital Input/Output):** this driver is responsible for the pins used to interface with external components. The driver customizes pins' direction to be input or output and their value to be high or low.
* **GIE (Global Interrupt Enable):** the Global Interrupt (activation - deactivation) which is considered the global gate for all maskable interrupts.
* **ADC (Analog to Digital Converter):** this driver convert the analog signals to digital sigals.
* **TIMERS (Timer0 - Timer1 - Timer2):** this driver has 3 timers. Timer0 and Timer2 are 8-bit timers with their options and configurations. Timer2 is a 16-bit timer with its options and configurations.

### Compnents of HAL
* **LED (Light Emitting Diode):** this driver contains options that facilitate the interfacing with LEDs by giving ID to every LED so that you can turn them on/off, toggle or blink with just their ID.

## Drivers Structure
Every driver has 4 files `interface.h` `config.h` `private.h` `program.c`

* **inteface.h**: this file has the prototypes of the function and the names of any custom inputs or and info I need to inform the user about it, but the user can't change anything in this file just can read it.
* **config.h**: this file has configurable settings so that the user can change them as he wants.
* **private.h**: this file has info that will be used in the `program.c` from addresses of the register and any macros or bit masking and info the user isn't interested in them.
* **programe.c**: this file has the C code of all functions.
> Note: from the previous description, we can know the the first two file `interface.h` `config.h` the user can access them or see what is inside so that he can use the driver and knows its options. and the last two file `private.h` `program.c` the user can't access them or even know what is inside.

> Note: there is a folder called **LIB** (Library) this folder contains utilities or files that will be used in all layers like the standard data types or bit manipulation.