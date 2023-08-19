#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	if(argc < 3)
		return -1;

	FILE *fp, *wp;
	char *lineptr = NULL;
	size_t size = 0;

	fp = fopen(argv[1], "r");
	wp = fopen(argv[2], "w");

	if(fp == NULL & wp == NULL)
		return -1;

	while(1)
	{
		if(-1 == getline(&lineptr, &size, fp))
			break;
		fputs(lineptr, wp);
	}

	free(lineptr);
	lineptr = NULL;
	fclose(fp);
	fclose(wp);

	return 0;
}
