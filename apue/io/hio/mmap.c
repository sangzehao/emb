#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/mman.h>

//将argv[1]映射到内存
int main(int argc, char *argv[])
{
	int fd;
	struct stat st;
	char *ptr;

	if(argc < 2)
		return 1;

	fd = open(argv[1], O_RDONLY);
	if(-1 == fd)
	{
		perror("open()");
		return 1;
	}

	if(-1 == fstat(fd, &st))
	{
		perror("fstat()");
		goto ERROR;
	}
	
	//映射到内存
	ptr = (char *)mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_PRIVATE, fd, 0);
	if(MAP_FAILED == ptr)
	{
		perror("mmap()");
		goto ERROR;
	}

	puts(ptr);

	//解除映射
	munmap(ptr, st.st_size);
	close(fd);

	return 0;
ERROR:
	close(fd);
	return 1;
}	
