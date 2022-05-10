//  Program number 12
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write a program to create an orphan process. Use kill system call to send SIGKILL signal to
// the parent process from the child process.
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void sig_handler(int signo)
{
    if (signo == SIGKILL)
    {
        printf("received SIGKILL\n");
    }
}

int main()
{

    if (!fork()) // child process
    {
        printf("sending kill signal to parent\n");
        kill(getppid(), SIGKILL); // Sending kill signal to Parent.
    }
    else
    {
        sleep(5);
        printf("This is the parent process\n");
        if (signal(SIGKILL, sig_handler) == SIG_ERR)
            printf("Can't catch SIGKILL\n");
    }
    return 0;
}