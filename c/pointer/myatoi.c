#include<stdio.h>

int myatoi(const char *p);

int main(int argc, char *argv[])
{
	if(argc < 2)
		return 1;
	printf("sizeof:%ld\n", sizeof(*argv));
	printf("%d\n", myatoi(argv[1]));

	return 0;
}

int myatoi(const char *p)
{
	int i, res;

	res = 0;
	
	for(i = 0; p[i]; i++)
	{
		res = res * 10 + (p[i] - '0');
	}

	return res;
}
