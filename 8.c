#include <stdio.h>

int main()
{
    const char *source = "/home/anjaneyayadav/Linux/filemanagement/source_dir/sample.txt";       // Original location
    const char *destination = "/home/anjaneyayadav/Linux/filemanagement/dest/sample.txt";  // New location

    // Attempt to move (rename) the file
    if (rename(source, destination) == 0)
    {
        printf("File moved successfully.\n");
    }
    else
    {
        perror("Error moving file");
    }

    return 0;
}
