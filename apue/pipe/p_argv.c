#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFSIZE 128

int fork_pipe(int *s);
int _write(int fd1, int fd2);

int main(int argc, char *argv[])
{
	int fp;
	int pfd[2] = {};
	pid_t pid;

	if(argc < 2)
		exit(0);

	if(-1 == pipe(pfd))
	{
		perror("pipe()");
		return -1;
	}
	
	pid = fork();

	if(-1 == pid)
	{
		perror("pid()");
		goto ERROR;
	}
	
	if(pid > 0)
	{
		fp = open(argv[1], O_RDONLY);

		if(-1 == fp)
		{
			perror("open()");
			exit(1);
		}
		
		close(pfd[0]);
		_write(fp, pfd[1]);
		close(pfd[1]);
	}
	
	if(0 == pid)
	{
		close(pfd[1]);
		_write(pfd[0], 1);
		exit(0);
	}

	wait(NULL);

	return 0;

ERROR:
	close(pfd[0]);
	close(pfd[1]);
	return -1;
}
int fork_pipe(int *s)
{
	pid_t pid;

	if(-1 == pipe(s))
	{
		perror("pipe()");
		return -1;
	}
	
	pid = fork();

	if(-1 == pid)
	{
		perror("pid()");
		goto ERROR;
	}

	return 0;

ERROR:
	close(s[0]);
	close(s[1]);
	return -1;
}

int _write(int fd1, int fd2)
{
	char buf[BUFSIZE];
	int ret;

	while(1)
	{	
		memset(buf, 0, BUFSIZE);
		ret = read(fd1, buf, BUFSIZE);
		if(0 == ret)
			return 0;
		write(fd2, buf, ret);
	}
}

