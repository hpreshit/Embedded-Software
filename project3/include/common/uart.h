#ifndef SOURCES_UART_H_
#define SOURCES_UART_H_

/***************************************************************************************************
 *
 * @author Shivam Khandelwal, Preshit Harlikar
 * @file uart.h
 * @brief This header file includes UART function declarations
 * @date October 24, 2017
 *
 * long description - The uart.h file includes function declarations of functions to -
 *                      1) configure UART (UART_Configure())
 *                      2) send a UART character (UART_send())
 *                      3) send n UART characters (UART_send_n())
 *                      4) receive UART character (UART_receive())
 *                      5) receive n UART characters (UART_receive_n())
 *                      6) handle UART interrupts (UART0_IRQHandler())
 *
 *
 ***************************************************************************************************/

#include <stdint.h>
#include "MKL25Z4.h"
#include <stdlib.h>
#include "circbuf.h"
#include "project3.h"

#define BAUD 115200
#define BAUD_RATE ((SystemCoreClock)/((BAUD)*(16)))

typedef enum{
	TX_SUCCESS=6,
	RX_SUCCESS=7,
	TX_IRQ=8,
	RX_IRQ=9,
	UART_CONFIG_SUCCESS
}UART_status;

extern uint8_t log_mode;

/********************************** UART_configure() *****************************************************
 *
 * @name   -  UART_configure()
 * @brief  -  function to initialize UART
 * @param  -  none
 *
 * long description - This function configures UART control and status registers, sets baud rate, enables
 * 					  interrupts, selects clock mode and sets oversampling ratio.
 *
 * @return -  SUCCESS
 *
 ******************************************************************************************************/

/******************************** UART_configure() function declaration ***********************************/

UART_status UART_configure();

/********************************** UART_send() *****************************************************
 *
 * @name   -  UART_send()
 * @brief  -  function to send a character
 * @param  -  *data0 - pointer to data
 *
 * long description - This function sends a character by writing data to UART0 data register
 *
 * @return -  TX_SUCCESS
 *
 ******************************************************************************************************/

/******************************** UART_send() function declaration ***********************************/

UART_status UART_send(uint8_t *data0);

/********************************** UART_send_n() *****************************************************
 *
 * @name   -  UART_send_n()
 * @brief  -  function to send n characters
 * @param  -  *data0 : pointer to data
 * @param  -  length : length of data bytes
 *
 * long description - This function sends n characters by writing data to UART0 data register
 *
 * @return -  TX_SUCCESS
 *
 ******************************************************************************************************/

/******************************** UART_send_n() function declaration ***********************************/

UART_status UART_send_n(uint8_t *data0, uint8_t length);

/********************************** UART_receive() *****************************************************
 *
 * @name   -  UART_receive()
 * @brief  -  function to receive a character
 * @param  -  *data0 - pointer to data
 *
 * long description - This function receives a character by reading data from UART0 data register
 *
 * @return -  TX_SUCCESS
 *
 ******************************************************************************************************/

/******************************** UART_receive() function declaration ***********************************/

UART_status UART_receive(uint8_t *data0);

/********************************** UART_receive_n() *****************************************************
 *
 * @name   -  UART_receive_n()
 * @brief  -  function to receive n characters
 * @param  -  *data0 : pointer to data
 * @param  -  length : length of data bytes received
 *
 * long description - This function receives n characters by reading data from UART0 data register
 *
 * @return -  TX_SUCCESS
 *
 ******************************************************************************************************/

/******************************** UART_receive_n() function declaration ***********************************/

UART_status UART_receive_n(uint8_t *data0, uint8_t length);

/********************************** UART0_IRQHandler() *****************************************************
 *
 * @name   -  UART0_IRQHandler()
 * @brief  -  function to handle UART0 interrupts
 * @param  -  none
 *
 * long description - This function handles UART0 interrupts while receive and transmit operations.
 *
 * @return -  TX_IRQ : transmit interrupt
 * @return -  RX_IRQ : receive interrupt
 *
 ***********************************************************************************************************/

/******************************** UART0_IRQHandler() function declaration ***********************************/

UART_status UART0_IRQHandler(void);

#endif /* SOURCES_UART_H_ */
