#include <stdio.h>
#include <unistd.h>  // For access()

int main() {
    const char *filename = "config.ini";

    // Check write permission
    if (access(filename, W_OK) == 0) {
        printf("The file '%s' is writable.\n", filename);
    } else {
        perror("File is not writable or does not exist");
    }

    return 0;
}

