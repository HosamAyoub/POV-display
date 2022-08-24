/********************************************************************************************/
/********************************************************************************************/
/********************			Author: Hosam Ayoub			*********************************/
/********************			Layer: MCAL					*********************************/
/********************			SWC: TIMERS					*********************************/
/********************			Version: 1.00				*********************************/
/********************************************************************************************/
/********************************************************************************************/
#ifndef TIMERS_PRIVATE_H
#define TIMERS_PRIVATE_H

/********************			Timer0/Counter0				*********************************/

#define TCCR0			                                (*((volatile u8*)0x53))				//Timer0 Control Register
#define TCCR0_CS00		                                0									//Prescaler Bit 0
#define TCCR1_CS01		                                1									//Prescaler Bit 1
#define TCCR2_CS02		                                2                                   //Prescaler Bit 2
#define TCCR0_WGM01		                                3                                   //Waveform Generation Mode Bit 1
#define TCCR0_COM00		                                4                                   //Compare Match Output Mode Bit 1
#define TCCR0_COM01		                                5									//Compare Match Output Mode Bit 0
#define TCCR0_WGM00		                                6									//Waveform Generation Mode Bit 0
#define TCCR0_FOC0		                                7									//Force Output Compare

#define TIMSK			                                (*((volatile u8*)0x59))				//Timer0 Interrupt Mask
#define TIMSK_TOIE0		                                0									//Overflow Interrupt Enable
#define TIMSK_OCIE0		                                1                                   //Output Compare match Interrupt Enable

#define TIFR			                                (*((volatile u8*)0x58))				//Interrupt Flag Register
#define TIFR_TOV0		                                0									//Overflow Flag
#define TIFR_OCF0		                                1                                   //Output Compare Flag

#define TCNT0			                                (*((volatile u8*)0x52))				//Timer0 Register

#define OCR0			                                (*((volatile u8*)0x5C))				//Output Compare Register

/********************			Timer1/Counter1				*********************************/

#define TCCR1A			                                (*((volatile u8*)0x4F))				//Timer1 Control Register B
#define TCCR1A_WGM10	                                0									//Waveform Generation Mode Bit 0
#define TCCR1A_WGM11	                                1									//Waveform Generation Mode Bit 1
#define TCCR1A_FOC1B	                                2                                   //Force Output Compare for Channel B
#define TCCR1A_FOC1A	                                3                                   //Force Output Compare for Channel A
#define TCCR1A_COM1B0	                                4                                   //Compare Output Mode for Channel B Bit 0
#define TCCR1A_COM1B1	                                5                                   //Compare Output Mode for Channel B Bit 1
#define TCCR1A_COM1A0	                                6                                   //Compare Output Mode for Channel A Bit 0
#define TCCR1A_COM1A1	                                7                                   //Compare Output Mode for Channel A Bit 1

#define TCCR1B			                                (*((volatile u8*)0x4E))				//Timer1 Control Register A
#define TCCR1B_CS10		                                0                                   //Prescaler Bit 0
#define TCCR1B_CS11		                                1                                   //Prescaler Bit 1
#define TCCR1B_CS12		                                2                                   //Prescaler Bit 2
#define TCCR1B_WGM12	                                3                                   //Waveform Generation Mode Bit 2
#define TCCR1B_WGM13	                                4                                   //Waveform Generation Mode Bit 3
#define TCCR1B_ICES1	                                6                                   //Input Capture Edge Select
#define TCCR1B_ICNC1	                        		7                                   //Input Capture Noise Canceller

#define TCCR1											(*((volatile u16*)0x4E))			//Timer1 Control Register

#define TIMSK_TOIE1		                        		2                                   //Overflow Interrupt Enable
#define TIMSK_OCIE1B	                       		 	3                                   //Output Compare Interrupt Channel B Enable
#define TIMSK_OCIE1A	                        		4                                   //Output Compare Interrupt Channel A Enable
#define TIMSK_TICIE1	                        		5                                   //Input Capture Interrupt Enable


#define TIFR_TOV1		                        		2                                   //Overflow Flag
#define TIFR_OCF1B		                        		3                                   //Output Compare Flag Channel B
#define TIFR_OCF1A		                        		4                                   //Output Compare Flag Channel A
#define TIFR_ICF1		                        		5                                   //Input Capture Flag


