#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>

void main()
{
	int fd;
	int ret;
	char buf[64]="hello world!";

	fd=open("file.txt",O_WRONLY|O_CREAT,0666);
	if(fd<0)
	{
		printf("failed to open the file\n");
		return;
	}
	printf("file opened successfully\n");
	ret=write(fd,buf,strlen(buf));
	if(ret<0)
	{
		printf("failed to read\n");
		return;
	}
	buf[ret]=NULL;
	printf("read %d bytes from file %s\n",ret,buf);
	close(fd);
}
