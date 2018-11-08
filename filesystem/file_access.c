/*************************************************************************
	> File Name: file_access.c
	> Author: AlekXu
	> Mail: alekxu@163.com 
	> Created Time: 2018年11月08日 星期四 10时00分28秒
 ************************************************************************/

//int access(const char *pathname,int mode)
//pathname:文件的路径名
//mode:R_OK/W_OK/X_OK/F_OK
//返回值：success:0;failed:-1

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

int main(int argc,char **argv)
{
	if(argc != 2)
	{
		printf("参数太少\n");
		exit(1);
	}

	if(access(argv[1],F_OK) == 0)//判断文件是否存在
	{
		if(access(argv[1],R_OK) == 0)//判断文件是否可读
		{
			printf("可读\n");
		}

		if(access(argv[1],W_OK) == 0)
		{
			printf("可写\n");
		}

		if(access(argv[1],X_OK) == 0)
		{
			printf("可执行\n");
		}
	}
	else
		printf("文件不存在\n");

	return 0;
}
