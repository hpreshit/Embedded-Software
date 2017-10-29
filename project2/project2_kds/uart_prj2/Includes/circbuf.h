#ifndef INCLUDES_CIRCBUF_H_
#define INCLUDES_CIRCBUF_H_

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef struct{
uint8_t *buffer;
uint8_t *buffer_end;
uint8_t *head;
uint8_t *tail;
uint8_t length;
uint8_t count;
}CB_t;

typedef enum{
BUFFER_FULL=1,
BUFFER_EMPTY=2,
SUCCESS=3,
NULL_ERROR=0,
PEEK_LENGTH_ERROR=5,
TX_SUCCESS=6,
RX_SUCCESS=7,
TX_IRQ=8,
RX_IRQ=9
}CB_status;

CB_status CB_buffer_add_item(CB_t *cb, volatile uint8_t *data);

CB_status CB_buffer_remove_item(CB_t *cb, uint8_t *data);

CB_status CB_is_full(CB_t *cb);

CB_status CB_is_empty(CB_t *cb);

CB_status CB_peek(CB_t *cb, uint8_t peek_pos, uint8_t *peek_ptr);

CB_status CB_init(CB_t *cb, uint8_t length);

CB_status CB_destroy(CB_t *cb);

#endif /* INCLUDES_CIRCBUF_H_ */
