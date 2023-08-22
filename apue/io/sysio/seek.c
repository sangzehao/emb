#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAXSIZE 32
#define SIZE 16

int main(int argc, char *argv[])
{
	if(argc < 3)
		return -1;

	int fd, wd;
	int cnt;
	char ptr[MAXSIZE];


	fd = open(argv[1], O_RDONLY);
	if(-1 == fd)
	{
		perror("ropen()");
		return -1;
	}
	wd = open(argv[2], O_WRONLY);
	if(-1 == wd)
	{
		close(fd);
		perror("wopen()");
		return -1;
	}

	while(1)
	{
		memset(ptr, '\0', MAXSIZE);
		cnt = read(fd, ptr, SIZE);
		if(-1 == cnt)
		{
			perror("read()");
			goto ERROR;
		}
		if(0 == cnt)
			break;
		write(wd, ptr, cnt);
		
	}
 
	close(fd);
	close(wd);
	return 0;

ERROR:
	close(fd);
	close(wd);
	return -1;

}
