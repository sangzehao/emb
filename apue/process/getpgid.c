#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(void)
{
	pid_t pid;

	pid = fork();

	if(-1 == pid)
	{
		perror("fork()");
		exit(0);
	}

	if(0 == pid)
	{
		printf("child:pid:%d gid:%d sid:%d\n", getpid(), getpgid(getpid()), getsid(getpid()));
		if(-1 == setpgid(0, 0))
		{
			perror("setpgid()");
			exit(1);
		}
		printf("child:pid:%d gid:%d sid:%d\n", getpid(), getpgid(getpid()), getsid(getpid()));
		exit(0);
	}
	wait(NULL);

	printf("parent:gid:%d pid:%d sid:%d\n", getpid(), getpgid(getpid()), getsid(getpid()));


	return 0;
}
