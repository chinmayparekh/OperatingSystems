//  Program number 27c
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("Using execle system call\n");
    execle("/bin/ls", "-R", "-l", NULL, NULL);
    return 0;
}