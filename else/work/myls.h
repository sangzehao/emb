#ifndef __MYLS_H__
#define __MYLS_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <errno.h>
#include <pwd.h>
#include <grp.h>
#include <time.h>


int ergodic(const char *pathname);//计算总用量
int p_ls_l(const char *path);//ls -l

#endif
