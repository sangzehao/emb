#include <stdio.h>

#include "myls.h"

#define PATHSIZE 512

static int my_ls_l(const char *path);
static int show_name(const char *path);

int main(int argc, char *argv[])
{
	const char *optstring = "-l::a::";
	
	char pathname[PATHSIZE];
	int c;
	int flag = 0;

	getcwd(pathname, PATHSIZE);

	while(1){
		c = getopt(argc, argv, optstring);
		if(-1 == c)
		{
			if(flag == 0)
			{
				show_name(pathname);
			}
			break;//读完了
		}
		switch(c)
		{
			case 'l':
				flag = 1;
				if(optarg)
					my_ls_l(optarg);
				else
					my_ls_l(pathname);
				break;
			case '?':
				flag = 1;
				printf("?\n");
				break;
			default:
				break;
		}
	
	}

}

static int show_name(const char *path)
{
	DIR *dir;
	struct dirent *entry;

	if(path == NULL)
		return 1;
	
	dir = opendir(path);

	while(1)
	{
		entry = readdir(dir);
		if(NULL == entry)
		{
			if(errno)
			{
				perror("entry");
				goto ERROR;
			}
			break;
		}
		if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;
		printf("%s  ", entry->d_name);
	}
	printf("\n");

	closedir(dir);
	return 0;

ERROR:
	printf("\n");
	closedir(dir);
	return -1;
}

static int my_ls_l(const char *path)
{
	struct stat s;
	DIR *dir;
	struct dirent *entry;
	char mypath[PATHSIZE];

	if(NULL == path)
		return 1;
	
	if(-1 == stat(path, &s))
	{
		perror("stat()");
		return 1;
	}	
	
	ergodic(path);
	if(!S_ISDIR(s.st_mode))
	{
		p_ls_l(path);		
		return 1;
	}
	
	dir = opendir(path);
	
	while(1)
	{
	char pathname[PATHSIZE];
		entry = readdir(dir);
		if(NULL == entry)
		{
			if(errno)
				goto ERROR;
			break;
		}
		if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;
		memset(mypath, '\0', PATHSIZE);
		strncpy(mypath, path, PATHSIZE);
		strncat(mypath, "/", PATHSIZE - strlen(mypath));
		strncat(mypath, entry->d_name, PATHSIZE - strlen(mypath));
		p_ls_l(mypath);		
	}

	closedir(dir);
	return 0;

ERROR:
	closedir(dir);	
	return 1;	
}
