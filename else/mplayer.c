#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
//#include "/home/sang/emb/apue/signal/tbf/tbf.h"

#define CPS 512
#define BURST 1024
#define BUFSIZE 256

static int _write(int rfd, int wfd);

int main(int argc, char *argv[])
{
	pid_t pid;
	int pfd[2] = {};
	int ret;	

	if(argc < 2)
		exit(1);

	ret = pipe(pfd);

	if(-1 == ret)
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
	if(pid > 0)
	{
		int fd;

		close(pfd[0]);
		fd = open(argv[1], O_RDONLY);
		if(-1 == fd)
		{
			perror("open()");
			exit(1);
		}
		_write(fd, pfd[1]);
		//close(pfd[1]);//写端不关闭，进程不会结束
	}else{
		close(pfd[1]);
		dup2(pfd[0], 0);
		execl("/usr/bin/mplayer", "mplayer", "-", NULL);
		_write(pfd[0], 1);
		close(pfd[0]);
		exit(0);
	}
	
	wait(NULL);
	return 0;

ERROR:
	close(pfd[0]);
	close(pfd[1]);
	return -1;
}

static int _write(int rfd, int wfd)
{
	int ret;
	char buf[BUFSIZE] = {};

	while(1)
	{
		memset(buf, 0, BUFSIZE);
		ret = read(rfd, buf, BUFSIZE);
		if(-1 == ret)
		{
			perror("read()");
			return 1;
		}
		if(0 == ret)
			return 0;
		write(wfd, buf, ret);
		//write(wfd, buf, strlen(buf));
	}
}
