#include <stdio.h>
#include <signal.h>
#include <unistd.h>

static void sig_handler(int s)
{
	write(1, "!", 1);
}

int main(void)
{
	sigset_t set, oldset;
	int i, j;

	signal(SIGINT, sig_handler);

	sigemptyset(&set);

	sigaddset(&set, SIGINT);

	for(i = 0; i < 5; i++)
	{
		sigprocmask(SIG_BLOCK, &set, &oldset);
		for(j = 0; j < 3; j++)
		{
			write(1, "*", 1);
			sleep(1);
		}
		printf("\n");
		sigprocmask(SIG_SETMASK, &oldset, NULL);
	}

	return 0;
}
