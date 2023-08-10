#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include"list.h"

int listhead_init(listhead_t **head, int size)
{
	*head = malloc(sizeof(listhead_t));
	if(*head == NULL)
		return -1;
	(*head)->size = size;
	(*head)->node.next = NULL;
	(*head)->node.data = NULL;

	return 0;
}

int list_insert(listhead_t *head, const void *data, int way)
{
	//新结点开辟空间
	struct node_st *newnode;
	struct node_st *cur;

	if(LIST_INSERT_HEAD != way && LIST_INSERT_TAIL != way)
		return -1;
	//新结点开辟空间
	newnode = malloc(sizeof(struct node_st));

	if(newnode == NULL)
		return -1;
	//结点数据域开辟空间
	newnode->data = malloc(head->size);
	if (NULL == newnode->data)
	{
		free(newnode);
		return -1;
	}
	//存放数据
	memcpy(newnode->data, data, head->size);

	//插入到单链表中
	if(LIST_INSERT_HEAD == way)
	{
		//头插
		newnode->next = head->node.next;
		//新结点的next指针指向第一个数据结点
		head->node.next = newnode;
	}else if(LIST_INSERT_TAIL == way){
		//尾插
		newnode->next = NULL;
		if(head->node.next == NULL)
		{
			//没有数据结点
			head->node.next = newnode;
		}else{
			for(cur = head->node.next; cur->next != NULL; cur = cur->next)
				;
			//cur指向最后一个结点
			cur->next = newnode;
		}
	}
	return 0;
}

void list_traval(const listhead_t *head, pri_t pri)
{
	struct node_st *cur;

	for(cur = head->node.next; cur != NULL; cur = cur->next){
		pri(cur->data);
	}
}

//销毁

void list_destory(listhead_t *head)
{
	struct node_st *cur, *cur_next;

	cur = head->node.next;
	cur_next = cur->next;
	//释放cur 
    //cur_next永远指向cur的下一个结点的地址
	while(1)
	{
		free(cur->data);
		cur->data = NULL;
		cur = cur_next;
		if(cur == NULL)
			break;
		cur_next = cur->next;
	}
	free(head);
	head = NULL;
}

static struct node_st *__find( listhead_t *head, const void *key, cmp_t cmp)
{
	struct node_st *prev, *cur;

	prev = &head->node;
	cur = prev->next;

	while(cur != NULL)
	{
		if(cmp(cur->data, key) == 0)
		{
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

	if(NULL == p)
		return -1;

	//要删除结点的前驱是p
	del = p->next;
	p->next = del->next;
	del->next = NULL;
	free(del->data);
	del->data = NULL;
	free(del);
	del = NULL;

	return 0;
}

//逆序生成链表
 
int list_reverse(listhead_t **newhead, const listhead_t *head)
{
	listhead_init(newhead, sizeof(char *));

	struct node_st *cur;

//自己再实现一遍头插
/*	for(cur = head->node.next; cur != NULL; cur = cur->next)
	{
		
		struct node_st *newdata;
		newdata = malloc(sizeof(struct node_st));//newdata 应每次都开辟新地址
		newdata->next = NULL;

		if(newdata == NULL)
			return -1;

		newdata->data = malloc(head->size);
		if(newdata->data == NULL)
		{
			free(newdata);
			return -1;
		}
		memcpy(newdata->data, cur->data, head->size);
		newdata->next = (*newhead)->node.next;
		(*newhead)->node.next = newdata;
	}
*/
	
//直接调函数
	for(cur = head->node.next; cur != NULL; cur = cur->next)
	{
		list_insert(*newhead, cur->data, LIST_INSERT_HEAD);
	}

	return 0;
}

int list_self_reverse(listhead_t *head)
{
/*	struct node_st *first, *newfirst;

	first = head->node.next;
	newfirst = first->next;

	while(first->next != NULL)
	{
		first->next = newfirst->next;
		newfirst->next = head->node.next;
		head->node.next = newfirst;
		newfirst = first->next;
	}

*/

	struct node_st *cur;
	struct node_st *tem;

	for(cur = head->node.next; cur->next != NULL; )
	{
		tem = cur->next;
		cur->next = tem->next;
		tem->next = head->node.next;
		head->node.next = tem;
		//list_insert(head, tem->data, LIST_INSERT_HEAD);
	}

//这种会浪费存储空间
/*	for(cur = head->node.next; cur->next != NULL; )
	{
		tem = cur->next;
		cur->next = tem->next;
		list_insert(head, tem->data, LIST_INSERT_HEAD);
	}

	
	return 0;
}
*/
}
int list_mid(listhead_t *head, struct node_st **key)
{
	struct node_st *step1;
	struct node_st *step2;
	int i = 0;

	step1 = head->node.next;
	step2 = head->node.next;
	while(step2->next != NULL)
	{
		step2 = step2->next;
		i++;
		if(i % 2 == 0)
		{	
			step1 = step1->next;
		}
	}
	*key = step1;

	return 0;
}
