#include<sys/time.h>
#include<signal.h>
#include<stdio.h>

void myfunc()
{
	printf("hello world\n");	//第一次2s打印，后续循环5s打印
}

int main()
{
	struct itimerval it, oldit;

	signal(SIGALRM, myfunc);

	it.it_value.tv_sec = 2;
	it.it_value.tv_usec = 0;
	
	it.it_interval.tv_sec = 5;
	it.it_interval.tv_usec = 0;

	if(setitimer(ITIMER_REAL, &it, &oldit) == -1)
	{
		perror("setitimer error");
		exit(-1);
	}
	int i = 0;
	while(1)
	{
		sleep(1);
		printf("%d\n", i++);
	}
	return 0;
}
