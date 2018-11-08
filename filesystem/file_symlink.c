/*************************************************************************
	> File Name: file_symlink.c
	> Author: AlekXu
	> Mail: alekxu@163.com 
	> Created Time: 2018年11月07日 星期三 17时00分36秒
 ************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>

int main(int argc,char **argv)
{
	int lik;
	if(argc != 3)
	{
		printf("参数太少\n");
		exit(1);
	}

	lik = symlink(argv[1],argv[2]); //创建文件的硬链接

	if(lik == -1)
	{
		perror("创建硬连接失败");
		exit(1);
	}
	printf("完成！\n");
	return 0;
}
