/**
 * @file defines.h
 * @brief include files and bit manipulation
 *
 * This header file provides bit masks and bit 
 * operation and important header files
 *
 * @author Hosni Adel
 * @date July 10 2020
 *
 */
#ifndef __DEFINES_H
#define __DEFINES_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <TM4C123GH6PM.h>

typedef enum PORT{
  A,
  B,
  C,
  D,
  E,
  F}IOPORT;

#define SETBIT(REG, MBIT) (REG |= MBIT)
#define CLEARBIT(REG, MBIT) (REG &= ~MBIT)
#define TOGBIT(REG, MBIT) (REG ^= MBIT)
#define READBIT(REG, BIT) ((REG >> BIT) & 1) 
#define SWAP2BITS(REG, BIT1, BIT2) (REG ^= ( ((READBIT(REG, BIT2) ^ READBIT(REG, BIT1)) << BIT1) | ((READBIT(REG, BIT2) ^ READBIT(REG, BIT1)) << BIT2) ))
#define MASK(X) (1 << X)

#ifndef BIT0
#define BIT0    0x01
#define BIT1    0x02
#define BIT2    0x04
#define BIT3    0x08
#define BIT4    0x10
#define BIT5    0x20
#define BIT6    0x40
#define BIT7    0x80
#endif



#endif
