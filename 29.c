#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int fd;
    const char *filename = "myfifo";
    char buffer[256];

    // Open the FIFO for reading (blocking mode)
    fd = open(filename, O_RDONLY);
    if (fd < 0)
    {
        perror("open failed");
        return 1;
    }

    // Read data from FIFO
    ssize_t byteread = read(fd, buffer, sizeof(buffer) - 1);
    if (byteread > 0) 
    {
        buffer[byteread] = '\0';  // NULL terminate the string
        printf("Read data: %s\n", buffer);
    }
    else
    {
        perror("read failed or no data");
    }
    close(fd);
    return 0;
}
