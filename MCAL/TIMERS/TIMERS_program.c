/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: TIMERS					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"
#include "../DIO/DIO_interface.h"
#include "TIMERS_interface.h"
#include "TIMERS_private.h"
#include "TIMERS_config.h"

/*Array of pointers to function*/
static void (*Global_pvArrayFunction[ARRAY_SIZE])(void) = {NULL};

/********************			TIMER0 Functions			*********************************/

void TIMERS_voidTimer0Init (void)
{
	#if TIMER0_MODE == TIMER0_OVF_MODE
		/*Set OVF mode*/
		CLR_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
		/*Timer0 Interrupt mode*/
		#if TIMER0_OVF_INTERRUPT == TIMER0_OVF_INTERRUPT_ON
			/*Enable OVF interrupt*/
			SET_BIT(TIMSK, TIMSK_TOIE0);
		#elif TIMER0_OVF_INTERRUPT == TIMER0_OVF_INTERRUPT_OFF
			/*Disable OVF interrupt*/
			CLR_BIT(TIMSK, TIMSK_TOIE0);
		#else
			#error "Timer0_OVF_INTERRUPT Configuration Error"
		#endif
	#elif TIMER0_MODE == TIMER0_PWM_PHASE_CORRECT_MODE
		/*Set OVF mode*/
		SET_BIT(TCCR0, TCCR0_WGM00);
		CLR_BIT(TCCR0, TCCR0_WGM01);
		/*Set mode: OC0 PIN mode*/
		TCCR0 &= OC0_PIN_MASK;
		TCCR0 |= OC0_PIN_MODE;

	#elif TIMER0_MODE == TIMER0_CTC_MODE
		/*Set CTC mode*/
		CLR_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
		/*Timer0 Interrupt mode*/
		#if TIMER0_CTC_INTERRUPT == TIMER0_CTC_INTERRUPT_ON
			/*Enable CTC interrupt*/
			SET_BIT(TIMSK, TIMSK_OCIE0);
		#elif TIMER0_CTC_INTERRUPT == TIMER0_CTC_INTERRUPT_OFF
			/*Disable CTC interrupt*/
			CLR_BIT(TIMSK, TIMSK_OCIE0);
		#else
			#error "Timer0_CTC_INTERRUPT Configuration Error"
		#endif
		/*Set mode: OC0 PIN mode*/
		TCCR0 &= OC0_PIN_MASK;
		TCCR0 |= OC0_PIN_MODE;

	#elif TIMER0_MODE == TIMER0_FAST_PWM_MODE
		/*Set Fast PMW mode*/
		SET_BIT(TCCR0, TCCR0_WGM00);
		SET_BIT(TCCR0, TCCR0_WGM01);
		/*Set mode: OC0 PIN mode*/
		TCCR0 &= OC0_PIN_MASK;
		TCCR0 |= OC0_PIN_MODE;
	#else
		#error "Timer0_MODE Configuration Error"
	#endif

	/*Set Prescaler of the clock*/
	TCCR0 &= TIMERS_PRESCALER_MASK;
	TCCR0 |= TIMER0_PRESCALER;
}

