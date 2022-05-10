//  Program number 11c
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd = open("11c", O_CREAT | O_RDWR, 0744);
    char buf[10] = {'1', '2', '3', '4', '5', '6', '7', '8', '9', '0'};
    int fd1 = fcntl(fd, F_DUPFD);
    write(fd, buf, 10);
    write(fd1, buf, 10);
    close(fd);
    close(fd1);

    return 0;
}
