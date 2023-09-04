#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <time.h>
#include <fcntl.h>

#define MAX 128
#define PATHNAME "/tmp/out"

int mydaemon(void);

int main(void)
{
	pid_t pid;

	time_t tim;
	struct tm *tmp;
	char s[MAX];
	FILE *fp;

	if(-1 == mydaemon())
		return 1;
	fp = fopen(PATHNAME, "w");

	if(NULL == fp)
	{
		perror("fopen()");
		exit(0);
	}
	while(1)
	{
		tim = time(NULL);
		if(-1 == tim)
		{
			perror("tim");
			return 1;
		}
		tmp = localtime(&tim);
		if(NULL == tmp)
		{
			perror("localtime()");
			return 1;
		}
		memset(s, 0, MAX);
		strftime(s, MAX,"%Y-%m-%d %H:%M:%S\n", tmp);
		printf("%s\n", s);

		fputs(s, fp);
		fflush(NULL);
		sleep(1);
	}
	return 0;
}

int mydaemon(void)
{
	int fd;
	pid_t pid;
	pid = fork();
	
	if(-1 == pid)
	{
		perror("fork()");
		return -1;
	}
	if(pid > 0)
		exit(0);
	if(-1 == setsid())
	{
		perror("setsid()");
		return -1;
	}
	
	umask(0);
	chdir("/");

	fd = open("/dev/null", O_RDWR);

	if(-1 == fd)
	{
		perror("open()");
		return -1;
	}

	dup2(fd, 0);
	dup2(fd, 1);
	dup2(fd, 2);

	if(fd > 2)
		close(fd);

	return 0;
}
