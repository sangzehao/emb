#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#define START 100
#define END 300

int is_primer(int num);

int main(void)
{
	int i = START;
	int num = START;
	pid_t pid;

	while(i <= END)
	{
		pid = fork();
		if(-1 == pid)
		{
			perror("fork");
			continue;
		}
		
		if(0 == pid)
		{
			is_primer(i);
			exit(0);	
		}
	
		i++;		
	}

	for(i = START; i <= END; i++)
		wait(NULL);	
	
	return 0;
}


int is_primer(int num)
{
	sleep(1);
	int end = num / 2;
	int i = 2;
	while(i <= end)
	{
		if( num % i == 0)
		{
			break;
		}
		i++;
	}
	
	if(i == end + 1)
		printf("%d\n", num);

	return 0;
}

