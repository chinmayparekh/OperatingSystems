//  Program number 22
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program, open a file, call fork, and then write to the file by both the child as well as the
// parent processes. Check output of the file.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/wait.h>

int main()
{
    int fd = open("22.txt", O_CREAT | O_RDWR, 0744);
    int isParent = fork();
    char buf[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    if (isParent)
    {
        write(fd, buf, 10);
    }
    else
    {
        write(fd, buf, 10);
    }
}