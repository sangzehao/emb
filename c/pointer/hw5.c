#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int opera_fun(const char *argv, char **s, char *p);
int myatoi(const char *p);

int main(int argc, char *argv[])
{
	char *p = NULL;

	printf("%c %c %c = %d\n", (*argv)[1], *p, (*argv)[3], opera_fun(*argv, argv, p));

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
int opera_fun(const char *argv, char **s, char *p)
{
	int res;

	switch (argv[2]){
		case '+':
			*p = '+';
			res = myatoi((*s)[1]) + myatoi((*s)[3]);
			break;
		case '-':
			*p = '-';
			res = myatoi((*s)[1]) - myatoi((*s)[3]);
			break;
	/*	case 'x':
			*p = 'x';
			res = myatoi(argv[1]) * myatoi(argv[3]);
			break;
		case '\\':
			*p = '\\';
			res = myatoi(argv[1]) \ myatoi(argv[3]);
			break;
	}
*/}	
	return res;
}
