#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>

int main()
{
#if 0
	int fd = 0, rd = 0;
	char buf;
	char msg[] = "Is't a test txt\n";
	int fp = open("lseek.txt", O_RDWR|O_CREAT, 0644);
	if(fp < 0)
	{
		perror("open ");
		return -1;
	}
	write(fp, msg, strlen(msg));
	//lseek(fp, 0, SEEK_SET); 	//从开始位置偏移
	//lseek(fp, -1, SEEK_CUR);	//从当前位置偏移
	lseek(fp, -1, SEEK_END);    //从文件尾开始偏移
	lseek(fp, 0, SEEK_END);  //从起始位置到结尾，返回值表示文件大小
	
	while(rd = read(fp, &buf, 1))
	{
		if(rd < 0)
		{
			perror("read ");
			close(fp);
			return -1;
		}
		write(STDOUT_FILENO, &buf, 1);
		sleep(1);
	}

	close(fp);	
#endif

	int fd = 0, rd = 0;
	char buf;
	char msg[] = "Is't a test txt\n";
	int fp = open("lseek.txt", O_RDWR);
	if(fp < 0)
	{
		perror("open ");
		return -1;
	}
	system("ls -l lseek.txt");
	
	lseek(fp, 99, SEEK_END);  //扩展文件大小，增加100个字节：99 + 1 = 100
	write(fp, "\0", 1);  //必须对文件进行IO操作，才会真正的扩展文件大小
	system("ls -l lseek.txt");

	close(fp);

	return 0;
}

