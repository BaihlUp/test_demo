#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
//#include <stdlib.h>

#define MSG_TRY "try again\n"
//#define 

int main()
{
#if 0	
	int rd = 0;
	char buf[1024] = {0};
	int fp = open("test.txt", O_RDWR);
	if(fp < 0)
	{
		perror("open ");
		return -1;
	}
	
	while((rd = read(fp, buf, 10)) > 0)
	{
		write(STDOUT_FILENO, buf, 10);
	}
	if(rd < 0)
	{
		perror("read ");
		close(fp);
		return -1;
	}
	close(fp);
#endif
	int i = 0;
	int rd = 0;
	char buf[1024] = {0};
	int fp = open("/dev/tty", O_RDONLY|O_NONBLOCK);
	if(fp < 0)
	{
		perror("open ");
		return -1;
	}


	for(; i < 5; i++)
	{
		rd = read(fp, buf, 10);
		if(rd > 0)
		{
			break;
		}
		if(errno != EAGAIN)
		{
			perror("read tty ");
			close(fp);
			exit(1);
		}
		else
		{
			write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
			sleep(2);
		}
	}
	if(i == 5)
	{
		write(STDOUT_FILENO, "time out\n", strlen("time out"));
	}
	else
	{
		write(STDOUT_FILENO, buf, strlen(buf));
	}
	
	close(fp);

	return 0;
}

