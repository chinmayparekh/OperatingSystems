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
#include <stdlib.h>
#include <sys/time.h>

void sig_handler(int signo)
{
    printf("in handler\n");
    if (signo == SIGPROF)
    {
        printf("received SIGPROF\n");
        exit(0);
    }
}

int main(void)
{
    if (signal(SIGPROF, sig_handler) == SIG_ERR)
        printf("\ncan't catch SIGPROF\n");

    struct itimerval timer;
    timer.it_value.tv_sec = 2;
    timer.it_value.tv_usec = 0;

    timer.it_interval.tv_sec = 2;
    timer.it_interval.tv_usec = 0;

    setitimer(ITIMER_REAL, &timer, NULL);
    printf("going to sleep\n");
    sleep(5);
    printf("no SIGPROF received\n");
    return 0;
}