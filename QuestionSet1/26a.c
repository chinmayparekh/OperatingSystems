//  Program number 26a
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to execute an executable program.
// a. use some executable program
// b. pass some input to an executable program. (for example execute an executable of $./a.out name)

//use test.c as the executable program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    static char *argv[] = {"a.out",NULL};
    execv("./a.out", argv);
    return 0;
}