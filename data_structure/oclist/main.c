#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"oclist.h"

int list_find(struct list_head *head, const void *data, struct data_st **mynode);

struct data_st{
	char *data;
	struct list_head node;
};

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
	pos = (&myhead)->next;
	while(pos != &myhead)
	{
		mydata = list_entry(pos, struct data_st, node);
		if(strcmp(mydata->data, *(argv + 3)) == 0)
		{
			mydata->data = "change";
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

//查	
	printf("\n******cha******\n");
/*	pos = (&myhead)->next;
	while(pos != &myhead)
	{
		mydata = list_entry(pos, struct data_st, node);
		if(strcmp(mydata->data, *(argv + 4)) == 0)
		{
			printf("%s ", (char *)mydata->data);
			break;
		}
		prev = pos;
		pos = pos->next;
	}
	*/

	i = list_find(&myhead, *(argv + 3), pos);
	if(i == -1)
		printf("no!\n");
	else
		printf("%s\n", mydata->data);
	printf("\n");

	return 0;
}

int list_find(struct list_head *head, const void *data, struct list_head *mynode)
{
	struct list_head *cur;
	struct list_head *prev;
	struct data_st *mydata;

	cur = head->next;

	while(cur != head)
	{
		mydata = list_entry(cur, struct data_st, node);
		if(strcmp(mydata->data, data) == 0)
		{	
			return 0;
		}
		prev = cur;
		cur = cur->next;
	}

	return -1;
}
