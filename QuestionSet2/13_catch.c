//  Program number 13
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write two programs: first program is waiting to catch SIGSTOP signal, the second program
// will send the signal (using kill system call). Find out whether the first program is able to catch
// the signal or not.
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

// void <signal handler func name> (int sig)
void sig_handler(int signo)
{
    if (signo == SIGSTOP)
        printf("received SIGSTOP\n");
}

int main(void)
{
    int pid = getpid();
    printf("%d waiting for SIGSTOP...\n", pid);
    if (signal(SIGSTOP, sig_handler) == SIG_ERR)
    {
        perror("signal ");
        printf("Can't catch SIGSTOP\n");
    }
    while (1)
        ;
    return 0;
}