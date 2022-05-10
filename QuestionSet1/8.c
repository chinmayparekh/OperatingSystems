//  Program number 8
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to open a file in read only mode, read line by line and display each line as it is read.
// Close the file when end of file is reached.
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;
    char buf;
    char line[1000];
    int count = 0;
    fd = open("8.c", O_RDWR);

    while (read(fd, &buf, sizeof(buf)) != 0)
    {
        if (buf != '\n')
        {
            line[count++] = buf;
        }
        else
        {
            line[count++] = '\0';
            getchar();
            printf("%s\n", line);
            count = 0;
        }
    }

    close(fd);
    return 0;
}