#define TCNT1L			                        		(*((volatile u8*)0x4C))             //Timer1 Low Byte Register
#define TCNT1H			                        		(*((volatile u8*)0x4D))             //Timer1 High Byte Register
#define TCNT1			                        		(*((volatile u16*)0x4C))            //Timer1 Register



#define OCR1AL			                        		(*((volatile u8*)0x5A))             //Timer1 Channel A Compare Match Value Low Byte
#define OCR1AH			                        		(*((volatile u8*)0x5B))             //Timer1 Channel A Compare Match Value High Byte
#define OCR1A			                        		(*((volatile u16*)0x5A))            //Timer1 Channel A Compare Match Value

#define OCR1BL			                        		(*((volatile u8*)0x48))             //Timer1 Channel B Compare Match Value Low Byte
#define OCR1BH			                        		(*((volatile u8*)0x49))             //Timer1 Channel B Compare Match Value High Byte
#define OCR1B			                        		(*((volatile u16*)0x48))            //Timer1 Channel B Compare Match Value

#define ICR1L			                        		(*((volatile u8*)0x46))             //Input Capture Register Low Byte
#define ICR1H			                        		(*((volatile u8*)0x47))             //Input Capture Register High Byte
#define ICR1			                        		(*((volatile u16*)0x46))            //Input Capture Register

/********************			Timer2/Counter2				*********************************/

#define TCCR2											(*((volatile u8*)0x45))				//Timer2 Control Register
#define TCCR2_CS20										0                                   //Prescaler Bit 0
#define TCCR2_CS21										1                                   //Prescaler Bit 1
#define TCCR2_CS22										2                                   //Prescaler Bit 2
#define TCCR2_WGM21										3                                   //Waveform Generation Bit 1
#define TCCR2_COM20										4                                   //Compare Match Output Mode Bit 0
#define TCCR2_COM21										5                                   //Compare Match Output Mode Bit 1
#define TCCR2_WGM20										6                                   //Waveform Generation Bit 0
#define TCCR2_FOC2										7                                   //Force Output Compare

#define TCNT2											(*((volatile u8*)0X44))				//Timer2 Register

#define OCR2											(*((volatile u8*)0X43))				//Output Compare Register

#define TIMSK_TOIE2										6									//Overflow Interrupt Enable
#define TIMSK_OCIE2										7									//Output Compare match Interrupt Enable

#define TIFR_TOV2										6									//Overflow Flag
#define TIFR_OCF2										7									//Output Compare Flag

/********************			Timers Configuration			*********************************/
//Timer0 and Timer1 Prescaler
#define	TIMERS_PRESCALER_MASK				    		0b11111000
#define TIMERS_NO_CLOCK_SOURCE                         	0
#define TIMERS_PRESCALER_DIV_BY_1                      	1
#define TIMERS_PRESCALER_DIV_BY_8                      	2
#define TIMERS_PRESCALER_DIV_BY_64                     	3
#define TIMERS_PRESCALER_DIV_BY_256                   	4
#define TIMERS_PRESCALER_DIV_BY_1024				    5
#define TIMERS_EXTERNAL_CLOCK_SOURCE_FALLING_EDGE	    6
#define TIMERS_EXTERNAL_CLOCK_SOURCE_RISING_EDGE	    7

//Array of pointers to function size
#define ARRAY_SIZE										8

//Array of pointers to function index
#define TIMER0_CTC		                	    		0
#define TIMER0_OVF		                	    		1
#define TIMER1_ICU							    		2
#define TIMER1_CTCA	                		    		3
#define TIMER1_CTCB	                		    		4
#define TIMER1_OVF		                	    		5
#define TIMER2_CTC							    		6
#define TIMER2_OVF							    		7

#define CLOCK											(F_CPU/1000000UL)

#define SECONDS_SCALE									1000000
#define MILLI_SECONDS_SCAL								1000

/********************			Timer0 Configuration			*********************************/
//Timer0 Modes of operation
#define TIMER0_OVF_MODE									0
#define TIMER0_PWM_PHASE_CORRECT_MODE      	 			1
#define TIMER0_CTC_MODE                     			2
#define	TIMER0_FAST_PWM_MODE                			3

