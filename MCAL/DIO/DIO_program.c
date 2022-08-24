/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: DIO					*********************************/
/********************			Version: 1.10				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
#include "DIO_interface.h"
#include "DIO_private.h"
#include "DIO_config.h"

u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction)
{
	u8 Local_u8RunState = DIO_OK;
	switch(Copy_u8Port)
	{
	case DIO_PORTA: DDRA = Copy_u8Direction; break;
	case DIO_PORTB:	DDRB = Copy_u8Direction; break;
	case DIO_PORTC: DDRC = Copy_u8Direction; break;
	case DIO_PORTD: DDRD = Copy_u8Direction; break;
	default: Local_u8RunState = DIO_ERROR;
	}
	return Local_u8RunState;
}


u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value)
{
	u8 Local_u8RunState = DIO_OK;
	switch(Copy_u8Port)
	{
	case DIO_PORTA: PORTA = Copy_u8Value; break;
	case DIO_PORTB:	PORTB = Copy_u8Value; break;
	case DIO_PORTC: PORTC = Copy_u8Value; break;
	case DIO_PORTD: PORTD = Copy_u8Value; break;
	default: Local_u8RunState = DIO_ERROR;
	}
	return Local_u8RunState;
}


u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_u8Variable)
{
	u8 Local_u8RunState = DIO_OK;
	if(Copy_u8Variable != NULL)
	{
		switch(Copy_u8Port)
		{
		case DIO_PORTA: *Copy_u8Variable = PINA; break;
		case DIO_PORTB:	*Copy_u8Variable = PINB; break;
		case DIO_PORTC: *Copy_u8Variable = PINC; break;
		case DIO_PORTD: *Copy_u8Variable = PIND; break;
		default: Local_u8RunState = DIO_ERROR;
		}
	}
	else
	{
		Local_u8RunState = DIO_ERROR;
	}
	return Local_u8RunState;
}


u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction)
{
	u8 Local_u8RunState = DIO_OK;
	if((Copy_u8Pin >= DIO_PIN0) && (Copy_u8Pin <= DIO_PIN7))
	{
		if(Copy_u8Direction == DIO_PIN_INPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA: CLR_BIT(DDRA, Copy_u8Pin); break;
			case DIO_PORTB:	CLR_BIT(DDRB, Copy_u8Pin); break;
			case DIO_PORTC: CLR_BIT(DDRC, Copy_u8Pin); break;
			case DIO_PORTD: CLR_BIT(DDRD, Copy_u8Pin); break;
			default: Local_u8RunState = DIO_ERROR;
			}
		}
		else if(Copy_u8Direction == DIO_PIN_OUTPUT)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA: SET_BIT(DDRA, Copy_u8Pin); break;
			case DIO_PORTB:	SET_BIT(DDRB, Copy_u8Pin); break;
			case DIO_PORTC: SET_BIT(DDRC, Copy_u8Pin); break;
			case DIO_PORTD: SET_BIT(DDRD, Copy_u8Pin); break;
			default: Local_u8RunState = DIO_ERROR;
			}
		}
		else
		{
			Local_u8RunState = DIO_ERROR;
		}
	}
	else
	{
		Local_u8RunState = DIO_ERROR;
	}
	return Local_u8RunState;
}


u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value)
{
	u8 Local_u8RunState = DIO_OK;
	if((Copy_u8Pin >= DIO_PIN0) && (Copy_u8Pin <= DIO_PIN7))
	{
		if(Copy_u8Value == DIO_PIN_LOW)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA: CLR_BIT(PORTA, Copy_u8Pin); break;
			case DIO_PORTB:	CLR_BIT(PORTB, Copy_u8Pin); break;
			case DIO_PORTC: CLR_BIT(PORTC, Copy_u8Pin); break;
			case DIO_PORTD: CLR_BIT(PORTD, Copy_u8Pin); break;
			default: Local_u8RunState = DIO_ERROR;
			}
		}
		else if(Copy_u8Value == DIO_PIN_HIGH)
		{
			switch(Copy_u8Port)
			{
			case DIO_PORTA: SET_BIT(PORTA, Copy_u8Pin); break;
			case DIO_PORTB:	SET_BIT(PORTB, Copy_u8Pin); break;
			case DIO_PORTC: SET_BIT(PORTC, Copy_u8Pin); break;
			case DIO_PORTD: SET_BIT(PORTD, Copy_u8Pin); break;
			default: Local_u8RunState = DIO_ERROR;
			}
		}
		else
		{
			Local_u8RunState = DIO_ERROR;
		}
	}
	else
	{
		Local_u8RunState = DIO_ERROR;
	}
	return Local_u8RunState;
}


u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_u8Variable)
{
	u8 Local_u8RunState = DIO_OK;
	if((Copy_u8Pin >= DIO_PIN0) && (Copy_u8Pin <= DIO_PIN7) && (Copy_u8Variable != NULL))
	{
		switch(Copy_u8Port)
		{
		case DIO_PORTA: *Copy_u8Variable = GET_BIT(PINA, Copy_u8Pin); break;
		case DIO_PORTB:	*Copy_u8Variable = GET_BIT(PINB, Copy_u8Pin); break;
		case DIO_PORTC: *Copy_u8Variable = GET_BIT(PINC, Copy_u8Pin); break;
		case DIO_PORTD: *Copy_u8Variable = GET_BIT(PIND, Copy_u8Pin); break;
		default: Local_u8RunState = DIO_ERROR;
		}
	}
	else
	{
		Local_u8RunState = DIO_ERROR;
	}
	return Local_u8RunState;
}
