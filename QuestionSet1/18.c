//  Program number 18
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to perform Record locking.
// a. Implement write lock
// b. Implement read lock
// Create three records in a file. Whenever you access a particular record, first lock it then modify/access
// to avoid race condition.
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
struct student
{
    int roll_number;
    int marks;
};

int main()
{
    struct flock lock;
    int fd = open("file18.txt", O_CREAT | O_RDWR, 0744);
    struct student student1, student2, student3;
    student1.roll_number = 1;
    student2.roll_number = 2;
    student3.roll_number = 3;

    student1.marks = 6;
    student2.marks = 9;
    student3.marks = 10;

    write(fd, &student1, sizeof(struct student));
    write(fd, &student2, sizeof(struct student));
    write(fd, &student3, sizeof(struct student));

    // implementing the write lock before writing in the place of 2nd record.
    lock.l_type = F_WRLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 8;
    lock.l_len = 8;
    lock.l_pid = getpid();

    printf("Before entering critical section\n");
    fcntl(fd, F_SETLKW, &lock);
    printf("Critical Section\n");
    getchar();

    // implementing read lock before reading the first record.
    lock.l_type = F_RDLCK;
    lock.l_start = 0;
    lock.l_len = 8;


    

    fcntl(fd, F_SETLKW, &lock);
    printf("Read LOCK\n");
    lock.l_type = F_UNLCK;
    lock.l_start = 8;
    lock.l_len = 8;
    fcntl(fd, F_SETLKW, &lock);

    getchar();
    close(fd);
}