//  Program number 27d
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("Using execv system call\n");
    static char *argv[] = {"/bin/ls", "-Rl", NULL};
    execv(argv[0], argv);
    return 0;
}