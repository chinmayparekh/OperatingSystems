//  Program number 5
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to create five new files with infinite loop. Execute the program in the background
// and check the file descriptor table at /proc/pid/fd.
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main()
{
    int fd1, fd2, fd3, fd4, fd5;
    int a = 0;
    fd1 = open("newfile5.txt", O_CREAT |O_EXCL, 0744);
    fd2 = open("newfile1.txt", O_CREAT |O_EXCL, 0744);
    fd3 = open("newfile2.txt", O_CREAT |O_EXCL, 0744);
    fd4 = open("newfile3.txt", O_CREAT |O_EXCL, 0744);
    fd5 = open("newfile4.txt", O_CREAT |O_EXCL, 0744);
    printf("%d %d %d %d %d\n", fd1, fd2, fd3, fd4, fd5);
    for (;;)
        a++;

    return 0;
}