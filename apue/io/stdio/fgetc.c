#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
		return -1;

	FILE *fp;
	int c;
	
	fp = fopen(argv[1], "r");
	
	if(NULL == fp)
		return -1;

	while(1)
	{
		c = fgetc(fp);
		if(EOF == c)
		{
			if(ferror(fp))
				printf("error\n");
			break;
		}
		fputc(c, stdout);
		sleep(1);//休眠一秒
		fflush(stdout);//刷新缓存区
	}

	fclose(fp);
//	fclose(wfp);

	return 0;
}
