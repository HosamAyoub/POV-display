/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: HAL					*********************************/
/********************			SWC: LED					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "../../MCAL/TIMERS/TIMERS_interface.h"
#include "LED_interface.h"
#include "LED_config.h"
#include "LED_private.h"

LED_t LEDS[NUMBER_OF_LEDS] = {{NULL}};

u8 LED_u8InitLED (u8 Copy_u8ID, u8 Copy_u8Port, u8 Copy_u8Pin)
{
	if (Copy_u8ID < NUMBER_OF_LEDS)
	{
		LEDS[Copy_u8ID].u8Port = Copy_u8Port;
		LEDS[Copy_u8ID].u8Pin = Copy_u8Pin;
		DIO_u8SetPinDirection(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_OUTPUT);
		return OK;
	}
	else
	{
		return ERROR;
	}
}

u8 LED_u8InitGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID, u8 Copy_u8Port, u8 Copy_u8Pin)
{
	if ((Copy_u8EndID - Copy_u8StartID) <= (DIO_PIN7 - Copy_u8Pin))
	{
		for (u8 Local_u8Iterator = Copy_u8StartID; Local_u8Iterator <= Copy_u8EndID; Local_u8Iterator++)
		{
			LEDS[Local_u8Iterator].u8Port = Copy_u8Port;
			LEDS[Local_u8Iterator].u8Pin = Copy_u8Pin + (Local_u8Iterator - Copy_u8StartID);
			DIO_u8SetPinDirection(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_OUTPUT);
		}
		return OK;
	}
	else
	{
		return ERROR;
	}
}

u8 LED_u8TurnOnLED (u8 Copy_u8ID)
{
	if (Copy_u8ID < NUMBER_OF_LEDS)
	{
		#if CONNECTION_TYPE == SOURCE
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
			return OK;
		#elif CONNECTION_TYPE == SINK
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
			return OK;

		#else
			#error "LED Connection Type Error"
		#endif
	}
	else
	{
		return ERROR;
	}
}

u8 LED_u8TurnOnGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID)
{
	if (Copy_u8StartID < NUMBER_OF_LEDS && Copy_u8EndID > Copy_u8StartID && Copy_u8EndID < NUMBER_OF_LEDS)
	{
		for (u8 Local_u8Iterator = Copy_u8StartID; Local_u8Iterator <= Copy_u8EndID; Local_u8Iterator++)
		{
			#if CONNECTION_TYPE == SOURCE
				DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
			#elif CONNECTION_TYPE == SINK
				DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
			#else
				#error "LED Connection Type Error"
			#endif
		}
		return OK;
	}
	else
	{
		return ERROR;
	}
}

u8 LED_u8TurnOffLED (u8 Copy_u8ID)
{
	if (Copy_u8ID < NUMBER_OF_LEDS)
	{
		#if CONNECTION_TYPE == SOURCE
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
			return OK;
		#elif CONNECTION_TYPE == SINK
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
			return OK;
		#else
			#error "LED Connection Type Error"
		#endif
	}
	else
	{
		return ERROR;
	}
}

u8 LED_u8TurnOffGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID)
{
	if (Copy_u8StartID < NUMBER_OF_LEDS && Copy_u8EndID > Copy_u8StartID && Copy_u8EndID < NUMBER_OF_LEDS)
	{
		for (u8 Local_u8Iterator = Copy_u8StartID; Local_u8Iterator <= Copy_u8EndID; Local_u8Iterator++)
		{
			#if CONNECTION_TYPE == SOURCE
				DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
			#elif CONNECTION_TYPE == SINK
				DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
			#else
				#error "LED Connection Type Error"
			#endif
		}
		return OK;
	}
	else
	{
		return ERROR;
	}
}

u8 LED_u8ToggleLED (u8 Copy_u8ID)
{
	if (Copy_u8ID < NUMBER_OF_LEDS)
	{
		u8 Local_u8PinState;
		DIO_u8GetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, &Local_u8PinState);
		#if CONNECTION_TYPE == SOURCE
			if (Local_u8PinState == 0)
			{
				DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
			}
			else if (Local_u8PinState == 1)
			{
				DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
			}
			return OK;
		#elif CONNECTION_TYPE == SINK
			if (Local_u8PinState == 0)
			{
				DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
			}
			else if (Local_u8PinState == 1)
			{
				DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
			}
			return OK;
		#else
			#error "LED Connection Type Error"
		#endif
	}
	else
	{
		return ERROR;
	}
}

u8 LED_u8ToggleGroupOfLEDS (u8 Copy_u8StartID, u8 Copy_u8EndID)
{
	if (Copy_u8StartID < NUMBER_OF_LEDS && Copy_u8EndID > Copy_u8StartID && Copy_u8EndID < NUMBER_OF_LEDS)
	{
		u8 Local_u8PinState;
		for (u8 Local_u8Iterator = Copy_u8StartID; Local_u8Iterator <= Copy_u8EndID; Local_u8Iterator++)
		{
			DIO_u8GetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, &Local_u8PinState);
			#if CONNECTION_TYPE == SOURCE
				if (Local_u8PinState == 0)
				{
					DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
				}
				else if (Local_u8PinState == 1)
				{
					DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
				}
			#elif CONNECTION_TYPE == SINK
				if (Local_u8PinState == 0)
				{
					DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
				}
				else if (Local_u8PinState == 1)
				{
					DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
				}
			#else
				#error "LED Connection Type Error"
			#endif
		}
		return OK;
	}
	else
	{
		return ERROR;
	}
}

u8 LED_u8BlinkLED (u8 Copy_u8ID, u32 Copy_u32Delay, u8 Copy_u8DelayType)
{
	if (Copy_u8ID < NUMBER_OF_LEDS)
	{
	u8 Local_u8PinState;
	DIO_u8GetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, &Local_u8PinState);
	#if CONNECTION_TYPE == SOURCE
		if (Local_u8PinState == 0)
		{
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
			switch (Copy_u8DelayType)
			{
				case LED_MILLI_SECOND:
				{
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
					break;
				}
				case LED_MICRO_SECOND:
				{
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
					break;
				}
			}

		}
		else if (Local_u8PinState == 1)
		{
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
			switch (Copy_u8DelayType)
			{
				case LED_MILLI_SECOND:
				{
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
					break;
				}
				case LED_MICRO_SECOND:
				{
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
					break;
				}
			}
		}
		return OK;
	#elif CONNECTION_TYPE == SINK
		if (Local_u8PinState == 0)
		{
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
			switch (Copy_u8DelayType)
			{
				case LED_MILLI_SECOND:
				{
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
					break;
				}
				case LED_MICRO_SECOND:
				{
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
					break;
				}
			}
		}
		else if (Local_u8PinState == 1)
		{
			DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_HIGH);
			switch (Copy_u8DelayType)
			{
				case LED_MILLI_SECOND:
				{
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
					break;
				}
				case LED_MICRO_SECOND:
				{
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
					DIO_u8SetPinValue(LEDS[Copy_u8ID].u8Port, LEDS[Copy_u8ID].u8Pin, DIO_PIN_LOW);
					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
					break;
				}
			}
		}
		return OK;
	#else
		#error "LED Connection Type Error"
	#endif
	}
	else
	{
		return ERROR;
	}
}

//void LED_voidBlinkGroupOfLEDs (u8 Copy_u8StartID, u8 Copy_u8EndID, u16 Copy_u32Delay, u8 Copy_u8DelayType)
//{
//	u8 Local_u8PinState;
//	for (u8 Local_u8Iterator = Copy_u8StartID; Local_u8Iterator <= Copy_u8EndID; Local_u8Iterator++)
//	{
//	DIO_u8GetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, &Local_u8PinState);
//	#if CONNECTION_TYPE == SOURCE
//		if (Local_u8PinState == 0)
//		{
//			DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
//			switch (Copy_u8DelayType)
//			{
//				case LED_MILLI_SECOND:
//				{
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
//					DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
//					break;
//				}
//				case LED_MICRO_SECOND:
//				{
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
//					DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
//					break;
//				}
//			}
//
//		}
//		else if (Local_u8PinState == 1)
//		{
//			DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
//			switch (Copy_u8DelayType)
//			{
//				case LED_MILLI_SECOND:
//				{
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
//					DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
//					break;
//				}
//				case LED_MICRO_SECOND:
//				{
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
//					DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
//					break;
//				}
//			}
//		}
//	#elif CONNECTION_TYPE == SINK
//		if (Local_u8PinState == 0)
//		{
//			DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
//			switch (Copy_u8DelayType)
//			{
//				case LED_MILLI_SECOND:
//				{
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
//					DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
//					break;
//				}
//				case LED_MICRO_SECOND:
//				{
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
//					DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
//					break;
//				}
//			}
//		}
//		else if (Local_u8PinState == 1)
//		{
//			DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_HIGH);
//			switch (Copy_u8DelayType)
//			{
//				case LED_MILLI_SECOND:
//				{
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
//					DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_MS);
//					break;
//				}
//				case LED_MICRO_SECOND:
//				{
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
//					DIO_u8SetPinValue(LEDS[Local_u8Iterator].u8Port, LEDS[Local_u8Iterator].u8Pin, DIO_PIN_LOW);
//					TIMERS_u8Timer0Delay(Copy_u32Delay, TIMERS_US);
//					break;
//				}
//			}
//		}
//	#else
//		#error "LED Connection Type Error"
//	#endif
//	}
//}
