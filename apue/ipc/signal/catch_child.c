#include<stdio.h>
#include<signal.h>


void catch_child()
{
	pid_t wpid;
	int status;
	
	while((wpid = wait(NULL)) != -1){
		printf("----catch child id: %d\n", wpid);
	}
}

int main()
{
	pid_t pid;
	int i;

	for(i = 0; i < 15; i++)
		if((pid = fork()) == 0)
			break;
	if(15 == i){
		struct sigaction act;

		act.sa_handler = catch_child;
		sigemptyset(&act.sa_mask);
		act.sa_flags = 0;

		sigaction(SIGCHLD, &act, NULL);

		printf("I am parent process %d\n", getpid());
		while(1);
	}
	else{
		printf("I am child process %d\n", getpid());
	}
	
	return 0;
}



