//  Program number 18
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to find out total number of directories on the pwd.
// execute ls -l | grep ^d | wc ? Use only dup2.
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
int main(void)
{
    int fd1[2], fd2[2];
    pipe(fd1);
    pipe(fd2);

    if (!fork())
    {
        dup2(fd1[1], 1);
        close(fd2[0]);
        close(fd2[1]);
        close(fd1[0]);
        execlp("ls", "ls", "-l", (char *)0);
    }

    else
    {
        if (!fork())
        {
            dup2(fd1[0], 0);
            dup2(fd2[1], 1);
            close(fd1[1]);
            close(fd2[0]);
            execlp("grep", "grep", "^-", (char *)0);
        }
        else
        {
            sleep(2);
            dup2(fd2[0], 0);
            close(fd2[1]);
            close(fd1[0]);
            close(fd1[1]);
            execlp("wc", "wc", "-l", (char *)0);
        }
    }
}