#include <stdio.h>

int main()
{
    FILE *src, *dest;
    int ch;

    // Open source file in read mode
    src = fopen("source.txt", "r");
    if (src == NULL) 
    {
        perror("Error opening source file");
        return 1;
    }

    // Open destination file in write mode
    dest = fopen("destination.txt", "w");
    if (dest == NULL)
    {
        perror("Error opening destination file");
        fclose(src); // close source if dest fails
        return 1;
    }

    // Copy character by character
    while ((ch = fgetc(src)) != EOF) 
    {
        fputc(ch, dest);
    }

    printf("File copied successfully.\n");

    // Close both files
    fclose(src);
    fclose(dest);

    return 0;
}
