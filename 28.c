#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<errno.h>
int main()
{
        const char *fifoname="myfifo";
        if(mkfifo(fifoname,0666)==-1)
        {
                if(errno==EEXIST)
                {
                        printf("file are exisr already %s\n",fifoname);
                }
                else
                {
                        printf("not exist");
                }
        }
        else
        {
                printf("file is create newly %s\n",fifoname);
        }
}
