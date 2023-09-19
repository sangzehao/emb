#include <stdio.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

#define BUFSIZE 128

int main(int argc, char *argv[])
{
	FILE *fs;
	int fd;
	int ret;
	char *buf = NULL;
	char *buf2[BUFSIZE];
	size_t n = 0;
	int pfd[2];
	pid_t pid;

	if(argc < 2)
		return 1;

	//建管道
	ret = pipe(pfd);
	if(-1 == ret)
	{
		perror("pipe()");
		goto ERROR;
	}

	//创子进程
	pid = fork();

	if(-1 == pid)
	{
		perror("fork()");
		goto ERROR;
	}

	if(pid == 0)
	{
		fs = fopen(argv[1], "r");

		if(NULL == fs)
		{
			perror("fopen()");
			return 1;
		}

		int i = 0;
		close(pfd[0]);
		while(1)
		{
			ret = getline(&buf, &n, fs);
			if(i == 2)
			{	
				i++;
				continue;
			}
			if(-1 == ret)
			{
				perror("getline()");
				goto ERROR;
			}

			if(0 == ret)
				break;
			write(pfd[1], buf, ret);
			i++;	
		}
		close(pfd[1]);
		free(buf);
		fclose(fs);
		exit(0);
	}

	if(pid > 0)
	{
		wait(NULL);
		fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0600);

		if(-1 == fd)
		{	
			perror("open()");
			fclose(fs);
			return 1;
		}
		close(pfd[1]);
		while(1)
		{
			memset(&buf2, 0, BUFSIZE);
			ret = read(pfd[0], buf2, BUFSIZE);

			if(-1 == ret)
			{
				perror("read2()");
				goto ERROR;
			}

			if(0 == ret)
				break;
			write(fd, buf2, ret);
		}

		close(pfd[0]);
	}

	close(fd);
	return 0;

ERROR:
	free(buf);
	fclose(fs);
	close(fd);
	return 1;
}

