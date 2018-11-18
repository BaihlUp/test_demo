#include<unistd.h>
#include<stdio.h>

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		fprintf(stderr, "Usage: <pathname>\n");
		return -1;		
	}
	char buf[10];
	if(-1 == readlink(argv[1], buf, sizeof(buf)))
	{
		perror("readlink failed");
		return -1;
	}
	printf("%s\n", buf);
	return 0;
}

