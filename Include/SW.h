/**
* @file SW.h
* @brief Configure sw1 and sw2 in tiva-c board
* 
* Here we will configure the sw1 which connected
* to PF4 and sw2 which connected to PF1
* SW1-->PF4
* SW1-->PF1
*
* @author Hosni Adel
* @date July 10 2020
*
*/
#ifndef __SW_H__
#define __SW_H__
#include <defines.h>

/**
* @brief initialize PF4 to use the switch
*
* @param void
* 
* @return void
*/
void SW1_init(void);

/**
* @brief specify the state of the switch
* 
* if the switch is released the state of pin HIGH
* if the switch is pressed the state of pin LOW
*
* @param void
* 
* @return the state of the switch 1-->released and 0-->pressed
*/
uint8_t SW1_state(void);

/**
* @brief initialize PF1 to use the switch
*
* @param void
* 
* @return void
*/
void SW2_init(void);

/**
* @brief specify the state of the switch
* 
* if the switch is released the state of pin HIGH
* if the switch is pressed the state of pin LOW
*
* @param void
* 
* @return the state of the switch 1-->released and 0-->pressed
*/
uint8_t SW2_state(void);

#endif