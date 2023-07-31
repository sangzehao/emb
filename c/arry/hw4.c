#include<stdio.h>

int main(void)
{
	char s[100];
	int i, j, count, pos;
	
	count == 0;
	printf("输入：");
	for(i = 0; i < 99; i++)
	{
		scanf("%c", &s[i]);
		if(s[i] == '\n')
			break;
	}
		s[i] = '\0';
	for(i = 0; s[i]; i++)
	{
		pos = 1;
		if(((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) && ( i == 0 || s[i - 1] == ' ' || s[i - 1] == 39))
		{
			while(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' && s[i])
			{
				i++;
			}
		//	j = i;
			i--;
			count++;
			pos = 0;
/*			while(s[j] != ' ' && !(s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z'))
			{
				j++;
			}
			if(s[j] >= 'a' && s[j] <= 'z' || s[j] >= 'A' && s[j] <= 'Z')
				count--;
		*/
		}else if(((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) && !( i == 0 || s[i - 1] == ' ') && pos == 0)
		{
		count--;
		pos = 1;
			while(s[i] >= 'a' && s[i] <= 'z' || s[i] >= 'A' && s[i] <= 'Z' && s[i])
			{
				i++;
			}
			i--;
		}
	}

	printf("count:%d\n", count);

	return 0;
}
