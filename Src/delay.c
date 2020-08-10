/**
 * @file delay.c
 * @brief implemintation of delay functions using timer
 *
 * @author Hosni Adel
 * @date July 5 2020
 *
 */

#include <defines.h>
#include "delay.h"

/**************************************************************
 Function Definitions
**************************************************************/
void delayMicros(uint32_t n)
{
	SYSCTL->RCGCTIMER |= 8; /* enable clock to Timer Block 0 */
	TIMER3->CTL = 0; /* disable Timer before initialization */
	TIMER3->CFG = 0x04; /* 16-bit option */
	TIMER3->TBMR = 0x02; /* periodic mode and down-counter */
	TIMER3->TBILR = 16 - 1; /* TimerB interval load value reg */
	TIMER3->ICR = 0x100; /* clear the TimerB timeout flag */
	TIMER3->CTL |= 0x0100; /* enable TimerB after initialization */
	for(uint32_t i = 0; i < n; i++)
	{
		while ((TIMER3->RIS & 0x100) == 0) ; /* wait for TimerB timeout flag 1ms */
		TIMER3->ICR = 0x100; /* clear the TimerB timeout flag */
	}
}
void delayMs(uint32_t n)
{

	SYSCTL->RCGCTIMER |= 4; /* enable clock to Timer Block 0 */
	TIMER2->CTL = 0; /* disable Timer before initialization */
	TIMER2->CFG = 0x04; /* 16-bit option */
	TIMER2->TBMR = 0x02; /* periodic mode and down-counter */
	TIMER2->TBILR = 16000 - 1; /* TimerB interval load value reg */
	TIMER2->ICR = 0x100; /* clear the TimerB timeout flag */
	TIMER2->CTL |= 0x0100; /* enable TimerB after initialization */
	
	for(uint32_t i = 0; i < n; i++)
	{
		while ((TIMER2->RIS & 0x100) == 0) ; /* wait for TimerB timeout flag 1ms */
		TIMER2->ICR = 0x100; /* clear the TimerB timeout flag */
	}
}