#ifndef __ULTRASONIC_H__
#define __ULTRASONIC_H__
#include <defines.h>

/**
* @brief initial the HC-SR04 Ultrasonic Sensor Module
* 
* configure the pins of the sensor and all peripherals 
* needed for interfacing the sensor
* 
* @param X one of the prts in tive-c(A,B,C,D,E,F)
* @param trigger the number of pin trigger of sensor module
* 
* @return void
*/
void ultrasonic_init(IOPORT X, uint8_t trigger);

/**
* @brief using calculations to compute the distance
* 
* calculate the pulsewidth of echo pin using timer 
* peripheral in capture mode 
*
* @param void
* 
* @return the distance that the sensor measure
*/
float ultrasonic_measure(void);


#endif