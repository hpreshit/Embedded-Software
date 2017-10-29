

#include "circbuf.h"


CB_status CB_buffer_add_item(CB_t *cb, volatile uint8_t *data)
{
    if(cb->count==cb->length)
    {
        return BUFFER_FULL;
    }
    else if(cb->head==cb->buffer_end && cb->count<cb->length)
    {
        cb->head=cb->buffer;
        *(cb->head)=*data;
        cb->count++;
        cb->head++;
        return SUCCESS;
    }
    else
    {
        *(cb->head)=*data;
        cb->count++;
        cb->head++;
        return SUCCESS;
    }
}

CB_status CB_buffer_remove_item(CB_t *cb, uint8_t *data)
{
    if(cb->count==0)
    {
        return BUFFER_EMPTY;
    }
    else if(cb->head==cb->buffer && cb->tail==cb->buffer)
    {
        *data=*(cb->tail);
        cb->count--;
        return SUCCESS;
    }

    else if(cb->tail==cb->buffer_end)
    {
        *data=*(cb->tail);
        cb->tail=cb->buffer;
        cb->count--;
        return SUCCESS;
    }
    else
    {
        *data=*(cb->tail);
        cb->tail++;
        cb->count--;
        return SUCCESS;
    }
}

CB_status CB_is_full(CB_t *cb)
{
    if (cb->count == cb->length)
        return BUFFER_FULL;
    else
        return NULL_ERROR;
}

CB_status CB_is_empty(CB_t *cb)
{
    if (cb->count == 0)
        return BUFFER_EMPTY;
    else
        return NULL_ERROR;
}

CB_status CB_peek(CB_t *cb, uint8_t peek_pos, uint8_t *peek_ptr)
{
    if(((cb->count) != 0) && (peek_pos <= (cb->length)))
    {
        if(((cb->head)+(peek_pos))<(cb->buffer_end))
        {
            *peek_ptr= *((cb->head)+(peek_pos));
        }

        else if(((cb->head)+(peek_pos))>=(cb->buffer_end))
        {
            *peek_ptr= *((cb->buffer)+((cb->buffer_end)-((cb->head)+(peek_pos))));
        }
    }
    else if((cb->count) == 0)
    {
        return BUFFER_EMPTY;
    }
    else
    {
        return PEEK_LENGTH_ERROR;
    }

}

CB_status CB_init(CB_t *cb, uint8_t length)
{
    cb->buffer = (uint8_t*)malloc(sizeof(uint8_t)*length);
    cb->buffer_end = cb->buffer + (sizeof(uint8_t)*length);
    cb->head = cb->buffer;
    cb->tail = cb->buffer;
    cb->count = 0;
    cb->length = length;
    return SUCCESS;
}

CB_status CB_destroy(CB_t *cb)
{
    free(cb->buffer);
    return SUCCESS;
}

