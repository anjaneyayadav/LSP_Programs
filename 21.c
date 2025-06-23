#include<stdio.h>
#include<sys/stat.h>
int main()
{
        char path[256];
        struct stat info;
        printf("enter a path");
        scanf("%s",path);
        if(stat(path,&info)!=0)
        {
                printf("error: this can't acess\n");
                return 1;
        }

        if(S_ISREG(info.st_mode))
        {
                printf("it is regular file");
        }
        else if(S_ISDIR(info.st_mode))
        {
                printf("it is directory");
        }
        else
        {
                printf("it is neither file or directory");
        }
        return 0;
}
