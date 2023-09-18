#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define BUFSIZE 128

int main(void)
{	
	int fd1, fd2;
	char buf[BUFSIZE] = {};


	fd1 = open("/home/sang/emb/apue/signal/pp", O_RDWR | O_APPEND, 0666);
	/*
	   	打开一个文件，作为新的标准输入，标准输出，标准错误输出的目的地。
		需要标准输入时，不用在终端上用键盘输入，直接读文件的内容。文件里的内容作为标准输入输入的内容。
		标准输出如printf时，不再输出到终端上，而是输入到此文件里
		标准出错输出如perror()，也输出到此文件里
		注意，我们没有改变标准输入，标准输出，标准错误输出的文件描述符。
		而是让文件描述符，代表新的文件。把本来写在终端的内容，写到了我们指定的这个文件中。
	*/  
	dup2(fd1, 2);
	dup2(fd1, 0);
	/*
		dup2(int oldfd, int newfd);
		意思是oldfd文件描述符值的文件有了新的文件描述符名字newfd,
		但是注意此时oldfd描述符并没有被废，而是oldfd, newfd都指向这同一个文件。两着作用等效，都指得是
		这个文件。
		如果之后对newfd文件描述符有什么操作，它起作用的对象就是这个新指向的文件了。
	*/
	fd2 = open("/home/sang/emb/apue/signal", O_RDWR, 0666);
	if(-1 == fd2)
		perror("open()");
	read(0, buf, BUFSIZE);
	write(1, buf, strlen(buf));
	printf("fd:dsdsf***%d\n", dup2(fd1, 1));
	printf("stdout\n");
	printf("stdout\n");
	printf("************\n");
	
	return 0;
}
