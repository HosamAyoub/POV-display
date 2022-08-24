/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: TIMERS					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef TIMERS_CONFIG_H
#define TIMERS_CONFIG_H

/********************					Timer0				*********************************/
/*Options Timer0 modes of operation:
 * 1- TIMER0_OVF_MODE
 * 2- TIMER0_PWM_PHASE_CORRECT_MODE
 * 3- TIMER0_CTC_MODE
 * 4- TIMER0_FAST_PWM_MODE*/
#define	TIMER0_MODE								TIMER0_OVF_MODE

/*Options Clock Prescaler:
 * 1- TIMERS_NO_CLOCK_SOURCE
 * 2- TIMERS_PRESCALER_DIV_BY_1
 * 3- TIMERS_PRESCALER_DIV_BY_8
 * 4- TIMERS_PRESCALER_DIV_BY_64
 * 5- TIMERS_PRESCALER_DIV_BY_256
 * 6- TIMERS_PRESCALER_DIV_BY_1024
 * 7- TIMERS_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE
 * 8- TIMERS_EXTERNAL_CLOCK_SOURCE_RISING_EDGE*/
#define TIMER0_PRESCALER						TIMERS_PRESCALER_DIV_BY_1

/*Options for OC0 in CTC mode:							Options for OC0 in PWM (Fast/PHASE CORRECT):
 * 1- OC0_CTC_DISCONNECTED								1- OC0_PWM_DISCONNECTED
 * 2- OC0_CTC_TOGGLE									2- OC0_PWM_CLR_ON_CMP
 * 3- OC0_CTC_CLR_ON_CMP								3- OC0_PWM_SET_ON_CMP
 * 4- OC0_CTC_SET_ON_CMP																			*/
#define OC0_PIN_MODE							OC0_CTC_DISCONNECTED

/*Options for Interrupt OVF mode:
 * 1- TIMER0_OVF_INTERRUPT_ON							2- TIMER0_OVF_INTERRUPT_OFF*/
#define TIMER0_OVF_INTERRUPT					TIMER0_OVF_INTERRUPT_OFF

/*Options for Interrupt CTC mode:
 * 1- TIMER0_CTC_INTERRUPT_ON							2- TIMER0_CTC_INTERRUPT_OFF*/
#define TIMER0_CTC_INTERRUPT					TIMER0_CTC_INTERRUPT_OFF

/********************					Timer1				*********************************/
/*Options Timer1 modes of operation:
 * 1- TIMER1_OVF_MODE
 * 2- TIMER1_PWM_PHASE_CORRECT_8_BIT_MODE
 * 3- TIMER1_PWM_PHASE_CORRECT_9_BIT_MODE
 * 4- TIMER1_PWM_PHASE_CORRECT_10_BIT_MODE
 * 5- TIMER1_CTC_MODE
 * 6- TIMER1_FAST_PWM_8_BIT_MODE
 * 7- TIMER1_FAST_PWM_9_BIT_MODE
 * 8- TIMER1_FAST_PWM_10_BIT_MODE
 * 9- TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICU
 * 10-TIMER1_PWM_PHASE_FREQUENCY_CORRECT_OC
 * 11-TIMER1_PWM_PHASE_CORRECT_ICU_MODE
 * 12-TIMER1_PWM_PHASE_CORRECT_OC_MODE
 * 13-TIMER1_CTC_ICU_MODE
 * 14-TIMER1_FAST_PWM_ICU_MODE
 * 15-TIMER1_FAST_PWM_OC_MODE*/
#define TIMER1_MODE								TIMER1_OVF_MODE

/*Options for Clock Prescaler:
 * 1- TIMERS_NO_CLOCK_SOURCE
 * 2- TIMERS_PRESCALER_DIV_BY_1
 * 3- TIMERS_PRESCALER_DIV_BY_8
 * 4- TIMERS_PRESCALER_DIV_BY_64
 * 5- TIMERS_PRESCALER_DIV_BY_256
 * 6- TIMERS_PRESCALER_DIV_BY_1024
 * 7- TIMERS_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE
 * 8- TIMERS_EXTERNAL_CLOCK_SOURCE_RISING_EDGE*/
