#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int data_len;
	int file_pipes[2];
	char buffer[BUFSIZ + 1];
	const char some_data[] = "123";
	pid_t fork_result;

	memset(buffer, '\0', sizeof(buffer));

	if(pipe(file_pipes) == 0)
	{
		fork_result = fork();
		if(fork_result == -1)
		{
			fprintf(stderr, "Fork failure");
			exit(EXIT_FAILURE);
		}
		if(fork_result == 0)
		{
			sprintf(buffer, "%d", file_pipes[0]);
			(void)execl("pipe4", "pipe4", buffer, (char*)0);
			/*
				buffer: 让程序读取的文件描述符
				(char*)0: 这个参数的作用是终止被调用程序的参数列表
			*/
			
			exit(EXIT_FAILURE); 
		}
		else
		{
			data_len = write(file_pipes[1], some_data, strlen(some_data));
			printf("%d - Wrote %d bytes\n", getpid(), data_len);
		}
		exit(EXIT_SUCCESS);
	}

	exit(EXIT_FAILURE); 
}


