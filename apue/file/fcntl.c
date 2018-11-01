#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
//#include <stdlib.h>


#define MSG_TRY "try again\n"

int main()
{
	char buf[10];
	int flags, n;
	flags = fcntl(STDIN_FILENO,F_GETFL);
	if(flags == -1)
	{
		perror("fcntl error");
		exit(1);
	}
	flags |= O_NONBLOCK;		//设置非阻塞
	int ret = fcntl(STDIN_FILENO, F_SETFL, flags);
	if(ret == -1)
	{
		perror("fcntl error");
		exit(1);
	}	

tryagain:
	n = read(STDIN_FILENO, buf, 10);
	if(n < 0)
	{
		if(errno != EAGAIN)
		{
			perror("read tty ");
			exit(1);
		}
		else
		{
			write(STDOUT_FILENO, MSG_TRY, strlen(MSG_TRY));
			sleep(2);
			goto tryagain;
		}
	}

	write(STDOUT_FILENO, buf, strlen(buf));
	
	return 0;
}

