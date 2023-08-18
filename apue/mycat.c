#include<stdio.h>

int main(int argc, char *argv[])
{
	FILE *fp = NULL;
	int c;

	if(argc < 2)
		return -1;
	
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
	}

	fclose(fp);

	return 0;
}
