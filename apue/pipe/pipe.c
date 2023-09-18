#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFSIZE 128

int main(void)
{
	int pid;
	int fpd[2] = {};
	char buf[BUFSIZE] = {};

	if(-1 == pipe(fpd))
	{
		perror("pipe()");
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
		close(fpd[0]);//关掉自己的读端
		write(fpd[1], "hello", 5);
		close(fpd[1]);
		exit(0);
	}

	close(fpd[1]);
	read(fpd[0], buf, BUFSIZE);
	puts(buf);
	close(fpd[0]);

	wait(NULL);

	exit(0);

ERROR:
	close(fpd[0]);
	close(fpd[1]);
	exit(1);

}
