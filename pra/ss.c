#include<stdio.h>

int chg(char s[], int n, int end);

int main(void)
{
	char s[5] = "1111";
	
	printf("%d\n", chg(s, 0, 3));
	return 0;
}

int chg(char s[], int n, int end)
{
	if(n == end)
		return 1;
	else
		return 2 * chg(s, n + 1, end);
}
