#include <stdio.h>
#include <unistd.h>  // for access()

int main() {
    const char *filename = "data.txt";

    if (access(filename, R_OK) == 0) {
        printf("The file '%s' is readable.\n", filename);
    } else {
        perror("File is not readable or does not exist");
    }

    return 0;
}

