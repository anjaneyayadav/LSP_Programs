#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<string.h>
void main()
{
        int fd;
        int ret;
        char buf[64];
     fd=open("file.txt",O_RDONLY);
     //fd=open("file.txt",O_WRONLY|O_CREAT,0666);
        if(fd<0)
        {
                printf("failed to open the file\n");
                return ;
        }
        printf("file opened sucessfully\n");
//        ret=write(fd,buf,strlen(buf));
ret=read(fd,buf,64);
        if(ret<0)
        {
                printf("failed to read\n");
                return ;
        }
        buf[ret]=NULL;
        printf("contents are file%s\n",buf);
        close(fd);
}
