#include <stdio.h>
#include <time.h>
#include <stdlib.h>

#define MAXSIZE 32

int main(int argc, char *argv[])
{
	time_t curr_time;
	struct tm *tmp;
	char buf[MAXSIZE];

	time(&curr_time);
	
	tmp = localtime(&curr_time);
	if(NULL == tmp)
	{
		return -1;
	}


	tmp->tm_mday = tmp->tm_mday + atoi(argv[1]);
	curr_time = mktime(tmp);
	tmp = localtime(&curr_time);
	
	

	strftime(buf, 32, "%Y-%m-%d %H:%M:%S", tmp);

	printf("%s\n", buf);

	
	return 0;
}
