#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int s)
{
	write(1, "!", 1);
}

int main (void)
{
	sigset_t set, oldset;
	int i, j;
	struct sigaction act, oldact;

	act.sa_handler = sig_handler;
	act.sa_flags = 0;
	act.sa_mask = set;

	if(-1 == sigaction(SIGINT, &act, &oldact))
	{
		perror("sigation_int");
		return -1;
	}

	if(-1 == sigaction(SIGRTMIN, &act, &oldact))
	{
		perror("sigation_MIN");
		return -1;
	}

//	signal(SIGINT, sig_handler);
//	signal(SIGRTMIN, sig_handler);

/*	sigemptyset(&set);

	sigaddset(&set, SIGINT);//标准信号，被屏蔽的时候，发多次，只显示一次
	sigaddset(&set, SIGRTMIN);//实时信号，在排队，发10次信号显示10次

	sigprocmask(SIG_BLOCK, &set, &oldset);
*/	for(i = 0; i < 10; i++)
	{
		for(j = 0; j < 5; j++)
		{
			write(1, "*", 1);
			//sleep(1);
		}
		write(1, "\n", 1);
	/*	sigprocmask(SIG_SETMASK, &oldset, NULL);
		pause();
		sigprocmask(SIG_BLOCK, &set, &oldset);
	*/
		sigprocmask(SIG_SETMASK, &oldset, NULL);
		pause();
		sigprocmask(SIG_BLOCK, &set, NULL);
//		sigsuspend(&oldset);
	}

	return 0;
}
