//  Program number 27b
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("Using execlp system call\n");
    execlp("ls", "ls", "-Rl", (char *)0);
    return 0;
}