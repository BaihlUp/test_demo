#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>


int main()
{
	int data_len;
	int file_pipes[2];
	char buffer[BUFSIZ + 1];
	const char some_data[] = "1.hello";
	pid_t fork_result;
	int i = 0;

	memset(buffer, '\0', sizeof(buffer));
#if 0
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
			close(file_pipes[1]);
			data_len = read(file_pipes[0], buffer, BUFSIZ);
			printf("Read %d bytes, txt is: %s\n", data_len, buffer);
			close(file_pipes[0]);
		}
		else
		{
			close(file_pipes[0]);
			data_len = write(file_pipes[1], some_data, strlen(some_data));
			printf("Wrote %d bytes\n", data_len);
			close(file_pipes[1]);
			sleep(1);
		}
	
		exit(EXIT_SUCCESS);
	}
#endif
	/*
		创建两个进程，两个子进程写，父进程读
	*/
	if(pipe(file_pipes) == 0)
	{
		for(i = 0; i < 2; i++)
		{
			fork_result = fork();
			if(fork_result == 0)
			{
				//break;
			}
			else if(fork_result == -1)
			{
				fprintf(stderr, "Fork failure");
				exit(EXIT_FAILURE);
			}
		}
		
		if(fork_result == 0)
		{
			close(file_pipes[0]);
			data_len = write(file_pipes[1], some_data, strlen(some_data));
			printf("pid: %d, Write %d bytes, txt is: %s\n", getpid(), data_len, some_data);
		}
		#if 0
		else if(i == 1)
		{
			close(file_pipes[0]);
			data_len = write(file_pipes[1], "2.world", strlen("2.world"));
			printf("pid: %d, Write %d bytes\n", getpid(), data_len);
		}
		#endif
		else
		{
			sleep(1);
			close(file_pipes[1]);
			data_len = read(file_pipes[0], buffer, BUFSIZ);
			printf("pid: %d, Read %d bytes, txt is: %s\n", getpid(), data_len, buffer);
			close(file_pipes[0]);
			
			for(i = 0; i < 2; i++)
			{
				wait(NULL);
			}
		}
	
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_FAILURE); 
}

