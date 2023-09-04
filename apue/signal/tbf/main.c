#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#include "tbf.h"

#define CPS 5
#define BURST 25
#define BUFSIZE 200


int main(int argc, char *argv[])
{
	int flag;
	ssize_t num;
	int fd, i, toks, whi;
	char buf[BUFSIZE] = {};

	if(argc < 2)
		return -1;
		
	fd = open(argv[1], O_RDONLY);
	if(-1 == fd)
	{
		perror("open()");
		return -1;
	}
	
	//暂且先一次全部创建

	for(i = 0; i < TBFMAX; i++)
		tbf_init(CPS, BURST);
	
	pause();

	flag = 0;
	while(1)
	{
		if(0 == flag)
		{
			pause();
		//	sleep(2);
			flag = 1;
		}else{
			flag = 0;
		}		

		toks = 0;
		whi = 0;
		memset(buf, 0, BUFSIZE);
		tbf_init(CPS, BURST);//初始化令牌，并启动信号
		
		//取令牌，不能只单纯的从开头取，如果每次从开头取，那么就会出现后边桶令牌很多，但没用上，还要在前边等，浪费时间。

		//暂定先从第一个桶开始取令牌
BACK:
		;
		while(toks <= BUFSIZE && whi < TBFMAX)
		{
			toks += tbf_fetch_token(whi, BUFSIZE - toks);
			if(0 == toks)
				goto BACK;
			whi++;
		}
		printf("\n$$$***消耗%d个令牌\n", toks);
		num = read(fd, buf, toks);
		if(-1 == num)
		{
			perror("read()");
			goto ERROR;
		}
		if(0 == num && toks != 0)
			break;

		write(1, buf, toks);
	}
	
	close(fd);
	return 0;

ERROR:
	close(fd);
	return -1;
}
