#include"list.h"
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int list_init(head_t **mylist, int size)
{
	(*mylist) = malloc(sizeof(head_t));
	if(*mylist == NULL)
		return -1;
	(*mylist)->size = size;
	(*mylist)->node.next = &(*mylist)->node;
	(*mylist)->node.prev = &(*mylist)->node;
	return 0;
}

//插入一个新节点
static void _add(node_t *newnode, node_t *before, node_t *after)
{
	newnode->next = after;
	newnode->prev = before;
	before->next = newnode;
	after->prev = newnode;

}

int list_add(head_t *mylist, void *data, int way) //增加
{
	if(way != HEADADD &&way != TAILADD)
		return -1;
	node_t *cur = malloc(sizeof(node_t) + mylist->size);
	node_t *t;
	if(cur == NULL)
		return -1;
	cur->data = malloc(mylist->size);
	if(NULL == cur->data);
		return -1;
	memcpy(cur->data, data, mylist->size);

	if(way == HEADADD)
	{	
		_add(cur, &mylist->node, mylist->node.next);
	}
	
	if(way == TAILADD)
	{
		_add(cur, mylist->node.prev, &mylist->node);
	}
}
void list_traval(const head_t *mylist, pri_t pri) //遍历
{
	node_t *p = mylist->node.next;
	
	for(;p != &mylist->node; p = p->next)
		pri(p->data);	

}

static node_t *__find(head_t *mylist, const void *key, cmp_t cmp)
{
	node_t *cur = mylist->node.next;

	while(cur != &mylist->node)
	{
		if(cmp(cur->data, key) == 0)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;

}

static void one_destroy(node_t *f) ///释放一个节点
{
	free(f);
	f = NULL;
}

static void one_move(node_t *f)  //摘除一个节点
{
	f->prev->next = f->next; 
	f->next->prev = f->prev;
	f->prev = f->next = NULL;
}

int list_del(head_t *mylist, void *key, cmp_t cmp)//删除
{
	node_t *del = __find(mylist, key, cmp);
	if(del == NULL)
		return -1;
	one_move(del); //摘除
	one_destroy(del);//释放
	return 0;

}

static int cmp_always(const void *data, const void *data1)
{
	return 0;
}

int list_destroy(head_t *mylist)//释放
{
	while(mylist->node.next != &mylist->node && mylist->node.prev != &mylist->node)
	{
		list_del(mylist, NULL, cmp_always);
	}
	free(mylist);
	mylist = NULL;
	return 0;
}
int list_fetch(head_t *mylist, void *key, cmp_t cmp, void *data) //获取
{
	node_t *cur = __find(mylist, key, cmp);
	if(cur == NULL)
		return -1;
	memcpy(data, cur->data, mylist->size);
	one_move(cur);
	one_destroy(cur);//释放

	return 0;

}

void *list_first_data(head_t *mylist) //获取第一个数据 
{
	if(mylist->node.next == &mylist->node && mylist->node.prev == &mylist->node)
		return NULL;
	return mylist->node.next->data;
}
int list_empty(head_t *mylist) //是否为空栈
{
	return (mylist->node.next == &mylist->node && mylist->node.prev == &mylist->node);
}
int list_numb(head_t *mylist) //成员个数
{
	int cnt = 0;
	node_t *p = mylist->node.next;
	while(p != &mylist->node)
	{
		cnt ++;
		p = p->next;
	}
	return cnt;

}

int list_push(head_t *mylist, void *key, cmp_t cmp, void *data)//出栈
{
	node_t *del = __find(mylist, key, cmp);
	if(del == NULL)
		return -1;
	memcpy(data, del->data, mylist->size);
	one_move(del); //摘除
	one_destroy(del);//释放
	return 0;

}

