#include "fsm.h"

#define TTY1 "/dev/tty10"
#define TTY2 "/dev/tty11"

//通知法

int main(void)
{
	fsm_t *fd12, *fd21;
	fd_set readfds, writefds;
	int ret;
	int fd1, fd2;

	fd1 = open(TTY1, O_RDWR);
	if(-1 == fd1)
	{
		perror("open1()");
		exit(1);
	}
	write(fd1, "tty10:", 6);

	fd2 = open(TTY2, O_RDWR);
	if(-1 == fd2)
	{
		close(fd1);
		perror("open2()");
		exit(1);
	}
	write(fd2, "tty11:", 6);

	fsm_init(&fd12, fd1, fd2);
	fsm_init(&fd21, fd2, fd1);

	while(!(fd12->state == STATE_T && fd21->state == STATE_T))
	{
		//每次都有可能改变，所以每次都要初始化
		FD_ZERO(&readfds);
		FD_ZERO(&writefds);

		//现在是要读的状态，去监听能不能读。要读和能读不等价
		//加入三种集， 读集，写集，出错集
		if(fd12->state == STATE_R)
		{
			FD_SET(fd12->rfd, &readfds);
		}else if(fd12->state == STATE_W)
		{
			FD_SET(fd12->rfd, &writefds);
		}
			
		if(fd21->state == STATE_R)
		{
			FD_SET(fd21->rfd, &readfds);
		}else if(fd21->state == STATE_W)
		{
			FD_SET(fd21->wfd, &writefds);
		}

		//内核监听
		ret = select((fd1 > fd2 ? fd1 : fd2) + 1, &readfds, &writefds, NULL, NULL);
	
		if(-1 == ret)
		{
			if(errno == EINTR)
				continue;
			perror("select()");
			goto ERROR;

		}
		//判断
		if(FD_ISSET(fd12->rfd, &readfds) || FD_ISSET(fd12->wfd, &writefds))
			fsm_drive(fd12);
		if(FD_ISSET(fd21->rfd, &readfds) || FD_ISSET(fd21->wfd, &writefds))
			fsm_drive(fd21);
	}

	fsm_destroy(&fd12);
	fsm_destroy(&fd21);
	close(fd1);
	close(fd2);

	return 0;
	
ERROR:
	fsm_destroy(&fd12);
	fsm_destroy(&fd21);
	close(fd1);
	close(fd2);

	return 1;
	
}
