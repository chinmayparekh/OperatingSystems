// void <signal handler func name> (int sig)
// SIGABRT – abnormal termination.
// SIGFPE – floating point exception.
// SIGILL – invalid instruction.
// SIGINT – interactive attention request sent to the program.
// SIGSEGV – invalid memory access.
// SIGTERM – termination request sent to the program.

//  Program number 8
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a separate program using signal system call to catch the following signals.
// a. SIGSEGV
// b. SIGINT
// c. SIGFPE
// d. SIGALRM (use alarm system call)
// e. SIGALRM (use setitimer system call)
// f. SIGVTALRM (use setitimer system call)
// g. SIGPROF (use setitimer system call)
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGSEGV)
        printf("received SIGSEGV\n");
}

int main(void)
{
    if (signal(SIGSEGV, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");
    int *p = NULL;
    printf("%d\n", *p);
    printf("no SIGSEGV received\n");
    return 0;
}