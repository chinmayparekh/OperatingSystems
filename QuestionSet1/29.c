//  Program number 29
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
// SCHED_RR).
#include <sched.h>
#include <unistd.h>
#include <stdio.h>
int main()
{
    int x = sched_getscheduler(getpid());
    printf("Scheduling policy = %d\n", x);

    struct sched_param sp = {.sched_priority = 50};
    int ret;

    ret = sched_setscheduler(0, SCHED_FIFO, &sp); // changing the policy to FIFO
    if (ret == -1)
    {
        perror("sched_setscheduler");
        return 1;
    }

    x = sched_getscheduler(getpid());
    printf("Scheduling policy = %d\n", x);

    // sp = { .sched_priority = 50 };

    ret = sched_setscheduler(0, SCHED_RR, &sp); // Changing the policy to RR
    if (ret == -1)
    {
        perror("sched_setscheduler");
        return 1;
    }

    x = sched_getscheduler(getpid());
    printf("Scheduling policy = %d\n", x);
    return 0;
}