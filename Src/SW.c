/**
 * @file SW.c
 * @brief Implemintation of configuration of sw1 and sw2
 *
 * @author Hosni Adel
 * @date July 10 2020
 *
 */

#include <defines.h>
#include "SW.h"

/**************************************************************
 Function Definitions
**************************************************************/

void SW1_init(void)
{
	SYSCTL->RCGCGPIO |= 0x20;	/* enable clock to GPIOF */
	GPIOF->DIR &= ~(0x10);	/* PF4 as an input pin */
	GPIOF->DEN |= 0x10;	/* Enable PF4 as a digital GPIO pins */ 
	GPIOF->PUR |= 0x10;	/*Enable the pull up resistor to pin PF4*/		 	 
}

uint8_t SW1_state(void)
{
	return (uint8_t)((GPIOF->DATA & 0x10) >> 4);
}

void SW2_init(void)
{
	SYSCTL->RCGCGPIO |= 0x20;	/* enable clock to GPIOF */
	GPIOF->LOCK = 0x4C4F434B;   /* unlockGPIOCR register because PF0 is locked pin */
	GPIOF->CR = 0x01;           /* Enable GPIOPUR register enable to commit */
	GPIOF->DIR &= ~(0x01);	/* PF0 as an input pin */
	GPIOF->DEN |= 0x01;	/* Enable PF1 as a digital GPIO pins */ 
	GPIOF->PUR |= 0x01;	/*Enable the pull up resistor to pin PF1*/		 	 
}

uint8_t SW2_state(void)
{
	return (uint8_t)((GPIOF->DATA & 0x01) >> 0);
}