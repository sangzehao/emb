#include<stdio.h>
#include<string.h>
#include"queue.h"


int main(int argc, char *argv[])
{

	queue *myque = NULL;
	int i;
	char **s;
	char *str = "hello";

	if(argc < 2)
		return -1;
	queue_init(&myque, 10, sizeof(char *));

	for(i = 1; i < argc; i++)
	{
		if(-1 == queue_enq(myque, argv + i))
			break;
	}

	for(i = 0; i < 3; i++)
	{
		if(-1 == queue_deq(myque, s))
		{
			break;
		}
		printf("%s\n", *s);
	}

	printf("***********\n");
	queue_enq(myque, &str);
	printf("***********\n");
	
	while(!queue_isempty(myque))
	{
		queue_deq(myque, s);
		//puts(*s);
		printf("%s\n", *s);
	}	
	queue_destory(&myque);
	printf("\n");


	return 0;

}
