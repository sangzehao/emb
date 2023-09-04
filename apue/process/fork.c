#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
	int pid;
	
	printf("start\n");

	pid = fork();

	if(-1 == pid)
	{
		perror("fork");
		return 1;
	}

	if(pid > 0)
		printf("parent\n");
	else
		printf("child\n");
	
	while(1);
	return 0;

}
