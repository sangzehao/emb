#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h> 
#include <pwd.h>
#include <string.h>
#include <grp.h>
#include <sys/sysmacros.h>
#include <time.h>

#define MAXSIZE 64

blksize_t file_io_blocks(struct stat res);
blkcnt_t file_blocks(struct stat res);
off_t file_size(struct stat res);
uid_t file_uid(struct stat res);
int file_gid_name(struct stat res, gid_t *gid, char **g_name);
dev_t file_dev(struct stat res, int *dev_h, int *dev_d);
static int __time_change(struct timespec tim, char *buf, int size);
int get_file_atime(struct stat res, char *buf, int size);
int get_file_mtime(struct stat res, char *buf, int size);
int get_file_ctime(struct stat res, char *buf, int size);
char *file_type(struct stat res);
int ctoi(char *num);
int file_mode(struct stat res, int *n, char **mode);
int dtoh(int num, int *sum);

int main(int argc, char *argv[])
{
	struct stat s;
	struct passwd *p = NULL;
	uid_t uid;
	char *g_name = NULL;
	gid_t gid;
	int dev_d, dev_h;
	char buf[MAXSIZE];
	char *mode = NULL;
	int n;

	if(argc < 2)
		return -1;
	if(-1 == stat(argv[1], &s))
	{
		perror("stat()");
		return -1;
	}

	uid = file_uid(s);
	p = getpwuid(uid);//返回的是静态区，不用释放
	
	file_gid_name(s, &gid, &g_name);//用的是堆空间存储信息，得释放
	file_dev(s, &dev_h, &dev_d);
	file_mode(s, &n, &mode);

	printf("文件：%s\n", argv[1]);
	printf("大小：%ld\t\t块：%ld\t\tIO块：%ld\t\t %s\n", file_size(s), file_blocks(s), file_io_blocks(s), file_type(s));
	printf("设备：%dh/%dd\t\t", dev_h, dev_d);
	printf("Inode:%ld\t\t硬链接:%ld\n", s.st_ino, s.st_nlink);
	printf("权限:(0%d / %s)\t\t", n, mode);
	printf("uid:( %d/ %s)\t", uid, p->pw_name);
	printf("group: ( %d/ %s)\n", gid, g_name);
	get_file_atime(s, buf, MAXSIZE);	
	printf("最近访问：%s\n", buf);
	get_file_mtime(s, buf, MAXSIZE)	;
	printf("最近更改：%s\n", buf);
	get_file_ctime(s, buf, MAXSIZE)	;
	printf("最近改动：%s\n", buf);

	//free(p);
	//p = NULL;
	
	free(g_name);
	g_name = NULL;
	free(mode);
	mode = NULL;

	return 0;
}

off_t file_size(struct stat res)
{
	return res.st_size;
}

blkcnt_t file_blocks(struct stat res)
{
	return res.st_blocks;
}

blksize_t file_io_blocks(struct stat res)
{
	return res.st_blksize;
}

dev_t file_dev(struct stat res, int *dev_h, int *dev_d)
{
	int sum = 0;
	dev_t dev = res.st_dev;
	*dev_d = dev;
	*dev_h = dtoh(dev, &sum);
	*dev_h = sum * 10 + *dev_h; 

	return dev;
}

int dtoh(int num, int *sum)
{
	int mod = 0;
	int mid;
	
	if(num)
	{
		mod = num % 16;
		num = num / 16;
		mid = dtoh(num, sum);
		*sum = *sum * 10 + mid;	
	}

	return mod;
}

uid_t file_uid(struct stat res)
{
	return res.st_uid;
}
int file_gid_name(struct stat res, gid_t *gid, char **g_name)
{
	struct group *gp = NULL;
	*gid = res.st_gid;

	gp = getgrgid(*gid);

	if(NULL == gp)
		return -1;

	*g_name = malloc(sizeof(char *));
	strcpy(*g_name, gp->gr_name);

	return 0;

}

static int __time_change(struct timespec tim, char *buf, int size)
{
	struct tm *temp;

	temp = localtime(&tim.tv_sec);
	if(NULL == temp)
		return -1;
	strftime(buf, size, "%Y-%m-%d %H-%M-%S", temp);

	return 0;
}

int get_file_atime(struct stat res, char *buf, int size)
{
	__time_change(res.st_atim, buf, size);
}
int get_file_mtime(struct stat res, char *buf, int size)
{
	__time_change(res.st_mtim, buf, size);
}
int get_file_ctime(struct stat res, char *buf, int size)
{
	__time_change(res.st_ctim, buf, size);
}


char *file_type(struct stat res)
{
	char *s = malloc(10 * sizeof(char)); 

	switch(res.st_mode & S_IFMT)
	{	
		case S_IFSOCK:
			strcpy(s,"套接字");
			break;			
		case S_IFLNK:
			strcpy(s, "链接");
			break;			
		case S_IFREG:
			strcpy(s, "普通");
			break;			
		case S_IFBLK:
			strcpy(s, "块");
			break;			
		case S_IFDIR:
			strcpy(s, "目录");
			break;			
		case S_IFCHR:
			strcpy(s, "字符");
			break;			
		case S_IFIFO:
			strcpy(s, "管道");
			break;			
	}
	return s;
}

int file_mode(struct stat res, int *n, char **mode)
{
	char *num = NULL;
	int i;
	int all_mode[] = {S_IRUSR, S_IWUSR, S_IXUSR, S_IRGRP, S_IWGRP, S_IXGRP, S_IROTH, S_IWOTH, S_IXOTH};
	*mode = calloc(10, sizeof(char));
	if(*mode == NULL)
		return -1;
	num = calloc(10, sizeof(char));
	if(NULL == num)
	{
		free(*mode);
		*mode = NULL;
		return -1;
	}
	strncpy(*mode, "rwxrwxrwx", 10);
	strncpy(num, "111111111", 10);
	for(i = 0; i < 9; i++)
	{
		if(!(res.st_mode & all_mode[i]))
		{
			(*mode)[i] = '-';
			num[i] = '0';
		}
	}

	*n = ctoi(num);
	free(num);
	num = NULL;

	return 0;
}

int ctoi(char *num)
{
	int p = 0;
	int sum = 0;
	int i, j;
	int t;

	for(i = 0; i < 9; i++)
	{
		j = 0;
		p = 0;
		for(j; j < 3; j++)
		{
			t = num[i] - '0';
			p = p * 2 + t;
			i++;
		}
		i--;
		sum  = sum * 10 + p;
	}
	return sum;
}

