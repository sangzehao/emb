#include<stdlib.h>
#include<string.h>

#include "linklist.h"

int listhead_init(listhead **head, int size)
{
	*head = malloc(sizeof(listhead));
	if(*head == NULL)
		return -1;
	(*head)->size = size;
	(*head)->next = NULL;

	return 0;
}

int list_insert(listhead *head, const void *key, int way)
{
	data_node *data = NULL;
	data_node *cur = NULL;
	data = malloc(sizeof(data_node));
	cur = malloc(sizeof(data_node));

	if(data == NULL)
		return -1;
	switch(way)
	{
		case 0:
			data->next = head->next;
			head->next = data;
			data->l_p = malloc(head->size);
			memcpy(data->l_p, key, head->size);
			break;
		case 1:
			data->next = NULL;
			for(cur = head->next; cur->next != NULL; cur = cur->next)
			cur->next = data;
			memcpy(data->l_p, key, head->size);
			break;
	}
	return 0;
}

void list_traval(const listhead *head, pri_t pri)
{
	data_node *cur;

	for(cur = head->next; cur != NULL; cur = cur->next)
	{
		pri(cur->l_p);
	}
}


