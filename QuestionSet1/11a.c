//  Program number 11a
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to open a file, duplicate the file descriptor and append the file with both the
// descriptors and check whether the file is updated properly or not.
// a. use dup
// b. use dup2
// c. use fcntl
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd, fd1;
    char buf[80];
    fd = open("11a", O_CREAT | O_RDWR, 0744);
    fd1 = dup(fd); 
    printf("%d\n", fd1);
    printf("%d\n", fd);
    close(fd);

    return 0;
}