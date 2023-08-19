#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
		return -1;

	FILE *fp;
	char s[10];
	int size = 10;


	fp = fopen(argv[1], "r");
	
	while(1)
	{
		if(NULL == fgets(s, size, fp))
			break;
		fputs(s, stdout);
		sleep(1);
		fflush(stdout);
	}

	fclose(fp);

	return 0;

}
