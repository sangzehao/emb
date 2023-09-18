#include <stdio.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <poll.h>

#include "fsm.h"

#define TTY1	"/dev/tty11"
#define TTY2	"/dev/tty12"

int main(void)
{
	fsm_t *fsm12, *fsm21;
	int fd1, fd2;
	struct pollfd pfd[2];	

	fd1 = open(TTY1, O_RDWR | O_NONBLOCK);
	if (-1 == fd1) {
		perror("open()");
		exit(1);
	}
	write(fd1, "[********]", 10);

	fd2 = open(TTY2, O_RDWR);
	if (-1 == fd2) {
		perror("open()");
		close(fd1);
		exit(1);
	}
	write(fd2, "[!!!!!!!!]", 10);

	fsm_init(&fsm12, fd1, fd2);
	fsm_init(&fsm21, fd2, fd1);

	pfd[0].fd = fd1;
	pfd[1].fd = fd2;

	// 轮询--->通知 监听文件的数据到来
	while (!(fsm12->state == STATE_T && fsm21->state == STATE_T)) {
		// 监听文件描述符的事件

		pfd[0].events = 0;
		pfd[1].events = 0;

		// 判断状态机的状态
		if (fsm12->state == STATE_R) {
			// 想要读fsm12->rfd
			pfd[0].events |= POLLIN; 
		} else if (fsm12->state == STATE_W) {
			// 想要写fsm12->wfd
			pfd[1].events |= POLLOUT;
		}

		if (fsm21->state == STATE_R)
			pfd[1].events |= POLLIN;
		else if (fsm21->state == STATE_W)
			pfd[0].events |= POLLOUT;
		// 请求内核监听 
		while (-1 == poll(pfd, 2, -1)) {
			// 信号会打断阻塞的系统调用
			if (errno == EINTR) {
				continue;
			}
			perror("select()");
			goto ERROR;
		}

		// 判断是哪个集合事件发生了
		if (pfd[0].revents & POLLIN || pfd[1].revents & POLLOUT)
			fsm_drive(fsm12);
		if (pfd[1].revents & POLLIN || pfd[0].revents & POLLOUT)
			fsm_drive(fsm21);
	}

	fsm_destroy(&fsm12);
	fsm_destroy(&fsm21);

	close(fd1);
	close(fd2);

	return 0;
ERROR:
	close(fd1);
	close(fd2);
	exit(1);
}


