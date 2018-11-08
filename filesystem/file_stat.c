/*************************************************************************
	> File Name: file_stat.c
	> Author: AlekXu
	> Mail: alekxu@163.com 
	> Created Time: 2018年11月07日 星期三 17时16分37秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>

int main(int argc,char **argv)
{
	struct stat sta;
	if(argc != 2)
	{
		printf("参数太少\n");
		exit(1);
	}
	//stat(1,2)
	//1:要获取属性的文件名
	//2：结构体存储获取到的属性值
	stat(argv[1],&sta);//获取文件的属性
	printf("文件大小：%ld byte\n",sta.st_size);
	printf("文件类型：");
	
	if(S_ISSOCK(sta.st_mode))
	{
		printf("套接字");
	}

	if(S_ISDIR(sta.st_mode))
	{
		printf("目录文件");
	}

	return 0;
}
