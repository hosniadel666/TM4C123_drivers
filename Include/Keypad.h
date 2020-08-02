/**
 * @file memory.h
 * @brief Abstraction of memory read and write operations
 *
 * This header file provides an abstraction of reading and
 * writing to memory via function calls. 
 *
 * @author Hosni Adel
 * @date July 10 2020
 *
 */
#ifndef __KEYPAD_H__
#define __KEYPAD_H__

#include <defines.h>
#define KEYPAD_ROW GPIOE
#define KEYPAD_COL GPIOC

/**
 * @brief Initialize the pins for the keypad  
 *
 * Set the pins required for rows and coloumns
 *
 * @param void
 *
 * @return void.
 */
void keypad_init(void); 

/**
 * @brief Get the pressed key 
 *
 * By using some logic thought we could specify which key 
 * was pressed using the state of the row and coloumns pin
 *
 * @param void
 *
 * @return the pressed key pf the keypad
 */
uint8_t keypadGetkey(void);

/**
 * @brief check if any key is pressed or not 
 *
 * By using some logic thought we could specify if any key  
 * was pressed or not 
 *
 * @param void
 *
 * @return TRUE(if pressed) or FALSE (if released)
 */
uint8_t keypadIspressed(void); 
#endif