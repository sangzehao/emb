#include<stdlib.h>
#include<stdio.h>
#include "list.h"

struct data_st{
	int num;
	struct list_head node;
};
//me
int main(void)
{
	int datas[] = {3,1,2,3,4,1,6,8,3,35,63};
	struct data_st *mydata;
	struct list_head *pos;
	int i;

	LIST_HEAD(myhead);//初始化头结点

	for(i = 0; i < sizeof(datas) / sizeof(int); i++)
	{
		mydata = malloc(sizeof(struct data_st));

		if(mydata == NULL)
			return -1;
		mydata->num = datas[i];
		//头插
		list_add(&mydata->node, &myhead);
	}
	//遍历
	list_for_each(pos, &myhead){
		mydata = list_entry(pos, struct data_st,  node);
		printf("%d ", mydata->num);
	}

	printf("\nmove tail\n");
	list_for_each(pos, &myhead){
	//	mydata = list_entry(pos, struct data_st,  node);
		list_move_tail(pos, &myhead);
	}
	list_for_each(pos, &myhead){
		mydata = list_entry(pos, struct data_st,  node);
		printf("%d ", mydata->num);
	}
	printf("\n删除\n");
	list_for_each(pos, &myhead)
	{
		mydata = list_entry(pos, struct data_st, node);
		if(mydata->num == 35)
		{
			list_del(pos);
		//	list_del(&mydata->node);
			break;
		}
	}
	list_for_each(pos, &myhead)
	{
		mydata = list_entry(pos, struct data_st, node);
		printf("%d ", mydata->num);
	}
	printf("\n全删\n");
	while(myhead.next != &myhead)
	{
		pos = myhead.next;
		mydata = list_entry(pos, struct data_st, node);
		list_del(pos);
		free(mydata);
		mydata = NULL;
	}
	if(myhead.next == myhead .prev)
	{
		printf("all delete\n");
	}

	printf("\n");

	return 0;
}
