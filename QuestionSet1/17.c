//  Program number 17
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to simulate online ticket reservation. Implement write lock
// Write a program to open a file, store a ticket number and exit. Write a separate program, to
// open the file, implement write lock, read the ticket number, increment the number and print
// the new ticket number then close the file.
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
int main()
{
    struct flock lock;
    int fd = open("ticket.txt", O_RDWR);

    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();
    int ticket_no;
    lock.l_type = F_RDLCK;
    printf("Readlock\n");
    fcntl(fd, F_SETLKW, &lock);
    read(fd, &ticket_no, 4);

    printf("%d\n", ticket_no);
    lseek(fd, -4, SEEK_CUR);
    ticket_no++;

    printf("Before write lock\n");
    lock.l_type = F_WRLCK;
    fcntl(fd, F_SETLKW, &lock);

    printf("After write lock\n");
    write(fd, &ticket_no, 4);
    getchar();
    lock.l_type = F_UNLCK;
    fcntl(fd, F_SETLKW, &lock);
    close(fd);
}   