//  Program number 4
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to open an existing file with read write mode. Try O_EXCL flag also.
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd;
    fd = open("newfile", O_CREAT |O_RDWR |O_EXCL);
    perror("");
    printf("fd = %d\n", fd);
    return 0;
}