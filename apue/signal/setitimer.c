#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/time.h>

#define BUFSIZE	32
#define CPS		10

// 权限
static int token;

static void alrm_handler(int s);

int main(int argc, char *argv[]/*char **argv*/)
{
	int fd;
	char buf[BUFSIZE] = {};
	int cnt;
	struct itimerval tim;

	if (argc < 2)
		return 1;
		
	tim.it_interval.tv_usec = 0;//间隔时间，执行这个函数时，多长时间产生一次信号
	tim.it_interval.tv_sec = 100;
	tim.it_value.tv_sec = 0;
	tim.it_value.tv_usec = 500000;//第一次是闹钟，什么时候开始执行这个函数
	
	setitimer(ITIMER_REAL, &tim, 0);

	// 注册SIGALARM的行为
	signal(SIGALRM, alrm_handler);
	// 定义闹钟1s
//	alarm(1);

	// 打开
	fd = open(argv[1], O_RDONLY);
	if (-1 == fd) {
		return -1;		
	}

	// cat
	while (1) {
		// 流量控制 ---> 当token为1的时候才有权限读文件
		while (token == 0)
			// 等待信号到来--->轮询
			;
		token = 0;

		// 重复使用buf，建议buf清理干净，防止有脏数据	
		memset(buf, 0, BUFSIZE);
		cnt = read(fd, buf, CPS);
		if (0 == cnt) {
			// 读完了
			break;
		} else if (-1 == cnt) {
			// 出错了
			goto ERROR;
		}
		// 成功了
		write(1, buf, cnt); // 注意读多少写多少
	}

	close(fd);

	return 0;
ERROR:
	close(fd);
	return 1;
}

/*
 SIGALRM注册一个行为
 	控制是否有权限输出
 */
static void alrm_handler(int s)
{
	token = 1;
}




