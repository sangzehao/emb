#include <stdio.h>
#include <unistd.h>

#define PATHSIZE 512

int main(int argc, char *argv[])
{
	const char *optstring = "-l::a::";
	
	char pathname[PATHSIZE];
	int c;

	getcwd(pathname, PATHSIZE);

	while(1){
		c = getopt(argc, argv, optstring);
		if(-1 == c)
			break;//读完了
		switch(c)
		{
			case 'l':
				if(!optarg)
					my_ls_l(optarg)
				else
					my_ls_l(pathname);
				break;
			case '?':
				printf("?\n");
				break;
			default:
				break;
		}
	
	}

}

static int __ls_l(const char* path)
{ 
	struct stat s;

}

int my_ls_l(const char *path)
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
	
	if(!S_ISDIR(s.st_mode))
	{
		__ls_l(path);
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
		memset(mypath, '\0', PATHSIZE);
		strncpy(mypath, path, PATHSIZE);
		strncat(mypath, "/", PATHSIZE - strlen(mypath));
		strncat(mypath, entry->d_name, PATHSIZE - strlen(mypath));
		__ls_l(mypath);	
	}

	closedir(dir);
	return 0;

ERROR:
	closedir(dir);	
	return 1;	
}
