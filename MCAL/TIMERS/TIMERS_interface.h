/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: TIMERS					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef TIMERS_INTERFACE_H
#define TIMERS_INTERFACE_H

/********************			Timer0 Functions			*********************************/
/* This function is responsible for set the Timer0 settings pre-build configuration */
void TIMERS_voidTimer0Init (void);
/* This function sets the compare match value of the CTC Mode for Timer0
 * Arguments: compare match value (0 : 255)
 * Returns: Error states (OK - ERROR) */
u8 TIMERS_u8Timer0SetCompareMatchValue (u8 Copy_u8CompareMatchValue);
/* This function sets the pre-load value of the OVF Mode
 * Arguments: Preload value (0 : 255)
 * Returns: Error states (OK - ERROR) */
u8 TIMERS_u8Timer0SetPreloadValue (u8 Copy_u8PreloadValue);
/* These are the call back functions for all Timer0 modes
 * Arguments: pointer to function which will be called in the ISR
 * Returns: Error states (OK - ERROR) */
u8 TIMERS_u8Timer0CTCSetCallbackFunction (void (*Copy_pvCTCFunction) (void));
u8 TIMERS_u8Timer0OVFSetCallbackFunction (void (*Copy_pvOVFFunction) (void));
/* This is the delay function which work in 2 modes OVF and CTC and it has pre-build and post-build configuration
 * Arguments:  Delay (0 : 4294967295) - Type of delay (TIMERS_S - TIMERS_MS - TIMERS_US)
 * Returns: Error states (OK - ERROR) */
u8 TIMERS_u8Timer0Delay (u32 Copy_u32Delay, u8 Copy_u8Type);

/********************			Timer1 Functions			*********************************/
void TIMERS_voidTimer1Init (void);
void TIMERS_voidTimer1SetPreloadValue (u16 Copy_u16PreloadValue);
void TIMERS_voidTimer1SetTopValue (u16 Copy_u16OverflowValue);
void TIMERS_voidTimer1SetChannelACompareMatchValue (u16 Copy_u16CompareMatchValue);
void TIMERS_voidTimer1SetCTCAInterruptControl (u8 Copy_u8InterruptState);
void TIMERS_voidTimer1SetChannelBCompareMatchValue (u16 Copy_u16CompareMatchValue);
void TIMERS_voidTimer1SetCTCBInterruptControl (u8 Copy_u8InterruptState);
void TIMERS_voidTimer1ICUSetSenseControl (u8 Copy_u8SenseControl);
void TIMERS_voidTimer1ICUInterruptControl (u8 Copy_u8InterruptState);
u16  TIMERS_u16Timer1ICUReadInputCapture (void);
void TIMERS_voidTimer1ICUSetCallbackFunction (void (*Copy_pvICUFunction) (void));
void TIMERS_voidTimer1CTCASetCallbackFunction (void (*Copy_pvCTCAFunction) (void));
void TIMERS_voidTimer1CTCBSetCallbackFunction (void (*Copy_pvCTCBFunction) (void));
void TIMERS_voidTimer1OVFSetCallbackFunction (void (*Copy_pvOVFFunction) (void));

/********************			Timer2 Functions			*********************************/
/* This function is responsible for set the Timer2 settings pre-build configuration */
void TIMERS_voidTimer2Init (void);
/* This function sets the compare match value of the CTC Mode for Timer2
 * Arguments: compare match value (0 : 255)
 * Returns: Error states (OK - ERROR) */
u8 TIMERS_u8Timer2SetCompareMatchValue (u8 Copy_u8CompareMatchValue);
/* This function sets the pre-load value of the OVF Mode for Timer2
 * Arguments: Preload value (0 : 255)
 * Returns: Error states (OK - ERROR) */
u8 TIMERS_u8Timer2SetPreloadValue (u8 Copy_u8PreloadValue);
/* These are the call back functions for all Timer2 modes
 * Arguments: pointer to function which will be called in the ISR
 * Returns: Error states (OK - ERROR) */
u8 TIMERS_u8Timer2CTCSetCallbackFunction (void (*Copy_pvCTCFunction) (void));
u8 TIMERS_u8Timer2OVFSetCallbackFunction (void (*Copy_pvCTCFunction) (void));


/*Timer1 ICU Sense Control Options*/
#define TIMERS_FALLING_EDGE				0
#define TIMERS_RISING_EDGE				1

/*Interrupt State Options*/
#define TIMERS_DISABLE					0
#define TIMERS_ENABLE					1

/*Delay Types Options*/
#define TIMERS_US						0
#define TIMERS_MS						1
#define TIMERS_S						2

#endif
