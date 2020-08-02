/**
 * @file ultrasonic.c
 * @brief Abstraction of memory read and write operations
 *
 * This implementation file provides an abstraction of reading and
 * writing to memory via function calls. There is also a globally
 * allocated buffer array used for manipulation.
 *
 * @author Hosni Hosni
 * @date July 10 2020
 *
 */
#include <defines.h>
#include "delay.h"

/***********************************************************
 Function Definitions
***********************************************************/

void ultrasonic_init(IOPORT X, uint8_t trigger){
	SYSCTL->RCGCGPIO |= MASK(X); /* enable clock to GPIO PORT X */
	SYSCTL->RCGCTIMER |= 1; /* enable clock to Timer Block 0 */
	SYSCTL->RCGCGPIO |= 2; /* enable clock to PORTB */
	
	
	GPIOF->DIR = MASK(trigger); /* let bit trigger as output*/
	GPIOF->DEN = MASK(trigger); /* enable digital pin*/

	
	GPIOB->DIR &= ~0x40; /* make PB6 an input pin */
	GPIOB->DEN |= 0x40; /* make PB6 as digital pin */
	GPIOB->AFSEL |= 0x40; /* use PB6 alternate function */
	GPIOB->PCTL &= ~0x0F000000; /* configure PB6 for T0CCP0 */
	GPIOB->PCTL |= 0x07000000;
	
	TIMER0->CTL &= ~1; /* disable timer0A during setup */
	TIMER0->CFG = 4; /* 16-bit timer mode */
	TIMER0->TAMR = 0x17; /* up-count, edge-time, capture mode */
	TIMER0->CTL |= 0x0c; /* capture the rising edge */
	TIMER0->CTL |= 1; /* enable timer0A */
}


float ultrasonic_measure(void){
    uint32_t fallingEdge, raisingEdge, pulseWidth;
    float distance;
	
    /* trigger the trigger pin*/
    GPIOF->DATA = 0x00;
    delayMs(30);
    GPIOF->DATA = 0x04;
    delayMicros(10);
    GPIOF->DATA = 0x00;
	
	/* capture the first rising edge */
	TIMER0->ICR = 4; /* clear timer0A capture flag */

	while((TIMER0->RIS & 4) == 0 && (TIMER0->RIS & 0x1) == 0) ; /* wait till captured */
	fallingEdge = TIMER0->TAR; /* save the timestamp */
	  
	/* capture the first faling edge */
	TIMER0->ICR = 4; /* clear timer0A capture flag */

	while((TIMER0->RIS & 4) == 0 && (TIMER0->RIS & 0x1) == 0) ; /* wait till captured */
	raisingEdge = TIMER0->TAR; /* save the timestamp */
	
	pulseWidth = (raisingEdge - fallingEdge) & 0x00FFFFFF;
	
	/*soundspeed = distance / time , time = timer clock cycles * system clock period */
	distance = pulseWidth * (1 / 32000000.0) * 34000; 
	
	return distance; /* return the time difference */
}