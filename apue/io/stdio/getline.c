#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
		return -1;

	FILE *fp;
	char *lineptr = NULL;
	size_t size = 0;

	fp = fopen(argv[1], "r");

	if(NULL == fp)
		return -1;

	while(1)
	{
		printf("size:%ld\n", size);
		if( -1 == getline(&lineptr, &size, fp))
			break;
		fputs(lineptr, stdout);
		sleep(1);
		fflush(stdout);
	}
	free(lineptr);
	lineptr = NULL;
	fclose(fp);

	return 0;
}
