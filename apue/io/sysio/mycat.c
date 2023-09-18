#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 2

int main(int argc, char *argv[])
{
	if(argc < 2)
		return 0;

	int fp;
	char buf[BUFSIZE];
	int cnt;

	fp = open(argv[1], O_RDONLY);//可以打开目录
	//fp = open(argv[1], O_WRONLY, 0666);//可以打开目录，但不能写
	if(-1 == fp)
	{
		perror("open()");
		return -1;
	}
	while(1)
	{
		memset(buf, 0, BUFSIZE);
		cnt = read(fp, buf, BUFSIZE);
		if(0 == cnt)
			break;
		else if(-1 == cnt)
		{
			goto ERROR;
		}

		write(1, buf, cnt);
		sleep(1);
	}

	close(fp);

	return 0;

ERROR:
	close(fp);
	return 1;
}
