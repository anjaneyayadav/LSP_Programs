#include <stdio.h>

int main()
{
    FILE *fp;
    long size;

    // Open the file in read mode
    fp = fopen("file.txt", "r");
    if (fp == NULL)
    {
        perror("Error opening file");
        return 1;
    }

    // Move file pointer to end of file
    fseek(fp, 0, SEEK_END);

    // Get current position (which is the size)
    size = ftell(fp);

    // Close the file
    fclose(fp);

    printf("Size of file.txt: %ld bytes\n", size);

    return 0;
}
