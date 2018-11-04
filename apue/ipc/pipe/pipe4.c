#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char *argv[])
{
	int data_len;
	char buffer[BUFSIZ + 1];
	int pipe_fd;

	memset(buffer, '\0', sizeof(buffer));
	pipe_fd = atoi(argv[1]);
//	sscanf(argv[1], "%d", &pipe_fd);
	data_len = read(pipe_fd, buffer, BUFSIZ);
	printf("%d - Read %d bytes: %s\n", getpid(), data_len, buffer);
	exit(EXIT_SUCCESS);
}

