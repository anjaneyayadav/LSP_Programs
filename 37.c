#include <stdio.h>

int main() {
    FILE *input, *output;
    long file_size;

    input = fopen("input.txt", "r");
    if (input == NULL) {
        perror("Failed to open input file");
        return 1;
    }

    output = fopen("output.txt", "w");
    if (output == NULL) {
        perror("Failed to open output file");
        fclose(input);
        return 1;
    }

    // Move to the end of the file
    fseek(input, 0, SEEK_END);
    file_size = ftell(input);

    // Read characters in reverse and write to output
    for (long i = file_size - 1; i >= 0; i--) {
        fseek(input, i, SEEK_SET);
        int ch = fgetc(input);
        fputc(ch, output);
    }

    printf("File reversed successfully.\n");

    fclose(input);
    fclose(output);

    return 0;
}























