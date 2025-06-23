#include <stdio.h>

int main() {
    FILE *file;
    long size;

    file = fopen("data.bin", "rb");
    if (file == NULL) {
        perror("Unable to open file");
        return 1;
    }

    fseek(file, 0, SEEK_END);      // Move to end of file
    size = ftell(file);            // Get current position (file size in bytes)
    fclose(file);

    printf("Size of 'data.bin': %ld bytes\n", size);
    return 0;
}

