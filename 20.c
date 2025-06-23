#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Create a temporary file
    FILE *filename = tmpfile();

    if (filename == NULL)
    {
        printf("Failed to create temporary file.\n");
        return 1;
    }

    // Write some data to the temporary file
    fprintf(filename, "This is temporary data.\n");

    // Move to the beginning of the file to read what was written
    rewind(filename);

    // Read and print the data
    char buffer[100];
    while (fgets(buffer, sizeof(buffer), filename) != NULL)
    {
        printf("Read from temp file: %s", buffer);
    }

    // File will be automatically deleted when closed
    fclose(filename);

    return 0;
}