#define TIMER1_PRESCALER						TIMERS_PRESCALER_DIV_BY_8

/*Options for OC1A in CTC mode:							Options for OC1A in PWM (Fast/PHASE CORRECT):
 * 1- OC1A_CTC_DISCONNECTED								1- OC1A_PWM_DISCONNECTED
 * 2- OC1A_CTC_TOGGLE									2- OC1A_PWM_TOGGLE_ON_CMP
 * 3- OC1A_CTC_CLR_ON_CMP								3- OC1A_PWM_CLR_ON_CMP
 * 4- OC1A_CTC_SET_ON_CMP								4- OC1A_PWM_SET_ON_CMP*/
#define OC1A_PIN_MODE							OC1A_CTC_DISCONNECTED

/*Options for OC1B in CTC mode:							Options for OC1B in PWM (Fast/PHASE CORRECT):
 * 1- OC1B_CTC_DISCONNECTED								1- OC1B_PWM_DISCONNECTED
 * 2- OC1B_CTC_TOGGLE									2- OC1B_PWM_CLR_ON_CMP
 * 3- OC1B_CTC_CLR_ON_CMP								3- OC1B_PWM_SET_ON_CMP
 * 4- OC1B_CTC_SET_ON_CMP*/
#define OC1B_PIN_MODE							OC1B_CTC_DISCONNECTED

/*Options for OVF mode:
 * 1- TIMER1_OVF_INTERRUPT_ON							2- TIMER1_OVF_INTERRUPT_OFF*/
#define TIMER1_OVF_INTERRUPT					TIMER1_OVF_INTERRUPT_OFF


/********************					Timer2				*********************************/
/*Options Timer2 modes of operation:
 * 1- TIMER2_OVF_MODE
 * 2- TIMER2_PWM_PHASE_CORRECT_MODE
 * 3- TIMER2_CTC_MODE
 * 4- TIMER2_FAST_PWM_MODE*/
#define	TIMER2_MODE								TIMER2_OVF_MODE

/*Options for Clock Prescaler:
 * 1- TIMER2_NO_CLOCK_SOURCE
 * 2- TIMER2_PRESCALER_DIV_BY_1
 * 3- TIMER2_PRESCALER_DIV_BY_8
 * 4- TIMER2_PRESCALER_DIV_BY_32
 * 5- TIMER2_PRESCALER_DIV_BY_64
 * 6- TIMER2_PRESCALER_DIV_BY_128
 * 7- TIMER2_PRESCALER_DIV_BY_256
 * 8- TIMER2_PRESCALER_DIV_BY_1024*/
#define TIMER2_PRESCALER						TIMER2_PRESCALER_DIV_BY_256

/*Options for OC2 in CTC mode:							Options for OC2 in PWM (Fast/PHASE CORRECT):
 * 1- OC2_CTC_DISCONNECTED								1- OC2_PWM_DISCONNECTED
 * 2- OC2_CTC_TOGGLE									2- OC2_PWM_CLR_ON_CMP
 * 3- OC2_CTC_CLR_ON_CMP								3- OC2_PWM_SET_ON_CMP
 * 4- OC2_CTC_SET_ON_CMP*/
#define OC2_PIN_MODE							OC2_CTC_DISCONNECTED

/*Options for OVF mode:
 * 1- TIMER2_OVF_INTERRUPT_ON							2- TIMER2_OVF_INTERRUPT_OFF*/
#define TIMER2_OVF_INTERRUPT					TIMER2_OVF_INTERRUPT_ON

/*Options for CTC mode:
 * 1- TIMER2_CTC_INTERRUPT_ON							2- TIMER2_CTC_INTERRUPT_OFF*/
#define TIMER2_CTC_INTERRUPT					TIMER2_CTC_INTERRUPT_OFF

#endif
