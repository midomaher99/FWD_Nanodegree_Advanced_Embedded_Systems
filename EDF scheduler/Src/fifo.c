#include"fifo.h"
#include "stdint.h"

void fifo_init(fifo_t *buff,item_type *target,uint32_t length)
{

		buff->base = buff->head = buff->tail = target;
		buff->length = length;

}

void fifo_push(fifo_t* buff, item_type item)
{
	
		*(buff->head) = item;
		buff->head ++;
		if(buff->head == (buff->base + buff->length))
			buff->head = buff->base;
}

fifo_status_t fifo_pop(fifo_t* buff, item_type* item)
{
			if (buff->tail== buff->head)
				return fifo_empty;
			else
			{
			*item = *(buff->tail);
			buff->tail ++;
			if(buff->tail == (buff->base + buff->length))
				buff->tail = buff->base;
				return fifo_succeded;
			}
}

fifo_status_t fifo_get(fifo_t* buff, item_type* item)
{
	if (buff->tail== buff->head)
				return fifo_empty;
			else
			{
			*item = *(buff->tail);
				return fifo_succeded;
			}
}

