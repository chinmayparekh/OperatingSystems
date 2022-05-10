//  Program number 15
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a simple program to send some data from parent to the child process.
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <string.h>
#include <sys/wait.h>

int main()
{

    int fd[2];
    if (pipe(fd) == -1)
    {
        printf("Pipe failed\n");
    }

    int isParent = fork();
    if (!isParent)
    {
        char buf[100];
        close(fd[1]);
        read(fd[0], buf, sizeof(buf));

        printf("%s is read by the child\n", buf);
    }
    else
    {
        char buf[100] = "Writing";
        close(fd[0]);
        write(fd[1], buf, sizeof(buf));
        printf("%s is written by the parent\n", buf);
    }
    return 0;
}
