#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	int a;
	if(argc < 2)
	{
		return -1;
	}

	int fd = open(argv[1], O_WRONLY | O_CREAT | O_TRUNC, 0666);
	if(-1 == fd)
	{
		perror("open()");
		return -1;
	}
	close(1);
	dup2(fd, 1);

	write(1, "hello wiiorld", 11);
	
	close(fd);

	return 0;
}
