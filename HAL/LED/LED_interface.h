/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: LED					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H


/* This function Initialize LED setup
 * Arguments: ID (0 : NUMBER_OF_LEDS) - PORT (DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD) - PIN (DIO_PIN0 : DIO_PIN7)
 * Returns: Error states (OK - ERROR) */
u8 LED_u8InitLED (u8 Copy_u8ID, u8 Copy_u8Port, u8 Copy_u8Pin);
/* This function Initialize port of LEDs or less than 8 LEDs in a single port
 * Arguments: Start ID (0 : End ID - 1) - End ID (Start ID + 1 : NUMBER_OF_LEDS) - PORT (DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD) - PIN (DIO_PIN0 : DIO_PIN7)
 * Returns: Error states (OK - ERROR) */
u8 LED_u8InitGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID, u8 Copy_u8Port, u8 Copy_u8Pin);
/* This function turn on LED
 * Arguments: Start ID (0 : NUMBER_OF_LEDS)
 * Returns: Error states (OK - ERROR) */
u8 LED_u8TurnOnLED (u8 Copy_u8ID);
/* This function turn on a group of LEDs
 * Arguments: Start ID (0 : End ID - 1) - End ID (Start ID + 1 : NUMBER_OF_LEDS)
 * Returns: Error states (OK - ERROR) */
u8 LED_u8TurnOnGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID);
/* This function turn off LED
 * Arguments: Start ID (0 : NUMBER_OF_LEDS)
 * Returns: Error states (OK - ERROR) */
u8 LED_u8TurnOffLED (u8 Copy_u8ID);
/* This function turn off a group of LEDs
 * Arguments: Start ID (0 : End ID - 1) - End ID (Start ID + 1 : NUMBER_OF_LEDS)
 * Returns: Error states (OK - ERROR) */
u8 LED_u8TurnOffGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID);
/* This function toggle LED
 * Arguments: Start ID (0 : NUMBER_OF_LEDS)
 * Returns: Error states (OK - ERROR) */
u8 LED_u8ToggleLED (u8 Copy_u8ID);
/* This function toggle a group of LEDs
 * Arguments: Start ID (0 : End ID - 1) - End ID (Start ID + 1 : NUMBER_OF_LEDS)
 * Returns: Error states (OK - ERROR) */
u8 LED_u8ToggleGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID);
/* This function blink LED
 * Arguments: Start ID (0 : NUMBER_OF_LEDS) - Delay (0 : 4294967295) - Copy_u8DelayType (LED_MILLI_SECOND - LED_MICRO_SECOND)
 * Returns: Error states (OK - ERROR) */
u8 LED_u8BlinkLED (u8 Copy_u8ID, u32 Copy_u32Delay, u8 Copy_u8DelayType);
//void LED_voidBlinkGroupOfLEDs (u8 Copy_u8StartID, u8 Copy_u8EndID, u32 Copy_u32Delay, u8 Copy_u8DelayType);

/*Delay Types*/
#define LED_MILLI_SECOND				0
#define LED_MICRO_SECOND				1

#endif
