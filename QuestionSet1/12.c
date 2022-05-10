//  Program number 12
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to find out the opening mode of a file. Use fcntl.
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main()
{
    int fd = open("12.txt", O_CREAT | O_RDWR, 0744);
    int mode = fcntl(fd, F_GETFL);
    printf("%d\n", mode & O_ACCMODE);
}