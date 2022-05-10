//  Program number 14
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a simple program to create a pipe, write to the pipe, read from pipe and display on
// the monitor.
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

    char msg[] = "Writing in pipe";
    char buf[100];
    if (pipe(fd) == -1)
    {
        printf("Pipe failed\n");
    }

    write(fd[1], msg, 100);

    read(fd[0], buf, 100);

    printf("Message = %s \n", buf);

    return 0;
}