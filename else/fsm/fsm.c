#include "fsm.h"

int fsm_init(fsm_t **fsm, int rfd, int wfd)
{
	*fsm = malloc(sizeof(fsm_t));

	if(NULL == *fsm)
	{
		perror("malloc()");
		return 1;
	}

	(*fsm)->rfd = rfd;
	(*fsm)->wfd = wfd;
	(*fsm)->read_cnt = 0;
	(*fsm)->write_cnt = 0;
	(*fsm)->state = STATE_R;
	(*fsm)->errmsg = NULL;
	memset((*fsm)->buf, 0, BUFSIZE);
	
	return 0;
}

int fsm_driver(fsm_t *fsm)
{
	switch(fsm->state)
	{
		case STATE_R://到读状态了，去读
			fsm->read_cnt = read(fsm->rfd, fsm->buf, BUFSIZE);
			if(-1 == fsm->read_cnt){
				if(errno != EAGAIN)//非堵塞造成的假错
				{
					fsm->state = STATE_E;
					fsm->errmsg = "read()";
				}
			}else if(0 == fsm->read_cnt){
				fsm->state = STATE_T;
			}else{
				fsm->state = STATE_W;
			}
			break;
		case STATE_W:
			fsm->write_cnt += write(fsm->wfd, fsm->buf, fsm->read_cnt - fsm->write_cnt);
			if(-1 == fsm->write_cnt){
				fsm->errmsg = "wrtie()";
				fsm->state = STATE_E;
			}else if(fsm->write_cnt < fsm->read_cnt){
				fsm->state = STATE_W;
			}else{
				fsm->read_cnt = 0;
				fsm->write_cnt = 0;
				fsm->state = STATE_T;
			}
			break;
		case STATE_E:
			perror(fsm->errmsg);
			fsm->state = STATE_T;
			break;
		case STATE_T:
			break;
	}

	return 0;
}

void fsm_destroy(fsm_t **fsm)
{
	free(*fsm);
	*fsm = NULL;
}
