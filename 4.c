#include <stdio.h>
#include<unistd.h>
int main() 
{
    // Check file existence using access()
    if (access("sample.txt", F_OK) == 0) 
    {
        printf("File 'sample.txt' exists in the current directory.\n");
    }
    else
    {
          printf("File 'sample.txt' does NOT exist in the current directory.\n");
    }

    return 0;
}