//OC0 PIN Mode
#define OC0_PIN_MASK							        0b11001111
//For CTC mode
#define OC0_CTC_DISCONNECTED					        0b00000000
#define OC0_CTC_TOGGLE							        0b00010000
#define OC0_CTC_CLR_ON_CMP						        0b00100000
#define OC0_CTC_SET_ON							        0b00110000
//For FAST PWM and PHASE CORRECT PWM modes
#define OC0_PWM_DISCONNECTED					        0b00000000
#define OC0_PWM_CLR_ON_CMP						        0b00100000
#define OC0_PWM_SET_ON_CMP						        0b00110000

#define TIMER0_OVF_VALUE						        256

//For Interrupt mode
#define TIMER0_OVF_INTERRUPT_ON							0
#define TIMER0_OVF_INTERRUPT_OFF						1
#define TIMER0_CTC_INTERRUPT_ON							2
#define TIMER0_CTC_INTERRUPT_OFF						3

//For Delay function
#define TIMER0_INSTRUCTIONS_TIME							1900


/********************			Timer1 Configuration			*********************************/
//Timer1 Modes of operation
//#define TIMER1_MODE_MASK							0b1110011111111100
//#define TIMER1_OVF_MODE							0b0000000000000000
//#define TIMER1_PWM_PHASE_CORRECT_8_BIT_MODE   	0b0000000000000001
//#define TIMER1_PWM_PHASE_CORRECT_9_BIT_MODE   	0b0000000000000010
//#define TIMER1_PWM_PHASE_CORRECT_10_BIT_MODE  	0b0000000000000011
//#define TIMER1_CTC_MODE                       	0b0100000000000000
//#define TIMER1_FAST_PWM_8_BIT_MODE            	0b0100000000000001
//#define TIMER1_FAST_PWM_9_BIT_MODE            	0b0100000000000010
//#define TIMER1_FAST_PWM_10_BIT_MODE           	0b0100000000000011
//#define TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICU	0b1000000000000000                  //Top Value in: Input Capture Unit Register ICR1
//#define TIMER1_PWM_PHASE_FREQUANCY_CORRECT_OC 	0b1000000000000001				    //Top Value in: Output Compare Register OCR1A/OCR1B
//#define TIMER1_PWM_PHASE_CORRECT_ICU_MODE     	0b1000000000000010					//Top Value in: Input Capture Unit Register ICR1
//#define TIMER1_PWM_PHASE_CORRECT_OC_MODE      	0b1000000000000011					//Top Value in: Output Compare Register OCR1A/OCR1B
//#define TIMER1_CTC_ICU_MODE                   	0b1100000000000000					//Top Value in: Input Capture Unit Register ICR1
//#define TIMER1_FAST_PWM_ICU_MODE              	0b1100000000000010					//Top Value in: Input Capture Unit Register ICR1
//#define TIMER1_FAST_PWM_OC_MODE               	0b1100000000000011					//Top Value in: Output Compare Register OCR1A/OCR1B

#define TIMER1_MODE_MASK						        0b1111110011100111
#define TIMER1_OVF_MODE							        0b0000000000000000
#define TIMER1_PWM_PHASE_CORRECT_8_BIT_MODE   	        0b0000000100000000
#define TIMER1_PWM_PHASE_CORRECT_9_BIT_MODE   	        0b0000001000000000
#define TIMER1_PWM_PHASE_CORRECT_10_BIT_MODE  	        0b0000001100000000
#define TIMER1_CTC_MODE                       	        0b0000000000001000
#define TIMER1_FAST_PWM_8_BIT_MODE            	        0b0000000100001000
#define TIMER1_FAST_PWM_9_BIT_MODE            	        0b0000001000001000
#define TIMER1_FAST_PWM_10_BIT_MODE           	        0b0000001100001000
#define TIMER1_PWM_PHASE_FREQUENCY_CORRECT_ICU	        0b0000000000010000                  //Top Value in: Input Capture Unit Register ICR1
#define TIMER1_PWM_PHASE_FREQUANCY_CORRECT_OC 	        0b0000000100010000				    //Top Value in: Output Compare Register OCR1A/OCR1B
#define TIMER1_PWM_PHASE_CORRECT_ICU_MODE     	        0b0000001000010000					//Top Value in: Input Capture Unit Register ICR1
#define TIMER1_PWM_PHASE_CORRECT_OC_MODE      	        0b0000001100010000					//Top Value in: Output Compare Register OCR1A/OCR1B
#define TIMER1_CTC_ICU_MODE                   	        0b0000000000011000					//Top Value in: Input Capture Unit Register ICR1
#define TIMER1_FAST_PWM_ICU_MODE              	        0b0000001000011000					//Top Value in: Input Capture Unit Register ICR1
#define TIMER1_FAST_PWM_OC_MODE               	        0b0000001100011000					//Top Value in: Output Compare Register OCR1A/OCR1B

