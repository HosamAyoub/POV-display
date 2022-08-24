/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: APP					*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef APP_H
#define APP_H

#define F_CPU 8000000UL
#include "../LIB/STD_TYPES.h"
#include "../LIB/BIT_MATH.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMERS/TIMERS_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../HAL/LED/LED_interface.h"

extern u32 Global_u32Seconds;

/* This function calculates the time of the real second using Timer2 */
void Seconds (void);
/* This function turns on outer frame LED */
void OuterFrame (void);
/* This function turns on minutes marker LEDs */
void MinutesMarker (void);
/* This function turns on hours marker LEDs */
void HoursMarker (void);
/* This function turns on quarters marker LEDs */
void QuartersMarker (void);
/* This function turns on seconds arrow LEDs */
void SecondsArrow (void);
/* This function turns on minutes arrow LEDs */
void MinutesArrow (void);
/* This function turns on hours arrow LEDs */
void HoursArrow (void);
/* This function turns off all LEDs except outer frame LED */
void Clear (void);


#define LEDS_ON_TIME					1
#define LEDS_OFF_TIME					1

#define SENSOR_HIGH						1
#define SENSOR_LOW						0

#define PRELOAD_VALUE					238

#endif
