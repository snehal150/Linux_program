#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

int main()
{
    int fd;
    char buffer[20];
    int bytes;

    // Write to file
    fd = open("xyz.txt", O_CREAT | O_WRONLY, 0123);
    if(fd<0)
    {
     perror("error to open file");
     return 1;
    }
    write(fd, "hello", strlen("hello"));
    close(fd);

    // Read from file
    fd = open("xyz.txt", O_RDONLY);
    if(fd<0){
    perror("error to open file");
    return 1;
    }
    bytes = read(fd, buffer, sizeof(buffer) - 1);
    buffer[bytes] = '\0';
    
    printf("file content = %s\n", buffer);
    close(fd);

    return 0;
}

