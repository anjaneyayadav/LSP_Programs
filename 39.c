#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *file;
    unsigned char buffer[1024];  // Buffer to hold binary data
    size_t bytesRead;

    file = fopen("binary.bin", "rb");
    if (file == NULL) {
        perror("Failed to open file");
        return 1;
    }

    printf("Contents of binary.bin (in hexadecimal):\n");

    while ((bytesRead = fread(buffer, 1, sizeof(buffer), file)) > 0) {
        for (size_t i = 0; i < bytesRead; i++) {
            printf("%02X ", buffer[i]);  // Print each byte in hex format
        }
    }

    printf("\n");
    fclose(file);
    return 0;
}

