#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include"lqueue.h"

int main(int argc, char *argv[])
{
	int i;
	char *s;
	if(argc < 2)
		return -1;
	lqueue *myque;
	queue_init(&myque, sizeof(char *));

	for(i = 1; i < argc; i++)
	{
		queue_enq(myque, &argv[i]);
	}
	while(!queue_isempty(myque))
	{
		queue_deq(myque, &s);
		printf("%s ", s);
	}
	printf("\n");

	return 0;
}
