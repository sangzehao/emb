#ifndef _LIST_H_
#define _LIST_H_

typedef void (*pri_t)(const void *data);
typedef int (*cmp_t)(const void *data, const void *data1);

enum {HEADADD, TAILADD};

typedef struct LNode
{
	struct LNode *next;
	struct LNode *prev;
//	char data[0];
	void *data;

}node_t;

typedef struct
{
	node_t node;
	int size;
}head_t;

int list_init(head_t **mylist, int size); //初始化
int list_add(head_t *mylist, void *data, int way); //增加
void list_traval(const head_t *mylist, pri_t pri); //遍历
int list_del(head_t *mylist, void *key, cmp_t cmp);//删除
int list_destroy(head_t *mylist);//释放
int list_fetch(head_t *mylist, void *key, cmp_t, void *data); //获取
void *list_first_data(head_t *mylist); //获取第一个数据

int list_push(head_t *mylist, void *key, cmp_t cmp, void *data);//出栈	
int list_empty(head_t *mylist); //是否为空栈
int list_numb(head_t *mylist);  //成员个数

#endif

