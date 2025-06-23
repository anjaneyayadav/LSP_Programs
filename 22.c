#include<stdio.h>
int main()
{
        if(link("hardlink.txt","source.txt")==0)
        {
                printf("it is sucess");
        }
        else
        {
                printf("failure");
        }
}
