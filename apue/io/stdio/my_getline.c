#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<stdlib.h>

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream);

int main(int argc, char *argv[])
{
	if(argc < 2)
		return -1;

	char s[100];
	FILE *fp;
	char *lineptr = NULL;
	int c;
	size_t n = 0;
	ssize_t ret;

	fp = fopen(argv[1], "r");

	while(1)
	{
		ret = my_getline(&lineptr, &n, fp);		
		if( -1 == ret)
			break;
		if(-2 == ret)
		{
			fputs(lineptr, stdout);
		}	
	//	fseek(fp, n, SEEK_SET);
	//	n = 0;
	}

	free(lineptr);
	lineptr = NULL;

/*	while(1)
	{
		c = fgetc(fp);
		if(c == EOF)
		{
			if(ferror(fp))
				printf("error\n");
			break;
		}
		s[count] = c;
		count++;
		if(c == '\n')
		{
			s[count] = '\0';
			fputs(s, stdout);
			memset(s, '\0', 100);
			count = 0;
			sleep(1);
			fflush(stdout);
		}	
	}
*/
	fclose(fp);

	return 0;

}

ssize_t my_getline(char **lineptr, size_t *n, FILE *stream)
{
	*lineptr = realloc(*lineptr, *n);
		
	int c;
	int count = 0;
	
	while(1)
	{
		if(count == *n)
		{
			*lineptr = realloc(*lineptr, (*n + 1) * sizeof(char));
			n++;
		}
		c = fgetc(stream);
		if(EOF == c)
		{
		//	if(ferror(stream))
		//		printf("error\n");
			printf("***************************\n");
		//	break;
			return -1;
		}
		if(c == '\n')
		{
			//c = '\0';
			memcpy((char *)(*lineptr) + count - 1, &c, sizeof(char));
			c = '\0';
			
			memcpy((char *)(*lineptr) + count, &c, sizeof(char));
		//	c = '\n';
		//	memcpy((char *)(*lineptr) + count + 1, &c, sizeof(char));
			return -2;
			//*n = count;
//			return -2;
		}
		memcpy((char *)(*lineptr) + count, &c, sizeof(char));
		count++;
	/*	if(EOF == c)
		{
		//	if(ferror(stream))
		//		printf("error\n");
			return EOF;
		}
	*/
	}
	
	return 0;
}
