#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void sig_handl(int s)
{
	write(1, "!", 1);
}

int main(void)
{
	sigset_t set, oldset;
	struct sigaction act, oldact;
	int i, j;

	act.sa_handler = sig_handl;
	act.sa_flags = 0;
	sigaction(SIGINT, &act, &oldact);

	//signal(SIGINT, sig_handler);
	sigemptyset(&set);

	sigaddset(&set, SIGINT);
	
	sigprocmask(SIG_BLOCK, &set, &oldset);
	for(i = 0; i < 5; i++)
	{
		for(j = 0; j < 5; j++)
		{
			write(1, "*", 1);
			sleep(1);
		}
		write(1, "\n", 1);
		sigsuspend(&oldset);
	}

	return 0;

}
