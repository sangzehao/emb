#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#include"../ten_two/stack.h"

void p_int(const void *data);
int ten_two(int num, int *sum);

int main(int argc, char *argv[])
{
	stack *mystack;
	int j;
	int remain;
	int sum = atoi(argv[1]);
	int num = sum;
	int res = 0;

	if(argc < 2)
		return -1;

	//栈
	printf("****stack****\n");
	stack_init(&mystack, sizeof(int));
	while(sum != 1)
	{
		remain = sum % 2;
		sum = sum / 2;
		stack_push(mystack, &remain);
	}
	stack_push(mystack, &sum);
	while(!stack_isempty(mystack))
	{
		stack_pop(mystack, &remain);
		printf("%d", remain);
	}
	stack_destory(mystack);
	printf("\n");

	//递归，只能用于小于1000,最多表示10位
	if(num <= 1000)
	{
		printf("****recursion****\n");
		j = ten_two(num, &res);
		res = res * 10 + j;
		printf("%d\n", res);
	}

	return 0;
}

void p_int(const void *data)
{
	int *s = (int *)data;

	printf("%d ", *s);

}

int ten_two(int num, int *sum)
{
	int i, j;

	i = 0;
	if(num > 0)
	{
		i = num % 2;
		num = num / 2;
		j = ten_two(num, sum);
		*sum = *sum * 10 + j;
	}
	
	return i;
}
	
