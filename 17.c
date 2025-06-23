#include<stdio.h>
#include<sys/stat.h>
int main()
{
        if(chmod("file.txt",0444)==0)
        {
                printf("sucess");
        }
        else
        {
                printf("failure");
        }
}