//OC1A Mode
#define OC1A_PIN_MASK						            0b00111111
//For CTC mode
#define OC1A_CTC_DISCONNECTED				            0b00000000
#define OC1A_CTC_TOGGLE						            0b01000000
#define OC1A_CTC_CLR_ON_CMP					            0b10000000
#define OC1A_CTC_SET_ON						            0b11000000
//For FAST PWM and PHASE CORRECT PWM modes
#define OC1A_PWM_DISCONNECTED				            0b00000000
#define OC1A_PWM_TOGGLE_ON_CMP				            0b01000000
#define OC1A_PWM_CLR_ON_CMP					            0b10000000
#define OC1A_PWM_SET_ON_CMP					            0b11000000

//OC1B Mode
#define OC1B_PIN_MASK						            0b11001111
//For CTC mode
#define OC1B_CTC_DISCONNECTED				            0b00000000
#define OC1B_CTC_TOGGLE						            0b00010000
#define OC1B_CTC_CLR_ON_CMP					            0b00100000
#define OC1B_CTC_SET_ON						            0b00110000
//For FAST PWM and PHASE CORRECT PWM modes
#define OC1B_PWM_DISCONNECTED				            0b00000000
#define OC1B_PWM_CLR_ON_CMP					            0b00100000
#define OC1B_PWM_SET_ON_CMP					            0b00110000
//For OVF Interrupt mode
#define TIMER1_OVF_INTERRUPT_ON							0
#define TIMER1_OVF_INTERRUPT_OFF						1


/********************			Timer2 Configuration			*********************************/
//Timer2 Modes of operation
#define TIMER2_OVF_MODE							        0
#define TIMER2_PWM_PHASE_CORRECT_MODE      	 	        1
#define TIMER2_CTC_MODE                     	        2
#define	TIMER2_FAST_PWM_MODE                	        3

//Timer2 Prescaler
#define	TIMERS_PRESCALER_MASK				            0b11111000
#define TIMER2_NO_CLOCK_SOURCE                          0
#define TIMER2_PRESCALER_DIV_BY_1                       1
#define TIMER2_PRESCALER_DIV_BY_8                       2
#define TIMER2_PRESCALER_DIV_BY_32                      3
#define TIMER2_PRESCALER_DIV_BY_64                      4
#define TIMER2_PRESCALER_DIV_BY_128				        5
#define TIMER2_PRESCALER_DIV_BY_256	    		        6
#define TIMER2_PRESCALER_DIV_BY_1024			        7

//OC2 PIN Mode
#define OC2_PIN_MASK							        0b11001111
//For CTC mode
#define OC2_CTC_DISCONNECTED					        0b00000000
#define OC2_CTC_TOGGLE							        0b00010000
#define OC2_CTC_CLR_ON_CMP						        0b00100000
#define OC2_CTC_SET_ON							        0b00110000
//For FAST PWM and PHASE CORRECT PWM modes
#define OC2_PWM_DISCONNECTED					        0b00000000
#define OC2_PWM_CLR_ON_CMP						        0b00100000
#define OC2_PWM_SET_ON_CMP						        0b00110000

#define TIMER2_OVF_INTERRUPT_ON							0
#define TIMER2_OVF_INTERRUPT_OFF						1
#define TIMER2_CTC_INTERRUPT_ON							2
#define TIMER2_CTC_INTERRUPT_OFF						3

#endif
