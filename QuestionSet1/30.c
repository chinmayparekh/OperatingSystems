//  Program number 30
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to run a script at a specific time using a Daemon process.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()//daemon should run in the root directory as a session(group of processes) leader
{
    if (!fork())
    {
        setsid();//setting as session leader
        chdir("/");
        umask(0);//givingf full permissions
        int fd = open("daemon.txt", O_RDWR | O_CREAT, 0744);
        while (1)
        {
            sleep(5);
            printf("This is a daemon process\n");
        }
        return (0);
    }
    else
        exit(0);
}