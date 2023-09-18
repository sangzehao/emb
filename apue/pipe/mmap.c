#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define LENTH 1024

int main(void)
{
	void *ptr;
	pid_t pid;

	ptr = mmap(NULL, LENTH, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	if(MAP_FAILED == ptr)
	{
		perror("mmap");
		exit(1);
	}

	pid = fork();

	if(-1 == pid)
	{
		perror("fork()");
		goto ERROR;
	}
	
	if(0 == pid)
	{
		memcpy(ptr, "good morning", LENTH);
		munmap(ptr, LENTH);
		exit(0);
	}
	
	wait(NULL);
	puts(ptr);
	munmap(ptr, LENTH);
	
	exit(0);

ERROR:
	munmap(ptr, LENTH);
	exit(0);
}
