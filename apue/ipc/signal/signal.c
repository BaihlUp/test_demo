#include<signal.h>
#include<stdio.h>

typedef void (*sighandler_t)(int);

sighandler_t old_handle = NULL;

void sig_handle(int signum)
{
	printf("catch signal %d\n", signum);
	signal(SIGINT, old_handle);	//回复信号的默认处理工作
}

int main()
{
	//old_handle：接收信号之前的默认处理动作
	old_handle = signal(SIGINT, sig_handle);

	while(1);
	return 0;
}

