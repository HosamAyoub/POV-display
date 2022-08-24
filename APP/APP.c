/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: APP					*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "APP.h"

u32 Global_u32Seconds;

void Seconds (void)
{
	static u8 Local_u8Counter = 0;
	static u32 Local_u32Seconds = 0;
	Local_u8Counter++;

	if (Local_u8Counter == 123)
	{
		Local_u8Counter = 0;
		TIMERS_u8Timer2SetPreloadValue(PRELOAD_VALUE);
		Local_u32Seconds++;
	}
	Global_u32Seconds = Local_u32Seconds;
}

void OuterFrame (void)
{
	LED_u8TurnOnLED(11);
}

void MinutesMarker (void)
{
	LED_u8TurnOnLED(10);
}

void HoursMarker (void)
{
	LED_u8TurnOnLED(9);
}

void QuartersMarker (void)
{
	LED_u8TurnOnLED(8);
}

void SecondsArrow (void)
{
	LED_u8TurnOnGroupOfLEDS(0, 7);
}

void MinutesArrow (void)
{
	LED_u8TurnOnGroupOfLEDS(0, 5);
}

void HoursArrow (void)
{
	LED_u8TurnOnGroupOfLEDS(0, 3);
}

void Clear (void)
{
	LED_u8TurnOffGroupOfLEDS(0, 10);
}
