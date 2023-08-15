#include <stdlib.h>
#include <stdio.h>
#include "lqueue.h"

int main(int argc, char *argv[])
{
	lqueue_t *mylqueue = NULL;
	int n;

	if(argc < 2)
		return 2;

	lqueue_init(&mylqueue, sizeof(int));

	for(int i = 1; i < argc; i++)
	{
		n = atoi(argv[i]);
		lqueue_enq(mylqueue, &n);
	}

	while(!lqueue_is_empty(mylqueue))
	{
		lqueue_deq(mylqueue, &n);
		printf("%d ", n);
	}
	printf("\n");

	lqueue_destory(mylqueue);

	return 0;
}
