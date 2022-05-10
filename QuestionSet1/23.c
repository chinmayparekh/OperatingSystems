//  Program number 23
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to create a Zombie state of the running program.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    int isParent = fork();
    if (isParent)
    {
        sleep(10);
        printf("Parent\n");
    }
    else
    {
        printf("Child\n");
    }
}