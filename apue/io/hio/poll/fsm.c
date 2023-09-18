#include <stdlib.h>
#include <errno.h>
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#include "fsm.h"

int fsm_init(fsm_t **fsm, int rfd, int wfd)
{
	int rfd_old_flag, wfd_old_flag;

	fsm_t *me = malloc(sizeof(fsm_t));
	if (NULL == me)
		return -1;
	me->rfd = rfd;
	me->wfd = wfd;
	memset(me->buf, '\0', BUFSIZE);
	me->read_cnt = 0;
	me->state = STATE_R;
	me->errmsg = NULL;
	me->write_cnt = 0;

	// 确定状态机的文件都是非阻塞的
	rfd_old_flag = fcntl(me->rfd, F_GETFL);
	fcntl(me->rfd, F_SETFL, rfd_old_flag | O_NONBLOCK);

	wfd_old_flag = fcntl(me->wfd, F_GETFL);
	fcntl(me->wfd, F_SETFL, wfd_old_flag | O_NONBLOCK);

	*fsm = me;

	return 0;
}

int fsm_drive(fsm_t *fsm)
{
	int ret;
	// 根据当前状态机的状态，满足的条件推到下一个状态
	switch (fsm->state) {
		case STATE_R:
			fsm->read_cnt = read(fsm->rfd, fsm->buf, BUFSIZE);
			if (fsm->read_cnt == 0) {
				// eof
				fsm->state = STATE_T;
			} else if (fsm->read_cnt == -1) {
				if (errno != EAGAIN) {
					// 不是假错
					fsm->state = STATE_E;
					fsm->errmsg = "read()";
				}
			} else {
				// 读成功了
				fsm->state = STATE_W;
				fsm->write_cnt = 0;
			}
			break;
		case STATE_W:
			// 读多少写多少
			ret = write(fsm->wfd, fsm->buf + fsm->write_cnt, fsm->read_cnt);
			if (-1 == ret) {
				fsm->state = STATE_E;
				fsm->errmsg = "write()";
			} else {
				// 没写完
				if (ret < fsm->read_cnt) {
					fsm->write_cnt += ret;	
					fsm->read_cnt -= ret;
				} else {
					// 写完了
					fsm->state = STATE_R;
				}
			}
			break;
		case STATE_E:
			perror(fsm->errmsg);
			fsm->state = STATE_T;
			break;
		case STATE_T:
			// 保留
			break;
	}

	return 0;
}

void fsm_destroy(fsm_t **fsm)
{
	free(*fsm);
	*fsm = NULL;
}

