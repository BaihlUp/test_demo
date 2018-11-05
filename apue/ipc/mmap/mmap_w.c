#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<unistd.h>

void sys_err(const char *str)
{
	perror(str);
	exit(EXIT_FAILURE);
}

struct student{
	int id;
	char name[64];
	int age;
};

int main()
{
	int fd;
	struct student *p = NULL;
	off_t len;
	struct student stu = {1, "baihl", 18};

	fd = open("testmap", O_RDWR);
	if(fd == -1)
	{
		sys_err("open error");
		exit(EXIT_FAILURE);
	}

	ftruncate(fd, sizeof(stu));

	p = (struct student*)mmap(NULL, sizeof(stu), PROT_READ|PROT_WRITE, MAP_SHARED, fd, 0);
	if(p == MAP_FAILED)
	{
		sys_err("mmap error");
		exit(EXIT_FAILURE);
	}
	while(1){
		memcpy(p, &stu, sizeof(stu));
		stu.id++;
		sleep(1);
	}

	int ret = munmap(p, len);
	if(ret == -1)
	{
		sys_err("munmap error");
		exit(EXIT_FAILURE);
	}
	close(fd);
	exit(EXIT_SUCCESS);
}





