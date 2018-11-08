/*************************************************************************
	> File Name: file_test.c
	> Author: AlekXu
	> Mail: alekxu@163.com 
	> Created Time: 2018年11月08日 星期四 10时20分48秒
 ************************************************************************/
//1.使用open创建一个file.txt文件，权限为666，并在文件中写入字符串“hello world”
//2.并使用read()函数读取file.txt中内容并输出，并获取file.txt的大小和权限输出到屏幕上
//3.并获取当前目录下的所有文件并输出
#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<error.h>
#include<string.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<sys/types.h>

int main(int argc,char **argv)
{
	int ret;
	int ret_temp;
	int ret_temp1;
	struct stat status;

	//umask(0);
	ret = open(argv[1],O_CREAT|O_RDWR,00666);
	char *buffer = "hello world";
	char recvbuff[256];

	if(ret == -1)
	{
		perror("文件创建失败");
		exit(1);
	}
	else
	{
		ret_temp = write(ret,buffer,11);
		if(ret_temp == -1)
		{
			perror("写数据失败");
			exit(1);
		}
	}

	close(ret);
	
	ret = open(argv[1],O_RDONLY,00666);

	read(ret,recvbuff,256);

	printf("%s",recvbuff);

	close(ret);

	ret_temp1 = stat(argv[1],&status);
	printf("文件大小：%ld byte\n",status.st_size);
	printf("文件类型：");

}
