#include <stdio.h>

int main(void)
{
	char c;

	printf("shuru\n");
	scanf("%c", &c);

	switch(c)
	{
		case 'A':
		case 'a':
			printf("1\n");
			break;
		case 'B':
		case 'b':
			printf("2\n");
			break;
		case 'C':
		case 'c':
			printf("3\n");
			break;
		case 'D':
		case 'd':
			printf("4\n");
			break;
	}
	return 0;
}
