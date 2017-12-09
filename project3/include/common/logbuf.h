/***************************************************************************************************
 *
 * @author  Preshit Harlikar, Shivam Khandelwal
 * @file logbuf.h
 * @brief This file includes Log Buffer functions
 * @date November 23, 2017
 *
 * long description - The logbuf.c file includes function declaration of function to -
 *                      1) add data to log buffer(Log_buffer_add_item())
 *                      2) remove data from log buffer (Log_buffer_remove_item())
 *                      3) check whether or not buffer is full(Log_buffer_is_full())
 *                      4) check whether or not buffer is empty(Log_buffer_is_empty())
 *                      5) peek at a location from head (Log_buffer_peek())
 *                      6) initialize log buffer (Log_buffer_init())
 *                      7) destroy a log buffer (Log_buffer_destroy())
 *
 *
 ***************************************************************************************************/

#ifndef SOURCES_LOGBUF_H_
#define SOURCES_LOGBUF_H_

/*----- Header-Files -------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

/*----- Log Buffer Struct --------------------------------------------*/

typedef struct{
uint8_t *buffer;
uint8_t *buffer_end;
uint8_t *head;
uint8_t *tail;
uint16_t length;
uint8_t count;
}Log_t;

/*----- Enum for Log Buffer and UART ---------------------------------*/


typedef enum{
LOG_BUFFER_FULL=11,
LOG_BUFFER_EMPTY=80,
LOG_SUCCESS=13,
LOG_NULL_ERROR=0,
LOG_PEEK_LENGTH_ERROR=15,
LOG_TX_SUCCESS=16,
LOG_RX_SUCCESS=17,
LOG_TX_IRQ=18,
LOG_RX_IRQ=19
}Log_Buffer_Status;

/********************************** Log_buffer_add_item() *****************************************************
 *
 * @name   -  Log_buffer_add_item()
 * @brief  -  function to add data to log buffer
 * @param  -  *log : pointer to log buffer
 * @param  -  *data : data to be added to buffer
 *
 * long description - This function adds data to log buffer from a given memory location.
 *
 * @return -  LOG_BUFFER_FULL : if buffer is full
 * @return -  LOG_SUCCESS : if data added successfully to buffer
 *
 ******************************************************************************************************/

/******************************** Log_buffer_add_item() function definition ***********************************/

Log_Buffer_Status Log_buffer_add_item(Log_t *log, volatile uint8_t *data);

/********************************** Log_buffer_remove_item() *****************************************************
 *
 * @name   -  Log_buffer_remove_item()
 * @brief  -  function to remove data from log buffer
 * @param  -  *log : pointer to log buffer
 * @param  -  *data : location to which data is dumped from buffer.
 *
 * long description - This function removes data from log buffer to a given memory location.
 *
 * @return -  LOG_BUFFER_EMPTY : if buffer is empty
 * @return -  LOG_SUCCESS : if data removed successfully from buffer
 *
 ******************************************************************************************************/

/******************************** Log_buffer_remove_item() function definition ***********************************/

Log_Buffer_Status Log_buffer_remove_item(Log_t *log, volatile uint8_t *data);

/********************************** Log_buffer_is_full() *****************************************************
 *
 * @name   -  Log_buffer_is_full()
 * @brief  -  function to check whether or not buffer is full
 * @param  -  *log : pointer to log buffer
 *
 * long description - This function checks whether or not buffer is full.
 *
 * @return -  LOG_BUFFER_FULL : if buffer is full.
 * @return -  LOG_NULL_ERROR : if buffer is not full.
 *
 ******************************************************************************************************/

/******************************** Log_buffer_is_full() function definition ***********************************/

Log_Buffer_Status Log_buffer_is_full(Log_t *log);

/********************************** Log_buffer_is_empty() *****************************************************
 *
 * @name   -  Log_buffer_is_empty()
 * @brief  -  function to check whether or not buffer is empty
 * @param  -  *log : pointer to log buffer
 *
 * long description - This function checks whether or not buffer is empty.
 *
 * @return -  LOG_BUFFER_EMPTY : if buffer is empty.
 * @return -  LOG_NULL_ERROR : if buffer is not empty.
 *
 ******************************************************************************************************/


Log_Buffer_Status Log_buffer_is_empty(Log_t *log);

/********************************** Log_buffer_peek() *****************************************************
 *
 * @name   -  Log_buffer_peek()
 * @brief  -  peek at a location from head
 * @param  -  *log : pointer to circular buffer
 * @param  -  *peek_ptr : location to which data is dumped from buffer.
 * @param  -  peek_pos : position to peek from head
 *
 * long description - This function peeks at a location from head. The data of the peeked location
 * 					  is copied to peek pointer.
 *
 * @return -  LOG_BUFFER_EMPTY : if buffer is empty
 * @return -  LOG_SUCCESS : if data removed successfully from buffer
 * @return -  LOG_PEEK_LENGTH_ERROR : if data removed successfully from buffer
 *
 ******************************************************************************************************/

Log_Buffer_Status Log_buffer_peek(Log_t *log, uint8_t peek_pos, uint8_t *peek_ptr);


/********************************** Log_buffer_init() *****************************************************
 *
 * @name   -  Log_buffer_init()
 * @brief  -  function to create a log buffer
 * @param  -  *log : pointer to log buffer
 * @param  -  length : size of buffer in bytes.
 *
 * long description - This function creates a log buffer of specified bytes.
 *
 * @return -  LOG_SUCCESS : if buffer is successfully created.
 *
 ******************************************************************************************************/

/******************************** Log_buffer_init() function definition ***********************************/

Log_Buffer_Status Log_buffer_init(Log_t *log, uint16_t length);

/********************************** Log_buffer_destroy() *****************************************************
 *
 * @name   -  Log_buffer_destroy()
 * @brief  -  function to destroy a log buffer
 * @param  -  *log : pointer to log buffer
 *
 * long description - This function destroys a log buffer.
 *
 * @return -  LOG_SUCCESS : if buffer is successfully destroyed.
 *
 ******************************************************************************************************/

/******************************** Log_buffer_destroy() function definition ***********************************/

Log_Buffer_Status Log_buffer_destroy(Log_t *log);




#endif /* SOURCES_LOGBUF_H_ */
