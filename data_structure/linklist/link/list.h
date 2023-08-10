#ifndef __LIST_H__
#define __LISH_H__

//数据节点
struct node_st
{
	void *data;
	struct node_st *next;
};

//头结点

typedef struct {
	struct node_st node;
	int size;
}listhead_t;

//插入方式 头插 尾插
enum {LIST_INSERT_HEAD, LIST_INSERT_TAIL};
		
typedef int (*cmp_t)(const void *data, const void *key);
typedef void (*pri_t)(const void *data);

//初始化头结点

int listhead_init(listhead_t **head, int size);

//插入

int list_insert(listhead_t *head, const void *data, int way);

//删除

int list_delete(listhead_t *head, const void *key, cmp_t cmp);

//查找
void *list_search(const listhead_t *head, const void *key, cmp_t cmp);

//遍历
void list_traval(const listhead_t *head, pri_t pri);

//销毁
void list_destory(listhead_t *head);

//逆序生成一个新链表返回

int list_reverse(listhead_t **newhead, const listhead_t *head);

//自己反转
int list_self_reverse(listhead_t *head);

//输出中间
int  list_mid(listhead_t *head, struct node_st **key);


#endif
