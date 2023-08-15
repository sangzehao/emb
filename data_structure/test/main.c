#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//#include"../prev_expression/dls_stack.h"
#include"/home/sang/emb/data_structure/prev_expression/dls_stack.h"

static int is_num(const char *data);
int cmp_op(const char *op1, const char *op2);

int main(int argc, char *argv[])
{	
	char n;
	int len;
	int i;
	if(argc < 2)
		return -1;
	stack *stack_op;
	stack *stack_res;
	stack_init(&stack_op, sizeof(char));
	stack_init(&stack_res, sizeof(char));
	len = strlen(argv[1]);
	
	for(i = len - 1; i >= 0; i--)
	{
		if(is_num(&argv[1][i]))
		{
			stack_push(stack_res, &argv[1][i]);
		}
		else
		{
			if(!stack_isempty(stack_op))
			{
				//比较
				while(!stack_isempty(stack_op))
				{
					stack_pop(stack_op, &n);
					if(cmp_op(&n, &argv[1][i]))//新的优先级大,直接进
					{
						stack_push(stack_op, &n);
						stack_push(stack_op, &argv[1][i]);
						break;
					}else{
						stack_push(stack_res, &n);
					}
				}
				if(stack_isempty(stack_op))
				{
					stack_push(stack_op, &argv[1][i]);
				}
			}	
			else
				stack_push(stack_op, &argv[1][i]);
		}
	}
	printf("****expression****\n");
	while(!stack_isempty(stack_op))
	{
		stack_pop(stack_op, &n);
		stack_push(stack_res, &n);
	}
	while(!stack_isempty(stack_res))
	{
		stack_pop(stack_res, &n);
		printf("%c ", n);
	}
	printf("\n");
	
	return 0;
}

static int is_num(const char *data)
{
	return (*data >= 48) && (*data <= 57);
}

static int __find(const char *data, const char *arr, int size)
{
	int i;

	for(i = 0; i < size; i++)
	{
		if(*data == *(arr + i))
			return i;
	}
}

int cmp_op(const char *in_op, const char *out_op)
{
	char op[] = {'-', '+', '*', '/'};
   	int b = __find(out_op, op, sizeof(op) / sizeof(char));	
	int a = __find(in_op, op, sizeof(op) / sizeof(char));
	int priority;
	
	if(1 == a && 2 == b)
		return 1;
	if(2 == a && 1 ==b)
		return 0;

	priority = b - a;

	if(priority == 1 || priority == -1 || priority == 0)
		return 1;
	else if(priority > 0)
		return 1;
	else if(priority < 0)
		return 0;
}
