#include<stdio.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>

int main()
{
	int fd;
	int ret;
	char *p1 = "hello world";

	fd = open("/home/mylink", O_CREAT|O_RDWR|O_TRUNC, 0644);
	if(fd == -1)
	{
		perror("open failed");
		exit(-1);
	}
#if 0
	ret = link("/home/mylink", "/home/testlink");
	if(ret == -1)
	{
		perror("link failed");
		exit(-1);
	}
#endif
#if 1
	//unlink文件会消失，但是依然可以向fd中写入数据，是写入到了缓冲区
	ret = unlink("/home/mylink");
	if(ret == -1)
	{
		perror("unlink failed");
		exit(-1);
	}
#endif
	ret = write(fd, p1, strlen(p1));
	if(ret == -1)
	{
		perror("write failed");
		exit(-1);
	}
	
	getchar();
	close(fd);

#if 0//表示程序结束后文件删除
	//unlink文件会消失，但是依然可以向fd中写入数据，是写入到了缓冲区
	ret = unlink("/home/mylink");
	if(ret == -1)
	{
		perror("unlink failed");
		exit(-1);
	}
#endif

	return 0;
}
