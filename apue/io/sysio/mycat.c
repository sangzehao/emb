#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>

#define BUFSIZE 2

int main(int argc, char *argv[])
{
	if(argc < 2)
		return 0;

	int fp;
	char buf[BUFSIZE];
	int cnt;

	fp = open(argv[1], O_RDONLY);
	if(-1 == fp)
		return -1;
	
	while(1)
	{
		memset(buf, 0, BUFSIZE);
		cnt = read(fp, buf, BUFSIZE);
		if(0 == cnt)
			break;
		else if(-1 == cnt)
		{
			goto ERROR;
		}

		write(1, buf, cnt);
		sleep(1);
	}

	close(fp);

	return 0;

ERROR:
	close(fp);
	return 1;
}
