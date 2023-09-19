#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <syslog.h>
#include <sys/file.h>
#include <errno.h>

#define BUFSIZE 256
#define PATHNAME "/tmp/out"
#define LOCKFILE "/var/run/mydaemon.pid"

int mydaemon(void);
int write_log(void);
int already_running(void);

int main(void)
{

	//创建连接
	openlog("my_daemon", LOG_PID, LOG_DAEMON);
	
	if(-1 == mydaemon())
		return -1;
	
	if(-1 == already_running())
	{
		syslog(LOG_ERR, "the procese is already running");
		exit(1);
	}

//	while(1)
//		;	
	if(-1 == write_log())		
		return -1;

}

int  mydaemon(void)
{
	pid_t pid;
	int fd;

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
		perror("sid()");
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

int write_log(void)
{
	int fd;
	FILE *fp;
	time_t tim;
	struct tm *tmp;
	char buf[BUFSIZE];
	size_t ret;
	int i = 0;

	//fd = open(PATHNAME, O_WRONLY, 0666);//为什么系统io就不行呢
	fp = fopen(PATHNAME, "w");

	if(-1 == fd)
	{
		perror("wri_open()");
		return -1;
	}



	while(1)
	{
		i++;

		if(5 == i)
		{//日志默认写在了 /var/log/syslog
			syslog(LOG_INFO, "%s is running", buf);
			i = 0;
		}
		tim = time(NULL);
		
		if(-1 == tim)
		{
			perror("time()");
			return -1;
		}

		tmp = localtime(&tim);

		if(NULL == tmp)
		{
			perror("localtime()");
			return -1;
		}

		memset(buf, 0, BUFSIZE);
	
		strftime(buf, BUFSIZE, "%Y-%m-%d %H:%M:%S\n", tmp); 
	
	/*	if(-1 == write(fd, buf, strlen(buf)))
		{
			perror("write()");
			return -1;
		}
	*/
		fputs(buf, fp);	
		fflush(NULL);	

		sleep(1);
	}

	return 0;
}


//加锁，但实例，同一个进程不会被同时执行多个
int already_running(void)
{
	int fd;
	char buf[BUFSIZE] = {};

 	fd = open(LOCKFILE, O_WRONLY | O_CREAT, 0666);

	if(-1 == fd)
	{
		syslog(LOG_ERR, "open():%s", strerror(errno));
		return  -1;
	}

	if(-1 == flock(fd, LOCK_EX | LOCK_NB))
	{
		syslog(LOG_ERR, "flock():%s", strerror(errno));
		return -1;
	}

	//进程目前还未被执行过
	snprintf(buf, BUFSIZE, "%d", getpid());

	//清空原文件内容
	ftruncate(fd, 0);
	write(fd, buf, strlen(buf));

	return 0;
}
