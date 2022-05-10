//  Program number 27e
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    printf("Using execvp system call\n");
    static char *argv[] = {"/bin/ls", "-Rl", NULL};
    execvp(argv[0], argv);
    return 0;
}