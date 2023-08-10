#include<stdlib.h>
#include<string.h>
#include "d_list.h"

int dlist_init(dlist_t **head, int size)
{
	*head = malloc(sizeof(struct dlist_t));

	if(*head == NULL)
		return -1;

	(*head)->node.next =&((*head)->node);
	(*head)->node.prev = &((*head)->node);
	(*head)->size = size;

	return 0;
}

int dlist_insert(dlist_t *head, const void *data, int way)
{
	struct node_dt *node;

	node = malloc(sizeof(struct node_dt));
	if(node == NULL)
		return -1;
	node->data = malloc(head->size);
	if(node->data == NULL)
	{
		free(node);
		node = NULL;
		return -1;
	}
	memcpy(node->data, data, head->size);
	
	if(DLIST_INSERT_HEAD == way)//头插
	{
		node->next = head->node.next;
		(head->node.next)->prev = node;
		head->node.next = node;
		node->prev = &(head->node);
	}else if(DLIST_INSERT_TAIL == way){
		node->next = &(head->node);
		(head->node.prev)->next = node;
		node->prev = head->node.prev;
		head->node.prev = node;		
	}

	return 0;

}

int dlist_traval(dlist_t *head, pri_t pri)
{
	struct node_dt *cur;

	for(cur = head->node.next; cur != &head->node; cur = cur->next)
	{
		pri(cur->data);
	}
	
	return 0;
}

static struct node_dt *__find(dlist_t *head, const void *key, cmp_t cmp)
{
	struct node_dt *cur;

	for(cur = head->node.next; cur != &head->node; cur = cur->next)
	{
		if(cmp(cur->data, key) == 0)
			return cur;
	}

	return NULL;
}

//删除
int dlist_del(dlist_t *head, const void *key, cmp_t cmp)
{
	struct node_dt *f;

	f = __find(head, key, cmp);
	if(f == NULL)
		return -1;
	f->next->prev = f->prev;
	f->prev->next = f->next;
	f->prev = f->next = NULL;	

	free(f->data);
	f->data = NULL;
	free(f);
	f = NULL;

	return 0;
}

//销毁

static int destory_cmp(const void *data, const void *key)
{
	return 0;
}

int dlist_destory(dlist_t *head)
{
	struct node_dt *cur;

	while(head->node.next != &head->node)
		dlist_del(head, NULL, destory_cmp);

	free(head);
	head = NULL;

	return 0;
}
