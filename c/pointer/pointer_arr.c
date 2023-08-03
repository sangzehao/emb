#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(int argc, char *argv[])
{
	int i;

	char *arr[] = {"saf", "fsdaf", "dfsa", "rwe"};
	srand(time(NULL));
	i = rand() % (sizeof(arr) / sizeof(char *));
//	printf("a[i]:%s\n", arr[i]);

	printf("argc:%d\n", argc);	
	for(i = 0; i < argc; i++)
	{
		printf("**%d %s\n", i, argv[i]);
	}
//	printf('\n');
	
	return 0;
}
