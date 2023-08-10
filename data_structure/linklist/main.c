#include<stdio.h>
#include<string.h>

#include"linklist.h"

#define NAMESIZE 32

typedef struct{
	int id;
	char name[NAMESIZE];
}stu_k;

void p_a(const void*key);

int main(void)
{
	listhead *head = NULL;
	stu_k *stu;
	stu->id = 1;
	strcpy(stu->name, "stu1");
	
//	printf("%d %s\n", stu->id, stu->name);
	listhead_init(&head, sizeof(stu_k));
	list_insert(head, &stu, 0);
	list_traval(head, p_a);

	return 0;
}

void p_a(const void*key)
{
	stu_k *data = (stu_k *)key;

	printf("%d %s\n", data->id, data->name);
}

