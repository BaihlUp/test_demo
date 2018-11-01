#include <stdio.h>

int main()
{
	FILE *fp = NULL;
	fp = fopen("test.txt", "w");
	if(fp == NULL)
	{
		perror("test.txt if not found\n");
		printf("test.txt if not found\n");
	}
	

	return 0;
}














