//  Program number 26b
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{

    static char *argv[] = {"a.out", "1234", NULL};
    execv(argv[0], argv);
}