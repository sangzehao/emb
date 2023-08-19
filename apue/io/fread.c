#include<stdio.h>
#include<unistd.h>

int main(int argc, char *argv[])
{
	if(argc < 2)
		return -1;

	FILE *fp;
	size_t size = 2;
	size_t nmemb = 2;
	char s[10];

	fp = fopen(argv[1], "r");

	fseek(fp, 4, SEEK_SET);
	rewind(fp);

	if(NULL == fp)
		return -1;
	while(1)
	{
		if(0 == fread(s, size, nmemb, fp))
			break;
		fwrite(s, size, nmemb, stdout);
		sleep(1);
		fflush(stdout);
	}

	fclose(fp);
	return 0;
}
