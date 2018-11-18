#include<stdio.h>


int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		fprintf(stderr, "Usage: <pathname>\n");
		return -1;		
	}
	if(-1 == rename(argv[1], argv[2]))
	{
		perror("rename failed");
		return -1;
	}
	
	return 0;
}

