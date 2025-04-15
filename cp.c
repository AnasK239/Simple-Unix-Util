#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUF_SIZE 4096

int main(int argc, char *argv[])
{

    if (argc != 3)
    {

        printf("Wrong Usage\n");
        return EXIT_FAILURE;
    }

    int src_fd = open(argv[1], O_RDONLY);
    if (src_fd < 0)
    {

        printf("Error opening source file\n");
        return EXIT_FAILURE;
    }

    int destination_fd = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (destination_fd < 0)
    {

        printf("Error opening destination file\n");
        close(src_fd);
        return EXIT_FAILURE;
    }

    char buffer[BUF_SIZE];
    int bytesRead, bytesWritten;

    while ((bytesRead = read(src_fd, buffer, BUF_SIZE)) > 0)
    {

        int bytesLeft = bytesRead, i = 0;
        while (i < bytesRead)
        {

            bytesWritten = write(destination_fd, buffer + i, bytesRead - i);

            if (bytesWritten < 0)
            {
                close(src_fd);
                close(destination_fd);
                return EXIT_FAILURE;
            }
            i += bytesWritten;
        }
    }

    if (bytesRead < 0)
    {

        printf("Error reading from source file\n");
        close(src_fd);
        close(destination_fd);
        return EXIT_FAILURE;
    }

    close(src_fd);
    close(destination_fd);
}
