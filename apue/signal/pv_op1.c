#include <stdio.h>
#include <stdlib.h>

#define PATHNAME "/tmp/out"
#define N 20
#define BUFSIZE 16

int main(void)
{
	int fd;
	pid_t pid;
	char buf[BUFSIZE];

	fd = open(PATHNAME, O_WRONLY, 0666);

	if(-1 == fd)
	{
		perror("open()");
		exit(1);
	}
	
	write(fd, "0", 1);
	close(fd);

	//创建信号量集
	semid = semget(IPC_PRIVATE, 1, IPC_CREATE | IPC_EXCL | 0600);
	if(-1 == semid)
	{
		perror("semget()");
		exit(1);
	}

	//设置信号量
	semctl(semid, 0, SETVAL, 1);

	for(i = 0; i < N; i++)
	{
		pid = fork();
		if(-1 == pid)
		{
			perror("fork()");
			exit(1);
		}
		P()//p操作
		fd = open(PATHNAME, O_RDWR | O_APPEND, 0600);//io
		if(-1 == fd)
		{
			perror("chil_fork()");
			exit(1);
		}
		read(fd, buf, BUFSIZE);
		

		V()//v操作
	}


}
