#include "fsm.h"

int fsm_init(fsm_t **fsm, int rfd, int wfd)
{
	int old_rfd_flag, old_wfd_flag;	
	
	*fsm = malloc(sizeof(fsm_t));

	if(NULL == *fsm)
		return 1;
	
	(*fsm)->rfd = rfd;
	(*fsm)->wfd = wfd;
	(*fsm)->state = STATE_R; //都从读状态开始
	(*fsm)->read_cnt = 0;
	(*fsm)->write_cnt = 0;
	memset((*fsm)->buf, 0, BUFSIZE);
	(*fsm)->errmsg = NULL;

	/*
	   	调用者若想要以状态机的方式运行，
		他只需要保证两个文件描述符是对的即可，
	  	不需要他们的状态是非阻塞的，
		让他们状态是非阻塞的是编写者的工作
	 */
	
	//先获取旧状态，后边追加新的
	old_rfd_flag = fcntl((*fsm)->rfd, F_GETFL);
	old_wfd_flag = fcntl((*fsm)->wfd, F_GETFL);
	//追加
	fcntl((*fsm)->rfd, F_SETFL, old_rfd_flag | O_NONBLOCK);
	fcntl((*fsm)->wfd, F_SETFL, old_wfd_flag | O_NONBLOCK);
		
	return 0;
}

int fsm_drive(fsm_t *fsm)
{
	switch(fsm->state)
	{
		case STATE_R://去读
			fsm->read_cnt = read(fsm->rfd, fsm->buf, BUFSIZE);
			
			if(-1 == fsm->read_cnt)
			{
				if(errno != EAGAIN)
				{
					fsm->state = STATE_E;
					fsm->errmsg = "read()";
				}
			}else if(fsm->read_cnt > 0)
			{
				fsm->state = STATE_W;
				fsm->write_cnt = 0;
			}else{
				fsm->state = STATE_T;
			}
			break;
		case STATE_W:
			fsm->write_cnt += write(fsm->wfd, fsm->buf + fsm->write_cnt, fsm->read_cnt - fsm->write_cnt);
			if(fsm->write_cnt < fsm->read_cnt)
			{
				fsm->state = STATE_W;
			}else if(fsm->write_cnt == fsm->read_cnt)
			{
				fsm->read_cnt = 0;
				fsm->write_cnt = 0;
				fsm->state = STATE_R;
			}else{
				fsm->state = STATE_E;
				fsm->errmsg = "write()";
			}
			break;
		case STATE_E:
			perror(fsm->errmsg);
			fsm->state = STATE_T;
			break;
		case STATE_T:
			break;
	}		
}

void fsm_destroy(fsm_t **fsm)
{
	free(*fsm);
	*fsm = NULL;
}
