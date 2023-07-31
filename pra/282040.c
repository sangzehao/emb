#include<stdio.h>

int chg(char s[], int j, int end);
int lk(char s[], int i);

int main(void)
{
	char a[33];
	int i, n, num;

	for(i = 0; i < 32; i++)
	{
		scanf("%c", &a[i]);
	}
	a[i] = '\0';

	puts(a);
	for(i = 0; i < 32; i += 8)
	{
		printf("%d.", lk(a, i));
	}
	printf("\n");

	return 0;
}

int chg(char s[], int j, int end)
{
	if(j != end)
	{
		return 2 * chg(s, j + 1, end);
	}else if(j == end)
	{
		return 1;
	}
}
int lk(char s[], int i)
{
	int count = 0;
	int sum = 0;
	int t = i;

	for(count; count < 8; count++)
	{
		sum +=  (s[i] == '1') * chg(s, i, t + 7);
		i++;
	}

	return sum;
}
