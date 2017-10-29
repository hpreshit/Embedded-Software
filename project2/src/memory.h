/***************************************************************************************************
 *
 * @author Preshit Harlikar, Shivam Khandelwal
 * @file memory.c
 * @brief This file includes memory manipulation function declarations.
 * @date October 1, 2017
 *
 * long decription - The memory.h file includes memory manipulation function declarations for -
 *                      1) moving bytes of data from source to destination(my_memmove())
 *                      2) copying bytes of data from source to destination(my_memcpy())
 *                      3) setting bytes of data to a specified value(my_memset())
 *                      4) setting bytes of data to zero(my_memzero())
 *                      5) reversing bytes of data at a specified memory loaction(my_reverse())
 *                      6) reserving a specified number of words at a particular
 *                         memory location.(reserve_words())
 *                      7) free a dynamic memory allocation by providing the pointer src to
 *                         the function(free_words())
 *
 ***************************************************************************************************/

#ifndef MEMORY_H_INCLUDED
#define MEMORY_H_INCLUDED

/************* including standard libraries*************/

#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <math.h>

/*******************************************************/



/**************************** my_memmove() function declaration **********************************/

uint8_t *my_memmove(uint8_t * src, uint8_t * dst, size_t length);



/**************************** my_memset() function declaration ************************************/

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);



/**************************** my_memzero() function declaration ************************************/

uint8_t * my_memzero(uint8_t * src, size_t length);



/**************************** my_reverse() function declaration ************************************/

uint8_t * my_reverse(uint8_t * src, size_t length);



#endif // MEMORY_H_INCLUDED
