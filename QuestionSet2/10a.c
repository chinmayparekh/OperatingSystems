// SIGSEGV invalid memory reference
//  Program number 10
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a separate program using sigaction system call to catch the following signals.
// a. SIGSEGV
// b. SIGINT
// c. SIGFPE
#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler(int signo)
{
    if (signo == SIGSEGV)
    {
        printf("received SIGSEGV\n");
        exit(0);
    }
}

int main(void)
{
    struct sigaction act;
    act.sa_handler = &sig_handler;
    if (sigaction(SIGSEGV, &act, NULL) < 0)
    { 
        perror("sigaction");
        return 1;
    }
    int *p = NULL;
    printf("%d\n", *p);
    printf("no SIGSEGV received\n");
    return 0;
}