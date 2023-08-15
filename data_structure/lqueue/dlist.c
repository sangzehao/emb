#include <stdlib.h>
#include <string.h>
#include "dlist.h"

int dlisthead_init(dlist_t **head, int size)
{
	*head = malloc(sizeof(dlist_t));
	if (NULL == *head)
		return -1;
	(*head)->node.prev = (*head)->node.next = &(*head)->node;
	(*head)->size = size;

	return 0;
}

// 将新结点插入在两个结点之间
static void __insert(struct node_st *newnode, struct node_st *before, struct node_st *after)
{
	newnode->prev = before;
	newnode->next = after;
	before->next = newnode;
	after->prev = newnode;
}

// 初始化一个新的结点
static int __node_init(struct node_st **newnode, const void *data, int size)
{
	// 结点的存储空间
	*newnode = malloc(sizeof(struct node_st) + size);
	if (NULL == *newnode)
		return -1;
	memcpy((*newnode)->data, data, size);

	return 0;
}

int dlist_head_insert(dlist_t *head, const void *data)
{
	// 新结点开辟存储空间
	struct node_st *mynode;

	__node_init(&mynode, data, head->size);

	__insert(mynode, &head->node, head->node.next);

}

int dlist_tail_insert(dlist_t *head, const void *data)
{
	// 新结点开辟存储空间
	struct node_st *mynode;

	__node_init(&mynode, data, head->size);
	__insert(mynode, head->node.prev, &head->node);
}

// 找到指定的结点并放回
// static struct node_st *__find(const dlist_t *head, const void *key, cmp_t cmp)
static int __find(const dlist_t *head, const void *key, cmp_t cmp, struct node_st **findnode)
{
	struct node_st *cur;	

	for (cur = head->node.next; cur != &head->node; cur = cur->next) {
		if (cmp(cur->data, key) == 0) {
			*findnode = cur;	
			return 0;
		}
	}

	return -1;
}

// 将指定结点从链表中移除
static void __fetch(struct node_st *f)
{
	f->prev->next = f->next;
	f->next->prev = f->prev;
	f->prev = f->next = NULL;
}

// 将制定结点释放
static void __destroy(struct node_st *f)
{
	free(f);
	f = NULL;
}

int dlist_delete(dlist_t *head, const void *key, cmp_t cmp)
{
	struct node_st *f;

	// 找到指定结点
	if (-1 == __find(head, key, cmp, &f))
		return -1;

	// 摘除
	__fetch(f);
	// 释放
	__destroy(f);

	return 0;
}

void dlist_traval(const dlist_t *head, pri_t pri)
{
	struct node_st *cur;

	for (cur = head->node.next; cur != &head->node; cur = cur->next)
		pri(cur->data);
}

// 比较函数
static	int __always_cmp(const void *data, const void *key) 
{
	return 0;
}

void dlist_destroy(dlist_t *head)
{
	while (head->node.prev != &head->node && head->node.next != &head->node) {
		dlist_delete(head, NULL, __always_cmp);	
	}

	free(head);
	head = NULL;
}

void *dlist_search(const dlist_t *head, const void *key, cmp_t cmp)
{
	struct node_st *f;

	__find(head, key, cmp, &f);
	if (NULL == f)
		return NULL;

	return f->data;
}

int dlist_fetch(dlist_t *head, const void *key, cmp_t cmp, void *data)
{
	struct node_st *f = NULL;

	__find(head, key, cmp, &f);
	if (NULL == f)
		return -1;
	__fetch(f);
	memcpy(data, f->data, head->size);
	__destroy(f);

	return 0;
}

int dlist_is_empty(const dlist_t *head)
{
	return head->node.next == &head->node && head->node.prev == &head->node;
}

// 获取第一个数据结点的数据
void *dlist_get_first(const dlist_t *head)
{
	if (dlist_is_empty(head))
		return NULL;
	return (head->node.next)->data;
}


