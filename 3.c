#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
int main()
{
        int ret;
        ret=mkdir("test",0755);
        if(ret==0)
        {
                printf("directory 'test' created sucessfull.\n");
        }
        else
        {
                printf("directory is not created");
        }
}
