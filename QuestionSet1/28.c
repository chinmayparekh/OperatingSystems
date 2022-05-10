//  Program number 28
//  Chinmay Parekh - IMT2020069
//  Date - 21-2-2022
// Write a program to get maximum and minimum real time priority.
#include <sched.h>
#include <stdio.h>
int main()
{
    printf("maximum priority = %d\n", sched_get_priority_max(SCHED_FIFO));
    printf("minimum priority = %d\n", sched_get_priority_min(SCHED_FIFO));
    return 0;
}
