#include "stdint.h"

#ifndef _FIFO_H_
#define _FIFO_H_

typedef struct
{
	uint8_t* message;
	uint32_t messageLength;
}message_t;

#define item_type message_t

typedef struct
{
	item_type *base;
	item_type *head;
	item_type *tail;
	uint32_t length;
}fifo_t;
typedef enum
{
	fifo_null,
	fifo_full,
	fifo_empty,
	fifo_succeded
}fifo_status_t;

void fifo_init(fifo_t *buff,item_type *target,uint32_t length);
void fifo_push(fifo_t* buff, item_type item);
fifo_status_t fifo_pop(fifo_t* buff, item_type* item);
fifo_status_t fifo_get(fifo_t* buff, item_type* item);

#endif
