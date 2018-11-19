#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage: <pathname>\n");
		return -1;
	}

	int fd1 = open(argv[1], O_RDWR|O_APPEND);
	if(fd1 == -1)
	{
		perror("open failed");
		return -1;
	}

	int fd2 = open(argv[2], O_RDWR);
	if(fd2 == -1)
	{
		perror("open failed");
		return -1;
	}
#if 0	
	int dupfd = dup(fd);
	if(-1 == dupfd){
		perror("dup failed");
		return -1;
	}
#endif
	int dup2fd = dup2(fd1, fd2);
	if(dup2fd == -1){
		perror("dup2 failed");
		return -1;
	}
	
	int len = write(dup2fd, "hello world", 10);
	if(len == -1)
	{
		perror("write failed");
		return -1;
	}
	

	return 0;
}
