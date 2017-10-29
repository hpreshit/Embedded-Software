#ifndef INCLUDES_UART_H_
#define INCLUDES_UART_H_

#include "MKL25Z4.h"
#include "circbuf.h"
#include "conversion.h"

extern uint8_t Rx_Data;
extern uint8_t Tx_Data;
extern CB_t Tx_Buffer;
extern CB_t Rx_Buffer;

#define BAUD 115200
#define BAUD_RATE ((SystemCoreClock)/((BAUD)*(16)))

CB_status UART_configure();

CB_status UART_send(uint8_t *data0);

CB_status UART_send_n(uint8_t *data0, uint8_t length);

CB_status UART_receive(uint8_t *data0);

CB_status UART_receive_n(uint8_t *data0, uint8_t length);

#endif /* INCLUDES_UART_H_ */
