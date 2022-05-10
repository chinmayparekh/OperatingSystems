//  Program number 21
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program, call fork and print the parent and child process id.
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    int id = fork();
    if (id)
    {
        printf("Parent process id = %d\n", getpid());
    }
    else
    {
        printf("Child process id = %d\n", getpid());
    }
}