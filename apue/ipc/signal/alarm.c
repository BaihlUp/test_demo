#include<unistd.h>
#include<stdio.h>

int main()
{
	int seconds = 1;
	long i = 0;
	alarm(seconds);

	while(1)
	{
		printf("%ld\n", i++);
	}
	return 0;
}


