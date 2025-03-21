#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main() {
    int fd = open("example.txt", O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    char buffer[100];
    ssize_t bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead < 0) {
        perror("Error reading file");
        close(fd);
        return 1;
    }
    buffer[bytesRead]='\0';
    printf("File content:\n%s", buffer);
    close(fd);

    return 0;
}
