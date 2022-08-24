/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: DIO					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef DIO_INTERFACE_H
#define DIO_INTERFACE_H

/* This function set the port value to be high or low.
 * Arguments: PORT (DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD) - Direction (DIO_PORT_HIGH - DIO_PORT_LOW)
 * Returns: Error states DIO_OK - DIO_ERROR */
u8 DIO_u8SetPortValue(u8 Copy_u8Port, u8 Copy_u8Value);
/* This function set the port direction to be output or input.
 * Arguments: PORT (DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD) - Direction (DIO_PORT_OUTPUT - DIO_PORT_INPUT)
 * Returns: Error states DIO_OK - DIO_ERROR */
u8 DIO_u8SetPortDirection(u8 Copy_u8Port, u8 Copy_u8Direction);
/* This function get the port value.
 * Arguments: PORT (DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD) - Pointer to variable
 * Returns: Error states (DIO_OK - DIO_ERROR) */
u8 DIO_u8GetPortValue(u8 Copy_u8Port, u8 *Copy_u8Variable);

/* This function set the pin value to be high or low.
 * Arguments: PORT (DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD) - PIN (DIO_PIN0 : DIO_PIN7) - Direction (DIO_PIN_HIGH - DIO_PIN_LOW)
 * Returns: Error states (DIO_OK - DIO_ERROR) */
u8 DIO_u8SetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Value);
/* This function set the pin direction to be output or input.
 * Arguments: PORT (DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD) - PIN (DIO_PIN0 : DIO_PIN7) - Direction (DIO_PIN_OUTPUT - DIO_PIN_INPUT)
 * Returns: Error states (DIO_OK - DIO_ERROR) */
u8 DIO_u8SetPinDirection(u8 Copy_u8Port, u8 Copy_u8Pin, u8 Copy_u8Direction);
/* This function get the pin value.
 * Arguments: PORT (DIO_PORTA - DIO_PORTB - DIO_PORTC - DIO_PORTD) - PIN (DIO_PIN0 : DIO_PIN7) - Pointer to variable
 * Returns: Error states (DIO_OK - DIO_ERROR) */
u8 DIO_u8GetPinValue(u8 Copy_u8Port, u8 Copy_u8Pin, u8 *Copy_u8Variable);

#define DIO_PIN_INPUT			0
#define DIO_PIN_OUTPUT	    	1

#define DIO_PIN_LOW		    	0
#define DIO_PIN_HIGH	    	1

#define DIO_PORTA		    	0
#define DIO_PORTB		    	1
#define DIO_PORTC		    	2
#define DIO_PORTD		    	3

#define DIO_PIN0		    	0
#define DIO_PIN1		    	1
#define DIO_PIN2		    	2
#define DIO_PIN3		    	3
#define DIO_PIN4		   	 	4
#define DIO_PIN5		   	 	5
#define DIO_PIN6		    	6
#define DIO_PIN7		    	7

#define DIO_NO_PULLUP	    	0
#define DIO_PULLUP		    	1

#define DIO_PORT_INPUT	   		0
#define DIO_PORT_OUTPUT	    	0xff
#define DIO_PORT_LHALF_OUTPUT   0xf0
#define DIO_PORT_FHALF_OUTPUT   0x0f

#define DIO_PORT_LOW	    	0
#define DIO_PORT_HIGH	    	0xff

#define DIO_OK					0
#define DIO_ERROR				1

#endif
