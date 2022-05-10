//  Program number 24
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to create an orphan process.
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

void main()
{
    int isParent = fork();
    if (isParent)
    {
        printf("Parent\n");
    }
    else
    {
        sleep(10);
        printf("Child\n");
    }
}