#include<fcntl.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: <pathname>\n");
		return -1;
	}

	int fd = open(argv[1], O_RDWR|O_APPEND);
	if(fd == -1)
	{
		perror("open failed");
		return -1;
	}	

	int dupfd = fcntl(fd, F_DUPFD, 7);
	if(dupfd == -1)
	{
		perror("fcntl failed");
		return -1;
	}
	int len = write(dupfd, "hello world", 10);
	if(len == -1)
	{
		perror("write failed");
		return -1;
	}	
	printf("dupfd = %d\n", dupfd);   // 7

	return 0;
}

