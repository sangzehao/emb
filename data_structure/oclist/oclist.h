#ifndef __OCLIST_H__
#define __OCLIST_H__

#include<stdio.h>

struct list_head{
	struct list_head *next;
};

#define LIST_HEAD_INIT(name) {&(name)}

#define LIST_HEAD(name) \
	struct list_head name = LIST_HEAD_INIT(name)

static inline void __list_add(struct list_head *new, struct list_head *prev, struct list_head *next)
{
	new->next = next;
	prev->next = new;
}
//增
static inline void list_add(struct list_head *new, struct list_head *head)
{
	__list_add(new, head, head->next);
}


static inline void __list_del_entry(struct list_head *entry, struct list_head *prev)
{
	prev->next = entry->next;
}
//删 只传一个要删的结点
static inline void list_del(struct list_head *entry, struct list_head *prev)
{
	__list_del_entry(entry, prev);
	entry->next = NULL;
}

//查找
/*static inline int list_find(struct list_head *head, const void **data, struct list_head **mynode)
{
	__list_find(head, data, *mynode);
}*/


//head 指针 head括号必须加，是地址
#define list_for_each(pos, head) \
	for(pos = (head)->next; pos != (head); pos = pos->next)

#define offsetof(TYPE, MEMBER) ((size_t)&((TYPE *)0)->MEMBER)

#define container_of(ptr, type, member)({ \
		char *__mptr = (void *)(ptr); \
		((type *)(__mptr - offsetof(type, member)));					\
		})

//找到数据结点起始位置，输出数据
#define list_entry(ptr, type, member) \
	container_of(ptr, type, member)


#endif
