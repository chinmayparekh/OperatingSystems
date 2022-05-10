//  Program number 23
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to print the maximum number of files can be opened within a process and
// size of a pipe (circular buffer).
#include <unistd.h>
#include <stdio.h>

int main()
{
    long PIPE_BUF, OPEN_MAX;
    PIPE_BUF = pathconf(".",_PC_PIPE_BUF);
    OPEN_MAX = sysconf(_SC_OPEN_MAX);
    printf("Pipe_buf = %ld\t OPEN_MAX = %ld\n",PIPE_BUF,OPEN_MAX);
}