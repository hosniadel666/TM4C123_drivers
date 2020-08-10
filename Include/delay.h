/**
* @file delay.h
* @brief This file contain dealy functions 
*
* we use GPTM to achieve delay
*
* @author Hosni Adel
* @date July 5 2020
*
*/
#ifndef __DELAY_H__
#define __DELAY_H__
#include <defines.h>

/**
* @brief Configure the Timer3 to achieve delay in micros 
*
* @param n the time in microsec needed for delay
* 
* @return void
*/
void delayMicros(uint32_t n);

/**
* @brief Configure the Timer2 to achieve delay in millis 
*
* @param n the time in millisec needed for delay
* 
* @return void
*/
void delayMs(uint32_t n);
#endif