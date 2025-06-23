#include <stdio.h>



int main()
{

    if (rename("old.txt", "new.txt") == 0)

        printf("Renamed successfully.\n");

    else

        perror("Rename failed");



    return 0;
}
