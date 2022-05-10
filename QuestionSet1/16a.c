//  Program number 16a
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to perform mandatory locking.
// a. Implement write lock
// b. Implement read lock
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
int main()
{
    struct flock lock;
    int fd = open("16a.txt", O_CREAT | O_RDWR, 0744);

    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    printf("Before entering critical section\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Critical Section\n");
    getchar();
    lock.l_type = F_UNLCK;
    printf("Unlocked!\n");
    fcntl(fd, F_SETLKW, &lock);
    close(fd);
}