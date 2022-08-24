/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "APP/APP.h"

int main (void)
{
	u8 Local_u8SensorState = SENSOR_LOW, Local_u8Hours = 9, Local_u8Minutes = 30,
			Local_u8Seconds = 15, Local_u8Postion = 0, Local_u8Iterator = 0;
	u32 Local_u32PreviousTime = 0;

	/*Enabling the global interrupt*/
	GIE_voidEnableGlobalInterrupt();
	/* Timer2 configuration */
	TIMERS_u8Timer2SetPreloadValue(PRELOAD_VALUE);
	TIMERS_u8Timer2OVFSetCallbackFunction(&Seconds);
	/* Timer2 Initialization */
	TIMERS_voidTimer2Init();

	/* Initializing sensor pins */
	DIO_u8SetPinDirection(DIO_PORTD, DIO_PIN7, DIO_PIN_INPUT);
	DIO_u8SetPinDirection(DIO_PORTC, DIO_PIN0, DIO_PIN_OUTPUT);
	DIO_u8SetPinDirection(DIO_PORTC, DIO_PIN1, DIO_PIN_OUTPUT);
	DIO_u8SetPinValue(DIO_PORTD, DIO_PIN7, DIO_PIN_HIGH);
	DIO_u8SetPinValue(DIO_PORTC, DIO_PIN0, DIO_PIN_LOW);
	DIO_u8SetPinValue(DIO_PORTC, DIO_PIN1, DIO_PIN_HIGH);
	/* Initializing red LEDs */
	LED_u8InitGroupOfLEDS(0, 7, DIO_PORTA, DIO_PIN0);
	/* Initializing yellow LEDs */
	LED_u8InitLED(8, DIO_PORTC, DIO_PIN7);
	LED_u8InitLED(9, DIO_PORTC, DIO_PIN6);
	LED_u8InitLED(10, DIO_PORTC, DIO_PIN5);
	/* Initializing blue LED */
	LED_u8InitLED(11, DIO_PORTC, DIO_PIN4);
	/* Turn on the outer frame of the clock */
	OuterFrame();
	/* Checking if hours reach 12 to clear it */
	if (Local_u8Hours == 12)
	{
		Local_u8Hours = 0;
	}

	while (1)
	{
		/* Getting sensor value */
		DIO_u8GetPinValue(DIO_PORTD, DIO_PIN7, &Local_u8SensorState);
		/* polling in sensor to check it passes the magnet or not */
		while (Local_u8SensorState == SENSOR_LOW)
		{
			/* Getting sensor value */
			DIO_u8GetPinValue(DIO_PORTD, DIO_PIN7, &Local_u8SensorState);
		}
		/* Check if a second has passed real time clock */
		if (Global_u32Seconds >= Local_u32PreviousTime)
		{
			Local_u32PreviousTime++;
			Local_u8Seconds++;
			/* Checking if seconds reach 60 so that it will be cleared and increase the minutes by 1 */
			if (Local_u8Seconds == 60)
			{
				Local_u8Seconds = 0;
				Local_u8Minutes++;
			}
			/* Checking if minute reach 60 so that it will be cleared and increase the hourse by 1 */
			if (Local_u8Minutes == 60)
			{
				Local_u8Minutes = 0;
				Local_u8Hours++;
			}
			/* Checking if hours reach 12 to clear it */
			if (Local_u8Hours == 12)
			{
				Local_u8Hours = 0;
			}
		}

		Local_u8Postion = 45;
		/* Looping in the 60 sections of the clock */
		for (Local_u8Iterator = 0; Local_u8Iterator < 60; Local_u8Iterator++)
		{
			/* Turn on minutes marker */
			MinutesMarker();
			/* cehck if the position was in the hours values to draw hours marker */
			if ((Local_u8Postion == 0) || (Local_u8Postion == 5) || (Local_u8Postion == 10) ||
					(Local_u8Postion == 15) || (Local_u8Postion == 20) || (Local_u8Postion == 25) ||
					(Local_u8Postion == 30) || (Local_u8Postion == 35) || (Local_u8Postion == 40) ||
					(Local_u8Postion == 45) || (Local_u8Postion == 50) || (Local_u8Postion == 55))
			{
				/* Turn on hours marker */
				HoursMarker();
			}
			/* cehck if the position was in the quarters values to draw quarters marker */
			if ((Local_u8Postion==0) || (Local_u8Postion==15) || (Local_u8Postion==30) || (Local_u8Postion==45))
			{
				/* Turn on quarters marker */
				QuartersMarker();
			}
			if(Local_u8Postion == Local_u8Hours*5)
			{
				/* Turn on hours arrow */
				HoursArrow();
			}
			if(Local_u8Postion == Local_u8Minutes)
			{
				/* Turn on minutes arrow */
				MinutesArrow();
			}
			if(Local_u8Postion == Local_u8Seconds)
			{
				/* Turn on seconds arrow */
				SecondsArrow();
			}
			/* The on-time delay for all LEDs except outer frame LED */
			TIMERS_u8Timer0Delay(LEDS_ON_TIME, TIMERS_MS);
			/* Turn off all LEDs except outer frame LED */
			Clear();
			/* The off-time delay for all LEDs except outer frame LED */
			TIMERS_u8Timer0Delay(LEDS_OFF_TIME, TIMERS_MS);
			/* Incrementing position variable */
			Local_u8Postion++;
			/* Checking if the position reached 60 to clear it */
			if (Local_u8Postion == 60)
			{
				Local_u8Postion = 0;
			}
		}
		/* Getting sensor value */
		DIO_u8GetPinValue(DIO_PORTD, DIO_PIN7, &Local_u8SensorState);
		/* polling in sensor to check it reachs the magnet or not */
		while (Local_u8SensorState == SENSOR_HIGH)
		{
			/* Getting sensor value */
			DIO_u8GetPinValue(DIO_PORTD, DIO_PIN7, &Local_u8SensorState);
		}
	}
}


