#include<stdio.h>
#include<unistd.h>
#include<limits.h>
int main()
{
        char path[PATH_MAX];
        if(getcwd(path,sizeof(path))!=NULL)
        {
                printf("current working directory%s ",path);
        }
        else
        {
                printf("not current working directry");
        }
}
