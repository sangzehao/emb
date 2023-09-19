#include "fsm.h"

#define TTY1 "/dev/tty9"
#define TTY2 "/dev/tty10"

int main(void)
{
	fsm_t *fd12, *fd21;
	int fd1, fd2;
	fd_set *readset, *writeset;

	fd1 = open(TTY1, O_RDWR | O_NONBLOCK);
	if(-1 == fd1)
	{
		perror("fd1_open()");
		return 1;
	}

	write(fd1, "tty9", 4);
	
	fd2 = open(TTY2, O_RDWR | O_NONBLOCK);
	if(-1 == fd2)
	{
		close(fd2);
		perror("fd2_open()");
		return 1;
	}
	write(fd2, "tty10", 5);

	fsm_init(&fd12, fd1, fd2);
	fsm_init(&fd21, fd2, fd1);

	while(fd12->state != STATE_T || fd21->state != STATE_T)
	{
		//通知法
		FD_ZERO(readset);
		FD_ZERO(writeset);

		if(STATE_R == fd12->state){
			FD_SET(fd12->rfd, readset);
		}else if(STATE_W == fd12->state){
			FD_SET(fd12->wfd, writeset);
		}

		if(STATE_R == fd21->state){
			FD_SET(fd21->rfd, readset);
		}else if(STATE_W == fd21->state){
			FD_SET(fd21->wfd, writeset);
		}

		select((fd1 > fd2 ? fd1 : fd2) + 1, readset, writeset, NULL, NULL);

		if(FD_ISSET(fd12->rfd, readset) || FD_ISSET(fd12->wfd, writeset))
			fsm_driver(fd12);
		if(FD_ISSET(fd21->rfd, readset) || FD_ISSET(fd21->wfd, writeset))
			fsm_driver(fd21);
	}

	fsm_destroy(&fd12);
	fsm_destroy(&fd21);

	return 0;
}
