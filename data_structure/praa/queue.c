#include "queue.h"
#include<stdio.h>

int queue_init(queue_t **myqueue, int size)//初始化
{
	return list_init(myqueue, size);
}

int queue_empty(queue_t *myqueue) //是否为空队列
{
	return list_empty(myqueue);
}

int queue_pull(queue_t *myqueue)	//是否溢出
{
	return CAP == list_numb(myqueue);		
}

int queue_push(queue_t *myqueue, void *data)//入队
{
	return list_add(myqueue, data, TAILADD);
}

static int cmp_always(const void *data, const void *data1)
{
	return 0;
}

int queue_pop(queue_t *myqueue, void *data)//出队
{
	return list_push(myqueue, NULL, cmp_always, data); 
}

