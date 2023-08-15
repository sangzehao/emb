#include <stdio.h>
#include "stack.h"

int main(int argc, char *argv[])
{
	stack *mystack = NULL;
	int i; 
	char c;

	if(argc < 2)
		return -1;
	stack_init(&mystack, sizeof(char));

	for(i = 0; argv[1][i]; i++)
	{
		if( -1 == stack_push(mystack, argv[1] + i))
			break;
	}


	while(!stack_is_empty(mystack))
	{
		stack_pop(mystack, &c);
		putchar(c);
	}

	printf("\n");
	
	return 0;
}
