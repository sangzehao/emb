#include <stdlib.h>
#include <string.h>
#include "list.h"

int listhead_init(listhead_t **head, int size)
{
	*head = malloc(sizeof(listhead_t));
	if (NULL == *head)
		return -1;

	(*head)->size = size;
	(*head)->node.next = NULL;
	(*head)->node.data = NULL;

	return 0;
}

int list_insert(listhead_t *head, const void *data, int way)
{
	// 新结点开辟存储空间
	struct node_st *newnode;
	struct node_st *cur;

	// 如果不是头插 也不是尾插 则直接返回
	if (LIST_INSERT_HEAD != way && LIST_INSERT_TAIL != way)
		return -1;

	// 新结点开辟存储空间
	newnode = malloc(sizeof(struct node_st));
	if (NULL == newnode)
		return -1;
	// 结点数据域
	newnode->data = malloc(head->size);
	if (NULL == newnode->data) {
		free(newnode);
		return -1;
	}
	// 存放数据
	memcpy(newnode->data, data, head->size);	

	// 插入到单链表中
	if (LIST_INSERT_HEAD == way) {
		// 头插
		newnode->next = head->node.next; // 新结点的next指针指向第一个数据结点
		head->node.next = newnode; // 头结点的next指针指向新结点
	} else if (LIST_INSERT_TAIL == way) {
		// 尾插
		newnode->next = NULL;	// 新结点的next指针指向NULL
		if (head->node.next == NULL) {
			// 没有数据结点
			head->node.next = newnode;
		} else {
			for (cur = head->node.next; cur->next != NULL; cur = cur->next)	
				;
			// cur就指向最后一个结点
			cur->next = newnode; // 最后一个结点的next指针指向新结点
		}
	}

	return 0;
}

void list_traval(const listhead_t *head, pri_t pri)
{
	struct node_st *cur;

	for (cur = head->node.next; cur != NULL; cur = cur->next) {
		pri(cur->data);
	}
}

void list_destroy(listhead_t *head)
{
	struct node_st *cur, *cur_next;
		
	cur = head->node.next;
	cur_next = cur->next;

	// 释放cur cur_next永远指向cur的下一个结点的地址
	while (1) {
		free(cur->data);
		cur->data = NULL;
		free(cur);
		cur = cur_next;
		if (cur == NULL)
			break;
		cur_next = cur->next;
	}

	free(head);
	head = NULL;
}

// 返回要找的结点的前驱结点地址
static struct node_st *__find(const listhead_t *head, const void *key, cmp_t cmp) 
{
	struct node_st *prev, *cur;	

	prev = (struct node_st *)&head->node;
	cur = prev->next;
	
	while (cur != NULL) {
		if (cmp(cur->data, key) == 0) {
			return prev;
		}
		prev = cur;
		cur = cur->next;
	}

	return NULL;
}

int list_delete(listhead_t *head, const void *key, cmp_t cmp)
{
	struct node_st *p, *del;

	p = __find(head, key, cmp);
	if (NULL == p)
		return -1;
	
	// 要删除结点的前驱是p
	del = p->next;
	p->next = del->next;
	del->next = NULL;
	free(del->data);
	del->data = NULL;
	free(del);
	del = NULL;

	return 0; 
}

void *list_search(const listhead_t *head, const void *key, cmp_t cmp)
{
	struct node_st *p;

	p = __find(head, key, cmp);
	if (NULL == p)
		return NULL;

	return p->next;
}

int list_newlist_reverse(listhead_t **newhead, const listhead_t *head)
{
	struct node_st *cur;

	// 初始化新链表的头结点
	listhead_init(newhead, head->size);

	for (cur = head->node.next; cur != NULL; cur = cur->next) {
		list_insert(*newhead, cur->data, LIST_INSERT_HEAD);
	}

	return 0;
}

void list_reverse(listhead_t *head)
{
	struct node_st *first, *newfirst;	

	// 第一个数据结点
	first = head->node.next;	
	newfirst = first->next;

	while (first->next != NULL) {
		first->next = newfirst->next;
		newfirst->next = head->node.next;
		head->node.next = newfirst;
		newfirst = first->next;
	}
}




