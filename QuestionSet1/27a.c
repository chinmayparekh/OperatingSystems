//  Program number 27a
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to execute ls -Rl by the following system calls
// a. execl
// b. execlp
// c. execled. execv
// e. execvp
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("Using execl system call\n");
    execl("/bin/ls", "ls", "-Rl", (char *)0);
    return 0;
}