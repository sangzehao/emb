#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

static void signal_handler(int s)
{
	write(1, "!", 1);
}

int main(void)
{
	sigset_t set, oldset;
	int i, j;

	signal(SIGRTMIN, signal_handler);

	sigemptyset(&set);

	sigaddset(&set, SIGRTMIN);

	for(i = 0; i < 5; i++)
	{
		sigprocmask(SIG_BLOCK, &set, &oldset);

		for(j = 0; j < 3; j++)
		{
			write(1, "*", 1);
			sleep(1);
		}
		sigprocmask(SIG_SETMASK, &oldset, NULL);
	}
	
	return 0;	
}
