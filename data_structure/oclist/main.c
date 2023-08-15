#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"oclist.h"

struct data_st{
	char *data;
	struct list_head node;
};

int list_find(struct list_head *head, struct list_head **prev, const void *data, struct data_st **mydata);

int main(int argc, char *argv[])
{
	if(argc < 2)
		return -1;
	struct data_st *mydata;
	struct list_head *pos;
	struct list_head *prev;
	int i;

	//初始化头结点
	LIST_HEAD(myhead);

	//插入
	printf("\n******add******\n");
	for(i = 1; i < argc; i++)
	{
		mydata = malloc(sizeof(struct data_st));
		mydata->data = malloc(sizeof(char *));
		memcpy(&mydata->data, argv + i, sizeof(char *));	
		list_add(&mydata->node, &myhead);
	}
	//遍历
		
	list_for_each(pos, &myhead)
	{
		mydata = list_entry(pos, struct data_st, node);
		printf("%s ", (char *)mydata->data);
	}
	//删除
	printf("\n******del******\n");
	prev = &myhead;
	pos = (&myhead)->next;

	while(pos != &myhead)
	{
		mydata = list_entry(pos, struct data_st, node);
		if(strcmp(mydata->data, *(argv + 2)) == 0)
		{
			list_del(pos, prev);
		//	if(mydata->data != NULL)
		//		free(mydata->data);
			mydata->data = NULL;
			free(mydata);
			mydata = NULL;
			break;
		}
		prev = pos;
		pos = pos->next;
	}
	list_for_each(pos, &myhead)
	{
		mydata = list_entry(pos, struct data_st, node);
		printf("%s ", (char *)mydata->data);
	}

	//改
	printf("\n******cha******\n");
	i = list_find(&myhead, &prev, *(argv + 3), &mydata);
	if(i == -1)
		printf("no!\n");
	else
	{
		//strcpy(mydata->data, "change");
		mydata->data = "change";
		list_for_each(pos, &myhead)
		{
			mydata = list_entry(pos, struct data_st, node);
			printf("%s ", (char *)mydata->data);
		}
	}

//查	
	printf("\n******cha******\n");
	i = list_find(&myhead, &prev, *(argv + 4), &mydata);
	if(i == -1)
		printf("no!\n");
	else
		printf("%s\n", mydata->data);
	printf("\n");

	return 0;
}

int list_find(struct list_head *head, struct list_head **prev, const void *data, struct data_st **mydata)
{
	struct list_head *cur;
//	struct data_st *mydata;
	
	*prev = head;
	cur = head->next;

	while(cur != head)
	{
		*mydata = list_entry(cur, struct data_st, node);
		if(strcmp((*mydata)->data, data) == 0)
		{
			return 0;
		}
		*prev = cur;
		cur = cur->next;
	}

	return -1;
}