u8 TIMERS_u8Timer0SetCompareMatchValue (u8 Copy_u8CompareMatchValue)
{
	if (Copy_u8CompareMatchValue < 256)
	{
		OCR0 = Copy_u8CompareMatchValue;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

u8 TIMERS_u8Timer0SetPreloadValue (u8 Copy_u8PreloadValue)
{
	if (Copy_u8PreloadValue < 256)
	{
		TCNT0 = Copy_u8PreloadValue;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

u8 TIMERS_u8Timer0CTCSetCallbackFunction (void (*Copy_pvCTCFunction) (void))
{
	if (Copy_pvCTCFunction != NULL)
	{
		Global_pvArrayFunction[TIMER0_CTC] = Copy_pvCTCFunction;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

u8 TIMERS_u8Timer0OVFSetCallbackFunction (void (*Copy_pvOVFFunction) (void))
{
	if (Copy_pvOVFFunction != NULL)
	{
		Global_pvArrayFunction[TIMER0_OVF] = Copy_pvOVFFunction;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

u8 TIMERS_u8Timer0Delay (u32 Copy_u32Delay, u8 Copy_u8Type)
{
	//Check Delay Type
	if (Copy_u8Type == TIMERS_US)
	{
		if (Copy_u32Delay < 51)
		{
			return OK;
		}
		else if (Copy_u32Delay < 701)
		{
			Copy_u32Delay = 0;
		}
		else if (Copy_u32Delay < 2000)
		{
			Copy_u32Delay = 1;
		}
		else
		{
			Copy_u32Delay -= TIMER0_INSTRUCTIONS_TIME;
		}
	}
	//Check if the user work in the correct mode or not
	#if ((TIMER0_MODE == TIMER0_CTC_MODE) || (TIMER0_MODE == TIMER0_OVF_MODE))
		f32 Local_f32TickTime, Local_f32OVFNumbers = 0;
		u8 Local_u8Value = TIMER0_OVF_VALUE - 1;
		u32 Local_u32OVFNumbersInteger = 0, Local_u32OverflowTime;

		//Calculate the tick time
		#if TIMER0_PRESCALER == TIMERS_PRESCALER_DIV_BY_1
			Local_f32TickTime = 1.0 / CLOCK;
		#elif TIMER0_PRESCALER == TIMERS_PRESCALER_DIV_BY_8
			Local_f32TickTime = 8.0 / CLOCK;
		#elif TIMER0_PRESCALER == TIMERS_PRESCALER_DIV_BY_64
			Local_f32TickTime = 64.0 / CLOCK;
		#elif TIMER0_PRESCALER == TIMERS_PRESCALER_DIV_BY_256
			Local_f32TickTime = 256.0 / CLOCK;
		#elif TIMER0_PRESCALER == TIMERS_PRESCALER_DIV_BY_1024
			Local_f32TickTime = 1024.0 / CLOCK;
		#endif
		//Calculate the overflow Time
		Local_u32OverflowTime = Local_f32TickTime * (TIMER0_OVF_VALUE);
		//Check if the delay is less the tick time
		if (Copy_u32Delay <= Local_f32TickTime)
		{
			return OK;
		}
		//Check if the delay is more the tick time and less than or equal the over flow time
		else if ((Copy_u32Delay > Local_f32TickTime) && (Copy_u32Delay <= Local_u32OverflowTime))
		{
			Local_u8Value = Copy_u32Delay / Local_f32TickTime;
			Local_u32OVFNumbersInteger = 1;
		}
		//Check if the delay more than the over flow time
		else if (Copy_u32Delay > Local_u32OverflowTime)
		{
			Local_f32OVFNumbers = (Copy_u32Delay / ((TIMER0_OVF_VALUE) * Local_f32TickTime));
			Local_u32OVFNumbersInteger = (u32)(Local_f32OVFNumbers);
			Local_f32OVFNumbers -= Local_u32OVFNumbersInteger;
		}
		//Calculations for CTC Mode
		#if TIMER0_MODE == TIMER0_CTC_MODE
			TIMERS_u8Timer0SetCompareMatchValue(Local_u8Value);
			TIMERS_voidTimer0Init();
			for (u32 Local_u32Iterator = 0; Local_u32Iterator < Local_u32OVFNumbersInteger; Local_u32Iterator++)
			{
				while (GET_BIT(TIFR, TIFR_OCF0) == 0);
				SET_BIT(TIFR, TIFR_OCF0);
			}
			Local_u8Value = Local_f32OVFNumbers * (TIMER0_OVF_VALUE);
			TIMERS_u8Timer0SetCompareMatchValue(Local_u8Value);
			while (GET_BIT(TIFR, TIFR_OCF0) == 0);
			SET_BIT(TIFR, TIFR_OCF0);
		//Calculations for OVF Mode
		#elif TIMER0_MODE == TIMER0_OVF_MODE
			Local_u8Value = (TIMER0_OVF_VALUE) * (1 - Local_f32OVFNumbers);
			TIMERS_u8Timer0SetPreloadValue(Local_u8Value);
			TIMERS_voidTimer0Init();
			for (u32 Local_u32Iterator = 0; Local_u32Iterator <= Local_u32OVFNumbersInteger; Local_u32Iterator++)
			{
				while (GET_BIT(TIFR, TIFR_TOV0) == 0);
				SET_BIT(TIFR, TIFR_TOV0);
			}
		#endif
		return OK;
	#else
		#warning "The Delay function of Timer0 won't work"
	#endif
}

void __vector_10 (void) __attribute__((signal));
void __vector_10 (void)
{
	if (Global_pvArrayFunction[TIMER0_CTC] != NULL)
	{
		Global_pvArrayFunction[TIMER0_CTC]();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_11 (void) __attribute__((signal));
void __vector_11 (void)
{
	if (Global_pvArrayFunction[TIMER0_OVF] != NULL)
	{
		Global_pvArrayFunction[TIMER0_OVF]();
	}
	else
	{
		/*Do Nothing*/
	}
}


/********************			TIMER1 Functions			*********************************/

void TIMERS_voidTimer1Init (void)
{
	/*Set mode of operation*/
	TCCR1 &= TIMER1_MODE_MASK;
	TCCR1 |= TIMER1_MODE;
	/*Timer1 Interrupt mode*/
	#if TIMER1_MODE != TIMER1_OVF_MODE
		/*Set mode: OC1A PIN mode*/
		TCCR1A &= OC1A_PIN_MASK;
		TCCR1A |= OC1A_PIN_MODE;
		/*Set mode: OC1B PIN mode*/
		TCCR1A &= OC1B_PIN_MASK;
		TCCR1A |= OC1B_PIN_MODE;
	#elif TIMER1_MODE == TIMER1_OVF_MODE
        #if TIMER1_OVF_INTERRUPT == TIMER1_OVF_INTERRUPT_ON
        	/*Enable OVF interrupt*/
        	SET_BIT(TIMSK, TIMSK_TOIE1);
        #elif TIMER1_OVF_INTERRUPT == TIMER1_OVF_INTERRUPT_OFF
        	/*Disable OVF interrupt*/
        	CLR_BIT(TIMSK, TIMSK_TOIE1);
        #else
        	#error "Timer1_OVF_INTERRUPT Configuration Error"
        #endif
	#else
		#error "Timer1_MODE Configuration Error"
	#endif
	/*Set Prescaler of the clock*/
	TCCR1B &= TIMERS_PRESCALER_MASK;
	TCCR1B |= TIMER1_PRESCALER;
}

void TIMERS_voidTimer1SetPreloadValue (u16 Copy_u16PreloadValue)
{
	TCNT1 = Copy_u16PreloadValue;
}

void TIMERS_voidTimer1SetTopValue (u16 Copy_u16TopValue)
{
	ICR1 = Copy_u16TopValue;
}

void TIMERS_voidTimer1SetChannelACompareMatchValue (u16 Copy_u16CompareMatchValue)
{
	OCR1A = Copy_u16CompareMatchValue;
}

void TIMERS_voidTimer1SetCTCAInterruptControl (u8 Copy_u8InterruptState)
{
	switch(Copy_u8InterruptState)
	{
		case TIMERS_ENABLE:
		{
			/*Enable CTC Interrupt for Channel A*/
			SET_BIT(TIMSK, TIMSK_OCIE1A);
			break;
		}
		case TIMERS_DISABLE:
		{
			/*Disable CTC Interrupt for Channel A*/
			CLR_BIT(TIMSK, TIMSK_OCIE1A);
			break;
		}
	}
}

void TIMERS_voidTimer1SetChannelBCompareMatchValue (u16 Copy_u16CompareMatchValue)
{
	OCR1B = Copy_u16CompareMatchValue;
}

void TIMERS_voidTimer1SetCTCBInterruptControl (u8 Copy_u8InterruptState)
{
	switch(Copy_u8InterruptState)
	{
		case TIMERS_ENABLE:
		{
			/*Enable CTC Interrupt for Channel B*/
			SET_BIT(TIMSK, TIMSK_OCIE1B);
			break;
		}
		case TIMERS_DISABLE:
		{
			/*Disable CTC Interrupt for Channel B*/
			CLR_BIT(TIMSK, TIMSK_OCIE1B);
			break;
		}
	}
}

void TIMERS_voidTimer1ICUSetSenseControl (u8 Copy_u8SenseControl)
{
	switch(Copy_u8SenseControl)
	{
		case TIMERS_FALLING_EDGE:
		{
			/*Set Sense Signal To Be Falling Edge*/
			CLR_BIT(TCCR1B, TCCR1B_ICES1);
			break;
		}
		case TIMERS_RISING_EDGE:
		{
			/*Set Sense Signal To Be Rising Edge*/
			SET_BIT(TCCR1B, TCCR1B_ICES1);
			break;
		}
	}
}

u16 TIMERS_u16Timer1ICUReadInputCapture (void)
{
	/*Return Input Capture Register*/
	return ICR1;
}

void TIMERS_voidTimer1ICUInterruptControl (u8 Copy_u8InterruptState)
{
	switch(Copy_u8InterruptState)
	{
		case TIMERS_ENABLE:
		{
			/*Enable ICU Interrupt*/
			SET_BIT(TIMSK, TIMSK_TICIE1);
		break;
		}
		case TIMERS_DISABLE:
		{
			/*Disable ICU Interrupt*/
			CLR_BIT(TIMSK, TIMSK_TICIE1);
		break;
		}
	}
}

void TIMERS_voidTimer1ICUSetCallbackFunction (void (*Copy_pvICUFunction) (void))
{
	Global_pvArrayFunction[TIMER1_ICU] = Copy_pvICUFunction;
}

void TIMERS_voidTimer1CTCASetCallbackFunction (void (*Copy_pvCTCAFunction) (void))
{
	Global_pvArrayFunction[TIMER1_CTCA] = Copy_pvCTCAFunction;
}

void TIMERS_voidTimer1CTCBSetCallbackFunction (void (*Copy_pvCTCBFunction) (void))
{
	Global_pvArrayFunction[TIMER1_CTCB] = Copy_pvCTCBFunction;
}

void TIMERS_voidTimer1OVFSetCallbackFunction (void (*Copy_pvOVFFunction) (void))
{
	Global_pvArrayFunction[TIMER1_OVF] = Copy_pvOVFFunction;
}

void __vector_6 (void) __attribute__((signal));
void __vector_6 (void)
{
	if (Global_pvArrayFunction[TIMER1_ICU] != NULL)
	{
		Global_pvArrayFunction[TIMER1_ICU]();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_7 (void) __attribute__((signal));
void __vector_7 (void)
{
	if (Global_pvArrayFunction[TIMER1_CTCA] != NULL)
	{
		Global_pvArrayFunction[TIMER1_CTCA]();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_8 (void) __attribute__((signal));
void __vector_8 (void)
{
	if (Global_pvArrayFunction[TIMER1_CTCB] != NULL)
	{
		Global_pvArrayFunction[TIMER1_CTCB]();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_9 (void) __attribute__((signal));
void __vector_9 (void)
{
	if (Global_pvArrayFunction[TIMER1_OVF] != NULL)
	{
		Global_pvArrayFunction[TIMER1_OVF]();
	}
	else
	{
		/*Do Nothing*/
	}
}


/********************			TIMER2 Functions			*********************************/

void TIMERS_voidTimer2Init (void)
{
	#if TIMER2_MODE == TIMER2_OVF_MODE
		/*Set OVF mode*/
		CLR_BIT(TCCR2, TCCR2_WGM20);
		CLR_BIT(TCCR2, TCCR2_WGM21);
		/*Timer2 Interrupt mode*/
        #if TIMER2_OVF_INTERRUPT == TIMER2_OVF_INTERRUPT_ON
        	/*Enable OVF interrupt*/
        	SET_BIT(TIMSK, TIMSK_TOIE2);
        #elif TIMER2_OVF_INTERRUPT == TIMER2_OVF_INTERRUPT_OFF
        	/*Disable OVF interrupt*/
        	CLR_BIT(TIMSK, TIMSK_TOIE2);
        #else
        	#error "Timer2_OVF_INTERRUPT Configuration Error"
        #endif
	#elif TIMER2_MODE == TIMER2_PWM_PHASE_CORRECT_MODE
		/*Set OVF mode*/
		SET_BIT(TCCR2, TCCR2_WGM20);
		CLR_BIT(TCCR2, TCCR2_WGM21);
		/*Set mode: OC2 PIN mode*/
		TCCR2 &= OC2_PIN_MASK;
		TCCR2 |= OC2_PIN_MODE;

	#elif TIMER2_MODE == TIMER2_CTC_MODE
		/*Set CTC mode*/
		CLR_BIT(TCCR2, TCCR2_WGM20);
		SET_BIT(TCCR2, TCCR2_WGM21);
		/*Timer2 Interrupt mode*/
        #if TIMER2_CTC_INTERRUPT == TIMER2_CTC_INTERRUPT_ON
        	/*Enable CTC interrupt*/
        	SET_BIT(TIMSK, TIMSK_OCIE2);
        #elif TIMER2_CTC_INTERRUPT == TIMER2_CTC_INTERRUPT_OFF
        	/*Disable CTC interrupt*/
        	CLR_BIT(TIMSK, TIMSK_OCIE2);
        #else
        	#error "Timer2_CTC_INTERRUPT Configuration Error"
        #endif
		/*Set mode: OC2 PIN mode*/
		TCCR2 &= OC2_PIN_MASK;
		TCCR2 |= OC2_PIN_MODE;

	#elif TIMER2_MODE == TIMER2_FAST_PWM_MODE
		/*Set Fast PMW mode*/
		SET_BIT(TCCR2, TCCR2_WGM20);
		SET_BIT(TCCR2, TCCR2_WGM21);
		/*Set mode: OC2 PIN mode*/
		TCCR2 &= OC2_PIN_MASK;
		TCCR2 |= OC2_PIN_MODE;
	#else
		#error "Timer2_MODE Configuration Error"
	#endif

	/*Set Prescaler of the clock*/
	TCCR2 &= TIMERS_PRESCALER_MASK;
	TCCR2 |= TIMER2_PRESCALER;
}

u8 TIMERS_u8Timer2SetCompareMatchValue (u8 Copy_u8CompareMatchValue)
{
	if (Copy_u8CompareMatchValue < 256)
	{
		OCR2 = Copy_u8CompareMatchValue;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

u8 TIMERS_u8Timer2SetPreloadValue (u8 Copy_u8PreloadValue)
{
	if (Copy_u8PreloadValue < 256)
	{
		TCNT2 = Copy_u8PreloadValue;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

u8 TIMERS_u8Timer2CTCSetCallbackFunction (void (*Copy_pvCTCFunction) (void))
{
	if (Copy_pvCTCFunction != NULL)
	{
		Global_pvArrayFunction[TIMER2_CTC] = Copy_pvCTCFunction;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

u8 TIMERS_u8Timer2OVFSetCallbackFunction (void (*Copy_pvOVFFunction) (void))
{
	if (Copy_pvOVFFunction != NULL)
	{
		Global_pvArrayFunction[TIMER2_OVF] = Copy_pvOVFFunction;
		return OK;
	}
	else
	{
		return ERROR;
	}
}

void __vector_4 (void) __attribute__((signal));
void __vector_4 (void)
{
	if (Global_pvArrayFunction[TIMER2_CTC] != NULL)
	{
		Global_pvArrayFunction[TIMER2_CTC]();
	}
	else
	{
		/*Do Nothing*/
	}
}

void __vector_5 (void) __attribute__((signal));
void __vector_5 (void)
{
	if (Global_pvArrayFunction[TIMER2_OVF] != NULL)
	{
		Global_pvArrayFunction[TIMER2_OVF]();
	}
	else
	{
		/*Do Nothing*/
	}
}



