//  Program number 9
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to ignore a SIGINT signal then reset the default action of the SIGINT
// signal - Use signal system call.
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGINT)
    {
        signal(SIGINT, SIG_DFL);
        printf("\nreceived SIGINT and set to default\n");
    }
}

int main(void)
{
    if (signal(SIGINT, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");
    while (1)
        ;
    return 0;
}