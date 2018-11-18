#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: <pathname>\n");
		return -1;		
	}
	if(access(argv[1], X_OK) < 0)
	{	
		perror("access failed");
		return -1;
	}
	else
	{
		printf("execute is ok\n");
	}
	return 0;
}
