// void <signal handler func name> (int sig)
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
    if (signo == SIGFPE)
        printf("received SIGFPE\n");
}

int main(void)
{
    if (signal(SIGFPE, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGINT\n");
    int p = 1 / 0;
    printf("%d\n", p);
    printf("no SIGFPE received\n");
    return 0;
}