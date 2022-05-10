//  Program number 13
//  Chinmay Parekh - IMT2020069
//  Date - 22-04-2022
// Write two programs: first program is waiting to catch SIGSTOP signal, the second program
// will send the signal (using kill system call). Find out whether the first program is able to catch
// the signal or not.
#include <stdio.h>
#include <signal.h>
#include <unistd.h>

int main()
{
    int pid;
    printf("Enter pid : ");
    scanf("%d", &pid);
    printf("Sending kill signal\n");
    kill(pid, SIGSTOP);
    printf("Killed!\n");
    return 0;
}