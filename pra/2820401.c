#include<stdio.h>

//ip地址转换
int chg(char s[], int j, int end);
int bin_dec(char s[], int n);

int main(void)
{
	char a[33];
	int i;

	printf("输入二进制ip地址：\n");
	for(i = 0; i < 32; i++)
	{
		scanf("%c", &a[i]);
	}
	a[i] = '\0';
	puts(a);
	for(i = 0; i < 32; i += 8)
	{
		printf("%d.", bin_dec(a, i));
	}
	printf("\n");	
			
	return 0;
}

int chg(char s[], int j, int end)
{
	if(j != end)
	{
		return 2 * chg(s, j + 1, end);
	}else{
		return 1;
	}
}

int bin_dec(char s[], int n)
{
	int sum, t, count;
	
	sum = 0;
	t = n;

	for(count = 0; count < 8; count++)//8位的和
	{
		sum += (s[n] == '1') * chg(s, n, t + 7);
		n++;
	}

	return sum;

}
