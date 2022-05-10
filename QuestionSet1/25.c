//  Program number 25
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to create three child processes. The parent should wait for a particular child (use
// waitpid system call).
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

int main()
{
    int child1, child2, child3;
    if (!(child1 = fork()))
        sleep(5);
    else if (!(child2 = fork()))
        sleep(10);
    else if (!(child3 = fork()))
        sleep(15);
    else
        waitpid(child1, NULL, 0); // child1,child2,child3 can be used as the parameter for which the parent waits
}