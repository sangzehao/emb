#include "fsm.h"

#define TTY1 "/dev/tty10"
#define TTY2 "/dev/tty11"

int main(void)
{
	fsm_t *fd12, *fd21;

	int fd1, fd2;

	fd1 = open(TTY1, O_RDWR | O_TRUNC);
	if(-1 == fd1)
	{
		perror("open1()");
		exit(1);
	}
	write(fd1, "tty10:", 6);

	fd2 = open(TTY2, O_RDWR | O_TRUNC);
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
		fsm_drive(fd12);
		fsm_drive(fd21);
	}

	fsm_destroy(&fd12);
	fsm_destroy(&fd21);

	return 0;
	
}
