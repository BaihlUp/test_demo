#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
	/*	扩展文件大小的两个函数
		int truncate(const char *path, off_t length);
		int ftruncate(int fd, off_t length);
	*/
	system("ls -l lseek.txt");
	int ret = truncate("lseek.txt", 500); //扩展文件大小到500字节
	if(ret == 0)
	{
		printf("add success!\n");
	}
	system("ls -l lseek.txt");

	return 0;
}

