#include<stdio.h>
#include<string.h>

int my_strlen(const char *p);
char *my_strncpy(char *p, const char *s, int n);
char *my_strcat(char *p, const char *s, int n);
int my_strcmp(const char *p, const char *s);
char *my_strchr(const char *p, int n);
char *my_strstr(const char *p, const char *s);

int main()
{	
	char s[] = "hello word";
	char a[5];
	char b[5] = "we"; 
	char d[] = "hello word";
	char f[] ="word";
	int n = 'e';
	
	printf("str:%c\n", *(my_strstr(d, f)));
	puts(my_strstr(d, f));
	printf("%c\n",*(my_strchr(s, n)));
	printf("len:%d\n", my_strlen(s));
	my_strncpy(a, s, 4);
	printf("%c\n", a[1]);
	puts(a);
	my_strcat(b, s, 2);
	puts(b);
	printf("cmp:%d\n", my_strcmp(s, d));

	return 0;
}

int my_strlen(const char *p)
{
	int i;

	for(i = 0; p[i]; i++)
	{}	
		return i;
}

char *my_strncpy(char *p, const char *s, int n)
{
	int i;

	for(i = 0; s[i] && i < n; i++)
	{
		p[i] = s[i];
	}
	p[i] = '\0';

	return p;
}

char *my_strcat(char *p, const char *s, int n)
{
	int len, i;

	len = my_strlen(p);

	for(i = 0; s[i] && i < n; i++)
	{
		p[len + i] = s[i];
	}

	p[len + i] = '\0';

	return p;
}

int my_strcmp(const char *p, const char *s)
{
	int i, res;

	i = 0;
	res = 0;

	while(!res || !(s[i] == 0 && p[i] == 0)){
		res  = p[i] - s[i];
		i++;
	}
	if(s[i] == '\0' && p[i] == '\0')
		return 0;
	else 
		return res;
}

char *my_strchr(const char *p, int n)
{
	int i;

	for(i = 0; p[i]; i++)
	{
		if(*p == n)
			break;
		p++;
	}
	printf("s[%d]\n", i);

	return  (char *) p;
}

char *my_strstr(const char *p, const char *s)
{
	int i, j, pos, mid;
	
	
	j = 0;
	pos = 0;
	for (i = 0; i < my_strlen(p); i++)
	{
		if(p[i] == s[j])
		{	
			mid = i;
			pos = 1;
			for(j; s[j]; i++,j++)
			{
				if(p[i] != s[j])
					pos = 0;

			}
		}
	
	}

	if(pos)
		return (char *) &p[mid];
	else
		return NULL;
}
