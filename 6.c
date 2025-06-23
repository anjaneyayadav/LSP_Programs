#include <stdio.h>

int main()
{
    const char *filename = "delete_me.txt";

    // Attempt to delete the file
    if (remove(filename) == 0) 
    {
        printf("File '%s' deleted successfully.\n", filename);
    }
    else
    {
        perror("Error deleting the file");
    }

    return 0;
}
