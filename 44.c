#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    FILE *file;
    char command[1024];

    file = fopen("instructions.txt", "r");
    if (file == NULL) {
        perror("Unable to open instructions.txt");
        return 1;
    }

    printf("Executing shell commands from instructions.txt:\n\n");

    while (fgets(command, sizeof(command), file) != NULL) {
        // Remove trailing newline character
        command[strcspn(command, "\n")] = '\0';

        if (strlen(command) == 0) continue; // Skip empty lines

        printf(">> %s\n", command);
        int status = system(command);

        if (status == -1) {
            perror("system() failed");
        } else {
            printf("Command executed with exit code: %d\n\n", WEXITSTATUS(status));
        }
    }

    fclose(file);
    return 0;
}

