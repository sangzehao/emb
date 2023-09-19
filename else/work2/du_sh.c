#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>

#define BUFSIZE 2048

int _ergodic(const char *pathname, long *bl_num);
int du_h(long *bl_num);

int main(int argc, char *argv[])
{
	int pos = 0;
	long bl_num = 0;
	char unity[] = {'B', 'K', 'M', 'G'};


	if(argc < 2)
		return 1;
	
	_ergodic(argv[1], &bl_num);

	pos = du_h(&bl_num);

	printf("%ld%c\t\t%s\n", bl_num, unity[pos], argv[1]);
	

}

int _ergodic(const char *pathname, long *bl_num)
{
	struct stat s;
	DIR *dir = NULL;
	struct dirent *entry;
	char buf[BUFSIZE] = {};

	if(NULL == pathname)
		return 1;
	if(-1 == stat(pathname, &s))
	{
		perror("stat()");
		return 1;
	}

	*bl_num += s.st_blocks;
	
	if(!S_ISDIR(s.st_mode))
		return 1;

	dir = opendir(pathname);
	if(NULL == dir)
	{
		perror("opendir()");
		return -1;
	}
	
	while(1)
	{
		entry = readdir(dir);
		
		if(NULL == entry)
		{
			if(errno)
				goto ERROR;
			break;
		}
		if(strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0)
			continue;
		memset(buf, '\0', BUFSIZE);
		strncpy(buf, pathname, BUFSIZE);
		strncat(buf, "/", BUFSIZE - strlen(buf));
		strncat(buf, entry->d_name, BUFSIZE - strlen(buf));
		_ergodic(buf, bl_num);
		
	}
	
	closedir(dir);
	return 0;

ERROR:
	closedir(dir);
	return 1;	
}

int du_h(long *bl_num)
{
	int u = 0;

	*bl_num  = *bl_num * 512;
	

	while(*bl_num >= 1024)
	{
		*bl_num = *bl_num / 1024;
		u++;
	}

	return u;
}
