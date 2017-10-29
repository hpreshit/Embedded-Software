#ifndef CIRCBUF_H_INCLUDED
#define CIRCBUF_H_INCLUDED

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
BUFFER_NOT_FULL=2,
BUFFER_EMPTY=3,
BUFFER_NOT_EMPTY=4,
SUCCESS=5,
FAILURE=6,
NULL_ERROR=7,
PEEK_LENGTH_ERROR=8
}CB_status;


CB_status CB_buffer_add_item(CB_t *cb, uint8_t *data);

CB_status CB_buffer_remove_item(CB_t *cb, uint8_t *data);

CB_status CB_is_full(CB_t *cb);

CB_status CB_is_empty(CB_t *cb);

CB_status CB_peek(CB_t *cb, uint8_t peek_pos, uint8_t *peek_ptr);

CB_status CB_init(CB_t *cb, uint8_t length);

CB_status CB_destroy(CB_t *cb);


#endif // CIRCBUF_H_INCLUDED
